// FUN_fffffff0081cab84 @ fffffff0081cab84 size=260

void FUN_fffffff0081cab84(long param_1,uint *param_2,ulong param_3)

{
  ulong *puVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  
  if ((*(int *)(param_1 + 0x30) == 0) || (1 < *(uint *)(*(long *)(param_1 + 0x20) + 0x888))) {
    uVar8 = 0x200000000000000;
    if (*(int *)(param_1 + 0x34) != 0) {
      uVar8 = 0x400000000000000;
    }
  }
  else {
    uVar8 = 0x600000000000000;
  }
  lVar3 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x28),&DAT_fffffff00ae23d28);
  if (lVar3 != 0) {
    if (*(uint *)(param_1 + 0x38) < 0xb) {
      uVar4 = (ulong)(byte)(&DAT_fffffff007115cd8)[*(uint *)(param_1 + 0x38)] << 0x3b;
    }
    else {
      uVar4 = 0;
    }
    if (7 < param_3) {
      lVar5 = *(long *)(lVar3 + 0x230);
      uVar2 = *(uint *)(lVar5 + 0x68);
      if ((ulong)(uVar2 + 1) * 8 + 8 <= param_3) {
        lVar7 = (ulong)uVar2 * 8;
        iVar6 = (int)lVar7;
        puVar1 = (ulong *)((long)param_2 + (long)iVar6 + 8);
        if (lVar7 - iVar6 != 0) {
          puVar1 = (ulong *)((ulong)(param_2 + (ulong)uVar2 * 2 + 2) & 0xffffffffffff |
                            0x2bad000000000000);
        }
        *puVar1 = uVar8 | uVar4 | *(ulong *)(lVar3 + 0x228) & 0x1ffffffffffffff;
        *param_2 = uVar2 + 1;
        *(int *)(lVar5 + 0x68) = *(int *)(lVar5 + 0x68) + 1;
      }
    }
  }
  return;
}

