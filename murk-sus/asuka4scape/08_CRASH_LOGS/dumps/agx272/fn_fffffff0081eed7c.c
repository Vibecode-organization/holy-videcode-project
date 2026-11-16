// FUN_fffffff0081eed7c @ fffffff0081eed7c size=4

void FUN_fffffff0081eed7c
               (long param_1,uint param_2,ulong param_3,long param_4,long param_5,ulong param_6,
               uint param_7,long param_8,long param_9)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  uint *puVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  long lStack_b0;
  long lStack_a8;
  long lStack_a0;
  ulong uStack_98;
  long lStack_90;
  undefined8 uStack_88;
  long lStack_80;
  undefined8 uStack_78;
  long lStack_68;
  
  lStack_68 = *(long *)PTR_DAT_fffffff007ca61a0;
  uVar10 = (ulong)param_7;
  uVar2 = 0;
  if (uVar10 != 0) {
    uVar2 = param_6 / uVar10;
  }
  if (0x3fffffff < uVar2) {
    uVar2 = 0x40000000;
  }
  uVar2 = uVar2 & 0x7fffc000;
  if (uVar2 != 0) {
    uVar3 = *(ulong *)(param_1 + 0x38);
    if (uVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar6 = uVar3 + (ulong)*(uint *)(param_1 + 0x40) * 0x68;
      if (((uVar3 ^ uVar6) & 0xffc0000000000000) != 0) {
        uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
      }
      uVar4 = uVar6 - uVar3;
      if ((uVar6 < uVar3) || (uVar4 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                  );
      }
    }
    lVar8 = (ulong)param_2 * 0x68;
    if (lVar8 - (int)lVar8 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                );
    }
    uVar6 = (ulong)param_2 * 0x6800000000;
    if (((long)uVar6 < 0) || ((uint)uVar4 < (int)(uVar6 >> 0x20) + 0x68U)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                );
    }
    uVar7 = (ulong)CARRY8(uVar3,uVar6 >> 0x20);
    uVar4 = -uVar7;
    if ((uVar4 != uVar7) || ((long)uVar4 < 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                );
    }
    if (param_7 != 0) {
      lVar8 = param_9 + param_5 + 0x30;
      lVar9 = 0;
      param_9 = param_9 + param_4;
      if ((*(uint *)(*(long *)(uVar3 + (uVar6 >> 0x20)) + 4) & 1) == 0) {
        do {
          lStack_a0 = uVar2 * lVar9;
          lStack_b0 = param_8 + param_4 + lStack_a0;
          lStack_a8 = param_8 + param_5 + lStack_a0;
          uStack_88 = 0;
          uStack_78 = 0;
          puVar5 = (uint *)(param_3 + lVar9 * 0x38);
          if (((param_3 ^ (ulong)puVar5) & 0xffc0000000000000) != 0) {
            puVar5 = (uint *)((ulong)puVar5 & 0xffffffffffff | 0xc8a2000000000000);
          }
          *puVar5 = param_2;
          *(long *)(puVar5 + 4) = lStack_a8;
          puVar5[2] = (uint)uVar2;
          *(long *)(puVar5 + 6) = lStack_a8;
          *(long *)(puVar5 + 8) = lStack_a8;
          *(long *)(puVar5 + 10) = lVar8 + -0x10;
          *(long *)(puVar5 + 0xc) = lVar8;
          *(short *)(puVar5 + 1) = (short)*(undefined4 *)(param_1 + 0x4c);
          *(char *)((long)puVar5 + 6) = (char)*(undefined4 *)(param_1 + 0x50);
          uStack_98 = uVar2;
          lStack_90 = lStack_a8;
          lStack_80 = lStack_a8;
          thunk_EXT_FUN_8011000003386690(&lStack_b0,param_9,0x40);
          lVar9 = lVar9 + 1;
          lVar8 = lVar8 + 0x40;
          param_9 = param_9 + 0x40;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
      else {
        do {
          lStack_a8 = uVar2 * lVar9;
          lStack_b0 = param_8 + param_4 + lStack_a8;
          lVar1 = param_8 + param_5 + lStack_a8;
          uStack_88 = 0;
          uStack_78 = 0;
          puVar5 = (uint *)(param_3 + lVar9 * 0x38);
          if (((param_3 ^ (ulong)puVar5) & 0xffc0000000000000) != 0) {
            puVar5 = (uint *)((ulong)puVar5 & 0xffffffffffff | 0xc8a2000000000000);
          }
          *puVar5 = param_2;
          *(long *)(puVar5 + 4) = lVar1;
          puVar5[2] = (uint)uVar2;
          *(long *)(puVar5 + 6) = lVar1;
          *(long *)(puVar5 + 8) = lVar1;
          *(long *)(puVar5 + 10) = lVar8 + -0x10;
          *(long *)(puVar5 + 0xc) = lVar8;
          *(short *)(puVar5 + 1) = (short)*(undefined4 *)(param_1 + 0x4c);
          *(char *)((long)puVar5 + 6) = (char)*(undefined4 *)(param_1 + 0x50);
          lStack_a0 = lStack_a8;
          uStack_98 = uVar2;
          lStack_90 = lStack_a8;
          lStack_80 = lStack_a8;
          thunk_EXT_FUN_8011000003386690(&lStack_b0,param_9,0x40);
          lVar9 = lVar9 + 1;
          lVar8 = lVar8 + 0x40;
          param_9 = param_9 + 0x40;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
    }
  }
  if (*(long *)PTR_DAT_fffffff007ca61a0 != lStack_68) {
    thunk_EXT_FUN_8011000003a48590(uVar2 != 0);
    return;
  }
  return;
}

