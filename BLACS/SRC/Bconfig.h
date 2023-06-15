/*
 *  This file includes the standard C libraries, as well as system dependant
 *  include files.  All BLACS routines include this file.
 */

#ifndef BCONFIG_H
#define BCONFIG_H 1

/*
 * Include files
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <mpi.h>

/*
 * Integer types used by BLACS
 */
#ifndef Int
#define Int int
#endif
#ifndef MpiInt
#define MpiInt int
#endif

/*
 *  Uncomment these macro definitions, and substitute the topology of your
 *  choice to vary the default topology (TOP = ' ') for broadcast and combines.
#define DefBSTop '1'
#define DefCombTop '1'
 */

/*
 * Uncomment this line if your MPI_Send provides a locally-blocking send
 */
//#define SndIsLocBlk

/*
 * Comment out the following line if your MPI does a data copy on every
 * non-contiguous send
 */
#define MpiBuffGood

/*
 * If your MPI cannot form data types of zero length, uncomment the
 * following definition
 */
/* #define ZeroByteTypeBug */

/*
 *  These macros set the timing and debug levels for the BLACS.  The fastest
 *  code is produced by setting both values to 0.  Higher levels provide
 *  more timing/debug information at the cost of performance.  Present levels
 *  of debug are:
 *  0 : No debug information
 *  1 : Mainly parameter checking.
 *
 *  Present levels of timing are:
 *  0 : No timings taken
 */
#ifndef BlacsDebugLvl
#define BlacsDebugLvl 0
#endif
#ifndef BlacsTimingLvl
#define BlacsTimingLvl 0
#endif

#endif
