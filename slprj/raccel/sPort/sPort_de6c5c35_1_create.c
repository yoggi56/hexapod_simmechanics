/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'sPort/Solver Configuration'.
 */

#include "pm_std.h"
#include "ne_std.h"
#include "ne_dae.h"
#include "ne_default_allocator.h"
#include "sm_ssci_NeDaePrivateData.h"
#include "sm_CTarget.h"

PmfMessageId sm_ssci_recordRunTimeError(
  const char *errorId, const char *errorMsg, NeuDiagnosticManager* mgr);

#define ne_allocator_alloc(_allocator, _m, _n) ((_allocator)->mCallocFcn((_allocator), (_m), (_n)))
#define NE_ALLOCATE_ARRAY(_name, _type, _size, _allocator)\
 _name = (_type *) ne_allocator_alloc(_allocator, sizeof(_type), _size)
#define ne_size_to_int(_size)          ((int32_T) (_size))

NeIntVector *neu_create_int_vector(size_t, NeAllocator *);
int_T neu_create_int_vector_fields (NeIntVector *, size_t, NeAllocator *);
int_T neu_create_real_vector_fields(NeRealVector *, size_t, NeAllocator *);
int_T neu_create_char_vector_fields(NeCharVector *, size_t, NeAllocator *);
int_T neu_create_bool_vector_fields(NeBoolVector *, size_t, NeAllocator *);
void neu_rv_equals_rv(const NeRealVector *, const NeRealVector *);
void sm_ssci_setupLoggerFcn_codeGen(const NeDae *dae,
  NeLoggerBuilder *neLoggerBuilder);
int32_T sm_ssci_logFcn_codeGen(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeRealVector *output);
PmfMessageId sPort_de6c5c35_1_deriv(
  const double *,
  const double *, const double *, const double *,
  const double *,
  double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId sPort_de6c5c35_1_checkDynamics(
  const double *,
  const double *, const double *, const double *,
  const double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId sPort_de6c5c35_1_outputDyn(
  const double *,
  const double *, const double *, const double *,
  const double *,
  double *,
  double *,
  int *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId sPort_de6c5c35_1_outputKin(
  const double *,
  const double *, const double *, const double *,
  const double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId sPort_de6c5c35_1_output (
  const double *,
  const double *, const double *, const double *,
  const double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
void sPort_de6c5c35_1_resetStateVector(const void *mech, double *stateVector);
PmfMessageId sPort_de6c5c35_1_initializeTrackedAngleState(
  const void *mech,
  double *stateVector,
  void *neDiagMgr);
void sPort_de6c5c35_1_computeDiscreteState(const void *mech, double *stateVector);
void sPort_de6c5c35_1_adjustPosition(
  const void *mech,
  const double *dofDeltas,
  double *stateVector);
void sPort_de6c5c35_1_perturbState(
  const void *mech,
  size_t stageIdx,
  size_t primitiveIdx,
  double magnitude,
  boolean_T doPerturbVelocity,
  double *stateVector);
void sPort_de6c5c35_1_computeDofBlendMatrix(
  const void *mech,
  size_t stageIdx,
  size_t primitiveIdx,
  const double *stateVector,
  int partialType,
  double *matrix);
void sPort_de6c5c35_1_projectPartiallyTargetedPos(
  const void *mech,
  size_t stageIdx,
  size_t primitiveIdx,
  const double *origStateVector,
  int partialType,
  double *stateVector);
void sPort_de6c5c35_1_propagateMotion(
  const void *mech,
  const double *stateVector,
  double *motionData);
size_t sPort_de6c5c35_1_computeAssemblyError(
  const void *mech,
  size_t constraintIdx,
  const double *stateVector,
  const double *motionData,
  double *error);
size_t sPort_de6c5c35_1_computeAssemblyJacobian(
  const void *mech,
  size_t constraintIdx,
  boolean_T forVelocitySatisfaction,
  const double *stateVector,
  const double *motionData,
  double *J);
size_t sPort_de6c5c35_1_computeFullAssemblyJacobian(
  const void *mech,
  const double *stateVector,
  const double *motionData,
  double *J);
PmfMessageId sPort_de6c5c35_1_convertStateVector(
  const void *asmMech,
  const void *simMech,
  const double *asmStateVector,
  double *simStateVector,
  void *neDiagMgr);
void sPort_de6c5c35_1_constructStateVector(
  const void *mech,
  const double *solverStateVector,
  const double *u,
  const double *uDot,
  const double *discreteStateVector,
  double *fullStateVector);
void sPort_de6c5c35_1_extractSolverStateVector(
  const void *mech,
  const double *fullStateVector,
  double *solverStateVector);
int sPort_de6c5c35_1_isPositionViolation(
  const void *mech,
  const double *stateVector);
int sPort_de6c5c35_1_isVelocityViolation(
  const void *mech,
  const double *stateVector);
PmfMessageId sPort_de6c5c35_1_projectStateSim(
  const void *mech,
  const double *inputVector,
  double *stateVector,
  void *neDiagMgr);
PmfMessageId sPort_de6c5c35_1_assemble(const double *u, double *udot, double *x,
  NeuDiagnosticManager *neDiagMgr)
{
  (void) x;
  (void) u;
  (void) udot;
  return NULL;
}

static
  PmfMessageId dae_cg_deriv_method(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeDaeMethodOutput *daeMethodOutput,
  NeuDiagnosticManager *neDiagMgr)
{
  const NeDaePrivateData *smData = dae->mPrivateData;
  PmfMessageId errorId = NULL;
  double errorResult = 0.0;
  if (smData->mCachedDerivativesAvailable)
    memcpy(daeMethodOutput->mXP0.mX, smData->mCachedDerivatives.mX,
           2 * sizeof(real_T));
  else
    errorId = sPort_de6c5c35_1_deriv(
      systemInput->mX.mX,
      systemInput->mU.mX,
      systemInput->mU.mX + 1,
      systemInput->mV.mX + 1,
      systemInput->mD.mX,
      daeMethodOutput->mXP0.mX,
      &errorResult,
      neDiagMgr);
  return errorId;
}

static
  PmfMessageId dae_cg_output_method(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeDaeMethodOutput *daeMethodOutput,
  NeuDiagnosticManager *neDiagMgr)
{
  PmfMessageId errorId = NULL;
  (void) dae;
  (void) systemInput;
  (void) daeMethodOutput;
  (void) neDiagMgr;
  return errorId;
}

static
  PmfMessageId dae_cg_project_solve(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeuDiagnosticManager *neDiagMgr)
{
  NeDaePrivateData *smData = dae->mPrivateData;
  return
    sm_core_projectState(
    false,
    &smData->mSimulationDelegate,
    systemInput->mU.mX,
    systemInput->mU.mX + 1,
    systemInput->mD.mX,
    systemInput->mX.mX, neDiagMgr);
}

static
  PmfMessageId dae_cg_check_solve(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeuDiagnosticManager *neDiagMgr)
{
  NeDaePrivateData *smData = dae->mPrivateData;
  PmfMessageId errorId = NULL;
  if (smData->mNumConstraintEqns > 0)
    errorId = sm_core_projectState(
      false,
      &smData->mSimulationDelegate,
      systemInput->mU.mX,
      systemInput->mU.mX + 1,
      systemInput->mD.mX,
      systemInput->mX.mX, neDiagMgr);
  if (errorId == NULL && smData->mDoCheckDynamics) {
    double result = 0.0;
    errorId = sPort_de6c5c35_1_checkDynamics(
      systemInput->mX.mX,
      systemInput->mU.mX,
      systemInput->mU.mX + 1,
      systemInput->mV.mX + 1,
      systemInput->mD.mX,
      &result, neDiagMgr);
  }

  return errorId;
}

static
  PmfMessageId dae_cg_projectMaybe_solve(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeuDiagnosticManager *neDiagMgr)
{
  NeDaePrivateData *smData = dae->mPrivateData;
  return
    sm_core_projectState(
    true,
    &smData->mSimulationDelegate,
    systemInput->mU.mX,
    systemInput->mU.mX + 1,
    systemInput->mD.mX,
    systemInput->mX.mX, neDiagMgr);
}

static
  PmfMessageId dae_cg_assemble_solve(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeuDiagnosticManager *neDiagMgr)
{
  NeDaePrivateData *smData = dae->mPrivateData;
  PmfMessageId errorId = NULL;
  if (smData->mNumInputMotionPrimitives == 0) {
    neu_rv_equals_rv(&systemInput->mX, &dae->mPrivateData->mInitialStateVector);
    neu_rv_equals_rv(&systemInput->mD, &dae->mPrivateData->mDiscreteStateVector);
  } else {
    size_t i;
    const size_t numTargets = 6;
    unsigned int asmStatus = 0;
    double *assemblyFullStateVector = smData->mAssemblyFullStateVector.mX;
    double *simulationFullStateVector = smData->mSimulationFullStateVector.mX;
    const double *u = systemInput->mU.mX;
    const double *uDot = u + smData->mInputVectorSize;
    CTarget *target = smData->mTargets + smData->mNumInternalTargets;
    for (i = 0; i < smData->mNumInputMotionPrimitives; ++i) {
      const size_t inputOffset = smData->mMotionInputOffsets.mX[i];
      (target++)->mValue[0] = u [inputOffset];
      (target++)->mValue[0] = uDot[inputOffset];
    }

    errorId = sm_core_computeStateVector(
      &smData->mMechanismDelegate, numTargets, smData->mTargets,
      assemblyFullStateVector, neDiagMgr);
    if (errorId != NULL)
      return errorId;
    asmStatus = sm_core_checkAssembly(
      &smData->mMechanismDelegate, numTargets, smData->mTargets,
      assemblyFullStateVector, NULL, NULL);
    if (asmStatus != 1) {
      return sm_ssci_recordRunTimeError(
        "sm:compiler:messages:simulationErrors:AssemblyFailure",
        asmStatus == 2 ?
        "Model not assembled due to a position violation. The failure occurred during the attempt to assemble all joints in the system and satisfy any motion inputs. If an Update Diagram operation completes successfully, the failure is likely caused by motion inputs. Consider adjusting the motion inputs to specify a different starting configuration. Also consider adjusting or adding joint targets to better guide the assembly."
        :
        "Model not assembled due to a velocity violation. The failure occurred during the attempt to assemble all joints in the system and satisfy any motion inputs. If an Update Diagram operation completes successfully, the failure is likely caused by motion inputs. Consider adjusting the motion inputs to specify a different starting configuration. Also consider adjusting or adding joint targets to better guide the assembly.",
        neDiagMgr);
    }

    errorId =
      (*smData->mMechanismDelegate.mConvertStateVector)(
      NULL, NULL, assemblyFullStateVector, simulationFullStateVector,
      neDiagMgr);
    for (i = 0; i < smData->mStateVectorSize; ++i)
      systemInput->mX.mX[i] = simulationFullStateVector
        [smData->mStateVectorMap.mX[i]];
    memcpy(systemInput->mD.mX,
           simulationFullStateVector +
           smData->mFullStateVectorSize - smData->mDiscreteStateSize,
           smData->mDiscreteStateSize * sizeof(double));
  }

  return errorId;
}

typedef struct {
  size_t first;
  size_t second;
} SizePair;

static void checkMemAllocStatus(int_T status)
{
  (void) status;
}

static
  NeCharVector cStringToCharVector(const char *src)
{
  const size_t n = strlen(src);
  NeCharVector charVect;
  const int_T status =
    neu_create_char_vector_fields(&charVect, n + 1, ne_default_allocator());
  checkMemAllocStatus(status);
  strcpy(charVect.mX, src);
  return charVect;
}

static
  void initBasicAttributes(NeDaePrivateData *smData)
{
  size_t i;
  smData->mStateVectorSize = 2;
  smData->mFullStateVectorSize = 4;
  smData->mDiscreteStateSize = 0;
  smData->mInputVectorSize = 1;
  smData->mOutputVectorSize = 0;
  smData->mNumConstraintEqns = 0;
  smData->mDoCheckDynamics = false;
  for (i = 0; i < 4; ++i)
    smData->mChecksum[i] = 0;
}

static
  void initStateVector(NeDaePrivateData *smData)
{
  NeAllocator *alloc = ne_default_allocator();
  const double initialStateVector[2] = {
    +7.853981633974482800e-01, +0.000000000000000000e+00
  };

  const double *discreteStateVector = NULL;
  const int32_T stateVectorMap[2] = {
    2, 3
  };

  const CTarget targets[6] = {
    { 0, 26, 0, false, 0, 2, "deg", false, true, +1.000000000000000000e+00, true,
      1, { +7.853981633974482800e-01, +0.000000000000000000e+00,
        +0.000000000000000000e+00, +0.000000000000000000e+00 }, { +
        0.000000000000000000e+00 } },

    { 0, 26, 0, false, 0, 0, "1", true, true, +1.000000000000000000e+00, true, 1,
      { +0.000000000000000000e+00, +0.000000000000000000e+00,
        +0.000000000000000000e+00, +0.000000000000000000e+00 }, { +
        0.000000000000000000e+00 } },

    { 0, 39, 0, false, 0, 2, "deg", false, true, +1.000000000000000000e+00, true,
      1, { +1.047197551196597600e+00, +0.000000000000000000e+00,
        +0.000000000000000000e+00, +0.000000000000000000e+00 }, { +
        0.000000000000000000e+00 } },

    { 0, 39, 0, false, 0, 0, "1", true, true, +1.000000000000000000e+00, true, 1,
      { +0.000000000000000000e+00, +0.000000000000000000e+00,
        +0.000000000000000000e+00, +0.000000000000000000e+00 }, { +
        0.000000000000000000e+00 } },

    { 0, 39, 0, false, 0, 3, "", false, false, +1.000000000000000000e+00, true,
      1, { +0.000000000000000000e+00, +0.000000000000000000e+00,
        +0.000000000000000000e+00, +0.000000000000000000e+00 }, { +
        0.000000000000000000e+00 } },

    { 0, 39, 0, false, 0, 3, "", true, false, +1.000000000000000000e+00, true, 1,
      { +0.000000000000000000e+00, +0.000000000000000000e+00,
        +0.000000000000000000e+00, +0.000000000000000000e+00 }, { +
        0.000000000000000000e+00 } }
  };

  const size_t numTargets = 6;
  int_T status;
  size_t i;
  status = neu_create_real_vector_fields(
    &smData->mAssemblyFullStateVector, 4, alloc);
  checkMemAllocStatus(status);
  status = neu_create_real_vector_fields(
    &smData->mSimulationFullStateVector, 4, alloc);
  checkMemAllocStatus(status);
  status = neu_create_real_vector_fields(
    &smData->mInitialStateVector, 2, alloc);
  checkMemAllocStatus(status);
  memcpy(smData->mInitialStateVector.mX, initialStateVector,
         2 * sizeof(real_T));
  status = neu_create_real_vector_fields(
    &smData->mDiscreteStateVector, 0, alloc);
  checkMemAllocStatus(status);
  memcpy(smData->mDiscreteStateVector.mX, discreteStateVector,
         0 * sizeof(real_T));
  status = neu_create_int_vector_fields(
    &smData->mStateVectorMap, smData->mStateVectorSize, alloc);
  checkMemAllocStatus(status);
  memcpy(smData->mStateVectorMap.mX, stateVectorMap,
         smData->mStateVectorSize * sizeof(int32_T));
  smData->mNumInternalTargets = 4;
  smData->mNumInputMotionPrimitives = 1;
  NE_ALLOCATE_ARRAY(smData->mTargets, CTarget, numTargets, alloc);
  for (i = 0; i < numTargets; ++i)
    sm_compiler_CTarget_copy(targets + i, smData->mTargets + i);
}

static
  void initVariables(NeDaePrivateData *smData)
{
  const char *varFullPaths[2] = {
    "Lower_Revolute.Rz.q",
    "Lower_Revolute.Rz.w"
  };

  const char *varObjects[2] = {
    "sPort/Lower Revolute",
    "sPort/Lower Revolute"
  };

  smData->mNumVarScalars = 2;
  smData->mVarFullPaths = NULL;
  smData->mVarObjects = NULL;
  if (smData->mNumVarScalars > 0) {
    size_t s;
    NeAllocator *alloc = ne_default_allocator();
    NE_ALLOCATE_ARRAY(smData->mVarFullPaths, NeCharVector, 2, alloc);
    NE_ALLOCATE_ARRAY(smData->mVarObjects, NeCharVector, 2, alloc);
    for (s = 0; s < smData->mNumVarScalars; ++s) {
      smData->mVarFullPaths[s] = cStringToCharVector(varFullPaths[s]);
      smData->mVarObjects[s] = cStringToCharVector(varObjects[s]);
    }
  }
}

static
  void initIoInfoHelper(
  size_t n,
  const char *portPathsSource[],
  const char *unitsSource[],
  const SizePair dimensions[],
  boolean_T doInputs,
  NeDaePrivateData *smData)
{
  NeCharVector *portPaths = NULL;
  NeCharVector *units = NULL;
  NeDsIoInfo *infos = NULL;
  if (n > 0) {
    size_t s;
    NeAllocator *alloc = ne_default_allocator();
    NE_ALLOCATE_ARRAY(portPaths, NeCharVector, n, alloc);
    NE_ALLOCATE_ARRAY(units, NeCharVector, n, alloc);
    NE_ALLOCATE_ARRAY(infos, NeDsIoInfo, n, alloc);
    for (s = 0; s < n; ++s) {
      portPaths[s] = cStringToCharVector(portPathsSource[s]);
      units[s] = cStringToCharVector(unitsSource[s]);

      {
        NeDsIoInfo *info = infos + s;
        info->mName = info->mIdentifier = portPaths[s].mX;
        info->mM = dimensions[s].first;
        info->mN = dimensions[s].second;
        info->mUnit = units[s].mX;
      }
    }
  }

  if (doInputs) {
    smData->mNumInputs = n;
    smData->mInputPortPaths = portPaths;
    smData->mInputUnits = units;
    smData->mInputInfos = infos;
  } else {
    smData->mNumOutputs = n;
    smData->mOutputPortPaths = portPaths;
    smData->mOutputUnits = units;
    smData->mOutputInfos = infos;
  }
}

static
  void initIoInfo(NeDaePrivateData *smData)
{
  const char *inputPortPaths[1] = {
    "Upper_Revolute.qi"
  };

  const char *inputUnits[1] = {
    "rad"
  };

  const SizePair inputDimensions[1] = {
    { 1, 1 }
  };

  const char **outputPortPaths = NULL;
  const char **outputUnits = NULL;
  const SizePair *outputDimensions = NULL;
  initIoInfoHelper(1, inputPortPaths, inputUnits, inputDimensions,
                   true, smData);
  initIoInfoHelper(0, outputPortPaths, outputUnits, outputDimensions,
                   false, smData);
}

static
  void initInputDerivs(NeDaePrivateData *smData)
{
  const int32_T numInputDerivs[1] = {
    2
  };

  NeAllocator *alloc = ne_default_allocator();
  const int_T status = neu_create_int_vector_fields(
    &smData->mNumInputDerivs, smData->mInputVectorSize, alloc);
  checkMemAllocStatus(status);
  memcpy(smData->mNumInputDerivs.mX, numInputDerivs,
         1 * sizeof(int32_T));
  smData->mInputOrder = 2;
}

static
  void initDirectFeedthrough(NeDaePrivateData *smData)
{
  const boolean_T directFeedthroughVector[1] = {
    true
  };

  const boolean_T *directFeedthroughMatrix = NULL;
  NeAllocator *alloc = ne_default_allocator();

  {
    const int_T status = neu_create_bool_vector_fields(
      &smData->mDirectFeedthroughVector, 1, alloc);
    checkMemAllocStatus(status);
    memcpy(smData->mDirectFeedthroughVector.mX, directFeedthroughVector,
           1 * sizeof(boolean_T));
  }

  {
    const int_T status = neu_create_bool_vector_fields(
      &smData->mDirectFeedthroughMatrix, 0, alloc);
    checkMemAllocStatus(status);
    memcpy(smData->mDirectFeedthroughMatrix.mX, directFeedthroughMatrix,
           0 * sizeof(boolean_T));
  }
}

static
  void initOutputDerivProc(NeDaePrivateData *smData)
{
  NeAllocator *alloc = ne_default_allocator();
  const int32_T *outputFunctionMap = NULL;
  smData->mOutputFunctionMap = neu_create_int_vector(0, alloc);
  memcpy(smData->mOutputFunctionMap->mX, outputFunctionMap,
         0 * sizeof(int32_T));
  smData->mNumOutputClasses = 0;
  smData->mHasKinematicOutputs = false;
  smData->mHasDynamicOutputs = false;
  smData->mIsOutputClass0Dynamic = false;
  smData->mDoComputeDynamicOutputs = false;
  smData->mCachedDerivativesAvailable = false;

  {
    size_t i = 0;
    const int_T status = neu_create_real_vector_fields(
      &smData->mCachedDerivatives, 0, ne_default_allocator());
    checkMemAllocStatus(status);
    for (i = 0; i < smData->mCachedDerivatives.mN; ++i)
      smData->mCachedDerivatives.mX[i] = 0.0;
  }
}

#if 0

static void initializeSizePairVector(const SmSizePair *data,
  SmSizePairVector *vector)
{
  const size_t n = sm_core_SmSizePairVector_size(vector);
  size_t i;
  for (i = 0; i < n; ++i, ++data)
    sm_core_SmSizePairVector_setValue(vector, i, data++);
}

#endif

static
  void initMechanismDelegate(SmMechanismDelegate *delegate)
{
  NeAllocator *alloc = ne_default_allocator();
  const SmSizePair jointToStageIdx[2] = {
    { 26, 1 }, { 39, 0 }
  };

  const size_t primitiveIndices[2 + 1] = {
    0, 1, 2
  };

  const SmSizePair stateOffsets[2] = {
    { 0, 1 }, { 2, 3 }
  };

  const SmSizePair dofOffsets[2] = {
    { 0, 1 }, { 1, 2 }
  };

  const size_t remodIndices[2] = {
    0, 2
  };

  const size_t *equationsPerConstraint = NULL;
  const size_t dofToVelSlot[2] = {
    1, 3
  };

  const size_t *constraintDofs = NULL;
  const size_t constraintDofOffsets[0 + 1] = {
    0
  };

  const size_t Jm = 0;
  const size_t Jn = 2;
  SmSizePair zeroSizePair;
  zeroSizePair.mFirst = zeroSizePair.mSecond = 0;
  delegate->mTargetStrengthFree = 0;
  delegate->mTargetStrengthSuggested = 1;
  delegate->mTargetStrengthDesired = 2;
  delegate->mTargetStrengthRequired = 3;
  delegate->mConsistencyTol = +1.000000000000000100e-09;
  delegate->mDof = 2;
  delegate->mStateSize = 4;
  delegate->mNumStages = 2;
  delegate->mNumConstraints = 0;
  delegate->mNumAllConstraintEquations = 0;
  sm_core_SmSizePairVector_create(
    &delegate->mJointToStageIdx, delegate->mNumStages, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&delegate->mJointToStageIdx),
         jointToStageIdx, delegate->mNumStages * sizeof(SmSizePair));
  sm_core_SmSizeTVector_create(
    &delegate->mPrimitiveIndices, delegate->mNumStages + 1, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mPrimitiveIndices),
         primitiveIndices, (delegate->mNumStages + 1) * sizeof(size_t));
  sm_core_SmSizePairVector_create(
    &delegate->mStateOffsets, 2, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&delegate->mStateOffsets),
         stateOffsets, 2 * sizeof(SmSizePair));
  sm_core_SmSizePairVector_create(
    &delegate->mDofOffsets, 2, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&delegate->mDofOffsets),
         dofOffsets, 2 * sizeof(SmSizePair));
  sm_core_SmSizeTVector_create(
    &delegate->mRemodIndices, 2, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mRemodIndices),
         remodIndices, 2 * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &delegate->mEquationsPerConstraint, delegate->mNumConstraints, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mEquationsPerConstraint),
         equationsPerConstraint, delegate->mNumConstraints * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &delegate->mDofToVelSlot, delegate->mDof, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mDofToVelSlot),
         dofToVelSlot, delegate->mDof * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &delegate->mConstraintDofs, 0, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mConstraintDofs),
         constraintDofs, 0 * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &delegate->mConstraintDofOffsets, delegate->mNumConstraints + 1, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&delegate->mConstraintDofOffsets),
         constraintDofOffsets, (delegate->mNumConstraints + 1) * sizeof(size_t));
  sm_core_SmBoundedSet_create(&delegate->mPosRequired, 2);
  sm_core_SmBoundedSet_create(&delegate->mPosDesired, 2);
  sm_core_SmBoundedSet_create(&delegate->mPosSuggested, 2);
  sm_core_SmBoundedSet_create(&delegate->mPosFree, 2);
  sm_core_SmBoundedSet_create(&delegate->mPosNonRequired, 2);
  sm_core_SmBoundedSet_create(&delegate->mPosSuggAndFree, 2);
  sm_core_SmBoundedSet_create(&delegate->mVelRequired, 2);
  sm_core_SmBoundedSet_create(&delegate->mVelDesired, 2);
  sm_core_SmBoundedSet_create(&delegate->mVelSuggested, 2);
  sm_core_SmBoundedSet_create(&delegate->mVelFree, 2);
  sm_core_SmBoundedSet_create(&delegate->mVelNonRequired, 2);
  sm_core_SmBoundedSet_create(&delegate->mVelSuggAndFree, 2);
  sm_core_SmBoundedSet_create(&delegate->mConstraintFilter, 0);
  sm_core_SmBoundedSet_create(&delegate->mActiveConstraints, 0);
  sm_core_SmBoundedSet_create(&delegate->mActiveDofs, 2);
  sm_core_SmBoundedSet_create(&delegate->mActiveDofs0, 2);
  sm_core_SmBoundedSet_create(&delegate->mNewConstraints, 0);
  sm_core_SmBoundedSet_create(&delegate->mNewDofs, 2);
  sm_core_SmBoundedSet_create(&delegate->mUnsatisfiedConstraints, 0);
  sm_core_SmSizeTVector_create(&delegate->mActiveConstraintsVect,
    0, 0);
  sm_core_SmSizeTVector_create(&delegate->mActiveDofsVect, 2, 0);
  sm_core_SmSizeTVector_create(&delegate->mFullDofToActiveDof, 2, 0);
  sm_core_SmSizePairVector_create(
    &delegate->mPartiallyPosTargetedPrims, 2, &zeroSizePair);
  sm_core_SmSizePairVector_create(
    &delegate->mPartiallyVelTargetedPrims, 2, &zeroSizePair);
  sm_core_SmSizeTVector_create(&delegate->mPosPartialTypes, 2, 0);
  sm_core_SmSizeTVector_create(&delegate->mVelPartialTypes, 2, 0);
  sm_core_SmSizeTVector_create(&delegate->mPartiallyActivePrims, 2, 0);
  sm_core_SmSizePairVector_create(
    &delegate->mBaseFrameVelOffsets, 0, &zeroSizePair);
  sm_core_SmSizePairVector_create(
    &delegate->mCvVelOffsets, 2, &zeroSizePair);
  sm_core_SmRealVector_create(&delegate->mInitialState, 4, 0.0);
  sm_core_SmRealVector_create(&delegate->mStartState, 4, 0.0);
  sm_core_SmRealVector_create(&delegate->mTestState, 4, 0.0);
  sm_core_SmRealVector_create(&delegate->mFullStateVector, 4, 0.0);
  sm_core_SmRealVector_create(&delegate->mJacobianRowMaj, Jm * Jn, 0.0);
  sm_core_SmRealVector_create(&delegate->mJacobian, Jm * Jn, 0.0);
  sm_core_SmRealVector_create(&delegate->mJacobianPrimSubmatrix, Jm * 6, 0.0);
  sm_core_SmRealVector_create(&delegate->mConstraintNonhomoTerms, Jm, 0.0);
  sm_core_SmRealVector_create(&delegate->mConstraintError, Jm, 0.0);
  sm_core_SmRealVector_create(&delegate->mBestConstraintError, Jm, 0.0);
  sm_core_SmRealVector_create(&delegate->mDeltas,
    Jn * (Jm <= Jn ? Jm : Jn), 0.0);
  sm_core_SmRealVector_create(&delegate->mSvdWork, 9, 0.0);
  sm_core_SmRealVector_create(
    &delegate->mLineSearchScaledDeltaVect, 2, 0.0);
  sm_core_SmRealVector_create(
    &delegate->mLineSearchTestStateVect, 4, 0.0);
  sm_core_SmRealVector_create(&delegate->mLineSearchErrorVect, Jm, 0.0);
  sm_core_SmRealVector_create(&delegate->mActiveDofVelsVect, 2, 0.0);
  sm_core_SmRealVector_create(&delegate->mVelSystemRhs, Jm, 0.0);
  sm_core_SmRealVector_create(&delegate->mMotionData, 26, 0.0);
  delegate->mResetStateVector = sPort_de6c5c35_1_resetStateVector;
  delegate->mInitializeTrackedAngleState =
    sPort_de6c5c35_1_initializeTrackedAngleState;
  delegate->mComputeDiscreteState = sPort_de6c5c35_1_computeDiscreteState;
  delegate->mAdjustPosition = sPort_de6c5c35_1_adjustPosition;
  delegate->mPerturbState = sPort_de6c5c35_1_perturbState;
  delegate->mComputeDofBlendMatrix = sPort_de6c5c35_1_computeDofBlendMatrix;
  delegate->mProjectPartiallyTargetedPos =
    sPort_de6c5c35_1_projectPartiallyTargetedPos;
  delegate->mPropagateMotion = sPort_de6c5c35_1_propagateMotion;
  delegate->mComputeAssemblyError = sPort_de6c5c35_1_computeAssemblyError;
  delegate->mComputeAssemblyJacobian = sPort_de6c5c35_1_computeAssemblyJacobian;
  delegate->mComputeFullAssemblyJacobian =
    sPort_de6c5c35_1_computeFullAssemblyJacobian;
  delegate->mConvertStateVector = sPort_de6c5c35_1_convertStateVector;
  delegate->mConstructStateVector = sPort_de6c5c35_1_constructStateVector;
  delegate->mExtractSolverStateVector =
    sPort_de6c5c35_1_extractSolverStateVector;
  delegate->mIsPositionViolation = sPort_de6c5c35_1_isPositionViolation;
  delegate->mIsVelocityViolation = sPort_de6c5c35_1_isVelocityViolation;
  delegate->mProjectStateSim = sPort_de6c5c35_1_projectStateSim;
  delegate->mMech = NULL;
}

static
  void initSimulationDelegate(SmMechanismDelegate *simDelegate)
{
  NeAllocator *alloc = ne_default_allocator();
  const SmSizePair jointToStageIdx[2] = {
    { 26, 1 }, { 39, 0 }
  };

  const size_t primitiveIndices[2 + 1] = {
    0, 1, 2
  };

  const SmSizePair stateOffsets[2] = {
    { 0, 1 }, { 2, 3 }
  };

  const SmSizePair dofOffsets[2] = {
    { 0, 1 }, { 1, 2 }
  };

  const size_t remodIndices[2] = {
    0, 2
  };

  const size_t *equationsPerConstraint = NULL;
  const size_t dofToVelSlot[2] = {
    1, 3
  };

  const size_t *constraintDofs = NULL;
  const size_t constraintDofOffsets[0 + 1] = {
    0
  };

  const size_t Jm = 0;
  const size_t Jn = 2;
  SmSizePair zeroSizePair;
  zeroSizePair.mFirst = zeroSizePair.mSecond = 0;
  simDelegate->mTargetStrengthFree = 0;
  simDelegate->mTargetStrengthSuggested = 1;
  simDelegate->mTargetStrengthDesired = 2;
  simDelegate->mTargetStrengthRequired = 3;
  simDelegate->mConsistencyTol = +1.000000000000000100e-09;
  simDelegate->mDof = 2;
  simDelegate->mStateSize = 4;
  simDelegate->mNumStages = 2;
  simDelegate->mNumConstraints = 0;
  simDelegate->mNumAllConstraintEquations = 0;
  sm_core_SmSizePairVector_create(
    &simDelegate->mJointToStageIdx, simDelegate->mNumStages, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&simDelegate->mJointToStageIdx),
         jointToStageIdx, simDelegate->mNumStages * sizeof(SmSizePair));
  sm_core_SmSizeTVector_create(
    &simDelegate->mPrimitiveIndices, simDelegate->mNumStages + 1, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&simDelegate->mPrimitiveIndices),
         primitiveIndices, (simDelegate->mNumStages + 1) * sizeof(size_t));
  sm_core_SmSizePairVector_create(
    &simDelegate->mStateOffsets, 2, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&simDelegate->mStateOffsets),
         stateOffsets, 2 * sizeof(SmSizePair));
  sm_core_SmSizePairVector_create(
    &simDelegate->mDofOffsets, 2, &zeroSizePair);
  memcpy(sm_core_SmSizePairVector_nonConstValues(&simDelegate->mDofOffsets),
         dofOffsets, 2 * sizeof(SmSizePair));
  sm_core_SmSizeTVector_create(
    &simDelegate->mRemodIndices, 2, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&simDelegate->mRemodIndices),
         remodIndices, 2 * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &simDelegate->mEquationsPerConstraint, simDelegate->mNumConstraints, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues
         (&simDelegate->mEquationsPerConstraint),
         equationsPerConstraint, simDelegate->mNumConstraints * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &simDelegate->mDofToVelSlot, simDelegate->mDof, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&simDelegate->mDofToVelSlot),
         dofToVelSlot, simDelegate->mDof * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &simDelegate->mConstraintDofs, 0, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues(&simDelegate->mConstraintDofs),
         constraintDofs, 0 * sizeof(size_t));
  sm_core_SmSizeTVector_create(
    &simDelegate->mConstraintDofOffsets, simDelegate->mNumConstraints + 1, 0);
  memcpy(sm_core_SmSizeTVector_nonConstValues
         (&simDelegate->mConstraintDofOffsets),
         constraintDofOffsets, (simDelegate->mNumConstraints + 1) * sizeof
         (size_t));
  sm_core_SmBoundedSet_create(&simDelegate->mPosRequired, 2);
  sm_core_SmBoundedSet_create(&simDelegate->mPosDesired, 2);
  sm_core_SmBoundedSet_create(&simDelegate->mPosSuggested, 2);
  sm_core_SmBoundedSet_create(&simDelegate->mPosFree, 2);
  sm_core_SmBoundedSet_create(&simDelegate->mPosNonRequired, 2);
  sm_core_SmBoundedSet_create(&simDelegate->mPosSuggAndFree, 2);
  sm_core_SmBoundedSet_create(&simDelegate->mVelRequired, 2);
  sm_core_SmBoundedSet_create(&simDelegate->mVelDesired, 2);
  sm_core_SmBoundedSet_create(&simDelegate->mVelSuggested, 2);
  sm_core_SmBoundedSet_create(&simDelegate->mVelFree, 2);
  sm_core_SmBoundedSet_create(&simDelegate->mVelNonRequired, 2);
  sm_core_SmBoundedSet_create(&simDelegate->mVelSuggAndFree, 2);
  sm_core_SmBoundedSet_create(&simDelegate->mConstraintFilter, 0);
  sm_core_SmBoundedSet_create(&simDelegate->mActiveConstraints, 0);
  sm_core_SmBoundedSet_create(&simDelegate->mActiveDofs, 2);
  sm_core_SmBoundedSet_create(&simDelegate->mNewConstraints, 0);
  sm_core_SmBoundedSet_create(&simDelegate->mNewDofs, 2);
  sm_core_SmBoundedSet_create(&simDelegate->mUnsatisfiedConstraints, 0);
  sm_core_SmSizeTVector_create(&simDelegate->mActiveConstraintsVect,
    0, 0);
  sm_core_SmSizeTVector_create(&simDelegate->mActiveDofsVect, 2, 0);
  sm_core_SmSizePairVector_create(
    &simDelegate->mBaseFrameVelOffsets, 0, &zeroSizePair);
  sm_core_SmRealVector_create(&simDelegate->mInitialState, 4, 0.0);
  sm_core_SmRealVector_create(&simDelegate->mStartState, 4, 0.0);
  sm_core_SmRealVector_create(&simDelegate->mTestState, 4, 0.0);
  sm_core_SmRealVector_create(&simDelegate->mFullStateVector, 4, 0.0);
  sm_core_SmRealVector_create(&simDelegate->mJacobianRowMaj, Jm * Jn, 0.0);
  sm_core_SmRealVector_create(&simDelegate->mJacobian, Jm * Jn, 0.0);
  sm_core_SmRealVector_create(&simDelegate->mConstraintNonhomoTerms, Jm, 0.0);
  sm_core_SmRealVector_create(&simDelegate->mConstraintError, Jm, 0.0);
  sm_core_SmRealVector_create(&simDelegate->mBestConstraintError, Jm, 0.0);
  sm_core_SmRealVector_create(&simDelegate->mDeltas,
    Jn * (Jm <= Jn ? Jm : Jn), 0.0);
  sm_core_SmRealVector_create(&simDelegate->mSvdWork, 9, 0.0);
  sm_core_SmRealVector_create(
    &simDelegate->mLineSearchScaledDeltaVect, 2, 0.0);
  sm_core_SmRealVector_create(
    &simDelegate->mLineSearchTestStateVect, 4, 0.0);
  sm_core_SmRealVector_create(&simDelegate->mLineSearchErrorVect, Jm, 0.0);
  sm_core_SmRealVector_create(&simDelegate->mActiveDofVelsVect, 2, 0.0);
  sm_core_SmRealVector_create(&simDelegate->mVelSystemRhs, Jm, 0.0);
  sm_core_SmRealVector_create(&simDelegate->mMotionData, 26, 0.0);
  simDelegate->mResetStateVector = sPort_de6c5c35_1_resetStateVector;
  simDelegate->mInitializeTrackedAngleState =
    sPort_de6c5c35_1_initializeTrackedAngleState;
  simDelegate->mComputeDiscreteState = sPort_de6c5c35_1_computeDiscreteState;
  simDelegate->mAdjustPosition = sPort_de6c5c35_1_adjustPosition;
  simDelegate->mPerturbState = sPort_de6c5c35_1_perturbState;
  simDelegate->mPropagateMotion = sPort_de6c5c35_1_propagateMotion;
  simDelegate->mComputeAssemblyError = sPort_de6c5c35_1_computeAssemblyError;
  simDelegate->mComputeAssemblyJacobian =
    sPort_de6c5c35_1_computeAssemblyJacobian;
  simDelegate->mComputeFullAssemblyJacobian =
    sPort_de6c5c35_1_computeFullAssemblyJacobian;
  simDelegate->mConvertStateVector = sPort_de6c5c35_1_convertStateVector;
  simDelegate->mConstructStateVector = sPort_de6c5c35_1_constructStateVector;
  simDelegate->mExtractSolverStateVector =
    sPort_de6c5c35_1_extractSolverStateVector;
  simDelegate->mIsPositionViolation = sPort_de6c5c35_1_isPositionViolation;
  simDelegate->mIsVelocityViolation = sPort_de6c5c35_1_isVelocityViolation;
  simDelegate->mProjectStateSim = sPort_de6c5c35_1_projectStateSim;
  simDelegate->mMech = NULL;
}

static
  void initAssemblyStructures(NeDaePrivateData *smData)
{
  NeAllocator *alloc = ne_default_allocator();
  const int32_T motionInputOffsets[1] = {
    0
  };

  int_T status = 0;
  initMechanismDelegate(&smData->mMechanismDelegate);
  initSimulationDelegate(&smData->mSimulationDelegate);
  status = neu_create_int_vector_fields(
    &smData->mMotionInputOffsets, smData->mNumInputMotionPrimitives, alloc);
  checkMemAllocStatus(status);
  memcpy(smData->mMotionInputOffsets.mX, motionInputOffsets,
         1 * sizeof(int32_T));
}

static
  void initComputationFcnPtrs(NeDaePrivateData *smData)
{
  smData->mDerivativeFcn = dae_cg_deriv_method;
  smData->mOutputFcn = dae_cg_output_method;
  smData->mProjectionFcn = dae_cg_project_solve;
  smData->mProjectionMaybeFcn = dae_cg_projectMaybe_solve;
  smData->mCheckFcn =
    (smData->mStateVectorSize == 0) ? dae_cg_check_solve : NULL;
  smData->mAssemblyFcn = dae_cg_assemble_solve;
  smData->mSetupLoggerFcn = sm_ssci_setupLoggerFcn_codeGen;
  smData->mLogFcn = sm_ssci_logFcn_codeGen;
  smData->mResidualsFcn = NULL;
  smData->mLinearizeFcn = NULL;
  smData->mGenerateFcn = NULL;
}

static
  void initLiveLinkToSm(NeDaePrivateData *smData)
{
  smData->mLiveSmLink = NULL;
  smData->mLiveSmLink_destroy = NULL;
  smData->mLiveSmLink_copy = NULL;
}

void sPort_de6c5c35_1_NeDaePrivateData_create(NeDaePrivateData *smData)
{
  initBasicAttributes (smData);
  initStateVector (smData);
  initVariables (smData);
  initIoInfo (smData);
  initInputDerivs (smData);
  initDirectFeedthrough (smData);
  initOutputDerivProc (smData);
  initAssemblyStructures (smData);
  initComputationFcnPtrs (smData);
  initLiveLinkToSm (smData);
}
