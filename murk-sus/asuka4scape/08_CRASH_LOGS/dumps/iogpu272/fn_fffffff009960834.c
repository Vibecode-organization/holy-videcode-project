// FUN_fffffff009960834 @ fffffff009960834 size=328

void FUN_fffffff009960834(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  undefined8 local_28;
  
  lVar3 = *(long *)(param_1 + 0x1a8);
  if (DAT_fffffff00af227bc != 0) {
    lVar4 = thunk_EXT_FUN_8011000002c339b0(*(undefined8 *)(lVar3 + 0xf8));
    lVar3 = *(long *)(param_1 + 0x1a8);
    uVar5 = *(ulong *)(lVar3 + 0x2c8);
    uVar2 = lVar4 * 3;
    if (uVar5 / 6 <= (ulong)(lVar4 * 3)) {
      uVar2 = uVar5 / 6;
    }
    uVar1 = lVar4 * 6;
    if (uVar5 >> 4 <= (ulong)(lVar4 * 6)) {
      uVar1 = uVar5 >> 4;
    }
    if (uVar2 <= uVar1) {
      uVar2 = uVar1;
    }
    if (uVar2 < 0x2000001) {
      uVar2 = 0x2000000;
    }
    *(ulong *)(param_1 + 0xa8) = uVar2;
  }
  lVar3 = FUN_fffffff009974f6c(lVar3,0);
  lVar4 = FUN_fffffff009974f6c(*(undefined8 *)(param_1 + 0x1a8),1);
  uVar2 = *(ulong *)(param_1 + 0xa8);
  if (DAT_fffffff00af227b8 != 0) {
    uVar2 = (ulong)DAT_fffffff00af227b8 << 0x14;
  }
  if (((uVar2 < (ulong)(lVar4 + lVar3)) &&
      ((*(uint *)(*(long *)(param_1 + 0x1a8) + 0x1fc) & 0x40) == 0 && DAT_fffffff00af227cc == 0)) &&
     (*(int *)(param_1 + 0x94) == 0)) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xc0));
    if (*(int *)(param_1 + 0x88) == 0) {
      local_28 = 0;
      *(undefined4 *)(param_1 + 0x88) = 1;
      thunk_EXT_FUN_8011000003204ed8(*(undefined4 *)(param_1 + 0x90),1000000,&local_28);
      thunk_EXT_FUN_8011000003277924(*(undefined8 *)(param_1 + 0xb8),local_28);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xc0));
  }
  return;
}

