// FUN_fffffff009c3f130 @ fffffff009c3f130 size=160
// CALLERS:
//   fffffff00afec114 no-fn
//   fffffff009c3b410 FUN_fffffff009c3b3ac@fffffff009c3b3ac
//   fffffff009c3cba0 FUN_fffffff009c3cb74@fffffff009c3cb74
//   fffffff009c3ccb4 FUN_fffffff009c3cc88@fffffff009c3cc88
//   fffffff009c3cdd8 FUN_fffffff009c3cd9c@fffffff009c3cd9c
// CALLEES:
//   fffffff009c16670 FUN_fffffff009c16670
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c495d4 thunk_FUN_fffffff00a226de0
//   fffffff009c495b4 thunk_FUN_fffffff00a2262a8
//   fffffff009c3f044 FUN_fffffff009c3f044

long FUN_fffffff009c3f130
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               uint param_8)

{
  undefined8 uVar1;
  long lVar2;
  undefined1 auVar3 [16];
  long *local_38;
  long local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_38 = (long *)&DAT_aaaaaaaaaaaaaaaa;
  local_30 = 0;
  auVar3 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0xd8));
  uVar1 = FUN_fffffff009c3f044
                    (auVar3,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                     (long *)&local_38);
  lVar2 = 0;
  if ((int)uVar1 != 0) {
    FUN_fffffff009c16670(&local_30,local_38);
    lVar2 = local_30;
  }
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0xd8));
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return lVar2;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

