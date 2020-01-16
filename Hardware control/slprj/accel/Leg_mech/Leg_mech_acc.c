#include "__cf_Leg_mech.h"
#include <math.h>
#include "Leg_mech_acc.h"
#include "Leg_mech_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T * lastU ;
boolean_T first_output ; real_T gk1osxznds ; dtjh2bwaj2 * _rtB ; endjf0yiwl *
_rtP ; aglbppzn4x * _rtX ; e5eijqndez * _rtDW ; _rtDW = ( ( e5eijqndez * )
ssGetRootDWork ( S ) ) ; _rtX = ( ( aglbppzn4x * ) ssGetContStates ( S ) ) ;
_rtP = ( ( endjf0yiwl * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( dtjh2bwaj2 *
) _ssGetBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
cdahssyvp2 = _rtP -> P_0 ; } _rtB -> cph0nr0jbe = _rtX -> i2mr2yogps ; if (
_rtB -> cph0nr0jbe > _rtP -> P_2 ) { _rtB -> br3qau50ef = _rtP -> P_2 ; }
else if ( _rtB -> cph0nr0jbe < _rtP -> P_3 ) { _rtB -> br3qau50ef = _rtP ->
P_3 ; } else { _rtB -> br3qau50ef = _rtB -> cph0nr0jbe ; } _rtB -> erxvrsj0m0
= 0.0 ; _rtB -> erxvrsj0m0 += _rtP -> P_5 * _rtX -> pp3nbaforg ; _rtB ->
jw1tbzsvfu = _rtP -> P_6 * _rtB -> erxvrsj0m0 ; if ( ssIsSampleHit ( S , 1 ,
0 ) ) { ssCallAccelRunBlock ( S , 0 , 6 , SS_CALL_MDL_OUTPUTS ) ; } if ( (
_rtDW -> nndpwa0hxi >= ssGetT ( S ) ) && ( _rtDW -> ld2pnhmiep >= ssGetT ( S
) ) ) { gk1osxznds = 0.0 ; } else { gk1osxznds = _rtDW -> nndpwa0hxi ; lastU
= & _rtDW -> o4z3pm4ews ; if ( _rtDW -> nndpwa0hxi < _rtDW -> ld2pnhmiep ) {
if ( _rtDW -> ld2pnhmiep < ssGetT ( S ) ) { gk1osxznds = _rtDW -> ld2pnhmiep
; lastU = & _rtDW -> bvbrrbyb5z ; } } else { if ( _rtDW -> nndpwa0hxi >=
ssGetT ( S ) ) { gk1osxznds = _rtDW -> ld2pnhmiep ; lastU = & _rtDW ->
bvbrrbyb5z ; } } gk1osxznds = ( _rtB -> jw1tbzsvfu - * lastU ) / ( ssGetT ( S
) - gk1osxznds ) ; } if ( gk1osxznds > _rtP -> P_7 ) { _rtB -> e024rkh3ov =
_rtP -> P_7 ; } else if ( gk1osxznds < _rtP -> P_8 ) { _rtB -> e024rkh3ov =
_rtP -> P_8 ; } else { _rtB -> e024rkh3ov = gk1osxznds ; } if ( ssIsSampleHit
( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 0 , 9 , SS_CALL_MDL_OUTPUTS ) ; }
_rtB -> bq31ee5rnh = _rtP -> P_9 * _rtB -> br3qau50ef ; _rtB -> iq4oicudpb =
_rtB -> cdahssyvp2 - _rtB -> bq31ee5rnh ; _rtB -> p4ezv02dea = _rtP -> P_10 *
_rtB -> iq4oicudpb ; if ( ( _rtDW -> m3akjxxfz4 >= ssGetT ( S ) ) && ( _rtDW
-> a1lckp3xid >= ssGetT ( S ) ) ) { _rtB -> mltpgxmzer = 0.0 ; } else {
gk1osxznds = _rtDW -> m3akjxxfz4 ; lastU = & _rtDW -> giyluo0zow ; if ( _rtDW
-> m3akjxxfz4 < _rtDW -> a1lckp3xid ) { if ( _rtDW -> a1lckp3xid < ssGetT ( S
) ) { gk1osxznds = _rtDW -> a1lckp3xid ; lastU = & _rtDW -> kodryrbsza ; } }
else { if ( _rtDW -> m3akjxxfz4 >= ssGetT ( S ) ) { gk1osxznds = _rtDW ->
a1lckp3xid ; lastU = & _rtDW -> kodryrbsza ; } } _rtB -> mltpgxmzer = ( _rtB
-> p4ezv02dea - * lastU ) / ( ssGetT ( S ) - gk1osxznds ) ; } _rtB ->
nazfau3lh4 = _rtX -> d4z4om03g1 ; _rtB -> cz5ohjqll0 = _rtP -> P_12 * _rtB ->
iq4oicudpb ; _rtB -> p3sdcp0bph = _rtP -> P_13 * _rtB -> iq4oicudpb ; _rtB ->
kkzl0cmwos = ( _rtB -> nazfau3lh4 + _rtB -> cz5ohjqll0 ) + _rtB -> mltpgxmzer
; _rtB -> bbpj4zninz = _rtP -> P_14 * _rtB -> erxvrsj0m0 ; _rtB -> melzdgeneo
= _rtP -> P_15 * _rtB -> kkzl0cmwos ; _rtB -> octrugiayc = 0.0 ; _rtB ->
octrugiayc += _rtP -> P_17 * _rtX -> ldl2i1sth4 ; _rtB -> bo2wiaphgg = _rtP
-> P_18 * _rtB -> octrugiayc ; _rtB -> o0ryzogsig = _rtB -> melzdgeneo - _rtB
-> bbpj4zninz ; _rtB -> g2yykp3yxu = _rtX -> b5wra4nhza ; if ( _rtB ->
g2yykp3yxu > _rtP -> P_20 ) { _rtB -> dddycepwsv = _rtP -> P_20 ; } else if (
_rtB -> g2yykp3yxu < _rtP -> P_21 ) { _rtB -> dddycepwsv = _rtP -> P_21 ; }
else { _rtB -> dddycepwsv = _rtB -> g2yykp3yxu ; } if ( ssIsSampleHit ( S , 1
, 0 ) ) { ssCallAccelRunBlock ( S , 0 , 25 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
ft30d54lmi = _rtP -> P_22 ; } _rtB -> lfj4xysyi3 = 0.0 ; _rtB -> lfj4xysyi3
+= _rtP -> P_24 * _rtX -> dczbtdrn1l ; _rtB -> gqzslppc0s = _rtP -> P_25 *
_rtB -> lfj4xysyi3 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock
( S , 0 , 30 , SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW -> ghlzhlsroj >= ssGetT
( S ) ) && ( _rtDW -> kvb0ns4lek >= ssGetT ( S ) ) ) { gk1osxznds = 0.0 ; }
else { gk1osxznds = _rtDW -> ghlzhlsroj ; lastU = & _rtDW -> oqljj4aupg ; if
( _rtDW -> ghlzhlsroj < _rtDW -> kvb0ns4lek ) { if ( _rtDW -> kvb0ns4lek <
ssGetT ( S ) ) { gk1osxznds = _rtDW -> kvb0ns4lek ; lastU = & _rtDW ->
iibci31gsh ; } } else { if ( _rtDW -> ghlzhlsroj >= ssGetT ( S ) ) {
gk1osxznds = _rtDW -> kvb0ns4lek ; lastU = & _rtDW -> iibci31gsh ; } }
gk1osxznds = ( _rtB -> gqzslppc0s - * lastU ) / ( ssGetT ( S ) - gk1osxznds )
; } if ( gk1osxznds > _rtP -> P_26 ) { _rtB -> ltxcblf3x3 = _rtP -> P_26 ; }
else if ( gk1osxznds < _rtP -> P_27 ) { _rtB -> ltxcblf3x3 = _rtP -> P_27 ; }
else { _rtB -> ltxcblf3x3 = gk1osxznds ; } if ( ssIsSampleHit ( S , 1 , 0 ) )
{ ssCallAccelRunBlock ( S , 0 , 33 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
ez4cz0aert = _rtP -> P_28 * _rtB -> dddycepwsv ; _rtB -> ob2tky4yb5 = _rtB ->
ft30d54lmi - _rtB -> ez4cz0aert ; _rtB -> mem002lfu4 = _rtP -> P_29 * _rtB ->
ob2tky4yb5 ; if ( ( _rtDW -> pc2eqzxonm >= ssGetT ( S ) ) && ( _rtDW ->
mzqjkw5bjd >= ssGetT ( S ) ) ) { _rtB -> brd4xuts23 = 0.0 ; } else {
gk1osxznds = _rtDW -> pc2eqzxonm ; lastU = & _rtDW -> dr4bgc4chv ; if ( _rtDW
-> pc2eqzxonm < _rtDW -> mzqjkw5bjd ) { if ( _rtDW -> mzqjkw5bjd < ssGetT ( S
) ) { gk1osxznds = _rtDW -> mzqjkw5bjd ; lastU = & _rtDW -> jowz4dbtns ; } }
else { if ( _rtDW -> pc2eqzxonm >= ssGetT ( S ) ) { gk1osxznds = _rtDW ->
mzqjkw5bjd ; lastU = & _rtDW -> jowz4dbtns ; } } _rtB -> brd4xuts23 = ( _rtB
-> mem002lfu4 - * lastU ) / ( ssGetT ( S ) - gk1osxznds ) ; } _rtB ->
gtxs44e1ql = _rtX -> cfmni2r44a ; _rtB -> kgbfinlkli = _rtP -> P_31 * _rtB ->
ob2tky4yb5 ; _rtB -> ajt3332cqr = _rtP -> P_32 * _rtB -> ob2tky4yb5 ; _rtB ->
feccnccavl = ( _rtB -> gtxs44e1ql + _rtB -> kgbfinlkli ) + _rtB -> brd4xuts23
; _rtB -> idz0fe0hyt = _rtP -> P_33 * _rtB -> lfj4xysyi3 ; _rtB -> a4cv0lvec2
= _rtP -> P_34 * _rtB -> feccnccavl ; _rtB -> nam5wdg54i = 0.0 ; _rtB ->
nam5wdg54i += _rtP -> P_36 * _rtX -> nulrucfrwu ; _rtB -> erumreizen = _rtP
-> P_37 * _rtB -> nam5wdg54i ; _rtB -> emolj12mao = _rtB -> a4cv0lvec2 - _rtB
-> idz0fe0hyt ; _rtB -> d1gcgngdjs = _rtX -> erjevuv2j3 ; if ( _rtB ->
d1gcgngdjs > _rtP -> P_39 ) { _rtB -> auomm1zz4p = _rtP -> P_39 ; } else if (
_rtB -> d1gcgngdjs < _rtP -> P_40 ) { _rtB -> auomm1zz4p = _rtP -> P_40 ; }
else { _rtB -> auomm1zz4p = _rtB -> d1gcgngdjs ; } if ( ssIsSampleHit ( S , 1
, 0 ) ) { ssCallAccelRunBlock ( S , 0 , 49 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
ih4efok3og = _rtP -> P_42 * _rtP -> P_41 ; } _rtB -> lqyrrstjah = 0.0 ; _rtB
-> lqyrrstjah += _rtP -> P_44 * _rtX -> cdkmns0j4o ; _rtB -> a2ogz0ozt1 =
_rtP -> P_45 * _rtB -> lqyrrstjah ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 0 , 55 , SS_CALL_MDL_OUTPUTS ) ; } if ( ( _rtDW ->
mpeck0ln3i >= ssGetT ( S ) ) && ( _rtDW -> kt0ipcx1ey >= ssGetT ( S ) ) ) {
gk1osxznds = 0.0 ; } else { gk1osxznds = _rtDW -> mpeck0ln3i ; lastU = &
_rtDW -> hbqw1ru5hi ; if ( _rtDW -> mpeck0ln3i < _rtDW -> kt0ipcx1ey ) { if (
_rtDW -> kt0ipcx1ey < ssGetT ( S ) ) { gk1osxznds = _rtDW -> kt0ipcx1ey ;
lastU = & _rtDW -> lczpmmqxsw ; } } else { if ( _rtDW -> mpeck0ln3i >= ssGetT
( S ) ) { gk1osxznds = _rtDW -> kt0ipcx1ey ; lastU = & _rtDW -> lczpmmqxsw ;
} } gk1osxznds = ( _rtB -> a2ogz0ozt1 - * lastU ) / ( ssGetT ( S ) -
gk1osxznds ) ; } if ( gk1osxznds > _rtP -> P_46 ) { _rtB -> msohwgzuxt = _rtP
-> P_46 ; } else if ( gk1osxznds < _rtP -> P_47 ) { _rtB -> msohwgzuxt = _rtP
-> P_47 ; } else { _rtB -> msohwgzuxt = gk1osxznds ; } if ( ssIsSampleHit ( S
, 1 , 0 ) ) { ssCallAccelRunBlock ( S , 0 , 58 , SS_CALL_MDL_OUTPUTS ) ; }
_rtB -> k5shf42vcg = _rtP -> P_48 * _rtB -> auomm1zz4p ; _rtB -> ilguftpitt =
_rtB -> ih4efok3og - _rtB -> k5shf42vcg ; _rtB -> geqclvgbun = _rtP -> P_49 *
_rtB -> ilguftpitt ; if ( ( _rtDW -> p4z1tqfqmd >= ssGetT ( S ) ) && ( _rtDW
-> p5dl5h41wy >= ssGetT ( S ) ) ) { _rtB -> m3hivkpqpi = 0.0 ; } else {
gk1osxznds = _rtDW -> p4z1tqfqmd ; lastU = & _rtDW -> fst2trzs2i ; if ( _rtDW
-> p4z1tqfqmd < _rtDW -> p5dl5h41wy ) { if ( _rtDW -> p5dl5h41wy < ssGetT ( S
) ) { gk1osxznds = _rtDW -> p5dl5h41wy ; lastU = & _rtDW -> kptncbbh3v ; } }
else { if ( _rtDW -> p4z1tqfqmd >= ssGetT ( S ) ) { gk1osxznds = _rtDW ->
p5dl5h41wy ; lastU = & _rtDW -> kptncbbh3v ; } } _rtB -> m3hivkpqpi = ( _rtB
-> geqclvgbun - * lastU ) / ( ssGetT ( S ) - gk1osxznds ) ; } _rtB ->
hgpna2iuyu = _rtX -> e2scgnse0k ; _rtB -> pxmdypxwbp = _rtP -> P_51 * _rtB ->
ilguftpitt ; _rtB -> f15v1fmuvu = _rtP -> P_52 * _rtB -> ilguftpitt ; _rtB ->
boyziglokv = ( _rtB -> hgpna2iuyu + _rtB -> pxmdypxwbp ) + _rtB -> m3hivkpqpi
; _rtB -> fexbsafsku = _rtP -> P_53 * _rtB -> lqyrrstjah ; _rtB -> gb4e03la1v
= _rtP -> P_54 * _rtB -> boyziglokv ; _rtB -> goruhspumi = 0.0 ; _rtB ->
goruhspumi += _rtP -> P_56 * _rtX -> am2plv2zhu ; _rtB -> c0c05bnev2 = _rtP
-> P_57 * _rtB -> goruhspumi ; _rtB -> fsllpl1l25 = _rtB -> gb4e03la1v - _rtB
-> fexbsafsku ; first_output = false ; if ( _rtDW -> bvyx5kxert == 0.0 ) {
_rtDW -> bvyx5kxert = 1.0 ; first_output = true ; } if ( first_output ) {
_rtX -> eaizrkivmk [ 0 ] = _rtB -> auomm1zz4p ; _rtX -> eaizrkivmk [ 1 ] =
0.0 ; } _rtB -> petw5th2mw [ 0 ] = _rtX -> eaizrkivmk [ 0 ] ; _rtB ->
petw5th2mw [ 1 ] = _rtX -> eaizrkivmk [ 1 ] ; _rtB -> petw5th2mw [ 2 ] = ( (
_rtB -> auomm1zz4p - _rtX -> eaizrkivmk [ 0 ] ) * 1000.0 - 2.0 * _rtX ->
eaizrkivmk [ 1 ] ) * 1000.0 ; _rtB -> petw5th2mw [ 3 ] = 0.0 ; first_output =
false ; if ( _rtDW -> p2dfd03gui == 0.0 ) { _rtDW -> p2dfd03gui = 1.0 ;
first_output = true ; } if ( first_output ) { _rtX -> clzllcgeow [ 0 ] = _rtB
-> br3qau50ef ; _rtX -> clzllcgeow [ 1 ] = 0.0 ; } _rtB -> ngw1lto2mp [ 0 ] =
_rtX -> clzllcgeow [ 0 ] ; _rtB -> ngw1lto2mp [ 1 ] = _rtX -> clzllcgeow [ 1
] ; _rtB -> ngw1lto2mp [ 2 ] = ( ( _rtB -> br3qau50ef - _rtX -> clzllcgeow [
0 ] ) * 1000.0 - 2.0 * _rtX -> clzllcgeow [ 1 ] ) * 1000.0 ; _rtB ->
ngw1lto2mp [ 3 ] = 0.0 ; first_output = false ; if ( _rtDW -> lewlj2nlvj ==
0.0 ) { _rtDW -> lewlj2nlvj = 1.0 ; first_output = true ; } if ( first_output
) { _rtX -> majvdw5wcp [ 0 ] = _rtB -> dddycepwsv ; _rtX -> majvdw5wcp [ 1 ]
= 0.0 ; } _rtB -> ga3df5zum4 [ 0 ] = _rtX -> majvdw5wcp [ 0 ] ; _rtB ->
ga3df5zum4 [ 1 ] = _rtX -> majvdw5wcp [ 1 ] ; _rtB -> ga3df5zum4 [ 2 ] = ( (
_rtB -> dddycepwsv - _rtX -> majvdw5wcp [ 0 ] ) * 1000.0 - 2.0 * _rtX ->
majvdw5wcp [ 1 ] ) * 1000.0 ; _rtB -> ga3df5zum4 [ 3 ] = 0.0 ;
ssCallAccelRunBlock ( S , 0 , 75 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 0 , 76 , SS_CALL_MDL_OUTPUTS ) ;
} ssCallAccelRunBlock ( S , 0 , 96 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 97 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER (
tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { real_T * lastU ;
dtjh2bwaj2 * _rtB ; e5eijqndez * _rtDW ; _rtDW = ( ( e5eijqndez * )
ssGetRootDWork ( S ) ) ; _rtB = ( ( dtjh2bwaj2 * ) _ssGetBlockIO ( S ) ) ; if
( _rtDW -> nndpwa0hxi == ( rtInf ) ) { _rtDW -> nndpwa0hxi = ssGetT ( S ) ;
lastU = & _rtDW -> o4z3pm4ews ; } else if ( _rtDW -> ld2pnhmiep == ( rtInf )
) { _rtDW -> ld2pnhmiep = ssGetT ( S ) ; lastU = & _rtDW -> bvbrrbyb5z ; }
else if ( _rtDW -> nndpwa0hxi < _rtDW -> ld2pnhmiep ) { _rtDW -> nndpwa0hxi =
ssGetT ( S ) ; lastU = & _rtDW -> o4z3pm4ews ; } else { _rtDW -> ld2pnhmiep =
ssGetT ( S ) ; lastU = & _rtDW -> bvbrrbyb5z ; } * lastU = _rtB -> jw1tbzsvfu
; if ( _rtDW -> m3akjxxfz4 == ( rtInf ) ) { _rtDW -> m3akjxxfz4 = ssGetT ( S
) ; lastU = & _rtDW -> giyluo0zow ; } else if ( _rtDW -> a1lckp3xid == (
rtInf ) ) { _rtDW -> a1lckp3xid = ssGetT ( S ) ; lastU = & _rtDW ->
kodryrbsza ; } else if ( _rtDW -> m3akjxxfz4 < _rtDW -> a1lckp3xid ) { _rtDW
-> m3akjxxfz4 = ssGetT ( S ) ; lastU = & _rtDW -> giyluo0zow ; } else { _rtDW
-> a1lckp3xid = ssGetT ( S ) ; lastU = & _rtDW -> kodryrbsza ; } * lastU =
_rtB -> p4ezv02dea ; if ( _rtDW -> ghlzhlsroj == ( rtInf ) ) { _rtDW ->
ghlzhlsroj = ssGetT ( S ) ; lastU = & _rtDW -> oqljj4aupg ; } else if ( _rtDW
-> kvb0ns4lek == ( rtInf ) ) { _rtDW -> kvb0ns4lek = ssGetT ( S ) ; lastU = &
_rtDW -> iibci31gsh ; } else if ( _rtDW -> ghlzhlsroj < _rtDW -> kvb0ns4lek )
{ _rtDW -> ghlzhlsroj = ssGetT ( S ) ; lastU = & _rtDW -> oqljj4aupg ; } else
{ _rtDW -> kvb0ns4lek = ssGetT ( S ) ; lastU = & _rtDW -> iibci31gsh ; } *
lastU = _rtB -> gqzslppc0s ; if ( _rtDW -> pc2eqzxonm == ( rtInf ) ) { _rtDW
-> pc2eqzxonm = ssGetT ( S ) ; lastU = & _rtDW -> dr4bgc4chv ; } else if (
_rtDW -> mzqjkw5bjd == ( rtInf ) ) { _rtDW -> mzqjkw5bjd = ssGetT ( S ) ;
lastU = & _rtDW -> jowz4dbtns ; } else if ( _rtDW -> pc2eqzxonm < _rtDW ->
mzqjkw5bjd ) { _rtDW -> pc2eqzxonm = ssGetT ( S ) ; lastU = & _rtDW ->
dr4bgc4chv ; } else { _rtDW -> mzqjkw5bjd = ssGetT ( S ) ; lastU = & _rtDW ->
jowz4dbtns ; } * lastU = _rtB -> mem002lfu4 ; if ( _rtDW -> mpeck0ln3i == (
rtInf ) ) { _rtDW -> mpeck0ln3i = ssGetT ( S ) ; lastU = & _rtDW ->
hbqw1ru5hi ; } else if ( _rtDW -> kt0ipcx1ey == ( rtInf ) ) { _rtDW ->
kt0ipcx1ey = ssGetT ( S ) ; lastU = & _rtDW -> lczpmmqxsw ; } else if ( _rtDW
-> mpeck0ln3i < _rtDW -> kt0ipcx1ey ) { _rtDW -> mpeck0ln3i = ssGetT ( S ) ;
lastU = & _rtDW -> hbqw1ru5hi ; } else { _rtDW -> kt0ipcx1ey = ssGetT ( S ) ;
lastU = & _rtDW -> lczpmmqxsw ; } * lastU = _rtB -> a2ogz0ozt1 ; if ( _rtDW
-> p4z1tqfqmd == ( rtInf ) ) { _rtDW -> p4z1tqfqmd = ssGetT ( S ) ; lastU = &
_rtDW -> fst2trzs2i ; } else if ( _rtDW -> p5dl5h41wy == ( rtInf ) ) { _rtDW
-> p5dl5h41wy = ssGetT ( S ) ; lastU = & _rtDW -> kptncbbh3v ; } else if (
_rtDW -> p4z1tqfqmd < _rtDW -> p5dl5h41wy ) { _rtDW -> p4z1tqfqmd = ssGetT (
S ) ; lastU = & _rtDW -> fst2trzs2i ; } else { _rtDW -> p5dl5h41wy = ssGetT (
S ) ; lastU = & _rtDW -> kptncbbh3v ; } * lastU = _rtB -> geqclvgbun ;
ssCallAccelRunBlock ( S , 0 , 97 , SS_CALL_MDL_UPDATE ) ; UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { dtjh2bwaj2 * _rtB ; endjf0yiwl
* _rtP ; aglbppzn4x * _rtX ; grsri2mzjo * _rtXdot ; _rtXdot = ( ( grsri2mzjo
* ) ssGetdX ( S ) ) ; _rtX = ( ( aglbppzn4x * ) ssGetContStates ( S ) ) ;
_rtP = ( ( endjf0yiwl * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( dtjh2bwaj2 *
) _ssGetBlockIO ( S ) ) ; _rtXdot -> i2mr2yogps = _rtB -> jw1tbzsvfu ;
_rtXdot -> pp3nbaforg = 0.0 ; _rtXdot -> pp3nbaforg += _rtP -> P_4 * _rtX ->
pp3nbaforg ; _rtXdot -> pp3nbaforg += _rtB -> bo2wiaphgg ; _rtXdot ->
d4z4om03g1 = _rtB -> p3sdcp0bph ; _rtXdot -> ldl2i1sth4 = 0.0 ; _rtXdot ->
ldl2i1sth4 += _rtP -> P_16 * _rtX -> ldl2i1sth4 ; _rtXdot -> ldl2i1sth4 +=
_rtB -> o0ryzogsig ; _rtXdot -> b5wra4nhza = _rtB -> gqzslppc0s ; _rtXdot ->
dczbtdrn1l = 0.0 ; _rtXdot -> dczbtdrn1l += _rtP -> P_23 * _rtX -> dczbtdrn1l
; _rtXdot -> dczbtdrn1l += _rtB -> erumreizen ; _rtXdot -> cfmni2r44a = _rtB
-> ajt3332cqr ; _rtXdot -> nulrucfrwu = 0.0 ; _rtXdot -> nulrucfrwu += _rtP
-> P_35 * _rtX -> nulrucfrwu ; _rtXdot -> nulrucfrwu += _rtB -> emolj12mao ;
_rtXdot -> erjevuv2j3 = _rtB -> a2ogz0ozt1 ; _rtXdot -> cdkmns0j4o = 0.0 ;
_rtXdot -> cdkmns0j4o += _rtP -> P_43 * _rtX -> cdkmns0j4o ; _rtXdot ->
cdkmns0j4o += _rtB -> c0c05bnev2 ; _rtXdot -> e2scgnse0k = _rtB -> f15v1fmuvu
; _rtXdot -> am2plv2zhu = 0.0 ; _rtXdot -> am2plv2zhu += _rtP -> P_55 * _rtX
-> am2plv2zhu ; _rtXdot -> am2plv2zhu += _rtB -> fsllpl1l25 ; _rtXdot ->
eaizrkivmk [ 0 ] = _rtX -> eaizrkivmk [ 1 ] ; _rtXdot -> eaizrkivmk [ 1 ] = (
( _rtB -> auomm1zz4p - _rtX -> eaizrkivmk [ 0 ] ) * 1000.0 - 2.0 * _rtX ->
eaizrkivmk [ 1 ] ) * 1000.0 ; _rtXdot -> clzllcgeow [ 0 ] = _rtX ->
clzllcgeow [ 1 ] ; _rtXdot -> clzllcgeow [ 1 ] = ( ( _rtB -> br3qau50ef -
_rtX -> clzllcgeow [ 0 ] ) * 1000.0 - 2.0 * _rtX -> clzllcgeow [ 1 ] ) *
1000.0 ; _rtXdot -> majvdw5wcp [ 0 ] = _rtX -> majvdw5wcp [ 1 ] ; _rtXdot ->
majvdw5wcp [ 1 ] = ( ( _rtB -> dddycepwsv - _rtX -> majvdw5wcp [ 0 ] ) *
1000.0 - 2.0 * _rtX -> majvdw5wcp [ 1 ] ) * 1000.0 ; } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 837886427U
) ; ssSetChecksumVal ( S , 1 , 2545480864U ) ; ssSetChecksumVal ( S , 2 ,
2410676655U ) ; ssSetChecksumVal ( S , 3 , 3388748570U ) ; { mxArray *
slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" ) ;
char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat , 1
, & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat = mxGetField
( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) { status = 1 ; }
else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; } }
mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "8.5" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( e5eijqndez ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( dtjh2bwaj2 ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
endjf0yiwl ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & kizbign1ms ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static
void mdlInitializeSampleTimes ( SimStruct * S ) { } static void mdlTerminate
( SimStruct * S ) { }
#include "simulink.c"
