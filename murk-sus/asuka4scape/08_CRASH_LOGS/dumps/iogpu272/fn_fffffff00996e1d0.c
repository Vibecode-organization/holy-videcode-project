// FUN_fffffff00996e1d0 @ fffffff00996e1d0 size=156

void FUN_fffffff00996e1d0(long param_1)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  
  *(undefined8 *)(param_1 + 0x138) = 0;
  if (((*(byte *)(param_1 + 0x4d) & 1) != 0) &&
     (uVar3 = (ulong)*(uint *)(param_1 + 0x30), 0 < (int)*(uint *)(param_1 + 0x30))) {
    lVar4 = 0;
    lVar5 = *(long *)(param_1 + 0x28);
    do {
      FUN_fffffff0099437a0(*(undefined8 *)(lVar5 + lVar4 * 8));
      iVar1 = FUN_fffffff009942bf8(*(undefined8 *)(lVar5 + lVar4 * 8));
      if (iVar1 == 0) {
        lVar2 = (**(code **)(**(long **)(lVar5 + lVar4 * 8) + 0x88))();
        *(long *)(param_1 + 0x138) = *(long *)(param_1 + 0x138) + lVar2;
      }
      lVar4 = lVar4 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  *(undefined1 *)(param_1 + 0x4d) = 0;
  return;
}

