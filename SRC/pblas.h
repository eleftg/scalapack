/* ---------------------------------------------------------------------
*
*  -- ScaLAPACK routine (version 1.0) --
*     University of Tennessee, Knoxville, Oak Ridge National Laboratory,
*     and University of California, Berkeley.
*     November 17, 1996
*
*  ---------------------------------------------------------------------
*/

/*
* This file includes the standard C libraries, as well as system
* dependent include files.  All PBLAS routines include this file.
*/

/*
* ========================================================================
* Machine Specific PBLAS macros
* ========================================================================
*/

#define _HAL_           0
#define _T3D_           1

#ifdef T3D
#define _MACH_          _T3D_
#endif

#ifndef _MACH_
#define _MACH_          _HAL_
#endif

/*
* ========================================================================
* Include files
* ========================================================================
*/
#include <FCMangle.h>
#include <stdio.h>
#include <stdlib.h>

#if( _MACH_ == _T3D_ )
#include <fortran.h>
#endif

/*
* ========================================================================
* TYPE DEFINITIONS AND CONVERSION UTILITIES
* ========================================================================
*/

#ifndef Int
#define Int int
#endif

typedef struct { float  re, im; } complex;
typedef struct { double re, im; } complex16;

#if( _MACH_ == _T3D_ )
#define float  double
                       /* Type of character argument in a FORTRAN call */
#define F_CHAR          _fcd
                                     /* Character conversion utilities */
#define F2C_CHAR(a)     ( _fcdtocp( (a) ) )
#define C2F_CHAR(a)     ( _cptofcd( (a), 1 ) )
                                          /* Type of FORTRAN functions */
#define F_VOID_FCT      void   fortran                   /* Subroutine */
#define F_INTG_FCT      Int    fortran             /* INTEGER function */
#define F_DBLE_FCT      double fortran    /* DOUBLE PRECISION function */

#else
                       /* Type of character argument in a FORTRAN call */
typedef char *          F_CHAR;
                                     /* Character conversion utilities */
#define F2C_CHAR(a)     (a)
#define C2F_CHAR(a)     (a)
                                          /* Type of FORTRAN functions */
#define F_VOID_FCT      void                             /* Subroutine */
#define F_INTG_FCT      Int                        /* INTEGER function */
#define F_DBLE_FCT      double            /* DOUBLE PRECISION function */

#endif

/*
* ========================================================================
* #DEFINE MACRO CONSTANTS
* ========================================================================
*/
#define    DLEN_        9                     /* Length of a descriptor */
#define    DT_          0                     /* Descriptor Type        */
#define    CTXT_        1                              /* BLACS context */
#define    M_           2                      /* Global Number of Rows */
#define    N_           3                   /* Global Number of Columns */
#define    MB_          4                          /* Row Blocking Size */
#define    NB_          5                       /* Column Blocking Size */
#define    RSRC_        6                     /* Starting Processor Row */
#define    CSRC_        7                  /* Starting Processor Column */
#define    LLD_         8                    /* Local Leading Dimension */

/*
 * Descriptor types
 */
#define    BLOCK_CYCLIC_2D                1
#define    BLOCK_CYCLIC_INB_2D            2

#define    BROADCAST    "B"              /* Blacs operation definitions */
#define    COMBINE      "C"

#define    ALL          "A"                        /* Scope definitions */
#define    COLUMN       "C"
#define    ROW          "R"

#define    TOPDEF       " " /* Default BLACS topology, PB-BLAS routines */
#define    CTOPDEF      ' '
#define    TOPGET       "!"

#define    YES          "Y"
#define    NO           "N"

#define    MULLENFAC    2

#define    ONE          1.0
#define    ZERO         0.0

/*
* ========================================================================
* PREPROCESSOR MACRO FUNCTIONS USED FOR OPTIMIZATION & CONVENIENCE
* ========================================================================
*/

#define ABS(a)   (((a) < 0) ? -(a) : (a))

#define MIN(a,b) (((a) < (b)) ? (a) : (b))

#define MAX(a,b) (((a) > (b)) ? (a) : (b))

#define CEIL(a,b) ( ((a)+(b)-1) / (b) )

#define Mlowcase(C) ( ((C) > 64 && (C) < 91) ? (C) | 32 : (C) )

#define Mupcase(C) ( ((C) > 96 && (C) < 123) ? (C) & 0xDF : (C) )

#define INDXG2L( iglob, nb, iproc, isrcproc, nprocs )\
    ( (nb) * ( ( (iglob)-1) / ( (nb) * (nprocs) ) ) +\
      ( ( (iglob) - 1 ) % (nb) ) + 1 )

#define INDXL2G( iloc, nb, iproc, isrcproc, nprocs )\
    ( (nprocs) * (nb) * ( ( (iloc) - 1 ) / (nb) ) +\
      ( ( (iloc) - 1 ) % (nb) ) +\
      ( ( (nprocs) + (iproc) - (isrcproc) ) % (nprocs) ) * (nb) + 1 )

#define INDXG2P( iglob, nb, iproc, isrcproc, nprocs ) \
    ( ( (isrcproc) + ( (iglob) - 1 ) / (nb) ) % (nprocs) )

#define MYROC0( nblocks, n, nb, nprocs )\
  ( ( (nblocks) % (nprocs) ) ? ( ( (nblocks) / (nprocs) ) * (nb) + (nb) )\
                   : ( ( (nblocks) / (nprocs) )* (nb) + ( (n) % (nb) ) ) )


#define ilcm_             FC_GLOBAL(ilcm, ILCM)
#define infog2l_          FC_GLOBAL(infog2l, INFOG2L)
#define numroc_           FC_GLOBAL(numroc, NUMROC)
#define pstreecomb_       FC_GLOBAL(pstreecomb, PSTREECOMB)
#define pdtreecomb_       FC_GLOBAL(pdtreecomb, PDTREECOMB)
#define pctreecomb_       FC_GLOBAL(pctreecomb, PCTREECOMB)
#define pztreecomb_       FC_GLOBAL(pztreecomb, PZTREECOMB)
#define scombamax_        FC_GLOBAL(scombamax, SCOMBAMAX)
#define dcombamax_        FC_GLOBAL(dcombamax, DCOMBAMAX)
#define ccombamax_        FC_GLOBAL(ccombamax, CCOMBAMAX)
#define zcombamax_        FC_GLOBAL(zcombamax, ZCOMBAMAX)
#define scombnrm2_        FC_GLOBAL(scombnrm2, SCOMBNRM2)
#define dcombnrm2_        FC_GLOBAL(dcombnrm2, DCOMBNRM2)

#define dlamov_           FC_GLOBAL(dlamov, DLAMOV)
#define slamov_           FC_GLOBAL(slamov, SLAMOV)
#define clamov_           FC_GLOBAL(clamov, CLAMOV)
#define zlamov_           FC_GLOBAL(zlamov, ZLAMOV)
#define dlacpy_           FC_GLOBAL(dlacpy, DLACPY)
#define slacpy_           FC_GLOBAL(slacpy, SLACPY)
#define clacpy_           FC_GLOBAL(clacpy, CLACPY)
#define zlacpy_           FC_GLOBAL(zlacpy, ZLACPY)
#define xerbla_           FC_GLOBAL(xerbla, XERBLA)
                                                            /* BLACS */
#define blacs_abort_      FC_GLOBAL_(blacs_abort, BLACS_ABORT)
#define blacs_gridinfo_   FC_GLOBAL_(blacs_gridinfo, BLACS_GRIDINFO)

#define igesd2d_          FC_GLOBAL(igesd2d, IGESD2D)
#define igebs2d_          FC_GLOBAL(igebs2d, IGEBS2D)
#define itrsd2d_          FC_GLOBAL(itrsd2d, ITRSD2D)
#define itrbs2d_          FC_GLOBAL(itrbs2d, ITRBS2D)
#define igerv2d_          FC_GLOBAL(igerv2d, IGERV2D)
#define igebr2d_          FC_GLOBAL(igebr2d, IGEBR2D)
#define itrrv2d_          FC_GLOBAL(itrrv2d, ITRRV2D)
#define itrbr2d_          FC_GLOBAL(itrbr2d, ITRBR2D)
#define igamx2d_          FC_GLOBAL(igamx2d, IGAMX2D)
#define igamn2d_          FC_GLOBAL(igamn2d, IGAMN2D)
#define igsum2d_          FC_GLOBAL(igsum2d, IGSUM2D)

#define sgesd2d_          FC_GLOBAL(sgesd2d, SGESD2D)
#define sgebs2d_          FC_GLOBAL(sgebs2d, SGEBS2D)
#define strsd2d_          FC_GLOBAL(strsd2d, STRSD2D)
#define strbs2d_          FC_GLOBAL(strbs2d, STRBS2D)
#define sgerv2d_          FC_GLOBAL(sgerv2d, SGERV2D)
#define sgebr2d_          FC_GLOBAL(sgebr2d, SGEBR2D)
#define strrv2d_          FC_GLOBAL(strrv2d, STRRV2D)
#define strbr2d_          FC_GLOBAL(strbr2d, STRBR2D)
#define sgamx2d_          FC_GLOBAL(sgamx2d, SGAMX2D)
#define sgamn2d_          FC_GLOBAL(sgamn2d, SGAMN2D)
#define sgsum2d_          FC_GLOBAL(sgsum2d, SGSUM2D)

#define dgesd2d_          FC_GLOBAL(dgesd2d, DGESD2D)
#define dgebs2d_          FC_GLOBAL(dgebs2d, DGEBS2D)
#define dtrsd2d_          FC_GLOBAL(dtrsd2d, DTRSD2D)
#define dtrbs2d_          FC_GLOBAL(dtrbs2d, DTRBS2D)
#define dgerv2d_          FC_GLOBAL(dgerv2d, DGERV2D)
#define dgebr2d_          FC_GLOBAL(dgebr2d, DGEBR2D)
#define dtrrv2d_          FC_GLOBAL(dtrrv2d, DTRRV2D)
#define dtrbr2d_          FC_GLOBAL(dtrbr2d, DTRBR2D)
#define dgamx2d_          FC_GLOBAL(dgamx2d, DGAMX2D)
#define dgamn2d_          FC_GLOBAL(dgamn2d, DGAMN2D)
#define dgsum2d_          FC_GLOBAL(dgsum2d, DGSUM2D)

#define cgesd2d_          FC_GLOBAL(cgesd2d, CGESD2D)
#define cgebs2d_          FC_GLOBAL(cgebs2d, CGEBS2D)
#define ctrsd2d_          FC_GLOBAL(ctrsd2d, CTRSD2D)
#define ctrbs2d_          FC_GLOBAL(ctrbs2d, CTRBS2D)
#define cgerv2d_          FC_GLOBAL(cgerv2d, CGERV2D)
#define cgebr2d_          FC_GLOBAL(cgebr2d, CGEBR2D)
#define ctrrv2d_          FC_GLOBAL(ctrrv2d, CTRRV2D)
#define ctrbr2d_          FC_GLOBAL(ctrbr2d, CTRBR2D)
#define cgamx2d_          FC_GLOBAL(cgamx2d, CGAMX2D)
#define cgamn2d_          FC_GLOBAL(cgamn2d, CGAMN2D)
#define cgsum2d_          FC_GLOBAL(cgsum2d, CGSUM2D)

#define zgesd2d_          FC_GLOBAL(zgesd2d, ZGESD2D)
#define zgebs2d_          FC_GLOBAL(zgebs2d, ZGEBS2D)
#define ztrsd2d_          FC_GLOBAL(ztrsd2d, ZTRSD2D)
#define ztrbs2d_          FC_GLOBAL(ztrbs2d, ZTRBS2D)
#define zgerv2d_          FC_GLOBAL(zgerv2d, ZGERV2D)
#define zgebr2d_          FC_GLOBAL(zgebr2d, ZGEBR2D)
#define ztrrv2d_          FC_GLOBAL(ztrrv2d, ZTRRV2D)
#define ztrbr2d_          FC_GLOBAL(ztrbr2d, ZTRBR2D)
#define zgamx2d_          FC_GLOBAL(zgamx2d, ZGAMX2D)
#define zgamn2d_          FC_GLOBAL(zgamn2d, ZGAMN2D)
#define zgsum2d_          FC_GLOBAL(zgsum2d, ZGSUM2D)
                                                     /* Level-1 BLAS */
#define srotg_            FC_GLOBAL(srotg, SROTG)
#define srotmg_           FC_GLOBAL(srotmg, SROTMG)
#define srot_             FC_GLOBAL(srot, SROT)
#define srotm_            FC_GLOBAL(srotm, SROTM)
#define sswap_            FC_GLOBAL(sswap, SSWAP)
#define sscal_            FC_GLOBAL(sscal, SSCAL)
#define scopy_            FC_GLOBAL(scopy, SCOPY)
#define saxpy_            FC_GLOBAL(saxpy, SAXPY)
#define ssdot_            FC_GLOBAL(ssdot, SSDOT)
#define isamax_           FC_GLOBAL(isamax, ISAMAX)

#define drotg_            FC_GLOBAL(drotg, DROTG)
#define drotmg_           FC_GLOBAL(drotmg, DROTMG)
#define drot_             FC_GLOBAL(drot, DROT)
#define drotm_            FC_GLOBAL(drotm, DROTM)
#define dswap_            FC_GLOBAL(dswap, DSWAP)
#define dscal_            FC_GLOBAL(dscal, DSCAL)
#define dcopy_            FC_GLOBAL(dcopy, DCOPY)
#define daxpy_            FC_GLOBAL(daxpy, DAXPY)
#define dddot_            FC_GLOBAL(dddot, DDDOT)
#define dnrm2_            FC_GLOBAL(dnrm2, DNRM2)
#define dsnrm2_           FC_GLOBAL(dsnrm2, DSNRM2)
#define dasum_            FC_GLOBAL(dasum, DASUM)
#define dsasum_           FC_GLOBAL(dsasum, DSASUM)
#define idamax_           FC_GLOBAL(idamax, IDAMAX)

#define cswap_            FC_GLOBAL(cswap, CSWAP)
#define cscal_            FC_GLOBAL(cscal, CSCAL)
#define csscal_           FC_GLOBAL(csscal, CSSCAL)
#define ccopy_            FC_GLOBAL(ccopy, CCOPY)
#define caxpy_            FC_GLOBAL(caxpy, CAXPY)
#define ccdotu_           FC_GLOBAL(ccdotu, CCDOTU)
#define ccdotc_           FC_GLOBAL(ccdotc, CCDOTC)
#define icamax_           FC_GLOBAL(icamax, ICAMAX)

#define zswap_            FC_GLOBAL(zswap, ZSWAP)
#define zscal_            FC_GLOBAL(zscal, ZSCAL)
#define zdscal_           FC_GLOBAL(zdscal, ZDSCAL)
#define zcopy_            FC_GLOBAL(zcopy, ZCOPY)
#define zaxpy_            FC_GLOBAL(zaxpy, ZAXPY)
#define zzdotu_           FC_GLOBAL(zzdotu, ZZDOTU)
#define zzdotc_           FC_GLOBAL(zzdotc, ZZDOTC)
#define dscnrm2_          FC_GLOBAL(dscnrm2, DSCNRM2)
#define dznrm2_           FC_GLOBAL(dznrm2, DZNRM2)
#define dscasum_          FC_GLOBAL(dscasum, DSCASUM)
#define dzasum_           FC_GLOBAL(dzasum, DZASUM)
#define izamax_           FC_GLOBAL(izamax, IZAMAX)
                                                     /* Level-2 BLAS */
#define sgemv_            FC_GLOBAL(sgemv, SGEMV)
#define ssymv_            FC_GLOBAL(ssymv, SSYMV)
#define strmv_            FC_GLOBAL(strmv, STRMV)
#define strsv_            FC_GLOBAL(strsv, STRSV)
#define sger_             FC_GLOBAL(sger, SGER)
#define ssyr_             FC_GLOBAL(ssyr, SSYR)
#define ssyr2_            FC_GLOBAL(ssyr2, SSYR2)

#define dgemv_            FC_GLOBAL(dgemv, DGEMV)
#define dsymv_            FC_GLOBAL(dsymv, DSYMV)
#define dtrmv_            FC_GLOBAL(dtrmv, DTRMV)
#define dtrsv_            FC_GLOBAL(dtrsv, DTRSV)
#define dger_             FC_GLOBAL(dger, DGER)
#define dsyr_             FC_GLOBAL(dsyr, DSYR)
#define dsyr2_            FC_GLOBAL(dsyr2, DSYR2)

#define cgemv_            FC_GLOBAL(cgemv, CGEMV)
#define chemv_            FC_GLOBAL(chemv, CHEMV)
#define ctrmv_            FC_GLOBAL(ctrmv, CTRMV)
#define ctrsv_            FC_GLOBAL(ctrsv, CTRSV)
#define cgeru_            FC_GLOBAL(cgeru, CGERU)
#define cgerc_            FC_GLOBAL(cgerc, CGERC)
#define cher_             FC_GLOBAL(cher, CHER)
#define cher2_            FC_GLOBAL(cher2, CHER2)

#define zgemv_            FC_GLOBAL(zgemv, ZGEMV)
#define zhemv_            FC_GLOBAL(zhemv, ZHEMV)
#define ztrmv_            FC_GLOBAL(ztrmv, ZTRMV)
#define ztrsv_            FC_GLOBAL(ztrsv, ZTRSV)
#define zgeru_            FC_GLOBAL(zgeru, ZGERU)
#define zgerc_            FC_GLOBAL(zgerc, ZGERC)
#define zher_             FC_GLOBAL(zher, ZHER)
#define zher2_            FC_GLOBAL(zher2, ZHER2)
                                                     /* Level-3 BLAS */
#define sgemm_            FC_GLOBAL(sgemm, SGEMM)
#define ssymm_            FC_GLOBAL(ssymm, SSYMM)
#define ssyrk_            FC_GLOBAL(ssyrk, SSYRK)
#define ssyr2k_           FC_GLOBAL(ssyr2k, SSYR2K)
#define strmm_            FC_GLOBAL(strmm, STRMM)
#define strsm_            FC_GLOBAL(strsm, STRSM)

#define dgemm_            FC_GLOBAL(dgemm, DGEMM)
#define dsymm_            FC_GLOBAL(dsymm, DSYMM)
#define dsyrk_            FC_GLOBAL(dsyrk, DSYRK)
#define dsyr2k_           FC_GLOBAL(dsyr2k, DSYR2K)
#define dtrmm_            FC_GLOBAL(dtrmm, DTRMM)
#define dtrsm_            FC_GLOBAL(dtrsm, DTRSM)

#define cgemm_            FC_GLOBAL(cgemm, CGEMM)
#define chemm_            FC_GLOBAL(chemm, CHEMM)
#define csymm_            FC_GLOBAL(csymm, CSYMM)
#define csyrk_            FC_GLOBAL(csyrk, CSYRK)
#define cherk_            FC_GLOBAL(cherk, CHERK)
#define csyr2k_           FC_GLOBAL(csyr2k, CSYR2K)
#define cher2k_           FC_GLOBAL(cher2k, CHER2K)
#define ctrmm_            FC_GLOBAL(ctrmm, CTRMM)
#define ctrsm_            FC_GLOBAL(ctrsm, CTRSM)

#define zgemm_            FC_GLOBAL(zgemm, ZGEMM)
#define zhemm_            FC_GLOBAL(zhemm, ZHEMM)
#define zsymm_            FC_GLOBAL(zsymm, ZSYMM)
#define zsyrk_            FC_GLOBAL(zsyrk, ZSYRK)
#define zherk_            FC_GLOBAL(zherk, ZHERK)
#define zsyr2k_           FC_GLOBAL(zsyr2k, ZSYR2K)
#define zher2k_           FC_GLOBAL(zher2k, ZHER2K)
#define ztrmm_            FC_GLOBAL(ztrmm, ZTRMM)
#define ztrsm_            FC_GLOBAL(ztrsm, ZTRSM)
                                   /* absolute value auxiliary PBLAS */
#define psatrmv_          FC_GLOBAL(psatrmv, PSATRMV)
#define pdatrmv_          FC_GLOBAL(pdatrmv, PDATRMV)
#define pcatrmv_          FC_GLOBAL(pcatrmv, PCATRMV)
#define pzatrmv_          FC_GLOBAL(pzatrmv, PZATRMV)
#define psagemv_          FC_GLOBAL(psagemv, PSAGEMV)
#define pdagemv_          FC_GLOBAL(pdagemv, PDAGEMV)
#define pcagemv_          FC_GLOBAL(pcagemv, PCAGEMV)
#define pzagemv_          FC_GLOBAL(pzagemv, PZAGEMV)
#define psasymv_          FC_GLOBAL(psasymv, PSASYMV)
#define pdasymv_          FC_GLOBAL(pdasymv, PDASYMV)
#define pcahemv_          FC_GLOBAL(pcahemv, PCAHEMV)
#define pzahemv_          FC_GLOBAL(pzahemv, PZAHEMV)
                                                /* Auxiliary PB-BLAS */
#define pbcmatadd_        FC_GLOBAL(pbcmatadd, PBCMATADD)
#define pbdmatadd_        FC_GLOBAL(pbdmatadd, PBDMATADD)
#define pbsmatadd_        FC_GLOBAL(pbsmatadd, PBSMATADD)
#define pbzmatadd_        FC_GLOBAL(pbzmatadd, PBZMATADD)
                                                   /* Level-2 PBBLAS */
#define pbcgemv_          FC_GLOBAL(pbcgemv, PBCGEMV)
#define pbcgeru_          FC_GLOBAL(pbcgeru, PBCGERU)
#define pbcgerc_          FC_GLOBAL(pbcgerc, PBCGERC)
#define pbchemv_          FC_GLOBAL(pbchemv, PBCHEMV)
#define pbcher_           FC_GLOBAL(pbcher, PBCHER)
#define pbcher2_          FC_GLOBAL(pbcher2, PBCHER2)
#define pbctrmv_          FC_GLOBAL(pbctrmv, PBCTRMV)
#define pbctrnv_          FC_GLOBAL(pbctrnv, PBCTRNV)
#define pbctrsv_          FC_GLOBAL(pbctrsv, PBCTRSV)

#define pbdgemv_          FC_GLOBAL(pbdgemv, PBDGEMV)
#define pbdger_           FC_GLOBAL(pbdger, PBDGER)
#define pbdsymv_          FC_GLOBAL(pbdsymv, PBDSYMV)
#define pbdsyr_           FC_GLOBAL(pbdsyr, PBDSYR)
#define pbdsyr2_          FC_GLOBAL(pbdsyr2, PBDSYR2)
#define pbdtrmv_          FC_GLOBAL(pbdtrmv, PBDTRMV)
#define pbdtrnv_          FC_GLOBAL(pbdtrnv, PBDTRNV)
#define pbdtrsv_          FC_GLOBAL(pbdtrsv, PBDTRSV)

#define pbsgemv_          FC_GLOBAL(pbsgemv, PBSGEMV)
#define pbsger_           FC_GLOBAL(pbsger, PBSGER)
#define pbssymv_          FC_GLOBAL(pbssymv, PBSSYMV)
#define pbssyr_           FC_GLOBAL(pbssyr, PBSSYR)
#define pbssyr2_          FC_GLOBAL(pbssyr2, PBSSYR2)
#define pbstrmv_          FC_GLOBAL(pbstrmv, PBSTRMV)
#define pbstrnv_          FC_GLOBAL(pbstrnv, PBSTRNV)
#define pbstrsv_          FC_GLOBAL(pbstrsv, PBSTRSV)

#define pbzgemv_          FC_GLOBAL(pbzgemv, PBZGEMV)
#define pbzgeru_          FC_GLOBAL(pbzgeru, PBZGERU)
#define pbzgerc_          FC_GLOBAL(pbzgerc, PBZGERC)
#define pbzhemv_          FC_GLOBAL(pbzhemv, PBZHEMV)
#define pbzher_           FC_GLOBAL(pbzher, PBZHER)
#define pbzher2_          FC_GLOBAL(pbzher2, PBZHER2)
#define pbztrmv_          FC_GLOBAL(pbztrmv, PBZTRMV)
#define pbztrnv_          FC_GLOBAL(pbztrnv, PBZTRNV)
#define pbztrsv_          FC_GLOBAL(pbztrsv, PBZTRSV)
                                                   /* Level-3 PBBLAS */
#define pbcgemm_          FC_GLOBAL(pbcgemm, PBCGEMM)
#define pbchemm_          FC_GLOBAL(pbchemm, PBCHEMM)
#define pbcher2k_         FC_GLOBAL(pbcher2k, PBCHER2K)
#define pbcherk_          FC_GLOBAL(pbcherk, PBCHERK)
#define pbcsymm_          FC_GLOBAL(pbcsymm, PBCSYMM)
#define pbcsyr2k_         FC_GLOBAL(pbcsyr2k, PBCSYR2K)
#define pbcsyrk_          FC_GLOBAL(pbcsyrk, PBCSYRK)
#define pbctrmm_          FC_GLOBAL(pbctrmm, PBCTRMM)
#define pbctrsm_          FC_GLOBAL(pbctrsm, PBCTRSM)
#define pbctran_          FC_GLOBAL(pbctran, PBCTRAN)

#define pbdgemm_          FC_GLOBAL(pbdgemm, PBDGEMM)
#define pbdsymm_          FC_GLOBAL(pbdsymm, PBDSYMM)
#define pbdsyr2k_         FC_GLOBAL(pbdsyr2k, PBDSYR2K)
#define pbdsyrk_          FC_GLOBAL(pbdsyrk, PBDSYRK)
#define pbdtrmm_          FC_GLOBAL(pbdtrmm, PBDTRMM)
#define pbdtrsm_          FC_GLOBAL(pbdtrsm, PBDTRSM)
#define pbdtran_          FC_GLOBAL(pbdtran, PBDTRAN)

#define pbsgemm_          FC_GLOBAL(pbsgemm, PBSGEMM)
#define pbssymm_          FC_GLOBAL(pbssymm, PBSSYMM)
#define pbssyr2k_         FC_GLOBAL(pbssyr2k, PBSSYR2K)
#define pbssyrk_          FC_GLOBAL(pbssyrk, PBSSYRK)
#define pbstrmm_          FC_GLOBAL(pbstrmm, PBSTRMM)
#define pbstrsm_          FC_GLOBAL(pbstrsm, PBSTRSM)
#define pbstran_          FC_GLOBAL(pbstran, PBSTRAN)

#define pbzgemm_          FC_GLOBAL(pbzgemm, PBZGEMM)
#define pbzhemm_          FC_GLOBAL(pbzhemm, PBZHEMM)
#define pbzher2k_         FC_GLOBAL(pbzher2k, PBZHER2K)
#define pbzherk_          FC_GLOBAL(pbzherk, PBZHERK)
#define pbzsymm_          FC_GLOBAL(pbzsymm, PBZSYMM)
#define pbzsyr2k_         FC_GLOBAL(pbzsyr2k, PBZSYR2K)
#define pbzsyrk_          FC_GLOBAL(pbzsyrk, PBZSYRK)
#define pbztrmm_          FC_GLOBAL(pbztrmm, PBZTRMM)
#define pbztrsm_          FC_GLOBAL(pbztrsm, PBZTRSM)
#define pbztran_          FC_GLOBAL(pbztran, PBZTRAN)
                                                 /* Auxilliary PBLAS */
#define pberror_          FC_GLOBAL(pberror, PBERROR)
#define pb_freebuf_       FC_GLOBAL_(pb_freebuf, PB_FREEBUF)
#define pb_topget_        FC_GLOBAL_(pb_topget, PB_TOPGET)
#define pb_topset_        FC_GLOBAL_(pb_topset, PB_TOPSET)
                                                    /* Level-1 PBLAS */
#define psrotg_           FC_GLOBAL(psrotg, PSROTG)
#define psrotmg_          FC_GLOBAL(psrotmg, PSROTMG)
#define psrot_            FC_GLOBAL(psrot, PSROT)
#define psrotm_           FC_GLOBAL(psrotm, PSROTM)
#define psswap_           FC_GLOBAL(psswap, PSSWAP)
#define psscal_           FC_GLOBAL(psscal, PSSCAL)
#define pscopy_           FC_GLOBAL(pscopy, PSCOPY)
#define psaxpy_           FC_GLOBAL(psaxpy, PSAXPY)
#define psdot_            FC_GLOBAL(psdot, PSDOT)
#define psnrm2_           FC_GLOBAL(psnrm2, PSNRM2)
#define psasum_           FC_GLOBAL(psasum, PSASUM)
#define psamax_           FC_GLOBAL(psamax, PSAMAX)

#define pdrotg_           FC_GLOBAL(pdrotg, PDROTG)
#define pdrotmg_          FC_GLOBAL(pdrotmg, PDROTMG)
#define pdrot_            FC_GLOBAL(pdrot, PDROT)
#define pdrotm_           FC_GLOBAL(pdrotm, PDROTM)
#define pdswap_           FC_GLOBAL(pdswap, PDSWAP)
#define pdscal_           FC_GLOBAL(pdscal, PDSCAL)
#define pdcopy_           FC_GLOBAL(pdcopy, PDCOPY)
#define pdaxpy_           FC_GLOBAL(pdaxpy, PDAXPY)
#define pddot_            FC_GLOBAL(pddot, PDDOT)
#define pdnrm2_           FC_GLOBAL(pdnrm2, PDNRM2)
#define pdasum_           FC_GLOBAL(pdasum, PDASUM)
#define pdamax_           FC_GLOBAL(pdamax, PDAMAX)

#define pcswap_           FC_GLOBAL(pcswap, PCSWAP)
#define pcscal_           FC_GLOBAL(pcscal, PCSCAL)
#define pcsscal_          FC_GLOBAL(pcsscal, PCSSCAL)
#define pccopy_           FC_GLOBAL(pccopy, PCCOPY)
#define pcaxpy_           FC_GLOBAL(pcaxpy, PCAXPY)
#define pcdotu_           FC_GLOBAL(pcdotu, PCDOTU)
#define pcdotc_           FC_GLOBAL(pcdotc, PCDOTC)
#define pscnrm2_          FC_GLOBAL(pscnrm2, PSCNRM2)
#define pscasum_          FC_GLOBAL(pscasum, PSCASUM)
#define pcamax_           FC_GLOBAL(pcamax, PCAMAX)
#define pcrot_            FC_GLOBAL(pcrot, PCROT)
#define crot_             FC_GLOBAL(crot, CROT)

#define pzswap_           FC_GLOBAL(pzswap, PZSWAP)
#define pzscal_           FC_GLOBAL(pzscal, PZSCAL)
#define pzdscal_          FC_GLOBAL(pzdscal, PZDSCAL)
#define pzcopy_           FC_GLOBAL(pzcopy, PZCOPY)
#define pzaxpy_           FC_GLOBAL(pzaxpy, PZAXPY)
#define pzdotu_           FC_GLOBAL(pzdotu, PZDOTU)
#define pzdotc_           FC_GLOBAL(pzdotc, PZDOTC)
#define pdznrm2_          FC_GLOBAL(pdznrm2, PDZNRM2)
#define pdzasum_          FC_GLOBAL(pdzasum, PDZASUM)
#define pzamax_           FC_GLOBAL(pzamax, PZAMAX)
#define pzrot_            FC_GLOBAL(pzrot, PZROT)
#define zrot_             FC_GLOBAL(zrot, ZROT)
                                                    /* Level-2 PBLAS */
#define pcgemv_           FC_GLOBAL(pcgemv, PCGEMV)
#define pcgeru_           FC_GLOBAL(pcgeru, PCGERU)
#define pcgerc_           FC_GLOBAL(pcgerc, PCGERC)
#define pchemv_           FC_GLOBAL(pchemv, PCHEMV)
#define pcher_            FC_GLOBAL(pcher, PCHER)
#define pcher2_           FC_GLOBAL(pcher2, PCHER2)
#define pctrmv_           FC_GLOBAL(pctrmv, PCTRMV)
#define pctrsv_           FC_GLOBAL(pctrsv, PCTRSV)

#define pdgemv_           FC_GLOBAL(pdgemv, PDGEMV)
#define pdger_            FC_GLOBAL(pdger, PDGER)
#define pdsymv_           FC_GLOBAL(pdsymv, PDSYMV)
#define pdsyr_            FC_GLOBAL(pdsyr, PDSYR)
#define pdsyr2_           FC_GLOBAL(pdsyr2, PDSYR2)
#define pdtrmv_           FC_GLOBAL(pdtrmv, PDTRMV)
#define pdtrsv_           FC_GLOBAL(pdtrsv, PDTRSV)

#define psgemv_           FC_GLOBAL(psgemv, PSGEMV)
#define psger_            FC_GLOBAL(psger, PSGER)
#define pssymv_           FC_GLOBAL(pssymv, PSSYMV)
#define pssyr_            FC_GLOBAL(pssyr, PSSYR)
#define pssyr2_           FC_GLOBAL(pssyr2, PSSYR2)
#define pstrmv_           FC_GLOBAL(pstrmv, PSTRMV)
#define pstrsv_           FC_GLOBAL(pstrsv, PSTRSV)

#define pzgemv_           FC_GLOBAL(pzgemv, PZGEMV)
#define pzgeru_           FC_GLOBAL(pzgeru, PZGERU)
#define pzgerc_           FC_GLOBAL(pzgerc, PZGERC)
#define pzhemv_           FC_GLOBAL(pzhemv, PZHEMV)
#define pzher_            FC_GLOBAL(pzher, PZHER)
#define pzher2_           FC_GLOBAL(pzher2, PZHER2)
#define pztrmv_           FC_GLOBAL(pztrmv, PZTRMV)
#define pztrsv_           FC_GLOBAL(pztrsv, PZTRSV)
                                                    /* Level-3 PBLAS */
#define pcgemm_           FC_GLOBAL(pcgemm, PCGEMM)
#define pchemm_           FC_GLOBAL(pchemm, PCHEMM)
#define pcher2k_          FC_GLOBAL(pcher2k, PCHER2K)
#define pcherk_           FC_GLOBAL(pcherk, PCHERK)
#define pcsymm_           FC_GLOBAL(pcsymm, PCSYMM)
#define pcsyr2k_          FC_GLOBAL(pcsyr2k, PCSYR2K)
#define pcsyrk_           FC_GLOBAL(pcsyrk, PCSYRK)
#define pctrmm_           FC_GLOBAL(pctrmm, PCTRMM)
#define pctrsm_           FC_GLOBAL(pctrsm, PCTRSM)
#define pctranu_          FC_GLOBAL(pctranu, PCTRANU)
#define pctranc_          FC_GLOBAL(pctranc, PCTRANC)

#define pdgemm_           FC_GLOBAL(pdgemm, PDGEMM)
#define pdsymm_           FC_GLOBAL(pdsymm, PDSYMM)
#define pdsyr2k_          FC_GLOBAL(pdsyr2k, PDSYR2K)
#define pdsyrk_           FC_GLOBAL(pdsyrk, PDSYRK)
#define pdtrmm_           FC_GLOBAL(pdtrmm, PDTRMM)
#define pdtrsm_           FC_GLOBAL(pdtrsm, PDTRSM)
#define pdtran_           FC_GLOBAL(pdtran, PDTRAN)

#define psgemm_           FC_GLOBAL(psgemm, PSGEMM)
#define pssymm_           FC_GLOBAL(pssymm, PSSYMM)
#define pssyr2k_          FC_GLOBAL(pssyr2k, PSSYR2K)
#define pssyrk_           FC_GLOBAL(pssyrk, PSSYRK)
#define pstrmm_           FC_GLOBAL(pstrmm, PSTRMM)
#define pstrsm_           FC_GLOBAL(pstrsm, PSTRSM)
#define pstran_           FC_GLOBAL(pstran, PSTRAN)

#define pzgemm_           FC_GLOBAL(pzgemm, PZGEMM)
#define pzhemm_           FC_GLOBAL(pzhemm, PZHEMM)
#define pzher2k_          FC_GLOBAL(pzher2k, PZHER2K)
#define pzherk_           FC_GLOBAL(pzherk, PZHERK)
#define pzsymm_           FC_GLOBAL(pzsymm, PZSYMM)
#define pzsyr2k_          FC_GLOBAL(pzsyr2k, PZSYR2K)
#define pzsyrk_           FC_GLOBAL(pzsyrk, PZSYRK)
#define pztrmm_           FC_GLOBAL(pztrmm, PZTRMM)
#define pztrsm_           FC_GLOBAL(pztrsm, PZTRSM)
#define pztranu_          FC_GLOBAL(pztranu, PZTRANU)
#define pztranc_          FC_GLOBAL(pztranc, PZTRANC)
