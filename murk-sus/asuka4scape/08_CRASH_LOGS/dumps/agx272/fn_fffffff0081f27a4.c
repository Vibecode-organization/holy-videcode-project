// FUN_fffffff0081f27a4 @ fffffff0081f27a4 size=1172

undefined8 FUN_fffffff0081f27a4(long *param_1,long param_2,int *param_3)

{
  int *piVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  long *plVar7;
  ulong uVar8;
  int *piVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  long lVar16;
  int *piVar17;
  long lVar18;
  uint *puVar19;
  ulong uVar20;
  int iVar21;
  ulong uVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  undefined8 uVar26;
  
  iVar5 = *(int *)(param_2 + 0x3d0);
  iVar23 = *(int *)(param_2 + 0x3f4);
  param_3[2] = *(int *)(param_2 + 0x3ec);
  param_3[3] = iVar23;
  uVar4 = 0;
  if (*(uint *)(param_2 + 0x414) != 0) {
    uVar4 = *(uint *)(param_2 + 0x3e0) / *(uint *)(param_2 + 0x414);
  }
  *param_3 = iVar5;
  param_3[1] = uVar4;
  uVar26 = NEON_rev64(*(undefined8 *)(param_2 + 0x418),4);
  *(undefined8 *)(param_3 + 5) = uVar26;
  uVar4 = iVar5 - 1;
  if (uVar4 < 0x1a) {
    lVar12 = (ulong)uVar4 * 4;
    piVar17 = (int *)(&DAT_fffffff0071150d0 + (int)lVar12);
    if (lVar12 != (int)lVar12) {
      piVar17 = (int *)((ulong)(&DAT_fffffff0071150d0 + lVar12) & 0xffffffffffff |
                       0x2bad000000000000);
    }
    param_3[4] = *piVar17;
    iVar5 = FUN_fffffff0081f0bac();
    if (iVar5 != 0) {
      lVar12 = param_1[3];
      uVar14 = (ulong)*(uint *)(lVar12 + 0x48);
      if (*(uint *)(lVar12 + 0x48) != 0) {
        lVar16 = 0;
        lVar18 = *(long *)(lVar12 + 0x40);
        do {
          puVar19 = *(uint **)(lVar18 + lVar16 * 8);
          if ((puVar19[4] != 0) && (uVar4 = *puVar19, (uVar4 & 0x3f000000) != 0)) {
            if ((uVar4 >> 0x18 & 1) == 0) {
              iVar5 = 0;
              if ((uVar4 >> 0x19 & 1) != 0) goto LAB_fffffff0081f28a0;
LAB_fffffff0081f28cc:
              iVar23 = 0;
              if ((uVar4 >> 0x1a & 1) == 0) goto LAB_fffffff0081f28d4;
LAB_fffffff0081f28a8:
              iVar24 = *(int *)(lVar12 + 0xc);
              if ((uVar4 >> 0x1b & 1) != 0) goto LAB_fffffff0081f28b0;
LAB_fffffff0081f28dc:
              iVar25 = 0;
              if ((uVar4 >> 0x1c & 1) == 0) goto LAB_fffffff0081f28e4;
LAB_fffffff0081f28b8:
              iVar6 = *(int *)(lVar12 + 0x18);
              if ((uVar4 >> 0x1d & 1) == 0) goto LAB_fffffff0081f28ec;
LAB_fffffff0081f2854:
              iVar21 = *(int *)(lVar12 + 0x14);
            }
            else {
              iVar5 = *(int *)(lVar12 + 4);
              if ((uVar4 >> 0x19 & 1) == 0) goto LAB_fffffff0081f28cc;
LAB_fffffff0081f28a0:
              iVar23 = *(int *)(lVar12 + 8);
              if ((uVar4 >> 0x1a & 1) != 0) goto LAB_fffffff0081f28a8;
LAB_fffffff0081f28d4:
              iVar24 = 0;
              if ((uVar4 >> 0x1b & 1) == 0) goto LAB_fffffff0081f28dc;
LAB_fffffff0081f28b0:
              iVar25 = *(int *)(lVar12 + 0x10);
              if ((uVar4 >> 0x1c & 1) != 0) goto LAB_fffffff0081f28b8;
LAB_fffffff0081f28e4:
              iVar6 = 0;
              if ((uVar4 >> 0x1d & 1) != 0) goto LAB_fffffff0081f2854;
LAB_fffffff0081f28ec:
              iVar21 = 0;
            }
            *puVar19 = iVar21 + iVar6 + iVar25 + iVar24 + iVar23 + iVar5;
          }
          lVar16 = lVar16 + 1;
          uVar14 = uVar14 - 1;
        } while (uVar14 != 0);
      }
      uVar4 = *(uint *)(lVar12 + 0x78);
      if (uVar4 != 0) {
        *(uint *)(param_1 + 9) = uVar4;
        lVar12 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4a08,(ulong)uVar4 * 0x68);
        lVar16 = param_1[7];
        uVar3 = *(uint *)(param_1 + 8);
        param_1[7] = lVar12;
        *(uint *)(param_1 + 8) = uVar4;
        if (lVar16 != 0) {
          thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4a08,lVar16,(ulong)uVar3 * 0x68);
        }
        uVar4 = *(uint *)(param_1[3] + 0x78);
        uVar14 = (ulong)uVar4;
        if (uVar4 != 0) {
          piVar17 = (int *)(param_2 + 0x3e0);
          piVar1 = (int *)(param_2 + 0x414);
          uVar13 = *(ulong *)(param_1[3] + 0x70);
          uVar20 = param_1[7];
          if (uVar20 == 0) {
            if ((*(int *)(uVar13 + 0x18) == 0x2000000) ||
               (piVar17 = piVar1, *(int *)(uVar13 + 0x18) == 0x1000000)) {
              *(int *)(uVar13 + 0x18) = *piVar17;
            }
            *(undefined4 *)(uVar13 + 0x1c) = 0;
LAB_fffffff0081f2c2c:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff008214ca8
                      (
                      "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                      );
          }
          uVar22 = uVar20 + (ulong)*(uint *)(param_1 + 8) * 0x68;
          if (((uVar20 ^ uVar22) & 0xffc0000000000000) != 0) {
            uVar22 = uVar22 & 0xffffffffffff | 0xc8a2000000000000;
          }
          if ((uVar22 < uVar20) || (uVar22 - uVar20 >> 0x20 != 0)) {
            if ((*(int *)(uVar13 + 0x18) == 0x2000000) ||
               (piVar17 = piVar1, *(int *)(uVar13 + 0x18) == 0x1000000)) {
              *(int *)(uVar13 + 0x18) = *piVar17;
            }
            *(undefined4 *)(uVar13 + 0x1c) = 0;
LAB_fffffff0081f2bf4:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff008214ca8
                      (
                      "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                      );
          }
          lVar12 = 0;
          iVar5 = 0;
          lVar16 = 0x13b13b2;
          uVar15 = 0;
          do {
            uVar8 = uVar13 + lVar12 * 0xe0;
            if (((uVar13 ^ uVar8) & 0xffc0000000000000) != 0) {
              uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
            }
            iVar23 = *(int *)(uVar8 + 0x18);
            piVar9 = piVar1;
            if ((iVar23 == 0x1000000) || (piVar9 = piVar17, iVar23 == 0x2000000)) {
              iVar23 = *piVar9;
              *(int *)(uVar8 + 0x18) = iVar23;
            }
            *(int *)(uVar8 + 0x1c) = iVar5;
            if (lVar16 == 0) goto LAB_fffffff0081f2bb0;
            if (((long)uVar15 < 0) || ((uint)(uVar22 - uVar20) < (int)(uVar15 >> 0x20) + 0x68U))
            goto LAB_fffffff0081f2c2c;
            uVar11 = (ulong)CARRY8(uVar20,uVar15 >> 0x20);
            uVar10 = -uVar11;
            if ((uVar10 != uVar11) || ((long)uVar10 < 0)) goto LAB_fffffff0081f2bbc;
            iVar5 = iVar23 + iVar5;
            *(ulong *)(uVar20 + (uVar15 >> 0x20)) = uVar8;
            lVar12 = lVar12 + 1;
            lVar16 = lVar16 + -1;
            uVar15 = uVar15 + 0x6800000000;
            uVar14 = uVar14 - 1;
          } while (uVar14 != 0);
        }
        if ((int)param_1[9] == 0) {
          return 1;
        }
        uVar20 = 0;
        uVar14 = 0;
        uVar13 = 0xffffffff80000000;
        do {
          iVar5 = FUN_fffffff0081f1f88(param_1,uVar14);
          if (iVar5 != 0) {
            uVar22 = param_1[7];
            if (uVar22 == 0) {
              uVar15 = 0;
            }
            else {
              uVar8 = uVar22 + (ulong)*(uint *)(param_1 + 8) * 0x68;
              if (((uVar22 ^ uVar8) & 0xffc0000000000000) != 0) {
                uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
              }
              uVar15 = uVar8 - uVar22;
              if ((uVar8 < uVar22) || (uVar15 >> 0x20 != 0)) goto LAB_fffffff0081f2bf4;
            }
            if (uVar13 < 0xffffffff00000000) {
LAB_fffffff0081f2bb0:
                    /* WARNING: Subroutine does not return */
              FUN_fffffff008214ca8
                        (
                        "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                        );
            }
            if (((long)uVar20 < 0) || ((uint)uVar15 < (int)(uVar20 >> 0x20) + 0x68U))
            goto LAB_fffffff0081f2c2c;
            puVar2 = (undefined8 *)(uVar22 + (uVar20 >> 0x20));
            uVar15 = (ulong)CARRY8(uVar22,uVar20 >> 0x20);
            uVar22 = -uVar15;
            if ((uVar22 != uVar15) || ((long)uVar22 < 0)) {
LAB_fffffff0081f2bbc:
                    /* WARNING: Subroutine does not return */
              FUN_fffffff008214ca8
                        (
                        "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                        );
            }
            plVar7 = (long *)(**(code **)(*param_1 + 0x120))(param_1,*puVar2);
            *(undefined4 *)(puVar2 + 1) = 1;
            puVar2[0xc] = plVar7;
            (**(code **)(*plVar7 + 0x10))(plVar7,param_3,0,uVar14);
            (**(code **)(*plVar7 + 0x18))(plVar7);
          }
          uVar14 = uVar14 + 1;
          uVar20 = uVar20 + 0x6800000000;
          uVar13 = uVar13 + 0x68;
        } while (uVar14 < *(uint *)(param_1 + 9));
      }
      return 1;
    }
  }
  return 0;
}

