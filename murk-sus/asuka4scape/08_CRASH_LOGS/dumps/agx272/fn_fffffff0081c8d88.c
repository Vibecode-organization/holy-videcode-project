// FUN_fffffff0081c8d88 @ fffffff0081c8d88 size=488

long * FUN_fffffff0081c8d88(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  long *plVar5;
  undefined4 uVar6;
  ulong uVar7;
  
  uVar7 = 0;
  uVar6 = 0;
  uVar4 = 0;
  iVar2 = 0;
  lVar3 = *(long *)(param_1 + 0x918);
  do {
    uVar1 = *(uint *)(lVar3 + 0x5c4);
    if ((uVar1 & 1) == 0) {
      iVar2 = *(int *)(lVar3 + 0x558);
      uVar7 = (ulong)*(uint *)(*(long *)(param_1 + 0x2c0) + 4) / 0x18;
      uVar6 = *(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0xb9c);
      DataMemoryBarrier(2,3);
      lVar3 = *(long *)(param_1 + 0x918);
      uVar4 = *(uint *)(lVar3 + 0x5c4);
    }
  } while (uVar1 != uVar4);
  if ((uVar1 == *(uint *)(lVar3 + 0x55c)) && (*(int *)(*(long *)(param_1 + 0x2c0) + 0x38) == 0)) {
    (**(code **)(**(long **)(param_1 + 0x1bc0) + 0x108))
              (*(long **)(param_1 + 0x1bc0),DAT_fffffff00ae22508);
  }
  else {
    *(uint *)(lVar3 + 0x55c) = uVar1;
    (**(code **)(**(long **)(param_1 + 0x1bc8) + 0xc0))(*(long **)(param_1 + 0x1bc8),(long)iVar2);
    (**(code **)(**(long **)(param_1 + 0x1bc0) + 0xf0))
              (*(long **)(param_1 + 0x1bc0),DAT_fffffff00ae22508,*(undefined8 *)(param_1 + 0x1bc8));
  }
  (**(code **)(**(long **)(param_1 + 0x1bd0) + 0xc0))
            (*(long **)(param_1 + 0x1bd0),*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x548));
  (**(code **)(**(long **)(param_1 + 0x1bd8) + 0xc0))
            (*(long **)(param_1 + 0x1bd8),*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x550));
  (**(code **)(**(long **)(param_1 + 0x1be0) + 0xc0))(*(long **)(param_1 + 0x1be0),uVar7);
  (**(code **)(**(long **)(param_1 + 0x1be8) + 0xc0))(*(long **)(param_1 + 0x1be8),uVar6);
  plVar5 = *(long **)(param_1 + 0x1bc0);
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x20))(plVar5);
  }
  return plVar5;
}

