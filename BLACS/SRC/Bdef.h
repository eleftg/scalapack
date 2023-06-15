#ifndef BDEF_H
#define BDEF_H 1

/*
 * Include the system dependant and user defined stuff
 */
#include "Bconfig.h"
#include <FCMangle.h>
/*
 * Data type defining a scope for the BLACS
 */
typedef struct bLaCsScOpE BLACSSCOPE;
struct bLaCsScOpE
{
   MPI_Comm comm;
   Int ScpId, MaxId, MinId;
   Int Np, Iam;
};
/*
 * Data type defining a context for the BLACS
 */
typedef struct bLaCsCoNtExT BLACSCONTEXT;
struct bLaCsCoNtExT
{
   BLACSSCOPE rscp, cscp, ascp, pscp; /* row, column, all, and pt2pt scopes */
   BLACSSCOPE *scp;                   /* pointer to present scope */
   Int TopsRepeat;                    /* Use only repeatable topologies? */
   Int TopsCohrnt;                    /* Use only coherent topologies? */
   Int Nb_bs, Nr_bs;           /* for bcast general tree and multiring tops */
   Int Nb_co, Nr_co;           /* for combine general tree and multiring tops */
};

/*
 *  Define the fortran data types COMPLEX*8 (SCOMPLEX)
 *  and COMPLEX*16 (DCOMPLEX).
 */
typedef struct {double r, i;} DCOMPLEX;
typedef struct {float r, i;} SCOMPLEX;

/*
 *  These variables will be defined to be MPI datatypes for complex and double
 *  complex if we are using the C interface to MPI.  If we use the fortran
 *  interface, we need to declare the contants array.  I'm too lazy to declare
 *  these guys external in every file that needs them.
 */
#ifndef GlobalVars
   extern Int *BI_COMM_WORLD;
#endif

/*
 *  Definition of buffer type for BLACS' asynchronous operations
 */
typedef struct bLaCbUfF BLACBUFF;
struct bLaCbUfF
{
   char *Buff;             /* send/recv buffer */
   Int Len;                /* length of buffer in bytes */
   Int nAops;              /* number of asynchronous operations out of buff */
   MPI_Request *Aops;   /* list of async. operations out of buff */
   MPI_Datatype dtype;  /* data type of buffer */
   Int N;                  /* number of elements of data type in buff */
   BLACBUFF *prev, *next;  /* pointer to the other BLACBUFF in queue */
};

/*
 * Pointer to the combine's vector-vector functions
 */
typedef void (*VVFUNPTR)(Int, char *, char *);
typedef void (*SDRVPTR)(BLACSCONTEXT *, Int, Int, BLACBUFF *);


#define BI_DistType                  unsigned short
#define BI_MpiDistType               MPI_UNSIGNED_SHORT

#define BUFFALIGN    8      /* force all buffers to 8 byte alignment */
#define BANYNODE     MPI_ANY_SOURCE
#define PT2PTID      9976   /* TAG used for point to point */
#define NOTINCONTEXT -1  /* Indicates node called gridmap, but not in grid */
#define MAXNCTXT     10      /* initial guess at max # of contexts */
#define MAXNSYSCTXT  10   /* initial guess at max # of system context */
#define AOPDONE      MPI_REQUEST_NULL
#define BUFWAIT      120      /* Length of time to wait for emergency buff */

/*
 * Error codes
 */
#define NORV 1          /* No receiver (only 1 proc in scoped op) */
#define NPOW2 2         /* Number of procs is not a power of 2 */
#define BADSCP 3        /* Scope not row, column or all */

/*
 * Data types
 */
#define INTEGER   3
#define SINGLE    4
#define DOUBLE    6
#define COMPLEX8  5
#define COMPLEX16 7

#define FULLCON 0      /* top is fully connected */

/*
 * Routine types
 */
#define RT_SD    1
#define RT_RV    2
#define RT_BS    3
#define RT_BR    4
#define RT_COMB  5

/*
 * Legal WHAT values for BLACS_SET
 */
#define SGET_SYSCONTXT    0
#define SGET_MSGIDS       1
#define SGET_DEBUGLVL     2
#define SGET_BLACSCONTXT 10
#define SGET_NR_BS       11
#define SGET_NB_BS       12
#define SGET_NR_CO       13
#define SGET_NB_CO       14
#define SGET_TOPSREPEAT  15
#define SGET_TOPSCOHRNT  16

/*
 * These are prototypes for error and warning functions -- I don't want
 * to prototype them in each routine.
 */
void BI_BlacsWarn(Int ConTxt, Int line, char *file, char *form, ...);
void BI_BlacsErr(Int ConTxt, Int line, char *file, char *form, ...);
Int BI_ContxtNum(BLACSCONTEXT *ctxt);

/*
 * If we've got an ANSI standard C compiler, we can use void pointers...
 */
#define BVOID void


/*
 * ========================================================================
 *     PREPROCESSOR MACRO FUNCTIONS USED FOR OPTIMIZATION & CONVENIENCE
 * ========================================================================
 */

#define Mlowcase(C) ( ((C) > 64 && (C) < 91) ? (C) | 32 : (C) )

/*
 * Slightly modified gridinfo substitute
 */
#define Mgridinfo(ctxt, Ng0, nprow0, npcol0, myrow0, mycol0)\
{\
   (Ng0) = (ctxt)->ascp.Np;\
   (nprow0) = (ctxt)->cscp.Np;\
   (npcol0) = (ctxt)->rscp.Np;\
   (myrow0) = (ctxt)->cscp.Iam;\
   (mycol0) = (ctxt)->rscp.Iam;\
}

/*
 * These routines return coordinates based on nodes number, or node number
 * based on coordinates.  Those routines with v after the M return virtual
 * nodes numbers (i.e., in respect to the grid, not physical node numbers)
 * based on grid coordinates, or grid coordinates based on virtual node numbers.
 */
#define Mpcoord(ctxt, node, prow, pcol)\
{\
   (prow) = (node) / (ctxt)->rscp.Np;\
   (pcol) = (node) % (ctxt)->rscp.Np;\
}
#define Mvpcoord(ctxt, node, prow, pcol) \
        Mpcoord((ctxt), (node), (prow), (pcol));

#define Mkpnum(ctxt, prow, pcol)  ( (prow)*(ctxt)->rscp.Np+(pcol) )
#define Mvkpnum(ctxt, prow, pcol) ( (prow)*(ctxt)->rscp.Np+(pcol) )

/*
 * This macro returns scoped message ID's.
 */
#define Mscopeid(ctxt) (ctxt)->scp->ScpId; \
   if (++(ctxt)->scp->ScpId == (ctxt)->scp->MaxId) \
      (ctxt)->scp->ScpId = (ctxt)->scp->MinId;

/*
 *  Get context, and check for validity if debug level is high
 */
#if (BlacsDebugLvl > 0)
#define MGetConTxt(Context, ctxtptr)\
{\
   extern BLACSCONTEXT **BI_MyContxts;\
   extern Int BI_MaxNCtxt;\
   if ( ((Context) >= BI_MaxNCtxt) || ((Context) < 0) )\
      BI_BlacsErr(-1, __LINE__, __FILE__, "Invalid context handle: %d",\
                  (Context));\
   else if (BI_MyContxts[(Context)] == NULL)\
      BI_BlacsErr(-1, __LINE__, __FILE__, "Invalid context, handle=%d",\
                  (Context));\
   (ctxtptr) = BI_MyContxts[(Context)];\
}
#else
#define MGetConTxt(Context, ctxtptr)\
{\
   extern BLACSCONTEXT **BI_MyContxts;\
   (ctxtptr) = BI_MyContxts[(Context)];\
}
#endif
/*
 * This macro handles MPI errors
 */
#if(BlacsDebugLvl > 0)
#define Mmpierror(ierr, rout, ctxt, line, file) \
{ \
   if ( (ierr) != BI_MPI_SUCCESS )\
      BI_BlacsErr(BI_ContxtNum((ctxt)), (line), (file), \
                  "MPI error %d on call to %s", (ierr), (rout)); \
}
#else
#define Mmpierror(ierr, rout, ctxt, line, file)
#endif
/*
 * A small macro useful for debugging
 */
#define ErrPrint \
{ \
   extern Int BI_Iam; \
   fprintf(stderr, "%d: line %d of file %s\n", BI_Iam, __LINE__, __FILE__); \
}

/*
 * These macros allow for the funky function declarations and character handling
 * needed on the CRAY to have a C routine callable from fortran
 */
#define F_VOID_FUNC void
#define F_INT_FUNC  Int
#define F_DOUBLE_FUNC double

#if (INTFACE == C_CALL)

#define F2C_CharTrans(c) *(c)

#else

#ifdef CRAY
#define F2C_CharTrans(c) *( _fcdtocp((c)) )
#define F_CHAR      _fcd
#else
#define F2C_CharTrans(c) *(c)
#define F_CHAR      char *
#endif

#endif

/*
 *  These macros allow for accessing values and addresses of parameters, which
 *  will be pointers if we're using fortran, and values if we're using C.
 */
#if (INTFACE == C_CALL)
#define Mpval(para) (para)
#define Mpaddress(para) (&(para))
#define Mwalltime Cdwalltime00
#else
#define Mpval(para) (*(para))
#define Mpaddress(para) (para)
#define Mwalltime dwalltime00_
#endif

/*
 * Real and complex absolute values
 */
#define Rabs(x) ( (x) < 0 ? (x) * -1 : (x) )
#define Cabs(z) ( (((z).i) < 0 ? ((z).i) * -1 : ((z).i)) + (((z).r) < 0 ? ((z).r) * -1 : ((z).r)) )

/*
 * Figures the length of packed trapezoidal matrix
 */
#define trsize(diag, m, n, bytes, length)\
{\
   if ( (diag) == 'u' ) (length) = 1;\
   else() = 0;\
   if ( (m) > (n) )\
      (length) = ( (n) * ( (m) - (n) ) + ( (n)*(n) ) - ( (n)*(n) )/2 +\
                   (n)/2 - (n) * (length) ) * (bytes);\
   else\
      (length) = ( (m) * ( (n) - (m) ) + ( (m)*(m) ) - ( (m)*(m) )/2 +\
                   (m)/2 - (m) * (length) ) * (bytes);\
}

/*
 * These macros call the correct packing/unpacking routines
 */
#define BI_cmvcopy(m, n, A, lda, buff) \
        BI_smvcopy(2*(m), (n), (float *) (A), 2*(lda), (float *) (buff))
#define BI_cvmcopy(m, n, A, lda, buff) \
        BI_svmcopy(2*(m), (n), (float *) (A), 2*(lda), (float *) (buff))
#define BI_zmvcopy(m, n, A, lda, buff) \
        BI_dmvcopy(2*(m), (n), (double *) (A), 2*(lda), (double *) (buff))
#define BI_zvmcopy(m, n, A, lda, buff) \
        BI_dvmcopy(2*(m), (n), (double *) (A), 2*(lda), (double *) (buff))

/*
 * This macro avoids freeing types when the zero-byte workaround was applied
 */
#ifdef ZeroByteTypeBug
#define BI_MPI_TYPE_FREE(t) (*(t) != MPI_BYTE ? MPI_Type_free(t) : 0)
#else
#define BI_MPI_TYPE_FREE(t) MPI_Type_free(t)
#endif

/*
 * Support routines
 */
#define blacs_pinfo_          FC_GLOBAL_(blacs_pinfo, BLACS_PINFO)
#define blacs_setup_          FC_GLOBAL_(blacs_setup, BLACS_SETUP)
#define setpvmtids_           FC_GLOBAL(setpvmtids, SETPVMTIDS)
#define blacs_set_            FC_GLOBAL_(blacs_set, BLACS_SET)
#define blacs_get_            FC_GLOBAL_(blacs_get, BLACS_GET)
#define blacs_gridinit_       FC_GLOBAL_(blacs_gridinit, BLACS_GRIDINIT)
#define blacs_gridmap_        FC_GLOBAL_(blacs_gridmap, BLACS_GRIDMAP)
#define ksendid_              FC_GLOBAL(ksendid, KSENDID)
#define krecvid_              FC_GLOBAL(krecvid, KRECVID)
#define kbsid_                FC_GLOBAL(kbsid, KBSID)
#define kbrid_                FC_GLOBAL(kbrid, KBRID)
#define blacs_freebuff_       FC_GLOBAL_(blacs_freebuff, BLACS_FREEBUFF)
#define blacs_gridexit_       FC_GLOBAL_(blacs_gridexit, BLACS_GRIDEXIT)
#define blacs_abort_          FC_GLOBAL_(blacs_abort, BLACS_ABORT)
#define blacs_exit_           FC_GLOBAL_(blacs_exit, BLACS_EXIT)
#define blacs_gridinfo_       FC_GLOBAL_(blacs_gridinfo, BLACS_GRIDINFO)
#define blacs_pnum_           FC_GLOBAL_(blacs_pnum, BLACS_PNUM)
#define blacs_pcoord_         FC_GLOBAL_(blacs_pcoord, BLACS_PCOORD)
#define dcputime00_           FC_GLOBAL(dcputime00, DCPUTIME00)
#define dwalltime00_          FC_GLOBAL(dwalltime00, DWALLTIME00)
#define blacs_barrier_        FC_GLOBAL_(blacs_barrier, BLACS_BARRIER)

/*
 * Main, type dependent, routines
 */
#define igesd2d_   FC_GLOBAL(igesd2d, IGESD2D)
#define igerv2d_   FC_GLOBAL(igerv2d, IGERV2D)
#define igebs2d_   FC_GLOBAL(igebs2d, IGEBS2D)
#define igebr2d_   FC_GLOBAL(igebr2d, IGEBR2D)
#define itrsd2d_   FC_GLOBAL(itrsd2d, ITRSD2D)
#define itrrv2d_   FC_GLOBAL(itrrv2d, ITRRV2D)
#define itrbs2d_   FC_GLOBAL(itrbs2d, ITRBS2D)
#define itrbr2d_   FC_GLOBAL(itrbr2d, ITRBR2D)
#define igsum2d_   FC_GLOBAL(igsum2d, IGSUM2D)
#define igamx2d_   FC_GLOBAL(igamx2d, IGAMX2D)
#define igamn2d_   FC_GLOBAL(igamn2d, IGAMN2D)
#define sgesd2d_   FC_GLOBAL(sgesd2d, SGESD2D)
#define sgerv2d_   FC_GLOBAL(sgerv2d, SGERV2D)
#define sgebs2d_   FC_GLOBAL(sgebs2d, SGEBS2D)
#define sgebr2d_   FC_GLOBAL(sgebr2d, SGEBR2D)
#define strsd2d_   FC_GLOBAL(strsd2d, STRSD2D)
#define strrv2d_   FC_GLOBAL(strrv2d, STRRV2D)
#define strbs2d_   FC_GLOBAL(strbs2d, STRBS2D)
#define strbr2d_   FC_GLOBAL(strbr2d, STRBR2D)
#define sgsum2d_   FC_GLOBAL(sgsum2d, SGSUM2D)
#define sgamx2d_   FC_GLOBAL(sgamx2d, SGAMX2D)
#define sgamn2d_   FC_GLOBAL(sgamn2d, SGAMN2D)
#define dgesd2d_   FC_GLOBAL(dgesd2d, DGESD2D)
#define dgerv2d_   FC_GLOBAL(dgerv2d, DGERV2D)
#define dgebs2d_   FC_GLOBAL(dgebs2d, DGEBS2D)
#define dgebr2d_   FC_GLOBAL(dgebr2d, DGEBR2D)
#define dtrsd2d_   FC_GLOBAL(dtrsd2d, DTRSD2D)
#define dtrrv2d_   FC_GLOBAL(dtrrv2d, DTRRV2D)
#define dtrbs2d_   FC_GLOBAL(dtrbs2d, DTRBS2D)
#define dtrbr2d_   FC_GLOBAL(dtrbr2d, DTRBR2D)
#define dgsum2d_   FC_GLOBAL(dgsum2d, DGSUM2D)
#define dgamx2d_   FC_GLOBAL(dgamx2d, DGAMX2D)
#define dgamn2d_   FC_GLOBAL(dgamn2d, DGAMN2D)
#define cgesd2d_   FC_GLOBAL(cgesd2d, CGESD2D)
#define cgerv2d_   FC_GLOBAL(cgerv2d, CGERV2D)
#define cgebs2d_   FC_GLOBAL(cgebs2d, CGEBS2D)
#define cgebr2d_   FC_GLOBAL(cgebr2d, CGEBR2D)
#define ctrsd2d_   FC_GLOBAL(ctrsd2d, CTRSD2D)
#define ctrrv2d_   FC_GLOBAL(ctrrv2d, CTRRV2D)
#define ctrbs2d_   FC_GLOBAL(ctrbs2d, CTRBS2D)
#define ctrbr2d_   FC_GLOBAL(ctrbr2d, CTRBR2D)
#define cgsum2d_   FC_GLOBAL(cgsum2d, CGSUM2D)
#define cgamx2d_   FC_GLOBAL(cgamx2d, CGAMX2D)
#define cgamn2d_   FC_GLOBAL(cgamn2d, CGAMN2D)
#define zgesd2d_   FC_GLOBAL(zgesd2d, ZGESD2D)
#define zgerv2d_   FC_GLOBAL(zgerv2d, ZGERV2D)
#define zgebs2d_   FC_GLOBAL(zgebs2d, ZGEBS2D)
#define zgebr2d_   FC_GLOBAL(zgebr2d, ZGEBR2D)
#define ztrsd2d_   FC_GLOBAL(ztrsd2d, ZTRSD2D)
#define ztrrv2d_   FC_GLOBAL(ztrrv2d, ZTRRV2D)
#define ztrbs2d_   FC_GLOBAL(ztrbs2d, ZTRBS2D)
#define ztrbr2d_   FC_GLOBAL(ztrbr2d, ZTRBR2D)
#define zgsum2d_   FC_GLOBAL(zgsum2d, ZGSUM2D)
#define zgamx2d_   FC_GLOBAL(zgamx2d, ZGAMX2D)
#define zgamn2d_   FC_GLOBAL(zgamn2d, ZGAMN2D)

#endif
