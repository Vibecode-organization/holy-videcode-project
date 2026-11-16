// FUN_fffffff009c42814 @ fffffff009c42814 size=112
// CALLERS:
//   fffffff00afec19e no-fn
//   fffffff009c4409c FUN_fffffff009c4405c@fffffff009c4405c
//   fffffff009c3743c FUN_fffffff009c373ec@fffffff009c373ec
//   fffffff009c3ad4c FUN_fffffff009c3ab8c@fffffff009c3ab8c
//   fffffff009c425b0 FUN_fffffff009c4257c@fffffff009c4257c
// CALLEES:
//   fffffff009c49430 FUN_fffffff009c49430
//   fffffff009c49664 thunk_FUN_fffffff00a228180
//   fffffff009c49674 thunk_FUN_fffffff00a228d30

long FUN_fffffff009c42814
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               long param_8)

{
  long lVar1;
  undefined1 auVar2 [16];
  bool bVar3;
  long lVar4;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  
  thunk_FUN_fffffff00a228180(*(ulong *)(param_7 + 0x10));
  lVar4 = *(long *)(param_7 + 0x20);
  auVar2 = extraout_q0;
  do {
    lVar1 = lVar4;
    if (lVar1 == 0) break;
    lVar4 = *(long *)(lVar1 + 0x10);
  } while ((*(long *)(lVar1 + 0x28) != param_8) ||
          (bVar3 = FUN_fffffff009c49430
                             (auVar2,param_2,param_3,param_4,param_5,param_6,(uint *)(lVar1 + 0x20))
          , auVar2 = extraout_q0_00, !bVar3));
  thunk_FUN_fffffff00a228d30(*(long *)(param_7 + 0x10));
  return lVar1;
}

