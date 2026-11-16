// FUN_fffffff0081de2b0 @ fffffff0081de2b0 size=176

void FUN_fffffff0081de2b0(long param_1)

{
  ulong uVar1;
  undefined4 *puVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  undefined8 *puVar9;
  
  uVar3 = *(uint *)(param_1 + 0x19440);
  uVar4 = (ulong)uVar3;
  if (uVar3 != 0) {
    uVar1 = *(long *)(param_1 + 0x111a8) + 0x20;
    if (uVar3 < 8) {
      uVar6 = 0;
    }
    else {
      lVar5 = 0;
      uVar6 = uVar4 & 0xfffffff8;
      uVar7 = uVar6;
      do {
        puVar9 = (undefined8 *)(uVar1 + lVar5 * 4);
        if (((uVar1 ^ (ulong)puVar9) & 0xffc0000000000000) != 0) {
          puVar9 = (undefined8 *)((ulong)puVar9 & 0xffffffffffff | 0xc8a2000000000000);
        }
        puVar9[1] = 0x3f828f5c3f828f5c;
        *puVar9 = 0x3f828f5c3f828f5c;
        puVar9[3] = 0x3f828f5c3f828f5c;
        puVar9[2] = 0x3f828f5c3f828f5c;
        lVar5 = lVar5 + 8;
        uVar7 = uVar7 - 8;
      } while (uVar7 != 0);
      if (uVar6 == uVar4) {
        return;
      }
    }
    lVar5 = uVar4 - uVar6;
    do {
      lVar8 = uVar6 * 4;
      puVar2 = (undefined4 *)(uVar1 + (long)(int)lVar8);
      if (lVar8 - (int)lVar8 != 0) {
        puVar2 = (undefined4 *)(uVar1 + lVar8 & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar2 = 0x3f828f5c;
      uVar6 = uVar6 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  return;
}

