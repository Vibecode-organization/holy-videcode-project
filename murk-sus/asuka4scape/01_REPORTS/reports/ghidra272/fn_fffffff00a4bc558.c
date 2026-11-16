// FUN_fffffff00a4bc558 @ fffffff00a4bc558 size=1700

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a4bc558
               (long param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5,
               int param_6)

{
  ushort uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined4 uVar18;
  int iVar19;
  ulong uVar20;
  ulong uVar21;
  long *plVar22;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 *puStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 auStack_148 [2];
  undefined8 uStack_138;
  undefined1 auStack_137 [7];
  undefined8 local_130;
  undefined2 uStack_128;
  undefined6 uStack_126;
  undefined2 local_120;
  undefined6 uStack_11e;
  undefined2 uStack_118;
  undefined6 uStack_116;
  undefined2 local_110;
  undefined6 uStack_10e;
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
  uStack_116 = 0;
  local_120 = 0;
  uStack_11e = 0;
  uStack_108 = 0;
  uStack_106 = 0;
  uStack_104 = 0;
  local_110 = 0;
  uStack_10e = 0;
  uStack_138 = 0;
  auStack_148[1] = 0;
  uStack_128 = 0;
  uStack_126 = 0;
  local_130 = 0;
  local_160 = 0;
  auStack_148[0] = 0;
  uStack_168 = uRamfffffff00adcb5d0;
  local_170 = _DAT_fffffff00adcb5c8;
  uStack_158 = CONCAT26(*(undefined2 *)(param_2 + 0x8a),
                        CONCAT24(*(undefined2 *)(param_2 + 2),
                                 CONCAT22(*(undefined2 *)(param_2 + 0x1c),
                                          *(undefined2 *)(param_1 + 0xcc))));
  local_150 = *(undefined8 *)(param_2 + 0x40);
  uVar20 = FUN_fffffff00a1d14a0(param_2 + 0x48,0x11);
  uVar21 = uVar20;
  if (0x10 < uVar20) {
    uVar21 = 0x11;
  }
  if (0xf < uVar20) {
    uVar20 = 0x10;
  }
  FUN_fffffff00aa65b10(auStack_148,param_2 + 0x48,uVar21);
  *(undefined1 *)((long)auStack_148 + uVar20) = 0;
  uVar20 = FUN_fffffff00a1d14a0(param_2 + 0x59,0x11);
  uVar21 = uVar20;
  if (0x10 < uVar20) {
    uVar21 = 0x11;
  }
  if (0xf < uVar20) {
    uVar20 = 0x10;
  }
  FUN_fffffff00aa65b10(auStack_137,param_2 + 0x59,uVar21);
  auStack_137[uVar20] = 0;
  uStack_11e = (undefined6)*(undefined8 *)(param_2 + 0x72);
  uStack_118 = (undefined2)((ulong)*(undefined8 *)(param_2 + 0x72) >> 0x30);
  uStack_126 = (undefined6)*(undefined8 *)(param_2 + 0x6a);
  local_120 = (undefined2)((ulong)*(undefined8 *)(param_2 + 0x6a) >> 0x30);
  uStack_10e = (undefined6)*(undefined8 *)(param_2 + 0x82);
  uStack_108 = (undefined2)((ulong)*(undefined8 *)(param_2 + 0x82) >> 0x30);
  uStack_116 = (undefined6)*(undefined8 *)(param_2 + 0x7a);
  local_110 = (undefined2)((ulong)*(undefined8 *)(param_2 + 0x7a) >> 0x30);
  uStack_106 = *(undefined2 *)(param_2 + 0x1e);
  uStack_fc = (undefined4)*(undefined8 *)(param_2 + 0x28);
  uStack_f8 = (undefined4)((ulong)*(undefined8 *)(param_2 + 0x28) >> 0x20);
  uStack_104 = (undefined4)*(undefined8 *)(param_2 + 0x20);
  local_100 = (undefined4)((ulong)*(undefined8 *)(param_2 + 0x20) >> 0x20);
  uStack_ec = (undefined4)*(undefined8 *)(param_2 + 0x38);
  uStack_e8 = (undefined4)((ulong)*(undefined8 *)(param_2 + 0x38) >> 0x20);
  uStack_f4 = (undefined4)*(undefined8 *)(param_2 + 0x30);
  local_f0 = (undefined4)((ulong)*(undefined8 *)(param_2 + 0x30) >> 0x20);
  FUN_fffffff00a354958(&uStack_e4,*(undefined8 *)(param_1 + 0x20),0x10);
  uStack_c8 = *(undefined8 *)(param_1 + 0x338);
  uVar18 = FUN_fffffff00a45a590(param_1,1);
  local_c0 = CONCAT44(local_c0._4_4_,uVar18);
  FUN_fffffff00a228180(&DAT_fffffff00adcb5d8);
  uVar20 = FUN_fffffff00a1d14a0(&DAT_fffffff00adcb814,0x10);
  uVar21 = uVar20;
  if (0xf < uVar20) {
    uVar21 = 0x10;
  }
  if (0xe < uVar20) {
    uVar20 = 0xf;
  }
  FUN_fffffff00aa65b10((long)&local_c0 + 4,&DAT_fffffff00adcb814,uVar21);
  *(undefined1 *)((long)&local_c0 + 4 + uVar20) = 0;
  local_b0 = CONCAT44(DAT_fffffff00adcb708,(undefined4)local_b0);
  uStack_a8 = CONCAT44(DAT_fffffff00adcb828,DAT_fffffff00adcb824);
  iVar19 = FUN_fffffff00a228d30(&DAT_fffffff00adcb5d8);
  if (iVar19 != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("lck_rw_unlock_shared(): lock %p held in mode: %d @%s:%d");
  }
  uStack_d8 = CONCAT44(param_3,(undefined4)uStack_d8);
  local_d0._0_6_ = CONCAT24(param_5,param_4);
  if ((*(byte *)(param_2 + 3) >> 1 & 1) != 0) {
    local_d0 = CONCAT26(local_d0._6_2_,CONCAT24(param_5,param_4)) | 0x100000000000;
  }
  FUN_fffffff00a227a00(&DAT_fffffff00adcb5d8);
  if (param_6 == 0) {
    if (DAT_fffffff00adcb810 != '\x01') {
      uVar21 = FUN_fffffff00a4ba800(param_1);
      if ((uVar21 & 1) == 0) {
        uVar1 = *(ushort *)(param_2 + 2);
        uVar2 = local_170;
        uVar3 = uStack_168;
        uVar4 = local_160;
        uVar5 = uStack_158;
        uVar6 = local_150;
        uVar7 = auStack_148[0];
        uVar8 = auStack_148[1];
        uVar9 = uStack_138;
        uVar10 = local_130;
        uVar11 = local_e0;
        uVar12 = uStack_d8;
        uVar21 = local_d0;
        uVar13 = uStack_c8;
        uVar14 = local_c0;
        uVar15 = uStack_b8;
        uVar16 = local_b0;
        uVar17 = uStack_a8;
joined_r0xfffffff00a4bc778:
        _DAT_fffffff00adcb6e0 = uVar17;
        _DAT_fffffff00adcb6d8 = uVar16;
        _DAT_fffffff00adcb6d0 = uVar15;
        _DAT_fffffff00adcb6c8 = uVar14;
        _DAT_fffffff00adcb6c0 = uVar13;
        _DAT_fffffff00adcb6b8 = uVar21;
        _DAT_fffffff00adcb6b0 = uVar12;
        _DAT_fffffff00adcb6a8 = uVar11;
        _DAT_fffffff00adcb658 = uVar10;
        _DAT_fffffff00adcb650 = uVar9;
        _DAT_fffffff00adcb648 = uVar8;
        _DAT_fffffff00adcb640 = uVar7;
        _DAT_fffffff00adcb638 = uVar6;
        _DAT_fffffff00adcb630 = uVar5;
        _DAT_fffffff00adcb628 = uVar4;
        _DAT_fffffff00adcb620 = uVar3;
        _DAT_fffffff00adcb618 = uVar2;
        if ((uVar1 >> 9 & 1) != 0) {
          DAT_fffffff00ad95780 = DAT_fffffff00ad95780 + 1;
        }
        uStack_188 = 0;
        local_190 = 0;
        uStack_178 = 0;
        uStack_180 = 0;
        uStack_1a8 = 0;
        local_1b0 = 0;
        uStack_198 = 0;
        uStack_1a0 = 0;
        DAT_fffffff00adcb810 = '\x01';
        DAT_fffffff00ad95718 = DAT_fffffff00ad95718 + 1;
        _DAT_fffffff00adcb6a0 = CONCAT44(uStack_e4,uStack_e8);
        _DAT_fffffff00adcb698 = CONCAT44(uStack_ec,local_f0);
        _DAT_fffffff00adcb660 = CONCAT62(uStack_126,uStack_128);
        _DAT_fffffff00adcb670 = CONCAT62(uStack_116,uStack_118);
        _DAT_fffffff00adcb668 = CONCAT62(uStack_11e,local_120);
        _DAT_fffffff00adcb680 = CONCAT44(uStack_104,CONCAT22(uStack_106,uStack_108));
        _DAT_fffffff00adcb678 = CONCAT62(uStack_10e,local_110);
        _DAT_fffffff00adcb690 = CONCAT44(uStack_f4,uStack_f8);
        _DAT_fffffff00adcb688 = CONCAT44(uStack_fc,local_100);
        DAT_fffffff00adcb610 = 1;
        puStack_1b8 = &local_170;
        local_1c0 = 0xd0;
        local_1d0 = _DAT_fffffff00700f510;
        uStack_1c8 = _UNK_fffffff00700f518;
        local_170 = _DAT_fffffff00adcb618;
        uStack_168 = _DAT_fffffff00adcb620;
        local_160 = _DAT_fffffff00adcb628;
        uStack_158 = _DAT_fffffff00adcb630;
        local_150 = _DAT_fffffff00adcb638;
        auStack_148[0] = _DAT_fffffff00adcb640;
        auStack_148[1] = _DAT_fffffff00adcb648;
        uStack_138 = _DAT_fffffff00adcb650;
        local_130 = _DAT_fffffff00adcb658;
        local_e0 = _DAT_fffffff00adcb6a8;
        uStack_d8 = _DAT_fffffff00adcb6b0;
        local_d0 = _DAT_fffffff00adcb6b8;
        uStack_c8 = _DAT_fffffff00adcb6c0;
        local_c0 = _DAT_fffffff00adcb6c8;
        uStack_b8 = _DAT_fffffff00adcb6d0;
        local_b0 = _DAT_fffffff00adcb6d8;
        uStack_a8 = _DAT_fffffff00adcb6e0;
        iVar19 = FUN_fffffff00a7049b0(&local_1d0,0);
        if (iVar19 == 0) goto LAB_fffffff00a4bcb68;
        uStack_80 = 0;
        uStack_98 = 0;
        local_a0 = 0;
        uStack_88 = 0;
        local_83 = 0;
        uStack_90 = 0;
        FUN_fffffff00a76d3ec
                  (&local_a0,0x25,
                   "%02X%02X%02X%02X-%02X%02X-%02X%02X-%02X%02X-%02X%02X%02X%02X%02X%02X");
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,DAT_fffffff00ad95428,0x10,
                   "%s: kev_post_msg() failed with error %d for wake uuid %s");
        goto LAB_fffffff00a4bcaa8;
      }
      if (DAT_fffffff00adcb70c == 1) {
        plVar22 = &DAT_fffffff00ad957d0;
LAB_fffffff00a4bcb00:
        *plVar22 = *plVar22 + 1;
      }
      else if (DAT_fffffff00adcb70c == 2) {
        plVar22 = &DAT_fffffff00ad957d8;
        goto LAB_fffffff00a4bcb00;
      }
      _DAT_fffffff00adcb79c = CONCAT44(uStack_e4,uStack_e8);
      _DAT_fffffff00adcb794 = CONCAT44(uStack_ec,local_f0);
      _DAT_fffffff00adcb7ac = uStack_d8;
      _DAT_fffffff00adcb7a4 = local_e0;
      _DAT_fffffff00adcb7bc = uStack_c8;
      _DAT_fffffff00adcb7b4 = local_d0;
      _DAT_fffffff00adcb7cc = uStack_b8;
      _DAT_fffffff00adcb7c4 = local_c0;
      _DAT_fffffff00adcb7dc = uStack_a8;
      _DAT_fffffff00adcb7d4 = local_b0;
      _DAT_fffffff00adcb75c = CONCAT62(uStack_126,uStack_128);
      _DAT_fffffff00adcb76c = CONCAT62(uStack_116,uStack_118);
      _DAT_fffffff00adcb764 = CONCAT62(uStack_11e,local_120);
      _DAT_fffffff00adcb77c = CONCAT44(uStack_104,CONCAT22(uStack_106,uStack_108));
      _DAT_fffffff00adcb774 = CONCAT62(uStack_10e,local_110);
      _DAT_fffffff00adcb78c = CONCAT44(uStack_f4,uStack_f8);
      _DAT_fffffff00adcb784 = CONCAT44(uStack_fc,local_100);
      _DAT_fffffff00adcb72c = uStack_158;
      _DAT_fffffff00adcb724 = local_160;
      _DAT_fffffff00adcb73c = auStack_148[0];
      _DAT_fffffff00adcb734 = local_150;
      _DAT_fffffff00adcb74c = uStack_138;
      _DAT_fffffff00adcb744 = auStack_148[1];
      _DAT_fffffff00adcb754 = local_130;
      DAT_fffffff00adcb70c = 1;
      _DAT_fffffff00adcb71c = uStack_168;
      _DAT_fffffff00adcb714 = local_170;
      goto LAB_fffffff00a4bcb68;
    }
  }
  else {
    uVar1 = *(ushort *)(param_2 + 2);
    if ((uVar1 >> 0xd & 1) != 0) {
      if ((DAT_fffffff00adcb812 & 1) != 0) goto LAB_fffffff00a4bcb68;
      DAT_fffffff00adcb812 = 1;
      uStack_188 = 0;
      local_190 = 0;
      uStack_178 = 0;
      uStack_180 = 0;
      uStack_1a8 = 0;
      local_1b0 = 0;
      uStack_198 = 0;
      uStack_1a0 = 0;
      DAT_fffffff00ad95718 = DAT_fffffff00ad95718 + 1;
      _DAT_fffffff00adcb6a0 = CONCAT44(uStack_e4,uStack_e8);
      _DAT_fffffff00adcb698 = CONCAT44(uStack_ec,local_f0);
      _DAT_fffffff00adcb6b0 = uStack_d8;
      _DAT_fffffff00adcb6a8 = local_e0;
      _DAT_fffffff00adcb6c0 = uStack_c8;
      _DAT_fffffff00adcb6b8 = local_d0;
      _DAT_fffffff00adcb6d0 = uStack_b8;
      _DAT_fffffff00adcb6c8 = local_c0;
      _DAT_fffffff00adcb6e0 = uStack_a8;
      _DAT_fffffff00adcb6d8 = local_b0;
      _DAT_fffffff00adcb660 = CONCAT62(uStack_126,uStack_128);
      _DAT_fffffff00adcb670 = CONCAT62(uStack_116,uStack_118);
      _DAT_fffffff00adcb668 = CONCAT62(uStack_11e,local_120);
      _DAT_fffffff00adcb680 = CONCAT44(uStack_104,CONCAT22(uStack_106,uStack_108));
      _DAT_fffffff00adcb678 = CONCAT62(uStack_10e,local_110);
      _DAT_fffffff00adcb690 = CONCAT44(uStack_f4,uStack_f8);
      _DAT_fffffff00adcb688 = CONCAT44(uStack_fc,local_100);
      _DAT_fffffff00adcb630 = uStack_158;
      _DAT_fffffff00adcb628 = local_160;
      _DAT_fffffff00adcb640 = auStack_148[0];
      _DAT_fffffff00adcb638 = local_150;
      _DAT_fffffff00adcb650 = uStack_138;
      _DAT_fffffff00adcb648 = auStack_148[1];
      _DAT_fffffff00adcb658 = local_130;
      DAT_fffffff00adcb610 = 1;
      _DAT_fffffff00adcb620 = uStack_168;
      _DAT_fffffff00adcb618 = local_170;
      uStack_1c8 = _UNK_fffffff00700f518;
      local_1d0 = _DAT_fffffff00700f510;
      puStack_1b8 = &local_170;
      local_1c0 = 0xd0;
      iVar19 = FUN_fffffff00a7049b0(&local_1d0,0);
      if (iVar19 == 0) goto LAB_fffffff00a4bcb68;
      uStack_80 = 0;
      uStack_98 = 0;
      local_a0 = 0;
      uStack_88 = 0;
      local_83 = 0;
      uStack_90 = 0;
      FUN_fffffff00a76d3ec
                (&local_a0,0x25,
                 "%02X%02X%02X%02X-%02X%02X-%02X%02X-%02X%02X-%02X%02X%02X%02X%02X%02X");
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad95428,0x10,
                 "%s: kev_post_msg() failed with error %d for wake uuid %s");
LAB_fffffff00a4bcaa8:
      DAT_fffffff00ad95728 = DAT_fffffff00ad95728 + 1;
      goto LAB_fffffff00a4bcb68;
    }
    uVar2 = local_170;
    uVar3 = uStack_168;
    uVar4 = local_160;
    uVar5 = uStack_158;
    uVar6 = local_150;
    uVar7 = auStack_148[0];
    uVar8 = auStack_148[1];
    uVar9 = uStack_138;
    uVar10 = local_130;
    uVar11 = local_e0;
    uVar12 = uStack_d8;
    uVar21 = local_d0;
    uVar13 = uStack_c8;
    uVar14 = local_c0;
    uVar15 = uStack_b8;
    uVar16 = local_b0;
    uVar17 = uStack_a8;
    if (DAT_fffffff00adcb810 != '\x01') goto joined_r0xfffffff00a4bc778;
  }
  DAT_fffffff00ad95720 = DAT_fffffff00ad95720 + 1;
  if (DAT_fffffff00ad9447c != 0) {
    FUN_fffffff00a4b8148("already notified attributed wake packet",param_2);
  }
LAB_fffffff00a4bcb68:
  iVar19 = FUN_fffffff00a228d30(&DAT_fffffff00adcb5d8);
  if (iVar19 != 2) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("lck_rw_unlock_exclusive(): lock %p held in mode: %d @%s:%d");
  }
  if (DAT_fffffff00ad30000 != local_78) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4c590();
  }
  return;
}

