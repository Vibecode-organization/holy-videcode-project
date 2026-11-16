// FUN_fffffff0081f207c @ fffffff0081f207c size=320

undefined8 FUN_fffffff0081f207c(long param_1,undefined8 param_2,ulong param_3)

{
  undefined8 uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  
  if (*(int *)(param_1 + 0x58) == 0x200) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_fffffff0081f1f88(param_1,param_3);
    if ((int)uVar1 != 0) {
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
      lVar6 = (param_3 & 0xffffffff) * 0x68;
      if (lVar6 - (int)lVar6 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  ("bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                   ,param_2);
      }
      uVar4 = (param_3 & 0xffffffff) * 0x6800000000;
      if (((long)uVar4 < 0) || ((uint)uVar3 < (int)(uVar4 >> 0x20) + 0x68U)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  ("bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                   ,param_2);
      }
      uVar5 = (ulong)CARRY8(uVar2,uVar4 >> 0x20);
      uVar3 = -uVar5;
      if ((uVar3 != uVar5) || ((long)uVar3 < 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  ("This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                   ,param_2);
      }
      uVar1 = (**(code **)(**(long **)(uVar2 + (uVar4 >> 0x20) + 0x60) + 0x20))();
      if ((int)uVar1 != 0) {
        *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}

