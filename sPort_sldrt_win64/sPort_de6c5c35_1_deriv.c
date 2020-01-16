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
  double xx[104];
  int ii[4];
  (void) input;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = 0.9999966519717261;
  xx[1] = 0.5;
  xx[2] = xx[1] * state[2];
  xx[3] = cos(xx[2]);
  xx[4] = xx[0] * xx[3];
  xx[6] = 6.410737143340839e-3;
  xx[7] = sin(xx[2]);
  xx[2] = xx[6] * xx[7];
  xx[8] = 2.587671798894606e-3;
  xx[9] = 0.9999794510135091;
  xx[10] = xx[9] * xx[7];
  xx[7] = xx[0] * xx[2] + xx[8] * xx[10];
  xx[11] = - xx[7];
  xx[12] = xx[8] * xx[3];
  xx[3] = - xx[12];
  xx[13] = xx[8] * xx[2] - xx[0] * xx[10];
  xx[14] = - xx[4];
  xx[15] = xx[11];
  xx[16] = xx[3];
  xx[17] = xx[13];
  xx[0] = 0.0115858712130506;
  xx[2] = xx[0] * state[1];
  xx[5] = 2.0;
  xx[18] = xx[11];
  xx[19] = xx[3];
  xx[20] = xx[13];
  xx[3] = 0.9999328815416736;
  xx[8] = xx[3] * state[1];
  xx[10] = xx[8] * xx[12];
  xx[21] = xx[2] * xx[13] + xx[7] * xx[8];
  xx[22] = xx[2] * xx[12];
  xx[23] = - xx[10];
  xx[24] = xx[21];
  xx[25] = xx[22];
  pm_math_cross3(xx + 18, xx + 23, xx + 26);
  xx[11] = xx[2] + xx[5] * (xx[26] - xx[10] * xx[4]);
  xx[10] = xx[6] * state[3];
  xx[23] = xx[11] + xx[10];
  xx[24] = xx[5] * (xx[27] + xx[4] * xx[21]);
  xx[21] = xx[8] + (xx[22] * xx[4] + xx[28]) * xx[5];
  xx[22] = xx[9] * state[3];
  xx[25] = xx[21] + xx[22];
  xx[27] = 9.576938279530255e-7;
  xx[29] = 1.045648095010161e-4;
  xx[31] = 1.053072449675825e-4;
  xx[33] = xx[23] * xx[27];
  xx[34] = xx[29] * xx[24];
  xx[35] = xx[25] * xx[31];
  pm_math_cross3(xx + 23, xx + 33, xx + 36);
  xx[26] = xx[36] + xx[27] * xx[24] * xx[22];
  xx[28] = 6.139523394806731e-9;
  xx[30] = xx[38] - xx[31] * xx[24] * xx[10];
  xx[24] = 0.1053638116085455;
  xx[32] = 0.02635612271749689;
  xx[33] = 4.072700927056475e-4;
  xx[34] = xx[33] * xx[12];
  xx[39] = 0.1053633658174156;
  xx[41] = xx[7] * xx[33] - xx[39] * xx[13];
  xx[40] = xx[39] * xx[12];
  xx[42] = - xx[34];
  xx[43] = xx[41];
  xx[44] = - xx[40];
  pm_math_cross3(xx + 18, xx + 42, xx + 45);
  xx[35] = 0.06491237358601078 - ((xx[34] * xx[4] + xx[45]) * xx[5] - xx[39]);
  xx[34] = 6.379363119980433e-3 - (xx[33] + xx[5] * (xx[47] + xx[40] * xx[4]));
  xx[33] = xx[8] * xx[35] - xx[2] * xx[34];
  xx[39] = (xx[46] - xx[4] * xx[41]) * xx[5];
  xx[42] = - xx[8] * xx[33];
  xx[43] = xx[8] * xx[8] * xx[39] + xx[2] * xx[2] * xx[39];
  xx[44] = xx[2] * xx[33];
  pm_math_quatInverseXform(xx + 14, xx + 42, xx + 45);
  xx[33] = xx[32] * xx[46];
  xx[40] = 3.978963171982543e-4;
  memcpy(ii + 2, ii + 0, 1 * sizeof(int));
  ii[1] = factorSymmetric(xx + 40, 1, xx + 43, xx + 42, ii + 2, ii + 3);
  if (ii[3] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:DegenerateMass",
      "'sPort/Lower Revolute' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[41] = (xx[26] * xx[6] + xx[9] * xx[30] + xx[24] * xx[33]) / xx[40];
  xx[6] = 1.053050810104283e-4;
  xx[48] = xx[26] - xx[28] * xx[41];
  xx[49] = xx[37] + xx[29] * (xx[21] * xx[10] - xx[11] * xx[22]);
  xx[50] = xx[30] - xx[6] * xx[41];
  pm_math_quatXform(xx + 14, xx + 48, xx + 36);
  xx[42] = xx[35];
  xx[43] = - xx[39];
  xx[44] = xx[34];
  xx[9] = xx[24] * state[3];
  xx[22] = 2.776981548738048e-3;
  xx[48] = xx[32] * (xx[45] - (xx[21] + xx[25]) * xx[9]);
  xx[49] = xx[33] - xx[22] * xx[41];
  xx[50] = ((xx[11] + xx[23]) * xx[9] + xx[47]) * xx[32];
  pm_math_quatXform(xx + 14, xx + 48, xx + 9);
  pm_math_cross3(xx + 42, xx + 9, xx + 23);
  xx[9] = xx[7] * xx[12];
  xx[11] = xx[4] * xx[13];
  xx[21] = xx[5] * (xx[9] + xx[11]);
  xx[26] = xx[22] / xx[40];
  xx[30] = xx[28] * xx[26];
  xx[33] = xx[21] * xx[30];
  xx[45] = xx[4] * xx[4];
  xx[47] = 1.0;
  xx[48] = (xx[45] + xx[7] * xx[7]) * xx[5] - xx[47];
  xx[46] = xx[6] * xx[26];
  xx[50] = xx[21] * xx[46];
  xx[51] = xx[12] * xx[4];
  xx[52] = xx[7] * xx[13];
  xx[54] = (xx[51] - xx[52]) * xx[5];
  xx[53] = xx[33] * xx[48] + xx[50] * xx[54];
  xx[49] = (xx[9] - xx[11]) * xx[5];
  xx[9] = (xx[45] + xx[12] * xx[12]) * xx[5] - xx[47];
  xx[11] = xx[12] * xx[13];
  xx[55] = xx[7] * xx[4];
  xx[57] = xx[5] * (xx[11] + xx[55]);
  xx[56] = xx[5] * (xx[52] + xx[51]);
  xx[51] = (xx[55] - xx[11]) * xx[5];
  xx[11] = (xx[45] + xx[13] * xx[13]) * xx[5] - xx[47];
  xx[59] = xx[48];
  xx[60] = xx[21];
  xx[61] = xx[54];
  xx[62] = xx[49];
  xx[63] = xx[9];
  xx[64] = - xx[57];
  xx[65] = - xx[56];
  xx[66] = xx[51];
  xx[67] = xx[11];
  xx[45] = xx[32] - xx[22] * xx[26];
  xx[68] = xx[32] * xx[48];
  xx[69] = xx[32] * xx[49];
  xx[70] = - xx[32] * xx[56];
  xx[71] = xx[21] * xx[45];
  xx[72] = xx[45] * xx[9];
  xx[73] = xx[51] * xx[45];
  xx[74] = xx[32] * xx[54];
  xx[75] = - xx[32] * xx[57];
  xx[76] = xx[32] * xx[11];
  pm_math_matrix3x3Compose(xx + 59, xx + 68, xx + 77);
  pm_math_matrix3x3PostCross(xx + 77, xx + 42, xx + 68);
  xx[22] = xx[53] + xx[68];
  xx[32] = 0.07516589371196002;
  xx[45] = xx[32] * state[1];
  xx[47] = xx[45] * xx[8];
  xx[8] = xx[30] * xx[51];
  xx[52] = xx[46] * xx[51];
  xx[58] = xx[8] * xx[48] + xx[52] * xx[54];
  xx[55] = xx[58] + xx[74];
  xx[77] = xx[2] * xx[45];
  xx[2] = xx[50] * xx[11] - xx[56] * xx[33];
  xx[24] = xx[2] + xx[70];
  xx[37] = xx[52] * xx[11] - xx[56] * xx[8];
  xx[45] = xx[37] + xx[76];
  xx[79] = xx[28] / xx[40];
  xx[83] = xx[27] - xx[28] * xx[79];
  xx[27] = xx[6] * xx[79];
  xx[85] = xx[6] / xx[40];
  xx[40] = xx[31] - xx[6] * xx[85];
  xx[86] = xx[83] * xx[48] - xx[27] * xx[54];
  xx[87] = xx[49] * xx[83] + xx[57] * xx[27];
  xx[88] = - (xx[56] * xx[83] + xx[27] * xx[11]);
  xx[89] = xx[29] * xx[21];
  xx[90] = xx[29] * xx[9];
  xx[91] = xx[29] * xx[51];
  xx[92] = xx[54] * xx[40] - xx[27] * xx[48];
  xx[93] = - (xx[57] * xx[40] + xx[27] * xx[49]);
  xx[94] = xx[40] * xx[11] + xx[56] * xx[27];
  pm_math_matrix3x3Compose(xx + 59, xx + 86, xx + 95);
  xx[6] = xx[30] * xx[9];
  xx[21] = xx[46] * xx[9];
  xx[9] = xx[6] * xx[48] + xx[21] * xx[54];
  xx[27] = xx[21] * xx[11] - xx[56] * xx[6];
  xx[59] = - xx[53];
  xx[60] = - xx[9];
  xx[61] = - xx[58];
  xx[62] = - (xx[49] * xx[33] - xx[57] * xx[50]);
  xx[63] = - (xx[49] * xx[6] - xx[57] * xx[21]);
  xx[64] = - (xx[49] * xx[8] - xx[57] * xx[52]);
  xx[65] = - xx[2];
  xx[66] = - xx[27];
  xx[67] = - xx[37];
  pm_math_matrix3x3PostCross(xx + 59, xx + 42, xx + 86);
  pm_math_matrix3x3PreCross(xx + 68, xx + 42, xx + 57);
  xx[2] = xx[9] + xx[71];
  xx[6] = xx[27] + xx[73];
  xx[8] = (0.01596343559791407 + xx[81]) * xx[32] - (xx[2] * xx[0] + xx[6] * xx
    [3]);
  xx[11] = xx[0] * ((5.841331749688078e-7 + xx[95] - xx[86] - xx[86] - xx[57]) *
                    xx[0] + xx[3] * (xx[97] - xx[88] - xx[92] - xx[59]) - xx[2] *
                    xx[32]) + xx[3] * (xx[0] * (xx[101] - xx[92] - xx[88] - xx
    [63]) + (3.35492885408098e-5 + xx[103] - xx[94] - xx[94] - xx[65]) * xx[3] -
    xx[6] * xx[32]) + xx[32] * xx[8];
  ii[1] = factorSymmetric(xx + 11, 1, xx + 27, xx + 2, ii + 0, ii + 2);
  if (ii[2] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:DegenerateMass",
      "'sPort/Upper Revolute' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[27] = (xx[32] * xx[78] - (xx[22] * xx[0] + xx[24] * xx[3])) / xx[11];
  xx[28] = xx[8] / xx[11];
  xx[29] = (xx[32] * xx[84] - (xx[55] * xx[0] + xx[45] * xx[3])) / xx[11];
  xx[2] = 9.810000000000001;
  xx[6] = 0.5028881265284185;
  xx[8] = xx[1] * state[0];
  xx[9] = sin(xx[8]);
  xx[21] = xx[0] * xx[9];
  xx[30] = xx[6] * xx[21];
  xx[31] = 0.4970950937162199;
  xx[37] = cos(xx[8]);
  xx[8] = xx[31] * xx[37];
  xx[40] = xx[3] * xx[9];
  xx[42] = xx[31] * xx[40];
  xx[43] = xx[30] - xx[8] + xx[42];
  xx[9] = xx[2] * xx[43];
  xx[44] = xx[6] * xx[37];
  xx[37] = xx[6] * xx[40];
  xx[6] = xx[31] * xx[21];
  xx[21] = xx[44] + xx[37] - xx[6];
  xx[31] = xx[30] + xx[8] + xx[42];
  xx[8] = xx[31] * xx[2];
  xx[30] = xx[44] - xx[37] + xx[6];
  xx[6] = xx[5] * (xx[9] * xx[21] - xx[8] * xx[30]);
  xx[37] = (xx[8] * xx[21] + xx[9] * xx[30]) * xx[5];
  xx[21] = xx[2] - (xx[31] * xx[8] + xx[9] * xx[43]) * xx[5];
  xx[42] = xx[6];
  xx[43] = xx[37];
  xx[44] = xx[21];
  xx[2] = ((xx[36] + xx[23] + xx[22] * xx[47] - xx[55] * xx[77]) * xx[0] + (xx
            [38] + xx[25] + xx[24] * xx[47] - xx[45] * xx[77]) * xx[3] + (xx[10]
            + xx[82] * xx[77] - xx[80] * xx[47]) * xx[32]) / xx[11] +
    pm_math_dot3(xx + 27, xx + 42);
  xx[1] = xx[2] * xx[3];
  xx[8] = xx[12] * xx[1];
  xx[10] = xx[2] * xx[0];
  xx[0] = xx[12] * xx[10];
  xx[22] = xx[8];
  xx[23] = - (xx[7] * xx[1] + xx[10] * xx[13]);
  xx[24] = - xx[0];
  pm_math_cross3(xx + 18, xx + 22, xx + 11);
  xx[18] = xx[6] - xx[47] - xx[39] * xx[1];
  xx[19] = xx[37] - xx[2] * xx[32] + xx[10] * xx[34] - xx[1] * xx[35];
  xx[20] = xx[21] + xx[77] + xx[39] * xx[10];
  pm_math_quatInverseXform(xx + 14, xx + 18, xx + 21);
  deriv[0] = state[1];
  deriv[1] = - xx[2];
  deriv[2] = state[3];
  deriv[3] = - (xx[41] + xx[79] * ((xx[4] * xx[8] + xx[11]) * xx[5] - xx[10]) +
                xx[85] * (xx[5] * (xx[13] - xx[4] * xx[0]) - xx[1]) + xx[26] *
                xx[22]);
  errorResult[0] = 0.0;
  return NULL;
}
