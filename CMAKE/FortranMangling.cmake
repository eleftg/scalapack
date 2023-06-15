# Macro that defines variables describing the Fortran name mangling
# convention
#
# Sets the following outputs on success:
#
#  INTFACE
#    Add_
#    NoChange
#    f77IsF2C
#    UpCase
#
get_property(gen_is_multiconfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
set(_build_dir ${CMAKE_BINARY_DIR}/BLACS_FortranMangling_build_dir)

function(compile)
    message(STATUS "=========")
    message(STATUS "Compiling and Building BLACS INSTALL Testing to set correct variables")

    file(MAKE_DIRECTORY ${_build_dir})
    if(gen_is_multiconfig)
        set(_c "--config Release")
    else()
        set(_bt -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE})
    endif()
    # Configure:
    execute_process(COMMAND ${CMAKE_COMMAND}
         -G ${CMAKE_GENERATOR} ${_bt}
         "-DCMAKE_Fortran_COMPILER=${CMAKE_Fortran_COMPILER}"
         "-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}"
         ${CMAKE_SOURCE_DIR}/BLACS/INSTALL
        WORKING_DIRECTORY ${_build_dir}
        RESULT_VARIABLE RESVAR OUTPUT_VARIABLE LOG1_OUT ERROR_VARIABLE LOG1_ERR
    )
    if(RESVAR EQUAL 0)
        message(STATUS "Configure in the INSTALL directory successful")
    else()
        message(STATUS " Build Output:\n ${LOG1_OUT}")
        message(STATUS " Error Output:\n ${LOG1_ERR}")
        message(FATAL_ERROR " Configure in the BLACS INSTALL directory FAILED")
    endif()

    # Build:
    execute_process(COMMAND ${CMAKE_COMMAND} --build ${_build_dir} ${_c}
        RESULT_VARIABLE RESVAR OUTPUT_VARIABLE LOG2_OUT ERROR_VARIABLE LOG2_ERR
    )
    if(RESVAR  EQUAL 0)
        message(STATUS "Build in the BLACS INSTALL directory successful")
    else()
        message(STATUS " Build Output:\n ${LOG2_OUT}")
        message(STATUS " Error Output:\n ${LOG2_ERR}")
        message(FATAL_ERROR " Build in the BLACS INSTALL directory FAILED")
    endif()
    # Clean up:
    file(REMOVE_RECURSE ${_build_dir}/CMakeCache.txt)
    file(REMOVE_RECURSE ${_build_dir}/CMakeFiles )
endfunction()

macro(fortran_mangling CDEFS)
    if(gen_is_multiconfig)
        set(_path ${_build_dir}/$<CONFIG>)
    else()
        set(_path ${_build_dir})
    endif()
    message(STATUS "=========")
    message(STATUS "Testing FORTRAN_MANGLING")

    execute_process(COMMAND ${_path}/xintface
        RESULT_VARIABLE xintface_RES
        OUTPUT_VARIABLE xintface_OUT
        ERROR_VARIABLE xintface_ERR)

#    MESSAGE(STATUS "FORTRAN MANGLING:RUN \n${xintface_OUT}")

    if (xintface_RES EQUAL 0)
        string(REPLACE "\n" "" xintface_OUT "${xintface_OUT}")
        message(STATUS "CDEFS set to ${xintface_OUT}")
        set(CDEFS ${xintface_OUT} CACHE STRING "Fortran Mangling" FORCE)
    else()
        message(STATUS " xintface Output:\n ${xintface_OUT}")
        message(FATAL_ERROR "FORTRAN_MANGLING:ERROR ${xintface_ERR}")
    endif()
endmacro()
