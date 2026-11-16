// FUN_fffffff0081ed670 @ fffffff0081ed670 size=316

void FUN_fffffff0081ed670(long param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  
  if (*(long **)(param_2 + 0x18) != (long *)0x0) {
    (**(code **)(**(long **)(param_2 + 0x18) + 0x28))();
  }
  *(undefined8 *)(param_2 + 0x18) = 0;
  uVar1 = *(uint *)(param_1 + 0x238);
  uVar2 = *(ulong *)(param_1 + 0x230);
  if (1 < uVar1) {
    if (uVar1 < 5) {
      uVar3 = 1;
    }
    else {
      lVar4 = 0;
      uVar5 = (ulong)uVar1 - 1;
      uVar3 = uVar5 & 0xfffffffffffffffc;
      uVar7 = uVar3;
      do {
        puVar9 = (undefined8 *)(uVar2 + (lVar4 << 3 | 8U));
        if (((uVar2 ^ (ulong)puVar9) & 0xffc0000000000000) != 0) {
          puVar9 = (undefined8 *)((ulong)puVar9 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar10 = *puVar9;
        uVar12 = puVar9[3];
        uVar11 = puVar9[2];
        puVar8 = (undefined8 *)(uVar2 + lVar4 * 8);
        if (((uVar2 ^ (ulong)puVar8) & 0xffc0000000000000) != 0) {
          puVar8 = (undefined8 *)((ulong)puVar8 & 0xffffffffffff | 0xc8a2000000000000);
        }
        puVar8[1] = puVar9[1];
        *puVar8 = uVar10;
        puVar8[3] = uVar12;
        puVar8[2] = uVar11;
        lVar4 = lVar4 + 4;
        uVar7 = uVar7 - 4;
      } while (uVar7 != 0);
      if (uVar5 == uVar3) goto LAB_fffffff0081ed77c;
      uVar3 = uVar3 | 1;
    }
    lVar4 = uVar1 - uVar3;
    do {
      lVar6 = uVar3 * 8;
      puVar9 = (undefined8 *)(uVar2 + (long)(int)lVar6);
      if (lVar6 - (int)lVar6 != 0) {
        puVar9 = (undefined8 *)(uVar2 + lVar6 & 0xffffffffffff | 0x2bad000000000000);
      }
      lVar6 = lVar6 + -8;
      puVar8 = (undefined8 *)(uVar2 + (long)(int)lVar6);
      if (lVar6 != (int)lVar6) {
        puVar8 = (undefined8 *)(uVar2 + lVar6 & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar8 = *puVar9;
      uVar3 = uVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
  }
LAB_fffffff0081ed77c:
  *(uint *)(param_1 + 0x238) = uVar1 - 1;
  lVar4 = (ulong)(uVar1 - 1) * 8;
  puVar9 = (undefined8 *)(uVar2 + (long)(int)lVar4);
  if (lVar4 != (int)lVar4) {
    puVar9 = (undefined8 *)(uVar2 + lVar4 & 0xffffffffffff | 0x2bad000000000000);
  }
  *puVar9 = 0;
  return;
}

