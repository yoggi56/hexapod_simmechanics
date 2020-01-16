/*
 * sPort.c
 *
 * Code generation for model "sPort".
 *
 * Model version              : 1.0
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Jun 30 13:39:22 2016
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sPort.h"
#include "sPort_private.h"
#include "sPort_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_sPort_T sPort_B;

/* Continuous states */
X_sPort_T sPort_X;

/* Block states (auto storage) */
DW_sPort_T sPort_DW;

/* Real-time model */
RT_MODEL_sPort_T sPort_M_;
RT_MODEL_sPort_T *const sPort_M = &sPort_M_;

/* Projection for root system: '<Root>' */
void sPort_projection(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  int_T tmp_0;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_1;
  char *msg;

  /* Projection for SimscapeExecutionBlock: '<S5>/STATE_1' */
  simulationData = (NeslSimulationData *)sPort_DW.STATE_1_SimulationData;
  time = sPort_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 4;
  simulationData->mData->mContStates.mX = (real_T *)&sPort_X.Upper_RevoluteRzq;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = NULL;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = NULL;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(sPort_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&sPort_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_0 = 0;
  simulationData->mData->mInputValues.mN = 0;
  simulationData->mData->mInputOffsets.mN = 1;
  simulationData->mData->mInputOffsets.mX = &tmp_0;
  diagnosticManager = (NeuDiagnosticManager *)sPort_DW.STATE_1_DiagnosticManager;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_1 = ne_simulator_method((NeslSimulator *)sPort_DW.STATE_1_Simulator,
    NESL_SIM_PROJECTION, simulationData, diagnosticManager);
  if (tmp_1 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(sPort_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(sPort_M, msg);
    }
  }

  /* End of Projection for SimscapeExecutionBlock: '<S5>/STATE_1' */
}

/* Simplified version of numjac.cpp, for use with RTW. */
void local_numjac( RTWSolverInfo *si, real_T *y, const real_T *Fty, real_T *fac,
                  real_T *dFdy )
{
  /* constants */
  real_T THRESH = 1e-6;
  real_T EPS = 2.2e-16;                /* utGetEps(); */
  real_T BL = pow(EPS, 0.75);
  real_T BU = pow(EPS, 0.25);
  real_T FACMIN = pow(EPS, 0.78);
  real_T FACMAX = 0.1;
  int_T nx = 4;
  real_T *x = rtsiGetContStates(si);
  real_T del;
  real_T difmax;
  real_T FdelRowmax;
  real_T temp;
  real_T Fdiff;
  real_T maybe;
  real_T xscale;
  real_T fscale;
  real_T *p;
  int_T rowmax;
  int_T i,j;
  if (x != y)
    (void) memcpy(x, y,
                  (uint_T)nx*sizeof(real_T));
  rtsiSetSolverComputingJacobian(si,true);
  for (p = dFdy, j = 0; j < nx; j++, p += nx) {
    /* Select an increment del for a difference approximation to
       column j of dFdy.  The vector fac accounts for experience
       gained in previous calls to numjac. */
    xscale = fabs(x[j]);
    if (xscale < THRESH)
      xscale = THRESH;
    temp = (x[j] + fac[j]*xscale);
    del = temp - y[j];
    while (del == 0.0) {
      if (fac[j] < FACMAX) {
        fac[j] *= 100.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
        temp = (x[j] + fac[j]*xscale);
        del = temp - x[j];
      } else {
        del = THRESH;                  /* thresh is nonzero */
        break;
      }
    }

    /* Keep del pointing into region. */
    if (Fty[j] >= 0.0)
      del = fabs(del);
    else
      del = -fabs(del);

    /* Form a difference approximation to column j of dFdy. */
    temp = x[j];
    x[j] += del;
    sPort_output();
    rtsiSetdX(si,p);
    sPort_derivatives();
    x[j] = temp;
    difmax = 0.0;
    rowmax = 0;
    FdelRowmax = p[0];
    temp = 1.0 / del;
    for (i = 0; i < nx; i++) {
      Fdiff = p[i] - Fty[i];
      maybe = fabs(Fdiff);
      if (maybe > difmax) {
        difmax = maybe;
        rowmax = i;
        FdelRowmax = p[i];
      }

      p[i] = temp * Fdiff;
    }

    /* Adjust fac for next call to numjac. */
    if (((FdelRowmax != 0.0) && (Fty[rowmax] != 0.0)) || (difmax == 0.0)) {
      fscale = fabs(FdelRowmax);
      if (fscale < fabs(Fty[rowmax]))
        fscale = fabs(Fty[rowmax]);
      if (difmax <= BL*fscale) {
        /* The difference is small, so increase the increment. */
        fac[j] *= 10.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
      } else if (difmax > BU*fscale) {
        /* The difference is large, so reduce the increment. */
        fac[j] *= 0.1;
        if (fac[j] < FACMIN)
          fac[j] = FACMIN;
      }
    }
  }

  rtsiSetSolverComputingJacobian(si,false);
}                                      /* end local_numjac */

/*
 * This function updates continuous states using the ODE14x fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static int_T rt_ODE14x_N[4] = { 12, 8, 6, 4 };

  time_T t0 = rtsiGetT(si);
  time_T t1 = t0;
  time_T h = rtsiGetStepSize(si);
  real_T *x1 = rtsiGetContStates(si);
  int_T order = rtsiGetSolverExtrapolationOrder(si);
  int_T numIter = rtsiGetSolverNumberNewtonIterations(si);
  ODE14X_IntgData *id = (ODE14X_IntgData *)rtsiGetSolverData(si);
  real_T *x0 = id->x0;
  real_T *f0 = id->f0;
  real_T *x1start = id->x1start;
  real_T *f1 = id->f1;
  real_T *Delta = id->Delta;
  real_T *E = id->E;
  real_T *fac = id->fac;
  real_T *dfdx = id->DFDX;
  real_T *W = id->W;
  int_T *pivots = id->pivots;
  real_T *xtmp = id->xtmp;
  real_T *ztmp = id->ztmp;
  int_T *N = &(rt_ODE14x_N[0]);
  int_T i,j,k,iter;
  int_T nx = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(x0, x1,
                (uint_T)nx*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */

  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  sPort_derivatives();
  local_numjac(si,x0,f0,fac,dfdx );
  for (j = 0; j < order; j++) {
    real_T *p;
    real_T hN = h/N[j];

    /* Get the iteration matrix and solution at t0 */

    /* [L,U] = lu(M - hN*J) */
    (void) memcpy(W, dfdx,
                  (uint_T)nx*nx*sizeof(real_T));
    for (p = W, i = 0; i < nx*nx; i++, p++) {
      *p *= (-hN);
    }

    for (p = W, i = 0; i < nx; i++, p += (nx+1)) {
      *p += 1.0;
    }

    rt_lu_real(W, nx,
               pivots);

    /* First Newton's iteration at t0. */
    /* rhs = hN*f0 */
    for (i = 0; i < nx; i++) {
      Delta[i] = hN*f0[i];
    }

    /* Delta = (U \ (L \ rhs)) */
    rt_ForwardSubstitutionRR_Dbl(W, Delta,
      f1, nx,
      1, pivots,
      1);
    rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
      Delta, nx,
      1, 0);

    /* ytmp = y0 + Delta
       ztmp = (ytmp-y0)/h
     */
    (void) memcpy(x1, x0,
                  (uint_T)nx*sizeof(real_T));
    for (i = 0; i < nx; i++) {
      x1[i] += Delta[i];
      ztmp[i] = Delta[i]/hN;
    }

    /* Additional Newton's iterations, if desired.
       for iter = 2:NewtIter
       rhs = hN*feval(odefun,tn,ytmp,extraArgs{:}) - M*(ytmp - yn);
       if statedepM   % only for state dep. Mdel ~= 0
       Mdel = M - feval(massfun,tn,ytmp);
       rhs = rhs + Mdel*ztmp*h;
       end
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       ztmp = (ytmp - yn)/h
       end
     */
    rtsiSetT(si, t0);
    rtsiSetdX(si, f1);
    for (iter = 1; iter < numIter; iter++) {
      sPort_output();
      sPort_derivatives();
      for (i = 0; i < nx; i++) {
        Delta[i] = hN*f1[i];
        xtmp[i] = x1[i] - x0[i];
      }

      /* rhs = hN*f(tn,ytmp) - (ytmp-yn) */
      for (i = 0; i < nx; i++) {
        Delta[i] -= xtmp[i];
      }

      rt_ForwardSubstitutionRR_Dbl(W, Delta,
        f1, nx,
        1, pivots,
        1);
      rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
        Delta, nx,
        1, 0);

      /* ytmp = ytmp + delta
         ztmp = (ytmp - yn)/h
       */
      for (i = 0; i < nx; i++) {
        x1[i] += Delta[i];
        ztmp[i] = (x1[i] - x0[i])/hN;
      }
    }

    /* Steps from t0+hN to t1 -- subintegration of N(j) steps for extrapolation
       ttmp = t0;
       for i = 2:N(j)
       ttmp = ttmp + hN
       ytmp0 = ytmp;
       for iter = 1:NewtIter
       rhs = (ytmp0 - ytmp) + hN*feval(odefun,ttmp,ytmp,extraArgs{:});
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       end
       end
     */
    for (k = 1; k < N[j]; k++) {
      t1 = t0 + k*hN;
      (void) memcpy(x1start, x1,
                    (uint_T)nx*sizeof(real_T));
      rtsiSetT(si, t1);
      rtsiSetdX(si, f1);
      for (iter = 0; iter < numIter; iter++) {
        sPort_output();
        sPort_derivatives();
        if (iter == 0) {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
          }
        } else {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
            xtmp[i] = (x1[i]-x1start[i]);
          }

          /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
          for (i = 0; i < nx; i++) {
            Delta[i] -= xtmp[i];
          }
        }

        rt_ForwardSubstitutionRR_Dbl(W, Delta,
          f1, nx,
          1, pivots,
          1);
        rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
          Delta, nx,
          1, 0);

        /* ytmp = ytmp + Delta
           ztmp = (ytmp - ytmp0)/h
         */
        for (i = 0; i < nx; i++) {
          x1[i] += Delta[i];
          ztmp[i] = (x1[i] - x1start[i])/hN;
        }
      }
    }

    /* Extrapolate to order j
       E(:,j) = ytmp
       for k = j:-1:2
       coef = N(k-1)/(N(j) - N(k-1))
       E(:,k-1) = E(:,k) + coef*( E(:,k) - E(:,k-1) )
       end
     */
    (void) memcpy(&(E[nx*j]), x1,
                  (uint_T)nx*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = (real_T)(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        x1[i] = E[nx*k+i] + coef*(E[nx*k+i] - E[nx*(k-1)+i]);
      }

      (void) memcpy(&(E[nx*(k-1)]), x1,
                    (uint_T)nx*sizeof(real_T));
    }
  }

  /* x1 = E(:,1); */
  (void) memcpy(x1, E,
                (uint_T)nx*sizeof(real_T));

  /* t1 = t0 + h; */
  rtsiSetT(si,rtsiGetSolverStopTime(si));
  sPort_output();
  sPort_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void sPort_output(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  int_T tmp_0;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_1;
  char *msg;
  if (rtmIsMajorTimeStep(sPort_M)) {
    /* set solver stop time */
    if (!(sPort_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&sPort_M->solverInfo, ((sPort_M->Timing.clockTickH0
        + 1) * sPort_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&sPort_M->solverInfo, ((sPort_M->Timing.clockTick0 +
        1) * sPort_M->Timing.stepSize0 + sPort_M->Timing.clockTickH0 *
        sPort_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(sPort_M)) {
    sPort_M->Timing.t[0] = rtsiGetT(&sPort_M->solverInfo);
  }

  /* SimscapeExecutionBlock: '<S5>/STATE_1' */
  simulationData = (NeslSimulationData *)sPort_DW.STATE_1_SimulationData;
  time = sPort_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 4;
  simulationData->mData->mContStates.mX = (real_T *)&sPort_X.Upper_RevoluteRzq;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = NULL;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = NULL;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(sPort_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&sPort_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_0 = 0;
  simulationData->mData->mInputValues.mN = 0;
  simulationData->mData->mInputOffsets.mN = 1;
  simulationData->mData->mInputOffsets.mX = &tmp_0;
  simulationData->mData->mOutputs.mN = 4;
  simulationData->mData->mOutputs.mX = &sPort_B.STATE_1[0];
  simulationData->mData->mSampleHits.mN = 0;
  simulationData->mData->mSampleHits.mX = NULL;
  simulationData->mData->mIsFundamentalSampleHit = false;
  diagnosticManager = (NeuDiagnosticManager *)sPort_DW.STATE_1_DiagnosticManager;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_1 = ne_simulator_method((NeslSimulator *)sPort_DW.STATE_1_Simulator,
    NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
  if (tmp_1 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(sPort_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(sPort_M, msg);
    }
  }

  /* End of SimscapeExecutionBlock: '<S5>/STATE_1' */
}

/* Model update function */
void sPort_update(void)
{
  if (rtmIsMajorTimeStep(sPort_M)) {
    rt_ertODEUpdateContinuousStates(&sPort_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++sPort_M->Timing.clockTick0)) {
    ++sPort_M->Timing.clockTickH0;
  }

  sPort_M->Timing.t[0] = rtsiGetSolverStopTime(&sPort_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++sPort_M->Timing.clockTick1)) {
      ++sPort_M->Timing.clockTickH1;
    }

    sPort_M->Timing.t[1] = sPort_M->Timing.clockTick1 *
      sPort_M->Timing.stepSize1 + sPort_M->Timing.clockTickH1 *
      sPort_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void sPort_derivatives(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  int_T tmp_0;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_1;
  char *msg;
  XDot_sPort_T *_rtXdot;
  _rtXdot = ((XDot_sPort_T *) sPort_M->ModelData.derivs);

  /* Derivatives for SimscapeExecutionBlock: '<S5>/STATE_1' */
  simulationData = (NeslSimulationData *)sPort_DW.STATE_1_SimulationData;
  time = sPort_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 4;
  simulationData->mData->mContStates.mX = (real_T *)&sPort_X.Upper_RevoluteRzq;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = NULL;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX = NULL;
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(sPort_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&sPort_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_0 = 0;
  simulationData->mData->mInputValues.mN = 0;
  simulationData->mData->mInputOffsets.mN = 1;
  simulationData->mData->mInputOffsets.mX = &tmp_0;
  simulationData->mData->mDx.mN = 4;
  simulationData->mData->mDx.mX = (real_T *)&_rtXdot->Upper_RevoluteRzq;
  diagnosticManager = (NeuDiagnosticManager *)sPort_DW.STATE_1_DiagnosticManager;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_1 = ne_simulator_method((NeslSimulator *)sPort_DW.STATE_1_Simulator,
    NESL_SIM_DERIVATIVES, simulationData, diagnosticManager);
  if (tmp_1 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(sPort_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(sPort_M, msg);
    }
  }

  /* End of Derivatives for SimscapeExecutionBlock: '<S5>/STATE_1' */
}

/* Model initialize function */
void sPort_initialize(void)
{
  {
    NeslSimulator *tmp;
    NeuDiagnosticManager *diagnosticManager;
    real_T modelParameters_mSolverTolerance;
    real_T modelParameters_mFixedStepSize;
    boolean_T modelParameters_mVariableStepSolver;
    NeuDiagnosticTree *diagnosticTree;
    int32_T tmp_0;
    char *msg;
    NeslSimulationData *simulationData;
    real_T time;
    NeModelParameters expl_temp;

    /* Start for SimscapeExecutionBlock: '<S5>/STATE_1' */
    tmp = nesl_lease_simulator("sPort/Solver Configuration", 0, 0);
    sPort_DW.STATE_1_Simulator = (void *)tmp;
    modelParameters_mVariableStepSolver = pointer_is_null
      (sPort_DW.STATE_1_Simulator);
    if (modelParameters_mVariableStepSolver) {
      sPort_de6c5c35_gateway();
      tmp = nesl_lease_simulator("sPort/Solver Configuration", 0, 0);
      sPort_DW.STATE_1_Simulator = (void *)tmp;
    }

    simulationData = nesl_create_simulation_data();
    sPort_DW.STATE_1_SimulationData = (void *)simulationData;
    diagnosticManager = rtw_create_diagnostics();
    sPort_DW.STATE_1_DiagnosticManager = (void *)diagnosticManager;
    modelParameters_mSolverTolerance = 0.001;
    modelParameters_mFixedStepSize = 0.01;
    modelParameters_mVariableStepSolver = false;
    diagnosticManager = (NeuDiagnosticManager *)
      sPort_DW.STATE_1_DiagnosticManager;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    expl_temp.mVariableStepSolver = modelParameters_mVariableStepSolver;
    expl_temp.mUseSimState = false;
    expl_temp.mStartTime = 0.0;
    expl_temp.mSolverType = NE_SOLVER_TYPE_DAE;
    expl_temp.mSolverTolerance = modelParameters_mSolverTolerance;
    expl_temp.mLoggingMode = SSC_LOGGING_NONE;
    expl_temp.mLoadInitialState = false;
    expl_temp.mLinTrimCompile = false;
    expl_temp.mFixedStepSize = modelParameters_mFixedStepSize;
    tmp_0 = nesl_initialize_simulator((NeslSimulator *)
      sPort_DW.STATE_1_Simulator, expl_temp, diagnosticManager);
    if (tmp_0 != 0) {
      modelParameters_mVariableStepSolver = error_buffer_is_empty
        (rtmGetErrorStatus(sPort_M));
      if (modelParameters_mVariableStepSolver) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(sPort_M, msg);
      }
    }

    simulationData = (NeslSimulationData *)sPort_DW.STATE_1_SimulationData;
    time = sPort_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 4;
    simulationData->mData->mContStates.mX = (real_T *)&sPort_X.Upper_RevoluteRzq;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = NULL;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = NULL;
    modelParameters_mVariableStepSolver = false;
    simulationData->mData->mFoundZcEvents = modelParameters_mVariableStepSolver;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(sPort_M);
    modelParameters_mVariableStepSolver = false;
    simulationData->mData->mIsSolverAssertCheck =
      modelParameters_mVariableStepSolver;
    simulationData->mData->mIsSolverCheckingCIC = false;
    modelParameters_mVariableStepSolver = rtsiIsSolverComputingJacobian
      (&sPort_M->solverInfo);
    simulationData->mData->mIsComputingJacobian =
      modelParameters_mVariableStepSolver;
    simulationData->mData->mIsSolverRequestingReset = false;
    diagnosticManager = (NeuDiagnosticManager *)
      sPort_DW.STATE_1_DiagnosticManager;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_0 = ne_simulator_method((NeslSimulator *)sPort_DW.STATE_1_Simulator,
      NESL_SIM_INITIALIZEONCE, simulationData, diagnosticManager);
    if (tmp_0 != 0) {
      modelParameters_mVariableStepSolver = error_buffer_is_empty
        (rtmGetErrorStatus(sPort_M));
      if (modelParameters_mVariableStepSolver) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(sPort_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S5>/STATE_1' */
  }

  {
    boolean_T tmp;
    int_T tmp_0;
    char *tmp_1;

    /* InitializeConditions for SimscapeExecutionBlock: '<S5>/STATE_1' */
    tmp = false;
    if (tmp) {
      tmp_0 = strcmp("ode14x", rtsiGetSolverName(&sPort_M->solverInfo));
      if (tmp_0 != 0) {
        tmp_1 = solver_mismatch_message("ode14x", rtsiGetSolverName
          (&sPort_M->solverInfo));
        rtmSetErrorStatus(sPort_M, tmp_1);
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S5>/STATE_1' */
  }
}

/* Model terminate function */
void sPort_terminate(void)
{
  /* Terminate for SimscapeExecutionBlock: '<S5>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    sPort_DW.STATE_1_DiagnosticManager);
  nesl_destroy_simulation_data((NeslSimulationData *)
    sPort_DW.STATE_1_SimulationData);
  nesl_erase_simulator("sPort/Solver Configuration");
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  sPort_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  sPort_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  sPort_initialize();
}

void MdlTerminate(void)
{
  sPort_terminate();
}

/* Registration function */
RT_MODEL_sPort_T *sPort(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)sPort_M, 0,
                sizeof(RT_MODEL_sPort_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sPort_M->solverInfo, &sPort_M->Timing.simTimeStep);
    rtsiSetTPtr(&sPort_M->solverInfo, &rtmGetTPtr(sPort_M));
    rtsiSetStepSizePtr(&sPort_M->solverInfo, &sPort_M->Timing.stepSize0);
    rtsiSetdXPtr(&sPort_M->solverInfo, &sPort_M->ModelData.derivs);
    rtsiSetContStatesPtr(&sPort_M->solverInfo, (real_T **)
                         &sPort_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&sPort_M->solverInfo, &sPort_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&sPort_M->solverInfo, (&rtmGetErrorStatus(sPort_M)));
    rtsiSetRTModelPtr(&sPort_M->solverInfo, sPort_M);
  }

  rtsiSetSimTimeStep(&sPort_M->solverInfo, MAJOR_TIME_STEP);
  sPort_M->ModelData.intgData.x0 = sPort_M->ModelData.odeX0;
  sPort_M->ModelData.intgData.f0 = sPort_M->ModelData.odeF0;
  sPort_M->ModelData.intgData.x1start = sPort_M->ModelData.odeX1START;
  sPort_M->ModelData.intgData.f1 = sPort_M->ModelData.odeF1;
  sPort_M->ModelData.intgData.Delta = sPort_M->ModelData.odeDELTA;
  sPort_M->ModelData.intgData.E = sPort_M->ModelData.odeE;
  sPort_M->ModelData.intgData.fac = sPort_M->ModelData.odeFAC;

  /* initialize */
  {
    int_T i;
    real_T *f = sPort_M->ModelData.intgData.fac;
    for (i = 0; i < (int_T)(sizeof(sPort_M->ModelData.odeFAC)/sizeof(real_T)); i
         ++) {
      f[i] = 1.5e-8;
    }
  }

  sPort_M->ModelData.intgData.DFDX = sPort_M->ModelData.odeDFDX;
  sPort_M->ModelData.intgData.W = sPort_M->ModelData.odeW;
  sPort_M->ModelData.intgData.pivots = sPort_M->ModelData.odePIVOTS;
  sPort_M->ModelData.intgData.xtmp = sPort_M->ModelData.odeXTMP;
  sPort_M->ModelData.intgData.ztmp = sPort_M->ModelData.odeZTMP;
  sPort_M->ModelData.intgData.isFirstStep = true;
  rtsiSetSolverExtrapolationOrder(&sPort_M->solverInfo, 4);
  rtsiSetSolverNumberNewtonIterations(&sPort_M->solverInfo, 1);
  sPort_M->ModelData.contStates = ((real_T *) &sPort_X);
  rtsiSetSolverData(&sPort_M->solverInfo, (void *)&sPort_M->ModelData.intgData);
  rtsiSetSolverName(&sPort_M->solverInfo,"ode14x");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = sPort_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    sPort_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    sPort_M->Timing.sampleTimes = (&sPort_M->Timing.sampleTimesArray[0]);
    sPort_M->Timing.offsetTimes = (&sPort_M->Timing.offsetTimesArray[0]);

    /* task periods */
    sPort_M->Timing.sampleTimes[0] = (0.0);
    sPort_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    sPort_M->Timing.offsetTimes[0] = (0.0);
    sPort_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(sPort_M, &sPort_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = sPort_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    sPort_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(sPort_M, 10.0);
  sPort_M->Timing.stepSize0 = 0.01;
  sPort_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  sPort_M->Sizes.checksums[0] = (1162924064U);
  sPort_M->Sizes.checksums[1] = (717389515U);
  sPort_M->Sizes.checksums[2] = (4012839055U);
  sPort_M->Sizes.checksums[3] = (1603260763U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    sPort_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(sPort_M->extModeInfo,
      &sPort_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(sPort_M->extModeInfo, sPort_M->Sizes.checksums);
    rteiSetTPtr(sPort_M->extModeInfo, rtmGetTPtr(sPort_M));
  }

  sPort_M->solverInfoPtr = (&sPort_M->solverInfo);
  sPort_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&sPort_M->solverInfo, 0.01);
  rtsiSetSolverMode(&sPort_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  sPort_M->ModelData.blockIO = ((void *) &sPort_B);
  (void) memset(((void *) &sPort_B), 0,
                sizeof(B_sPort_T));

  /* states (continuous) */
  {
    real_T *x = (real_T *) &sPort_X;
    sPort_M->ModelData.contStates = (x);
    (void) memset((void *)&sPort_X, 0,
                  sizeof(X_sPort_T));
  }

  /* states (dwork) */
  sPort_M->ModelData.dwork = ((void *) &sPort_DW);
  (void) memset((void *)&sPort_DW, 0,
                sizeof(DW_sPort_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    sPort_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;
  }

  /* Initialize Sizes */
  sPort_M->Sizes.numContStates = (4);  /* Number of continuous states */
  sPort_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  sPort_M->Sizes.numY = (0);           /* Number of model outputs */
  sPort_M->Sizes.numU = (0);           /* Number of model inputs */
  sPort_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  sPort_M->Sizes.numSampTimes = (2);   /* Number of sample times */
  sPort_M->Sizes.numBlocks = (26);     /* Number of blocks */
  sPort_M->Sizes.numBlockIO = (1);     /* Number of block outputs */
  return sPort_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
