// FUN_fffffff00820b9d0 @ fffffff00820b9d0 size=252

void FUN_fffffff00820b9d0(long param_1,long param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  code *pcVar3;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  ulong unaff_x30;
  
  uVar2 = *(uint *)(param_2 + 0x2c);
  uVar4 = *(ulong *)(param_2 + 0x98);
  if (uVar4 == 0) {
    uVar5 = 0;
  }
  else {
    uVar8 = uVar4 + (ulong)*(uint *)(param_2 + 0xa0) * 8;
    if (((uVar4 ^ uVar8) & 0xffc0000000000000) != 0) {
      uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
    }
    uVar5 = uVar8 - uVar4;
    if ((uVar8 < uVar4) || (uVar5 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                );
    }
  }
  lVar7 = (ulong)uVar2 * 8;
  iVar6 = (int)lVar7;
  if (lVar7 - iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff008214ca8
              (
              "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
              );
  }
  if ((((ulong)uVar2 & 0x1fffffff) >> 0x1c == 0) && (uVar2 = uVar2 * 8, uVar2 + 8 <= (uint)uVar5)) {
    uVar8 = (ulong)CARRY8(uVar4,(ulong)uVar2);
    uVar5 = -uVar8;
    if ((uVar5 != uVar8) || ((long)uVar5 < 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                );
    }
    *(undefined8 *)(param_1 + 0x1020) = *(undefined8 *)(uVar4 + uVar2);
    puVar1 = (undefined8 *)(*(long *)(param_2 + 0x78) + (long)iVar6);
    if (lVar7 - iVar6 != 0) {
      puVar1 = (undefined8 *)
               (*(long *)(param_2 + 0x78) + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *(undefined8 *)(param_1 + 0x1028) = *puVar1;
    *(undefined8 *)(param_1 + 0x1030) = *(undefined8 *)(param_2 + 0xa8);
    *(undefined4 *)(param_1 + 0x1038) = *(undefined4 *)(param_2 + 0x1c4);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00820baa4);
      (*pcVar3)();
    }
    FUN_fffffff0081664f4();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff008214ca8
            (
            "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
            );
}

