// FUN_fffffff0081ef0f4 @ fffffff0081ef0f4 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0081ef51c) */

undefined8 FUN_fffffff0081ef0f4(long *param_1,undefined8 *param_2)

{
  long *plVar1;
  long lVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  undefined8 uVar8;
  long *plVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  int iVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  long *plVar18;
  undefined8 uVar19;
  long lVar20;
  
  bVar3 = *(byte *)((long)param_2 + 4);
  if (*(uint *)(param_1 + 9) <= (uint)bVar3) {
    return 0;
  }
  uVar10 = param_1[7];
  if (uVar10 != 0) {
    uVar12 = uVar10 + (ulong)*(uint *)(param_1 + 8) * 0x68;
    if (((uVar10 ^ uVar12) & 0xffc0000000000000) != 0) {
      uVar12 = uVar12 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar12 < uVar10) || (uVar12 - uVar10 >> 0x20 != 0)) {
LAB_fffffff0081ef570:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                );
    }
    uVar4 = (uint)bVar3 * 0x68;
    uVar16 = (ulong)uVar4;
    uVar4 = uVar4 + 0x68;
    if (uVar4 <= (uint)(uVar12 - uVar10)) {
      plVar1 = (long *)(uVar10 + uVar16);
      uVar12 = -(ulong)CARRY8(uVar10,uVar16);
      if ((uVar12 != CARRY8(uVar10,uVar16)) || ((long)uVar12 < 0)) {
LAB_fffffff0081ef57c:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                  );
      }
      lVar11 = *plVar1;
      iVar14 = *(int *)(lVar11 + 0x18);
      if (iVar14 != 0) {
        lVar2 = param_1[0xe] + (ulong)(uint)bVar3 * 0x538;
        lVar15 = (ulong)*(uint *)(lVar11 + 0x1c) * 0x38;
        uVar10 = param_1[0x10] + (long)(int)lVar15;
        if (lVar15 != (int)lVar15) {
          uVar10 = param_1[0x10] + lVar15 & 0xffffffffffffU | 0x2bad000000000000;
        }
        plVar18 = (long *)param_2[1];
        uVar12 = param_2[2];
        if (plVar18 == (long *)0x0) {
          if (uVar12 == 0) {
            uVar6 = (**(code **)(*param_1 + 0xa0))();
            if ((uVar6 & 1) == 0) {
              uVar12 = param_1[7];
              if (uVar12 == 0) goto LAB_fffffff0081ef588;
              uVar13 = uVar12 + (ulong)*(uint *)(param_1 + 8) * 0x68;
              if (((uVar12 ^ uVar13) & 0xffc0000000000000) != 0) {
                uVar13 = uVar13 & 0xffffffffffff | 0xc8a2000000000000;
              }
              if ((uVar13 < uVar12) || (uVar13 - uVar12 >> 0x20 != 0)) goto LAB_fffffff0081ef570;
              if ((uint)(uVar13 - uVar12) < uVar4) goto LAB_fffffff0081ef588;
              uVar13 = -(ulong)CARRY8(uVar12,uVar16);
              if ((uVar13 != CARRY8(uVar12,uVar16)) || ((long)uVar13 < 0))
              goto LAB_fffffff0081ef57c;
            }
            if (plVar1[9] != 0) {
              thunk_EXT_FUN_8011000003a61cc0(uVar10,(ulong)*(uint *)(*plVar1 + 0x18) * 0x38);
              thunk_EXT_FUN_8011000003a61cc0(lVar2 + 0xe0,0x458);
              thunk_EXT_FUN_801100000297b408(plVar1[9]);
              plVar1[9] = 0;
              plVar1[10] = 0;
              thunk_EXT_FUN_801100000297b408(plVar1[0xb]);
              if ((long *)plVar1[0xb] != (long *)0x0) {
                (**(code **)(*(long *)plVar1[0xb] + 0x28))();
              }
              plVar1[0xb] = 0;
              DataMemoryBarrier(2,3);
            }
            if (uVar6 != 0) {
              lVar15 = 0;
              iVar14 = 0;
              lVar11 = 0;
LAB_fffffff0081ef354:
              *param_2 = 0;
              param_2[1] = lVar15;
              *(int *)(param_2 + 2) = iVar14;
              *(undefined4 *)((long)param_2 + 0x14) = 0;
              param_2[3] = lVar11;
              param_2[5] = 0;
              param_2[4] = 0;
              param_2[7] = 0;
              param_2[6] = 0;
              param_2[8] = 0;
              return 1;
            }
          }
        }
        else {
          if (uVar12 == 0) {
            return 0;
          }
          if ((uVar12 & 0x3fff) != 0) {
            return 0;
          }
          if (plVar1[9] == 0) {
            lVar20 = plVar18[3];
            uVar4 = *(uint *)(lVar11 + 4);
            iVar5 = thunk_EXT_FUN_801100000297b3fc(plVar18);
            if (iVar5 == 0) {
              lVar15 = (param_2[2] & 0xffffffffffffc000) - 0x4000;
              lVar11 = (**(code **)(*plVar18 + 0x98))(plVar18);
              lVar7 = lVar11;
              if ((uVar4 & 1) != 0) {
                lVar7 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x208))
                                  (*(long **)(param_1[2] + 0x4b0),lVar11,0);
                lVar11 = 0;
              }
              uVar8 = thunk_EXT_FUN_801100000297dcf4(lVar20);
              uVar10 = (**(code **)(*param_1 + 0x118))
                                 (param_1,bVar3,uVar10,uVar8,lVar7,lVar15,iVar14,0,lVar15);
              if ((uVar10 & 1) != 0) {
                lVar17 = param_1[4];
                uVar8 = *(undefined8 *)(lVar17 + 0x50);
                uVar19 = *(undefined8 *)(param_1[2] + 0x11da0);
                lVar20 = thunk_EXT_FUN_801100000297dcf4(lVar20);
                plVar9 = (long *)FUN_fffffff008200e48
                                           (lVar17,uVar8,uVar19,lVar20 + lVar15,0x4000,0x800000007);
                if (plVar9 != (long *)0x0) {
                  iVar5 = thunk_EXT_FUN_801100000297b3fc();
                  if (iVar5 == 0) {
                    lVar20 = param_2[2];
                    plVar1[9] = (long)plVar18;
                    plVar1[10] = lVar20;
                    plVar1[0xb] = (long)plVar9;
                    *(long *)(lVar2 + 0x520) = lVar7;
                    *(long *)(lVar2 + 0x518) = lVar20;
                    *(long *)(lVar2 + 0x528) = lVar7 + lVar15;
                    plVar18 = *(long **)(param_1[2] + 0x4b0);
                    uVar8 = (**(code **)(*plVar9 + 0x98))(plVar9);
                    lVar20 = *plVar18;
                    uVar8 = (**(code **)(lVar20 + 0x208))(lVar20 + 0x208,plVar18,uVar8,0);
                    *(undefined8 *)(lVar2 + 0x530) = uVar8;
                    thunk_EXT_FUN_801100000297d510(*(undefined8 *)(param_1[0xd] + 0x48));
                    thunk_EXT_FUN_801100000297d510(*(undefined8 *)(plVar1[9] + 0x18));
                    thunk_EXT_FUN_801100000297d510(*(undefined8 *)(plVar1[0xb] + 0x18));
                    DataMemoryBarrier(2,3);
                    goto LAB_fffffff0081ef354;
                  }
                  (**(code **)(*plVar9 + 0x28))(plVar9);
                }
              }
              thunk_EXT_FUN_801100000297b408(plVar18);
            }
          }
        }
      }
      return 0;
    }
  }
LAB_fffffff0081ef588:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff008214ca8
            (
            "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
            );
}

