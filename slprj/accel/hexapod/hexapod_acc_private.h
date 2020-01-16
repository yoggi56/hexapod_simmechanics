#include "__cf_hexapod.h"
#ifndef RTW_HEADER_hexapod_acc_private_h_
#define RTW_HEADER_hexapod_acc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
extern void rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( const real_T u0 [ 9 ] , const
real_T u1 [ 3 ] , real_T y [ 3 ] ) ; extern real_T look1_binlxpw ( real_T u0
, const real_T bp0 [ ] , const real_T table [ ] , uint32_T maxIndex ) ;
extern real_T look1_binlcpw ( real_T u0 , const real_T bp0 [ ] , const real_T
table [ ] , uint32_T maxIndex ) ; void gg1bfsp2im ( SimStruct * const S ) ;
void cy205zjjvp ( aqk41knsjs * localB , nuymkaafal * localP , mtzv34lgmb *
localZCSV ) ; void oogbjkhpvp ( SimStruct * const S ) ; void na1jczuzfj (
SimStruct * const S , real_T dc5okcroby , real_T o4edwafn02 , real_T
p1hgv0dswb , real_T j25sq3a1qg , const real_T punmnex54m [ 9 ] , real_T
jig2xoj0os , real_T hdkiq2aomp , real_T crvf1f5mcd , real_T b5aswy32si ,
real_T eifcutivb3 [ 12 ] , aqk41knsjs * localB , e4j3nmaq30 * localDW ,
nuymkaafal * localP ) ;
#endif
