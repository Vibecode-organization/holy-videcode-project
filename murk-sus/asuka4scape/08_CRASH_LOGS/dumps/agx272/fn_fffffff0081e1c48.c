// FUN_fffffff0081e1c48 @ fffffff0081e1c48 size=4

void FUN_fffffff0081e1c48(long param_1)

{
  undefined8 *puVar1;
  long *plVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  long lVar7;
  int *piVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  ulong unaff_x30;
  
  lVar7 = *(long *)(param_1 + 0x18);
  if (lVar7 != 0) {
    if (*(long *)(param_1 + 0x68) != 0) {
      if (*(long *)(param_1 + 0x28) == 0) {
        lVar7 = *(long *)(lVar7 + 0x4b0);
        uVar3 = *(uint *)(param_1 + 0x50);
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x1110));
        if ((uVar3 == 0xffffffff) ||
           (uVar4 = *(uint *)(lVar7 + 0x1120), uVar10 = *(long *)(lVar7 + 0x1158) * (ulong)uVar4,
           uVar10 < uVar3 || uVar10 - uVar3 == 0)) {
          thunk_EXT_FUN_8011000003a49114
                    (
                    "AGXk: %s:%d:%s: !!! Assertion failed: %s: Attempt to release an out-of-range element (%d)\n"
                    );
          return;
        }
        uVar5 = 0;
        if (uVar4 != 0) {
          uVar5 = uVar3 / uVar4;
        }
        lVar9 = (ulong)uVar5 * 8;
        puVar1 = (undefined8 *)(*(long *)(lVar7 + 0x1150) + (long)(int)lVar9);
        if (lVar9 != (int)lVar9) {
          puVar1 = (undefined8 *)
                   (*(long *)(lVar7 + 0x1150) + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
        }
        piVar8 = (int *)*puVar1;
        if (piVar8 == (int *)0x0) {
          thunk_EXT_FUN_8011000003a49114
                    ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid allocation\n");
          return;
        }
        if (*piVar8 == 0) {
          thunk_EXT_FUN_8011000003a49114
                    ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid ref count (%d %d)\n");
          return;
        }
        *piVar8 = *piVar8 + -1;
        lVar9 = *(long *)(lVar7 + 0x1170) + (ulong)(uVar3 >> 8) * 0x20;
        uVar10 = (ulong)((uVar3 & 0xff) >> 6);
        uVar12 = 1L << ((ulong)(uVar3 & 0xff) & 0x3f);
        if ((*(ulong *)(lVar9 + uVar10 * 8) & uVar12) != 0) {
          thunk_EXT_FUN_8011000003a49114
                    ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid element (%d)\n");
          return;
        }
        uVar11 = (ulong)(uVar3 >> 0xb) & 0x1ffff8;
        *(ulong *)(lVar7 + 0x1168 + uVar11) =
             *(ulong *)(lVar7 + 0x1168 + uVar11) | 1L << ((ulong)(uVar3 >> 8) & 0x3f);
        *(ulong *)(lVar9 + uVar10 * 8) = *(ulong *)(lVar9 + uVar10 * 8) | uVar12;
        FUN_fffffff0081ac984(lVar7 + 0x10d8,(ulong)uVar5,1);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x1110));
        lVar7 = *(long *)(param_1 + 0x60);
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x40));
        if (0 < *(long *)(lVar7 + 0x38)) {
          if (*(long *)(lVar7 + 0x50) != 0) {
            thunk_EXT_FUN_801100000297b408();
          }
          if (*(long *)(lVar7 + 0x58) != 0) {
            thunk_EXT_FUN_801100000297b408();
          }
          *(long *)(lVar7 + 0x38) = *(long *)(lVar7 + 0x38) + -1;
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x40));
        (**(code **)(**(long **)(param_1 + 0x60) + 0x28))();
        lVar7 = *(long *)(param_1 + 0x18);
      }
      *(undefined8 *)(param_1 + 0x50) = 0;
      *(undefined8 *)(param_1 + 0x58) = 0;
      *(undefined8 *)(param_1 + 0x60) = 0;
      *(undefined8 *)(param_1 + 0x68) = 0;
    }
    if ((*(byte *)(param_1 + 0x30) & 1) != 0) {
      lVar13 = *(long *)(*(long *)(lVar7 + 0x11d98) + 0x10);
      uVar10 = thunk_EXT_FUN_8011000002c13530(*(undefined8 *)(param_1 + 0x28));
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar13 + 0x28));
      lVar9 = *(long *)(lVar13 + 0x10);
      lVar7 = (uVar10 & 0xffffffff) * 8;
      plVar2 = (long *)(lVar9 + (int)lVar7);
      if (lVar7 != (int)lVar7) {
        plVar2 = (long *)(lVar9 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
      }
      if (*plVar2 == param_1) {
        lVar7 = (uVar10 & 0xffffffff) * 8;
        puVar1 = (undefined8 *)(lVar9 + (int)lVar7);
        if (lVar7 - (int)lVar7 != 0) {
          puVar1 = (undefined8 *)(lVar9 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar1 = 0;
      }
      *(int *)(lVar13 + 0x18) = *(int *)(lVar13 + 0x18) + -1;
      *(undefined1 *)(param_1 + 0x30) = 0;
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar13 + 0x28));
    }
    if (*(long **)(param_1 + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x28) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x28) = 0;
    if (*(long *)(param_1 + 0x48) != 0) {
      thunk_EXT_FUN_80110000038ff020();
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e1eb4);
    (*pcVar6)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081e1ebc. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6158 + 0x80))(param_1);
  return;
}

