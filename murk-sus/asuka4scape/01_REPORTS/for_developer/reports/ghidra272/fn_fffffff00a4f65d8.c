// FUN_fffffff00a4f65d8 @ fffffff00a4f65d8 size=9880

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_fffffff00a4f65d8
               (long param_1,long param_2,long param_3,long param_4,int param_5,undefined4 *param_6,
               int *param_7,undefined4 *param_8,uint *param_9)

{
  undefined8 *puVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint *puVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  int *piVar25;
  bool bVar26;
  undefined8 uVar27;
  code *pcVar28;
  bool bVar29;
  bool bVar30;
  byte bVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  uint uVar36;
  undefined8 uVar37;
  ulong uVar38;
  ulong uVar39;
  undefined4 uVar40;
  long lVar41;
  ulong uVar42;
  uint uVar43;
  long lVar44;
  ulong uVar45;
  uint uVar46;
  uint uVar47;
  undefined4 in_stack_fffffffffffffc80;
  ulong in_stack_fffffffffffffc88;
  ulong in_stack_fffffffffffffc90;
  undefined8 in_stack_fffffffffffffcd8;
  undefined4 uVar48;
  uint local_258;
  long local_248;
  undefined8 local_240;
  long local_238;
  int local_22c;
  undefined8 local_228;
  undefined8 local_220;
  undefined8 uStack_218;
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 local_200;
  undefined8 uStack_1f8;
  undefined8 uStack_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  long local_198;
  undefined8 local_190;
  ulong local_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  ulong local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  ulong local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  ulong local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  long local_78;
  
  iVar34 = DAT_fffffff00adcd97c;
  uVar48 = (undefined4)((ulong)in_stack_fffffffffffffcd8 >> 0x20);
  local_78 = DAT_fffffff00ad30000;
  if (param_4 == 0) {
    local_258 = 0;
  }
  else {
    local_258 = (uint)*(ushort *)(param_4 + 0xcc);
  }
  local_190 = 0;
  uStack_1a8 = 0;
  local_1b0 = 0;
  local_198 = 0;
  uStack_1a0 = 0;
  uStack_1b8 = 0;
  local_1c0 = 0;
  uStack_1d8 = 0;
  local_1e0 = 0;
  uStack_1c8 = 0;
  uStack_1d0 = 0;
  uStack_1f8 = 0;
  local_200 = 0;
  uStack_1e8 = 0;
  uStack_1f0 = 0;
  uStack_218 = 0;
  local_220 = 0;
  uStack_208 = 0;
  uStack_210 = 0;
  local_228 = 0;
  local_22c = 0;
  local_240 = 0;
  local_238 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  uStack_a8 = 0;
  uStack_b0 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = 0;
  }
  if (param_7 != (int *)0x0) {
    *param_7 = 0;
  }
  if (param_9 != (uint *)0x0) {
    *param_9 = 0;
  }
  if (param_1 == 0) {
LAB_fffffff00a4f6994:
    uVar46 = 0;
    uVar43 = 1;
    goto LAB_fffffff00a4f69c8;
  }
  lVar41 = *(long *)(param_1 + 0xe8);
  uVar42 = *(ulong *)(param_1 + 0x40);
  if (DAT_fffffff00ad7ce04 == 0) {
    iVar32 = 0;
  }
  else {
    lVar44 = *(long *)(uVar42 + 0x208);
    iVar32 = FUN_fffffff00aa39574(lVar44,0x271c);
    if (((iVar32 == 0) &&
        ((*(int *)(lVar44 + 0x18) == 0 ||
         (iVar32 = FUN_fffffff00aa39798(lVar44,0x271c), iVar32 == 0)))) ||
       ((iVar33 = FUN_fffffff00aa39574(lVar44,0x271d), iVar32 = DAT_fffffff00ad7ce04, iVar33 == 0 &&
        ((*(int *)(lVar44 + 0x18) == 0 ||
         (iVar33 = FUN_fffffff00aa39798(lVar44,0x271d), iVar32 = DAT_fffffff00ad7ce04, iVar33 == 0))
        )))) {
      iVar32 = 0;
    }
  }
  if ((DAT_fffffff00ad7ce0c == 0) &&
     ((DAT_fffffff00adcd960 == 0 ||
      (((*(byte *)(param_1 + 0x94) >> 2 & 1) == 0 && (DAT_fffffff00adcd968 == 0)))))) {
    if (DAT_fffffff00ad7cdf8 == 0 && iVar32 == 0) goto LAB_fffffff00a4f6994;
    iVar34 = FUN_fffffff00a4f1ebc(param_2,param_3);
    if ((iVar34 == 3) || (iVar34 == 0)) {
LAB_fffffff00a4f6984:
      uVar46 = 0;
      uVar43 = 0;
      goto LAB_fffffff00a4f69c8;
    }
LAB_fffffff00a4f7fe4:
    uVar46 = 0;
    uVar43 = 1;
    goto LAB_fffffff00a4f69c8;
  }
  if ((((*(ushort *)(*(long *)(param_1 + 0x40) + 0x16) & 0xe) != 0) ||
      (param_2 == 0 && param_3 == 0)) && (*(int *)(param_1 + 0x1a4) != 0)) {
    bVar30 = true;
    uVar40 = 1;
    if (param_4 != 0) {
      uVar40 = 2;
    }
    in_stack_fffffffffffffc88 = CONCAT71((int7)(in_stack_fffffffffffffc88 >> 8),1);
    uVar38 = CONCAT44(local_258,in_stack_fffffffffffffc80) & 0xffffffffffffff00;
    FUN_fffffff00a4f204c
              (param_1,param_2,param_3,0,uVar40,iVar32,&local_238,&local_220,uVar38,
               in_stack_fffffffffffffc88);
    in_stack_fffffffffffffc80 = (undefined4)uVar38;
    piVar2 = (int *)(param_1 + 0x1ac);
    if (local_198 != 0) {
      piVar2 = (int *)(local_198 + 0xac);
    }
    iVar33 = *piVar2;
    if (((DAT_fffffff00ad7e490 & 1) != 0) && (DAT_fffffff00ad7ce0c != 0)) {
      lVar44 = param_4;
      if ((param_4 == 0) && (lVar41 != 0)) {
        lVar44 = *(long *)(lVar41 + 0x88);
      }
      if ((lVar44 == 0) || ((*(byte *)(lVar44 + 0xd9) >> 6 & 1) == 0)) {
        bVar30 = true;
      }
      else {
        uVar43 = *(uint *)(param_1 + 0x94) & 0x10080;
        bVar30 = uVar43 != 0;
        if ((1 < DAT_fffffff00ad7e494) && (uVar43 == 0)) {
          FUN_fffffff00a4ebdcc(lVar44,0);
          bVar30 = false;
        }
      }
    }
    if (iVar33 == DAT_fffffff00adcda90) {
      if (*(int *)(param_1 + 0x1c8) != 0) {
        FUN_fffffff00a228180(&DAT_fffffff00adcd940);
        bVar31 = FUN_fffffff00a4eb9f0
                           (lVar41,param_4,0,0,*(undefined4 *)(param_1 + 0x1c8),(long)&local_228 + 4
                            ,0);
        bVar30 = (bool)(bVar31 & bVar30);
        FUN_fffffff00a228d30(&DAT_fffffff00adcd940);
      }
      if (iVar34 == 0) {
        bVar26 = true;
      }
      else {
        FUN_fffffff00a4f204c
                  (param_1,param_2,param_3,0,uVar40,iVar32,&local_238,&local_220,
                   CONCAT44(local_258,in_stack_fffffffffffffc80) & 0xffffffffffffff00,
                   in_stack_fffffffffffffc88 & 0xffffffffffffff00);
        if (DAT_fffffff00adcd990 == 0) {
          if (DAT_fffffff00adcd97c != 0) {
            if ((((DAT_fffffff00adcd988 != 0) &&
                 (((int)local_220 == 0 || ((int)local_220 == DAT_fffffff00adcd988)))) ||
                ((DAT_fffffff00adcd984 != 0 && (DAT_fffffff00adcd984 == uStack_1c8._4_2_)))) ||
               ((DAT_fffffff00adcd98c != 0 && ((int)uStack_1d8 == DAT_fffffff00adcd98c))))
            goto LAB_fffffff00a4f6c20;
            if (DAT_fffffff00adcd980 != 0) goto LAB_fffffff00a4f6c00;
            goto LAB_fffffff00a4f6c34;
          }
        }
        else if (DAT_fffffff00adcd97c != 0) {
          if (((((DAT_fffffff00adcd988 == 0) || ((int)local_220 == 0)) ||
               ((int)local_220 == DAT_fffffff00adcd988)) &&
              ((DAT_fffffff00adcd984 == 0 || (DAT_fffffff00adcd984 == uStack_1c8._4_2_)))) &&
             ((DAT_fffffff00adcd98c == 0 || ((int)uStack_1d8 == DAT_fffffff00adcd98c)))) {
            if (DAT_fffffff00adcd980 != 0) {
LAB_fffffff00a4f6c00:
              if ((DAT_fffffff00adcd980 !=
                   ((uint)(uStack_210._2_2_ >> 8) | (uStack_210._2_2_ & 0xff00ff) << 8)) &&
                 (DAT_fffffff00adcd980 !=
                  ((uint)(uStack_1f8._6_2_ >> 8) | (uStack_1f8._6_2_ & 0xff00ff) << 8)))
              goto LAB_fffffff00a4f6c34;
            }
LAB_fffffff00a4f6c20:
            bVar26 = false;
          }
          else {
LAB_fffffff00a4f6c34:
            bVar26 = true;
          }
          goto LAB_fffffff00a4f6c38;
        }
        bVar26 = true;
      }
LAB_fffffff00a4f6c38:
      uVar27 = DAT_fffffff00ad7ce40;
      iVar34 = *(int *)(param_1 + 0x1b8);
      uVar43 = *(uint *)(param_1 + 0x1bc);
      if (local_198 == 0) {
        bVar29 = false;
      }
      else {
        iVar32 = *(int *)(local_198 + 0xb8);
        bVar29 = false;
        if (iVar32 != 0) {
          bVar29 = iVar34 != iVar32;
          if (bVar29) {
            iVar34 = iVar32;
          }
          bVar29 = uVar43 != *(uint *)(local_198 + 0xbc) || bVar29;
          uVar43 = *(uint *)(local_198 + 0xbc);
        }
      }
      bVar4 = false;
      if (iVar34 - 5U < 0xfffffffe) {
        bVar4 = bVar30;
      }
      if ((bVar4 == true) && (((param_4 == 0 || (iVar34 != 6)) || (uVar43 == local_258)))) {
        bVar29 = !bVar29;
        puVar6 = (undefined4 *)(local_198 + 0xb0);
        if (bVar29) {
          puVar6 = (undefined4 *)(param_1 + 0x1a4);
        }
        puVar7 = (undefined4 *)(local_198 + 0xb4);
        if (bVar29) {
          puVar7 = (undefined4 *)(param_1 + 0x1a8);
        }
        uVar48 = *puVar7;
        puVar8 = (uint *)(local_198 + 0xbc);
        if (bVar29) {
          puVar8 = (uint *)(param_1 + 0x1bc);
        }
        uVar46 = *puVar8;
        if (param_6 != (undefined4 *)0x0) {
          *param_6 = *puVar6;
        }
        if (param_8 != (undefined4 *)0x0) {
          *param_8 = uVar48;
        }
        if (param_7 != (int *)0x0) {
          *param_7 = *(int *)(param_1 + 0x1c8);
        }
        uVar27 = DAT_fffffff00ad7ce10;
        if (iVar34 != 1) {
          uVar46 = 0;
        }
        if (bVar26) {
          uVar43 = 1;
        }
        else {
          uStack_d8 = 0;
          local_e0 = 0;
          uStack_c8 = 0;
          local_d0 = 0;
          uStack_f8 = 0;
          local_100 = 0;
          uStack_e8 = 0;
          local_f0 = 0;
          uStack_118 = 0;
          local_120 = 0;
          uStack_108 = 0;
          local_110 = 0;
          uStack_138 = 0;
          local_140 = 0;
          uStack_128 = 0;
          local_130 = 0;
          iVar34 = FUN_fffffff00a4ecdf8(uVar42);
          uVar38 = uVar42 | 0xffffff8000000000;
          if (iVar34 == 0) {
            if ((((uVar42 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar38)) &&
               (uVar38 < 0xfffffffc00000000)) {
              FUN_fffffff00a1d12d4();
            }
          }
          else {
            uVar45 = uVar42 & 0x7ffffffffff;
            if ((uVar42 & 0x80000000000000) != 0) {
              uVar45 = uVar38;
            }
            FUN_fffffff00a396010(uVar45);
          }
          FUN_fffffff00a4eb1ec(&uStack_210,&local_100);
          FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_140);
          uVar43 = 1;
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar27,0x10,
                     "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d> <input ifindex %d> <allowed_to_receive %d><pf_tag %X pass_flags %X><gen_count inp %d current %d>\n"
                    );
        }
        goto LAB_fffffff00a4f69c8;
      }
      if (bVar26) {
        uVar46 = 0;
        uVar43 = 0;
        goto LAB_fffffff00a4f69c8;
      }
      uVar45 = uVar42 | 0xffffff8000000000;
      uVar38 = uVar45;
      if ((uVar42 & 0x80000000000000) == 0) {
        uVar38 = uVar42 & 0x7ffffffffff;
      }
      if (((uVar38 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar38) ||
          (DAT_fffffff007c6a378 <= uVar38 && uVar38 < DAT_fffffff007c6a380)) ||
         ((DAT_fffffff007c6a3a0 <= uVar38 && (uVar38 < DAT_fffffff007c6a3a8)))) {
        FUN_fffffff00a396010(uVar38);
      }
      else if ((((uVar42 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar45)) &&
              (uVar45 < 0xfffffffc00000000)) {
        FUN_fffffff00a1d12d4(uVar45);
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar27,0x10,
                 "%s: DATA-TRACE: <SOCKET - DATA PATH %llx>: START - RESULT - CACHED DROP - <route_allowed %d><result %d paramater %d><verifyifindex %d>\n"
                );
      uVar27 = DAT_fffffff00ad7ce10;
      if (((uVar38 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar38) ||
          (DAT_fffffff007c6a378 <= uVar38 && uVar38 < DAT_fffffff007c6a380)) ||
         ((DAT_fffffff007c6a3a0 <= uVar38 && (uVar38 < DAT_fffffff007c6a3a8)))) {
        FUN_fffffff00a396010(uVar38);
      }
      else if ((((uVar42 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar45)) &&
              (uVar45 < 0xfffffffc00000000)) {
        FUN_fffffff00a1d12d4(uVar45);
      }
      uStack_f8 = 0;
      local_100 = 0;
      uStack_e8 = 0;
      local_f0 = 0;
      uStack_d8 = 0;
      local_e0 = 0;
      uStack_c8 = 0;
      local_d0 = 0;
      if (uStack_210._1_1_ == '\x02') {
        lVar41 = 4;
        uVar37 = 2;
LAB_fffffff00a4f6fd4:
        FUN_fffffff00a8dd3c8(uVar37,(long)&uStack_210 + lVar41,&local_100,0x40);
        auVar9[1] = -((char)(local_100 >> 8) == '\0');
        auVar9[0] = -((char)local_100 == '\0');
        auVar9[2] = -((char)(local_100 >> 0x10) == '\0');
        auVar9[3] = -((char)(local_100 >> 0x18) == '\0');
        auVar9[4] = -((char)(local_100 >> 0x20) == '\0');
        auVar9[5] = -((char)(local_100 >> 0x28) == '\0');
        auVar9[6] = -((char)(local_100 >> 0x30) == '\0');
        auVar9[7] = -((char)(local_100 >> 0x38) == '\0');
        auVar9[8] = -((char)uStack_f8 == '\0');
        auVar9[9] = -((char)((ulong)uStack_f8 >> 8) == '\0');
        auVar9[10] = -((char)((ulong)uStack_f8 >> 0x10) == '\0');
        auVar9[0xb] = -((char)((ulong)uStack_f8 >> 0x18) == '\0');
        auVar9[0xc] = -((char)((ulong)uStack_f8 >> 0x20) == '\0');
        auVar9[0xd] = -((char)((ulong)uStack_f8 >> 0x28) == '\0');
        auVar9[0xe] = -((char)((ulong)uStack_f8 >> 0x30) == '\0');
        auVar9[0xf] = -((char)((ulong)uStack_f8 >> 0x38) == '\0');
        bVar31 = NEON_umaxv(auVar9,1);
        if (((((bVar31 & 1) == 0) &&
             (auVar10[1] = -((char)((ulong)local_f0 >> 8) == '\0'),
             auVar10[0] = -((char)local_f0 == '\0'),
             auVar10[2] = -((char)((ulong)local_f0 >> 0x10) == '\0'),
             auVar10[3] = -((char)((ulong)local_f0 >> 0x18) == '\0'),
             auVar10[4] = -((char)((ulong)local_f0 >> 0x20) == '\0'),
             auVar10[5] = -((char)((ulong)local_f0 >> 0x28) == '\0'),
             auVar10[6] = -((char)((ulong)local_f0 >> 0x30) == '\0'),
             auVar10[7] = -((char)((ulong)local_f0 >> 0x38) == '\0'),
             auVar10[8] = -((char)uStack_e8 == '\0'),
             auVar10[9] = -((char)((ulong)uStack_e8 >> 8) == '\0'),
             auVar10[10] = -((char)((ulong)uStack_e8 >> 0x10) == '\0'),
             auVar10[0xb] = -((char)((ulong)uStack_e8 >> 0x18) == '\0'),
             auVar10[0xc] = -((char)((ulong)uStack_e8 >> 0x20) == '\0'),
             auVar10[0xd] = -((char)((ulong)uStack_e8 >> 0x28) == '\0'),
             auVar10[0xe] = -((char)((ulong)uStack_e8 >> 0x30) == '\0'),
             auVar10[0xf] = -((char)((ulong)uStack_e8 >> 0x38) == '\0'),
             bVar31 = NEON_umaxv(auVar10,1), (bVar31 & 1) == 0)) &&
            (auVar11[1] = -((char)((ulong)local_e0 >> 8) == '\0'),
            auVar11[0] = -((char)local_e0 == '\0'),
            auVar11[2] = -((char)((ulong)local_e0 >> 0x10) == '\0'),
            auVar11[3] = -((char)((ulong)local_e0 >> 0x18) == '\0'),
            auVar11[4] = -((char)((ulong)local_e0 >> 0x20) == '\0'),
            auVar11[5] = -((char)((ulong)local_e0 >> 0x28) == '\0'),
            auVar11[6] = -((char)((ulong)local_e0 >> 0x30) == '\0'),
            auVar11[7] = -((char)((ulong)local_e0 >> 0x38) == '\0'),
            auVar11[8] = -((char)uStack_d8 == '\0'),
            auVar11[9] = -((char)((ulong)uStack_d8 >> 8) == '\0'),
            auVar11[10] = -((char)((ulong)uStack_d8 >> 0x10) == '\0'),
            auVar11[0xb] = -((char)((ulong)uStack_d8 >> 0x18) == '\0'),
            auVar11[0xc] = -((char)((ulong)uStack_d8 >> 0x20) == '\0'),
            auVar11[0xd] = -((char)((ulong)uStack_d8 >> 0x28) == '\0'),
            auVar11[0xe] = -((char)((ulong)uStack_d8 >> 0x30) == '\0'),
            auVar11[0xf] = -((char)((ulong)uStack_d8 >> 0x38) == '\0'),
            bVar31 = NEON_umaxv(auVar11,1), (bVar31 & 1) == 0)) &&
           (auVar12[1] = -((char)((ulong)local_d0 >> 8) == '\0'),
           auVar12[0] = -((char)local_d0 == '\0'),
           auVar12[2] = -((char)((ulong)local_d0 >> 0x10) == '\0'),
           auVar12[3] = -((char)((ulong)local_d0 >> 0x18) == '\0'),
           auVar12[4] = -((char)((ulong)local_d0 >> 0x20) == '\0'),
           auVar12[5] = -((char)((ulong)local_d0 >> 0x28) == '\0'),
           auVar12[6] = -((char)((ulong)local_d0 >> 0x30) == '\0'),
           auVar12[7] = -((char)((ulong)local_d0 >> 0x38) == '\0'),
           auVar12[8] = -((char)uStack_c8 == '\0'),
           auVar12[9] = -((char)((ulong)uStack_c8 >> 8) == '\0'),
           auVar12[10] = -((char)((ulong)uStack_c8 >> 0x10) == '\0'),
           auVar12[0xb] = -((char)((ulong)uStack_c8 >> 0x18) == '\0'),
           auVar12[0xc] = -((char)((ulong)uStack_c8 >> 0x20) == '\0'),
           auVar12[0xd] = -((char)((ulong)uStack_c8 >> 0x28) == '\0'),
           auVar12[0xe] = -((char)((ulong)uStack_c8 >> 0x30) == '\0'),
           auVar12[0xf] = -((char)((ulong)uStack_c8 >> 0x38) == '\0'),
           bVar31 = NEON_umaxv(auVar12,1), (bVar31 & 1) == 0)) goto LAB_fffffff00a4f8a08;
      }
      else if (uStack_210._1_1_ == '\x1e') {
        uVar37 = 0x1e;
        lVar41 = 8;
        goto LAB_fffffff00a4f6fd4;
      }
      uStack_138 = 0;
      local_140 = 0;
      uStack_128 = 0;
      local_130 = 0;
      uStack_118 = 0;
      local_120 = 0;
      uStack_108 = 0;
      local_110 = 0;
      if (uStack_1f8._5_1_ == '\x02') {
        lVar41 = 4;
LAB_fffffff00a4f70bc:
        FUN_fffffff00a8dd3c8(uStack_1f8._5_1_,(long)&uStack_1f8 + lVar41 + 4,&local_140,0x40);
        auVar13[1] = -((char)(local_140 >> 8) == '\0');
        auVar13[0] = -((char)local_140 == '\0');
        auVar13[2] = -((char)(local_140 >> 0x10) == '\0');
        auVar13[3] = -((char)(local_140 >> 0x18) == '\0');
        auVar13[4] = -((char)(local_140 >> 0x20) == '\0');
        auVar13[5] = -((char)(local_140 >> 0x28) == '\0');
        auVar13[6] = -((char)(local_140 >> 0x30) == '\0');
        auVar13[7] = -((char)(local_140 >> 0x38) == '\0');
        auVar13[8] = -((char)uStack_138 == '\0');
        auVar13[9] = -((char)((ulong)uStack_138 >> 8) == '\0');
        auVar13[10] = -((char)((ulong)uStack_138 >> 0x10) == '\0');
        auVar13[0xb] = -((char)((ulong)uStack_138 >> 0x18) == '\0');
        auVar13[0xc] = -((char)((ulong)uStack_138 >> 0x20) == '\0');
        auVar13[0xd] = -((char)((ulong)uStack_138 >> 0x28) == '\0');
        auVar13[0xe] = -((char)((ulong)uStack_138 >> 0x30) == '\0');
        auVar13[0xf] = -((char)((ulong)uStack_138 >> 0x38) == '\0');
        bVar31 = NEON_umaxv(auVar13,1);
        if ((((bVar31 & 1) == 0) &&
            (auVar14[1] = -((char)((ulong)local_130 >> 8) == '\0'),
            auVar14[0] = -((char)local_130 == '\0'),
            auVar14[2] = -((char)((ulong)local_130 >> 0x10) == '\0'),
            auVar14[3] = -((char)((ulong)local_130 >> 0x18) == '\0'),
            auVar14[4] = -((char)((ulong)local_130 >> 0x20) == '\0'),
            auVar14[5] = -((char)((ulong)local_130 >> 0x28) == '\0'),
            auVar14[6] = -((char)((ulong)local_130 >> 0x30) == '\0'),
            auVar14[7] = -((char)((ulong)local_130 >> 0x38) == '\0'),
            auVar14[8] = -((char)uStack_128 == '\0'),
            auVar14[9] = -((char)((ulong)uStack_128 >> 8) == '\0'),
            auVar14[10] = -((char)((ulong)uStack_128 >> 0x10) == '\0'),
            auVar14[0xb] = -((char)((ulong)uStack_128 >> 0x18) == '\0'),
            auVar14[0xc] = -((char)((ulong)uStack_128 >> 0x20) == '\0'),
            auVar14[0xd] = -((char)((ulong)uStack_128 >> 0x28) == '\0'),
            auVar14[0xe] = -((char)((ulong)uStack_128 >> 0x30) == '\0'),
            auVar14[0xf] = -((char)((ulong)uStack_128 >> 0x38) == '\0'),
            bVar31 = NEON_umaxv(auVar14,1), (bVar31 & 1) == 0)) &&
           ((auVar15[1] = -((char)((ulong)local_120 >> 8) == '\0'),
            auVar15[0] = -((char)local_120 == '\0'),
            auVar15[2] = -((char)((ulong)local_120 >> 0x10) == '\0'),
            auVar15[3] = -((char)((ulong)local_120 >> 0x18) == '\0'),
            auVar15[4] = -((char)((ulong)local_120 >> 0x20) == '\0'),
            auVar15[5] = -((char)((ulong)local_120 >> 0x28) == '\0'),
            auVar15[6] = -((char)((ulong)local_120 >> 0x30) == '\0'),
            auVar15[7] = -((char)((ulong)local_120 >> 0x38) == '\0'),
            auVar15[8] = -((char)uStack_118 == '\0'),
            auVar15[9] = -((char)((ulong)uStack_118 >> 8) == '\0'),
            auVar15[10] = -((char)((ulong)uStack_118 >> 0x10) == '\0'),
            auVar15[0xb] = -((char)((ulong)uStack_118 >> 0x18) == '\0'),
            auVar15[0xc] = -((char)((ulong)uStack_118 >> 0x20) == '\0'),
            auVar15[0xd] = -((char)((ulong)uStack_118 >> 0x28) == '\0'),
            auVar15[0xe] = -((char)((ulong)uStack_118 >> 0x30) == '\0'),
            auVar15[0xf] = -((char)((ulong)uStack_118 >> 0x38) == '\0'),
            bVar31 = NEON_umaxv(auVar15,1), (bVar31 & 1) == 0 &&
            (auVar16[1] = -((char)((ulong)local_110 >> 8) == '\0'),
            auVar16[0] = -((char)local_110 == '\0'),
            auVar16[2] = -((char)((ulong)local_110 >> 0x10) == '\0'),
            auVar16[3] = -((char)((ulong)local_110 >> 0x18) == '\0'),
            auVar16[4] = -((char)((ulong)local_110 >> 0x20) == '\0'),
            auVar16[5] = -((char)((ulong)local_110 >> 0x28) == '\0'),
            auVar16[6] = -((char)((ulong)local_110 >> 0x30) == '\0'),
            auVar16[7] = -((char)((ulong)local_110 >> 0x38) == '\0'),
            auVar16[8] = -((char)uStack_108 == '\0'),
            auVar16[9] = -((char)((ulong)uStack_108 >> 8) == '\0'),
            auVar16[10] = -((char)((ulong)uStack_108 >> 0x10) == '\0'),
            auVar16[0xb] = -((char)((ulong)uStack_108 >> 0x18) == '\0'),
            auVar16[0xc] = -((char)((ulong)uStack_108 >> 0x20) == '\0'),
            auVar16[0xd] = -((char)((ulong)uStack_108 >> 0x28) == '\0'),
            auVar16[0xe] = -((char)((ulong)uStack_108 >> 0x30) == '\0'),
            auVar16[0xf] = -((char)((ulong)uStack_108 >> 0x38) == '\0'),
            bVar31 = NEON_umaxv(auVar16,1), (bVar31 & 1) == 0)))) goto LAB_fffffff00a4f8a08;
      }
      else if (uStack_1f8._5_1_ == '\x1e') {
        lVar41 = 8;
        goto LAB_fffffff00a4f70bc;
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar27,0x10,
                 "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d> <input ifindex %d> <allowed_to_receive %d><pf_tag %X pass_flags %X><gen_count inp %d current %d>\n"
                );
      uVar46 = 0;
      uVar43 = 0;
      goto LAB_fffffff00a4f69c8;
    }
  }
  iVar34 = FUN_fffffff00a4f1ebc(param_2,param_3);
  if (iVar34 == 1) {
LAB_fffffff00a4f69b8:
    uVar46 = 0;
    uVar43 = 1;
    goto LAB_fffffff00a4f69c8;
  }
  if (iVar34 == 3) {
    uVar46 = 0;
    uVar43 = 0;
    goto LAB_fffffff00a4f69c8;
  }
  if ((iVar34 == 2) && (_DAT_fffffff00ad11f40 == 1)) goto LAB_fffffff00a4f69b8;
  FUN_fffffff00a228180(&DAT_fffffff00adcd940);
  uVar40 = 1;
  if (param_4 != 0) {
    uVar40 = 2;
  }
  FUN_fffffff00a4f204c
            (param_1,param_2,param_3,0,uVar40,iVar32,&local_238,&local_220,
             CONCAT71((int7)(CONCAT44(local_258,in_stack_fffffffffffffc80) >> 8),iVar34 == 2),
             in_stack_fffffffffffffc88 & 0xffffffffffffff00);
  iVar32 = DAT_fffffff00adcd97c;
  uVar27 = DAT_fffffff00ad7ce10;
  piVar2 = (int *)(param_1 + 0x1ac);
  piVar3 = piVar2;
  if (local_198 != 0) {
    piVar3 = (int *)(local_198 + 0xac);
  }
  iVar33 = *piVar3;
  if (DAT_fffffff00adcd990 == 0) {
    if (DAT_fffffff00adcd97c != 0) {
      if ((((DAT_fffffff00adcd988 != 0) &&
           (((int)local_220 == 0 || ((int)local_220 == DAT_fffffff00adcd988)))) ||
          ((DAT_fffffff00adcd984 != 0 && (DAT_fffffff00adcd984 == uStack_1c8._4_2_)))) ||
         ((DAT_fffffff00adcd98c != 0 && ((int)uStack_1d8 == DAT_fffffff00adcd98c))))
      goto LAB_fffffff00a4f6edc;
      if (DAT_fffffff00adcd980 != 0) goto LAB_fffffff00a4f6ebc;
    }
LAB_fffffff00a4f6fc0:
    uVar47 = 0;
    iVar32 = 0;
  }
  else {
    if ((((DAT_fffffff00adcd97c == 0) ||
         (((DAT_fffffff00adcd988 != 0 && ((int)local_220 != 0)) &&
          ((int)local_220 != DAT_fffffff00adcd988)))) ||
        ((DAT_fffffff00adcd984 != 0 && (DAT_fffffff00adcd984 != uStack_1c8._4_2_)))) ||
       ((DAT_fffffff00adcd98c != 0 && ((int)uStack_1d8 != DAT_fffffff00adcd98c))))
    goto LAB_fffffff00a4f6fc0;
    if (DAT_fffffff00adcd980 != 0) {
LAB_fffffff00a4f6ebc:
      if ((DAT_fffffff00adcd980 !=
           ((uint)(uStack_210._2_2_ >> 8) | (uStack_210._2_2_ & 0xff00ff) << 8)) &&
         (DAT_fffffff00adcd980 !=
          ((uint)(uStack_1f8._6_2_ >> 8) | (uStack_1f8._6_2_ & 0xff00ff) << 8)))
      goto LAB_fffffff00a4f6fc0;
    }
LAB_fffffff00a4f6edc:
    uStack_d8 = 0;
    local_e0 = 0;
    uStack_c8 = 0;
    local_d0 = 0;
    uStack_f8 = 0;
    local_100 = 0;
    uStack_e8 = 0;
    local_f0 = 0;
    uStack_118 = 0;
    local_120 = 0;
    uStack_108 = 0;
    local_110 = 0;
    uStack_138 = 0;
    local_140 = 0;
    uStack_128 = 0;
    local_130 = 0;
    uVar38 = uVar42 | 0xffffff8000000000;
    in_stack_fffffffffffffc90 = uVar38;
    if ((uVar42 & 0x80000000000000) == 0) {
      in_stack_fffffffffffffc90 = uVar42 & 0x7ffffffffff;
    }
    if (((in_stack_fffffffffffffc90 < DAT_fffffff007c6a360 &&
          DAT_fffffff007c6a358 <= in_stack_fffffffffffffc90) ||
        (DAT_fffffff007c6a378 <= in_stack_fffffffffffffc90 &&
         in_stack_fffffffffffffc90 < DAT_fffffff007c6a380)) ||
       ((DAT_fffffff007c6a3a0 <= in_stack_fffffffffffffc90 &&
        (in_stack_fffffffffffffc90 < DAT_fffffff007c6a3a8)))) {
      in_stack_fffffffffffffc90 = FUN_fffffff00a396010(in_stack_fffffffffffffc90);
    }
    else if ((((uVar42 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar38)) &&
            (uVar38 < 0xfffffffc00000000)) {
      in_stack_fffffffffffffc90 = FUN_fffffff00a1d12d4();
    }
    uStack_f8 = 0;
    local_100 = 0;
    uStack_e8 = 0;
    local_f0 = 0;
    uStack_d8 = 0;
    local_e0 = 0;
    uStack_c8 = 0;
    local_d0 = 0;
    if (uStack_210._1_1_ == '\x02') {
      lVar44 = 4;
      uVar37 = 2;
LAB_fffffff00a4f72ac:
      FUN_fffffff00a8dd3c8(uVar37,(long)&uStack_210 + lVar44,&local_100,0x40);
      auVar17[1] = -((char)(local_100 >> 8) == '\0');
      auVar17[0] = -((char)local_100 == '\0');
      auVar17[2] = -((char)(local_100 >> 0x10) == '\0');
      auVar17[3] = -((char)(local_100 >> 0x18) == '\0');
      auVar17[4] = -((char)(local_100 >> 0x20) == '\0');
      auVar17[5] = -((char)(local_100 >> 0x28) == '\0');
      auVar17[6] = -((char)(local_100 >> 0x30) == '\0');
      auVar17[7] = -((char)(local_100 >> 0x38) == '\0');
      auVar17[8] = -((char)uStack_f8 == '\0');
      auVar17[9] = -((char)((ulong)uStack_f8 >> 8) == '\0');
      auVar17[10] = -((char)((ulong)uStack_f8 >> 0x10) == '\0');
      auVar17[0xb] = -((char)((ulong)uStack_f8 >> 0x18) == '\0');
      auVar17[0xc] = -((char)((ulong)uStack_f8 >> 0x20) == '\0');
      auVar17[0xd] = -((char)((ulong)uStack_f8 >> 0x28) == '\0');
      auVar17[0xe] = -((char)((ulong)uStack_f8 >> 0x30) == '\0');
      auVar17[0xf] = -((char)((ulong)uStack_f8 >> 0x38) == '\0');
      bVar31 = NEON_umaxv(auVar17,1);
      if ((((bVar31 & 1) == 0) &&
          (auVar18[1] = -((char)((ulong)local_f0 >> 8) == '\0'),
          auVar18[0] = -((char)local_f0 == '\0'),
          auVar18[2] = -((char)((ulong)local_f0 >> 0x10) == '\0'),
          auVar18[3] = -((char)((ulong)local_f0 >> 0x18) == '\0'),
          auVar18[4] = -((char)((ulong)local_f0 >> 0x20) == '\0'),
          auVar18[5] = -((char)((ulong)local_f0 >> 0x28) == '\0'),
          auVar18[6] = -((char)((ulong)local_f0 >> 0x30) == '\0'),
          auVar18[7] = -((char)((ulong)local_f0 >> 0x38) == '\0'),
          auVar18[8] = -((char)uStack_e8 == '\0'),
          auVar18[9] = -((char)((ulong)uStack_e8 >> 8) == '\0'),
          auVar18[10] = -((char)((ulong)uStack_e8 >> 0x10) == '\0'),
          auVar18[0xb] = -((char)((ulong)uStack_e8 >> 0x18) == '\0'),
          auVar18[0xc] = -((char)((ulong)uStack_e8 >> 0x20) == '\0'),
          auVar18[0xd] = -((char)((ulong)uStack_e8 >> 0x28) == '\0'),
          auVar18[0xe] = -((char)((ulong)uStack_e8 >> 0x30) == '\0'),
          auVar18[0xf] = -((char)((ulong)uStack_e8 >> 0x38) == '\0'), bVar31 = NEON_umaxv(auVar18,1)
          , (bVar31 & 1) == 0)) &&
         ((auVar19[1] = -((char)((ulong)local_e0 >> 8) == '\0'),
          auVar19[0] = -((char)local_e0 == '\0'),
          auVar19[2] = -((char)((ulong)local_e0 >> 0x10) == '\0'),
          auVar19[3] = -((char)((ulong)local_e0 >> 0x18) == '\0'),
          auVar19[4] = -((char)((ulong)local_e0 >> 0x20) == '\0'),
          auVar19[5] = -((char)((ulong)local_e0 >> 0x28) == '\0'),
          auVar19[6] = -((char)((ulong)local_e0 >> 0x30) == '\0'),
          auVar19[7] = -((char)((ulong)local_e0 >> 0x38) == '\0'),
          auVar19[8] = -((char)uStack_d8 == '\0'),
          auVar19[9] = -((char)((ulong)uStack_d8 >> 8) == '\0'),
          auVar19[10] = -((char)((ulong)uStack_d8 >> 0x10) == '\0'),
          auVar19[0xb] = -((char)((ulong)uStack_d8 >> 0x18) == '\0'),
          auVar19[0xc] = -((char)((ulong)uStack_d8 >> 0x20) == '\0'),
          auVar19[0xd] = -((char)((ulong)uStack_d8 >> 0x28) == '\0'),
          auVar19[0xe] = -((char)((ulong)uStack_d8 >> 0x30) == '\0'),
          auVar19[0xf] = -((char)((ulong)uStack_d8 >> 0x38) == '\0'), bVar31 = NEON_umaxv(auVar19,1)
          , (bVar31 & 1) == 0 &&
          (auVar20[1] = -((char)((ulong)local_d0 >> 8) == '\0'),
          auVar20[0] = -((char)local_d0 == '\0'),
          auVar20[2] = -((char)((ulong)local_d0 >> 0x10) == '\0'),
          auVar20[3] = -((char)((ulong)local_d0 >> 0x18) == '\0'),
          auVar20[4] = -((char)((ulong)local_d0 >> 0x20) == '\0'),
          auVar20[5] = -((char)((ulong)local_d0 >> 0x28) == '\0'),
          auVar20[6] = -((char)((ulong)local_d0 >> 0x30) == '\0'),
          auVar20[7] = -((char)((ulong)local_d0 >> 0x38) == '\0'),
          auVar20[8] = -((char)uStack_c8 == '\0'),
          auVar20[9] = -((char)((ulong)uStack_c8 >> 8) == '\0'),
          auVar20[10] = -((char)((ulong)uStack_c8 >> 0x10) == '\0'),
          auVar20[0xb] = -((char)((ulong)uStack_c8 >> 0x18) == '\0'),
          auVar20[0xc] = -((char)((ulong)uStack_c8 >> 0x20) == '\0'),
          auVar20[0xd] = -((char)((ulong)uStack_c8 >> 0x28) == '\0'),
          auVar20[0xe] = -((char)((ulong)uStack_c8 >> 0x30) == '\0'),
          auVar20[0xf] = -((char)((ulong)uStack_c8 >> 0x38) == '\0'), bVar31 = NEON_umaxv(auVar20,1)
          , (bVar31 & 1) == 0)))) goto LAB_fffffff00a4f8a08;
    }
    else if (uStack_210._1_1_ == '\x1e') {
      uVar37 = 0x1e;
      lVar44 = 8;
      goto LAB_fffffff00a4f72ac;
    }
    uStack_138 = 0;
    local_140 = 0;
    uStack_128 = 0;
    local_130 = 0;
    uStack_118 = 0;
    local_120 = 0;
    uStack_108 = 0;
    local_110 = 0;
    if (uStack_1f8._5_1_ == '\x02') {
      lVar44 = 4;
LAB_fffffff00a4f7344:
      FUN_fffffff00a8dd3c8(uStack_1f8._5_1_,(long)&uStack_1f8 + lVar44 + 4,&local_140,0x40);
      auVar21[1] = -((char)(local_140 >> 8) == '\0');
      auVar21[0] = -((char)local_140 == '\0');
      auVar21[2] = -((char)(local_140 >> 0x10) == '\0');
      auVar21[3] = -((char)(local_140 >> 0x18) == '\0');
      auVar21[4] = -((char)(local_140 >> 0x20) == '\0');
      auVar21[5] = -((char)(local_140 >> 0x28) == '\0');
      auVar21[6] = -((char)(local_140 >> 0x30) == '\0');
      auVar21[7] = -((char)(local_140 >> 0x38) == '\0');
      auVar21[8] = -((char)uStack_138 == '\0');
      auVar21[9] = -((char)((ulong)uStack_138 >> 8) == '\0');
      auVar21[10] = -((char)((ulong)uStack_138 >> 0x10) == '\0');
      auVar21[0xb] = -((char)((ulong)uStack_138 >> 0x18) == '\0');
      auVar21[0xc] = -((char)((ulong)uStack_138 >> 0x20) == '\0');
      auVar21[0xd] = -((char)((ulong)uStack_138 >> 0x28) == '\0');
      auVar21[0xe] = -((char)((ulong)uStack_138 >> 0x30) == '\0');
      auVar21[0xf] = -((char)((ulong)uStack_138 >> 0x38) == '\0');
      bVar31 = NEON_umaxv(auVar21,1);
      if ((((bVar31 & 1) == 0) &&
          (auVar22[1] = -((char)((ulong)local_130 >> 8) == '\0'),
          auVar22[0] = -((char)local_130 == '\0'),
          auVar22[2] = -((char)((ulong)local_130 >> 0x10) == '\0'),
          auVar22[3] = -((char)((ulong)local_130 >> 0x18) == '\0'),
          auVar22[4] = -((char)((ulong)local_130 >> 0x20) == '\0'),
          auVar22[5] = -((char)((ulong)local_130 >> 0x28) == '\0'),
          auVar22[6] = -((char)((ulong)local_130 >> 0x30) == '\0'),
          auVar22[7] = -((char)((ulong)local_130 >> 0x38) == '\0'),
          auVar22[8] = -((char)uStack_128 == '\0'),
          auVar22[9] = -((char)((ulong)uStack_128 >> 8) == '\0'),
          auVar22[10] = -((char)((ulong)uStack_128 >> 0x10) == '\0'),
          auVar22[0xb] = -((char)((ulong)uStack_128 >> 0x18) == '\0'),
          auVar22[0xc] = -((char)((ulong)uStack_128 >> 0x20) == '\0'),
          auVar22[0xd] = -((char)((ulong)uStack_128 >> 0x28) == '\0'),
          auVar22[0xe] = -((char)((ulong)uStack_128 >> 0x30) == '\0'),
          auVar22[0xf] = -((char)((ulong)uStack_128 >> 0x38) == '\0'),
          bVar31 = NEON_umaxv(auVar22,1), (bVar31 & 1) == 0)) &&
         ((auVar23[1] = -((char)((ulong)local_120 >> 8) == '\0'),
          auVar23[0] = -((char)local_120 == '\0'),
          auVar23[2] = -((char)((ulong)local_120 >> 0x10) == '\0'),
          auVar23[3] = -((char)((ulong)local_120 >> 0x18) == '\0'),
          auVar23[4] = -((char)((ulong)local_120 >> 0x20) == '\0'),
          auVar23[5] = -((char)((ulong)local_120 >> 0x28) == '\0'),
          auVar23[6] = -((char)((ulong)local_120 >> 0x30) == '\0'),
          auVar23[7] = -((char)((ulong)local_120 >> 0x38) == '\0'),
          auVar23[8] = -((char)uStack_118 == '\0'),
          auVar23[9] = -((char)((ulong)uStack_118 >> 8) == '\0'),
          auVar23[10] = -((char)((ulong)uStack_118 >> 0x10) == '\0'),
          auVar23[0xb] = -((char)((ulong)uStack_118 >> 0x18) == '\0'),
          auVar23[0xc] = -((char)((ulong)uStack_118 >> 0x20) == '\0'),
          auVar23[0xd] = -((char)((ulong)uStack_118 >> 0x28) == '\0'),
          auVar23[0xe] = -((char)((ulong)uStack_118 >> 0x30) == '\0'),
          auVar23[0xf] = -((char)((ulong)uStack_118 >> 0x38) == '\0'),
          bVar31 = NEON_umaxv(auVar23,1), (bVar31 & 1) == 0 &&
          (auVar24[1] = -((char)((ulong)local_110 >> 8) == '\0'),
          auVar24[0] = -((char)local_110 == '\0'),
          auVar24[2] = -((char)((ulong)local_110 >> 0x10) == '\0'),
          auVar24[3] = -((char)((ulong)local_110 >> 0x18) == '\0'),
          auVar24[4] = -((char)((ulong)local_110 >> 0x20) == '\0'),
          auVar24[5] = -((char)((ulong)local_110 >> 0x28) == '\0'),
          auVar24[6] = -((char)((ulong)local_110 >> 0x30) == '\0'),
          auVar24[7] = -((char)((ulong)local_110 >> 0x38) == '\0'),
          auVar24[8] = -((char)uStack_108 == '\0'),
          auVar24[9] = -((char)((ulong)uStack_108 >> 8) == '\0'),
          auVar24[10] = -((char)((ulong)uStack_108 >> 0x10) == '\0'),
          auVar24[0xb] = -((char)((ulong)uStack_108 >> 0x18) == '\0'),
          auVar24[0xc] = -((char)((ulong)uStack_108 >> 0x20) == '\0'),
          auVar24[0xd] = -((char)((ulong)uStack_108 >> 0x28) == '\0'),
          auVar24[0xe] = -((char)((ulong)uStack_108 >> 0x30) == '\0'),
          auVar24[0xf] = -((char)((ulong)uStack_108 >> 0x38) == '\0'),
          bVar31 = NEON_umaxv(auVar24,1), (bVar31 & 1) == 0)))) goto LAB_fffffff00a4f8a08;
    }
    else if (uStack_1f8._5_1_ == '\x1e') {
      lVar44 = 8;
      goto LAB_fffffff00a4f7344;
    }
    uVar47 = 1;
    uVar48 = (undefined4)((ulong)&local_140 >> 0x20);
    FUN_fffffff00a8df19c
              (&MACH_HEADER,uVar27,0x10,
               "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d> <input ifindex %d> <allowed_to_receive %d><pf_tag %X pass_flags %X><gen_count inp %d current %d>\n"
              );
  }
  iVar35 = (*_DAT_fffffff00ad19dc8)(&local_220,0x98,DAT_fffffff00adcda90);
  if (((*(int *)(param_1 + 0x1a4) != 0) && (iVar33 == DAT_fffffff00adcda90)) &&
     (*(int *)(param_1 + 0x1b0) == iVar35)) {
    iVar34 = *(int *)(param_1 + 0x1b8);
    uVar43 = *(uint *)(param_1 + 0x1bc);
    if (local_198 == 0) {
      bVar30 = false;
    }
    else {
      iVar33 = *(int *)(local_198 + 0xb8);
      if (iVar33 == 0) {
        bVar30 = false;
      }
      else {
        bVar30 = iVar34 != iVar33;
        if (bVar30) {
          iVar34 = iVar33;
        }
        bVar30 = uVar43 != *(uint *)(local_198 + 0xbc) || bVar30;
        uVar43 = *(uint *)(local_198 + 0xbc);
      }
    }
    if ((iVar34 - 3U < 2) ||
       ((((param_4 != 0 && (iVar34 == 6)) && (uVar43 != local_258)) ||
        ((iVar34 = FUN_fffffff00a4ebc98(lVar41,param_4,0), iVar34 == 0 ||
         ((*(int *)(param_1 + 0x1c8) != 0 &&
          (uVar38 = FUN_fffffff00a4eb9f0
                              (lVar41,param_4,0,0,*(int *)(param_1 + 0x1c8),(long)&local_228 + 4,0),
          (uVar38 & 1) == 0)))))))) {
      uVar27 = DAT_fffffff00ad7ce40;
      if (uVar47 == 0) {
        uVar46 = 0;
        uVar43 = 0;
      }
      else {
        iVar34 = FUN_fffffff00a4ecdf8(uVar42);
        uVar38 = uVar42 | 0xffffff8000000000;
        if (iVar34 == 0) {
          if ((((uVar42 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar38)) &&
             (uVar38 < 0xfffffffc00000000)) {
            FUN_fffffff00a1d12d4(uVar38);
          }
        }
        else {
          uVar45 = uVar42 & 0x7ffffffffff;
          if ((uVar42 & 0x80000000000000) != 0) {
            uVar45 = uVar38;
          }
          FUN_fffffff00a396010(uVar45);
        }
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,uVar27,0x10,
                   "%s: DATA-TRACE: <SOCKET - DATA PATH %llx>: START - RESULT - CACHED <DROP> - <result %d paramater %d><verifyifindex %d>\n"
                  );
        uVar27 = DAT_fffffff00ad7ce10;
        uStack_d8 = 0;
        local_e0 = 0;
        uStack_c8 = 0;
        local_d0 = 0;
        uStack_f8 = 0;
        local_100 = 0;
        uStack_e8 = 0;
        local_f0 = 0;
        uStack_118 = 0;
        local_120 = 0;
        uStack_108 = 0;
        local_110 = 0;
        uStack_138 = 0;
        local_140 = 0;
        uStack_128 = 0;
        local_130 = 0;
        iVar34 = FUN_fffffff00a4ecdf8(uVar42);
        if (iVar34 == 0) {
          if ((((uVar42 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar38)) &&
             (uVar38 < 0xfffffffc00000000)) {
            FUN_fffffff00a1d12d4(uVar38);
          }
        }
        else {
          uVar45 = uVar42 & 0x7ffffffffff;
          if ((uVar42 & 0x80000000000000) != 0) {
            uVar45 = uVar38;
          }
          FUN_fffffff00a396010(uVar45);
        }
        FUN_fffffff00a4eb1ec(&uStack_210,&local_100);
        FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_140);
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,uVar27,0x10,
                   "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d> <input ifindex %d> <allowed_to_receive %d><pf_tag %X pass_flags %X><gen_count inp %d current %d>\n"
                  );
        uVar46 = 0;
        uVar43 = 0;
      }
    }
    else {
      puVar6 = (undefined4 *)(local_198 + 0xb0);
      if (!bVar30) {
        puVar6 = (undefined4 *)(param_1 + 0x1a4);
      }
      puVar7 = (undefined4 *)(local_198 + 0xb4);
      if (!bVar30) {
        puVar7 = (undefined4 *)(param_1 + 0x1a8);
      }
      uVar48 = *puVar7;
      puVar8 = (uint *)(local_198 + 0xbc);
      if (!bVar30) {
        puVar8 = (uint *)(param_1 + 0x1bc);
      }
      uVar46 = *puVar8;
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = *puVar6;
      }
      if (param_7 != (int *)0x0) {
        *param_7 = *(int *)(param_1 + 0x1c8);
      }
      if (param_8 != (undefined4 *)0x0) {
        *param_8 = uVar48;
      }
      if (*(int *)(param_1 + 0x1b8) != 1) {
        uVar46 = 0;
      }
      if ((1 < iVar32) || (1 < DAT_fffffff00ad7ce48)) {
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,DAT_fffffff00ad7ce40,0,
                   "%s: DATA-TRACE: Socket Policy - Send/Recv - RESULT - CACHED <MATCHED>: %p (BoundInterface %d Proto %d) Policy %d Skip %d Result %d Parameter %d\n"
                  );
      }
      uVar27 = DAT_fffffff00ad7ce10;
      if (uVar47 != 0) {
        uStack_d8 = 0;
        local_e0 = 0;
        uStack_c8 = 0;
        local_d0 = 0;
        uStack_f8 = 0;
        local_100 = 0;
        uStack_e8 = 0;
        local_f0 = 0;
        uStack_118 = 0;
        local_120 = 0;
        uStack_108 = 0;
        local_110 = 0;
        uStack_138 = 0;
        local_140 = 0;
        uStack_128 = 0;
        local_130 = 0;
        iVar34 = FUN_fffffff00a4ecdf8(uVar42);
        uVar38 = uVar42 | 0xffffff8000000000;
        if (iVar34 == 0) {
          if ((((uVar42 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar38)) &&
             (uVar38 < 0xfffffffc00000000)) {
            FUN_fffffff00a1d12d4();
          }
        }
        else {
          uVar45 = uVar42 & 0x7ffffffffff;
          if ((uVar42 & 0x80000000000000) != 0) {
            uVar45 = uVar38;
          }
          FUN_fffffff00a396010(uVar45);
        }
        FUN_fffffff00a4eb1ec(&uStack_210,&local_100);
        FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_140);
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,uVar27,0x10,
                   "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d> <input ifindex %d> <allowed_to_receive %d><pf_tag %X pass_flags %X><gen_count inp %d current %d>\n"
                  );
      }
      uVar43 = 1;
    }
    FUN_fffffff00a228d30(&DAT_fffffff00adcd940);
    goto LAB_fffffff00a4f69c8;
  }
  if (uVar47 != 0) {
    if (*piVar2 != DAT_fffffff00adcda90) {
      DAT_fffffff00ad7ce20 = DAT_fffffff00ad7ce20 + 1;
    }
    DAT_fffffff00ad7ce28 = DAT_fffffff00ad7ce28 + 1;
  }
  uStack_158 = 0;
  local_160 = 0;
  uStack_148 = 0;
  uStack_150 = 0;
  uStack_178 = 0;
  local_180 = 0;
  uStack_168 = 0;
  uStack_170 = 0;
  local_248 = 0;
  lVar44 = local_238;
  if (local_238 == 0) {
    lVar44 = FUN_fffffff00a29b24c();
    lVar44 = *(long *)(lVar44 + 0x18);
    if (lVar44 == 0) {
      lVar44 = DAT_fffffff007c6b250;
    }
  }
  uVar43 = 0;
  if ((uint)local_1c0 != 0) {
    uVar43 = ((uint)local_1c0 & 3) + 1;
  }
  puVar1 = &DAT_fffffff00adcda98 + (ulong)uVar43 * 2;
  if ((((undefined8 *)((long)&DAT_fffffff00adcdae0 + 7) < puVar1) ||
      (puVar1 < &DAT_fffffff00adcda98)) || (uVar42 + 0x3c0 <= uVar42)) goto LAB_fffffff00a4f8a08;
  uVar45 = FUN_fffffff00a4e8d7c
                     (*puVar1,(&DAT_fffffff00adcdaa0)[(ulong)uVar43 * 2],&local_220,
                      (long)&local_240 + 4,&local_180,&local_248,&local_c0,0,0,0,
                      in_stack_fffffffffffffc90 & 0xffffffff00000000,lVar44,(short)param_5,param_8,
                      *(undefined8 *)(param_1 + 0xe8),&local_228,&local_22c,&local_240,uVar42,
                      CONCAT44(uVar48,iVar32));
  uVar38 = uVar45 + 0x178;
  if (((iVar34 == 2) && (_DAT_fffffff00ad11f40 == 2)) &&
     ((uVar45 == 0 || (*(int *)(uVar45 + 0x170) != 4)))) {
    piVar3 = (int *)(local_198 + 0xac);
    piVar5 = (int *)(param_1 + 0x1c0);
    piVar25 = piVar2;
    if (local_198 != 0) {
      piVar5 = (int *)(local_198 + 0xa8);
      piVar25 = piVar3;
    }
    if ((*piVar25 == DAT_fffffff00adcda90) || (*piVar5 == local_240._4_4_)) {
      if (*piVar2 == DAT_fffffff00adcda90) {
        if (local_198 != 0) goto LAB_fffffff00a4f78f4;
      }
      else {
        *piVar2 = DAT_fffffff00adcda90;
        if (uVar45 == 0) {
          if (local_198 != 0) goto LAB_fffffff00a4f7f5c;
        }
        else {
          *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(uVar45 + 0x170);
          if (uVar38 <= uVar45) goto LAB_fffffff00a4f8a08;
          *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(uVar45 + 0x174);
          if (local_198 != 0) goto LAB_fffffff00a4f7f30;
        }
      }
    }
    else {
      *(int *)(param_1 + 0x1c0) = local_240._4_4_;
      if (local_198 == 0) {
        if ((*piVar2 != DAT_fffffff00adcda90) && (*piVar2 = DAT_fffffff00adcda90, uVar45 != 0)) {
          *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(uVar45 + 0x170);
          if (uVar38 <= uVar45) goto LAB_fffffff00a4f8a08;
          *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(uVar45 + 0x174);
        }
      }
      else {
        *(int *)(local_198 + 0xa8) = local_240._4_4_;
        if (*piVar2 == DAT_fffffff00adcda90) {
LAB_fffffff00a4f78f4:
          *piVar3 = DAT_fffffff00adcda90;
          if (uVar45 != 0) goto LAB_fffffff00a4f7f3c;
        }
        else {
          *piVar2 = DAT_fffffff00adcda90;
          if (uVar45 == 0) {
LAB_fffffff00a4f7f5c:
            *piVar3 = DAT_fffffff00adcda90;
          }
          else {
            *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(uVar45 + 0x170);
            if (uVar38 <= uVar45) goto LAB_fffffff00a4f8a08;
            *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(uVar45 + 0x174);
LAB_fffffff00a4f7f30:
            *piVar3 = DAT_fffffff00adcda90;
LAB_fffffff00a4f7f3c:
            *(undefined4 *)(local_198 + 0xb8) = *(undefined4 *)(uVar45 + 0x170);
            if (uVar38 <= uVar45) goto LAB_fffffff00a4f8a08;
            *(undefined4 *)(local_198 + 0xbc) = *(undefined4 *)(uVar45 + 0x174);
          }
        }
      }
    }
    if (*(int *)(param_1 + 0x1c4) != (int)local_240) {
      *(int *)(param_1 + 0x1c4) = (int)local_240;
    }
    FUN_fffffff00a228d30(&DAT_fffffff00adcd940);
    uVar27 = DAT_fffffff00ad7ce10;
    if (uVar47 != 0) {
      uStack_d8 = 0;
      local_e0 = 0;
      uStack_c8 = 0;
      local_d0 = 0;
      uStack_f8 = 0;
      local_100 = 0;
      uStack_e8 = 0;
      local_f0 = 0;
      uStack_118 = 0;
      local_120 = 0;
      uStack_108 = 0;
      local_110 = 0;
      uStack_138 = 0;
      local_140 = 0;
      uStack_128 = 0;
      local_130 = 0;
      iVar34 = FUN_fffffff00a4ecdf8(uVar42);
      uVar38 = uVar42 | 0xffffff8000000000;
      if (iVar34 == 0) {
        if ((((uVar42 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar38)) &&
           (uVar38 < 0xfffffffc00000000)) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        uVar45 = uVar42 & 0x7ffffffffff;
        if ((uVar42 & 0x80000000000000) != 0) {
          uVar45 = uVar38;
        }
        FUN_fffffff00a396010(uVar45);
      }
      FUN_fffffff00a4eb1ec(&uStack_210,&local_100);
      FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_140);
      uVar43 = 1;
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar27,0x10,
                 "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d> <input ifindex %d> <allowed_to_receive %d><pf_tag %X pass_flags %X><gen_count inp %d current %d>\n"
                );
      uVar46 = 0;
      goto LAB_fffffff00a4f69c8;
    }
    goto LAB_fffffff00a4f7fe4;
  }
  if ((uStack_1c8._4_2_ == 0x11) &&
     (uVar39 = FUN_fffffff00a4f2c9c(&local_c0,iVar32,uVar42), uVar27 = DAT_fffffff00ad7ce40,
     (uVar39 & 1) == 0)) {
    if ((1 < iVar32) || (1 < DAT_fffffff00ad7ce48)) {
      iVar34 = FUN_fffffff00a4ecdf8(uVar42);
      uVar38 = uVar42 | 0xffffff8000000000;
      if (iVar34 == 0) {
        if ((((uVar42 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar38)) &&
           (uVar38 < 0xfffffffc00000000)) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        uVar45 = uVar42 & 0x7ffffffffff;
        if ((uVar42 & 0x80000000000000) != 0) {
          uVar45 = uVar38;
        }
        FUN_fffffff00a396010(uVar45);
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar27,0x10,
                 "%s: DATA-TRACE: Socket Policy: <so %llx> (BoundInterface %d Proto %d) Dropping packet because agent is not active\n"
                );
    }
    *(undefined8 *)(param_1 + 0x1a4) = 0x100000001;
    *(int *)(param_1 + 0x1ac) = DAT_fffffff00adcda90;
    *(int *)(param_1 + 0x1b0) = iVar35;
    *(undefined8 *)(param_1 + 0x1c0) = 0;
    *(undefined4 *)(param_1 + 0x1c8) = 0;
    *(undefined4 *)(param_1 + 0x1b8) = 3;
    iVar34 = DAT_fffffff00adcda90;
    if (local_198 != 0) {
      *(undefined4 *)(local_198 + 0xa8) = 0;
      *(int *)(local_198 + 0xac) = iVar34;
      *(undefined8 *)(local_198 + 0xb8) = 0;
    }
    FUN_fffffff00a228d30(&DAT_fffffff00adcd940);
    uVar27 = DAT_fffffff00ad7ce10;
    if (uVar47 != 0) {
      uStack_d8 = 0;
      local_e0 = 0;
      uStack_c8 = 0;
      local_d0 = 0;
      uStack_f8 = 0;
      local_100 = 0;
      uStack_e8 = 0;
      local_f0 = 0;
      uStack_118 = 0;
      local_120 = 0;
      uStack_108 = 0;
      local_110 = 0;
      uStack_138 = 0;
      local_140 = 0;
      uStack_128 = 0;
      local_130 = 0;
      iVar34 = FUN_fffffff00a4ecdf8(uVar42);
      uVar38 = uVar42 | 0xffffff8000000000;
      if (iVar34 == 0) {
        if ((((uVar42 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar38)) &&
           (uVar38 < 0xfffffffc00000000)) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        uVar45 = uVar42 & 0x7ffffffffff;
        if ((uVar42 & 0x80000000000000) != 0) {
          uVar45 = uVar38;
        }
        FUN_fffffff00a396010(uVar45);
      }
      FUN_fffffff00a4eb1ec(&uStack_210,&local_100);
      FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_140);
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar27,0x10,
                 "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d> <input ifindex %d> <allowed_to_receive %d><pf_tag %X pass_flags %X><gen_count inp %d current %d>\n"
                );
      uVar46 = 0;
      uVar43 = 0;
      goto LAB_fffffff00a4f69c8;
    }
    goto LAB_fffffff00a4f6984;
  }
  if (local_248 == 0) {
    uVar39 = 0;
  }
  else if (local_248 == 1) {
    uVar39 = local_180 & 0xffffffff;
  }
  else {
    uVar39 = FUN_fffffff00a4f2e5c(&local_180);
  }
  iVar34 = (int)uVar39;
  if (uVar45 == 0) {
    if (((DAT_fffffff00ad7cdf8 == 0) && (uStack_1b8._4_4_ == 0)) && ((int)local_228 != 3)) {
LAB_fffffff00a4f7834:
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = 1;
      }
      if (param_7 != (int *)0x0) {
        *param_7 = iVar34;
      }
      piVar3 = (int *)(param_1 + 0x1c0);
      piVar5 = piVar2;
      if (local_198 != 0) {
        piVar3 = (int *)(local_198 + 0xa8);
        piVar5 = (int *)(local_198 + 0xac);
      }
      if ((*piVar5 == DAT_fffffff00adcda90) || (*piVar3 == local_240._4_4_)) {
        *piVar2 = DAT_fffffff00adcda90;
        if (local_198 != 0) goto LAB_fffffff00a4f7e14;
      }
      else {
        *(int *)(param_1 + 0x1c0) = local_240._4_4_;
        if (local_198 == 0) {
          *piVar2 = DAT_fffffff00adcda90;
        }
        else {
          *(int *)(local_198 + 0xa8) = local_240._4_4_;
          *piVar2 = DAT_fffffff00adcda90;
LAB_fffffff00a4f7e14:
          *(int *)(local_198 + 0xac) = DAT_fffffff00adcda90;
          *(undefined8 *)(local_198 + 0xb8) = 0;
        }
      }
      if (*(int *)(param_1 + 0x1c4) != (int)local_240) {
        *(int *)(param_1 + 0x1c4) = (int)local_240;
      }
      uVar27 = DAT_fffffff00ad7ce10;
      if (uVar47 == 0) {
        bVar30 = false;
        uVar46 = 0;
        uVar43 = 1;
      }
      else {
        uStack_d8 = 0;
        local_e0 = 0;
        uStack_c8 = 0;
        local_d0 = 0;
        uStack_f8 = 0;
        local_100 = 0;
        uStack_e8 = 0;
        local_f0 = 0;
        uStack_118 = 0;
        local_120 = 0;
        uStack_108 = 0;
        local_110 = 0;
        uStack_138 = 0;
        local_140 = 0;
        uStack_128 = 0;
        local_130 = 0;
        iVar34 = FUN_fffffff00a4ecdf8(uVar42);
        uVar38 = uVar42 | 0xffffff8000000000;
        if (iVar34 == 0) {
          if ((((uVar42 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar38)) &&
             (uVar38 < 0xfffffffc00000000)) {
            FUN_fffffff00a1d12d4();
          }
        }
        else {
          uVar45 = uVar42 & 0x7ffffffffff;
          if ((uVar42 & 0x80000000000000) != 0) {
            uVar45 = uVar38;
          }
          FUN_fffffff00a396010(uVar45);
        }
        FUN_fffffff00a4eb1ec(&uStack_210,&local_100);
        FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_140);
        uVar43 = 1;
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,uVar27,0x10,
                   "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d> <input ifindex %d> <allowed_to_receive %d><pf_tag %X pass_flags %X><gen_count inp %d current %d>\n"
                  );
        bVar30 = false;
        uVar46 = 0;
      }
    }
    else {
      iVar32 = local_22c;
      if (local_22c == 0) {
        iVar32 = FUN_fffffff00a4eb270(lVar44);
      }
      uVar27 = DAT_fffffff00ad7ce10;
      if (iVar32 != 2) goto LAB_fffffff00a4f7834;
      if (uVar47 == 0) {
        bVar30 = false;
        uVar46 = 0;
        uVar43 = 0;
      }
      else {
        uStack_d8 = 0;
        local_e0 = 0;
        uStack_c8 = 0;
        local_d0 = 0;
        uStack_f8 = 0;
        local_100 = 0;
        uStack_e8 = 0;
        local_f0 = 0;
        uStack_118 = 0;
        local_120 = 0;
        uStack_108 = 0;
        local_110 = 0;
        uStack_138 = 0;
        local_140 = 0;
        uStack_128 = 0;
        local_130 = 0;
        iVar34 = FUN_fffffff00a4ecdf8(uVar42);
        uVar38 = uVar42 | 0xffffff8000000000;
        if (iVar34 == 0) {
          if ((((uVar42 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar38)) &&
             (uVar38 < 0xfffffffc00000000)) {
            FUN_fffffff00a1d12d4();
          }
        }
        else {
          uVar45 = uVar42 & 0x7ffffffffff;
          if ((uVar42 & 0x80000000000000) != 0) {
            uVar45 = uVar38;
          }
          FUN_fffffff00a396010(uVar45);
        }
        FUN_fffffff00a4eb1ec(&uStack_210,&local_100);
        FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_140);
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,uVar27,0x10,
                   "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d> <input ifindex %d> <allowed_to_receive %d><pf_tag %X pass_flags %X><gen_count inp %d current %d>\n"
                  );
        bVar30 = false;
        uVar46 = 0;
        uVar43 = 0;
      }
    }
  }
  else {
    iVar33 = *(int *)(uVar45 + 0x170);
    if (iVar33 == 3) {
      bVar30 = (*(uint *)(uVar45 + 0x174) & 3) == 1;
LAB_fffffff00a4f7810:
      uVar46 = 0;
      uVar43 = 0;
      uVar27 = DAT_fffffff00ad7ce40;
    }
    else {
      if ((iVar33 - 3U < 2) ||
         (((param_4 != 0 && (iVar33 == 6)) && (*(uint *)(uVar45 + 0x174) != local_258)))) {
        bVar30 = false;
        goto LAB_fffffff00a4f7810;
      }
      iVar33 = FUN_fffffff00a4ebc98(lVar41,param_4,0);
      if (((iVar33 == 0) ||
          ((iVar34 != 0 &&
           (iVar33 = FUN_fffffff00a4eb9f0
                               (lVar41,param_4,&local_c0,0x10,uVar39,(long)&local_228 + 4,0),
           iVar33 == 0)))) || (iVar33 = FUN_fffffff00a4f8c70(&local_c0), iVar33 == 0)) {
        bVar30 = false;
        uVar46 = 0;
        uVar43 = 0;
        uVar27 = DAT_fffffff00ad7ce40;
      }
      else {
        if (param_6 != (undefined4 *)0x0) {
          *param_6 = *(undefined4 *)(uVar45 + 0x10);
        }
        if (param_7 != (int *)0x0) {
          *param_7 = iVar34;
        }
        if (*(int *)(uVar45 + 0x170) == 1) {
          uVar46 = *(uint *)(uVar45 + 0x174);
        }
        else {
          uVar46 = 0;
        }
        piVar3 = (int *)(param_1 + 0x1c0);
        piVar5 = piVar2;
        if (local_198 != 0) {
          piVar3 = (int *)(local_198 + 0xa8);
          piVar5 = (int *)(local_198 + 0xac);
        }
        if (((*piVar5 != DAT_fffffff00adcda90) && (*piVar3 != local_240._4_4_)) &&
           (*(int *)(param_1 + 0x1c0) = local_240._4_4_, local_198 != 0)) {
          *(int *)(local_198 + 0xa8) = local_240._4_4_;
        }
        if (*piVar2 != DAT_fffffff00adcda90) {
          *(int *)(param_1 + 0x1ac) = DAT_fffffff00adcda90;
          *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(uVar45 + 0x170);
          if (uVar38 <= uVar45) goto LAB_fffffff00a4f8a08;
          *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(uVar45 + 0x174);
        }
        if (local_198 != 0) {
          *(int *)(local_198 + 0xac) = DAT_fffffff00adcda90;
          *(undefined4 *)(local_198 + 0xb8) = *(undefined4 *)(uVar45 + 0x170);
          if (uVar38 <= uVar45) goto LAB_fffffff00a4f8a08;
          *(undefined4 *)(local_198 + 0xbc) = *(undefined4 *)(uVar45 + 0x174);
        }
        bVar30 = false;
        if (*(int *)(param_1 + 0x1c4) != (int)local_240) {
          *(int *)(param_1 + 0x1c4) = (int)local_240;
        }
        uVar43 = 1;
        uVar27 = DAT_fffffff00ad7ce40;
      }
    }
    DAT_fffffff00ad7ce40 = uVar27;
    if ((1 < iVar32) || (1 < DAT_fffffff00ad7ce48)) {
      uVar45 = *(ulong *)(param_1 + 0x40);
      iVar34 = FUN_fffffff00a4ecdf8(uVar45);
      uVar38 = uVar45 | 0xffffff8000000000;
      if (iVar34 == 0) {
        if ((((uVar45 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar38)) &&
           (uVar38 < 0xfffffffc00000000)) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        uVar39 = uVar45 & 0x7ffffffffff;
        if ((uVar45 & 0x80000000000000) != 0) {
          uVar39 = uVar38;
        }
        FUN_fffffff00a396010(uVar39);
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar27,0,
                 "%s: DATA-TRACE: Socket Policy - Send/Recv: <%llx> (BoundInterface %d Proto %d) Policy %d Result %d Parameter %d Allowed %d <filter_control_unit %d flow_divert_aggregate_unit %d>\n"
                );
    }
  }
  uVar36 = FUN_fffffff00a4eb308(lVar44,&local_220,1);
  uVar27 = DAT_fffffff00ad7ce10;
  if ((uVar47 & uVar36) == 1) {
    uStack_d8 = 0;
    local_e0 = 0;
    uStack_c8 = 0;
    local_d0 = 0;
    uStack_f8 = 0;
    local_100 = 0;
    uStack_e8 = 0;
    local_f0 = 0;
    uStack_118 = 0;
    local_120 = 0;
    uStack_108 = 0;
    local_110 = 0;
    uStack_138 = 0;
    local_140 = 0;
    uStack_128 = 0;
    local_130 = 0;
    iVar34 = FUN_fffffff00a4ecdf8(uVar42);
    uVar38 = uVar42 | 0xffffff8000000000;
    if (iVar34 == 0) {
      if ((((uVar42 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar38)) &&
         (uVar38 < 0xfffffffc00000000)) {
        FUN_fffffff00a1d12d4();
      }
    }
    else {
      uVar45 = uVar42 & 0x7ffffffffff;
      if ((uVar42 & 0x80000000000000) != 0) {
        uVar45 = uVar38;
      }
      FUN_fffffff00a396010(uVar45);
    }
    FUN_fffffff00a4eb1ec(&uStack_210,&local_100);
    FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_140);
    FUN_fffffff00a8df19c
              (&MACH_HEADER,uVar27,0x10,
               "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d> <input ifindex %d> <allowed_to_receive %d><pf_tag %X pass_flags %X><gen_count inp %d current %d>\n"
              );
    uVar43 = 0;
  }
  else {
    uVar43 = uVar43 & (uVar36 ^ 1);
  }
  FUN_fffffff00a228d30(&DAT_fffffff00adcd940);
  if ((bVar30) && (*(int *)(param_1 + 0x1b4) == 0)) {
    *(undefined4 *)(param_1 + 0x1b4) = 1;
    lVar41 = uVar42 + 0x354;
    lVar44 = uVar42 + 0x364;
    if ((*(uint *)(uVar42 + 0x230) & 0x10000000) != 0) {
      lVar41 = uVar42 + 0x364;
      lVar44 = uVar42 + 0x374;
    }
    if ((ulong)(lVar44 - lVar41) < 0x10) {
LAB_fffffff00a4f8a08:
                    /* WARNING: Does not return */
      pcVar28 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a4f8a0c);
      (*pcVar28)();
    }
    lVar44 = 0x21c;
    if ((*(uint *)(uVar42 + 0x230) & 0x10000000) != 0) {
      lVar44 = 0x344;
    }
    FUN_fffffff00a4eb480(*(undefined4 *)(uVar42 + lVar44),lVar41,1);
  }
LAB_fffffff00a4f69c8:
  if (param_9 != (uint *)0x0) {
    *param_9 = uVar46;
  }
  uVar47 = uVar43 ^ 1;
  if (param_5 == 0) {
    uVar47 = 1;
  }
  if ((uVar47 == 0) && (uVar43 = uVar46 >> 1 & 1, param_5 != 0xff01)) {
    uVar43 = 1;
  }
  if ((uVar43 == 0) && (local_228._4_4_ != 0)) {
    FUN_fffffff00a7a8c80(*(undefined8 *)(param_1 + 0x40),0x41);
  }
  if (local_238 != 0) {
    FUN_fffffff00a724838();
  }
  if (local_198 != 0) {
    FUN_fffffff00a7d8ee8();
  }
  if (DAT_fffffff00ad30000 == local_78) {
    return uVar43;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590();
}

