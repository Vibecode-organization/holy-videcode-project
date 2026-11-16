// FUN_fffffff0081e334c @ fffffff0081e334c size=868

long * FUN_fffffff0081e334c(long param_1)

{
  ulong uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  long lVar4;
  uint uVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  int iVar8;
  undefined4 uVar9;
  long *plVar10;
  long lVar11;
  long *plVar12;
  long lVar13;
  ulong uVar14;
  long lVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  
  plVar10 = (long *)(**(code **)(DAT_fffffff00ae23160 + 0x68))();
  if (plVar10 == (long *)0x0) {
    return (long *)0x0;
  }
  iVar8 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))(plVar10);
  if (iVar8 != 0) {
    plVar10[3] = param_1;
    uVar16 = *(undefined8 *)(param_1 + 0xf8);
    *(undefined1 *)((long)plVar10 + 0xc) = 0;
    uVar1 = plVar10[6] + 4;
    if (uVar1 == 0) {
      lVar11 = 0;
      lVar13 = plVar10[7];
    }
    else {
      auVar6._8_8_ = 0;
      auVar6._0_8_ = uVar1;
      lVar11 = -0x8000000000000000;
      if (SUB168(auVar6 * ZEXT816(0x18),8) == 0 && -1 < (long)(uVar1 * 0x18)) {
        lVar11 = uVar1 * 0x18;
      }
      lVar11 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4378,lVar11);
      if (lVar11 == 0) goto LAB_fffffff0081e35ec;
      lVar13 = plVar10[7];
    }
    if (lVar13 != 0) {
      uVar14 = 0;
      do {
        lVar13 = uVar14 * 0x18;
        iVar8 = (int)lVar13;
        puVar2 = (undefined8 *)(plVar10[5] + (long)iVar8);
        if (lVar13 - iVar8 != 0) {
          puVar2 = (undefined8 *)(plVar10[5] + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
        }
        puVar3 = (undefined8 *)(lVar11 + iVar8);
        if (lVar13 - iVar8 != 0) {
          puVar3 = (undefined8 *)(lVar11 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar18 = puVar2[1];
        uVar17 = *puVar2;
        puVar3[2] = puVar2[2];
        puVar3[1] = uVar18;
        *puVar3 = uVar17;
        uVar14 = uVar14 + 1;
      } while (uVar14 < (ulong)plVar10[7]);
    }
    lVar4 = plVar10[5];
    auVar7._8_8_ = 0;
    auVar7._0_8_ = plVar10[6];
    lVar15 = plVar10[6] * 0x18;
    lVar13 = -0x8000000000000000;
    if (SUB168(auVar7 * ZEXT816(0x18),8) == 0 && -1 < lVar15) {
      lVar13 = lVar15;
    }
    plVar10[5] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca43c8,lVar4,lVar13);
    plVar10[5] = lVar11;
    plVar10[6] = uVar1;
    uVar9 = thunk_EXT_FUN_8011000002c3280c(uVar16);
    *(undefined4 *)(plVar10 + 9) = uVar9;
    *(undefined4 *)(plVar10 + 4) = 0;
    iVar8 = FUN_fffffff0081e36b0(plVar10,0);
    if (iVar8 != 0) {
      lVar11 = plVar10[3];
      uVar5 = *(uint *)(plVar10 + 4);
      plVar12 = (long *)(**(code **)(DAT_fffffff00ae23138 + 0x68))();
      if (plVar12 != (long *)0x0) {
        (**(code **)(PTR_DAT_fffffff007ca60e0 + 0x78))();
        plVar12[6] = lVar11;
        lVar11 = thunk_EXT_FUN_80110000038ff010();
        plVar12[5] = lVar11;
        if (lVar11 != 0) {
          *(undefined4 *)(plVar12 + 3) = 0;
          *(uint *)((long)plVar12 + 0x1c) = uVar5;
          *(uint *)(plVar12 + 4) = uVar5;
          *(uint *)((long)plVar12 + 0x24) = uVar5;
          lVar11 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca41e8,(ulong)uVar5 << 3);
          plVar12[2] = lVar11;
          if (lVar11 != 0) {
            plVar10[2] = (long)plVar12;
            lVar11 = thunk_EXT_FUN_80110000038ff010();
            plVar10[8] = lVar11;
            if (lVar11 != 0) {
              lVar11 = thunk_EXT_FUN_80110000038ff010();
              plVar10[0xd] = lVar11;
              if (lVar11 != 0) {
                uVar1 = plVar10[0xb] + 4;
                if (uVar1 == 0) {
                  lVar11 = 0;
                }
                else {
                  lVar11 = -0x8000000000000000;
                  if (-1 < (long)(uVar1 * 0x20) && (uVar1 & 0xf800000000000000) == 0) {
                    lVar11 = uVar1 * 0x20;
                  }
                  lVar11 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4418,lVar11);
                  if (lVar11 == 0) {
                    thunk_EXT_FUN_80110000038ff020(plVar10[0xd]);
                    plVar10[0xd] = 0;
                    goto LAB_fffffff0081e35ec;
                  }
                }
                if (plVar10[0xc] != 0) {
                  uVar14 = 0;
                  do {
                    lVar13 = uVar14 * 0x20;
                    iVar8 = (int)lVar13;
                    puVar2 = (undefined8 *)(plVar10[10] + (long)iVar8);
                    if (lVar13 - iVar8 != 0) {
                      puVar2 = (undefined8 *)
                               (plVar10[10] + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
                    }
                    puVar3 = (undefined8 *)(lVar11 + iVar8);
                    if (lVar13 - iVar8 != 0) {
                      puVar3 = (undefined8 *)
                               (lVar11 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
                    }
                    uVar16 = *puVar2;
                    uVar18 = puVar2[3];
                    uVar17 = puVar2[2];
                    puVar3[1] = puVar2[1];
                    *puVar3 = uVar16;
                    puVar3[3] = uVar18;
                    puVar3[2] = uVar17;
                    uVar14 = uVar14 + 1;
                  } while (uVar14 < (ulong)plVar10[0xc]);
                }
                lVar4 = plVar10[10];
                lVar15 = plVar10[0xb] * 0x20;
                lVar13 = -0x8000000000000000;
                if (-1 < lVar15 && (plVar10[0xb] & 0xf800000000000000U) == 0) {
                  lVar13 = lVar15;
                }
                plVar10[10] = 0;
                thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4468,lVar4,lVar13);
                plVar10[10] = lVar11;
                plVar10[0xb] = uVar1;
                return plVar10;
              }
            }
            goto LAB_fffffff0081e35ec;
          }
          thunk_EXT_FUN_80110000038ff020(plVar12[5]);
          plVar12[5] = 0;
        }
        (**(code **)(*plVar12 + 0x28))(plVar12);
      }
      plVar10[2] = 0;
    }
  }
LAB_fffffff0081e35ec:
  (**(code **)(*plVar10 + 0x28))(plVar10);
  return (long *)0x0;
}

