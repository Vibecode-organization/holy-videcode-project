// FUN_fffffff00997fe30 @ fffffff00997fe30 size=124

void FUN_fffffff00997fe30(long param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x40);
  iVar1 = *(int *)(param_1 + 0x44) - uVar2;
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    iVar1 = FUN_fffffff00994ba48
                      (*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148),
                       param_1 + 0x88 + (ulong)(uVar2 & 7) * 0x40);
    if (iVar1 == 0) break;
    *(undefined8 *)(param_1 + 0x28) =
         *(undefined8 *)(param_1 + 0x48 + ((ulong)*(uint *)(param_1 + 0x40) & 7) * 8);
    uVar2 = *(uint *)(param_1 + 0x40) + 1;
    *(uint *)(param_1 + 0x40) = uVar2;
    iVar1 = *(int *)(param_1 + 0x44) - uVar2;
    if (iVar1 < 0) {
      FUN_fffffff0099841cc();
      return;
    }
  }
  return;
}

