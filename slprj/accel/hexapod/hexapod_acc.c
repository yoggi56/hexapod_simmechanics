#include "__cf_hexapod.h"
#include <math.h>
#include "hexapod_acc.h"
#include "hexapod_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
real_T look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table
[ ] , uint32_T maxIndex ) { real_T frac ; uint32_T iRght ; uint32_T iLeft ;
uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [
0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) {
bpIdx = maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while ( iRght -
iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft =
bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) /
( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex - 1U ;
frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex -
1U ] ) ; } return ( table [ iLeft + 1U ] - table [ iLeft ] ) * frac + table [
iLeft ] ; } real_T look1_binlcpw ( real_T u0 , const real_T bp0 [ ] , const
real_T table [ ] , uint32_T maxIndex ) { real_T frac ; uint32_T iRght ;
uint32_T iLeft ; uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac
= 0.0 ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx = maxIndex >> 1U ; iLeft
= 0U ; iRght = maxIndex ; while ( iRght - iLeft > 1U ) { if ( u0 < bp0 [
bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx = ( iRght +
iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0
[ iLeft ] ) ; } else { iLeft = maxIndex - 1U ; frac = 1.0 ; } return ( table
[ iLeft + 1U ] - table [ iLeft ] ) * frac + table [ iLeft ] ; } void
rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( const real_T u0 [ 9 ] , const real_T u1 [
3 ] , real_T y [ 3 ] ) { real_T A [ 9 ] ; int32_T r1 ; int32_T r2 ; int32_T
r3 ; real_T maxval ; real_T a21 ; int32_T rtemp ; memcpy ( & A [ 0 ] , & u0 [
0 ] , 9U * sizeof ( real_T ) ) ; r1 = 1 ; r2 = 2 ; r3 = 3 ; maxval =
muDoubleScalarAbs ( u0 [ 0 ] ) ; a21 = muDoubleScalarAbs ( u0 [ 1 ] ) ; if (
a21 > maxval ) { maxval = a21 ; r1 = 2 ; r2 = 1 ; } if ( muDoubleScalarAbs (
u0 [ 2 ] ) > maxval ) { r1 = 3 ; r2 = 2 ; r3 = 1 ; } A [ r2 - 1 ] = u0 [ r2 -
1 ] / u0 [ r1 - 1 ] ; A [ r3 - 1 ] /= A [ r1 - 1 ] ; A [ r2 + 2 ] -= A [ r2 -
1 ] * A [ r1 + 2 ] ; A [ r3 + 2 ] -= A [ r3 - 1 ] * A [ r1 + 2 ] ; A [ r2 + 5
] -= A [ r2 - 1 ] * A [ r1 + 5 ] ; A [ r3 + 5 ] -= A [ r3 - 1 ] * A [ r1 + 5
] ; if ( muDoubleScalarAbs ( A [ r3 + 2 ] ) > muDoubleScalarAbs ( A [ r2 + 2
] ) ) { rtemp = r2 ; r2 = r3 ; r3 = rtemp ; } A [ r3 + 2 ] /= A [ r2 + 2 ] ;
A [ r3 + 5 ] -= A [ r3 + 2 ] * A [ r2 + 5 ] ; maxval = u1 [ r2 - 1 ] - u1 [
r1 - 1 ] * A [ r2 - 1 ] ; a21 = ( ( u1 [ r3 - 1 ] - u1 [ r1 - 1 ] * A [ r3 -
1 ] ) - A [ r3 + 2 ] * maxval ) / A [ r3 + 5 ] ; maxval -= A [ r2 + 5 ] * a21
; maxval /= A [ r2 + 2 ] ; y [ 0 ] = ( ( u1 [ r1 - 1 ] - A [ r1 + 5 ] * a21 )
- A [ r1 + 2 ] * maxval ) / A [ r1 - 1 ] ; y [ 1 ] = maxval ; y [ 2 ] = a21 ;
} void gg1bfsp2im ( SimStruct * const S ) { if ( ssGetTaskTime ( S , 0 ) !=
ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } } void oogbjkhpvp (
SimStruct * const S ) { ssSetSolverNeedsReset ( S ) ; } void cy205zjjvp (
aqk41knsjs * localB , nuymkaafal * localP , mtzv34lgmb * localZCSV ) {
localZCSV -> chnz0bwja4 = localB -> p2r1v5uc1t - localP -> P_2 ; localZCSV ->
irs1oyzos2 = localB -> p2r1v5uc1t - localP -> P_3 ; } void na1jczuzfj (
SimStruct * const S , real_T dc5okcroby , real_T o4edwafn02 , real_T
p1hgv0dswb , real_T j25sq3a1qg , const real_T punmnex54m [ 9 ] , real_T
jig2xoj0os , real_T hdkiq2aomp , real_T crvf1f5mcd , real_T b5aswy32si ,
real_T eifcutivb3 [ 12 ] , aqk41knsjs * localB , e4j3nmaq30 * localDW ,
nuymkaafal * localP ) { real_T tmp ; real_T jpgd4wk4zh ; localB -> jt22zgkkw4
= muDoubleScalarAbs ( p1hgv0dswb ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
localB -> az3fraw5ir = localP -> P_1 ; } localB -> p2r1v5uc1t = localB ->
az3fraw5ir - localB -> jt22zgkkw4 ; if ( ssIsMajorTimeStep ( S ) ) { if (
localB -> p2r1v5uc1t > localP -> P_3 ) { localDW -> f0xg2emmhz = 1 ; } else
if ( localB -> p2r1v5uc1t >= localP -> P_2 ) { localDW -> f0xg2emmhz = 0 ; }
else { localDW -> f0xg2emmhz = - 1 ; } } if ( localDW -> f0xg2emmhz == 1 ) {
localB -> pupcffpnrj = localB -> p2r1v5uc1t - localP -> P_3 ; } else if (
localDW -> f0xg2emmhz == - 1 ) { localB -> pupcffpnrj = localB -> p2r1v5uc1t
- localP -> P_2 ; } else { localB -> pupcffpnrj = 0.0 ; } localB ->
k2jlyn0jxb = muDoubleScalarSign ( p1hgv0dswb ) ; localB -> d3kbrz0bwi =
localB -> k2jlyn0jxb * j25sq3a1qg ; localB -> nelft1gzp1 = localP -> P_4 *
localB -> d3kbrz0bwi ; localB -> dzbdf3thpd = muDoubleScalarSign ( j25sq3a1qg
) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { localB -> ap1ghulkz0 = localP -> P_5
; } localB -> b40s5fnwul = localP -> P_6 * localB -> pupcffpnrj ; localB ->
ffqyncmssz = localB -> k2jlyn0jxb * localB -> b40s5fnwul ; localB ->
mwfsnphzgx = muDoubleScalarSign ( localB -> pupcffpnrj ) ; localB ->
exta23c5fe = muDoubleScalarAbs ( localB -> mwfsnphzgx ) ; if ( localB ->
nelft1gzp1 > localP -> P_7 ) { localB -> bbqii4xqxg = localP -> P_7 ; } else
if ( localB -> nelft1gzp1 < localP -> P_8 ) { localB -> bbqii4xqxg = localP
-> P_8 ; } else { localB -> bbqii4xqxg = localB -> nelft1gzp1 ; } localB ->
jmr2p33101 = localP -> P_9 * localB -> bbqii4xqxg ; localB -> erhesdajtc =
localB -> exta23c5fe * localB -> jmr2p33101 ; localB -> owrrpqgatq = localB
-> erhesdajtc * localB -> dzbdf3thpd ; localB -> eketdjbork = localB ->
ffqyncmssz + localB -> owrrpqgatq ; localB -> gnsxl4unri [ 0 ] = localB ->
ap1ghulkz0 ; localB -> gnsxl4unri [ 1 ] = localB -> ap1ghulkz0 ; localB ->
gnsxl4unri [ 2 ] = localB -> eketdjbork ; localB -> khwsspxbba [ 0 ] = localP
-> P_10 * localB -> gnsxl4unri [ 0 ] ; localB -> khwsspxbba [ 1 ] = localP ->
P_10 * localB -> gnsxl4unri [ 1 ] ; localB -> khwsspxbba [ 2 ] = localP ->
P_10 * localB -> gnsxl4unri [ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
localB -> lpvel2cmla = localP -> P_11 ; } localB -> eeufigro0d = jig2xoj0os *
localB -> lpvel2cmla ; localB -> nynouhgux0 = localB -> k2jlyn0jxb *
b5aswy32si ; localB -> meb4dwv43q = localB -> eeufigro0d + localB ->
nynouhgux0 ; localB -> laxomk3ckb = localB -> lpvel2cmla * hdkiq2aomp ;
localB -> ommrl4mcrz = crvf1f5mcd * localB -> k2jlyn0jxb ; localB ->
em4dotrrip = localB -> ommrl4mcrz - localB -> laxomk3ckb ; localB ->
c1kn35gh0g = localB -> meb4dwv43q * localB -> meb4dwv43q + localB ->
em4dotrrip * localB -> em4dotrrip ; tmp = localB -> c1kn35gh0g ; if (
ssIsMajorTimeStep ( S ) ) { if ( localDW -> eqck5n0qkn != 0 ) {
ssSetSolverNeedsReset ( S ) ; localDW -> eqck5n0qkn = 0 ; } jpgd4wk4zh =
muDoubleScalarSqrt ( localB -> c1kn35gh0g ) ; } else { if ( localB ->
c1kn35gh0g < 0.0 ) { jpgd4wk4zh = - muDoubleScalarSqrt ( muDoubleScalarAbs (
localB -> c1kn35gh0g ) ) ; } else { jpgd4wk4zh = muDoubleScalarSqrt ( localB
-> c1kn35gh0g ) ; } if ( tmp < 0.0 ) { localDW -> eqck5n0qkn = 1 ; } }
jpgd4wk4zh = look1_binlxpw ( jpgd4wk4zh , localP -> P_13 , localP -> P_12 ,
5U ) ; localB -> mbw0xl5mlf = jpgd4wk4zh * localB -> khwsspxbba [ 2 ] ;
localB -> j511rr1z2y = localP -> P_14 * localB -> mbw0xl5mlf ; jpgd4wk4zh =
muDoubleScalarAtan2 ( localB -> meb4dwv43q , localB -> em4dotrrip ) ; localB
-> lqmtyll2fa = localB -> j511rr1z2y * muDoubleScalarCos ( jpgd4wk4zh ) ;
localB -> of51mlfxns = localB -> j511rr1z2y * muDoubleScalarSin ( jpgd4wk4zh
) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { localB -> f3ichguwu1 = localP ->
P_15 ; } localB -> acfpaxlf4r [ 0 ] = localB -> lqmtyll2fa ; localB ->
acfpaxlf4r [ 1 ] = localB -> of51mlfxns ; localB -> acfpaxlf4r [ 2 ] = localB
-> f3ichguwu1 ; localB -> b31cg5x1ir [ 0 ] = localP -> P_16 * localB ->
acfpaxlf4r [ 0 ] ; localB -> b31cg5x1ir [ 1 ] = localP -> P_16 * localB ->
acfpaxlf4r [ 1 ] ; localB -> b31cg5x1ir [ 2 ] = localP -> P_16 * localB ->
acfpaxlf4r [ 2 ] ; localB -> objcm4nsmp [ 0 ] = localB -> khwsspxbba [ 0 ] +
localB -> b31cg5x1ir [ 0 ] ; localB -> objcm4nsmp [ 1 ] = localB ->
khwsspxbba [ 1 ] + localB -> b31cg5x1ir [ 1 ] ; localB -> objcm4nsmp [ 2 ] =
localB -> khwsspxbba [ 2 ] + localB -> b31cg5x1ir [ 2 ] ; localB ->
onspir1oyh = o4edwafn02 * localB -> objcm4nsmp [ 2 ] ; localB -> o5nja05wof =
p1hgv0dswb * localB -> objcm4nsmp [ 1 ] ; localB -> opeu3t0bsw = p1hgv0dswb *
localB -> objcm4nsmp [ 0 ] ; localB -> gyxwkbymcw = dc5okcroby * localB ->
objcm4nsmp [ 2 ] ; localB -> btobm50fu1 = dc5okcroby * localB -> objcm4nsmp [
1 ] ; localB -> assc2styrr = o4edwafn02 * localB -> objcm4nsmp [ 0 ] ; localB
-> njc0oaaoub = localB -> onspir1oyh - localB -> o5nja05wof ; localB ->
ioktonger1 = localB -> opeu3t0bsw - localB -> gyxwkbymcw ; localB ->
nrayy2fuft = localB -> btobm50fu1 - localB -> assc2styrr ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { localB -> f5ljzumgsi [ 0 ] = localP -> P_17 [ 0 ] ; localB
-> f5ljzumgsi [ 1 ] = localP -> P_17 [ 1 ] ; localB -> f5ljzumgsi [ 2 ] =
localP -> P_17 [ 2 ] ; } localB -> bllxcbyi2o [ 0 ] = localB -> f5ljzumgsi [
0 ] * localB -> k2jlyn0jxb ; localB -> bllxcbyi2o [ 1 ] = localB ->
f5ljzumgsi [ 1 ] * localB -> k2jlyn0jxb ; localB -> bllxcbyi2o [ 2 ] = localB
-> f5ljzumgsi [ 2 ] * localB -> k2jlyn0jxb ; localB -> fa3gxj521e = localB ->
bllxcbyi2o [ 1 ] * localB -> f3ichguwu1 ; localB -> cvbi5bfxeq = localB ->
bllxcbyi2o [ 2 ] * localB -> of51mlfxns ; localB -> opxliyqzk2 = localB ->
bllxcbyi2o [ 2 ] * localB -> lqmtyll2fa ; localB -> pnx555tnup = localB ->
bllxcbyi2o [ 0 ] * localB -> f3ichguwu1 ; localB -> ak332gqds2 = localB ->
bllxcbyi2o [ 0 ] * localB -> of51mlfxns ; localB -> h0ghjjucwk = localB ->
bllxcbyi2o [ 1 ] * localB -> lqmtyll2fa ; localB -> ahipwszw5j = localB ->
fa3gxj521e - localB -> cvbi5bfxeq ; localB -> knm5b0rp4n = localB ->
opxliyqzk2 - localB -> pnx555tnup ; localB -> dahq25v1f0 = localB ->
ak332gqds2 - localB -> h0ghjjucwk ; rt_mldivide_U1d3x3_U2d3_Yd3x1_snf (
punmnex54m , localB -> acfpaxlf4r , localB -> k2nmdendpv ) ; localB ->
eu1x1i0ijb [ 0 ] = localB -> ahipwszw5j ; localB -> eu1x1i0ijb [ 1 ] = localB
-> knm5b0rp4n ; localB -> eu1x1i0ijb [ 2 ] = localB -> dahq25v1f0 ;
rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( punmnex54m , localB -> eu1x1i0ijb ,
localB -> bae2wqkb3x ) ; rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( punmnex54m ,
localB -> gnsxl4unri , localB -> lypqdm2ag2 ) ; localB -> blcihgazcv [ 0 ] =
localB -> lypqdm2ag2 [ 0 ] + localB -> k2nmdendpv [ 0 ] ; localB ->
blcihgazcv [ 1 ] = localB -> lypqdm2ag2 [ 1 ] + localB -> k2nmdendpv [ 1 ] ;
localB -> blcihgazcv [ 2 ] = localB -> lypqdm2ag2 [ 2 ] + localB ->
k2nmdendpv [ 2 ] ; eifcutivb3 [ 0 ] = localB -> blcihgazcv [ 0 ] ; eifcutivb3
[ 1 ] = localB -> blcihgazcv [ 1 ] ; eifcutivb3 [ 2 ] = localB -> blcihgazcv
[ 2 ] ; eifcutivb3 [ 3 ] = localB -> bae2wqkb3x [ 0 ] ; eifcutivb3 [ 4 ] =
localB -> bae2wqkb3x [ 1 ] ; eifcutivb3 [ 5 ] = localB -> bae2wqkb3x [ 2 ] ;
eifcutivb3 [ 6 ] = localB -> objcm4nsmp [ 0 ] ; eifcutivb3 [ 7 ] = localB ->
objcm4nsmp [ 1 ] ; eifcutivb3 [ 8 ] = localB -> objcm4nsmp [ 2 ] ; eifcutivb3
[ 9 ] = localB -> njc0oaaoub ; eifcutivb3 [ 10 ] = localB -> ioktonger1 ;
eifcutivb3 [ 11 ] = localB -> nrayy2fuft ; } void pnmcdodxqx ( SimStruct *
const S ) { } static void mdlOutputs ( SimStruct * S , int_T tid ) {
boolean_T first_output ; real_T * lastU ; int8_T rtPrevAction ; int8_T
rtAction ; uint8_T it4zcb31j5 ; uint8_T kpy4amgi3w ; uint8_T aw0su3bro5 ;
real_T j0hhbshz2o ; int32_T i ; real_T tmp [ 16 ] ; int32_T i_p ; fwhqxupvfb
* _rtB ; gv4lfag1c5 * _rtP ; cfqhbkrmw3 * _rtX ; bpocjipxik * _rtDW ; _rtDW =
( ( bpocjipxik * ) ssGetRootDWork ( S ) ) ; _rtX = ( ( cfqhbkrmw3 * )
ssGetContStates ( S ) ) ; _rtP = ( ( gv4lfag1c5 * ) ssGetDefaultParam ( S ) )
; _rtB = ( ( fwhqxupvfb * ) _ssGetBlockIO ( S ) ) ; _rtB -> i0j0mklcqh = ( (
cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> jm10gs3jtx ; _rtB -> ajofuijmjd = (
( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> fodndj1vhy ; _rtB -> a5nszgip1h =
( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> oltvbdbnrv ;
ssCallAccelRunBlock ( S , 26 , 3 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { _rtB -> d2g5skvky4 = _rtP -> P_26 ; } _rtB -> nbl0ysbr3h =
ssGetT ( S ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> o2bfsepd3t = _rtP
-> P_27 ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> obp41iol2y = ( _rtB ->
nbl0ysbr3h <= _rtB -> o2bfsepd3t ) ; } _rtB -> nuir4wmqhb = _rtDW ->
obp41iol2y ; } _rtB -> g3sryjiihq = ( ( cfqhbkrmw3 * ) ssGetContStates ( S )
) -> jv0vvsx3pu ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> a0vgjvfpiq = _rtB
-> g3sryjiihq >= _rtP -> P_29 ? 1 : _rtB -> g3sryjiihq > _rtP -> P_30 ? 0 : -
1 ; } _rtB -> pl2wvrqrxm = _rtDW -> a0vgjvfpiq == 1 ? _rtP -> P_29 : _rtDW ->
a0vgjvfpiq == - 1 ? _rtP -> P_30 : _rtB -> g3sryjiihq ; first_output = false
; if ( _rtDW -> iqb51meuk4 == 0.0 ) { _rtDW -> iqb51meuk4 = 1.0 ;
first_output = true ; } if ( first_output ) { _rtX -> mzra4bbhyj [ 0 ] = _rtB
-> pl2wvrqrxm ; _rtX -> mzra4bbhyj [ 1 ] = 0.0 ; } _rtB -> oh0svn5w12 [ 0 ] =
_rtX -> mzra4bbhyj [ 0 ] ; _rtB -> oh0svn5w12 [ 1 ] = _rtX -> mzra4bbhyj [ 1
] ; _rtB -> oh0svn5w12 [ 2 ] = ( ( _rtB -> pl2wvrqrxm - _rtX -> mzra4bbhyj [
0 ] ) * 1000.0 - 2.0 * _rtX -> mzra4bbhyj [ 1 ] ) * 1000.0 ; _rtB ->
oh0svn5w12 [ 3 ] = 0.0 ; _rtB -> pil5ufxoef = ( ( cfqhbkrmw3 * )
ssGetContStates ( S ) ) -> j3bpgzmycv ; if ( ssIsMajorTimeStep ( S ) ) {
_rtDW -> kazrze3npi = _rtB -> pil5ufxoef >= _rtP -> P_32 ? 1 : _rtB ->
pil5ufxoef > _rtP -> P_33 ? 0 : - 1 ; } _rtB -> nwkzu3qpu5 = _rtDW ->
kazrze3npi == 1 ? _rtP -> P_32 : _rtDW -> kazrze3npi == - 1 ? _rtP -> P_33 :
_rtB -> pil5ufxoef ; first_output = false ; if ( _rtDW -> cyy5rjdkzv == 0.0 )
{ _rtDW -> cyy5rjdkzv = 1.0 ; first_output = true ; } if ( first_output ) {
_rtX -> hzxrhlxoh3 [ 0 ] = _rtB -> nwkzu3qpu5 ; _rtX -> hzxrhlxoh3 [ 1 ] =
0.0 ; } _rtB -> n55dq53lec [ 0 ] = _rtX -> hzxrhlxoh3 [ 0 ] ; _rtB ->
n55dq53lec [ 1 ] = _rtX -> hzxrhlxoh3 [ 1 ] ; _rtB -> n55dq53lec [ 2 ] = ( (
_rtB -> nwkzu3qpu5 - _rtX -> hzxrhlxoh3 [ 0 ] ) * 1000.0 - 2.0 * _rtX ->
hzxrhlxoh3 [ 1 ] ) * 1000.0 ; _rtB -> n55dq53lec [ 3 ] = 0.0 ; _rtB ->
ed1qlbi42l = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> kxycjxmepv ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> kzvhzaicl5 = _rtB -> ed1qlbi42l >= _rtP
-> P_35 ? 1 : _rtB -> ed1qlbi42l > _rtP -> P_36 ? 0 : - 1 ; } _rtB ->
h3fjt0sblk = _rtDW -> kzvhzaicl5 == 1 ? _rtP -> P_35 : _rtDW -> kzvhzaicl5 ==
- 1 ? _rtP -> P_36 : _rtB -> ed1qlbi42l ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ _rtB -> bn1kujc0nc = _rtP -> P_37 ; } _rtB -> f2ancyeofe = _rtB ->
h3fjt0sblk + _rtB -> bn1kujc0nc ; first_output = false ; if ( _rtDW ->
cddth4qhvc == 0.0 ) { _rtDW -> cddth4qhvc = 1.0 ; first_output = true ; } if
( first_output ) { _rtX -> l3rszswrqk [ 0 ] = _rtB -> f2ancyeofe ; _rtX ->
l3rszswrqk [ 1 ] = 0.0 ; } _rtB -> dv1btr2efp [ 0 ] = _rtX -> l3rszswrqk [ 0
] ; _rtB -> dv1btr2efp [ 1 ] = _rtX -> l3rszswrqk [ 1 ] ; _rtB -> dv1btr2efp
[ 2 ] = ( ( _rtB -> f2ancyeofe - _rtX -> l3rszswrqk [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> l3rszswrqk [ 1 ] ) * 1000.0 ; _rtB -> dv1btr2efp [ 3 ] = 0.0 ; _rtB
-> e1jqosdkzn = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> cx0cg2fpl4 ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> mbjy3tts2m = _rtB -> e1jqosdkzn >=
_rtP -> P_39 ? 1 : _rtB -> e1jqosdkzn > _rtP -> P_40 ? 0 : - 1 ; } _rtB ->
i300diadtf = _rtDW -> mbjy3tts2m == 1 ? _rtP -> P_39 : _rtDW -> mbjy3tts2m ==
- 1 ? _rtP -> P_40 : _rtB -> e1jqosdkzn ; first_output = false ; if ( _rtDW
-> jqc3yjqzkw == 0.0 ) { _rtDW -> jqc3yjqzkw = 1.0 ; first_output = true ; }
if ( first_output ) { _rtX -> l0n3ehfyux [ 0 ] = _rtB -> i300diadtf ; _rtX ->
l0n3ehfyux [ 1 ] = 0.0 ; } _rtB -> kub52hrsmt [ 0 ] = _rtX -> l0n3ehfyux [ 0
] ; _rtB -> kub52hrsmt [ 1 ] = _rtX -> l0n3ehfyux [ 1 ] ; _rtB -> kub52hrsmt
[ 2 ] = ( ( _rtB -> i300diadtf - _rtX -> l0n3ehfyux [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> l0n3ehfyux [ 1 ] ) * 1000.0 ; _rtB -> kub52hrsmt [ 3 ] = 0.0 ; _rtB
-> jcyf4n31wf = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> f5chxutszn ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> nzgkygaqgo = _rtB -> jcyf4n31wf >=
_rtP -> P_42 ? 1 : _rtB -> jcyf4n31wf > _rtP -> P_43 ? 0 : - 1 ; } _rtB ->
f1xe44wn5b = _rtDW -> nzgkygaqgo == 1 ? _rtP -> P_42 : _rtDW -> nzgkygaqgo ==
- 1 ? _rtP -> P_43 : _rtB -> jcyf4n31wf ; first_output = false ; if ( _rtDW
-> ik2jhnw1zm == 0.0 ) { _rtDW -> ik2jhnw1zm = 1.0 ; first_output = true ; }
if ( first_output ) { _rtX -> h5trv2qfm5 [ 0 ] = _rtB -> f1xe44wn5b ; _rtX ->
h5trv2qfm5 [ 1 ] = 0.0 ; } _rtB -> kyae2enmx0 [ 0 ] = _rtX -> h5trv2qfm5 [ 0
] ; _rtB -> kyae2enmx0 [ 1 ] = _rtX -> h5trv2qfm5 [ 1 ] ; _rtB -> kyae2enmx0
[ 2 ] = ( ( _rtB -> f1xe44wn5b - _rtX -> h5trv2qfm5 [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> h5trv2qfm5 [ 1 ] ) * 1000.0 ; _rtB -> kyae2enmx0 [ 3 ] = 0.0 ; _rtB
-> a1wvi15y5z = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> n1bu2zupn0 ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> gdey5u2i31 = _rtB -> a1wvi15y5z >=
_rtP -> P_45 ? 1 : _rtB -> a1wvi15y5z > _rtP -> P_46 ? 0 : - 1 ; } _rtB ->
efng1cj14q = _rtDW -> gdey5u2i31 == 1 ? _rtP -> P_45 : _rtDW -> gdey5u2i31 ==
- 1 ? _rtP -> P_46 : _rtB -> a1wvi15y5z ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ _rtB -> otsirbdoqd = _rtP -> P_47 ; } _rtB -> efwousquh4 = _rtB ->
efng1cj14q + _rtB -> otsirbdoqd ; first_output = false ; if ( _rtDW ->
eczk0m0zs0 == 0.0 ) { _rtDW -> eczk0m0zs0 = 1.0 ; first_output = true ; } if
( first_output ) { _rtX -> ewtjdz3urj [ 0 ] = _rtB -> efwousquh4 ; _rtX ->
ewtjdz3urj [ 1 ] = 0.0 ; } _rtB -> hiew0jhhqe [ 0 ] = _rtX -> ewtjdz3urj [ 0
] ; _rtB -> hiew0jhhqe [ 1 ] = _rtX -> ewtjdz3urj [ 1 ] ; _rtB -> hiew0jhhqe
[ 2 ] = ( ( _rtB -> efwousquh4 - _rtX -> ewtjdz3urj [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> ewtjdz3urj [ 1 ] ) * 1000.0 ; _rtB -> hiew0jhhqe [ 3 ] = 0.0 ; _rtB
-> m1wdj4ywn0 = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> oflrpx4jgo ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> hwblmgkkad = _rtB -> m1wdj4ywn0 >=
_rtP -> P_49 ? 1 : _rtB -> m1wdj4ywn0 > _rtP -> P_50 ? 0 : - 1 ; } _rtB ->
ofeafse4g5 = _rtDW -> hwblmgkkad == 1 ? _rtP -> P_49 : _rtDW -> hwblmgkkad ==
- 1 ? _rtP -> P_50 : _rtB -> m1wdj4ywn0 ; first_output = false ; if ( _rtDW
-> nonunyd5as == 0.0 ) { _rtDW -> nonunyd5as = 1.0 ; first_output = true ; }
if ( first_output ) { _rtX -> e21euocnfu [ 0 ] = _rtB -> ofeafse4g5 ; _rtX ->
e21euocnfu [ 1 ] = 0.0 ; } _rtB -> eugwurgpyy [ 0 ] = _rtX -> e21euocnfu [ 0
] ; _rtB -> eugwurgpyy [ 1 ] = _rtX -> e21euocnfu [ 1 ] ; _rtB -> eugwurgpyy
[ 2 ] = ( ( _rtB -> ofeafse4g5 - _rtX -> e21euocnfu [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> e21euocnfu [ 1 ] ) * 1000.0 ; _rtB -> eugwurgpyy [ 3 ] = 0.0 ; _rtB
-> drjx2o4dvc = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> obh2b3io0g ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> nclfsgybog = _rtB -> drjx2o4dvc >=
_rtP -> P_52 ? 1 : _rtB -> drjx2o4dvc > _rtP -> P_53 ? 0 : - 1 ; } _rtB ->
irhvcfxcsa = _rtDW -> nclfsgybog == 1 ? _rtP -> P_52 : _rtDW -> nclfsgybog ==
- 1 ? _rtP -> P_53 : _rtB -> drjx2o4dvc ; first_output = false ; if ( _rtDW
-> krxichck0h == 0.0 ) { _rtDW -> krxichck0h = 1.0 ; first_output = true ; }
if ( first_output ) { _rtX -> asysdruxqk [ 0 ] = _rtB -> irhvcfxcsa ; _rtX ->
asysdruxqk [ 1 ] = 0.0 ; } _rtB -> eqcrq0scgw [ 0 ] = _rtX -> asysdruxqk [ 0
] ; _rtB -> eqcrq0scgw [ 1 ] = _rtX -> asysdruxqk [ 1 ] ; _rtB -> eqcrq0scgw
[ 2 ] = ( ( _rtB -> irhvcfxcsa - _rtX -> asysdruxqk [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> asysdruxqk [ 1 ] ) * 1000.0 ; _rtB -> eqcrq0scgw [ 3 ] = 0.0 ; _rtB
-> liod4lgaau = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> e554iejytk ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> ewmb3apvmh = _rtB -> liod4lgaau >=
_rtP -> P_55 ? 1 : _rtB -> liod4lgaau > _rtP -> P_56 ? 0 : - 1 ; } _rtB ->
e21bd0tfoz = _rtDW -> ewmb3apvmh == 1 ? _rtP -> P_55 : _rtDW -> ewmb3apvmh ==
- 1 ? _rtP -> P_56 : _rtB -> liod4lgaau ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ _rtB -> pl4jsq30hb = _rtP -> P_57 ; } _rtB -> ev4wogm2gm = _rtB ->
e21bd0tfoz + _rtB -> pl4jsq30hb ; first_output = false ; if ( _rtDW ->
arvqjki2y2 == 0.0 ) { _rtDW -> arvqjki2y2 = 1.0 ; first_output = true ; } if
( first_output ) { _rtX -> ncec53pyop [ 0 ] = _rtB -> ev4wogm2gm ; _rtX ->
ncec53pyop [ 1 ] = 0.0 ; } _rtB -> eynnak1agt [ 0 ] = _rtX -> ncec53pyop [ 0
] ; _rtB -> eynnak1agt [ 1 ] = _rtX -> ncec53pyop [ 1 ] ; _rtB -> eynnak1agt
[ 2 ] = ( ( _rtB -> ev4wogm2gm - _rtX -> ncec53pyop [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> ncec53pyop [ 1 ] ) * 1000.0 ; _rtB -> eynnak1agt [ 3 ] = 0.0 ; _rtB
-> cvz0aedo3t = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> muikzs5val ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> k3pyo00csd = _rtB -> cvz0aedo3t >=
_rtP -> P_59 ? 1 : _rtB -> cvz0aedo3t > _rtP -> P_60 ? 0 : - 1 ; } _rtB ->
ejeeikgi2h = _rtDW -> k3pyo00csd == 1 ? _rtP -> P_59 : _rtDW -> k3pyo00csd ==
- 1 ? _rtP -> P_60 : _rtB -> cvz0aedo3t ; first_output = false ; if ( _rtDW
-> p23idn2y0q == 0.0 ) { _rtDW -> p23idn2y0q = 1.0 ; first_output = true ; }
if ( first_output ) { _rtX -> b2y0jcphiu [ 0 ] = _rtB -> ejeeikgi2h ; _rtX ->
b2y0jcphiu [ 1 ] = 0.0 ; } _rtB -> n2p4xm25zn [ 0 ] = _rtX -> b2y0jcphiu [ 0
] ; _rtB -> n2p4xm25zn [ 1 ] = _rtX -> b2y0jcphiu [ 1 ] ; _rtB -> n2p4xm25zn
[ 2 ] = ( ( _rtB -> ejeeikgi2h - _rtX -> b2y0jcphiu [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> b2y0jcphiu [ 1 ] ) * 1000.0 ; _rtB -> n2p4xm25zn [ 3 ] = 0.0 ; _rtB
-> lzdhfvavgi = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> ctle43cx5w ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> p0dmh2y21v = _rtB -> lzdhfvavgi >=
_rtP -> P_62 ? 1 : _rtB -> lzdhfvavgi > _rtP -> P_63 ? 0 : - 1 ; } _rtB ->
gxcwwxfexc = _rtDW -> p0dmh2y21v == 1 ? _rtP -> P_62 : _rtDW -> p0dmh2y21v ==
- 1 ? _rtP -> P_63 : _rtB -> lzdhfvavgi ; first_output = false ; if ( _rtDW
-> pgsrf2evdb == 0.0 ) { _rtDW -> pgsrf2evdb = 1.0 ; first_output = true ; }
if ( first_output ) { _rtX -> efdpehqsdx [ 0 ] = _rtB -> gxcwwxfexc ; _rtX ->
efdpehqsdx [ 1 ] = 0.0 ; } _rtB -> lpzp2jdad0 [ 0 ] = _rtX -> efdpehqsdx [ 0
] ; _rtB -> lpzp2jdad0 [ 1 ] = _rtX -> efdpehqsdx [ 1 ] ; _rtB -> lpzp2jdad0
[ 2 ] = ( ( _rtB -> gxcwwxfexc - _rtX -> efdpehqsdx [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> efdpehqsdx [ 1 ] ) * 1000.0 ; _rtB -> lpzp2jdad0 [ 3 ] = 0.0 ; _rtB
-> ne2zyxbo02 = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> afps34cofr ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> dfd440z1kq = _rtB -> ne2zyxbo02 >=
_rtP -> P_65 ? 1 : _rtB -> ne2zyxbo02 > _rtP -> P_66 ? 0 : - 1 ; } _rtB ->
h4eeh2fwvk = _rtDW -> dfd440z1kq == 1 ? _rtP -> P_65 : _rtDW -> dfd440z1kq ==
- 1 ? _rtP -> P_66 : _rtB -> ne2zyxbo02 ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ _rtB -> i11ri2pijk = _rtP -> P_67 ; } _rtB -> nyo0mtbfor = _rtB ->
h4eeh2fwvk + _rtB -> i11ri2pijk ; first_output = false ; if ( _rtDW ->
jqf0rqkuqu == 0.0 ) { _rtDW -> jqf0rqkuqu = 1.0 ; first_output = true ; } if
( first_output ) { _rtX -> os4wjwwywo [ 0 ] = _rtB -> nyo0mtbfor ; _rtX ->
os4wjwwywo [ 1 ] = 0.0 ; } _rtB -> l4zxac3usd [ 0 ] = _rtX -> os4wjwwywo [ 0
] ; _rtB -> l4zxac3usd [ 1 ] = _rtX -> os4wjwwywo [ 1 ] ; _rtB -> l4zxac3usd
[ 2 ] = ( ( _rtB -> nyo0mtbfor - _rtX -> os4wjwwywo [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> os4wjwwywo [ 1 ] ) * 1000.0 ; _rtB -> l4zxac3usd [ 3 ] = 0.0 ; _rtB
-> c3s43vv3fy = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> nnelvip41m ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> bc5n2gwqx2 = _rtB -> c3s43vv3fy >=
_rtP -> P_69 ? 1 : _rtB -> c3s43vv3fy > _rtP -> P_70 ? 0 : - 1 ; } _rtB ->
pjtv53t1ga = _rtDW -> bc5n2gwqx2 == 1 ? _rtP -> P_69 : _rtDW -> bc5n2gwqx2 ==
- 1 ? _rtP -> P_70 : _rtB -> c3s43vv3fy ; first_output = false ; if ( _rtDW
-> bhlzqtjas5 == 0.0 ) { _rtDW -> bhlzqtjas5 = 1.0 ; first_output = true ; }
if ( first_output ) { _rtX -> enzxkhjcgi [ 0 ] = _rtB -> pjtv53t1ga ; _rtX ->
enzxkhjcgi [ 1 ] = 0.0 ; } _rtB -> dqwoim2l4j [ 0 ] = _rtX -> enzxkhjcgi [ 0
] ; _rtB -> dqwoim2l4j [ 1 ] = _rtX -> enzxkhjcgi [ 1 ] ; _rtB -> dqwoim2l4j
[ 2 ] = ( ( _rtB -> pjtv53t1ga - _rtX -> enzxkhjcgi [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> enzxkhjcgi [ 1 ] ) * 1000.0 ; _rtB -> dqwoim2l4j [ 3 ] = 0.0 ; _rtB
-> j3qgyvd5st = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> mlvwdw3tjx ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> nrwdhn43bh = _rtB -> j3qgyvd5st >=
_rtP -> P_72 ? 1 : _rtB -> j3qgyvd5st > _rtP -> P_73 ? 0 : - 1 ; } _rtB ->
jd2m5t2awx = _rtDW -> nrwdhn43bh == 1 ? _rtP -> P_72 : _rtDW -> nrwdhn43bh ==
- 1 ? _rtP -> P_73 : _rtB -> j3qgyvd5st ; first_output = false ; if ( _rtDW
-> c5ynqd3rfm == 0.0 ) { _rtDW -> c5ynqd3rfm = 1.0 ; first_output = true ; }
if ( first_output ) { _rtX -> oojbg1bx4b [ 0 ] = _rtB -> jd2m5t2awx ; _rtX ->
oojbg1bx4b [ 1 ] = 0.0 ; } _rtB -> gonr2qbyem [ 0 ] = _rtX -> oojbg1bx4b [ 0
] ; _rtB -> gonr2qbyem [ 1 ] = _rtX -> oojbg1bx4b [ 1 ] ; _rtB -> gonr2qbyem
[ 2 ] = ( ( _rtB -> jd2m5t2awx - _rtX -> oojbg1bx4b [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> oojbg1bx4b [ 1 ] ) * 1000.0 ; _rtB -> gonr2qbyem [ 3 ] = 0.0 ; _rtB
-> j3l3up1kvo = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> ma2dtr2sez ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> jki3yikz4u = _rtB -> j3l3up1kvo >=
_rtP -> P_75 ? 1 : _rtB -> j3l3up1kvo > _rtP -> P_76 ? 0 : - 1 ; } _rtB ->
fqocnpspxc = _rtDW -> jki3yikz4u == 1 ? _rtP -> P_75 : _rtDW -> jki3yikz4u ==
- 1 ? _rtP -> P_76 : _rtB -> j3l3up1kvo ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ _rtB -> pdwxsg5nvd = _rtP -> P_77 ; } _rtB -> dpv1oe3ih3 = _rtB ->
fqocnpspxc + _rtB -> pdwxsg5nvd ; first_output = false ; if ( _rtDW ->
njwc33uzps == 0.0 ) { _rtDW -> njwc33uzps = 1.0 ; first_output = true ; } if
( first_output ) { _rtX -> cekdgjravx [ 0 ] = _rtB -> dpv1oe3ih3 ; _rtX ->
cekdgjravx [ 1 ] = 0.0 ; } _rtB -> mkzwd104fw [ 0 ] = _rtX -> cekdgjravx [ 0
] ; _rtB -> mkzwd104fw [ 1 ] = _rtX -> cekdgjravx [ 1 ] ; _rtB -> mkzwd104fw
[ 2 ] = ( ( _rtB -> dpv1oe3ih3 - _rtX -> cekdgjravx [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> cekdgjravx [ 1 ] ) * 1000.0 ; _rtB -> mkzwd104fw [ 3 ] = 0.0 ; _rtB
-> nkoo0exfdx = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> muzujlinyc ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> i2iwjwgtsw = _rtB -> nkoo0exfdx >=
_rtP -> P_79 ? 1 : _rtB -> nkoo0exfdx > _rtP -> P_80 ? 0 : - 1 ; } _rtB ->
piyok5iwts = _rtDW -> i2iwjwgtsw == 1 ? _rtP -> P_79 : _rtDW -> i2iwjwgtsw ==
- 1 ? _rtP -> P_80 : _rtB -> nkoo0exfdx ; first_output = false ; if ( _rtDW
-> n015q0oibi == 0.0 ) { _rtDW -> n015q0oibi = 1.0 ; first_output = true ; }
if ( first_output ) { _rtX -> neoskuf135 [ 0 ] = _rtB -> piyok5iwts ; _rtX ->
neoskuf135 [ 1 ] = 0.0 ; } _rtB -> ku1tnfsolu [ 0 ] = _rtX -> neoskuf135 [ 0
] ; _rtB -> ku1tnfsolu [ 1 ] = _rtX -> neoskuf135 [ 1 ] ; _rtB -> ku1tnfsolu
[ 2 ] = ( ( _rtB -> piyok5iwts - _rtX -> neoskuf135 [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> neoskuf135 [ 1 ] ) * 1000.0 ; _rtB -> ku1tnfsolu [ 3 ] = 0.0 ; _rtB
-> ip5i4w2t4o = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> gwcgb0amvz ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> fcotbbvzjp = _rtB -> ip5i4w2t4o >=
_rtP -> P_82 ? 1 : _rtB -> ip5i4w2t4o > _rtP -> P_83 ? 0 : - 1 ; } _rtB ->
hqbvo1rsxu = _rtDW -> fcotbbvzjp == 1 ? _rtP -> P_82 : _rtDW -> fcotbbvzjp ==
- 1 ? _rtP -> P_83 : _rtB -> ip5i4w2t4o ; first_output = false ; if ( _rtDW
-> h2qpnjixun == 0.0 ) { _rtDW -> h2qpnjixun = 1.0 ; first_output = true ; }
if ( first_output ) { _rtX -> bbxqinau05 [ 0 ] = _rtB -> hqbvo1rsxu ; _rtX ->
bbxqinau05 [ 1 ] = 0.0 ; } _rtB -> jnb0sxkeml [ 0 ] = _rtX -> bbxqinau05 [ 0
] ; _rtB -> jnb0sxkeml [ 1 ] = _rtX -> bbxqinau05 [ 1 ] ; _rtB -> jnb0sxkeml
[ 2 ] = ( ( _rtB -> hqbvo1rsxu - _rtX -> bbxqinau05 [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> bbxqinau05 [ 1 ] ) * 1000.0 ; _rtB -> jnb0sxkeml [ 3 ] = 0.0 ; _rtB
-> aevstei5cx = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> dpjj44i2aj ; if
( ssIsMajorTimeStep ( S ) ) { _rtDW -> lj3hflwxnj = _rtB -> aevstei5cx >=
_rtP -> P_85 ? 1 : _rtB -> aevstei5cx > _rtP -> P_86 ? 0 : - 1 ; } _rtB ->
hsnfguvswh = _rtDW -> lj3hflwxnj == 1 ? _rtP -> P_85 : _rtDW -> lj3hflwxnj ==
- 1 ? _rtP -> P_86 : _rtB -> aevstei5cx ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ _rtB -> ahnsnc4zkg = _rtP -> P_87 ; } _rtB -> ioqypqfh4t = _rtB ->
hsnfguvswh + _rtB -> ahnsnc4zkg ; first_output = false ; if ( _rtDW ->
ke4f4jyotz == 0.0 ) { _rtDW -> ke4f4jyotz = 1.0 ; first_output = true ; } if
( first_output ) { _rtX -> j50oldiplh [ 0 ] = _rtB -> ioqypqfh4t ; _rtX ->
j50oldiplh [ 1 ] = 0.0 ; } _rtB -> l4r15rrpt2 [ 0 ] = _rtX -> j50oldiplh [ 0
] ; _rtB -> l4r15rrpt2 [ 1 ] = _rtX -> j50oldiplh [ 1 ] ; _rtB -> l4r15rrpt2
[ 2 ] = ( ( _rtB -> ioqypqfh4t - _rtX -> j50oldiplh [ 0 ] ) * 1000.0 - 2.0 *
_rtX -> j50oldiplh [ 1 ] ) * 1000.0 ; _rtB -> l4r15rrpt2 [ 3 ] = 0.0 ;
ssCallAccelRunBlock ( S , 26 , 74 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 75 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
nuir4wmqhb ) { _rtB -> p514wil3wf [ 0 ] = _rtB -> d2g5skvky4 ; _rtB ->
p514wil3wf [ 1 ] = _rtB -> d2g5skvky4 ; _rtB -> p514wil3wf [ 2 ] = _rtB ->
d2g5skvky4 ; } else { _rtB -> p514wil3wf [ 0 ] = _rtB -> gm5e5ghrph [ 21 ] ;
_rtB -> p514wil3wf [ 1 ] = _rtB -> gm5e5ghrph [ 22 ] ; _rtB -> p514wil3wf [ 2
] = _rtB -> gm5e5ghrph [ 23 ] ; } _rtB -> opkpzk1kku = _rtP -> P_88 * _rtB ->
p514wil3wf [ 0 ] ; _rtB -> k30uihcugk = _rtP -> P_89 * _rtB -> p514wil3wf [ 1
] ; _rtB -> gzzh1oxkw2 = _rtP -> P_90 * _rtB -> p514wil3wf [ 2 ] ;
ssCallAccelRunBlock ( S , 26 , 80 , SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i <
4 ; i ++ ) { for ( i_p = 0 ; i_p < 4 ; i_p ++ ) { _rtB -> khjsuo3osc [ i + (
i_p << 2 ) ] = 0.0 ; _rtB -> khjsuo3osc [ i + ( i_p << 2 ) ] += _rtB ->
hh2u53uzuf [ i_p << 2 ] * _rtB -> gburcqcwbo [ i ] ; _rtB -> khjsuo3osc [ i +
( i_p << 2 ) ] += _rtB -> hh2u53uzuf [ ( i_p << 2 ) + 1 ] * _rtB ->
gburcqcwbo [ i + 4 ] ; _rtB -> khjsuo3osc [ i + ( i_p << 2 ) ] += _rtB ->
hh2u53uzuf [ ( i_p << 2 ) + 2 ] * _rtB -> gburcqcwbo [ i + 8 ] ; _rtB ->
khjsuo3osc [ i + ( i_p << 2 ) ] += _rtB -> hh2u53uzuf [ ( i_p << 2 ) + 3 ] *
_rtB -> gburcqcwbo [ i + 12 ] ; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
memcpy ( & _rtB -> nzbsvwuedv [ 0 ] , & _rtP -> P_91 [ 0 ] , sizeof ( real_T
) << 4U ) ; } ssCallAccelRunBlock ( S , 26 , 83 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 84 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> adc0nqgk5j = _rtP -> P_92 ; } _rtB ->
a5tuo12eqh = _rtB -> gm5e5ghrph [ 2 ] - _rtB -> adc0nqgk5j ;
ssCallAccelRunBlock ( S , 26 , 87 , SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i <
4 ; i ++ ) { for ( i_p = 0 ; i_p < 4 ; i_p ++ ) { tmp [ i + ( i_p << 2 ) ] =
0.0 ; tmp [ i + ( i_p << 2 ) ] += _rtB -> pyx1ky2feu [ i_p << 2 ] * _rtB ->
gburcqcwbo [ i ] ; tmp [ i + ( i_p << 2 ) ] += _rtB -> pyx1ky2feu [ ( i_p <<
2 ) + 1 ] * _rtB -> gburcqcwbo [ i + 4 ] ; tmp [ i + ( i_p << 2 ) ] += _rtB
-> pyx1ky2feu [ ( i_p << 2 ) + 2 ] * _rtB -> gburcqcwbo [ i + 8 ] ; tmp [ i +
( i_p << 2 ) ] += _rtB -> pyx1ky2feu [ ( i_p << 2 ) + 3 ] * _rtB ->
gburcqcwbo [ i + 12 ] ; } } for ( i = 0 ; i < 4 ; i ++ ) { for ( i_p = 0 ;
i_p < 4 ; i_p ++ ) { _rtB -> h4snrz3353 [ i + ( i_p << 2 ) ] = 0.0 ; _rtB ->
h4snrz3353 [ i + ( i_p << 2 ) ] += tmp [ i_p << 2 ] * _rtB -> hh2u53uzuf [ i
] ; _rtB -> h4snrz3353 [ i + ( i_p << 2 ) ] += tmp [ ( i_p << 2 ) + 1 ] *
_rtB -> hh2u53uzuf [ i + 4 ] ; _rtB -> h4snrz3353 [ i + ( i_p << 2 ) ] += tmp
[ ( i_p << 2 ) + 2 ] * _rtB -> hh2u53uzuf [ i + 8 ] ; _rtB -> h4snrz3353 [ i
+ ( i_p << 2 ) ] += tmp [ ( i_p << 2 ) + 3 ] * _rtB -> hh2u53uzuf [ i + 12 ]
; } } for ( i = 0 ; i < 4 ; i ++ ) { for ( i_p = 0 ; i_p < 4 ; i_p ++ ) {
_rtB -> bkagydprid [ i + ( i_p << 2 ) ] = 0.0 ; _rtB -> bkagydprid [ i + (
i_p << 2 ) ] += _rtB -> h4snrz3353 [ i_p << 2 ] * _rtB -> nzbsvwuedv [ i ] ;
_rtB -> bkagydprid [ i + ( i_p << 2 ) ] += _rtB -> h4snrz3353 [ ( i_p << 2 )
+ 1 ] * _rtB -> nzbsvwuedv [ i + 4 ] ; _rtB -> bkagydprid [ i + ( i_p << 2 )
] += _rtB -> h4snrz3353 [ ( i_p << 2 ) + 2 ] * _rtB -> nzbsvwuedv [ i + 8 ] ;
_rtB -> bkagydprid [ i + ( i_p << 2 ) ] += _rtB -> h4snrz3353 [ ( i_p << 2 )
+ 3 ] * _rtB -> nzbsvwuedv [ i + 12 ] ; } } for ( i = 0 ; i < 4 ; i ++ ) {
for ( i_p = 0 ; i_p < 4 ; i_p ++ ) { _rtB -> jlo450jiqx [ i + ( i_p << 2 ) ]
= 0.0 ; _rtB -> jlo450jiqx [ i + ( i_p << 2 ) ] += _rtB -> bkagydprid [ i_p
<< 2 ] * _rtB -> khjsuo3osc [ i ] ; _rtB -> jlo450jiqx [ i + ( i_p << 2 ) ]
+= _rtB -> bkagydprid [ ( i_p << 2 ) + 1 ] * _rtB -> khjsuo3osc [ i + 4 ] ;
_rtB -> jlo450jiqx [ i + ( i_p << 2 ) ] += _rtB -> bkagydprid [ ( i_p << 2 )
+ 2 ] * _rtB -> khjsuo3osc [ i + 8 ] ; _rtB -> jlo450jiqx [ i + ( i_p << 2 )
] += _rtB -> bkagydprid [ ( i_p << 2 ) + 3 ] * _rtB -> khjsuo3osc [ i + 12 ]
; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> gejf5ivnkq [ 0 ] = _rtP ->
P_93 [ 0 ] ; _rtB -> gejf5ivnkq [ 1 ] = _rtP -> P_93 [ 1 ] ; _rtB ->
gejf5ivnkq [ 2 ] = _rtP -> P_93 [ 2 ] ; _rtB -> gejf5ivnkq [ 3 ] = _rtP ->
P_93 [ 3 ] ; } for ( i = 0 ; i < 4 ; i ++ ) { _rtB -> l5vcadh1by [ i ] = 0.0
; _rtB -> l5vcadh1by [ i ] += _rtB -> jlo450jiqx [ i ] * _rtB -> gejf5ivnkq [
0 ] ; _rtB -> l5vcadh1by [ i ] += _rtB -> jlo450jiqx [ i + 4 ] * _rtB ->
gejf5ivnkq [ 1 ] ; _rtB -> l5vcadh1by [ i ] += _rtB -> jlo450jiqx [ i + 8 ] *
_rtB -> gejf5ivnkq [ 2 ] ; _rtB -> l5vcadh1by [ i ] += _rtB -> jlo450jiqx [ i
+ 12 ] * _rtB -> gejf5ivnkq [ 3 ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
memcpy ( & _rtB -> popne0wtiu [ 0 ] , & _rtP -> P_94 [ 0 ] , sizeof ( real_T
) << 4U ) ; } ssCallAccelRunBlock ( S , 26 , 94 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 95 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> jdneviwxz3 = _rtP -> P_95 ; } _rtB ->
hpgav1w5qc = _rtB -> gm5e5ghrph [ 5 ] - _rtB -> jdneviwxz3 ;
ssCallAccelRunBlock ( S , 26 , 98 , SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i <
4 ; i ++ ) { for ( i_p = 0 ; i_p < 4 ; i_p ++ ) { tmp [ i + ( i_p << 2 ) ] =
0.0 ; tmp [ i + ( i_p << 2 ) ] += _rtB -> gburcqcwbo [ i_p << 2 ] * _rtB ->
hh2u53uzuf [ i ] ; tmp [ i + ( i_p << 2 ) ] += _rtB -> gburcqcwbo [ ( i_p <<
2 ) + 1 ] * _rtB -> hh2u53uzuf [ i + 4 ] ; tmp [ i + ( i_p << 2 ) ] += _rtB
-> gburcqcwbo [ ( i_p << 2 ) + 2 ] * _rtB -> hh2u53uzuf [ i + 8 ] ; tmp [ i +
( i_p << 2 ) ] += _rtB -> gburcqcwbo [ ( i_p << 2 ) + 3 ] * _rtB ->
hh2u53uzuf [ i + 12 ] ; } } for ( i = 0 ; i < 4 ; i ++ ) { for ( i_p = 0 ;
i_p < 4 ; i_p ++ ) { _rtB -> djgcwqwgsb [ i + ( i_p << 2 ) ] = 0.0 ; _rtB ->
djgcwqwgsb [ i + ( i_p << 2 ) ] += tmp [ i_p << 2 ] * _rtB -> pyx1ky2feu [ i
] ; _rtB -> djgcwqwgsb [ i + ( i_p << 2 ) ] += tmp [ ( i_p << 2 ) + 1 ] *
_rtB -> pyx1ky2feu [ i + 4 ] ; _rtB -> djgcwqwgsb [ i + ( i_p << 2 ) ] += tmp
[ ( i_p << 2 ) + 2 ] * _rtB -> pyx1ky2feu [ i + 8 ] ; _rtB -> djgcwqwgsb [ i
+ ( i_p << 2 ) ] += tmp [ ( i_p << 2 ) + 3 ] * _rtB -> pyx1ky2feu [ i + 12 ]
; } } for ( i = 0 ; i < 4 ; i ++ ) { for ( i_p = 0 ; i_p < 4 ; i_p ++ ) {
_rtB -> jgvgvwcyhb [ i + ( i_p << 2 ) ] = 0.0 ; _rtB -> jgvgvwcyhb [ i + (
i_p << 2 ) ] += _rtB -> djgcwqwgsb [ i_p << 2 ] * _rtB -> popne0wtiu [ i ] ;
_rtB -> jgvgvwcyhb [ i + ( i_p << 2 ) ] += _rtB -> djgcwqwgsb [ ( i_p << 2 )
+ 1 ] * _rtB -> popne0wtiu [ i + 4 ] ; _rtB -> jgvgvwcyhb [ i + ( i_p << 2 )
] += _rtB -> djgcwqwgsb [ ( i_p << 2 ) + 2 ] * _rtB -> popne0wtiu [ i + 8 ] ;
_rtB -> jgvgvwcyhb [ i + ( i_p << 2 ) ] += _rtB -> djgcwqwgsb [ ( i_p << 2 )
+ 3 ] * _rtB -> popne0wtiu [ i + 12 ] ; } } for ( i = 0 ; i < 4 ; i ++ ) {
for ( i_p = 0 ; i_p < 4 ; i_p ++ ) { _rtB -> jwuuujjenc [ i + ( i_p << 2 ) ]
= 0.0 ; _rtB -> jwuuujjenc [ i + ( i_p << 2 ) ] += _rtB -> jgvgvwcyhb [ i_p
<< 2 ] * _rtB -> khjsuo3osc [ i ] ; _rtB -> jwuuujjenc [ i + ( i_p << 2 ) ]
+= _rtB -> jgvgvwcyhb [ ( i_p << 2 ) + 1 ] * _rtB -> khjsuo3osc [ i + 4 ] ;
_rtB -> jwuuujjenc [ i + ( i_p << 2 ) ] += _rtB -> jgvgvwcyhb [ ( i_p << 2 )
+ 2 ] * _rtB -> khjsuo3osc [ i + 8 ] ; _rtB -> jwuuujjenc [ i + ( i_p << 2 )
] += _rtB -> jgvgvwcyhb [ ( i_p << 2 ) + 3 ] * _rtB -> khjsuo3osc [ i + 12 ]
; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> anqlapqmqr [ 0 ] = _rtP ->
P_96 [ 0 ] ; _rtB -> anqlapqmqr [ 1 ] = _rtP -> P_96 [ 1 ] ; _rtB ->
anqlapqmqr [ 2 ] = _rtP -> P_96 [ 2 ] ; _rtB -> anqlapqmqr [ 3 ] = _rtP ->
P_96 [ 3 ] ; } for ( i = 0 ; i < 4 ; i ++ ) { _rtB -> dcegzfky4q [ i ] = 0.0
; _rtB -> dcegzfky4q [ i ] += _rtB -> jwuuujjenc [ i ] * _rtB -> anqlapqmqr [
0 ] ; _rtB -> dcegzfky4q [ i ] += _rtB -> jwuuujjenc [ i + 4 ] * _rtB ->
anqlapqmqr [ 1 ] ; _rtB -> dcegzfky4q [ i ] += _rtB -> jwuuujjenc [ i + 8 ] *
_rtB -> anqlapqmqr [ 2 ] ; _rtB -> dcegzfky4q [ i ] += _rtB -> jwuuujjenc [ i
+ 12 ] * _rtB -> anqlapqmqr [ 3 ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
memcpy ( & _rtB -> mtcewu43bp [ 0 ] , & _rtP -> P_97 [ 0 ] , sizeof ( real_T
) << 4U ) ; } ssCallAccelRunBlock ( S , 26 , 105 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 106 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> j11uokpxme = _rtP -> P_98 ; } _rtB ->
bgegxfbkgr = _rtB -> gm5e5ghrph [ 8 ] - _rtB -> j11uokpxme ;
ssCallAccelRunBlock ( S , 26 , 109 , SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i
< 4 ; i ++ ) { for ( i_p = 0 ; i_p < 4 ; i_p ++ ) { tmp [ i + ( i_p << 2 ) ]
= 0.0 ; tmp [ i + ( i_p << 2 ) ] += _rtB -> fajc5v5hdc [ i_p << 2 ] * _rtB ->
hvinuhjlyz [ i ] ; tmp [ i + ( i_p << 2 ) ] += _rtB -> fajc5v5hdc [ ( i_p <<
2 ) + 1 ] * _rtB -> hvinuhjlyz [ i + 4 ] ; tmp [ i + ( i_p << 2 ) ] += _rtB
-> fajc5v5hdc [ ( i_p << 2 ) + 2 ] * _rtB -> hvinuhjlyz [ i + 8 ] ; tmp [ i +
( i_p << 2 ) ] += _rtB -> fajc5v5hdc [ ( i_p << 2 ) + 3 ] * _rtB ->
hvinuhjlyz [ i + 12 ] ; } } for ( i = 0 ; i < 4 ; i ++ ) { for ( i_p = 0 ;
i_p < 4 ; i_p ++ ) { _rtB -> irugtisj0l [ i + ( i_p << 2 ) ] = 0.0 ; _rtB ->
irugtisj0l [ i + ( i_p << 2 ) ] += tmp [ i_p << 2 ] * _rtB -> n54544rfrj [ i
] ; _rtB -> irugtisj0l [ i + ( i_p << 2 ) ] += tmp [ ( i_p << 2 ) + 1 ] *
_rtB -> n54544rfrj [ i + 4 ] ; _rtB -> irugtisj0l [ i + ( i_p << 2 ) ] += tmp
[ ( i_p << 2 ) + 2 ] * _rtB -> n54544rfrj [ i + 8 ] ; _rtB -> irugtisj0l [ i
+ ( i_p << 2 ) ] += tmp [ ( i_p << 2 ) + 3 ] * _rtB -> n54544rfrj [ i + 12 ]
; } } for ( i = 0 ; i < 4 ; i ++ ) { for ( i_p = 0 ; i_p < 4 ; i_p ++ ) {
_rtB -> gknasrevhr [ i + ( i_p << 2 ) ] = 0.0 ; _rtB -> gknasrevhr [ i + (
i_p << 2 ) ] += _rtB -> irugtisj0l [ i_p << 2 ] * _rtB -> mtcewu43bp [ i ] ;
_rtB -> gknasrevhr [ i + ( i_p << 2 ) ] += _rtB -> irugtisj0l [ ( i_p << 2 )
+ 1 ] * _rtB -> mtcewu43bp [ i + 4 ] ; _rtB -> gknasrevhr [ i + ( i_p << 2 )
] += _rtB -> irugtisj0l [ ( i_p << 2 ) + 2 ] * _rtB -> mtcewu43bp [ i + 8 ] ;
_rtB -> gknasrevhr [ i + ( i_p << 2 ) ] += _rtB -> irugtisj0l [ ( i_p << 2 )
+ 3 ] * _rtB -> mtcewu43bp [ i + 12 ] ; } } for ( i = 0 ; i < 4 ; i ++ ) {
for ( i_p = 0 ; i_p < 4 ; i_p ++ ) { _rtB -> aowa4p1gbt [ i + ( i_p << 2 ) ]
= 0.0 ; _rtB -> aowa4p1gbt [ i + ( i_p << 2 ) ] += _rtB -> gknasrevhr [ i_p
<< 2 ] * _rtB -> khjsuo3osc [ i ] ; _rtB -> aowa4p1gbt [ i + ( i_p << 2 ) ]
+= _rtB -> gknasrevhr [ ( i_p << 2 ) + 1 ] * _rtB -> khjsuo3osc [ i + 4 ] ;
_rtB -> aowa4p1gbt [ i + ( i_p << 2 ) ] += _rtB -> gknasrevhr [ ( i_p << 2 )
+ 2 ] * _rtB -> khjsuo3osc [ i + 8 ] ; _rtB -> aowa4p1gbt [ i + ( i_p << 2 )
] += _rtB -> gknasrevhr [ ( i_p << 2 ) + 3 ] * _rtB -> khjsuo3osc [ i + 12 ]
; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mywijktxdm [ 0 ] = _rtP ->
P_99 [ 0 ] ; _rtB -> mywijktxdm [ 1 ] = _rtP -> P_99 [ 1 ] ; _rtB ->
mywijktxdm [ 2 ] = _rtP -> P_99 [ 2 ] ; _rtB -> mywijktxdm [ 3 ] = _rtP ->
P_99 [ 3 ] ; } for ( i = 0 ; i < 4 ; i ++ ) { _rtB -> mklakgkhyt [ i ] = 0.0
; _rtB -> mklakgkhyt [ i ] += _rtB -> aowa4p1gbt [ i ] * _rtB -> mywijktxdm [
0 ] ; _rtB -> mklakgkhyt [ i ] += _rtB -> aowa4p1gbt [ i + 4 ] * _rtB ->
mywijktxdm [ 1 ] ; _rtB -> mklakgkhyt [ i ] += _rtB -> aowa4p1gbt [ i + 8 ] *
_rtB -> mywijktxdm [ 2 ] ; _rtB -> mklakgkhyt [ i ] += _rtB -> aowa4p1gbt [ i
+ 12 ] * _rtB -> mywijktxdm [ 3 ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
memcpy ( & _rtB -> cdnjjwztmj [ 0 ] , & _rtP -> P_100 [ 0 ] , sizeof ( real_T
) << 4U ) ; } ssCallAccelRunBlock ( S , 26 , 116 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 117 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> jbklaqyomj = _rtP -> P_101 ; } _rtB
-> ggylcarcl1 = _rtB -> gm5e5ghrph [ 11 ] - _rtB -> jbklaqyomj ;
ssCallAccelRunBlock ( S , 26 , 120 , SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i
< 4 ; i ++ ) { for ( i_p = 0 ; i_p < 4 ; i_p ++ ) { tmp [ i + ( i_p << 2 ) ]
= 0.0 ; tmp [ i + ( i_p << 2 ) ] += _rtB -> hs1xdxyoig [ i_p << 2 ] * _rtB ->
lwp4uclrtp [ i ] ; tmp [ i + ( i_p << 2 ) ] += _rtB -> hs1xdxyoig [ ( i_p <<
2 ) + 1 ] * _rtB -> lwp4uclrtp [ i + 4 ] ; tmp [ i + ( i_p << 2 ) ] += _rtB
-> hs1xdxyoig [ ( i_p << 2 ) + 2 ] * _rtB -> lwp4uclrtp [ i + 8 ] ; tmp [ i +
( i_p << 2 ) ] += _rtB -> hs1xdxyoig [ ( i_p << 2 ) + 3 ] * _rtB ->
lwp4uclrtp [ i + 12 ] ; } } for ( i = 0 ; i < 4 ; i ++ ) { for ( i_p = 0 ;
i_p < 4 ; i_p ++ ) { _rtB -> mylvu3jead [ i + ( i_p << 2 ) ] = 0.0 ; _rtB ->
mylvu3jead [ i + ( i_p << 2 ) ] += tmp [ i_p << 2 ] * _rtB -> bcqkkxsxtp [ i
] ; _rtB -> mylvu3jead [ i + ( i_p << 2 ) ] += tmp [ ( i_p << 2 ) + 1 ] *
_rtB -> bcqkkxsxtp [ i + 4 ] ; _rtB -> mylvu3jead [ i + ( i_p << 2 ) ] += tmp
[ ( i_p << 2 ) + 2 ] * _rtB -> bcqkkxsxtp [ i + 8 ] ; _rtB -> mylvu3jead [ i
+ ( i_p << 2 ) ] += tmp [ ( i_p << 2 ) + 3 ] * _rtB -> bcqkkxsxtp [ i + 12 ]
; } } for ( i = 0 ; i < 4 ; i ++ ) { for ( i_p = 0 ; i_p < 4 ; i_p ++ ) {
_rtB -> d11u1kmke3 [ i + ( i_p << 2 ) ] = 0.0 ; _rtB -> d11u1kmke3 [ i + (
i_p << 2 ) ] += _rtB -> mylvu3jead [ i_p << 2 ] * _rtB -> cdnjjwztmj [ i ] ;
_rtB -> d11u1kmke3 [ i + ( i_p << 2 ) ] += _rtB -> mylvu3jead [ ( i_p << 2 )
+ 1 ] * _rtB -> cdnjjwztmj [ i + 4 ] ; _rtB -> d11u1kmke3 [ i + ( i_p << 2 )
] += _rtB -> mylvu3jead [ ( i_p << 2 ) + 2 ] * _rtB -> cdnjjwztmj [ i + 8 ] ;
_rtB -> d11u1kmke3 [ i + ( i_p << 2 ) ] += _rtB -> mylvu3jead [ ( i_p << 2 )
+ 3 ] * _rtB -> cdnjjwztmj [ i + 12 ] ; } } for ( i = 0 ; i < 4 ; i ++ ) {
for ( i_p = 0 ; i_p < 4 ; i_p ++ ) { _rtB -> f5fhc3y0ph [ i + ( i_p << 2 ) ]
= 0.0 ; _rtB -> f5fhc3y0ph [ i + ( i_p << 2 ) ] += _rtB -> d11u1kmke3 [ i_p
<< 2 ] * _rtB -> khjsuo3osc [ i ] ; _rtB -> f5fhc3y0ph [ i + ( i_p << 2 ) ]
+= _rtB -> d11u1kmke3 [ ( i_p << 2 ) + 1 ] * _rtB -> khjsuo3osc [ i + 4 ] ;
_rtB -> f5fhc3y0ph [ i + ( i_p << 2 ) ] += _rtB -> d11u1kmke3 [ ( i_p << 2 )
+ 2 ] * _rtB -> khjsuo3osc [ i + 8 ] ; _rtB -> f5fhc3y0ph [ i + ( i_p << 2 )
] += _rtB -> d11u1kmke3 [ ( i_p << 2 ) + 3 ] * _rtB -> khjsuo3osc [ i + 12 ]
; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> jmlomzcuyp [ 0 ] = _rtP ->
P_102 [ 0 ] ; _rtB -> jmlomzcuyp [ 1 ] = _rtP -> P_102 [ 1 ] ; _rtB ->
jmlomzcuyp [ 2 ] = _rtP -> P_102 [ 2 ] ; _rtB -> jmlomzcuyp [ 3 ] = _rtP ->
P_102 [ 3 ] ; } for ( i = 0 ; i < 4 ; i ++ ) { _rtB -> fszvrnl3il [ i ] = 0.0
; _rtB -> fszvrnl3il [ i ] += _rtB -> f5fhc3y0ph [ i ] * _rtB -> jmlomzcuyp [
0 ] ; _rtB -> fszvrnl3il [ i ] += _rtB -> f5fhc3y0ph [ i + 4 ] * _rtB ->
jmlomzcuyp [ 1 ] ; _rtB -> fszvrnl3il [ i ] += _rtB -> f5fhc3y0ph [ i + 8 ] *
_rtB -> jmlomzcuyp [ 2 ] ; _rtB -> fszvrnl3il [ i ] += _rtB -> f5fhc3y0ph [ i
+ 12 ] * _rtB -> jmlomzcuyp [ 3 ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
memcpy ( & _rtB -> pjltbssr2i [ 0 ] , & _rtP -> P_103 [ 0 ] , sizeof ( real_T
) << 4U ) ; } ssCallAccelRunBlock ( S , 26 , 127 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 128 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mllmsy43ul = _rtP -> P_104 ; } _rtB
-> k4gob43t1x = _rtB -> gm5e5ghrph [ 14 ] - _rtB -> mllmsy43ul ;
ssCallAccelRunBlock ( S , 26 , 131 , SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i
< 4 ; i ++ ) { for ( i_p = 0 ; i_p < 4 ; i_p ++ ) { tmp [ i + ( i_p << 2 ) ]
= 0.0 ; tmp [ i + ( i_p << 2 ) ] += _rtB -> n2e4gzl0vx [ i_p << 2 ] * _rtB ->
lxv4fyeosb [ i ] ; tmp [ i + ( i_p << 2 ) ] += _rtB -> n2e4gzl0vx [ ( i_p <<
2 ) + 1 ] * _rtB -> lxv4fyeosb [ i + 4 ] ; tmp [ i + ( i_p << 2 ) ] += _rtB
-> n2e4gzl0vx [ ( i_p << 2 ) + 2 ] * _rtB -> lxv4fyeosb [ i + 8 ] ; tmp [ i +
( i_p << 2 ) ] += _rtB -> n2e4gzl0vx [ ( i_p << 2 ) + 3 ] * _rtB ->
lxv4fyeosb [ i + 12 ] ; } } for ( i = 0 ; i < 4 ; i ++ ) { for ( i_p = 0 ;
i_p < 4 ; i_p ++ ) { _rtB -> kyvnutapxx [ i + ( i_p << 2 ) ] = 0.0 ; _rtB ->
kyvnutapxx [ i + ( i_p << 2 ) ] += tmp [ i_p << 2 ] * _rtB -> a5z0kz5m3c [ i
] ; _rtB -> kyvnutapxx [ i + ( i_p << 2 ) ] += tmp [ ( i_p << 2 ) + 1 ] *
_rtB -> a5z0kz5m3c [ i + 4 ] ; _rtB -> kyvnutapxx [ i + ( i_p << 2 ) ] += tmp
[ ( i_p << 2 ) + 2 ] * _rtB -> a5z0kz5m3c [ i + 8 ] ; _rtB -> kyvnutapxx [ i
+ ( i_p << 2 ) ] += tmp [ ( i_p << 2 ) + 3 ] * _rtB -> a5z0kz5m3c [ i + 12 ]
; } } for ( i = 0 ; i < 4 ; i ++ ) { for ( i_p = 0 ; i_p < 4 ; i_p ++ ) {
_rtB -> lw5vez2oxy [ i + ( i_p << 2 ) ] = 0.0 ; _rtB -> lw5vez2oxy [ i + (
i_p << 2 ) ] += _rtB -> kyvnutapxx [ i_p << 2 ] * _rtB -> pjltbssr2i [ i ] ;
_rtB -> lw5vez2oxy [ i + ( i_p << 2 ) ] += _rtB -> kyvnutapxx [ ( i_p << 2 )
+ 1 ] * _rtB -> pjltbssr2i [ i + 4 ] ; _rtB -> lw5vez2oxy [ i + ( i_p << 2 )
] += _rtB -> kyvnutapxx [ ( i_p << 2 ) + 2 ] * _rtB -> pjltbssr2i [ i + 8 ] ;
_rtB -> lw5vez2oxy [ i + ( i_p << 2 ) ] += _rtB -> kyvnutapxx [ ( i_p << 2 )
+ 3 ] * _rtB -> pjltbssr2i [ i + 12 ] ; } } for ( i = 0 ; i < 4 ; i ++ ) {
for ( i_p = 0 ; i_p < 4 ; i_p ++ ) { _rtB -> fplk30c4uh [ i + ( i_p << 2 ) ]
= 0.0 ; _rtB -> fplk30c4uh [ i + ( i_p << 2 ) ] += _rtB -> lw5vez2oxy [ i_p
<< 2 ] * _rtB -> khjsuo3osc [ i ] ; _rtB -> fplk30c4uh [ i + ( i_p << 2 ) ]
+= _rtB -> lw5vez2oxy [ ( i_p << 2 ) + 1 ] * _rtB -> khjsuo3osc [ i + 4 ] ;
_rtB -> fplk30c4uh [ i + ( i_p << 2 ) ] += _rtB -> lw5vez2oxy [ ( i_p << 2 )
+ 2 ] * _rtB -> khjsuo3osc [ i + 8 ] ; _rtB -> fplk30c4uh [ i + ( i_p << 2 )
] += _rtB -> lw5vez2oxy [ ( i_p << 2 ) + 3 ] * _rtB -> khjsuo3osc [ i + 12 ]
; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ha0dhd55b0 [ 0 ] = _rtP ->
P_105 [ 0 ] ; _rtB -> ha0dhd55b0 [ 1 ] = _rtP -> P_105 [ 1 ] ; _rtB ->
ha0dhd55b0 [ 2 ] = _rtP -> P_105 [ 2 ] ; _rtB -> ha0dhd55b0 [ 3 ] = _rtP ->
P_105 [ 3 ] ; } for ( i = 0 ; i < 4 ; i ++ ) { _rtB -> cqmcdzes4r [ i ] = 0.0
; _rtB -> cqmcdzes4r [ i ] += _rtB -> fplk30c4uh [ i ] * _rtB -> ha0dhd55b0 [
0 ] ; _rtB -> cqmcdzes4r [ i ] += _rtB -> fplk30c4uh [ i + 4 ] * _rtB ->
ha0dhd55b0 [ 1 ] ; _rtB -> cqmcdzes4r [ i ] += _rtB -> fplk30c4uh [ i + 8 ] *
_rtB -> ha0dhd55b0 [ 2 ] ; _rtB -> cqmcdzes4r [ i ] += _rtB -> fplk30c4uh [ i
+ 12 ] * _rtB -> ha0dhd55b0 [ 3 ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
memcpy ( & _rtB -> oj332s3drl [ 0 ] , & _rtP -> P_106 [ 0 ] , sizeof ( real_T
) << 4U ) ; } ssCallAccelRunBlock ( S , 26 , 138 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 139 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> lf0furhods = _rtP -> P_107 ; } _rtB
-> i1xdbgo2td = _rtB -> gm5e5ghrph [ 17 ] - _rtB -> lf0furhods ;
ssCallAccelRunBlock ( S , 26 , 142 , SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i
< 4 ; i ++ ) { for ( i_p = 0 ; i_p < 4 ; i_p ++ ) { tmp [ i + ( i_p << 2 ) ]
= 0.0 ; tmp [ i + ( i_p << 2 ) ] += _rtB -> krkokhssz2 [ i_p << 2 ] * _rtB ->
kiw2a32gk2 [ i ] ; tmp [ i + ( i_p << 2 ) ] += _rtB -> krkokhssz2 [ ( i_p <<
2 ) + 1 ] * _rtB -> kiw2a32gk2 [ i + 4 ] ; tmp [ i + ( i_p << 2 ) ] += _rtB
-> krkokhssz2 [ ( i_p << 2 ) + 2 ] * _rtB -> kiw2a32gk2 [ i + 8 ] ; tmp [ i +
( i_p << 2 ) ] += _rtB -> krkokhssz2 [ ( i_p << 2 ) + 3 ] * _rtB ->
kiw2a32gk2 [ i + 12 ] ; } } for ( i = 0 ; i < 4 ; i ++ ) { for ( i_p = 0 ;
i_p < 4 ; i_p ++ ) { _rtB -> fhyyyytdi1 [ i + ( i_p << 2 ) ] = 0.0 ; _rtB ->
fhyyyytdi1 [ i + ( i_p << 2 ) ] += tmp [ i_p << 2 ] * _rtB -> ppih0koyw4 [ i
] ; _rtB -> fhyyyytdi1 [ i + ( i_p << 2 ) ] += tmp [ ( i_p << 2 ) + 1 ] *
_rtB -> ppih0koyw4 [ i + 4 ] ; _rtB -> fhyyyytdi1 [ i + ( i_p << 2 ) ] += tmp
[ ( i_p << 2 ) + 2 ] * _rtB -> ppih0koyw4 [ i + 8 ] ; _rtB -> fhyyyytdi1 [ i
+ ( i_p << 2 ) ] += tmp [ ( i_p << 2 ) + 3 ] * _rtB -> ppih0koyw4 [ i + 12 ]
; } } for ( i = 0 ; i < 4 ; i ++ ) { for ( i_p = 0 ; i_p < 4 ; i_p ++ ) {
_rtB -> lxwnilolrv [ i + ( i_p << 2 ) ] = 0.0 ; _rtB -> lxwnilolrv [ i + (
i_p << 2 ) ] += _rtB -> fhyyyytdi1 [ i_p << 2 ] * _rtB -> oj332s3drl [ i ] ;
_rtB -> lxwnilolrv [ i + ( i_p << 2 ) ] += _rtB -> fhyyyytdi1 [ ( i_p << 2 )
+ 1 ] * _rtB -> oj332s3drl [ i + 4 ] ; _rtB -> lxwnilolrv [ i + ( i_p << 2 )
] += _rtB -> fhyyyytdi1 [ ( i_p << 2 ) + 2 ] * _rtB -> oj332s3drl [ i + 8 ] ;
_rtB -> lxwnilolrv [ i + ( i_p << 2 ) ] += _rtB -> fhyyyytdi1 [ ( i_p << 2 )
+ 3 ] * _rtB -> oj332s3drl [ i + 12 ] ; } } for ( i = 0 ; i < 4 ; i ++ ) {
for ( i_p = 0 ; i_p < 4 ; i_p ++ ) { _rtB -> aoysdsjlzd [ i + ( i_p << 2 ) ]
= 0.0 ; _rtB -> aoysdsjlzd [ i + ( i_p << 2 ) ] += _rtB -> lxwnilolrv [ i_p
<< 2 ] * _rtB -> khjsuo3osc [ i ] ; _rtB -> aoysdsjlzd [ i + ( i_p << 2 ) ]
+= _rtB -> lxwnilolrv [ ( i_p << 2 ) + 1 ] * _rtB -> khjsuo3osc [ i + 4 ] ;
_rtB -> aoysdsjlzd [ i + ( i_p << 2 ) ] += _rtB -> lxwnilolrv [ ( i_p << 2 )
+ 2 ] * _rtB -> khjsuo3osc [ i + 8 ] ; _rtB -> aoysdsjlzd [ i + ( i_p << 2 )
] += _rtB -> lxwnilolrv [ ( i_p << 2 ) + 3 ] * _rtB -> khjsuo3osc [ i + 12 ]
; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> pwmdl5emnt [ 0 ] = _rtP ->
P_108 [ 0 ] ; _rtB -> pwmdl5emnt [ 1 ] = _rtP -> P_108 [ 1 ] ; _rtB ->
pwmdl5emnt [ 2 ] = _rtP -> P_108 [ 2 ] ; _rtB -> pwmdl5emnt [ 3 ] = _rtP ->
P_108 [ 3 ] ; } for ( i = 0 ; i < 4 ; i ++ ) { _rtB -> hewg4kivjw [ i ] = 0.0
; _rtB -> hewg4kivjw [ i ] += _rtB -> aoysdsjlzd [ i ] * _rtB -> pwmdl5emnt [
0 ] ; _rtB -> hewg4kivjw [ i ] += _rtB -> aoysdsjlzd [ i + 4 ] * _rtB ->
pwmdl5emnt [ 1 ] ; _rtB -> hewg4kivjw [ i ] += _rtB -> aoysdsjlzd [ i + 8 ] *
_rtB -> pwmdl5emnt [ 2 ] ; _rtB -> hewg4kivjw [ i ] += _rtB -> aoysdsjlzd [ i
+ 12 ] * _rtB -> pwmdl5emnt [ 3 ] ; } ssCallAccelRunBlock ( S , 26 , 148 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
ghnwuc0jar [ 0 ] = _rtP -> P_109 [ 0 ] ; _rtB -> ghnwuc0jar [ 1 ] = _rtP ->
P_109 [ 1 ] ; _rtB -> ghnwuc0jar [ 2 ] = _rtP -> P_109 [ 2 ] ; _rtB ->
ghnwuc0jar [ 3 ] = _rtP -> P_109 [ 3 ] ; } for ( i = 0 ; i < 4 ; i ++ ) {
_rtB -> mkcuhcsfxg [ i ] = 0.0 ; _rtB -> mkcuhcsfxg [ i ] += _rtB ->
bkagydprid [ i ] * _rtB -> ghnwuc0jar [ 0 ] ; _rtB -> mkcuhcsfxg [ i ] +=
_rtB -> bkagydprid [ i + 4 ] * _rtB -> ghnwuc0jar [ 1 ] ; _rtB -> mkcuhcsfxg
[ i ] += _rtB -> bkagydprid [ i + 8 ] * _rtB -> ghnwuc0jar [ 2 ] ; _rtB ->
mkcuhcsfxg [ i ] += _rtB -> bkagydprid [ i + 12 ] * _rtB -> ghnwuc0jar [ 3 ]
; } ssCallAccelRunBlock ( S , 26 , 151 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> he4n4am3yh [ 0 ] = _rtP -> P_110 [ 0
] ; _rtB -> he4n4am3yh [ 1 ] = _rtP -> P_110 [ 1 ] ; _rtB -> he4n4am3yh [ 2 ]
= _rtP -> P_110 [ 2 ] ; _rtB -> he4n4am3yh [ 3 ] = _rtP -> P_110 [ 3 ] ; }
for ( i = 0 ; i < 4 ; i ++ ) { _rtB -> luqrws0mtx [ i ] = 0.0 ; _rtB ->
luqrws0mtx [ i ] += _rtB -> lxwnilolrv [ i ] * _rtB -> he4n4am3yh [ 0 ] ;
_rtB -> luqrws0mtx [ i ] += _rtB -> lxwnilolrv [ i + 4 ] * _rtB -> he4n4am3yh
[ 1 ] ; _rtB -> luqrws0mtx [ i ] += _rtB -> lxwnilolrv [ i + 8 ] * _rtB ->
he4n4am3yh [ 2 ] ; _rtB -> luqrws0mtx [ i ] += _rtB -> lxwnilolrv [ i + 12 ]
* _rtB -> he4n4am3yh [ 3 ] ; } ssCallAccelRunBlock ( S , 26 , 154 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
j3wrdvdhvv [ 0 ] = _rtP -> P_111 [ 0 ] ; _rtB -> j3wrdvdhvv [ 1 ] = _rtP ->
P_111 [ 1 ] ; _rtB -> j3wrdvdhvv [ 2 ] = _rtP -> P_111 [ 2 ] ; _rtB ->
j3wrdvdhvv [ 3 ] = _rtP -> P_111 [ 3 ] ; } for ( i = 0 ; i < 4 ; i ++ ) {
_rtB -> mi0yut2dm0 [ i ] = 0.0 ; _rtB -> mi0yut2dm0 [ i ] += _rtB ->
jgvgvwcyhb [ i ] * _rtB -> j3wrdvdhvv [ 0 ] ; _rtB -> mi0yut2dm0 [ i ] +=
_rtB -> jgvgvwcyhb [ i + 4 ] * _rtB -> j3wrdvdhvv [ 1 ] ; _rtB -> mi0yut2dm0
[ i ] += _rtB -> jgvgvwcyhb [ i + 8 ] * _rtB -> j3wrdvdhvv [ 2 ] ; _rtB ->
mi0yut2dm0 [ i ] += _rtB -> jgvgvwcyhb [ i + 12 ] * _rtB -> j3wrdvdhvv [ 3 ]
; } ssCallAccelRunBlock ( S , 26 , 157 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> j5ubqrdbe0 [ 0 ] = _rtP -> P_112 [ 0
] ; _rtB -> j5ubqrdbe0 [ 1 ] = _rtP -> P_112 [ 1 ] ; _rtB -> j5ubqrdbe0 [ 2 ]
= _rtP -> P_112 [ 2 ] ; _rtB -> j5ubqrdbe0 [ 3 ] = _rtP -> P_112 [ 3 ] ; }
for ( i = 0 ; i < 4 ; i ++ ) { _rtB -> jdvqhawtbv [ i ] = 0.0 ; _rtB ->
jdvqhawtbv [ i ] += _rtB -> gknasrevhr [ i ] * _rtB -> j5ubqrdbe0 [ 0 ] ;
_rtB -> jdvqhawtbv [ i ] += _rtB -> gknasrevhr [ i + 4 ] * _rtB -> j5ubqrdbe0
[ 1 ] ; _rtB -> jdvqhawtbv [ i ] += _rtB -> gknasrevhr [ i + 8 ] * _rtB ->
j5ubqrdbe0 [ 2 ] ; _rtB -> jdvqhawtbv [ i ] += _rtB -> gknasrevhr [ i + 12 ]
* _rtB -> j5ubqrdbe0 [ 3 ] ; } ssCallAccelRunBlock ( S , 26 , 160 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
bdiifzo5vs [ 0 ] = _rtP -> P_113 [ 0 ] ; _rtB -> bdiifzo5vs [ 1 ] = _rtP ->
P_113 [ 1 ] ; _rtB -> bdiifzo5vs [ 2 ] = _rtP -> P_113 [ 2 ] ; _rtB ->
bdiifzo5vs [ 3 ] = _rtP -> P_113 [ 3 ] ; } for ( i = 0 ; i < 4 ; i ++ ) {
_rtB -> drbh1gihd3 [ i ] = 0.0 ; _rtB -> drbh1gihd3 [ i ] += _rtB ->
d11u1kmke3 [ i ] * _rtB -> bdiifzo5vs [ 0 ] ; _rtB -> drbh1gihd3 [ i ] +=
_rtB -> d11u1kmke3 [ i + 4 ] * _rtB -> bdiifzo5vs [ 1 ] ; _rtB -> drbh1gihd3
[ i ] += _rtB -> d11u1kmke3 [ i + 8 ] * _rtB -> bdiifzo5vs [ 2 ] ; _rtB ->
drbh1gihd3 [ i ] += _rtB -> d11u1kmke3 [ i + 12 ] * _rtB -> bdiifzo5vs [ 3 ]
; } ssCallAccelRunBlock ( S , 26 , 163 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> hjoxqvkzh2 [ 0 ] = _rtP -> P_114 [ 0
] ; _rtB -> hjoxqvkzh2 [ 1 ] = _rtP -> P_114 [ 1 ] ; _rtB -> hjoxqvkzh2 [ 2 ]
= _rtP -> P_114 [ 2 ] ; _rtB -> hjoxqvkzh2 [ 3 ] = _rtP -> P_114 [ 3 ] ; }
for ( i = 0 ; i < 4 ; i ++ ) { _rtB -> dtsnskdtml [ i ] = 0.0 ; _rtB ->
dtsnskdtml [ i ] += _rtB -> lw5vez2oxy [ i ] * _rtB -> hjoxqvkzh2 [ 0 ] ;
_rtB -> dtsnskdtml [ i ] += _rtB -> lw5vez2oxy [ i + 4 ] * _rtB -> hjoxqvkzh2
[ 1 ] ; _rtB -> dtsnskdtml [ i ] += _rtB -> lw5vez2oxy [ i + 8 ] * _rtB ->
hjoxqvkzh2 [ 2 ] ; _rtB -> dtsnskdtml [ i ] += _rtB -> lw5vez2oxy [ i + 12 ]
* _rtB -> hjoxqvkzh2 [ 3 ] ; } ssCallAccelRunBlock ( S , 26 , 166 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 167 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> n2b4t5qkih = _rtP -> P_115 * _rtB ->
gm5e5ghrph [ 52 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> iddqtyp3nj = (
_rtB -> n2b4t5qkih >= 0.0 ) ; } _rtB -> krl0rvqgpa = _rtDW -> iddqtyp3nj > 0
? _rtB -> n2b4t5qkih : - _rtB -> n2b4t5qkih ; _rtB -> bt3v1dlnor = _rtP ->
P_116 * _rtB -> gm5e5ghrph [ 53 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
cwrz0rwrw4 = ( _rtB -> bt3v1dlnor >= 0.0 ) ; } _rtB -> fh4vof1q4k = _rtDW ->
cwrz0rwrw4 > 0 ? _rtB -> bt3v1dlnor : - _rtB -> bt3v1dlnor ; rtPrevAction =
_rtDW -> lpfhrsacdg ; if ( ssIsMajorTimeStep ( S ) ) { rtAction = ( int8_T )
! ( ( _rtB -> krl0rvqgpa < 4.0 ) && ( _rtB -> fh4vof1q4k < 1.0 ) ) ; _rtDW ->
lpfhrsacdg = rtAction ; } else { rtAction = _rtDW -> lpfhrsacdg ; } if (
rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0 : oogbjkhpvp (
S ) ; break ; case 1 : ssSetSolverNeedsReset ( S ) ; break ; } } switch (
rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { gg1bfsp2im ( S ) ; }
na1jczuzfj ( S , _rtB -> gm5e5ghrph [ 52 ] , _rtB -> gm5e5ghrph [ 53 ] , _rtB
-> gm5e5ghrph [ 54 ] , _rtB -> gm5e5ghrph [ 57 ] , & _rtB -> gm5e5ghrph [ 41
] , _rtB -> gm5e5ghrph [ 50 ] , _rtB -> gm5e5ghrph [ 51 ] , _rtB ->
gm5e5ghrph [ 55 ] , _rtB -> gm5e5ghrph [ 56 ] , _rtB -> ndlpykuox4 , & _rtB
-> na1jczuzfju , & _rtDW -> na1jczuzfju , ( nuymkaafal * ) & _rtP ->
na1jczuzfju ) ; if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
na1jczuzfju . lavjhvwnyp ) ; } break ; case 1 : if ( rtAction != rtPrevAction
) { if ( ssGetTaskTime ( S , 0 ) != ssGetTStart ( S ) ) {
ssSetSolverNeedsReset ( S ) ; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { memcpy
( & _rtB -> ndlpykuox4 [ 0 ] , & _rtP -> P_17 [ 0 ] , 12U * sizeof ( real_T )
) ; } if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> gmffrkcsqj ) ; }
break ; } ssCallAccelRunBlock ( S , 26 , 175 , SS_CALL_MDL_OUTPUTS ) ; _rtB
-> dl5hplbqw5 = _rtP -> P_117 * _rtB -> gm5e5ghrph [ 69 ] ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> lorob5ix2t = ( _rtB -> dl5hplbqw5 >= 0.0
) ; } _rtB -> ojw4smlies = _rtDW -> lorob5ix2t > 0 ? _rtB -> dl5hplbqw5 : -
_rtB -> dl5hplbqw5 ; _rtB -> dind2uaenb = _rtP -> P_118 * _rtB -> gm5e5ghrph
[ 70 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> ccvo3pp0zm = ( _rtB ->
dind2uaenb >= 0.0 ) ; } _rtB -> aiqdmb44iz = _rtDW -> ccvo3pp0zm > 0 ? _rtB
-> dind2uaenb : - _rtB -> dind2uaenb ; rtPrevAction = _rtDW -> ltptzi1mym ;
if ( ssIsMajorTimeStep ( S ) ) { rtAction = ( int8_T ) ! ( ( _rtB ->
ojw4smlies < 4.0 ) && ( _rtB -> aiqdmb44iz < 1.0 ) ) ; _rtDW -> ltptzi1mym =
rtAction ; } else { rtAction = _rtDW -> ltptzi1mym ; } if ( rtPrevAction !=
rtAction ) { switch ( rtPrevAction ) { case 0 : oogbjkhpvp ( S ) ; break ;
case 1 : ssSetSolverNeedsReset ( S ) ; break ; } } switch ( rtAction ) { case
0 : if ( rtAction != rtPrevAction ) { gg1bfsp2im ( S ) ; } na1jczuzfj ( S ,
_rtB -> gm5e5ghrph [ 69 ] , _rtB -> gm5e5ghrph [ 70 ] , _rtB -> gm5e5ghrph [
71 ] , _rtB -> gm5e5ghrph [ 74 ] , & _rtB -> gm5e5ghrph [ 58 ] , _rtB ->
gm5e5ghrph [ 67 ] , _rtB -> gm5e5ghrph [ 68 ] , _rtB -> gm5e5ghrph [ 72 ] ,
_rtB -> gm5e5ghrph [ 73 ] , _rtB -> jwxbhz1f5w , & _rtB -> mqod2hqw1t , &
_rtDW -> mqod2hqw1t , ( nuymkaafal * ) & _rtP -> mqod2hqw1t ) ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> mqod2hqw1t . lavjhvwnyp ) ;
} break ; case 1 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S ,
0 ) != ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } } if (
ssIsSampleHit ( S , 1 , 0 ) ) { memcpy ( & _rtB -> jwxbhz1f5w [ 0 ] , & _rtP
-> P_18 [ 0 ] , 12U * sizeof ( real_T ) ) ; } if ( ssIsMajorTimeStep ( S ) )
{ srUpdateBC ( _rtDW -> p5vzqjpwcj ) ; } break ; } ssCallAccelRunBlock ( S ,
26 , 183 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> ofgjid40wp = _rtP -> P_119 * _rtB
-> gm5e5ghrph [ 86 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> hyhnxylquf =
( _rtB -> ofgjid40wp >= 0.0 ) ; } _rtB -> l1ujllkjwm = _rtDW -> hyhnxylquf >
0 ? _rtB -> ofgjid40wp : - _rtB -> ofgjid40wp ; _rtB -> p1bdslpw4i = _rtP ->
P_120 * _rtB -> gm5e5ghrph [ 87 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
gkv5vj1acy = ( _rtB -> p1bdslpw4i >= 0.0 ) ; } _rtB -> okhmrtyj2b = _rtDW ->
gkv5vj1acy > 0 ? _rtB -> p1bdslpw4i : - _rtB -> p1bdslpw4i ; rtPrevAction =
_rtDW -> omvzilo3wu ; if ( ssIsMajorTimeStep ( S ) ) { rtAction = ( int8_T )
! ( ( _rtB -> l1ujllkjwm < 4.0 ) && ( _rtB -> okhmrtyj2b < 1.0 ) ) ; _rtDW ->
omvzilo3wu = rtAction ; } else { rtAction = _rtDW -> omvzilo3wu ; } if (
rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0 : oogbjkhpvp (
S ) ; break ; case 1 : ssSetSolverNeedsReset ( S ) ; break ; } } switch (
rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { gg1bfsp2im ( S ) ; }
na1jczuzfj ( S , _rtB -> gm5e5ghrph [ 86 ] , _rtB -> gm5e5ghrph [ 87 ] , _rtB
-> gm5e5ghrph [ 88 ] , _rtB -> gm5e5ghrph [ 91 ] , & _rtB -> gm5e5ghrph [ 75
] , _rtB -> gm5e5ghrph [ 84 ] , _rtB -> gm5e5ghrph [ 85 ] , _rtB ->
gm5e5ghrph [ 89 ] , _rtB -> gm5e5ghrph [ 90 ] , _rtB -> i2qp0tjdl2 , & _rtB
-> ciiustz54e , & _rtDW -> ciiustz54e , ( nuymkaafal * ) & _rtP -> ciiustz54e
) ; if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> ciiustz54e .
lavjhvwnyp ) ; } break ; case 1 : if ( rtAction != rtPrevAction ) { if (
ssGetTaskTime ( S , 0 ) != ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S )
; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { memcpy ( & _rtB -> i2qp0tjdl2 [ 0
] , & _rtP -> P_19 [ 0 ] , 12U * sizeof ( real_T ) ) ; } if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> b0hpv5lemh ) ; } break ; }
ssCallAccelRunBlock ( S , 26 , 191 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
caqymvlmdq = _rtP -> P_121 * _rtB -> gm5e5ghrph [ 103 ] ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> kz2yjlbzan = ( _rtB -> caqymvlmdq >= 0.0
) ; } _rtB -> j4z3scridc = _rtDW -> kz2yjlbzan > 0 ? _rtB -> caqymvlmdq : -
_rtB -> caqymvlmdq ; _rtB -> kf2ucwxo3i = _rtP -> P_122 * _rtB -> gm5e5ghrph
[ 104 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> e1zvqfeeju = ( _rtB ->
kf2ucwxo3i >= 0.0 ) ; } _rtB -> mmbxsshdvn = _rtDW -> e1zvqfeeju > 0 ? _rtB
-> kf2ucwxo3i : - _rtB -> kf2ucwxo3i ; rtPrevAction = _rtDW -> ij53yycoh0 ;
if ( ssIsMajorTimeStep ( S ) ) { rtAction = ( int8_T ) ! ( ( _rtB ->
j4z3scridc < 4.0 ) && ( _rtB -> mmbxsshdvn < 1.0 ) ) ; _rtDW -> ij53yycoh0 =
rtAction ; } else { rtAction = _rtDW -> ij53yycoh0 ; } if ( rtPrevAction !=
rtAction ) { switch ( rtPrevAction ) { case 0 : oogbjkhpvp ( S ) ; break ;
case 1 : ssSetSolverNeedsReset ( S ) ; break ; } } switch ( rtAction ) { case
0 : if ( rtAction != rtPrevAction ) { gg1bfsp2im ( S ) ; } na1jczuzfj ( S ,
_rtB -> gm5e5ghrph [ 103 ] , _rtB -> gm5e5ghrph [ 104 ] , _rtB -> gm5e5ghrph
[ 105 ] , _rtB -> gm5e5ghrph [ 108 ] , & _rtB -> gm5e5ghrph [ 92 ] , _rtB ->
gm5e5ghrph [ 101 ] , _rtB -> gm5e5ghrph [ 102 ] , _rtB -> gm5e5ghrph [ 106 ]
, _rtB -> gm5e5ghrph [ 107 ] , _rtB -> hadnru0wsf , & _rtB -> aiyffyrf0x , &
_rtDW -> aiyffyrf0x , ( nuymkaafal * ) & _rtP -> aiyffyrf0x ) ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> aiyffyrf0x . lavjhvwnyp ) ;
} break ; case 1 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S ,
0 ) != ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } } if (
ssIsSampleHit ( S , 1 , 0 ) ) { memcpy ( & _rtB -> hadnru0wsf [ 0 ] , & _rtP
-> P_20 [ 0 ] , 12U * sizeof ( real_T ) ) ; } if ( ssIsMajorTimeStep ( S ) )
{ srUpdateBC ( _rtDW -> buczmbj5iq ) ; } break ; } ssCallAccelRunBlock ( S ,
26 , 199 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> ic2fzqpr5w = _rtP -> P_123 * _rtB
-> gm5e5ghrph [ 120 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> c4t2wh0glc
= ( _rtB -> ic2fzqpr5w >= 0.0 ) ; } _rtB -> eqgqiyei4y = _rtDW -> c4t2wh0glc
> 0 ? _rtB -> ic2fzqpr5w : - _rtB -> ic2fzqpr5w ; _rtB -> fxxftdxvue = _rtP
-> P_124 * _rtB -> gm5e5ghrph [ 121 ] ; if ( ssIsMajorTimeStep ( S ) ) {
_rtDW -> enxktzkbf5 = ( _rtB -> fxxftdxvue >= 0.0 ) ; } _rtB -> bwzybpg4rs =
_rtDW -> enxktzkbf5 > 0 ? _rtB -> fxxftdxvue : - _rtB -> fxxftdxvue ;
rtPrevAction = _rtDW -> m4a5pybsb3 ; if ( ssIsMajorTimeStep ( S ) ) {
rtAction = ( int8_T ) ! ( ( _rtB -> eqgqiyei4y < 4.0 ) && ( _rtB ->
bwzybpg4rs < 1.0 ) ) ; _rtDW -> m4a5pybsb3 = rtAction ; } else { rtAction =
_rtDW -> m4a5pybsb3 ; } if ( rtPrevAction != rtAction ) { switch (
rtPrevAction ) { case 0 : oogbjkhpvp ( S ) ; break ; case 1 :
ssSetSolverNeedsReset ( S ) ; break ; } } switch ( rtAction ) { case 0 : if (
rtAction != rtPrevAction ) { gg1bfsp2im ( S ) ; } na1jczuzfj ( S , _rtB ->
gm5e5ghrph [ 120 ] , _rtB -> gm5e5ghrph [ 121 ] , _rtB -> gm5e5ghrph [ 122 ]
, _rtB -> gm5e5ghrph [ 125 ] , & _rtB -> gm5e5ghrph [ 109 ] , _rtB ->
gm5e5ghrph [ 118 ] , _rtB -> gm5e5ghrph [ 119 ] , _rtB -> gm5e5ghrph [ 123 ]
, _rtB -> gm5e5ghrph [ 124 ] , _rtB -> lsebfabbei , & _rtB -> ogmpawilnd , &
_rtDW -> ogmpawilnd , ( nuymkaafal * ) & _rtP -> ogmpawilnd ) ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> ogmpawilnd . lavjhvwnyp ) ;
} break ; case 1 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S ,
0 ) != ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } } if (
ssIsSampleHit ( S , 1 , 0 ) ) { memcpy ( & _rtB -> lsebfabbei [ 0 ] , & _rtP
-> P_21 [ 0 ] , 12U * sizeof ( real_T ) ) ; } if ( ssIsMajorTimeStep ( S ) )
{ srUpdateBC ( _rtDW -> jlg5tcm5l0 ) ; } break ; } ssCallAccelRunBlock ( S ,
26 , 207 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> prqxdyfyh2 = _rtP -> P_125 * _rtB
-> gm5e5ghrph [ 137 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> b0i0ovssui
= ( _rtB -> prqxdyfyh2 >= 0.0 ) ; } _rtB -> gwsiifvsss = _rtDW -> b0i0ovssui
> 0 ? _rtB -> prqxdyfyh2 : - _rtB -> prqxdyfyh2 ; _rtB -> dzd2ploozm = _rtP
-> P_126 * _rtB -> gm5e5ghrph [ 138 ] ; if ( ssIsMajorTimeStep ( S ) ) {
_rtDW -> dksnvohwhd = ( _rtB -> dzd2ploozm >= 0.0 ) ; } _rtB -> aff0hhixvp =
_rtDW -> dksnvohwhd > 0 ? _rtB -> dzd2ploozm : - _rtB -> dzd2ploozm ;
rtPrevAction = _rtDW -> kgstnambvp ; if ( ssIsMajorTimeStep ( S ) ) {
rtAction = ( int8_T ) ! ( ( _rtB -> gwsiifvsss < 4.0 ) && ( _rtB ->
aff0hhixvp < 1.0 ) ) ; _rtDW -> kgstnambvp = rtAction ; } else { rtAction =
_rtDW -> kgstnambvp ; } if ( rtPrevAction != rtAction ) { switch (
rtPrevAction ) { case 0 : oogbjkhpvp ( S ) ; break ; case 1 :
ssSetSolverNeedsReset ( S ) ; break ; } } switch ( rtAction ) { case 0 : if (
rtAction != rtPrevAction ) { gg1bfsp2im ( S ) ; } na1jczuzfj ( S , _rtB ->
gm5e5ghrph [ 137 ] , _rtB -> gm5e5ghrph [ 138 ] , _rtB -> gm5e5ghrph [ 139 ]
, _rtB -> gm5e5ghrph [ 142 ] , & _rtB -> gm5e5ghrph [ 126 ] , _rtB ->
gm5e5ghrph [ 135 ] , _rtB -> gm5e5ghrph [ 136 ] , _rtB -> gm5e5ghrph [ 140 ]
, _rtB -> gm5e5ghrph [ 141 ] , _rtB -> fuy0b2wi3g , & _rtB -> gibf3zurdd , &
_rtDW -> gibf3zurdd , ( nuymkaafal * ) & _rtP -> gibf3zurdd ) ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> gibf3zurdd . lavjhvwnyp ) ;
} break ; case 1 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S ,
0 ) != ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } } if (
ssIsSampleHit ( S , 1 , 0 ) ) { memcpy ( & _rtB -> fuy0b2wi3g [ 0 ] , & _rtP
-> P_22 [ 0 ] , 12U * sizeof ( real_T ) ) ; } if ( ssIsMajorTimeStep ( S ) )
{ srUpdateBC ( _rtDW -> jghnbpit2v ) ; } break ; } ssCallAccelRunBlock ( S ,
26 , 215 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 216 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 217 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 218 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 219 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 220 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 221 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 222 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 2 , 0 ) ) { it4zcb31j5 =
_rtDW -> kymelibeuf ; _rtB -> ccs3nmxgox = look1_binlcpw ( ( real_T ) _rtDW
-> kymelibeuf * _rtP -> P_127 , _rtP -> P_129 , _rtP -> P_128 , 5U ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mooukgcgde = _rtP -> P_130 ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { kpy4amgi3w = _rtDW -> l2aowypwq0 ; _rtB ->
bdmq1xuozt = look1_binlcpw ( ( real_T ) _rtDW -> l2aowypwq0 * _rtP -> P_131 ,
_rtP -> P_133 , _rtP -> P_132 , 5U ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 26 , 232 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 26 , 233 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 234 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 235 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> lccnjlbmdc = _rtP -> P_134 ; } _rtB
-> easygxnnnn = ssGetT ( S ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
nzn4q1sbb3 = _rtP -> P_135 ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
prajlf1mwj = ( _rtB -> easygxnnnn <= _rtB -> nzn4q1sbb3 ) ; } _rtB ->
jq13yil0pc = _rtDW -> prajlf1mwj ; } if ( _rtB -> jq13yil0pc ) { _rtB ->
f5gxbasaq5 [ 0 ] = _rtB -> lccnjlbmdc ; _rtB -> f5gxbasaq5 [ 1 ] = _rtB ->
lccnjlbmdc ; _rtB -> f5gxbasaq5 [ 2 ] = _rtB -> lccnjlbmdc ; } else { _rtB ->
f5gxbasaq5 [ 0 ] = _rtB -> gm5e5ghrph [ 18 ] ; _rtB -> f5gxbasaq5 [ 1 ] =
_rtB -> gm5e5ghrph [ 19 ] ; _rtB -> f5gxbasaq5 [ 2 ] = _rtB -> gm5e5ghrph [
20 ] ; } ssCallAccelRunBlock ( S , 26 , 241 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 242 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 243 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 244 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 245 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 246 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 247 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 248 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 249 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 250 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 251 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 252 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 253 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 254 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 255 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 256 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 257 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 258 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 259 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 260 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 261 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { it4zcb31j5 = (
uint8_T ) ( ( uint32_T ) it4zcb31j5 + _rtP -> P_459 ) ; if ( it4zcb31j5 >
_rtP -> P_460 ) { _rtB -> ebetrw30ln = _rtP -> P_445 ; } else { _rtB ->
ebetrw30ln = it4zcb31j5 ; } kpy4amgi3w = ( uint8_T ) ( ( uint32_T )
kpy4amgi3w + _rtP -> P_461 ) ; if ( kpy4amgi3w > _rtP -> P_462 ) { _rtB ->
duujqdjx4c = _rtP -> P_446 ; } else { _rtB -> duujqdjx4c = kpy4amgi3w ; }
aw0su3bro5 = _rtDW -> b2cjgliafe ; _rtB -> no1bvtpfyo = look1_binlcpw ( (
real_T ) _rtDW -> b2cjgliafe * _rtP -> P_136 , _rtP -> P_138 , _rtP -> P_137
, 5U ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mooukgcgde = _rtP ->
P_139 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { kpy4amgi3w = _rtDW ->
ehbsveshkm ; _rtB -> agcmg3fq0i = look1_binlcpw ( ( real_T ) _rtDW ->
ehbsveshkm * _rtP -> P_140 , _rtP -> P_142 , _rtP -> P_141 , 5U ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 279 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 280 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { aw0su3bro5 = (
uint8_T ) ( ( uint32_T ) aw0su3bro5 + _rtP -> P_465 ) ; if ( aw0su3bro5 >
_rtP -> P_466 ) { _rtB -> hfi2k0sruc = _rtP -> P_447 ; } else { _rtB ->
hfi2k0sruc = aw0su3bro5 ; } kpy4amgi3w = ( uint8_T ) ( ( uint32_T )
kpy4amgi3w + _rtP -> P_467 ) ; if ( kpy4amgi3w > _rtP -> P_468 ) { _rtB ->
bmipz2yvhp = _rtP -> P_448 ; } else { _rtB -> bmipz2yvhp = kpy4amgi3w ; }
aw0su3bro5 = _rtDW -> hvyhvsvapr ; _rtB -> hhace30tdq = look1_binlcpw ( (
real_T ) _rtDW -> hvyhvsvapr * _rtP -> P_143 , _rtP -> P_145 , _rtP -> P_144
, 5U ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mooukgcgde = _rtP ->
P_146 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { kpy4amgi3w = _rtDW ->
mw535gip5g ; _rtB -> ljvzmzscjq = look1_binlcpw ( ( real_T ) _rtDW ->
mw535gip5g * _rtP -> P_147 , _rtP -> P_149 , _rtP -> P_148 , 5U ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 298 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 299 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { aw0su3bro5 = (
uint8_T ) ( ( uint32_T ) aw0su3bro5 + _rtP -> P_471 ) ; if ( aw0su3bro5 >
_rtP -> P_472 ) { _rtB -> nmyb20ug1b = _rtP -> P_449 ; } else { _rtB ->
nmyb20ug1b = aw0su3bro5 ; } kpy4amgi3w = ( uint8_T ) ( ( uint32_T )
kpy4amgi3w + _rtP -> P_473 ) ; if ( kpy4amgi3w > _rtP -> P_474 ) { _rtB ->
pqogctc0aj = _rtP -> P_450 ; } else { _rtB -> pqogctc0aj = kpy4amgi3w ; }
aw0su3bro5 = _rtDW -> apnwvehbxl ; _rtB -> h1kawruiqg = look1_binlcpw ( (
real_T ) _rtDW -> apnwvehbxl * _rtP -> P_150 , _rtP -> P_152 , _rtP -> P_151
, 5U ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mooukgcgde = _rtP ->
P_153 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { kpy4amgi3w = _rtDW ->
ftvhungduu ; _rtB -> pkvyt15lla = look1_binlcpw ( ( real_T ) _rtDW ->
ftvhungduu * _rtP -> P_154 , _rtP -> P_156 , _rtP -> P_155 , 5U ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 317 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 318 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { aw0su3bro5 = (
uint8_T ) ( ( uint32_T ) aw0su3bro5 + _rtP -> P_477 ) ; if ( aw0su3bro5 >
_rtP -> P_478 ) { _rtB -> plpjudsfzo = _rtP -> P_451 ; } else { _rtB ->
plpjudsfzo = aw0su3bro5 ; } kpy4amgi3w = ( uint8_T ) ( ( uint32_T )
kpy4amgi3w + _rtP -> P_479 ) ; if ( kpy4amgi3w > _rtP -> P_480 ) { _rtB ->
ecpdchnh0s = _rtP -> P_452 ; } else { _rtB -> ecpdchnh0s = kpy4amgi3w ; }
aw0su3bro5 = _rtDW -> jkuohcbhwi ; _rtB -> hvoitmbuxr = look1_binlcpw ( (
real_T ) _rtDW -> jkuohcbhwi * _rtP -> P_157 , _rtP -> P_159 , _rtP -> P_158
, 5U ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mooukgcgde = _rtP ->
P_160 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { kpy4amgi3w = _rtDW ->
lidex5nqky ; _rtB -> pgpp5h1v2i = look1_binlcpw ( ( real_T ) _rtDW ->
lidex5nqky * _rtP -> P_161 , _rtP -> P_163 , _rtP -> P_162 , 5U ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 336 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 337 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { aw0su3bro5 = (
uint8_T ) ( ( uint32_T ) aw0su3bro5 + _rtP -> P_483 ) ; if ( aw0su3bro5 >
_rtP -> P_484 ) { _rtB -> ox1jrxk1x1 = _rtP -> P_453 ; } else { _rtB ->
ox1jrxk1x1 = aw0su3bro5 ; } kpy4amgi3w = ( uint8_T ) ( ( uint32_T )
kpy4amgi3w + _rtP -> P_485 ) ; if ( kpy4amgi3w > _rtP -> P_486 ) { _rtB ->
eb5slduxsz = _rtP -> P_454 ; } else { _rtB -> eb5slduxsz = kpy4amgi3w ; }
aw0su3bro5 = _rtDW -> drqejj3y2z ; _rtB -> dzogryqg3l = look1_binlcpw ( (
real_T ) _rtDW -> drqejj3y2z * _rtP -> P_164 , _rtP -> P_166 , _rtP -> P_165
, 5U ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mooukgcgde = _rtP ->
P_167 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { kpy4amgi3w = _rtDW ->
ce5tye3xvi ; _rtB -> htkssjppyj = look1_binlcpw ( ( real_T ) _rtDW ->
ce5tye3xvi * _rtP -> P_168 , _rtP -> P_170 , _rtP -> P_169 , 5U ) ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 355 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 356 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { aw0su3bro5 = (
uint8_T ) ( ( uint32_T ) aw0su3bro5 + _rtP -> P_489 ) ; if ( aw0su3bro5 >
_rtP -> P_490 ) { _rtB -> benv3yrtmp = _rtP -> P_455 ; } else { _rtB ->
benv3yrtmp = aw0su3bro5 ; } kpy4amgi3w = ( uint8_T ) ( ( uint32_T )
kpy4amgi3w + _rtP -> P_491 ) ; if ( kpy4amgi3w > _rtP -> P_492 ) { _rtB ->
ifimttgx4a = _rtP -> P_456 ; } else { _rtB -> ifimttgx4a = kpy4amgi3w ; } }
_rtB -> h04nuywjcn = _rtP -> P_171 * _rtB -> gm5e5ghrph [ 21 ] ; _rtB ->
guih2ongku = _rtP -> P_172 * _rtB -> gm5e5ghrph [ 23 ] ; ssCallAccelRunBlock
( S , 26 , 370 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> p2aqiuarmj = _rtP -> P_173 *
_rtB -> gm5e5ghrph [ 35 ] ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
phvzb0suex = ( _rtB -> p2aqiuarmj >= 0.0 ) ; } _rtB -> mof0z5zbuk = _rtDW ->
phvzb0suex > 0 ? _rtB -> p2aqiuarmj : - _rtB -> p2aqiuarmj ; _rtB ->
h1r4x5wbvt = _rtP -> P_174 * _rtB -> gm5e5ghrph [ 36 ] ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> bklnvxg1g2 = ( _rtB -> h1r4x5wbvt >= 0.0
) ; } _rtB -> lbkrnv0eqq = _rtDW -> bklnvxg1g2 > 0 ? _rtB -> h1r4x5wbvt : -
_rtB -> h1r4x5wbvt ; rtPrevAction = _rtDW -> fj23pr2tgi ; if (
ssIsMajorTimeStep ( S ) ) { rtAction = ( int8_T ) ! ( ( _rtB -> mof0z5zbuk <
10.0 ) && ( _rtB -> lbkrnv0eqq < 1.0 ) ) ; _rtDW -> fj23pr2tgi = rtAction ; }
else { rtAction = _rtDW -> fj23pr2tgi ; } if ( rtPrevAction != rtAction ) {
switch ( rtPrevAction ) { case 0 : ssSetSolverNeedsReset ( S ) ; break ; case
1 : ssSetSolverNeedsReset ( S ) ; break ; } } switch ( rtAction ) { case 0 :
if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) != ssGetTStart
( S ) ) { ssSetSolverNeedsReset ( S ) ; } } _rtB -> pqzhct5mba =
muDoubleScalarAbs ( _rtB -> gm5e5ghrph [ 37 ] ) ; if ( ssIsSampleHit ( S , 1
, 0 ) ) { _rtB -> gskxfjsrla = _rtP -> P_1 ; } _rtB -> fc51keidwe = _rtB ->
gskxfjsrla - _rtB -> pqzhct5mba ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtB
-> fc51keidwe > _rtP -> P_3 ) { _rtDW -> nowqk5vjl3 = 1 ; } else if ( _rtB ->
fc51keidwe >= _rtP -> P_2 ) { _rtDW -> nowqk5vjl3 = 0 ; } else { _rtDW ->
nowqk5vjl3 = - 1 ; } } if ( _rtDW -> nowqk5vjl3 == 1 ) { _rtB -> mpil5blyi5 =
_rtB -> fc51keidwe - _rtP -> P_3 ; } else if ( _rtDW -> nowqk5vjl3 == - 1 ) {
_rtB -> mpil5blyi5 = _rtB -> fc51keidwe - _rtP -> P_2 ; } else { _rtB ->
mpil5blyi5 = 0.0 ; } _rtB -> g1vh3txmut = muDoubleScalarSign ( _rtB ->
gm5e5ghrph [ 37 ] ) ; _rtB -> aetmpurpjg = _rtB -> g1vh3txmut * _rtB ->
gm5e5ghrph [ 40 ] ; _rtB -> csgrq3h5qf = _rtP -> P_4 * _rtB -> aetmpurpjg ;
_rtB -> pi4ewu2pq0 = muDoubleScalarSign ( _rtB -> gm5e5ghrph [ 40 ] ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> p0mjonhooj = _rtP -> P_5 ; } _rtB ->
c133dk20b3 = _rtP -> P_6 * _rtB -> mpil5blyi5 ; _rtB -> g4f1o5ef5r = _rtB ->
g1vh3txmut * _rtB -> c133dk20b3 ; _rtB -> griwklx5wt = muDoubleScalarSign (
_rtB -> mpil5blyi5 ) ; _rtB -> dmwckndsfm = muDoubleScalarAbs ( _rtB ->
griwklx5wt ) ; if ( _rtB -> csgrq3h5qf > _rtP -> P_7 ) { _rtB -> gvybz5pid1 =
_rtP -> P_7 ; } else if ( _rtB -> csgrq3h5qf < _rtP -> P_8 ) { _rtB ->
gvybz5pid1 = _rtP -> P_8 ; } else { _rtB -> gvybz5pid1 = _rtB -> csgrq3h5qf ;
} _rtB -> cqlupp4vsi = _rtP -> P_9 * _rtB -> gvybz5pid1 ; _rtB -> jcg24qcvjx
= _rtB -> dmwckndsfm * _rtB -> cqlupp4vsi ; _rtB -> ohex500asr = _rtB ->
jcg24qcvjx * _rtB -> pi4ewu2pq0 ; _rtB -> kwnufrcgdc = _rtB -> g4f1o5ef5r +
_rtB -> ohex500asr ; _rtB -> cg1khvyo3b [ 0 ] = _rtB -> p0mjonhooj ; _rtB ->
cg1khvyo3b [ 1 ] = _rtB -> p0mjonhooj ; _rtB -> cg1khvyo3b [ 2 ] = _rtB ->
kwnufrcgdc ; _rtB -> px2wtwr2yf [ 0 ] = _rtP -> P_10 * _rtB -> cg1khvyo3b [ 0
] ; _rtB -> px2wtwr2yf [ 1 ] = _rtP -> P_10 * _rtB -> cg1khvyo3b [ 1 ] ; _rtB
-> px2wtwr2yf [ 2 ] = _rtP -> P_10 * _rtB -> cg1khvyo3b [ 2 ] ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> etmxwgpupg = _rtP -> P_11 ; _rtB ->
nm4iy0gbav = _rtP -> P_12 ; } _rtB -> j4aecx3b0m = _rtB -> gm5e5ghrph [ 33 ]
* _rtB -> nm4iy0gbav ; _rtB -> pxru0m40vf = _rtB -> g1vh3txmut * _rtB ->
gm5e5ghrph [ 39 ] ; _rtB -> owbp0twjbb = _rtB -> j4aecx3b0m + _rtB ->
pxru0m40vf ; _rtB -> er4omywihq = _rtB -> nm4iy0gbav * _rtB -> gm5e5ghrph [
34 ] ; _rtB -> myrrvhnnh1 = _rtB -> gm5e5ghrph [ 38 ] * _rtB -> g1vh3txmut ;
_rtB -> cqka3jwqgf = _rtB -> myrrvhnnh1 - _rtB -> er4omywihq ; j0hhbshz2o =
muDoubleScalarAtan2 ( _rtB -> owbp0twjbb , _rtB -> cqka3jwqgf ) ; _rtB ->
g5sl52iiuk = _rtB -> etmxwgpupg * muDoubleScalarCos ( j0hhbshz2o ) ; _rtB ->
cscyt12tep = _rtB -> etmxwgpupg * muDoubleScalarSin ( j0hhbshz2o ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> oh5f2dxhdq = _rtP -> P_13 ; } _rtB ->
a3alki1qm1 [ 0 ] = _rtB -> g5sl52iiuk ; _rtB -> a3alki1qm1 [ 1 ] = _rtB ->
cscyt12tep ; _rtB -> a3alki1qm1 [ 2 ] = _rtB -> oh5f2dxhdq ; _rtB ->
oln2qbbpbp [ 0 ] = _rtP -> P_14 * _rtB -> a3alki1qm1 [ 0 ] ; _rtB ->
oln2qbbpbp [ 1 ] = _rtP -> P_14 * _rtB -> a3alki1qm1 [ 1 ] ; _rtB ->
oln2qbbpbp [ 2 ] = _rtP -> P_14 * _rtB -> a3alki1qm1 [ 2 ] ; _rtB ->
b1ahpgysy0 [ 0 ] = _rtB -> px2wtwr2yf [ 0 ] + _rtB -> oln2qbbpbp [ 0 ] ; _rtB
-> b1ahpgysy0 [ 1 ] = _rtB -> px2wtwr2yf [ 1 ] + _rtB -> oln2qbbpbp [ 1 ] ;
_rtB -> b1ahpgysy0 [ 2 ] = _rtB -> px2wtwr2yf [ 2 ] + _rtB -> oln2qbbpbp [ 2
] ; _rtB -> ahk2y3rvvt = _rtB -> gm5e5ghrph [ 36 ] * _rtB -> b1ahpgysy0 [ 2 ]
; _rtB -> l3dp4ocvfx = _rtB -> gm5e5ghrph [ 37 ] * _rtB -> b1ahpgysy0 [ 1 ] ;
_rtB -> orgwj5dkdt = _rtB -> gm5e5ghrph [ 37 ] * _rtB -> b1ahpgysy0 [ 0 ] ;
_rtB -> aganqanvr3 = _rtB -> gm5e5ghrph [ 35 ] * _rtB -> b1ahpgysy0 [ 2 ] ;
_rtB -> msutkq20kh = _rtB -> gm5e5ghrph [ 35 ] * _rtB -> b1ahpgysy0 [ 1 ] ;
_rtB -> ej5jc5ypuo = _rtB -> gm5e5ghrph [ 36 ] * _rtB -> b1ahpgysy0 [ 0 ] ;
_rtB -> if5lbd1ysg = _rtB -> ahk2y3rvvt - _rtB -> l3dp4ocvfx ; _rtB ->
lwu41ojmh4 = _rtB -> orgwj5dkdt - _rtB -> aganqanvr3 ; _rtB -> lphukmrmz2 =
_rtB -> msutkq20kh - _rtB -> ej5jc5ypuo ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ _rtB -> nckld4e1i0 [ 0 ] = _rtP -> P_15 [ 0 ] ; _rtB -> nckld4e1i0 [ 1 ] =
_rtP -> P_15 [ 1 ] ; _rtB -> nckld4e1i0 [ 2 ] = _rtP -> P_15 [ 2 ] ; } _rtB
-> pio4xwafmb [ 0 ] = _rtB -> nckld4e1i0 [ 0 ] * _rtB -> g1vh3txmut ; _rtB ->
pio4xwafmb [ 1 ] = _rtB -> nckld4e1i0 [ 1 ] * _rtB -> g1vh3txmut ; _rtB ->
pio4xwafmb [ 2 ] = _rtB -> nckld4e1i0 [ 2 ] * _rtB -> g1vh3txmut ; _rtB ->
ing0razk1l = _rtB -> pio4xwafmb [ 1 ] * _rtB -> oh5f2dxhdq ; _rtB ->
i4pkwpecbu = _rtB -> pio4xwafmb [ 2 ] * _rtB -> cscyt12tep ; _rtB ->
ldoxzqtc22 = _rtB -> pio4xwafmb [ 2 ] * _rtB -> g5sl52iiuk ; _rtB ->
c24dxnltqw = _rtB -> pio4xwafmb [ 0 ] * _rtB -> oh5f2dxhdq ; _rtB ->
dgtweuqhfp = _rtB -> pio4xwafmb [ 0 ] * _rtB -> cscyt12tep ; _rtB ->
gl55jse3bk = _rtB -> pio4xwafmb [ 1 ] * _rtB -> g5sl52iiuk ; _rtB ->
nzacozubva = _rtB -> ing0razk1l - _rtB -> i4pkwpecbu ; _rtB -> n4gkcnq1e3 =
_rtB -> ldoxzqtc22 - _rtB -> c24dxnltqw ; _rtB -> dd0nq2apla = _rtB ->
dgtweuqhfp - _rtB -> gl55jse3bk ; rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( * (
real_T ( * ) [ 9 ] ) & _rtB -> gm5e5ghrph [ 24 ] , _rtB -> a3alki1qm1 , _rtB
-> poe3npndyu ) ; _rtB -> p2qrxdsowc [ 0 ] = _rtB -> nzacozubva ; _rtB ->
p2qrxdsowc [ 1 ] = _rtB -> n4gkcnq1e3 ; _rtB -> p2qrxdsowc [ 2 ] = _rtB ->
dd0nq2apla ; rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( * ( real_T ( * ) [ 9 ] ) &
_rtB -> gm5e5ghrph [ 24 ] , _rtB -> p2qrxdsowc , _rtB -> hvppa0xfeq ) ;
rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( * ( real_T ( * ) [ 9 ] ) & _rtB ->
gm5e5ghrph [ 24 ] , _rtB -> cg1khvyo3b , _rtB -> iodape3kax ) ; _rtB ->
g4gpktfxtm [ 0 ] = _rtB -> iodape3kax [ 0 ] + _rtB -> poe3npndyu [ 0 ] ; _rtB
-> g4gpktfxtm [ 1 ] = _rtB -> iodape3kax [ 1 ] + _rtB -> poe3npndyu [ 1 ] ;
_rtB -> g4gpktfxtm [ 2 ] = _rtB -> iodape3kax [ 2 ] + _rtB -> poe3npndyu [ 2
] ; _rtB -> iogf2nxv44 [ 0 ] = _rtB -> g4gpktfxtm [ 0 ] ; _rtB -> iogf2nxv44
[ 1 ] = _rtB -> g4gpktfxtm [ 1 ] ; _rtB -> iogf2nxv44 [ 2 ] = _rtB ->
g4gpktfxtm [ 2 ] ; _rtB -> iogf2nxv44 [ 3 ] = _rtB -> hvppa0xfeq [ 0 ] ; _rtB
-> iogf2nxv44 [ 4 ] = _rtB -> hvppa0xfeq [ 1 ] ; _rtB -> iogf2nxv44 [ 5 ] =
_rtB -> hvppa0xfeq [ 2 ] ; _rtB -> iogf2nxv44 [ 6 ] = _rtB -> b1ahpgysy0 [ 0
] ; _rtB -> iogf2nxv44 [ 7 ] = _rtB -> b1ahpgysy0 [ 1 ] ; _rtB -> iogf2nxv44
[ 8 ] = _rtB -> b1ahpgysy0 [ 2 ] ; _rtB -> iogf2nxv44 [ 9 ] = _rtB ->
if5lbd1ysg ; _rtB -> iogf2nxv44 [ 10 ] = _rtB -> lwu41ojmh4 ; _rtB ->
iogf2nxv44 [ 11 ] = _rtB -> lphukmrmz2 ; if ( ssIsMajorTimeStep ( S ) ) {
srUpdateBC ( _rtDW -> md1zpei3wt ) ; } break ; case 1 : if ( rtAction !=
rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) != ssGetTStart ( S ) ) {
ssSetSolverNeedsReset ( S ) ; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { memcpy
( & _rtB -> iogf2nxv44 [ 0 ] , & _rtP -> P_16 [ 0 ] , 12U * sizeof ( real_T )
) ; } if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> kfm5u3jruy ) ; }
break ; } _rtB -> nhzs40pmoi [ 0 ] = _rtB -> iogf2nxv44 [ 6 ] ; _rtB ->
nhzs40pmoi [ 1 ] = 0.0 ; _rtB -> nhzs40pmoi [ 2 ] = 0.0 ; _rtB -> nhzs40pmoi
[ 3 ] = 0.0 ; _rtB -> lxchpavsn0 [ 0 ] = _rtB -> iogf2nxv44 [ 7 ] ; _rtB ->
lxchpavsn0 [ 1 ] = 0.0 ; _rtB -> lxchpavsn0 [ 2 ] = 0.0 ; _rtB -> lxchpavsn0
[ 3 ] = 0.0 ; _rtB -> ksxmonsaer [ 0 ] = _rtB -> iogf2nxv44 [ 8 ] ; _rtB ->
ksxmonsaer [ 1 ] = 0.0 ; _rtB -> ksxmonsaer [ 2 ] = 0.0 ; _rtB -> ksxmonsaer
[ 3 ] = 0.0 ; _rtB -> prdnaqy2ec [ 0 ] = _rtB -> iogf2nxv44 [ 9 ] ; _rtB ->
prdnaqy2ec [ 1 ] = 0.0 ; _rtB -> prdnaqy2ec [ 2 ] = 0.0 ; _rtB -> prdnaqy2ec
[ 3 ] = 0.0 ; _rtB -> aiekaugdow [ 0 ] = _rtB -> iogf2nxv44 [ 10 ] ; _rtB ->
aiekaugdow [ 1 ] = 0.0 ; _rtB -> aiekaugdow [ 2 ] = 0.0 ; _rtB -> aiekaugdow
[ 3 ] = 0.0 ; _rtB -> nwk30go1rf [ 0 ] = _rtB -> iogf2nxv44 [ 11 ] ; _rtB ->
nwk30go1rf [ 1 ] = 0.0 ; _rtB -> nwk30go1rf [ 2 ] = 0.0 ; _rtB -> nwk30go1rf
[ 3 ] = 0.0 ; _rtB -> hu534ggqyy [ 0 ] = _rtB -> iogf2nxv44 [ 0 ] ; _rtB ->
hu534ggqyy [ 1 ] = 0.0 ; _rtB -> hu534ggqyy [ 2 ] = 0.0 ; _rtB -> hu534ggqyy
[ 3 ] = 0.0 ; _rtB -> jk2ikpq4ge [ 0 ] = _rtB -> iogf2nxv44 [ 1 ] ; _rtB ->
jk2ikpq4ge [ 1 ] = 0.0 ; _rtB -> jk2ikpq4ge [ 2 ] = 0.0 ; _rtB -> jk2ikpq4ge
[ 3 ] = 0.0 ; _rtB -> j4pi23nmhh [ 0 ] = _rtB -> iogf2nxv44 [ 2 ] ; _rtB ->
j4pi23nmhh [ 1 ] = 0.0 ; _rtB -> j4pi23nmhh [ 2 ] = 0.0 ; _rtB -> j4pi23nmhh
[ 3 ] = 0.0 ; _rtB -> es3tnr3ahv [ 0 ] = _rtB -> iogf2nxv44 [ 3 ] ; _rtB ->
es3tnr3ahv [ 1 ] = 0.0 ; _rtB -> es3tnr3ahv [ 2 ] = 0.0 ; _rtB -> es3tnr3ahv
[ 3 ] = 0.0 ; _rtB -> jlezkb5wjr [ 0 ] = _rtB -> iogf2nxv44 [ 4 ] ; _rtB ->
jlezkb5wjr [ 1 ] = 0.0 ; _rtB -> jlezkb5wjr [ 2 ] = 0.0 ; _rtB -> jlezkb5wjr
[ 3 ] = 0.0 ; _rtB -> ezl2gvscoq [ 0 ] = _rtB -> iogf2nxv44 [ 5 ] ; _rtB ->
ezl2gvscoq [ 1 ] = 0.0 ; _rtB -> ezl2gvscoq [ 2 ] = 0.0 ; _rtB -> ezl2gvscoq
[ 3 ] = 0.0 ; _rtB -> nb4vvf5xpt [ 0 ] = _rtB -> ndlpykuox4 [ 6 ] ; _rtB ->
nb4vvf5xpt [ 1 ] = 0.0 ; _rtB -> nb4vvf5xpt [ 2 ] = 0.0 ; _rtB -> nb4vvf5xpt
[ 3 ] = 0.0 ; _rtB -> iqaerwsfd4 [ 0 ] = _rtB -> ndlpykuox4 [ 7 ] ; _rtB ->
iqaerwsfd4 [ 1 ] = 0.0 ; _rtB -> iqaerwsfd4 [ 2 ] = 0.0 ; _rtB -> iqaerwsfd4
[ 3 ] = 0.0 ; _rtB -> bjwtxslhs2 [ 0 ] = _rtB -> ndlpykuox4 [ 8 ] ; _rtB ->
bjwtxslhs2 [ 1 ] = 0.0 ; _rtB -> bjwtxslhs2 [ 2 ] = 0.0 ; _rtB -> bjwtxslhs2
[ 3 ] = 0.0 ; _rtB -> hocys0i5rq [ 0 ] = _rtB -> ndlpykuox4 [ 9 ] ; _rtB ->
hocys0i5rq [ 1 ] = 0.0 ; _rtB -> hocys0i5rq [ 2 ] = 0.0 ; _rtB -> hocys0i5rq
[ 3 ] = 0.0 ; _rtB -> ghr5jdm1hi [ 0 ] = _rtB -> ndlpykuox4 [ 10 ] ; _rtB ->
ghr5jdm1hi [ 1 ] = 0.0 ; _rtB -> ghr5jdm1hi [ 2 ] = 0.0 ; _rtB -> ghr5jdm1hi
[ 3 ] = 0.0 ; _rtB -> m5fthzdlq2 [ 0 ] = _rtB -> ndlpykuox4 [ 11 ] ; _rtB ->
m5fthzdlq2 [ 1 ] = 0.0 ; _rtB -> m5fthzdlq2 [ 2 ] = 0.0 ; _rtB -> m5fthzdlq2
[ 3 ] = 0.0 ; _rtB -> i33zxlwumb [ 0 ] = _rtB -> ndlpykuox4 [ 0 ] ; _rtB ->
i33zxlwumb [ 1 ] = 0.0 ; _rtB -> i33zxlwumb [ 2 ] = 0.0 ; _rtB -> i33zxlwumb
[ 3 ] = 0.0 ; _rtB -> dxiq20aky4 [ 0 ] = _rtB -> ndlpykuox4 [ 1 ] ; _rtB ->
dxiq20aky4 [ 1 ] = 0.0 ; _rtB -> dxiq20aky4 [ 2 ] = 0.0 ; _rtB -> dxiq20aky4
[ 3 ] = 0.0 ; _rtB -> ks1c12cyzq [ 0 ] = _rtB -> ndlpykuox4 [ 2 ] ; _rtB ->
ks1c12cyzq [ 1 ] = 0.0 ; _rtB -> ks1c12cyzq [ 2 ] = 0.0 ; _rtB -> ks1c12cyzq
[ 3 ] = 0.0 ; _rtB -> mftwh0ao1u [ 0 ] = _rtB -> ndlpykuox4 [ 3 ] ; _rtB ->
mftwh0ao1u [ 1 ] = 0.0 ; _rtB -> mftwh0ao1u [ 2 ] = 0.0 ; _rtB -> mftwh0ao1u
[ 3 ] = 0.0 ; _rtB -> ogdvqiqqha [ 0 ] = _rtB -> ndlpykuox4 [ 4 ] ; _rtB ->
ogdvqiqqha [ 1 ] = 0.0 ; _rtB -> ogdvqiqqha [ 2 ] = 0.0 ; _rtB -> ogdvqiqqha
[ 3 ] = 0.0 ; _rtB -> n1v1qywznl [ 0 ] = _rtB -> ndlpykuox4 [ 5 ] ; _rtB ->
n1v1qywznl [ 1 ] = 0.0 ; _rtB -> n1v1qywznl [ 2 ] = 0.0 ; _rtB -> n1v1qywznl
[ 3 ] = 0.0 ; _rtB -> m2qi2lgkw3 [ 0 ] = _rtB -> jwxbhz1f5w [ 6 ] ; _rtB ->
m2qi2lgkw3 [ 1 ] = 0.0 ; _rtB -> m2qi2lgkw3 [ 2 ] = 0.0 ; _rtB -> m2qi2lgkw3
[ 3 ] = 0.0 ; _rtB -> dgmvd12oky [ 0 ] = _rtB -> jwxbhz1f5w [ 7 ] ; _rtB ->
dgmvd12oky [ 1 ] = 0.0 ; _rtB -> dgmvd12oky [ 2 ] = 0.0 ; _rtB -> dgmvd12oky
[ 3 ] = 0.0 ; _rtB -> ihji3hiod4 [ 0 ] = _rtB -> jwxbhz1f5w [ 8 ] ; _rtB ->
ihji3hiod4 [ 1 ] = 0.0 ; _rtB -> ihji3hiod4 [ 2 ] = 0.0 ; _rtB -> ihji3hiod4
[ 3 ] = 0.0 ; _rtB -> kbynhn3zy2 [ 0 ] = _rtB -> jwxbhz1f5w [ 9 ] ; _rtB ->
kbynhn3zy2 [ 1 ] = 0.0 ; _rtB -> kbynhn3zy2 [ 2 ] = 0.0 ; _rtB -> kbynhn3zy2
[ 3 ] = 0.0 ; _rtB -> dsueo5l2r1 [ 0 ] = _rtB -> jwxbhz1f5w [ 10 ] ; _rtB ->
dsueo5l2r1 [ 1 ] = 0.0 ; _rtB -> dsueo5l2r1 [ 2 ] = 0.0 ; _rtB -> dsueo5l2r1
[ 3 ] = 0.0 ; _rtB -> kho0zo3dfg [ 0 ] = _rtB -> jwxbhz1f5w [ 11 ] ; _rtB ->
kho0zo3dfg [ 1 ] = 0.0 ; _rtB -> kho0zo3dfg [ 2 ] = 0.0 ; _rtB -> kho0zo3dfg
[ 3 ] = 0.0 ; _rtB -> lrrfvatgwi [ 0 ] = _rtB -> jwxbhz1f5w [ 0 ] ; _rtB ->
lrrfvatgwi [ 1 ] = 0.0 ; _rtB -> lrrfvatgwi [ 2 ] = 0.0 ; _rtB -> lrrfvatgwi
[ 3 ] = 0.0 ; _rtB -> d1qp532kqr [ 0 ] = _rtB -> jwxbhz1f5w [ 1 ] ; _rtB ->
d1qp532kqr [ 1 ] = 0.0 ; _rtB -> d1qp532kqr [ 2 ] = 0.0 ; _rtB -> d1qp532kqr
[ 3 ] = 0.0 ; _rtB -> j432h4ypvr [ 0 ] = _rtB -> jwxbhz1f5w [ 2 ] ; _rtB ->
j432h4ypvr [ 1 ] = 0.0 ; _rtB -> j432h4ypvr [ 2 ] = 0.0 ; _rtB -> j432h4ypvr
[ 3 ] = 0.0 ; _rtB -> l1xjx4iktq [ 0 ] = _rtB -> jwxbhz1f5w [ 3 ] ; _rtB ->
l1xjx4iktq [ 1 ] = 0.0 ; _rtB -> l1xjx4iktq [ 2 ] = 0.0 ; _rtB -> l1xjx4iktq
[ 3 ] = 0.0 ; _rtB -> f2rhh4oerl [ 0 ] = _rtB -> jwxbhz1f5w [ 4 ] ; _rtB ->
f2rhh4oerl [ 1 ] = 0.0 ; _rtB -> f2rhh4oerl [ 2 ] = 0.0 ; _rtB -> f2rhh4oerl
[ 3 ] = 0.0 ; _rtB -> iflirfdj4d [ 0 ] = _rtB -> jwxbhz1f5w [ 5 ] ; _rtB ->
iflirfdj4d [ 1 ] = 0.0 ; _rtB -> iflirfdj4d [ 2 ] = 0.0 ; _rtB -> iflirfdj4d
[ 3 ] = 0.0 ; _rtB -> ne5ij4fl4c [ 0 ] = _rtB -> i2qp0tjdl2 [ 6 ] ; _rtB ->
ne5ij4fl4c [ 1 ] = 0.0 ; _rtB -> ne5ij4fl4c [ 2 ] = 0.0 ; _rtB -> ne5ij4fl4c
[ 3 ] = 0.0 ; _rtB -> bq1bdwbibr [ 0 ] = _rtB -> i2qp0tjdl2 [ 7 ] ; _rtB ->
bq1bdwbibr [ 1 ] = 0.0 ; _rtB -> bq1bdwbibr [ 2 ] = 0.0 ; _rtB -> bq1bdwbibr
[ 3 ] = 0.0 ; _rtB -> kcl1oidpuu [ 0 ] = _rtB -> i2qp0tjdl2 [ 8 ] ; _rtB ->
kcl1oidpuu [ 1 ] = 0.0 ; _rtB -> kcl1oidpuu [ 2 ] = 0.0 ; _rtB -> kcl1oidpuu
[ 3 ] = 0.0 ; _rtB -> jmhte4s2am [ 0 ] = _rtB -> i2qp0tjdl2 [ 9 ] ; _rtB ->
jmhte4s2am [ 1 ] = 0.0 ; _rtB -> jmhte4s2am [ 2 ] = 0.0 ; _rtB -> jmhte4s2am
[ 3 ] = 0.0 ; _rtB -> dai5adlmji [ 0 ] = _rtB -> i2qp0tjdl2 [ 10 ] ; _rtB ->
dai5adlmji [ 1 ] = 0.0 ; _rtB -> dai5adlmji [ 2 ] = 0.0 ; _rtB -> dai5adlmji
[ 3 ] = 0.0 ; _rtB -> dks1ylimhn [ 0 ] = _rtB -> i2qp0tjdl2 [ 11 ] ; _rtB ->
dks1ylimhn [ 1 ] = 0.0 ; _rtB -> dks1ylimhn [ 2 ] = 0.0 ; _rtB -> dks1ylimhn
[ 3 ] = 0.0 ; _rtB -> ozgzpvj4gi [ 0 ] = _rtB -> i2qp0tjdl2 [ 0 ] ; _rtB ->
ozgzpvj4gi [ 1 ] = 0.0 ; _rtB -> ozgzpvj4gi [ 2 ] = 0.0 ; _rtB -> ozgzpvj4gi
[ 3 ] = 0.0 ; _rtB -> jojg0netq2 [ 0 ] = _rtB -> i2qp0tjdl2 [ 1 ] ; _rtB ->
jojg0netq2 [ 1 ] = 0.0 ; _rtB -> jojg0netq2 [ 2 ] = 0.0 ; _rtB -> jojg0netq2
[ 3 ] = 0.0 ; _rtB -> oa5qha35nl [ 0 ] = _rtB -> i2qp0tjdl2 [ 2 ] ; _rtB ->
oa5qha35nl [ 1 ] = 0.0 ; _rtB -> oa5qha35nl [ 2 ] = 0.0 ; _rtB -> oa5qha35nl
[ 3 ] = 0.0 ; _rtB -> kpnxhhg4go [ 0 ] = _rtB -> i2qp0tjdl2 [ 3 ] ; _rtB ->
kpnxhhg4go [ 1 ] = 0.0 ; _rtB -> kpnxhhg4go [ 2 ] = 0.0 ; _rtB -> kpnxhhg4go
[ 3 ] = 0.0 ; _rtB -> jx5jfkuw25 [ 0 ] = _rtB -> i2qp0tjdl2 [ 4 ] ; _rtB ->
jx5jfkuw25 [ 1 ] = 0.0 ; _rtB -> jx5jfkuw25 [ 2 ] = 0.0 ; _rtB -> jx5jfkuw25
[ 3 ] = 0.0 ; _rtB -> a2ywov5eaz [ 0 ] = _rtB -> i2qp0tjdl2 [ 5 ] ; _rtB ->
a2ywov5eaz [ 1 ] = 0.0 ; _rtB -> a2ywov5eaz [ 2 ] = 0.0 ; _rtB -> a2ywov5eaz
[ 3 ] = 0.0 ; _rtB -> fx3mb11snc [ 0 ] = _rtB -> hadnru0wsf [ 6 ] ; _rtB ->
fx3mb11snc [ 1 ] = 0.0 ; _rtB -> fx3mb11snc [ 2 ] = 0.0 ; _rtB -> fx3mb11snc
[ 3 ] = 0.0 ; _rtB -> avfw2jcfcg [ 0 ] = _rtB -> hadnru0wsf [ 7 ] ; _rtB ->
avfw2jcfcg [ 1 ] = 0.0 ; _rtB -> avfw2jcfcg [ 2 ] = 0.0 ; _rtB -> avfw2jcfcg
[ 3 ] = 0.0 ; _rtB -> lqbqnbhefj [ 0 ] = _rtB -> hadnru0wsf [ 8 ] ; _rtB ->
lqbqnbhefj [ 1 ] = 0.0 ; _rtB -> lqbqnbhefj [ 2 ] = 0.0 ; _rtB -> lqbqnbhefj
[ 3 ] = 0.0 ; _rtB -> b3lnt1bhf2 [ 0 ] = _rtB -> hadnru0wsf [ 9 ] ; _rtB ->
b3lnt1bhf2 [ 1 ] = 0.0 ; _rtB -> b3lnt1bhf2 [ 2 ] = 0.0 ; _rtB -> b3lnt1bhf2
[ 3 ] = 0.0 ; _rtB -> fhneemmrkn [ 0 ] = _rtB -> hadnru0wsf [ 10 ] ; _rtB ->
fhneemmrkn [ 1 ] = 0.0 ; _rtB -> fhneemmrkn [ 2 ] = 0.0 ; _rtB -> fhneemmrkn
[ 3 ] = 0.0 ; _rtB -> o3dem52fmc [ 0 ] = _rtB -> hadnru0wsf [ 11 ] ; _rtB ->
o3dem52fmc [ 1 ] = 0.0 ; _rtB -> o3dem52fmc [ 2 ] = 0.0 ; _rtB -> o3dem52fmc
[ 3 ] = 0.0 ; _rtB -> kvyqi2xwsw [ 0 ] = _rtB -> hadnru0wsf [ 0 ] ; _rtB ->
kvyqi2xwsw [ 1 ] = 0.0 ; _rtB -> kvyqi2xwsw [ 2 ] = 0.0 ; _rtB -> kvyqi2xwsw
[ 3 ] = 0.0 ; _rtB -> lwilg5g4hr [ 0 ] = _rtB -> hadnru0wsf [ 1 ] ; _rtB ->
lwilg5g4hr [ 1 ] = 0.0 ; _rtB -> lwilg5g4hr [ 2 ] = 0.0 ; _rtB -> lwilg5g4hr
[ 3 ] = 0.0 ; _rtB -> awrjk3wl4z [ 0 ] = _rtB -> hadnru0wsf [ 2 ] ; _rtB ->
awrjk3wl4z [ 1 ] = 0.0 ; _rtB -> awrjk3wl4z [ 2 ] = 0.0 ; _rtB -> awrjk3wl4z
[ 3 ] = 0.0 ; _rtB -> edpze40v1d [ 0 ] = _rtB -> hadnru0wsf [ 3 ] ; _rtB ->
edpze40v1d [ 1 ] = 0.0 ; _rtB -> edpze40v1d [ 2 ] = 0.0 ; _rtB -> edpze40v1d
[ 3 ] = 0.0 ; _rtB -> j2a05xqc43 [ 0 ] = _rtB -> hadnru0wsf [ 4 ] ; _rtB ->
j2a05xqc43 [ 1 ] = 0.0 ; _rtB -> j2a05xqc43 [ 2 ] = 0.0 ; _rtB -> j2a05xqc43
[ 3 ] = 0.0 ; _rtB -> nrt0aybvpv [ 0 ] = _rtB -> hadnru0wsf [ 5 ] ; _rtB ->
nrt0aybvpv [ 1 ] = 0.0 ; _rtB -> nrt0aybvpv [ 2 ] = 0.0 ; _rtB -> nrt0aybvpv
[ 3 ] = 0.0 ; _rtB -> fdxzddl3gx [ 0 ] = _rtB -> lsebfabbei [ 6 ] ; _rtB ->
fdxzddl3gx [ 1 ] = 0.0 ; _rtB -> fdxzddl3gx [ 2 ] = 0.0 ; _rtB -> fdxzddl3gx
[ 3 ] = 0.0 ; _rtB -> mj4gv0ebkp [ 0 ] = _rtB -> lsebfabbei [ 7 ] ; _rtB ->
mj4gv0ebkp [ 1 ] = 0.0 ; _rtB -> mj4gv0ebkp [ 2 ] = 0.0 ; _rtB -> mj4gv0ebkp
[ 3 ] = 0.0 ; _rtB -> fgiplr1ufu [ 0 ] = _rtB -> lsebfabbei [ 8 ] ; _rtB ->
fgiplr1ufu [ 1 ] = 0.0 ; _rtB -> fgiplr1ufu [ 2 ] = 0.0 ; _rtB -> fgiplr1ufu
[ 3 ] = 0.0 ; _rtB -> ptvj1bi1xi [ 0 ] = _rtB -> lsebfabbei [ 9 ] ; _rtB ->
ptvj1bi1xi [ 1 ] = 0.0 ; _rtB -> ptvj1bi1xi [ 2 ] = 0.0 ; _rtB -> ptvj1bi1xi
[ 3 ] = 0.0 ; _rtB -> khlhbskuua [ 0 ] = _rtB -> lsebfabbei [ 10 ] ; _rtB ->
khlhbskuua [ 1 ] = 0.0 ; _rtB -> khlhbskuua [ 2 ] = 0.0 ; _rtB -> khlhbskuua
[ 3 ] = 0.0 ; _rtB -> eothdqmd1p [ 0 ] = _rtB -> lsebfabbei [ 11 ] ; _rtB ->
eothdqmd1p [ 1 ] = 0.0 ; _rtB -> eothdqmd1p [ 2 ] = 0.0 ; _rtB -> eothdqmd1p
[ 3 ] = 0.0 ; _rtB -> lzmz2r2htf [ 0 ] = _rtB -> lsebfabbei [ 0 ] ; _rtB ->
lzmz2r2htf [ 1 ] = 0.0 ; _rtB -> lzmz2r2htf [ 2 ] = 0.0 ; _rtB -> lzmz2r2htf
[ 3 ] = 0.0 ; _rtB -> gui1hk0dke [ 0 ] = _rtB -> lsebfabbei [ 1 ] ; _rtB ->
gui1hk0dke [ 1 ] = 0.0 ; _rtB -> gui1hk0dke [ 2 ] = 0.0 ; _rtB -> gui1hk0dke
[ 3 ] = 0.0 ; _rtB -> hmetoqt04f [ 0 ] = _rtB -> lsebfabbei [ 2 ] ; _rtB ->
hmetoqt04f [ 1 ] = 0.0 ; _rtB -> hmetoqt04f [ 2 ] = 0.0 ; _rtB -> hmetoqt04f
[ 3 ] = 0.0 ; _rtB -> fosb3iierc [ 0 ] = _rtB -> lsebfabbei [ 3 ] ; _rtB ->
fosb3iierc [ 1 ] = 0.0 ; _rtB -> fosb3iierc [ 2 ] = 0.0 ; _rtB -> fosb3iierc
[ 3 ] = 0.0 ; _rtB -> bcbvo2pfaj [ 0 ] = _rtB -> lsebfabbei [ 4 ] ; _rtB ->
bcbvo2pfaj [ 1 ] = 0.0 ; _rtB -> bcbvo2pfaj [ 2 ] = 0.0 ; _rtB -> bcbvo2pfaj
[ 3 ] = 0.0 ; _rtB -> ki33cd1iq0 [ 0 ] = _rtB -> lsebfabbei [ 5 ] ; _rtB ->
ki33cd1iq0 [ 1 ] = 0.0 ; _rtB -> ki33cd1iq0 [ 2 ] = 0.0 ; _rtB -> ki33cd1iq0
[ 3 ] = 0.0 ; _rtB -> owaqcpk4qz [ 0 ] = _rtB -> fuy0b2wi3g [ 6 ] ; _rtB ->
owaqcpk4qz [ 1 ] = 0.0 ; _rtB -> owaqcpk4qz [ 2 ] = 0.0 ; _rtB -> owaqcpk4qz
[ 3 ] = 0.0 ; _rtB -> o44elcg1tr [ 0 ] = _rtB -> fuy0b2wi3g [ 7 ] ; _rtB ->
o44elcg1tr [ 1 ] = 0.0 ; _rtB -> o44elcg1tr [ 2 ] = 0.0 ; _rtB -> o44elcg1tr
[ 3 ] = 0.0 ; _rtB -> mnmsaa3all [ 0 ] = _rtB -> fuy0b2wi3g [ 8 ] ; _rtB ->
mnmsaa3all [ 1 ] = 0.0 ; _rtB -> mnmsaa3all [ 2 ] = 0.0 ; _rtB -> mnmsaa3all
[ 3 ] = 0.0 ; _rtB -> jff4xkkzrz [ 0 ] = _rtB -> fuy0b2wi3g [ 9 ] ; _rtB ->
jff4xkkzrz [ 1 ] = 0.0 ; _rtB -> jff4xkkzrz [ 2 ] = 0.0 ; _rtB -> jff4xkkzrz
[ 3 ] = 0.0 ; _rtB -> fmz2c0ogxt [ 0 ] = _rtB -> fuy0b2wi3g [ 10 ] ; _rtB ->
fmz2c0ogxt [ 1 ] = 0.0 ; _rtB -> fmz2c0ogxt [ 2 ] = 0.0 ; _rtB -> fmz2c0ogxt
[ 3 ] = 0.0 ; _rtB -> ecwigpcj1i [ 0 ] = _rtB -> fuy0b2wi3g [ 11 ] ; _rtB ->
ecwigpcj1i [ 1 ] = 0.0 ; _rtB -> ecwigpcj1i [ 2 ] = 0.0 ; _rtB -> ecwigpcj1i
[ 3 ] = 0.0 ; _rtB -> duxvz5dx3f [ 0 ] = _rtB -> fuy0b2wi3g [ 0 ] ; _rtB ->
duxvz5dx3f [ 1 ] = 0.0 ; _rtB -> duxvz5dx3f [ 2 ] = 0.0 ; _rtB -> duxvz5dx3f
[ 3 ] = 0.0 ; _rtB -> psti5gi3rv [ 0 ] = _rtB -> fuy0b2wi3g [ 1 ] ; _rtB ->
psti5gi3rv [ 1 ] = 0.0 ; _rtB -> psti5gi3rv [ 2 ] = 0.0 ; _rtB -> psti5gi3rv
[ 3 ] = 0.0 ; _rtB -> o5f13dyiiz [ 0 ] = _rtB -> fuy0b2wi3g [ 2 ] ; _rtB ->
o5f13dyiiz [ 1 ] = 0.0 ; _rtB -> o5f13dyiiz [ 2 ] = 0.0 ; _rtB -> o5f13dyiiz
[ 3 ] = 0.0 ; _rtB -> n2w3jwavrc [ 0 ] = _rtB -> fuy0b2wi3g [ 3 ] ; _rtB ->
n2w3jwavrc [ 1 ] = 0.0 ; _rtB -> n2w3jwavrc [ 2 ] = 0.0 ; _rtB -> n2w3jwavrc
[ 3 ] = 0.0 ; _rtB -> n32vpthjpx [ 0 ] = _rtB -> fuy0b2wi3g [ 4 ] ; _rtB ->
n32vpthjpx [ 1 ] = 0.0 ; _rtB -> n32vpthjpx [ 2 ] = 0.0 ; _rtB -> n32vpthjpx
[ 3 ] = 0.0 ; _rtB -> lamtwytqeb [ 0 ] = _rtB -> fuy0b2wi3g [ 5 ] ; _rtB ->
lamtwytqeb [ 1 ] = 0.0 ; _rtB -> lamtwytqeb [ 2 ] = 0.0 ; _rtB -> lamtwytqeb
[ 3 ] = 0.0 ; ssCallAccelRunBlock ( S , 26 , 472 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 473 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 518 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 519 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 520 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 521 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 522 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { for ( i = 0 ; i < 4 ; i ++ ) { _rtB ->
pjp54lsdsf [ i ] = 0.0 ; _rtB -> pjp54lsdsf [ i ] += _rtP -> P_175 [ i ] *
_rtB -> en5rkorno5 [ 0 ] ; _rtB -> pjp54lsdsf [ i ] += _rtP -> P_175 [ i + 4
] * _rtB -> en5rkorno5 [ 1 ] ; _rtB -> pjp54lsdsf [ i ] += _rtP -> P_175 [ i
+ 8 ] * _rtB -> en5rkorno5 [ 2 ] ; _rtB -> pjp54lsdsf [ i ] += _rtP -> P_175
[ i + 12 ] * _rtB -> en5rkorno5 [ 3 ] ; } ssCallAccelRunBlock ( S , 26 , 525
, SS_CALL_MDL_OUTPUTS ) ; _rtB -> kmvjezjnyx = _rtP -> P_176 * _rtB ->
mooukgcgde ; ssCallAccelRunBlock ( S , 26 , 527 , SS_CALL_MDL_OUTPUTS ) ; for
( i = 0 ; i < 4 ; i ++ ) { _rtB -> f01pvxxhvn [ i ] = 0.0 ; _rtB ->
f01pvxxhvn [ i ] += _rtB -> mj52ye3fhg [ i ] * _rtB -> pjp54lsdsf [ 0 ] ;
_rtB -> f01pvxxhvn [ i ] += _rtB -> mj52ye3fhg [ i + 4 ] * _rtB -> pjp54lsdsf
[ 1 ] ; _rtB -> f01pvxxhvn [ i ] += _rtB -> mj52ye3fhg [ i + 8 ] * _rtB ->
pjp54lsdsf [ 2 ] ; _rtB -> f01pvxxhvn [ i ] += _rtB -> mj52ye3fhg [ i + 12 ]
* _rtB -> pjp54lsdsf [ 3 ] ; } ssCallAccelRunBlock ( S , 26 , 529 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 530 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> nmzk53brpb = _rtP -> P_177 * _rtB ->
mooukgcgde ; } ssCallAccelRunBlock ( S , 26 , 532 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 533 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 534 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
dqxngs4sfd = 0.0 ; _rtB -> dqxngs4sfd += _rtP -> P_179 * _rtX -> h155tmmbck ;
_rtB -> iegl4q51xa = _rtP -> P_180 * _rtB -> dqxngs4sfd ; ssCallAccelRunBlock
( S , 26 , 567 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW -> gxvzfjyjfz >= ssGetT
( S ) ) && ( _rtDW -> niymfi4oq3 >= ssGetT ( S ) ) ) { _rtB -> guih2ongku =
0.0 ; } else { j0hhbshz2o = _rtDW -> gxvzfjyjfz ; lastU = & _rtDW ->
fyq1ioii4y ; if ( _rtDW -> gxvzfjyjfz < _rtDW -> niymfi4oq3 ) { if ( _rtDW ->
niymfi4oq3 < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> niymfi4oq3 ; lastU = &
_rtDW -> ky2ygw5nhh ; } } else { if ( _rtDW -> gxvzfjyjfz >= ssGetT ( S ) ) {
j0hhbshz2o = _rtDW -> niymfi4oq3 ; lastU = & _rtDW -> ky2ygw5nhh ; } } _rtB
-> guih2ongku = ( _rtB -> iegl4q51xa - * lastU ) / ( ssGetT ( S ) -
j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 , 569 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> mynb2yyuft = _rtP -> P_181 * _rtB -> pl2wvrqrxm ; _rtB -> bid4dqpdei
= _rtB -> kmvjezjnyx - _rtB -> mynb2yyuft ; _rtB -> eld3tcrwu3 = _rtP ->
P_182 * _rtB -> bid4dqpdei ; if ( ( _rtDW -> p5p0vltaax >= ssGetT ( S ) ) &&
( _rtDW -> ddafsn123k >= ssGetT ( S ) ) ) { _rtB -> hs0j1cf1ly = 0.0 ; } else
{ j0hhbshz2o = _rtDW -> p5p0vltaax ; lastU = & _rtDW -> lnzzyyuval ; if (
_rtDW -> p5p0vltaax < _rtDW -> ddafsn123k ) { if ( _rtDW -> ddafsn123k <
ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> ddafsn123k ; lastU = & _rtDW ->
bzuhgwd2ot ; } } else { if ( _rtDW -> p5p0vltaax >= ssGetT ( S ) ) {
j0hhbshz2o = _rtDW -> ddafsn123k ; lastU = & _rtDW -> bzuhgwd2ot ; } } _rtB
-> hs0j1cf1ly = ( _rtB -> eld3tcrwu3 - * lastU ) / ( ssGetT ( S ) -
j0hhbshz2o ) ; } _rtB -> oyhiyjsdn4 = ( ( cfqhbkrmw3 * ) ssGetContStates ( S
) ) -> gh3iyxvqht ; _rtB -> k5mdvduknf = _rtP -> P_184 * _rtB -> bid4dqpdei ;
_rtB -> gw42y0c5xe = _rtP -> P_185 * _rtB -> bid4dqpdei ; _rtB -> dxozndhpyz
= ( _rtB -> oyhiyjsdn4 + _rtB -> k5mdvduknf ) + _rtB -> hs0j1cf1ly ; _rtB ->
kovtoirsgq = _rtP -> P_186 * _rtB -> dqxngs4sfd ; _rtB -> kwv5boo2l1 = _rtP
-> P_187 * _rtB -> dxozndhpyz ; _rtB -> aluymje4gy = 0.0 ; _rtB -> aluymje4gy
+= _rtP -> P_189 * _rtX -> lqibactaag ; _rtB -> ddqicp1aaf = _rtP -> P_190 *
_rtB -> aluymje4gy ; _rtB -> bezcxsb4ow = _rtB -> kwv5boo2l1 - _rtB ->
kovtoirsgq ; _rtB -> agunmohhrb = 0.0 ; _rtB -> agunmohhrb += _rtP -> P_192 *
_rtX -> dvazecsy1c ; _rtB -> cebyqijllt = _rtP -> P_193 * _rtB -> agunmohhrb
; ssCallAccelRunBlock ( S , 26 , 585 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW
-> p2stagy2hg >= ssGetT ( S ) ) && ( _rtDW -> d1h1i0lh2q >= ssGetT ( S ) ) )
{ _rtB -> guih2ongku = 0.0 ; } else { j0hhbshz2o = _rtDW -> p2stagy2hg ;
lastU = & _rtDW -> olfp5w0idj ; if ( _rtDW -> p2stagy2hg < _rtDW ->
d1h1i0lh2q ) { if ( _rtDW -> d1h1i0lh2q < ssGetT ( S ) ) { j0hhbshz2o = _rtDW
-> d1h1i0lh2q ; lastU = & _rtDW -> ecoarytxkj ; } } else { if ( _rtDW ->
p2stagy2hg >= ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> d1h1i0lh2q ; lastU = &
_rtDW -> ecoarytxkj ; } } _rtB -> guih2ongku = ( _rtB -> cebyqijllt - * lastU
) / ( ssGetT ( S ) - j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 , 587 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
plvrtgf4hz = _rtP -> P_194 * _rtB -> bxlc4gpij0 ; } _rtB -> i32xwjn5ve = _rtP
-> P_195 * _rtB -> nwkzu3qpu5 ; _rtB -> gmpe403dan = _rtB -> plvrtgf4hz -
_rtB -> i32xwjn5ve ; _rtB -> mfpr0jjl3y = _rtP -> P_196 * _rtB -> gmpe403dan
; if ( ( _rtDW -> nokgbkqmov >= ssGetT ( S ) ) && ( _rtDW -> fu4fuq2uck >=
ssGetT ( S ) ) ) { _rtB -> mrn2jfpswe = 0.0 ; } else { j0hhbshz2o = _rtDW ->
nokgbkqmov ; lastU = & _rtDW -> dhzyfmgyay ; if ( _rtDW -> nokgbkqmov < _rtDW
-> fu4fuq2uck ) { if ( _rtDW -> fu4fuq2uck < ssGetT ( S ) ) { j0hhbshz2o =
_rtDW -> fu4fuq2uck ; lastU = & _rtDW -> orx4swi3fj ; } } else { if ( _rtDW
-> nokgbkqmov >= ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> fu4fuq2uck ; lastU =
& _rtDW -> orx4swi3fj ; } } _rtB -> mrn2jfpswe = ( _rtB -> mfpr0jjl3y - *
lastU ) / ( ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> kzjib33z4b = ( (
cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> b3u12lyooc ; _rtB -> el1ekqutdp =
_rtP -> P_198 * _rtB -> gmpe403dan ; _rtB -> hp1uxbetun = _rtP -> P_199 *
_rtB -> gmpe403dan ; _rtB -> j0irqzwrof = ( _rtB -> kzjib33z4b + _rtB ->
el1ekqutdp ) + _rtB -> mrn2jfpswe ; _rtB -> cyhiid4so1 = 0.0 ; _rtB ->
cyhiid4so1 += _rtP -> P_201 * _rtX -> hkmcxcpyw4 ; _rtB -> c23l5g1qub = _rtP
-> P_202 * _rtB -> cyhiid4so1 ; ssCallAccelRunBlock ( S , 26 , 599 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 600 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 601 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> bh1vvwnnwf = _rtP -> P_203 * _rtB ->
j0irqzwrof ; ssCallAccelRunBlock ( S , 26 , 603 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> gvnuhyqwv1 = _rtP -> P_204 * _rtB -> agunmohhrb ; _rtB -> k4t0ez3yni
= _rtB -> bh1vvwnnwf - _rtB -> gvnuhyqwv1 ; if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> mclbanmqbw = _rtP -> P_205 ; } _rtB -> nz3rzjih2f [ 0 ] = _rtB ->
mclbanmqbw + _rtB -> h3fjt0sblk ; _rtB -> nz3rzjih2f [ 1 ] = _rtB ->
mclbanmqbw + _rtB -> nmzk53brpb ; _rtB -> fcgzam2erz = 0.0 ; _rtB ->
fcgzam2erz += _rtP -> P_207 * _rtX -> ocimq5mxpx ; _rtB -> fva4drfwi0 = _rtP
-> P_208 * _rtB -> fcgzam2erz ; ssCallAccelRunBlock ( S , 26 , 610 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW -> k4lcetjgkb >= ssGetT ( S ) ) && (
_rtDW -> cabtruwfpo >= ssGetT ( S ) ) ) { _rtB -> guih2ongku = 0.0 ; } else {
j0hhbshz2o = _rtDW -> k4lcetjgkb ; lastU = & _rtDW -> i44riggpwd ; if ( _rtDW
-> k4lcetjgkb < _rtDW -> cabtruwfpo ) { if ( _rtDW -> cabtruwfpo < ssGetT ( S
) ) { j0hhbshz2o = _rtDW -> cabtruwfpo ; lastU = & _rtDW -> liyko2tf3s ; } }
else { if ( _rtDW -> k4lcetjgkb >= ssGetT ( S ) ) { j0hhbshz2o = _rtDW ->
cabtruwfpo ; lastU = & _rtDW -> liyko2tf3s ; } } _rtB -> guih2ongku = ( _rtB
-> fva4drfwi0 - * lastU ) / ( ssGetT ( S ) - j0hhbshz2o ) ; }
ssCallAccelRunBlock ( S , 26 , 612 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> cqdobc3pya = _rtP -> P_209 * _rtB ->
nmzk53brpb ; } _rtB -> hrwvzoh1ke = _rtP -> P_210 * _rtB -> h3fjt0sblk ; _rtB
-> ojqs5g2ole = _rtB -> cqdobc3pya - _rtB -> hrwvzoh1ke ; _rtB -> fgixxej3oa
= _rtP -> P_211 * _rtB -> ojqs5g2ole ; if ( ( _rtDW -> gj12sphtdn >= ssGetT (
S ) ) && ( _rtDW -> otxkpvw3hh >= ssGetT ( S ) ) ) { _rtB -> kmaxhrlgpl = 0.0
; } else { j0hhbshz2o = _rtDW -> gj12sphtdn ; lastU = & _rtDW -> b1ntdub2it ;
if ( _rtDW -> gj12sphtdn < _rtDW -> otxkpvw3hh ) { if ( _rtDW -> otxkpvw3hh <
ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> otxkpvw3hh ; lastU = & _rtDW ->
dcypfrtcpg ; } } else { if ( _rtDW -> gj12sphtdn >= ssGetT ( S ) ) {
j0hhbshz2o = _rtDW -> otxkpvw3hh ; lastU = & _rtDW -> dcypfrtcpg ; } } _rtB
-> kmaxhrlgpl = ( _rtB -> fgixxej3oa - * lastU ) / ( ssGetT ( S ) -
j0hhbshz2o ) ; } _rtB -> kptrgo0rs2 = ( ( cfqhbkrmw3 * ) ssGetContStates ( S
) ) -> mzkaz2abrd ; _rtB -> auo2vmx3lc = _rtP -> P_213 * _rtB -> ojqs5g2ole ;
_rtB -> bgdvv2kkfq = _rtP -> P_214 * _rtB -> ojqs5g2ole ; _rtB -> jvatq1l4cp
= ( _rtB -> kptrgo0rs2 + _rtB -> auo2vmx3lc ) + _rtB -> kmaxhrlgpl ; _rtB ->
b04rwpmlfa = 0.0 ; _rtB -> b04rwpmlfa += _rtP -> P_216 * _rtX -> mjlt2dcjyn ;
_rtB -> mdck2fipfs = _rtP -> P_217 * _rtB -> b04rwpmlfa ; ssCallAccelRunBlock
( S , 26 , 624 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 625 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 626 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> coy3nrbu3x = _rtP -> P_218 * _rtB ->
jvatq1l4cp ; ssCallAccelRunBlock ( S , 26 , 628 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> bukn1g3xnh = _rtP -> P_219 * _rtB -> fcgzam2erz ; _rtB -> iwtgxpue0e
= _rtB -> coy3nrbu3x - _rtB -> bukn1g3xnh ; ssCallAccelRunBlock ( S , 26 ,
631 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 635 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 663 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 694 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> g13mlvrku5 = 0.0 ; _rtB -> g13mlvrku5 += _rtP
-> P_221 * _rtX -> maia2upwdj ; _rtB -> esnf0glwer = _rtP -> P_222 * _rtB ->
g13mlvrku5 ; ssCallAccelRunBlock ( S , 26 , 697 , SS_CALL_MDL_OUTPUTS ) ; if
( ( _rtDW -> iyjs3n2hlb >= ssGetT ( S ) ) && ( _rtDW -> fgdiy1cbbh >= ssGetT
( S ) ) ) { _rtB -> guih2ongku = 0.0 ; } else { j0hhbshz2o = _rtDW ->
iyjs3n2hlb ; lastU = & _rtDW -> macdwpifir ; if ( _rtDW -> iyjs3n2hlb < _rtDW
-> fgdiy1cbbh ) { if ( _rtDW -> fgdiy1cbbh < ssGetT ( S ) ) { j0hhbshz2o =
_rtDW -> fgdiy1cbbh ; lastU = & _rtDW -> omitc2ymp2 ; } } else { if ( _rtDW
-> iyjs3n2hlb >= ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> fgdiy1cbbh ; lastU =
& _rtDW -> omitc2ymp2 ; } } _rtB -> guih2ongku = ( _rtB -> esnf0glwer - *
lastU ) / ( ssGetT ( S ) - j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 ,
699 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { for ( i =
0 ; i < 4 ; i ++ ) { _rtB -> f01pvxxhvn [ i ] = 0.0 ; _rtB -> f01pvxxhvn [ i
] += _rtP -> P_223 [ i ] * _rtB -> jtdvbs3ycu [ 0 ] ; _rtB -> f01pvxxhvn [ i
] += _rtP -> P_223 [ i + 4 ] * _rtB -> jtdvbs3ycu [ 1 ] ; _rtB -> f01pvxxhvn
[ i ] += _rtP -> P_223 [ i + 8 ] * _rtB -> jtdvbs3ycu [ 2 ] ; _rtB ->
f01pvxxhvn [ i ] += _rtP -> P_223 [ i + 12 ] * _rtB -> jtdvbs3ycu [ 3 ] ; }
ssCallAccelRunBlock ( S , 26 , 702 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
g3tylt5or5 = _rtP -> P_224 * _rtB -> mooukgcgde ; _rtB -> aejwlpdlac = _rtP
-> P_225 * _rtB -> g3tylt5or5 ; } _rtB -> ni0uburybf = _rtP -> P_226 * _rtB
-> i300diadtf ; _rtB -> iqartapwkn = _rtB -> aejwlpdlac - _rtB -> ni0uburybf
; _rtB -> gjnz3y1xbh = _rtP -> P_227 * _rtB -> iqartapwkn ; if ( ( _rtDW ->
ing2zbnlej >= ssGetT ( S ) ) && ( _rtDW -> fj5aqqw3v0 >= ssGetT ( S ) ) ) {
_rtB -> eko00ze2li = 0.0 ; } else { j0hhbshz2o = _rtDW -> ing2zbnlej ; lastU
= & _rtDW -> ljqavruy5n ; if ( _rtDW -> ing2zbnlej < _rtDW -> fj5aqqw3v0 ) {
if ( _rtDW -> fj5aqqw3v0 < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> fj5aqqw3v0
; lastU = & _rtDW -> a2ql4ar3pm ; } } else { if ( _rtDW -> ing2zbnlej >=
ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> fj5aqqw3v0 ; lastU = & _rtDW ->
a2ql4ar3pm ; } } _rtB -> eko00ze2li = ( _rtB -> gjnz3y1xbh - * lastU ) / (
ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> mwmx1zzb4v = ( ( cfqhbkrmw3 * )
ssGetContStates ( S ) ) -> doz4021415 ; _rtB -> eiuxqujnnx = _rtP -> P_229 *
_rtB -> iqartapwkn ; _rtB -> md4wuzup0w = _rtP -> P_230 * _rtB -> iqartapwkn
; _rtB -> ii2f2vzqk2 = ( _rtB -> mwmx1zzb4v + _rtB -> eiuxqujnnx ) + _rtB ->
eko00ze2li ; _rtB -> dienwhc0rd = 0.0 ; _rtB -> dienwhc0rd += _rtP -> P_232 *
_rtX -> b0hpv5pjok ; _rtB -> naayrmdz5t = _rtP -> P_233 * _rtB -> dienwhc0rd
; ssCallAccelRunBlock ( S , 26 , 715 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 716 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 717 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
iraxrx3swd = _rtP -> P_234 * _rtB -> ii2f2vzqk2 ; ssCallAccelRunBlock ( S ,
26 , 719 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> plhn0acsqc = _rtP -> P_235 * _rtB
-> g13mlvrku5 ; _rtB -> oycakzdqvd = _rtB -> iraxrx3swd - _rtB -> plhn0acsqc
; ssCallAccelRunBlock ( S , 26 , 722 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
mndszxksdj = 0.0 ; _rtB -> mndszxksdj += _rtP -> P_237 * _rtX -> kda52s1yxv ;
_rtB -> h1ket0xx5q = _rtP -> P_238 * _rtB -> mndszxksdj ; ssCallAccelRunBlock
( S , 26 , 725 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW -> hzb1j1dedc >= ssGetT
( S ) ) && ( _rtDW -> pqekytbgoa >= ssGetT ( S ) ) ) { _rtB -> guih2ongku =
0.0 ; } else { j0hhbshz2o = _rtDW -> hzb1j1dedc ; lastU = & _rtDW ->
lvjxccrcmc ; if ( _rtDW -> hzb1j1dedc < _rtDW -> pqekytbgoa ) { if ( _rtDW ->
pqekytbgoa < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> pqekytbgoa ; lastU = &
_rtDW -> etik1cpo2m ; } } else { if ( _rtDW -> hzb1j1dedc >= ssGetT ( S ) ) {
j0hhbshz2o = _rtDW -> pqekytbgoa ; lastU = & _rtDW -> etik1cpo2m ; } } _rtB
-> guih2ongku = ( _rtB -> h1ket0xx5q - * lastU ) / ( ssGetT ( S ) -
j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 , 727 , SS_CALL_MDL_OUTPUTS ) ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 728 ,
SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i < 4 ; i ++ ) { _rtB -> pjp54lsdsf [ i
] = 0.0 ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i ] * _rtB ->
f01pvxxhvn [ 0 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i + 4 ] *
_rtB -> f01pvxxhvn [ 1 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i
+ 8 ] * _rtB -> f01pvxxhvn [ 2 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB ->
mj52ye3fhg [ i + 12 ] * _rtB -> f01pvxxhvn [ 3 ] ; } ssCallAccelRunBlock ( S
, 26 , 730 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> cb2zj14ant = _rtP -> P_239 *
_rtB -> mooukgcgde ; } _rtB -> js3zxjkg4h = _rtP -> P_240 * _rtB ->
f1xe44wn5b ; _rtB -> flbgmfrbi4 = _rtB -> cb2zj14ant - _rtB -> js3zxjkg4h ;
_rtB -> kddf15ytqn = _rtP -> P_241 * _rtB -> flbgmfrbi4 ; if ( ( _rtDW ->
m0nhdmvumy >= ssGetT ( S ) ) && ( _rtDW -> bfmcbjs0af >= ssGetT ( S ) ) ) {
_rtB -> accq1grg2q = 0.0 ; } else { j0hhbshz2o = _rtDW -> m0nhdmvumy ; lastU
= & _rtDW -> fuqlxsqqsg ; if ( _rtDW -> m0nhdmvumy < _rtDW -> bfmcbjs0af ) {
if ( _rtDW -> bfmcbjs0af < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> bfmcbjs0af
; lastU = & _rtDW -> lovupdqmon ; } } else { if ( _rtDW -> m0nhdmvumy >=
ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> bfmcbjs0af ; lastU = & _rtDW ->
lovupdqmon ; } } _rtB -> accq1grg2q = ( _rtB -> kddf15ytqn - * lastU ) / (
ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> chprxt3htm = ( ( cfqhbkrmw3 * )
ssGetContStates ( S ) ) -> ky1obcqoz2 ; _rtB -> gbipecft0b = _rtP -> P_243 *
_rtB -> flbgmfrbi4 ; _rtB -> hvzmuzn5h1 = _rtP -> P_244 * _rtB -> flbgmfrbi4
; _rtB -> fmv1dlejoa = ( _rtB -> chprxt3htm + _rtB -> gbipecft0b ) + _rtB ->
accq1grg2q ; _rtB -> co2pir51t1 = 0.0 ; _rtB -> co2pir51t1 += _rtP -> P_246 *
_rtX -> oirh2svypv ; _rtB -> fzz4f03a4p = _rtP -> P_247 * _rtB -> co2pir51t1
; ssCallAccelRunBlock ( S , 26 , 742 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 743 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 744 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
phdukpccjd = _rtP -> P_248 * _rtB -> fmv1dlejoa ; ssCallAccelRunBlock ( S ,
26 , 746 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> cu0p5sbmox = _rtP -> P_249 * _rtB
-> mndszxksdj ; _rtB -> ge104hxhus = _rtB -> phdukpccjd - _rtB -> cu0p5sbmox
; ssCallAccelRunBlock ( S , 26 , 749 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
oyd1jq2gup = 0.0 ; _rtB -> oyd1jq2gup += _rtP -> P_251 * _rtX -> hvrzirvdht ;
_rtB -> pcfhp1iopy = _rtP -> P_252 * _rtB -> oyd1jq2gup ; ssCallAccelRunBlock
( S , 26 , 752 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW -> e0md23qrnv >= ssGetT
( S ) ) && ( _rtDW -> bkptfilnzm >= ssGetT ( S ) ) ) { _rtB -> guih2ongku =
0.0 ; } else { j0hhbshz2o = _rtDW -> e0md23qrnv ; lastU = & _rtDW ->
ekglrfhonl ; if ( _rtDW -> e0md23qrnv < _rtDW -> bkptfilnzm ) { if ( _rtDW ->
bkptfilnzm < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> bkptfilnzm ; lastU = &
_rtDW -> lrpmykjqy3 ; } } else { if ( _rtDW -> e0md23qrnv >= ssGetT ( S ) ) {
j0hhbshz2o = _rtDW -> bkptfilnzm ; lastU = & _rtDW -> lrpmykjqy3 ; } } _rtB
-> guih2ongku = ( _rtB -> pcfhp1iopy - * lastU ) / ( ssGetT ( S ) -
j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 , 754 , SS_CALL_MDL_OUTPUTS ) ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 755 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> iweqouqaaf *= _rtP -> P_253 ; _rtB ->
bqjaf5fav2 = _rtP -> P_254 * _rtB -> iweqouqaaf ; } _rtB -> aqvyma4301 = _rtP
-> P_255 * _rtB -> efng1cj14q ; _rtB -> obk0u1tai5 = _rtB -> bqjaf5fav2 -
_rtB -> aqvyma4301 ; _rtB -> bnu5015hlg = _rtP -> P_256 * _rtB -> obk0u1tai5
; if ( ( _rtDW -> ponpoa5jnj >= ssGetT ( S ) ) && ( _rtDW -> g5f0njdqmd >=
ssGetT ( S ) ) ) { _rtB -> fui5yyiyy5 = 0.0 ; } else { j0hhbshz2o = _rtDW ->
ponpoa5jnj ; lastU = & _rtDW -> kwjpgule3p ; if ( _rtDW -> ponpoa5jnj < _rtDW
-> g5f0njdqmd ) { if ( _rtDW -> g5f0njdqmd < ssGetT ( S ) ) { j0hhbshz2o =
_rtDW -> g5f0njdqmd ; lastU = & _rtDW -> j21ik0qxig ; } } else { if ( _rtDW
-> ponpoa5jnj >= ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> g5f0njdqmd ; lastU =
& _rtDW -> j21ik0qxig ; } } _rtB -> fui5yyiyy5 = ( _rtB -> bnu5015hlg - *
lastU ) / ( ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> g4hv1ns3re = ( (
cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> neccwznanm ; _rtB -> ooed5azk2s =
_rtP -> P_258 * _rtB -> obk0u1tai5 ; _rtB -> ipkrfhf40a = _rtP -> P_259 *
_rtB -> obk0u1tai5 ; _rtB -> hl5k3qocr0 = ( _rtB -> g4hv1ns3re + _rtB ->
ooed5azk2s ) + _rtB -> fui5yyiyy5 ; _rtB -> ljqq5wknre = 0.0 ; _rtB ->
ljqq5wknre += _rtP -> P_261 * _rtX -> nkzwoy5l3s ; _rtB -> ot0goil1fh = _rtP
-> P_262 * _rtB -> ljqq5wknre ; ssCallAccelRunBlock ( S , 26 , 768 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 769 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 770 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> o4jdu42nqi = _rtP -> P_263 * _rtB ->
hl5k3qocr0 ; ssCallAccelRunBlock ( S , 26 , 772 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> hlqqun4taa = _rtP -> P_264 * _rtB -> oyd1jq2gup ; _rtB -> amidl4hci3
= _rtB -> o4jdu42nqi - _rtB -> hlqqun4taa ; ssCallAccelRunBlock ( S , 26 ,
799 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 830 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> jykbtpbcct = 0.0 ; _rtB -> jykbtpbcct += _rtP
-> P_266 * _rtX -> bilhigf3xj ; _rtB -> kxwytcbakg = _rtP -> P_267 * _rtB ->
jykbtpbcct ; ssCallAccelRunBlock ( S , 26 , 833 , SS_CALL_MDL_OUTPUTS ) ; if
( ( _rtDW -> jsqocbcrbw >= ssGetT ( S ) ) && ( _rtDW -> mjccdjqte1 >= ssGetT
( S ) ) ) { _rtB -> guih2ongku = 0.0 ; } else { j0hhbshz2o = _rtDW ->
jsqocbcrbw ; lastU = & _rtDW -> glsyupdcw5 ; if ( _rtDW -> jsqocbcrbw < _rtDW
-> mjccdjqte1 ) { if ( _rtDW -> mjccdjqte1 < ssGetT ( S ) ) { j0hhbshz2o =
_rtDW -> mjccdjqte1 ; lastU = & _rtDW -> ep0sq2bcqm ; } } else { if ( _rtDW
-> jsqocbcrbw >= ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> mjccdjqte1 ; lastU =
& _rtDW -> ep0sq2bcqm ; } } _rtB -> guih2ongku = ( _rtB -> kxwytcbakg - *
lastU ) / ( ssGetT ( S ) - j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 ,
835 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { for ( i =
0 ; i < 4 ; i ++ ) { _rtB -> f01pvxxhvn [ i ] = 0.0 ; _rtB -> f01pvxxhvn [ i
] += _rtP -> P_268 [ i ] * _rtB -> ptpzyjs1p2 [ 0 ] ; _rtB -> f01pvxxhvn [ i
] += _rtP -> P_268 [ i + 4 ] * _rtB -> ptpzyjs1p2 [ 1 ] ; _rtB -> f01pvxxhvn
[ i ] += _rtP -> P_268 [ i + 8 ] * _rtB -> ptpzyjs1p2 [ 2 ] ; _rtB ->
f01pvxxhvn [ i ] += _rtP -> P_268 [ i + 12 ] * _rtB -> ptpzyjs1p2 [ 3 ] ; }
ssCallAccelRunBlock ( S , 26 , 838 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
eexwmnv3fc = _rtP -> P_269 * _rtB -> fvjhga3og4 ; _rtB -> ip2xu0tu40 = _rtP
-> P_270 * _rtB -> eexwmnv3fc ; } _rtB -> btv5vex4qr = _rtP -> P_271 * _rtB
-> ofeafse4g5 ; _rtB -> ntxq2snrot = _rtB -> ip2xu0tu40 - _rtB -> btv5vex4qr
; _rtB -> nidjbvpyt5 = _rtP -> P_272 * _rtB -> ntxq2snrot ; if ( ( _rtDW ->
hurojtxhba >= ssGetT ( S ) ) && ( _rtDW -> lsokswrh0d >= ssGetT ( S ) ) ) {
_rtB -> e2rqonsyao = 0.0 ; } else { j0hhbshz2o = _rtDW -> hurojtxhba ; lastU
= & _rtDW -> dg0bwrgz1t ; if ( _rtDW -> hurojtxhba < _rtDW -> lsokswrh0d ) {
if ( _rtDW -> lsokswrh0d < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> lsokswrh0d
; lastU = & _rtDW -> dhwgj24z5h ; } } else { if ( _rtDW -> hurojtxhba >=
ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> lsokswrh0d ; lastU = & _rtDW ->
dhwgj24z5h ; } } _rtB -> e2rqonsyao = ( _rtB -> nidjbvpyt5 - * lastU ) / (
ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> ldeea1p1ww = ( ( cfqhbkrmw3 * )
ssGetContStates ( S ) ) -> frfcp5rz22 ; _rtB -> nulvaxvar1 = _rtP -> P_274 *
_rtB -> ntxq2snrot ; _rtB -> o2nihsaxz0 = _rtP -> P_275 * _rtB -> ntxq2snrot
; _rtB -> eglcrpdqag = ( _rtB -> ldeea1p1ww + _rtB -> nulvaxvar1 ) + _rtB ->
e2rqonsyao ; _rtB -> dixqs1g40y = 0.0 ; _rtB -> dixqs1g40y += _rtP -> P_277 *
_rtX -> ccnqyqy5bg ; _rtB -> lnoo4wgtiw = _rtP -> P_278 * _rtB -> dixqs1g40y
; ssCallAccelRunBlock ( S , 26 , 851 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 852 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 853 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
kjyb00grhn = _rtP -> P_279 * _rtB -> eglcrpdqag ; ssCallAccelRunBlock ( S ,
26 , 855 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> jyc5vqrloa = _rtP -> P_280 * _rtB
-> jykbtpbcct ; _rtB -> pyt4v5x1ie = _rtB -> kjyb00grhn - _rtB -> jyc5vqrloa
; ssCallAccelRunBlock ( S , 26 , 858 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
penleup5yw = 0.0 ; _rtB -> penleup5yw += _rtP -> P_282 * _rtX -> efckm0ivgu ;
_rtB -> jomu1lqb5u = _rtP -> P_283 * _rtB -> penleup5yw ; ssCallAccelRunBlock
( S , 26 , 861 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW -> p5nimkmwn1 >= ssGetT
( S ) ) && ( _rtDW -> mvfhsh0waz >= ssGetT ( S ) ) ) { _rtB -> guih2ongku =
0.0 ; } else { j0hhbshz2o = _rtDW -> p5nimkmwn1 ; lastU = & _rtDW ->
agvcyw1f0l ; if ( _rtDW -> p5nimkmwn1 < _rtDW -> mvfhsh0waz ) { if ( _rtDW ->
mvfhsh0waz < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> mvfhsh0waz ; lastU = &
_rtDW -> cc1bpr21vd ; } } else { if ( _rtDW -> p5nimkmwn1 >= ssGetT ( S ) ) {
j0hhbshz2o = _rtDW -> mvfhsh0waz ; lastU = & _rtDW -> cc1bpr21vd ; } } _rtB
-> guih2ongku = ( _rtB -> jomu1lqb5u - * lastU ) / ( ssGetT ( S ) -
j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 , 863 , SS_CALL_MDL_OUTPUTS ) ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 864 ,
SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i < 4 ; i ++ ) { _rtB -> pjp54lsdsf [ i
] = 0.0 ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i ] * _rtB ->
f01pvxxhvn [ 0 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i + 4 ] *
_rtB -> f01pvxxhvn [ 1 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i
+ 8 ] * _rtB -> f01pvxxhvn [ 2 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB ->
mj52ye3fhg [ i + 12 ] * _rtB -> f01pvxxhvn [ 3 ] ; } ssCallAccelRunBlock ( S
, 26 , 866 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> asked2p3qh = _rtP -> P_284 *
_rtB -> fvjhga3og4 ; } _rtB -> dqibhyv33l = _rtP -> P_285 * _rtB ->
irhvcfxcsa ; _rtB -> akdt4l0pa4 = _rtB -> asked2p3qh - _rtB -> dqibhyv33l ;
_rtB -> mbcf3o2d3b = _rtP -> P_286 * _rtB -> akdt4l0pa4 ; if ( ( _rtDW ->
o0405brpgz >= ssGetT ( S ) ) && ( _rtDW -> acq3dyiyhd >= ssGetT ( S ) ) ) {
_rtB -> hq55ieycbz = 0.0 ; } else { j0hhbshz2o = _rtDW -> o0405brpgz ; lastU
= & _rtDW -> inlh4jzgm5 ; if ( _rtDW -> o0405brpgz < _rtDW -> acq3dyiyhd ) {
if ( _rtDW -> acq3dyiyhd < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> acq3dyiyhd
; lastU = & _rtDW -> dbnp2xyj1p ; } } else { if ( _rtDW -> o0405brpgz >=
ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> acq3dyiyhd ; lastU = & _rtDW ->
dbnp2xyj1p ; } } _rtB -> hq55ieycbz = ( _rtB -> mbcf3o2d3b - * lastU ) / (
ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> j1q3neqkwb = ( ( cfqhbkrmw3 * )
ssGetContStates ( S ) ) -> chsynbzd3y ; _rtB -> kdk3evhfbq = _rtP -> P_288 *
_rtB -> akdt4l0pa4 ; _rtB -> ej0uvfoa2v = _rtP -> P_289 * _rtB -> akdt4l0pa4
; _rtB -> m2ttpk1tmt = ( _rtB -> j1q3neqkwb + _rtB -> kdk3evhfbq ) + _rtB ->
hq55ieycbz ; _rtB -> h1ahxhx2po = 0.0 ; _rtB -> h1ahxhx2po += _rtP -> P_291 *
_rtX -> owholqk5yt ; _rtB -> gir5snnrwd = _rtP -> P_292 * _rtB -> h1ahxhx2po
; ssCallAccelRunBlock ( S , 26 , 878 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 879 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 880 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
j2dqme2d0f = _rtP -> P_293 * _rtB -> m2ttpk1tmt ; ssCallAccelRunBlock ( S ,
26 , 882 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> m2ry102cbu = _rtP -> P_294 * _rtB
-> penleup5yw ; _rtB -> pozqtc4xfd = _rtB -> j2dqme2d0f - _rtB -> m2ry102cbu
; ssCallAccelRunBlock ( S , 26 , 885 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
g3rb5bjdu0 = 0.0 ; _rtB -> g3rb5bjdu0 += _rtP -> P_296 * _rtX -> ig3uaiwoa2 ;
_rtB -> o4jpa32wvo = _rtP -> P_297 * _rtB -> g3rb5bjdu0 ; ssCallAccelRunBlock
( S , 26 , 888 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW -> lqwlakp4jj >= ssGetT
( S ) ) && ( _rtDW -> ggjg1s003h >= ssGetT ( S ) ) ) { _rtB -> guih2ongku =
0.0 ; } else { j0hhbshz2o = _rtDW -> lqwlakp4jj ; lastU = & _rtDW ->
hg3zs34v4n ; if ( _rtDW -> lqwlakp4jj < _rtDW -> ggjg1s003h ) { if ( _rtDW ->
ggjg1s003h < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> ggjg1s003h ; lastU = &
_rtDW -> bevwtdgkk5 ; } } else { if ( _rtDW -> lqwlakp4jj >= ssGetT ( S ) ) {
j0hhbshz2o = _rtDW -> ggjg1s003h ; lastU = & _rtDW -> bevwtdgkk5 ; } } _rtB
-> guih2ongku = ( _rtB -> o4jpa32wvo - * lastU ) / ( ssGetT ( S ) -
j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 , 890 , SS_CALL_MDL_OUTPUTS ) ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 891 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> l1a4zfzykx *= _rtP -> P_298 ; _rtB ->
mxbmrusayr = _rtP -> P_299 * _rtB -> l1a4zfzykx ; } _rtB -> ainedswxfy = _rtP
-> P_300 * _rtB -> e21bd0tfoz ; _rtB -> ppcaxpe4pk = _rtB -> mxbmrusayr -
_rtB -> ainedswxfy ; _rtB -> a14ae5ywsf = _rtP -> P_301 * _rtB -> ppcaxpe4pk
; if ( ( _rtDW -> g5flx1vu0d >= ssGetT ( S ) ) && ( _rtDW -> i03cehs32p >=
ssGetT ( S ) ) ) { _rtB -> jepwsqb0ud = 0.0 ; } else { j0hhbshz2o = _rtDW ->
g5flx1vu0d ; lastU = & _rtDW -> bzosdsme2i ; if ( _rtDW -> g5flx1vu0d < _rtDW
-> i03cehs32p ) { if ( _rtDW -> i03cehs32p < ssGetT ( S ) ) { j0hhbshz2o =
_rtDW -> i03cehs32p ; lastU = & _rtDW -> acheszdxnh ; } } else { if ( _rtDW
-> g5flx1vu0d >= ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> i03cehs32p ; lastU =
& _rtDW -> acheszdxnh ; } } _rtB -> jepwsqb0ud = ( _rtB -> a14ae5ywsf - *
lastU ) / ( ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> ganaqf2jzy = ( (
cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> p2bhqhyz1s ; _rtB -> cngvpidkxh =
_rtP -> P_303 * _rtB -> ppcaxpe4pk ; _rtB -> etxth0gwa0 = _rtP -> P_304 *
_rtB -> ppcaxpe4pk ; _rtB -> fd20jqfk10 = ( _rtB -> ganaqf2jzy + _rtB ->
cngvpidkxh ) + _rtB -> jepwsqb0ud ; _rtB -> e2dhszrqf2 = 0.0 ; _rtB ->
e2dhszrqf2 += _rtP -> P_306 * _rtX -> nd2es0pja2 ; _rtB -> ft2a4nbu4n = _rtP
-> P_307 * _rtB -> e2dhszrqf2 ; ssCallAccelRunBlock ( S , 26 , 904 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 905 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 906 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> ebsib3lbrq = _rtP -> P_308 * _rtB ->
fd20jqfk10 ; ssCallAccelRunBlock ( S , 26 , 908 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> hlwgllw0fl = _rtP -> P_309 * _rtB -> g3rb5bjdu0 ; _rtB -> hlbg03vbov
= _rtB -> ebsib3lbrq - _rtB -> hlwgllw0fl ; ssCallAccelRunBlock ( S , 26 ,
935 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 966 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> i1pqsldj3h = 0.0 ; _rtB -> i1pqsldj3h += _rtP
-> P_311 * _rtX -> hwvtodn0ry ; _rtB -> fzwnpjpxmp = _rtP -> P_312 * _rtB ->
i1pqsldj3h ; ssCallAccelRunBlock ( S , 26 , 969 , SS_CALL_MDL_OUTPUTS ) ; if
( ( _rtDW -> hrsnmvoy4j >= ssGetT ( S ) ) && ( _rtDW -> jymexjnm51 >= ssGetT
( S ) ) ) { _rtB -> guih2ongku = 0.0 ; } else { j0hhbshz2o = _rtDW ->
hrsnmvoy4j ; lastU = & _rtDW -> lmekbo340y ; if ( _rtDW -> hrsnmvoy4j < _rtDW
-> jymexjnm51 ) { if ( _rtDW -> jymexjnm51 < ssGetT ( S ) ) { j0hhbshz2o =
_rtDW -> jymexjnm51 ; lastU = & _rtDW -> m455ukdm4v ; } } else { if ( _rtDW
-> hrsnmvoy4j >= ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> jymexjnm51 ; lastU =
& _rtDW -> m455ukdm4v ; } } _rtB -> guih2ongku = ( _rtB -> fzwnpjpxmp - *
lastU ) / ( ssGetT ( S ) - j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 ,
971 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { for ( i =
0 ; i < 4 ; i ++ ) { _rtB -> f01pvxxhvn [ i ] = 0.0 ; _rtB -> f01pvxxhvn [ i
] += _rtP -> P_313 [ i ] * _rtB -> hr34hxvvfl [ 0 ] ; _rtB -> f01pvxxhvn [ i
] += _rtP -> P_313 [ i + 4 ] * _rtB -> hr34hxvvfl [ 1 ] ; _rtB -> f01pvxxhvn
[ i ] += _rtP -> P_313 [ i + 8 ] * _rtB -> hr34hxvvfl [ 2 ] ; _rtB ->
f01pvxxhvn [ i ] += _rtP -> P_313 [ i + 12 ] * _rtB -> hr34hxvvfl [ 3 ] ; }
ssCallAccelRunBlock ( S , 26 , 974 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
prgyjahbae = _rtP -> P_314 * _rtB -> d5fplfzlor ; _rtB -> ceudn3yjvp = _rtP
-> P_315 * _rtB -> prgyjahbae ; } _rtB -> i3bfzytua3 = _rtP -> P_316 * _rtB
-> ejeeikgi2h ; _rtB -> kkdxw2wgm2 = _rtB -> ceudn3yjvp - _rtB -> i3bfzytua3
; _rtB -> pvgkci1ovv = _rtP -> P_317 * _rtB -> kkdxw2wgm2 ; if ( ( _rtDW ->
gb4jvzidh0 >= ssGetT ( S ) ) && ( _rtDW -> fsbsshuzyr >= ssGetT ( S ) ) ) {
_rtB -> abiqixgtra = 0.0 ; } else { j0hhbshz2o = _rtDW -> gb4jvzidh0 ; lastU
= & _rtDW -> ntgipn1ph0 ; if ( _rtDW -> gb4jvzidh0 < _rtDW -> fsbsshuzyr ) {
if ( _rtDW -> fsbsshuzyr < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> fsbsshuzyr
; lastU = & _rtDW -> molarj3aht ; } } else { if ( _rtDW -> gb4jvzidh0 >=
ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> fsbsshuzyr ; lastU = & _rtDW ->
molarj3aht ; } } _rtB -> abiqixgtra = ( _rtB -> pvgkci1ovv - * lastU ) / (
ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> ncck0bxbwc = ( ( cfqhbkrmw3 * )
ssGetContStates ( S ) ) -> hsil0chis3 ; _rtB -> bzxibjen1w = _rtP -> P_319 *
_rtB -> kkdxw2wgm2 ; _rtB -> od4rewcypc = _rtP -> P_320 * _rtB -> kkdxw2wgm2
; _rtB -> fpzpt1vcd4 = ( _rtB -> ncck0bxbwc + _rtB -> bzxibjen1w ) + _rtB ->
abiqixgtra ; _rtB -> msoia4k5ev = 0.0 ; _rtB -> msoia4k5ev += _rtP -> P_322 *
_rtX -> fdpg2dhqer ; _rtB -> fbgb52dnaw = _rtP -> P_323 * _rtB -> msoia4k5ev
; ssCallAccelRunBlock ( S , 26 , 987 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 988 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 989 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
awqai25rn1 = _rtP -> P_324 * _rtB -> fpzpt1vcd4 ; ssCallAccelRunBlock ( S ,
26 , 991 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> jxpz3d0mo3 = _rtP -> P_325 * _rtB
-> i1pqsldj3h ; _rtB -> p4u52cdz0j = _rtB -> awqai25rn1 - _rtB -> jxpz3d0mo3
; ssCallAccelRunBlock ( S , 26 , 994 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
pdomsv135f = 0.0 ; _rtB -> pdomsv135f += _rtP -> P_327 * _rtX -> pkmi5ynvrb ;
_rtB -> b5bg5sylim = _rtP -> P_328 * _rtB -> pdomsv135f ; ssCallAccelRunBlock
( S , 26 , 997 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW -> fiuzhnygr2 >= ssGetT
( S ) ) && ( _rtDW -> axg0pokrgz >= ssGetT ( S ) ) ) { _rtB -> guih2ongku =
0.0 ; } else { j0hhbshz2o = _rtDW -> fiuzhnygr2 ; lastU = & _rtDW ->
bw53tndja1 ; if ( _rtDW -> fiuzhnygr2 < _rtDW -> axg0pokrgz ) { if ( _rtDW ->
axg0pokrgz < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> axg0pokrgz ; lastU = &
_rtDW -> oerq0ak54m ; } } else { if ( _rtDW -> fiuzhnygr2 >= ssGetT ( S ) ) {
j0hhbshz2o = _rtDW -> axg0pokrgz ; lastU = & _rtDW -> oerq0ak54m ; } } _rtB
-> guih2ongku = ( _rtB -> b5bg5sylim - * lastU ) / ( ssGetT ( S ) -
j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 , 999 , SS_CALL_MDL_OUTPUTS ) ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 1000 ,
SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i < 4 ; i ++ ) { _rtB -> pjp54lsdsf [ i
] = 0.0 ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i ] * _rtB ->
f01pvxxhvn [ 0 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i + 4 ] *
_rtB -> f01pvxxhvn [ 1 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i
+ 8 ] * _rtB -> f01pvxxhvn [ 2 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB ->
mj52ye3fhg [ i + 12 ] * _rtB -> f01pvxxhvn [ 3 ] ; } ssCallAccelRunBlock ( S
, 26 , 1002 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> ibxjwxodwx = _rtP -> P_329 *
_rtB -> d5fplfzlor ; } _rtB -> io2lwtrg02 = _rtP -> P_330 * _rtB ->
gxcwwxfexc ; _rtB -> o3xwetsl3v = _rtB -> ibxjwxodwx - _rtB -> io2lwtrg02 ;
_rtB -> kmvcfmr1jd = _rtP -> P_331 * _rtB -> o3xwetsl3v ; if ( ( _rtDW ->
hjjy0flo5v >= ssGetT ( S ) ) && ( _rtDW -> agoglty3xy >= ssGetT ( S ) ) ) {
_rtB -> lrgpujcz4i = 0.0 ; } else { j0hhbshz2o = _rtDW -> hjjy0flo5v ; lastU
= & _rtDW -> bllgnsd24p ; if ( _rtDW -> hjjy0flo5v < _rtDW -> agoglty3xy ) {
if ( _rtDW -> agoglty3xy < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> agoglty3xy
; lastU = & _rtDW -> j2hdn4t1kc ; } } else { if ( _rtDW -> hjjy0flo5v >=
ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> agoglty3xy ; lastU = & _rtDW ->
j2hdn4t1kc ; } } _rtB -> lrgpujcz4i = ( _rtB -> kmvcfmr1jd - * lastU ) / (
ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> n0fkpox1ba = ( ( cfqhbkrmw3 * )
ssGetContStates ( S ) ) -> cph23tcm3m ; _rtB -> onvi15v2km = _rtP -> P_333 *
_rtB -> o3xwetsl3v ; _rtB -> oeqrqi1yhg = _rtP -> P_334 * _rtB -> o3xwetsl3v
; _rtB -> o144uanyhx = ( _rtB -> n0fkpox1ba + _rtB -> onvi15v2km ) + _rtB ->
lrgpujcz4i ; _rtB -> plt3zphlp0 = 0.0 ; _rtB -> plt3zphlp0 += _rtP -> P_336 *
_rtX -> jccjfuzxai ; _rtB -> pzysbvittb = _rtP -> P_337 * _rtB -> plt3zphlp0
; ssCallAccelRunBlock ( S , 26 , 1014 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1015 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1016 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
psqwk3q53t = _rtP -> P_338 * _rtB -> o144uanyhx ; ssCallAccelRunBlock ( S ,
26 , 1018 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> ovir5kbxet = _rtP -> P_339 * _rtB
-> pdomsv135f ; _rtB -> f1al4weaso = _rtB -> psqwk3q53t - _rtB -> ovir5kbxet
; ssCallAccelRunBlock ( S , 26 , 1021 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
oetq41it5s = 0.0 ; _rtB -> oetq41it5s += _rtP -> P_341 * _rtX -> mvd2pevwkz ;
_rtB -> cpo1oiounj = _rtP -> P_342 * _rtB -> oetq41it5s ; ssCallAccelRunBlock
( S , 26 , 1024 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW -> engdnf2o11 >=
ssGetT ( S ) ) && ( _rtDW -> imygdvmpjz >= ssGetT ( S ) ) ) { _rtB ->
guih2ongku = 0.0 ; } else { j0hhbshz2o = _rtDW -> engdnf2o11 ; lastU = &
_rtDW -> lnidc1joj2 ; if ( _rtDW -> engdnf2o11 < _rtDW -> imygdvmpjz ) { if (
_rtDW -> imygdvmpjz < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> imygdvmpjz ;
lastU = & _rtDW -> hlaq0fchte ; } } else { if ( _rtDW -> engdnf2o11 >= ssGetT
( S ) ) { j0hhbshz2o = _rtDW -> imygdvmpjz ; lastU = & _rtDW -> hlaq0fchte ;
} } _rtB -> guih2ongku = ( _rtB -> cpo1oiounj - * lastU ) / ( ssGetT ( S ) -
j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 , 1026 , SS_CALL_MDL_OUTPUTS )
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 1027 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> jlcj4frrgy *= _rtP -> P_343 ; _rtB ->
ma2jhdiham = _rtP -> P_344 * _rtB -> jlcj4frrgy ; } _rtB -> fl0q0sz03u = _rtP
-> P_345 * _rtB -> h4eeh2fwvk ; _rtB -> n3ckcvkpht = _rtB -> ma2jhdiham -
_rtB -> fl0q0sz03u ; _rtB -> md0fds2ykq = _rtP -> P_346 * _rtB -> n3ckcvkpht
; if ( ( _rtDW -> gth35uto5a >= ssGetT ( S ) ) && ( _rtDW -> hqciimvqbr >=
ssGetT ( S ) ) ) { _rtB -> lz5nwyf5ra = 0.0 ; } else { j0hhbshz2o = _rtDW ->
gth35uto5a ; lastU = & _rtDW -> bcyswmosff ; if ( _rtDW -> gth35uto5a < _rtDW
-> hqciimvqbr ) { if ( _rtDW -> hqciimvqbr < ssGetT ( S ) ) { j0hhbshz2o =
_rtDW -> hqciimvqbr ; lastU = & _rtDW -> hpawn23ndd ; } } else { if ( _rtDW
-> gth35uto5a >= ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> hqciimvqbr ; lastU =
& _rtDW -> hpawn23ndd ; } } _rtB -> lz5nwyf5ra = ( _rtB -> md0fds2ykq - *
lastU ) / ( ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> hqvao0haw0 = ( (
cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> ksy2o0tkwn ; _rtB -> bkzwqt2egm =
_rtP -> P_348 * _rtB -> n3ckcvkpht ; _rtB -> pfba4bin2v = _rtP -> P_349 *
_rtB -> n3ckcvkpht ; _rtB -> ghk0cxh2to = ( _rtB -> hqvao0haw0 + _rtB ->
bkzwqt2egm ) + _rtB -> lz5nwyf5ra ; _rtB -> fasaaqypps = 0.0 ; _rtB ->
fasaaqypps += _rtP -> P_351 * _rtX -> nw4s40wdz2 ; _rtB -> ad5y31rmda = _rtP
-> P_352 * _rtB -> fasaaqypps ; ssCallAccelRunBlock ( S , 26 , 1040 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 1041 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 1042 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> bhg5nwb50l = _rtP -> P_353 * _rtB ->
ghk0cxh2to ; ssCallAccelRunBlock ( S , 26 , 1044 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> ktqy43hug2 = _rtP -> P_354 * _rtB -> oetq41it5s ; _rtB -> bperb2as5o
= _rtB -> bhg5nwb50l - _rtB -> ktqy43hug2 ; ssCallAccelRunBlock ( S , 26 ,
1071 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 1102 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> jezc55iqz1 = 0.0 ; _rtB -> jezc55iqz1 += _rtP
-> P_356 * _rtX -> pb403lheya ; _rtB -> ab0retugfm = _rtP -> P_357 * _rtB ->
jezc55iqz1 ; ssCallAccelRunBlock ( S , 26 , 1105 , SS_CALL_MDL_OUTPUTS ) ; if
( ( _rtDW -> j5azrn5jaj >= ssGetT ( S ) ) && ( _rtDW -> idppvjqgxy >= ssGetT
( S ) ) ) { _rtB -> guih2ongku = 0.0 ; } else { j0hhbshz2o = _rtDW ->
j5azrn5jaj ; lastU = & _rtDW -> iksuvkx2h2 ; if ( _rtDW -> j5azrn5jaj < _rtDW
-> idppvjqgxy ) { if ( _rtDW -> idppvjqgxy < ssGetT ( S ) ) { j0hhbshz2o =
_rtDW -> idppvjqgxy ; lastU = & _rtDW -> d0g45ks2pg ; } } else { if ( _rtDW
-> j5azrn5jaj >= ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> idppvjqgxy ; lastU =
& _rtDW -> d0g45ks2pg ; } } _rtB -> guih2ongku = ( _rtB -> ab0retugfm - *
lastU ) / ( ssGetT ( S ) - j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 ,
1107 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { for ( i =
0 ; i < 4 ; i ++ ) { _rtB -> f01pvxxhvn [ i ] = 0.0 ; _rtB -> f01pvxxhvn [ i
] += _rtP -> P_358 [ i ] * _rtB -> o4ufeiwnae [ 0 ] ; _rtB -> f01pvxxhvn [ i
] += _rtP -> P_358 [ i + 4 ] * _rtB -> o4ufeiwnae [ 1 ] ; _rtB -> f01pvxxhvn
[ i ] += _rtP -> P_358 [ i + 8 ] * _rtB -> o4ufeiwnae [ 2 ] ; _rtB ->
f01pvxxhvn [ i ] += _rtP -> P_358 [ i + 12 ] * _rtB -> o4ufeiwnae [ 3 ] ; }
ssCallAccelRunBlock ( S , 26 , 1110 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
e5nrbsa0mk = _rtP -> P_359 * _rtB -> f5qbeq0xp4 ; _rtB -> ljldpzmjsh = _rtP
-> P_360 * _rtB -> e5nrbsa0mk ; } _rtB -> jwy4sxy0do = _rtP -> P_361 * _rtB
-> pjtv53t1ga ; _rtB -> ggrychdh2g = _rtB -> ljldpzmjsh - _rtB -> jwy4sxy0do
; _rtB -> cpdqurfm2a = _rtP -> P_362 * _rtB -> ggrychdh2g ; if ( ( _rtDW ->
g1iciqjkj1 >= ssGetT ( S ) ) && ( _rtDW -> a5mtwtffo4 >= ssGetT ( S ) ) ) {
_rtB -> lvqlm3ovxu = 0.0 ; } else { j0hhbshz2o = _rtDW -> g1iciqjkj1 ; lastU
= & _rtDW -> btjr4tvdt4 ; if ( _rtDW -> g1iciqjkj1 < _rtDW -> a5mtwtffo4 ) {
if ( _rtDW -> a5mtwtffo4 < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> a5mtwtffo4
; lastU = & _rtDW -> eaq5fgtm5y ; } } else { if ( _rtDW -> g1iciqjkj1 >=
ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> a5mtwtffo4 ; lastU = & _rtDW ->
eaq5fgtm5y ; } } _rtB -> lvqlm3ovxu = ( _rtB -> cpdqurfm2a - * lastU ) / (
ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> bm2kl31bab = ( ( cfqhbkrmw3 * )
ssGetContStates ( S ) ) -> cdfctdfq0w ; _rtB -> kt0tennyty = _rtP -> P_364 *
_rtB -> ggrychdh2g ; _rtB -> ow5lrns1ak = _rtP -> P_365 * _rtB -> ggrychdh2g
; _rtB -> dmmbh00ltl = ( _rtB -> bm2kl31bab + _rtB -> kt0tennyty ) + _rtB ->
lvqlm3ovxu ; _rtB -> dox1e0hdei = 0.0 ; _rtB -> dox1e0hdei += _rtP -> P_367 *
_rtX -> nmhaueqlt1 ; _rtB -> j2ocxan4o0 = _rtP -> P_368 * _rtB -> dox1e0hdei
; ssCallAccelRunBlock ( S , 26 , 1123 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1124 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1125 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
fmauqvgw2m = _rtP -> P_369 * _rtB -> dmmbh00ltl ; ssCallAccelRunBlock ( S ,
26 , 1127 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> pbrtts2zl2 = _rtP -> P_370 * _rtB
-> jezc55iqz1 ; _rtB -> bu1tbhjpdv = _rtB -> fmauqvgw2m - _rtB -> pbrtts2zl2
; ssCallAccelRunBlock ( S , 26 , 1130 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
d1qvaj5al1 = 0.0 ; _rtB -> d1qvaj5al1 += _rtP -> P_372 * _rtX -> gt3adnl5hb ;
_rtB -> ofnxohnqca = _rtP -> P_373 * _rtB -> d1qvaj5al1 ; ssCallAccelRunBlock
( S , 26 , 1133 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW -> hezyb4c2n0 >=
ssGetT ( S ) ) && ( _rtDW -> ki4k3pwqpo >= ssGetT ( S ) ) ) { _rtB ->
guih2ongku = 0.0 ; } else { j0hhbshz2o = _rtDW -> hezyb4c2n0 ; lastU = &
_rtDW -> a3jqkmyzub ; if ( _rtDW -> hezyb4c2n0 < _rtDW -> ki4k3pwqpo ) { if (
_rtDW -> ki4k3pwqpo < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> ki4k3pwqpo ;
lastU = & _rtDW -> n14saw03pu ; } } else { if ( _rtDW -> hezyb4c2n0 >= ssGetT
( S ) ) { j0hhbshz2o = _rtDW -> ki4k3pwqpo ; lastU = & _rtDW -> n14saw03pu ;
} } _rtB -> guih2ongku = ( _rtB -> ofnxohnqca - * lastU ) / ( ssGetT ( S ) -
j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 , 1135 , SS_CALL_MDL_OUTPUTS )
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 1136 ,
SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i < 4 ; i ++ ) { _rtB -> pjp54lsdsf [ i
] = 0.0 ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i ] * _rtB ->
f01pvxxhvn [ 0 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i + 4 ] *
_rtB -> f01pvxxhvn [ 1 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i
+ 8 ] * _rtB -> f01pvxxhvn [ 2 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB ->
mj52ye3fhg [ i + 12 ] * _rtB -> f01pvxxhvn [ 3 ] ; } ssCallAccelRunBlock ( S
, 26 , 1138 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> jxmgxkbfnk = _rtP -> P_374 *
_rtB -> f5qbeq0xp4 ; } _rtB -> eikvkvvrdc = _rtP -> P_375 * _rtB ->
jd2m5t2awx ; _rtB -> gbw1cnvzqy = _rtB -> jxmgxkbfnk - _rtB -> eikvkvvrdc ;
_rtB -> n553trglzx = _rtP -> P_376 * _rtB -> gbw1cnvzqy ; if ( ( _rtDW ->
piihx4u5k0 >= ssGetT ( S ) ) && ( _rtDW -> ok5r2wnawf >= ssGetT ( S ) ) ) {
_rtB -> hpdlyyl0et = 0.0 ; } else { j0hhbshz2o = _rtDW -> piihx4u5k0 ; lastU
= & _rtDW -> afnt3mz1hb ; if ( _rtDW -> piihx4u5k0 < _rtDW -> ok5r2wnawf ) {
if ( _rtDW -> ok5r2wnawf < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> ok5r2wnawf
; lastU = & _rtDW -> fs5vvpaw21 ; } } else { if ( _rtDW -> piihx4u5k0 >=
ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> ok5r2wnawf ; lastU = & _rtDW ->
fs5vvpaw21 ; } } _rtB -> hpdlyyl0et = ( _rtB -> n553trglzx - * lastU ) / (
ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> ovnrqoaatw = ( ( cfqhbkrmw3 * )
ssGetContStates ( S ) ) -> e0skt04bhf ; _rtB -> lslchzbyj5 = _rtP -> P_378 *
_rtB -> gbw1cnvzqy ; _rtB -> pkqczepwyj = _rtP -> P_379 * _rtB -> gbw1cnvzqy
; _rtB -> ham03ljnzl = ( _rtB -> ovnrqoaatw + _rtB -> lslchzbyj5 ) + _rtB ->
hpdlyyl0et ; _rtB -> ga1chveqv3 = 0.0 ; _rtB -> ga1chveqv3 += _rtP -> P_381 *
_rtX -> pmnyfm5h5u ; _rtB -> fujsn2boel = _rtP -> P_382 * _rtB -> ga1chveqv3
; ssCallAccelRunBlock ( S , 26 , 1150 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1151 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1152 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
bjd5eahk0y = _rtP -> P_383 * _rtB -> ham03ljnzl ; ssCallAccelRunBlock ( S ,
26 , 1154 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> kxmacejdpk = _rtP -> P_384 * _rtB
-> d1qvaj5al1 ; _rtB -> ll3w5whb3u = _rtB -> bjd5eahk0y - _rtB -> kxmacejdpk
; ssCallAccelRunBlock ( S , 26 , 1157 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
mlfqfffaqp = 0.0 ; _rtB -> mlfqfffaqp += _rtP -> P_386 * _rtX -> nddgccshex ;
_rtB -> p2mwsr20yb = _rtP -> P_387 * _rtB -> mlfqfffaqp ; ssCallAccelRunBlock
( S , 26 , 1160 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW -> ivto2yfcpr >=
ssGetT ( S ) ) && ( _rtDW -> odwx5gyepo >= ssGetT ( S ) ) ) { _rtB ->
guih2ongku = 0.0 ; } else { j0hhbshz2o = _rtDW -> ivto2yfcpr ; lastU = &
_rtDW -> hu4itulmza ; if ( _rtDW -> ivto2yfcpr < _rtDW -> odwx5gyepo ) { if (
_rtDW -> odwx5gyepo < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> odwx5gyepo ;
lastU = & _rtDW -> ewdfbs3mtp ; } } else { if ( _rtDW -> ivto2yfcpr >= ssGetT
( S ) ) { j0hhbshz2o = _rtDW -> odwx5gyepo ; lastU = & _rtDW -> ewdfbs3mtp ;
} } _rtB -> guih2ongku = ( _rtB -> p2mwsr20yb - * lastU ) / ( ssGetT ( S ) -
j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 , 1162 , SS_CALL_MDL_OUTPUTS )
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 1163 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> pchp0ejwcl *= _rtP -> P_388 ; _rtB ->
nz3yswlnve = _rtP -> P_389 * _rtB -> pchp0ejwcl ; } _rtB -> dlcunozrwp = _rtP
-> P_390 * _rtB -> fqocnpspxc ; _rtB -> nvwvzfgr4a = _rtB -> nz3yswlnve -
_rtB -> dlcunozrwp ; _rtB -> n4ekgqxrgn = _rtP -> P_391 * _rtB -> nvwvzfgr4a
; if ( ( _rtDW -> ngx20kzjdu >= ssGetT ( S ) ) && ( _rtDW -> io5qz1bfri >=
ssGetT ( S ) ) ) { _rtB -> j5rmpkevim = 0.0 ; } else { j0hhbshz2o = _rtDW ->
ngx20kzjdu ; lastU = & _rtDW -> cn0m0dnvvv ; if ( _rtDW -> ngx20kzjdu < _rtDW
-> io5qz1bfri ) { if ( _rtDW -> io5qz1bfri < ssGetT ( S ) ) { j0hhbshz2o =
_rtDW -> io5qz1bfri ; lastU = & _rtDW -> fud4qkvc5l ; } } else { if ( _rtDW
-> ngx20kzjdu >= ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> io5qz1bfri ; lastU =
& _rtDW -> fud4qkvc5l ; } } _rtB -> j5rmpkevim = ( _rtB -> n4ekgqxrgn - *
lastU ) / ( ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> bgfjugf0jw = ( (
cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> k5ycu1q42c ; _rtB -> czkn3ygfkf =
_rtP -> P_393 * _rtB -> nvwvzfgr4a ; _rtB -> acumsenz15 = _rtP -> P_394 *
_rtB -> nvwvzfgr4a ; _rtB -> bhywplrvnl = ( _rtB -> bgfjugf0jw + _rtB ->
czkn3ygfkf ) + _rtB -> j5rmpkevim ; _rtB -> mdq3teucpz = 0.0 ; _rtB ->
mdq3teucpz += _rtP -> P_396 * _rtX -> k4tkggdnnr ; _rtB -> apturjtxro = _rtP
-> P_397 * _rtB -> mdq3teucpz ; ssCallAccelRunBlock ( S , 26 , 1176 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 1177 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 1178 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> gulfffis41 = _rtP -> P_398 * _rtB ->
bhywplrvnl ; ssCallAccelRunBlock ( S , 26 , 1180 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> epktrm1za5 = _rtP -> P_399 * _rtB -> mlfqfffaqp ; _rtB -> fy0eubivg0
= _rtB -> gulfffis41 - _rtB -> epktrm1za5 ; ssCallAccelRunBlock ( S , 26 ,
1207 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 1238 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> ektd4bmw1w = 0.0 ; _rtB -> ektd4bmw1w += _rtP
-> P_401 * _rtX -> mxeiruq5kr ; _rtB -> gjgpfapzeu = _rtP -> P_402 * _rtB ->
ektd4bmw1w ; ssCallAccelRunBlock ( S , 26 , 1241 , SS_CALL_MDL_OUTPUTS ) ; if
( ( _rtDW -> ahzdlyt1hz >= ssGetT ( S ) ) && ( _rtDW -> kkhc1hmdrl >= ssGetT
( S ) ) ) { _rtB -> guih2ongku = 0.0 ; } else { j0hhbshz2o = _rtDW ->
ahzdlyt1hz ; lastU = & _rtDW -> ixptss4bts ; if ( _rtDW -> ahzdlyt1hz < _rtDW
-> kkhc1hmdrl ) { if ( _rtDW -> kkhc1hmdrl < ssGetT ( S ) ) { j0hhbshz2o =
_rtDW -> kkhc1hmdrl ; lastU = & _rtDW -> akh4h1zg23 ; } } else { if ( _rtDW
-> ahzdlyt1hz >= ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> kkhc1hmdrl ; lastU =
& _rtDW -> akh4h1zg23 ; } } _rtB -> guih2ongku = ( _rtB -> gjgpfapzeu - *
lastU ) / ( ssGetT ( S ) - j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 ,
1243 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { for ( i =
0 ; i < 4 ; i ++ ) { _rtB -> f01pvxxhvn [ i ] = 0.0 ; _rtB -> f01pvxxhvn [ i
] += _rtP -> P_403 [ i ] * _rtB -> c4kgqb2gcs [ 0 ] ; _rtB -> f01pvxxhvn [ i
] += _rtP -> P_403 [ i + 4 ] * _rtB -> c4kgqb2gcs [ 1 ] ; _rtB -> f01pvxxhvn
[ i ] += _rtP -> P_403 [ i + 8 ] * _rtB -> c4kgqb2gcs [ 2 ] ; _rtB ->
f01pvxxhvn [ i ] += _rtP -> P_403 [ i + 12 ] * _rtB -> c4kgqb2gcs [ 3 ] ; }
ssCallAccelRunBlock ( S , 26 , 1246 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
bsy2ir202u = _rtP -> P_404 * _rtB -> ok3z4yxyfo ; _rtB -> djt0yfd5ok = _rtP
-> P_405 * _rtB -> bsy2ir202u ; } _rtB -> ikaloso2aj = _rtP -> P_406 * _rtB
-> piyok5iwts ; _rtB -> ds4u35qx1f = _rtB -> djt0yfd5ok - _rtB -> ikaloso2aj
; _rtB -> k2n1xiq5z0 = _rtP -> P_407 * _rtB -> ds4u35qx1f ; if ( ( _rtDW ->
lwlaw2shm0 >= ssGetT ( S ) ) && ( _rtDW -> jf0lqrg3bd >= ssGetT ( S ) ) ) {
_rtB -> cilpxp5dfo = 0.0 ; } else { j0hhbshz2o = _rtDW -> lwlaw2shm0 ; lastU
= & _rtDW -> ijbu1a3mnl ; if ( _rtDW -> lwlaw2shm0 < _rtDW -> jf0lqrg3bd ) {
if ( _rtDW -> jf0lqrg3bd < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> jf0lqrg3bd
; lastU = & _rtDW -> fmfwxfvqoe ; } } else { if ( _rtDW -> lwlaw2shm0 >=
ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> jf0lqrg3bd ; lastU = & _rtDW ->
fmfwxfvqoe ; } } _rtB -> cilpxp5dfo = ( _rtB -> k2n1xiq5z0 - * lastU ) / (
ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> nulyll0uz4 = ( ( cfqhbkrmw3 * )
ssGetContStates ( S ) ) -> lmjo1j5prc ; _rtB -> cl43aaekxa = _rtP -> P_409 *
_rtB -> ds4u35qx1f ; _rtB -> dv0t3hxt1n = _rtP -> P_410 * _rtB -> ds4u35qx1f
; _rtB -> gy2orym5qo = ( _rtB -> nulyll0uz4 + _rtB -> cl43aaekxa ) + _rtB ->
cilpxp5dfo ; _rtB -> cilwkwivsv = 0.0 ; _rtB -> cilwkwivsv += _rtP -> P_412 *
_rtX -> mgv01d2cjw ; _rtB -> gedrcejq23 = _rtP -> P_413 * _rtB -> cilwkwivsv
; ssCallAccelRunBlock ( S , 26 , 1259 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1260 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1261 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
m105hvmryp = _rtP -> P_414 * _rtB -> gy2orym5qo ; ssCallAccelRunBlock ( S ,
26 , 1263 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> h2yyeiqj2l = _rtP -> P_415 * _rtB
-> ektd4bmw1w ; _rtB -> ite1vno4hy = _rtB -> m105hvmryp - _rtB -> h2yyeiqj2l
; ssCallAccelRunBlock ( S , 26 , 1266 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
cju0gfcbxa = 0.0 ; _rtB -> cju0gfcbxa += _rtP -> P_417 * _rtX -> g5vybs2yfi ;
_rtB -> io44b2wfxq = _rtP -> P_418 * _rtB -> cju0gfcbxa ; ssCallAccelRunBlock
( S , 26 , 1269 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW -> m5xzpfc1il >=
ssGetT ( S ) ) && ( _rtDW -> k3p3z2moz2 >= ssGetT ( S ) ) ) { _rtB ->
guih2ongku = 0.0 ; } else { j0hhbshz2o = _rtDW -> m5xzpfc1il ; lastU = &
_rtDW -> czej0oyj0v ; if ( _rtDW -> m5xzpfc1il < _rtDW -> k3p3z2moz2 ) { if (
_rtDW -> k3p3z2moz2 < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> k3p3z2moz2 ;
lastU = & _rtDW -> kaja0vlux0 ; } } else { if ( _rtDW -> m5xzpfc1il >= ssGetT
( S ) ) { j0hhbshz2o = _rtDW -> k3p3z2moz2 ; lastU = & _rtDW -> kaja0vlux0 ;
} } _rtB -> guih2ongku = ( _rtB -> io44b2wfxq - * lastU ) / ( ssGetT ( S ) -
j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 , 1271 , SS_CALL_MDL_OUTPUTS )
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 1272 ,
SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i < 4 ; i ++ ) { _rtB -> pjp54lsdsf [ i
] = 0.0 ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i ] * _rtB ->
f01pvxxhvn [ 0 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i + 4 ] *
_rtB -> f01pvxxhvn [ 1 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB -> mj52ye3fhg [ i
+ 8 ] * _rtB -> f01pvxxhvn [ 2 ] ; _rtB -> pjp54lsdsf [ i ] += _rtB ->
mj52ye3fhg [ i + 12 ] * _rtB -> f01pvxxhvn [ 3 ] ; } ssCallAccelRunBlock ( S
, 26 , 1274 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> bfn2ia4w1b = _rtP -> P_419 *
_rtB -> ok3z4yxyfo ; } _rtB -> fs4aiocymj = _rtP -> P_420 * _rtB ->
hqbvo1rsxu ; _rtB -> fe32b3hkdb = _rtB -> bfn2ia4w1b - _rtB -> fs4aiocymj ;
_rtB -> ftmscilcju = _rtP -> P_421 * _rtB -> fe32b3hkdb ; if ( ( _rtDW ->
jwjv4dmxil >= ssGetT ( S ) ) && ( _rtDW -> lyok1yozh4 >= ssGetT ( S ) ) ) {
_rtB -> asr3umwumk = 0.0 ; } else { j0hhbshz2o = _rtDW -> jwjv4dmxil ; lastU
= & _rtDW -> pbpp4gmqys ; if ( _rtDW -> jwjv4dmxil < _rtDW -> lyok1yozh4 ) {
if ( _rtDW -> lyok1yozh4 < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> lyok1yozh4
; lastU = & _rtDW -> e4rsirdlj2 ; } } else { if ( _rtDW -> jwjv4dmxil >=
ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> lyok1yozh4 ; lastU = & _rtDW ->
e4rsirdlj2 ; } } _rtB -> asr3umwumk = ( _rtB -> ftmscilcju - * lastU ) / (
ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> ey5dhldvoy = ( ( cfqhbkrmw3 * )
ssGetContStates ( S ) ) -> mbti4ipw3j ; _rtB -> gfwzvrgbb3 = _rtP -> P_423 *
_rtB -> fe32b3hkdb ; _rtB -> fyknhrqbo4 = _rtP -> P_424 * _rtB -> fe32b3hkdb
; _rtB -> bnkop2gy3k = ( _rtB -> ey5dhldvoy + _rtB -> gfwzvrgbb3 ) + _rtB ->
asr3umwumk ; _rtB -> c251tm4hyx = 0.0 ; _rtB -> c251tm4hyx += _rtP -> P_426 *
_rtX -> glghzxiyqq ; _rtB -> ig2ozehlaq = _rtP -> P_427 * _rtB -> c251tm4hyx
; ssCallAccelRunBlock ( S , 26 , 1286 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1287 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1288 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
f5nbxvbjtj = _rtP -> P_428 * _rtB -> bnkop2gy3k ; ssCallAccelRunBlock ( S ,
26 , 1290 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> hdfxjbmqsy = _rtP -> P_429 * _rtB
-> cju0gfcbxa ; _rtB -> fbu1ktdpcw = _rtB -> f5nbxvbjtj - _rtB -> hdfxjbmqsy
; ssCallAccelRunBlock ( S , 26 , 1293 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
nyuu0kwz0z = 0.0 ; _rtB -> nyuu0kwz0z += _rtP -> P_431 * _rtX -> ntf0pkglvk ;
_rtB -> owm1b3loru = _rtP -> P_432 * _rtB -> nyuu0kwz0z ; ssCallAccelRunBlock
( S , 26 , 1296 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW -> jacpkfor01 >=
ssGetT ( S ) ) && ( _rtDW -> fu030l101l >= ssGetT ( S ) ) ) { _rtB ->
guih2ongku = 0.0 ; } else { j0hhbshz2o = _rtDW -> jacpkfor01 ; lastU = &
_rtDW -> p4hdnk4r1v ; if ( _rtDW -> jacpkfor01 < _rtDW -> fu030l101l ) { if (
_rtDW -> fu030l101l < ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> fu030l101l ;
lastU = & _rtDW -> haedbnc4qr ; } } else { if ( _rtDW -> jacpkfor01 >= ssGetT
( S ) ) { j0hhbshz2o = _rtDW -> fu030l101l ; lastU = & _rtDW -> haedbnc4qr ;
} } _rtB -> guih2ongku = ( _rtB -> owm1b3loru - * lastU ) / ( ssGetT ( S ) -
j0hhbshz2o ) ; } ssCallAccelRunBlock ( S , 26 , 1298 , SS_CALL_MDL_OUTPUTS )
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 26 , 1299 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> p3jdscy5m4 *= _rtP -> P_433 ; _rtB ->
mucbhbxkmi = _rtP -> P_434 * _rtB -> p3jdscy5m4 ; } _rtB -> kgtfq3uvtp = _rtP
-> P_435 * _rtB -> hsnfguvswh ; _rtB -> nzkjwfwm5s = _rtB -> mucbhbxkmi -
_rtB -> kgtfq3uvtp ; _rtB -> lyozvblyxh = _rtP -> P_436 * _rtB -> nzkjwfwm5s
; if ( ( _rtDW -> lggckakxot >= ssGetT ( S ) ) && ( _rtDW -> fydwxywx3a >=
ssGetT ( S ) ) ) { _rtB -> nywoculevv = 0.0 ; } else { j0hhbshz2o = _rtDW ->
lggckakxot ; lastU = & _rtDW -> mopgtvoupi ; if ( _rtDW -> lggckakxot < _rtDW
-> fydwxywx3a ) { if ( _rtDW -> fydwxywx3a < ssGetT ( S ) ) { j0hhbshz2o =
_rtDW -> fydwxywx3a ; lastU = & _rtDW -> luk5pugjpa ; } } else { if ( _rtDW
-> lggckakxot >= ssGetT ( S ) ) { j0hhbshz2o = _rtDW -> fydwxywx3a ; lastU =
& _rtDW -> luk5pugjpa ; } } _rtB -> nywoculevv = ( _rtB -> lyozvblyxh - *
lastU ) / ( ssGetT ( S ) - j0hhbshz2o ) ; } _rtB -> ptqhor1fgg = ( (
cfqhbkrmw3 * ) ssGetContStates ( S ) ) -> b5hykck5fp ; _rtB -> kkeanfv3xi =
_rtP -> P_438 * _rtB -> nzkjwfwm5s ; _rtB -> j5imzuuv2y = _rtP -> P_439 *
_rtB -> nzkjwfwm5s ; _rtB -> lxruevtohm = ( _rtB -> ptqhor1fgg + _rtB ->
kkeanfv3xi ) + _rtB -> nywoculevv ; _rtB -> cq5tonv1t4 = 0.0 ; _rtB ->
cq5tonv1t4 += _rtP -> P_441 * _rtX -> khr0fwz2ri ; _rtB -> dz44revwz1 = _rtP
-> P_442 * _rtB -> cq5tonv1t4 ; ssCallAccelRunBlock ( S , 26 , 1312 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 1313 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 1314 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> hyjj24u52x = _rtP -> P_443 * _rtB ->
lxruevtohm ; ssCallAccelRunBlock ( S , 26 , 1316 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> j33jrr5nz2 = _rtP -> P_444 * _rtB -> nyuu0kwz0z ; _rtB -> m52tklnlgu
= _rtB -> hyjj24u52x - _rtB -> j33jrr5nz2 ; ssCallAccelRunBlock ( S , 26 ,
1343 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 26 , 1349 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1350 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1351 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1352 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1353 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 1354 , SS_CALL_MDL_OUTPUTS ) ; }
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
fwhqxupvfb * _rtB ; gv4lfag1c5 * _rtP ; bpocjipxik * _rtDW ; _rtDW = ( (
bpocjipxik * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( gv4lfag1c5 * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( fwhqxupvfb * ) _ssGetBlockIO ( S ) ) ;
if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> kymelibeuf = _rtB -> ebetrw30ln
; _rtDW -> l2aowypwq0 = _rtB -> duujqdjx4c ; _rtDW -> b2cjgliafe = _rtB ->
hfi2k0sruc ; _rtDW -> ehbsveshkm = _rtB -> bmipz2yvhp ; _rtDW -> hvyhvsvapr =
_rtB -> nmyb20ug1b ; _rtDW -> mw535gip5g = _rtB -> pqogctc0aj ; _rtDW ->
apnwvehbxl = _rtB -> plpjudsfzo ; _rtDW -> ftvhungduu = _rtB -> ecpdchnh0s ;
_rtDW -> jkuohcbhwi = _rtB -> ox1jrxk1x1 ; _rtDW -> lidex5nqky = _rtB ->
eb5slduxsz ; _rtDW -> drqejj3y2z = _rtB -> benv3yrtmp ; _rtDW -> ce5tye3xvi =
_rtB -> ifimttgx4a ; } if ( _rtDW -> gxvzfjyjfz == ( rtInf ) ) { _rtDW ->
gxvzfjyjfz = ssGetT ( S ) ; lastU = & _rtDW -> fyq1ioii4y ; } else if ( _rtDW
-> niymfi4oq3 == ( rtInf ) ) { _rtDW -> niymfi4oq3 = ssGetT ( S ) ; lastU = &
_rtDW -> ky2ygw5nhh ; } else if ( _rtDW -> gxvzfjyjfz < _rtDW -> niymfi4oq3 )
{ _rtDW -> gxvzfjyjfz = ssGetT ( S ) ; lastU = & _rtDW -> fyq1ioii4y ; } else
{ _rtDW -> niymfi4oq3 = ssGetT ( S ) ; lastU = & _rtDW -> ky2ygw5nhh ; } *
lastU = _rtB -> iegl4q51xa ; if ( _rtDW -> p5p0vltaax == ( rtInf ) ) { _rtDW
-> p5p0vltaax = ssGetT ( S ) ; lastU = & _rtDW -> lnzzyyuval ; } else if (
_rtDW -> ddafsn123k == ( rtInf ) ) { _rtDW -> ddafsn123k = ssGetT ( S ) ;
lastU = & _rtDW -> bzuhgwd2ot ; } else if ( _rtDW -> p5p0vltaax < _rtDW ->
ddafsn123k ) { _rtDW -> p5p0vltaax = ssGetT ( S ) ; lastU = & _rtDW ->
lnzzyyuval ; } else { _rtDW -> ddafsn123k = ssGetT ( S ) ; lastU = & _rtDW ->
bzuhgwd2ot ; } * lastU = _rtB -> eld3tcrwu3 ; if ( _rtDW -> p2stagy2hg == (
rtInf ) ) { _rtDW -> p2stagy2hg = ssGetT ( S ) ; lastU = & _rtDW ->
olfp5w0idj ; } else if ( _rtDW -> d1h1i0lh2q == ( rtInf ) ) { _rtDW ->
d1h1i0lh2q = ssGetT ( S ) ; lastU = & _rtDW -> ecoarytxkj ; } else if ( _rtDW
-> p2stagy2hg < _rtDW -> d1h1i0lh2q ) { _rtDW -> p2stagy2hg = ssGetT ( S ) ;
lastU = & _rtDW -> olfp5w0idj ; } else { _rtDW -> d1h1i0lh2q = ssGetT ( S ) ;
lastU = & _rtDW -> ecoarytxkj ; } * lastU = _rtB -> cebyqijllt ; if ( _rtDW
-> nokgbkqmov == ( rtInf ) ) { _rtDW -> nokgbkqmov = ssGetT ( S ) ; lastU = &
_rtDW -> dhzyfmgyay ; } else if ( _rtDW -> fu4fuq2uck == ( rtInf ) ) { _rtDW
-> fu4fuq2uck = ssGetT ( S ) ; lastU = & _rtDW -> orx4swi3fj ; } else if (
_rtDW -> nokgbkqmov < _rtDW -> fu4fuq2uck ) { _rtDW -> nokgbkqmov = ssGetT (
S ) ; lastU = & _rtDW -> dhzyfmgyay ; } else { _rtDW -> fu4fuq2uck = ssGetT (
S ) ; lastU = & _rtDW -> orx4swi3fj ; } * lastU = _rtB -> mfpr0jjl3y ; if (
_rtDW -> k4lcetjgkb == ( rtInf ) ) { _rtDW -> k4lcetjgkb = ssGetT ( S ) ;
lastU = & _rtDW -> i44riggpwd ; } else if ( _rtDW -> cabtruwfpo == ( rtInf )
) { _rtDW -> cabtruwfpo = ssGetT ( S ) ; lastU = & _rtDW -> liyko2tf3s ; }
else if ( _rtDW -> k4lcetjgkb < _rtDW -> cabtruwfpo ) { _rtDW -> k4lcetjgkb =
ssGetT ( S ) ; lastU = & _rtDW -> i44riggpwd ; } else { _rtDW -> cabtruwfpo =
ssGetT ( S ) ; lastU = & _rtDW -> liyko2tf3s ; } * lastU = _rtB -> fva4drfwi0
; if ( _rtDW -> gj12sphtdn == ( rtInf ) ) { _rtDW -> gj12sphtdn = ssGetT ( S
) ; lastU = & _rtDW -> b1ntdub2it ; } else if ( _rtDW -> otxkpvw3hh == (
rtInf ) ) { _rtDW -> otxkpvw3hh = ssGetT ( S ) ; lastU = & _rtDW ->
dcypfrtcpg ; } else if ( _rtDW -> gj12sphtdn < _rtDW -> otxkpvw3hh ) { _rtDW
-> gj12sphtdn = ssGetT ( S ) ; lastU = & _rtDW -> b1ntdub2it ; } else { _rtDW
-> otxkpvw3hh = ssGetT ( S ) ; lastU = & _rtDW -> dcypfrtcpg ; } * lastU =
_rtB -> fgixxej3oa ; if ( _rtDW -> iyjs3n2hlb == ( rtInf ) ) { _rtDW ->
iyjs3n2hlb = ssGetT ( S ) ; lastU = & _rtDW -> macdwpifir ; } else if ( _rtDW
-> fgdiy1cbbh == ( rtInf ) ) { _rtDW -> fgdiy1cbbh = ssGetT ( S ) ; lastU = &
_rtDW -> omitc2ymp2 ; } else if ( _rtDW -> iyjs3n2hlb < _rtDW -> fgdiy1cbbh )
{ _rtDW -> iyjs3n2hlb = ssGetT ( S ) ; lastU = & _rtDW -> macdwpifir ; } else
{ _rtDW -> fgdiy1cbbh = ssGetT ( S ) ; lastU = & _rtDW -> omitc2ymp2 ; } *
lastU = _rtB -> esnf0glwer ; if ( _rtDW -> ing2zbnlej == ( rtInf ) ) { _rtDW
-> ing2zbnlej = ssGetT ( S ) ; lastU = & _rtDW -> ljqavruy5n ; } else if (
_rtDW -> fj5aqqw3v0 == ( rtInf ) ) { _rtDW -> fj5aqqw3v0 = ssGetT ( S ) ;
lastU = & _rtDW -> a2ql4ar3pm ; } else if ( _rtDW -> ing2zbnlej < _rtDW ->
fj5aqqw3v0 ) { _rtDW -> ing2zbnlej = ssGetT ( S ) ; lastU = & _rtDW ->
ljqavruy5n ; } else { _rtDW -> fj5aqqw3v0 = ssGetT ( S ) ; lastU = & _rtDW ->
a2ql4ar3pm ; } * lastU = _rtB -> gjnz3y1xbh ; if ( _rtDW -> hzb1j1dedc == (
rtInf ) ) { _rtDW -> hzb1j1dedc = ssGetT ( S ) ; lastU = & _rtDW ->
lvjxccrcmc ; } else if ( _rtDW -> pqekytbgoa == ( rtInf ) ) { _rtDW ->
pqekytbgoa = ssGetT ( S ) ; lastU = & _rtDW -> etik1cpo2m ; } else if ( _rtDW
-> hzb1j1dedc < _rtDW -> pqekytbgoa ) { _rtDW -> hzb1j1dedc = ssGetT ( S ) ;
lastU = & _rtDW -> lvjxccrcmc ; } else { _rtDW -> pqekytbgoa = ssGetT ( S ) ;
lastU = & _rtDW -> etik1cpo2m ; } * lastU = _rtB -> h1ket0xx5q ; if ( _rtDW
-> m0nhdmvumy == ( rtInf ) ) { _rtDW -> m0nhdmvumy = ssGetT ( S ) ; lastU = &
_rtDW -> fuqlxsqqsg ; } else if ( _rtDW -> bfmcbjs0af == ( rtInf ) ) { _rtDW
-> bfmcbjs0af = ssGetT ( S ) ; lastU = & _rtDW -> lovupdqmon ; } else if (
_rtDW -> m0nhdmvumy < _rtDW -> bfmcbjs0af ) { _rtDW -> m0nhdmvumy = ssGetT (
S ) ; lastU = & _rtDW -> fuqlxsqqsg ; } else { _rtDW -> bfmcbjs0af = ssGetT (
S ) ; lastU = & _rtDW -> lovupdqmon ; } * lastU = _rtB -> kddf15ytqn ; if (
_rtDW -> e0md23qrnv == ( rtInf ) ) { _rtDW -> e0md23qrnv = ssGetT ( S ) ;
lastU = & _rtDW -> ekglrfhonl ; } else if ( _rtDW -> bkptfilnzm == ( rtInf )
) { _rtDW -> bkptfilnzm = ssGetT ( S ) ; lastU = & _rtDW -> lrpmykjqy3 ; }
else if ( _rtDW -> e0md23qrnv < _rtDW -> bkptfilnzm ) { _rtDW -> e0md23qrnv =
ssGetT ( S ) ; lastU = & _rtDW -> ekglrfhonl ; } else { _rtDW -> bkptfilnzm =
ssGetT ( S ) ; lastU = & _rtDW -> lrpmykjqy3 ; } * lastU = _rtB -> pcfhp1iopy
; if ( _rtDW -> ponpoa5jnj == ( rtInf ) ) { _rtDW -> ponpoa5jnj = ssGetT ( S
) ; lastU = & _rtDW -> kwjpgule3p ; } else if ( _rtDW -> g5f0njdqmd == (
rtInf ) ) { _rtDW -> g5f0njdqmd = ssGetT ( S ) ; lastU = & _rtDW ->
j21ik0qxig ; } else if ( _rtDW -> ponpoa5jnj < _rtDW -> g5f0njdqmd ) { _rtDW
-> ponpoa5jnj = ssGetT ( S ) ; lastU = & _rtDW -> kwjpgule3p ; } else { _rtDW
-> g5f0njdqmd = ssGetT ( S ) ; lastU = & _rtDW -> j21ik0qxig ; } * lastU =
_rtB -> bnu5015hlg ; if ( _rtDW -> jsqocbcrbw == ( rtInf ) ) { _rtDW ->
jsqocbcrbw = ssGetT ( S ) ; lastU = & _rtDW -> glsyupdcw5 ; } else if ( _rtDW
-> mjccdjqte1 == ( rtInf ) ) { _rtDW -> mjccdjqte1 = ssGetT ( S ) ; lastU = &
_rtDW -> ep0sq2bcqm ; } else if ( _rtDW -> jsqocbcrbw < _rtDW -> mjccdjqte1 )
{ _rtDW -> jsqocbcrbw = ssGetT ( S ) ; lastU = & _rtDW -> glsyupdcw5 ; } else
{ _rtDW -> mjccdjqte1 = ssGetT ( S ) ; lastU = & _rtDW -> ep0sq2bcqm ; } *
lastU = _rtB -> kxwytcbakg ; if ( _rtDW -> hurojtxhba == ( rtInf ) ) { _rtDW
-> hurojtxhba = ssGetT ( S ) ; lastU = & _rtDW -> dg0bwrgz1t ; } else if (
_rtDW -> lsokswrh0d == ( rtInf ) ) { _rtDW -> lsokswrh0d = ssGetT ( S ) ;
lastU = & _rtDW -> dhwgj24z5h ; } else if ( _rtDW -> hurojtxhba < _rtDW ->
lsokswrh0d ) { _rtDW -> hurojtxhba = ssGetT ( S ) ; lastU = & _rtDW ->
dg0bwrgz1t ; } else { _rtDW -> lsokswrh0d = ssGetT ( S ) ; lastU = & _rtDW ->
dhwgj24z5h ; } * lastU = _rtB -> nidjbvpyt5 ; if ( _rtDW -> p5nimkmwn1 == (
rtInf ) ) { _rtDW -> p5nimkmwn1 = ssGetT ( S ) ; lastU = & _rtDW ->
agvcyw1f0l ; } else if ( _rtDW -> mvfhsh0waz == ( rtInf ) ) { _rtDW ->
mvfhsh0waz = ssGetT ( S ) ; lastU = & _rtDW -> cc1bpr21vd ; } else if ( _rtDW
-> p5nimkmwn1 < _rtDW -> mvfhsh0waz ) { _rtDW -> p5nimkmwn1 = ssGetT ( S ) ;
lastU = & _rtDW -> agvcyw1f0l ; } else { _rtDW -> mvfhsh0waz = ssGetT ( S ) ;
lastU = & _rtDW -> cc1bpr21vd ; } * lastU = _rtB -> jomu1lqb5u ; if ( _rtDW
-> o0405brpgz == ( rtInf ) ) { _rtDW -> o0405brpgz = ssGetT ( S ) ; lastU = &
_rtDW -> inlh4jzgm5 ; } else if ( _rtDW -> acq3dyiyhd == ( rtInf ) ) { _rtDW
-> acq3dyiyhd = ssGetT ( S ) ; lastU = & _rtDW -> dbnp2xyj1p ; } else if (
_rtDW -> o0405brpgz < _rtDW -> acq3dyiyhd ) { _rtDW -> o0405brpgz = ssGetT (
S ) ; lastU = & _rtDW -> inlh4jzgm5 ; } else { _rtDW -> acq3dyiyhd = ssGetT (
S ) ; lastU = & _rtDW -> dbnp2xyj1p ; } * lastU = _rtB -> mbcf3o2d3b ; if (
_rtDW -> lqwlakp4jj == ( rtInf ) ) { _rtDW -> lqwlakp4jj = ssGetT ( S ) ;
lastU = & _rtDW -> hg3zs34v4n ; } else if ( _rtDW -> ggjg1s003h == ( rtInf )
) { _rtDW -> ggjg1s003h = ssGetT ( S ) ; lastU = & _rtDW -> bevwtdgkk5 ; }
else if ( _rtDW -> lqwlakp4jj < _rtDW -> ggjg1s003h ) { _rtDW -> lqwlakp4jj =
ssGetT ( S ) ; lastU = & _rtDW -> hg3zs34v4n ; } else { _rtDW -> ggjg1s003h =
ssGetT ( S ) ; lastU = & _rtDW -> bevwtdgkk5 ; } * lastU = _rtB -> o4jpa32wvo
; if ( _rtDW -> g5flx1vu0d == ( rtInf ) ) { _rtDW -> g5flx1vu0d = ssGetT ( S
) ; lastU = & _rtDW -> bzosdsme2i ; } else if ( _rtDW -> i03cehs32p == (
rtInf ) ) { _rtDW -> i03cehs32p = ssGetT ( S ) ; lastU = & _rtDW ->
acheszdxnh ; } else if ( _rtDW -> g5flx1vu0d < _rtDW -> i03cehs32p ) { _rtDW
-> g5flx1vu0d = ssGetT ( S ) ; lastU = & _rtDW -> bzosdsme2i ; } else { _rtDW
-> i03cehs32p = ssGetT ( S ) ; lastU = & _rtDW -> acheszdxnh ; } * lastU =
_rtB -> a14ae5ywsf ; if ( _rtDW -> hrsnmvoy4j == ( rtInf ) ) { _rtDW ->
hrsnmvoy4j = ssGetT ( S ) ; lastU = & _rtDW -> lmekbo340y ; } else if ( _rtDW
-> jymexjnm51 == ( rtInf ) ) { _rtDW -> jymexjnm51 = ssGetT ( S ) ; lastU = &
_rtDW -> m455ukdm4v ; } else if ( _rtDW -> hrsnmvoy4j < _rtDW -> jymexjnm51 )
{ _rtDW -> hrsnmvoy4j = ssGetT ( S ) ; lastU = & _rtDW -> lmekbo340y ; } else
{ _rtDW -> jymexjnm51 = ssGetT ( S ) ; lastU = & _rtDW -> m455ukdm4v ; } *
lastU = _rtB -> fzwnpjpxmp ; if ( _rtDW -> gb4jvzidh0 == ( rtInf ) ) { _rtDW
-> gb4jvzidh0 = ssGetT ( S ) ; lastU = & _rtDW -> ntgipn1ph0 ; } else if (
_rtDW -> fsbsshuzyr == ( rtInf ) ) { _rtDW -> fsbsshuzyr = ssGetT ( S ) ;
lastU = & _rtDW -> molarj3aht ; } else if ( _rtDW -> gb4jvzidh0 < _rtDW ->
fsbsshuzyr ) { _rtDW -> gb4jvzidh0 = ssGetT ( S ) ; lastU = & _rtDW ->
ntgipn1ph0 ; } else { _rtDW -> fsbsshuzyr = ssGetT ( S ) ; lastU = & _rtDW ->
molarj3aht ; } * lastU = _rtB -> pvgkci1ovv ; if ( _rtDW -> fiuzhnygr2 == (
rtInf ) ) { _rtDW -> fiuzhnygr2 = ssGetT ( S ) ; lastU = & _rtDW ->
bw53tndja1 ; } else if ( _rtDW -> axg0pokrgz == ( rtInf ) ) { _rtDW ->
axg0pokrgz = ssGetT ( S ) ; lastU = & _rtDW -> oerq0ak54m ; } else if ( _rtDW
-> fiuzhnygr2 < _rtDW -> axg0pokrgz ) { _rtDW -> fiuzhnygr2 = ssGetT ( S ) ;
lastU = & _rtDW -> bw53tndja1 ; } else { _rtDW -> axg0pokrgz = ssGetT ( S ) ;
lastU = & _rtDW -> oerq0ak54m ; } * lastU = _rtB -> b5bg5sylim ; if ( _rtDW
-> hjjy0flo5v == ( rtInf ) ) { _rtDW -> hjjy0flo5v = ssGetT ( S ) ; lastU = &
_rtDW -> bllgnsd24p ; } else if ( _rtDW -> agoglty3xy == ( rtInf ) ) { _rtDW
-> agoglty3xy = ssGetT ( S ) ; lastU = & _rtDW -> j2hdn4t1kc ; } else if (
_rtDW -> hjjy0flo5v < _rtDW -> agoglty3xy ) { _rtDW -> hjjy0flo5v = ssGetT (
S ) ; lastU = & _rtDW -> bllgnsd24p ; } else { _rtDW -> agoglty3xy = ssGetT (
S ) ; lastU = & _rtDW -> j2hdn4t1kc ; } * lastU = _rtB -> kmvcfmr1jd ; if (
_rtDW -> engdnf2o11 == ( rtInf ) ) { _rtDW -> engdnf2o11 = ssGetT ( S ) ;
lastU = & _rtDW -> lnidc1joj2 ; } else if ( _rtDW -> imygdvmpjz == ( rtInf )
) { _rtDW -> imygdvmpjz = ssGetT ( S ) ; lastU = & _rtDW -> hlaq0fchte ; }
else if ( _rtDW -> engdnf2o11 < _rtDW -> imygdvmpjz ) { _rtDW -> engdnf2o11 =
ssGetT ( S ) ; lastU = & _rtDW -> lnidc1joj2 ; } else { _rtDW -> imygdvmpjz =
ssGetT ( S ) ; lastU = & _rtDW -> hlaq0fchte ; } * lastU = _rtB -> cpo1oiounj
; if ( _rtDW -> gth35uto5a == ( rtInf ) ) { _rtDW -> gth35uto5a = ssGetT ( S
) ; lastU = & _rtDW -> bcyswmosff ; } else if ( _rtDW -> hqciimvqbr == (
rtInf ) ) { _rtDW -> hqciimvqbr = ssGetT ( S ) ; lastU = & _rtDW ->
hpawn23ndd ; } else if ( _rtDW -> gth35uto5a < _rtDW -> hqciimvqbr ) { _rtDW
-> gth35uto5a = ssGetT ( S ) ; lastU = & _rtDW -> bcyswmosff ; } else { _rtDW
-> hqciimvqbr = ssGetT ( S ) ; lastU = & _rtDW -> hpawn23ndd ; } * lastU =
_rtB -> md0fds2ykq ; if ( _rtDW -> j5azrn5jaj == ( rtInf ) ) { _rtDW ->
j5azrn5jaj = ssGetT ( S ) ; lastU = & _rtDW -> iksuvkx2h2 ; } else if ( _rtDW
-> idppvjqgxy == ( rtInf ) ) { _rtDW -> idppvjqgxy = ssGetT ( S ) ; lastU = &
_rtDW -> d0g45ks2pg ; } else if ( _rtDW -> j5azrn5jaj < _rtDW -> idppvjqgxy )
{ _rtDW -> j5azrn5jaj = ssGetT ( S ) ; lastU = & _rtDW -> iksuvkx2h2 ; } else
{ _rtDW -> idppvjqgxy = ssGetT ( S ) ; lastU = & _rtDW -> d0g45ks2pg ; } *
lastU = _rtB -> ab0retugfm ; if ( _rtDW -> g1iciqjkj1 == ( rtInf ) ) { _rtDW
-> g1iciqjkj1 = ssGetT ( S ) ; lastU = & _rtDW -> btjr4tvdt4 ; } else if (
_rtDW -> a5mtwtffo4 == ( rtInf ) ) { _rtDW -> a5mtwtffo4 = ssGetT ( S ) ;
lastU = & _rtDW -> eaq5fgtm5y ; } else if ( _rtDW -> g1iciqjkj1 < _rtDW ->
a5mtwtffo4 ) { _rtDW -> g1iciqjkj1 = ssGetT ( S ) ; lastU = & _rtDW ->
btjr4tvdt4 ; } else { _rtDW -> a5mtwtffo4 = ssGetT ( S ) ; lastU = & _rtDW ->
eaq5fgtm5y ; } * lastU = _rtB -> cpdqurfm2a ; if ( _rtDW -> hezyb4c2n0 == (
rtInf ) ) { _rtDW -> hezyb4c2n0 = ssGetT ( S ) ; lastU = & _rtDW ->
a3jqkmyzub ; } else if ( _rtDW -> ki4k3pwqpo == ( rtInf ) ) { _rtDW ->
ki4k3pwqpo = ssGetT ( S ) ; lastU = & _rtDW -> n14saw03pu ; } else if ( _rtDW
-> hezyb4c2n0 < _rtDW -> ki4k3pwqpo ) { _rtDW -> hezyb4c2n0 = ssGetT ( S ) ;
lastU = & _rtDW -> a3jqkmyzub ; } else { _rtDW -> ki4k3pwqpo = ssGetT ( S ) ;
lastU = & _rtDW -> n14saw03pu ; } * lastU = _rtB -> ofnxohnqca ; if ( _rtDW
-> piihx4u5k0 == ( rtInf ) ) { _rtDW -> piihx4u5k0 = ssGetT ( S ) ; lastU = &
_rtDW -> afnt3mz1hb ; } else if ( _rtDW -> ok5r2wnawf == ( rtInf ) ) { _rtDW
-> ok5r2wnawf = ssGetT ( S ) ; lastU = & _rtDW -> fs5vvpaw21 ; } else if (
_rtDW -> piihx4u5k0 < _rtDW -> ok5r2wnawf ) { _rtDW -> piihx4u5k0 = ssGetT (
S ) ; lastU = & _rtDW -> afnt3mz1hb ; } else { _rtDW -> ok5r2wnawf = ssGetT (
S ) ; lastU = & _rtDW -> fs5vvpaw21 ; } * lastU = _rtB -> n553trglzx ; if (
_rtDW -> ivto2yfcpr == ( rtInf ) ) { _rtDW -> ivto2yfcpr = ssGetT ( S ) ;
lastU = & _rtDW -> hu4itulmza ; } else if ( _rtDW -> odwx5gyepo == ( rtInf )
) { _rtDW -> odwx5gyepo = ssGetT ( S ) ; lastU = & _rtDW -> ewdfbs3mtp ; }
else if ( _rtDW -> ivto2yfcpr < _rtDW -> odwx5gyepo ) { _rtDW -> ivto2yfcpr =
ssGetT ( S ) ; lastU = & _rtDW -> hu4itulmza ; } else { _rtDW -> odwx5gyepo =
ssGetT ( S ) ; lastU = & _rtDW -> ewdfbs3mtp ; } * lastU = _rtB -> p2mwsr20yb
; if ( _rtDW -> ngx20kzjdu == ( rtInf ) ) { _rtDW -> ngx20kzjdu = ssGetT ( S
) ; lastU = & _rtDW -> cn0m0dnvvv ; } else if ( _rtDW -> io5qz1bfri == (
rtInf ) ) { _rtDW -> io5qz1bfri = ssGetT ( S ) ; lastU = & _rtDW ->
fud4qkvc5l ; } else if ( _rtDW -> ngx20kzjdu < _rtDW -> io5qz1bfri ) { _rtDW
-> ngx20kzjdu = ssGetT ( S ) ; lastU = & _rtDW -> cn0m0dnvvv ; } else { _rtDW
-> io5qz1bfri = ssGetT ( S ) ; lastU = & _rtDW -> fud4qkvc5l ; } * lastU =
_rtB -> n4ekgqxrgn ; if ( _rtDW -> ahzdlyt1hz == ( rtInf ) ) { _rtDW ->
ahzdlyt1hz = ssGetT ( S ) ; lastU = & _rtDW -> ixptss4bts ; } else if ( _rtDW
-> kkhc1hmdrl == ( rtInf ) ) { _rtDW -> kkhc1hmdrl = ssGetT ( S ) ; lastU = &
_rtDW -> akh4h1zg23 ; } else if ( _rtDW -> ahzdlyt1hz < _rtDW -> kkhc1hmdrl )
{ _rtDW -> ahzdlyt1hz = ssGetT ( S ) ; lastU = & _rtDW -> ixptss4bts ; } else
{ _rtDW -> kkhc1hmdrl = ssGetT ( S ) ; lastU = & _rtDW -> akh4h1zg23 ; } *
lastU = _rtB -> gjgpfapzeu ; if ( _rtDW -> lwlaw2shm0 == ( rtInf ) ) { _rtDW
-> lwlaw2shm0 = ssGetT ( S ) ; lastU = & _rtDW -> ijbu1a3mnl ; } else if (
_rtDW -> jf0lqrg3bd == ( rtInf ) ) { _rtDW -> jf0lqrg3bd = ssGetT ( S ) ;
lastU = & _rtDW -> fmfwxfvqoe ; } else if ( _rtDW -> lwlaw2shm0 < _rtDW ->
jf0lqrg3bd ) { _rtDW -> lwlaw2shm0 = ssGetT ( S ) ; lastU = & _rtDW ->
ijbu1a3mnl ; } else { _rtDW -> jf0lqrg3bd = ssGetT ( S ) ; lastU = & _rtDW ->
fmfwxfvqoe ; } * lastU = _rtB -> k2n1xiq5z0 ; if ( _rtDW -> m5xzpfc1il == (
rtInf ) ) { _rtDW -> m5xzpfc1il = ssGetT ( S ) ; lastU = & _rtDW ->
czej0oyj0v ; } else if ( _rtDW -> k3p3z2moz2 == ( rtInf ) ) { _rtDW ->
k3p3z2moz2 = ssGetT ( S ) ; lastU = & _rtDW -> kaja0vlux0 ; } else if ( _rtDW
-> m5xzpfc1il < _rtDW -> k3p3z2moz2 ) { _rtDW -> m5xzpfc1il = ssGetT ( S ) ;
lastU = & _rtDW -> czej0oyj0v ; } else { _rtDW -> k3p3z2moz2 = ssGetT ( S ) ;
lastU = & _rtDW -> kaja0vlux0 ; } * lastU = _rtB -> io44b2wfxq ; if ( _rtDW
-> jwjv4dmxil == ( rtInf ) ) { _rtDW -> jwjv4dmxil = ssGetT ( S ) ; lastU = &
_rtDW -> pbpp4gmqys ; } else if ( _rtDW -> lyok1yozh4 == ( rtInf ) ) { _rtDW
-> lyok1yozh4 = ssGetT ( S ) ; lastU = & _rtDW -> e4rsirdlj2 ; } else if (
_rtDW -> jwjv4dmxil < _rtDW -> lyok1yozh4 ) { _rtDW -> jwjv4dmxil = ssGetT (
S ) ; lastU = & _rtDW -> pbpp4gmqys ; } else { _rtDW -> lyok1yozh4 = ssGetT (
S ) ; lastU = & _rtDW -> e4rsirdlj2 ; } * lastU = _rtB -> ftmscilcju ; if (
_rtDW -> jacpkfor01 == ( rtInf ) ) { _rtDW -> jacpkfor01 = ssGetT ( S ) ;
lastU = & _rtDW -> p4hdnk4r1v ; } else if ( _rtDW -> fu030l101l == ( rtInf )
) { _rtDW -> fu030l101l = ssGetT ( S ) ; lastU = & _rtDW -> haedbnc4qr ; }
else if ( _rtDW -> jacpkfor01 < _rtDW -> fu030l101l ) { _rtDW -> jacpkfor01 =
ssGetT ( S ) ; lastU = & _rtDW -> p4hdnk4r1v ; } else { _rtDW -> fu030l101l =
ssGetT ( S ) ; lastU = & _rtDW -> haedbnc4qr ; } * lastU = _rtB -> owm1b3loru
; if ( _rtDW -> lggckakxot == ( rtInf ) ) { _rtDW -> lggckakxot = ssGetT ( S
) ; lastU = & _rtDW -> mopgtvoupi ; } else if ( _rtDW -> fydwxywx3a == (
rtInf ) ) { _rtDW -> fydwxywx3a = ssGetT ( S ) ; lastU = & _rtDW ->
luk5pugjpa ; } else if ( _rtDW -> lggckakxot < _rtDW -> fydwxywx3a ) { _rtDW
-> lggckakxot = ssGetT ( S ) ; lastU = & _rtDW -> mopgtvoupi ; } else { _rtDW
-> fydwxywx3a = ssGetT ( S ) ; lastU = & _rtDW -> luk5pugjpa ; } * lastU =
_rtB -> lyozvblyxh ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { fwhqxupvfb * _rtB ; gv4lfag1c5
* _rtP ; cfqhbkrmw3 * _rtX ; lxdz41kqrh * _rtXdot ; _rtXdot = ( ( lxdz41kqrh
* ) ssGetdX ( S ) ) ; _rtX = ( ( cfqhbkrmw3 * ) ssGetContStates ( S ) ) ;
_rtP = ( ( gv4lfag1c5 * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( fwhqxupvfb *
) _ssGetBlockIO ( S ) ) ; { ( ( lxdz41kqrh * ) ssGetdX ( S ) ) -> jm10gs3jtx
= _rtB -> f5gxbasaq5 [ 0 ] ; } { ( ( lxdz41kqrh * ) ssGetdX ( S ) ) ->
fodndj1vhy = _rtB -> f5gxbasaq5 [ 1 ] ; } { ( ( lxdz41kqrh * ) ssGetdX ( S )
) -> oltvbdbnrv = _rtB -> f5gxbasaq5 [ 2 ] ; } { ( ( lxdz41kqrh * ) ssGetdX (
S ) ) -> jv0vvsx3pu = _rtB -> iegl4q51xa ; } _rtXdot -> mzra4bbhyj [ 0 ] =
_rtX -> mzra4bbhyj [ 1 ] ; _rtXdot -> mzra4bbhyj [ 1 ] = ( ( _rtB ->
pl2wvrqrxm - _rtX -> mzra4bbhyj [ 0 ] ) * 1000.0 - 2.0 * _rtX -> mzra4bbhyj [
1 ] ) * 1000.0 ; { ( ( lxdz41kqrh * ) ssGetdX ( S ) ) -> j3bpgzmycv = _rtB ->
cebyqijllt ; } _rtXdot -> hzxrhlxoh3 [ 0 ] = _rtX -> hzxrhlxoh3 [ 1 ] ;
_rtXdot -> hzxrhlxoh3 [ 1 ] = ( ( _rtB -> nwkzu3qpu5 - _rtX -> hzxrhlxoh3 [ 0
] ) * 1000.0 - 2.0 * _rtX -> hzxrhlxoh3 [ 1 ] ) * 1000.0 ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> kxycjxmepv = _rtB -> fva4drfwi0 ; } _rtXdot ->
l3rszswrqk [ 0 ] = _rtX -> l3rszswrqk [ 1 ] ; _rtXdot -> l3rszswrqk [ 1 ] = (
( _rtB -> f2ancyeofe - _rtX -> l3rszswrqk [ 0 ] ) * 1000.0 - 2.0 * _rtX ->
l3rszswrqk [ 1 ] ) * 1000.0 ; { ( ( lxdz41kqrh * ) ssGetdX ( S ) ) ->
cx0cg2fpl4 = _rtB -> esnf0glwer ; } _rtXdot -> l0n3ehfyux [ 0 ] = _rtX ->
l0n3ehfyux [ 1 ] ; _rtXdot -> l0n3ehfyux [ 1 ] = ( ( _rtB -> i300diadtf -
_rtX -> l0n3ehfyux [ 0 ] ) * 1000.0 - 2.0 * _rtX -> l0n3ehfyux [ 1 ] ) *
1000.0 ; { ( ( lxdz41kqrh * ) ssGetdX ( S ) ) -> f5chxutszn = _rtB ->
h1ket0xx5q ; } _rtXdot -> h5trv2qfm5 [ 0 ] = _rtX -> h5trv2qfm5 [ 1 ] ;
_rtXdot -> h5trv2qfm5 [ 1 ] = ( ( _rtB -> f1xe44wn5b - _rtX -> h5trv2qfm5 [ 0
] ) * 1000.0 - 2.0 * _rtX -> h5trv2qfm5 [ 1 ] ) * 1000.0 ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> n1bu2zupn0 = _rtB -> pcfhp1iopy ; } _rtXdot ->
ewtjdz3urj [ 0 ] = _rtX -> ewtjdz3urj [ 1 ] ; _rtXdot -> ewtjdz3urj [ 1 ] = (
( _rtB -> efwousquh4 - _rtX -> ewtjdz3urj [ 0 ] ) * 1000.0 - 2.0 * _rtX ->
ewtjdz3urj [ 1 ] ) * 1000.0 ; { ( ( lxdz41kqrh * ) ssGetdX ( S ) ) ->
oflrpx4jgo = _rtB -> kxwytcbakg ; } _rtXdot -> e21euocnfu [ 0 ] = _rtX ->
e21euocnfu [ 1 ] ; _rtXdot -> e21euocnfu [ 1 ] = ( ( _rtB -> ofeafse4g5 -
_rtX -> e21euocnfu [ 0 ] ) * 1000.0 - 2.0 * _rtX -> e21euocnfu [ 1 ] ) *
1000.0 ; { ( ( lxdz41kqrh * ) ssGetdX ( S ) ) -> obh2b3io0g = _rtB ->
jomu1lqb5u ; } _rtXdot -> asysdruxqk [ 0 ] = _rtX -> asysdruxqk [ 1 ] ;
_rtXdot -> asysdruxqk [ 1 ] = ( ( _rtB -> irhvcfxcsa - _rtX -> asysdruxqk [ 0
] ) * 1000.0 - 2.0 * _rtX -> asysdruxqk [ 1 ] ) * 1000.0 ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> e554iejytk = _rtB -> o4jpa32wvo ; } _rtXdot ->
ncec53pyop [ 0 ] = _rtX -> ncec53pyop [ 1 ] ; _rtXdot -> ncec53pyop [ 1 ] = (
( _rtB -> ev4wogm2gm - _rtX -> ncec53pyop [ 0 ] ) * 1000.0 - 2.0 * _rtX ->
ncec53pyop [ 1 ] ) * 1000.0 ; { ( ( lxdz41kqrh * ) ssGetdX ( S ) ) ->
muikzs5val = _rtB -> fzwnpjpxmp ; } _rtXdot -> b2y0jcphiu [ 0 ] = _rtX ->
b2y0jcphiu [ 1 ] ; _rtXdot -> b2y0jcphiu [ 1 ] = ( ( _rtB -> ejeeikgi2h -
_rtX -> b2y0jcphiu [ 0 ] ) * 1000.0 - 2.0 * _rtX -> b2y0jcphiu [ 1 ] ) *
1000.0 ; { ( ( lxdz41kqrh * ) ssGetdX ( S ) ) -> ctle43cx5w = _rtB ->
b5bg5sylim ; } _rtXdot -> efdpehqsdx [ 0 ] = _rtX -> efdpehqsdx [ 1 ] ;
_rtXdot -> efdpehqsdx [ 1 ] = ( ( _rtB -> gxcwwxfexc - _rtX -> efdpehqsdx [ 0
] ) * 1000.0 - 2.0 * _rtX -> efdpehqsdx [ 1 ] ) * 1000.0 ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> afps34cofr = _rtB -> cpo1oiounj ; } _rtXdot ->
os4wjwwywo [ 0 ] = _rtX -> os4wjwwywo [ 1 ] ; _rtXdot -> os4wjwwywo [ 1 ] = (
( _rtB -> nyo0mtbfor - _rtX -> os4wjwwywo [ 0 ] ) * 1000.0 - 2.0 * _rtX ->
os4wjwwywo [ 1 ] ) * 1000.0 ; { ( ( lxdz41kqrh * ) ssGetdX ( S ) ) ->
nnelvip41m = _rtB -> ab0retugfm ; } _rtXdot -> enzxkhjcgi [ 0 ] = _rtX ->
enzxkhjcgi [ 1 ] ; _rtXdot -> enzxkhjcgi [ 1 ] = ( ( _rtB -> pjtv53t1ga -
_rtX -> enzxkhjcgi [ 0 ] ) * 1000.0 - 2.0 * _rtX -> enzxkhjcgi [ 1 ] ) *
1000.0 ; { ( ( lxdz41kqrh * ) ssGetdX ( S ) ) -> mlvwdw3tjx = _rtB ->
ofnxohnqca ; } _rtXdot -> oojbg1bx4b [ 0 ] = _rtX -> oojbg1bx4b [ 1 ] ;
_rtXdot -> oojbg1bx4b [ 1 ] = ( ( _rtB -> jd2m5t2awx - _rtX -> oojbg1bx4b [ 0
] ) * 1000.0 - 2.0 * _rtX -> oojbg1bx4b [ 1 ] ) * 1000.0 ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> ma2dtr2sez = _rtB -> p2mwsr20yb ; } _rtXdot ->
cekdgjravx [ 0 ] = _rtX -> cekdgjravx [ 1 ] ; _rtXdot -> cekdgjravx [ 1 ] = (
( _rtB -> dpv1oe3ih3 - _rtX -> cekdgjravx [ 0 ] ) * 1000.0 - 2.0 * _rtX ->
cekdgjravx [ 1 ] ) * 1000.0 ; { ( ( lxdz41kqrh * ) ssGetdX ( S ) ) ->
muzujlinyc = _rtB -> gjgpfapzeu ; } _rtXdot -> neoskuf135 [ 0 ] = _rtX ->
neoskuf135 [ 1 ] ; _rtXdot -> neoskuf135 [ 1 ] = ( ( _rtB -> piyok5iwts -
_rtX -> neoskuf135 [ 0 ] ) * 1000.0 - 2.0 * _rtX -> neoskuf135 [ 1 ] ) *
1000.0 ; { ( ( lxdz41kqrh * ) ssGetdX ( S ) ) -> gwcgb0amvz = _rtB ->
io44b2wfxq ; } _rtXdot -> bbxqinau05 [ 0 ] = _rtX -> bbxqinau05 [ 1 ] ;
_rtXdot -> bbxqinau05 [ 1 ] = ( ( _rtB -> hqbvo1rsxu - _rtX -> bbxqinau05 [ 0
] ) * 1000.0 - 2.0 * _rtX -> bbxqinau05 [ 1 ] ) * 1000.0 ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> dpjj44i2aj = _rtB -> owm1b3loru ; } _rtXdot ->
j50oldiplh [ 0 ] = _rtX -> j50oldiplh [ 1 ] ; _rtXdot -> j50oldiplh [ 1 ] = (
( _rtB -> ioqypqfh4t - _rtX -> j50oldiplh [ 0 ] ) * 1000.0 - 2.0 * _rtX ->
j50oldiplh [ 1 ] ) * 1000.0 ; ssCallAccelRunBlock ( S , 26 , 74 ,
SS_CALL_MDL_DERIVATIVES ) ; _rtXdot -> h155tmmbck = 0.0 ; _rtXdot ->
h155tmmbck += _rtP -> P_178 * _rtX -> h155tmmbck ; _rtXdot -> h155tmmbck +=
_rtB -> ddqicp1aaf ; { ( ( lxdz41kqrh * ) ssGetdX ( S ) ) -> gh3iyxvqht =
_rtB -> gw42y0c5xe ; } _rtXdot -> lqibactaag = 0.0 ; _rtXdot -> lqibactaag +=
_rtP -> P_188 * _rtX -> lqibactaag ; _rtXdot -> lqibactaag += _rtB ->
bezcxsb4ow ; _rtXdot -> dvazecsy1c = 0.0 ; _rtXdot -> dvazecsy1c += _rtP ->
P_191 * _rtX -> dvazecsy1c ; _rtXdot -> dvazecsy1c += _rtB -> c23l5g1qub ; {
( ( lxdz41kqrh * ) ssGetdX ( S ) ) -> b3u12lyooc = _rtB -> hp1uxbetun ; }
_rtXdot -> hkmcxcpyw4 = 0.0 ; _rtXdot -> hkmcxcpyw4 += _rtP -> P_200 * _rtX
-> hkmcxcpyw4 ; _rtXdot -> hkmcxcpyw4 += _rtB -> k4t0ez3yni ; _rtXdot ->
ocimq5mxpx = 0.0 ; _rtXdot -> ocimq5mxpx += _rtP -> P_206 * _rtX ->
ocimq5mxpx ; _rtXdot -> ocimq5mxpx += _rtB -> mdck2fipfs ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> mzkaz2abrd = _rtB -> bgdvv2kkfq ; } _rtXdot ->
mjlt2dcjyn = 0.0 ; _rtXdot -> mjlt2dcjyn += _rtP -> P_215 * _rtX ->
mjlt2dcjyn ; _rtXdot -> mjlt2dcjyn += _rtB -> iwtgxpue0e ; _rtXdot ->
maia2upwdj = 0.0 ; _rtXdot -> maia2upwdj += _rtP -> P_220 * _rtX ->
maia2upwdj ; _rtXdot -> maia2upwdj += _rtB -> naayrmdz5t ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> doz4021415 = _rtB -> md4wuzup0w ; } _rtXdot ->
b0hpv5pjok = 0.0 ; _rtXdot -> b0hpv5pjok += _rtP -> P_231 * _rtX ->
b0hpv5pjok ; _rtXdot -> b0hpv5pjok += _rtB -> oycakzdqvd ; _rtXdot ->
kda52s1yxv = 0.0 ; _rtXdot -> kda52s1yxv += _rtP -> P_236 * _rtX ->
kda52s1yxv ; _rtXdot -> kda52s1yxv += _rtB -> fzz4f03a4p ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> ky1obcqoz2 = _rtB -> hvzmuzn5h1 ; } _rtXdot ->
oirh2svypv = 0.0 ; _rtXdot -> oirh2svypv += _rtP -> P_245 * _rtX ->
oirh2svypv ; _rtXdot -> oirh2svypv += _rtB -> ge104hxhus ; _rtXdot ->
hvrzirvdht = 0.0 ; _rtXdot -> hvrzirvdht += _rtP -> P_250 * _rtX ->
hvrzirvdht ; _rtXdot -> hvrzirvdht += _rtB -> ot0goil1fh ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> neccwznanm = _rtB -> ipkrfhf40a ; } _rtXdot ->
nkzwoy5l3s = 0.0 ; _rtXdot -> nkzwoy5l3s += _rtP -> P_260 * _rtX ->
nkzwoy5l3s ; _rtXdot -> nkzwoy5l3s += _rtB -> amidl4hci3 ; _rtXdot ->
bilhigf3xj = 0.0 ; _rtXdot -> bilhigf3xj += _rtP -> P_265 * _rtX ->
bilhigf3xj ; _rtXdot -> bilhigf3xj += _rtB -> lnoo4wgtiw ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> frfcp5rz22 = _rtB -> o2nihsaxz0 ; } _rtXdot ->
ccnqyqy5bg = 0.0 ; _rtXdot -> ccnqyqy5bg += _rtP -> P_276 * _rtX ->
ccnqyqy5bg ; _rtXdot -> ccnqyqy5bg += _rtB -> pyt4v5x1ie ; _rtXdot ->
efckm0ivgu = 0.0 ; _rtXdot -> efckm0ivgu += _rtP -> P_281 * _rtX ->
efckm0ivgu ; _rtXdot -> efckm0ivgu += _rtB -> gir5snnrwd ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> chsynbzd3y = _rtB -> ej0uvfoa2v ; } _rtXdot ->
owholqk5yt = 0.0 ; _rtXdot -> owholqk5yt += _rtP -> P_290 * _rtX ->
owholqk5yt ; _rtXdot -> owholqk5yt += _rtB -> pozqtc4xfd ; _rtXdot ->
ig3uaiwoa2 = 0.0 ; _rtXdot -> ig3uaiwoa2 += _rtP -> P_295 * _rtX ->
ig3uaiwoa2 ; _rtXdot -> ig3uaiwoa2 += _rtB -> ft2a4nbu4n ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> p2bhqhyz1s = _rtB -> etxth0gwa0 ; } _rtXdot ->
nd2es0pja2 = 0.0 ; _rtXdot -> nd2es0pja2 += _rtP -> P_305 * _rtX ->
nd2es0pja2 ; _rtXdot -> nd2es0pja2 += _rtB -> hlbg03vbov ; _rtXdot ->
hwvtodn0ry = 0.0 ; _rtXdot -> hwvtodn0ry += _rtP -> P_310 * _rtX ->
hwvtodn0ry ; _rtXdot -> hwvtodn0ry += _rtB -> fbgb52dnaw ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> hsil0chis3 = _rtB -> od4rewcypc ; } _rtXdot ->
fdpg2dhqer = 0.0 ; _rtXdot -> fdpg2dhqer += _rtP -> P_321 * _rtX ->
fdpg2dhqer ; _rtXdot -> fdpg2dhqer += _rtB -> p4u52cdz0j ; _rtXdot ->
pkmi5ynvrb = 0.0 ; _rtXdot -> pkmi5ynvrb += _rtP -> P_326 * _rtX ->
pkmi5ynvrb ; _rtXdot -> pkmi5ynvrb += _rtB -> pzysbvittb ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> cph23tcm3m = _rtB -> oeqrqi1yhg ; } _rtXdot ->
jccjfuzxai = 0.0 ; _rtXdot -> jccjfuzxai += _rtP -> P_335 * _rtX ->
jccjfuzxai ; _rtXdot -> jccjfuzxai += _rtB -> f1al4weaso ; _rtXdot ->
mvd2pevwkz = 0.0 ; _rtXdot -> mvd2pevwkz += _rtP -> P_340 * _rtX ->
mvd2pevwkz ; _rtXdot -> mvd2pevwkz += _rtB -> ad5y31rmda ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> ksy2o0tkwn = _rtB -> pfba4bin2v ; } _rtXdot ->
nw4s40wdz2 = 0.0 ; _rtXdot -> nw4s40wdz2 += _rtP -> P_350 * _rtX ->
nw4s40wdz2 ; _rtXdot -> nw4s40wdz2 += _rtB -> bperb2as5o ; _rtXdot ->
pb403lheya = 0.0 ; _rtXdot -> pb403lheya += _rtP -> P_355 * _rtX ->
pb403lheya ; _rtXdot -> pb403lheya += _rtB -> j2ocxan4o0 ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> cdfctdfq0w = _rtB -> ow5lrns1ak ; } _rtXdot ->
nmhaueqlt1 = 0.0 ; _rtXdot -> nmhaueqlt1 += _rtP -> P_366 * _rtX ->
nmhaueqlt1 ; _rtXdot -> nmhaueqlt1 += _rtB -> bu1tbhjpdv ; _rtXdot ->
gt3adnl5hb = 0.0 ; _rtXdot -> gt3adnl5hb += _rtP -> P_371 * _rtX ->
gt3adnl5hb ; _rtXdot -> gt3adnl5hb += _rtB -> fujsn2boel ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> e0skt04bhf = _rtB -> pkqczepwyj ; } _rtXdot ->
pmnyfm5h5u = 0.0 ; _rtXdot -> pmnyfm5h5u += _rtP -> P_380 * _rtX ->
pmnyfm5h5u ; _rtXdot -> pmnyfm5h5u += _rtB -> ll3w5whb3u ; _rtXdot ->
nddgccshex = 0.0 ; _rtXdot -> nddgccshex += _rtP -> P_385 * _rtX ->
nddgccshex ; _rtXdot -> nddgccshex += _rtB -> apturjtxro ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> k5ycu1q42c = _rtB -> acumsenz15 ; } _rtXdot ->
k4tkggdnnr = 0.0 ; _rtXdot -> k4tkggdnnr += _rtP -> P_395 * _rtX ->
k4tkggdnnr ; _rtXdot -> k4tkggdnnr += _rtB -> fy0eubivg0 ; _rtXdot ->
mxeiruq5kr = 0.0 ; _rtXdot -> mxeiruq5kr += _rtP -> P_400 * _rtX ->
mxeiruq5kr ; _rtXdot -> mxeiruq5kr += _rtB -> gedrcejq23 ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> lmjo1j5prc = _rtB -> dv0t3hxt1n ; } _rtXdot ->
mgv01d2cjw = 0.0 ; _rtXdot -> mgv01d2cjw += _rtP -> P_411 * _rtX ->
mgv01d2cjw ; _rtXdot -> mgv01d2cjw += _rtB -> ite1vno4hy ; _rtXdot ->
g5vybs2yfi = 0.0 ; _rtXdot -> g5vybs2yfi += _rtP -> P_416 * _rtX ->
g5vybs2yfi ; _rtXdot -> g5vybs2yfi += _rtB -> ig2ozehlaq ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> mbti4ipw3j = _rtB -> fyknhrqbo4 ; } _rtXdot ->
glghzxiyqq = 0.0 ; _rtXdot -> glghzxiyqq += _rtP -> P_425 * _rtX ->
glghzxiyqq ; _rtXdot -> glghzxiyqq += _rtB -> fbu1ktdpcw ; _rtXdot ->
ntf0pkglvk = 0.0 ; _rtXdot -> ntf0pkglvk += _rtP -> P_430 * _rtX ->
ntf0pkglvk ; _rtXdot -> ntf0pkglvk += _rtB -> dz44revwz1 ; { ( ( lxdz41kqrh *
) ssGetdX ( S ) ) -> b5hykck5fp = _rtB -> j5imzuuv2y ; } _rtXdot ->
khr0fwz2ri = 0.0 ; _rtXdot -> khr0fwz2ri += _rtP -> P_440 * _rtX ->
khr0fwz2ri ; _rtXdot -> khr0fwz2ri += _rtB -> m52tklnlgu ; }
#define MDL_PROJECTION
static void mdlProjection ( SimStruct * S ) { ssCallAccelRunBlock ( S , 26 ,
74 , SS_CALL_MDL_PROJECTION ) ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { fwhqxupvfb * _rtB ;
gv4lfag1c5 * _rtP ; arpw0ddufh * _rtZCSV ; bpocjipxik * _rtDW ; _rtDW = ( (
bpocjipxik * ) ssGetRootDWork ( S ) ) ; _rtZCSV = ( ( arpw0ddufh * )
ssGetSolverZcSignalVector ( S ) ) ; _rtP = ( ( gv4lfag1c5 * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( fwhqxupvfb * ) _ssGetBlockIO ( S ) ) ;
_rtZCSV -> gb01noqbj3 = _rtB -> nbl0ysbr3h - _rtB -> o2bfsepd3t ; _rtZCSV ->
g5oc2lawsd = _rtB -> g3sryjiihq - _rtP -> P_29 ; _rtZCSV -> jkqhuyvqz2 = _rtB
-> g3sryjiihq - _rtP -> P_30 ; _rtZCSV -> nqkfubt2to = _rtB -> pil5ufxoef -
_rtP -> P_32 ; _rtZCSV -> plb5bdh34n = _rtB -> pil5ufxoef - _rtP -> P_33 ;
_rtZCSV -> nxpmwixgxp = _rtB -> ed1qlbi42l - _rtP -> P_35 ; _rtZCSV ->
jprsnl5mi4 = _rtB -> ed1qlbi42l - _rtP -> P_36 ; _rtZCSV -> hmhhn3mbon = _rtB
-> e1jqosdkzn - _rtP -> P_39 ; _rtZCSV -> ledpcdeywb = _rtB -> e1jqosdkzn -
_rtP -> P_40 ; _rtZCSV -> bouxgifg51 = _rtB -> jcyf4n31wf - _rtP -> P_42 ;
_rtZCSV -> j204dmwahe = _rtB -> jcyf4n31wf - _rtP -> P_43 ; _rtZCSV ->
joy2tdhbea = _rtB -> a1wvi15y5z - _rtP -> P_45 ; _rtZCSV -> fleoy0llqr = _rtB
-> a1wvi15y5z - _rtP -> P_46 ; _rtZCSV -> o5n1fl3i1g = _rtB -> m1wdj4ywn0 -
_rtP -> P_49 ; _rtZCSV -> ja4x1iilwt = _rtB -> m1wdj4ywn0 - _rtP -> P_50 ;
_rtZCSV -> hggqhkugwx = _rtB -> drjx2o4dvc - _rtP -> P_52 ; _rtZCSV ->
dq13jevjxi = _rtB -> drjx2o4dvc - _rtP -> P_53 ; _rtZCSV -> nkl5d4isw0 = _rtB
-> liod4lgaau - _rtP -> P_55 ; _rtZCSV -> j5knolj0bg = _rtB -> liod4lgaau -
_rtP -> P_56 ; _rtZCSV -> kovfsy3esd = _rtB -> cvz0aedo3t - _rtP -> P_59 ;
_rtZCSV -> mirby1tjwk = _rtB -> cvz0aedo3t - _rtP -> P_60 ; _rtZCSV ->
drxhtjdepo = _rtB -> lzdhfvavgi - _rtP -> P_62 ; _rtZCSV -> gcnsrpzpxw = _rtB
-> lzdhfvavgi - _rtP -> P_63 ; _rtZCSV -> fuqf4fmezi = _rtB -> ne2zyxbo02 -
_rtP -> P_65 ; _rtZCSV -> eyjmtkgjuv = _rtB -> ne2zyxbo02 - _rtP -> P_66 ;
_rtZCSV -> bxdphrwdih = _rtB -> c3s43vv3fy - _rtP -> P_69 ; _rtZCSV ->
bows4d1ol3 = _rtB -> c3s43vv3fy - _rtP -> P_70 ; _rtZCSV -> es1jvix3a1 = _rtB
-> j3qgyvd5st - _rtP -> P_72 ; _rtZCSV -> hcaphnpvq2 = _rtB -> j3qgyvd5st -
_rtP -> P_73 ; _rtZCSV -> pk5skh10t2 = _rtB -> j3l3up1kvo - _rtP -> P_75 ;
_rtZCSV -> gvtn32z1do = _rtB -> j3l3up1kvo - _rtP -> P_76 ; _rtZCSV ->
be0otep23j = _rtB -> nkoo0exfdx - _rtP -> P_79 ; _rtZCSV -> fwspl10g2v = _rtB
-> nkoo0exfdx - _rtP -> P_80 ; _rtZCSV -> jeiflfvyu4 = _rtB -> ip5i4w2t4o -
_rtP -> P_82 ; _rtZCSV -> nxm5mjk0lh = _rtB -> ip5i4w2t4o - _rtP -> P_83 ;
_rtZCSV -> n11r4npq1t = _rtB -> aevstei5cx - _rtP -> P_85 ; _rtZCSV ->
bspnwtr54u = _rtB -> aevstei5cx - _rtP -> P_86 ; _rtZCSV -> igxkd4utc2 = _rtB
-> n2b4t5qkih ; _rtZCSV -> d4oscbwopb = _rtB -> bt3v1dlnor ; _rtZCSV ->
l0gowdc50d = 0.0 ; if ( ( _rtB -> krl0rvqgpa < 4.0 ) && ( _rtB -> fh4vof1q4k
< 1.0 ) ) { _rtZCSV -> l0gowdc50d = 1.0 ; } { real_T * zcsv = & ( ( (
arpw0ddufh * ) ssGetSolverZcSignalVector ( S ) ) -> na1jczuzfju . chnz0bwja4
) ; int_T i ; for ( i = 0 ; i < 2 ; i ++ ) { zcsv [ i ] = 0.0 ; } } if (
_rtDW -> lpfhrsacdg == 0 ) { cy205zjjvp ( & _rtB -> na1jczuzfju , (
nuymkaafal * ) & _rtP -> na1jczuzfju , & _rtZCSV -> na1jczuzfju ) ; } _rtZCSV
-> pgdggw2glo = _rtB -> dl5hplbqw5 ; _rtZCSV -> hsxglcokvo = _rtB ->
dind2uaenb ; _rtZCSV -> dc35anxygc = 0.0 ; if ( ( _rtB -> ojw4smlies < 4.0 )
&& ( _rtB -> aiqdmb44iz < 1.0 ) ) { _rtZCSV -> dc35anxygc = 1.0 ; } { real_T
* zcsv = & ( ( ( arpw0ddufh * ) ssGetSolverZcSignalVector ( S ) ) ->
mqod2hqw1t . chnz0bwja4 ) ; int_T i ; for ( i = 0 ; i < 2 ; i ++ ) { zcsv [ i
] = 0.0 ; } } if ( _rtDW -> ltptzi1mym == 0 ) { cy205zjjvp ( & _rtB ->
mqod2hqw1t , ( nuymkaafal * ) & _rtP -> mqod2hqw1t , & _rtZCSV -> mqod2hqw1t
) ; } _rtZCSV -> jqpzolafih = _rtB -> ofgjid40wp ; _rtZCSV -> pw5ewfkqku =
_rtB -> p1bdslpw4i ; _rtZCSV -> pe2qdd1qku = 0.0 ; if ( ( _rtB -> l1ujllkjwm
< 4.0 ) && ( _rtB -> okhmrtyj2b < 1.0 ) ) { _rtZCSV -> pe2qdd1qku = 1.0 ; } {
real_T * zcsv = & ( ( ( arpw0ddufh * ) ssGetSolverZcSignalVector ( S ) ) ->
ciiustz54e . chnz0bwja4 ) ; int_T i ; for ( i = 0 ; i < 2 ; i ++ ) { zcsv [ i
] = 0.0 ; } } if ( _rtDW -> omvzilo3wu == 0 ) { cy205zjjvp ( & _rtB ->
ciiustz54e , ( nuymkaafal * ) & _rtP -> ciiustz54e , & _rtZCSV -> ciiustz54e
) ; } _rtZCSV -> ehfx0stuca = _rtB -> caqymvlmdq ; _rtZCSV -> msev0xjjvh =
_rtB -> kf2ucwxo3i ; _rtZCSV -> fuwh4dlkq1 = 0.0 ; if ( ( _rtB -> j4z3scridc
< 4.0 ) && ( _rtB -> mmbxsshdvn < 1.0 ) ) { _rtZCSV -> fuwh4dlkq1 = 1.0 ; } {
real_T * zcsv = & ( ( ( arpw0ddufh * ) ssGetSolverZcSignalVector ( S ) ) ->
aiyffyrf0x . chnz0bwja4 ) ; int_T i ; for ( i = 0 ; i < 2 ; i ++ ) { zcsv [ i
] = 0.0 ; } } if ( _rtDW -> ij53yycoh0 == 0 ) { cy205zjjvp ( & _rtB ->
aiyffyrf0x , ( nuymkaafal * ) & _rtP -> aiyffyrf0x , & _rtZCSV -> aiyffyrf0x
) ; } _rtZCSV -> agleipqazf = _rtB -> ic2fzqpr5w ; _rtZCSV -> jcknf5hdwk =
_rtB -> fxxftdxvue ; _rtZCSV -> ithaulkggz = 0.0 ; if ( ( _rtB -> eqgqiyei4y
< 4.0 ) && ( _rtB -> bwzybpg4rs < 1.0 ) ) { _rtZCSV -> ithaulkggz = 1.0 ; } {
real_T * zcsv = & ( ( ( arpw0ddufh * ) ssGetSolverZcSignalVector ( S ) ) ->
ogmpawilnd . chnz0bwja4 ) ; int_T i ; for ( i = 0 ; i < 2 ; i ++ ) { zcsv [ i
] = 0.0 ; } } if ( _rtDW -> m4a5pybsb3 == 0 ) { cy205zjjvp ( & _rtB ->
ogmpawilnd , ( nuymkaafal * ) & _rtP -> ogmpawilnd , & _rtZCSV -> ogmpawilnd
) ; } _rtZCSV -> pwpw2irisv = _rtB -> prqxdyfyh2 ; _rtZCSV -> n14p4vqctn =
_rtB -> dzd2ploozm ; _rtZCSV -> ls20rb3f0f = 0.0 ; if ( ( _rtB -> gwsiifvsss
< 4.0 ) && ( _rtB -> aff0hhixvp < 1.0 ) ) { _rtZCSV -> ls20rb3f0f = 1.0 ; } {
real_T * zcsv = & ( ( ( arpw0ddufh * ) ssGetSolverZcSignalVector ( S ) ) ->
gibf3zurdd . chnz0bwja4 ) ; int_T i ; for ( i = 0 ; i < 2 ; i ++ ) { zcsv [ i
] = 0.0 ; } } if ( _rtDW -> kgstnambvp == 0 ) { cy205zjjvp ( & _rtB ->
gibf3zurdd , ( nuymkaafal * ) & _rtP -> gibf3zurdd , & _rtZCSV -> gibf3zurdd
) ; } _rtZCSV -> a252zkg5p4 = _rtB -> easygxnnnn - _rtB -> nzn4q1sbb3 ;
_rtZCSV -> mxybvkgls3 = _rtB -> p2aqiuarmj ; _rtZCSV -> eyaadxnqjd = _rtB ->
h1r4x5wbvt ; _rtZCSV -> hzklyv0xzc = 0.0 ; if ( ( _rtB -> mof0z5zbuk < 10.0 )
&& ( _rtB -> lbkrnv0eqq < 1.0 ) ) { _rtZCSV -> hzklyv0xzc = 1.0 ; } { real_T
* zcsv = & ( ( ( arpw0ddufh * ) ssGetSolverZcSignalVector ( S ) ) ->
bjhy5xugrc ) ; int_T i ; for ( i = 0 ; i < 2 ; i ++ ) { zcsv [ i ] = 0.0 ; }
} if ( _rtDW -> fj23pr2tgi == 0 ) { _rtZCSV -> bjhy5xugrc = _rtB ->
fc51keidwe - _rtP -> P_2 ; _rtZCSV -> lyvf2sqjho = _rtB -> fc51keidwe - _rtP
-> P_3 ; } } static void mdlInitializeSizes ( SimStruct * S ) {
ssSetChecksumVal ( S , 0 , 1103476954U ) ; ssSetChecksumVal ( S , 1 ,
545104851U ) ; ssSetChecksumVal ( S , 2 , 2859263191U ) ; ssSetChecksumVal (
S , 3 , 2563133079U ) ; { mxArray * slVerStructMat = NULL ; mxArray *
slStrMat = mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status
= mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if (
status == 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 ,
"Version" ) ; if ( slVerMat == NULL ) { status = 1 ; } else { status =
mxGetString ( slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.5" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
bpocjipxik ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( fwhqxupvfb ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofY ( S ) != sizeof
( hgxkokaugy ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal ExternalOutputs sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
gv4lfag1c5 ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & iipfbb1rgz ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( (
gv4lfag1c5 * ) ssGetDefaultParam ( S ) ) -> P_2 = rtMinusInf ; ( ( gv4lfag1c5
* ) ssGetDefaultParam ( S ) ) -> P_7 = rtInf ; ( ( gv4lfag1c5 * )
ssGetDefaultParam ( S ) ) -> gibf3zurdd . P_2 = rtMinusInf ; ( ( gv4lfag1c5 *
) ssGetDefaultParam ( S ) ) -> gibf3zurdd . P_7 = rtInf ; ( ( gv4lfag1c5 * )
ssGetDefaultParam ( S ) ) -> ogmpawilnd . P_2 = rtMinusInf ; ( ( gv4lfag1c5 *
) ssGetDefaultParam ( S ) ) -> ogmpawilnd . P_7 = rtInf ; ( ( gv4lfag1c5 * )
ssGetDefaultParam ( S ) ) -> aiyffyrf0x . P_2 = rtMinusInf ; ( ( gv4lfag1c5 *
) ssGetDefaultParam ( S ) ) -> aiyffyrf0x . P_7 = rtInf ; ( ( gv4lfag1c5 * )
ssGetDefaultParam ( S ) ) -> ciiustz54e . P_2 = rtMinusInf ; ( ( gv4lfag1c5 *
) ssGetDefaultParam ( S ) ) -> ciiustz54e . P_7 = rtInf ; ( ( gv4lfag1c5 * )
ssGetDefaultParam ( S ) ) -> mqod2hqw1t . P_2 = rtMinusInf ; ( ( gv4lfag1c5 *
) ssGetDefaultParam ( S ) ) -> mqod2hqw1t . P_7 = rtInf ; ( ( gv4lfag1c5 * )
ssGetDefaultParam ( S ) ) -> na1jczuzfju . P_2 = rtMinusInf ; ( ( gv4lfag1c5
* ) ssGetDefaultParam ( S ) ) -> na1jczuzfju . P_7 = rtInf ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"
