// FUN_fffffff00a4baf94 @ fffffff00a4baf94 size=3268

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a4baf94(long param_1,int param_2,long param_3)

{
  uint uVar1;
  ushort uVar2;
  byte bVar3;
  long lVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  ulong uVar10;
  char *pcVar11;
  ushort uVar12;
  uint uVar13;
  ulong uVar14;
  ulong *puVar15;
  long *plVar16;
  uint uVar17;
  ushort uVar18;
  long lVar19;
  ushort uVar20;
  ushort uVar21;
  int local_280;
  undefined2 local_27c;
  ushort local_27a;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  short sStack_260;
  short sStack_25e;
  undefined4 uStack_25c;
  undefined4 local_258;
  undefined4 uStack_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 local_248;
  undefined4 uStack_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  ulong local_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined6 local_170;
  short sStack_16a;
  short sStack_168;
  undefined2 uStack_166;
  undefined4 uStack_164;
  undefined4 local_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined8 local_140;
  long lStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined5 uStack_e8;
  undefined3 local_e3;
  undefined5 uStack_e0;
  undefined8 local_d0;
  undefined8 uStack_c8;
  ulong local_c0;
  undefined5 uStack_b8;
  undefined3 uStack_b3;
  undefined5 uStack_b0;
  undefined3 uStack_ab;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long local_68;
  
  local_68 = DAT_fffffff00ad30000;
  local_1f8 = 0;
  uStack_200 = 0;
  local_208 = 0;
  uStack_210 = 0;
  local_218 = 0;
  uStack_220 = 0;
  local_228 = 0;
  uStack_230 = 0;
  local_238 = 0;
  uStack_240 = 0;
  uStack_23c = 0;
  local_248 = 0;
  uStack_244 = 0;
  uStack_250 = 0;
  uStack_24c = 0;
  local_258 = 0;
  uStack_254 = 0;
  sStack_260 = 0;
  sStack_25e = 0;
  uStack_25c = 0;
  local_268 = 0;
  uStack_270 = 0;
  local_278 = 0;
  local_280 = 0;
  if (param_1 == 0) {
    FUN_fffffff00a8df19c
              (&MACH_HEADER,DAT_fffffff00ad95428,0,
               "if_ports_used_match_mbuf: receive interface is NULL");
    plVar16 = &DAT_fffffff00ad95748;
LAB_fffffff00a4bb098:
    *plVar16 = *plVar16 + 1;
    goto LAB_fffffff00a4bb8d8;
  }
  uVar10 = FUN_fffffff00a4b9130();
  if (((uVar10 & 1) == 0) && ((*(uint *)(param_3 + 0x74) >> 10 & 1) == 0))
  goto LAB_fffffff00a4bb8d8;
  if (DAT_fffffff00ad9447c != 0) {
    FUN_fffffff00a4bbc58(param_1,param_3);
  }
  if (((uVar10 & 1) == 0) && ((*(byte *)(param_3 + 0x75) >> 2 & 1) == 0)) {
    DAT_fffffff00ad95750 = DAT_fffffff00ad95750 + 1;
    FUN_fffffff00a8df19c
              (&MACH_HEADER,DAT_fffffff00ad95428,0x10,
               "if_ports_used_match_mbuf: called PKTF_WAKE_PKT not set from %s");
    goto LAB_fffffff00a4bb8d8;
  }
  iVar7 = FUN_fffffff00a4bbd48(param_1,uVar10);
  lVar4 = DAT_fffffff00ad956e0;
  lVar19 = DAT_fffffff00ad956d8;
  if (iVar7 == -2) {
    *(uint *)(param_3 + 0x74) = *(uint *)(param_3 + 0x74) & 0xfffffbff;
    goto LAB_fffffff00a4bb8d8;
  }
  DAT_fffffff00ad956c8 = DAT_fffffff00ad956c8 + 1;
  local_27a = 0x20;
  uVar1 = *(uint *)(param_3 + 0x60);
  local_27c = *(undefined2 *)(param_1 + 0xcc);
  if ((*(byte *)(param_1 + 0xda) >> 4 & 1) != 0) {
    local_27a = 0x1020;
  }
  uVar17 = uVar1;
  if (param_2 == 0x1e) {
    local_1d0 = 0;
    uStack_1e8 = 0;
    local_1f0 = 0;
    uStack_1d8 = 0;
    local_1e0 = 0;
    DAT_fffffff00ad956e0 = DAT_fffffff00ad956e0 + 1;
    iVar7 = FUN_fffffff00a75edfc(lVar4,param_3,0,0x28,&local_1f0);
    if (iVar7 != 0) {
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad95428,0,
                 "if_ports_used_match_mbuf: mbuf_copydata(ip6_hdr) error %d");
      goto LAB_fffffff00a4bb1d4;
    }
    local_27a = local_27a | 2;
    uStack_254 = (undefined4)local_1d0;
    uStack_250 = (undefined4)((ulong)local_1d0 >> 0x20);
    uStack_25c = (undefined4)uStack_1d8;
    local_258 = (undefined4)(uStack_1d8 >> 0x20);
    uStack_244 = (undefined4)local_1e0;
    uStack_240 = (undefined4)(local_1e0 >> 0x20);
    uStack_24c = (undefined4)uStack_1e8;
    local_248 = (undefined4)((ulong)uStack_1e8 >> 0x20);
    FUN_fffffff00a4bc0d0(&local_27c);
    uVar20 = (ushort)local_1f0._6_1_;
    uVar18 = (ushort)local_1f0._6_1_;
    uVar21 = (ushort)local_1f0._6_1_;
    uVar17 = 0;
    if (0x27 < uVar1) {
      uVar17 = uVar1 - 0x28;
    }
    if (local_1f0._6_1_ == 0x2c) {
      local_d0 = 0;
      iVar7 = FUN_fffffff00a75edfc(param_3,0x28,8,&local_d0);
      if (iVar7 != 0) {
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,DAT_fffffff00ad95428,0,
                   "if_ports_used_match_mbuf: mbuf_copydata(ip6_frag) error %d");
        uVar18 = 0x2c;
        goto LAB_fffffff00a4bb1d8;
      }
      if ((local_d0 & 0xf8ff0000) != 0) {
        local_27a = local_27a | 0x400;
        DAT_fffffff00ad95758 = DAT_fffffff00ad95758 + 1;
      }
      lVar19 = 0x30;
      bVar3 = (byte)local_d0;
    }
    else {
      lVar19 = 0x28;
      bVar3 = local_1f0._6_1_;
    }
    uVar12 = local_27a;
    if (bVar3 == 0x32) {
LAB_fffffff00a4bb8b8:
      DAT_fffffff00ad95700 = DAT_fffffff00ad95700 + 1;
      local_27a = uVar12 | 0x800;
      if (DAT_fffffff00ad9447c == 0) goto LAB_fffffff00a4bb8d8;
      pcVar11 = "defer ESP matching";
LAB_fffffff00a4bb8d0:
      FUN_fffffff00a4b8148(pcVar11,&local_27c);
      goto LAB_fffffff00a4bb8d8;
    }
    if (bVar3 == 0x11) {
      DAT_fffffff00ad956f0 = DAT_fffffff00ad956f0 + 1;
      uVar12 = local_27a | 8;
      uVar2 = local_27a >> 10;
      local_27a = uVar12;
      if ((uVar2 & 1) == 0) {
        local_d0 = 0;
        iVar7 = FUN_fffffff00a75edfc(param_3,lVar19,8,&local_d0);
        lVar4 = DAT_fffffff00ad956f8;
        if (iVar7 != 0) {
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,DAT_fffffff00ad95428,0,
                     "if_ports_used_match_mbuf: mbuf_copydata(udphdr) error %d");
          iVar7 = 0;
          uVar18 = 0;
          uVar9 = 0;
          DAT_fffffff00ad95768 = DAT_fffffff00ad95768 + 1;
          goto LAB_fffffff00a4bb234;
        }
        sStack_260 = local_d0._2_2_;
        sStack_25e = (short)local_d0;
        if ((local_d0._2_2_ == -0x6bef) || ((short)local_d0 == -0x6bef)) {
          DAT_fffffff00ad956f8 = DAT_fffffff00ad956f8 + 1;
          iVar7 = FUN_fffffff00a4bc030(lVar4,param_3,lVar19 + 8);
          if (iVar7 != 0) {
            if (DAT_fffffff00ad9447c == 0) goto LAB_fffffff00a4bb8d8;
            pcVar11 = "defer encapsulated ESP matching";
            goto LAB_fffffff00a4bb8d0;
          }
        }
        bVar6 = 0x2f < uVar1;
        uVar17 = uVar1 - 0x30;
        uVar21 = uVar20;
LAB_fffffff00a4bbbfc:
        uVar18 = 0;
        uVar13 = 0;
        if (bVar6) {
          uVar13 = uVar17;
        }
LAB_fffffff00a4bbc00:
        uVar9 = FUN_fffffff00a4bc168(param_1,&local_27c,&local_280);
        iVar7 = local_280;
        uVar17 = uVar13;
        goto LAB_fffffff00a4bb234;
      }
    }
    else if (bVar3 == 6) {
      DAT_fffffff00ad956e8 = DAT_fffffff00ad956e8 + 1;
      uVar21 = local_27a | 4;
      uVar12 = local_27a >> 10;
      local_27a = uVar21;
      if ((uVar12 & 1) == 0) {
        local_d0 = 0;
        uStack_c8 = 0;
        local_c0 = local_c0 & 0xffffffff00000000;
        iVar7 = FUN_fffffff00a75edfc(param_3,lVar19,0x14,&local_d0);
        uVar21 = uVar20;
        if (iVar7 == 0) {
LAB_fffffff00a4bba80:
          sStack_260 = (short)(local_d0 >> 0x10);
          sStack_25e = (short)local_d0;
          if (uVar17 < 0x14) {
            uVar13 = 0;
          }
          else {
            uVar9 = uStack_c8._4_1_ >> 2 & 0x3c;
            uVar13 = 0;
            if (uVar9 <= uVar17) {
              uVar13 = uVar17 - uVar9;
            }
          }
          uVar18 = (ushort)uStack_c8._5_1_;
          goto LAB_fffffff00a4bbc00;
        }
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,DAT_fffffff00ad95428,0,
                   "if_ports_used_match_mbuf: mbuf_copydata(tcphdr) error %d");
        DAT_fffffff00ad95760 = DAT_fffffff00ad95760 + 1;
      }
    }
    else {
      DAT_fffffff00ad95708 = DAT_fffffff00ad95708 + 1;
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad95428,0,
                 "if_ports_used_match_mbuf: unexpected IPv6 protocol %u from %s");
    }
LAB_fffffff00a4bb1d8:
    uVar21 = uVar18;
    uVar18 = 0;
    uVar9 = 0;
    iVar7 = 0;
  }
  else {
    if (param_2 == 2) {
      local_1f0 = 0;
      uStack_1e8 = 0;
      local_1e0 = local_1e0 & 0xffffffff00000000;
      DAT_fffffff00ad956d8 = DAT_fffffff00ad956d8 + 1;
      iVar7 = FUN_fffffff00a75edfc(lVar19,param_3,0,0x14,&local_1f0);
      if (iVar7 == 0) {
        uVar17 = (uint)local_27a;
        uVar9 = uVar17 | 1;
        local_27a = (ushort)uVar9;
        uStack_24c = uStack_1e8._4_4_;
        uStack_25c = (undefined4)local_1e0;
        if ((local_1f0 & 0xff1f000000000000) != 0) {
          uVar9 = uVar17 | 0x401;
          local_27a = (ushort)uVar9;
          DAT_fffffff00ad95758 = DAT_fffffff00ad95758 + 1;
        }
        uVar12 = (ushort)uVar9;
        lVar19 = (local_1f0 & 0xf) * 4;
        uVar17 = 0;
        if ((uint)lVar19 <= uVar1) {
          uVar17 = uVar1 - (uint)lVar19;
        }
        uVar18 = (ushort)uStack_1e8._1_1_;
        if (uStack_1e8._1_1_ == 0x32) goto LAB_fffffff00a4bb8b8;
        if (uStack_1e8._1_1_ == 0x11) {
          DAT_fffffff00ad956f0 = DAT_fffffff00ad956f0 + 1;
          local_27a = uVar12 | 8;
          if ((uVar9 >> 10 & 1) == 0) {
            local_d0 = 0;
            iVar7 = FUN_fffffff00a75edfc(param_3,lVar19,8,&local_d0);
            lVar4 = DAT_fffffff00ad956f8;
            if (iVar7 != 0) {
              FUN_fffffff00a8df19c
                        (&MACH_HEADER,DAT_fffffff00ad95428,0,
                         "if_ports_used_match_mbuf: mbuf_copydata(udphdr) error %d");
              iVar7 = 0;
              uVar18 = 0;
              uVar9 = 0;
              uVar21 = 0x11;
              goto LAB_fffffff00a4bb234;
            }
            sStack_260 = local_d0._2_2_;
            sStack_25e = (short)local_d0;
            if ((local_d0._2_2_ == -0x6bef) || ((short)local_d0 == -0x6bef)) {
              DAT_fffffff00ad956f8 = DAT_fffffff00ad956f8 + 1;
              iVar7 = FUN_fffffff00a4bc030(lVar4,param_3,lVar19 + 8);
              if (iVar7 != 0) {
                if (DAT_fffffff00ad9447c == 0) goto LAB_fffffff00a4bb8d8;
                pcVar11 = "defer ISAKMP_NATT matching";
                goto LAB_fffffff00a4bb8d0;
              }
            }
            bVar6 = 7 < uVar17;
            uVar17 = uVar17 - 8;
            uVar21 = 0x11;
            goto LAB_fffffff00a4bbbfc;
          }
          uVar18 = 0x11;
        }
        else if (uStack_1e8._1_1_ == 6) {
          DAT_fffffff00ad956e8 = DAT_fffffff00ad956e8 + 1;
          local_27a = uVar12 | 4;
          if ((uVar9 >> 10 & 1) == 0) {
            local_d0 = 0;
            uStack_c8 = 0;
            local_c0 = local_c0 & 0xffffffff00000000;
            iVar7 = FUN_fffffff00a75edfc(param_3,lVar19,0x14,&local_d0);
            uVar21 = 6;
            if (iVar7 == 0) goto LAB_fffffff00a4bba80;
            FUN_fffffff00a8df19c
                      (&MACH_HEADER,DAT_fffffff00ad95428,0,
                       "if_ports_used_match_mbuf: mbuf_copydata(tcphdr) error %d");
            uVar18 = 6;
          }
          else {
            uVar18 = 6;
          }
        }
        else {
          DAT_fffffff00ad95708 = DAT_fffffff00ad95708 + 1;
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,DAT_fffffff00ad95428,0,
                     "if_ports_used_match_mbuf: unexpected IPv4 protocol %u from %s");
        }
        goto LAB_fffffff00a4bb1d8;
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad95428,0,
                 "if_ports_used_match_mbuf: mbuf_copydata(ip) error %d");
LAB_fffffff00a4bb1d4:
      uVar18 = 0;
      goto LAB_fffffff00a4bb1d8;
    }
    DAT_fffffff00ad95710 = DAT_fffffff00ad95710 + 1;
    FUN_fffffff00a8df19c
              (&MACH_HEADER,DAT_fffffff00ad95428,0,
               "if_ports_used_match_mbuf: unexpected protocol family %d from %s");
    iVar7 = 0;
    uVar21 = 0;
    uVar18 = 0;
    uVar9 = 0;
  }
LAB_fffffff00a4bb234:
  if (iVar7 == DAT_fffffff00adcb60c) goto LAB_fffffff00a4bb8d8;
  uVar14 = (ulong)*(byte *)(param_3 + 0x75);
  if ((*(byte *)(param_3 + 0x75) >> 2 & 1) != 0) {
    uVar14 = (ulong)(local_27a | 0x100);
    local_27a = (ushort)(local_27a | 0x100);
  }
  if ((int)uVar10 != 0) {
    uVar13 = (uint)local_27a;
    local_27a = local_27a | 0x4000;
    if ((uVar9 & (uVar13 & 0x2000) >> 0xd) == 1) {
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad95428,0,
                 "if_ports_used_match_mbuf: idle connection in LPW on %s");
      puVar15 = &DAT_fffffff00ad957a8;
    }
    else {
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad95428,0,
                 "if_ports_used_match_mbuf: not idle connection in LPW on %s");
      puVar15 = &DAT_fffffff00ad957b0;
    }
    uVar14 = *puVar15;
    *puVar15 = uVar14 + 1;
  }
  if (uVar9 != 0) {
    FUN_fffffff00a4bc558(uVar14,param_1,&local_27c,uVar1,uVar17,uVar18,uVar10);
    goto LAB_fffffff00a4bb8d8;
  }
  uStack_118 = 0;
  local_120 = 0;
  uStack_108 = 0;
  local_110 = 0;
  local_140 = 0;
  uStack_128 = 0;
  uStack_144 = 0;
  uStack_178 = 0;
  local_180 = 0;
  uStack_166 = 0;
  local_170 = 0;
  uStack_198 = 0;
  local_1a0 = 0;
  uStack_188 = 0;
  local_190 = 0;
  uStack_1b8 = 0;
  local_1c0 = 0;
  uStack_1a8 = 0;
  local_1b0 = 0;
  local_1e0 = 0;
  uStack_1c8 = 0;
  local_1d0 = 0;
  local_1f8._6_2_ = (undefined2)((ulong)local_1f8 >> 0x30);
  uStack_1d8._0_6_ = CONCAT24(local_1f8._6_2_,CONCAT22(local_27a,*(undefined2 *)(param_1 + 0xcc)));
  uStack_1d8 = (ulong)(uint6)uStack_1d8;
  lStack_138 = (ulong)uVar1 << 0x20;
  local_130 = CONCAT26(uVar21,CONCAT24(uVar18,uVar17));
  local_1f0 = _DAT_fffffff00adcb5c8;
  uStack_1e8 = uRamfffffff00adcb5d0;
  sStack_16a = sStack_260;
  sStack_168 = sStack_25e;
  uStack_164 = uStack_25c;
  local_160 = local_258;
  uStack_15c = uStack_254;
  uStack_158 = uStack_250;
  uStack_154 = uStack_24c;
  local_150 = local_248;
  uStack_14c = uStack_244;
  uStack_148 = uStack_240;
  FUN_fffffff00a354958(&uStack_144,*(undefined8 *)(param_1 + 0x20),0x10);
  uStack_128 = *(undefined8 *)(param_1 + 0x338);
  uVar8 = FUN_fffffff00a45a590(param_1,1);
  local_120 = CONCAT44(local_120._4_4_,uVar8);
  FUN_fffffff00a228180(&DAT_fffffff00adcb5d8);
  uVar14 = FUN_fffffff00a1d14a0(&DAT_fffffff00adcb814,0x10);
  uVar10 = uVar14;
  if (0xf < uVar14) {
    uVar10 = 0x10;
  }
  if (0xe < uVar14) {
    uVar14 = 0xf;
  }
  FUN_fffffff00aa65b10((long)&local_120 + 4,&DAT_fffffff00adcb814,uVar10);
  *(undefined1 *)((long)&local_120 + 4 + uVar14) = 0;
  local_110 = CONCAT44(DAT_fffffff00adcb708,(undefined4)local_110);
  uStack_108 = CONCAT44(DAT_fffffff00adcb828,DAT_fffffff00adcb824);
  iVar7 = FUN_fffffff00a228d30(&DAT_fffffff00adcb5d8);
  if (iVar7 != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("lck_rw_unlock_shared(): lock %p held in mode: %d @%s:%d");
  }
  uVar1 = *(uint *)(param_3 + 0x60);
  if (0x65 < (int)uVar1) {
    uVar1 = 0x66;
  }
  uStack_1d8 = CONCAT26((short)uVar1,(uint6)uStack_1d8);
  if (0x66 < (uVar1 & 0xffff)) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a4bbc58);
    (*pcVar5)();
  }
  iVar7 = FUN_fffffff00a75edfc(param_3,0,uVar1 & 0x7f,&local_1d0);
  if (iVar7 != 0) {
    uStack_b0 = 0;
    uStack_c8 = 0;
    local_d0 = 0;
    uStack_b8 = 0;
    uStack_b3 = 0;
    local_c0 = 0;
    FUN_fffffff00a8de968(&local_1f0,&local_d0);
    FUN_fffffff00a8df19c
              (&MACH_HEADER,DAT_fffffff00ad95428,0x10,
               "%s: mbuf_copydata() failed with error %d for wake uuid %s");
    plVar16 = &DAT_fffffff00ad95740;
    goto LAB_fffffff00a4bb098;
  }
  FUN_fffffff00a227a00(&DAT_fffffff00adcb5d8);
  if (((DAT_fffffff00adcb811 & 1) == 0) && (DAT_fffffff00adcb810 != '\x01')) {
    iVar7 = FUN_fffffff00a4ba800(param_1);
    if (iVar7 == 0) {
      uStack_88 = 0;
      local_90 = 0;
      uStack_78 = 0;
      uStack_80 = 0;
      uStack_a8 = 0;
      uStack_b0 = 0;
      uStack_ab = 0;
      uStack_98 = 0;
      uStack_a0 = 0;
      DAT_fffffff00adcb811 = 1;
      DAT_fffffff00ad95730 = DAT_fffffff00ad95730 + 1;
      _DAT_fffffff00adcb6c0 = CONCAT44(uStack_144,uStack_148);
      _DAT_fffffff00adcb6b8 = CONCAT44(uStack_14c,local_150);
      _DAT_fffffff00adcb6d0 = lStack_138;
      _DAT_fffffff00adcb6c8 = local_140;
      _DAT_fffffff00adcb6e0 = uStack_128;
      _DAT_fffffff00adcb6d8 = local_130;
      _DAT_fffffff00adcb6f0 = uStack_118;
      _DAT_fffffff00adcb6e8 = local_120;
      DAT_fffffff00adcb700 = uStack_108;
      _DAT_fffffff00adcb6f8 = local_110;
      _DAT_fffffff00adcb690 = uStack_178;
      _DAT_fffffff00adcb688 = local_180;
      _DAT_fffffff00adcb6a0 = CONCAT44(uStack_164,CONCAT22(uStack_166,sStack_168));
      _DAT_fffffff00adcb698 = CONCAT26(sStack_16a,local_170);
      _DAT_fffffff00adcb6b0 = CONCAT44(uStack_154,uStack_158);
      _DAT_fffffff00adcb6a8 = CONCAT44(uStack_15c,local_160);
      _DAT_fffffff00adcb650 = uStack_1b8;
      _DAT_fffffff00adcb648 = local_1c0;
      _DAT_fffffff00adcb660 = uStack_1a8;
      _DAT_fffffff00adcb658 = local_1b0;
      _DAT_fffffff00adcb670 = uStack_198;
      _DAT_fffffff00adcb668 = local_1a0;
      _DAT_fffffff00adcb680 = uStack_188;
      _DAT_fffffff00adcb678 = local_190;
      _DAT_fffffff00adcb620 = uStack_1e8;
      _DAT_fffffff00adcb618 = local_1f0;
      _DAT_fffffff00adcb630 = uStack_1d8;
      _DAT_fffffff00adcb628 = local_1e0;
      DAT_fffffff00adcb610 = 2;
      _DAT_fffffff00adcb640 = uStack_1c8;
      _DAT_fffffff00adcb638 = local_1d0;
      uStack_c8 = _UNK_fffffff00700f528;
      local_d0 = _DAT_fffffff00700f520;
      uStack_b8 = SUB85(&local_1f0,0);
      uStack_b3 = (undefined3)((ulong)&local_1f0 >> 0x28);
      local_c0 = 0xf0;
      iVar7 = FUN_fffffff00a7049b0(&local_d0,0);
      if (iVar7 != 0) {
        uStack_e0 = 0;
        uStack_f8 = 0;
        local_100 = 0;
        uStack_e8 = 0;
        local_e3 = 0;
        uStack_f0 = 0;
        FUN_fffffff00a8de968(&local_1f0,&local_100);
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,DAT_fffffff00ad95428,0x10,
                   "%s: kev_post_msg() failed with error %d for wake uuid %s");
        DAT_fffffff00ad95728 = DAT_fffffff00ad95728 + 1;
      }
    }
    else {
      if (DAT_fffffff00adcb70c == 1) {
        plVar16 = &DAT_fffffff00ad957d0;
LAB_fffffff00a4bbb7c:
        *plVar16 = *plVar16 + 1;
      }
      else if (DAT_fffffff00adcb70c == 2) {
        plVar16 = &DAT_fffffff00ad957d8;
        goto LAB_fffffff00a4bbb7c;
      }
      _DAT_fffffff00adcb7bc = CONCAT44(uStack_144,uStack_148);
      _DAT_fffffff00adcb7b4 = CONCAT44(uStack_14c,local_150);
      _DAT_fffffff00adcb7cc = lStack_138;
      _DAT_fffffff00adcb7c4 = local_140;
      _DAT_fffffff00adcb7dc = uStack_128;
      _DAT_fffffff00adcb7d4 = local_130;
      _DAT_fffffff00adcb7ec = uStack_118;
      _DAT_fffffff00adcb7e4 = local_120;
      DAT_fffffff00adcb7fc = uStack_108;
      _DAT_fffffff00adcb7f4 = local_110;
      _DAT_fffffff00adcb77c = uStack_188;
      _DAT_fffffff00adcb774 = local_190;
      _DAT_fffffff00adcb78c = uStack_178;
      _DAT_fffffff00adcb784 = local_180;
      _DAT_fffffff00adcb79c = CONCAT44(uStack_164,CONCAT22(uStack_166,sStack_168));
      _DAT_fffffff00adcb794 = CONCAT26(sStack_16a,local_170);
      _DAT_fffffff00adcb7ac = CONCAT44(uStack_154,uStack_158);
      _DAT_fffffff00adcb7a4 = CONCAT44(uStack_15c,local_160);
      _DAT_fffffff00adcb73c = uStack_1c8;
      _DAT_fffffff00adcb734 = local_1d0;
      _DAT_fffffff00adcb74c = uStack_1b8;
      _DAT_fffffff00adcb744 = local_1c0;
      _DAT_fffffff00adcb75c = uStack_1a8;
      _DAT_fffffff00adcb754 = local_1b0;
      _DAT_fffffff00adcb76c = uStack_198;
      _DAT_fffffff00adcb764 = local_1a0;
      _DAT_fffffff00adcb71c = uStack_1e8;
      _DAT_fffffff00adcb714 = local_1f0;
      _DAT_fffffff00adcb72c = uStack_1d8;
      _DAT_fffffff00adcb724 = local_1e0;
      DAT_fffffff00adcb70c = 2;
    }
  }
  else {
    DAT_fffffff00ad95738 = DAT_fffffff00ad95738 + 1;
    if (DAT_fffffff00ad9447c != 0) {
      FUN_fffffff00a4b8148("already notified unattributed wake packet",&local_27c);
    }
  }
  FUN_fffffff00a228f08(&DAT_fffffff00adcb5d8);
LAB_fffffff00a4bb8d8:
  if (DAT_fffffff00ad30000 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590();
}

