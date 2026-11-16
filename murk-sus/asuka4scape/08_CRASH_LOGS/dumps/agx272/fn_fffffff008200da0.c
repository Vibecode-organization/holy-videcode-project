// FUN_fffffff008200da0 @ fffffff008200da0 size=168

undefined4 FUN_fffffff008200da0(long param_1,int param_2)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar2 = *(ulong *)(param_1 + 0x38);
  if (uVar2 != 0) {
    uVar3 = uVar2 + (ulong)*(uint *)(param_1 + 0x40) * 0x68;
    if (((uVar2 ^ uVar3) & 0xffc0000000000000) != 0) {
      uVar3 = uVar3 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar3 < uVar2) || (uVar3 - uVar2 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                );
    }
    uVar1 = param_2 * 0x68;
    if (uVar1 + 0x68 <= (uint)(uVar3 - uVar2)) {
      uVar4 = (ulong)CARRY8(uVar2,(ulong)uVar1);
      uVar3 = -uVar4;
      if ((uVar3 == uVar4) && (-1 < (long)uVar3)) {
        return *(undefined4 *)(*(long *)(uVar2 + uVar1) + 4);
      }
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                );
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff008214ca8
            (
            "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
            );
}

