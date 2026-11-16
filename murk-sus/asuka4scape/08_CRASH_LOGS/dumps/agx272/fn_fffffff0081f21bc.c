// FUN_fffffff0081f21bc @ fffffff0081f21bc size=344

undefined8 FUN_fffffff0081f21bc(long param_1)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  
  if (*(int *)(param_1 + 0x48) != 0) {
    uVar6 = 0;
    uVar5 = 0;
    uVar7 = 0xffffffff80000000;
    do {
      iVar1 = FUN_fffffff0081f1f88(param_1,uVar5);
      if (iVar1 != 0) {
        uVar2 = *(ulong *)(param_1 + 0x38);
        if (uVar2 == 0) {
          uVar3 = 0;
        }
        else {
          uVar4 = uVar2 + (ulong)*(uint *)(param_1 + 0x40) * 0x68;
          if (((uVar2 ^ uVar4) & 0xffc0000000000000) != 0) {
            uVar4 = uVar4 & 0xffffffffffff | 0xc8a2000000000000;
          }
          uVar3 = uVar4 - uVar2;
          if ((uVar4 < uVar2) || (uVar3 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff008214ca8
                      (
                      "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                      );
          }
        }
        if (uVar7 < 0xffffffff00000000) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                    );
        }
        if (((long)uVar6 < 0) || ((uint)uVar3 < (int)(uVar6 >> 0x20) + 0x68U)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                    );
        }
        uVar4 = (ulong)CARRY8(uVar2,uVar6 >> 0x20);
        uVar3 = -uVar4;
        if ((uVar3 != uVar4) || ((long)uVar3 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                    );
        }
        (**(code **)(**(long **)(uVar2 + (uVar6 >> 0x20) + 0x60) + 0x18))();
      }
      uVar5 = uVar5 + 1;
      uVar6 = uVar6 + 0x6800000000;
      uVar7 = uVar7 + 0x68;
    } while (uVar5 < *(uint *)(param_1 + 0x48));
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  return 1;
}

