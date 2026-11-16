// FUN_fffffff0081a09a0 @ fffffff0081a09a0 size=3188

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_fffffff0081a09a0(long *param_1,undefined8 param_2,char *param_3)

{
  undefined1 auVar1 [16];
  uint uVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  ulong uVar8;
  ulong uVar10;
  ulong uVar11;
  char *pcVar12;
  ulong uVar13;
  undefined1 auVar14 [16];
  undefined1 local_210 [16];
  long local_200;
  long lStack_1f8;
  undefined8 local_1f0;
  long lStack_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  long local_1c0;
  long local_1b8;
  undefined4 local_1b0;
  int iStack_1ac;
  int iStack_1a8;
  int iStack_1a4;
  int local_1a0;
  uint local_19c;
  long local_198;
  long local_190;
  byte bStack_188;
  byte bStack_187;
  byte bStack_186;
  byte bStack_185;
  byte bStack_184;
  byte bStack_183;
  byte bStack_182;
  byte bStack_181;
  undefined1 uStack_180;
  undefined1 uStack_17f;
  undefined4 uStack_17e;
  undefined2 uStack_17a;
  undefined1 local_170 [16];
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  long local_58;
  long lVar9;
  
  local_58 = *(long *)PTR_DAT_fffffff007ca61a0;
  piVar6 = (int *)(**(code **)(*param_1 + 0xda8))();
  auVar14._8_8_ = local_170._8_8_;
  auVar14._0_8_ = local_170._0_8_;
  uVar13 = 0;
  if (piVar6 != (int *)0x0) {
    local_1d0 = 0;
    local_1b0 = 0;
    local_198 = 0;
    local_19c = 0;
    bStack_188 = 0;
    bStack_187 = 0;
    bStack_185 = 0;
    bStack_183 = 0;
    bStack_182 = 0;
    bStack_181 = 0;
    uStack_17f = 0;
    uStack_17a = 0;
    lStack_1e8 = 0;
    local_1f0 = 0;
    local_1d8 = 0;
    local_1e0 = 0;
    local_210._8_8_ = 0;
    local_210._0_8_ = 0;
    lStack_1f8 = 0;
    local_200 = 0;
    local_1c0 = 0x100000001;
    uStack_1c8 = 0x100000001;
    local_1b8 = 0x100000001;
    iStack_1a4 = 1;
    local_1a0 = 1;
    iStack_1ac = 1;
    iStack_1a8 = 1;
    local_190 = 0;
    bStack_186 = 0;
    bStack_184 = 1;
    uStack_180 = 0;
    uStack_17e = 1;
    (**(code **)(*param_1 + 0xdb0))(param_1,local_210);
    lVar9 = local_1f0;
    if ((((int)local_1f0 != 0) && ((int)local_1e0 != 0)) && (local_1d0._4_4_ != 0)) {
      if (((int)local_1f0 == DAT_fffffff00ae22d40) &&
         (((local_1f0._4_4_ == 0 || (local_1f0._4_4_ == DAT_fffffff00ae22d44)) ||
          (DAT_fffffff00ae22d44 == 0)))) {
        if ((((int)lStack_1e8 != DAT_fffffff00ae22d48) || ((int)local_1e0 != DAT_fffffff00ae22d50))
           || (local_1d0._4_4_ != DAT_fffffff00ae22d64)) goto LAB_fffffff0081a0ac0;
        if ((int)local_1d8 != DAT_fffffff00ae22d58) goto LAB_fffffff0081a0ac0;
        if (local_1e0._4_4_ != DAT_fffffff00ae22d54) goto LAB_fffffff0081a0ac0;
        if (local_1d8._4_4_ != DAT_fffffff00ae22d5c) goto LAB_fffffff0081a0ac0;
        if ((int)local_1d0 != DAT_fffffff00ae22d60) goto LAB_fffffff0081a0ac0;
        if ((int)uStack_1c8 != DAT_fffffff00ae22d68) goto LAB_fffffff0081a0ac0;
        if (uStack_1c8._4_4_ != DAT_fffffff00ae22d6c) goto LAB_fffffff0081a0ac0;
        if (((((((int)local_1c0 != DAT_fffffff00ae22d70) || (iStack_1ac != DAT_fffffff00ae22d84)) ||
              (iStack_1a8 != DAT_fffffff00ae22d88)) ||
             ((iStack_1a4 != DAT_fffffff00ae22d8c || (local_1a0 != DAT_fffffff00ae22d90)))) ||
            ((((DAT_fffffff00ae22da8 ^ bStack_188) & 1) != 0 ||
             ((((DAT_fffffff00ae22da9 ^ bStack_187) & 1) != 0 ||
              (((DAT_fffffff00ae22dad ^ bStack_183) & 1) != 0)))))) ||
           ((((DAT_fffffff00ae22dae ^ bStack_182) & 1) != 0 ||
            (((DAT_fffffff00ae22daf ^ bStack_181) & 1) != 0)))) goto LAB_fffffff0081a0ac0;
        bVar3 = true;
      }
      else {
LAB_fffffff0081a0ac0:
        uStack_78 = 0;
        local_80 = 0;
        uStack_68 = 0;
        uStack_70 = 0;
        uStack_98 = 0;
        local_a0 = 0;
        uStack_88 = 0;
        uStack_90 = 0;
        uStack_b8 = 0;
        local_c0 = 0;
        uStack_a8 = 0;
        uStack_b0 = 0;
        uStack_d8 = 0;
        local_e0 = 0;
        uStack_c8 = 0;
        uStack_d0 = 0;
        uStack_f8 = 0;
        local_100 = 0;
        uStack_e8 = 0;
        uStack_f0 = 0;
        uStack_118 = 0;
        local_120 = 0;
        uStack_108 = 0;
        uStack_110 = 0;
        uStack_138 = 0;
        local_140 = 0;
        uStack_128 = 0;
        uStack_130 = 0;
        uStack_158 = 0;
        local_160 = 0;
        uStack_148 = 0;
        uStack_150 = 0;
        uVar4 = FUN_fffffff0081a1614(&local_1f0,&local_160,0x100);
        uVar13 = (ulong)(0x100 - uVar4) + (ulong)uVar4;
        if (uVar13 >> 0x20 != 0) {
LAB_fffffff0081a15f8:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    ("bounded_array_ref: n + m is larger than the size of any bounded_array_ref");
        }
        if (0x100 < uVar13) {
LAB_fffffff0081a1604:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff008214ca8
                    (
                    "bounded_array_ref: invalid slice provided, the indices are of bounds for the bounded_array_ref"
                    );
        }
        iVar5 = thunk_EXT_FUN_80110000037693ec
                          ((long)&local_160 + (ulong)uVar4,(ulong)(0x100 - uVar4)," [");
        uVar4 = iVar5 + uVar4;
        uVar13 = (ulong)(0x100 - uVar4) + (ulong)uVar4;
        if (uVar13 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
        if (0x100 < uVar13) goto LAB_fffffff0081a1604;
        iVar5 = thunk_EXT_FUN_80110000037693ec
                          ((long)&local_160 + (ulong)uVar4,(ulong)(0x100 - uVar4),"%uMGPUs");
        uVar4 = iVar5 + uVar4;
        uVar13 = (ulong)(0x100 - uVar4) + (ulong)uVar4;
        if (uVar13 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
        if (0x100 < uVar13) goto LAB_fffffff0081a1604;
        iVar5 = thunk_EXT_FUN_80110000037693ec
                          ((long)&local_160 + (ulong)uVar4,(ulong)(0x100 - uVar4)," %uGVDMs");
        uVar4 = iVar5 + uVar4;
        uVar13 = (ulong)(0x100 - uVar4) + (ulong)uVar4;
        if (uVar13 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
        if (0x100 < uVar13) goto LAB_fffffff0081a1604;
        iVar5 = thunk_EXT_FUN_80110000037693ec
                          ((long)&local_160 + (ulong)uVar4,(ulong)(0x100 - uVar4)," %uCores");
        uVar4 = iVar5 + uVar4;
        uVar13 = (ulong)uVar4;
        if ((bStack_186 & 1) != 0) {
          uVar11 = (0x100 - uVar4) + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec
                            ((long)&local_160 + uVar13,(ulong)(0x100 - uVar4),"(");
          uVar4 = iVar5 + uVar4;
          uVar13 = (ulong)(0x100 - uVar4) + (ulong)uVar4;
          if (uVar13 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar13) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec
                            ((long)&local_160 + (ulong)uVar4,(ulong)(0x100 - uVar4),"%u)");
          uVar13 = (ulong)(iVar5 + uVar4);
        }
        uVar8 = (ulong)(0x100 - (int)uVar13);
        uVar11 = uVar8 + uVar13;
        if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
        if (0x100 < uVar11) goto LAB_fffffff0081a1604;
        iVar5 = thunk_EXT_FUN_80110000037693ec((long)&local_160 + uVar13,uVar8," %uFrags");
        uVar4 = iVar5 + (int)uVar13;
        uVar13 = (ulong)uVar4;
        if ((bStack_186 & 1) != 0) {
          uVar11 = (0x100 - uVar4) + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec
                            ((long)&local_160 + uVar13,(ulong)(0x100 - uVar4),"(");
          uVar4 = iVar5 + uVar4;
          uVar13 = (ulong)(0x100 - uVar4) + (ulong)uVar4;
          if (uVar13 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar13) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec
                            ((long)&local_160 + (ulong)uVar4,(ulong)(0x100 - uVar4),"%u)");
          uVar13 = (ulong)(iVar5 + uVar4);
        }
        if ((bStack_185 & 1) != 0) {
          uVar8 = (ulong)(0x100 - (int)uVar13);
          uVar11 = uVar8 + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec
                            ((long)&local_160 + uVar13,uVar8," SWProtoHarvesting");
          uVar13 = (ulong)(uint)(iVar5 + (int)uVar13);
        }
        if (local_1e0._4_4_ != 0) {
          uVar8 = (ulong)(0x100 - (int)uVar13);
          uVar11 = uVar8 + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec((long)&local_160 + uVar13,uVar8," %uTEs");
          uVar13 = (ulong)(uint)(iVar5 + (int)uVar13);
        }
        if ((int)local_1d8 != 0) {
          uVar8 = (ulong)(0x100 - (int)uVar13);
          uVar11 = uVar8 + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec((long)&local_160 + uVar13,uVar8," %uVCEs");
          uVar13 = (ulong)(uint)(iVar5 + (int)uVar13);
        }
        if (local_1d8._4_4_ != 0) {
          uVar8 = (ulong)(0x100 - (int)uVar13);
          uVar11 = uVar8 + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec((long)&local_160 + uVar13,uVar8," %uGPs");
          uVar13 = (ulong)(uint)(iVar5 + (int)uVar13);
        }
        if ((int)local_1d0 != 0) {
          uVar8 = (ulong)(0x100 - (int)uVar13);
          uVar11 = uVar8 + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec((long)&local_160 + uVar13,uVar8," %uIPFPipes");
          uVar13 = (ulong)(uint)(iVar5 + (int)uVar13);
        }
        if ((int)uStack_1c8 != 0) {
          uVar8 = (ulong)(0x100 - (int)uVar13);
          uVar11 = uVar8 + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec((long)&local_160 + uVar13,uVar8," %uGTPSlots");
          uVar13 = (ulong)(uint)(iVar5 + (int)uVar13);
        }
        if (uStack_1c8._4_4_ != 0) {
          uVar8 = (ulong)(0x100 - (int)uVar13);
          uVar11 = uVar8 + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec((long)&local_160 + uVar13,uVar8," %uFRGSlots");
          uVar13 = (ulong)(uint)(iVar5 + (int)uVar13);
        }
        if ((int)local_1c0 != 0) {
          uVar8 = (ulong)(0x100 - (int)uVar13);
          uVar11 = uVar8 + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec((long)&local_160 + uVar13,uVar8," %uCDMSlots");
          uVar13 = (ulong)(uint)(iVar5 + (int)uVar13);
        }
        if ((bStack_188 & 1) != 0) {
          uVar8 = (ulong)(0x100 - (int)uVar13);
          uVar11 = uVar8 + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec
                            ((long)&local_160 + uVar13,uVar8," SKSMInGPUCorePowerDomain");
          uVar13 = (ulong)(uint)(iVar5 + (int)uVar13);
        }
        if ((bStack_187 & 1) != 0) {
          uVar8 = (ulong)(0x100 - (int)uVar13);
          uVar11 = uVar8 + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec((long)&local_160 + uVar13,uVar8," DVMR");
          uVar13 = (ulong)(uint)(iVar5 + (int)uVar13);
        }
        if ((bStack_183 & 1) != 0) {
          uVar8 = (ulong)(0x100 - (int)uVar13);
          uVar11 = uVar8 + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec((long)&local_160 + uVar13,uVar8," CSClkDomain");
          uVar13 = (ulong)(uint)(iVar5 + (int)uVar13);
        }
        if ((bStack_182 & 1) != 0) {
          uVar8 = (ulong)(0x100 - (int)uVar13);
          uVar11 = uVar8 + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec((long)&local_160 + uVar13,uVar8," AFRClkDomain");
          uVar13 = (ulong)(uint)(iVar5 + (int)uVar13);
        }
        if ((bStack_181 & 1) != 0) {
          uVar8 = (ulong)(0x100 - (int)uVar13);
          uVar11 = uVar8 + uVar13;
          if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
          if (0x100 < uVar11) goto LAB_fffffff0081a1604;
          iVar5 = thunk_EXT_FUN_80110000037693ec((long)&local_160 + uVar13,uVar8," CSAFRRailMerged")
          ;
          uVar13 = (ulong)(uint)(iVar5 + (int)uVar13);
        }
        uVar11 = (0x100 - (int)uVar13) + uVar13;
        if (uVar11 >> 0x20 != 0) goto LAB_fffffff0081a15f8;
        if (0x100 < uVar11) goto LAB_fffffff0081a1604;
        param_3 = "]";
        thunk_EXT_FUN_80110000037693ec((long)&local_160 + uVar13);
        _DAT_fffffff00ae22d88 = CONCAT44(iStack_1a4,iStack_1a8);
        _DAT_fffffff00ae22d80 = CONCAT44(iStack_1ac,local_1b0);
        _DAT_fffffff00ae22d90 = CONCAT44(local_19c,local_1a0);
        _DAT_fffffff00ae22da9 =
             (undefined4)
             (CONCAT14(bStack_184,
                       CONCAT13(bStack_185,CONCAT12(bStack_186,CONCAT11(bStack_187,bStack_188)))) >>
             8);
        _DAT_fffffff00ae22db0 = CONCAT42(uStack_17e,CONCAT11(uStack_17f,uStack_180));
        bVar3 = local_1d0._4_4_ != 0;
        uRamfffffff00ae22d28 = local_210._8_8_;
        _DAT_fffffff00ae22d20 = local_210._0_8_;
        lRamfffffff00ae22d38 = lStack_1f8;
        _DAT_fffffff00ae22d30 = local_200;
        lRamfffffff00ae22d98 = local_198;
        DAT_fffffff00ae22da0 = local_190;
        _DAT_fffffff00ae22d48 = lStack_1e8;
        _DAT_fffffff00ae22d40 = local_1f0;
        _DAT_fffffff00ae22d58 = local_1d8;
        _DAT_fffffff00ae22d50 = local_1e0;
        _DAT_fffffff00ae22d68 = uStack_1c8;
        _DAT_fffffff00ae22d60 = local_1d0;
        lRamfffffff00ae22d78 = local_1b8;
        _DAT_fffffff00ae22d70 = local_1c0;
        DAT_fffffff00ae22da8 = bStack_188;
        DAT_fffffff00ae22dad = bStack_183;
        DAT_fffffff00ae22dae = bStack_182;
        DAT_fffffff00ae22daf = bStack_181;
        lVar9 = local_1f0;
      }
      if (((((int)local_1f0 != 0) && ((int)local_1e0 != 0)) && (bVar3)) &&
         (iVar5 = *piVar6, iVar5 != 0)) {
        local_1f0._4_4_ = (int)((ulong)lVar9 >> 0x20);
        piVar7 = piVar6;
        if (local_1f0._4_4_ == 0) {
          uVar13 = 1;
          do {
            if (((int)lVar9 == iVar5) && ((int)lStack_1e8 == piVar7[2])) goto LAB_fffffff0081a13a8;
            iVar5 = (int)(uVar13 * 0x10);
            piVar7 = (int *)((long)piVar6 + (long)iVar5);
            if (uVar13 * 0x10 != (long)iVar5) {
              piVar7 = (int *)((ulong)(piVar6 + uVar13 * 4) & 0xffffffffffff | 0x2bad000000000000);
            }
            iVar5 = *piVar7;
            uVar13 = (ulong)((int)uVar13 + 1);
          } while (iVar5 != 0);
        }
        else {
          uVar13 = 1;
          do {
            if ((((int)lVar9 == iVar5) && (local_1f0._4_4_ == piVar7[1] || piVar7[1] == 0)) &&
               ((int)lStack_1e8 == piVar7[2])) goto LAB_fffffff0081a13a8;
            iVar5 = (int)(uVar13 * 0x10);
            piVar7 = (int *)((long)piVar6 + (long)iVar5);
            if (uVar13 * 0x10 != (long)iVar5) {
              piVar7 = (int *)((ulong)(piVar6 + uVar13 * 4) & 0xffffffffffff | 0x2bad000000000000);
            }
            iVar5 = *piVar7;
            uVar13 = (ulong)((int)uVar13 + 1);
          } while (iVar5 != 0);
        }
      }
    }
    local_1f0 = lVar9;
    (**(code **)(*param_1 + 0x38))(param_1);
    thunk_EXT_FUN_8011000003891b28();
    auVar14._8_8_ = local_170._8_8_;
    auVar14._0_8_ = local_170._0_8_;
    uVar13 = 0;
  }
  goto LAB_fffffff0081a1330;
LAB_fffffff0081a13a8:
  uStack_f8 = 0;
  local_100 = 0;
  uStack_e8 = 0;
  uStack_f0 = 0;
  uStack_118 = 0;
  local_120 = 0;
  uStack_108 = 0;
  uStack_110 = 0;
  uStack_138 = 0;
  local_140 = 0;
  uStack_128 = 0;
  uStack_130 = 0;
  uStack_158 = 0;
  local_160 = 0;
  uStack_148 = 0;
  uStack_150 = 0;
  param_3 = (char *)0x80;
  local_1f0 = lVar9;
  FUN_fffffff0081a1614(piVar7,&local_160);
  (**(code **)(*param_1 + 0x38))(param_1);
  thunk_EXT_FUN_8011000003891b28();
  auVar14._8_8_ = local_170._8_8_;
  auVar14._0_8_ = local_170._0_8_;
  if ((bStack_186 & 1) == 0) {
    local_210 = ZEXT816(0);
  }
  else {
    pcVar12 = (char *)(local_1e0 & 0xffffffff);
    param_3 = pcVar12;
    local_170 = (**(code **)(*param_1 + 0xdc0))(param_1,local_210);
    auVar1._8_8_ = lStack_1f8;
    auVar1._0_8_ = local_200;
    uVar4 = (uint)(byte)(POPCOUNT(local_170[8]) + POPCOUNT(local_170[9]) + POPCOUNT(local_170[10]) +
                         POPCOUNT(local_170[0xb]) + POPCOUNT(local_170[0xc]) +
                         POPCOUNT(local_170[0xd]) + POPCOUNT(local_170[0xe]) +
                        POPCOUNT(local_170[0xf])) +
            (uint)(byte)(POPCOUNT(local_170[0]) + POPCOUNT(local_170[1]) + POPCOUNT(local_170[2]) +
                         POPCOUNT(local_170[3]) + POPCOUNT(local_170[4]) + POPCOUNT(local_170[5]) +
                         POPCOUNT(local_170[6]) + POPCOUNT(local_170[7]));
    if (uVar4 < local_19c) {
      local_170._0_8_ = local_200;
      local_170._8_8_ = lStack_1f8;
      uVar4 = (uint)(byte)(POPCOUNT((char)lStack_1f8) + POPCOUNT((char)((ulong)lStack_1f8 >> 8)) +
                           POPCOUNT((char)((ulong)lStack_1f8 >> 0x10)) +
                           POPCOUNT((char)((ulong)lStack_1f8 >> 0x18)) +
                           POPCOUNT((char)((ulong)lStack_1f8 >> 0x20)) +
                           POPCOUNT((char)((ulong)lStack_1f8 >> 0x28)) +
                           POPCOUNT((char)((ulong)lStack_1f8 >> 0x30)) +
                          POPCOUNT((char)((ulong)lStack_1f8 >> 0x38))) +
              (uint)(byte)(POPCOUNT((char)local_200) + POPCOUNT((char)((ulong)local_200 >> 8)) +
                           POPCOUNT((char)((ulong)local_200 >> 0x10)) +
                           POPCOUNT((char)((ulong)local_200 >> 0x18)) +
                           POPCOUNT((char)((ulong)local_200 >> 0x20)) +
                           POPCOUNT((char)((ulong)local_200 >> 0x28)) +
                           POPCOUNT((char)((ulong)local_200 >> 0x30)) +
                          POPCOUNT((char)((ulong)local_200 >> 0x38)));
    }
    uVar2 = uVar4;
    auVar14 = local_170;
    for (; (uint)local_198 < uVar4; uVar4 = uVar4 - 1) {
      local_170._8_8_ = auVar14._8_8_;
      local_170._0_8_ = auVar14._0_8_;
      if (local_170._0_8_ == 0) {
        if (local_170._8_8_ != 0) {
          uVar13 = 0x40;
          goto LAB_fffffff0081a1494;
        }
        uVar13 = 0xffffffff;
      }
      else {
        uVar13 = 0;
        local_170._8_8_ = local_170._0_8_;
LAB_fffffff0081a1494:
        uVar11 = (local_170._8_8_ & 0xaaaaaaaaaaaaaaaa) >> 1 |
                 (local_170._8_8_ & 0x5555555555555555) << 1;
        uVar11 = (uVar11 & 0xcccccccccccccccc) >> 2 | (uVar11 & 0x3333333333333333) << 2;
        uVar11 = (uVar11 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar11 & 0xf0f0f0f0f0f0f0f) << 4;
        uVar11 = (uVar11 & 0xff00ff00ff00ff00) >> 8 | (uVar11 & 0xff00ff00ff00ff) << 8;
        uVar11 = (uVar11 & 0xffff0000ffff0000) >> 0x10 | (uVar11 & 0xffff0000ffff) << 0x10;
        uVar13 = LZCOUNT(uVar11 >> 0x20 | uVar11 << 0x20) | uVar13;
      }
      uVar11 = uVar13 >> 3 & 0x1ffffff8;
      local_170 = auVar14;
      *(ulong *)(local_170 + uVar11) =
           *(ulong *)(local_170 + uVar11) & (1L << (uVar13 & 0x3f) ^ 0xffffffffffffffffU);
      uVar2 = (uint)local_198;
      auVar14 = local_170;
    }
    if (((char *)(long)(int)uVar2 != pcVar12) && ((bStack_184 & 1) != 0)) {
      local_1e0 = CONCAT44(local_1e0._4_4_,uVar2);
      local_1d0 = CONCAT44(uVar2,(int)local_1d0);
    }
    local_210 = auVar14;
    if (auVar14 == auVar1) {
      local_210 = ZEXT816(0);
    }
  }
  lVar9 = _DAT_fffffff007113890;
  if ((bStack_187 & 1) == 0) {
    param_1[0x3170] = _UNK_fffffff007113898;
    param_1[0x316f] = lVar9;
    param_1[0x3178] = 0;
    param_1[0x3177] = 0;
    lVar9 = _DAT_fffffff0071138a0;
    param_1[0x3172] = _UNK_fffffff0071138a8;
    param_1[0x3171] = lVar9;
    param_1[0x317a] = 0;
    param_1[0x3179] = 0;
    lVar9 = _DAT_fffffff0071138b0;
    param_1[0x3174] = _UNK_fffffff0071138b8;
    param_1[0x3173] = lVar9;
    param_1[0x317c] = 0;
    param_1[0x317b] = 0;
    lVar9 = _DAT_fffffff0071138c0;
    param_1[0x3176] = _UNK_fffffff0071138c8;
    param_1[0x3175] = lVar9;
    param_1[0x317e] = 0;
    param_1[0x317d] = 0;
  }
  else {
    local_170 = auVar14;
    (**(code **)(*param_1 + 0xdb8))(param_1);
    auVar14 = local_170;
  }
  *(undefined1 (*) [16])(param_1 + 0x76) = local_210;
  param_1[0x79] = lStack_1f8;
  param_1[0x78] = local_200;
  param_1[0x83] = CONCAT44(iStack_1a4,iStack_1a8);
  param_1[0x82] = CONCAT44(iStack_1ac,local_1b0);
  param_1[0x85] = local_198;
  param_1[0x84] = CONCAT44(local_19c,local_1a0);
  param_1[0x87] =
       CONCAT17(bStack_181,
                CONCAT16(bStack_182,
                         CONCAT15(bStack_183,
                                  CONCAT14(bStack_184,
                                           CONCAT13(bStack_185,
                                                    CONCAT12(bStack_186,
                                                             CONCAT11(bStack_187,bStack_188)))))));
  param_1[0x86] = local_190;
  *(ulong *)((long)param_1 + 0x43e) =
       CONCAT44(uStack_17e,CONCAT13(uStack_17f,CONCAT12(uStack_180,CONCAT11(bStack_181,bStack_182)))
               );
  param_1[0x7b] = lStack_1e8;
  param_1[0x7a] = local_1f0;
  param_1[0x7d] = local_1d8;
  param_1[0x7c] = local_1e0;
  uVar13 = 10000;
  param_1[0x7f] = uStack_1c8;
  param_1[0x7e] = local_1d0;
  param_1[0x81] = local_1b8;
  param_1[0x80] = local_1c0;
LAB_fffffff0081a1330:
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_58) {
    return uVar13;
  }
  local_170 = auVar14;
  auVar14 = thunk_EXT_FUN_8011000003a48590(uVar13);
  lVar9 = auVar14._8_8_;
  uVar11 = (ulong)param_3 & 0xffffffff;
  uVar13 = thunk_EXT_FUN_80110000037693ec(lVar9,uVar11,"%s %s");
  if (*(int *)(auVar14._0_8_ + 8) == 0) {
    return uVar13;
  }
  uVar10 = (ulong)(uint)((int)param_3 - (int)uVar13);
  uVar8 = uVar10 + (uVar13 & 0xffffffff);
  if (uVar8 >> 0x20 != 0) {
LAB_fffffff0081a1724:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff008214ca8
              ("bounded_array_ref: n + m is larger than the size of any bounded_array_ref");
  }
  if (uVar8 <= uVar11) {
    iVar5 = thunk_EXT_FUN_80110000037693ec(lVar9 + (uVar13 & 0xffffffff),uVar10," (");
    uVar4 = iVar5 + (int)uVar13;
    uVar8 = (ulong)((int)param_3 - uVar4);
    uVar13 = uVar8 + uVar4;
    if (uVar13 >> 0x20 != 0) goto LAB_fffffff0081a1724;
    if (uVar13 <= uVar11) {
      iVar5 = thunk_EXT_FUN_80110000037693ec(lVar9 + (ulong)uVar4,uVar8,")");
      return (ulong)(iVar5 + uVar4);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff008214ca8
            (
            "bounded_array_ref: invalid slice provided, the indices are of bounds for the bounded_array_ref"
            );
}

