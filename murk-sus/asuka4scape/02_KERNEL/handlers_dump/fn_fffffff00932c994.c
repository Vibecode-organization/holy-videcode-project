// FUN_fffffff00932c994 @ fffffff00932c994 size=4 depth=0
// CALLERS:
//   fffffff00afde56e ?
//   fffffff007f19dd8 ?
// CALLS:

ulong FUN_fffffff00932c994(long *param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uStack_28;
  
  uVar3 = 0xe00002c2;
  plVar2 = thunk_FUN_fffffff00a894f30(param_1,(long)PTR_DAT_fffffff007f190d8);
  if ((plVar2 != (long *)0x0) && (uStack_28 = 0, *(long *)(param_3 + 0x78) != 0)) {
    uVar1 = FUN_fffffff00932be9c(plVar2,&uStack_28);
    uVar3 = (ulong)uVar1;
    **(undefined8 **)(param_3 + 0x78) = uStack_28;
  }
  return uVar3;
}

