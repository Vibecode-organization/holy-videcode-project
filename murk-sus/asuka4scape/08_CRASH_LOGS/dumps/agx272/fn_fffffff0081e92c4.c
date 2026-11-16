// FUN_fffffff0081e92c4 @ fffffff0081e92c4 size=1324

void FUN_fffffff0081e92c4(long *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  uint *puVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  undefined8 *puVar12;
  ulong uVar13;
  ulong uVar14;
  undefined8 uVar15;
  ulong uVar16;
  long *plVar17;
  uint uVar18;
  long lVar19;
  
  lVar19 = param_1[4];
  if (lVar19 != 0) {
    lVar6 = param_1[2];
    uVar15 = *(undefined8 *)(lVar6 + 0x11db0);
    thunk_EXT_FUN_80110000038ff214(uVar15);
    iVar2 = *(int *)(lVar19 + 0x10);
    if (iVar2 != -1) {
      lVar10 = (long)iVar2 * 8;
      plVar17 = (long *)(*(long *)(lVar6 + 0x11dc0) + (long)(int)lVar10);
      if (lVar10 - (int)lVar10 != 0) {
        plVar17 = (long *)(*(long *)(lVar6 + 0x11dc0) + lVar10 & 0xffffffffffffU |
                          0x2bad000000000000);
      }
      if (*plVar17 == lVar19) {
        *plVar17 = 0;
        lVar10 = (long)*(int *)(lVar6 + 0x11de0) + 1;
        *(int *)(lVar6 + 0x11de0) = (int)lVar10;
        lVar10 = lVar10 * 4;
        piVar1 = (int *)(*(long *)(lVar6 + 0x11dd8) + (long)(int)lVar10);
        if (lVar10 - (int)lVar10 != 0) {
          piVar1 = (int *)(*(long *)(lVar6 + 0x11dd8) + lVar10 & 0xffffffffffffU |
                          0x2bad000000000000);
        }
        *piVar1 = iVar2;
      }
    }
    *(undefined4 *)(lVar19 + 0x10) = 0xffffffff;
    thunk_EXT_FUN_80110000038ff2e0(uVar15);
  }
  if (param_1[0x24] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[0x24] = 0;
  }
  lVar19 = param_1[0x22];
  if ((int)param_1[0x23] == 0) {
    if (lVar19 != 0) goto LAB_fffffff0081e93e0;
  }
  else {
    uVar16 = 0;
    do {
      (**(code **)(**(long **)(lVar19 + uVar16 * 8) + 0x90))();
      lVar19 = param_1[0x22];
      *(undefined8 *)(lVar19 + uVar16 * 8) = 0;
      uVar16 = uVar16 + 1;
    } while (uVar16 < *(uint *)(param_1 + 0x23));
    *(undefined4 *)(param_1 + 0x23) = 0;
LAB_fffffff0081e93e0:
    param_1[0x22] = 0;
    thunk_EXT_FUN_80110000038fe768
              (&DAT_fffffff007ca4738,lVar19,(ulong)*(uint *)(param_1 + 0x27) << 3);
    param_1[0x22] = 0;
  }
  puVar7 = (uint *)param_1[0x11];
  if ((puVar7 != (uint *)0x0) && (param_1[0x32] != 0)) {
    uVar18 = puVar7[2];
    if ((*(uint *)(param_1 + 0x27) <= uVar18) ||
       (uVar3 = *puVar7, *(uint *)(param_1 + 0x27) <= uVar3)) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: OOB access in GPU Driver Resource\n");
      return;
    }
    if (uVar18 != uVar3) {
      do {
        lVar19 = (ulong)uVar18 * 8;
        puVar12 = (undefined8 *)(param_1[0x32] + (long)(int)lVar19);
        if (lVar19 != (int)lVar19) {
          puVar12 = (undefined8 *)(param_1[0x32] + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar15 = *puVar12;
        *puVar12 = 0;
        (**(code **)(*param_1 + 0xe0))(param_1,uVar15);
        (**(code **)(*param_1 + 0xf8))(param_1,uVar15);
        uVar4 = *(uint *)(param_1 + 0x27);
        uVar5 = 0;
        if (uVar4 != 0) {
          uVar5 = (uVar18 + 1) / uVar4;
        }
        uVar18 = (uVar18 + 1) - uVar5 * uVar4;
      } while (uVar18 != uVar3);
      puVar7 = (uint *)param_1[0x11];
      uVar18 = uVar3;
    }
    puVar7[2] = uVar18;
  }
  plVar17 = (long *)param_1[7];
  if (plVar17 != (long *)0x0) {
    if ((int)param_1[0x38] == 0) {
LAB_fffffff0081e9520:
      (**(code **)(*plVar17 + 0x28))(plVar17);
    }
    else {
      thunk_EXT_FUN_80110000032222a8(plVar17[8]);
      if (0 < plVar17[7]) {
        if (plVar17[10] != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        if (plVar17[0xb] != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        plVar17[7] = plVar17[7] + -1;
      }
      thunk_EXT_FUN_8011000003222de0(plVar17[8]);
      *(int *)(param_1 + 0x38) = (int)param_1[0x38] + -1;
      plVar17 = (long *)param_1[7];
      if (plVar17 != (long *)0x0) goto LAB_fffffff0081e9520;
    }
    param_1[7] = 0;
  }
  if ((long *)param_1[8] != (long *)0x0) {
    (**(code **)(*(long *)param_1[8] + 0x28))();
  }
  param_1[8] = 0;
  param_1[0x11] = 0;
  if ((long *)param_1[6] != (long *)0x0) {
    (**(code **)(*(long *)param_1[6] + 0x28))();
  }
  param_1[6] = 0;
  if ((long *)param_1[9] != (long *)0x0) {
    (**(code **)(*(long *)param_1[9] + 0x28))();
  }
  param_1[9] = 0;
  FUN_fffffff00816b2a8(param_1[2]);
  uVar16 = param_1[0xf];
  if (uVar16 == 0) goto LAB_fffffff0081e9670;
  uVar18 = *(uint *)(param_1 + 10);
  uVar8 = (ulong)uVar18;
  if (uVar18 == 0) {
    lVar19 = 0;
  }
  else {
    if (uVar18 < 4) {
      uVar9 = 0;
LAB_fffffff0081e962c:
      lVar19 = uVar8 - uVar9;
      do {
        lVar6 = uVar9 * 8;
        puVar12 = (undefined8 *)(uVar16 + (long)(int)lVar6);
        if (lVar6 - (int)lVar6 != 0) {
          puVar12 = (undefined8 *)(uVar16 + lVar6 & 0xffffffffffff | 0x2bad000000000000);
        }
        *puVar12 = 0;
        uVar9 = uVar9 + 1;
        lVar19 = lVar19 + -1;
      } while (lVar19 != 0);
    }
    else {
      lVar19 = 0;
      uVar9 = uVar8 & 0xfffffffc;
      uVar11 = uVar9;
      do {
        puVar12 = (undefined8 *)(uVar16 + lVar19 * 8);
        if (((uVar16 ^ (ulong)puVar12) & 0xffc0000000000000) != 0) {
          puVar12 = (undefined8 *)((ulong)puVar12 & 0xffffffffffff | 0xc8a2000000000000);
        }
        puVar12[1] = 0;
        *puVar12 = 0;
        puVar12[3] = 0;
        puVar12[2] = 0;
        lVar19 = lVar19 + 4;
        uVar11 = uVar11 - 4;
      } while (uVar11 != 0);
      if (uVar9 != uVar8) goto LAB_fffffff0081e962c;
    }
    lVar19 = uVar8 << 3;
  }
  param_1[0xf] = 0;
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4788,uVar16,lVar19);
  param_1[0xf] = 0;
LAB_fffffff0081e9670:
  uVar16 = param_1[0x13];
  if (uVar16 != 0) {
    uVar8 = (ulong)*(uint *)(param_1 + 10);
    uVar18 = *(uint *)(param_1 + 0x14);
    if (*(uint *)(param_1 + 10) != 0) {
      uVar9 = uVar16 + (ulong)uVar18 * 8;
      if (((uVar16 ^ uVar9) & 0xffc0000000000000) != 0) {
        uVar9 = uVar9 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar9 < uVar16) || (uVar9 - uVar16 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                  );
      }
      lVar19 = 0x10000000;
      uVar11 = 0;
      do {
        if (lVar19 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                    );
        }
        if (((long)uVar11 < 0) || ((uint)(uVar9 - uVar16) < (int)(uVar11 >> 0x20) + 8U)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                    );
        }
        uVar14 = (ulong)CARRY8(uVar16,uVar11 >> 0x20);
        uVar13 = -uVar14;
        if ((uVar13 != uVar14) || ((long)uVar13 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                    );
        }
        *(undefined8 *)(uVar16 + (uVar11 >> 0x20)) = 0;
        lVar19 = lVar19 + -1;
        uVar11 = uVar11 + 0x800000000;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    thunk_EXT_FUN_80110000038fe6b0(uVar16,(ulong)uVar18 << 3);
    param_1[0x13] = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  param_1[0x15] = 0;
  lVar19 = param_1[0x18];
  param_1[0x18] = 0;
  thunk_EXT_FUN_80110000038fe6b0(lVar19,(ulong)*(uint *)(param_1 + 10) << 6);
  lVar19 = param_1[0x31];
  param_1[0x31] = 0;
  thunk_EXT_FUN_80110000038fe6b0(lVar19,(ulong)*(uint *)(param_1 + 0x27) << 6);
  lVar19 = param_1[0x32];
  if (lVar19 != 0) {
    param_1[0x32] = 0;
    thunk_EXT_FUN_80110000038fe768
              (&DAT_fffffff007ca47d8,lVar19,(ulong)*(uint *)(param_1 + 0x27) << 3);
    param_1[0x32] = 0;
  }
  return;
}

