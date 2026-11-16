// FUN_fffffff00821f67c @ fffffff00821f67c size=4
// CALLERS:
//   fffffff00afc19d9 no-fn
//   fffffff007cb0000 no-fn
// CALLEES:

ulong FUN_fffffff00821f67c(long *param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  long *plVar2;
  ulong uVar3;
  uint uStack_2c;
  long *plStack_28;
  
  uVar3 = 0xe00002c2;
  plStack_28 = (long *)0x0;
  uStack_2c = 0;
  if (((param_3 != 0) && (*(long *)(param_3 + 0x58) != 0)) && (*(int *)(param_3 + 0x50) == 3)) {
    plVar2 = thunk_FUN_fffffff00a894f30(param_1,-0xff51d6e70);
    if (plVar2 == (long *)0x0) {
      uVar3 = 0xe00002bc;
    }
    else {
      uVar3 = (**(code **)(*plVar2 + 0x5f8))(plVar2,&plStack_28);
      if ((int)uVar3 == 0) {
        uVar1 = FUN_fffffff00821f880
                          (plStack_28,plStack_28,*(ulong **)(param_3 + 0x48),
                           *(long *)(param_3 + 0x58),&uStack_2c,*(uint *)(param_3 + 0x60));
        uVar3 = (ulong)uVar1;
      }
      if (plStack_28 != (long *)0x0) {
        (**(code **)(*plStack_28 + 0x28))();
      }
    }
  }
  return uVar3;
}

