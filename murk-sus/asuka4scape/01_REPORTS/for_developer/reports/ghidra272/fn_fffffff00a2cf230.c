// FUN_fffffff00a2cf230 @ fffffff00a2cf230 size=15484

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_fffffff00a2cf230
                (ulong param_1,ulong param_2,undefined8 param_3,undefined4 param_4,
                undefined8 *param_5,ulong param_6,int *param_7,ushort *param_8,undefined8 *param_9)

{
  long lVar1;
  long *plVar2;
  ulong *puVar3;
  uint uVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  ushort uVar8;
  ushort uVar9;
  long lVar10;
  bool bVar11;
  bool bVar12;
  ulong uVar13;
  code *pcVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  long lVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  undefined8 uVar22;
  ulong uVar23;
  undefined8 *puVar24;
  undefined4 *puVar25;
  undefined8 uVar26;
  ulong uVar27;
  uint uVar28;
  long lVar29;
  undefined8 *puVar30;
  long *plVar31;
  ulong uVar32;
  byte bVar33;
  ulong uVar34;
  undefined4 *puVar35;
  undefined8 *puVar36;
  undefined8 *puVar37;
  undefined4 *puVar38;
  undefined8 *puVar39;
  undefined4 *puVar40;
  uint uVar41;
  uint uVar42;
  ulong uVar43;
  ulong uVar44;
  long lVar45;
  ulong uVar46;
  undefined4 *puVar47;
  long lVar48;
  undefined4 in_wzr;
  undefined1 auVar49 [16];
  ushort *puVar50;
  undefined4 uVar53;
  undefined1 *puVar51;
  byte *pbVar52;
  undefined8 *in_stack_fffffffffffffd20;
  undefined4 uVar54;
  undefined4 uVar55;
  undefined8 in_stack_fffffffffffffd30;
  undefined4 uVar56;
  undefined8 local_290;
  undefined4 local_27c;
  ulong local_220;
  undefined4 *local_210;
  ulong local_1e8;
  int local_1d8;
  uint local_1d4;
  int local_1b8;
  uint local_1ac;
  ulong local_1a8;
  undefined4 *local_1a0;
  ulong local_198;
  long lStack_190;
  undefined8 local_188;
  undefined8 local_180;
  long lStack_178;
  undefined8 local_170;
  byte local_161;
  long local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  long local_148;
  undefined8 local_140;
  uint uStack_138;
  ushort uStack_134;
  undefined2 uStack_132;
  undefined8 local_130;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 local_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 local_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 local_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  long local_f0;
  long local_e8;
  undefined1 local_dd;
  int local_dc;
  undefined4 *local_d8;
  undefined8 local_d0;
  long local_c8;
  byte local_b9;
  ulong local_b8;
  uint local_b0;
  uint local_ac;
  undefined8 local_a8;
  undefined8 *local_a0;
  uint local_94;
  ulong local_90;
  undefined4 *local_88;
  int local_7c;
  ulong local_78 [3];
  
  uVar13 = DAT_fffffff007c6a380;
  uVar43 = DAT_fffffff007c6a378;
  uVar46 = DAT_fffffff007c6a360;
  uVar23 = DAT_fffffff007c6a358;
  uVar32 = DAT_fffffff007c678d8;
  local_7c = 0;
  local_90 = 0;
  local_88 = (undefined4 *)0x0;
  local_94 = 0;
  local_a8 = 0;
  local_a0 = (undefined8 *)0x0;
  local_ac = 0;
  local_b9 = 0;
  local_d8 = (undefined4 *)0x0;
  local_d0 = 0;
  local_c8 = 0;
  local_dd = 0;
  local_f0 = 0;
  local_e8 = 0;
  uStack_108 = 0;
  uStack_104 = 0;
  local_110 = 0;
  uStack_10c = 0;
  uStack_f8 = 0;
  uStack_f4 = 0;
  local_100 = 0;
  uStack_fc = 0;
  uStack_118 = 0;
  uStack_114 = 0;
  local_120 = 0;
  uStack_11c = 0;
  uStack_138 = 0;
  uStack_134 = 0;
  uStack_132 = 0;
  local_140 = 0;
  uStack_128 = 0;
  uStack_124 = 0;
  local_130._0_4_ = 0;
  local_130._4_4_ = 0;
  uStack_158 = 0;
  local_160 = 0;
  local_148 = 0;
  local_150 = 0;
  if ((*(byte *)(param_1 + 0xf9) >> 6 & 1) != 0) {
    return 1;
  }
  uVar44 = (ulong)*(byte *)(param_1 + 0x2c);
  lVar29 = 1L << (uVar44 & 0x3f);
  uVar34 = -1L << (uVar44 & 0x3f);
  if (0xd < *(byte *)(param_1 + 0x2c)) {
    lVar29 = 0x4000;
    uVar34 = 0xffffffffffffc000;
  }
  uVar34 = param_2 & uVar34;
  uVar27 = uVar34;
  local_b8 = param_1;
  local_78[0] = param_1;
  if (param_1 == DAT_fffffff007c678d8) {
    uVar5 = uVar34 & 0x7ffffffffff;
    if ((param_2 & 0x80000000000000) != 0) {
      uVar5 = uVar34 | 0xffffff8000000000;
    }
    if (((uVar5 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar5) ||
        (DAT_fffffff007c6a378 <= uVar5 && uVar5 < DAT_fffffff007c6a380)) ||
       ((uVar27 = 0, DAT_fffffff007c6a3a0 <= uVar5 && (uVar5 < DAT_fffffff007c6a3a8)))) {
      uVar27 = FUN_fffffff00a396010();
    }
    uVar5 = param_2 & 0x7ffffffffff;
    if ((param_2 & 0x80000000000000) != 0) {
      uVar5 = param_2 | 0xffffff8000000000;
    }
    if (((uVar5 < uVar46 && uVar23 <= uVar5) || (uVar43 <= uVar5 && uVar5 < uVar13)) ||
       ((param_2 = 0, DAT_fffffff007c6a3a0 <= uVar5 && (uVar5 < DAT_fffffff007c6a3a8)))) {
      param_2 = FUN_fffffff00a396010();
    }
  }
  if ((DAT_fffffff00ad98b00 & 0xfffffff7) != 0) {
    FUN_fffffff00a6de494(0x1300009,uVar27 >> 0x20,uVar27,param_1 == uVar32,0);
  }
  lVar10 = tpidr_el1;
  if (*(int *)(lVar10 + 0x1c0) == 0) {
    if ((*(byte *)(lVar10 + 1000) & 1) == 0) {
      iVar6 = *(int *)(lVar10 + 0x1ec);
      local_161 = 0;
      if (iVar6 == 1) {
        local_290 = UnkSytemRegRead(3,4,0xf,10,6);
      }
      else {
        local_290 = 0;
      }
      uVar8 = *(ushort *)(lVar10 + 200);
      *(ushort *)(lVar10 + 200) = uVar8 & 0xfffc | *param_8 & 3;
      uVar41 = (uint)param_3;
      uVar4 = uVar41;
      if ((*(uint *)(param_8 + 0x14) & 0x800) != 0) {
        uVar4 = 0;
      }
      plVar31 = (long *)(_DAT_fffffff00ad0e438 + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
      lVar18 = *plVar31;
      *plVar31 = lVar18 + 1;
      lVar18 = FUN_fffffff00a29bafc(lVar18,lVar10);
      plVar31 = (long *)(*(long *)(lVar18 + 0x380) + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
      *plVar31 = *plVar31 + 1;
      if ((uVar4 >> 1 & 1) == 0) {
        local_1b8 = 1;
        if ((*(byte *)((long)param_8 + 0x29) & 8) != 0) {
          local_1b8 = 2;
        }
      }
      else {
        local_1b8 = 2;
      }
      local_dc = 0;
      if ((((param_1 == DAT_fffffff007c678d8) && ((uVar41 >> 1 & 1) != 0)) &&
          (DAT_fffffff00ad46000 != 0)) &&
         ((*(ulong *)(DAT_fffffff00ad46000 + 0x10) <= uVar34 &&
          (uVar34 < *(ulong *)(DAT_fffffff00ad46000 + 0x18))))) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114("Write fault on compressor map, va: %p type: %u bounds: %p->%p @%s:%d")
        ;
      }
      puVar47 = (undefined4 *)0x0;
      bVar11 = false;
      bVar12 = false;
      local_27c = 0;
      local_1d4 = uVar4 >> 1 & 1;
      uVar32 = uVar34;
      if (param_5 != (undefined8 *)0x0) {
        uVar32 = param_6;
      }
      local_1e8 = 0xffffffffffffffff;
      local_1d8 = 1;
LAB_fffffff00a2cf624:
      plVar31 = &local_160;
      local_b0 = 4;
      if (bVar11) {
        DAT_fffffff00ad94e88 = DAT_fffffff00ad94e88 + 1;
        uVar28 = 0x10;
        local_1b8 = 2;
        local_1d4 = 1;
        uVar42 = 1;
      }
      else {
        uVar28 = 0x10;
        uVar42 = uVar4;
        if (local_1d4 == 0) {
          uVar28 = 0;
        }
      }
      uStack_f4 = 0;
      uStack_f8 = 0;
      uStack_fc = 0;
      local_100 = 0;
      uStack_104 = 0;
      uStack_108 = 0;
      uStack_10c = 0;
      local_110 = 0;
      uStack_114 = 0;
      uStack_118 = 0;
      uStack_11c = 0;
      local_120 = 0;
      uStack_124 = 0;
      uStack_128 = 0;
      local_130._4_4_ = 0;
      local_130._0_4_ = 0;
      uStack_132 = 0;
      uStack_134 = 0;
      uStack_138 = 0;
      local_140 = 0;
      local_148 = 0;
      local_150 = 0;
      uStack_158 = 0;
      local_160 = 0;
      in_stack_fffffffffffffd20 =
           (undefined8 *)((ulong)in_stack_fffffffffffffd20 & 0xffffffffffffff00);
      puVar50 = param_8;
      local_78[0] = param_1;
      uVar23 = FUN_fffffff00a2d2eac
                         (local_78,uVar34,uVar28 | uVar42,&local_88,&local_e8,&local_90,&local_94,
                          &local_7c,param_8,&local_b8,plVar31,param_9,in_stack_fffffffffffffd20);
      *(int *)(lVar10 + 0x1c0) = *(int *)(lVar10 + 0x1c0) + 1;
      lVar45 = *(long *)(lVar10 + 0x1b0) >> 0x10;
      plVar2 = (long *)(&DAT_fffffff00ad28260 + lVar45);
      if (*plVar2 == 0) {
        puVar30 = *(undefined8 **)(&DAT_fffffff00ad28268 + lVar45);
        if (puVar30 == (undefined8 *)0x0) {
          *plVar2 = 0;
        }
        else {
          *(undefined8 *)(&DAT_fffffff00ad28268 + lVar45) = *puVar30;
          *puVar30 = 0;
          *plVar2 = (long)puVar30;
          if ((puVar30 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar30)) {
            uVar28 = *(uint *)((long)puVar30 + 0x3c);
          }
          else {
            uVar28 = DAT_fffffff007bf0000 +
                     (int)((ulong)((long)puVar30 - (long)DAT_fffffff007bf0010) >> 6);
          }
          FUN_fffffff00a38dfd0((ulong)uVar28 << 0xe,0x4000);
          plVar2 = (long *)(_DAT_fffffff00ad0e4f8 + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
          *plVar2 = *plVar2 + 1;
        }
      }
      if (*(int *)(lVar10 + 0x1c0) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa5c868();
      }
      lVar45 = *(long *)(&DAT_fffffff00ad28268 + lVar45);
      iVar19 = *(int *)(lVar10 + 0x1c0) + -1;
      *(int *)(lVar10 + 0x1c0) = iVar19;
      if ((iVar19 == 0) && ((*(byte *)(*(long *)(lVar10 + 0x1b8) + 0x4c) >> 2 & 1) != 0)) {
        FUN_fffffff00a3976a4();
      }
      if (lVar45 == 0) {
        FUN_fffffff00a32d064(10);
      }
      puVar40 = local_88;
      if ((int)uVar23 != 0) goto LAB_fffffff00a2d22c4;
      puVar30 = *(undefined8 **)(local_b8 + 0x58);
      if (puVar30 == (undefined8 *)0x0) {
        puVar30 = (undefined8 *)0x0;
      }
      uVar28 = *(uint *)(param_8 + 0x14);
      *(uint *)(param_8 + 0x14) = uVar28 & 0xffffff9b;
      if (local_7c != 0) {
        uVar42 = local_94 | 2;
      }
      iVar19 = 2;
      if (local_7c == 0 && local_1d4 == 0) {
        iVar19 = local_1b8;
      }
      if (((uVar42 == 1) && ((local_94 & 5) == 4)) && (puVar30 != &DAT_fffffff00ad6cc50)) {
        if (param_9 == (undefined8 *)0x0) {
          *(undefined8 *)(lVar10 + 0x228) = 0;
          if ((uStack_134 & 0xc) == 8) {
            if (((byte)uStack_138 >> 2 & 1) == 0) {
              local_160 = CONCAT44(uStack_114,uStack_118);
            }
            else {
              local_130 = CONCAT44(uStack_fc,local_100) +
                          CONCAT44(local_130._4_4_,(undefined4)local_130);
              local_160 = local_160 + CONCAT44(uStack_fc,local_100);
            }
            local_148 = CONCAT44(uStack_f4,uStack_f8);
            local_150 = CONCAT44(uStack_104,uStack_108);
            uStack_158 = CONCAT44(uStack_10c,local_110);
            uStack_134 = uStack_134 & 0xfff3;
            local_100 = 0;
            uStack_fc = 0;
            uStack_f8 = 0;
            uStack_f4 = 0;
          }
          if ((uStack_138 >> 2 & 1) == 0) {
            FUN_fffffff00a34ab40(&local_160);
          }
          else if ((local_148 != 0) &&
                  (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                   ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
            FUN_fffffff00a346730();
          }
          local_150 = 0;
          local_148 = 0;
          local_130._4_4_ = 0;
          uStack_128 = 0;
          uStack_134 = 0;
          uStack_132 = 0;
          local_130._0_4_ = 0;
          uStack_11c = 0;
          uStack_118 = 0;
          uStack_124 = 0;
          local_120 = 0;
          uStack_10c = 0;
          uStack_108 = 0;
          uStack_114 = 0;
          local_110 = 0;
          uStack_fc = 0;
          uStack_f8 = 0;
          uStack_104 = 0;
          local_100 = 0;
          uStack_f4 = 0;
        }
        local_e8 = 0;
        uVar23 = 2;
        goto LAB_fffffff00a2d22c4;
      }
      if (bVar11) {
        if (((local_88 == (undefined4 *)0x0) || (local_88 != puVar47)) ||
           ((local_90 != local_1e8 || ((uVar28 >> 7 & 1) == 0)))) {
          if (param_9 == (undefined8 *)0x0) {
            *(undefined8 *)(lVar10 + 0x228) = 0;
            if ((uStack_134 & 0xc) == 8) {
              if (((byte)uStack_138 >> 2 & 1) == 0) {
                local_160 = CONCAT44(uStack_114,uStack_118);
              }
              else {
                local_130 = CONCAT44(uStack_fc,local_100) +
                            CONCAT44(local_130._4_4_,(undefined4)local_130);
                local_160 = local_160 + CONCAT44(uStack_fc,local_100);
              }
              local_148 = CONCAT44(uStack_f4,uStack_f8);
              local_150 = CONCAT44(uStack_104,uStack_108);
              uStack_158 = CONCAT44(uStack_10c,local_110);
              uStack_134 = uStack_134 & 0xfff3;
              local_100 = 0;
              uStack_fc = 0;
              uStack_f8 = 0;
              uStack_f4 = 0;
            }
            if ((uStack_138 >> 2 & 1) == 0) {
              FUN_fffffff00a34ab40(&local_160);
            }
            else if ((local_148 != 0) &&
                    (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                     ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
              FUN_fffffff00a346730();
            }
            local_150 = 0;
            local_148 = 0;
            local_130._4_4_ = 0;
            uStack_128 = 0;
            uStack_134 = 0;
            uStack_132 = 0;
            local_130._0_4_ = 0;
            uStack_11c = 0;
            uStack_118 = 0;
            uStack_124 = 0;
            local_120 = 0;
            uStack_10c = 0;
            uStack_108 = 0;
            uStack_114 = 0;
            local_110 = 0;
            uStack_fc = 0;
            uStack_f8 = 0;
            uStack_104 = 0;
            local_100 = 0;
            uStack_f4 = 0;
          }
          local_e8 = 0;
          FUN_fffffff00a303950(puVar47);
          puVar47 = (undefined4 *)0x0;
          bVar11 = false;
          DAT_fffffff00ad94ea0 = DAT_fffffff00ad94ea0 + 1;
          local_1e8 = 0xffffffffffffffff;
          local_1b8 = iVar19;
          goto LAB_fffffff00a2cf624;
        }
        DAT_fffffff00ad94e90 = DAT_fffffff00ad94e90 + 1;
      }
      else {
        local_1e8 = 0xffffffffffffffff;
      }
      if ((iVar19 == 2) || ((*(long *)(local_88 + 0x12) == 0 && (*(short *)(local_88 + 4) != 0)))) {
        FUN_fffffff00a3061bc(local_88);
        local_1b8 = 2;
      }
      else {
        FUN_fffffff00a306ebc(local_88);
        local_1b8 = 1;
      }
      uVar53 = (undefined4)((ulong)plVar31 >> 0x20);
      uVar46 = local_90 & 0x3fff;
      if ((((puVar40[0x1a] | 4) != 6) || (*(long *)(puVar40 + 0xe) == 0)) ||
         ((uVar42 >> 1 & 1) == 0)) {
        puVar38 = puVar40;
        if (((uint)puVar40[0x2a] >> 6 & 1) == 0) {
          uVar28 = (uint)puVar40[0x2a] >> 1;
          puVar37 = puVar30;
          if (param_5 != (undefined8 *)0x0) {
            puVar37 = param_5;
          }
          uVar20 = uVar42 & 2;
          uVar43 = local_90;
LAB_fffffff00a2cf928:
          do {
            uVar23 = uVar43 & 0xffffffffffffc000;
            puVar24 = (undefined8 *)FUN_fffffff00a32bd34(puVar40,uVar23);
            uVar53 = (undefined4)((ulong)plVar31 >> 0x20);
            puVar38 = puVar40;
            if (puVar24 != (undefined8 *)0x0) {
              if ((local_161 & 1) == 0) {
                bVar33 = 0;
              }
              else {
                uVar23 = FUN_fffffff00a2d34ec(puVar30,puVar24,uVar34,local_94,param_8,&local_161);
                puVar25 = local_88;
                bVar33 = local_161;
                if ((int)uVar23 != 0) {
                  FUN_fffffff00a22aeac(local_88 + 2);
                  if (puVar25 != puVar40) {
                    FUN_fffffff00a22aeac(puVar40 + 2);
                  }
                  if (param_9 == (undefined8 *)0x0) {
                    *(undefined8 *)(lVar10 + 0x228) = 0;
                    if ((uStack_134 & 0xc) == 8) {
                      if (((byte)uStack_138 >> 2 & 1) == 0) {
                        local_160 = CONCAT44(uStack_114,uStack_118);
                      }
                      else {
                        local_130 = CONCAT44(uStack_fc,local_100) +
                                    CONCAT44(local_130._4_4_,(undefined4)local_130);
                        local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                      }
                      local_148 = CONCAT44(uStack_f4,uStack_f8);
                      local_150 = CONCAT44(uStack_104,uStack_108);
                      uStack_158 = CONCAT44(uStack_10c,local_110);
                      uStack_134 = uStack_134 & 0xfff3;
                      local_100 = 0;
                      uStack_fc = 0;
                      uStack_f8 = 0;
                      uStack_f4 = 0;
                    }
                    if ((uStack_138 >> 2 & 1) == 0) {
                      FUN_fffffff00a34ab40(&local_160);
                    }
                    else if ((local_148 != 0) &&
                            (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                             ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                      FUN_fffffff00a346730();
                    }
                    local_150 = 0;
                    local_148 = 0;
                    local_130._4_4_ = 0;
                    uStack_128 = 0;
                    uStack_134 = 0;
                    uStack_132 = 0;
                    local_130._0_4_ = 0;
                    uStack_11c = 0;
                    uStack_118 = 0;
                    uStack_124 = 0;
                    local_120 = 0;
                    uStack_10c = 0;
                    uStack_108 = 0;
                    uStack_114 = 0;
                    local_110 = 0;
                    uStack_fc = 0;
                    uStack_f8 = 0;
                    uStack_104 = 0;
                    local_100 = 0;
                    uStack_f4 = 0;
                  }
                  local_e8 = 0;
                  goto LAB_fffffff00a2d22c4;
                }
              }
              puVar25 = local_88;
              if (((*(byte *)((long)puVar24 + 0x2c) >> 2 & 1) != 0) || ((bVar33 & 1) != 0)) {
                local_161 = 0;
                if (local_88 == puVar40) {
                  if ((local_1b8 != 1) || (iVar19 = FUN_fffffff00a229f28(local_88 + 2), iVar19 != 0)
                     ) {
                    local_1b8 = 2;
                    goto LAB_fffffff00a2cfabc;
                  }
LAB_fffffff00a2cfa78:
                  FUN_fffffff00a3061bc(puVar25);
                  goto LAB_fffffff00a2cfdd4;
                }
                if (local_1d8 == 1) {
                  iVar19 = FUN_fffffff00a229f28(puVar40 + 2);
                  if (iVar19 == 0) {
                    FUN_fffffff00a22aeac(local_88 + 2);
                    if (param_9 == (undefined8 *)0x0) {
                      *(undefined8 *)(lVar10 + 0x228) = 0;
                      if ((uStack_134 & 0xc) == 8) {
                        if (((byte)uStack_138 >> 2 & 1) == 0) {
                          local_160 = CONCAT44(uStack_114,uStack_118);
                        }
                        else {
                          local_130 = CONCAT44(uStack_fc,local_100) +
                                      CONCAT44(local_130._4_4_,(undefined4)local_130);
                          local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                        }
                        local_148 = CONCAT44(uStack_f4,uStack_f8);
                        local_150 = CONCAT44(uStack_104,uStack_108);
                        uStack_158 = CONCAT44(uStack_10c,local_110);
                        uStack_134 = uStack_134 & 0xfff3;
                        local_100 = 0;
                        uStack_fc = 0;
                        uStack_f8 = 0;
                        uStack_f4 = 0;
                      }
                      if ((uStack_138 >> 2 & 1) == 0) {
                        FUN_fffffff00a34ab40(&local_160);
                      }
                      else if ((local_148 != 0) &&
                              (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                               ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                        FUN_fffffff00a346730();
                      }
                    }
                    local_e8 = 0;
                    local_1d8 = 2;
                    goto LAB_fffffff00a2cf624;
                  }
                  local_1d8 = 2;
                }
                else {
                  local_1d8 = 2;
                }
LAB_fffffff00a2cfabc:
                if (((*(byte *)((long)puVar24 + 0x2a) & 0xf) == 7) &&
                   ((*(byte *)((long)puVar40 + 0x75) >> 4 & 1) != 0)) {
                  uVar23 = (ulong)*(uint *)(lVar10 + 0x4e8);
                  if (DAT_fffffff00ad6d188 != 0) {
                    FUN_fffffff00a2262d4(&DAT_fffffff00ad6d180,lVar10,0);
                    uVar23 = DAT_fffffff00ad6d188;
                  }
                  DAT_fffffff00ad6d188 = uVar23;
                  if ((*(byte *)((long)puVar24 + 0x2a) & 0xf) == 7) {
                    uVar22 = FUN_fffffff00a311408(puVar24);
                    if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar10 + 0x4e8)) {
                      DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
                    }
                    else {
                      uVar22 = FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar10);
                    }
                    FUN_fffffff00a30a920(uVar22,puVar24);
                    goto LAB_fffffff00a2cfb2c;
                  }
                  if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar10 + 0x4e8)) {
                    DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
                  }
                  else {
                    FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar10);
                  }
                }
                if (local_88 != puVar40) {
                  FUN_fffffff00a22aeac(local_88 + 2);
                }
                if (param_9 == (undefined8 *)0x0) {
                  *(undefined8 *)(lVar10 + 0x228) = 0;
                  if ((uStack_134 & 0xc) == 8) {
                    if (((byte)uStack_138 >> 2 & 1) == 0) {
                      local_160 = CONCAT44(uStack_114,uStack_118);
                    }
                    else {
                      local_130 = CONCAT44(uStack_fc,local_100) +
                                  CONCAT44(local_130._4_4_,(undefined4)local_130);
                      local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                    }
                    local_148 = CONCAT44(uStack_f4,uStack_f8);
                    local_150 = CONCAT44(uStack_104,uStack_108);
                    uStack_158 = CONCAT44(uStack_10c,local_110);
                    uStack_134 = uStack_134 & 0xfff3;
                    local_100 = 0;
                    uStack_fc = 0;
                    uStack_f8 = 0;
                    uStack_f4 = 0;
                  }
                  if ((uStack_138 >> 2 & 1) == 0) {
                    FUN_fffffff00a34ab40(&local_160);
                  }
                  else if ((local_148 != 0) &&
                          (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                           ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                    FUN_fffffff00a346730();
                  }
                  local_150 = 0;
                  local_148 = 0;
                  local_130._4_4_ = 0;
                  uStack_128 = 0;
                  uStack_134 = 0;
                  uStack_132 = 0;
                  local_130._0_4_ = 0;
                  uStack_11c = 0;
                  uStack_118 = 0;
                  uStack_124 = 0;
                  local_120 = 0;
                  uStack_10c = 0;
                  uStack_108 = 0;
                  uStack_114 = 0;
                  local_110 = 0;
                  uStack_fc = 0;
                  uStack_f8 = 0;
                  uStack_104 = 0;
                  local_100 = 0;
                  uStack_f4 = 0;
                  local_e8 = 0;
                }
                else {
                  local_e8 = 0;
                  if ((*(byte *)(param_9 + 5) >> 5 & 1) != 0) {
                    FUN_fffffff00a2d3670(param_9[2],&DAT_fffffff00ad18830,2,*param_9,param_9[1]);
                  }
                }
                iVar19 = FUN_fffffff00a305a48(puVar40,puVar24,*(undefined4 *)param_8,1);
                if ((iVar19 == 0) || (iVar19 == 3)) goto LAB_fffffff00a2cf624;
                if (lVar10 == 0) {
                  uVar22 = 0;
                }
                else {
                  uVar22 = *(undefined8 *)(lVar10 + 0x4e0);
                }
                FUN_fffffff00a6db8c0(uVar22,0x1000034,0);
                uVar23 = 0xe;
                goto LAB_fffffff00a2d22c4;
              }
LAB_fffffff00a2cfb2c:
              puVar25 = local_88;
              if ((*(byte *)((long)puVar24 + 0x2b) >> 1 & 1) != 0) {
                if (local_88 == puVar40) {
                  if ((local_1b8 == 1) && (iVar19 = FUN_fffffff00a229f28(local_88 + 2), iVar19 == 0)
                     ) goto LAB_fffffff00a2cfa78;
                  local_1b8 = 2;
                }
                else if (local_1d8 == 1) {
                  FUN_fffffff00a22aeac(local_88 + 2);
                  FUN_fffffff00a22aeac(puVar40 + 2);
                  if (param_9 == (undefined8 *)0x0) {
                    *(undefined8 *)(lVar10 + 0x228) = 0;
                    if ((uStack_134 & 0xc) == 8) {
                      if (((byte)uStack_138 >> 2 & 1) == 0) {
                        local_160 = CONCAT44(uStack_114,uStack_118);
                      }
                      else {
                        local_130 = CONCAT44(uStack_fc,local_100) +
                                    CONCAT44(local_130._4_4_,(undefined4)local_130);
                        local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                      }
                      local_148 = CONCAT44(uStack_f4,uStack_f8);
                      local_150 = CONCAT44(uStack_104,uStack_108);
                      uStack_158 = CONCAT44(uStack_10c,local_110);
                      uStack_134 = uStack_134 & 0xfff3;
                      local_100 = 0;
                      uStack_fc = 0;
                      uStack_f8 = 0;
                      uStack_f4 = 0;
                    }
joined_r0xfffffff00a2d212c:
                    if ((uStack_138 >> 2 & 1) == 0) {
                      FUN_fffffff00a34ab40(&local_160);
                    }
                    else if ((local_148 != 0) &&
                            (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                             ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                      FUN_fffffff00a346730();
                    }
                  }
LAB_fffffff00a2d2170:
                  local_e8 = 0;
                  local_1d8 = 2;
                  goto LAB_fffffff00a2cf624;
                }
                FUN_fffffff00a31b0d8(puVar24,0);
              }
              uVar23 = local_78[0];
              uVar53 = (undefined4)((ulong)plVar31 >> 0x20);
              if (((((puVar24 >= DAT_fffffff007bf0010 && DAT_fffffff007bf0008 > puVar24) ||
                    (*(int *)((long)puVar24 + 0x3c) != -2)) &&
                   ((*(byte *)((long)puVar24 + 0x2c) >> 3 & 1) == 0)) &&
                  (1 < (*(byte *)((long)puVar24 + 0x2c) & 3) - 1)) &&
                 ((*(char *)((long)puVar24 + 0x2a) < '\0' ||
                  ((puVar24 < DAT_fffffff007bf0010 || DAT_fffffff007bf0008 <= puVar24 &&
                   (0xfffffffd < *(uint *)((long)puVar24 + 0x3c))))))) {
                if ((((uint)puVar40[0x2a] >> 5 & 1) == 0) ||
                   (1 < (*(ushort *)((long)puVar40 + 0x76) & 3) - 1)) {
                  puVar39 = (undefined8 *)(local_78[0] + 0x58);
                  puVar36 = (undefined8 *)*puVar39;
                  if ((((puVar40[0x2a] & 1) == 0) ||
                      (puVar36 != (undefined8 *)0x0 && puVar36 == &DAT_fffffff00ad6cc50)) ||
                     ((0xef < *(byte *)((long)puVar24 + 0x2e) ||
                      ((((*(byte *)((long)puVar24 + 0x2e) ^ 0xff) & 0xf) == 0 &&
                       ((*(byte *)((long)puVar24 + 0x2d) >> 6 & 1) == 0)))))) {
                    if (param_7 == (int *)0x0) goto LAB_fffffff00a2cfd3c;
                    if (((byte)local_94 >> 1 & 1) == 0) goto LAB_fffffff00a2cfd3c;
                  }
LAB_fffffff00a2cfcf0:
                  puVar25 = local_88;
                  iVar19 = local_1b8;
                  if (local_88 == puVar40) {
                    local_1b8 = 2;
                    if (iVar19 == 1) {
                      iVar19 = FUN_fffffff00a229f28(local_88 + 2);
                      local_1b8 = 2;
                      if (iVar19 == 0) goto LAB_fffffff00a2cfdc8;
                    }
                  }
                  else if (local_1d8 == 1) {
                    FUN_fffffff00a22aeac(local_88 + 2);
                    FUN_fffffff00a22aeac(puVar40 + 2);
                    if (param_9 != (undefined8 *)0x0) goto LAB_fffffff00a2d2170;
                    *(undefined8 *)(lVar10 + 0x228) = 0;
                    if ((uStack_134 & 0xc) == 8) {
                      if (((byte)uStack_138 >> 2 & 1) == 0) {
                        local_160 = CONCAT44(uStack_114,uStack_118);
                      }
                      else {
                        local_130 = CONCAT44(uStack_fc,local_100) +
                                    CONCAT44(local_130._4_4_,(undefined4)local_130);
                        local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                      }
                      local_148 = CONCAT44(uStack_f4,uStack_f8);
                      local_150 = CONCAT44(uStack_104,uStack_108);
                      uStack_158 = CONCAT44(uStack_10c,local_110);
                      uStack_134 = uStack_134 & 0xfff3;
                      local_100 = 0;
                      uStack_fc = 0;
                      uStack_f8 = 0;
                      uStack_f4 = 0;
                    }
                    goto joined_r0xfffffff00a2d212c;
                  }
LAB_fffffff00a2cfd3c:
                  puVar25 = local_88;
                  uVar54 = (undefined4)((ulong)in_stack_fffffffffffffd30 >> 0x20);
                  iVar19 = local_1b8;
                  if ((local_88 == puVar40) && (*(long *)(local_88 + 0xe) == 0)) {
                    puVar35 = (undefined4 *)0x0;
                    puVar40 = local_88;
                    goto LAB_fffffff00a2d12cc;
                  }
                  if (local_1d4 == 0) {
                    if (((*(byte *)((long)param_8 + 0x29) & 1) == 0) &&
                       (iVar21 = FUN_fffffff00a2d3720(uVar23,puVar37,local_88,puVar40), iVar21 != 0)
                       ) {
                      DAT_fffffff00ad94e18 = DAT_fffffff00ad94e18 + 1;
                      lVar48 = FUN_fffffff00a29b24c();
                      lVar45 = *(long *)(lVar48 + 0x18);
                      if (*(long *)(lVar48 + 0x18) == 0) {
                        lVar45 = DAT_fffffff007c6b250;
                      }
                      iVar19 = FUN_fffffff00a6ec3c0(lVar45);
                      if (iVar19 == 0) {
                        puVar39 = (undefined8 *)*puVar39;
                        if (puVar39 == (undefined8 *)0x0) {
                          plVar31 = &DAT_fffffff00ad94e28;
                        }
                        else {
                          plVar31 = (long *)0xfffffff00ad94e20;
                          if (puVar39 != &DAT_fffffff00ad6cc50) {
                            plVar31 = &DAT_fffffff00ad94e28;
                          }
                        }
                        *plVar31 = *plVar31 + 1;
                      }
                      FUN_fffffff00a22aeac(puVar25 + 2);
                      FUN_fffffff00a22aeac(puVar40 + 2);
                      if (param_9 == (undefined8 *)0x0) {
                        *(undefined8 *)(lVar10 + 0x228) = 0;
                        if ((uStack_134 & 0xc) == 8) {
                          if (((byte)uStack_138 >> 2 & 1) == 0) {
                            local_160 = CONCAT44(uStack_114,uStack_118);
                          }
                          else {
                            local_130 = CONCAT44(uStack_fc,local_100) +
                                        CONCAT44(local_130._4_4_,(undefined4)local_130);
                            local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                          }
                          local_148 = CONCAT44(uStack_f4,uStack_f8);
                          local_150 = CONCAT44(uStack_104,uStack_108);
                          uStack_158 = CONCAT44(uStack_10c,local_110);
                          uStack_134 = uStack_134 & 0xfff3;
                          local_100 = 0;
                          uStack_fc = 0;
                          uStack_f8 = 0;
                          uStack_f4 = 0;
                        }
                        if ((uStack_138 >> 2 & 1) == 0) {
                          FUN_fffffff00a34ab40(&local_160);
                        }
                        else if ((local_148 != 0) &&
                                (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                                 ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                          FUN_fffffff00a346730();
                        }
                      }
                      local_1d4 = 1;
                      goto LAB_fffffff00a2d162c;
                    }
                    uVar54 = (undefined4)((ulong)in_stack_fffffffffffffd30 >> 0x20);
                    if (uVar20 == 0) {
                      if (puVar30 == (undefined8 *)0x0) {
                        bVar33 = 1;
                      }
                      else {
                        bVar33 = *(byte *)(puVar30[4] + 0x4c) ^ 1;
                      }
                      if ((((local_94 ^ 0xffffffff) & 7) == 0) && ((bVar33 & 1) != 0)) {
                        if (((byte)param_8[0x14] >> 3 & 1) == 0) goto LAB_fffffff00a2d2d90;
                      }
                      else {
                        local_94 = local_94 & 0xfffffffd;
                      }
                      puVar35 = puVar25;
                      iVar19 = local_1d8;
                      if (puVar25 == puVar40) {
                        puVar35 = (undefined4 *)0x0;
                        iVar19 = local_1b8;
                        puVar40 = local_88;
                      }
                      goto LAB_fffffff00a2d12cc;
                    }
                  }
                  uVar53 = (undefined4)((ulong)plVar31 >> 0x20);
                  if (puVar25 != puVar40) {
                    if (local_1d8 == 1) goto code_r0xfffffff00a2cfd9c;
                    goto LAB_fffffff00a2d0808;
                  }
                  break;
                }
                if (local_88 != puVar40) {
                  FUN_fffffff00a22aeac(local_88 + 2);
                }
                if (param_9 == (undefined8 *)0x0) {
                  *(undefined8 *)(lVar10 + 0x228) = 0;
                  if ((uStack_134 & 0xc) == 8) {
                    if (((byte)uStack_138 >> 2 & 1) == 0) {
                      local_160 = CONCAT44(uStack_114,uStack_118);
                    }
                    else {
                      local_130 = CONCAT44(uStack_fc,local_100) +
                                  CONCAT44(local_130._4_4_,(undefined4)local_130);
                      local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                    }
                    local_148 = CONCAT44(uStack_f4,uStack_f8);
                    local_150 = CONCAT44(uStack_104,uStack_108);
                    uStack_158 = CONCAT44(uStack_10c,local_110);
                    uStack_134 = uStack_134 & 0xfff3;
                    local_100 = 0;
                    uStack_fc = 0;
                    uStack_f8 = 0;
                    uStack_f4 = 0;
                  }
                  if ((uStack_138 >> 2 & 1) == 0) {
                    FUN_fffffff00a34ab40(&local_160);
                  }
                  else if ((local_148 != 0) &&
                          (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                           ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                    FUN_fffffff00a346730();
                  }
                  local_150 = 0;
                  local_148 = 0;
                  local_130._4_4_ = 0;
                  uStack_128 = 0;
                  uStack_134 = 0;
                  uStack_132 = 0;
                  local_130._0_4_ = 0;
                  uStack_11c = 0;
                  uStack_118 = 0;
                  uStack_124 = 0;
                  local_120 = 0;
                  uStack_10c = 0;
                  uStack_108 = 0;
                  uStack_114 = 0;
                  local_110 = 0;
                  uStack_fc = 0;
                  uStack_f8 = 0;
                  uStack_104 = 0;
                  local_100 = 0;
                  uStack_f4 = 0;
                }
                local_e8 = 0;
                FUN_fffffff00a22aeac(puVar40 + 2);
                if (lVar10 == 0) goto LAB_fffffff00a2d2790;
LAB_fffffff00a2d29f0:
                uVar22 = *(undefined8 *)(lVar10 + 0x4e0);
                goto LAB_fffffff00a2d29f4;
              }
              break;
            }
            uVar7 = puVar40[0x1d];
            if ((uVar7 >> 7 & 1) != 0) {
              if ((((uVar7 >> 0xc & 1) == 0) || ((uVar7 >> 0xf & 1) == 0)) ||
                 (*(long *)(puVar40 + 0x14) == 0)) break;
              iVar19 = FUN_fffffff00a2c5c14
                                 (*(long *)(puVar40 + 0x14),*(long *)(puVar40 + 0x18) + uVar43);
              puVar25 = local_88;
              uVar53 = (undefined4)((ulong)plVar31 >> 0x20);
              if (iVar19 != 3) {
                local_198 = local_198 & 0xffffffff00000000;
                if (((iVar19 == 1) && (local_78[0] != DAT_fffffff007c678d8)) &&
                   (local_b8 != DAT_fffffff007c678d8)) {
                  bVar15 = local_88 != puVar40;
                  bVar16 = uVar20 == 0;
                  if (bVar15 && bVar16) {
                    if ((local_1d8 == 1) &&
                       (iVar19 = FUN_fffffff00a229f28(puVar40 + 2), iVar19 == 0)) {
                      FUN_fffffff00a22aeac(local_88 + 2);
                      local_1d8 = 2;
joined_r0xfffffff00a2d1bfc:
                      if (param_9 == (undefined8 *)0x0) {
                        *(undefined8 *)(lVar10 + 0x228) = 0;
                        if ((uStack_134 & 0xc) == 8) {
                          if (((byte)uStack_138 >> 2 & 1) == 0) {
                            local_160 = CONCAT44(uStack_114,uStack_118);
                          }
                          else {
                            local_130 = CONCAT44(uStack_fc,local_100) +
                                        CONCAT44(local_130._4_4_,(undefined4)local_130);
                            local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                          }
                          local_148 = CONCAT44(uStack_f4,uStack_f8);
                          local_150 = CONCAT44(uStack_104,uStack_108);
                          uStack_158 = CONCAT44(uStack_10c,local_110);
                          uStack_134 = uStack_134 & 0xfff3;
                          local_100 = 0;
                          uStack_fc = 0;
                          uStack_f8 = 0;
                          uStack_f4 = 0;
                        }
                        if ((uStack_138 >> 2 & 1) == 0) {
                          FUN_fffffff00a34ab40(&local_160);
                        }
                        else if ((local_148 != 0) &&
                                (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                                 ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                          FUN_fffffff00a346730();
                        }
                      }
                      local_e8 = 0;
                      goto LAB_fffffff00a2cf624;
                    }
                    iVar19 = 1;
                    local_1d8 = 2;
                  }
                  else {
                    if (local_1b8 == 1) {
                      if (local_88 != puVar40) {
                        FUN_fffffff00a22aeac(local_88 + 2);
                        FUN_fffffff00a22aeac(puVar40 + 2);
                        local_1b8 = 2;
                        goto joined_r0xfffffff00a2d1bfc;
                      }
                      iVar19 = FUN_fffffff00a229f28(local_88 + 2);
                      uVar53 = (undefined4)((ulong)plVar31 >> 0x20);
                      if (iVar19 == 0) goto LAB_fffffff00a2cfa78;
                      iVar19 = 1;
                    }
                    else {
                      iVar19 = 1;
                      if (local_88 != puVar40) {
                        iVar19 = uVar20 + 1;
                      }
                    }
                    local_1b8 = 2;
                  }
                  puVar24 = (undefined8 *)FUN_fffffff00a32cd9c(uVar28 & 0x10000);
                  puVar25 = local_88;
                  if (puVar24 != (undefined8 *)0x0) {
                    local_210 = local_88;
                    bVar17 = local_88 != puVar40;
                    if ((puVar24 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar24)) {
                      iVar21 = *(int *)((long)puVar24 + 0x3c);
                    }
                    else {
                      iVar21 = DAT_fffffff007bf0000 +
                               (int)((ulong)((long)puVar24 - (long)DAT_fffffff007bf0010) >> 6);
                    }
                    iVar19 = FUN_fffffff00a2c58f4
                                       (*(undefined8 *)(puVar40 + 0x14),
                                        *(long *)(puVar40 + 0x18) + uVar23,iVar21,&local_198,iVar19,
                                        &local_dc);
                    uVar54 = (undefined4)((ulong)in_stack_fffffffffffffd30 >> 0x20);
                    lVar45 = *(long *)(puVar40 + 0x14);
                    if (((lVar45 != 0) && (local_dc != 0)) &&
                       (*(undefined **)(lVar45 + 8) == &DAT_fffffff007bca018)) {
                      if ((local_1b8 != 2 || bVar17) && (local_1d8 != 2 || !bVar17)) {
                        *(int *)(lVar45 + 0x34) = *(int *)(lVar45 + 0x34) + local_dc;
                      }
                      else {
                        *(int *)(lVar45 + 0x34) = *(int *)(lVar45 + 0x34) + local_dc;
                      }
                    }
                    if (iVar19 == 0) {
                      *(byte *)((long)puVar24 + 0x2d) = *(byte *)((long)puVar24 + 0x2d) | 1;
                      if ((((puVar25 == puVar40 || bVar15 && bVar16) &&
                           ((((puVar40[0x1d] ^ 0xffffffff) & 0x30000) != 0 ||
                            ((*(byte *)((long)puVar40 + 0xaa) & 0x38) != 0)))) &&
                          (*(long *)(puVar40 + 0x16) != 0)) && (local_dc != 0)) {
                        FUN_fffffff00a322eb0(puVar40,0xffffffff);
                      }
                      puVar38 = local_88;
                      if (bVar15 && bVar16) {
                        FUN_fffffff00a3297a4(puVar24,puVar40,uVar23,0,0,0);
                        puVar38 = puVar40;
                      }
                      else {
                        FUN_fffffff00a3297a4(puVar24,local_88,local_90 & 0xffffffffffffc000,0,0,0);
                      }
                      if ((*(char *)((long)puVar38 + 0xa6) != '\x02') &&
                         (*(char *)((long)puVar38 + 0xa6) != -0x80)) {
                        DataSynchronizationBarrier(3,3,0);
                      }
                      local_b0 = (uint)local_198;
                      plVar31 = (long *)(_DAT_fffffff00ad0e498 +
                                        (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
                      *plVar31 = *plVar31 + 1;
                      *(int *)(lVar10 + 0x560) = *(int *)(lVar10 + 0x560) + 1;
                      if (puVar40 == local_88) {
LAB_fffffff00a2d1bcc:
                        puVar35 = (undefined4 *)0x0;
                        iVar19 = local_1b8;
                        puVar40 = local_88;
                      }
                      else {
                        puVar35 = local_88;
                        iVar19 = local_1d8;
                        if (!bVar15 || !bVar16) {
                          FUN_fffffff00a22aeac(puVar40 + 2);
                          goto LAB_fffffff00a2d1bcc;
                        }
                      }
LAB_fffffff00a2d12cc:
                      local_88 = puVar40;
                      if ((bVar11) && ((local_94 >> 1 & 1) != 0)) {
                        if (puVar30 == (undefined8 *)0x0) {
                          bVar33 = 1;
                        }
                        else {
                          bVar33 = *(byte *)(puVar30[4] + 0x4c) ^ 1;
                        }
                        if ((((local_94 ^ 0xffffffff) & 7) == 0) && ((bVar33 & 1) != 0)) {
                          if (((byte)param_8[0x14] >> 3 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
                            FUN_fffffff00aa4d114
                                      ("%s: pmap %p vaddr 0x%llx prot 0x%x options 0x%x @%s:%d");
                          }
                        }
                        else {
                          local_94 = local_94 & 0xfffffffd;
                        }
                      }
                      if (((iVar6 == 1) && ((*(byte *)((long)puVar24 + 0x2b) >> 4 & 1) == 0)) &&
                         (_DAT_fffffff00ad188f0 != 0)) {
                        if (DAT_fffffff00ad6d188 == 0) {
                          bVar33 = *(byte *)((long)puVar24 + 0x2b);
                          DAT_fffffff00ad6d188 = (ulong)*(uint *)(lVar10 + 0x4e8);
                        }
                        else {
                          FUN_fffffff00a2262d4(&DAT_fffffff00ad6d180,lVar10,0);
                          bVar33 = *(byte *)((long)puVar24 + 0x2b);
                        }
                        if ((bVar33 >> 4 & 1) == 0) {
                          *(byte *)((long)puVar24 + 0x2b) = bVar33 | 0x10;
                          lVar45 = (ulong)DAT_fffffff00ad94cdc + 1;
                          DAT_fffffff00ad94cdc = (uint)lVar45;
                          if (lVar45 != lVar45 * 0x80000000 >> 0x1f) {
                    /* WARNING: Does not return */
                            pcVar14 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2d2e80);
                            (*pcVar14)();
                          }
                        }
                        if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar10 + 0x4e8)) {
                          DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
                        }
                        else {
                          FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar10);
                        }
                      }
                      uVar28 = local_94;
                      local_b9 = 0;
                      puVar37 = puVar30;
                      uVar23 = uVar34;
                      if (param_5 != (undefined8 *)0x0) {
                        puVar37 = param_5;
                        uVar23 = param_6;
                      }
                      pbVar52 = &local_b9;
                      uVar22 = CONCAT62((int6)((ulong)puVar50 >> 0x10),(short)param_4);
                      uVar53 = (undefined4)uVar22;
                      auVar49 = FUN_fffffff00a2d37f0
                                          (puVar24,puVar37,uVar23,lVar29,uVar46,local_94,param_3,
                                           local_7c,uVar22,param_8,pbVar52,&local_b0,
                                           in_stack_fffffffffffffd20,&local_161);
                      uVar23 = auVar49._0_8_;
                      uVar56 = (undefined4)((ulong)pbVar52 >> 0x20);
                      uVar55 = (undefined4)((ulong)in_stack_fffffffffffffd20 >> 0x20);
                      local_180 = *(undefined8 *)(puVar38 + 0x14);
                      lStack_178 = puVar24[4] + *(long *)(puVar38 + 0x18);
                      local_170 = 0;
                      if ((*(byte *)((long)param_8 + 0x29) >> 5 & 1) == 0) {
                        uVar20 = 1;
                      }
                      else {
                        uVar20 = FUN_fffffff00a3687b8(&local_180,auVar49._8_8_,puVar24);
                        uVar20 = uVar20 ^ 1;
                      }
                      uVar7 = 0xb;
                      if (!(bool)(bVar12 & local_b0 == 3)) {
                        uVar7 = local_b0;
                      }
                      in_stack_fffffffffffffd30 = CONCAT44(uVar54,uVar42);
                      in_stack_fffffffffffffd20 = (undefined8 *)CONCAT44(uVar55,local_27c);
                      uVar46 = CONCAT71((int7)(CONCAT44(auVar49._0_4_,uVar53) >> 8),
                                        local_b9 | local_161) & 0xffffffffffffff01;
                      FUN_fffffff00a2d39fc
                                (local_88,puVar38,puVar24,local_90,param_2,param_8,param_3,uVar7,
                                 uVar46,param_7,CONCAT44(uVar56,uVar28),puVar35,
                                 in_stack_fffffffffffffd20,uVar43,in_stack_fffffffffffffd30,
                                 &local_d8);
                      if ((uVar20 & 1) == 0) {
                        FUN_fffffff00a368874(&local_180);
                      }
                      if (param_9 == (undefined8 *)0x0) {
                        *(undefined8 *)(lVar10 + 0x228) = 0;
                        if ((uStack_134 & 0xc) == 8) {
                          if (((byte)uStack_138 >> 2 & 1) == 0) {
                            local_160 = CONCAT44(uStack_114,uStack_118);
                          }
                          else {
                            local_130 = CONCAT44(uStack_fc,local_100) +
                                        CONCAT44(local_130._4_4_,(undefined4)local_130);
                            local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                          }
                          local_148 = CONCAT44(uStack_f4,uStack_f8);
                          local_150 = CONCAT44(uStack_104,uStack_108);
                          uStack_158 = CONCAT44(uStack_10c,local_110);
                          uStack_134 = uStack_134 & 0xfff3;
                          local_100 = 0;
                          uStack_fc = 0;
                          uStack_f8 = 0;
                          uStack_f4 = 0;
                        }
                        if ((uStack_138 >> 2 & 1) == 0) {
                          FUN_fffffff00a34ab40(&local_160);
                        }
                        else if ((local_148 != 0) &&
                                (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                                 ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                          FUN_fffffff00a346730();
                        }
                        local_150 = 0;
                        local_148 = 0;
                        local_130._4_4_ = 0;
                        uStack_128 = 0;
                        uStack_134 = 0;
                        uStack_132 = 0;
                        local_130._0_4_ = 0;
                        uStack_11c = 0;
                        uStack_118 = 0;
                        uStack_124 = 0;
                        local_120 = 0;
                        uStack_10c = 0;
                        uStack_108 = 0;
                        uStack_114 = 0;
                        local_110 = 0;
                        uStack_fc = 0;
                        uStack_f8 = 0;
                        uStack_104 = 0;
                        local_100 = 0;
                        uStack_f4 = 0;
                      }
                      local_e8 = 0;
                      local_1b8 = iVar19;
                      if ((local_b9 & 1) == 0) {
                        if ((local_161 & 1) != 0) goto LAB_fffffff00a2cf624;
                        goto LAB_fffffff00a2d22c4;
                      }
                      FUN_fffffff00a37023c(puVar30,uVar34,0,0,0,0,0,2,uVar46 & 0xffffffffffffff00);
                      local_b9 = 0;
                      goto LAB_fffffff00a2cf624;
                    }
                    FUN_fffffff00a32ba64(puVar24,0);
                    if (iVar19 == 9) {
                      if (puVar25 != puVar40) {
                        FUN_fffffff00a22aeac(puVar40 + 2);
                        local_210 = local_88;
                      }
                      FUN_fffffff00a22aeac(local_210 + 2);
                      if (param_9 == (undefined8 *)0x0) {
                        *(undefined8 *)(lVar10 + 0x228) = 0;
                        if ((uStack_134 & 0xc) == 8) {
                          if (((byte)uStack_138 >> 2 & 1) == 0) {
                            local_160 = CONCAT44(uStack_114,uStack_118);
                          }
                          else {
                            local_130 = CONCAT44(uStack_fc,local_100) +
                                        CONCAT44(local_130._4_4_,(undefined4)local_130);
                            local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                          }
                          local_148 = CONCAT44(uStack_f4,uStack_f8);
                          local_150 = CONCAT44(uStack_104,uStack_108);
                          uStack_158 = CONCAT44(uStack_10c,local_110);
                          uStack_134 = uStack_134 & 0xfff3;
                          local_100 = 0;
                          uStack_fc = 0;
                          uStack_f8 = 0;
                          uStack_f4 = 0;
                        }
                        if ((uStack_138 >> 2 & 1) == 0) {
                          FUN_fffffff00a34ab40(&local_160);
                        }
                        else if ((local_148 != 0) &&
                                (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                                 ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                          FUN_fffffff00a346730();
                        }
                        local_150 = 0;
                        local_148 = 0;
                        local_130._4_4_ = 0;
                        uStack_128 = 0;
                        uStack_134 = 0;
                        uStack_132 = 0;
                        local_130._0_4_ = 0;
                        uStack_11c = 0;
                        uStack_118 = 0;
                        uStack_124 = 0;
                        local_120 = 0;
                        uStack_10c = 0;
                        uStack_108 = 0;
                        uStack_114 = 0;
                        local_110 = 0;
                        uStack_fc = 0;
                        uStack_f8 = 0;
                        uStack_104 = 0;
                        local_100 = 0;
                        uStack_f4 = 0;
                      }
                      local_e8 = 0;
                      uVar23 = 9;
                      goto LAB_fffffff00a2d22c4;
                    }
                  }
                }
                break;
              }
            }
            uVar53 = (undefined4)((ulong)plVar31 >> 0x20);
            puVar38 = *(undefined4 **)(puVar40 + 0x12);
            if (!(bool)(puVar38 != (undefined4 *)0x0 & (bVar11 ^ 1U))) {
              if (((((*(byte *)(puVar40 + 0x2a) >> 5 & 1) != 0) &&
                   ((uVar9 = *(ushort *)((long)puVar40 + 0x76) & 3, uVar9 == 1 || (uVar9 == 2)))) ||
                  (puVar40 == &DAT_fffffff00adbb400)) || (puVar40 == &DAT_fffffff00adbb300)) {
                if (local_88 != puVar40) {
                  FUN_fffffff00a22aeac(puVar40 + 2);
                }
                FUN_fffffff00a22aeac(local_88 + 2);
                if (param_9 == (undefined8 *)0x0) {
                  *(undefined8 *)(lVar10 + 0x228) = 0;
                  if ((uStack_134 & 0xc) == 8) {
                    if (((byte)uStack_138 >> 2 & 1) == 0) {
                      local_160 = CONCAT44(uStack_114,uStack_118);
                    }
                    else {
                      local_130 = CONCAT44(uStack_fc,local_100) +
                                  CONCAT44(local_130._4_4_,(undefined4)local_130);
                      local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                    }
                    local_148 = CONCAT44(uStack_f4,uStack_f8);
                    local_150 = CONCAT44(uStack_104,uStack_108);
                    uStack_158 = CONCAT44(uStack_10c,local_110);
                    uStack_134 = uStack_134 & 0xfff3;
                    local_100 = 0;
                    uStack_fc = 0;
                    uStack_f8 = 0;
                    uStack_f4 = 0;
                  }
                  if ((uStack_138 >> 2 & 1) == 0) {
                    FUN_fffffff00a34ab40(&local_160);
                  }
                  else if ((local_148 != 0) &&
                          (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                           ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                    FUN_fffffff00a346730();
                  }
                  local_150 = 0;
                  local_148 = 0;
                  local_130._4_4_ = 0;
                  uStack_128 = 0;
                  uStack_134 = 0;
                  uStack_132 = 0;
                  local_130._0_4_ = 0;
                  uStack_11c = 0;
                  uStack_118 = 0;
                  uStack_124 = 0;
                  local_120 = 0;
                  uStack_10c = 0;
                  uStack_108 = 0;
                  uStack_114 = 0;
                  local_110 = 0;
                  uStack_fc = 0;
                  uStack_f8 = 0;
                  uStack_104 = 0;
                  local_100 = 0;
                  uStack_f4 = 0;
                }
                local_e8 = 0;
                if (((*(byte *)(puVar40 + 0x2a) >> 5 & 1) == 0) ||
                   (1 < (*(ushort *)((long)puVar40 + 0x76) & 3) - 1)) {
                  uVar23 = 10;
                }
                else {
                  if (lVar10 != 0) goto LAB_fffffff00a2d29f0;
LAB_fffffff00a2d2790:
                  uVar22 = 0;
LAB_fffffff00a2d29f4:
                  FUN_fffffff00a6db8c0(uVar22,0x1000038,0);
                  uVar23 = 10;
                }
                goto LAB_fffffff00a2d22c4;
              }
              if (puVar40 != local_88) {
                FUN_fffffff00a22aeac(puVar40 + 2);
                puVar40 = local_88;
              }
              puVar38 = local_88;
              if (local_1b8 == 1) {
                iVar19 = FUN_fffffff00a229f28(local_88 + 2);
                if (iVar19 == 0) {
                  if (param_9 == (undefined8 *)0x0) {
                    *(undefined8 *)(lVar10 + 0x228) = 0;
                    if ((uStack_134 & 0xc) == 8) {
                      if (((byte)uStack_138 >> 2 & 1) == 0) {
                        local_160 = CONCAT44(uStack_114,uStack_118);
                      }
                      else {
                        local_130 = CONCAT44(uStack_fc,local_100) +
                                    CONCAT44(local_130._4_4_,(undefined4)local_130);
                        local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                      }
                      local_148 = CONCAT44(uStack_f4,uStack_f8);
                      local_150 = CONCAT44(uStack_104,uStack_108);
                      uStack_158 = CONCAT44(uStack_10c,local_110);
                      uStack_134 = uStack_134 & 0xfff3;
                      local_100 = 0;
                      uStack_fc = 0;
                      uStack_f8 = 0;
                      uStack_f4 = 0;
                    }
                    if ((uStack_138 >> 2 & 1) == 0) {
                      FUN_fffffff00a34ab40(&local_160);
                    }
                    else if ((local_148 != 0) &&
                            (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                             ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                      FUN_fffffff00a346730();
                    }
                  }
LAB_fffffff00a2d162c:
                  local_e8 = 0;
                  local_1b8 = 2;
                  goto LAB_fffffff00a2cf624;
                }
              }
              uVar23 = local_78[0];
              uVar54 = (undefined4)((ulong)in_stack_fffffffffffffd20 >> 0x20);
              if ((*(byte *)((long)puVar38 + 0x75) >> 4 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_fffffff00aa4d114
                          (
                          "%s:%d should not zero-fill page at offset 0x%llx in external object %p @%s:%d"
                          );
              }
              lVar45 = FUN_fffffff00a32cd9c
                                 (((*(uint *)(local_78[0] + 0xf8) & 2) << 3 | uVar28 & 0x10000) ^
                                  0x10);
              uVar13 = local_90;
              uVar56 = (undefined4)((ulong)in_stack_fffffffffffffd30 >> 0x20);
              if (lVar45 != 0) {
                FUN_fffffff00a3297a4(lVar45,puVar38,local_90 & 0xffffffffffffc000,0,8,0);
                if ((((local_94 >> 1 & 1) != 0) && (uVar20 == 0)) && (*(long *)(puVar38 + 0xe) != 0)
                   ) {
                  if (puVar30 == (undefined8 *)0x0) {
                    bVar33 = 1;
                  }
                  else {
                    bVar33 = *(byte *)(puVar30[4] + 0x4c) ^ 1;
                  }
                  if ((((local_94 ^ 0xffffffff) & 7) == 0) && ((bVar33 & 1) != 0)) {
                    if (((byte)param_8[0x14] >> 3 & 1) == 0) {
LAB_fffffff00a2d2d90:
                    /* WARNING: Subroutine does not return */
                      FUN_fffffff00aa4d114("%s: pmap %p vaddr 0x%llx prot 0x%x options 0x%x @%s:%d")
                      ;
                    }
                  }
                  else {
                    local_94 = local_94 & 0xfffffffd;
                  }
                }
                *(ushort *)(lVar45 + 0x2e) = *(ushort *)(lVar45 + 0x2e) & 0xf000;
                *(byte *)(lVar45 + 0x2d) = *(byte *)(lVar45 + 0x2d) | 0x10;
                local_b0 = 5;
                if ((*(uint *)(uVar23 + 0xf8) & 2) == 0) {
                  local_b0 = 1;
                }
                uVar28 = uVar41;
                if ((*(uint *)(param_8 + 0x14) & 0x800) != 0) {
                  uVar28 = 0;
                }
                puVar51 = &local_dd;
                puVar50 = param_8;
                uVar23 = FUN_fffffff00a2d3d88
                                   (lVar45,puVar37,uVar32,&local_94,param_3,lVar29,uVar46,uVar28,
                                    param_8,&local_b0,puVar51,&local_161);
                iVar19 = local_7c;
                uVar20 = (uint)puVar50;
                uVar53 = (undefined4)((ulong)puVar51 >> 0x20);
                if ((int)uVar23 == 0) {
                  if (((*(uint *)(param_8 + 0x14) >> 9 & 1) != 0) &&
                     ((*(byte *)(puVar38 + 0x2a) & 1) == 0)) {
                    *(uint *)(param_8 + 0x16) = *(uint *)(param_8 + 0x16) | 0x20000;
                  }
                  if ((*(uint *)(param_8 + 0x14) >> 10 & 1) == 0) {
                    uVar20 = *(uint *)(param_8 + 0x16);
                  }
                  else {
                    uVar20 = *(uint *)(param_8 + 0x16);
                    if (((byte)local_94 >> 1 & 1) != 0) {
                      uVar20 = uVar20 | 0x400000;
                      *(uint *)(param_8 + 0x16) = uVar20;
                    }
                  }
                  uVar23 = FUN_fffffff00a2d4cc0
                                     (puVar37,uVar32,uVar46,lVar45,&local_94,param_3,uVar28,
                                      local_7c != 0,uVar20,&local_b9);
                }
                FUN_fffffff00a2d4db0(puVar38,lVar45);
                FUN_fffffff00a2d4f10
                          (puVar38,lVar45,iVar19 != 0,*(uint *)(param_8 + 0x14) >> 0xb & 1,param_4,
                           *(uint *)(param_8 + 0x14) & 1,&local_b0,uVar23);
                if (((iVar6 == 1) && ((*(byte *)(lVar45 + 0x2b) >> 4 & 1) == 0)) &&
                   (_DAT_fffffff00ad188f0 != 0)) {
                  if (DAT_fffffff00ad6d188 == 0) {
                    bVar33 = *(byte *)(lVar45 + 0x2b);
                    DAT_fffffff00ad6d188 = (ulong)*(uint *)(lVar10 + 0x4e8);
                  }
                  else {
                    FUN_fffffff00a2262d4(&DAT_fffffff00ad6d180,lVar10,0);
                    bVar33 = *(byte *)(lVar45 + 0x2b);
                  }
                  if ((bVar33 >> 4 & 1) == 0) {
                    *(byte *)(lVar45 + 0x2b) = bVar33 | 0x10;
                    lVar48 = (ulong)DAT_fffffff00ad94cdc + 1;
                    DAT_fffffff00ad94cdc = (uint)lVar48;
                    if (lVar48 != lVar48 * 0x80000000 >> 0x1f) {
                    /* WARNING: Does not return */
                      pcVar14 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2d2e74);
                      (*pcVar14)();
                    }
                  }
                  if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar10 + 0x4e8)) {
                    DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
                  }
                  else {
                    FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar10);
                  }
                }
                bVar33 = local_b9;
                in_stack_fffffffffffffd30 = CONCAT44(uVar56,uVar42);
                in_stack_fffffffffffffd20 = (undefined8 *)CONCAT44(uVar54,local_27c);
                uVar46 = CONCAT71((int7)(CONCAT44((int)uVar23,uVar20) >> 8),local_b9) &
                         0xffffffffffffff01;
                FUN_fffffff00a2d39fc
                          (puVar38,puVar38,lVar45,uVar13,param_2,param_8,param_3,local_b0,uVar46,
                           param_7,CONCAT44(uVar53,local_94),0,in_stack_fffffffffffffd20,uVar43,
                           in_stack_fffffffffffffd30,&local_d8);
                if (param_9 == (undefined8 *)0x0) {
                  *(undefined8 *)(lVar10 + 0x228) = 0;
                  if ((uStack_134 & 0xc) == 8) {
                    if (((byte)uStack_138 >> 2 & 1) == 0) {
                      local_160 = CONCAT44(uStack_114,uStack_118);
                    }
                    else {
                      local_130 = CONCAT44(uStack_fc,local_100) +
                                  CONCAT44(local_130._4_4_,(undefined4)local_130);
                      local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                    }
                    local_148 = CONCAT44(uStack_f4,uStack_f8);
                    local_150 = CONCAT44(uStack_104,uStack_108);
                    uStack_158 = CONCAT44(uStack_10c,local_110);
                    uStack_134 = uStack_134 & 0xfff3;
                    local_100 = 0;
                    uStack_fc = 0;
                    uStack_f8 = 0;
                    uStack_f4 = 0;
                  }
                  if ((uStack_138 >> 2 & 1) == 0) {
                    FUN_fffffff00a34ab40(&local_160);
                  }
                  else if ((local_148 != 0) &&
                          (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                           ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                    FUN_fffffff00a346730(puVar30);
                  }
                  local_150 = 0;
                  local_148 = 0;
                  local_130._4_4_ = 0;
                  uStack_128 = 0;
                  uStack_134 = 0;
                  uStack_132 = 0;
                  local_130._0_4_ = 0;
                  uStack_11c = 0;
                  uStack_118 = 0;
                  uStack_124 = 0;
                  local_120 = 0;
                  uStack_10c = 0;
                  uStack_108 = 0;
                  uStack_114 = 0;
                  local_110 = 0;
                  uStack_fc = 0;
                  uStack_f8 = 0;
                  uStack_104 = 0;
                  local_100 = 0;
                  uStack_f4 = 0;
                }
                local_e8 = 0;
                if ((bVar33 & 1) == 0) goto LAB_fffffff00a2d22c4;
                local_1b8 = 2;
                FUN_fffffff00a37023c(puVar30,uVar34,0,0,0,0,0,2,uVar46 & 0xffffffffffffff00);
                local_b9 = 0;
                goto LAB_fffffff00a2cf624;
              }
              local_1b8 = 2;
              puVar38 = puVar40;
              break;
            }
            lVar45 = *(long *)(puVar40 + 0x16);
            if (local_1d8 == 1) {
              FUN_fffffff00a306ebc();
            }
            else {
              FUN_fffffff00a3061bc(puVar38);
            }
            if (puVar40 != local_88) {
              FUN_fffffff00a22aeac(puVar40 + 2);
            }
            uVar53 = (undefined4)((ulong)plVar31 >> 0x20);
            uVar46 = lVar45 + uVar43 & 0x3fff;
            uVar43 = lVar45 + uVar43;
            puVar40 = puVar38;
          } while ((*(byte *)(puVar38 + 0x2a) >> 6 & 1) == 0);
        }
LAB_fffffff00a2cfe40:
        if (local_88 != puVar38) {
          FUN_fffffff00a22aeac(puVar38 + 2);
        }
        puVar40 = local_88;
        if (local_1b8 == 1) {
          iVar19 = FUN_fffffff00a229f28(local_88 + 2);
          if (iVar19 == 0) {
            FUN_fffffff00a3061bc(puVar40);
          }
          local_1b8 = 2;
        }
        else {
          local_1b8 = 2;
        }
      }
      if (param_9 == (undefined8 *)0x0) {
        *(undefined8 *)(lVar10 + 0x228) = 0;
        if ((uStack_134 & 0xc) == 8) {
          if (((byte)uStack_138 >> 2 & 1) == 0) {
            local_160 = CONCAT44(uStack_114,uStack_118);
          }
          else {
            local_130 = CONCAT44(uStack_fc,local_100) +
                        CONCAT44(local_130._4_4_,(undefined4)local_130);
            local_160 = local_160 + CONCAT44(uStack_fc,local_100);
          }
          local_148 = CONCAT44(uStack_f4,uStack_f8);
          local_150 = CONCAT44(uStack_104,uStack_108);
          uStack_158 = CONCAT44(uStack_10c,local_110);
          uStack_134 = uStack_134 & 0xfff3;
          local_100 = 0;
          uStack_fc = 0;
          uStack_f8 = 0;
          uStack_f4 = 0;
        }
        if ((uStack_138 >> 2 & 1) == 0) {
          FUN_fffffff00a34ab40(&local_160);
        }
        else if ((local_148 != 0) &&
                (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                 ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
          FUN_fffffff00a346730();
        }
        local_150 = 0;
        local_148 = 0;
        local_130._4_4_ = 0;
        uStack_128 = 0;
        uStack_134 = 0;
        uStack_132 = 0;
        local_130._0_4_ = 0;
        uStack_11c = 0;
        uStack_118 = 0;
        uStack_124 = 0;
        local_120 = 0;
        uStack_10c = 0;
        uStack_108 = 0;
        uStack_114 = 0;
        local_110 = 0;
        uStack_fc = 0;
        uStack_f8 = 0;
        uStack_104 = 0;
        local_100 = 0;
        uStack_f4 = 0;
      }
      local_e8 = 0;
      if ((local_88 == &DAT_fffffff00adbb400) || (local_88 == &DAT_fffffff00adbb300)) {
        FUN_fffffff00a22aeac(local_88 + 2);
        uVar23 = 10;
        goto LAB_fffffff00a2d22c4;
      }
      if (bVar11) {
        if (local_88 != puVar47) {
          FUN_fffffff00a303950(puVar47);
          puVar47 = (undefined4 *)0x0;
          DAT_fffffff00ad94ea8 = DAT_fffffff00ad94ea8 + 1;
          local_1e8 = 0xffffffffffffffff;
          goto LAB_fffffff00a2cffb0;
        }
        puVar47 = (undefined4 *)0x0;
        DAT_fffffff00ad94ea8 = DAT_fffffff00ad94ea8 + 1;
        local_1e8 = 0xffffffffffffffff;
      }
      else {
LAB_fffffff00a2cffb0:
        if (local_88[10] + 0xf0000001 < 0xf0000002) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa61ed0(local_88 + 10);
        }
        local_88[10] = local_88[10] + 1;
      }
      puVar40 = local_88;
      uVar43 = local_90;
      uVar9 = *(ushort *)(local_88 + 0x1b);
      *(short *)(local_88 + 0x1b) = (short)(uVar9 + 1);
      if (uVar9 + 1 >> 0x10 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114("vm_object_paging_begin(%p): overflow\n @%s:%d");
      }
      *(undefined4 *)(lVar10 + 0x478) = 0;
      local_ac = 0;
      local_a0 = (undefined8 *)0x0;
      uVar23 = local_90;
      in_stack_fffffffffffffd20 = param_9;
      iVar19 = FUN_fffffff00a2d5330
                         (local_88,local_90,uVar42,
                          (uint)(local_7c == 0) & *(uint *)(param_8 + 0x14) >> 0xb,0,&local_94,
                          &local_a0,&local_a8,&local_b0,&local_ac,
                          CONCAT44(uVar53,*(uint *)(local_78[0] + 0xf8) >> 1) & 0xffffffff00000001,
                          param_8,param_9);
      if ((iVar19 == 0) || (iVar19 == 6)) goto LAB_fffffff00a2d01fc;
      if (iVar19 != 5) {
        FUN_fffffff00a303950(puVar40);
        puVar40 = (undefined4 *)0x0;
        local_88 = (undefined4 *)0x0;
        if (iVar19 < 3) {
          bVar11 = false;
          if (iVar19 == 1) goto LAB_fffffff00a2cf624;
          if (iVar19 == 2) {
            if (lVar10 == 0) {
              uVar22 = 0;
            }
            else {
              uVar22 = *(undefined8 *)(lVar10 + 0x4e0);
            }
LAB_fffffff00a2d262c:
            FUN_fffffff00a6db8c0(uVar22,0x1000024,0);
            uVar23 = 0xe;
            goto LAB_fffffff00a2d22c4;
          }
        }
        else {
          if (iVar19 == 3) {
            iVar19 = FUN_fffffff00a32d760((*(uint *)(param_8 + 0x14) >> 10 ^ 0xffffffff) & 2);
            bVar11 = false;
            if (iVar19 == 0) {
              if (lVar10 == 0) {
                uVar22 = 0;
              }
              else {
                uVar22 = *(undefined8 *)(lVar10 + 0x4e0);
              }
              FUN_fffffff00a6db8c0(uVar22,0x1000014,0);
              goto LAB_fffffff00a2d262c;
            }
            goto LAB_fffffff00a2cf624;
          }
          if (iVar19 == 7) {
            uVar23 = 0x1e;
            goto LAB_fffffff00a2d22c4;
          }
        }
LAB_fffffff00a2d01fc:
        puVar30 = local_a0;
        if (local_a0 == (undefined8 *)0x0) {
          FUN_fffffff00a22aeac(puVar40 + 2);
          lVar45 = 0;
          lVar48 = 0;
          local_210 = (undefined4 *)0x0;
        }
        else {
          lVar1 = (ulong)*(uint *)((long)local_a0 + 0x1c) * 0x40;
          local_210 = (undefined4 *)0x0;
          if (*(uint *)((long)local_a0 + 0x1c) != 0) {
            local_210 = (undefined4 *)(lVar1 + -0x2400000000);
          }
          lVar45 = *(long *)(lVar1 + -0x23ffffffc8);
          lVar48 = *(long *)(lVar1 + -0x23ffffffc0);
          local_198 = *(ulong *)(lVar1 + -0x23ffffffb0);
          lStack_190 = local_a0[4] + *(long *)(lVar1 + -0x23ffffffa0);
          local_188 = 0;
          if ((*(byte *)((long)param_8 + 0x29) >> 5 & 1) == 0) {
            *(short *)(lVar10 + 0x20e) = *(short *)(lVar10 + 0x20e) + 1;
            local_f0 = lVar10;
            FUN_fffffff00a22aeac(lVar1 + -0x23fffffff8);
          }
          else {
            iVar19 = FUN_fffffff00a3687b8(&local_198);
            *(short *)(lVar10 + 0x20e) = *(short *)(lVar10 + 0x20e) + 1;
            local_f0 = lVar10;
            FUN_fffffff00a22aeac(lVar1 + -0x23fffffff8);
            if (iVar19 != 0) {
              FUN_fffffff00a368874(&local_198);
            }
          }
        }
        local_1a8 = 0;
        local_1a0 = (undefined4 *)0x0;
        local_1ac = 0;
        uStack_158 = 0;
        local_160 = 0;
        local_148 = 0;
        local_150 = 0;
        uStack_138 = 0;
        uStack_134 = 0;
        uStack_132 = 0;
        local_140 = 0;
        uStack_128 = 0;
        uStack_124 = 0;
        local_130._0_4_ = 0;
        local_130._4_4_ = 0;
        uStack_118 = 0;
        uStack_114 = 0;
        local_120 = 0;
        uStack_11c = 0;
        uStack_108 = 0;
        uStack_104 = 0;
        local_110 = 0;
        uStack_10c = 0;
        uStack_f8 = 0;
        uStack_f4 = 0;
        local_100 = 0;
        uStack_fc = 0;
        in_stack_fffffffffffffd20 =
             (undefined8 *)CONCAT71((int7)((ulong)in_stack_fffffffffffffd20 >> 8),1);
        puVar50 = param_8;
        local_78[0] = param_1;
        uVar23 = FUN_fffffff00a2d2eac
                           (local_78,uVar34,uVar42,&local_1a0,&local_e8,&local_1a8,&local_1ac,
                            &local_7c,param_8,&local_b8,&local_160,param_9,in_stack_fffffffffffffd20
                           );
        puVar40 = local_88;
        puVar24 = (undefined8 *)(local_b8 + 0x58);
        puVar37 = (undefined8 *)*puVar24;
        iVar19 = (int)uVar23;
        if (puVar37 == (undefined8 *)0x0) {
          puVar37 = (undefined8 *)0x0;
        }
        if (iVar19 != 0) {
          if (puVar30 == (undefined8 *)0x0) {
            FUN_fffffff00a3061bc(local_88);
            FUN_fffffff00a2d759c(puVar40,local_a8);
          }
          else {
            FUN_fffffff00a3061bc(local_210);
            uVar22 = FUN_fffffff00a274564(&local_f0);
            FUN_fffffff00a30a920(uVar22,puVar30);
            if ((1L << (*(byte *)((long)puVar30 + 0x2a) & 0xf) & 0x3d60U) == 0) {
              *(int *)(lVar10 + 0x1c0) = *(int *)(lVar10 + 0x1c0) + 1;
              uVar46 = (ulong)*(uint *)(lVar10 + 0x4e8) | 0x30000000;
              if (DAT_fffffff00ad6d188 != 0) {
                FUN_fffffff00a2262d4(&DAT_fffffff00ad6d180,lVar10,1);
                uVar46 = DAT_fffffff00ad6d188;
              }
              DAT_fffffff00ad6d188 = uVar46;
              if ((1L << (*(byte *)((long)puVar30 + 0x2a) & 0xf) & 0x3d60U) == 0) {
                FUN_fffffff00a32c144(puVar30);
              }
              if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar10 + 0x4e8)) {
                DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
              }
              else {
                FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar10);
              }
            }
            FUN_fffffff00a2d759c(local_210,local_a8);
            puVar40 = local_88;
          }
          FUN_fffffff00a303950(puVar40);
          uVar46 = local_78[0];
          if (iVar19 != 0x20008006) {
            if (iVar19 == 1) {
              if (lVar10 == 0) {
                uVar22 = 0;
              }
              else {
                uVar22 = *(undefined8 *)(lVar10 + 0x4e0);
              }
              FUN_fffffff00a6db8c0(uVar22,0x100000c,0);
              uVar23 = 1;
            }
            goto LAB_fffffff00a2d22c4;
          }
          bVar11 = false;
          if ((*(byte *)(local_78[0] + 0xfb) & 1) != 0) {
            bVar11 = false;
            plVar31 = (long *)(_DAT_fffffff00ad18828 + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
            *plVar31 = *plVar31 + 1;
            if ((DAT_fffffff00ad98b00 & 0xfffffff7) != 0) {
              iVar19 = FUN_fffffff00a2d7940(local_78[0]);
              if (iVar19 == 0) {
                uVar22 = 0;
              }
              else {
                uVar23 = uVar46 & 0x7ffffffffff;
                if ((uVar46 & 0x80000000000000) != 0) {
                  uVar23 = uVar46 | 0xffffff8000000000;
                }
                uVar22 = FUN_fffffff00a396010(uVar23);
              }
              FUN_fffffff00a6de494(0x1b12004,uVar22,uVar34,uVar34,0);
              bVar11 = false;
            }
          }
          goto LAB_fffffff00a2cf624;
        }
        if ((local_1a0 == local_88) && (local_1a8 == uVar43)) {
          if (puVar37 == (undefined8 *)0x0) {
            bVar33 = 1;
          }
          else {
            bVar33 = *(byte *)(puVar37[4] + 0x4c) ^ 1;
          }
          if ((((local_1ac ^ 0xffffffff) & 7) == 0 & bVar33) != 0) {
            local_94 = 0xffffffff;
          }
          uVar28 = local_94 & local_1ac;
          local_94 = uVar28;
          if (puVar30 == (undefined8 *)0x0) {
            uVar22 = FUN_fffffff00a3061bc();
LAB_fffffff00a2d0654:
            if (local_1d4 == 0) goto LAB_fffffff00a2d0a54;
LAB_fffffff00a2d065c:
            bVar12 = false;
            local_1d4 = 1;
          }
          else {
            FUN_fffffff00a3061bc(local_210);
            uVar22 = FUN_fffffff00a274564(&local_f0);
            if (((uVar28 >> 1 & 1) == 0) ||
               ((*(long *)(local_210 + 0xe) == lVar45 && (*(long *)(local_210 + 0x10) == lVar48))))
            goto LAB_fffffff00a2d0654;
            if (puVar37 == (undefined8 *)0x0) {
              bVar33 = 1;
            }
            else {
              bVar33 = *(byte *)(puVar37[4] + 0x4c) ^ 1;
            }
            if ((((uVar28 ^ 0xffffffff) & 7) == 0) && ((bVar33 & 1) != 0)) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff00aa4d114
                        (
                        "%s: pmap %p vaddr 0x%llx prot 0x%x options 0x%x m%p obj %p copyobj %p @%s:%d"
                        );
            }
            local_94 = uVar28 & 0xfffffffd;
            uVar28 = local_94;
            if (local_1d4 != 0) goto LAB_fffffff00a2d065c;
LAB_fffffff00a2d0a54:
            uVar23 = local_78[0];
            bVar12 = false;
            if (puVar30 == (undefined8 *)0x0) {
              local_1d4 = 0;
            }
            else {
              local_1d4 = 0;
              if ((*(uint *)(param_8 + 0x14) >> 8 & 1) == 0) {
                puVar36 = puVar37;
                if (param_5 != (undefined8 *)0x0) {
                  puVar36 = param_5;
                }
                lVar45 = 0;
                if (*(uint *)((long)puVar30 + 0x1c) != 0) {
                  lVar45 = (ulong)*(uint *)((long)puVar30 + 0x1c) * 0x40 + -0x2400000000;
                }
                uVar22 = FUN_fffffff00a2d3720(local_78[0],puVar36,puVar40,lVar45);
                if ((int)uVar22 == 0) {
                  bVar12 = false;
                  local_1d4 = 0;
                }
                else {
                  DAT_fffffff00ad94e18 = DAT_fffffff00ad94e18 + 1;
                  lVar45 = FUN_fffffff00a29b24c();
                  if (*(long *)(lVar45 + 0x18) == 0) {
                    uVar22 = FUN_fffffff00a6ec3c0(DAT_fffffff007c6b250);
                    iVar19 = (int)uVar22;
                  }
                  else {
                    uVar22 = FUN_fffffff00a6ec3c0();
                    iVar19 = (int)uVar22;
                  }
                  if (iVar19 == 0) {
                    if (*(undefined8 **)(uVar23 + 0x58) == (undefined8 *)0x0) {
                      plVar31 = &DAT_fffffff00ad94e28;
                    }
                    else {
                      plVar31 = (long *)0xfffffff00ad94e20;
                      if (*(undefined8 **)(uVar23 + 0x58) != &DAT_fffffff00ad6cc50) {
                        plVar31 = &DAT_fffffff00ad94e28;
                      }
                    }
                    *plVar31 = *plVar31 + 1;
                    bVar12 = true;
                    local_1d4 = 1;
                  }
                  else {
                    bVar12 = true;
                    local_1d4 = 1;
                  }
                }
              }
            }
          }
          if (local_7c == 0) {
            if (bVar12) goto LAB_fffffff00a2d068c;
          }
          else {
            bVar11 = bVar12;
            if (uVar42 != (uVar28 | 2)) {
              bVar11 = true;
            }
            if (bVar11) {
LAB_fffffff00a2d068c:
              if (puVar30 == (undefined8 *)0x0) {
                FUN_fffffff00a2d759c(puVar40,local_a8);
              }
              else {
                FUN_fffffff00a30a920(uVar22,puVar30);
                if ((1L << (*(byte *)((long)puVar30 + 0x2a) & 0xf) & 0x3d60U) == 0) {
                  FUN_fffffff00a226c24(&DAT_fffffff00ad6d180);
                  if ((1L << (*(byte *)((long)puVar30 + 0x2a) & 0xf) & 0x3d60U) == 0) {
                    FUN_fffffff00a32c144(puVar30);
                  }
                  if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar10 + 0x4e8)) {
                    DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
                  }
                  else {
                    FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar10);
                  }
                }
                FUN_fffffff00a2d759c(local_210,local_a8);
                puVar40 = local_88;
              }
              FUN_fffffff00a303950(puVar40);
              if (param_9 == (undefined8 *)0x0) {
                *(undefined8 *)(lVar10 + 0x228) = 0;
                if ((uStack_134 & 0xc) == 8) {
                  if (((byte)uStack_138 >> 2 & 1) == 0) {
                    local_160 = CONCAT44(uStack_114,uStack_118);
                  }
                  else {
                    local_130 = CONCAT44(uStack_fc,local_100) +
                                CONCAT44(local_130._4_4_,(undefined4)local_130);
                    local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                  }
                  local_148 = CONCAT44(uStack_f4,uStack_f8);
                  local_150 = CONCAT44(uStack_104,uStack_108);
                  uStack_158 = CONCAT44(uStack_10c,local_110);
                  uStack_134 = uStack_134 & 0xfff3;
                  local_100 = 0;
                  uStack_fc = 0;
                  uStack_f8 = 0;
                  uStack_f4 = 0;
                }
                if ((uStack_138 >> 2 & 1) == 0) {
                  FUN_fffffff00a34ab40(&local_160);
                }
                else if ((local_148 != 0) &&
                        (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                         ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                  FUN_fffffff00a346730();
                }
              }
              bVar11 = false;
              local_e8 = 0;
              goto LAB_fffffff00a2cf624;
            }
          }
          if (puVar30 == (undefined8 *)0x0) {
            lVar29 = uVar34 - CONCAT44(uStack_fc,local_100);
            uVar32 = lVar29 - *(long *)(local_e8 + 0x10);
            if (0xffffffffffffefff < uVar32) {
              uVar32 = 0xfffffffffffff000;
            }
            uVar23 = *(long *)(local_e8 + 0x18) - lVar29;
            if (0xffffffffffffefff < uVar23) {
              uVar23 = 0xfffffffffffff000;
            }
            local_220 = param_6;
            if ((param_5 == (undefined8 *)0x0) &&
               (param_5 = (undefined8 *)*puVar24, local_220 = uVar34, param_5 == (undefined8 *)0x0))
            {
              param_5 = (undefined8 *)0x0;
            }
            uVar23 = FUN_fffffff00a378b34
                               (param_5,local_220 - uVar32,
                                ((lVar29 - *(long *)(local_e8 + 0x10)) - uVar32) +
                                *(long *)(puVar40 + 0x16) +
                                (*(ulong *)(local_e8 + 0x30) & 0xfffffffffffff000),
                                uVar23 + uVar32 >> (uVar44 & 0x3f),uVar28,
                                *(undefined1 *)((long)puVar40 + 0xa6));
          }
          else {
            local_b9 = 0;
            puVar24 = puVar37;
            uVar23 = uVar34;
            if (param_5 != (undefined8 *)0x0) {
              puVar24 = param_5;
              uVar23 = param_6;
            }
            uVar43 = CONCAT62((int6)((ulong)puVar50 >> 0x10),(short)param_4);
            uVar23 = FUN_fffffff00a2d37f0
                               (puVar30,puVar24,uVar23,lVar29,uVar46,uVar28,param_3,local_7c,uVar43,
                                param_8,&local_b9,&local_b0,in_stack_fffffffffffffd20,&local_161);
            uVar20 = 0xb;
            if (!(bool)(bVar12 & local_b0 == 3)) {
              uVar20 = local_b0;
            }
            uVar53 = 0x1320008;
            if ((*(byte *)((long)local_210 + 0x75) >> 4 & 1) == 0) {
              uVar53 = 0x1320010;
              if ((*(byte *)((long)local_210 + 0xa9) & 1) != 0) {
                uVar53 = 0x1320014;
              }
            }
            uVar46 = uVar23;
            bVar33 = local_b9;
            if ((DAT_fffffff00ad98b00 & 0xfffffff7) != 0) {
              iVar19 = *(int *)(param_8 + 2);
              uVar26 = puVar30[4];
              uVar22 = FUN_fffffff00a723ce4();
              uVar46 = FUN_fffffff00a6de494
                                 (uVar53,param_2,uVar20 | uVar41 << 8 | iVar19 << 0x10,uVar26,uVar22
                                 );
              bVar33 = local_b9;
            }
            local_b9 = bVar33;
            if ((((int)uVar23 != 0) || ((local_161 & 1) != 0)) || ((bVar33 & 1) != 0)) {
              FUN_fffffff00a30a920(uVar46,puVar30);
              FUN_fffffff00a2d759c(local_210,local_a8);
              FUN_fffffff00a303950(puVar40);
              if ((bVar33 & 1) != 0) {
                uVar23 = uVar34;
                if (param_5 != (undefined8 *)0x0) {
                  puVar37 = param_5;
                  uVar23 = param_6;
                }
                FUN_fffffff00a37023c(puVar37,uVar23,0,0,0,0,0,2,uVar43 & 0xffffffffffffff00);
                uVar23 = 0;
                local_b9 = 0;
              }
              if (param_9 == (undefined8 *)0x0) {
                *(undefined8 *)(lVar10 + 0x228) = 0;
                if ((uStack_134 & 0xc) == 8) {
                  if (((byte)uStack_138 >> 2 & 1) == 0) {
                    local_160 = CONCAT44(uStack_114,uStack_118);
                  }
                  else {
                    local_130 = CONCAT44(uStack_fc,local_100) +
                                CONCAT44(local_130._4_4_,(undefined4)local_130);
                    local_160 = local_160 + CONCAT44(uStack_fc,local_100);
                  }
                  local_148 = CONCAT44(uStack_f4,uStack_f8);
                  local_150 = CONCAT44(uStack_104,uStack_108);
                  uStack_158 = CONCAT44(uStack_10c,local_110);
                  uStack_134 = uStack_134 & 0xfff3;
                  local_100 = 0;
                  uStack_fc = 0;
                  uStack_f8 = 0;
                  uStack_f4 = 0;
                }
                if ((uStack_138 >> 2 & 1) == 0) {
                  FUN_fffffff00a34ab40(&local_160);
                }
                else if ((local_148 != 0) &&
                        (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                         ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                  FUN_fffffff00a346730();
                }
                local_150 = 0;
                local_148 = 0;
                local_130._4_4_ = 0;
                uStack_128 = 0;
                uStack_134 = 0;
                uStack_132 = 0;
                local_130._0_4_ = 0;
                uStack_11c = 0;
                uStack_118 = 0;
                uStack_124 = 0;
                local_120 = 0;
                uStack_10c = 0;
                uStack_108 = 0;
                uStack_114 = 0;
                local_110 = 0;
                uStack_fc = 0;
                uStack_f8 = 0;
                uStack_104 = 0;
                local_100 = 0;
                uStack_f4 = 0;
              }
              bVar11 = false;
              local_e8 = 0;
              if ((int)uVar23 != 0) {
LAB_fffffff00a2d22c4:
                *(ushort *)(lVar10 + 200) = uVar8 & 3 | *(ushort *)(lVar10 + 200) & 0xfffc;
                if (puVar47 != (undefined4 *)0x0) {
                  FUN_fffffff00a303950(puVar47);
                  DAT_fffffff00ad94e98 = DAT_fffffff00ad94e98 + 1;
                }
                uVar4 = local_b0;
                lVar29 = (long)(int)local_b0;
                iVar19 = (int)uVar23;
                if ((local_b0 < 0xb) && ((1 << (ulong)(local_b0 & 0x1f) & 0x580U) != 0)) {
                  FUN_fffffff00a42f3f4(1);
                }
                else if ((iVar19 == 0) &&
                        (((local_b0 & 0xfffffffd) != 4 &&
                         (iVar21 = FUN_fffffff00a2d7a48(1), iVar21 != 0)))) {
                  FUN_fffffff00a2d7cf8();
                }
                puVar47 = local_d8;
                if (local_d8 != (undefined4 *)0x0) {
                  if (iVar19 == 0) {
                    FUN_fffffff00a2ba128(local_d0,local_c8,local_c8 + 0x4000);
                  }
                  FUN_fffffff00a3061bc(puVar47);
                  uVar8 = *(ushort *)(puVar47 + 0x1b);
                  uVar41 = uVar8 - 1;
                  *(short *)(puVar47 + 0x1b) = (short)uVar41;
                  if (0xffff < uVar41) {
                    /* WARNING: Subroutine does not return */
                    FUN_fffffff00aa4d114("vm_object_paging_end(%p): underflow\n @%s:%d");
                  }
                  uVar41 = uVar41 & 0xffff;
                  if (((*(byte *)((long)puVar47 + 0x75) >> 4 & 1) == 0) &&
                     (((*(byte *)((long)puVar47 + 0xa9) & (uint)uVar8 == (uint)DAT_fffffff007bccab0)
                       != 0 || (DAT_fffffff007bccab2 == uVar8)))) {
                    FUN_fffffff00a30c550(puVar47,6);
                    uVar41 = (uint)*(ushort *)(puVar47 + 0x1b);
                  }
                  if (uVar41 == 0) {
                    uVar41 = puVar47[0x1d];
                    if ((uVar41 >> 5 & 1) != 0) {
                      FUN_fffffff00a24a024((long)puVar47 + 5,0,0);
                      uVar41 = puVar47[0x1d];
                    }
                    puVar47[0x1d] = uVar41 & 0xffffffdf;
                    if (puVar47[0x1c] == 0) {
                      FUN_fffffff00a30c550(puVar47,2);
                    }
                  }
                  FUN_fffffff00a22aeac(puVar47 + 2);
                }
                if (iVar6 == 1) {
                  FUN_fffffff00a2d7db8(lVar10,local_290,uVar27,lVar29);
                }
                if ((DAT_fffffff00ad98b00 & 0xfffffff7) == 0) {
                  return uVar23;
                }
                lVar10 = 0xb;
                if (!(bool)(bVar12 & uVar4 == 3)) {
                  lVar10 = lVar29;
                }
                FUN_fffffff00a6de494(0x130000a,uVar27 >> 0x20,uVar27,(long)iVar19,lVar10);
                return uVar23;
              }
              goto LAB_fffffff00a2cf624;
            }
            if (param_7 != (int *)0x0) {
              if ((puVar30 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar30)) {
                iVar19 = *(int *)((long)puVar30 + 0x3c);
              }
              else {
                iVar19 = DAT_fffffff007bf0000 +
                         (int)((ulong)((long)puVar30 - (long)DAT_fffffff007bf0010) >> 6);
              }
              *param_7 = iVar19;
              if ((uVar28 >> 1 & 1) != 0) {
                *(byte *)((long)puVar30 + 0x2d) = *(byte *)((long)puVar30 + 0x2d) | 1;
              }
            }
            if (((iVar6 == 1) && ((*(byte *)((long)puVar30 + 0x2b) >> 4 & 1) == 0)) &&
               (_DAT_fffffff00ad188f0 != 0)) {
              if (DAT_fffffff00ad6d188 == 0) {
                bVar33 = *(byte *)((long)puVar30 + 0x2b);
                DAT_fffffff00ad6d188 = (ulong)*(uint *)(lVar10 + 0x4e8);
              }
              else {
                uVar46 = FUN_fffffff00a2262d4(&DAT_fffffff00ad6d180,lVar10,0);
                bVar33 = *(byte *)((long)puVar30 + 0x2b);
              }
              if ((bVar33 >> 4 & 1) == 0) {
                *(byte *)((long)puVar30 + 0x2b) = bVar33 | 0x10;
                lVar29 = (ulong)DAT_fffffff00ad94cdc + 1;
                DAT_fffffff00ad94cdc = (uint)lVar29;
                if (lVar29 != lVar29 * 0x80000000 >> 0x1f) {
                    /* WARNING: Does not return */
                  pcVar14 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2d2eac);
                  (*pcVar14)();
                }
              }
              if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar10 + 0x4e8)) {
                DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
              }
              else {
                uVar46 = FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar10);
              }
            }
            if (((uVar42 >> 1 & 1) != 0) && ((*(byte *)((long)local_210 + 0x75) >> 4 & 1) == 0)) {
              uVar46 = FUN_fffffff00a2d79ac(local_210);
              local_d0 = *(undefined8 *)(local_210 + 0x14);
              local_c8 = puVar30[4] + *(long *)(local_210 + 0x18);
              local_d8 = local_210;
            }
            FUN_fffffff00a30a920(uVar46,puVar30);
            uVar23 = 0;
            puVar40 = local_210;
          }
          FUN_fffffff00a2d759c(puVar40,local_a8);
          if (param_9 == (undefined8 *)0x0) {
            *(undefined8 *)(lVar10 + 0x228) = 0;
            if ((uStack_134 & 0xc) == 8) {
              if (((byte)uStack_138 >> 2 & 1) == 0) {
                local_160 = CONCAT44(uStack_114,uStack_118);
              }
              else {
                local_130 = CONCAT44(uStack_fc,local_100) +
                            CONCAT44(local_130._4_4_,(undefined4)local_130);
                local_160 = local_160 + CONCAT44(uStack_fc,local_100);
              }
              local_148 = CONCAT44(uStack_f4,uStack_f8);
              local_150 = CONCAT44(uStack_104,uStack_108);
              uStack_158 = CONCAT44(uStack_10c,local_110);
              uStack_134 = uStack_134 & 0xfff3;
              local_100 = 0;
              uStack_fc = 0;
              uStack_f8 = 0;
              uStack_f4 = 0;
            }
            if ((uStack_138 >> 2 & 1) == 0) {
              FUN_fffffff00a34ab40(&local_160);
            }
            else if ((local_148 != 0) &&
                    (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                     ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
              FUN_fffffff00a346730();
            }
            local_150 = 0;
            local_148 = 0;
            local_130._4_4_ = 0;
            uStack_128 = 0;
            uStack_134 = 0;
            uStack_132 = 0;
            local_130._0_4_ = 0;
            uStack_11c = 0;
            uStack_118 = 0;
            uStack_124 = 0;
            local_120 = 0;
            uStack_10c = 0;
            uStack_108 = 0;
            uStack_114 = 0;
            local_110 = 0;
            uStack_fc = 0;
            uStack_f8 = 0;
            uStack_104 = 0;
            local_100 = 0;
            uStack_f4 = 0;
          }
          local_e8 = 0;
          FUN_fffffff00a2d79f4(&local_d8,uVar23);
          FUN_fffffff00a303950(local_88);
          goto LAB_fffffff00a2d22c4;
        }
        if (puVar30 == (undefined8 *)0x0) {
          FUN_fffffff00a3061bc(local_88);
          local_210 = puVar40;
        }
        else {
          FUN_fffffff00a3061bc(local_210);
          uVar22 = FUN_fffffff00a274564(&local_f0);
          FUN_fffffff00a30a920(uVar22,puVar30);
          if ((1L << (*(byte *)((long)puVar30 + 0x2a) & 0xf) & 0x3d60U) == 0) {
            FUN_fffffff00a226c24(&DAT_fffffff00ad6d180);
            if ((1L << (*(byte *)((long)puVar30 + 0x2a) & 0xf) & 0x3d60U) == 0) {
              FUN_fffffff00a32c144(puVar30);
            }
            if ((int)DAT_fffffff00ad6d188 == *(int *)(lVar10 + 0x4e8)) {
              DAT_fffffff00ad6d188 = CONCAT44(DAT_fffffff00ad6d188._4_4_,in_wzr);
            }
            else {
              FUN_fffffff00a226e08(&DAT_fffffff00ad6d180,lVar10);
            }
          }
        }
        FUN_fffffff00a2d759c(local_210,local_a8);
        FUN_fffffff00a303950(puVar40);
        if (param_9 == (undefined8 *)0x0) {
          *(undefined8 *)(lVar10 + 0x228) = 0;
          if ((uStack_134 & 0xc) == 8) {
            if (((byte)uStack_138 >> 2 & 1) == 0) {
              local_160 = CONCAT44(uStack_114,uStack_118);
            }
            else {
              local_130 = CONCAT44(uStack_fc,local_100) +
                          CONCAT44(local_130._4_4_,(undefined4)local_130);
              local_160 = local_160 + CONCAT44(uStack_fc,local_100);
            }
            local_148 = CONCAT44(uStack_f4,uStack_f8);
            local_150 = CONCAT44(uStack_104,uStack_108);
            uStack_158 = CONCAT44(uStack_10c,local_110);
            uStack_134 = uStack_134 & 0xfff3;
            local_100 = 0;
            uStack_fc = 0;
            uStack_f8 = 0;
            uStack_f4 = 0;
          }
          if ((uStack_138 >> 2 & 1) == 0) {
            FUN_fffffff00a34ab40(&local_160);
          }
          else if ((local_148 != 0) &&
                  (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                   ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
            FUN_fffffff00a346730();
          }
        }
        bVar11 = false;
        local_e8 = 0;
        goto LAB_fffffff00a2cf624;
      }
      if (-1 < (char)param_8[0x14]) {
        FUN_fffffff00a303950(puVar40);
        local_88 = (undefined4 *)0x0;
        uVar4 = 10;
        if (local_ac != 0) {
          uVar4 = local_ac;
        }
        uVar23 = (ulong)uVar4;
        goto LAB_fffffff00a2d22c4;
      }
      DAT_fffffff00ad94e80 = DAT_fffffff00ad94e80 + 1;
      bVar11 = true;
      puVar47 = puVar40;
      local_1e8 = uVar23;
      goto LAB_fffffff00a2cf624;
    }
    if ((DAT_fffffff00ad98b00 & 0xfffffff7) == 0) {
      if (lVar10 == 0) goto LAB_fffffff00a2d2a28;
LAB_fffffff00a2cf49c:
      uVar22 = *(undefined8 *)(lVar10 + 0x4e0);
    }
    else {
      FUN_fffffff00a6de494(0x130000a,uVar27 >> 0x20,uVar27,5,0);
      if (lVar10 != 0) goto LAB_fffffff00a2cf49c;
LAB_fffffff00a2d2a28:
      uVar22 = 0;
    }
    uVar26 = 0x10000e0;
    goto LAB_fffffff00a2d2a38;
  }
  if ((DAT_fffffff00ad98b00 & 0xfffffff7) == 0) {
    if (lVar10 == 0) goto LAB_fffffff00a2d2830;
LAB_fffffff00a2cf47c:
    uVar22 = *(undefined8 *)(lVar10 + 0x4e0);
  }
  else {
    FUN_fffffff00a6de494(0x130000a,uVar27 >> 0x20,uVar27,5,0);
    if (lVar10 != 0) goto LAB_fffffff00a2cf47c;
LAB_fffffff00a2d2830:
    uVar22 = 0;
  }
  uVar26 = 0x1000030;
LAB_fffffff00a2d2a38:
  FUN_fffffff00a6db8c0(uVar22,uVar26,0);
  return 5;
LAB_fffffff00a2cfdc8:
  FUN_fffffff00a3061bc(puVar25);
LAB_fffffff00a2cfdd4:
  uVar53 = (undefined4)((ulong)plVar31 >> 0x20);
  local_1b8 = 2;
  if ((*(byte *)(puVar40 + 0x2a) >> 6 & 1) != 0) goto LAB_fffffff00a2cfe40;
  goto LAB_fffffff00a2cf928;
code_r0xfffffff00a2cfd9c:
  if ((((*(byte *)(puVar40 + 0x2a) & 1) != 0) && (*(byte *)((long)puVar24 + 0x2e) < 0xf0)) &&
     ((((*(byte *)((long)puVar24 + 0x2e) ^ 0xff) & 0xf) != 0 ||
      ((*(byte *)((long)puVar24 + 0x2d) >> 6 & 1) != 0)))) goto LAB_fffffff00a2cfcf0;
  local_1d8 = 1;
LAB_fffffff00a2d0808:
  puVar37 = (undefined8 *)FUN_fffffff00a32cd9c(uVar28 & 0x10000);
  uVar54 = (undefined4)((ulong)in_stack_fffffffffffffd30 >> 0x20);
  if (puVar37 == (undefined8 *)0x0) goto LAB_fffffff00a2cfe40;
  FUN_fffffff00a32f138(puVar24);
  FUN_fffffff00a3297a4(puVar37,puVar25,local_90 & 0xffffffffffffc000,0,0,0);
  *(byte *)((long)puVar37 + 0x2d) = *(byte *)((long)puVar37 + 0x2d) | 1;
  if (((1 < (uint)puVar25[10]) && ((*(byte *)((long)puVar24 + 0x2d) >> 4 & 1) != 0)) ||
     ((uVar23 != 0 && (*(byte *)(uVar23 + 0x2c) < 0xe)))) {
    if ((puVar24 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar24)) {
      iVar21 = *(int *)((long)puVar24 + 0x3c);
    }
    else {
      iVar21 = DAT_fffffff007bf0000 +
               (int)((ulong)((long)puVar24 - (long)DAT_fffffff007bf0010) >> 6);
    }
    FUN_fffffff00a37c100(iVar21);
  }
  if ((*(byte *)((long)puVar24 + 0x2d) >> 3 & 1) != 0) {
    plVar31 = (long *)(*(long *)(lVar18 + 0x388) + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
    *plVar31 = *plVar31 + 1;
    if ((puVar24 < DAT_fffffff007bf0010) || (DAT_fffffff007bf0008 <= puVar24)) {
      iVar21 = *(int *)((long)puVar24 + 0x3c);
    }
    else {
      iVar21 = DAT_fffffff007bf0000 +
               (int)((ulong)((long)puVar24 - (long)DAT_fffffff007bf0010) >> 6);
    }
    FUN_fffffff00a37c1d0(iVar21);
    uVar23 = (ulong)*(byte *)((long)puVar24 + 0x2d);
    if ((*(byte *)((long)puVar24 + 0x2d) >> 3 & 1) != 0) {
      lVar45 = 0;
      if (*(uint *)((long)puVar24 + 0x1c) != 0) {
        lVar45 = (ulong)*(uint *)((long)puVar24 + 0x1c) * 0x40 + -0x2400000000;
      }
      *(int *)(lVar45 + 0xa0) = *(int *)(lVar45 + 0xa0) + 1;
      *(byte *)((long)puVar24 + 0x2d) = *(byte *)((long)puVar24 + 0x2d) & 0xf7;
      puVar3 = (ulong *)(_DAT_fffffff00ad188c8 + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
      uVar23 = *puVar3;
      *puVar3 = uVar23 + 1;
    }
    FUN_fffffff00a37c37c(uVar23,iVar21);
    FUN_fffffff00a2d3c78(puVar40,uVar43,*(undefined4 *)(param_8 + 8));
  }
  if (((*(byte *)((long)puVar40 + 0x75) >> 4 & 1) == 0) && (puVar40[0x1a] == 2)) {
    if (*(undefined4 **)(puVar40 + 0xe) == local_88) {
      FUN_fffffff00a22aeac(puVar40 + 2);
    }
    else {
      if (*(undefined4 **)(puVar40 + 0xe) != *(undefined4 **)(local_88 + 0x12))
      goto LAB_fffffff00a2d0f5c;
      iVar21 = (*(undefined4 **)(local_88 + 0x12))[0xb];
      FUN_fffffff00a22aeac(puVar40 + 2);
      if (iVar21 != 0) {
        local_27c = 1;
        goto LAB_fffffff00a2d0f74;
      }
    }
    local_27c = 0;
    DAT_fffffff00ad45fb0 = DAT_fffffff00ad45fb0 + 1;
  }
  else {
LAB_fffffff00a2d0f5c:
    FUN_fffffff00a22aeac(puVar40 + 2);
    local_27c = 1;
  }
LAB_fffffff00a2d0f74:
  DAT_fffffff00ad45fa8 = DAT_fffffff00ad45fa8 + 1;
  local_b0 = 3;
  plVar31 = (long *)(_DAT_fffffff00ad0e4a0 + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
  *plVar31 = *plVar31 + 1;
  plVar31 = (long *)(*(long *)(lVar18 + 0x390) + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
  *plVar31 = *plVar31 + 1;
  puVar24 = puVar37;
  puVar35 = (undefined4 *)0x0;
  puVar38 = puVar25;
  puVar40 = local_88;
  goto LAB_fffffff00a2d12cc;
}

