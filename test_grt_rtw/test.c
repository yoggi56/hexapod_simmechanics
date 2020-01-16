/*
 * test.c
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

#include "test.h"
#include "test_private.h"

/* Block signals (auto storage) */
B_test_T test_B;

/* Continuous states */
X_test_T test_X;

/* Block states (auto storage) */
DW_test_T test_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_test_T test_Y;

/* Real-time model */
RT_MODEL_test_T test_M_;
RT_MODEL_test_T *const test_M = &test_M_;
real_T look1_binlcpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0;
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
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
  int_T nx = 1;
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
    test_step();
    rtsiSetdX(si,p);
    test_derivatives();
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
  int_T nx = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(x0, x1,
                (uint_T)nx*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */

  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  test_derivatives();
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
      test_step();
      test_derivatives();
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
        test_step();
        test_derivatives();
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
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void test_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_FixPtSwitch;
  uint8_T rtb_FixPtSum1;
  if (rtmIsMajorTimeStep(test_M)) {
    /* set solver stop time */
    if (!(test_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&test_M->solverInfo, ((test_M->Timing.clockTickH0 +
        1) * test_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&test_M->solverInfo, ((test_M->Timing.clockTick0 + 1)
        * test_M->Timing.stepSize0 + test_M->Timing.clockTickH0 *
        test_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(test_M)) {
    test_M->Timing.t[0] = rtsiGetT(&test_M->solverInfo);
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  test_B.TransferFcn = 0.0;
  test_B.TransferFcn += test_P.TransferFcn_C * test_X.TransferFcn_CSTATE;

  /* Outport: '<Root>/Out1' */
  test_Y.Out1 = test_B.TransferFcn;
  if (rtmIsMajorTimeStep(test_M)) {
    /* Sum: '<S3>/FixPt Sum1' incorporates:
     *  Constant: '<S3>/FixPt Constant'
     *  UnitDelay: '<S2>/Output'
     */
    rtb_FixPtSum1 = (uint8_T)((uint32_T)test_DW.Output_DSTATE +
      test_P.FixPtConstant_Value);

    /* Switch: '<S4>/FixPt Switch' incorporates:
     *  Constant: '<S4>/Constant'
     */
    if (rtb_FixPtSum1 > test_P.LimitedCounter_uplimit) {
      rtb_FixPtSwitch = test_P.Constant_Value;
    } else {
      rtb_FixPtSwitch = rtb_FixPtSum1;
    }

    /* End of Switch: '<S4>/FixPt Switch' */

    /* Lookup_n-D: '<S1>/Lookup' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     *  SampleTimeMath: '<S1>/Sample Time Math'
     *  UnitDelay: '<S2>/Output'
     *
     * About '<S1>/Sample Time Math':
     *  y = u * K where K = ( w * Ts )
     */
    test_B.Lookup = look1_binlcpw((real_T)test_DW.Output_DSTATE *
      test_P.SampleTimeMath_WtEt, test_P.LEG2_X_TimeValues,
      test_P.LEG2_X_OutValues, 5U);
  }

  if (rtmIsMajorTimeStep(test_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(test_M->rtwLogInfo, (test_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(test_M)) {
    if (rtmIsMajorTimeStep(test_M)) {
      /* Update for UnitDelay: '<S2>/Output' */
      test_DW.Output_DSTATE = rtb_FixPtSwitch;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(test_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(test_M)!=-1) &&
          !((rtmGetTFinal(test_M)-(((test_M->Timing.clockTick1+
               test_M->Timing.clockTickH1* 4294967296.0)) * 0.01)) >
            (((test_M->Timing.clockTick1+test_M->Timing.clockTickH1*
               4294967296.0)) * 0.01) * (DBL_EPSILON))) {
        rtmSetErrorStatus(test_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&test_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++test_M->Timing.clockTick0)) {
      ++test_M->Timing.clockTickH0;
    }

    test_M->Timing.t[0] = rtsiGetSolverStopTime(&test_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      test_M->Timing.clockTick1++;
      if (!test_M->Timing.clockTick1) {
        test_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void test_derivatives(void)
{
  XDot_test_T *_rtXdot;
  _rtXdot = ((XDot_test_T *) test_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += test_P.TransferFcn_A *
    test_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += test_B.Lookup;
}

/* Model initialize function */
void test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)test_M, 0,
                sizeof(RT_MODEL_test_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&test_M->solverInfo, &test_M->Timing.simTimeStep);
    rtsiSetTPtr(&test_M->solverInfo, &rtmGetTPtr(test_M));
    rtsiSetStepSizePtr(&test_M->solverInfo, &test_M->Timing.stepSize0);
    rtsiSetdXPtr(&test_M->solverInfo, &test_M->ModelData.derivs);
    rtsiSetContStatesPtr(&test_M->solverInfo, (real_T **)
                         &test_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&test_M->solverInfo, &test_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&test_M->solverInfo, (&rtmGetErrorStatus(test_M)));
    rtsiSetRTModelPtr(&test_M->solverInfo, test_M);
  }

  rtsiSetSimTimeStep(&test_M->solverInfo, MAJOR_TIME_STEP);
  test_M->ModelData.intgData.x0 = test_M->ModelData.odeX0;
  test_M->ModelData.intgData.f0 = test_M->ModelData.odeF0;
  test_M->ModelData.intgData.x1start = test_M->ModelData.odeX1START;
  test_M->ModelData.intgData.f1 = test_M->ModelData.odeF1;
  test_M->ModelData.intgData.Delta = test_M->ModelData.odeDELTA;
  test_M->ModelData.intgData.E = test_M->ModelData.odeE;
  test_M->ModelData.intgData.fac = test_M->ModelData.odeFAC;

  /* initialize */
  {
    int_T i;
    real_T *f = test_M->ModelData.intgData.fac;
    for (i = 0; i < (int_T)(sizeof(test_M->ModelData.odeFAC)/sizeof(real_T)); i
         ++) {
      f[i] = 1.5e-8;
    }
  }

  test_M->ModelData.intgData.DFDX = test_M->ModelData.odeDFDX;
  test_M->ModelData.intgData.W = test_M->ModelData.odeW;
  test_M->ModelData.intgData.pivots = test_M->ModelData.odePIVOTS;
  test_M->ModelData.intgData.xtmp = test_M->ModelData.odeXTMP;
  test_M->ModelData.intgData.ztmp = test_M->ModelData.odeZTMP;
  test_M->ModelData.intgData.isFirstStep = true;
  rtsiSetSolverExtrapolationOrder(&test_M->solverInfo, 4);
  rtsiSetSolverNumberNewtonIterations(&test_M->solverInfo, 1);
  test_M->ModelData.contStates = ((X_test_T *) &test_X);
  rtsiSetSolverData(&test_M->solverInfo, (void *)&test_M->ModelData.intgData);
  rtsiSetSolverName(&test_M->solverInfo,"ode14x");
  rtmSetTPtr(test_M, &test_M->Timing.tArray[0]);
  rtmSetTFinal(test_M, 10.0);
  test_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    test_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(test_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(test_M->rtwLogInfo, (NULL));
    rtliSetLogT(test_M->rtwLogInfo, "tout");
    rtliSetLogX(test_M->rtwLogInfo, "");
    rtliSetLogXFinal(test_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(test_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(test_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(test_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(test_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &test_Y.Out1
      };

      rtliSetLogYSignalPtrs(test_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "test/Out1" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(test_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(test_M->rtwLogInfo, "yout");
  }

  /* block I/O */
  (void) memset(((void *) &test_B), 0,
                sizeof(B_test_T));

  /* states (continuous) */
  {
    (void) memset((void *)&test_X, 0,
                  sizeof(X_test_T));
  }

  /* states (dwork) */
  (void) memset((void *)&test_DW, 0,
                sizeof(DW_test_T));

  /* external outputs */
  test_Y.Out1 = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(test_M->rtwLogInfo, 0.0, rtmGetTFinal(test_M),
    test_M->Timing.stepSize0, (&rtmGetErrorStatus(test_M)));

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  test_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S2>/Output' */
  test_DW.Output_DSTATE = test_P.Output_InitialCondition;
}

/* Model terminate function */
void test_terminate(void)
{
  /* (no terminate code required) */
}
