// FUN_fffffff0081f7f18 @ fffffff0081f7f18 size=388

undefined8 FUN_fffffff0081f7f18(long param_1,long *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  long *plVar5;
  
  if (*(long **)(param_1 + 0x60) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x60) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x60) = 0;
  uVar3 = (**(code **)(PTR_DAT_fffffff007ca6148 + 0x78))(param_1);
  if ((int)uVar3 != 0) {
    plVar5 = *(long **)(param_1 + 0x60);
    *(long **)(param_1 + 0x60) = param_2;
    if (param_2 != (long *)0x0) {
      (**(code **)(*param_2 + 0x20))(param_2);
    }
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
    *(undefined4 *)(param_1 + 0x70) = param_3;
    *(undefined4 *)(param_1 + 0x20) = param_4;
    *(undefined8 *)(param_1 + 0x50) = 0;
    if (*(long **)(param_1 + 0x18) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x58) = 0;
    uVar3 = 0;
    if (*(long **)(param_1 + 0x60) != (long *)0x0) {
      lVar4 = (**(code **)(**(long **)(param_1 + 0x60) + 0xb0))();
      *(long *)(param_1 + 0x68) = lVar4;
      *(ulong *)(param_1 + 0x50) = lVar4 * (ulong)*(uint *)(param_1 + 0x70);
      uVar1 = (**(code **)(**(long **)(param_1 + 0x60) + 0xc0))();
      *(undefined4 *)(param_1 + 0x58) = uVar1;
      uVar2 = thunk_EXT_FUN_801100000397744c(*(undefined8 *)(param_1 + 0x60));
      *(uint *)(param_1 + 0x20) = uVar2 & 0x400 | *(uint *)(param_1 + 0x20);
      uVar3 = 1;
    }
  }
  return uVar3;
}

