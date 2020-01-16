#include "__cf_sPort.h"
#include <math.h>
#include "sPort_acc.h"
#include "sPort_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { boolean_T first_output
; real_T tmp ; lu3rglnqbv * _rtB ; pws2qii1oy * _rtP ; blzi53foke * _rtX ;
fojpvphg1l * _rtDW ; _rtDW = ( ( fojpvphg1l * ) ssGetRootDWork ( S ) ) ; _rtX
= ( ( blzi53foke * ) ssGetContStates ( S ) ) ; _rtP = ( ( pws2qii1oy * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( lu3rglnqbv * ) _ssGetBlockIO ( S ) ) ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 0 , 1 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 2 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 0 , 3 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
foj2cgbz4e = ( real_T ) _rtP -> P_1 * 0.0078125 * ( real_T ) _rtB ->
ch1ea0vodx ; ssCallAccelRunBlock ( S , 0 , 6 , SS_CALL_MDL_OUTPUTS ) ; }
first_output = false ; if ( _rtDW -> cwcafxbak0 == 0.0 ) { _rtDW ->
cwcafxbak0 = 1.0 ; first_output = true ; } if ( first_output ) { _rtX ->
jax1pk4qzt [ 0 ] = _rtB -> jyzbnzsgkt ; _rtX -> jax1pk4qzt [ 1 ] = 0.0 ; }
_rtB -> bec5zfg3js [ 0 ] = _rtX -> jax1pk4qzt [ 0 ] ; _rtB -> bec5zfg3js [ 1
] = _rtX -> jax1pk4qzt [ 1 ] ; _rtB -> bec5zfg3js [ 2 ] = ( ( _rtB ->
jyzbnzsgkt - _rtX -> jax1pk4qzt [ 0 ] ) * 20.0 - 2.0 * _rtX -> jax1pk4qzt [ 1
] ) * 20.0 ; _rtB -> bec5zfg3js [ 3 ] = 0.0 ; ssCallAccelRunBlock ( S , 0 , 8
, SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 9 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 0 , 10 , SS_CALL_MDL_OUTPUTS ) ; tmp =
muDoubleScalarFloor ( _rtP -> P_0 * _rtB -> foj2cgbz4e ) ; if (
muDoubleScalarIsNaN ( tmp ) || muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; }
else { tmp = muDoubleScalarRem ( tmp , 256.0 ) ; } _rtB -> dmbjrto5ag = (
uint8_T ) ( tmp < 0.0 ? ( int32_T ) ( uint8_T ) - ( int8_T ) ( uint8_T ) -
tmp : ( int32_T ) ( uint8_T ) tmp ) ; ssCallAccelRunBlock ( S , 0 , 12 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 0 , 25 ,
SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { lu3rglnqbv * _rtB ;
fojpvphg1l * _rtDW ; _rtDW = ( ( fojpvphg1l * ) ssGetRootDWork ( S ) ) ; _rtB
= ( ( lu3rglnqbv * ) _ssGetBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 1 , 0 )
) { } UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { lu3rglnqbv * _rtB ; blzi53foke
* _rtX ; cft2yfjcjf * _rtXdot ; fojpvphg1l * _rtDW ; _rtDW = ( ( fojpvphg1l *
) ssGetRootDWork ( S ) ) ; _rtXdot = ( ( cft2yfjcjf * ) ssGetdX ( S ) ) ;
_rtX = ( ( blzi53foke * ) ssGetContStates ( S ) ) ; _rtB = ( ( lu3rglnqbv * )
_ssGetBlockIO ( S ) ) ; _rtXdot -> jax1pk4qzt [ 0 ] = _rtX -> jax1pk4qzt [ 1
] ; _rtXdot -> jax1pk4qzt [ 1 ] = ( ( _rtB -> jyzbnzsgkt - _rtX -> jax1pk4qzt
[ 0 ] ) * 20.0 - 2.0 * _rtX -> jax1pk4qzt [ 1 ] ) * 20.0 ;
ssCallAccelRunBlock ( S , 0 , 8 , SS_CALL_MDL_DERIVATIVES ) ; }
#define MDL_PROJECTION
static void mdlProjection ( SimStruct * S ) { ssCallAccelRunBlock ( S , 0 , 8
, SS_CALL_MDL_PROJECTION ) ; } static void mdlInitializeSizes ( SimStruct * S
) { ssSetChecksumVal ( S , 0 , 1521813206U ) ; ssSetChecksumVal ( S , 1 ,
4267516095U ) ; ssSetChecksumVal ( S , 2 , 4038094351U ) ; ssSetChecksumVal (
S , 3 , 3079528057U ) ; { mxArray * slVerStructMat = NULL ; mxArray *
slStrMat = mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status
= mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if (
status == 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 ,
"Version" ) ; if ( slVerMat == NULL ) { status = 1 ; } else { status =
mxGetString ( slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.5" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
fojpvphg1l ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( lu3rglnqbv ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
pws2qii1oy ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & dzcxpunfrf ) ; } static void mdlInitializeSampleTimes (
SimStruct * S ) { } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
