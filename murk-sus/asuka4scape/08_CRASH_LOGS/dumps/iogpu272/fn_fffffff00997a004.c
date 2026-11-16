// FUN_fffffff00997a004 @ fffffff00997a004 size=128

void FUN_fffffff00997a004(long param_1)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_1 + 0x430);
  uVar2 = (ulong)*(uint *)(lVar1 + 0x148);
  if (*(uint *)(lVar1 + 0x148) != 0) {
    lVar3 = 0;
    do {
      (**(code **)(**(long **)(lVar1 + 8 + lVar3 * 8) + 0x28))();
      lVar1 = *(long *)(param_1 + 0x430);
      *(undefined8 *)(lVar1 + 8 + lVar3 * 8) = 0;
      lVar3 = lVar3 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  *(undefined4 *)(lVar1 + 0x148) = 0;
  *(undefined1 *)(lVar1 + 0x2a0) = 0;
  return;
}

