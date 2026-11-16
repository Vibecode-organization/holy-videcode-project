// FUN_fffffff0081f028c @ fffffff0081f028c size=4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0081f028c(long *param_1,int param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  long *plVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  int iVar11;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  long lStack_58;
  
  lStack_58 = *(long *)PTR_DAT_fffffff007ca61a0;
  if (param_2 == 0) {
    if (param_1[4] != param_3) goto LAB_fffffff0081f0360;
    if ((*(byte *)((long)param_1 + 0x34) & 1) != 0) {
      (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x6c0))(*(long **)(param_1[2] + 0x4b0),0,0);
      *(undefined1 *)((long)param_1 + 0x34) = 0;
    }
    thunk_EXT_FUN_801100000295d6e0
              (*(undefined8 *)(param_1[2] + 0x160),*(ulong *)(param_1[2] + 0x5c8) >> 5 & 1);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1[2] + 0x11190));
    FUN_fffffff00817f498
              (param_1[2],*(undefined4 *)((long)param_1 + 0x8c),(int)param_1[0x12],
               *(undefined4 *)((long)param_1 + 0x94));
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1[2] + 0x11190));
    uStack_60 = 0;
    uStack_78 = 0;
    uStack_80 = 0;
    uStack_68 = 0;
    uStack_70 = 0;
    uStack_98 = 0;
    uStack_88 = 0;
    uStack_90 = 0;
    uStack_a0 = 9;
    (**(code **)(*param_1 + 0x88))(param_1,&uStack_a0);
    uVar3 = (ulong)*(uint *)(param_1 + 9);
    if (*(uint *)(param_1 + 9) != 0) {
      uVar9 = 0;
      uVar10 = 0;
      do {
        uVar6 = param_1[7];
        if (uVar6 == 0) {
          uVar7 = 0;
        }
        else {
          uVar8 = uVar6 + (ulong)*(uint *)(param_1 + 8) * 0x68;
          if (((uVar6 ^ uVar8) & 0xffc0000000000000) != 0) {
            uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
          }
          uVar7 = uVar8 - uVar6;
          if ((uVar8 < uVar6) || (uVar7 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff008214ca8
                      (
                      "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                      );
          }
        }
        if (uVar10 == 0x13b13b2) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                    );
        }
        if (((long)uVar9 < 0) || ((uint)uVar7 < (int)(uVar9 >> 0x20) + 0x68U)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                    );
        }
        uVar8 = (ulong)CARRY8(uVar6,uVar9 >> 0x20);
        uVar7 = -uVar8;
        if ((uVar7 != uVar8) || ((long)uVar7 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                    );
        }
        if (*(long *)(uVar6 + (uVar9 >> 0x20) + 0x48) != 0) {
          uStack_60 = 0;
          uStack_78 = 0;
          uStack_80 = 0;
          uStack_68 = 0;
          uStack_70 = 0;
          uStack_98 = 0;
          uStack_88 = 0;
          uStack_90 = 0;
          uStack_a0 = (ulong)CONCAT14((char)uVar10,3);
          (**(code **)(*param_1 + 200))(param_1,&uStack_a0);
          uVar3 = (ulong)*(uint *)(param_1 + 9);
        }
        uVar10 = uVar10 + 1;
        uVar9 = uVar9 + 0x6800000000;
      } while (uVar10 < uVar3);
    }
    (**(code **)(*param_1 + 0xb0))(param_1);
    (**(code **)(*param_1 + 0xc0))(param_1);
    (**(code **)(*param_1 + 0xe8))(param_1);
    plVar4 = (long *)thunk_EXT_FUN_8011000002940a54(*(undefined8 *)(param_1[2] + 0x1c8));
    if (plVar4 != (long *)0x0) {
      iVar1 = (**(code **)(*plVar4 + 0x90))();
      uVar2 = _UNK_fffffff007113768;
      uVar3 = _DAT_fffffff007113760;
      if (iVar1 != 0) {
        iVar11 = 0;
        do {
          lVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,iVar11);
          if (lVar5 != 0) {
            thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x168));
            if ((*(byte *)(lVar5 + 0x170) & 1) != 0) {
              uStack_98 = uVar2;
              uStack_a0 = uVar3;
              thunk_EXT_FUN_80110000039a40ec(lVar5 + 0x128,0,&uStack_a0,2);
            }
            thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x168));
          }
          iVar11 = iVar11 + 1;
        } while (iVar1 != iVar11);
      }
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
    DataMemoryBarrier(2,3);
    param_1[4] = 0;
  }
  else {
    if (param_1[4] != 0) {
LAB_fffffff0081f0360:
      uVar2 = 0;
      goto LAB_fffffff0081f0684;
    }
    uVar2 = (**(code **)(*param_1 + 0xa8))(param_1);
    if ((int)uVar2 == 0) goto LAB_fffffff0081f0684;
    uVar3 = (**(code **)(*param_1 + 0xb8))(param_1,param_3);
    if ((uVar3 & 1) == 0) {
      (**(code **)(*param_1 + 0xb0))(param_1);
      uVar2 = 0;
      goto LAB_fffffff0081f0684;
    }
    lVar5 = param_1[2];
    *(undefined4 *)((long)param_1 + 0x8c) = *(undefined4 *)(lVar5 + 0x109fc);
    *(uint *)(param_1 + 0x12) = *(byte *)(lVar5 + 0x11181) & 1;
    *(undefined4 *)((long)param_1 + 0x94) = *(undefined4 *)(lVar5 + 0x11184);
    DataMemoryBarrier(2,3);
    param_1[4] = param_3;
  }
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined1 *)((long)param_1 + 0x34) = 0;
  (**(code **)(*param_1 + 0xf8))(param_1,0);
  uVar2 = 1;
LAB_fffffff0081f0684:
  if (*(long *)PTR_DAT_fffffff007ca61a0 != lStack_58) {
    thunk_EXT_FUN_8011000003a48590(uVar2);
    return;
  }
  return;
}

