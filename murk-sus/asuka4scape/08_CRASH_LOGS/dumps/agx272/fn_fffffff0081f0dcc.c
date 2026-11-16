// FUN_fffffff0081f0dcc @ fffffff0081f0dcc size=432

void FUN_fffffff0081f0dcc(long param_1)

{
  uint uVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  
  lVar3 = *(long *)(param_1 + 0x38);
  if (lVar3 == 0) {
    return;
  }
  uVar4 = (ulong)*(uint *)(param_1 + 0x48);
  if (*(uint *)(param_1 + 0x48) != 0) {
    uVar9 = 0;
    uVar10 = 0;
    do {
      uVar5 = *(ulong *)(param_1 + 0x38);
      if (uVar5 == 0) {
        uVar7 = 0;
        uVar6 = 0;
      }
      else {
        uVar6 = uVar5 + (ulong)*(uint *)(param_1 + 0x40) * 0x68;
        if (((uVar5 ^ uVar6) & 0xffc0000000000000) != 0) {
          uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
        }
        uVar7 = uVar6 - uVar5;
        if ((uVar6 < uVar5) || (uVar6 = uVar5, uVar7 >> 0x20 != 0)) goto LAB_fffffff0081f0f4c;
      }
      if (uVar10 == 0x13b13b2) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                  );
      }
      if ((long)uVar9 < 0) {
LAB_fffffff0081f0f58:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                  );
      }
      uVar1 = (int)(uVar9 >> 0x20) + 0x68;
      if ((uint)uVar7 < uVar1) goto LAB_fffffff0081f0f58;
      uVar8 = (ulong)CARRY8(uVar6,uVar9 >> 0x20);
      uVar7 = -uVar8;
      if ((uVar7 != uVar8) || ((long)uVar7 < 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                  );
      }
      plVar2 = *(long **)(uVar6 + (uVar9 >> 0x20) + 0x60);
      if (plVar2 != (long *)0x0) {
        if (uVar5 == 0) goto LAB_fffffff0081f0f58;
        uVar4 = uVar5 + (ulong)*(uint *)(param_1 + 0x40) * 0x68;
        if (((uVar5 ^ uVar4) & 0xffc0000000000000) != 0) {
          uVar4 = uVar4 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar4 < uVar6) || (uVar4 - uVar6 >> 0x20 != 0)) {
LAB_fffffff0081f0f4c:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                    );
        }
        if ((uint)(uVar4 - uVar6) < uVar1) goto LAB_fffffff0081f0f58;
        (**(code **)(*plVar2 + 8))();
        uVar4 = (ulong)*(uint *)(param_1 + 0x48);
      }
      uVar10 = uVar10 + 1;
      uVar9 = uVar9 + 0x6800000000;
    } while (uVar10 < uVar4);
    lVar3 = *(long *)(param_1 + 0x38);
    if (lVar3 == 0) goto LAB_fffffff0081f0f2c;
  }
  thunk_EXT_FUN_80110000038fe768
            (&DAT_fffffff007ca49b8,lVar3,(ulong)*(uint *)(param_1 + 0x40) * 0x68);
LAB_fffffff0081f0f2c:
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  return;
}

