// FUN_fffffff0081f8a74 @ fffffff0081f8a74 size=4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_fffffff0081f8a74(long param_1,long param_2,long param_3,ulong param_4)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long *plVar16;
  long lVar17;
  char cVar18;
  uint uVar19;
  uint uVar20;
  undefined8 *puVar21;
  ulong uVar22;
  uint uVar23;
  int iVar24;
  undefined1 uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  ulong uVar29;
  uint uVar30;
  uint uVar31;
  undefined8 uVar32;
  ushort *puVar33;
  uint uVar34;
  uint uVar35;
  undefined1 auVar36 [16];
  
  if ((param_3 != 0) && (param_4 < 0x68)) {
    return 0;
  }
  uVar12 = (**(code **)(PTR_DAT_fffffff007ca60f0 + 0x98))(param_1,param_2,param_3);
  if ((int)uVar12 == 0) {
    return uVar12;
  }
  cVar18 = *(char *)(param_1 + 0x10);
  if (param_3 == 0) {
    bVar9 = false;
    if (cVar18 != -0x80) goto LAB_fffffff0081f8ba8;
LAB_fffffff0081f8b18:
    if (*(long *)(param_1 + 0x30) != 0) goto LAB_fffffff0081f8b20;
LAB_fffffff0081f8bb0:
    if ((param_3 != 0) && ((*(byte *)(param_3 + 0x5c) >> 5 & 1) != 0)) {
      *(undefined1 *)(param_1 + 0xb1) = 1;
      uVar12 = FUN_fffffff0081e8f54
                         (*(undefined8 *)(*(long *)(param_1 + 0x50) + 0x111e8),param_2,param_1);
      if ((uVar12 & 1) == 0) {
        *(undefined1 *)(param_1 + 0xb1) = 0;
        return 0;
      }
      goto LAB_fffffff0081f9418;
    }
    if ((bool)(((cVar18 == '\0' || cVar18 == -0x80) || cVar18 == '@') & bVar9)) {
      uVar12 = *(ulong *)(param_3 + 0x58);
      if ((uVar12 & 1) != 0) {
        uVar12 = FUN_fffffff0081f9868(param_1,param_3,0);
        if ((int)uVar12 == 0) {
          return uVar12;
        }
        uVar12 = *(ulong *)(param_3 + 0x58);
      }
      if ((uVar12 >> 0x27 & 1) != 0) {
        if (param_2 == 0) {
          return 0;
        }
        if (*(long *)(param_1 + 0x28) == 0) {
          return 0;
        }
        if (*(long *)(param_3 + 0x60) == 0) {
          return 0;
        }
        plVar16 = (long *)FUN_fffffff0081f9abc();
        if (plVar16 == (long *)0x0) {
          return 0;
        }
        uVar3 = *(undefined4 *)(param_3 + 0x60);
        uVar32 = (**(code **)(*plVar16 + 0xa8))();
        plVar16 = (long *)FUN_fffffff0081f8444(plVar16,uVar3,uVar32);
        if (plVar16 == (long *)0x0) {
          return 0;
        }
        lVar14 = thunk_EXT_FUN_801100000297d1cc(*(undefined8 *)(param_2 + 0x48),0,plVar16);
        if (lVar14 == 0) {
          (**(code **)(*plVar16 + 0x28))(plVar16);
          return 0;
        }
        if (*(long **)(param_1 + 0x28) != (long *)0x0) {
          (**(code **)(**(long **)(param_1 + 0x28) + 0x28))();
        }
        *(long *)(param_1 + 0x28) = lVar14;
        (**(code **)(*plVar16 + 0x28))(plVar16);
      }
      if (cVar18 == '@') {
        uVar32 = thunk_EXT_FUN_801100000295198c(param_1);
        lVar14 = thunk_EXT_FUN_8011000003890f30(uVar32,&DAT_fffffff00ae238d8);
        lVar14 = thunk_EXT_FUN_8011000003890f30
                           (*(undefined8 *)(lVar14 + 0x28),&DAT_fffffff00ae25a58);
        if (lVar14 == 0) {
          return 0;
        }
        if (*(long *)(lVar14 + 0xb8) != 0) {
          uVar12 = *(ulong *)(param_3 + 0x58);
          if ((uVar12 >> 0x31 & 1) == 0) {
            uVar22 = uVar12 >> 0x28 & 0xf;
            uVar23 = 1 << uVar22;
            uVar5 = *(ushort *)(param_3 + 8);
            uVar19 = (uint)*(ushort *)(param_3 + 10);
            uVar30 = (uint)*(ushort *)(param_3 + 0xc);
            if ((uVar12 & 0x1000000000000) != 0) {
              uVar19 = 1;
              uVar30 = (uint)*(ushort *)(param_3 + 10);
            }
            uVar35 = (uint)uVar12;
            if (((uVar35 >> 0xd & 1) != 0) && (uVar30 == 1)) {
              uVar30 = (uint)*(byte *)(param_3 + 0x10);
            }
            uVar7 = uVar35 >> 0x17 & 0xf;
            bVar4 = *(byte *)(param_3 + 0x13);
            puVar33 = (ushort *)(lVar14 + 0xd2);
            puVar33[0] = 0;
            puVar33[1] = 0;
            puVar33[2] = 0;
            puVar33[3] = 0;
            uVar26 = uVar35 >> 0xf & 0xf;
            uVar20 = uVar35 >> 0x13 & 0xf;
            *(undefined8 *)(lVar14 + 0xda) = 0;
            *(undefined8 *)(lVar14 + 0xe2) = 0;
            uVar29 = *(ulong *)(param_3 + 0x58);
            uVar35 = (uint)bVar4 << (ulong)(uVar35 >> 1 & 7);
            *(char *)(lVar14 + 0xe0) = (char)uVar35;
            uVar28 = (uint)uVar29;
            uVar27 = uVar28 >> 0x17 & 0xf;
            *puVar33 = uVar5;
            *(short *)(lVar14 + 0xd4) = (short)uVar19;
            *(short *)(lVar14 + 0xd6) = (short)uVar30;
            *(char *)(lVar14 + 0xda) = (char)uVar27;
            *(undefined2 *)(lVar14 + 0xd8) = 0x4000;
            *(byte *)(lVar14 + 0xe3) = (byte)(uVar29 >> 0x1f) & 7;
            *(byte *)(lVar14 + 0xe1) = (byte)(uVar28 >> 4) & 7;
            *(char *)(lVar14 + 0xe4) = (char)uVar26;
            *(char *)(lVar14 + 0xe5) = (char)uVar20;
            *(undefined1 *)(lVar14 + 0xe6) = 1;
            *(byte *)(lVar14 + 0xe7) = (byte)(uVar29 >> 0xd) & 1;
            *(byte *)(lVar14 + 0xe8) = (byte)(uVar28 >> 0xe) & 1;
            if ((((uVar29 >> 0x1f & 7) == 0) && (1 < uVar30)) && (1 < uVar27)) {
              uVar30 = 0;
              if (uVar26 != 0) {
                uVar30 = ((uVar26 + uVar5) - 1) / uVar26;
              }
              uVar35 = 0;
              if (uVar20 != 0) {
                uVar35 = ((uVar20 + uVar19) - 1) / uVar20;
              }
            }
            else {
              uVar35 = uVar35 & 0xff;
              uVar30 = 0;
              if (uVar26 != 0) {
                uVar30 = ((uVar26 + uVar5) - 1) / uVar26;
              }
              uVar25 = 1;
              if ((uVar29 & 0x2000) != 0) {
                uVar25 = 2;
              }
              uVar1 = 0;
              if ((uVar29 & 0x1000) != 0) {
                uVar1 = uVar25;
              }
              *(undefined1 *)(lVar14 + 0xe2) = uVar1;
              uVar26 = 0xc000;
              if (0x55555555 < uVar35 * -0x55555555) {
                uVar26 = 0x4000;
              }
              uVar27 = 0;
              if (uVar35 != 0) {
                uVar27 = uVar26 / uVar35;
              }
              uVar26 = 0x20 - (int)LZCOUNT(uVar27 - 1);
              uVar27 = uVar26 >> 1;
              *(char *)(lVar14 + 0xde) = (char)uVar27;
              uVar26 = uVar26 - uVar27;
              *(char *)(lVar14 + 0xdf) = (char)uVar26;
              if ((uVar28 >> 0xc & 1) != 0) {
                uVar26 = uVar26 & 0xff;
                if (uVar27 < 6) {
                  uVar27 = 5;
                }
                *(char *)(lVar14 + 0xde) = (char)uVar27;
                if (uVar26 < 6) {
                  uVar26 = 5;
                }
                *(char *)(lVar14 + 0xdf) = (char)uVar26;
              }
              uVar35 = uVar35 << (ulong)(uVar27 + (uVar26 & 0xff) & 0x1f);
              uVar26 = uVar35 + 0x3fff;
              if (-1 < (int)uVar35) {
                uVar26 = uVar35;
              }
              *(char *)(lVar14 + 0xdb) = (char)(uVar26 >> 0xe);
              uVar35 = 0;
              if (uVar20 != 0) {
                uVar35 = ((uVar20 + uVar19) - 1) / uVar20;
              }
              if (uVar30 < 2) {
                cVar18 = '\0';
              }
              else {
                cVar18 = ' ' - (char)LZCOUNT(~(-1 << (ulong)(-(int)LZCOUNT(uVar30 - 1) & 0x1f)));
              }
              *(char *)(lVar14 + 0xdc) = cVar18;
              if (uVar35 < 2) {
                cVar18 = '\0';
              }
              else {
                cVar18 = ' ' - (char)LZCOUNT(~(-1 << (ulong)(-(int)LZCOUNT(uVar35 - 1) & 0x1f)));
              }
              *(char *)(lVar14 + 0xdd) = cVar18;
            }
            *(uint *)(lVar14 + 300) = uVar30;
            *(uint *)(lVar14 + 0x130) = uVar23;
            uVar19 = *(uint *)(param_3 + 0x58) >> 0x17 & 0xf;
            *(uint *)(lVar14 + 0xf8) = uVar19;
            lVar13 = thunk_EXT_FUN_80110000038fe5cc(uVar19 << 2);
            *(long *)(lVar14 + 0xf0) = lVar13;
            uVar19 = (uint)*(ulong *)(param_3 + 0x58);
            if ((*(ulong *)(param_3 + 0x58) & 0x7800000) == 0) {
              uVar26 = 0;
              uVar29 = (ulong)uVar7;
            }
            else {
              uVar20 = 0;
              uVar29 = 0;
              uVar26 = 0;
              uVar12 = uVar12 >> 0x2c & 0xf;
              uVar27 = 1 << uVar12;
              uVar28 = (uVar23 + uVar30) - 1 >> uVar22;
              uVar6 = (uVar27 + uVar35) - 1 >> uVar12;
              do {
                uVar34 = (uint)uVar29;
                uVar19 = uVar30 >> (ulong)(uVar34 & 0x1f);
                if (uVar19 < 2) {
                  uVar19 = 1;
                }
                uVar31 = uVar35 >> (ulong)(uVar34 & 0x1f);
                if (uVar31 < 2) {
                  uVar31 = 1;
                }
                if (uVar19 < uVar23 || uVar31 < uVar27) {
                  *(uint *)(lVar14 + 0x124) = uVar26;
                  uVar12 = FUN_fffffff0081e39cc
                                     (puVar33,uVar29,
                                      (*(uint *)(param_3 + 0x58) >> 0x17 & 0xf) - uVar34);
                  uVar26 = uVar26 + (int)((uVar12 & 0xffffffff) + 0x3fff >> 0xe);
                  *(uint *)(lVar13 + uVar29 * 4) = uVar26;
                  uVar19 = (uint)*(undefined8 *)(param_3 + 0x58);
                  goto LAB_fffffff0081f8fc4;
                }
                uVar31 = -1 << (ulong)(uVar34 & 0x1f);
                bVar9 = (uVar28 & (uVar31 ^ 0xffffffff)) != 0;
                uVar19 = uVar6 >> (ulong)(uVar34 & 0x1f);
                if (!bVar9) {
                  uVar19 = 0;
                }
                uVar34 = uVar28 >> (ulong)(uVar34 & 0x1f);
                bVar10 = (uVar6 & (uVar31 ^ 0xffffffff)) == 0;
                if (bVar10) {
                  uVar34 = 0;
                }
                uVar31 = 0;
                if (!bVar10) {
                  uVar31 = (uint)bVar9;
                }
                uVar26 = (uVar6 * uVar28 >> (ulong)(uVar20 & 0x1f)) + uVar26 + uVar19 + uVar34 +
                         uVar31;
                *(uint *)(lVar13 + uVar29 * 4) = uVar26;
                uVar29 = uVar29 + 1;
                uVar19 = (uint)*(ulong *)(param_3 + 0x58);
                uVar20 = uVar20 + 2;
              } while (uVar29 < (*(ulong *)(param_3 + 0x58) >> 0x17 & 0xf));
              uVar29 = (ulong)uVar7;
            }
LAB_fffffff0081f8fc4:
            uVar23 = (uint)uVar29;
            if ((uVar19 >> 0x17 & 0xf) <= uVar23) {
              *(uint *)(lVar14 + 0x124) = uVar26;
            }
            *(ulong *)(lVar14 + 0x100) = (ulong)uVar26;
            lVar13 = thunk_EXT_FUN_80110000038fe5cc((ulong)*(byte *)(lVar14 + 0xda) << 2);
            *(long *)(lVar14 + 0x108) = lVar13;
            bVar4 = *(byte *)(lVar14 + 0xda);
            if (bVar4 != 0) {
              uVar12 = 0;
              iVar11 = 0;
              do {
                *(int *)(lVar13 + uVar12 * 4) = iVar11;
                lVar15 = FUN_fffffff0081e39cc(puVar33,uVar12,1);
                iVar11 = iVar11 + (int)(lVar15 + 0x3fffU >> 0xe);
                uVar12 = uVar12 + 1;
              } while (bVar4 != uVar12);
            }
            uVar12 = FUN_fffffff0081e39cc(puVar33,0,(ulong)bVar4);
            if (*(char *)(lVar14 + 0xe7) == '\0') {
              bVar9 = *(char *)(lVar14 + 0xe8) != '\0';
            }
            else {
              bVar9 = true;
            }
            bVar4 = *(byte *)(lVar14 + 0xe3);
            if (1 < *(ushort *)(lVar14 + 0xd6)) {
              bVar9 = true;
            }
            if (bVar4 < 3) {
              if (bVar4 == 1) {
                lVar15 = 0x4000;
                if (!(bool)((uVar12 & 0xffffffffffffc000) != 0 & bVar9)) {
                  lVar15 = 0x40;
                }
              }
              else {
                lVar15 = 0x4000;
                if (!(bool)((uVar12 & 0xffffffffffffc000) != 0 & bVar9)) {
                  lVar15 = 0x80;
                }
                if (bVar4 != 2) {
                  lVar15 = 0;
                }
              }
            }
            else {
              lVar15 = 0x4000;
              if (!(bool)((uVar12 & 0xffffffffffffc000) != 0 & bVar9)) {
                lVar15 = 0x80;
              }
              lVar17 = 0x4000;
              if (!(bool)((uVar12 & 0xffffffffffffc000) != 0 & bVar9)) {
                lVar17 = 0x80;
              }
              if (bVar4 != 4) {
                lVar17 = 0;
              }
              if (bVar4 != 3) {
                lVar15 = lVar17;
              }
            }
            uVar12 = ((uVar12 + lVar15) - 1 & -lVar15) + 0x3fffff >> 0xe & 0x3ffffffffff00;
            *(ulong *)(lVar14 + 0x110) = uVar12;
            *(uint *)(lVar14 + 0x120) = uVar23;
            if (uVar23 < (*(uint *)(param_3 + 0x58) >> 0x17 & 0xf)) {
              iVar11 = (int)uVar12 - *(int *)(lVar13 + (uVar29 & 0xffffffff) * 4);
            }
            else {
              iVar11 = 0;
            }
            *(int *)(lVar14 + 0x128) = iVar11;
            uVar25 = 1;
          }
          else {
            uVar25 = 0;
          }
          *(undefined1 *)(lVar14 + 0xd1) = uVar25;
        }
        lVar13 = thunk_EXT_FUN_8011000003890f30(param_2,&DAT_fffffff00ae23c90);
        if (lVar13 == 0) {
          return 0;
        }
        uVar32 = *(undefined8 *)(lVar13 + 0x1e8);
        thunk_EXT_FUN_80110000032222a8(uVar32);
        lVar15 = *(long *)(lVar13 + 0x1e0);
        if (lVar15 == 0) {
          lVar15 = (**(code **)(DAT_fffffff00ae22f20 + 0x68))();
          *(long *)(lVar13 + 0x1e0) = lVar15;
          if (lVar15 == 0) {
LAB_fffffff0081f97c8:
            thunk_EXT_FUN_8011000003222de0(uVar32);
            return 0;
          }
          uVar2 = *(undefined8 *)(lVar13 + 0x48);
          *(undefined8 *)(lVar15 + 0x10) = *(undefined8 *)(lVar13 + 0x50);
          iVar11 = FUN_fffffff0081e07cc(lVar15,uVar2,0x18000,0x23);
          if (iVar11 == 0) goto LAB_fffffff0081f97c8;
          lVar15 = *(long *)(lVar13 + 0x1e0);
          plVar16 = *(long **)(lVar15 + 0x60);
          if (plVar16 == (long *)0x0) {
            lVar17 = thunk_EXT_FUN_801100000297ea14(*(undefined8 *)(lVar15 + 0x48),0);
            *(long *)(lVar15 + 0x60) = lVar17;
            if (lVar17 == 0) goto LAB_fffffff0081f97c8;
            LOAcquire();
            DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + *(long *)(lVar15 + 0x30);
            LORelease();
            plVar16 = *(long **)(lVar15 + 0x60);
          }
          lVar15 = (**(code **)(*plVar16 + 0x78))();
          if (lVar15 == 0) goto LAB_fffffff0081f97c8;
          lVar17 = *(long *)(lVar13 + 0x1e0);
          lVar15 = *(long *)(lVar13 + 0x58);
          plVar16 = *(long **)(lVar17 + 0x58);
          if (plVar16 == (long *)0x0) {
            plVar16 = (long *)(**(code **)(**(long **)(lVar17 + 0x48) + 0x90))
                                        (*(long **)(lVar17 + 0x48),lVar15,0x500000085);
            if (plVar16 == (long *)0x0) goto LAB_fffffff0081f97c8;
            (**(code **)(*plVar16 + 0x20))();
            (**(code **)(*plVar16 + 0x28))(plVar16);
            *(long **)(lVar17 + 0x58) = plVar16;
          }
          if (plVar16[4] != lVar15) {
            uVar12 = thunk_EXT_FUN_8011000003a49114
                               (
                               "AGXk: %s:%d:%s: !!! Attempting to map into multiple GPU Contexts!\n"
                               );
            return uVar12;
          }
          lVar15 = (**(code **)(*plVar16 + 0x98))();
          if (lVar15 == 0) goto LAB_fffffff0081f97c8;
          lVar17 = (**(code **)(**(long **)(*(long *)(lVar13 + 0x1e0) + 0x60) + 0x78))();
          thunk_EXT_FUN_8011000003a61d70(lVar17,0xff,0x4000);
          puVar21 = (undefined8 *)(lVar17 + 0x4010);
          lVar15 = 0x1000;
          auVar36 = NEON_fmov(0x3f800000,4);
          do {
            puVar21[-1] = auVar36._8_8_;
            puVar21[-2] = auVar36._0_8_;
            puVar21[1] = auVar36._8_8_;
            *puVar21 = auVar36._0_8_;
            uVar8 = _UNK_fffffff007113d68;
            uVar2 = _DAT_fffffff007113d60;
            puVar21 = puVar21 + 4;
            lVar15 = lVar15 + -8;
          } while (lVar15 != 0);
          iVar11 = 0x400;
          puVar21 = (undefined8 *)(lVar17 + 0x8000);
          do {
            puVar21[1] = uVar8;
            *puVar21 = uVar2;
            iVar11 = iVar11 + -1;
            puVar21 = puVar21 + 2;
          } while (iVar11 != 0);
          puVar21 = (undefined8 *)(lVar17 + 0xc010);
          lVar15 = 0x800;
          do {
            puVar21[-1] = 0xffff00ffffff;
            puVar21[-2] = 0xffff00ffffff;
            puVar21[1] = 0xffff00ffffff;
            *puVar21 = 0xffff00ffffff;
            puVar21 = puVar21 + 4;
            lVar15 = lVar15 + -4;
          } while (lVar15 != 0);
          lVar15 = 0x800;
          puVar21 = (undefined8 *)(lVar17 + 0x10000);
          do {
            puVar21[1] = 0x7fff7ffe;
            *puVar21 = 0x7fff7ffe;
            puVar21[3] = 0x7fff7ffe;
            puVar21[2] = 0x7fff7ffe;
            auVar36 = _DAT_fffffff007113d70;
            lVar15 = lVar15 + -4;
            puVar21 = puVar21 + 4;
          } while (lVar15 != 0);
          iVar11 = 0x400;
          puVar21 = (undefined8 *)(lVar17 + 0x14000);
          do {
            puVar21[1] = auVar36._8_8_;
            *puVar21 = auVar36._0_8_;
            iVar11 = iVar11 + -1;
            puVar21 = puVar21 + 2;
          } while (iVar11 != 0);
          lVar15 = *(long *)(lVar13 + 0x1e0);
          thunk_EXT_FUN_8011000003222de0(uVar32);
          if (lVar15 == 0) {
            return 0;
          }
        }
        else {
          thunk_EXT_FUN_8011000003222de0(uVar32);
        }
        if (((*(ulong *)(param_3 + 0x58) ^ 0xffffffffffffffff) & 0x18000000000000) == 0) {
          lVar13 = 0;
        }
        else {
          lVar13 = (**(code **)(**(long **)(lVar15 + 0x58) + 0x98))();
          lVar13 = (*(ulong *)(param_3 + 0x58) >> 0x24 & 0x1c000) + lVar13;
        }
        *(long *)(lVar14 + 0x118) = lVar13;
      }
      uVar19 = (uint)*(undefined8 *)(param_3 + 0x58);
      if ((uVar19 >> 0x1b & 1) != 0) {
        uVar19 = uVar19 >> 0x1c & 7;
        if (uVar19 - 2 < 3) {
          uVar12 = (ulong)(*(uint *)(param_3 + 0x14) >> 0xf & 1);
          if (param_3 == 0) {
            return uVar12;
          }
          if ((*(uint *)(param_3 + 0x14) >> 0xf & 1) == 0) {
            return uVar12;
          }
        }
        else if ((uVar19 < 2) ||
                ((uVar19 == 5 && ((*(byte *)(*(long *)(param_1 + 0x50) + 0x5ce) >> 1 & 1) != 0)))) {
          uVar19 = *(uint *)(param_3 + 0x14) & 0x8000;
          uVar12 = (ulong)(uVar19 == 0);
          if (param_3 == 0) {
            return uVar12;
          }
          if (uVar19 != 0) {
            return uVar12;
          }
        }
      }
      goto LAB_fffffff0081f9418;
    }
  }
  else {
    bVar9 = *(char *)(param_3 + 0x13) != '\0';
    if (cVar18 == -0x80) goto LAB_fffffff0081f8b18;
LAB_fffffff0081f8ba8:
    if (cVar18 != -0x7e) goto LAB_fffffff0081f8bb0;
LAB_fffffff0081f8b20:
    lVar13 = thunk_EXT_FUN_801100000295198c(param_1);
    lVar14 = *(long *)(lVar13 + 0x28);
    uVar32 = *(undefined8 *)(*(long *)(lVar13 + 0x30) + 0x10);
    iVar11 = thunk_EXT_FUN_8011000002c26750(uVar32);
    if (iVar11 == 0) {
      if ((param_3 != 0) && ((*(byte *)(param_3 + 0x58) & 1) != 0)) {
        uVar12 = FUN_fffffff0081f9868(param_1,param_3,1);
        if ((uVar12 & 1) == 0) {
          return 0;
        }
        goto LAB_fffffff0081f9418;
      }
      *(undefined1 *)(lVar14 + 0xe8) = 0;
    }
    else {
      uVar12 = thunk_EXT_FUN_8011000002c1e9b0
                         (uVar32,*(undefined4 *)(*(long *)(lVar13 + 0x30) + 0x4c));
      if ((uVar12 & 0xffffffff & DAT_fffffff00ae21810 >> 4) != 0) {
        return 0;
      }
      uVar19 = (uint)(uVar12 >> 8) & 0xffffff;
      if ((uint)uVar12 < 0x200 || 0xffffffef < uVar19 - 0x11) {
        return 0;
      }
      if ((uVar19 - 1 & 0xfffffff0) != 0x10) {
        return 0;
      }
      *(undefined1 *)(lVar14 + 0xe8) = 1;
      *(undefined4 *)(lVar14 + 0xf0) = 0x20;
      *(uint *)(lVar14 + 0xf4) = uVar19;
    }
  }
  if (param_3 == 0) {
    return 1;
  }
LAB_fffffff0081f9418:
  *(byte *)(param_1 + 0xb0) = (byte)(*(uint *)(param_3 + 0x14) >> 0xd) & 1;
  *(byte *)(param_1 + 0xc0) = (byte)(uint)((ulong)*(undefined8 *)(param_3 + 0x58) >> 0x23) & 1;
  *(byte *)(param_1 + 0xc1) = (byte)(uint)((ulong)*(undefined8 *)(param_3 + 0x58) >> 0x24) & 1;
  *(byte *)(param_1 + 0xc2) = (byte)(uint)((ulong)*(undefined8 *)(param_3 + 0x58) >> 0x26) & 1;
  uVar12 = *(ulong *)(param_3 + 0x20);
  if (uVar12 == 0) {
    return 1;
  }
  uVar22 = uVar12 >> 0x20;
  if (0x10 < uVar22) {
    if (uVar12 >> 0x21 < 9) {
      iVar11 = 1;
    }
    else {
      if (uVar22 < 0x13) {
        return 0;
      }
      if (uVar12 >> 0x22 < 5) {
        iVar11 = 2;
      }
      else if (uVar12 < 0x14ffc00000) {
        iVar11 = 3;
      }
      else if (uVar22 < 0x15) {
        iVar11 = 4;
      }
      else if (uVar12 >> 0x24 < 7) {
        iVar11 = 5;
      }
      else {
        if (uVar12 < 0xffffff9fffe00000) {
          return 0;
        }
        if (uVar12 < 0xffffffa000000000) {
          iVar11 = 7;
        }
        else if (uVar12 < 0xffffffa0c0000000) {
          iVar11 = 8;
        }
        else if (uVar12 < 0xffffffa180000000) {
          iVar11 = 9;
        }
        else if (uVar12 < 0xffffffa181400000) {
          iVar11 = 10;
        }
        else if (uVar12 < 0xffffffa185400000) {
          iVar11 = 0xb;
        }
        else {
          if (0xffffffa1893fffff < uVar12) {
            return 0;
          }
          iVar11 = 0xc;
        }
      }
    }
    if (!CARRY8(uVar12,*(ulong *)(param_3 + 0x28))) {
      uVar12 = (uVar12 + *(ulong *)(param_3 + 0x28)) - 1;
      uVar22 = uVar12 >> 0x20;
      if (0x10 < uVar22) {
        if (uVar12 >> 0x21 < 9) {
          iVar24 = 1;
        }
        else {
          if (uVar22 < 0x13) {
            return 0;
          }
          if (uVar12 >> 0x22 < 5) {
            iVar24 = 2;
          }
          else if (uVar12 < 0x14ffc00000) {
            iVar24 = 3;
          }
          else if (uVar22 < 0x15) {
            iVar24 = 4;
          }
          else if (uVar12 >> 0x24 < 7) {
            iVar24 = 5;
          }
          else {
            if (uVar12 < 0xffffff9fffe00000) {
              return 0;
            }
            if (uVar12 < 0xffffffa000000000) {
              iVar24 = 7;
            }
            else if (uVar12 < 0xffffffa0c0000000) {
              iVar24 = 8;
            }
            else if (uVar12 < 0xffffffa180000000) {
              iVar24 = 9;
            }
            else if (uVar12 < 0xffffffa181400000) {
              iVar24 = 10;
            }
            else if (uVar12 < 0xffffffa185400000) {
              iVar24 = 0xb;
            }
            else {
              if (0xffffffa1893fffff < uVar12) {
                return 0;
              }
              iVar24 = 0xc;
            }
          }
        }
        return (ulong)(iVar11 == iVar24);
      }
    }
  }
  return 0;
}

