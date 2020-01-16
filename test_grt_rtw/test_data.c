/*
 * test_data.c
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

/* Block parameters (auto storage) */
P_test_T test_P = {
  /*  Mask Parameter: LEG2_X_OutValues
   * Referenced by: '<S1>/Lookup'
   */
  { 0.0, 4.0, 4.0, -4.0, -4.0, 0.0 },

  /*  Mask Parameter: LEG2_X_TimeValues
   * Referenced by: '<S1>/Lookup'
   */
  { 0.0, 0.25, 0.5, 1.5, 1.75, 2.0 },
  200U,                                /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S4>/FixPt Switch'
                                        */
  -1.0,                                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  1.0,                                 /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  0.01,                                /* Computed Parameter: SampleTimeMath_WtEt
                                        * Referenced by: '<S1>/Sample Time Math'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S4>/Constant'
                                        */
  0U,                                  /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S2>/Output'
                                        */
  1U                                   /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S3>/FixPt Constant'
                                        */
};
