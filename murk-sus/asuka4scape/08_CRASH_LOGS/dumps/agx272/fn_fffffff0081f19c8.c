// FUN_fffffff0081f19c8 @ fffffff0081f19c8 size=4

undefined8 FUN_fffffff0081f19c8(long param_1)

{
  long lVar1;
  long *plVar2;
  undefined4 *puVar3;
  ulong *puVar4;
  byte *pbVar5;
  bool bVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  ulong uVar10;
  undefined8 uVar11;
  uint uVar12;
  long lVar13;
  ulong uVar14;
  long lVar15;
  long lVar16;
  ulong uVar17;
  ulong uVar18;
  long lVar19;
  ulong uVar20;
  uint uVar21;
  long lVar22;
  byte bVar23;
  ulong uVar24;
  long *plVar25;
  undefined1 uVar26;
  undefined8 uStack_78;
  long lStack_70;
  undefined8 uStack_68;
  
  lVar13 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0x4b0) + 0x910);
  lVar1 = lVar13 + 0x18;
  thunk_EXT_FUN_8011000003a61cc0(lVar1,0x4000);
  *(undefined4 *)(lVar13 + 0x4018) = 0;
  if (*(int *)(param_1 + 0x48) != 0) {
    uVar24 = 0;
    do {
      iVar7 = FUN_fffffff0081f1f88(param_1,uVar24);
      if (iVar7 != 0) {
        uVar14 = *(ulong *)(param_1 + 0x38);
        if (uVar14 == 0) {
          uVar17 = 0;
        }
        else {
          uVar18 = uVar14 + (ulong)*(uint *)(param_1 + 0x40) * 0x68;
          if (((uVar14 ^ uVar18) & 0xffc0000000000000) != 0) {
            uVar18 = uVar18 & 0xffffffffffff | 0xc8a2000000000000;
          }
          uVar17 = uVar18 - uVar14;
          if ((uVar18 < uVar14) || (uVar17 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff008214ca8
                      (
                      "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                      );
          }
        }
        if (uVar24 * 0x68 - (long)(int)(uVar24 * 0x68) != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                    );
        }
        uVar18 = uVar24 * 0x6800000000;
        if (((long)uVar18 < 0) || ((uint)uVar17 < (int)(uVar18 >> 0x20) + 0x68U)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                    );
        }
        plVar2 = (long *)(uVar14 + (uVar18 >> 0x20));
        uVar17 = (ulong)CARRY8(uVar14,uVar18 >> 0x20);
        uVar14 = -uVar17;
        if ((uVar14 != uVar17) || ((long)uVar14 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                    );
        }
        uVar14 = *(ulong *)(param_1 + 0x70) + uVar24 * 0x538;
        if (((*(ulong *)(param_1 + 0x70) ^ uVar14) & 0xffc0000000000000) != 0) {
          uVar14 = uVar14 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((*(byte *)(*plVar2 + 4) & 0x5f) != 0) {
          plVar25 = (long *)plVar2[0xc];
          (**(code **)(*plVar25 + 0x48))(plVar25,*(undefined4 *)((long)plVar2 + 0xc));
          lVar15 = (ulong)*(uint *)(lVar13 + 0x4018) * 0x20;
          uVar17 = lVar1 + (int)lVar15;
          if (lVar15 - (int)lVar15 != 0) {
            uVar17 = lVar1 + lVar15 & 0xffffffffffffU | 0x2bad000000000000;
          }
          uStack_78 = uStack_78 & 0xffffffff00000000;
          uVar17 = (**(code **)(*plVar25 + 0x38))
                             (plVar25,uVar17,0x200 - *(int *)(lVar13 + 0x4018),&uStack_78);
          if ((uVar17 & 1) == 0) goto LAB_fffffff0081f1f34;
          *(int *)(lVar13 + 0x4018) = *(int *)(lVar13 + 0x4018) + (int)uStack_78;
          lVar15 = *plVar2;
          if ((*(uint *)(lVar15 + 4) & 0x5e) == 0) {
            if ((*(uint *)(lVar15 + 4) & 1) != 0) {
              thunk_EXT_FUN_8011000003a61cc0(uVar14 + 0x110,0x400);
              iVar7 = (**(code **)(*plVar25 + 0x28))(plVar25);
              goto LAB_fffffff0081f1e98;
            }
          }
          else {
            lVar19 = uVar14 + 0x110;
            thunk_EXT_FUN_8011000003a61cc0(lVar19,0x400);
            uVar12 = *(uint *)(lVar15 + 0xd8);
            if (*(char *)((long)plVar2 + 0xc) < '\0') {
              uVar12 = *(int *)(lVar15 + 0xdc) + uVar12;
            }
            lVar22 = (ulong)uVar12 * 4;
            thunk_EXT_FUN_8011000003a61b10(lVar19,*(undefined8 *)(lVar15 + 0xd0),lVar22);
            uStack_78 = 0;
            lStack_70 = 0;
            uStack_68 = 0;
            lVar16 = (ulong)*(byte *)(*(long *)(param_1 + 0x18) + 0x4c) * 4;
            puVar3 = (undefined4 *)(lVar19 + (int)lVar16);
            if (lVar16 - (int)lVar16 != 0) {
              puVar3 = (undefined4 *)(lVar19 + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
            }
            (**(code **)(*(long *)(param_1 + 0x18) + 0x68))(*puVar3,&uStack_78);
            uStack_78 = CONCAT44(uStack_78._4_4_,*(undefined4 *)(lVar15 + 0x70));
            uVar8 = (**(code **)(*(long *)(param_1 + 0x18) + 0x60))(&uStack_78);
            lVar15 = (ulong)*(byte *)(*(long *)(param_1 + 0x18) + 0x4c) * 4;
            puVar3 = (undefined4 *)(lVar19 + (int)lVar15);
            if (lVar15 - (int)lVar15 != 0) {
              puVar3 = (undefined4 *)(lVar19 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar3 = uVar8;
            if (uVar12 == 0x100) goto LAB_fffffff0081f1f34;
            uVar17 = lVar19 + (int)lVar22;
            if (lVar22 != (int)lVar22) {
              uVar17 = lVar19 + lVar22 & 0xffffffffffffU | 0x2bad000000000000;
            }
            if ((int)plVar25[0x2a3] == 0) {
              uVar18 = 0;
            }
            else {
              uVar18 = 0;
              do {
                iVar7 = (int)(uVar18 * 0x18);
                puVar4 = (ulong *)((long)plVar25 + (long)iVar7 + 0x18);
                if (uVar18 * 0x18 - (long)iVar7 != 0) {
                  puVar4 = (ulong *)((ulong)(plVar25 + uVar18 * 3 + 3) & 0xffffffffffff |
                                    0x2bad000000000000);
                }
                lVar15 = plVar25[1];
                bVar23 = (byte)puVar4[1];
                lVar19 = *(long *)(*(long *)(lVar15 + 0x40) + (ulong)bVar23 * 8);
                uStack_78 = 0;
                lStack_70 = 0;
                uStack_68 = 0;
                if ((*(byte *)((long)plVar25 + 0x1524) >> 6 & 1) == 0) {
                  uVar26 = 0x40;
                  if (1 < bVar23) goto LAB_fffffff0081f1d48;
LAB_fffffff0081f1d7c:
                  uVar10 = *puVar4;
                  uVar20 = uVar10 >> 0x3c;
                  if (uVar20 != 4) {
                    if (uVar20 == 0 || (uVar10 & 0xd000000000000000) == 0x1000000000000000) {
                      uVar21 = (uint)uVar10 & 0xfffff;
                      bVar6 = uVar20 == 3 || uVar20 == 1;
                      bVar23 = (byte)(uint)(uVar10 >> 0x2c) & 0xf;
                      if (uVar20 != 3) {
                        bVar23 = 0;
                      }
                      goto LAB_fffffff0081f1dc0;
                    }
                    goto LAB_fffffff0081f1f34;
                  }
                  (**(code **)(lVar15 + 0x68))(uVar10,&uStack_78);
                  uStack_78._0_5_ = CONCAT14(uVar26,(int)uStack_78);
                  lVar15 = plVar25[1];
                }
                else {
                  uVar26 = *(undefined1 *)((long)puVar4 + 0xb);
                  if (bVar23 < 2) goto LAB_fffffff0081f1d7c;
LAB_fffffff0081f1d48:
                  lVar22 = *(long *)(lVar19 + 0x18);
                  uVar21 = 0;
                  if (lVar22 != 0) {
                    uVar21 = *(uint *)(lVar22 + (ulong)*(byte *)((long)puVar4 + 9) * 8 + 4);
                  }
                  bVar23 = 0;
                  bVar6 = *(int *)(lVar19 + 0x10) != 0;
LAB_fffffff0081f1dc0:
                  uStack_78._0_5_ = CONCAT14(uVar26,uVar21);
                  uVar26 = 3;
                  if ((puVar4[2] & 0x20) != 0) {
                    uVar26 = 0;
                  }
                  lStack_70 = (ulong)CONCAT11(uVar26,bVar6) << 8;
                  uStack_78 = (ulong)CONCAT15(bVar23,(undefined5)uStack_78);
                }
                uVar8 = (**(code **)(lVar15 + 0x60))(&uStack_78);
                lVar15 = uVar18 * 4;
                puVar3 = (undefined4 *)(uVar17 + (long)(int)lVar15);
                if (lVar15 - (int)lVar15 != 0) {
                  puVar3 = (undefined4 *)(uVar17 + lVar15 & 0xffffffffffff | 0x2bad000000000000);
                }
                *puVar3 = uVar8;
                uVar18 = uVar18 + 1;
              } while (uVar18 < *(uint *)(plVar25 + 0x2a3));
            }
            iVar7 = (int)uVar18;
            if ((*(byte *)((long)plVar25 + 0x1524) & 1) != 0) {
              lVar15 = (uVar18 & 0xffffffff) * 4;
              uVar18 = uVar17 + (long)(int)lVar15;
              if (lVar15 != (int)lVar15) {
                uVar18 = uVar17 + lVar15 & 0xffffffffffff | 0x2bad000000000000;
              }
              iVar9 = (**(code **)(*plVar25 + 0x40))(plVar25,uVar18,0x100 - (uVar12 + iVar7));
              iVar7 = iVar9 + iVar7;
            }
            iVar7 = iVar7 + uVar12;
LAB_fffffff0081f1e98:
            *(int *)(uVar14 + 0x510) = iVar7;
          }
          *(int *)(uVar14 + 0xe4) = (int)plVar2[1];
          *(undefined4 *)(uVar14 + 0xe8) = *(undefined4 *)((long)plVar2 + 0xc);
          *(int *)(uVar14 + 0xec) = (int)plVar2[2];
          *(undefined1 *)(uVar14 + 0xf0) = *(undefined1 *)((long)plVar2 + 0x14);
          uVar12 = *(uint *)(plVar2[0xc] + 0x1518);
          uVar17 = (ulong)uVar12;
          if (uVar12 == 0) {
            uVar12 = 0;
          }
          else {
            lVar19 = 0;
            lVar15 = plVar2[0xc] + 0x18;
            do {
              uVar17 = uVar17 - 1;
              lVar22 = lVar19 * 0x18 + 8;
              pbVar5 = (byte *)(lVar15 + (int)lVar22);
              if (lVar22 != (int)lVar22) {
                pbVar5 = (byte *)(lVar15 + lVar22 & 0xffffffffffffU | 0x2bad000000000000);
              }
              lVar19 = lVar19 + 1;
            } while (*pbVar5 < 2 && uVar17 != 0);
            uVar12 = (uint)(1 < *pbVar5);
          }
          *(uint *)(uVar14 + 0xf4) = uVar12;
        }
      }
      uVar24 = uVar24 + 1;
    } while (uVar24 < *(uint *)(param_1 + 0x48));
  }
  iVar7 = *(int *)(param_1 + 0x4c);
  if (iVar7 == -1) {
LAB_fffffff0081f1f34:
    uVar11 = 0;
  }
  else {
    *(char *)(lVar13 + 0x407a) = (char)*(undefined4 *)(param_1 + 0x50);
    *(short *)(lVar13 + 0x4078) = (short)iVar7;
    uVar11 = 1;
  }
  return uVar11;
}

