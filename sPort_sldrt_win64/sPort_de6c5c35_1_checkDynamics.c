/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sPort/Solver Configuration'.
 */

#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"

PmfMessageId sPort_de6c5c35_1_checkDynamics(const double *state, const double
  *input, const double *inputDot, const double *inputDdot, const double
  *discreteState, double *result, NeuDiagnosticManager *neDiagMgr)
{
  (void) state;
  (void) input;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  result[0] = 0.0;
  return NULL;
}
