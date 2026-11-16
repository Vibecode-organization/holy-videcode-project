// FUN_fffffff009c215c4 @ fffffff009c215c4 size=2372

/* WARNING: Removing unreachable block (ram,0xfffffff009c21d90) */

undefined8 FUN_fffffff009c215c4(long param_1,uint param_2,int *param_3)

{
  undefined8 *puVar1;
  int iVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  undefined8 uVar7;
  undefined1 **ppuVar8;
  undefined1 **ppuVar9;
  long lVar10;
  uint uVar11;
  uint uVar12;
  long lVar13;
  undefined1 **ppuVar14;
  ulong uVar15;
  long lVar16;
  long lVar17;
  ulong uVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  long *plVar22;
  ulong uVar23;
  long *plVar24;
  uint uVar25;
  uint local_194;
  uint local_190;
  long *local_188;
  long *local_180;
  int local_174;
  undefined1 *local_170 [5];
  undefined1 *puStack_148;
  undefined1 *puStack_140;
  undefined1 *puStack_138;
  undefined1 *local_130;
  undefined1 *puStack_128;
  undefined1 *puStack_120;
  undefined1 *puStack_118;
  undefined1 *local_110;
  undefined1 *puStack_108;
  undefined1 *puStack_100;
  undefined1 *puStack_f8;
  undefined1 *local_f0;
  undefined1 *puStack_e8;
  undefined1 *puStack_e0;
  undefined1 *puStack_d8;
  undefined1 *local_d0;
  undefined1 *puStack_c8;
  undefined1 *puStack_c0;
  undefined1 *puStack_b8;
  undefined1 *local_b0;
  undefined1 *puStack_a8;
  undefined1 *puStack_a0;
  undefined1 *puStack_98;
  undefined1 *local_90;
  undefined1 *puStack_88;
  undefined1 *puStack_80;
  undefined1 *local_78 [3];
  
  local_78[1] = *(undefined1 **)PTR_DAT_fffffff00806ca40;
  local_174 = 4;
  if ((*(char *)(param_1 + 0x3d1) < '\0') && (*(long *)(param_1 + 0x30) != 0)) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
    uVar12 = 2;
    *param_3 = 2;
    uVar11 = param_2 & 0xf;
    if (uVar11 < 2) {
      if ((param_2 & 0xf) == 0) {
LAB_fffffff009c2168c:
        bVar4 = false;
        bVar3 = 0;
        *(uint *)(param_1 + 0x228) = uVar12;
        uVar11 = uVar12;
        goto LAB_fffffff009c216d4;
      }
      if (uVar11 == 1) {
        uVar12 = 3;
        *(undefined4 *)(param_1 + 0x228) = 3;
        if (*(long *)(param_1 + 0x38) == 0) {
          bVar4 = false;
          uVar12 = 3;
        }
        else {
          bVar4 = (*(uint *)(param_1 + 0x3d0) & 8) == 0;
          if (bVar4) {
            uVar12 = 4;
          }
        }
        bVar3 = 1;
        uVar11 = 3;
        goto LAB_fffffff009c216d4;
      }
LAB_fffffff009c216a0:
      *(undefined4 *)(param_1 + 0x228) = 0;
      uVar7 = 0xe00002c2;
    }
    else {
      if (uVar11 != 3) {
        if (uVar11 != 2) goto LAB_fffffff009c216a0;
        uVar12 = 4;
        goto LAB_fffffff009c2168c;
      }
      bVar4 = false;
      bVar3 = 0;
      uVar12 = 1;
      uVar11 = 1;
LAB_fffffff009c216d4:
      uVar7 = (**(code **)(**(long **)(param_1 + 0x30) + 0x80))
                        (*(long **)(param_1 + 0x30),uVar12 | param_2 & 0x760,&local_174);
      if (((int)uVar7 == 0 && uVar12 == 3) && local_174 == 4) {
        uVar7 = (**(code **)(**(long **)(param_1 + 0x30) + 0x80))(*(long **)(param_1 + 0x30),4,0);
      }
      if ((int)uVar7 == 0) {
        iVar6 = 1;
        if (local_174 != 3) {
          iVar6 = 2;
        }
        iVar2 = 0;
        if (local_174 != 2) {
          iVar2 = iVar6;
        }
        *param_3 = iVar2;
        local_190 = param_2 & 0xfffff89f;
        if ((((param_2 & 0xfffff89f) != 3) && ((param_2 & 0xfffff89f) != 0)) || (iVar2 != 2)) {
          lVar13 = 0;
          puStack_88 = &DAT_aaaaaaaaaaaaaaaa;
          local_90 = &DAT_aaaaaaaaaaaaaaaa;
          local_78[0] = &DAT_aaaaaaaaaaaaaaaa;
          puStack_80 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_a8 = &DAT_aaaaaaaaaaaaaaaa;
          local_b0 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_98 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_a0 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_c8 = &DAT_aaaaaaaaaaaaaaaa;
          local_d0 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_b8 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_c0 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_e8 = &DAT_aaaaaaaaaaaaaaaa;
          local_f0 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_d8 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_e0 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_108 = &DAT_aaaaaaaaaaaaaaaa;
          local_110 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_f8 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_100 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_128 = &DAT_aaaaaaaaaaaaaaaa;
          local_130 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_118 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_120 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_148 = &DAT_aaaaaaaaaaaaaaaa;
          local_170[4] = &DAT_aaaaaaaaaaaaaaaa;
          puStack_138 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_140 = &DAT_aaaaaaaaaaaaaaaa;
          lVar16 = 0x20;
          local_170[1] = &DAT_aaaaaaaaaaaaaaaa;
          local_170[0] = &DAT_aaaaaaaaaaaaaaaa;
          local_170[3] = &DAT_aaaaaaaaaaaaaaaa;
          local_170[2] = &DAT_aaaaaaaaaaaaaaaa;
          do {
            local_170[lVar13] = (undefined1 *)0x0;
            local_170[lVar13 + 1] = (undefined1 *)0x0;
            lVar13 = lVar13 + 2;
            lVar16 = lVar16 + -2;
          } while (lVar16 != 0);
          lVar13 = *(long *)(param_1 + 0x40);
          if (lVar13 == 0) {
            ppuVar9 = (undefined1 **)0x0;
          }
          else {
            lVar10 = 0;
            lVar16 = 0;
            uVar12 = 0xffffffff;
            lVar17 = lVar13;
            do {
              lVar17 = *(long *)(lVar17 + 0x30);
              uVar12 = uVar12 + 1;
              lVar16 = lVar16 + 1;
              lVar10 = lVar10 + 8;
            } while (lVar17 != 0);
            if (uVar12 < 0x20) {
              ppuVar8 = local_170;
              lVar16 = 0x20;
              ppuVar9 = (undefined1 **)0x0;
            }
            else {
              ppuVar8 = (undefined1 **)thunk_EXT_FUN_80110000038fe750(&DAT_fffffff00806be80,lVar10);
              lVar13 = *(long *)(param_1 + 0x40);
              ppuVar9 = ppuVar8;
              if (lVar13 == 0) goto LAB_fffffff009c21988;
            }
            ppuVar14 = ppuVar8 + lVar16;
            if ((((ulong)ppuVar8 ^ (ulong)ppuVar14) & 0xffc0000000000000) != 0) {
              ppuVar14 = (undefined1 **)((ulong)ppuVar14 & 0xffffffffffff | 0xc8a2000000000000);
            }
            if ((ppuVar14 < ppuVar8) || ((ulong)((long)ppuVar14 - (long)ppuVar8) >> 0x20 != 0)) {
              FUN_fffffff009c48f64();
LAB_fffffff009c21f00:
              FUN_fffffff009c48f64();
              goto LAB_fffffff009c21f04;
            }
            uVar23 = 0;
            uVar15 = 1;
            do {
              if ((uVar23 & 0x1fffffff) >> 0x1c != 0) {
LAB_fffffff009c21ec8:
                    /* WARNING: Subroutine does not return */
                FUN_fffffff009c48f28();
              }
              uVar12 = (int)uVar23 * 8;
              uVar25 = (uint)((long)ppuVar14 - (long)ppuVar8);
              if (uVar25 < uVar12 + 8) goto LAB_fffffff009c21ec8;
              lVar16 = (long)ppuVar8 + (ulong)uVar12;
              uVar18 = (ulong)CARRY8((ulong)ppuVar8,(ulong)uVar12);
              uVar23 = -uVar18;
              if ((uVar23 != uVar18) || ((long)uVar23 < 0)) {
                    /* WARNING: Subroutine does not return */
                FUN_fffffff009c48f50(lVar16);
              }
              FUN_fffffff009c16670(lVar16,lVar13);
              lVar13 = *(long *)(lVar13 + 0x30);
              if (lVar13 == 0) {
                thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
                lVar13 = 0x10000000;
                uVar23 = 0;
                uVar18 = uVar15;
                goto LAB_fffffff009c219b4;
              }
              bVar5 = uVar15 != 0x10000000;
              uVar23 = uVar15;
              uVar15 = uVar15 + 1;
            } while (bVar5);
            FUN_fffffff009c48f3c();
          }
LAB_fffffff009c21988:
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
          lVar13 = 0;
          goto LAB_fffffff009c21a28;
        }
        if ((param_2 & 0xfffff89f) == 0) {
          *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xfffffff3 | 0x20;
        }
        lVar13 = 0;
        local_180 = (long *)0x0;
        puStack_88 = &DAT_aaaaaaaaaaaaaaaa;
        local_90 = &DAT_aaaaaaaaaaaaaaaa;
        local_78[0] = &DAT_aaaaaaaaaaaaaaaa;
        puStack_80 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_a8 = &DAT_aaaaaaaaaaaaaaaa;
        local_b0 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_98 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_a0 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_c8 = &DAT_aaaaaaaaaaaaaaaa;
        local_d0 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_b8 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_c0 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_e8 = &DAT_aaaaaaaaaaaaaaaa;
        local_f0 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_d8 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_e0 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_108 = &DAT_aaaaaaaaaaaaaaaa;
        local_110 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_f8 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_100 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_128 = &DAT_aaaaaaaaaaaaaaaa;
        local_130 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_118 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_120 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_148 = &DAT_aaaaaaaaaaaaaaaa;
        local_170[4] = &DAT_aaaaaaaaaaaaaaaa;
        puStack_138 = &DAT_aaaaaaaaaaaaaaaa;
        puStack_140 = &DAT_aaaaaaaaaaaaaaaa;
        lVar16 = 0x20;
        local_170[1] = &DAT_aaaaaaaaaaaaaaaa;
        local_170[0] = &DAT_aaaaaaaaaaaaaaaa;
        local_170[3] = &DAT_aaaaaaaaaaaaaaaa;
        local_170[2] = &DAT_aaaaaaaaaaaaaaaa;
        do {
          local_170[lVar13] = (undefined1 *)0x0;
          local_170[lVar13 + 1] = (undefined1 *)0x0;
          lVar13 = lVar13 + 2;
          lVar16 = lVar16 + -2;
        } while (lVar16 != 0);
        local_188 = *(long **)(param_1 + 0x38);
        if (local_188 != (long *)0x0) {
          (**(code **)(*local_188 + 0x20))(local_188);
        }
        lVar13 = *(long *)(param_1 + 0x40);
        if (lVar13 != 0) {
          lVar10 = 0;
          lVar16 = 0;
          uVar11 = 0xffffffff;
          lVar17 = lVar13;
          do {
            lVar17 = *(long *)(lVar17 + 0x30);
            uVar11 = uVar11 + 1;
            lVar16 = lVar16 + 1;
            lVar10 = lVar10 + 8;
          } while (lVar17 != 0);
          if (uVar11 < 0x20) {
            ppuVar9 = local_170;
            lVar16 = 0x20;
            ppuVar8 = (undefined1 **)0x0;
LAB_fffffff009c21aa4:
            ppuVar14 = ppuVar9 + lVar16;
            if ((((ulong)ppuVar9 ^ (ulong)ppuVar14) & 0xffc0000000000000) != 0) {
              ppuVar14 = (undefined1 **)((ulong)ppuVar14 & 0xffffffffffff | 0xc8a2000000000000);
            }
            if ((ppuVar14 < ppuVar9) || ((ulong)((long)ppuVar14 - (long)ppuVar9) >> 0x20 != 0))
            goto LAB_fffffff009c21f00;
            uVar15 = 1;
            uVar18 = 0;
            do {
              uVar23 = uVar15;
              if ((uVar18 & 0x1fffffff) >> 0x1c != 0) {
LAB_fffffff009c21edc:
                    /* WARNING: Subroutine does not return */
                FUN_fffffff009c48f28();
              }
              uVar11 = (int)uVar18 * 8;
              uVar12 = (uint)((long)ppuVar14 - (long)ppuVar9);
              if (uVar12 < uVar11 + 8) goto LAB_fffffff009c21edc;
              lVar16 = (long)ppuVar9 + (ulong)uVar11;
              uVar19 = (ulong)CARRY8((ulong)ppuVar9,(ulong)uVar11);
              uVar15 = -uVar19;
              if ((uVar15 != uVar19) || ((long)uVar15 < 0)) {
                    /* WARNING: Subroutine does not return */
                FUN_fffffff009c48f50(lVar16);
              }
              FUN_fffffff009c16670(lVar16,lVar13);
              lVar13 = *(long *)(lVar13 + 0x30);
              if (lVar13 == 0) goto LAB_fffffff009c21b2c;
              uVar15 = uVar23 + 1;
              uVar18 = uVar23;
            } while (uVar23 != 0x10000000);
            FUN_fffffff009c48f3c();
LAB_fffffff009c21b2c:
            if ((int)uVar23 != 0) {
              bVar4 = (int)uVar23 != 1;
              thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
              if (local_188 == (long *)0x0) {
LAB_fffffff009c21bb0:
                local_188 = (long *)0x0;
                local_194 = 0;
              }
              else if (local_190 == 3) {
                local_194 = FUN_fffffff009c2db14(local_188);
              }
              else {
                uVar15 = FUN_fffffff009c2da80(local_188,0);
                if ((uVar15 & 1) == 0) {
                  FUN_fffffff009c2da10(local_188);
                  goto LAB_fffffff009c21bb0;
                }
                bVar4 = false;
                local_194 = 1;
              }
              uVar15 = 0;
              lVar13 = 0x10000000;
              uVar19 = uVar23;
              do {
                if (lVar13 == 0) {
                  FUN_fffffff009c48f3c();
LAB_fffffff009c21ee8:
                    /* WARNING: Subroutine does not return */
                  FUN_fffffff009c48f28();
                }
                if (((long)uVar15 < 0) || (uVar12 < (int)(uVar15 >> 0x20) + 8U))
                goto LAB_fffffff009c21ee8;
                uVar21 = (ulong)CARRY8((ulong)ppuVar9,uVar15 >> 0x20);
                uVar20 = -uVar21;
                if ((uVar20 != uVar21) || ((long)uVar20 < 0)) {
                    /* WARNING: Subroutine does not return */
                  FUN_fffffff009c48f50();
                }
                plVar24 = *(long **)((long)ppuVar9 + (uVar15 >> 0x20));
                if (plVar24 != local_188) {
                  if (local_190 == 3) {
                    if ((local_194 & 1) == 0) {
                      local_194 = FUN_fffffff009c2db14(plVar24);
                    }
                    else {
LAB_fffffff009c21c54:
                      local_194 = 1;
                    }
                  }
                  else {
                    iVar6 = FUN_fffffff009c2da80(plVar24,bVar4);
                    if (iVar6 != 0) {
                      if (local_180 == (long *)0x0) {
                        FUN_fffffff009c16670(&local_180,plVar24);
                      }
                      bVar4 = false;
                      goto LAB_fffffff009c21c54;
                    }
                  }
                }
                lVar13 = lVar13 + -1;
                uVar15 = uVar15 + 0x800000000;
                uVar19 = uVar19 - 1;
              } while (uVar19 != 0);
              uVar15 = 0;
              lVar13 = 0x10000000;
              uVar19 = uVar23;
              do {
                if (lVar13 == 0) {
                  FUN_fffffff009c48f3c();
LAB_fffffff009c21ef4:
                    /* WARNING: Subroutine does not return */
                  FUN_fffffff009c48f28();
                }
                if (((long)uVar15 < 0) || (uVar12 < (int)(uVar15 >> 0x20) + 8U))
                goto LAB_fffffff009c21ef4;
                puVar1 = (undefined8 *)((long)ppuVar9 + (uVar15 >> 0x20));
                uVar21 = (ulong)CARRY8((ulong)ppuVar9,uVar15 >> 0x20);
                uVar20 = -uVar21;
                if ((uVar20 != uVar21) || ((long)uVar20 < 0)) {
                    /* WARNING: Subroutine does not return */
                  FUN_fffffff009c48f50();
                }
                uVar7 = *puVar1;
                *puVar1 = 0;
                FUN_fffffff009c2da10(uVar7);
                lVar13 = lVar13 + -1;
                uVar15 = uVar15 + 0x800000000;
                uVar19 = uVar19 - 1;
              } while (uVar19 != 0);
              thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
              if ((local_194 & 1) == 0) {
                if (local_190 != 3) {
                  for (lVar13 = *(long *)(param_1 + 0x40); lVar13 != 0;
                      lVar13 = *(long *)(lVar13 + 0x30)) {
                    FUN_fffffff009c2da48(lVar13);
                  }
                }
              }
              else {
                if (local_190 != 3) {
                  if (local_188 == (long *)0x0) {
                    if (uVar18 == 0) {
                      *(long **)(param_1 + 0x38) = local_180;
                      plVar22 = *(long **)(param_1 + 0x178);
                      *(short *)(plVar22 + 1) = (short)(int)local_180[9];
                      *plVar22 = plVar24[0xc];
                      *(short *)((long)plVar22 + 10) =
                           (short)*(undefined4 *)((long)local_180 + 0x54);
                    }
                  }
                  else if (*(long **)(param_1 + 0x38) != local_188) {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                               "IOSurface %08x: Current device cache changed while purgeability status was changing.\n"
                              );
                  }
                }
                *param_3 = 1;
              }
              thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
              if (local_188 != (long *)0x0) {
                FUN_fffffff009c2da10(local_188);
              }
              if (local_180 != (long *)0x0) {
                local_180 = (long *)0x0;
                FUN_fffffff009c2da10();
              }
              thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
              local_188 = (long *)0x0;
              uVar23 = (uVar23 & 0xffffffff) << 3;
            }
          }
          else {
            ppuVar9 = (undefined1 **)thunk_EXT_FUN_80110000038fe750(&DAT_fffffff00806bde0,lVar10);
            lVar13 = *(long *)(param_1 + 0x40);
            ppuVar8 = ppuVar9;
            if (lVar13 != 0) goto LAB_fffffff009c21aa4;
            uVar23 = 0;
          }
          if (ppuVar8 != (undefined1 **)0x0) {
            thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806be30,ppuVar8,uVar23);
          }
        }
        ppuVar9 = local_78 + 1;
        do {
          ppuVar9 = ppuVar9 + -1;
          if ((long *)*ppuVar9 != (long *)0x0) {
            (**(code **)(*(long *)*ppuVar9 + 0x28))();
          }
          *ppuVar9 = (undefined1 *)0x0;
        } while (ppuVar9 != local_170);
        if (local_188 != (long *)0x0) {
          (**(code **)(*local_188 + 0x28))(local_188);
        }
        if (local_180 != (long *)0x0) {
          (**(code **)(*local_180 + 0x28))();
        }
        goto LAB_fffffff009c21e80;
      }
    }
    goto LAB_fffffff009c21e84;
  }
  uVar7 = 0;
  *param_3 = 0;
  goto LAB_fffffff009c21e8c;
  while( true ) {
    if (((long)uVar23 < 0) || (uVar25 < (int)(uVar23 >> 0x20) + 8U)) goto LAB_fffffff009c21ed4;
    plVar24 = (long *)((long)ppuVar8 + (uVar23 >> 0x20));
    uVar20 = (ulong)CARRY8((ulong)ppuVar8,uVar23 >> 0x20);
    uVar19 = -uVar20;
    if ((uVar19 != uVar20) || ((long)uVar19 < 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f50();
    }
    uVar12 = uVar11;
    if (((bool)(bVar4 & bVar3)) && (uVar12 = 3, *plVar24 != *(long *)(param_1 + 0x38))) {
      uVar12 = 4;
    }
    FUN_fffffff009c2dba4(*plVar24,uVar12);
    lVar16 = *plVar24;
    *plVar24 = 0;
    FUN_fffffff009c2da10(lVar16);
    lVar13 = lVar13 + -1;
    uVar23 = uVar23 + 0x800000000;
    uVar18 = uVar18 - 1;
    if (uVar18 == 0) break;
LAB_fffffff009c219b4:
    if (lVar13 == 0) {
      FUN_fffffff009c48f3c();
LAB_fffffff009c21ed4:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f28();
    }
  }
  lVar13 = (uVar15 & 0xffffffff) << 3;
LAB_fffffff009c21a28:
  ppuVar8 = local_78 + 1;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  if (ppuVar9 != (undefined1 **)0x0) {
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806bed0,ppuVar9,lVar13);
  }
  do {
    ppuVar8 = ppuVar8 + -1;
    if ((long *)*ppuVar8 != (long *)0x0) {
      (**(code **)(*(long *)*ppuVar8 + 0x28))();
    }
    *ppuVar8 = (undefined1 *)0x0;
  } while (ppuVar8 != local_170);
LAB_fffffff009c21e80:
  uVar7 = 0;
LAB_fffffff009c21e84:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
LAB_fffffff009c21e8c:
  if ((undefined1 *)*(long *)PTR_DAT_fffffff00806ca40 == local_78[1]) {
    return uVar7;
  }
LAB_fffffff009c21f04:
  uVar7 = thunk_EXT_FUN_8011000003a48590();
  return uVar7;
}

