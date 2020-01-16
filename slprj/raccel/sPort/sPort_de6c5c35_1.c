/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sPort/Solver Configuration'.
 */

#include "ne_std.h"
#include "ne_default_allocator.h"
#include "ne_dae.h"
#include "ne_solverparameters.h"
#include "sm_ssci_NeDaePrivateData.h"

NeDae *sm_ssci_constructDae(NeDaePrivateData *smData);
void sPort_de6c5c35_1_NeDaePrivateData_create(NeDaePrivateData *smData);
void sPort_de6c5c35_1_dae(
  NeDae **dae,
  const NeModelParameters *modelParams,
  const NeSolverParameters *solverParams,
  const NeLinearAlgebra *linear_algebra_ptr)
{
  NeAllocator *alloc = ne_default_allocator();
  NeDaePrivateData *smData =
    (NeDaePrivateData *) alloc->mCallocFcn(alloc, sizeof(NeDaePrivateData), 1);
  (void) modelParams;
  (void) solverParams;
  (void) linear_algebra_ptr;
  sPort_de6c5c35_1_NeDaePrivateData_create(smData);
  *dae = sm_ssci_constructDae(smData);
}
