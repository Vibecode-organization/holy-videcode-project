// FUN_fffffff00a69754c @ fffffff00a69754c size=396

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_fffffff00a69754c(int *param_1)

{
  char *pcVar1;
  ulong *puVar2;
  byte bVar3;
  undefined2 uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  uint uVar8;
  long lVar9;
  bool bVar10;
  bool bVar11;
  int iVar12;
  uint uVar13;
  undefined8 *puVar14;
  undefined4 uVar15;
  int *piVar16;
  long lVar17;
  long lVar18;
  long *plVar19;
  undefined4 *puVar20;
  undefined8 uVar21;
  uint uVar22;
  uint uVar23;
  undefined4 *puVar24;
  ulong uVar25;
  uint uVar26;
  long lVar27;
  long lVar28;
  long lVar29;
  uint uVar30;
  uint uVar31;
  int in_wzr;
  undefined4 in_register_000040fc;
  undefined1 auVar32 [16];
  uint uStack_a8;
  int iStack_a4;
  undefined8 local_38;
  
  puVar14 = *(undefined8 **)(param_1 + 0x18e);
  *(long *)(param_1 + 0x18e) = CONCAT44(in_register_000040fc,in_wzr);
  if (puVar14 == (undefined8 *)0x0) {
    return param_1;
  }
  lVar18 = tpidr_el1;
  if ((*(ushort *)(lVar18 + 0x528) >> 5 & 1) != 0) {
    *(undefined8 *)(lVar18 + 0x2c8) = 0;
  }
  FUN_fffffff00a23f988(*puVar14);
  FUN_fffffff00a23f988(puVar14[1]);
  FUN_fffffff00a23f988(puVar14[2]);
  FUN_fffffff00a23ef14(*puVar14);
  FUN_fffffff00a23ef14(puVar14[1]);
  FUN_fffffff00a23ef14(puVar14[2]);
  lVar28 = puVar14[0x1c];
  while (lVar27 = lVar28, lVar27 != 0) {
    lVar28 = *(long *)(lVar27 + 0x1b8);
    *(undefined8 *)(lVar27 + -0x2c8) = 0;
    if (lVar27 != 0x590) {
      piVar16 = (int *)(lVar27 + -0x378);
      iVar12 = *piVar16;
      *piVar16 = iVar12 + -1;
      LORelease();
      if (iVar12 == 0) goto LAB_fffffff00a697628;
      if (iVar12 == 1) {
        in_wzr = *(int *)(lVar27 + -0x378);
        FUN_fffffff00a2348d4();
      }
    }
  }
  piVar16 = (int *)(puVar14 + 7);
  iVar12 = *piVar16;
  *piVar16 = iVar12 + -1;
  if (iVar12 == 0) {
LAB_fffffff00a697628:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa210d4(piVar16);
  }
  if (iVar12 != 1) {
    return piVar16;
  }
  local_38 = 0;
  puVar20 = (undefined4 *)puVar14[3];
  puVar24 = *(undefined4 **)(puVar20 + 6);
  if (puVar24 == (undefined4 *)0x0) {
    uVar21 = 0;
    puVar14[3] = 0;
  }
  else {
    *(undefined8 *)(puVar20 + 6) = *(undefined8 *)(puVar24 + 6);
    *(undefined8 *)(puVar24 + 6) = 0;
    uVar21 = puVar14[3];
    puVar20 = puVar24;
  }
  FUN_fffffff00a24a064(puVar14,lVar18,puVar20,uVar21,&local_38);
  FUN_fffffff00a24b800();
  FUN_fffffff00a2499a4(local_38);
  if (*(uint *)(puVar14 + 4) >> 0x18 == 0x44) {
    *(uint *)(puVar14 + 4) = *(uint *)(puVar14 + 4) & 0xffffff;
    *(undefined4 *)(puVar14 + 5) = 0;
    lVar18 = *DAT_fffffff007bfa3a0;
    lVar28 = DAT_fffffff007bfa3a0[1];
    uVar4 = *(undefined2 *)(lVar18 + 0x34);
    FUN_fffffff00aa24ee0(puVar14,uVar4);
    piVar16 = (int *)FUN_fffffff00a255e34(lVar18,lVar28,puVar14,uVar4);
    return piVar16;
  }
  auVar32 = FUN_fffffff00aa10404(puVar14 + 4);
  plVar19 = auVar32._8_8_;
  lVar18 = auVar32._0_8_;
  lVar28 = *plVar19;
  if (0x400 < lVar28) {
    if (lVar28 < 0x1000) {
      if (lVar28 - 0x401U < 2) {
        return (int *)0x2d;
      }
      if (((lVar28 == 0x800) && (plVar19[3] == 0)) && (uVar25 = plVar19[2], uVar25 < 8)) {
        uVar13 = (uint)plVar19[1];
        if (((uint)uVar25 >> 1 & 1) == 0) {
          if (0xfffffff9 < (uVar13 & 0xff) - 7) {
LAB_fffffff00a697bd0:
            uVar15 = FUN_fffffff00a205420(uVar13 & 0xff,uVar25);
            *puVar20 = uVar15;
            return (int *)0x0;
          }
        }
        else if ((plVar19[1] & 0xffU) == 0) goto LAB_fffffff00a697bd0;
      }
    }
    else if (lVar28 == 0x1000) {
      if ((plVar19[2] == 0) && (plVar19[3] == 0)) {
        lVar18 = tpidr_el1;
        if ((*(ushort *)(lVar18 + 0x528) >> 5 & 1) == 0) {
          return (int *)0x0;
        }
        *(bool *)(lVar18 + 0x5d9) = plVar19[1] != 0;
        return (int *)0x0;
      }
    }
    else {
      if (lVar28 == 0x2000) {
        uVar21 = tpidr_el1;
        if (plVar19[1] == 2) {
          iVar12 = FUN_fffffff00a238e14(uVar21,0,0);
          uVar13 = 0;
          if (iVar12 != 0) {
            uVar13 = 0x16;
          }
          return (int *)(ulong)uVar13;
        }
        if (plVar19[1] == 1) {
          iVar12 = FUN_fffffff00a238cac(uVar21,plVar19,0,0);
          uVar13 = 0;
          if (iVar12 != 0) {
            uVar13 = 0x16;
          }
          return (int *)(ulong)uVar13;
        }
        return (int *)0x16;
      }
      if ((lVar28 == 0x4000) && (uVar13 = *(uint *)(plVar19 + 1), (uVar13 & 0x4011fd8) == 0)) {
        lVar28 = tpidr_el1;
        puVar2 = (ulong *)(lVar18 + 0x58);
        if (*puVar2 == 0) {
          *puVar2 = (ulong)*(uint *)(lVar28 + 0x4e8);
        }
        else {
          FUN_fffffff00a1ea02c(lVar18 + 0x50,lVar28,0);
        }
        *(uint *)(lVar18 + 0x554) = *(uint *)(lVar18 + 0x554) | uVar13;
        if (*(int *)puVar2 == *(int *)(lVar28 + 0x4e8)) {
          *(int *)puVar2 = in_wzr;
          return (int *)0x0;
        }
        lVar18 = lVar18 + 0x50;
        goto LAB_fffffff00a698004;
      }
    }
    return (int *)0x16;
  }
  if (lVar28 < 0x100) {
    if (lVar28 == 0x10) {
      return (int *)0x2d;
    }
    if (lVar28 == 0x40) {
      uVar25 = plVar19[2];
      if ((uVar25 & 0x22000000) != 0) {
        return (int *)0x16;
      }
      if ((uVar25 & 0x3f00) == 0) {
        return (int *)0x16;
      }
      uVar13 = (uint)uVar25 >> 8;
      if ((uVar13 & 0x3f) == 0) {
        return (int *)0x16;
      }
      lVar27 = plVar19[3];
      lVar28 = FUN_fffffff00a1e19f4((int)plVar19[1],1);
      if (lVar28 != 0) {
        uVar13 = (uVar13 & 0x2a) >> 1 | (uVar13 & 0x15) << 1;
        lVar29 = 0;
        if ((*(uint *)(lVar18 + 0x448) & 2) != 0) {
          lVar29 = lVar18 + 0x768;
        }
        piVar16 = (int *)FUN_fffffff00a245aac
                                   (lVar29,lVar28,0,
                                    (int)LZCOUNT(((uVar13 & 0x33333333) >> 2 |
                                                 ((uVar13 & 0xcccccccc) >> 2 |
                                                 (uVar13 & 0x3030303) << 2) << 4) << 0x18) + 1,1,
                                    lVar27,3);
        goto LAB_fffffff00a6979cc;
      }
    }
    else {
      if (lVar28 != 0x80) {
        return (int *)0x16;
      }
      if (plVar19[3] != 0) {
        return (int *)0x16;
      }
      lVar27 = plVar19[2];
      lVar28 = FUN_fffffff00a1e19f4((int)plVar19[1],1);
      if (lVar28 != 0) {
        lVar29 = 0;
        if ((*(uint *)(lVar18 + 0x448) & 2) != 0) {
          lVar29 = lVar18 + 0x768;
        }
        piVar16 = (int *)FUN_fffffff00a245e98(lVar29,lVar28,0,lVar27,3);
LAB_fffffff00a6979cc:
        FUN_fffffff00a23590c(lVar28);
        return piVar16;
      }
    }
    return (int *)0x3;
  }
  if (lVar28 != 0x100) {
    if (lVar28 == 0x200) {
      lVar28 = tpidr_el1;
      if ((*(ushort *)(lVar28 + 0x528) >> 5 & 1) == 0) {
        return (int *)0x1;
      }
      lVar27 = 0;
      if (*(long *)(lVar18 + 0x638) != -1) {
        lVar27 = *(long *)(lVar18 + 0x638);
      }
      if (*(ulong *)(lVar28 + 0x438) == 0) {
        *(ulong *)(lVar28 + 0x438) = (ulong)*(uint *)(lVar28 + 0x4e8);
      }
      else {
        FUN_fffffff00a1ea02c(lVar28 + 0x430,lVar28,0);
      }
      *(int *)(lVar28 + 0x1c0) = *(int *)(lVar28 + 0x1c0) + 1;
      LOAcquire();
      uVar13 = *(uint *)(lVar27 + 0x28);
      *(uint *)(lVar27 + 0x28) = uVar13 + 0x1000000;
      if ((uVar13 >> 0x10 & 0xff) == uVar13 >> 0x18) {
        *(undefined4 *)(lVar27 + 0x2c) = *(undefined4 *)(lVar28 + 0x4e8);
      }
      else {
        FUN_fffffff00a1ef300(lVar27 + 0x20,uVar13 >> 0x18,lVar28);
      }
      FUN_fffffff00a692f40
                (lVar18,lVar27,lVar28 + 0x590,*(ushort *)(lVar28 + 0x764),
                 *(ushort *)(lVar28 + 0x764) & 0xf0ff,0);
      FUN_fffffff00a1ef5a8(lVar27 + 0x20);
      if (*(int *)(lVar28 + 0x438) == *(int *)(lVar28 + 0x4e8)) {
        *(int *)(lVar28 + 0x438) = in_wzr;
        return (int *)0x0;
      }
      lVar18 = lVar28 + 0x430;
LAB_fffffff00a698004:
      FUN_fffffff00a1eab60(lVar18,lVar28);
      return (int *)0x0;
    }
    if (lVar28 != 0x400) {
      return (int *)0x16;
    }
    uVar13 = *(uint *)(plVar19 + 1);
    uVar25 = plVar19[2];
    lVar27 = plVar19[3];
    lVar29 = *(long *)(lVar18 + 0x638);
    lVar28 = 0;
    if (lVar29 != -1) {
      lVar28 = lVar29;
    }
    if ((uVar25 & 0x22000000) != 0) {
      return (int *)0x16;
    }
    if ((uVar25 & 0x3f00) == 0) {
      return (int *)0x16;
    }
    uVar30 = (uint)uVar25 >> 8;
    if ((uVar30 & 0x3f) == 0) {
      return (int *)0x16;
    }
    lVar17 = FUN_fffffff00a1e19f4(uVar13,1);
    if (lVar17 == 0) {
      return (int *)0x3;
    }
    if ((*(ushort *)(lVar17 + 0x528) >> 5 & 1) == 0) {
      FUN_fffffff00a23590c(lVar17);
      return (int *)0x1;
    }
    lVar9 = tpidr_el1;
    if (*(ulong *)(lVar17 + 0x438) == 0) {
      *(ulong *)(lVar17 + 0x438) = (ulong)*(uint *)(lVar9 + 0x4e8);
    }
    else {
      FUN_fffffff00a1ea02c(lVar17 + 0x430,lVar9,0);
    }
    if (lVar27 != 0) {
      uStack_a8 = 0;
      *(undefined1 *)(lVar9 + 1000) = 1;
      FUN_fffffff00a23c1f8();
      iVar12 = FUN_fffffff00a34d14c(lVar27,&uStack_a8);
      *(undefined1 *)(lVar9 + 1000) = 0;
      if ((iVar12 == 0) && ((uStack_a8 | 3) != uVar13)) goto LAB_fffffff00a697d58;
    }
    uVar13 = (uVar30 & 0x2a) >> 1 | (uVar30 & 0x15) << 1;
    uVar22 = (uint)LZCOUNT(((uVar13 & 0x33333333) >> 2 |
                           ((uVar13 & 0xcccccccc) >> 2 | (uVar13 & 0x3030303) << 2) << 4) << 0x18);
    uVar13 = uVar22 + 1;
    FUN_fffffff00a1ef2c0(lVar28 + 0x20);
    uVar5 = *(ushort *)(lVar17 + 0x764);
    uVar30 = uVar5 >> 8 & 0xf;
    if (uVar30 < uVar13) {
      uVar23 = (uVar5 & 0xfffff0ff) + uVar13 * 0x100;
      if (lVar17 == lVar9) {
        FUN_fffffff00a692f40(lVar18,lVar29,lVar17 + 0x590,uVar5,uVar23 & 0xffff,0);
      }
      else {
        *(short *)(lVar17 + 0x764) = (short)uVar23;
        uVar26 = uVar5 >> 4 & 0xf;
        uVar23 = uVar5 & 0xf;
        if ((uVar5 & 0xf) <= uVar26) {
          uVar23 = uVar26;
        }
        if (uVar23 <= uVar30) {
          uVar23 = uVar30;
        }
        uVar30 = (uint)(uVar5 >> 0xc);
        if (uVar5 >> 0xc <= uVar23) {
          uVar30 = uVar23;
        }
        if (uVar30 <= uVar22) {
          FUN_fffffff00a244490(lVar17,uVar13);
        }
      }
    }
    FUN_fffffff00a1ef5a8(lVar28 + 0x20);
LAB_fffffff00a697d58:
    if (*(int *)(lVar17 + 0x438) == *(int *)(lVar9 + 0x4e8)) {
      *(int *)(lVar17 + 0x438) = in_wzr;
    }
    else {
      FUN_fffffff00a1eab60(lVar17 + 0x430,lVar9);
    }
    FUN_fffffff00a23590c(lVar17);
    return (int *)0x0;
  }
  lVar27 = tpidr_el1;
  uVar25 = plVar19[1];
  lVar29 = plVar19[2];
  uVar13 = *(uint *)(plVar19 + 3);
  lVar17 = *(long *)(lVar18 + 0x638);
  lVar28 = 0;
  if (lVar17 != -1) {
    lVar28 = lVar17;
  }
  uVar5 = *(ushort *)(lVar27 + 0x528);
  uVar30 = (int)(uVar13 << 0x1b) >> 0x1f & 0x16;
  if (((uVar13 >> 4 & 1) != 0) && ((uVar5 >> 5 & 1) != 0)) {
    if (*(short *)(lVar27 + 0x764) < -0x7000) {
LAB_fffffff00a697ad8:
      uVar30 = 0x16;
    }
    else if (*(long *)(lVar27 + 0x740) == 0) {
      uVar30 = 0x25;
    }
    else {
      if ((*(byte *)(*(long *)(lVar27 + 0x740) + 0x1a) >> 1 & 1) != 0) goto LAB_fffffff00a697ad8;
      FUN_fffffff00a6c23e4();
      uVar30 = 0;
    }
  }
  if ((uVar13 & 0x41) == 0) {
    if ((uVar13 >> 1 & 1) == 0) goto LAB_fffffff00a697d90;
    uVar22 = 0;
LAB_fffffff00a697d9c:
    iVar12 = FUN_fffffff00a23905c((int)lVar29);
    bVar11 = iVar12 != 0;
    uVar23 = 2;
    if (!bVar11) {
      uVar23 = 0;
    }
    if (uVar22 != 0) {
      if (iVar12 != 0) {
        return (int *)0x5e;
      }
LAB_fffffff00a697de0:
      if (uVar30 != 0) {
        uVar22 = uVar30;
      }
      return (int *)(ulong)uVar22;
    }
  }
  else {
    if ((uVar13 & 1) == 0) {
      uVar22 = 0x16;
      if ((uVar13 >> 1 & 1) == 0) goto LAB_fffffff00a697de0;
      goto LAB_fffffff00a697d9c;
    }
    bVar11 = (uVar25 & 0x22000000) == 0;
    bVar10 = (uVar25 & 0x3f00) != 0;
    uVar31 = (uint)uVar25;
    uVar22 = uVar31 >> 8;
    uVar26 = (uVar22 & 0x2a) >> 1 | (uVar22 & 0x15) << 1;
    uVar23 = 0;
    if ((uVar22 & 0x3f) != 0) {
      uVar23 = (int)LZCOUNT(((uVar26 & 0x33333333) >> 2 |
                            ((uVar26 & 0xcccccccc) >> 2 | (uVar26 & 0x3030303) << 2) << 4) << 0x18)
               + 1;
    }
    uVar26 = 0;
    if (bVar10 && bVar11) {
      uVar26 = uVar23;
    }
    iStack_a4 = 0;
    if (bVar10 && bVar11) {
      iStack_a4 = (char)uVar25 + 1;
    }
    uVar22 = 0x16;
    uStack_a8 = uVar26;
    if ((uVar26 != 0) && (iStack_a4 + 0xfU < 0x10)) {
      if ((uVar13 >> 6 & 1) == 0) {
        uVar23 = 0;
        if (((uVar25 & 0x22800000) == 0x800000) && ((uVar25 & 0x3fc000) != 0)) {
LAB_fffffff00a697d30:
          uVar22 = 0x16;
        }
        else {
LAB_fffffff00a697cc0:
          if ((uVar5 >> 5 & 1) == 0) {
            iVar12 = FUN_fffffff00a24258c(lVar27);
            if (iVar12 == 0) {
              uVar22 = 1;
              goto LAB_fffffff00a697d88;
            }
          }
          else {
            if (((((*(ushort *)(lVar27 + 0x764) >> 0xc) - 7 < 2) ||
                 ((uVar6 = *(ushort *)(lVar27 + 0x766), (uVar31 >> 0x1b & 1) != 0 &&
                  ((uVar6 >> 3 & 1) != 0)))) ||
                (((uVar31 >> 0x1b & 1) == 0 && ((uVar6 >> 8 & 1) != 0)))) ||
               (((uVar31 >> 0x1b & 1) != 0 && ((uVar6 & 0x1108) == 0)))) goto LAB_fffffff00a697d30;
            if (uVar23 != 0) {
              if (*(ulong *)(lVar27 + 0x438) == 0) {
                *(ulong *)(lVar27 + 0x438) = (ulong)*(uint *)(lVar27 + 0x4e8);
              }
              else {
                FUN_fffffff00a1ea02c(lVar27 + 0x430,lVar27,0);
              }
            }
            FUN_fffffff00a1ef2c0(lVar28 + 0x20);
            uVar6 = *(ushort *)(lVar27 + 0x764);
            uVar22 = (uVar6 & 0xf0f0 | uVar26) + uVar23 * 0x100;
            if (uVar23 <= (uVar6 >> 8 & 0xf)) {
              uVar22 = uVar6 & 0xfff0 | uVar26;
            }
            uVar7 = *(ushort *)(lVar27 + 0x766);
            if (((uVar25 & 0x88000000) == 0) && ((uVar7 >> 3 & 1) != 0)) {
              uVar25 = 0;
              *(ushort *)(lVar27 + 0x766) = uVar7 & 0xeef7;
              *(short *)(lVar28 + 0x58) = *(short *)(lVar28 + 0x58) + 1;
            }
            else if (((int)uVar31 < 0) && ((uVar7 & 0x1108) == 0)) {
              *(ushort *)(lVar27 + 0x766) = uVar7 | 8;
              uVar7 = *(ushort *)(lVar28 + 0x58);
              *(ushort *)(lVar28 + 0x58) = uVar7 - 1;
              uVar25 = (ulong)(_DAT_fffffff00acd4c6c == uVar7);
            }
            else if ((uVar7 >> 8 & 1) == 0) {
              uVar25 = 0;
            }
            else {
              bVar3 = 0;
              if ((uVar6 & 0xf) != 1) {
                bVar3 = (char)(uVar6 & 0xf) - 2;
              }
              pcVar1 = (char *)(lVar28 + 0x130 + (ulong)bVar3);
              *pcVar1 = *pcVar1 + -1;
              bVar3 = 0;
              if ((uVar22 & 0xf) != 1) {
                bVar3 = (char)(uVar22 & 0xf) - 2;
              }
              pcVar1 = (char *)(lVar28 + 0x130 + (ulong)bVar3);
              *pcVar1 = *pcVar1 + '\x01';
              uVar25 = FUN_fffffff00a695774(lVar17);
            }
            FUN_fffffff00a692f40(lVar18,lVar17,lVar27 + 0x590,uVar6,uVar22 & 0xffff,uVar25);
            FUN_fffffff00a1ef5a8(lVar28 + 0x20);
            if (uVar23 == 0) {
LAB_fffffff00a697fb4:
              uVar6 = *(ushort *)(lVar27 + 0x766);
            }
            else {
              if (*(int *)(lVar27 + 0x438) == *(int *)(lVar27 + 0x4e8)) {
                *(int *)(lVar27 + 0x438) = in_wzr;
                goto LAB_fffffff00a697fb4;
              }
              FUN_fffffff00a1eab60(lVar27 + 0x430,lVar27);
              uVar6 = *(ushort *)(lVar27 + 0x766);
            }
            if ((uVar6 >> 3 & 1) == 0) {
              FUN_fffffff00a2395ac(lVar27);
            }
            else {
              *(undefined8 *)(lVar27 + 0x278) = 0;
              if ((*(ushort *)(lVar27 + 0x50e) >> 2 & 1) != 0) {
                *(ushort *)(lVar27 + 0x50e) = *(ushort *)(lVar27 + 0x50e) & 0xfffb;
              }
            }
          }
          iVar12 = FUN_fffffff00a243aa8(lVar27,9,&uStack_a8,2);
          uVar22 = 0;
          if (iVar12 != 0) {
            uVar22 = 0x16;
          }
        }
      }
      else if (((uVar25 & 0x2a800000) == 0x8800000) && ((uVar25 & 0x3fc000) != 0)) {
        uVar22 = uVar31 >> 0xe;
        uVar23 = (uVar22 & 0xaa) >> 1 | (uVar22 & 0x55) << 1;
        uVar8 = (uVar23 & 0xcccccccc) >> 2 | (uVar23 & 0x33333333) << 2;
        uVar23 = 0;
        if ((uVar22 & 0xff) != 0) {
          uVar23 = (int)LZCOUNT((uVar8 >> 4 | (uVar8 & 0xf0f0f0f) << 4) << 0x18) + 1;
        }
        goto LAB_fffffff00a697cc0;
      }
    }
LAB_fffffff00a697d88:
    if ((uVar13 >> 1 & 1) != 0) goto LAB_fffffff00a697d9c;
    if (uVar22 != 0) goto LAB_fffffff00a697de0;
LAB_fffffff00a697d90:
    uVar23 = 0;
    bVar11 = false;
  }
  if ((uVar13 >> 2 & 1) == 0) {
    if ((uVar13 >> 3 & 1) == 0) {
LAB_fffffff00a697e14:
      uVar22 = 0;
      uVar26 = 0x2d;
      if ((uVar13 & 0x20) == 0) {
        uVar26 = 0;
      }
      if (((uVar13 >> 5 & 1) == 0) || ((uVar5 >> 5 & 1) != 0)) goto LAB_fffffff00a697e40;
      FUN_fffffff00a215e74(lVar27,0x45);
      uVar22 = 0;
    }
    else {
      uStack_a8 = 1;
      if ((uVar5 >> 5 & 1) == 0) goto LAB_fffffff00a697df4;
LAB_fffffff00a697dd8:
      uVar22 = 0x2d;
    }
  }
  else {
    uStack_a8 = 0;
    if ((uVar5 >> 5 & 1) != 0) goto LAB_fffffff00a697dd8;
LAB_fffffff00a697df4:
    iVar12 = FUN_fffffff00a243aa8(lVar27,1,&uStack_a8,1);
    if (iVar12 == 0) goto LAB_fffffff00a697e14;
    uVar22 = 0x16;
  }
  uVar26 = 0;
LAB_fffffff00a697e40:
  uVar13 = uVar30;
  if (uVar30 == 0) {
    uVar13 = uVar23;
  }
  if ((!(bool)(uVar30 != 0 | bVar11)) && (uVar13 = uVar26, uVar22 != 0)) {
    uVar13 = uVar22;
  }
  return (int *)(ulong)uVar13;
}

