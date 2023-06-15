/* ---------------------------------------------------------------------
*
*  -- PBLAS routine (version 2.0) --
*     University of Tennessee, Knoxville, Oak Ridge National Laboratory,
*     and University of California, Berkeley.
*     April 1, 1998
*
*  ---------------------------------------------------------------------
*/
/*
*  This file includes F77 BLAS definitions. All  PBLAS  routines include
*  this file.
*
*  ---------------------------------------------------------------------
*  #define macro constants
*  ---------------------------------------------------------------------
*/
#include <FCMangle.h>

#define    CNOTRAN             'N'
#define    CNOCONJG            'N'
#define    CTRAN               'T'
#define    CCONJG              'Z'
#define    CCOTRAN             'C'

#define    CALL                'A'
#define    CLOWER              'L'
#define    CUPPER              'U'
#define    CDIAGONAL           'D'

#define    CLEFT               'L'
#define    CRIGHT              'R'

#define    CUNIT               'U'
#define    CNOUNIT             'N'

#define    CINIT               'I'
#define    CNOINIT             'N'

#define    CFORWARD            'F'
#define    CBACKWARD           'B'

#define    CREUSE              'R'
#define    CALLOCATE           'A'

#define    NOTRAN              "N"
#define    NOCONJG             "N"
#define    TRAN                "T"
#define    CONJG               "Z"
#define    COTRAN              "C"

#define    ALL                 "A"
#define    LOWER               "L"
#define    UPPER               "U"
#define    DIAGONAL            "D"

#define    LEFT                "L"
#define    RIGHT               "R"

#define    UNIT                "U"
#define    NOUNIT              "N"

#define    INIT                "I"
#define    NOINIT              "N"

#define    FORWARD             "F"
#define    BACKWARD            "B"

#define    REUSE               "R"
#define    ALLOCATE            "A"

#define    srot_        FC_GLOBAL(srot, SROT)
#define    drot_        FC_GLOBAL(drot, DROT)

#define    sswap_       FC_GLOBAL(sswap, SSWAP)
#define    dswap_       FC_GLOBAL(dswap, DSWAP)
#define    cswap_       FC_GLOBAL(cswap, CSWAP)
#define    zswap_       FC_GLOBAL(zswap, ZSWAP)

#define    scopy_       FC_GLOBAL(scopy, SCOPY)
#define    dcopy_       FC_GLOBAL(dcopy, DCOPY)
#define    ccopy_       FC_GLOBAL(ccopy, CCOPY)
#define    zcopy_       FC_GLOBAL(zcopy, ZCOPY)

#define    saxpy_       FC_GLOBAL(saxpy, SAXPY)
#define    daxpy_       FC_GLOBAL(daxpy, DAXPY)
#define    caxpy_       FC_GLOBAL(caxpy, CAXPY)
#define    zaxpy_       FC_GLOBAL(zaxpy, ZAXPY)

#define    sscal_       FC_GLOBAL(sscal, SSCAL)
#define    dscal_       FC_GLOBAL(dscal, DSCAL)
#define    cscal_       FC_GLOBAL(cscal, CSCAL)
#define    zscal_       FC_GLOBAL(zscal, ZSCAL)
#define    csscal_      FC_GLOBAL(csscal, CSSCAL)
#define    zdscal_      FC_GLOBAL(zdscal, ZDSCAL)

#define    sasum_       FC_GLOBAL(sasum, SASUM)
#define    dasum_       FC_GLOBAL(dasum, DASUM)
#define    scasum_      FC_GLOBAL(scasum, SCASUM)
#define    dzasum_      FC_GLOBAL(dzasum, DZASUM)

#define    snrm2_       FC_GLOBAL(snrm2, SNRM2)
#define    dnrm2_       FC_GLOBAL(dnrm2, DNRM2)
#define    scnrm2_      FC_GLOBAL(scnrm2, SCNRM2)
#define    dznrm2_      FC_GLOBAL(dznrm2, DZNRM2)

#define    sdot_        FC_GLOBAL(sdot, SDOT)
#define    ddot_        FC_GLOBAL(ddot, DDOT)
#define    cdotu_       FC_GLOBAL(cdotu, CDOTU)
#define    zdotu_       FC_GLOBAL(zdotu, ZDOTU)
#define    cdotc_       FC_GLOBAL(cdotc, CDOTC)
#define    zdotc_       FC_GLOBAL(zdotc, ZDOTC)

#define    isamax_      FC_GLOBAL(isamax, ISAMAX)
#define    idamax_      FC_GLOBAL(idamax, IDAMAX)
#define    icamax_      FC_GLOBAL(icamax, ICAMAX)
#define    izamax_      FC_GLOBAL(izamax, IZAMAX)

#define    sgemv_       FC_GLOBAL(sgemv, SGEMV)
#define    dgemv_       FC_GLOBAL(dgemv, DGEMV)
#define    cgemv_       FC_GLOBAL(cgemv, CGEMV)
#define    zgemv_       FC_GLOBAL(zgemv, ZGEMV)

#define    ssymv_       FC_GLOBAL(ssymv, SSYMV)
#define    dsymv_       FC_GLOBAL(dsymv, DSYMV)
#define    chemv_       FC_GLOBAL(chemv, CHEMV)
#define    zhemv_       FC_GLOBAL(zhemv, ZHEMV)

#define    strmv_       FC_GLOBAL(strmv, STRMV)
#define    dtrmv_       FC_GLOBAL(dtrmv, DTRMV)
#define    ctrmv_       FC_GLOBAL(ctrmv, CTRMV)
#define    ztrmv_       FC_GLOBAL(ztrmv, ZTRMV)

#define    strsv_       FC_GLOBAL(strsv, STRSV)
#define    dtrsv_       FC_GLOBAL(dtrsv, DTRSV)
#define    ctrsv_       FC_GLOBAL(ctrsv, CTRSV)
#define    ztrsv_       FC_GLOBAL(ztrsv, ZTRSV)

#define    sger_        FC_GLOBAL(sger, SGER)
#define    dger_        FC_GLOBAL(dger, DGER)
#define    cgeru_       FC_GLOBAL(cgeru, CGERU)
#define    zgeru_       FC_GLOBAL(zgeru, ZGERU)
#define    cgerc_       FC_GLOBAL(cgerc, CGERC)
#define    zgerc_       FC_GLOBAL(zgerc, ZGERC)

#define    ssyr_        FC_GLOBAL(ssyr, SSYR)
#define    dsyr_        FC_GLOBAL(dsyr, DSYR)
#define    cher_        FC_GLOBAL(cher, CHER)
#define    zher_        FC_GLOBAL(zher, ZHER)

#define    ssyr2_       FC_GLOBAL(ssyr2, SSYR2)
#define    dsyr2_       FC_GLOBAL(dsyr2, DSYR2)
#define    cher2_       FC_GLOBAL(cher2, CHER2)
#define    zher2_       FC_GLOBAL(zher2, ZHER2)

#define    sgemm_       FC_GLOBAL(sgemm, SGEMM)
#define    dgemm_       FC_GLOBAL(dgemm, DGEMM)
#define    cgemm_       FC_GLOBAL(cgemm, CGEMM)
#define    zgemm_       FC_GLOBAL(zgemm, ZGEMM)

#define    ssymm_       FC_GLOBAL(ssymm, SSYMM)
#define    dsymm_       FC_GLOBAL(dsymm, DSYMM)
#define    csymm_       FC_GLOBAL(csymm, CSYMM)
#define    chemm_       FC_GLOBAL(chemm, CHEMM)
#define    zsymm_       FC_GLOBAL(zsymm, ZSYMM)
#define    zhemm_       FC_GLOBAL(zhemm, ZHEMM)

#define    strmm_       FC_GLOBAL(strmm, STRMM)
#define    dtrmm_       FC_GLOBAL(dtrmm, DTRMM)
#define    ctrmm_       FC_GLOBAL(ctrmm, CTRMM)
#define    ztrmm_       FC_GLOBAL(ztrmm, ZTRMM)

#define    strsm_       FC_GLOBAL(strsm, STRSM)
#define    dtrsm_       FC_GLOBAL(dtrsm, DTRSM)
#define    ctrsm_       FC_GLOBAL(ctrsm, CTRSM)
#define    ztrsm_       FC_GLOBAL(ztrsm, ZTRSM)

#define    ssyrk_       FC_GLOBAL(ssyrk, SSYRK)
#define    dsyrk_       FC_GLOBAL(dsyrk, DSYRK)
#define    csyrk_       FC_GLOBAL(csyrk, CSYRK)
#define    cherk_       FC_GLOBAL(cherk, CHERK)
#define    zsyrk_       FC_GLOBAL(zsyrk, ZSYRK)
#define    zherk_       FC_GLOBAL(zherk, ZHERK)

#define    ssyr2k_      FC_GLOBAL(ssyr2k, SSYR2K)
#define    dsyr2k_      FC_GLOBAL(dsyr2k, DSYR2K)
#define    csyr2k_      FC_GLOBAL(csyr2k, CSYR2K)
#define    cher2k_      FC_GLOBAL(cher2k, CHER2K)
#define    zsyr2k_      FC_GLOBAL(zsyr2k, ZSYR2K)
#define    zher2k_      FC_GLOBAL(zher2k, ZHER2K)

/*
*  ---------------------------------------------------------------------
*  Function prototypes
*  ---------------------------------------------------------------------
*/
#ifdef __STDC__

Int            isamax_         ( Int *,     char *,    Int * );
Int            idamax_         ( Int *,     char *,    Int * );
Int            icamax_         ( Int *,     char *,    Int * );
Int            izamax_         ( Int *,     char *,    Int * );

F_VOID_FCT     saxpy_          ( Int *,     char *,    char *,
                                 Int *,     char *,    Int * );
F_VOID_FCT     daxpy_          ( Int *,     char *,    char *,
                                 Int *,     char *,    Int * );
F_VOID_FCT     caxpy_          ( Int *,     char *,    char *,
                                 Int *,     char *,    Int * );
F_VOID_FCT     zaxpy_          ( Int *,     char *,    char *,
                                 Int *,     char *,    Int * );

F_VOID_FCT     scopy_          ( Int *,     char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     dcopy_          ( Int *,     char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     ccopy_          ( Int *,     char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     zcopy_          ( Int *,     char *,    Int *,
                                 char *,    Int * );

F_VOID_FCT     sscal_          ( Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     dscal_          ( Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     cscal_          ( Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     csscal_         ( Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     zdscal_         ( Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     zscal_          ( Int *,     char *,    char *,
                                 Int * );

F_VOID_FCT     sswap_          ( Int *,     char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     dswap_          ( Int *,     char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     cswap_          ( Int *,     char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     zswap_          ( Int *,     char *,    Int *,
                                 char *,    Int * );

F_VOID_FCT     sgemv_          ( F_CHAR_T,  Int *,     Int *,
                                 char *,    char *,    Int *,
                                 char *,    Int *,     char *,
                                 char *,    Int * );
F_VOID_FCT     dgemv_          ( F_CHAR_T,  Int *,     Int *,
                                 char *,    char *,    Int *,
                                 char *,    Int *,     char *,
                                 char *,    Int * );
F_VOID_FCT     cgemv_          ( F_CHAR_T,  Int *,     Int *,
                                 char *,    char *,    Int *,
                                 char *,    Int *,     char *,
                                 char *,    Int * );
F_VOID_FCT     zgemv_          ( F_CHAR_T,  Int *,     Int *,
                                 char *,    char *,    Int *,
                                 char *,    Int *,     char *,
                                 char *,    Int * );

F_VOID_FCT     ssymv_          ( F_CHAR_T,  Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     dsymv_          ( F_CHAR_T,  Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     chemv_          ( F_CHAR_T,  Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     zhemv_          ( F_CHAR_T,  Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    char *,
                                 Int * );

F_VOID_FCT     strmv_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     dtrmv_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     ctrmv_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     ztrmv_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     char *,    Int *,
                                 char *,    Int * );

F_VOID_FCT     strsv_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     dtrsv_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     ctrsv_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     ztrsv_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     char *,    Int *,
                                 char *,    Int * );

F_VOID_FCT     sger_           ( Int *,     Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    Int * );
F_VOID_FCT     dger_           ( Int *,     Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    Int * );
F_VOID_FCT     cgerc_          ( Int *,     Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    Int * );
F_VOID_FCT     cgeru_          ( Int *,     Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    Int * );
F_VOID_FCT     zgerc_          ( Int *,     Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    Int * );
F_VOID_FCT     zgeru_          ( Int *,     Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    Int * );

F_VOID_FCT     ssyr_           ( F_CHAR_T,  Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int * );
F_VOID_FCT     dsyr_           ( F_CHAR_T,  Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int * );
F_VOID_FCT     cher_           ( F_CHAR_T,  Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int * );
F_VOID_FCT     zher_           ( F_CHAR_T,  Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int * );

F_VOID_FCT     ssyr2_          ( F_CHAR_T,  Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    Int * );
F_VOID_FCT     dsyr2_          ( F_CHAR_T,  Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    Int * );
F_VOID_FCT     cher2_          ( F_CHAR_T,  Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    Int * );
F_VOID_FCT     zher2_          ( F_CHAR_T,  Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    Int * );

F_VOID_FCT     sgemm_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     dgemm_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     cgemm_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     zgemm_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     Int *,     char *,
                                 char *,    Int *,     char *,
                                 Int *,     char *,    char *,
                                 Int * );

F_VOID_FCT     ssymm_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    Int *,
                                 char *,    char *,    Int * );
F_VOID_FCT     dsymm_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    Int *,
                                 char *,    char *,    Int * );
F_VOID_FCT     csymm_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    Int *,
                                 char *,    char *,    Int * );
F_VOID_FCT     zsymm_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    Int *,
                                 char *,    char *,    Int * );
F_VOID_FCT     chemm_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    Int *,
                                 char *,    char *,    Int * );
F_VOID_FCT     zhemm_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    Int *,
                                 char *,    char *,    Int * );

F_VOID_FCT     ssyrk_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     dsyrk_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     csyrk_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     zsyrk_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     cherk_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    char *,
                                 Int * );
F_VOID_FCT     zherk_          ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    char *,
                                 Int * );

F_VOID_FCT     ssyr2k_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    Int *,
                                 char *,    char *,    Int * );
F_VOID_FCT     dsyr2k_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    Int *,
                                 char *,    char *,    Int * );
F_VOID_FCT     csyr2k_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    Int *,
                                 char *,    char *,    Int * );
F_VOID_FCT     zsyr2k_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    Int *,
                                 char *,    char *,    Int * );
F_VOID_FCT     cher2k_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    Int *,
                                 char *,    char *,    Int * );
F_VOID_FCT     zher2k_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     char *,    char *,
                                 Int *,     char *,    Int *,
                                 char *,    char *,    Int * );

F_VOID_FCT     strmm_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 char *,    char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     dtrmm_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 char *,    char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     ctrmm_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 char *,    char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     ztrmm_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 char *,    char *,    Int *,
                                 char *,    Int * );

F_VOID_FCT     strsm_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 char *,    char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     dtrsm_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 char *,    char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     ctrsm_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 char *,    char *,    Int *,
                                 char *,    Int * );
F_VOID_FCT     ztrsm_          ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 char *,    char *,    Int *,
                                 char *,    Int * );

#else

Int            isamax_         ();
Int            idamax_         ();
Int            icamax_         ();
Int            izamax_         ();

F_VOID_FCT     saxpy_          ();
F_VOID_FCT     daxpy_          ();
F_VOID_FCT     caxpy_          ();
F_VOID_FCT     zaxpy_          ();

F_VOID_FCT     scopy_          ();
F_VOID_FCT     dcopy_          ();
F_VOID_FCT     ccopy_          ();
F_VOID_FCT     zcopy_          ();

F_VOID_FCT     sscal_          ();
F_VOID_FCT     dscal_          ();
F_VOID_FCT     cscal_          ();
F_VOID_FCT     csscal_         ();
F_VOID_FCT     zscal_          ();
F_VOID_FCT     zdscal_         ();

F_VOID_FCT     sswap_          ();
F_VOID_FCT     dswap_          ();
F_VOID_FCT     cswap_          ();
F_VOID_FCT     zswap_          ();

F_VOID_FCT     sgemv_          ();
F_VOID_FCT     dgemv_          ();
F_VOID_FCT     cgemv_          ();
F_VOID_FCT     zgemv_          ();

F_VOID_FCT     ssymv_          ();
F_VOID_FCT     dsymv_          ();
F_VOID_FCT     chemv_          ();
F_VOID_FCT     zhemv_          ();

F_VOID_FCT     strmv_          ();
F_VOID_FCT     dtrmv_          ();
F_VOID_FCT     ctrmv_          ();
F_VOID_FCT     ztrmv_          ();

F_VOID_FCT     strsv_          ();
F_VOID_FCT     dtrsv_          ();
F_VOID_FCT     ctrsv_          ();
F_VOID_FCT     ztrsv_          ();

F_VOID_FCT     sger_           ();
F_VOID_FCT     dger_           ();
F_VOID_FCT     cgerc_          ();
F_VOID_FCT     cgeru_          ();
F_VOID_FCT     zgerc_          ();
F_VOID_FCT     zgeru_          ();

F_VOID_FCT     ssyr_           ();
F_VOID_FCT     dsyr_           ();
F_VOID_FCT     cher_           ();
F_VOID_FCT     zher_           ();

F_VOID_FCT     ssyr2_          ();
F_VOID_FCT     dsyr2_          ();
F_VOID_FCT     cher2_          ();
F_VOID_FCT     zher2_          ();

F_VOID_FCT     sgemm_          ();
F_VOID_FCT     dgemm_          ();
F_VOID_FCT     cgemm_          ();
F_VOID_FCT     zgemm_          ();

F_VOID_FCT     ssymm_          ();
F_VOID_FCT     dsymm_          ();
F_VOID_FCT     csymm_          ();
F_VOID_FCT     zsymm_          ();
F_VOID_FCT     chemm_          ();
F_VOID_FCT     zhemm_          ();

F_VOID_FCT     ssyrk_          ();
F_VOID_FCT     dsyrk_          ();
F_VOID_FCT     csyrk_          ();
F_VOID_FCT     zsyrk_          ();
F_VOID_FCT     cherk_          ();
F_VOID_FCT     zherk_          ();

F_VOID_FCT     ssyr2k_         ();
F_VOID_FCT     dsyr2k_         ();
F_VOID_FCT     csyr2k_         ();
F_VOID_FCT     zsyr2k_         ();
F_VOID_FCT     cher2k_         ();
F_VOID_FCT     zher2k_         ();

F_VOID_FCT     strmm_          ();
F_VOID_FCT     dtrmm_          ();
F_VOID_FCT     ctrmm_          ();
F_VOID_FCT     ztrmm_          ();

F_VOID_FCT     strsm_          ();
F_VOID_FCT     dtrsm_          ();
F_VOID_FCT     ctrsm_          ();
F_VOID_FCT     ztrsm_          ();

#endif
