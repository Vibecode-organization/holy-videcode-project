// FUN_fffffff00a2217b4 @ fffffff00a2217b4 size=1584
// CALLERS:
//   fffffff00a366c90 FUN_fffffff00a366b28@fffffff00a366b28
//   fffffff00a8d9cf8 FUN_fffffff00a8d96f4@fffffff00a8d96f4
//   fffffff00a8da2d0 FUN_fffffff00a8d96f4@fffffff00a8d96f4
//   fffffff00a8d7ba8 FUN_fffffff00a8d7a58@fffffff00a8d7a58
//   fffffff00a8d7d6c FUN_fffffff00a8d7c28@fffffff00a8d7c28
//   fffffff00a8d59b4 FUN_fffffff00a8d4630@fffffff00a8d4630
//   fffffff00a43994c FUN_fffffff00a439874@fffffff00a439874
//   fffffff00a45cbcc FUN_fffffff00a45caf4@fffffff00a45caf4
//   fffffff00a345450 FUN_fffffff00a345240@fffffff00a345240
//   fffffff00a89e58c FUN_fffffff00a89e50c@fffffff00a89e50c
//   fffffff00a54bac0 FUN_fffffff00a54ba08@fffffff00a54ba08
//   fffffff00a5b87d8 FUN_fffffff00a5b8704@fffffff00a5b8704
//   fffffff00a818104 FUN_fffffff00a81801c@fffffff00a81801c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16]
FUN_fffffff00a2217b4
          (long *param_1,ulong param_2,ulong param_3,ulong param_4,ulong param_5,ulong param_6,
          ulong param_7)

{
  bool bVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  uint uVar8;
  ulong uVar9;
  long lVar10;
  undefined8 *puVar11;
  ulong extraout_x1;
  uint uVar12;
  ulong uVar13;
  byte bVar14;
  ulong uVar15;
  int iVar16;
  uint uVar17;
  undefined *puVar18;
  long *plVar19;
  ulong uVar20;
  long lVar21;
  uint uVar22;
  ulong uVar23;
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  ulong local_80;
  long local_70;
  long local_68;
  
  local_68 = 0;
  if (param_3 >> 0x24 != 0) {
    FUN_fffffff00aa50068(param_2,param_3);
    goto LAB_fffffff00a221db0;
  }
  if ((param_2 == 0) && (param_4 == 0)) {
    return ZEXT816(0);
  }
  if (((ulong)param_1 & 1) == 0) {
    uVar17 = (uint)*(ushort *)((long)param_1 + 0x14);
    uVar12 = (uint)*(ushort *)((long)param_1 + 0x16);
    plVar19 = param_1;
LAB_fffffff00a2218f8:
    lVar21 = *plVar19;
    if (param_4 == 0) goto LAB_fffffff00a221904;
LAB_fffffff00a221860:
    local_70 = 0;
    if (((*(byte *)(plVar19 + 2) & 0xfe) != 2) &&
       (lVar10 = tpidr_el1,
       *(int *)(lVar21 + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000 + 0x1c) == 0)) {
      param_5 = (ulong)((uint)param_5 | 0x40);
      uVar12 = (uint)DAT_fffffff007bc317e;
    }
    uVar23 = param_4;
    if ((param_5 & 0x100) != 0) {
      uVar23 = param_4 + 0x1f & 0xffffffffffffffe0;
    }
    if (uVar23 < 0x8001) {
      uVar22 = (int)uVar23 - 1;
      iVar16 = (int)LZCOUNT(uVar22);
      iVar16 = uVar12 + (uVar22 >> (ulong)(0x1eU - iVar16 & 0x1f)) + iVar16 * -2;
      if (0x10 < uVar23) {
        uVar12 = uVar12 + 1;
      }
      uVar22 = iVar16 + 0x34;
      if (uVar23 < 0x21) {
        uVar22 = uVar12;
      }
      lVar10 = ((ulong)uVar22 & 0xffff) * 0xc0;
      puVar18 = &DAT_fffffff00ad4c240 + lVar10;
      if (puVar18 == (undefined *)0x0) goto LAB_fffffff00a221910;
      uVar23 = (ulong)*(ushort *)(&DAT_fffffff00ad4c274 + lVar10);
    }
    else {
LAB_fffffff00a221910:
      if (0xffffffffffffc000 < param_4) {
LAB_fffffff00a221db0:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114("overflow detected @%s:%d");
      }
      puVar18 = (undefined *)0x0;
      uVar23 = param_4 + 0x3fff & 0xffffffffffffc000;
    }
  }
  else {
    uVar23 = (ulong)param_1 & 0xfffffffffffffffe;
    uVar17 = *(uint *)(uVar23 + 0x48);
    plVar19 = (long *)&DAT_fffffff007c28060;
    if ((uVar17 & 0x8000) != 0) {
      plVar19 = &DAT_fffffff007bca7f8;
    }
    if ((uVar17 & 8) != 0) {
      plVar19 = &DAT_fffffff007c6afb0;
    }
    lVar21 = *(long *)(uVar23 + 8);
    uVar17 = uVar17 >> 0x10;
    uVar12 = (uint)*(ushort *)((long)plVar19 + 0x16);
    if (*(ushort *)(uVar23 + 0x20) != 0) {
      uVar12 = (uint)*(ushort *)(uVar23 + 0x20);
    }
    if (lVar21 == 0) goto LAB_fffffff00a2218f8;
    if (param_4 != 0) goto LAB_fffffff00a221860;
LAB_fffffff00a221904:
    uVar23 = 0;
    puVar18 = (undefined *)0x0;
  }
  local_70 = 0;
  uVar20 = param_4;
  if ((param_5 & 0x200) != 0) {
    uVar20 = uVar23;
  }
  if (param_2 == 0) {
    uVar9 = 0;
    local_80 = 0;
LAB_fffffff00a221a74:
    local_70 = 0;
    param_3 = local_80;
    if (uVar20 <= local_80) {
      param_3 = uVar20;
    }
    if (uVar9 == uVar23) goto LAB_fffffff00a221d3c;
    if (((puVar18 == (undefined *)0x0) && (param_2 != 0)) && (uVar20 != 0)) {
      auVar24 = FUN_fffffff00a221de4(plVar19,param_2,local_80,uVar20,param_5,uVar17,param_6);
      return auVar24;
    }
    if (uVar20 != 0) {
      bVar14 = 0;
      if (puVar18 == (undefined *)0x0) goto LAB_fffffff00a221bb4;
LAB_fffffff00a221acc:
      if (lVar21 == 0) {
        lVar21 = *(long *)(puVar18 + 8);
      }
      auVar24 = FUN_fffffff00a292e20(puVar18,lVar21,(uint)param_5 & 0xfffffeff);
      uVar20 = auVar24._8_8_;
      uVar23 = auVar24._0_8_;
      if (uVar23 != 0) {
        if ((param_5 & 0x200) != 0) {
          param_4 = uVar20;
        }
        auVar5._8_8_ = param_4;
        auVar5._0_8_ = uVar23;
        auVar4._8_8_ = param_4;
        auVar4._0_8_ = uVar23;
        auVar24._8_8_ = param_4;
        auVar24._0_8_ = uVar23;
        uVar15 = param_4 + 0xf & 0xfffffffffffffff0;
        if (uVar15 < 0x11) {
          uVar15 = 0x10;
        }
        if ((((uVar20 + uVar23 & 0x3fff) == 0) &&
            (lVar21 = uVar20 - uVar15, auVar24 = auVar4, lVar21 != 0)) &&
           (auVar24 = auVar5,
           (*(ushort *)((uVar23 >> 10 & 0xffffffff0) + DAT_fffffff007bc7148) >> 10 & 1) != 0)) {
          *(short *)((uVar20 + uVar23 >> 10 & 0xffffffff0) + DAT_fffffff007bc7148 + 2) =
               (short)lVar21;
          uVar20 = uVar23 + lVar21;
          auVar24._0_8_ = uVar20;
          if (((uVar23 ^ uVar20) & 0xffc0000000000000) != 0) {
            auVar24._0_8_ = uVar20 & 0xffffffffffff | 0xc8a2000000000000;
          }
        }
        goto LAB_fffffff00a221c00;
      }
      if (param_2 == 0) {
        auVar7._8_8_ = 0;
        auVar7._0_8_ = uVar20;
        return auVar7 << 0x40;
      }
      goto LAB_fffffff00a221c70;
    }
    auVar24 = ZEXT816(0);
    if (param_2 == 0) {
      return ZEXT816(0) << 0x40;
    }
    goto LAB_fffffff00a221c7c;
  }
  local_80 = param_3;
  if (0x8000 < param_3) {
    uVar9 = param_3 + 0x3fff & 0x1fffffc000;
    goto LAB_fffffff00a221a74;
  }
  uVar15 = param_6;
  uVar9 = FUN_fffffff00a29647c(param_2,&local_70,1,&local_68);
  if ((uVar9 == 0) || (uVar9 < local_68 + param_3)) {
    lVar21 = local_68;
    auVar24 = FUN_fffffff00aa4fe9c(local_70,param_2);
    puVar11 = auVar24._0_8_;
    uVar17 = (uint)uVar9;
    if ((uVar17 >> 0xf & 1) == 0) {
      uVar23 = 0;
      if (param_3 >> 0x26 == 0) {
        uVar20 = 0;
        if ((uVar9 & 1) == 0) {
          uVar12 = 0x4000104;
          if ((uVar9 & 0x800) != 0) {
            uVar12 = 0x4000004;
          }
          uVar12 = uVar17 & 2 | ((uint)(uVar9 >> 2) & 1) << 7 | uVar12;
          uVar22 = uVar12 | 0x8000;
          if (puVar11 != (undefined8 *)&DAT_fffffff007c2e100) {
            uVar22 = uVar12;
          }
          uVar12 = uVar12 | 0x4000;
          if (puVar11 != &DAT_fffffff007c6afb0) {
            uVar12 = uVar22;
          }
          uVar22 = uVar17 >> 0x10;
          if (((uVar17 >> 0xc & 1) != 0) && (uVar8 = FUN_fffffff00a33134c(), uVar8 != 0)) {
            uVar22 = uVar8;
          }
          if (uVar22 == 0) {
            uVar22 = (uint)*(ushort *)((long)puVar11 + 0x12);
          }
          uVar8 = (int)(param_7 >> 4) * 0x5052acdb;
          uVar2 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8;
          FUN_fffffff00a2de484
                    (DAT_fffffff007c678d8,auVar24._8_8_,lVar21,param_3,uVar12 | uVar17 & 8,
                     (uVar15 & 0xffffffff) << 0x10 |
                     (ulong)(((uVar2 >> 0x10 | uVar2 << 0x10) ^ uVar8) << 1 | 1) << 0x20 |
                     (ulong)uVar22);
          uVar23 = lVar21 + 0x3fffU & 0x1fffffc000;
          if (extraout_x1 == 0) {
            if ((uVar9 & 8) == 0) {
              lVar21 = 0;
            }
            else {
              lVar21 = tpidr_el1;
              plVar19 = (long *)(_DAT_fffffff00ad0c2a0 + (ulong)*(ushort *)(lVar21 + 0x1b0) * 0x4000
                                );
              *plVar19 = *plVar19 + -1;
              lVar21 = -uVar23;
            }
          }
          else {
            lVar21 = (param_3 + 0x3fff & 0x7fffffc000) - uVar23;
          }
          lVar10 = tpidr_el1;
          plVar19 = (long *)(_DAT_fffffff00ad0e300 + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
          *plVar19 = *plVar19 + lVar21;
          FUN_fffffff00a223f24(*(undefined8 *)(lVar10 + 0x4b8),DAT_fffffff007bf16c4);
          uVar23 = extraout_x1;
          if (extraout_x1 == 0) {
            uVar20 = 0;
          }
          else {
            uVar20 = param_3;
            if ((uVar17 >> 8 & 1) != 0) {
              uVar23 = extraout_x1 & 0xffffffbfffffffff | param_3 >> 0xe;
            }
          }
        }
      }
      else {
        uVar20 = 0;
      }
      auVar25._8_8_ = uVar20;
      auVar25._0_8_ = uVar23;
      return auVar25;
    }
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("trying to kalloc(Z_NOFAIL) with a large size (%zd) @%s:%d");
  }
  if (uVar20 <= param_3) {
    param_3 = uVar20;
  }
  if (uVar9 == uVar23) {
    uVar9 = param_2 - local_68;
    if (((param_2 ^ uVar9) & 0xffc0000000000000) != 0) {
      uVar9 = uVar9 & 0xffffffffffff | 0xc8a2000000000000;
    }
    uVar15 = uVar20 + 0xf & 0xfffffffffffffff0;
    if (uVar15 < 0x11) {
      uVar15 = 0x10;
    }
    uVar13 = uVar9;
    if ((((uVar23 + uVar9 & 0x3fff) == 0) && (lVar21 = uVar23 - uVar15, lVar21 != 0)) &&
       ((*(ushort *)((uVar9 >> 10 & 0xffffffff0) + DAT_fffffff007bc7148) >> 10 & 1) != 0)) {
      *(short *)((uVar23 + uVar9 >> 10 & 0xffffffff0) + DAT_fffffff007bc7148 + 2) = (short)lVar21;
      uVar13 = uVar9 + lVar21;
      if (((uVar9 ^ uVar13) & 0xffc0000000000000) != 0) {
        uVar13 = uVar13 & 0xffffffffffff | 0xc8a2000000000000;
      }
    }
    if (uVar13 != param_2) {
      FUN_fffffff00aa65b10(uVar13,param_2,param_3);
      uVar23 = uVar13 + param_3;
      if (((uVar13 ^ uVar23) & 0xffc0000000000000) != 0) {
        uVar23 = uVar23 & 0xffffffffffff | 0xc8a2000000000000;
      }
      FUN_fffffff00aa65cc0(uVar23,uVar20 - param_3);
      param_2 = uVar13;
    }
    param_5 = param_5 & 0xffffffff;
    goto LAB_fffffff00a221d3c;
  }
  param_5 = param_5 & 0xffffffff;
  if (uVar20 == 0) {
    auVar24 = ZEXT816(0);
LAB_fffffff00a221c7c:
    if (local_70 == 0) {
      uVar17 = (int)(param_6 >> 4) * 0x5052acdb;
      uVar12 = (uVar17 & 0xff00ff00) >> 8 | (uVar17 & 0xff00ff) << 8;
      lVar10 = FUN_fffffff00a2defc4
                         (DAT_fffffff007c678d8,param_2,local_80,0xc000000,
                          (ulong)(((uVar12 >> 0x10 | uVar12 << 0x10) ^ uVar17) << 1 | 1) << 0x20);
      lVar21 = tpidr_el1;
      plVar19 = (long *)(_DAT_fffffff00ad0c2a0 + (ulong)*(ushort *)(lVar21 + 0x1b0) * 0x4000);
      *plVar19 = *plVar19 + -1;
      plVar19 = (long *)(_DAT_fffffff00ad0e300 + (ulong)*(ushort *)(lVar21 + 0x1b0) * 0x4000);
      *plVar19 = *plVar19 - lVar10;
      FUN_fffffff00a223a40(*(undefined8 *)(lVar21 + 0x4b8),DAT_fffffff007bf16c4,lVar10);
    }
    else {
      uVar23 = param_2 - local_68;
      if (((param_2 ^ uVar23) & 0xffc0000000000000) != 0) {
        uVar23 = uVar23 & 0xffffffffffff | 0xc8a2000000000000;
      }
      FUN_fffffff00a2213e4(param_1,uVar23,local_80,local_70,uVar9);
    }
  }
  else {
    bVar14 = 1;
    if (puVar18 != (undefined *)0x0) goto LAB_fffffff00a221acc;
LAB_fffffff00a221bb4:
    bVar1 = false;
    if (param_2 != 0) {
      bVar1 = (bool)(bVar14 ^ 1);
    }
    if (bVar1) {
      uVar20 = 0;
LAB_fffffff00a221c70:
      auVar6._8_8_ = 0;
      auVar6._0_8_ = uVar20;
      auVar24 = auVar6 << 0x40;
      if (((uint)param_5 >> 3 & 1) == 0) {
        return auVar24;
      }
      goto LAB_fffffff00a221c7c;
    }
    auVar24 = FUN_fffffff00a220e10(plVar19,uVar20,(uint)param_5 & 0xfffffeff,uVar17,param_6);
LAB_fffffff00a221c00:
    uVar20 = auVar24._8_8_;
    lVar21 = auVar24._0_8_;
    if ((param_2 != 0) && (lVar21 != 0)) {
      FUN_fffffff00aa65b10(lVar21,param_2,param_3);
      goto LAB_fffffff00a221c7c;
    }
    if (param_2 != 0) {
      if (lVar21 == 0) goto LAB_fffffff00a221c70;
      goto LAB_fffffff00a221c7c;
    }
  }
  uVar20 = auVar24._8_8_;
  param_2 = auVar24._0_8_;
  if (param_2 == 0) {
    return auVar24;
  }
LAB_fffffff00a221d3c:
  auVar3._8_8_ = uVar20;
  auVar3._0_8_ = param_2;
  if (((uint)param_5 >> 8 & 1) != 0) {
    if (puVar18 == (undefined *)0x0) {
      auVar3._0_8_ = param_2 & 0xffffffbfffffffff | uVar20 >> 0xe;
    }
    else {
      auVar3._0_8_ = *(uint *)(puVar18 + 0xb4) | param_2;
    }
  }
  return auVar3;
}

