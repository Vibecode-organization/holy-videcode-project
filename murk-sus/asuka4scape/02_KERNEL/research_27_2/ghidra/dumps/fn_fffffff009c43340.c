// FUN_fffffff009c43340 @ fffffff009c43340 size=144
// CALLERS:
//   fffffff00afec1b5 no-fn
//   fffffff009c44984 FUN_fffffff009c443e0@fffffff009c443e0
//   fffffff009c43300 FUN_fffffff009c43270@fffffff009c43270
// CALLEES:
//   fffffff009c49984 thunk_FUN_fffffff00a970b64
//   fffffff009c49bc4 thunk_FUN_fffffff00a2600a0

void FUN_fffffff009c43340
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               uint param_8)

{
  long lVar1;
  long *plVar2;
  undefined1 extraout_q0 [16];
  
  if (((param_8 & 0xf00) == 0) && ((*(byte *)(param_7 + 0xd) & 0xf) != 0)) {
    plVar2 = *(long **)(param_7 + 0x18);
    lVar1 = thunk_FUN_fffffff00a2600a0();
    plVar2 = (long *)thunk_FUN_fffffff00a970b64
                               (extraout_q0,param_2,param_3,param_4,param_5,param_6,plVar2,lVar1,0,
                                (undefined ********)0x501,(undefined ********)0x0,0);
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))();
    }
  }
  *(uint *)(param_7 + 0xc) = param_8;
  return;
}

