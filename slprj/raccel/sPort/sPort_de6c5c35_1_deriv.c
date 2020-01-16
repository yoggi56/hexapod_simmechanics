/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sPort/Solver Configuration'.
 */

#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"

PmfMessageId sPort_de6c5c35_1_deriv(const double *state, const double *input,
  const double *inputDot, const double *inputDdot, const double *discreteState,
  double *deriv, double *errorResult, NeuDiagnosticManager *neDiagMgr)
{
  double xx[44];
  int ii[3];
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = 0.0115858712130506;
  xx[1] = xx[0] * inputDot[0];
  xx[2] = 2.0;
  xx[3] = 0.9999966519717261;
  xx[4] = 6.410737143340839e-3;
  xx[5] = 0.5;
  xx[6] = xx[5] * state[0];
  xx[7] = sin(xx[6]);
  xx[8] = xx[4] * xx[7];
  xx[10] = 2.587671798894606e-3;
  xx[11] = 0.9999794510135091;
  xx[12] = xx[11] * xx[7];
  xx[7] = xx[3] * xx[8] + xx[10] * xx[12];
  xx[9] = - xx[7];
  xx[13] = cos(xx[6]);
  xx[6] = xx[10] * xx[13];
  xx[14] = - xx[6];
  xx[15] = xx[10] * xx[8] - xx[3] * xx[12];
  xx[16] = xx[9];
  xx[17] = xx[14];
  xx[18] = xx[15];
  xx[8] = 0.9999328815416736;
  xx[10] = xx[8] * inputDot[0];
  xx[12] = xx[6] * xx[10];
  xx[19] = xx[1] * xx[15] + xx[7] * xx[10];
  xx[20] = xx[6] * xx[1];
  xx[21] = - xx[12];
  xx[22] = xx[19];
  xx[23] = xx[20];
  pm_math_cross3(xx + 16, xx + 21, xx + 24);
  xx[21] = xx[3] * xx[13];
  xx[13] = xx[4] * state[1];
  xx[23] = xx[1] + xx[2] * (xx[24] - xx[21] * xx[12]) + xx[13];
  xx[3] = xx[2] * (xx[25] + xx[21] * xx[19]);
  xx[12] = xx[11] * state[1];
  xx[19] = xx[10] + (xx[21] * xx[20] + xx[26]) * xx[2] + xx[12];
  xx[24] = xx[23];
  xx[25] = xx[3];
  xx[26] = xx[19];
  xx[20] = 9.576938279530255e-7;
  xx[22] = 1.053072449675825e-4;
  xx[27] = xx[23] * xx[20];
  xx[28] = 1.045648095010161e-4 * xx[3];
  xx[29] = xx[19] * xx[22];
  pm_math_cross3(xx + 24, xx + 27, xx + 30);
  xx[19] = 2.776981548738048e-3;
  xx[23] = - xx[21];
  xx[24] = xx[9];
  xx[25] = xx[14];
  xx[26] = xx[15];
  xx[9] = 4.072700927056475e-4;
  xx[14] = xx[9] * xx[6];
  xx[27] = 0.1053633658174156;
  xx[29] = xx[7] * xx[9] - xx[27] * xx[15];
  xx[9] = xx[27] * xx[6];
  xx[33] = - xx[14];
  xx[34] = xx[29];
  xx[35] = - xx[9];
  pm_math_cross3(xx + 16, xx + 33, xx + 36);
  xx[27] = 0.1702757394034264 - (xx[21] * xx[14] + xx[36]) * xx[2];
  xx[14] = 5.972093027274786e-3 - xx[2] * (xx[38] + xx[21] * xx[9]);
  xx[9] = xx[10] * xx[27] - xx[1] * xx[14];
  xx[28] = (xx[37] - xx[21] * xx[29]) * xx[2];
  xx[33] = - xx[10] * xx[9];
  xx[34] = xx[28] * xx[10] * xx[10] + xx[28] * xx[1] * xx[1];
  xx[35] = xx[1] * xx[9];
  pm_math_quatInverseXform(xx + 23, xx + 33, xx + 36);
  xx[9] = 3.978963171982543e-4;
  ii[1] = factorSymmetric(xx + 9, 1, xx + 33, xx + 29, ii + 0, ii + 2);
  if (ii[2] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:DegenerateMass",
      "'sPort/Lower Revolute' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[29] = xx[0] * inputDdot[0];
  xx[31] = xx[8] * inputDdot[0];
  xx[33] = xx[6] * xx[31];
  xx[35] = xx[6] * xx[29];
  xx[38] = - xx[33];
  xx[39] = xx[29] * xx[15] + xx[7] * xx[31];
  xx[40] = xx[35];
  pm_math_cross3(xx + 16, xx + 38, xx + 41);
  xx[6] = 9.810000000000001;
  xx[7] = 0.5028881265284185;
  xx[15] = xx[5] * input[0];
  xx[5] = sin(xx[15]);
  xx[16] = xx[0] * xx[5];
  xx[0] = xx[7] * xx[16];
  xx[17] = 0.4970950937162199;
  xx[18] = cos(xx[15]);
  xx[15] = xx[17] * xx[18];
  xx[34] = xx[8] * xx[5];
  xx[5] = xx[17] * xx[34];
  xx[8] = xx[0] - xx[15] + xx[5];
  xx[36] = xx[6] * xx[8];
  xx[38] = xx[7] * xx[18];
  xx[18] = xx[7] * xx[34];
  xx[7] = xx[17] * xx[16];
  xx[16] = xx[38] + xx[18] - xx[7];
  xx[34] = xx[0] + xx[15] + xx[5];
  xx[0] = xx[34] * xx[6];
  xx[5] = xx[38] - xx[18] + xx[7];
  xx[7] = 0.07516589371196002;
  xx[15] = xx[7] * inputDot[0];
  xx[38] = xx[2] * (xx[36] * xx[16] - xx[0] * xx[5]) - xx[10] * xx[15] + xx[28] *
    xx[31];
  xx[39] = (xx[0] * xx[16] + xx[36] * xx[5]) * xx[2] + xx[7] * inputDdot[0] +
    xx[31] * xx[27] - xx[29] * xx[14];
  xx[40] = xx[1] * xx[15] - (xx[34] * xx[0] + xx[36] * xx[8]) * xx[2] - xx[28] *
    xx[29] + xx[6];
  pm_math_quatInverseXform(xx + 23, xx + 38, xx + 5);
  deriv[0] = state[1];
  deriv[1] = - (((xx[30] + xx[20] * xx[12] * xx[3]) * xx[4] + xx[11] * (xx[32] -
    xx[22] * xx[13] * xx[3]) + xx[19] * xx[37]) / xx[9] + 6.139523394806731e-9 *
                (xx[29] + xx[2] * (xx[41] - xx[21] * xx[33])) / xx[9] +
                1.053050810104283e-4 * (xx[31] + (xx[21] * xx[35] + xx[43]) *
    xx[2]) / xx[9] + xx[19] * xx[6] / xx[9]);
  errorResult[0] = 0.0;
  return NULL;
}
