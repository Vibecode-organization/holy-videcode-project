// FUN_fffffff00816e908 @ fffffff00816e908 size=224

void FUN_fffffff00816e908(long param_1,uint *param_2,ulong param_3)

{
  ulong *puVar1;
  ulong uVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  int iVar7;
  long lVar8;
  
  lVar4 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x20),&DAT_fffffff00ae23d28);
  if (lVar4 != 0) {
    if (*(uint *)(param_1 + 0x30) < 0xb) {
      uVar5 = (ulong)(byte)(&DAT_fffffff007115cd8)[*(uint *)(param_1 + 0x30)] << 0x3b;
    }
    else {
      uVar5 = 0;
    }
    if (7 < param_3) {
      lVar6 = *(long *)(lVar4 + 0x230);
      uVar3 = *(uint *)(lVar6 + 0x68);
      if ((ulong)(uVar3 + 1) * 8 + 8 <= param_3) {
        lVar8 = (ulong)uVar3 * 8;
        iVar7 = (int)lVar8;
        puVar1 = (ulong *)((long)param_2 + (long)iVar7 + 8);
        if (lVar8 - iVar7 != 0) {
          puVar1 = (ulong *)((ulong)(param_2 + (ulong)uVar3 * 2 + 2) & 0xffffffffffff |
                            0x2bad000000000000);
        }
        uVar2 = 0x600000000000000;
        if (*(long *)(param_1 + 0x28) != *(long *)(param_1 + 0x20)) {
          uVar2 = 0x200000000000000;
        }
        *puVar1 = uVar2 | *(ulong *)(lVar4 + 0x228) & 0x1ffffffffffffff | uVar5;
        *param_2 = uVar3 + 1;
        *(int *)(lVar6 + 0x68) = *(int *)(lVar6 + 0x68) + 1;
      }
    }
  }
  return;
}

