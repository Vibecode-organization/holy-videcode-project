// FUN_fffffff00a4bcbfc @ fffffff00a4bcbfc size=2452

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a4bcbfc(long param_1,long param_2)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  char *pcVar10;
  int iVar11;
  uint uVar12;
  undefined8 *puVar13;
  undefined2 *puVar14;
  short *psVar15;
  ulong uVar16;
  ulong *puVar17;
  long *plVar18;
  ushort uVar19;
  ushort uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  int local_284;
  undefined8 local_280;
  undefined8 uStack_278;
  undefined8 local_270;
  undefined8 *puStack_268;
  undefined8 local_260;
  undefined8 uStack_258;
  undefined8 uStack_250;
  undefined8 uStack_248;
  undefined8 local_240;
  undefined8 uStack_238;
  undefined8 uStack_230;
  undefined8 uStack_228;
  undefined8 local_220;
  undefined8 uStack_218;
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 local_200;
  undefined8 uStack_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined4 uStack_1a8;
  undefined4 local_1a4;
  undefined4 uStack_1a0;
  undefined8 uStack_19c;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined6 local_110;
  undefined2 uStack_10a;
  undefined2 uStack_108;
  undefined2 uStack_106;
  undefined4 uStack_104;
  undefined4 local_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined5 uStack_88;
  undefined3 local_83;
  undefined5 uStack_80;
  long local_78;
  
  local_78 = DAT_fffffff00ad30000;
  uStack_19c = 0;
  uStack_1a0 = 0;
  uStack_1b8 = 0;
  local_1c0 = 0;
  uStack_1a8 = 0;
  local_1a4 = 0;
  uStack_1b0 = 0;
  uStack_1d8 = 0;
  local_1e0 = 0;
  uStack_1c8 = 0;
  uStack_1d0 = 0;
  uStack_1f8 = 0;
  local_200 = 0;
  uStack_1e8 = 0;
  local_1f0 = 0;
  uStack_218 = 0;
  local_220 = 0;
  uStack_208 = 0;
  uStack_210 = 0;
  local_284 = 0;
  if (param_1 == 0) {
    FUN_fffffff00a8df19c
              (&MACH_HEADER,DAT_fffffff00ad95428,0,
               "if_ports_used_match_pkt: receive interface is NULL");
    DAT_fffffff00ad95748 = DAT_fffffff00ad95748 + 1;
    goto LAB_fffffff00a4bd328;
  }
  uVar9 = FUN_fffffff00a4b9130();
  if (((uVar9 & 1) == 0) && (((uint)*(undefined8 *)(param_2 + 0x90) >> 10 & 1) == 0))
  goto LAB_fffffff00a4bd328;
  if (DAT_fffffff00ad9447c != 0) {
    FUN_fffffff00a4bd590(param_1,param_2);
  }
  if (((uVar9 & 1) == 0) && (((uint)*(undefined8 *)(param_2 + 0x90) >> 10 & 1) == 0)) {
    DAT_fffffff00ad95750 = DAT_fffffff00ad95750 + 1;
    FUN_fffffff00a8df19c
              (&MACH_HEADER,DAT_fffffff00ad95428,0x10,"%s: called PKT_F_WAKE_PKT not set from %s");
    goto LAB_fffffff00a4bd328;
  }
  iVar7 = FUN_fffffff00a4bbd48(param_1,uVar9);
  if (iVar7 == -2) {
    *(ulong *)(param_2 + 0x90) = *(ulong *)(param_2 + 0x90) & 0xfffffffffffffbff;
    goto LAB_fffffff00a4bd328;
  }
  DAT_fffffff00ad956d0 = DAT_fffffff00ad956d0 + 1;
  uVar8 = 0x40;
  uVar6 = local_220._4_4_;
  local_220 = CONCAT44(local_220._4_4_,0x400000);
  puVar13 = *(undefined8 **)(param_2 + 0xb8);
  bVar2 = *(byte *)((long)puVar13 + 0x22);
  bVar3 = *(byte *)(puVar13 + 0x12);
  iVar7 = *(int *)(puVar13 + 7);
  local_220 = CONCAT62(local_220._2_6_,*(undefined2 *)(param_1 + 0xcc));
  if ((*(byte *)(param_1 + 0xda) >> 4 & 1) != 0) {
    uVar8 = 0x1040;
    local_220._0_4_ = CONCAT22(0x1040,*(undefined2 *)(param_1 + 0xcc));
    local_220 = CONCAT44(uVar6,(undefined4)local_220);
  }
  if (*(char *)(puVar13 + 4) == '`') {
    DAT_fffffff00ad956e0 = DAT_fffffff00ad956e0 + 1;
    uVar8 = uVar8 | 2;
    local_220._0_4_ = CONCAT22((short)uVar8,(undefined2)local_220);
    uStack_1f8 = puVar13[3];
    uVar21 = puVar13[2];
    uStack_1e8 = puVar13[1];
    uVar22 = *puVar13;
    local_200._0_1_ = (char)uVar21;
    local_200._1_1_ = (byte)((ulong)uVar21 >> 8);
    if ((char)local_200 == -1) {
      if (((local_200._1_1_ & 0xf) == 1) ||
         ((local_200._1_1_ & 0xf0) != 0x30 && (local_200._1_1_ & 0xf) == 2))
      goto LAB_fffffff00a4bce84;
    }
    else if (((char)local_200 == -2) && ((char)local_200._1_1_ < -0x40)) {
LAB_fffffff00a4bce84:
      local_200._4_4_ = (undefined4)((ulong)uVar21 >> 0x20);
      local_200._0_4_ = (uint)(ushort)uVar21;
      uVar21 = local_200;
    }
    local_200 = uVar21;
    local_1f0._0_1_ = (char)uVar22;
    local_1f0._1_1_ = (byte)((ulong)uVar22 >> 8);
    if ((char)local_1f0 == -1) {
      if (((local_1f0._1_1_ & 0xf) == 1) ||
         ((local_1f0._1_1_ & 0xf0) != 0x30 && (local_1f0._1_1_ & 0xf) == 2))
      goto LAB_fffffff00a4bced0;
    }
    else if (((char)local_1f0 == -2) && ((char)local_1f0._1_1_ < -0x40)) {
LAB_fffffff00a4bced0:
      local_1f0._4_4_ = (undefined4)((ulong)uVar22 >> 0x20);
      local_1f0._0_4_ = (uint)(ushort)uVar22;
      uVar22 = local_1f0;
    }
LAB_fffffff00a4bced4:
    local_1f0 = uVar22;
    bVar4 = *(byte *)((long)puVar13 + 0x21);
    uVar20 = (ushort)bVar4;
    if ((*(byte *)((long)puVar13 + 0x23) & 3) == 1) {
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad95428,0,"%s: unexpected wake fragment from %s");
      uVar8 = uVar8 | 0x400;
      local_220._0_4_ = CONCAT22((short)uVar8,(undefined2)local_220);
      DAT_fffffff00ad95758 = DAT_fffffff00ad95758 + 1;
      puVar13 = *(undefined8 **)(param_2 + 0xb8);
      bVar4 = *(byte *)((long)puVar13 + 0x21);
    }
    uVar5 = (undefined2)uVar8;
    if (bVar4 == 0x32) {
      DAT_fffffff00ad95700 = DAT_fffffff00ad95700 + 1;
      local_220 = CONCAT44(local_220._4_4_,CONCAT22(uVar5,(undefined2)local_220)) | 0x8000000;
      if (DAT_fffffff00ad9447c == 0) goto LAB_fffffff00a4bd328;
      pcVar10 = "defer ESP matching";
LAB_fffffff00a4bd034:
      FUN_fffffff00a4b8148(pcVar10,&local_220);
      goto LAB_fffffff00a4bd328;
    }
    if (bVar4 == 0x11) {
      DAT_fffffff00ad956f0 = DAT_fffffff00ad956f0 + 1;
      local_220 = CONCAT44(local_220._4_4_,CONCAT22(uVar5,(undefined2)local_220)) | 0x80000;
      if ((uVar8 >> 10 & 1) == 0) {
        psVar15 = (short *)puVar13[0x13];
        if (psVar15 != (short *)0x0) {
          uStack_208._0_6_ = CONCAT24(psVar15[1],(undefined4)uStack_208);
          uStack_208 = CONCAT26(*psVar15,(undefined6)uStack_208);
          if ((psVar15[1] != -0x6bef) && (*psVar15 != -0x6bef)) {
            uVar19 = 0;
            goto LAB_fffffff00a4bcfe0;
          }
          DAT_fffffff00ad95778 = DAT_fffffff00ad95778 + 1;
          if (DAT_fffffff00ad9447c == 0) goto LAB_fffffff00a4bd328;
          pcVar10 = "defer ISAKMP_NATT matching";
          goto LAB_fffffff00a4bd034;
        }
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,DAT_fffffff00ad95428,0,"%s: pkt with unassigned UDP header from %s")
        ;
        plVar18 = &DAT_fffffff00ad95768;
LAB_fffffff00a4bd124:
        iVar11 = 0;
        uVar8 = 0;
        uVar19 = 0;
        *plVar18 = *plVar18 + 1;
      }
      else {
LAB_fffffff00a4bcffc:
        iVar11 = 0;
        uVar19 = 0;
        uVar8 = 0;
      }
    }
    else if (bVar4 == 6) {
      DAT_fffffff00ad956e8 = DAT_fffffff00ad956e8 + 1;
      local_220 = CONCAT44(local_220._4_4_,CONCAT22(uVar5,(undefined2)local_220)) | 0x40000;
      if ((uVar8 >> 10 & 1) != 0) goto LAB_fffffff00a4bcffc;
      puVar14 = (undefined2 *)puVar13[0x13];
      if (puVar14 == (undefined2 *)0x0) {
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,DAT_fffffff00ad95428,0,"%s: pkt with unassigned TCP header from %s")
        ;
        plVar18 = &DAT_fffffff00ad95760;
        goto LAB_fffffff00a4bd124;
      }
      uStack_208._0_6_ = CONCAT24(puVar14[1],(undefined4)uStack_208);
      uStack_208 = CONCAT26(*puVar14,(undefined6)uStack_208);
      uVar19 = (ushort)*(byte *)((long)puVar14 + 0xd);
LAB_fffffff00a4bcfe0:
      uVar8 = FUN_fffffff00a4bc168(param_1,&local_220,&local_284);
      iVar11 = local_284;
    }
    else {
      DAT_fffffff00ad95708 = DAT_fffffff00ad95708 + 1;
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad95428,0,"%s: unexpected IP protocol %u from %s");
      iVar11 = 0;
      uVar19 = 0;
      uVar8 = 0;
    }
  }
  else {
    if (*(char *)(puVar13 + 4) == '\x04') {
      DAT_fffffff00ad956d8 = DAT_fffffff00ad956d8 + 1;
      uVar8 = uVar8 | 1;
      local_220._0_4_ = CONCAT22((short)uVar8,(undefined2)local_220);
      local_200 = CONCAT44(local_200._4_4_,*(undefined4 *)((long)puVar13 + 4));
      local_1f0 = CONCAT44(local_1f0._4_4_,*(undefined4 *)puVar13);
      uVar22 = local_1f0;
      goto LAB_fffffff00a4bced4;
    }
    DAT_fffffff00ad95710 = DAT_fffffff00ad95710 + 1;
    FUN_fffffff00a8df19c
              (&MACH_HEADER,DAT_fffffff00ad95428,0,"%s: unexpected protocol family %u from %s");
    iVar11 = 0;
    uVar20 = 0;
    uVar19 = 0;
    uVar8 = 0;
  }
  if (iVar11 == DAT_fffffff00adcb60c) goto LAB_fffffff00a4bd328;
  uVar16 = *(ulong *)(param_2 + 0x90);
  if (((uint)uVar16 >> 10 & 1) != 0) {
    uVar16 = (ulong)(local_220._2_2_ | 0x100);
    local_220._0_4_ = CONCAT22((short)(local_220._2_2_ | 0x100),(undefined2)local_220);
  }
  if ((int)uVar9 != 0) {
    uVar12 = (uint)local_220._2_2_;
    local_220 = local_220 | 0x40000000;
    if ((uVar8 & (uVar12 & 0x2000) >> 0xd) == 1) {
      if (0 < DAT_fffffff00ad95218) {
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,DAT_fffffff00ad95428,0,
                   "if_ports_used_match_pkt: idle connection in LPW on %s");
      }
      puVar17 = &DAT_fffffff00ad957a8;
    }
    else {
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad95428,0,
                 "if_ports_used_match_pkt: not idle connection in LPW on %s");
      puVar17 = &DAT_fffffff00ad957b0;
    }
    uVar16 = *puVar17;
    *puVar17 = uVar16 + 1;
  }
  iVar11 = (uint)bVar3 + (uint)bVar2 + iVar7;
  if (uVar8 != 0) {
    FUN_fffffff00a4bc558(uVar16,param_1,&local_220,iVar11,iVar7,uVar19,uVar9);
    goto LAB_fffffff00a4bd328;
  }
  local_180 = 0;
  uStack_168 = 0;
  local_170 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  uStack_d8 = 0;
  local_e0 = 0;
  uStack_c8 = 0;
  local_d0 = 0;
  uStack_f8 = 0;
  uStack_f4 = 0;
  local_100 = 0;
  uStack_fc = 0;
  uStack_e8 = 0;
  uStack_e4 = 0;
  local_f0 = 0;
  uStack_ec = 0;
  uStack_118 = 0;
  local_120 = 0;
  uStack_108 = 0;
  uStack_106 = 0;
  uStack_104 = 0;
  local_110 = 0;
  uStack_10a = 0;
  uStack_138 = 0;
  local_140 = 0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_158 = 0;
  local_160 = 0;
  uStack_148 = 0;
  local_150 = 0;
  iVar1 = (uint)*(byte *)(param_2 + 0x7b) + (uint)*(byte *)(param_2 + 0x7a);
  uVar8 = *(int *)(param_2 + 0x10) - iVar1;
  uStack_188 = uRamfffffff00adcb5d0;
  local_190 = _DAT_fffffff00adcb5c8;
  if (0x65 < uVar8) {
    uVar8 = 0x66;
  }
  uStack_178 = CONCAT26((short)uVar8,
                        CONCAT24(uStack_19c._6_2_,
                                 CONCAT22(local_220._2_2_,*(undefined2 *)(param_1 + 0xcc))));
  FUN_fffffff00a88947c(param_2,iVar1,uVar8,&local_170);
  uStack_10a = (undefined2)((ulong)uStack_208 >> 0x20);
  uStack_108 = (undefined2)((ulong)uStack_208 >> 0x30);
  uStack_fc = (undefined4)uStack_1f8;
  uStack_f8 = (undefined4)((ulong)uStack_1f8 >> 0x20);
  uStack_104 = (undefined4)local_200;
  local_100 = (undefined4)((ulong)local_200 >> 0x20);
  uStack_ec = (undefined4)uStack_1e8;
  uStack_e8 = (undefined4)((ulong)uStack_1e8 >> 0x20);
  uStack_f4 = (undefined4)local_1f0;
  local_f0 = (undefined4)((ulong)local_1f0 >> 0x20);
  FUN_fffffff00a354958(&uStack_e4,*(undefined8 *)(param_1 + 0x20),0x10);
  uStack_d8 = CONCAT44(iVar11,(undefined4)uStack_d8);
  local_d0 = CONCAT26(uVar20,CONCAT24(uVar19,iVar7));
  FUN_fffffff00a227a00(&DAT_fffffff00adcb5d8);
  if (((DAT_fffffff00adcb811 & 1) == 0) && (DAT_fffffff00adcb810 != '\x01')) {
    iVar7 = FUN_fffffff00a4ba800(param_1);
    if (iVar7 == 0) {
      uStack_238 = 0;
      local_240 = 0;
      uStack_228 = 0;
      uStack_230 = 0;
      uStack_258 = 0;
      local_260 = 0;
      uStack_248 = 0;
      uStack_250 = 0;
      DAT_fffffff00adcb811 = 1;
      DAT_fffffff00ad95730 = DAT_fffffff00ad95730 + 1;
      _DAT_fffffff00adcb6c0 = CONCAT44(uStack_e4,uStack_e8);
      _DAT_fffffff00adcb6b8 = CONCAT44(uStack_ec,local_f0);
      _DAT_fffffff00adcb6d0 = uStack_d8;
      _DAT_fffffff00adcb6c8 = local_e0;
      _DAT_fffffff00adcb6e0 = uStack_c8;
      _DAT_fffffff00adcb6d8 = local_d0;
      _DAT_fffffff00adcb6f0 = uStack_b8;
      _DAT_fffffff00adcb6e8 = local_c0;
      DAT_fffffff00adcb700 = uStack_a8;
      _DAT_fffffff00adcb6f8 = local_b0;
      _DAT_fffffff00adcb690 = uStack_118;
      _DAT_fffffff00adcb688 = local_120;
      _DAT_fffffff00adcb6a0 = CONCAT44(uStack_104,CONCAT22(uStack_106,uStack_108));
      _DAT_fffffff00adcb698 = CONCAT26(uStack_10a,local_110);
      _DAT_fffffff00adcb6b0 = CONCAT44(uStack_f4,uStack_f8);
      _DAT_fffffff00adcb6a8 = CONCAT44(uStack_fc,local_100);
      _DAT_fffffff00adcb650 = uStack_158;
      _DAT_fffffff00adcb648 = local_160;
      _DAT_fffffff00adcb660 = uStack_148;
      _DAT_fffffff00adcb658 = local_150;
      _DAT_fffffff00adcb670 = uStack_138;
      _DAT_fffffff00adcb668 = local_140;
      _DAT_fffffff00adcb680 = uStack_128;
      _DAT_fffffff00adcb678 = local_130;
      _DAT_fffffff00adcb620 = uStack_188;
      _DAT_fffffff00adcb618 = local_190;
      _DAT_fffffff00adcb630 = uStack_178;
      _DAT_fffffff00adcb628 = local_180;
      DAT_fffffff00adcb610 = 2;
      _DAT_fffffff00adcb640 = uStack_168;
      _DAT_fffffff00adcb638 = local_170;
      uStack_278 = _UNK_fffffff00700f528;
      local_280 = _DAT_fffffff00700f520;
      puStack_268 = &local_190;
      local_270 = 0xf0;
      iVar7 = FUN_fffffff00a7049b0(&local_280,0);
      if (iVar7 != 0) {
        uStack_80 = 0;
        uStack_98 = 0;
        local_a0 = 0;
        uStack_88 = 0;
        local_83 = 0;
        uStack_90 = 0;
        FUN_fffffff00a8de968(&local_190,&local_a0);
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,DAT_fffffff00ad95428,0x10,
                   "%s: kev_post_msg() failed with error %d for wake uuid %s");
        DAT_fffffff00ad95728 = DAT_fffffff00ad95728 + 1;
      }
    }
    else {
      if (DAT_fffffff00adcb70c == 1) {
        plVar18 = &DAT_fffffff00ad957d0;
LAB_fffffff00a4bd4e0:
        *plVar18 = *plVar18 + 1;
      }
      else if (DAT_fffffff00adcb70c == 2) {
        plVar18 = &DAT_fffffff00ad957d8;
        goto LAB_fffffff00a4bd4e0;
      }
      _DAT_fffffff00adcb7bc = CONCAT44(uStack_e4,uStack_e8);
      _DAT_fffffff00adcb7b4 = CONCAT44(uStack_ec,local_f0);
      _DAT_fffffff00adcb7cc = uStack_d8;
      _DAT_fffffff00adcb7c4 = local_e0;
      _DAT_fffffff00adcb7dc = uStack_c8;
      _DAT_fffffff00adcb7d4 = local_d0;
      _DAT_fffffff00adcb7ec = uStack_b8;
      _DAT_fffffff00adcb7e4 = local_c0;
      DAT_fffffff00adcb7fc = uStack_a8;
      _DAT_fffffff00adcb7f4 = local_b0;
      _DAT_fffffff00adcb77c = uStack_128;
      _DAT_fffffff00adcb774 = local_130;
      _DAT_fffffff00adcb78c = uStack_118;
      _DAT_fffffff00adcb784 = local_120;
      _DAT_fffffff00adcb79c = CONCAT44(uStack_104,CONCAT22(uStack_106,uStack_108));
      _DAT_fffffff00adcb794 = CONCAT26(uStack_10a,local_110);
      _DAT_fffffff00adcb7ac = CONCAT44(uStack_f4,uStack_f8);
      _DAT_fffffff00adcb7a4 = CONCAT44(uStack_fc,local_100);
      _DAT_fffffff00adcb73c = uStack_168;
      _DAT_fffffff00adcb734 = local_170;
      _DAT_fffffff00adcb74c = uStack_158;
      _DAT_fffffff00adcb744 = local_160;
      _DAT_fffffff00adcb75c = uStack_148;
      _DAT_fffffff00adcb754 = local_150;
      _DAT_fffffff00adcb76c = uStack_138;
      _DAT_fffffff00adcb764 = local_140;
      _DAT_fffffff00adcb71c = uStack_188;
      _DAT_fffffff00adcb714 = local_190;
      _DAT_fffffff00adcb72c = uStack_178;
      _DAT_fffffff00adcb724 = local_180;
      DAT_fffffff00adcb70c = 2;
    }
  }
  else {
    DAT_fffffff00ad95738 = DAT_fffffff00ad95738 + 1;
    if (DAT_fffffff00ad9447c != 0) {
      FUN_fffffff00a4b8148("already notified unattributed wake packet",&local_220);
    }
  }
  iVar7 = FUN_fffffff00a228d30(&DAT_fffffff00adcb5d8);
  if (iVar7 != 2) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("lck_rw_unlock_exclusive(): lock %p held in mode: %d @%s:%d");
  }
LAB_fffffff00a4bd328:
  if (DAT_fffffff00ad30000 != local_78) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4c590();
  }
  return;
}

