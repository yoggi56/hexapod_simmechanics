/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sPort/Solver Configuration'.
 */

#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"

void sPort_de6c5c35_1_resetStateVector(const void *mech, double *state)
{
  double xx[1];
  (void) mech;
  xx[0] = 0.0;
  state[0] = xx[0];
  state[1] = xx[0];
  state[2] = xx[0];
  state[3] = xx[0];
}

PmfMessageId sPort_de6c5c35_1_initializeTrackedAngleState(const void *mech,
  double *state, void *neDiagMgr0)
{
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  (void) mech;
  (void) state;
  return NULL;
}

void sPort_de6c5c35_1_computeDiscreteState(const void *mech, double *state)
{
  (void) mech;
  (void) state;
}

void sPort_de6c5c35_1_adjustPosition(const void *mech, const double *dofDeltas,
  double *state)
{
  (void) mech;
  state[0] = state[0] + dofDeltas[0];
  state[2] = state[2] + dofDeltas[1];
}

static void perturbState_0_0(double mag, double *state)
{
  state[0] = state[0] + mag;
}

static void perturbState_0_0v(double mag, double *state)
{
  state[0] = state[0] + mag;
  state[1] = state[1] - 0.875 * mag;
}

static void perturbState_1_0(double mag, double *state)
{
  state[2] = state[2] + mag;
}

static void perturbState_1_0v(double mag, double *state)
{
  state[2] = state[2] + mag;
  state[3] = state[3] - 0.875 * mag;
}

void sPort_de6c5c35_1_perturbState(const void *mech, size_t stageIdx, size_t
  primIdx, double mag, boolean_T doPerturbVelocity, double *state)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) mag;
  (void) doPerturbVelocity;
  (void) state;
  switch ((stageIdx * 6 + primIdx) * 2 + (doPerturbVelocity ? 1 : 0))
  {
   case 0:
    perturbState_0_0(mag, state);
    break;

   case 1:
    perturbState_0_0v(mag, state);
    break;

   case 12:
    perturbState_1_0(mag, state);
    break;

   case 13:
    perturbState_1_0v(mag, state);
    break;
  }
}

void sPort_de6c5c35_1_computeDofBlendMatrix(const void *mech, size_t stageIdx,
  size_t primIdx, const double *state, int partialType, double *matrix)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) state;
  (void) partialType;
  (void) matrix;
  switch ((stageIdx * 6 + primIdx))
  {
  }
}

void sPort_de6c5c35_1_projectPartiallyTargetedPos(const void *mech, size_t
  stageIdx, size_t primIdx, const double *origState, int partialType, double
  *state)
{
  (void) mech;
  (void) stageIdx;
  (void) primIdx;
  (void) origState;
  (void) partialType;
  (void) state;
  switch ((stageIdx * 6 + primIdx))
  {
  }
}

void sPort_de6c5c35_1_propagateMotion(const void *mech, const double *state,
  double *motionData)
{
  double xx[47];
  (void) mech;
  xx[0] = 0.5028881265284185;
  xx[1] = 0.5;
  xx[2] = xx[1] * state[0];
  xx[3] = cos(xx[2]);
  xx[4] = xx[0] * xx[3];
  xx[5] = 0.9999328815416736;
  xx[6] = sin(xx[2]);
  xx[2] = xx[5] * xx[6];
  xx[7] = xx[0] * xx[2];
  xx[8] = 0.4970950937162199;
  xx[9] = 0.0115858712130506;
  xx[10] = xx[9] * xx[6];
  xx[6] = xx[8] * xx[10];
  xx[11] = xx[4] + xx[7] - xx[6];
  xx[13] = xx[0] * xx[10];
  xx[0] = xx[8] * xx[3];
  xx[3] = xx[8] * xx[2];
  xx[2] = xx[13] + xx[0] + xx[3];
  xx[8] = - xx[2];
  xx[10] = xx[13] - xx[0] + xx[3];
  xx[0] = xx[4] - xx[7] + xx[6];
  xx[13] = xx[8];
  xx[14] = xx[10];
  xx[15] = xx[0];
  xx[3] = 5.018884782449662e-4;
  xx[4] = xx[3] * xx[10];
  xx[6] = 0.07516512386392142;
  xx[16] = xx[2] * xx[3] - xx[6] * xx[0];
  xx[2] = xx[6] * xx[10];
  xx[17] = xx[4];
  xx[18] = xx[16];
  xx[19] = xx[2];
  pm_math_cross3(xx + 13, xx + 17, xx + 20);
  xx[7] = 2.0;
  xx[15] = 0.9999966519717261;
  xx[17] = xx[1] * state[2];
  xx[1] = cos(xx[17]);
  xx[18] = xx[15] * xx[1];
  xx[19] = - xx[18];
  xx[23] = 6.410737143340839e-3;
  xx[24] = sin(xx[17]);
  xx[17] = xx[23] * xx[24];
  xx[25] = 2.587671798894606e-3;
  xx[26] = 0.9999794510135091;
  xx[27] = xx[26] * xx[24];
  xx[24] = xx[15] * xx[17] + xx[25] * xx[27];
  xx[28] = - xx[24];
  xx[29] = xx[25] * xx[1];
  xx[1] = - xx[29];
  xx[30] = xx[25] * xx[17] - xx[15] * xx[27];
  xx[15] = 4.072700927056475e-4;
  xx[17] = xx[15] * xx[29];
  xx[31] = xx[28];
  xx[32] = xx[1];
  xx[33] = xx[30];
  xx[27] = 0.1053633658174156;
  xx[34] = xx[24] * xx[15] - xx[27] * xx[30];
  xx[25] = xx[27] * xx[29];
  xx[35] = - xx[17];
  xx[36] = xx[34];
  xx[37] = - xx[25];
  pm_math_cross3(xx + 31, xx + 35, xx + 38);
  xx[35] = 0.06491237358601078 - ((xx[18] * xx[17] + xx[38]) * xx[7] - xx[27]);
  xx[17] = (xx[39] - xx[18] * xx[34]) * xx[7];
  xx[27] = 6.379363119980433e-3 - (xx[15] + xx[7] * (xx[40] + xx[18] * xx[25]));
  xx[15] = xx[9] * state[1];
  xx[9] = 0.0;
  xx[25] = xx[5] * state[1];
  xx[5] = 0.07516589371196002 * state[1];
  xx[34] = xx[29] * xx[25];
  xx[36] = xx[15] * xx[30] + xx[24] * xx[25];
  xx[24] = xx[29] * xx[15];
  xx[37] = - xx[34];
  xx[38] = xx[36];
  xx[39] = xx[24];
  pm_math_cross3(xx + 31, xx + 37, xx + 40);
  xx[43] = xx[19];
  xx[44] = xx[28];
  xx[45] = xx[1];
  xx[46] = xx[30];
  xx[31] = xx[17] * xx[25];
  xx[32] = xx[25] * xx[35] - xx[15] * xx[27] + xx[5];
  xx[33] = - xx[17] * xx[15];
  pm_math_quatInverseXform(xx + 43, xx + 31, xx + 37);
  motionData[0] = - xx[11];
  motionData[1] = xx[8];
  motionData[2] = xx[10];
  motionData[3] = xx[0];
  motionData[4] = - ((xx[20] - xx[4] * xx[11]) * xx[7] - xx[6]);
  motionData[5] = - (7.5e-3 + (xx[21] - xx[11] * xx[16]) * xx[7]);
  motionData[6] = - (xx[3] + xx[7] * (xx[22] - xx[2] * xx[11]));
  motionData[7] = xx[19];
  motionData[8] = xx[28];
  motionData[9] = xx[1];
  motionData[10] = xx[30];
  motionData[11] = xx[35];
  motionData[12] = - xx[17];
  motionData[13] = xx[27];
  motionData[14] = xx[15];
  motionData[15] = xx[9];
  motionData[16] = xx[25];
  motionData[17] = xx[9];
  motionData[18] = xx[5];
  motionData[19] = xx[9];
  motionData[20] = xx[15] + xx[7] * (xx[40] - xx[18] * xx[34]) + xx[23] * state
    [3];
  motionData[21] = xx[7] * (xx[41] + xx[18] * xx[36]);
  motionData[22] = xx[25] + (xx[18] * xx[24] + xx[42]) * xx[7] + xx[26] * state
    [3];
  motionData[23] = xx[37];
  motionData[24] = xx[38] + 0.1053638116085455 * state[3];
  motionData[25] = xx[39];
}

size_t sPort_de6c5c35_1_computeAssemblyError(const void *mech, size_t
  constraintIdx, const double *state, const double *motionData, double *error)
{
  (void) mech;
  (void) state;
  (void) motionData;
  (void) error;
  (void) state;
  switch (constraintIdx)
  {
  }

  return 0;
}

size_t sPort_de6c5c35_1_computeAssemblyJacobian(const void *mech, size_t
  constraintIdx, boolean_T forVelocitySatisfaction, const double *state, const
  double *motionData, double *J)
{
  (void) mech;
  (void) state;
  (void) forVelocitySatisfaction;
  (void) motionData;
  (void) J;
  switch (constraintIdx)
  {
  }

  return 0;
}

size_t sPort_de6c5c35_1_computeFullAssemblyJacobian(const void *mech, const
  double *state, const double *motionData, double *J)
{
  (void) mech;
  (void) state;
  (void) motionData;
  (void) J;
  return 0;
}

PmfMessageId sPort_de6c5c35_1_convertStateVector(const void *asmMech, const void
  *simMech, const double *asmState, double *simState, void *neDiagMgr0)
{
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  (void) asmMech;
  (void) simMech;
  simState[0] = asmState[0];
  simState[1] = asmState[1];
  simState[2] = asmState[2];
  simState[3] = asmState[3];
  return NULL;
}

void sPort_de6c5c35_1_constructStateVector(const void *mech, const double
  *solverState, const double *u, const double *uDot, double *discreteState,
  double *fullState)
{
  (void) mech;
  (void) u;
  (void) uDot;
  (void) discreteState;
  fullState[0] = solverState[0];
  fullState[1] = solverState[1];
  fullState[2] = solverState[2];
  fullState[3] = solverState[3];
}

void sPort_de6c5c35_1_extractSolverStateVector(const void *mech, const double
  *fullState, double *solverState)
{
  (void) mech;
  solverState[0] = fullState[0];
  solverState[1] = fullState[1];
  solverState[2] = fullState[2];
  solverState[3] = fullState[3];
}

int sPort_de6c5c35_1_isPositionViolation(const void *mech, const double *state)
{
  (void) mech;
  (void) state;
  return 0;
}

int sPort_de6c5c35_1_isVelocityViolation(const void *mech, const double *state)
{
  (void) mech;
  (void) state;
  return 0;
}

PmfMessageId sPort_de6c5c35_1_projectStateSim(const void *mech, const double
  *input, double *state, void *neDiagMgr0)
{
  NeuDiagnosticManager *neDiagMgr = (NeuDiagnosticManager *) neDiagMgr0;
  (void) mech;
  (void) input;
  (void) state;
  return NULL;
}
