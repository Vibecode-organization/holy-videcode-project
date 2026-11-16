// FUN_fffffff0081f1f88 @ fffffff0081f1f88 size=244

bool FUN_fffffff0081f1f88(long param_1,uint param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  
  if (*(uint *)(param_1 + 0x48) <= param_2) {
    return false;
  }
  uVar1 = *(ulong *)(param_1 + 0x38);
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar3 = uVar1 + (ulong)*(uint *)(param_1 + 0x40) * 0x68;
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
  lVar5 = (ulong)param_2 * 0x68;
  if (lVar5 - (int)lVar5 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff008214ca8
              (
              "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
              );
  }
  uVar3 = (ulong)param_2 * 0x6800000000;
  if ((-1 < (long)uVar3) && ((int)(uVar3 >> 0x20) + 0x68U <= (uint)uVar2)) {
    uVar4 = (ulong)CARRY8(uVar1,uVar3 >> 0x20);
    uVar2 = -uVar4;
    if ((uVar2 == uVar4) && (-1 < (long)uVar2)) {
      return *(int *)(*(long *)(uVar1 + (uVar3 >> 0x20)) + 0x18) != 0;
    }
                    /* WARNING: Subroutine does not return */
    FUN_fffffff008214ca8
              (
              "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
              );
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff008214ca8
            (
            "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
            );
}

