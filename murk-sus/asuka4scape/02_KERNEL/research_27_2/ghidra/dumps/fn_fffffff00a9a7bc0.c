// FUN_fffffff00a9a7bc0 @ fffffff00a9a7bc0 size=136
// CALLERS:
//   fffffff00afbf5e4 no-fn
//   fffffff007ff8c68 no-fn
//   fffffff00806c678 no-fn
//   fffffff0099a04f8 thunk_FUN_fffffff00a9a7bc0@fffffff0099a04ec
//   fffffff009c49830 thunk_FUN_fffffff00a9a7bc0@fffffff009c49824
// CALLEES:
//   fffffff00a34be34 FUN_fffffff00a34be34

undefined4 FUN_fffffff00a9a7bc0(long param_1,uint param_2,long *param_3)

{
  undefined4 uVar1;
  long *plVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x310);
  if (lVar3 == 0) {
    lVar3 = 0;
  }
  plVar2 = FUN_fffffff00a34be34(param_2,0x26,lVar3);
  if ((long *)*param_3 != (long *)0x0) {
    (**(code **)(*(long *)*param_3 + 0x28))();
  }
  uVar1 = 0xe00002bf;
  if (plVar2 != (long *)0x0) {
    uVar1 = 0;
  }
  *param_3 = (long)plVar2;
  return uVar1;
}

