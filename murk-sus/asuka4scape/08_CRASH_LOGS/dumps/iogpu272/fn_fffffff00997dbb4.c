// FUN_fffffff00997dbb4 @ fffffff00997dbb4 size=440

void FUN_fffffff00997dbb4(long *param_1)

{
  bool bVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  
  uVar7 = (ulong)*(uint *)((long)param_1 + 0x14);
  if (*(uint *)((long)param_1 + 0x14) != 0) {
    lVar8 = 0;
    uVar9 = param_1[1];
    do {
      lVar10 = *(long *)(uVar9 + lVar8 * 0x10);
      if (lVar10 != 0) {
        uVar11 = uVar9 + lVar8 * 0x10;
        if (((uVar9 ^ uVar11) & 0xffc0000000000000) != 0) {
          uVar11 = uVar11 & 0xffffffffffff | 0xc8a2000000000000;
        }
        *(undefined8 *)(uVar11 + 8) = *(undefined8 *)(lVar10 + 0x18);
      }
      lVar8 = lVar8 + 1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  lVar8 = *(long *)(*(long *)(*param_1 + 0x160) + 0x178);
  iVar4 = *(int *)((long)param_1 + 0x14);
  uVar7 = 0xb;
  do {
    lVar10 = (long)*(int *)(&UNK_fffffff007835d20 + (uVar7 - 1) * 4);
    if (*(int *)(&UNK_fffffff007835d20 + (uVar7 - 1) * 4) < iVar4) {
      lVar13 = param_1[1];
      lVar12 = lVar10;
      lVar16 = lVar13;
      do {
        lVar14 = lVar12 * 0x10;
        puVar2 = (undefined8 *)(lVar13 + (int)lVar14);
        if (lVar14 - (int)lVar14 != 0) {
          puVar2 = (undefined8 *)(lVar13 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar9 = puVar2[1];
        lVar14 = (lVar12 - lVar10) * 0x10;
        puVar6 = (undefined8 *)(lVar13 + (int)lVar14);
        if (lVar14 - (int)lVar14 != 0) {
          puVar6 = (undefined8 *)(lVar13 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar11 = puVar6[1];
        if (uVar9 < uVar11) {
          uVar5 = *puVar2;
          lVar14 = lVar12;
          lVar15 = lVar16;
          do {
            lVar17 = lVar15;
            lVar15 = lVar14 * 0x10;
            puVar2 = (undefined8 *)(lVar13 + (int)lVar15);
            if (lVar15 - (int)lVar15 != 0) {
              puVar2 = (undefined8 *)(lVar13 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar2 = *puVar6;
            puVar2[1] = uVar11;
            lVar14 = lVar14 - lVar10;
            if (lVar14 < lVar10) break;
            lVar15 = (lVar14 - lVar10) * 0x10;
            puVar6 = (undefined8 *)(lVar13 + (int)lVar15);
            if (lVar15 - (int)lVar15 != 0) {
              puVar6 = (undefined8 *)(lVar13 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
            }
            uVar11 = puVar6[1];
            lVar15 = lVar17 + lVar10 * -0x10;
          } while (uVar9 < uVar11);
          lVar14 = lVar14 * 0x10;
          puVar2 = (undefined8 *)(lVar13 + (int)lVar14);
          if (lVar14 - (int)lVar14 != 0) {
            puVar2 = (undefined8 *)(lVar13 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *puVar2 = uVar5;
          *(ulong *)(lVar17 + 8) = uVar9;
        }
        lVar12 = lVar12 + 1;
        lVar16 = lVar16 + 0x10;
      } while (lVar12 != iVar4);
    }
    bVar1 = uVar7 < 2;
    uVar7 = uVar7 - 1;
    if (bVar1) {
      uVar3 = *(uint *)(param_1 + 3);
      if (uVar3 != 0) {
        uVar7 = 0;
        lVar10 = param_1[1];
        do {
          lVar12 = *(long *)(lVar10 + uVar7 * 0x10);
          if (lVar12 != 0) {
            *(int *)(lVar12 + 0x20) = (int)uVar7;
          }
          uVar7 = uVar7 + 1;
        } while (uVar3 != uVar7);
      }
      *(uint *)((long)param_1 + 0x14) = uVar3;
      param_1[4] = lVar8;
      *(int *)((long)param_1 + 0x1c) = *(int *)((long)param_1 + 0x1c) + 1;
      return;
    }
  } while( true );
}

