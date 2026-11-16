// FUN_fffffff008e9b680 @ fffffff008e9b680 size=84
// CALLERS:
//   fffffff00afd5823 no-fn
//   fffffff008e9a5c8 FUN_fffffff008e9a458@fffffff008e9a458
//   fffffff008e9a8cc FUN_fffffff008e9a684@fffffff008e9a684
//   fffffff008e9b704 FUN_fffffff008e9b6d4@fffffff008e9b6d4
// CALLEES:
//   fffffff008eb93e0 thunk_FUN_fffffff009c22b48
//   fffffff008eb9350 thunk_FUN_fffffff009c223bc

undefined8
FUN_fffffff008e9b680
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 extraout_q0 [16];
  
  if (((param_7 == 0) || (iVar2 = thunk_FUN_fffffff009c223bc(param_7), iVar2 == 0)) ||
     (cVar1 = thunk_FUN_fffffff009c22b48
                        (extraout_q0,param_2,param_3,param_4,param_5,param_6,param_7,param_8),
     cVar1 != '\x05')) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

