// FUN_fffffff0081e63f0 @ fffffff0081e63f0 size=680

void FUN_fffffff0081e63f0(long param_1,undefined8 param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  ulong uVar6;
  int iVar7;
  long lVar8;
  undefined4 *puVar9;
  uint *puVar10;
  ulong uVar11;
  ulong uVar12;
  uint uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  
  lVar8 = *(long *)(param_1 + 0x28);
  if ((*(byte *)(lVar8 + 0x1ac44) >> 3 & 1) != 0) {
    puVar9 = *(undefined4 **)(param_1 + 0x1370);
    uVar2 = *puVar9;
    uVar3 = puVar9[1];
    uVar4 = puVar9[2];
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930cf9,uVar2,uVar3,uVar4,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 0x1ac48));
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  thunk_EXT_FUN_8011000002947870(*(undefined8 *)(*(long *)(param_1 + 0x28) + 0x148),param_1 + 0xe0);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  puVar10 = *(uint **)(param_1 + 0x1370);
  uVar13 = puVar10[1];
  uVar14 = (ulong)uVar13;
  if (uVar13 < 0x40) {
    uVar5 = *puVar10;
    if (uVar5 < 0x41) {
      if (uVar13 < uVar5) {
        uVar1 = param_1 + 0x1160;
        uVar6 = (param_1 + 0x1360U) - uVar1;
        if ((param_1 + 0x1360U < uVar1) || (uVar6 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                    );
        }
        uVar15 = uVar14 * 8 - 0x80000008;
        uVar16 = uVar14 << 0x23;
        do {
          uVar15 = uVar15 + 8;
          if (uVar15 < 0xffffffff00000000) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff008214ca8
                      (
                      "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                      );
          }
          if (((long)uVar16 < 0) || ((uint)uVar6 < (int)(uVar16 >> 0x20) + 8U)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff008214ca8
                      (
                      "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                      );
          }
          uVar12 = (ulong)CARRY8(uVar1,uVar16 >> 0x20);
          uVar11 = -uVar12;
          if ((uVar11 != uVar12) || ((long)uVar11 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff008214ca8
                      (
                      "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                      );
          }
          lVar8 = *(long *)(uVar1 + (uVar16 >> 0x20));
          if ((*(byte *)(lVar8 + 0x50) & 1) != 0) {
            thunk_EXT_FUN_801100000297b408(*(undefined8 *)(lVar8 + 0x58));
            *(ulong *)(param_1 + 0x13a8) =
                 *(ulong *)(param_1 + 0x13a8) & (1L << (uVar14 & 0x3f) ^ 0xffffffffffffffffU);
            *(undefined1 *)(lVar8 + 0x50) = 0;
          }
          uVar16 = uVar16 + 0x800000000;
          uVar14 = uVar14 + 1;
        } while (uVar5 != uVar14);
        puVar10 = *(uint **)(param_1 + 0x1370);
        uVar13 = puVar10[1];
      }
      *puVar10 = uVar13;
      puVar10[2] = puVar10[3];
      lVar8 = *(long *)(param_1 + 0x28);
      if ((*(byte *)(lVar8 + 0x1ac44) >> 3 & 1) != 0) {
        uVar5 = puVar10[2];
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 0x1ac48));
        thunk_EXT_FUN_80110000036da494(0x85930cfa,uVar13,uVar13,uVar5,0,0);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 0x1ac48));
      }
      *(undefined1 *)(param_1 + 0x13b0) = 1;
      iVar7 = FUN_fffffff0081e6698(param_1,param_2);
      *(undefined1 *)(param_1 + 0x13b0) = 0;
      if (iVar7 == 0) {
        *(undefined4 *)(param_1 + 0x48) = 0;
      }
      return;
    }
  }
  thunk_EXT_FUN_8011000003a49114
            ("AGXk: %s:%d:%s: !!! Assertion failed: %s: OOB access in fBlockArray\n");
  return;
}

