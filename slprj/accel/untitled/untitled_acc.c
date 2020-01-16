#include "__cf_untitled.h"
#include <math.h>
#include "untitled_acc.h"
#include "untitled_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { boolean_T first_output
; fsg2leehhc * _rtB ; g0szqdi43g * _rtP ; duq1u2s0wi * _rtX ; kywlqvr0yp *
_rtDW ; _rtDW = ( ( kywlqvr0yp * ) ssGetRootDWork ( S ) ) ; _rtX = ( (
duq1u2s0wi * ) ssGetContStates ( S ) ) ; _rtP = ( ( g0szqdi43g * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( fsg2leehhc * ) _ssGetBlockIO ( S ) ) ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 0 , 1 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 2 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 0 , 3 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
esou3sfy23 = ( real_T ) _rtP -> P_0 * 0.0078125 * ( real_T ) _rtB ->
jvqtoge3ey ; ssCallAccelRunBlock ( S , 0 , 6 , SS_CALL_MDL_OUTPUTS ) ; }
first_output = false ; if ( _rtDW -> l3owbsx2xu == 0.0 ) { _rtDW ->
l3owbsx2xu = 1.0 ; first_output = true ; } if ( first_output ) { _rtX ->
onipi2mvgf [ 0 ] = _rtB -> iutc3apfnv ; _rtX -> onipi2mvgf [ 1 ] = 0.0 ; }
_rtB -> ju330rqj2c [ 0 ] = _rtX -> onipi2mvgf [ 0 ] ; _rtB -> ju330rqj2c [ 1
] = _rtX -> onipi2mvgf [ 1 ] ; _rtB -> ju330rqj2c [ 2 ] = ( ( _rtB ->
iutc3apfnv - _rtX -> onipi2mvgf [ 0 ] ) * 20.0 - 2.0 * _rtX -> onipi2mvgf [ 1
] ) * 20.0 ; _rtB -> ju330rqj2c [ 3 ] = 0.0 ; ssCallAccelRunBlock ( S , 0 ,
19 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 20 ,
SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { fsg2leehhc * _rtB ;
kywlqvr0yp * _rtDW ; _rtDW = ( ( kywlqvr0yp * ) ssGetRootDWork ( S ) ) ; _rtB
= ( ( fsg2leehhc * ) _ssGetBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 1 , 0 )
) { } UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { fsg2leehhc * _rtB ; duq1u2s0wi
* _rtX ; d1e4i05lcy * _rtXdot ; kywlqvr0yp * _rtDW ; _rtDW = ( ( kywlqvr0yp *
) ssGetRootDWork ( S ) ) ; _rtXdot = ( ( d1e4i05lcy * ) ssGetdX ( S ) ) ;
_rtX = ( ( duq1u2s0wi * ) ssGetContStates ( S ) ) ; _rtB = ( ( fsg2leehhc * )
_ssGetBlockIO ( S ) ) ; _rtXdot -> onipi2mvgf [ 0 ] = _rtX -> onipi2mvgf [ 1
] ; _rtXdot -> onipi2mvgf [ 1 ] = ( ( _rtB -> iutc3apfnv - _rtX -> onipi2mvgf
[ 0 ] ) * 20.0 - 2.0 * _rtX -> onipi2mvgf [ 1 ] ) * 20.0 ;
ssCallAccelRunBlock ( S , 0 , 19 , SS_CALL_MDL_DERIVATIVES ) ; }
#define MDL_PROJECTION
static void mdlProjection ( SimStruct * S ) { ssCallAccelRunBlock ( S , 0 ,
19 , SS_CALL_MDL_PROJECTION ) ; } static void mdlInitializeSizes ( SimStruct
* S ) { ssSetChecksumVal ( S , 0 , 3009922622U ) ; ssSetChecksumVal ( S , 1 ,
3942275476U ) ; ssSetChecksumVal ( S , 2 , 3598563113U ) ; ssSetChecksumVal (
S , 3 , 3129879848U ) ; { mxArray * slVerStructMat = NULL ; mxArray *
slStrMat = mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status
= mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if (
status == 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 ,
"Version" ) ; if ( slVerMat == NULL ) { status = 1 ; } else { status =
mxGetString ( slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.5" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
kywlqvr0yp ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( fsg2leehhc ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
g0szqdi43g ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & lxkrdcync0 ) ; } static void mdlInitializeSampleTimes (
SimStruct * S ) { } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
