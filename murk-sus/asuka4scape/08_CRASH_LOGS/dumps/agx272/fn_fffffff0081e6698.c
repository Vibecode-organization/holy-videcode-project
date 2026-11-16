// FUN_fffffff0081e6698 @ fffffff0081e6698 size=532

undefined8 FUN_fffffff0081e6698(long param_1,long param_2)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  uint *puVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  
  uVar2 = **(uint **)(param_1 + 0x1370);
  uVar3 = (*(uint **)(param_1 + 0x1370))[3];
  uVar11 = (ulong)uVar3;
  lVar6 = thunk_EXT_FUN_80110000038961f4(uVar2 - uVar3);
  *(long *)(param_2 + 0x168) = lVar6;
  if (lVar6 == 0) {
    uVar7 = 0xe00002bd;
  }
  else {
    uVar7 = FUN_fffffff0081e0b20(*(undefined8 *)(param_1 + 0x40));
    if ((int)uVar7 == 0) {
      (**(code **)(**(long **)(param_1 + 0x40) + 0x20))();
      *(undefined8 *)(param_2 + 0x178) = *(undefined8 *)(param_1 + 0x40);
      if (uVar3 < uVar2) {
        uVar1 = param_1 + 0x1160;
        uVar4 = (param_1 + 0x1360U) - uVar1;
        if ((param_1 + 0x1360U < uVar1) || (uVar4 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                    );
        }
        uVar12 = uVar11 << 0x23;
        uVar13 = uVar11 * 8 - 0x80000008;
        do {
          uVar13 = uVar13 + 8;
          if (uVar13 < 0xffffffff00000000) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff008214ca8
                      (
                      "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                      );
          }
          if (((long)uVar12 < 0) || ((uint)uVar4 < (int)(uVar12 >> 0x20) + 8U)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff008214ca8
                      (
                      "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                      );
          }
          uVar10 = (ulong)CARRY8(uVar1,uVar12 >> 0x20);
          uVar9 = -uVar10;
          if ((uVar9 != uVar10) || ((long)uVar9 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff008214ca8
                      (
                      "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                      );
          }
          lVar6 = *(long *)(uVar1 + (uVar12 >> 0x20));
          uVar7 = thunk_EXT_FUN_801100000297b3fc(*(undefined8 *)(lVar6 + 0x58));
          if ((int)uVar7 != 0) {
            return uVar7;
          }
          (**(code **)(**(long **)(param_2 + 0x168) + 0xe8))(*(long **)(param_2 + 0x168),lVar6);
          if (((*(byte *)(lVar6 + 0x50) & 1) != 0) &&
             (iVar5 = thunk_EXT_FUN_80110000029479f8
                                (*(undefined8 *)(*(long *)(param_1 + 0x28) + 0x148),lVar6 + 0x10),
             iVar5 != 0)) {
            thunk_EXT_FUN_801100000297b408(*(undefined8 *)(lVar6 + 0x58));
            *(ulong *)(param_1 + 0x13a8) =
                 *(ulong *)(param_1 + 0x13a8) & (1L << (uVar11 & 0x3f) ^ 0xffffffffffffffffU);
            *(undefined1 *)(lVar6 + 0x50) = 0;
          }
          puVar8 = *(uint **)(param_1 + 0x1370);
          if ((uVar11 == puVar8[2]) && (puVar8[2] < *puVar8)) {
            puVar8[2] = puVar8[2] + 1;
          }
          uVar12 = uVar12 + 0x800000000;
          uVar11 = uVar11 + 1;
        } while (uVar2 != uVar11);
      }
      uVar7 = 0;
      *(undefined1 *)(param_1 + 0x13b0) = 0;
    }
  }
  return uVar7;
}

