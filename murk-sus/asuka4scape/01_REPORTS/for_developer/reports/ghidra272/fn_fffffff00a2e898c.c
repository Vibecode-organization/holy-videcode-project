// FUN_fffffff00a2e898c @ fffffff00a2e898c size=1696

ulong FUN_fffffff00a2e898c
                (undefined *****param_1,ulong param_2,long param_3,int param_4,uint param_5)

{
  uint uVar1;
  long *plVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  uint *puVar8;
  long *plVar9;
  ulong *puVar10;
  undefined4 *puVar11;
  long *plVar12;
  ulong uVar13;
  ushort uVar14;
  long *plVar15;
  ulong *****pppppuVar16;
  uint uVar17;
  ulong uVar18;
  ulong uVar19;
  byte bVar20;
  ulong uVar21;
  uint *puVar22;
  ulong uVar23;
  undefined ****ppppuVar24;
  undefined ****ppppuVar25;
  uint *puVar26;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined1 auVar27 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined1 in_register_00005044 [12];
  undefined4 in_s3;
  undefined1 in_register_00005064 [12];
  undefined4 in_s4;
  undefined4 in_s5;
  undefined *local_140;
  undefined8 local_138;
  code *local_130;
  undefined *local_128;
  undefined8 *puStack_120;
  int local_118;
  uint local_110 [2];
  undefined ****local_108;
  ulong local_100;
  ulong uStack_f8;
  ulong local_f0;
  uint *puStack_e8;
  undefined **local_e0;
  undefined8 local_d8;
  ulong local_d0 [7];
  uint *local_98;
  undefined8 local_88;
  undefined8 *local_80;
  undefined8 local_78;
  uint local_70;
  
  local_80 = &local_88;
  local_88 = 0;
  local_78 = DAT_fffffff00700da58;
  local_d0[5] = 0;
  local_d0[4] = 0;
  local_98 = (uint *)0x0;
  local_d0[6] = 0;
  local_d0[1] = 0;
  local_d0[0] = 0;
  local_d0[3] = 0;
  local_d0[2] = 0;
  puStack_e8 = (uint *)0x0;
  local_f0 = 0;
  local_d8 = 0;
  local_e0 = (undefined **)0x0;
  uStack_f8 = 0;
  local_100 = 0;
  if ((param_5 & 0xffffffe8) != 0) {
    local_70 = 0;
    uVar7 = 4;
    goto LAB_fffffff00a2e8f48;
  }
  uVar7 = param_3 - param_2;
  local_70 = param_5;
  if (param_1 == (undefined *****)0x0) {
    if (uVar7 != 0) {
      if (!CARRY8(param_2,uVar7)) {
        ppppuVar24 = (undefined ****)(param_2 & 0xffffffffffffc000);
        ppppuVar25 = (undefined ****)(param_2 + uVar7 + 0x3fff & 0xffffffffffffc000);
        if (ppppuVar24 < ppppuVar25) goto LAB_fffffff00a2e8a60;
      }
      uVar13 = 0x3fff;
      goto LAB_fffffff00a2e8fbc;
    }
  }
  else if (uVar7 != 0) {
    uVar13 = (ulong)(uint)~(-1 << (ulong)(*(byte *)((long)param_1 + 0x2c) & 0x1f));
    if (CARRY8(param_2,uVar7)) {
LAB_fffffff00a2e8fbc:
      uVar7 = FUN_fffffff00a345aa8(4,param_2,uVar7,uVar13);
      ppppuVar24 = (undefined ****)(uVar7 & 0xffffffff);
      ppppuVar25 = ppppuVar24;
      if ((int)uVar7 != 0) {
        if ((int)uVar7 != 0x20000001) goto LAB_fffffff00a2e8f48;
        goto LAB_fffffff00a2e8f44;
      }
    }
    else {
      ppppuVar24 = (undefined ****)(param_2 & (uVar13 ^ 0xffffffffffffffff));
      ppppuVar25 = (undefined ****)(param_2 + uVar7 + uVar13 & ~uVar13);
      if (ppppuVar25 <= ppppuVar24) goto LAB_fffffff00a2e8fbc;
    }
LAB_fffffff00a2e8a60:
    if (0xf < param_5) {
      uVar7 = 1;
      if (param_1[3] <= ppppuVar24) goto LAB_fffffff00a2e8f48;
      local_110[0] = param_5 & 7;
      local_110[1] = 0;
      pppppuVar16 = (ulong *****)0x8040000004001;
      if (((ulong)param_1[0x1f] & 0x10000) != 0) {
        pppppuVar16 = (ulong *****)0x40000004001;
      }
      local_108 = ppppuVar24;
      uVar7 = FUN_fffffff00a2e902c
                        (param_1,(ulong *)&local_108,
                         (undefined *****)((long)ppppuVar25 - (long)ppppuVar24),(undefined *****)0x0
                         ,pppppuVar16,param_1,(ulong)ppppuVar24,1,local_110 + 1,local_110,1);
      if ((int)uVar7 != 0) goto LAB_fffffff00a2e8f48;
      *(uint *)(local_80 + 3) = *(uint *)(local_80 + 3) & 0xffffffef;
    }
    plVar2 = (long *)tpidr_el1;
    *(int *)((long)plVar2 + 0x21c) = *(int *)((long)plVar2 + 0x21c) + 1;
    if ((((ulong)param_1[7] & 0xffffffff0001ffff) == 0x10000) &&
       (*(int *)((long)param_1 + 0x3c) == 0)) {
      *(int *)((long)param_1 + 0x3c) = 2;
    }
    else {
      FUN_fffffff00a22a2a0((ulong)(param_1 + 6),plVar2,0);
    }
    *(int *)((long)param_1 + 0x34) = (int)plVar2[0x9d];
    if (ppppuVar24 < param_1[3]) {
      local_e0 = &local_140;
      local_140 = &DAT_fffffff00ad98dc0;
      local_138 = DAT_fffffff00700da60;
      local_130 = FUN_fffffff00a2e9730;
      puStack_120 = &local_88;
      local_128 = &DAT_fffffff007bca278;
      local_118 = param_4;
      auVar27 = FUN_fffffff00a22a9a8((ulong)(param_1 + 6));
      uVar5 = FUN_fffffff00a348784
                        (auVar27,in_q1,in_s2,in_s3,in_s4,in_s5,&local_100,(ulong)param_1,
                         (ulong)ppppuVar24,(ulong)ppppuVar25,(undefined **)0x6029);
      auVar27._8_8_ = extraout_var;
      auVar27._0_8_ = extraout_d0;
      uVar7 = (ulong)uVar5;
      if (uVar5 == 0) {
        uVar7 = 0;
LAB_fffffff00a2e8b5c:
        uVar18 = local_d8;
        uVar5 = (uint)local_d8;
        uVar13 = local_d0[0];
        uVar19 = local_100;
        uVar21 = local_d0[6];
        puVar22 = local_98;
        uVar23 = uStack_f8;
        puVar26 = puStack_e8;
        uVar14 = local_d8._4_2_;
        do {
          uVar6 = uVar19;
          uVar19 = uVar6;
          if (puVar26 == (uint *)0x0) {
            local_d8 = CONCAT26(local_d8._6_2_,CONCAT24(uVar14,(uint)local_d8)) & 0xfffffffdffffffff
            ;
            puVar10 = local_d0;
            uVar14 = uVar14 & 0xfffd;
          }
          else {
            puVar8 = puVar22;
            if (((uVar14 & 0xc) == 8) && (uVar23 <= *(ulong *)(puVar26 + 6))) {
              local_100 = local_d0[3];
              if ((uVar5 >> 2 & 1) != 0) {
                uVar13 = uVar21 + uVar13;
                local_d0[0] = uVar13;
                local_100 = uVar6 + uVar21;
              }
              uVar21 = 0;
              local_f0 = local_d0[5];
              uStack_f8 = local_d0[4];
              local_d8 = CONCAT26(local_d8._6_2_,CONCAT24(uVar14,(uint)local_d8)) &
                         0xfffffff3ffffffff;
              local_d0[6] = 0;
              local_98 = (uint *)0x0;
              puVar8 = (uint *)0x0;
              uVar19 = local_100;
              puVar26 = puVar22;
              uVar23 = local_d0[4];
              uVar14 = uVar14 & 0xfff3;
            }
            uVar6 = *(ulong *)(puVar26 + 6);
            if (uVar23 <= uVar6) goto LAB_fffffff00a2e8eb4;
            puVar10 = (ulong *)(puVar26 + 2);
            puVar22 = puVar8;
          }
          puVar26 = (uint *)*puVar10;
          puVar11 = *(undefined4 **)(puVar26 + 10);
        } while (puVar11 == &DAT_fffffff00adbb500);
        if (((~(uint)puVar11 & 3) == 0 && (uVar18 & 0x40000) != 0) && ((puVar26[9] & 1) == 0)) {
          uStack_f8 = local_d0[4];
          if (*(ulong *)(puVar26 + 6) <= local_d0[4]) {
            uStack_f8 = *(ulong *)(puVar26 + 6);
          }
          local_d0[6] = *(long *)(puVar26 + 4) - (*(ulong *)(puVar26 + 0xc) & 0xfffffffffffff000);
          local_100 = uVar6 - local_d0[6];
          uStack_f8 = uStack_f8 - local_d0[6];
          local_f0 = (ulong)puVar11 & 0xfffffffffffffffc;
          puStack_e8 = (uint *)0x0;
          local_d8 = CONCAT26(local_d8._6_2_,CONCAT24(uVar14,(uint)local_d8)) & 0xfffffff3ffffffff |
                     0x800000000;
          if ((uVar5 >> 2 & 1) != 0) {
            local_d0[0] = local_100;
          }
          local_98 = puVar26;
          puVar26 = (uint *)FUN_fffffff00a2e1054(local_f0,local_100);
          auVar27._8_8_ = extraout_var_00;
          auVar27._0_8_ = extraout_d0_00;
          if (puVar26 == (uint *)0x0) goto LAB_fffffff00a2e8f78;
        }
        uVar13 = local_f0;
        uVar5 = puVar26[0xe];
        uVar1 = uVar5 >> 4 & 7;
        if (param_4 == 0) {
          uVar17 = uVar5 & 0xffffff80 | uVar5 & 0xf | (*(uint *)(local_80 + 3) & 7) << 4;
        }
        else {
          uVar17 = (*(uint *)(local_80 + 3) & 0xf) << 8;
          puVar26[0xe] = uVar5 & 0xfffff000 | uVar5 & 0xff | uVar17;
          uVar17 = uVar5 & 0xfffff000 | uVar5 & 0x80 | uVar17 |
                   uVar5 & 0xf | (*(uint *)(local_80 + 3) & uVar1) << 4;
        }
        puVar26[0xe] = uVar17;
        puStack_e8 = puVar26;
        if (((uVar17 >> 0x13 & 1) == 0) && (uVar1 < 4)) {
          if ((uVar17 >> 6 & 1) != 0) {
LAB_fffffff00a2e8cfc:
            FUN_fffffff00a2e98a0(local_f0,(long)puVar26,0x40000000000);
            auVar27._8_8_ = extraout_var_01;
            auVar27._0_8_ = extraout_d0_01;
            uVar17 = puVar26[0xe];
          }
        }
        else if (((uVar17 >> 5 & 1) != 0) && ((uVar17 & 0x80000) != 0 && (uVar5 & 0x20) == 0))
        goto LAB_fffffff00a2e8cfc;
        uVar5 = uVar17 >> 4 & 7;
        if (uVar5 != uVar1) {
          uVar18 = *(ulong *)(puVar26 + 10);
          uVar19 = uVar18 & 3;
          if (((uVar19 == 3) || (uVar19 != 0)) ||
             ((undefined4 *)(uVar18 & 0xfffffffffffffffc) != &DAT_fffffff00adbb400)) {
            uVar5 = uVar17 >> 4 & 5;
          }
          else {
            uVar7 = (ulong)((uVar17 & 0x20) << 7 | (uint)uVar7);
          }
          plVar15 = *(long **)(uVar13 + 0x58);
          if ((plVar15 == (long *)0x0) || (plVar15 == (long *)0x0)) {
            bVar20 = 1;
          }
          else {
            bVar20 = *(byte *)(plVar15[4] + 0x4c) ^ 1;
          }
          if ((uVar5 == 7) && ((bVar20 & 1) != 0)) {
            if ((short)puVar26[0xf] != 0) {
              auVar3._4_12_ = in_register_00005044;
              auVar3._0_4_ = in_s2;
              auVar4._4_12_ = in_register_00005064;
              auVar4._0_4_ = in_s3;
                    /* WARNING: Subroutine does not return */
              FUN_fffffff00aa4d114
                        (auVar27,in_q1,auVar3,auVar4,in_s4,in_s5,
                         (byte *)"vm_map_protect(%p,0x%llx,0x%llx) new=0x%x wired=%x @%s:%d");
            }
            uVar5 = 0;
          }
          if ((uVar19 == 3) && ((uVar17 >> 0xe & 1) != 0)) {
            plVar15 = *(long **)((uVar18 & 0xfffffffffffffffc) + 0x58);
            if (plVar15 == (long *)0x0) {
              plVar15 = (long *)0x0;
            }
            plVar9 = *(long **)(puVar26 + 4);
            plVar12 = *(long **)(puVar26 + 6);
            uVar13 = 0;
          }
          else {
            if (plVar15 == (long *)0x0) {
              plVar15 = (long *)0x0;
            }
            plVar9 = *(long **)(puVar26 + 4);
            plVar12 = *(long **)(puVar26 + 6);
            uVar13 = uVar7;
          }
          auVar27 = FUN_fffffff00a378104(plVar15,plVar9,plVar12,uVar5,uVar13);
        }
        goto LAB_fffffff00a2e8b5c;
      }
      plVar2[0x45] = 0;
    }
    else {
      FUN_fffffff00a22a910((ulong)(param_1 + 6));
      uVar7 = 1;
    }
    goto LAB_fffffff00a2e8f48;
  }
LAB_fffffff00a2e8f44:
  uVar7 = 0;
LAB_fffffff00a2e8f48:
  FUN_fffffff00a8eddac((long)&local_88,8);
  return uVar7;
LAB_fffffff00a2e8f78:
  uVar6 = 0;
  uVar5 = (uint)local_d8;
LAB_fffffff00a2e8eb4:
  puStack_e8 = (uint *)0x0;
  plVar2[0x45] = 0;
  if ((local_d8._4_2_ & 0xc) == 8) {
    uVar7 = local_d0[3];
    if (((byte)local_d8 >> 2 & 1) != 0) {
      local_d0[0] = local_d0[6] + local_d0[0];
      uVar7 = local_100 + local_d0[6];
    }
    puStack_e8 = local_98;
    local_f0 = local_d0[5];
    uStack_f8 = local_d0[4];
    local_d8 = local_d8 & 0xfffffff3ffffffff;
    local_d0[6] = 0;
    local_98 = (uint *)0x0;
    local_100 = uVar7;
  }
  if ((uVar5 >> 2 & 1) == 0) {
    FUN_fffffff00a34ab40((long)&local_100);
  }
  else if ((puStack_e8 != (uint *)0x0) &&
          (((~puStack_e8[10] & 3) != 0 || ((puStack_e8[9] & 1) == 0)))) {
    FUN_fffffff00a346378(uVar6,puStack_e8);
  }
  goto LAB_fffffff00a2e8f44;
}

