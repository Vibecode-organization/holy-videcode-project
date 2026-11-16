// FUN_fffffff0081e6f90 @ fffffff0081e6f90 size=564

void FUN_fffffff0081e6f90(long *param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined8 *puVar4;
  code *pcVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  int iVar15;
  long lVar16;
  uint uVar17;
  bool bVar18;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(param_1[7]);
  uVar6 = (**(code **)(*param_1 + 0x50))(param_1);
  uVar8 = uVar6 - *(uint *)(param_1 + 6);
  if ((*(uint *)(param_1 + 6) <= uVar6 && uVar8 != 0) && (uVar12 = param_1[0x10], uVar12 != 0)) {
    uVar6 = *(uint *)(param_1 + 9);
    uVar13 = uVar12;
    if ((uVar6 <= uVar8) && (uVar17 = (int)uVar12 - 1, uVar14 = (ulong)uVar17, -1 < (int)uVar17)) {
      bVar18 = true;
      uVar17 = 0;
      if (uVar6 != 0) {
        uVar17 = uVar8 / uVar6;
      }
      do {
        if ((*(byte *)(param_1 + 5) & 1) == 0) {
          uVar8 = (uint)(*(int *)((long)param_1 + 0x2c) == 1);
        }
        else {
          uVar8 = 0;
        }
        lVar16 = uVar14 * 8;
        iVar15 = (int)lVar16;
        puVar4 = (undefined8 *)(param_1[0xf] + (long)iVar15);
        if (lVar16 - iVar15 != 0) {
          puVar4 = (undefined8 *)(param_1[0xf] + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
        }
        puVar7 = (uint *)*puVar4;
        uVar6 = (uint)uVar14;
        if (puVar7 == (uint *)0x0) {
LAB_fffffff0081e7078:
          if (!bVar18) {
            uVar6 = (uint)uVar12;
          }
          uVar13 = (ulong)uVar6;
        }
        else {
          if (*puVar7 == uVar8) {
            *puVar7 = 0;
            uVar8 = *(uint *)(param_1 + 9);
            if (uVar8 != 0) {
              uVar9 = 0;
              lVar10 = param_1[0x13];
              do {
                uVar2 = uVar9 + uVar8 * uVar6;
                uVar13 = (ulong)(uVar2 >> 6);
                uVar3 = uVar8 - uVar9;
                if (0x3f < (uVar2 & 0x3f) + (uVar8 - uVar9)) {
                  uVar3 = 0x40 - (uVar2 & 0x3f);
                }
                uVar11 = 0xffffffffffffffff;
                if (uVar3 < 0x40) {
                  uVar11 = ~(-1L << ((ulong)uVar3 & 0x3f));
                }
                uVar11 = *(ulong *)(lVar10 + uVar13 * 8) &
                         (uVar11 << ((ulong)uVar2 & 0x3f) ^ 0xffffffffffffffff);
                *(ulong *)(lVar10 + uVar13 * 8) = uVar11;
                if (uVar11 == 0) {
                  uVar11 = (ulong)(uVar2 >> 9) & 0x7ffff8;
                  *(ulong *)((long)param_1 + uVar11 + 0x90) =
                       *(ulong *)((long)param_1 + uVar11 + 0x90) &
                       (1L << (uVar13 & 0x3f) ^ 0xffffffffffffffffU);
                }
                uVar9 = uVar3 + uVar9;
              } while (uVar9 < uVar8);
            }
            (**(code **)(*param_1 + 8))(param_1);
            puVar4 = (undefined8 *)(param_1[0xf] + (long)iVar15);
            if (lVar16 != iVar15) {
              puVar4 = (undefined8 *)(param_1[0xf] + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar4 = 0;
            *(int *)(param_1 + 0x14) = (int)param_1[0x14] + -1;
            uVar17 = uVar17 - 1;
            goto LAB_fffffff0081e7078;
          }
          bVar18 = false;
          uVar13 = uVar12;
        }
      } while ((uVar17 != 0) &&
              (bVar1 = 0 < (long)uVar14, uVar12 = uVar13, uVar14 = uVar14 - 1, bVar1));
      uVar12 = param_1[0x10];
    }
    if ((uVar13 & 0xffffffff) <= uVar12 - 1) {
      FUN_fffffff0081e71c4(param_1,uVar13);
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e71c0);
    (*pcVar5)();
  }
  thunk_EXT_FUN_8011000003222de0(param_1[7]);
  return;
}

