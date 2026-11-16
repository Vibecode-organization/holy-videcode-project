// FUN_fffffff00817bf58 @ fffffff00817bf58 size=1

void FUN_fffffff00817bf58(long param_1,undefined8 param_2,int param_3)

{
  uint *puVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ulong uVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  long *plVar11;
  undefined8 uVar12;
  undefined4 *puVar13;
  int *piVar14;
  long lVar15;
  uint *puVar16;
  ulong uVar17;
  ulong uVar18;
  undefined8 *puVar19;
  int iVar20;
  long *plVar21;
  long lVar22;
  int iVar23;
  undefined4 uVar24;
  undefined8 *puStack_e8;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined4 uStack_70;
  undefined4 auStack_6c [3];
  
  puVar1 = (uint *)(param_1 + 0x182d0);
  if (param_3 == 0) {
LAB_fffffff00817c760:
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x183a0));
    if (*(uint *)(param_1 + 0x182d4) != *puVar1) {
      *puVar1 = *puVar1 + param_3 & 7;
    }
LAB_fffffff00817c78c:
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x183a0));
    return;
  }
  iVar20 = 0;
LAB_fffffff00817c0a4:
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x183a0));
  if (*(uint *)(param_1 + 0x182d4) != *puVar1) {
    piVar2 = (int *)(param_1 + 0x181d0 + (ulong)(*puVar1 + iVar20 & 7) * 0x20);
    if (*piVar2 == 1) {
      uVar4 = piVar2[2];
      if (((int)uVar4 < 0) || (*(int *)(param_1 + 0x11e00) <= (int)uVar4)) {
        plVar21 = (long *)0x0;
      }
      else {
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x11df8));
        if ((int)uVar4 < *(int *)(param_1 + 0x11e00)) {
          lVar15 = (ulong)uVar4 * 8;
          puVar19 = (undefined8 *)(*(long *)(param_1 + 0x11e20) + (long)(int)lVar15);
          if (lVar15 - (int)lVar15 != 0) {
            puVar19 = (undefined8 *)
                      (*(long *)(param_1 + 0x11e20) + lVar15 & 0xffffffffffffU | 0x2bad000000000000)
            ;
          }
          plVar21 = (long *)*puVar19;
          if ((plVar21 == (long *)0x0) ||
             (uVar10 = thunk_EXT_FUN_801100000294991c(plVar21), (uVar10 & 1) == 0))
          goto LAB_fffffff00817c1c8;
        }
        else {
LAB_fffffff00817c1c8:
          plVar21 = (long *)0x0;
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x11df8));
      }
      uVar12 = thunk_EXT_FUN_801100000296c9a8(plVar21);
      plVar11 = (long *)thunk_EXT_FUN_8011000003890f30(uVar12,&DAT_fffffff00ae23c90);
      if (plVar21 != (long *)0x0) {
        (**(code **)(*plVar21 + 0x28))(plVar21);
      }
      if (plVar11 == (long *)0x0) {
        uStack_88 = 0;
        uStack_90 = 0;
        uStack_78 = 0;
        uStack_80 = 0;
        uStack_94 = 0;
        uStack_a0 = 0;
        uStack_b0 = 0x26;
        uStack_ac = (undefined4)*(undefined8 *)(piVar2 + 4);
        uStack_a8 = (undefined4)((ulong)*(undefined8 *)(piVar2 + 4) >> 0x20);
        uStack_a4 = 0;
        uStack_9c = (undefined4)*(undefined8 *)(piVar2 + 6);
        uStack_98 = (undefined4)((ulong)*(undefined8 *)(piVar2 + 6) >> 0x20);
        lVar15 = *(long *)(param_1 + 0x4b0);
        auStack_6c[0] = 9;
        uVar12 = (**(code **)(*(long *)(lVar15 + 0x848) + 0x30))(lVar15 + 0x848);
        uStack_70 = 0;
        plVar21 = *(long **)(*(long *)(lVar15 + 0x280) + 0x310);
        puVar19 = (undefined8 *)(*plVar21 + 0xe8);
        iVar8 = (*(code *)*puVar19)(puVar19,plVar21,FUN_fffffff00817ea94,&uStack_b0,auStack_6c,
                                    &uStack_70,0);
        if ((iVar8 == 0) && (((byte)auStack_6c[0] >> 1 & 1) != 0)) {
          FUN_fffffff0081a43cc(lVar15,uVar12,uStack_70);
        }
        goto LAB_fffffff00817c098;
      }
      lVar22 = plVar11[0x3e];
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar22 + 0x50));
      iVar8 = piVar2[3];
      lVar15 = *(long *)(lVar22 + 0x28);
      if ((*(byte *)(lVar15 + 0x1ac44) >> 3 & 1) != 0) {
        puVar13 = *(undefined4 **)(lVar22 + 0x1370);
        uVar24 = *puVar13;
        uVar3 = puVar13[1];
        uVar5 = puVar13[2];
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar15 + 0x1ac48));
        thunk_EXT_FUN_80110000036da494(0x85930cf5,iVar8,uVar24,uVar3,uVar5,0);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar15 + 0x1ac48));
      }
      if (iVar8 != 0) {
        uVar10 = lVar22 + 0x1160;
        uVar7 = (lVar22 + 0x1360U) - uVar10;
        iVar23 = iVar8;
        if ((uVar7 & 0xffffffff00000000) == 0 && uVar10 <= lVar22 + 0x1360U) {
          do {
            puVar16 = *(uint **)(lVar22 + 0x1370);
            uVar4 = puVar16[2];
            if (uVar4 == *puVar16) {
              lVar15 = FUN_fffffff0081e60cc(lVar22);
              if (lVar15 == 0) goto LAB_fffffff00817c654;
            }
            else {
              lVar15 = (ulong)uVar4 * 8;
              if (lVar15 - (int)lVar15 != 0) {
                    /* WARNING: Subroutine does not return */
                FUN_fffffff008214ca8
                          (
                          "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                          );
              }
              if ((((ulong)uVar4 & 0x1fffffff) >> 0x1c != 0) ||
                 (uVar4 = uVar4 * 8, (uint)uVar7 < uVar4 + 8)) {
                    /* WARNING: Subroutine does not return */
                FUN_fffffff008214ca8
                          (
                          "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                          );
              }
              uVar18 = (ulong)CARRY8(uVar10,(ulong)uVar4);
              uVar17 = -uVar18;
              if ((uVar17 != uVar18) || ((long)uVar17 < 0)) {
                    /* WARNING: Subroutine does not return */
                FUN_fffffff008214ca8
                          (
                          "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                          );
              }
              lVar15 = *(long *)(uVar10 + uVar4);
            }
            iVar9 = thunk_EXT_FUN_801100000297b3fc(*(undefined8 *)(lVar15 + 0x58));
            if (iVar9 != 0) goto LAB_fffffff00817c5dc;
            *(int *)(*(long *)(lVar22 + 0x1370) + 8) = *(int *)(*(long *)(lVar22 + 0x1370) + 8) + 1;
            thunk_EXT_FUN_801100000294849c
                      (*(undefined8 *)(*(long *)(lVar22 + 0x28) + 0x148),lVar22 + 0xe0,lVar15 + 0x10
                      );
            *(undefined1 *)(lVar15 + 0x50) = 1;
            *(ulong *)(lVar22 + 0x13a8) =
                 1L << ((ulong)*(uint *)(lVar15 + 0xc) & 0x3f) | *(ulong *)(lVar22 + 0x13a8);
            iVar23 = iVar23 + -1;
          } while (iVar23 != 0);
        }
        else {
          do {
            piVar14 = *(int **)(lVar22 + 0x1370);
            if (piVar14[2] != *piVar14) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff008214ca8
                        (
                        "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                        );
            }
            lVar15 = FUN_fffffff0081e60cc(lVar22);
            if (lVar15 == 0) goto LAB_fffffff00817c654;
            iVar9 = thunk_EXT_FUN_801100000297b3fc(*(undefined8 *)(lVar15 + 0x58));
            if (iVar9 != 0) goto LAB_fffffff00817c5dc;
            *(int *)(*(long *)(lVar22 + 0x1370) + 8) = *(int *)(*(long *)(lVar22 + 0x1370) + 8) + 1;
            thunk_EXT_FUN_801100000294849c
                      (*(undefined8 *)(*(long *)(lVar22 + 0x28) + 0x148),lVar22 + 0xe0,lVar15 + 0x10
                      );
            *(undefined1 *)(lVar15 + 0x50) = 1;
            *(ulong *)(lVar22 + 0x13a8) =
                 1L << ((ulong)*(uint *)(lVar15 + 0xc) & 0x3f) | *(ulong *)(lVar22 + 0x13a8);
            iVar23 = iVar23 + -1;
          } while (iVar23 != 0);
        }
      }
      lVar15 = *(long *)(lVar22 + 0x28);
      if ((*(byte *)(lVar15 + 0x1ac44) >> 3 & 1) != 0) {
        uVar3 = 1;
        goto LAB_fffffff00817c600;
      }
      uVar24 = 1;
      goto LAB_fffffff00817c65c;
    }
    if (*piVar2 != 0) {
      thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Invalid Host alloc Request type %d\n");
      return;
    }
    if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
      iVar8 = piVar2[3];
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930c50,iVar8,0,0,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
    }
    uVar4 = piVar2[2];
    if (((int)uVar4 < 0) || (*(int *)(param_1 + 0x11db8) <= (int)uVar4)) {
LAB_fffffff00817c390:
      plVar21 = (long *)0x0;
    }
    else {
      lVar15 = (ulong)uVar4 * 8;
      plVar21 = (long *)(*(long *)(param_1 + 0x11dc0) + (long)(int)lVar15);
      if (lVar15 - (int)lVar15 != 0) {
        plVar21 = (long *)(*(long *)(param_1 + 0x11dc0) + lVar15 & 0xffffffffffffU |
                          0x2bad000000000000);
      }
      if ((*plVar21 == 0) || (iVar8 = thunk_EXT_FUN_801100000294991c(), iVar8 == 0))
      goto LAB_fffffff00817c390;
      plVar21 = *(long **)(*(long *)(param_1 + 0x11dc0) + (ulong)uVar4 * 8);
    }
    plVar11 = (long *)thunk_EXT_FUN_8011000003890f30(plVar21,&DAT_fffffff00ae23390);
    if ((plVar21 != (long *)0x0) && (plVar11 == (long *)0x0)) {
      (**(code **)(*plVar21 + 0x28))(plVar21);
    }
    plVar21 = (long *)plVar11[0x13];
    thunk_EXT_FUN_80110000032222a8(plVar21[0x24]);
    uVar12 = (**(code **)(*plVar21 + 0xb8))(plVar21);
    thunk_EXT_FUN_8011000003222de0(plVar21[0x24]);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x183a0));
    if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930c54,uVar12,0,0,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
    }
    uStack_88 = 0;
    uStack_90 = 0;
    uStack_78 = 0;
    uStack_80 = 0;
    uStack_ac = (undefined4)uVar12;
    uStack_b0 = 8;
    uStack_a0 = (undefined4)*(undefined8 *)(piVar2 + 4);
    uStack_9c = (undefined4)((ulong)*(undefined8 *)(piVar2 + 4) >> 0x20);
    uStack_a8 = (undefined4)*(undefined8 *)(piVar2 + 2);
    uStack_a4 = (undefined4)((ulong)*(undefined8 *)(piVar2 + 2) >> 0x20);
    uStack_98 = (undefined4)*(undefined8 *)(piVar2 + 6);
    uStack_94 = (undefined4)((ulong)*(undefined8 *)(piVar2 + 6) >> 0x20);
    lVar15 = *(long *)(param_1 + 0x4b0);
    auStack_6c[0] = 0x19;
    uVar12 = (**(code **)(*(long *)(lVar15 + 0x848) + 0x30))(lVar15 + 0x848);
    uStack_70 = 0;
    plVar21 = *(long **)(*(long *)(lVar15 + 0x280) + 0x310);
    puVar19 = (undefined8 *)(*plVar21 + 0xe8);
    iVar8 = (*(code *)*puVar19)(puVar19,plVar21,FUN_fffffff00817ea94,&uStack_b0,auStack_6c,
                                &uStack_70,0);
    if ((iVar8 == 0) && (((byte)auStack_6c[0] >> 1 & 1) != 0)) {
      FUN_fffffff0081a43cc(lVar15,uVar12,uStack_70);
    }
    (**(code **)(*plVar11 + 0x28))(plVar11);
    goto LAB_fffffff00817c098;
  }
  goto LAB_fffffff00817c78c;
LAB_fffffff00817c654:
  uVar24 = 0;
  goto LAB_fffffff00817c65c;
LAB_fffffff00817c5dc:
  uVar24 = 0;
  lVar15 = *(long *)(lVar22 + 0x28);
  uVar3 = 0;
  if ((*(byte *)(lVar15 + 0x1ac44) >> 3 & 1) != 0) {
LAB_fffffff00817c600:
    uVar24 = uVar3;
    puVar13 = *(undefined4 **)(lVar22 + 0x1370);
    uVar3 = *puVar13;
    uVar5 = puVar13[1];
    uVar6 = puVar13[2];
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar15 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930cf6,iVar8,uVar3,uVar5,uVar6,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar15 + 0x1ac48));
  }
LAB_fffffff00817c65c:
  puStack_e8 = (undefined8 *)(param_1 + 0x183a0);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar22 + 0x50));
  thunk_EXT_FUN_8011000003222de0(*puStack_e8);
  uStack_88 = 0;
  uStack_90 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  uStack_94 = 0;
  uStack_a0 = 0;
  uStack_b0 = 0x26;
  uStack_ac = (undefined4)*(undefined8 *)(piVar2 + 4);
  uStack_a8 = (undefined4)((ulong)*(undefined8 *)(piVar2 + 4) >> 0x20);
  uStack_9c = (undefined4)*(undefined8 *)(piVar2 + 6);
  uStack_98 = (undefined4)((ulong)*(undefined8 *)(piVar2 + 6) >> 0x20);
  lVar15 = *(long *)(param_1 + 0x4b0);
  auStack_6c[0] = 9;
  uStack_a4 = uVar24;
  uVar12 = (**(code **)(*(long *)(lVar15 + 0x848) + 0x30))(lVar15 + 0x848);
  uStack_70 = 0;
  plVar21 = *(long **)(*(long *)(lVar15 + 0x280) + 0x310);
  puVar19 = (undefined8 *)(*plVar21 + 0xe8);
  iVar8 = (*(code *)*puVar19)(puVar19,plVar21,FUN_fffffff00817ea94,&uStack_b0,auStack_6c,&uStack_70,
                              0);
  if ((iVar8 == 0) && (((byte)auStack_6c[0] >> 1 & 1) != 0)) {
    FUN_fffffff0081a43cc(lVar15,uVar12,uStack_70);
  }
  (**(code **)(*plVar11 + 0x28))(plVar11);
LAB_fffffff00817c098:
  iVar20 = iVar20 + 1;
  if (iVar20 == param_3) goto LAB_fffffff00817c760;
  goto LAB_fffffff00817c0a4;
}

