// FUN_fffffff0081e4fec @ fffffff0081e4fec size=4

void FUN_fffffff0081e4fec(long param_1)

{
  long *plVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  code *pcVar7;
  long *plVar8;
  ulong uVar9;
  int *piVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x50) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x50) = 0;
  }
  if ((*(long *)(param_1 + 0x1370) != 0) &&
     (uVar3 = *(uint *)(*(long *)(param_1 + 0x1370) + 0xc), uVar13 = (ulong)uVar3, uVar3 < 0x40)) {
    uVar12 = param_1 + 0x1160;
    uVar11 = (param_1 + 0x1360U) - uVar12;
    if ((param_1 + 0x1360U < uVar12) || (uVar11 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                );
    }
    uVar15 = uVar13 << 3;
    do {
      if (uVar11 < uVar15 + 8) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                  );
      }
      plVar1 = (long *)(uVar12 + uVar15);
      uVar9 = -(ulong)CARRY8(uVar12,uVar15);
      if ((uVar9 != CARRY8(uVar12,uVar15)) || ((long)uVar9 < 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                  );
      }
      plVar8 = (long *)*plVar1;
      if (plVar8 != (long *)0x0) {
        if ((*(byte *)(plVar8 + 10) & 1) != 0) {
          thunk_EXT_FUN_801100000297b408(plVar8[0xb]);
          *(ulong *)(param_1 + 0x13a8) =
               *(ulong *)(param_1 + 0x13a8) & (1L << (uVar13 & 0x3f) ^ 0xffffffffffffffffU);
          plVar8 = (long *)*plVar1;
          *(undefined1 *)(plVar8 + 10) = 0;
        }
        (**(code **)(*plVar8 + 0x28))();
      }
      *plVar1 = 0;
      uVar13 = uVar13 + 1;
      uVar15 = uVar15 + 8;
    } while (uVar13 != 0x40);
  }
  if (*(long *)(param_1 + 5000) != 0) {
    lVar14 = *(long *)(*(long *)(param_1 + 0x28) + 0x4b0);
    uVar3 = *(uint *)(param_1 + 0x1398);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar14 + 0x1058));
    if ((uVar3 == 0xffffffff) ||
       (uVar4 = *(uint *)(lVar14 + 0x1068), uVar13 = *(long *)(lVar14 + 0x10a0) * (ulong)uVar4,
       uVar13 < uVar3 || uVar13 - uVar3 == 0)) {
      thunk_EXT_FUN_8011000003a49114
                (
                "AGXk: %s:%d:%s: !!! Assertion failed: %s: Attempt to release an out-of-range element (%d)\n"
                );
      return;
    }
    uVar6 = 0;
    if (uVar4 != 0) {
      uVar6 = uVar3 / uVar4;
    }
    lVar5 = (ulong)uVar6 * 8;
    puVar2 = (undefined8 *)(*(long *)(lVar14 + 0x1098) + (long)(int)lVar5);
    if (lVar5 != (int)lVar5) {
      puVar2 = (undefined8 *)
               (*(long *)(lVar14 + 0x1098) + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
    }
    piVar10 = (int *)*puVar2;
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
    *piVar10 = *piVar10 + -1;
    lVar5 = *(long *)(lVar14 + 0x10b8) + (ulong)(uVar3 >> 8) * 0x20;
    uVar13 = (ulong)((uVar3 & 0xff) >> 6);
    uVar12 = 1L << ((ulong)(uVar3 & 0xff) & 0x3f);
    if ((*(ulong *)(lVar5 + uVar13 * 8) & uVar12) != 0) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid element (%d)\n");
      return;
    }
    uVar11 = (ulong)(uVar3 >> 0xb) & 0x1ffff8;
    *(ulong *)(lVar14 + 0x10b0 + uVar11) =
         *(ulong *)(lVar14 + 0x10b0 + uVar11) | 1L << ((ulong)(uVar3 >> 8) & 0x3f);
    *(ulong *)(lVar5 + uVar13 * 8) = *(ulong *)(lVar5 + uVar13 * 8) | uVar12;
    FUN_fffffff0081ae0fc(lVar14 + 0x1020,(ulong)uVar6,1);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar14 + 0x1058));
    *(undefined8 *)(param_1 + 5000) = 0;
    *(undefined4 *)(param_1 + 0x1398) = 0xffffffff;
    *(undefined8 *)(param_1 + 0x13a0) = 0;
  }
  lVar14 = *(long *)(param_1 + 0x1390);
  if (lVar14 != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar14 + 0x40));
    if (0 < *(long *)(lVar14 + 0x38)) {
      if (*(long *)(lVar14 + 0x50) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (*(long *)(lVar14 + 0x58) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      *(long *)(lVar14 + 0x38) = *(long *)(lVar14 + 0x38) + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar14 + 0x40));
    if (*(long **)(param_1 + 0x1390) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x1390) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x1390) = 0;
  }
  if (*(long **)(param_1 + 0x40) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x40) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x40) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e52a0);
    (*pcVar7)();
  }
  FUN_fffffff00816b2a8(*(undefined8 *)(param_1 + 0x28));
  return;
}

