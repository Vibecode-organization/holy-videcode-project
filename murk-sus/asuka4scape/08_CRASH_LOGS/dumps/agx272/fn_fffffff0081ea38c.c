// FUN_fffffff0081ea38c @ fffffff0081ea38c size=4

undefined8 FUN_fffffff0081ea38c(long param_1,uint *param_2)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  int *piVar8;
  int *piVar9;
  undefined8 uVar10;
  ulong uVar11;
  long *plVar12;
  uint uVar13;
  long lVar14;
  long lVar15;
  ulong uVar16;
  int iVar17;
  long lVar18;
  ulong uVar19;
  long lVar20;
  
  lVar20 = *(long *)(*(long *)(param_1 + 0x20) + 0x20);
  uVar10 = 0;
  if (*(long *)(lVar20 + 0x28) != 0) {
    lVar7 = thunk_EXT_FUN_8011000003890f30(*(long *)(lVar20 + 0x28),&DAT_fffffff00ae21bd0);
    uVar10 = 0;
    if (lVar7 != 0) {
      lVar7 = thunk_EXT_FUN_801100000297dd00();
      uVar10 = 0;
      if (lVar7 != 0) {
        plVar12 = *(long **)(lVar20 + 0xa0);
        if (plVar12 == (long *)0x0) {
          plVar12 = (long *)thunk_EXT_FUN_801100000396cb64
                                      (lVar7,*(undefined8 *)PTR_DAT_fffffff007ca61d0,0,
                                       *(uint *)(*(long *)(lVar20 + 0x50) + 0x18b70) | 1,0,0);
          *(long **)(lVar20 + 0xa0) = plVar12;
          if (plVar12 == (long *)0x0) {
            return 0;
          }
        }
        piVar8 = (int *)(**(code **)(*plVar12 + 0x78))(plVar12);
        uVar10 = 0;
        if (piVar8 != (int *)0x0) {
          iVar17 = (int)(*(ulong *)(param_1 + 0x128) >> 0x11) * *(int *)(param_1 + 0x1c8);
          lVar7 = *(long *)(param_1 + 0x20);
          lVar20 = *(long *)(lVar7 + 0x48);
          *(int *)(lVar20 + 0x2c) = iVar17;
          *(int *)(lVar20 + 0x4c) = iVar17 + -1;
          *(undefined4 *)(lVar7 + 0x34) = 0;
          *(undefined8 *)(lVar7 + 0x38) = 0;
          *(undefined4 *)(lVar7 + 0x40) = 0;
          uVar16 = *(ulong *)(param_1 + 0x60);
          lVar7 = *(long *)(param_1 + 0x88);
          uVar2 = *(uint *)(lVar7 + 8);
          if ((*(uint *)(param_1 + 0x138) <= uVar2) ||
             (uVar3 = *param_2, *(uint *)(param_1 + 0x138) <= uVar3)) {
            uVar10 = thunk_EXT_FUN_8011000003a49114
                               (
                               "AGXk: %s:%d:%s: !!! Assertion failed: %s: OOB access in GPU Driver Resource\n"
                               );
            return uVar10;
          }
          uVar13 = uVar2;
          if (((uVar2 != uVar3) && (uVar13 = uVar3, uVar16 < 0x20001)) &&
             ((int)(uVar16 >> 0xf) != 0)) {
            lVar14 = *(long *)(param_1 + 400);
            lVar15 = *(long *)(param_1 + 0x80);
            uVar6 = 0;
            if (uVar16 != 0) {
              uVar6 = 0x20000 / uVar16;
            }
            do {
              uVar19 = 0;
              lVar18 = (ulong)uVar2 * 8;
              plVar12 = (long *)(lVar14 + (int)lVar18);
              if (lVar18 != (int)lVar18) {
                plVar12 = (long *)(lVar14 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
              }
              lVar18 = (ulong)*(uint *)(*plVar12 + 0xc) * 8;
              uVar1 = lVar15 + (int)lVar18;
              if (lVar18 - (int)lVar18 != 0) {
                uVar1 = lVar15 + lVar18 & 0xffffffffffffU | 0x2bad000000000000;
              }
              do {
                lVar18 = uVar19 * 4;
                piVar9 = (int *)(uVar1 + (long)(int)lVar18);
                if (lVar18 - (int)lVar18 != 0) {
                  piVar9 = (int *)(uVar1 + lVar18 & 0xffffffffffff | 0x2bad000000000000);
                }
                iVar17 = *piVar9;
                piVar9 = piVar8;
                uVar11 = uVar16 >> 0xf;
                do {
                  piVar8 = piVar9 + 1;
                  *piVar9 = iVar17;
                  iVar17 = iVar17 + 1;
                  uVar13 = (int)uVar11 - 1;
                  uVar11 = (ulong)uVar13;
                  piVar9 = piVar8;
                } while (uVar13 != 0);
                uVar19 = uVar19 + 1;
              } while (uVar19 < uVar6);
              uVar13 = *(uint *)(param_1 + 0x138);
              uVar5 = 0;
              if (uVar13 != 0) {
                uVar5 = (uVar2 + 1) / uVar13;
              }
              uVar2 = (uVar2 + 1) - uVar5 * uVar13;
            } while (uVar2 != uVar3);
            uVar13 = *param_2;
          }
          uVar4 = *(undefined4 *)(lVar7 + 8);
          *(uint *)(lVar20 + 0x34) = uVar13;
          *(undefined4 *)(lVar20 + 0x38) = uVar4;
          uVar10 = 1;
        }
      }
    }
  }
  return uVar10;
}

