// FUN_fffffff00a292c2c @ fffffff00a292c2c size=15372

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_fffffff00a292c2c
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
  undefined4 *puVar14;
  code *pcVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  long lVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  undefined8 uVar23;
  ulong uVar24;
  undefined4 *puVar25;
  undefined8 uVar26;
  uint uVar27;
  uint uVar28;
  long lVar29;
  undefined8 *puVar30;
  long *plVar31;
  ulong uVar32;
  byte bVar33;
  ulong uVar34;
  undefined8 *puVar35;
  uint uVar36;
  undefined4 *puVar37;
  undefined4 *puVar38;
  ulong uVar39;
  long lVar40;
  ulong uVar41;
  ulong uVar42;
  undefined4 *puVar43;
  undefined8 *puVar44;
  ulong uVar45;
  long lVar46;
  undefined4 in_wzr;
  ushort *puVar47;
  undefined4 uVar50;
  undefined1 *puVar48;
  byte *pbVar49;
  undefined8 *in_stack_fffffffffffffd20;
  undefined4 uVar51;
  undefined4 uVar52;
  undefined8 in_stack_fffffffffffffd30;
  undefined4 uVar53;
  undefined8 local_278;
  undefined4 local_264;
  undefined4 *local_238;
  undefined4 *local_208;
  ulong local_1f0;
  uint local_1e4;
  int local_1d0;
  int local_1c0;
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
  long local_d8;
  undefined8 local_d0;
  undefined4 *local_c8;
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
  
  uVar13 = DAT_fffffff007c5e238;
  uVar41 = DAT_fffffff007c5e230;
  uVar45 = DAT_fffffff007c5e218;
  uVar24 = DAT_fffffff007c5e210;
  uVar32 = DAT_fffffff007c5b790;
  local_7c = 0;
  local_90 = 0;
  local_88 = (undefined4 *)0x0;
  local_94 = 0;
  local_a8 = 0;
  local_a0 = (undefined8 *)0x0;
  local_ac = 0;
  local_b9 = 0;
  local_d0 = 0;
  local_c8 = (undefined4 *)0x0;
  local_d8 = 0;
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
  uVar39 = (ulong)*(byte *)(param_1 + 0x2c);
  lVar29 = 1L << (uVar39 & 0x3f);
  uVar34 = -1L << (uVar39 & 0x3f);
  if (0xd < *(byte *)(param_1 + 0x2c)) {
    lVar29 = 0x4000;
    uVar34 = 0xffffffffffffc000;
  }
  uVar34 = param_2 & uVar34;
  uVar42 = uVar34;
  local_b8 = param_1;
  local_78[0] = param_1;
  if (param_1 == DAT_fffffff007c5b790) {
    uVar5 = uVar34 & 0x7ffffffffff;
    if ((param_2 & 0x80000000000000) != 0) {
      uVar5 = uVar34 | 0xffffff8000000000;
    }
    if (((uVar5 < DAT_fffffff007c5e218 && DAT_fffffff007c5e210 <= uVar5) ||
        (DAT_fffffff007c5e230 <= uVar5 && uVar5 < DAT_fffffff007c5e238)) ||
       ((uVar42 = 0, DAT_fffffff007c5e258 <= uVar5 && (uVar5 < DAT_fffffff007c5e260)))) {
      uVar42 = FUN_fffffff00a35921c();
    }
    uVar5 = param_2 & 0x7ffffffffff;
    if ((param_2 & 0x80000000000000) != 0) {
      uVar5 = param_2 | 0xffffff8000000000;
    }
    if (((uVar5 < uVar45 && uVar24 <= uVar5) || (uVar41 <= uVar5 && uVar5 < uVar13)) ||
       ((param_2 = 0, DAT_fffffff007c5e258 <= uVar5 && (uVar5 < DAT_fffffff007c5e260)))) {
      param_2 = FUN_fffffff00a35921c();
    }
  }
  if ((DAT_fffffff00ad58a20 & 0xfffffff7) != 0) {
    FUN_fffffff00a69ee5c(0x1300009,uVar42 >> 0x20,uVar42,param_1 == uVar32,0);
  }
  lVar10 = tpidr_el1;
  if (*(int *)(lVar10 + 0x1c0) == 0) {
    if ((*(byte *)(lVar10 + 1000) & 1) == 0) {
      iVar6 = *(int *)(lVar10 + 0x1ec);
      local_161 = 0;
      if (iVar6 == 1) {
        local_278 = UnkSytemRegRead(3,4,0xf,10,6);
      }
      else {
        local_278 = 0;
      }
      uVar8 = *(ushort *)(lVar10 + 200);
      *(ushort *)(lVar10 + 200) = uVar8 & 0xfffc | *param_8 & 3;
      uVar27 = (uint)param_3;
      uVar4 = uVar27;
      if ((*(uint *)(param_8 + 0x14) & 0x800) != 0) {
        uVar4 = 0;
      }
      plVar31 = (long *)(_DAT_fffffff00acce438 + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
      lVar19 = *plVar31;
      *plVar31 = lVar19 + 1;
      lVar19 = FUN_fffffff00a25f6f4(lVar19,lVar10);
      plVar31 = (long *)(*(long *)(lVar19 + 0x380) + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
      *plVar31 = *plVar31 + 1;
      if ((uVar4 >> 1 & 1) == 0) {
        local_1c0 = 1;
        if ((*(byte *)((long)param_8 + 0x29) & 8) != 0) {
          local_1c0 = 2;
        }
      }
      else {
        local_1c0 = 2;
      }
      local_dc = 0;
      if ((((param_1 == DAT_fffffff007c5b790) && ((uVar27 >> 1 & 1) != 0)) &&
          (DAT_fffffff00ad06000 != 0)) &&
         ((*(ulong *)(DAT_fffffff00ad06000 + 0x10) <= uVar34 &&
          (uVar34 < *(ulong *)(DAT_fffffff00ad06000 + 0x18))))) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa0c4f8("Write fault on compressor map, va: %p type: %u bounds: %p->%p @%s:%d")
        ;
      }
      bVar11 = false;
      local_264 = 0;
      bVar12 = false;
      local_1e4 = uVar4 >> 1 & 1;
      uVar32 = uVar34;
      if (param_5 != (undefined8 *)0x0) {
        uVar32 = param_6;
      }
      local_1f0 = 0xffffffffffffffff;
      local_1d0 = 1;
      puVar43 = (undefined4 *)0x0;
LAB_fffffff00a292f98:
      local_b0 = 4;
      if (bVar11) {
        DAT_fffffff00ad54da8 = DAT_fffffff00ad54da8 + 1;
        uVar28 = 0x10;
        local_1c0 = 2;
        local_1e4 = 1;
        uVar36 = 1;
      }
      else {
        uVar28 = 0x10;
        uVar36 = uVar4;
        if (local_1e4 == 0) {
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
      plVar31 = &local_160;
      puVar47 = param_8;
      local_78[0] = param_1;
      uVar24 = FUN_fffffff00a296838
                         (local_78,uVar34,uVar28 | uVar36,&local_88,&local_e8,&local_90,&local_94,
                          &local_7c,param_8,&local_b8,plVar31,param_9,in_stack_fffffffffffffd20);
      *(int *)(lVar10 + 0x1c0) = *(int *)(lVar10 + 0x1c0) + 1;
      lVar40 = *(long *)(lVar10 + 0x1b0) >> 0x10;
      plVar2 = (long *)(&DAT_fffffff00ace8260 + lVar40);
      if (*plVar2 == 0) {
        puVar30 = *(undefined8 **)(&DAT_fffffff00ace8268 + lVar40);
        if (puVar30 == (undefined8 *)0x0) {
          *plVar2 = 0;
        }
        else {
          *(undefined8 *)(&DAT_fffffff00ace8268 + lVar40) = *puVar30;
          *puVar30 = 0;
          *plVar2 = (long)puVar30;
          if ((puVar30 < DAT_fffffff007be4010) || (DAT_fffffff007be4008 <= puVar30)) {
            uVar28 = *(uint *)((long)puVar30 + 0x3c);
          }
          else {
            uVar28 = DAT_fffffff007be4000 +
                     (int)((ulong)((long)puVar30 - (long)DAT_fffffff007be4010) >> 6);
          }
          FUN_fffffff00a35137c((ulong)uVar28 << 0xe,0x4000);
          plVar2 = (long *)(_DAT_fffffff00acce4f8 + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
          *plVar2 = *plVar2 + 1;
        }
      }
      if (*(int *)(lVar10 + 0x1c0) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa1ba9c();
      }
      lVar40 = *(long *)(&DAT_fffffff00ace8268 + lVar40);
      iVar21 = *(int *)(lVar10 + 0x1c0) + -1;
      *(int *)(lVar10 + 0x1c0) = iVar21;
      if ((iVar21 == 0) && ((*(byte *)(*(long *)(lVar10 + 0x1b8) + 0x4c) >> 2 & 1) != 0)) {
        FUN_fffffff00a35a8b0();
      }
      if (lVar40 == 0) {
        FUN_fffffff00a2f0490(10);
      }
      puVar38 = local_88;
      if ((int)uVar24 != 0) goto LAB_fffffff00a295ca8;
      puVar30 = *(undefined8 **)(local_b8 + 0x58);
      uVar28 = *(uint *)(param_8 + 0x14);
      *(uint *)(param_8 + 0x14) = uVar28 & 0xffffff9b;
      if (local_7c != 0) {
        uVar36 = local_94 | 2;
      }
      iVar21 = 2;
      if (local_7c == 0 && local_1e4 == 0) {
        iVar21 = local_1c0;
      }
      if (((uVar36 == 1) && ((local_94 & 5) == 4)) && (puVar30 != &DAT_fffffff00ad2cb90)) {
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
            FUN_fffffff00a30dfb8(&local_160);
          }
          else if ((local_148 != 0) &&
                  (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                   ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
            FUN_fffffff00a309bc4();
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
        uVar24 = 2;
        goto LAB_fffffff00a295ca8;
      }
      if (bVar11) {
        if (((local_88 == (undefined4 *)0x0) || (local_88 != puVar43)) ||
           ((local_90 != local_1f0 || ((uVar28 >> 7 & 1) == 0)))) {
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
              FUN_fffffff00a30dfb8(&local_160);
            }
            else if ((local_148 != 0) &&
                    (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                     ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
              FUN_fffffff00a309bc4();
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
          FUN_fffffff00a2c7010(puVar43);
          puVar43 = (undefined4 *)0x0;
          bVar11 = false;
          DAT_fffffff00ad54dc0 = DAT_fffffff00ad54dc0 + 1;
          local_1f0 = 0xffffffffffffffff;
          local_1c0 = iVar21;
          goto LAB_fffffff00a292f98;
        }
        DAT_fffffff00ad54db0 = DAT_fffffff00ad54db0 + 1;
      }
      else {
        local_1f0 = 0xffffffffffffffff;
      }
      if ((iVar21 == 2) || ((*(long *)(local_88 + 0x12) == 0 && (*(short *)(local_88 + 4) != 0)))) {
        FUN_fffffff00a2c987c(local_88);
        local_1c0 = 2;
      }
      else {
        FUN_fffffff00a2ca55c(local_88);
        local_1c0 = 1;
      }
      uVar50 = (undefined4)((ulong)plVar31 >> 0x20);
      uVar45 = local_90 & 0x3fff;
      if ((((puVar38[0x1a] | 4) != 6) || (*(long *)(puVar38 + 0xe) == 0)) ||
         ((uVar36 >> 1 & 1) == 0)) {
        puVar37 = puVar38;
        if (((uint)puVar38[0x2a] >> 6 & 1) == 0) {
          uVar28 = (uint)puVar38[0x2a] >> 1;
          uVar22 = uVar36 & 2;
          uVar41 = local_90;
          do {
            while( true ) {
              uVar24 = uVar41 & 0xffffffffffffc000;
              puVar35 = (undefined8 *)FUN_fffffff00a2ef170(puVar38,uVar24);
              uVar50 = (undefined4)((ulong)plVar31 >> 0x20);
              puVar37 = puVar38;
              if (puVar35 == (undefined8 *)0x0) break;
              if ((local_161 & 1) == 0) {
                bVar33 = 0;
              }
              else {
                uVar24 = FUN_fffffff00a296e78(puVar30,puVar35,uVar34,local_94,param_8,&local_161);
                puVar25 = local_88;
                bVar33 = local_161;
                if ((int)uVar24 != 0) {
                  FUN_fffffff00a1eec04(local_88 + 2);
                  if (puVar25 != puVar38) {
                    FUN_fffffff00a1eec04(puVar38 + 2);
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
                      FUN_fffffff00a30dfb8(&local_160);
                    }
                    else if ((local_148 != 0) &&
                            (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                             ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                      FUN_fffffff00a309bc4();
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
                  goto LAB_fffffff00a295ca8;
                }
              }
              puVar25 = local_88;
              if (((*(byte *)((long)puVar35 + 0x2c) >> 2 & 1) == 0) && ((bVar33 & 1) == 0)) {
LAB_fffffff00a29347c:
                puVar25 = local_88;
                if ((*(byte *)((long)puVar35 + 0x2b) >> 1 & 1) != 0) {
                  if (local_88 == puVar38) {
                    if ((local_1c0 == 1) &&
                       (iVar21 = FUN_fffffff00a1edc80(local_88 + 2), iVar21 == 0))
                    goto LAB_fffffff00a29361c;
                    local_1c0 = 2;
                  }
                  else if (local_1d0 == 1) {
                    FUN_fffffff00a1eec04(local_88 + 2);
                    FUN_fffffff00a1eec04(puVar38 + 2);
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
joined_r0xfffffff00a295680:
                      if ((uStack_138 >> 2 & 1) == 0) {
                        FUN_fffffff00a30dfb8(&local_160);
                      }
                      else if ((local_148 != 0) &&
                              (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                               ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                        FUN_fffffff00a309bc4();
                      }
                    }
LAB_fffffff00a2956c8:
                    local_e8 = 0;
                    local_1d0 = 2;
                    goto LAB_fffffff00a292f98;
                  }
                  FUN_fffffff00a2de438(puVar35,0);
                }
                uVar24 = local_78[0];
                uVar50 = (undefined4)((ulong)plVar31 >> 0x20);
                if (((((puVar35 >= DAT_fffffff007be4010 && DAT_fffffff007be4008 > puVar35) ||
                      (*(int *)((long)puVar35 + 0x3c) != -2)) &&
                     ((*(byte *)((long)puVar35 + 0x2c) >> 3 & 1) == 0)) &&
                    (1 < (*(byte *)((long)puVar35 + 0x2c) & 3) - 1)) &&
                   ((*(char *)((long)puVar35 + 0x2a) < '\0' ||
                    ((puVar35 < DAT_fffffff007be4010 || DAT_fffffff007be4008 <= puVar35 &&
                     (0xfffffffd < *(uint *)((long)puVar35 + 0x3c))))))) {
                  if ((((uint)puVar38[0x2a] >> 5 & 1) == 0) ||
                     (1 < (*(ushort *)((long)puVar38 + 0x76) & 3) - 1)) {
                    puVar44 = (undefined8 *)(local_78[0] + 0x58);
                    if ((((puVar38[0x2a] & 1) == 0) ||
                        ((undefined8 *)*puVar44 != (undefined8 *)0x0 &&
                         (undefined8 *)*puVar44 == &DAT_fffffff00ad2cb90)) ||
                       ((0xef < *(byte *)((long)puVar35 + 0x2e) ||
                        ((((*(byte *)((long)puVar35 + 0x2e) ^ 0xff) & 0xf) == 0 &&
                         ((*(byte *)((long)puVar35 + 0x2d) >> 6 & 1) == 0)))))) {
                      if (param_7 == (int *)0x0) goto LAB_fffffff00a29367c;
                      if (((byte)local_94 >> 1 & 1) == 0) goto LAB_fffffff00a29367c;
                    }
LAB_fffffff00a293630:
                    puVar25 = local_88;
                    iVar21 = local_1c0;
                    if (local_88 == puVar38) {
                      local_1c0 = 2;
                      if (iVar21 == 1) {
                        iVar21 = FUN_fffffff00a1edc80(local_88 + 2);
                        local_1c0 = 2;
                        if (iVar21 == 0) goto LAB_fffffff00a29361c;
                      }
                    }
                    else if (local_1d0 == 1) {
                      FUN_fffffff00a1eec04(local_88 + 2);
                      FUN_fffffff00a1eec04(puVar38 + 2);
                      if (param_9 != (undefined8 *)0x0) goto LAB_fffffff00a2956c8;
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
                      goto joined_r0xfffffff00a295680;
                    }
LAB_fffffff00a29367c:
                    puVar14 = local_88;
                    uVar51 = (undefined4)((ulong)in_stack_fffffffffffffd30 >> 0x20);
                    iVar21 = local_1c0;
                    if ((local_88 == puVar38) && (*(long *)(local_88 + 0xe) == 0)) {
                      puVar25 = (undefined4 *)0x0;
                      puVar38 = local_88;
                      goto LAB_fffffff00a294c70;
                    }
                    if (local_1e4 == 0) {
                      if ((((local_88 != puVar38) && (local_88 != (undefined4 *)0x0)) &&
                          ((*(uint *)(param_8 + 0x14) >> 8 & 1) == 0)) &&
                         (((*(byte *)((long)puVar38 + 0x75) & 0x14) == 0 &&
                          ((*(byte *)(puVar38 + 0x2a) & 1) == 0)))) {
                        lVar40 = FUN_fffffff00a25ee44();
                        if (*(long *)(lVar40 + 0x18) == 0) {
                          iVar20 = FUN_fffffff00a6acd88(DAT_fffffff007c5f108);
                        }
                        else {
                          iVar20 = FUN_fffffff00a6acd88();
                        }
                        if ((((iVar20 != 0) ||
                             (((undefined8 *)*puVar44 != (undefined8 *)0x0 &&
                              ((undefined8 *)*puVar44 == &DAT_fffffff00ad2cb90)))) ||
                            ((*(byte *)(uVar24 + 0xfa) >> 2 & 1) != 0)) &&
                           (_DAT_fffffff00acd88e0 != 0)) {
                          DAT_fffffff00ad54d38 = DAT_fffffff00ad54d38 + 1;
                          lVar46 = *(long *)(lVar40 + 0x18);
                          if (*(long *)(lVar40 + 0x18) == 0) {
                            lVar46 = DAT_fffffff007c5f108;
                          }
                          iVar21 = FUN_fffffff00a6acd88(lVar46);
                          if (iVar21 == 0) {
                            if ((undefined8 *)*puVar44 == (undefined8 *)0x0) {
                              plVar31 = &DAT_fffffff00ad54d48;
                            }
                            else {
                              plVar31 = (long *)0xfffffff00ad54d40;
                              if ((undefined8 *)*puVar44 != &DAT_fffffff00ad2cb90) {
                                plVar31 = &DAT_fffffff00ad54d48;
                              }
                            }
                            *plVar31 = *plVar31 + 1;
                          }
                          FUN_fffffff00a1eec04(puVar14 + 2);
                          FUN_fffffff00a1eec04(puVar38 + 2);
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
                              FUN_fffffff00a30dfb8(&local_160);
                            }
                            else if ((local_148 != 0) &&
                                    (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                                     ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                              FUN_fffffff00a309bc4();
                            }
                          }
                          local_1e4 = 1;
                          goto LAB_fffffff00a294fec;
                        }
                      }
                      uVar51 = (undefined4)((ulong)in_stack_fffffffffffffd30 >> 0x20);
                      if (uVar22 == 0) {
                        if (puVar30 == (undefined8 *)0x0) {
                          bVar33 = 1;
                        }
                        else {
                          bVar33 = *(byte *)(puVar30[4] + 0x4c) ^ 1;
                        }
                        if ((((local_94 ^ 0xffffffff) & 7) == 0) && ((bVar33 & 1) != 0)) {
                          if (((byte)param_8[0x14] >> 3 & 1) == 0) goto LAB_fffffff00a296724;
                        }
                        else {
                          local_94 = local_94 & 0xfffffffd;
                        }
                        puVar25 = puVar14;
                        iVar21 = local_1d0;
                        if (puVar14 == puVar38) {
                          puVar25 = (undefined4 *)0x0;
                          iVar21 = local_1c0;
                          puVar38 = local_88;
                        }
                        goto LAB_fffffff00a294c70;
                      }
                    }
                    uVar50 = (undefined4)((ulong)plVar31 >> 0x20);
                    if (puVar14 != puVar38) {
                      if (local_1d0 == 1) goto code_r0xfffffff00a293710;
                      goto LAB_fffffff00a2940e4;
                    }
                    goto LAB_fffffff00a2937ec;
                  }
                  if (local_88 != puVar38) {
                    FUN_fffffff00a1eec04(local_88 + 2);
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
                      FUN_fffffff00a30dfb8(&local_160);
                    }
                    else if ((local_148 != 0) &&
                            (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                             ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                      FUN_fffffff00a309bc4();
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
                  FUN_fffffff00a1eec04(puVar38 + 2);
joined_r0xfffffff00a296170:
                  if (lVar10 == 0) {
                    uVar23 = 0;
                  }
                  else {
                    uVar23 = *(undefined8 *)(lVar10 + 0x4e0);
                  }
                  FUN_fffffff00a69c288(uVar23,0x1000038,0);
                  uVar24 = 10;
                  goto LAB_fffffff00a295ca8;
                }
                goto LAB_fffffff00a2937ec;
              }
              local_161 = 0;
              if (local_88 != puVar38) {
                if ((local_1d0 == 1) && (iVar21 = FUN_fffffff00a1edc80(puVar38 + 2), iVar21 == 0)) {
                  FUN_fffffff00a1eec04(local_88 + 2);
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
                      FUN_fffffff00a30dfb8(&local_160);
                    }
                    else if ((local_148 != 0) &&
                            (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                             ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                      FUN_fffffff00a309bc4();
                    }
                  }
                  local_e8 = 0;
                  local_1d0 = 2;
                  goto LAB_fffffff00a292f98;
                }
                local_1d0 = 2;
LAB_fffffff00a29340c:
                if (((*(byte *)((long)puVar35 + 0x2a) & 0xf) == 7) &&
                   ((*(byte *)((long)puVar38 + 0x75) >> 4 & 1) != 0)) {
                  uVar24 = (ulong)*(uint *)(lVar10 + 0x4e8);
                  if (DAT_fffffff00ad2d0c8 != 0) {
                    FUN_fffffff00a1ea02c(&DAT_fffffff00ad2d0c0,lVar10,0);
                    uVar24 = DAT_fffffff00ad2d0c8;
                  }
                  DAT_fffffff00ad2d0c8 = uVar24;
                  if ((*(byte *)((long)puVar35 + 0x2a) & 0xf) == 7) {
                    uVar23 = FUN_fffffff00a2d4910(puVar35);
                    if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar10 + 0x4e8)) {
                      DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
                    }
                    else {
                      uVar23 = FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar10);
                    }
                    FUN_fffffff00a2cdfcc(uVar23,puVar35);
                    goto LAB_fffffff00a29347c;
                  }
                  if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar10 + 0x4e8)) {
                    DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
                  }
                  else {
                    FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar10);
                  }
                }
                if (local_88 != puVar38) {
                  FUN_fffffff00a1eec04(local_88 + 2);
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
                    FUN_fffffff00a30dfb8(&local_160);
                  }
                  else if ((local_148 != 0) &&
                          (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                           ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                    FUN_fffffff00a309bc4();
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
                    FUN_fffffff00a296ffc(param_9[2],&DAT_fffffff00acd8830,2,*param_9,param_9[1]);
                  }
                }
                iVar21 = FUN_fffffff00a2c9108(puVar38,puVar35,*(undefined4 *)param_8,1);
                if ((iVar21 == 0) || (iVar21 == 3)) goto LAB_fffffff00a292f98;
                if (lVar10 == 0) {
                  uVar23 = 0;
                }
                else {
                  uVar23 = *(undefined8 *)(lVar10 + 0x4e0);
                }
                FUN_fffffff00a69c288(uVar23,0x1000034,0);
                uVar24 = 0xe;
                goto LAB_fffffff00a295ca8;
              }
              if ((local_1c0 != 1) || (iVar21 = FUN_fffffff00a1edc80(local_88 + 2), iVar21 != 0)) {
                local_1c0 = 2;
                goto LAB_fffffff00a29340c;
              }
LAB_fffffff00a29361c:
              FUN_fffffff00a2c987c(puVar25);
              uVar50 = (undefined4)((ulong)plVar31 >> 0x20);
              local_1c0 = 2;
              if ((*(byte *)(puVar38 + 0x2a) >> 6 & 1) != 0) goto LAB_fffffff00a2937ec;
            }
            uVar7 = puVar38[0x1d];
            if ((uVar7 >> 7 & 1) != 0) {
              if ((((uVar7 >> 0xc & 1) != 0) && ((uVar7 >> 0xf & 1) != 0)) &&
                 (*(long *)(puVar38 + 0x14) != 0)) {
                iVar21 = FUN_fffffff00a28980c
                                   (*(long *)(puVar38 + 0x14),*(long *)(puVar38 + 0x18) + uVar41);
                puVar25 = local_88;
                uVar50 = (undefined4)((ulong)plVar31 >> 0x20);
                if (iVar21 == 3) goto LAB_fffffff00a2932d8;
                local_198 = local_198 & 0xffffffff00000000;
                if (((iVar21 == 1) && (local_78[0] != DAT_fffffff007c5b790)) &&
                   (local_b8 != DAT_fffffff007c5b790)) {
                  bVar16 = local_88 != puVar38;
                  bVar17 = uVar22 == 0;
                  if (bVar16 && bVar17) {
                    if ((local_1d0 == 1) &&
                       (iVar21 = FUN_fffffff00a1edc80(puVar38 + 2), iVar21 == 0)) {
                      FUN_fffffff00a1eec04(local_88 + 2);
                      local_1d0 = 2;
joined_r0xfffffff00a295594:
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
                          FUN_fffffff00a30dfb8(&local_160);
                        }
                        else if ((local_148 != 0) &&
                                (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                                 ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                          FUN_fffffff00a309bc4();
                        }
                      }
                      local_e8 = 0;
                      goto LAB_fffffff00a292f98;
                    }
                    iVar21 = 1;
                    local_1d0 = 2;
                  }
                  else {
                    if (local_1c0 == 1) {
                      if (local_88 != puVar38) {
                        FUN_fffffff00a1eec04(local_88 + 2);
                        FUN_fffffff00a1eec04(puVar38 + 2);
                        local_1c0 = 2;
                        goto joined_r0xfffffff00a295594;
                      }
                      iVar21 = FUN_fffffff00a1edc80(local_88 + 2);
                      uVar50 = (undefined4)((ulong)plVar31 >> 0x20);
                      if (iVar21 == 0) goto LAB_fffffff00a29361c;
                      iVar21 = 1;
                    }
                    else {
                      iVar21 = 1;
                      if (local_88 != puVar38) {
                        iVar21 = uVar22 + 1;
                      }
                    }
                    local_1c0 = 2;
                  }
                  puVar35 = (undefined8 *)FUN_fffffff00a2f01d8(uVar28 & 0x10000);
                  puVar25 = local_88;
                  if (puVar35 != (undefined8 *)0x0) {
                    local_238 = local_88;
                    bVar18 = local_88 != puVar38;
                    if ((puVar35 < DAT_fffffff007be4010) || (DAT_fffffff007be4008 <= puVar35)) {
                      iVar20 = *(int *)((long)puVar35 + 0x3c);
                    }
                    else {
                      iVar20 = DAT_fffffff007be4000 +
                               (int)((ulong)((long)puVar35 - (long)DAT_fffffff007be4010) >> 6);
                    }
                    iVar21 = FUN_fffffff00a2894ec
                                       (*(undefined8 *)(puVar38 + 0x14),
                                        *(long *)(puVar38 + 0x18) + uVar24,iVar20,&local_198,iVar21,
                                        &local_dc);
                    uVar51 = (undefined4)((ulong)in_stack_fffffffffffffd30 >> 0x20);
                    lVar40 = *(long *)(puVar38 + 0x14);
                    if (((lVar40 != 0) && (local_dc != 0)) &&
                       (*(undefined **)(lVar40 + 8) == &DAT_fffffff007bbe018)) {
                      if ((local_1c0 != 2 || bVar18) && (local_1d0 != 2 || !bVar18)) {
                        *(int *)(lVar40 + 0x34) = *(int *)(lVar40 + 0x34) + local_dc;
                      }
                      else {
                        *(int *)(lVar40 + 0x34) = *(int *)(lVar40 + 0x34) + local_dc;
                      }
                    }
                    if (iVar21 == 0) {
                      *(byte *)((long)puVar35 + 0x2d) = *(byte *)((long)puVar35 + 0x2d) | 1;
                      if ((((puVar25 == puVar38 || bVar16 && bVar17) &&
                           ((((puVar38[0x1d] ^ 0xffffffff) & 0x30000) != 0 ||
                            ((*(byte *)((long)puVar38 + 0xaa) & 0x38) != 0)))) &&
                          (*(long *)(puVar38 + 0x16) != 0)) && (local_dc != 0)) {
                        FUN_fffffff00a2e62f8(puVar38,0xffffffff);
                      }
                      puVar37 = local_88;
                      if (bVar16 && bVar17) {
                        FUN_fffffff00a2ecbf4(puVar35,puVar38,uVar24,0,0,0);
                        puVar37 = puVar38;
                      }
                      else {
                        FUN_fffffff00a2ecbf4(puVar35,local_88,local_90 & 0xffffffffffffc000,0,0,0);
                      }
                      if ((*(char *)((long)puVar37 + 0xa6) != '\x02') &&
                         (*(char *)((long)puVar37 + 0xa6) != -0x80)) {
                        DataSynchronizationBarrier(3,3,0);
                      }
                      local_b0 = (uint)local_198;
                      plVar31 = (long *)(_DAT_fffffff00acce498 +
                                        (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
                      *plVar31 = *plVar31 + 1;
                      *(int *)(lVar10 + 0x560) = *(int *)(lVar10 + 0x560) + 1;
                      if (puVar38 == local_88) {
                        puVar25 = (undefined4 *)0x0;
                        iVar21 = local_1c0;
                        puVar38 = local_88;
                      }
                      else {
                        puVar25 = local_88;
                        iVar21 = local_1d0;
                        if (!bVar16 || !bVar17) {
                          FUN_fffffff00a1eec04(puVar38 + 2);
                          puVar25 = (undefined4 *)0x0;
                          iVar21 = local_1c0;
                          puVar38 = local_88;
                        }
                      }
LAB_fffffff00a294c70:
                      local_88 = puVar38;
                      if ((bVar11) && ((local_94 >> 1 & 1) != 0)) {
                        if (puVar30 == (undefined8 *)0x0) {
                          bVar33 = 1;
                        }
                        else {
                          bVar33 = *(byte *)(puVar30[4] + 0x4c) ^ 1;
                        }
                        if ((((local_94 ^ 0xffffffff) & 7) == 0) && ((bVar33 & 1) != 0)) {
                          if (((byte)param_8[0x14] >> 3 & 1) == 0) {
LAB_fffffff00a296724:
                    /* WARNING: Subroutine does not return */
                            FUN_fffffff00aa0c4f8
                                      ("%s: pmap %p vaddr 0x%llx prot 0x%x options 0x%x @%s:%d");
                          }
                        }
                        else {
                          local_94 = local_94 & 0xfffffffd;
                        }
                      }
                      if (((iVar6 == 1) && ((*(byte *)((long)puVar35 + 0x2b) >> 4 & 1) == 0)) &&
                         (_DAT_fffffff00acd88d8 != 0)) {
                        if (DAT_fffffff00ad2d0c8 == 0) {
                          bVar33 = *(byte *)((long)puVar35 + 0x2b);
                          DAT_fffffff00ad2d0c8 = (ulong)*(uint *)(lVar10 + 0x4e8);
                        }
                        else {
                          FUN_fffffff00a1ea02c(&DAT_fffffff00ad2d0c0,lVar10,0);
                          bVar33 = *(byte *)((long)puVar35 + 0x2b);
                        }
                        if ((bVar33 >> 4 & 1) == 0) {
                          *(byte *)((long)puVar35 + 0x2b) = bVar33 | 0x10;
                          lVar40 = (ulong)DAT_fffffff00ad54bfc + 1;
                          DAT_fffffff00ad54bfc = (uint)lVar40;
                          if (lVar40 != lVar40 * 0x80000000 >> 0x1f) {
                    /* WARNING: Does not return */
                            pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a29680c);
                            (*pcVar15)();
                          }
                        }
                        if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar10 + 0x4e8)) {
                          DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
                        }
                        else {
                          FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar10);
                        }
                      }
                      uVar28 = local_94;
                      local_b9 = 0;
                      puVar44 = puVar30;
                      uVar24 = uVar34;
                      if (param_5 != (undefined8 *)0x0) {
                        puVar44 = param_5;
                        uVar24 = param_6;
                      }
                      pbVar49 = &local_b9;
                      uVar23 = CONCAT62((int6)((ulong)puVar47 >> 0x10),(short)param_4);
                      uVar50 = (undefined4)uVar23;
                      uVar24 = FUN_fffffff00a2970ac
                                         (puVar35,puVar44,uVar24,lVar29,uVar45,local_94,param_3,
                                          local_7c,uVar23,param_8,pbVar49,&local_b0,
                                          in_stack_fffffffffffffd20,&local_161);
                      uVar53 = (undefined4)((ulong)pbVar49 >> 0x20);
                      uVar52 = (undefined4)((ulong)in_stack_fffffffffffffd20 >> 0x20);
                      local_180 = *(undefined8 *)(puVar37 + 0x14);
                      lStack_178 = puVar35[4] + *(long *)(puVar37 + 0x18);
                      local_170 = 0;
                      if ((*(byte *)((long)param_8 + 0x29) >> 5 & 1) == 0) {
                        uVar22 = 1;
                      }
                      else {
                        uVar22 = FUN_fffffff00a32bbf4(&local_180);
                        uVar22 = uVar22 ^ 1;
                      }
                      uVar7 = 0xb;
                      if (!(bool)(bVar12 & local_b0 == 3)) {
                        uVar7 = local_b0;
                      }
                      in_stack_fffffffffffffd30 = CONCAT44(uVar51,uVar36);
                      in_stack_fffffffffffffd20 = (undefined8 *)CONCAT44(uVar52,local_264);
                      uVar45 = CONCAT71((int7)(CONCAT44((int)uVar24,uVar50) >> 8),
                                        local_b9 | local_161) & 0xffffffffffffff01;
                      FUN_fffffff00a2972b8
                                (local_88,puVar37,puVar35,local_90,param_2,param_8,param_3,uVar7,
                                 uVar45,param_7,CONCAT44(uVar53,uVar28),puVar25,
                                 in_stack_fffffffffffffd20,uVar41,in_stack_fffffffffffffd30,
                                 &local_c8,&local_d0,&local_d8);
                      if ((uVar22 & 1) == 0) {
                        FUN_fffffff00a32bcb0(&local_180);
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
                          FUN_fffffff00a30dfb8(&local_160);
                        }
                        else if ((local_148 != 0) &&
                                (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                                 ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                          FUN_fffffff00a309bc4();
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
                      local_1c0 = iVar21;
                      if ((local_b9 & 1) == 0) {
                        if ((local_161 & 1) != 0) goto LAB_fffffff00a292f98;
                        goto LAB_fffffff00a295ca8;
                      }
LAB_fffffff00a294f20:
                      local_e8 = 0;
                      FUN_fffffff00a33363c(puVar30,uVar34,0,0,0,0,0,2,uVar45 & 0xffffffffffffff00);
                      local_b9 = 0;
                      goto LAB_fffffff00a292f98;
                    }
                    FUN_fffffff00a2eeea0(puVar35,0);
                    if (iVar21 == 9) {
                      if (puVar25 != puVar38) {
                        FUN_fffffff00a1eec04(puVar38 + 2);
                        local_238 = local_88;
                      }
                      FUN_fffffff00a1eec04(local_238 + 2);
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
                          FUN_fffffff00a30dfb8(&local_160);
                        }
                        else if ((local_148 != 0) &&
                                (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                                 ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                          FUN_fffffff00a309bc4();
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
                      uVar24 = 9;
                      goto LAB_fffffff00a295ca8;
                    }
                  }
                }
              }
              break;
            }
LAB_fffffff00a2932d8:
            uVar50 = (undefined4)((ulong)plVar31 >> 0x20);
            puVar37 = *(undefined4 **)(puVar38 + 0x12);
            if (!(bool)(puVar37 != (undefined4 *)0x0 & (bVar11 ^ 1U))) {
              if ((((*(byte *)(puVar38 + 0x2a) >> 5 & 1) != 0) &&
                  ((uVar9 = *(ushort *)((long)puVar38 + 0x76) & 3, uVar9 == 1 || (uVar9 == 2)))) ||
                 ((puVar38 == &DAT_fffffff00ad7b400 || (puVar38 == &DAT_fffffff00ad7b300)))) {
                if (local_88 != puVar38) {
                  FUN_fffffff00a1eec04(puVar38 + 2);
                }
                FUN_fffffff00a1eec04(local_88 + 2);
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
                    FUN_fffffff00a30dfb8(&local_160);
                  }
                  else if ((local_148 != 0) &&
                          (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                           ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                    FUN_fffffff00a309bc4();
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
                if (((*(byte *)(puVar38 + 0x2a) >> 5 & 1) != 0) &&
                   ((*(ushort *)((long)puVar38 + 0x76) & 3) - 1 < 2))
                goto joined_r0xfffffff00a296170;
                uVar24 = 10;
                goto LAB_fffffff00a295ca8;
              }
              if (puVar38 != local_88) {
                FUN_fffffff00a1eec04(puVar38 + 2);
                puVar38 = local_88;
              }
              puVar37 = local_88;
              if (local_1c0 == 1) {
                iVar21 = FUN_fffffff00a1edc80(local_88 + 2);
                if (iVar21 == 0) {
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
                      FUN_fffffff00a30dfb8(&local_160);
                    }
                    else if ((local_148 != 0) &&
                            (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                             ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                      FUN_fffffff00a309bc4();
                    }
                  }
LAB_fffffff00a294fec:
                  local_e8 = 0;
                  local_1c0 = 2;
                  goto LAB_fffffff00a292f98;
                }
              }
              uVar24 = local_78[0];
              uVar51 = (undefined4)((ulong)in_stack_fffffffffffffd20 >> 0x20);
              if ((*(byte *)((long)puVar37 + 0x75) >> 4 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
                FUN_fffffff00aa0c4f8
                          (
                          "%s:%d should not zero-fill page at offset 0x%llx in external object %p @%s:%d"
                          );
              }
              lVar40 = FUN_fffffff00a2f01d8
                                 (((*(uint *)(local_78[0] + 0xf8) & 2) << 3 | uVar28 & 0x10000) ^
                                  0x10);
              uVar13 = local_90;
              uVar53 = (undefined4)((ulong)in_stack_fffffffffffffd30 >> 0x20);
              if (lVar40 != 0) {
                FUN_fffffff00a2ecbf4(lVar40,puVar37,local_90 & 0xffffffffffffc000,0,8,0);
                if ((((local_94 >> 1 & 1) != 0) && (uVar22 == 0)) && (*(long *)(puVar37 + 0xe) != 0)
                   ) {
                  if (puVar30 == (undefined8 *)0x0) {
                    bVar33 = 1;
                  }
                  else {
                    bVar33 = *(byte *)(puVar30[4] + 0x4c) ^ 1;
                  }
                  if ((((local_94 ^ 0xffffffff) & 7) == 0) && ((bVar33 & 1) != 0)) {
                    if (((byte)param_8[0x14] >> 3 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
                      FUN_fffffff00aa0c4f8("%s: pmap %p vaddr 0x%llx prot 0x%x options 0x%x @%s:%d")
                      ;
                    }
                  }
                  else {
                    local_94 = local_94 & 0xfffffffd;
                  }
                }
                *(ushort *)(lVar40 + 0x2e) = *(ushort *)(lVar40 + 0x2e) & 0xf000;
                *(byte *)(lVar40 + 0x2d) = *(byte *)(lVar40 + 0x2d) | 0x10;
                local_b0 = 5;
                if ((*(uint *)(uVar24 + 0xf8) & 2) == 0) {
                  local_b0 = 1;
                }
                puVar35 = puVar30;
                if (param_5 != (undefined8 *)0x0) {
                  puVar35 = param_5;
                }
                uVar28 = uVar27;
                if ((*(uint *)(param_8 + 0x14) & 0x800) != 0) {
                  uVar28 = 0;
                }
                puVar48 = &local_dd;
                puVar47 = param_8;
                uVar24 = FUN_fffffff00a297658
                                   (lVar40,puVar35,uVar32,&local_94,param_3,lVar29,uVar45,uVar28,
                                    param_8,&local_b0,puVar48,&local_161);
                iVar21 = local_7c;
                uVar22 = (uint)puVar47;
                uVar50 = (undefined4)((ulong)puVar48 >> 0x20);
                if ((int)uVar24 == 0) {
                  if (((*(uint *)(param_8 + 0x14) >> 9 & 1) != 0) &&
                     ((*(byte *)(puVar37 + 0x2a) & 1) == 0)) {
                    *(uint *)(param_8 + 0x16) = *(uint *)(param_8 + 0x16) | 0x20000;
                  }
                  if ((*(uint *)(param_8 + 0x14) >> 10 & 1) == 0) {
                    uVar22 = *(uint *)(param_8 + 0x16);
                  }
                  else {
                    uVar22 = *(uint *)(param_8 + 0x16);
                    if (((byte)local_94 >> 1 & 1) != 0) {
                      uVar22 = uVar22 | 0x400000;
                      *(uint *)(param_8 + 0x16) = uVar22;
                    }
                  }
                  uVar24 = FUN_fffffff00a298590
                                     (puVar35,uVar32,uVar45,lVar40,&local_94,param_3,uVar28,
                                      local_7c != 0,uVar22,&local_b9);
                }
                FUN_fffffff00a298680(puVar37,lVar40);
                FUN_fffffff00a2987e0
                          (puVar37,lVar40,iVar21 != 0,*(uint *)(param_8 + 0x14) >> 0xb & 1,param_4,
                           *(uint *)(param_8 + 0x14) & 1,&local_b0,uVar24);
                if (((iVar6 == 1) && ((*(byte *)(lVar40 + 0x2b) >> 4 & 1) == 0)) &&
                   (_DAT_fffffff00acd88d8 != 0)) {
                  if (DAT_fffffff00ad2d0c8 == 0) {
                    bVar33 = *(byte *)(lVar40 + 0x2b);
                    DAT_fffffff00ad2d0c8 = (ulong)*(uint *)(lVar10 + 0x4e8);
                  }
                  else {
                    FUN_fffffff00a1ea02c(&DAT_fffffff00ad2d0c0,lVar10,0);
                    bVar33 = *(byte *)(lVar40 + 0x2b);
                  }
                  if ((bVar33 >> 4 & 1) == 0) {
                    *(byte *)(lVar40 + 0x2b) = bVar33 | 0x10;
                    lVar46 = (ulong)DAT_fffffff00ad54bfc + 1;
                    DAT_fffffff00ad54bfc = (uint)lVar46;
                    if (lVar46 != lVar46 * 0x80000000 >> 0x1f) {
                    /* WARNING: Does not return */
                      pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a296800);
                      (*pcVar15)();
                    }
                  }
                  if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar10 + 0x4e8)) {
                    DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
                  }
                  else {
                    FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar10);
                  }
                }
                bVar33 = local_b9;
                in_stack_fffffffffffffd30 = CONCAT44(uVar53,uVar36);
                in_stack_fffffffffffffd20 = (undefined8 *)CONCAT44(uVar51,local_264);
                uVar45 = CONCAT71((int7)(CONCAT44((int)uVar24,uVar22) >> 8),local_b9) &
                         0xffffffffffffff01;
                FUN_fffffff00a2972b8
                          (puVar37,puVar37,lVar40,uVar13,param_2,param_8,param_3,local_b0,uVar45,
                           param_7,CONCAT44(uVar50,local_94),0,in_stack_fffffffffffffd20,uVar41,
                           in_stack_fffffffffffffd30,&local_c8,&local_d0,&local_d8);
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
                    FUN_fffffff00a30dfb8(&local_160);
                  }
                  else if ((local_148 != 0) &&
                          (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                           ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                    FUN_fffffff00a309bc4();
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
                if ((bVar33 & 1) != 0) {
                  local_1c0 = 2;
                  goto LAB_fffffff00a294f20;
                }
                goto LAB_fffffff00a295ca8;
              }
              local_1c0 = 2;
              puVar37 = puVar38;
              break;
            }
            lVar40 = *(long *)(puVar38 + 0x16);
            if (local_1d0 == 1) {
              FUN_fffffff00a2ca55c();
            }
            else {
              FUN_fffffff00a2c987c(puVar37);
            }
            if (puVar38 != local_88) {
              FUN_fffffff00a1eec04(puVar38 + 2);
            }
            uVar50 = (undefined4)((ulong)plVar31 >> 0x20);
            uVar45 = lVar40 + uVar41 & 0x3fff;
            uVar41 = lVar40 + uVar41;
            puVar38 = puVar37;
          } while ((*(byte *)(puVar37 + 0x2a) >> 6 & 1) == 0);
        }
LAB_fffffff00a2937ec:
        if (local_88 != puVar37) {
          FUN_fffffff00a1eec04(puVar37 + 2);
        }
        puVar38 = local_88;
        if ((local_1c0 == 1) && (iVar21 = FUN_fffffff00a1edc80(local_88 + 2), iVar21 == 0)) {
          FUN_fffffff00a2c987c(puVar38);
        }
        local_1c0 = 2;
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
          FUN_fffffff00a30dfb8(&local_160);
        }
        else if ((local_148 != 0) &&
                (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                 ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
          FUN_fffffff00a309bc4();
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
      if ((local_88 == &DAT_fffffff00ad7b400) || (local_88 == &DAT_fffffff00ad7b300)) {
        FUN_fffffff00a1eec04(local_88 + 2);
        uVar24 = 10;
        goto LAB_fffffff00a295ca8;
      }
      if (bVar11) {
        if (local_88 != puVar43) {
          FUN_fffffff00a2c7010(puVar43);
          puVar43 = (undefined4 *)0x0;
          DAT_fffffff00ad54dc8 = DAT_fffffff00ad54dc8 + 1;
          local_1f0 = 0xffffffffffffffff;
          goto LAB_fffffff00a29395c;
        }
        puVar43 = (undefined4 *)0x0;
        DAT_fffffff00ad54dc8 = DAT_fffffff00ad54dc8 + 1;
        local_1f0 = 0xffffffffffffffff;
      }
      else {
LAB_fffffff00a29395c:
        if (local_88[10] + 0xf0000001 < 0xf0000002) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa21104(local_88 + 10);
        }
        local_88[10] = local_88[10] + 1;
      }
      puVar38 = local_88;
      uVar41 = local_90;
      uVar9 = *(ushort *)(local_88 + 0x1b);
      *(short *)(local_88 + 0x1b) = (short)(uVar9 + 1);
      if (uVar9 + 1 >> 0x10 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa0c4f8("vm_object_paging_begin(%p): overflow\n @%s:%d");
      }
      *(undefined4 *)(lVar10 + 0x478) = 0;
      local_ac = 0;
      local_a0 = (undefined8 *)0x0;
      uVar24 = local_90;
      in_stack_fffffffffffffd20 = param_9;
      iVar21 = FUN_fffffff00a298c00
                         (local_88,local_90,uVar36,
                          (uint)(local_7c == 0) & *(uint *)(param_8 + 0x14) >> 0xb,0,&local_94,
                          &local_a0,&local_a8,&local_b0,&local_ac,
                          CONCAT44(uVar50,*(uint *)(local_78[0] + 0xf8) >> 1) & 0xffffffff00000001,
                          param_8,param_9);
      if ((iVar21 == 0) || (iVar21 == 6)) goto LAB_fffffff00a293bb0;
      if (iVar21 != 5) {
        FUN_fffffff00a2c7010(puVar38);
        puVar38 = (undefined4 *)0x0;
        local_88 = (undefined4 *)0x0;
        if (iVar21 < 3) {
          bVar11 = false;
          if (iVar21 == 1) goto LAB_fffffff00a292f98;
          if (iVar21 == 2) {
            if (lVar10 == 0) {
              uVar23 = 0;
            }
            else {
              uVar23 = *(undefined8 *)(lVar10 + 0x4e0);
            }
LAB_fffffff00a296000:
            FUN_fffffff00a69c288(uVar23,0x1000024,0);
            uVar24 = 0xe;
            goto LAB_fffffff00a295ca8;
          }
        }
        else {
          if (iVar21 == 3) {
            iVar21 = FUN_fffffff00a2f0b8c((*(uint *)(param_8 + 0x14) >> 10 ^ 0xffffffff) & 2);
            bVar11 = false;
            if (iVar21 == 0) {
              if (lVar10 == 0) {
                uVar23 = 0;
              }
              else {
                uVar23 = *(undefined8 *)(lVar10 + 0x4e0);
              }
              FUN_fffffff00a69c288(uVar23,0x1000014,0);
              goto LAB_fffffff00a296000;
            }
            goto LAB_fffffff00a292f98;
          }
          if (iVar21 == 7) {
            uVar24 = 0x1e;
            goto LAB_fffffff00a295ca8;
          }
        }
LAB_fffffff00a293bb0:
        puVar30 = local_a0;
        if (local_a0 == (undefined8 *)0x0) {
          FUN_fffffff00a1eec04(puVar38 + 2);
          lVar40 = 0;
          lVar46 = 0;
          local_208 = (undefined4 *)0x0;
        }
        else {
          lVar1 = (ulong)*(uint *)((long)local_a0 + 0x1c) * 0x40;
          local_208 = (undefined4 *)0x0;
          if (*(uint *)((long)local_a0 + 0x1c) != 0) {
            local_208 = (undefined4 *)(lVar1 + -0x2400000000);
          }
          lVar40 = *(long *)(lVar1 + -0x23ffffffc8);
          lVar46 = *(long *)(lVar1 + -0x23ffffffc0);
          local_198 = *(ulong *)(lVar1 + -0x23ffffffb0);
          lStack_190 = local_a0[4] + *(long *)(lVar1 + -0x23ffffffa0);
          local_188 = 0;
          if ((*(byte *)((long)param_8 + 0x29) >> 5 & 1) == 0) {
            *(short *)(lVar10 + 0x20e) = *(short *)(lVar10 + 0x20e) + 1;
            local_f0 = lVar10;
            FUN_fffffff00a1eec04(lVar1 + -0x23fffffff8);
          }
          else {
            iVar21 = FUN_fffffff00a32bbf4(&local_198);
            *(short *)(lVar10 + 0x20e) = *(short *)(lVar10 + 0x20e) + 1;
            local_f0 = lVar10;
            FUN_fffffff00a1eec04(lVar1 + -0x23fffffff8);
            if (iVar21 != 0) {
              FUN_fffffff00a32bcb0(&local_198);
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
        puVar47 = param_8;
        local_78[0] = param_1;
        uVar24 = FUN_fffffff00a296838
                           (local_78,uVar34,uVar36,&local_1a0,&local_e8,&local_1a8,&local_1ac,
                            &local_7c,param_8,&local_b8,&local_160,param_9,in_stack_fffffffffffffd20
                           );
        puVar38 = local_88;
        puVar44 = (undefined8 *)(local_b8 + 0x58);
        puVar35 = (undefined8 *)*puVar44;
        iVar21 = (int)uVar24;
        if (iVar21 != 0) {
          if (puVar30 == (undefined8 *)0x0) {
            FUN_fffffff00a2c987c(local_88);
            FUN_fffffff00a29b220(puVar38,local_a8);
          }
          else {
            FUN_fffffff00a2c987c(local_208);
            uVar23 = FUN_fffffff00a2381c0(&local_f0);
            FUN_fffffff00a2cdfcc(uVar23,puVar30);
            if ((1L << (*(byte *)((long)puVar30 + 0x2a) & 0xf) & 0x3d60U) == 0) {
              *(int *)(lVar10 + 0x1c0) = *(int *)(lVar10 + 0x1c0) + 1;
              uVar45 = (ulong)*(uint *)(lVar10 + 0x4e8) | 0x30000000;
              if (DAT_fffffff00ad2d0c8 != 0) {
                FUN_fffffff00a1ea02c(&DAT_fffffff00ad2d0c0,lVar10,1);
                uVar45 = DAT_fffffff00ad2d0c8;
              }
              DAT_fffffff00ad2d0c8 = uVar45;
              if ((1L << (*(byte *)((long)puVar30 + 0x2a) & 0xf) & 0x3d60U) == 0) {
                FUN_fffffff00a2ef580(puVar30);
              }
              if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar10 + 0x4e8)) {
                DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
              }
              else {
                FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar10);
              }
            }
            FUN_fffffff00a29b220(local_208,local_a8);
            puVar38 = local_88;
          }
          FUN_fffffff00a2c7010(puVar38);
          uVar45 = local_78[0];
          if (iVar21 != 0x20008006) {
            if (iVar21 == 1) {
              if (lVar10 == 0) {
                uVar23 = 0;
              }
              else {
                uVar23 = *(undefined8 *)(lVar10 + 0x4e0);
              }
              FUN_fffffff00a69c288(uVar23,0x100000c,0);
              uVar24 = 1;
            }
            goto LAB_fffffff00a295ca8;
          }
          bVar11 = false;
          if ((*(byte *)(local_78[0] + 0xfb) & 1) != 0) {
            bVar11 = false;
            plVar31 = (long *)(_DAT_fffffff00acd8828 + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
            *plVar31 = *plVar31 + 1;
            if ((DAT_fffffff00ad58a20 & 0xfffffff7) != 0) {
              iVar21 = FUN_fffffff00a29b5c4(local_78[0]);
              if (iVar21 == 0) {
                uVar23 = 0;
              }
              else {
                uVar24 = uVar45 & 0x7ffffffffff;
                if ((uVar45 & 0x80000000000000) != 0) {
                  uVar24 = uVar45 | 0xffffff8000000000;
                }
                uVar23 = FUN_fffffff00a35921c(uVar24);
              }
              FUN_fffffff00a69ee5c(0x1b12004,uVar23,uVar34,uVar34,0);
              bVar11 = false;
            }
          }
          goto LAB_fffffff00a292f98;
        }
        if ((local_1a0 == local_88) && (local_1a8 == uVar41)) {
          if (puVar35 == (undefined8 *)0x0) {
            bVar33 = 1;
          }
          else {
            bVar33 = *(byte *)(puVar35[4] + 0x4c) ^ 1;
          }
          if ((((local_1ac ^ 0xffffffff) & 7) == 0 & bVar33) != 0) {
            local_94 = 0xffffffff;
          }
          uVar28 = local_94 & local_1ac;
          local_94 = uVar28;
          if (puVar30 == (undefined8 *)0x0) {
            uVar23 = FUN_fffffff00a2c987c(local_88);
LAB_fffffff00a293f98:
            if (local_1e4 == 0) goto LAB_fffffff00a2941f0;
LAB_fffffff00a293fa0:
            bVar12 = false;
            local_1e4 = 1;
          }
          else {
            FUN_fffffff00a2c987c(local_208);
            uVar23 = FUN_fffffff00a2381c0(&local_f0);
            if (((uVar28 >> 1 & 1) == 0) ||
               ((*(long *)(local_208 + 0xe) == lVar40 && (*(long *)(local_208 + 0x10) == lVar46))))
            goto LAB_fffffff00a293f98;
            if (puVar35 == (undefined8 *)0x0) {
              bVar33 = 1;
            }
            else {
              bVar33 = *(byte *)(puVar35[4] + 0x4c) ^ 1;
            }
            if ((((uVar28 ^ 0xffffffff) & 7) == 0) && ((bVar33 & 1) != 0)) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff00aa0c4f8
                        (
                        "%s: pmap %p vaddr 0x%llx prot 0x%x options 0x%x m%p obj %p copyobj %p @%s:%d"
                        );
            }
            local_94 = uVar28 & 0xfffffffd;
            uVar28 = local_94;
            if (local_1e4 != 0) goto LAB_fffffff00a293fa0;
LAB_fffffff00a2941f0:
            uVar24 = local_78[0];
            bVar12 = false;
            if (puVar30 == (undefined8 *)0x0) {
              local_1e4 = 0;
            }
            else {
              local_1e4 = 0;
              if ((*(uint *)(param_8 + 0x14) >> 8 & 1) == 0) {
                lVar40 = 0;
                if (*(uint *)((long)puVar30 + 0x1c) != 0) {
                  lVar40 = (ulong)*(uint *)((long)puVar30 + 0x1c) * 0x40 + -0x2400000000;
                }
                uVar23 = FUN_fffffff00a29b630(local_78[0],puVar38,lVar40);
                if ((int)uVar23 == 0) {
                  bVar12 = false;
                  local_1e4 = 0;
                }
                else {
                  DAT_fffffff00ad54d38 = DAT_fffffff00ad54d38 + 1;
                  lVar40 = FUN_fffffff00a25ee44();
                  if (*(long *)(lVar40 + 0x18) == 0) {
                    uVar23 = FUN_fffffff00a6acd88(DAT_fffffff007c5f108);
                    iVar21 = (int)uVar23;
                  }
                  else {
                    uVar23 = FUN_fffffff00a6acd88();
                    iVar21 = (int)uVar23;
                  }
                  if (iVar21 == 0) {
                    if (*(undefined8 **)(uVar24 + 0x58) == (undefined8 *)0x0) {
                      plVar31 = &DAT_fffffff00ad54d48;
                    }
                    else {
                      plVar31 = (long *)0xfffffff00ad54d40;
                      if (*(undefined8 **)(uVar24 + 0x58) != &DAT_fffffff00ad2cb90) {
                        plVar31 = &DAT_fffffff00ad54d48;
                      }
                    }
                    *plVar31 = *plVar31 + 1;
                    bVar12 = true;
                    local_1e4 = 1;
                  }
                  else {
                    bVar12 = true;
                    local_1e4 = 1;
                  }
                }
              }
            }
          }
          if (local_7c == 0) {
            if (bVar12) goto LAB_fffffff00a2942b4;
          }
          else {
            bVar11 = bVar12;
            if (uVar36 != (uVar28 | 2)) {
              bVar11 = true;
            }
            if (bVar11) {
LAB_fffffff00a2942b4:
              if (puVar30 == (undefined8 *)0x0) {
                FUN_fffffff00a29b220(puVar38,local_a8);
              }
              else {
                FUN_fffffff00a2cdfcc(uVar23,puVar30);
                if ((1L << (*(byte *)((long)puVar30 + 0x2a) & 0xf) & 0x3d60U) == 0) {
                  FUN_fffffff00a1ea97c(&DAT_fffffff00ad2d0c0);
                  if ((1L << (*(byte *)((long)puVar30 + 0x2a) & 0xf) & 0x3d60U) == 0) {
                    FUN_fffffff00a2ef580(puVar30);
                  }
                  if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar10 + 0x4e8)) {
                    DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
                  }
                  else {
                    FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar10);
                  }
                }
                FUN_fffffff00a29b220(local_208,local_a8);
                puVar38 = local_88;
              }
              FUN_fffffff00a2c7010(puVar38);
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
                  FUN_fffffff00a30dfb8(&local_160);
                }
                else if ((local_148 != 0) &&
                        (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                         ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                  FUN_fffffff00a309bc4();
                }
              }
              bVar11 = false;
              local_e8 = 0;
              goto LAB_fffffff00a292f98;
            }
          }
          if (puVar30 == (undefined8 *)0x0) {
            lVar29 = uVar34 - CONCAT44(uStack_fc,local_100);
            uVar32 = lVar29 - *(long *)(local_e8 + 0x10);
            if (0xffffffffffffefff < uVar32) {
              uVar32 = 0xfffffffffffff000;
            }
            uVar24 = *(long *)(local_e8 + 0x18) - lVar29;
            if (0xffffffffffffefff < uVar24) {
              uVar24 = 0xfffffffffffff000;
            }
            if ((param_5 == (undefined8 *)0x0) &&
               (param_5 = (undefined8 *)*puVar44, param_6 = uVar34, param_5 == (undefined8 *)0x0)) {
              param_5 = (undefined8 *)0x0;
            }
            uVar24 = FUN_fffffff00a33bf34
                               (param_5,param_6 - uVar32,
                                (lVar29 - (*(long *)(local_e8 + 0x10) + uVar32)) +
                                *(long *)(puVar38 + 0x16) +
                                (*(ulong *)(local_e8 + 0x30) & 0xfffffffffffff000),
                                uVar24 + uVar32 >> (uVar39 & 0x3f),uVar28,
                                *(undefined1 *)((long)puVar38 + 0xa6));
            FUN_fffffff00a29b220(puVar38,local_a8);
          }
          else {
            local_b9 = 0;
            puVar44 = puVar35;
            uVar24 = uVar34;
            if (param_5 != (undefined8 *)0x0) {
              puVar44 = param_5;
              uVar24 = param_6;
            }
            uVar41 = CONCAT62((int6)((ulong)puVar47 >> 0x10),(short)param_4);
            uVar24 = FUN_fffffff00a2970ac
                               (puVar30,puVar44,uVar24,lVar29,uVar45,uVar28,param_3,local_7c,uVar41,
                                param_8,&local_b9,&local_b0,in_stack_fffffffffffffd20,&local_161);
            uVar22 = 0xb;
            if (!(bool)(bVar12 & local_b0 == 3)) {
              uVar22 = local_b0;
            }
            uVar50 = 0x1320008;
            if ((*(byte *)((long)local_208 + 0x75) >> 4 & 1) == 0) {
              uVar50 = 0x1320010;
              if ((*(byte *)((long)local_208 + 0xa9) & 1) != 0) {
                uVar50 = 0x1320014;
              }
            }
            uVar45 = uVar24;
            bVar33 = local_b9;
            if ((DAT_fffffff00ad58a20 & 0xfffffff7) != 0) {
              iVar21 = *(int *)(param_8 + 2);
              uVar26 = puVar30[4];
              uVar23 = FUN_fffffff00a6e470c();
              uVar45 = FUN_fffffff00a69ee5c
                                 (uVar50,param_2,uVar22 | uVar27 << 8 | iVar21 << 0x10,uVar26,uVar23
                                 );
              bVar33 = local_b9;
            }
            local_b9 = bVar33;
            if ((((int)uVar24 != 0) || ((local_161 & 1) != 0)) || ((bVar33 & 1) != 0)) {
              FUN_fffffff00a2cdfcc(uVar45,puVar30);
              FUN_fffffff00a29b220(local_208,local_a8);
              FUN_fffffff00a2c7010(puVar38);
              if ((bVar33 & 1) != 0) {
                uVar24 = uVar34;
                if (param_5 != (undefined8 *)0x0) {
                  puVar35 = param_5;
                  uVar24 = param_6;
                }
                FUN_fffffff00a33363c(puVar35,uVar24,0,0,0,0,0,2,uVar41 & 0xffffffffffffff00);
                uVar24 = 0;
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
                  FUN_fffffff00a30dfb8(&local_160);
                }
                else if ((local_148 != 0) &&
                        (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                         ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
                  FUN_fffffff00a309bc4();
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
              if ((int)uVar24 != 0) {
LAB_fffffff00a295ca8:
                *(ushort *)(lVar10 + 200) = uVar8 & 3 | *(ushort *)(lVar10 + 200) & 0xfffc;
                if (puVar43 != (undefined4 *)0x0) {
                  FUN_fffffff00a2c7010(puVar43);
                  DAT_fffffff00ad54db8 = DAT_fffffff00ad54db8 + 1;
                }
                uVar4 = local_b0;
                lVar29 = (long)(int)local_b0;
                if ((local_b0 < 0xb) && ((1 << (ulong)(local_b0 & 0x1f) & 0x580U) != 0)) {
                  FUN_fffffff00a3f2344(1);
                }
                else if (((int)uVar24 == 0) &&
                        (((local_b0 & 0xfffffffd) != 4 &&
                         (iVar21 = FUN_fffffff00a29b740(1), iVar21 != 0)))) {
                  FUN_fffffff00a29b9f0();
                }
                puVar43 = local_c8;
                if (local_c8 != (undefined4 *)0x0) {
                  FUN_fffffff00a27dd20(local_d0,local_d8,local_d8 + 0x4000);
                  FUN_fffffff00a2c987c(puVar43);
                  uVar8 = *(ushort *)(puVar43 + 0x1b);
                  uVar27 = uVar8 - 1;
                  *(short *)(puVar43 + 0x1b) = (short)uVar27;
                  if (0xffff < uVar27) {
                    /* WARNING: Subroutine does not return */
                    FUN_fffffff00aa0c4f8("vm_object_paging_end(%p): underflow\n @%s:%d");
                  }
                  uVar27 = uVar27 & 0xffff;
                  if (((*(byte *)((long)puVar43 + 0x75) >> 4 & 1) == 0) &&
                     (((*(byte *)((long)puVar43 + 0xa9) & (uint)uVar8 == (uint)DAT_fffffff007bc0ab0)
                       != 0 || (DAT_fffffff007bc0ab2 == uVar8)))) {
                    FUN_fffffff00a2cfbfc(puVar43,6);
                    uVar27 = (uint)*(ushort *)(puVar43 + 0x1b);
                  }
                  if (uVar27 == 0) {
                    uVar27 = puVar43[0x1d];
                    if ((uVar27 >> 5 & 1) != 0) {
                      FUN_fffffff00a20dce4((long)puVar43 + 5,0,0);
                      uVar27 = puVar43[0x1d];
                    }
                    puVar43[0x1d] = uVar27 & 0xffffffdf;
                    if (puVar43[0x1c] == 0) {
                      FUN_fffffff00a2cfbfc(puVar43,2);
                    }
                  }
                  FUN_fffffff00a1eec04(puVar43 + 2);
                }
                if (iVar6 == 1) {
                  FUN_fffffff00a29bab0(lVar10,local_278,uVar42,lVar29);
                }
                if ((DAT_fffffff00ad58a20 & 0xfffffff7) == 0) {
                  return uVar24;
                }
                lVar10 = 0xb;
                if (!(bool)(bVar12 & uVar4 == 3)) {
                  lVar10 = lVar29;
                }
                FUN_fffffff00a69ee5c(0x130000a,uVar42 >> 0x20,uVar42,(long)(int)uVar24,lVar10);
                return uVar24;
              }
              goto LAB_fffffff00a292f98;
            }
            if (param_7 != (int *)0x0) {
              if ((puVar30 < DAT_fffffff007be4010) || (DAT_fffffff007be4008 <= puVar30)) {
                iVar21 = *(int *)((long)puVar30 + 0x3c);
              }
              else {
                iVar21 = DAT_fffffff007be4000 +
                         (int)((ulong)((long)puVar30 - (long)DAT_fffffff007be4010) >> 6);
              }
              *param_7 = iVar21;
              if ((uVar28 >> 1 & 1) != 0) {
                *(byte *)((long)puVar30 + 0x2d) = *(byte *)((long)puVar30 + 0x2d) | 1;
              }
            }
            if (((iVar6 == 1) && ((*(byte *)((long)puVar30 + 0x2b) >> 4 & 1) == 0)) &&
               (_DAT_fffffff00acd88d8 != 0)) {
              if (DAT_fffffff00ad2d0c8 == 0) {
                bVar33 = *(byte *)((long)puVar30 + 0x2b);
                DAT_fffffff00ad2d0c8 = (ulong)*(uint *)(lVar10 + 0x4e8);
              }
              else {
                uVar45 = FUN_fffffff00a1ea02c(&DAT_fffffff00ad2d0c0,lVar10,0);
                bVar33 = *(byte *)((long)puVar30 + 0x2b);
              }
              if ((bVar33 >> 4 & 1) == 0) {
                *(byte *)((long)puVar30 + 0x2b) = bVar33 | 0x10;
                lVar29 = (ulong)DAT_fffffff00ad54bfc + 1;
                DAT_fffffff00ad54bfc = (uint)lVar29;
                if (lVar29 != lVar29 * 0x80000000 >> 0x1f) {
                    /* WARNING: Does not return */
                  pcVar15 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a296838);
                  (*pcVar15)();
                }
              }
              if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar10 + 0x4e8)) {
                DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
              }
              else {
                uVar45 = FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar10);
              }
            }
            if (((*(byte *)((long)local_208 + 0x75) >> 4 & 1) == 0) && ((uVar36 >> 1 & 1) != 0)) {
              uVar45 = FUN_fffffff00a29b6f8(local_208);
              local_d0 = *(undefined8 *)(local_208 + 0x14);
              local_d8 = puVar30[4] + *(long *)(local_208 + 0x18);
              local_c8 = local_208;
            }
            FUN_fffffff00a2cdfcc(uVar45,puVar30);
            FUN_fffffff00a29b220(local_208,local_a8);
            uVar24 = 0;
            puVar38 = local_88;
          }
          FUN_fffffff00a2c7010(puVar38);
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
              FUN_fffffff00a30dfb8(&local_160);
            }
            else if ((local_148 != 0) &&
                    (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                     ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
              FUN_fffffff00a309bc4();
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
          goto LAB_fffffff00a295ca8;
        }
        if (puVar30 == (undefined8 *)0x0) {
          FUN_fffffff00a2c987c(local_88);
          local_208 = puVar38;
        }
        else {
          FUN_fffffff00a2c987c(local_208);
          uVar23 = FUN_fffffff00a2381c0(&local_f0);
          FUN_fffffff00a2cdfcc(uVar23,puVar30);
          if ((1L << (*(byte *)((long)puVar30 + 0x2a) & 0xf) & 0x3d60U) == 0) {
            FUN_fffffff00a1ea97c(&DAT_fffffff00ad2d0c0);
            if ((1L << (*(byte *)((long)puVar30 + 0x2a) & 0xf) & 0x3d60U) == 0) {
              FUN_fffffff00a2ef580(puVar30);
            }
            if ((int)DAT_fffffff00ad2d0c8 == *(int *)(lVar10 + 0x4e8)) {
              DAT_fffffff00ad2d0c8 = CONCAT44(DAT_fffffff00ad2d0c8._4_4_,in_wzr);
            }
            else {
              FUN_fffffff00a1eab60(&DAT_fffffff00ad2d0c0,lVar10);
            }
          }
        }
        FUN_fffffff00a29b220(local_208,local_a8);
        FUN_fffffff00a2c7010(puVar38);
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
            FUN_fffffff00a30dfb8(&local_160);
          }
          else if ((local_148 != 0) &&
                  (((~*(uint *)(local_148 + 0x28) & 3) != 0 ||
                   ((*(uint *)(local_148 + 0x24) & 1) == 0)))) {
            FUN_fffffff00a309bc4();
          }
        }
        bVar11 = false;
        local_e8 = 0;
        goto LAB_fffffff00a292f98;
      }
      if (-1 < (char)param_8[0x14]) {
        FUN_fffffff00a2c7010(puVar38);
        local_88 = (undefined4 *)0x0;
        uVar4 = 10;
        if (local_ac != 0) {
          uVar4 = local_ac;
        }
        uVar24 = (ulong)uVar4;
        goto LAB_fffffff00a295ca8;
      }
      DAT_fffffff00ad54da0 = DAT_fffffff00ad54da0 + 1;
      bVar11 = true;
      puVar43 = puVar38;
      local_1f0 = uVar24;
      goto LAB_fffffff00a292f98;
    }
    if ((DAT_fffffff00ad58a20 & 0xfffffff7) == 0) {
      if (lVar10 != 0) goto LAB_fffffff00a292e34;
LAB_fffffff00a2963d0:
      uVar23 = 0;
    }
    else {
      FUN_fffffff00a69ee5c(0x130000a,uVar42 >> 0x20,uVar42,5,0);
      if (lVar10 == 0) goto LAB_fffffff00a2963d0;
LAB_fffffff00a292e34:
      uVar23 = *(undefined8 *)(lVar10 + 0x4e0);
    }
    uVar26 = 0x10000e0;
    goto LAB_fffffff00a2963e0;
  }
  if ((DAT_fffffff00ad58a20 & 0xfffffff7) == 0) {
    if (lVar10 != 0) goto LAB_fffffff00a292e0c;
LAB_fffffff00a2961dc:
    uVar23 = 0;
  }
  else {
    FUN_fffffff00a69ee5c(0x130000a,uVar42 >> 0x20,uVar42,5,0);
    if (lVar10 == 0) goto LAB_fffffff00a2961dc;
LAB_fffffff00a292e0c:
    uVar23 = *(undefined8 *)(lVar10 + 0x4e0);
  }
  uVar26 = 0x1000030;
LAB_fffffff00a2963e0:
  FUN_fffffff00a69c288(uVar23,uVar26,0);
  return 5;
code_r0xfffffff00a293710:
  if ((((*(byte *)(puVar38 + 0x2a) & 1) != 0) && (*(byte *)((long)puVar35 + 0x2e) < 0xf0)) &&
     ((((*(byte *)((long)puVar35 + 0x2e) ^ 0xff) & 0xf) != 0 ||
      ((*(byte *)((long)puVar35 + 0x2d) >> 6 & 1) != 0)))) goto LAB_fffffff00a293630;
  local_1d0 = 1;
LAB_fffffff00a2940e4:
  puVar44 = (undefined8 *)FUN_fffffff00a2f01d8(uVar28 & 0x10000);
  uVar51 = (undefined4)((ulong)in_stack_fffffffffffffd30 >> 0x20);
  if (puVar44 == (undefined8 *)0x0) goto LAB_fffffff00a2937ec;
  FUN_fffffff00a2f2558(puVar35);
  FUN_fffffff00a2ecbf4(puVar44,puVar14,local_90 & 0xffffffffffffc000,0,0,0);
  *(byte *)((long)puVar44 + 0x2d) = *(byte *)((long)puVar44 + 0x2d) | 1;
  if (((1 < (uint)puVar14[10]) && ((*(byte *)((long)puVar35 + 0x2d) >> 4 & 1) != 0)) ||
     ((uVar24 != 0 && (*(byte *)(uVar24 + 0x2c) < 0xe)))) {
    if ((puVar35 < DAT_fffffff007be4010) || (DAT_fffffff007be4008 <= puVar35)) {
      iVar20 = *(int *)((long)puVar35 + 0x3c);
    }
    else {
      iVar20 = DAT_fffffff007be4000 +
               (int)((ulong)((long)puVar35 - (long)DAT_fffffff007be4010) >> 6);
    }
    FUN_fffffff00a33f500(iVar20);
  }
  if ((*(byte *)((long)puVar35 + 0x2d) >> 3 & 1) != 0) {
    plVar31 = (long *)(*(long *)(lVar19 + 0x388) + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
    *plVar31 = *plVar31 + 1;
    if ((puVar35 < DAT_fffffff007be4010) || (DAT_fffffff007be4008 <= puVar35)) {
      iVar20 = *(int *)((long)puVar35 + 0x3c);
    }
    else {
      iVar20 = DAT_fffffff007be4000 +
               (int)((ulong)((long)puVar35 - (long)DAT_fffffff007be4010) >> 6);
    }
    FUN_fffffff00a33f5d0(iVar20);
    uVar24 = (ulong)*(byte *)((long)puVar35 + 0x2d);
    if ((*(byte *)((long)puVar35 + 0x2d) >> 3 & 1) != 0) {
      lVar40 = 0;
      if (*(uint *)((long)puVar35 + 0x1c) != 0) {
        lVar40 = (ulong)*(uint *)((long)puVar35 + 0x1c) * 0x40 + -0x2400000000;
      }
      *(int *)(lVar40 + 0xa0) = *(int *)(lVar40 + 0xa0) + 1;
      *(byte *)((long)puVar35 + 0x2d) = *(byte *)((long)puVar35 + 0x2d) & 0xf7;
      puVar3 = (ulong *)(_DAT_fffffff00acd88c0 + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
      uVar24 = *puVar3;
      *puVar3 = uVar24 + 1;
    }
    FUN_fffffff00a33f77c(uVar24,iVar20);
    FUN_fffffff00a297548(puVar38,uVar41,*(undefined4 *)(param_8 + 8));
  }
  if (((*(byte *)((long)puVar38 + 0x75) >> 4 & 1) == 0) && (puVar38[0x1a] == 2)) {
    if (*(undefined4 **)(puVar38 + 0xe) == local_88) {
      FUN_fffffff00a1eec04(puVar38 + 2);
    }
    else {
      if (*(undefined4 **)(puVar38 + 0xe) != *(undefined4 **)(local_88 + 0x12))
      goto LAB_fffffff00a294728;
      iVar20 = (*(undefined4 **)(local_88 + 0x12))[0xb];
      FUN_fffffff00a1eec04(puVar38 + 2);
      if (iVar20 != 0) {
        local_264 = 1;
        goto LAB_fffffff00a294740;
      }
    }
    local_264 = 0;
    DAT_fffffff00ad05fb0 = DAT_fffffff00ad05fb0 + 1;
  }
  else {
LAB_fffffff00a294728:
    FUN_fffffff00a1eec04(puVar38 + 2);
    local_264 = 1;
  }
LAB_fffffff00a294740:
  DAT_fffffff00ad05fa8 = DAT_fffffff00ad05fa8 + 1;
  local_b0 = 3;
  plVar31 = (long *)(_DAT_fffffff00acce4a0 + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
  *plVar31 = *plVar31 + 1;
  plVar31 = (long *)(*(long *)(lVar19 + 0x390) + (ulong)*(ushort *)(lVar10 + 0x1b0) * 0x4000);
  *plVar31 = *plVar31 + 1;
  puVar35 = puVar44;
  puVar25 = (undefined4 *)0x0;
  puVar37 = puVar14;
  puVar38 = local_88;
  goto LAB_fffffff00a294c70;
}

