// FUN_fffffff0081664f4 @ fffffff0081664f4 size=244

void FUN_fffffff0081664f4(long param_1,long param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  
  uVar2 = *(uint *)(param_2 + 0x2c);
  uVar3 = *(ulong *)(param_2 + 0x98);
  if (uVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar7 = uVar3 + (ulong)*(uint *)(param_2 + 0xa0) * 8;
    if (((uVar3 ^ uVar7) & 0xffc0000000000000) != 0) {
      uVar7 = uVar7 & 0xffffffffffff | 0xc8a2000000000000;
    }
    uVar4 = uVar7 - uVar3;
    if ((uVar7 < uVar3) || (uVar4 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                );
    }
  }
  lVar6 = (ulong)uVar2 * 8;
  iVar5 = (int)lVar6;
  if (lVar6 - iVar5 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff008214ca8
              (
              "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
              );
  }
  if ((((ulong)uVar2 & 0x1fffffff) >> 0x1c == 0) && (uVar2 = uVar2 * 8, uVar2 + 8 <= (uint)uVar4)) {
    uVar7 = (ulong)CARRY8(uVar3,(ulong)uVar2);
    uVar4 = -uVar7;
    if ((uVar4 == uVar7) && (-1 < (long)uVar4)) {
      *(undefined8 *)(param_1 + 0x8b8) = *(undefined8 *)(uVar3 + uVar2);
      puVar1 = (undefined8 *)(*(long *)(param_2 + 0x78) + (long)iVar5);
      if (lVar6 - iVar5 != 0) {
        puVar1 = (undefined8 *)
                 (*(long *)(param_2 + 0x78) + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *(undefined8 *)(param_1 + 0x8c0) = *puVar1;
      *(undefined8 *)(param_1 + 0x8c8) = *(undefined8 *)(param_2 + 0xa8);
      *(undefined4 *)(param_1 + 0x8d8) = *(undefined4 *)(param_2 + 0x1c4);
      return;
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

