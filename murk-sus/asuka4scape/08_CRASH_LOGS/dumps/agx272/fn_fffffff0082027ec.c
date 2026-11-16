// FUN_fffffff0082027ec @ fffffff0082027ec size=748

undefined8 FUN_fffffff0082027ec(long param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  long *plVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  
  lVar10 = *(long *)(param_1 + 8);
  *(long *)(param_1 + 0x10) = lVar10;
  uVar1 = *(uint *)PTR_DAT_fffffff007ca5f88;
  uVar7 = *(undefined8 *)(lVar10 + 0x148);
  *(uint *)(param_1 + 0x58) = param_3;
  uVar9 = (ulong)(param_2 + 0x3fU & 0xfc0);
  *(ulong *)(param_1 + 0x50) = uVar9;
  lVar6 = (long)(1 << (ulong)(uVar1 & 0x1f));
  uVar9 = (lVar6 + uVar9 * param_3) - 1 & -lVar6;
  *(ulong *)(param_1 + 0x30) = uVar9;
  *(undefined8 *)(param_1 + 0x38) = uVar7;
  lVar6 = thunk_EXT_FUN_801100000297cd4c
                    (lVar10,*(undefined8 *)PTR_DAT_fffffff007ca61d0,0,0,
                     *(uint *)(lVar10 + 0x18b70) | 0x23,uVar9,0);
  *(long *)(param_1 + 0x18) = lVar6;
  if (lVar6 != 0) {
    thunk_EXT_FUN_801100000297dcd4();
    lVar6 = (**(code **)(**(long **)(param_1 + 0x18) + 0x90))
                      (*(long **)(param_1 + 0x18),*(undefined8 *)(lVar10 + 0x11da0),0x20900000007);
    *(long *)(param_1 + 0x20) = lVar6;
    plVar3 = *(long **)(param_1 + 0x18);
    if (lVar6 != 0) {
      plVar3 = (long *)thunk_EXT_FUN_801100000297dd00();
      lVar6 = (**(code **)(*plVar3 + 0x148))();
      *(long *)(param_1 + 0x28) = lVar6;
      if (lVar6 != 0) {
        uVar1 = *(uint *)(param_1 + 0x58);
        lVar6 = thunk_EXT_FUN_80110000038fe5cc((ulong)uVar1 << 6);
        lVar10 = *(long *)(param_1 + 0x40);
        uVar2 = *(uint *)(param_1 + 0x48);
        *(long *)(param_1 + 0x40) = lVar6;
        *(uint *)(param_1 + 0x48) = uVar1;
        if (lVar10 != 0) {
          thunk_EXT_FUN_80110000038fe6b0(lVar10,(ulong)uVar2 << 6);
          lVar6 = *(long *)(param_1 + 0x40);
        }
        if (lVar6 == 0) {
          (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
          (**(code **)(**(long **)(param_1 + 0x20) + 0x28))();
          *(undefined8 *)(param_1 + 0x18) = 0;
          *(undefined8 *)(param_1 + 0x20) = 0;
          *(undefined8 *)(param_1 + 0x28) = 0;
          return 0;
        }
        if (*(int *)(param_1 + 0x58) != 0) {
          uVar11 = 0;
          uVar9 = 0;
          do {
            uVar4 = *(ulong *)(param_1 + 0x40);
            if (uVar4 == 0) {
              uVar5 = 0;
            }
            else {
              uVar8 = uVar4 + (ulong)*(uint *)(param_1 + 0x48) * 0x40;
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
            if (uVar9 == 0x2000000) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff008214ca8
                        (
                        "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                        );
            }
            if (((long)uVar11 < 0) || ((uint)uVar5 < (int)(uVar11 >> 0x20) + 0x40U)) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff008214ca8
                        (
                        "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                        );
            }
            uVar8 = (ulong)CARRY8(uVar4,uVar11 >> 0x20);
            uVar5 = -uVar8;
            if ((uVar5 != uVar8) || ((long)uVar5 < 0)) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff008214ca8
                        (
                        "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                        );
            }
            thunk_EXT_FUN_8011000002946f14(uVar4 + (uVar11 >> 0x20));
            uVar9 = uVar9 + 1;
            uVar11 = uVar11 + 0x4000000000;
          } while (uVar9 < *(uint *)(param_1 + 0x58));
        }
        *(undefined4 *)(param_1 + 0x70) = 0;
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
        return 1;
      }
      (**(code **)(**(long **)(param_1 + 0x20) + 0x28))();
      *(undefined8 *)(param_1 + 0x20) = 0;
      plVar3 = *(long **)(param_1 + 0x18);
    }
    (**(code **)(*plVar3 + 0x28))();
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  return 0;
}

