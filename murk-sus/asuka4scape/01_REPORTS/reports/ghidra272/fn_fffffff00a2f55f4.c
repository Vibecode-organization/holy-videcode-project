// FUN_fffffff00a2f55f4 @ fffffff00a2f55f4 size=3376

ulong FUN_fffffff00a2f55f4
                (long param_1,ulong param_2,ulong param_3,ulong *param_4,ulong param_5,ulong param_6
                ,uint param_7,ulong param_8)

{
  undefined8 *puVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  long lVar10;
  ulong uVar11;
  undefined4 *puVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  ulong *puVar16;
  ulong uVar17;
  long lVar18;
  ushort uVar19;
  ulong uVar20;
  long lVar21;
  ulong uVar22;
  long lVar23;
  ulong uVar24;
  undefined8 in_stack_fffffffffffffe18;
  undefined4 uVar25;
  ulong local_1c8;
  ulong local_180;
  ulong *local_178;
  long local_170;
  long *local_168;
  ulong local_160;
  ulong uStack_158;
  ulong local_150;
  long lStack_148;
  undefined *local_140;
  uint local_138;
  ushort local_134;
  undefined2 uStack_132;
  undefined8 uStack_130;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined8 local_100;
  undefined4 local_f8;
  undefined4 uStack_f4;
  ulong local_f0;
  ulong uStack_e8;
  ulong local_e0;
  long lStack_d8;
  undefined8 uStack_d0;
  uint local_c8;
  ushort local_c4;
  undefined2 uStack_c2;
  undefined8 uStack_c0;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 uStack_84;
  long local_80;
  ulong local_78 [3];
  long *plVar9;
  
  uVar25 = (undefined4)((ulong)in_stack_fffffffffffffe18 >> 0x20);
  uVar17 = param_3 + param_2;
  if (param_1 == 0) {
    uVar4 = 0xe;
  }
  else {
    uVar4 = (uint)*(byte *)(param_1 + 0x2c);
  }
  local_78[0] = uVar17;
  if ((*(undefined8 **)(param_1 + 0x58) != (undefined8 *)0x0) &&
     (*(undefined8 **)(param_1 + 0x58) == &DAT_fffffff00ad6cc50)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4d114("%s: tried to relocate entries in the kernel map (map = %p) @%s:%d");
  }
  if (*(char *)(param_1 + 0x2c) != '\x0e') {
    return 0x2e;
  }
  if (param_5 < param_3) {
    return 4;
  }
  uVar24 = (ulong)(uint)~(-1 << (ulong)(uVar4 & 0x1f));
  param_6 = param_6 | uVar24;
  uVar22 = param_8 & 1;
  if ((~(uint)param_8 & 0x4001) == 0) {
    uVar14 = *param_4;
    if ((uVar14 < uVar17) && (param_2 < uVar14 + param_5)) {
      return 1;
    }
  }
  else {
    if ((param_5 == param_3) && ((param_6 & param_2) == 0 && uVar22 == 0)) {
      *param_4 = param_2;
      return 0;
    }
    uVar14 = *param_4;
  }
  local_80 = param_1;
  if ((uVar22 == 0) || (param_2 <= uVar14)) {
    bVar2 = false;
    uStack_98 = 0;
    uStack_94 = 0;
    uStack_a0 = 0;
    uStack_9c = 0;
    local_88 = 0;
    uStack_84 = 0;
    local_90._0_4_ = 0;
    local_90._4_4_ = 0;
    uStack_b8 = 0;
    uStack_b4 = 0;
    uStack_c0._0_4_ = 0;
    uStack_c0._4_4_ = 0;
    uStack_a8 = 0;
    uStack_a4 = 0;
    uStack_b0 = 0;
    uStack_ac = 0;
    lStack_d8 = 0;
    local_e0 = 0;
    local_c8 = 0;
    local_c4 = 0;
    uStack_c2 = 0;
    uStack_d0 = 0;
    uStack_e8 = 0;
    local_f0 = 0;
  }
  else {
    uStack_98 = 0;
    uStack_94 = 0;
    uStack_a0 = 0;
    uStack_9c = 0;
    local_88 = 0;
    uStack_84 = 0;
    local_90._0_4_ = 0;
    local_90._4_4_ = 0;
    uStack_b8 = 0;
    uStack_b4 = 0;
    uStack_c0._0_4_ = 0;
    uStack_c0._4_4_ = 0;
    uStack_a8 = 0;
    uStack_a4 = 0;
    uStack_b0 = 0;
    uStack_ac = 0;
    lStack_d8 = 0;
    local_e0 = 0;
    local_c8 = 0;
    local_c4 = 0;
    uStack_c2 = 0;
    uStack_d0 = 0;
    uStack_e8 = 0;
    local_f0 = 0;
    if (((uint)param_8 >> 0xe & 1) == 0) {
      bVar2 = false;
    }
    else {
      uVar6 = CONCAT44(uVar25,2);
      uVar4 = FUN_fffffff00a2e387c
                        (param_1,param_4,param_5,param_6,param_8 | 0x10000000000,0,0,0,0,uVar6);
      uVar25 = (undefined4)((ulong)uVar6 >> 0x20);
      if (uVar4 != 0) {
        if (uVar4 != 3) {
          uVar4 = 0x2e;
        }
        return (ulong)uVar4;
      }
      FUN_fffffff00a347aec(&local_f0,&local_80,*param_4,param_5);
      bVar2 = true;
    }
  }
  local_1c8 = param_8 | 0x10000000000;
  uStack_108 = 0;
  uStack_104 = 0;
  uStack_110 = 0;
  uStack_10c = 0;
  local_f8 = 0;
  uStack_f4 = 0;
  local_100._0_4_ = 0;
  local_100._4_4_ = 0;
  uStack_128 = 0;
  uStack_124 = 0;
  uStack_130._0_4_ = 0;
  uStack_130._4_4_ = 0;
  uStack_118 = 0;
  uStack_114 = 0;
  uStack_120 = 0;
  uStack_11c = 0;
  lStack_148 = 0;
  local_150 = 0;
  local_138 = 0;
  local_134 = 0;
  uStack_132 = 0;
  uStack_158 = 0;
  local_160 = 0;
  local_140 = &DAT_fffffff007bca3c8;
  FUN_fffffff00a229514(param_1 + 0x30);
  uVar14 = FUN_fffffff00a348784(&local_160,param_1,param_2,uVar17,0x29);
  if ((int)uVar14 != 0) {
    lVar18 = tpidr_el1;
    *(undefined8 *)(lVar18 + 0x228) = 0;
    local_150 = 0;
    lStack_148 = 0;
    uStack_130._4_4_ = 0;
    uStack_128 = 0;
    local_134 = 0;
    uStack_132 = 0;
    uStack_130._0_4_ = 0;
    uStack_11c = 0;
    uStack_118 = 0;
    uStack_124 = 0;
    uStack_120 = 0;
    uStack_10c = 0;
    uStack_108 = 0;
    uStack_114 = 0;
    uStack_110 = 0;
    local_100._4_4_ = 0;
    local_f8 = 0;
    uStack_104 = 0;
    local_100._0_4_ = 0;
    uStack_f4 = 0;
    if (!bVar2) {
      return uVar14;
    }
    *(undefined8 *)(lVar18 + 0x228) = 0;
    if ((local_c4 & 0xc) == 8) {
      if (((byte)local_c8 >> 2 & 1) == 0) {
        local_f0 = CONCAT44(uStack_a4,uStack_a8);
      }
      else {
        uStack_c0 = CONCAT44(local_90._4_4_,(undefined4)local_90) +
                    CONCAT44(uStack_c0._4_4_,(undefined4)uStack_c0);
        local_f0 = local_f0 + CONCAT44(local_90._4_4_,(undefined4)local_90);
      }
      lStack_d8 = CONCAT44(uStack_84,local_88);
      local_e0 = CONCAT44(uStack_94,uStack_98);
      uStack_e8 = CONCAT44(uStack_9c,uStack_a0);
      local_c4 = local_c4 & 0xfff3;
      local_90._0_4_ = 0;
      local_90._4_4_ = 0;
      local_88 = 0;
      uStack_84 = 0;
    }
    if ((local_c8 >> 2 & 1) == 0) {
      FUN_fffffff00a34ab40(&local_f0);
      return uVar14;
    }
    if (lStack_d8 == 0) {
      return uVar14;
    }
    if (((~*(uint *)(lStack_d8 + 0x28) & 3) == 0) && ((*(uint *)(lStack_d8 + 0x24) & 1) != 0)) {
      return uVar14;
    }
    FUN_fffffff00a346378();
    return uVar14;
  }
  for (lVar18 = CONCAT44(uStack_130._4_4_,(undefined4)uStack_130);
      *(undefined4 **)(lVar18 + 0x28) == &DAT_fffffff00adbb500; lVar18 = *(long *)(lVar18 + 8)) {
  }
  uVar4 = *(uint *)(lVar18 + 0x38);
  if ((uVar22 == 0 && (param_6 & param_2) == 0) && (*(long *)(param_1 + 0xd8) == 0)) {
    uVar22 = CONCAT44(uVar25,uVar4 >> 0xc) & 0xffffffff00000003;
    uVar6 = FUN_fffffff00a2e387c
                      (param_1,local_78,param_5 - param_3,uVar24,param_8 & 0xfff000000 | 1,0,0,0,
                       CONCAT44(uVar4 >> 8,uVar4 >> 4) & 0xf00000007,uVar22);
    uVar25 = (undefined4)(uVar22 >> 0x20);
    if ((int)uVar6 == 0) {
      lVar18 = tpidr_el1;
      *(undefined8 *)(lVar18 + 0x228) = 0;
      if ((local_134 & 0xc) == 8) {
        if (((byte)local_138 >> 2 & 1) == 0) {
          local_160 = CONCAT44(uStack_114,uStack_118);
        }
        else {
          uStack_130 = CONCAT44(local_100._4_4_,(undefined4)local_100) +
                       CONCAT44(uStack_130._4_4_,(undefined4)uStack_130);
          local_160 = local_160 + CONCAT44(local_100._4_4_,(undefined4)local_100);
        }
        lStack_148 = CONCAT44(uStack_f4,local_f8);
        local_150 = CONCAT44(uStack_104,uStack_108);
        uStack_158 = CONCAT44(uStack_10c,uStack_110);
        local_134 = local_134 & 0xfff3;
        local_100._0_4_ = 0;
        local_100._4_4_ = 0;
        local_f8 = 0;
        uStack_f4 = 0;
      }
      if ((local_138 >> 2 & 1) == 0) {
        FUN_fffffff00a34ab40(&local_160);
      }
      else if ((lStack_148 != 0) &&
              (((~*(uint *)(lStack_148 + 0x28) & 3) != 0 ||
               ((*(uint *)(lStack_148 + 0x24) & 1) == 0)))) {
        FUN_fffffff00a346378(uVar6,lStack_148,param_5);
      }
      *param_4 = param_2;
      return 0;
    }
  }
  if (!bVar2) {
    uVar3 = FUN_fffffff00a2e387c
                      (param_1,param_4,param_5,param_6,local_1c8,0,0,0,0,CONCAT44(uVar25,2));
    if (uVar3 != 0) {
      lVar18 = tpidr_el1;
      *(undefined8 *)(lVar18 + 0x228) = 0;
      if ((local_134 & 0xc) == 8) {
        if (((byte)local_138 >> 2 & 1) == 0) {
          local_160 = CONCAT44(uStack_114,uStack_118);
        }
        else {
          uStack_130 = CONCAT44(local_100._4_4_,(undefined4)local_100) +
                       CONCAT44(uStack_130._4_4_,(undefined4)uStack_130);
          local_160 = local_160 + CONCAT44(local_100._4_4_,(undefined4)local_100);
        }
        lStack_148 = CONCAT44(uStack_f4,local_f8);
        local_150 = CONCAT44(uStack_104,uStack_108);
        uStack_158 = CONCAT44(uStack_10c,uStack_110);
        local_134 = local_134 & 0xfff3;
        local_100._0_4_ = 0;
        local_100._4_4_ = 0;
        local_f8 = 0;
        uStack_f4 = 0;
      }
      if ((local_138 >> 2 & 1) == 0) {
        FUN_fffffff00a34ab40(&local_160);
      }
      else if ((lStack_148 != 0) &&
              (((~*(uint *)(lStack_148 + 0x28) & 3) != 0 ||
               ((*(uint *)(lStack_148 + 0x24) & 1) == 0)))) {
        FUN_fffffff00a346378();
      }
      if (uVar3 != 3) {
        uVar3 = 0x2e;
      }
      return (ulong)uVar3;
    }
    FUN_fffffff00a347aec(&local_f0,&local_80,*param_4,param_5);
  }
  local_168 = &local_170;
  local_170 = 0;
  lVar18 = tpidr_el1;
  *(int *)(lVar18 + 0x21c) = *(int *)(lVar18 + 0x21c) + 1;
  if (((*(ulong *)(param_1 + 0x38) & 0xffffffff0001ffff) == 0x10000) &&
     (*(int *)(param_1 + 0x3c) == 0)) {
    *(int *)(param_1 + 0x3c) = 2;
  }
  else {
    FUN_fffffff00a22a2a0(param_1 + 0x30,lVar18,0);
  }
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(lVar18 + 0x4e8);
  uVar3 = (param_7 & 1) << 6;
  uVar24 = 0xffffffffffffffff;
  uVar14 = 0;
  uVar22 = CONCAT44(uStack_130._4_4_,(undefined4)uStack_130);
  lVar23 = CONCAT44(local_100._4_4_,(undefined4)local_100);
  do {
    uVar11 = CONCAT44(uStack_10c,uStack_110);
    lVar21 = CONCAT44(uStack_f4,local_f8);
    lVar10 = lStack_148;
    uVar15 = local_160;
    uVar20 = uStack_158;
    uVar19 = local_134;
    uStack_130 = uVar22;
    local_100 = lVar23;
    do {
      uVar7 = uVar15;
      uVar15 = uVar7;
      if (lVar10 == 0) {
        local_134 = uVar19 & 0xfffd;
        plVar9 = &uStack_130;
        uVar19 = local_134;
      }
      else {
        lVar8 = lVar21;
        if (((uVar19 & 0xc) == 8) && (uVar20 <= *(ulong *)(lVar10 + 0x18))) {
          local_160 = CONCAT44(uStack_114,uStack_118);
          if ((local_138 >> 2 & 1) != 0) {
            uVar22 = lVar23 + uVar22;
            uStack_130._0_4_ = (undefined4)uVar22;
            uStack_130._4_4_ = (undefined4)(uVar22 >> 0x20);
            local_160 = uVar7 + lVar23;
            uStack_130 = uVar22;
          }
          lVar23 = 0;
          local_134 = uVar19 & 0xfff3;
          local_100._0_4_ = 0;
          local_100._4_4_ = 0;
          local_100 = 0;
          local_f8 = 0;
          uStack_f4 = 0;
          lVar8 = 0;
          uVar15 = local_160;
          uVar20 = uVar11;
          lVar10 = lVar21;
          uStack_158 = uVar11;
          local_150 = CONCAT44(uStack_104,uStack_108);
          uVar19 = local_134;
        }
        uVar7 = *(ulong *)(lVar10 + 0x18);
        if (uVar20 <= uVar7) {
          lStack_148 = 0;
          goto LAB_fffffff00a2f5b04;
        }
        plVar9 = (long *)(lVar10 + 8);
        lVar21 = lVar8;
      }
      lVar10 = *plVar9;
      puVar12 = *(undefined4 **)(lVar10 + 0x28);
    } while (puVar12 == &DAT_fffffff00adbb500);
    if (((~(uint)puVar12 & 3) == 0 && (local_138 & 0x40000) != 0) &&
       ((*(uint *)(lVar10 + 0x24) & 1) == 0)) {
      if (*(ulong *)(lVar10 + 0x18) <= uVar11) {
        uVar11 = *(ulong *)(lVar10 + 0x18);
      }
      local_100 = *(long *)(lVar10 + 0x10) - (*(ulong *)(lVar10 + 0x30) & 0xfffffffffffff000);
      local_160 = uVar7 - local_100;
      uStack_158 = uVar11 - local_100;
      local_150 = (ulong)puVar12 & 0xfffffffffffffffc;
      lStack_148 = 0;
      local_134 = uVar19 & 0xfff3 | 8;
      local_f8 = (undefined4)lVar10;
      uStack_f4 = (undefined4)((ulong)lVar10 >> 0x20);
      if ((local_138 >> 2 & 1) != 0) {
        uStack_130 = local_160;
      }
      lVar10 = FUN_fffffff00a2e1054(local_150,local_160);
      lStack_148 = lVar10;
      if (lVar10 == 0) {
LAB_fffffff00a2f5b04:
        if ((uVar24 == param_2) && (uVar14 == uVar17)) {
          if ((local_134 & 0xc) == 8) {
            if (((byte)local_138 >> 2 & 1) == 0) {
              local_160 = CONCAT44(uStack_114,uStack_118);
            }
            else {
              uStack_130 = local_100 + uStack_130;
              local_160 = local_160 + local_100;
            }
            uStack_158 = CONCAT44(uStack_10c,uStack_110);
            local_150 = CONCAT44(uStack_104,uStack_108);
            local_134 = local_134 & 0xfff3;
            local_100 = 0;
            local_f8 = 0;
            uStack_f4 = 0;
          }
          local_134 = local_134 | 2;
          lStack_148 = 0;
          iVar5 = FUN_fffffff00a2dffb4
                            (param_1,param_2,uVar17,uVar3 | 0x20000000,0,&local_170,&local_160);
          if (iVar5 == 0) {
            lVar23 = 0;
            param_3 = *param_4 + param_3;
            uVar17 = CONCAT44(uStack_c0._4_4_,(undefined4)uStack_c0);
            lVar21 = CONCAT44(local_90._4_4_,(undefined4)local_90);
            break;
          }
        }
LAB_fffffff00a2f62fc:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114
                  (
                  "%s failed to delete source; it must have changed after it was locked (kr = %d) @%s:%d"
                  );
      }
    }
    lStack_148 = lVar10;
    iVar5 = FUN_fffffff00a2e0da0(&local_160,lVar10,uVar3,0);
    if (iVar5 != 0) goto LAB_fffffff00a2f62fc;
    uVar22 = *(ulong *)(lStack_148 + 0x10);
    if (*(ulong *)(lStack_148 + 0x10) <= local_160) {
      uVar22 = local_160;
    }
    uVar11 = *(ulong *)(lStack_148 + 0x18);
    if (uStack_158 <= *(ulong *)(lStack_148 + 0x18)) {
      uVar11 = uStack_158;
    }
    if (uVar22 <= uVar24) {
      uVar24 = uVar22;
    }
    uVar22 = uStack_130;
    lVar23 = local_100;
    if (uVar14 <= uVar11) {
      uVar14 = uVar11;
    }
  } while( true );
LAB_fffffff00a2f5bd4:
  uVar22 = CONCAT44(uStack_9c,uStack_a0);
  lVar10 = CONCAT44(uStack_84,local_88);
  lVar8 = lStack_d8;
  uVar24 = local_f0;
  uVar14 = uStack_e8;
  uVar19 = local_c4;
  uStack_c0 = uVar17;
  local_90 = lVar21;
  do {
    uVar11 = uVar24;
    uVar24 = uVar11;
    if (lVar8 == 0) {
      uVar19 = uVar19 & 0xfffd;
      local_c4 = uVar19;
      plVar9 = &uStack_c0;
    }
    else {
      lVar13 = lVar10;
      if (((uVar19 & 0xc) == 8) && (uVar14 <= *(ulong *)(lVar8 + 0x18))) {
        local_f0 = CONCAT44(uStack_a4,uStack_a8);
        if ((local_c8 >> 2 & 1) != 0) {
          uVar17 = lVar21 + uVar17;
          uStack_c0._0_4_ = (undefined4)uVar17;
          uStack_c0._4_4_ = (undefined4)(uVar17 >> 0x20);
          local_f0 = uVar11 + lVar21;
          uStack_c0 = uVar17;
        }
        lVar21 = 0;
        local_e0 = CONCAT44(uStack_94,uStack_98);
        lStack_d8 = lVar10;
        uStack_e8 = uVar22;
        uVar19 = uVar19 & 0xfff3;
        local_c4 = uVar19;
        local_90._0_4_ = 0;
        local_90._4_4_ = 0;
        local_90 = 0;
        local_88 = 0;
        uStack_84 = 0;
        lVar13 = 0;
        uVar24 = local_f0;
        lVar8 = lVar10;
        uVar14 = uVar22;
      }
      uVar11 = *(ulong *)(lVar8 + 0x18);
      if (uVar14 <= uVar11) {
        lStack_d8 = 0;
        goto LAB_fffffff00a2f5d58;
      }
      plVar9 = (long *)(lVar8 + 8);
      lVar10 = lVar13;
    }
    lVar8 = *plVar9;
    puVar12 = *(undefined4 **)(lVar8 + 0x28);
  } while (puVar12 == &DAT_fffffff00adbb500);
  if (((~(uint)puVar12 & 3) == 0 && (local_c8 & 0x40000) != 0) &&
     ((*(uint *)(lVar8 + 0x24) & 1) == 0)) {
    if (*(ulong *)(lVar8 + 0x18) <= uVar22) {
      uVar22 = *(ulong *)(lVar8 + 0x18);
    }
    local_90 = *(long *)(lVar8 + 0x10) - (*(ulong *)(lVar8 + 0x30) & 0xfffffffffffff000);
    local_f0 = uVar11 - local_90;
    uStack_e8 = uVar22 - local_90;
    local_e0 = (ulong)puVar12 & 0xfffffffffffffffc;
    lStack_d8 = 0;
    local_c4 = uVar19 & 0xfff3 | 8;
    local_88 = (undefined4)lVar8;
    uStack_84 = (undefined4)((ulong)lVar8 >> 0x20);
    if ((local_c8 >> 2 & 1) != 0) {
      uStack_c0 = local_f0;
    }
    lVar8 = FUN_fffffff00a2e1054(local_e0);
    lStack_d8 = lVar8;
    if (lVar8 == 0) goto LAB_fffffff00a2f5d58;
  }
  else {
    lStack_d8 = lVar8;
  }
  lStack_d8 = lVar8;
  if (*(ulong *)(lVar8 + 0x10) < param_3) {
    if (param_3 < *(ulong *)(lVar8 + 0x18)) {
      FUN_fffffff00a347614(&local_f0,lVar8,param_3);
    }
    lVar23 = lVar23 + 1;
    uVar17 = uStack_c0;
    lVar21 = local_90;
  }
  else {
    *(uint *)(lVar8 + 0x38) =
         *(uint *)(lVar8 + 0x38) & 0xffffc08f |
         (uVar4 >> 8 & 0xf) << 8 | (uVar4 >> 4 & 7) << 4 | (uVar4 >> 0xc & 3) << 0xc;
    uVar17 = uStack_c0;
    lVar21 = local_90;
  }
  goto LAB_fffffff00a2f5bd4;
LAB_fffffff00a2f5d58:
  *(int *)(lVar18 + 0x21c) = *(int *)(lVar18 + 0x21c) + 1;
  if (((*(ulong *)(param_1 + 0x38) & 0xffffffff0001ffff) == 0x10000) &&
     (*(int *)(param_1 + 0x3c) == 0)) {
    *(int *)(param_1 + 0x3c) = 2;
  }
  else {
    FUN_fffffff00a22a2a0(param_1 + 0x30,lVar18,0);
  }
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(lVar18 + 0x4e8);
  local_180 = 0;
  if ((local_c4 & 0xc) == 8) {
    if (((byte)local_c8 >> 2 & 1) == 0) {
      local_f0 = CONCAT44(uStack_a4,uStack_a8);
    }
    else {
      uStack_c0 = local_90 + uStack_c0;
      local_f0 = local_f0 + local_90;
    }
    uStack_e8 = CONCAT44(uStack_9c,uStack_a0);
    local_c4 = local_c4 & 0xfff3;
    local_90._0_4_ = 0;
    local_90._4_4_ = 0;
    local_90 = 0;
    local_88 = 0;
    uStack_84 = 0;
    local_e0 = CONCAT44(uStack_94,uStack_98);
  }
  local_c4 = local_c4 | 2;
  lStack_d8 = 0;
  local_178 = &local_180;
  if (lVar23 != 0) {
    lVar21 = 0;
    uVar17 = local_e0;
    uVar22 = uStack_c0;
joined_r0xfffffff00a2f5e0c:
    do {
      uVar24 = uVar22;
      local_e0 = uVar17;
      if (uVar22 != 0) {
        if (*(ulong *)(uVar22 + 0x18) < uStack_e8) {
          uVar24 = *(ulong *)(uVar22 + 8);
        }
        else {
          uVar24 = 0;
        }
        uStack_c0._0_4_ = (undefined4)uVar24;
        uStack_c0._4_4_ = (undefined4)(uVar24 >> 0x20);
        if (*(undefined4 **)(uVar22 + 0x28) == &DAT_fffffff00adbb500) {
          *(int *)(lVar18 + 0x21c) = *(int *)(lVar18 + 0x21c) + 1;
          uStack_c0 = uVar24;
          if (((*(ulong *)(uVar17 + 0x38) & 0xffffffff0001ffff) == 0x10000) &&
             (*(int *)(uVar17 + 0x3c) == 0)) {
            *(int *)(uVar17 + 0x3c) = 2;
          }
          else {
            FUN_fffffff00a22a2a0(uVar17 + 0x30,lVar18,0);
          }
          *(undefined4 *)(uVar17 + 0x34) = *(undefined4 *)(lVar18 + 0x4e8);
          FUN_fffffff00a2fe6c0(local_e0,uVar22,0);
          FUN_fffffff00a22a910(local_e0 + 0x30);
          uVar17 = local_e0;
          uVar22 = uStack_c0;
          goto joined_r0xfffffff00a2f5e0c;
        }
        puVar1 = (undefined8 *)&uStack_b0;
        if (uVar24 != 0) {
          puVar1 = (undefined8 *)(uVar24 + 0x10);
        }
        uStack_b8 = (undefined4)*puVar1;
        uStack_b4 = (undefined4)((ulong)*puVar1 >> 0x20);
      }
      uStack_c0 = uVar24;
      FUN_fffffff00a2fea68(param_1,uVar22,0);
      puVar16 = (ulong *)(uVar22 + 8);
      *puVar16 = 0;
      *local_178 = uVar22;
      lVar21 = lVar21 + 1;
      local_178 = puVar16;
      uVar17 = local_e0;
      uVar22 = uStack_c0;
    } while (lVar21 != lVar23);
  }
  if (local_170 != 0) {
    uVar17 = *param_4;
    lVar23 = local_170;
    do {
      local_170 = *(long *)(lVar23 + 8);
      if (local_170 == 0) {
        local_168 = &local_170;
      }
      *(undefined8 *)(lVar23 + 8) = 0;
      *(ulong *)(lVar23 + 0x18) = *(long *)(lVar23 + 0x18) + (uVar17 - param_2);
      *(ulong *)(lVar23 + 0x10) = *(long *)(lVar23 + 0x10) + (uVar17 - param_2);
      *(ulong *)(lVar23 + 0x30) =
           *(ulong *)(lVar23 + 0x30) & 0xfffffffffffff000 | param_8 >> 0x18 & 0xfff;
      uVar6 = FUN_fffffff00a2fdf70(param_1,lVar23,0,0,1);
      FUN_fffffff00a346378(uVar6,lVar23);
      lVar23 = local_170;
    } while (local_170 != 0);
  }
  FUN_fffffff00a22a910(param_1 + 0x30);
  *(undefined8 *)(lVar18 + 0x228) = 0;
  if ((local_c4 & 0xc) == 8) {
    if (((byte)local_c8 >> 2 & 1) == 0) {
      local_f0 = CONCAT44(uStack_a4,uStack_a8);
    }
    else {
      uStack_c0 = local_90 + uStack_c0;
      local_f0 = local_f0 + local_90;
    }
    lStack_d8 = CONCAT44(uStack_84,local_88);
    local_e0 = CONCAT44(uStack_94,uStack_98);
    uStack_e8 = CONCAT44(uStack_9c,uStack_a0);
    local_c4 = local_c4 & 0xfff3;
    local_90 = 0;
    local_88 = 0;
    uStack_84 = 0;
  }
  if ((local_c8 >> 2 & 1) == 0) {
    FUN_fffffff00a34ab40(&local_f0);
  }
  else if ((lStack_d8 != 0) &&
          (((~*(uint *)(lStack_d8 + 0x28) & 3) != 0 || ((*(uint *)(lStack_d8 + 0x24) & 1) == 0)))) {
    FUN_fffffff00a346378();
  }
  local_e0 = 0;
  lStack_d8 = 0;
  uStack_c0._4_4_ = 0;
  uStack_b8 = 0;
  local_c4 = 0;
  uStack_c2 = 0;
  uStack_c0._0_4_ = 0;
  uStack_ac = 0;
  uStack_a8 = 0;
  uStack_b4 = 0;
  uStack_b0 = 0;
  uStack_9c = 0;
  uStack_98 = 0;
  uStack_a4 = 0;
  uStack_a0 = 0;
  local_90._4_4_ = 0;
  local_88 = 0;
  uStack_94 = 0;
  local_90._0_4_ = 0;
  uStack_84 = 0;
  if (local_180 != 0) {
    do {
      uVar17 = *(ulong *)(local_180 + 8);
      if (uVar17 == 0) {
        local_178 = &local_180;
      }
      *(undefined8 *)(local_180 + 8) = 0;
      local_180 = uVar17;
      FUN_fffffff00a2dfb4c(0);
    } while (local_180 != 0);
  }
  return 0;
}

