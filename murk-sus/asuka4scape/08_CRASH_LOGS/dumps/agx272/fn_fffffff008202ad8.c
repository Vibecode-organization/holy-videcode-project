// FUN_fffffff008202ad8 @ fffffff008202ad8 size=584

void FUN_fffffff008202ad8(long param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  
  *(undefined4 *)(param_1 + 0x78) = param_3;
  lVar5 = *(long *)(param_1 + 8);
  if ((*(byte *)(lVar5 + 0x1ac44) >> 3 & 1) != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x7c);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930cb0,uVar1,param_3,0,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x1ac48));
  }
  uVar10 = 0;
  uVar9 = *(int *)(param_1 + 0x60) + 1;
  uVar2 = *(uint *)(param_1 + 0x58);
  uVar3 = 0;
  if (uVar2 != 0) {
    uVar3 = uVar9 / uVar2;
  }
  uVar9 = uVar9 - uVar3 * uVar2;
  do {
    uVar4 = *(ulong *)(param_1 + 0x40);
    if (uVar4 == 0) {
      uVar6 = 0;
    }
    else {
      uVar8 = uVar4 + (ulong)*(uint *)(param_1 + 0x48) * 0x40;
      if (((uVar4 ^ uVar8) & 0xffc0000000000000) != 0) {
        uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
      }
      uVar6 = uVar8 - uVar4;
      if ((uVar8 < uVar4) || (uVar6 >> 0x20 != 0)) goto LAB_fffffff008202c3c;
    }
    lVar5 = (ulong)uVar9 * 0x40;
    if (lVar5 - (int)lVar5 != 0) goto LAB_fffffff008202cd4;
    if ((((ulong)uVar9 & 0x3ffffff) >> 0x19 != 0) ||
       (uVar2 = uVar9 * 0x40, (uint)uVar6 < uVar2 + 0x40)) goto LAB_fffffff008202ce0;
    uVar8 = (ulong)CARRY8(uVar4,(ulong)uVar2);
    uVar6 = -uVar8;
    if ((uVar6 != uVar8) || ((long)uVar6 < 0)) goto LAB_fffffff008202cec;
    uVar4 = thunk_EXT_FUN_80110000029479f8(*(undefined8 *)(param_1 + 0x38),uVar4 + uVar2);
    uVar2 = *(uint *)(param_1 + 0x58);
    if ((uVar4 & 1) != 0) break;
    uVar3 = 0;
    if (uVar2 != 0) {
      uVar3 = (uVar9 + 1) / uVar2;
    }
    uVar9 = (uVar9 + 1) - uVar3 * uVar2;
    uVar10 = uVar10 + 1;
  } while (uVar10 < uVar2);
  if (uVar10 == uVar2) {
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! No free block found for SKU stream\n");
    return;
  }
  *(uint *)(param_1 + 0x60) = uVar9;
  uVar4 = *(ulong *)(param_1 + 0x40);
  if (uVar4 == 0) {
    uVar6 = 0;
  }
  else {
    uVar8 = uVar4 + (ulong)*(uint *)(param_1 + 0x48) * 0x40;
    if (((uVar4 ^ uVar8) & 0xffc0000000000000) != 0) {
      uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
    }
    uVar6 = uVar8 - uVar4;
    if ((uVar8 < uVar4) || (uVar6 >> 0x20 != 0)) {
LAB_fffffff008202c3c:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                );
    }
  }
  uVar8 = (ulong)uVar9;
  if (uVar8 * 0x40 - (long)(int)(uVar8 * 0x40) == 0) {
    if (((uVar8 & 0x3ffffff) >> 0x19 == 0) && (uVar9 = uVar9 * 0x40, uVar9 + 0x40 <= (uint)uVar6)) {
      uVar7 = (ulong)CARRY8(uVar4,(ulong)uVar9);
      uVar6 = -uVar7;
      if ((uVar6 == uVar7) && (-1 < (long)uVar6)) {
        thunk_EXT_FUN_801100000294849c(*(undefined8 *)(param_1 + 0x38),param_2,uVar4 + uVar9);
        lVar5 = *(long *)(param_1 + 0x50) * uVar8;
        uVar4 = *(ulong *)(param_1 + 0x28) + lVar5;
        if (((*(ulong *)(param_1 + 0x28) ^ uVar4) & 0xffc0000000000000) != 0) {
          uVar4 = uVar4 & 0xffffffffffff | 0xc8a2000000000000;
        }
        *(ulong *)(param_1 + 0x68) = uVar4;
        *(int *)(param_1 + 0x5c) = (int)lVar5;
        return;
      }
LAB_fffffff008202cec:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                );
    }
LAB_fffffff008202ce0:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff008214ca8
              (
              "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
              );
  }
LAB_fffffff008202cd4:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff008214ca8
            (
            "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
            );
}

