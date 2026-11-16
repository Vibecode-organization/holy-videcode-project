// FUN_fffffff008202558 @ fffffff008202558 size=264

void FUN_fffffff008202558(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    uVar4 = 0;
    uVar5 = 0;
    do {
      uVar1 = *(ulong *)(param_1 + 0x40);
      if (uVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar3 = uVar1 + (ulong)*(uint *)(param_1 + 0x48) * 0x40;
        if (((uVar1 ^ uVar3) & 0xffc0000000000000) != 0) {
          uVar3 = uVar3 & 0xffffffffffff | 0xc8a2000000000000;
        }
        uVar2 = uVar3 - uVar1;
        if ((uVar3 < uVar1) || (uVar2 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                    );
        }
      }
      if (uVar5 == 0x2000000) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                  );
      }
      if (((long)uVar4 < 0) || ((uint)uVar2 < (int)(uVar4 >> 0x20) + 0x40U)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                  );
      }
      uVar3 = (ulong)CARRY8(uVar1,uVar4 >> 0x20);
      uVar2 = -uVar3;
      if ((uVar2 != uVar3) || ((long)uVar2 < 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  ("This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                   ,uVar1 + (uVar4 >> 0x20));
      }
      thunk_EXT_FUN_8011000002947a48(*(undefined8 *)(param_1 + 0x38));
      uVar5 = uVar5 + 1;
      uVar4 = uVar4 + 0x4000000000;
    } while (uVar5 < *(uint *)(param_1 + 0x58));
  }
  return;
}

