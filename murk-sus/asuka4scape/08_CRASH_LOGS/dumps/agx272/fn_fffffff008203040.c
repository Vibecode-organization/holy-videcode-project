// FUN_fffffff008203040 @ fffffff008203040 size=4

void FUN_fffffff008203040(long param_1)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  long *plVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  code *pcVar9;
  int *piVar10;
  long lVar11;
  long lVar12;
  uint uVar13;
  ulong uVar14;
  ulong uVar15;
  long *plVar16;
  ulong uVar17;
  ulong uVar18;
  ulong unaff_x30;
  
  uVar5 = *(uint *)(param_1 + 0x38);
  uVar17 = (ulong)uVar5;
  if (uVar5 != 0xffffffff) {
    plVar16 = *(long **)(*(long *)(param_1 + 0x18) + 0x1e0);
    thunk_EXT_FUN_80110000032222a8(plVar16[7]);
    uVar6 = *(uint *)(plVar16 + 9);
    if (plVar16[0x10] * (ulong)uVar6 < uVar17 || plVar16[0x10] * (ulong)uVar6 - uVar17 == 0) {
      thunk_EXT_FUN_8011000003a49114
                (
                "AGXk: %s:%d:%s: !!! Assertion failed: %s: Attempt to release an out-of-range element (%d)\n"
                );
      return;
    }
    uVar8 = 0;
    if (uVar6 != 0) {
      uVar8 = uVar5 / uVar6;
    }
    uVar18 = (ulong)uVar8;
    lVar11 = uVar18 * 8;
    puVar3 = (undefined8 *)(plVar16[0xf] + (long)(int)lVar11);
    if (lVar11 != (int)lVar11) {
      puVar3 = (undefined8 *)(plVar16[0xf] + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
    }
    piVar10 = (int *)*puVar3;
    if (piVar10 == (int *)0x0) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid allocation\n");
      return;
    }
    if (*piVar10 == 0) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid ref count (%d %d)\n");
      return;
    }
    iVar7 = *piVar10 + -1;
    *piVar10 = iVar7;
    uVar14 = (ulong)(uVar5 >> 6);
    lVar11 = plVar16[0x13];
    uVar17 = 1L << (uVar17 & 0x3f);
    if ((*(ulong *)(lVar11 + uVar14 * 8) & uVar17) != 0) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid element (%d)\n");
      return;
    }
    uVar15 = (ulong)(uVar5 >> 9) & 0x7ffff8;
    *(ulong *)((long)plVar16 + uVar15 + 0x90) =
         *(ulong *)((long)plVar16 + uVar15 + 0x90) | 1L << (uVar14 & 0x3f);
    *(ulong *)(lVar11 + uVar14 * 8) = *(ulong *)(lVar11 + uVar14 * 8) | uVar17;
    if (iVar7 == 0) {
      uVar13 = 0;
      do {
        uVar1 = uVar13 + uVar8 * uVar6;
        uVar17 = (ulong)(uVar1 >> 6);
        uVar2 = uVar6 - uVar13;
        if (0x3f < (uVar1 & 0x3f) + (uVar6 - uVar13)) {
          uVar2 = 0x40 - (uVar1 & 0x3f);
        }
        uVar14 = 0xffffffffffffffff;
        if (uVar2 < 0x40) {
          uVar14 = ~(-1L << ((ulong)uVar2 & 0x3f));
        }
        uVar14 = *(ulong *)(lVar11 + uVar17 * 8) &
                 (uVar14 << ((ulong)uVar1 & 0x3f) ^ 0xffffffffffffffff);
        *(ulong *)(lVar11 + uVar17 * 8) = uVar14;
        if (uVar14 == 0) {
          uVar14 = (ulong)(uVar1 >> 9) & 0x7ffff8;
          *(ulong *)((long)plVar16 + uVar14 + 0x90) =
               *(ulong *)((long)plVar16 + uVar14 + 0x90) &
               (1L << (uVar17 & 0x3f) ^ 0xffffffffffffffffU);
        }
        uVar13 = uVar2 + uVar13;
      } while (uVar13 < uVar6);
      (**(code **)(*plVar16 + 8))(plVar16);
      lVar12 = uVar18 * 8;
      lVar11 = plVar16[0xf];
      uVar17 = plVar16[0x10];
      puVar3 = (undefined8 *)(lVar11 + (int)lVar12);
      if (lVar12 - (int)lVar12 != 0) {
        puVar3 = (undefined8 *)(lVar11 + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = 0;
      *(int *)(plVar16 + 0x14) = (int)plVar16[0x14] + -1;
      if (uVar17 - 1 == uVar18) {
        if (uVar6 <= uVar5) {
          do {
            lVar12 = uVar17 * 8 + -0x10;
            plVar4 = (long *)(lVar11 + (int)lVar12);
            if (lVar12 != (int)lVar12) {
              plVar4 = (long *)(lVar11 + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
            }
            if (*plVar4 != 0) goto LAB_fffffff008203228;
            uVar14 = uVar18 - 1;
            uVar17 = uVar18;
            uVar18 = uVar14;
          } while (uVar14 != 0);
        }
        uVar18 = 0;
LAB_fffffff008203228:
        FUN_fffffff0081e71c4(plVar16,uVar18);
      }
    }
    thunk_EXT_FUN_8011000003222de0(plVar16[7]);
  }
  *(undefined8 *)(param_1 + 0x40) = 0;
  if (*(long **)(param_1 + 0x20) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x20) + 0x28))();
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar9 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0082032a0);
    (*pcVar9)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0082032a8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

