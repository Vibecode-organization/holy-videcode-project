// FUN_fffffff00a9a7b30 @ fffffff00a9a7b30 size=48
// CALLERS:
//   fffffff00afbf5e1 no-fn
//   fffffff007ff2208 no-fn
//   fffffff007ff8c70 no-fn
//   fffffff00806c680 no-fn
//   fffffff0080fd338 no-fn
//   fffffff009984588 thunk_FUN_fffffff00a9a7b30@fffffff00998457c
//   fffffff0099a0508 thunk_FUN_fffffff00a9a7b30@fffffff0099a04fc
//   fffffff009c49840 thunk_FUN_fffffff00a9a7b30@fffffff009c49834
//   fffffff00a1bb2e4 thunk_FUN_fffffff00a9a7b30@fffffff00a1bb2d8
// CALLEES:
//   fffffff00a34c248 FUN_fffffff00a34c248

undefined8
FUN_fffffff00a9a7b30
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long *param_8,
          undefined4 *param_9)

{
  undefined4 uVar1;
  
  uVar1 = FUN_fffffff00a34c248(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,0x26)
  ;
  *param_9 = uVar1;
  return 0;
}

