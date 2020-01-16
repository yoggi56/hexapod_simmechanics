/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sPort/Solver Configuration'.
 */

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "nesl_rtw.h"
#include "sPort_de6c5c35_1.h"

void sPort_de6c5c35_gateway(void)
{
  NeModelParameters modelparams = { (NeSolverType) 0, 0.001, 0, 0.01, 0, 0, 0, 0,
    (SscLoggingSetting) 0, };

  NeSolverParameters solverparams = { 0, 0, 1, 0, 0, 0.001, 1e-06, 1e-09, 0, 0,
    100, 0, 1e-09, 0, (NeAdvancerChoice) 1, 0.001, 1, 3, 2,
    (NeLinearAlgebraChoice) 0, 1024, 1, 0.001, };

  const NeOutputParameters* outputparameters = NULL;
  const NeLinearAlgebra* linear_algebra_ptr = ((solverparams.mLinearAlgebra ==
    NE_FULL_LA) ? get_rtw_linear_algebra() : neu_get_csparse_linear_algebra());
  NeDae* dae[1];
  size_t numOutputs = 0;
  sPort_de6c5c35_1_dae(&dae[0],
                       &modelparams,
                       &solverparams,
                       linear_algebra_ptr);
  nesl_register_simulator_group("sPort/Solver Configuration",
    1,
    dae,
    solverparams,
    modelparams,
    numOutputs,
    outputparameters,
    1);
}
