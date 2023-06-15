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
*  This file includes PBLAS definitions. All PBLAS routines include this
*  file.
*
*  ---------------------------------------------------------------------
*  #define macro constants
*  ---------------------------------------------------------------------
*/
#define    pilaenv_      FC_GLOBAL(pilaenv, PILAENV)
#define    PB_freebuf_   FC_GLOBAL_(pb_freebuf, PB_FREEBUF)
#define    PB_topget_    FC_GLOBAL_(pb_topget, PB_TOPGET)
#define    PB_topset_    FC_GLOBAL_(pb_topset, PB_TOPSET)

#define    picopy_       FC_GLOBAL(picopy, PICOPY)
#define    pscopy_       FC_GLOBAL(pscopy, PSCOPY)
#define    pdcopy_       FC_GLOBAL(pdcopy, PDCOPY)
#define    pccopy_       FC_GLOBAL(pccopy, PCCOPY)
#define    pzcopy_       FC_GLOBAL(pzcopy, PZCOPY)

#define    psswap_       FC_GLOBAL(psswap, PSSWAP)
#define    pdswap_       FC_GLOBAL(pdswap, PDSWAP)
#define    pcswap_       FC_GLOBAL(pcswap, PCSWAP)
#define    pzswap_       FC_GLOBAL(pzswap, PZSWAP)

#define    psaxpy_       FC_GLOBAL(psaxpy, PSAXPY)
#define    pdaxpy_       FC_GLOBAL(pdaxpy, PDAXPY)
#define    pcaxpy_       FC_GLOBAL(pcaxpy, PCAXPY)
#define    pzaxpy_       FC_GLOBAL(pzaxpy, PZAXPY)

#define    psscal_       FC_GLOBAL(psscal, PSSCAL)
#define    pdscal_       FC_GLOBAL(pdscal, PDSCAL)
#define    pcscal_       FC_GLOBAL(pcscal, PCSCAL)
#define    pzscal_       FC_GLOBAL(pzscal, PZSCAL)
#define    pcsscal_      FC_GLOBAL(pcsscal, PCSSCAL)
#define    pzdscal_      FC_GLOBAL(pzdscal, PZDSCAL)

#define    psasum_       FC_GLOBAL(psasum, PSASUM)
#define    pdasum_       FC_GLOBAL(pdasum, PDASUM)
#define    pscasum_      FC_GLOBAL(pscasum, PSCASUM)
#define    pdzasum_      FC_GLOBAL(pdzasum, PDZASUM)

#define    psnrm2_       FC_GLOBAL(psnrm2, PSNRM2)
#define    pdnrm2_       FC_GLOBAL(pdnrm2, PDNRM2)
#define    pscnrm2_      FC_GLOBAL(pscnrm2, PSCNRM2)
#define    pdznrm2_      FC_GLOBAL(pdznrm2, PDZNRM2)

#define    psdot_        FC_GLOBAL(psdot, PSDOT)
#define    pddot_        FC_GLOBAL(pddot, PDDOT)
#define    pcdotu_       FC_GLOBAL(pcdotu, PCDOTU)
#define    pzdotu_       FC_GLOBAL(pzdotu, PZDOTU)
#define    pcdotc_       FC_GLOBAL(pcdotc, PCDOTC)
#define    pzdotc_       FC_GLOBAL(pzdotc, PZDOTC)

#define    psamax_       FC_GLOBAL(psamax, PSAMAX)
#define    pdamax_       FC_GLOBAL(pdamax, PDAMAX)
#define    pcamax_       FC_GLOBAL(pcamax, PCAMAX)
#define    pzamax_       FC_GLOBAL(pzamax, PZAMAX)

#define    psgemv_       FC_GLOBAL(psgemv, PSGEMV)
#define    pdgemv_       FC_GLOBAL(pdgemv, PDGEMV)
#define    pcgemv_       FC_GLOBAL(pcgemv, PCGEMV)
#define    pzgemv_       FC_GLOBAL(pzgemv, PZGEMV)

#define    psagemv_      FC_GLOBAL(psagemv, PSAGEMV)
#define    pdagemv_      FC_GLOBAL(pdagemv, PDAGEMV)
#define    pcagemv_      FC_GLOBAL(pcagemv, PCAGEMV)
#define    pzagemv_      FC_GLOBAL(pzagemv, PZAGEMV)

#define    pssymv_       FC_GLOBAL(pssymv, PSSYMV)
#define    pdsymv_       FC_GLOBAL(pdsymv, PDSYMV)
#define    pchemv_       FC_GLOBAL(pchemv, PCHEMV)
#define    pzhemv_       FC_GLOBAL(pzhemv, PZHEMV)

#define    psasymv_      FC_GLOBAL(psasymv, PSASYMV)
#define    pdasymv_      FC_GLOBAL(pdasymv, PDASYMV)
#define    pcahemv_      FC_GLOBAL(pcahemv, PCAHEMV)
#define    pzahemv_      FC_GLOBAL(pzahemv, PZAHEMV)

#define    pstrmv_       FC_GLOBAL(pstrmv, PSTRMV)
#define    pdtrmv_       FC_GLOBAL(pdtrmv, PDTRMV)
#define    pctrmv_       FC_GLOBAL(pctrmv, PCTRMV)
#define    pztrmv_       FC_GLOBAL(pztrmv, PZTRMV)

#define    psatrmv_      FC_GLOBAL(psatrmv, PSATRMV)
#define    pdatrmv_      FC_GLOBAL(pdatrmv, PDATRMV)
#define    pcatrmv_      FC_GLOBAL(pcatrmv, PCATRMV)
#define    pzatrmv_      FC_GLOBAL(pzatrmv, PZATRMV)

#define    pstrsv_       FC_GLOBAL(pstrsv, PSTRSV)
#define    pdtrsv_       FC_GLOBAL(pdtrsv, PDTRSV)
#define    pctrsv_       FC_GLOBAL(pctrsv, PCTRSV)
#define    pztrsv_       FC_GLOBAL(pztrsv, PZTRSV)

#define    psger_        FC_GLOBAL(psger, PSGER)
#define    pdger_        FC_GLOBAL(pdger, PDGER)
#define    pcgeru_       FC_GLOBAL(pcgeru, PCGERU)
#define    pzgeru_       FC_GLOBAL(pzgeru, PZGERU)
#define    pcgerc_       FC_GLOBAL(pcgerc, PCGERC)
#define    pzgerc_       FC_GLOBAL(pzgerc, PZGERC)

#define    pssyr_        FC_GLOBAL(pssyr, PSSYR)
#define    pdsyr_        FC_GLOBAL(pdsyr, PDSYR)
#define    pcher_        FC_GLOBAL(pcher, PCHER)
#define    pzher_        FC_GLOBAL(pzher, PZHER)

#define    pssyr2_       FC_GLOBAL(pssyr2, PSSYR2)
#define    pdsyr2_       FC_GLOBAL(pdsyr2, PDSYR2)
#define    pcher2_       FC_GLOBAL(pcher2, PCHER2)
#define    pzher2_       FC_GLOBAL(pzher2, PZHER2)

#define    psgeadd_      FC_GLOBAL(psgeadd, PSGEMM)
#define    pdgeadd_      FC_GLOBAL(pdgeadd, PDGEMM)
#define    pcgeadd_      FC_GLOBAL(pcgeadd, PCGEMM)
#define    pzgeadd_      FC_GLOBAL(pzgeadd, PZGEMM)

#define    psgemm_       FC_GLOBAL(psgemm, PSGEADD)
#define    pdgemm_       FC_GLOBAL(pdgemm, PDGEADD)
#define    pcgemm_       FC_GLOBAL(pcgemm, PCGEADD)
#define    pzgemm_       FC_GLOBAL(pzgemm, PZGEADD)

#define    pssymm_       FC_GLOBAL(pssymm, PSSYMM)
#define    pdsymm_       FC_GLOBAL(pdsymm, PDSYMM)
#define    pcsymm_       FC_GLOBAL(pcsymm, PCSYMM)
#define    pchemm_       FC_GLOBAL(pchemm, PCHEMM)
#define    pzsymm_       FC_GLOBAL(pzsymm, PZSYMM)
#define    pzhemm_       FC_GLOBAL(pzhemm, PZHEMM)

#define    pstrmm_       FC_GLOBAL(pstrmm, PSTRMM)
#define    pdtrmm_       FC_GLOBAL(pdtrmm, PDTRMM)
#define    pctrmm_       FC_GLOBAL(pctrmm, PCTRMM)
#define    pztrmm_       FC_GLOBAL(pztrmm, PZTRMM)

#define    pstrsm_       FC_GLOBAL(pstrsm, PSTRSM)
#define    pdtrsm_       FC_GLOBAL(pdtrsm, PDTRSM)
#define    pctrsm_       FC_GLOBAL(pctrsm, PCTRSM)
#define    pztrsm_       FC_GLOBAL(pztrsm, PZTRSM)

#define    pssyrk_       FC_GLOBAL(pssyrk, PSSYRK)
#define    pdsyrk_       FC_GLOBAL(pdsyrk, PDSYRK)
#define    pcsyrk_       FC_GLOBAL(pcsyrk, PCSYRK)
#define    pcherk_       FC_GLOBAL(pcherk, PCHERK)
#define    pzsyrk_       FC_GLOBAL(pzsyrk, PZSYRK)
#define    pzherk_       FC_GLOBAL(pzherk, PZHERK)

#define    pssyr2k_      FC_GLOBAL(pssyr2k, PSSYR2K)
#define    pdsyr2k_      FC_GLOBAL(pdsyr2k, PDSYR2K)
#define    pcsyr2k_      FC_GLOBAL(pcsyr2k, PCSYR2K)
#define    pcher2k_      FC_GLOBAL(pcher2k, PCHER2K)
#define    pzsyr2k_      FC_GLOBAL(pzsyr2k, PZSYR2K)
#define    pzher2k_      FC_GLOBAL(pzher2k, PZHER2K)

#define    pstradd_      FC_GLOBAL(pstradd, PSTRADD)
#define    pdtradd_      FC_GLOBAL(pdtradd, PDTRADD)
#define    pctradd_      FC_GLOBAL(pctradd, PCTRADD)
#define    pztradd_      FC_GLOBAL(pztradd, PZTRADD)

#define    pstran_       FC_GLOBAL(pstran, PSTRAN)
#define    pdtran_       FC_GLOBAL(pdtran, PDTRAN)
#define    pctranu_      FC_GLOBAL(pctranu, PCTRANU)
#define    pztranu_      FC_GLOBAL(pztranu, PZTRANU)
#define    pctranc_      FC_GLOBAL(pctranc, PCTRANC)
#define    pztranc_      FC_GLOBAL(pztranc, PZTRANC)

/*
*  ---------------------------------------------------------------------
*  Function prototypes
*  ---------------------------------------------------------------------
*/
#ifdef __STDC__

void           PB_freebuf_     ( void );

void           PB_topget_      ( Int *,     F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T );

void           PB_topset_      ( Int *,     F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T );

void           picopy_         ( Int *,     Int *,     Int *,
                                 Int *,     Int *,     Int *,
                                 Int *,     Int *,     Int *,
                                 Int *,     Int * );
void           pscopy_         ( Int *,     float *,   Int *,
                                 Int *,     Int *,     Int *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int * );
void           pdcopy_         ( Int *,     double *,  Int *,
                                 Int *,     Int *,     Int *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int * );
void           pccopy_         ( Int *,     float *,   Int *,
                                 Int *,     Int *,     Int *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int * );
void           pzcopy_         ( Int *,     double *,  Int *,
                                 Int *,     Int *,     Int *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int * );

void           psswap_         ( Int *,     float *,   Int *,
                                 Int *,     Int *,     Int *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int * );
void           pdswap_         ( Int *,     double *,  Int *,
                                 Int *,     Int *,     Int *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int * );
void           pcswap_         ( Int *,     float *,   Int *,
                                 Int *,     Int *,     Int *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int * );
void           pzswap_         ( Int *,     double *,  Int *,
                                 Int *,     Int *,     Int *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int * );

void           psaxpy_         ( Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     Int * );
void           pdaxpy_         ( Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     Int * );
void           pcaxpy_         ( Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     Int * );
void           pzaxpy_         ( Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     Int * );

void           psscal_         ( Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pdscal_         ( Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pcscal_         ( Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pcsscal_        ( Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pzscal_         ( Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pzdscal_        ( Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int * );

void           psasum_         ( Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pdasum_         ( Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pscasum_        ( Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pdzasum_        ( Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int * );

void           psnrm2_         ( Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pdnrm2_         ( Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pscnrm2_        ( Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pdznrm2_        ( Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int * );

void           psdot_          ( Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     Int * );
void           pddot_          ( Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     Int * );
void           pcdotc_         ( Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     Int * );
void           pcdotu_         ( Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     Int * );
void           pzdotc_         ( Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     Int * );
void           pzdotu_         ( Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     Int * );

void           psamax_         ( Int *,     float *,   Int *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int * );
void           pdamax_         ( Int *,     double *,  Int *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int * );
void           pcamax_         ( Int *,     float *,   Int *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int * );
void           pzamax_         ( Int *,     double *,  Int *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int * );

void           psgemv_         ( F_CHAR_T,  Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pdgemv_         ( F_CHAR_T,  Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pcgemv_         ( F_CHAR_T,  Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pzgemv_         ( F_CHAR_T,  Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int * );

void           psagemv_        ( F_CHAR_T,  Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pdagemv_        ( F_CHAR_T,  Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pcagemv_        ( F_CHAR_T,  Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pzagemv_        ( F_CHAR_T,  Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 Int * );

void           psger_          ( Int *,     Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int * );
void           pdger_          ( Int *,     Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int * );
void           pcgerc_         ( Int *,     Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int * );
void           pcgeru_         ( Int *,     Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int * );
void           pzgerc_         ( Int *,     Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int * );
void           pzgeru_         ( Int *,     Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int * );

void           pssymv_         ( F_CHAR_T,  Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int *,     Int * );
void           pdsymv_         ( F_CHAR_T,  Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int *,     Int * );
void           pchemv_         ( F_CHAR_T,  Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int *,     Int * );
void           pzhemv_         ( F_CHAR_T,  Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int *,     Int * );

void           psasymv_        ( F_CHAR_T,  Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int *,     Int * );
void           pdasymv_        ( F_CHAR_T,  Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int *,     Int * );
void           pcahemv_        ( F_CHAR_T,  Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int *,     Int * );
void           pzahemv_        ( F_CHAR_T,  Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int *,     Int * );

void           pssyr_          ( F_CHAR_T,  Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int * );
void           pdsyr_          ( F_CHAR_T,  Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int * );
void           pcher_          ( F_CHAR_T,  Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int * );
void           pzher_          ( F_CHAR_T,  Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int * );

void           pssyr2_         ( F_CHAR_T,  Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int * );
void           pdsyr2_         ( F_CHAR_T,  Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int * );
void           pcher2_         ( F_CHAR_T,  Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int * );
void           pzher2_         ( F_CHAR_T,  Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int * );

void           pstrmv_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pdtrmv_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pctrmv_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pztrmv_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int *,
                                 Int * );

void           psatrmv_        ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int * );
void           pdatrmv_        ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int * );
void           pcatrmv_        ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     Int * );
void           pzatrmv_        ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     Int * );

void           pstrsv_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pdtrsv_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pctrsv_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int *,
                                 Int * );
void           pztrsv_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int *,
                                 Int * );

void           psgeadd_        ( F_CHAR_T,  Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int * );
void           pdgeadd_        ( F_CHAR_T,  Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int * );
void           pcgeadd_        ( F_CHAR_T,  Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int * );
void           pzgeadd_        ( F_CHAR_T,  Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int * );

void           psgemm_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int * );
void           pdgemm_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int * );
void           pcgemm_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   Int *,
                                 Int *,     Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int * );
void           pzgemm_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  Int *,
                                 Int *,     Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int * );

void           pssymm_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int * );
void           pdsymm_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int * );
void           pcsymm_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int * );
void           pzsymm_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int * );
void           pchemm_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int * );
void           pzhemm_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int * );

void           pssyr2k_        ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int * );
void           pdsyr2k_        ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int * );
void           pcsyr2k_        ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int * );
void           pzsyr2k_        ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int * );
void           pcher2k_        ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int * );
void           pzher2k_        ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int * );

void           pssyrk_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int * );
void           pdsyrk_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int * );
void           pcsyrk_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int * );
void           pzsyrk_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int * );
void           pcherk_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int * );
void           pzherk_         ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int * );

void           pstradd_        ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int * );
void           pdtradd_        ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int * );
void           pctradd_        ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int * );
void           pztradd_        ( F_CHAR_T,  F_CHAR_T,  Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int * );

void           pstran_         ( Int *,     Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int * );
void           pdtran_         ( Int *,     Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int * );
void           pctranc_        ( Int *,     Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int * );
void           pztranc_        ( Int *,     Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int * );
void           pctranu_        ( Int *,     Int *,     float *,
                                 float *,   Int *,     Int *,
                                 Int *,     float *,   float *,
                                 Int *,     Int *,     Int * );
void           pztranu_        ( Int *,     Int *,     double *,
                                 double *,  Int *,     Int *,
                                 Int *,     double *,  double *,
                                 Int *,     Int *,     Int * );

void           pstrmm_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int * );
void           pdtrmm_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int * );
void           pctrmm_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int * );
void           pztrmm_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int * );

void           pstrsm_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int * );
void           pdtrsm_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int * );
void           pctrsm_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 float *,   float *,   Int *,
                                 Int *,     Int *,     float *,
                                 Int *,     Int *,     Int * );
void           pztrsm_         ( F_CHAR_T,  F_CHAR_T,  F_CHAR_T,
                                 F_CHAR_T,  Int *,     Int *,
                                 double *,  double *,  Int *,
                                 Int *,     Int *,     double *,
                                 Int *,     Int *,     Int * );
#else

void           PB_freebuf_     ();
void           PB_topget_      ();
void           PB_topset_      ();

void           picopy_         ();
void           pscopy_         ();
void           pdcopy_         ();
void           pccopy_         ();
void           pzcopy_         ();

void           psswap_         ();
void           pdswap_         ();
void           pcswap_         ();
void           pzswap_         ();

void           psaxpy_         ();
void           pdaxpy_         ();
void           pcaxpy_         ();
void           pzaxpy_         ();

void           psscal_         ();
void           pdscal_         ();
void           pcscal_         ();
void           pcsscal_        ();
void           pzscal_         ();
void           pzdscal_        ();

void           psasum_         ();
void           pdasum_         ();
void           pscasum_        ();
void           pdzasum_        ();

void           psnrm2_         ();
void           pdnrm2_         ();
void           pscnrm2_        ();
void           pdznrm2_        ();

void           psdot_          ();
void           pddot_          ();
void           pcdotc_         ();
void           pcdotu_         ();
void           pzdotc_         ();
void           pzdotu_         ();

void           psamax_         ();
void           pdamax_         ();
void           pcamax_         ();
void           pzamax_         ();

void           psgemv_         ();
void           pdgemv_         ();
void           pcgemv_         ();
void           pzgemv_         ();

void           psagemv_        ();
void           pdagemv_        ();
void           pcagemv_        ();
void           pzagemv_        ();

void           psger_          ();
void           pdger_          ();
void           pcgerc_         ();
void           pcgeru_         ();
void           pzgerc_         ();
void           pzgeru_         ();

void           pssymv_         ();
void           pdsymv_         ();
void           pchemv_         ();
void           pzhemv_         ();

void           psasymv_        ();
void           pdasymv_        ();
void           pcahemv_        ();
void           pzahemv_        ();

void           pssyr_          ();
void           pdsyr_          ();
void           pcher_          ();
void           pzher_          ();

void           pssyr2_         ();
void           pdsyr2_         ();
void           pcher2_         ();
void           pzher2_         ();

void           pstrmv_         ();
void           pdtrmv_         ();
void           pctrmv_         ();
void           pztrmv_         ();

void           psatrmv_        ();
void           pdatrmv_        ();
void           pcatrmv_        ();
void           pzatrmv_        ();

void           pstrsv_         ();
void           pdtrsv_         ();
void           pctrsv_         ();
void           pztrsv_         ();

void           psgeadd_        ();
void           pdgeadd_        ();
void           pcgeadd_        ();
void           pzgeadd_        ();

void           psgemm_         ();
void           pdgemm_         ();
void           pcgemm_         ();
void           pzgemm_         ();

void           pssymm_         ();
void           pdsymm_         ();
void           pcsymm_         ();
void           pchemm_         ();
void           pzsymm_         ();
void           pzhemm_         ();

void           pssyr2k_        ();
void           pdsyr2k_        ();
void           pcsyr2k_        ();
void           pcher2k_        ();
void           pzsyr2k_        ();
void           pzher2k_        ();

void           pssyrk_         ();
void           pdsyrk_         ();
void           pcsyrk_         ();
void           pcherk_         ();
void           pzsyrk_         ();
void           pzherk_         ();

void           pstradd_        ();
void           pdtradd_        ();
void           pctradd_        ();
void           pztradd_        ();

void           pstran_         ();
void           pdtran_         ();
void           pctranc_        ();
void           pctranu_        ();
void           pztranc_        ();
void           pztranu_        ();

void           pstrmm_         ();
void           pdtrmm_         ();
void           pctrmm_         ();
void           pztrmm_         ();

void           pstrsm_         ();
void           pdtrsm_         ();
void           pctrsm_         ();
void           pztrsm_         ();

#endif
