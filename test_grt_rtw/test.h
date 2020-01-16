/*
 * test.h
 *
 * Code generation for model "test".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed May 18 14:06:27 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test_h_
#define RTW_HEADER_test_h_
#include <float.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
#ifndef test_COMMON_INCLUDES_
# define test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* test_COMMON_INCLUDES_ */

#include "test_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "math.h"
#include "rt_matrixlib.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeDELTA
# define rtmGetOdeDELTA(rtm)           ((rtm)->ModelData.odeDELTA)
#endif

#ifndef rtmSetOdeDELTA
# define rtmSetOdeDELTA(rtm, val)      ((rtm)->ModelData.odeDELTA = (val))
#endif

#ifndef rtmGetOdeDFDX
# define rtmGetOdeDFDX(rtm)            ((rtm)->ModelData.odeDFDX)
#endif

#ifndef rtmSetOdeDFDX
# define rtmSetOdeDFDX(rtm, val)       ((rtm)->ModelData.odeDFDX = (val))
#endif

#ifndef rtmGetOdeE
# define rtmGetOdeE(rtm)               ((rtm)->ModelData.odeE)
#endif

#ifndef rtmSetOdeE
# define rtmSetOdeE(rtm, val)          ((rtm)->ModelData.odeE = (val))
#endif

#ifndef rtmGetOdeF0
# define rtmGetOdeF0(rtm)              ((rtm)->ModelData.odeF0)
#endif

#ifndef rtmSetOdeF0
# define rtmSetOdeF0(rtm, val)         ((rtm)->ModelData.odeF0 = (val))
#endif

#ifndef rtmGetOdeF1
# define rtmGetOdeF1(rtm)              ((rtm)->ModelData.odeF1)
#endif

#ifndef rtmSetOdeF1
# define rtmSetOdeF1(rtm, val)         ((rtm)->ModelData.odeF1 = (val))
#endif

#ifndef rtmGetOdeFAC
# define rtmGetOdeFAC(rtm)             ((rtm)->ModelData.odeFAC)
#endif

#ifndef rtmSetOdeFAC
# define rtmSetOdeFAC(rtm, val)        ((rtm)->ModelData.odeFAC = (val))
#endif

#ifndef rtmGetOdePIVOTS
# define rtmGetOdePIVOTS(rtm)          ((rtm)->ModelData.odePIVOTS)
#endif

#ifndef rtmSetOdePIVOTS
# define rtmSetOdePIVOTS(rtm, val)     ((rtm)->ModelData.odePIVOTS = (val))
#endif

#ifndef rtmGetOdeW
# define rtmGetOdeW(rtm)               ((rtm)->ModelData.odeW)
#endif

#ifndef rtmSetOdeW
# define rtmSetOdeW(rtm, val)          ((rtm)->ModelData.odeW = (val))
#endif

#ifndef rtmGetOdeX0
# define rtmGetOdeX0(rtm)              ((rtm)->ModelData.odeX0)
#endif

#ifndef rtmSetOdeX0
# define rtmSetOdeX0(rtm, val)         ((rtm)->ModelData.odeX0 = (val))
#endif

#ifndef rtmGetOdeX1START
# define rtmGetOdeX1START(rtm)         ((rtm)->ModelData.odeX1START)
#endif

#ifndef rtmSetOdeX1START
# define rtmSetOdeX1START(rtm, val)    ((rtm)->ModelData.odeX1START = (val))
#endif

#ifndef rtmGetOdeXTMP
# define rtmGetOdeXTMP(rtm)            ((rtm)->ModelData.odeXTMP)
#endif

#ifndef rtmSetOdeXTMP
# define rtmSetOdeXTMP(rtm, val)       ((rtm)->ModelData.odeXTMP = (val))
#endif

#ifndef rtmGetOdeZTMP
# define rtmGetOdeZTMP(rtm)            ((rtm)->ModelData.odeZTMP)
#endif

#ifndef rtmSetOdeZTMP
# define rtmSetOdeZTMP(rtm, val)       ((rtm)->ModelData.odeZTMP = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T TransferFcn;                  /* '<Root>/Transfer Fcn' */
  real_T Lookup;                       /* '<S1>/Lookup' */
} B_test_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  uint8_T Output_DSTATE;               /* '<S2>/Output' */
} DW_test_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
} X_test_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
} XDot_test_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<Root>/Transfer Fcn' */
} XDis_test_T;

#ifndef ODE14X_INTG
#define ODE14X_INTG

/* ODE14X Integration Data */
typedef struct {
  real_T *x0;
  real_T *f0;
  real_T *x1start;
  real_T *f1;
  real_T *Delta;
  real_T *E;
  real_T *fac;
  real_T *DFDX;
  real_T *W;
  int_T *pivots;
  real_T *xtmp;
  real_T *ztmp;
  real_T *M;
  real_T *M1;
  real_T *Edot;
  real_T *xdot;
  real_T *fminusMxdot;
  boolean_T isFirstStep;
} ODE14X_IntgData;

#endif

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_test_T;

/* Parameters (auto storage) */
struct P_test_T_ {
  real_T LEG2_X_OutValues[6];          /* Mask Parameter: LEG2_X_OutValues
                                        * Referenced by: '<S1>/Lookup'
                                        */
  real_T LEG2_X_TimeValues[6];         /* Mask Parameter: LEG2_X_TimeValues
                                        * Referenced by: '<S1>/Lookup'
                                        */
  uint8_T LimitedCounter_uplimit;      /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S4>/FixPt Switch'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T SampleTimeMath_WtEt;          /* Computed Parameter: SampleTimeMath_WtEt
                                        * Referenced by: '<S1>/Sample Time Math'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S4>/Constant'
                                        */
  uint8_T Output_InitialCondition;     /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S2>/Output'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S3>/FixPt Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_test_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeX0[1];
    real_T odeF0[1];
    real_T odeX1START[1];
    real_T odeF1[1];
    real_T odeDELTA[1];
    real_T odeE[4*1];
    real_T odeFAC[1];
    real_T odeDFDX[1*1];
    real_T odeW[1*1];
    int_T odePIVOTS[1];
    real_T odeXTMP[1];
    real_T odeZTMP[1];
    ODE14X_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_test_T test_P;

/* Block signals (auto storage) */
extern B_test_T test_B;

/* Continuous states (auto storage) */
extern X_test_T test_X;

/* Block states (auto storage) */
extern DW_test_T test_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_test_T test_Y;

/* Model entry point functions */
extern void test_initialize(void);
extern void test_step(void);
extern void test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test_T *const test_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'test'
 * '<S1>'   : 'test/LEG2_X'
 * '<S2>'   : 'test/LEG2_X/LimitedCounter'
 * '<S3>'   : 'test/LEG2_X/LimitedCounter/Increment Real World'
 * '<S4>'   : 'test/LEG2_X/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_test_h_ */
