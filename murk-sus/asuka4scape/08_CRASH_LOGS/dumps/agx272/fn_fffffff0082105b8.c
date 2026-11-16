// FUN_fffffff0082105b8 @ fffffff0082105b8 size=2388

void FUN_fffffff0082105b8(long *param_1,long *param_2,ulong param_3,ulong param_4,uint param_5)

{
  uint uVar1;
  int *piVar2;
  long *plVar3;
  long *plVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  uint uVar7;
  undefined *puVar8;
  bool bVar9;
  int iVar10;
  int iVar11;
  undefined8 uVar12;
  ulong uVar13;
  long *plVar14;
  long lVar15;
  ulong uVar16;
  ulong uVar17;
  long lVar18;
  ulong uVar19;
  long lVar20;
  uint uVar21;
  ulong uVar22;
  ulong uVar23;
  long lVar24;
  ulong uVar25;
  ulong uVar26;
  int iVar27;
  ulong uVar28;
  long lVar29;
  ulong uVar30;
  long lVar31;
  long local_98;
  long local_80;
  long local_68;
  
  FUN_fffffff00820f890();
  thunk_EXT_FUN_80110000032222a8(param_1[0x17]);
  uVar17 = param_3 >> 0x24 & 7;
  uVar16 = (param_3 + param_4) - 1;
  uVar22 = uVar16 >> 0x24 & 7;
  if (uVar17 <= uVar22) {
    uVar25 = param_3 >> 0x27 & 1;
    uVar28 = uVar17;
    do {
      lVar29 = uVar28 * 8;
      iVar27 = (int)lVar29;
      puVar6 = (undefined8 *)(param_1[uVar25 * 8 + 7] + (long)iVar27);
      if (lVar29 - iVar27 != 0) {
        puVar6 = (undefined8 *)
                 (param_1[uVar25 * 8 + 7] + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
      }
      iVar10 = (**(code **)(*param_1 + 0x78))(param_1,*puVar6);
      if (iVar10 == 0) {
        uVar21 = 1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f);
        plVar14 = (long *)thunk_EXT_FUN_8011000003962c64
                                    (*(uint *)((long)param_1 + 0xb4) | 3,
                                     (long)(int)(uVar21 & 0xfffffff8),(long)(int)uVar21);
        if (plVar14 == (long *)0x0) goto LAB_fffffff008210ee4;
        lVar31 = (**(code **)(*plVar14 + 0x148))();
        uVar21 = *(uint *)PTR_DAT_fffffff007ca5f88;
        if (2 < uVar21) {
          uVar30 = (ulong)(long)(1 << (ulong)(uVar21 & 0x1f)) >> 3;
          if (uVar21 < 8) {
LAB_fffffff008210980:
            uVar26 = 0;
            uVar21 = 0;
          }
          else {
            uVar26 = 0;
            if (uVar30 != 0) {
              uVar26 = uVar30 - 1;
            }
            if ((int)uVar26 == -1 || uVar26 >> 0x20 != 0) goto LAB_fffffff008210980;
            lVar18 = 0;
            uVar26 = uVar30 & 0x1ffffffffffffffc;
            uVar13 = uVar26;
            do {
              lVar15 = lVar18 * 8;
              puVar6 = (undefined8 *)(lVar31 + (int)lVar15);
              if (lVar15 - (int)lVar15 != 0) {
                puVar6 = (undefined8 *)(lVar31 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
              }
              puVar6[1] = 0;
              *puVar6 = 0;
              puVar6[3] = 0;
              puVar6[2] = 0;
              lVar18 = lVar18 + 4;
              uVar13 = uVar13 - 4;
            } while (uVar13 != 0);
            uVar21 = (uint)uVar26;
            if (uVar30 == uVar26) goto LAB_fffffff0082109b8;
          }
          do {
            uVar21 = uVar21 + 1;
            lVar18 = uVar26 * 8;
            puVar6 = (undefined8 *)(lVar31 + (int)lVar18);
            if (lVar18 - (int)lVar18 != 0) {
              puVar6 = (undefined8 *)(lVar31 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar6 = 0;
            uVar26 = (ulong)uVar21;
          } while (uVar26 < uVar30);
        }
LAB_fffffff0082109b8:
        iVar10 = (**(code **)(*plVar14 + 0xd8))(plVar14,3);
        if (iVar10 != 0) {
LAB_fffffff008210ee4:
          thunk_EXT_FUN_8011000003a49114
                    (
                    "AGXk: %s:%d:%s: !!! Unable to create page directory or page table descriptor\n"
                    );
          return;
        }
        lVar18 = param_1[uVar25 * 8 + 8];
        plVar3 = (long *)(param_1[uVar25 * 8 + 9] + (long)iVar27);
        if (lVar29 - iVar27 != 0) {
          plVar3 = (long *)(param_1[uVar25 * 8 + 9] + lVar29 & 0xffffffffffffU | 0x2bad000000000000)
          ;
        }
        *plVar3 = lVar31;
        plVar3 = (long *)(lVar18 + iVar27);
        if (lVar29 - iVar27 != 0) {
          plVar3 = (long *)(lVar18 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *plVar3 = (long)plVar14;
        puVar8 = PTR_DAT_fffffff007ca5f88;
        uVar30 = (ulong)(int)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f) & 0xfffffff8);
        if (0x7fffffffffffffff < uVar30) {
          uVar30 = 0x8000000000000000;
        }
        uVar12 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4f08,uVar30);
        puVar6 = (undefined8 *)(param_1[uVar25 * 8 + 0xb] + (long)iVar27);
        if (lVar29 - iVar27 != 0) {
          puVar6 = (undefined8 *)
                   (param_1[uVar25 * 8 + 0xb] + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar6 = uVar12;
        uVar30 = (ulong)(int)(1 << (ulong)(*(uint *)puVar8 & 0x1f) & 0xfffffff8);
        if (0x7fffffffffffffff < uVar30) {
          uVar30 = 0x8000000000000000;
        }
        lVar18 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4f58,uVar30);
        plVar3 = (long *)(param_1[uVar25 * 8 + 0xc] + (long)iVar27);
        if (lVar29 - iVar27 != 0) {
          plVar3 = (long *)(param_1[uVar25 * 8 + 0xc] + lVar29 & 0xffffffffffffU |
                           0x2bad000000000000);
        }
        *plVar3 = lVar18;
        uVar21 = *(uint *)puVar8;
        uVar30 = (ulong)(long)(1 << (ulong)(uVar21 & 0x1f)) >> 3;
        if (2 < uVar21) {
          if (uVar21 < 8) {
            uVar13 = 0;
            uVar21 = 0;
          }
          else {
            uVar21 = 0;
            uVar13 = 0;
            uVar26 = 0;
            if (uVar30 != 0) {
              uVar26 = uVar30 - 1;
            }
            if (((int)uVar26 != -1) && (uVar26 >> 0x20 == 0)) {
              lVar15 = 0;
              uVar13 = uVar30 & 0x1ffffffffffffffc;
              uVar26 = uVar13;
              do {
                lVar20 = lVar15 * 8;
                puVar6 = (undefined8 *)(lVar18 + (int)lVar20);
                if (lVar20 - (int)lVar20 != 0) {
                  puVar6 = (undefined8 *)(lVar18 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
                }
                puVar6[1] = 0;
                *puVar6 = 0;
                puVar6[3] = 0;
                puVar6[2] = 0;
                lVar15 = lVar15 + 4;
                uVar26 = uVar26 - 4;
              } while (uVar26 != 0);
              uVar21 = (uint)uVar13;
              if (uVar30 == uVar13) goto LAB_fffffff008210b00;
            }
          }
          do {
            uVar21 = uVar21 + 1;
            lVar15 = uVar13 * 8;
            puVar6 = (undefined8 *)(lVar18 + (int)lVar15);
            if (lVar15 - (int)lVar15 != 0) {
              puVar6 = (undefined8 *)(lVar18 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar6 = 0;
            uVar13 = (ulong)uVar21;
          } while (uVar13 < uVar30);
        }
LAB_fffffff008210b00:
        uVar12 = thunk_EXT_FUN_80110000038fe5cc(uVar30 << 2);
        puVar6 = (undefined8 *)(param_1[uVar25 * 8 + 0xd] + (long)iVar27);
        if (lVar29 - iVar27 != 0) {
          puVar6 = (undefined8 *)
                   (param_1[uVar25 * 8 + 0xd] + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar6 = uVar12;
        uVar12 = thunk_EXT_FUN_80110000039788dc(plVar14);
        uVar12 = (**(code **)(*param_1 + 0xb0))(param_1,uVar12);
        puVar6 = (undefined8 *)(param_1[uVar25 * 8 + 7] + (long)iVar27);
        if (lVar29 - iVar27 != 0) {
          puVar6 = (undefined8 *)
                   (param_1[uVar25 * 8 + 7] + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar6 = uVar12;
      }
      else {
        plVar14 = (long *)(param_1[uVar25 * 8 + 9] + (long)iVar27);
        if (lVar29 - iVar27 != 0) {
          plVar14 = (long *)(param_1[uVar25 * 8 + 9] + lVar29 & 0xffffffffffffU | 0x2bad000000000000
                            );
        }
        lVar31 = *plVar14;
      }
      lVar18 = uVar28 * 4;
      piVar2 = (int *)(param_1[uVar25 * 8 + 10] + (long)(int)lVar18);
      if (lVar18 - (int)lVar18 != 0) {
        piVar2 = (int *)(param_1[uVar25 * 8 + 10] + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *piVar2 = *piVar2 + 1;
      uVar30 = param_3 >> 0x19 & 0x7ff;
      if (uVar28 != uVar17) {
        uVar30 = 0;
      }
      uVar26 = uVar16 >> 0x19 & 0x7ff;
      if (uVar28 != uVar22) {
        uVar26 = ((ulong)(long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f)) >> 3) - 1;
      }
      for (; uVar30 <= uVar26; uVar30 = uVar30 + 1) {
        lVar18 = uVar30 * 8;
        iVar10 = (int)lVar18;
        puVar6 = (undefined8 *)(lVar31 + iVar10);
        if (lVar18 - iVar10 != 0) {
          puVar6 = (undefined8 *)(lVar31 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar13 = (**(code **)(*param_1 + 0x80))(param_1,*puVar6);
        if ((uVar13 & 1) == 0) {
          uVar21 = 1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f);
          plVar14 = (long *)thunk_EXT_FUN_8011000003962c64
                                      (*(uint *)((long)param_1 + 0xb4) | 3,
                                       (long)(int)(uVar21 & 0xfffffff8),(long)(int)uVar21);
          if (plVar14 == (long *)0x0) goto LAB_fffffff008210ee4;
          lVar15 = (**(code **)(*plVar14 + 0x148))();
          uVar21 = *(uint *)PTR_DAT_fffffff007ca5f88;
          if (2 < uVar21) {
            uVar13 = (ulong)(long)(1 << (ulong)(uVar21 & 0x1f)) >> 3;
            if (uVar21 < 8) {
LAB_fffffff008210cf8:
              uVar19 = 0;
              uVar21 = 0;
            }
            else {
              uVar19 = 0;
              if (uVar13 != 0) {
                uVar19 = uVar13 - 1;
              }
              if ((int)uVar19 == -1 || uVar19 >> 0x20 != 0) goto LAB_fffffff008210cf8;
              lVar20 = 0;
              uVar19 = uVar13 & 0x1ffffffffffffffc;
              uVar23 = uVar19;
              do {
                lVar24 = lVar20 * 8;
                puVar5 = (undefined8 *)(lVar15 + (int)lVar24);
                if (lVar24 - (int)lVar24 != 0) {
                  puVar5 = (undefined8 *)(lVar15 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
                }
                puVar5[1] = 0;
                *puVar5 = 0;
                puVar5[3] = 0;
                puVar5[2] = 0;
                lVar20 = lVar20 + 4;
                uVar23 = uVar23 - 4;
              } while (uVar23 != 0);
              uVar21 = (uint)uVar19;
              if (uVar13 == uVar19) goto LAB_fffffff008210d30;
            }
            do {
              uVar21 = uVar21 + 1;
              lVar20 = uVar19 * 8;
              puVar5 = (undefined8 *)(lVar15 + (int)lVar20);
              if (lVar20 - (int)lVar20 != 0) {
                puVar5 = (undefined8 *)(lVar15 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
              }
              *puVar5 = 0;
              uVar19 = (ulong)uVar21;
            } while (uVar19 < uVar13);
          }
LAB_fffffff008210d30:
          iVar11 = (**(code **)(*plVar14 + 0xd8))(plVar14,3);
          if (iVar11 != 0) goto LAB_fffffff008210ee4;
          lVar20 = param_1[uVar25 * 8 + 0xb];
          plVar3 = (long *)(param_1[uVar25 * 8 + 0xc] + (long)iVar27);
          if (lVar29 - iVar27 != 0) {
            plVar3 = (long *)(param_1[uVar25 * 8 + 0xc] + lVar29 & 0xffffffffffffU |
                             0x2bad000000000000);
          }
          plVar4 = (long *)(*plVar3 + (long)iVar10);
          if (lVar18 - iVar10 != 0) {
            plVar4 = (long *)(*plVar3 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *plVar4 = lVar15;
          plVar3 = (long *)(lVar20 + iVar27);
          if (lVar29 - iVar27 != 0) {
            plVar3 = (long *)(lVar20 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
          }
          plVar4 = (long *)(*plVar3 + (long)iVar10);
          if (lVar18 - iVar10 != 0) {
            plVar4 = (long *)(*plVar3 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *plVar4 = (long)plVar14;
          uVar12 = thunk_EXT_FUN_80110000039788dc(plVar14);
          uVar12 = (**(code **)(*param_1 + 0xb8))(param_1,uVar12);
          *puVar6 = uVar12;
        }
        plVar14 = (long *)(param_1[uVar25 * 8 + 0xd] + (long)iVar27);
        if (lVar29 - iVar27 != 0) {
          plVar14 = (long *)(param_1[uVar25 * 8 + 0xd] + lVar29 & 0xffffffffffffU |
                            0x2bad000000000000);
        }
        lVar18 = uVar30 * 4;
        piVar2 = (int *)(*plVar14 + (long)(int)lVar18);
        if (lVar18 - (int)lVar18 != 0) {
          piVar2 = (int *)(*plVar14 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *piVar2 = *piVar2 + 1;
      }
      bVar9 = uVar28 != uVar22;
      uVar28 = uVar28 + 1;
    } while (bVar9);
  }
  uVar21 = *(uint *)PTR_DAT_fffffff007ca5f88;
  local_68 = 0;
  uVar16 = (**(code **)(*param_2 + 0x98))(param_2,0,&local_68,0);
  if (uVar16 != 0) {
    local_80 = 0;
    local_98 = 0;
    uVar1 = param_5 >> 2 & 2;
    if ((param_5 & 4) != 0) {
      uVar1 = 1;
    }
    do {
      uVar17 = (ulong)(uint)~(-1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f));
      uVar22 = local_68 + uVar17 + (uVar16 & uVar17) & (uVar17 ^ 0xffffffffffffffff);
      uVar28 = uVar22 >> ((ulong)uVar21 & 0x3f) & 0xffffffff;
      if (uVar28 != 0) {
        uVar25 = 0;
        uVar16 = uVar16 & ~uVar17;
        do {
          uVar17 = local_80 + param_3 + (uVar25 << ((ulong)uVar21 & 0x3f));
          if (param_4 <= uVar17 - param_3) goto LAB_fffffff008210818;
          uVar30 = uVar17 >> 0x27 & 1;
          uVar7 = *(uint *)(&DAT_fffffff007115c80 +
                           (ulong)(param_5 >> 8 & 3 | (param_5 & 3) << 2) * 4);
          uVar12 = (**(code **)(*param_1 + 0xa8))
                             (param_1,uVar30,uVar7 >> 2 & 3,uVar7 & 1,uVar7 >> 1 & 1,1,uVar1);
          uVar12 = (**(code **)(*param_1 + 0xc0))(param_1,uVar30,uVar16,uVar12);
          *(undefined8 *)
           (*(long *)(*(long *)(*(long *)((long)param_1 + (uVar17 >> 0x21 & 0x40 | 0x30) + 0x30) +
                               (uVar17 >> 0x24 & 7) * 8) + (uVar17 >> 0x19 & 0x7ff) * 8) +
           (uVar17 >> 0xe & 0x7ff) * 8) = uVar12;
          uVar16 = uVar16 + (long)(1 << (ulong)(uVar21 & 0x1f));
          uVar25 = uVar25 + 1;
        } while (uVar28 != uVar25);
      }
      local_98 = local_68 + local_98;
      local_80 = uVar22 + local_80;
      uVar16 = (**(code **)(*param_2 + 0x98))(param_2,local_98,&local_68,0);
    } while (uVar16 != 0);
  }
LAB_fffffff008210818:
  thunk_EXT_FUN_8011000003222de0(param_1[0x17]);
  return;
}

