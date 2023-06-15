cmake_minimum_required(VERSION 3.2)

project(SCALAPACK VERSION 2.2.1 LANGUAGES C Fortran)

# Configure the warning and code coverage suppression file
configure_file(
  "${SCALAPACK_SOURCE_DIR}/CMAKE/CTestCustom.cmake.in"
  "${SCALAPACK_BINARY_DIR}/CTestCustom.cmake"
  COPYONLY
)

# Add the CMake directory for custom CMake modules
list(PREPEND CMAKE_MODULE_PATH ${SCALAPACK_SOURCE_DIR}/CMAKE)

set(SCALAPACK_VERSION_MAJOR 2)
set(SCALAPACK_VERSION_MINOR 2)
set(SCALAPACK_VERSION_PATCH 1)
set(SCALAPACK_VERSION ${SCALAPACK_VERSION_MAJOR}.${SCALAPACK_VERSION_MINOR}.${SCALAPACK_VERSION_PATCH})

if(UNIX AND CMAKE_Fortran_COMPILER_ID STREQUAL Intel)
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -fltconsistency -fp_port" )
endif()

#
#   MPI
#
find_package(MPI REQUIRED COMPONENTS C Fortran)

message(STATUS "--> MPI C Compiler : ${MPI_C_COMPILER}")
message(STATUS "--> C Compiler : ${CMAKE_C_COMPILER}")
message(STATUS "--> MPI Fortran Compiler : ${MPI_Fortran_COMPILER}")
message(STATUS "--> Fortran Compiler : ${CMAKE_Fortran_COMPILER}")

macro(SCALAPACK_install_library lib)
  install(TARGETS ${lib} EXPORT scalapack-targets
    ARCHIVE DESTINATION lib${LIB_SUFFIX}
    LIBRARY DESTINATION lib${LIB_SUFFIX}
    RUNTIME DESTINATION bin
  )
endmacro()

# --------------------------------------------------
# Testing
set(DART_TESTING_TIMEOUT 600)

include(CTest)
# --------------------------------------------------

# Organize output files.  On Windows this also keeps .dll files next
# to the .exe files that need them, making tests easy to run.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SCALAPACK_BINARY_DIR}/TESTING)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${SCALAPACK_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SCALAPACK_BINARY_DIR}/lib)

# --------------------------------------------------
# Check for any necessary platform specific compiler flags
include( CheckBLACSCompilerFlags )
CheckBLACSCompilerFlags()

set(prefix ${CMAKE_INSTALL_PREFIX})
set(libdir ${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX})
set(PKG_CONFIG_DIR ${libdir}/pkgconfig)

# --------------------------------------------------
# BLACS Internal variables
#
#   Fortran Mangling, MPI Tests and BLACS settings
#
include(FortranMangling)
compile()

fortran_mangling(CDEFS)
message(STATUS "=========")

# --------------------------------------------------
# Compiler Flags
add_compile_definitions(${CDEFS})

# --------------------------------------------------
# ScaLAPACK needs BLAS and LAPACK

option(USE_OPTIMIZED_LAPACK_BLAS "Whether or not to search for optimized LAPACK and BLAS libraries on your machine (if not found, Reference LAPACK and BLAS will be downloaded and installed)" ON)

message(STATUS "CHECKING BLAS AND LAPACK LIBRARIES")

if(LAPACK_LIBRARIES)
  include(CheckFortranFunctionExists)
  message(STATUS "--> LAPACK supplied by user is ${LAPACK_LIBRARIES}.")
  set(CMAKE_REQUIRED_LIBRARIES ${LAPACK_LIBRARIES})
  check_fortran_function_exists("dgesv" LAPACK_FOUND)
  unset( CMAKE_REQUIRED_LIBRARIES )
  message(STATUS "--> LAPACK routine dgesv is found: ${LAPACK_FOUND}.")
endif()

if(LAPACK_FOUND)
      message(STATUS "--> LAPACK supplied by user is WORKING, will use ${LAPACK_LIBRARIES}.")
else()
   if(USE_OPTIMIZED_LAPACK_BLAS)
      message(STATUS "--> Searching for optimized LAPACK and BLAS libraries on your machine.")
      find_package(LAPACK)
   endif()
   if(NOT LAPACK_FOUND)
      message(STATUS "--> LAPACK and BLAS were not found. Reference LAPACK and BLAS will be downloaded and installed")
      include(ExternalProject)
      ExternalProject_Add(
		lapack
		URL http://www.netlib.org/lapack/lapack.tgz
		CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${SCALAPACK_BINARY_DIR}
        PREFIX ${SCALAPACK_BINARY_DIR}/dependencies
      )
	  if(UNIX)
         set(LAPACK_LIBRARIES ${SCALAPACK_BINARY_DIR}/lib/liblapack.a CACHE STRING "LAPACK library" FORCE)
         set(BLAS_LIBRARIES ${SCALAPACK_BINARY_DIR}/lib/libblas.a CACHE STRING "BLAS library" FORCE)
	  else() # On Windows
         set(LAPACK_LIBRARIES ${SCALAPACK_BINARY_DIR}/lib/liblapack.lib CACHE STRING "LAPACK library" FORCE)
         set(BLAS_LIBRARIES ${SCALAPACK_BINARY_DIR}/lib/libblas.lib CACHE STRING "BLAS library" FORCE)
      endif()
   endif()
endif()

message(STATUS "BLAS library: ${BLAS_LIBRARIES}")
message(STATUS "LAPACK library: ${LAPACK_LIBRARIES}")

message(STATUS "=========")

# --------------------------------------------------
# Subdirectories that need to be processed

macro(append_subdir_files variable dirname)
get_directory_property(holder DIRECTORY ${dirname} DEFINITION ${variable})
foreach(depfile ${holder})
  list(APPEND ${variable} "${dirname}/${depfile}")
endforeach()
endmacro()


#
# BLACS
#
add_subdirectory(BLACS)
append_subdir_files(blacs "BLACS/SRC")

#
# TOOLS
#
add_subdirectory(TOOLS)
append_subdir_files(tools TOOLS)
append_subdir_files(tools-C TOOLS)
append_subdir_files(extra_lapack "TOOLS/LAPACK")

#
# PBLAS
#
add_subdirectory(PBLAS)
append_subdir_files(pblas "PBLAS/SRC")
append_subdir_files(pblas-F "PBLAS/SRC")
append_subdir_files(pbblas "PBLAS/SRC/PBBLAS")
append_subdir_files(ptzblas "PBLAS/SRC/PTZBLAS")
append_subdir_files(ptools "PBLAS/SRC/PTOOLS")

#
# REDIST
#
add_subdirectory(REDIST)
append_subdir_files(redist "REDIST/SRC")

#
# SRC
#
add_subdirectory(SRC)
append_subdir_files(src "SRC")
append_subdir_files(src-C "SRC")

if(UNIX)
    add_library(scalapack ${blacs} ${tools} ${tools-C} ${extra_lapack} ${pblas} ${pblas-F} ${ptzblas} ${ptools} ${pbblas} ${redist} ${src} ${src-C})
    set_target_properties(scalapack PROPERTIES
        VERSION ${SCALAPACK_VERSION}
        SOVERSION ${SCALAPACK_VERSION_MAJOR}.${SCALAPACK_VERSION_MINOR})
    target_link_libraries( scalapack ${LAPACK_LIBRARIES} ${BLAS_LIBRARIES})
    scalapack_install_library(scalapack)
else() # Need to separate Fortran and C Code
    if(MSVC AND BUILD_SHARED_LIBS)
        add_library(blacs_obj OBJECT ${blacs})
        add_library(pblas_obj OBJECT ${pblas})
        add_library(ptools_obj OBJECT ${ptools})
        add_library(redist_obj OBJECT ${redist})
        add_library(srcc_obj OBJECT ${src-C})
        add_library(toolsc_obj OBJECT ${tools-C})
        add_library(scalapack
            $<TARGET_OBJECTS:blacs_obj>
            $<TARGET_OBJECTS:pblas_obj>
            $<TARGET_OBJECTS:ptools_obj>
            $<TARGET_OBJECTS:redist_obj>
            $<TARGET_OBJECTS:srcc_obj>
            $<TARGET_OBJECTS:toolsc_obj>
            ${pblas-F} ${pbblas} ${ptzblas} ${tools} ${src} ${extra_lapack}
        )
        target_link_libraries( scalapack ${LAPACK_LIBRARIES} ${BLAS_LIBRARIES} MPI::MPI_C)
    else()
        add_library(scalapack ${blacs} ${tools-C} ${pblas} ${ptools} ${redist} ${src-C})
        target_link_libraries( scalapack ${LAPACK_LIBRARIES} ${BLAS_LIBRARIES})
        add_library(scalapack-F ${pblas-F} ${pbblas} ${ptzblas} ${tools} ${src} ${extra_lapack} )
    endif()
    set_target_properties(scalapack PROPERTIES
        VERSION ${SCALAPACK_VERSION}
        SOVERSION ${SCALAPACK_VERSION_MAJOR}.${SCALAPACK_VERSION_MINOR})
    scalapack_install_library(scalapack)
    if(TARGET scalapack-F)
        set_target_properties(scalapack-F PROPERTIES
            VERSION ${SCALAPACK_VERSION}
            SOVERSION ${SCALAPACK_VERSION_MAJOR}.${SCALAPACK_VERSION_MINOR})
        target_link_libraries( scalapack-F ${LAPACK_LIBRARIES} ${BLAS_LIBRARIES}  MPI::MPI_Fortran)
        scalapack_install_library(scalapack-F)
    endif()
endif()

option(SCALAPACK_BUILD_TESTS "Build all tests of the ScaLAPACK library" ON)
if(${SCALAPACK_BUILD_TESTS})
  add_subdirectory(TESTING)
endif()

# --------------------------------------------------
# CPACK Packaging

set(CPACK_PACKAGE_NAME "ScaLAPACK")
set(CPACK_PACKAGE_VENDOR "University of Tennessee, Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "ScaLAPACK- Linear Algebra Package")
set(CPACK_PACKAGE_VERSION_MAJOR ${SCALAPACK_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${SCALAPACK_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${SCALAPACK_VERSION_PATCH})
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "SCALAPACK")
if(WIN32 AND NOT UNIX)
  # There is a bug in NSI that does not handle full unix paths properly. Make
  # sure there is at least one set of four (4) backlasshes.
  set(CPACK_NSIS_HELP_LINK "http:\\\\\\\\http://icl.cs.utk.edu/lapack-forum")
  set(CPACK_NSIS_URL_INFO_ABOUT "http:\\\\\\\\www.netlib.org/scalapack")
  set(CPACK_NSIS_CONTACT "scalapack@eecs.utk.edu")
  set(CPACK_NSIS_MODIFY_PATH ON)
  set(CPACK_NSIS_DISPLAY_NAME "SCALAPACK-${SCALAPACK_VERSION}")
  set(CPACK_PACKAGE_RELOCATABLE "true")
else()
  set(CPACK_GENERATOR "TGZ")
  set(CPACK_SOURCE_GENERATOR TGZ)
  set(CPACK_SOURCE_PACKAGE_FILE_NAME "scalapack-${SCALAPACK_VERSION}" )
  set(CPACK_SOURCE_IGNORE_FILES ~$ .svn ${CPACK_SOURCE_IGNORE_FILES} )
endif()
INCLUDE(CPack)


# --------------------------------------------------


export(TARGETS scalapack FILE scalapack-targets.cmake)
if(TARGET scalapack-F)
    export(TARGETS scalapack-F APPEND FILE scalapack-targets.cmake)
endif()

if( NOT LAPACK_FOUND )
 install(FILES
  ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES}
  DESTINATION lib
   )
endif()

configure_file(${SCALAPACK_SOURCE_DIR}/CMAKE/scalapack-config-version.cmake.in
  ${SCALAPACK_BINARY_DIR}/scalapack-config-version.cmake @ONLY)
configure_file(${SCALAPACK_SOURCE_DIR}/CMAKE/scalapack-config-build.cmake.in
  ${SCALAPACK_BINARY_DIR}/scalapack-config.cmake @ONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scalapack.pc.in ${CMAKE_CURRENT_BINARY_DIR}/scalapack.pc)
 install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/scalapack.pc
  DESTINATION ${PKG_CONFIG_DIR}
   )

configure_file(${SCALAPACK_SOURCE_DIR}/CMAKE/scalapack-config-install.cmake.in
  ${SCALAPACK_BINARY_DIR}/CMakeFiles/scalapack-config.cmake @ONLY)
install(FILES
  ${SCALAPACK_BINARY_DIR}/CMakeFiles/scalapack-config.cmake
  ${SCALAPACK_BINARY_DIR}/scalapack-config-version.cmake
  DESTINATION lib${LIB_SUFFIX}/cmake/scalapack-${SCALAPACK_VERSION}
  )

install(EXPORT scalapack-targets
  DESTINATION lib${LIB_SUFFIX}/cmake/scalapack-${SCALAPACK_VERSION})
