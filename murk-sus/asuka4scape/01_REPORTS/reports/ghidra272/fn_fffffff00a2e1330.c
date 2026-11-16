// FUN_fffffff00a2e1330 @ fffffff00a2e1330 size=1112

ulong FUN_fffffff00a2e1330
                (long param_1,ulong param_2,ulong param_3,ulong param_4,undefined8 param_5,
                int param_6)

{
  undefined4 *puVar1;
  ulong uVar2;
  ulong uVar3;
  long *plVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  long *plVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  ulong uVar15;
  undefined *local_128;
  undefined8 local_120;
  code *local_118;
  undefined *local_110;
  int local_108;
  undefined4 local_100;
  undefined4 uStack_fc;
  long *local_f8;
  ulong local_f0;
  uint local_e4;
  long local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  long local_c8;
  undefined **local_c0;
  uint uStack_b8;
  ushort uStack_b4;
  undefined2 uStack_b2;
  undefined8 local_b0;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  
  uStack_88 = 0;
  uStack_84 = 0;
  local_90 = 0;
  uStack_8c = 0;
  local_78 = 0;
  uStack_74 = 0;
  local_80 = 0;
  uStack_7c = 0;
  uStack_98 = 0;
  uStack_94 = 0;
  local_a0 = 0;
  uStack_9c = 0;
  uStack_b8 = 0;
  uStack_b4 = 0;
  uStack_b2 = 0;
  local_c0 = (undefined **)0x0;
  uStack_a8 = 0;
  uStack_a4 = 0;
  local_b0._0_4_ = 0;
  local_b0._4_4_ = 0;
  uStack_d8 = 0;
  local_e0 = 0;
  local_c8 = 0;
  local_d0 = 0;
  if (param_3 != param_2) {
    if (param_1 == 0) {
      uVar10 = 0xe;
    }
    else {
      uVar10 = (uint)*(byte *)(param_1 + 0x2c);
    }
    if ((CARRY8(param_2,param_3 - param_2)) ||
       (uVar8 = (ulong)(uint)~(-1 << (ulong)(uVar10 & 0x1f)),
       (param_3 + uVar8 & (uVar8 ^ 0xffffffffffffffff)) <= (param_2 & (uVar8 ^ 0xffffffffffffffff)))
       ) {
      DAT_fffffff00ad94ee0 = DAT_fffffff00ad94ee0 + 1;
      return 1;
    }
  }
  uVar8 = param_2 & 0xffffffffffffc000;
  if (param_1 == 0) {
    uVar11 = param_3 + 0x3fff | 0x3fff;
    uVar10 = 0xe;
  }
  else {
    uVar10 = (uint)*(byte *)(param_1 + 0x2c);
    uVar11 = -1L << ((ulong)*(byte *)(param_1 + 0x2c) & 0x3f);
    uVar8 = uVar8 & uVar11;
    uVar11 = (param_3 + 0x3fff & 0xffffffffffffc000) + (ulong)~(uint)uVar11;
  }
  local_f8 = (long *)0x0;
  local_f0 = 0;
  local_100 = 5;
  if (param_6 == 2) {
    local_100 = 1;
  }
  uVar11 = uVar11 & (long)(-1 << (ulong)(uVar10 & 0x1f));
  uVar15 = 1;
  uStack_fc = local_100;
  iVar5 = FUN_fffffff00a2e1788
                    (param_1,uVar8,uVar11 - uVar8,1,&local_f8,&uStack_fc,&local_100,2,
                     0x2000000000000);
  if (iVar5 == 0) {
    local_c0 = &local_128;
    local_128 = &DAT_fffffff00ad98dc0;
    local_120 = DAT_fffffff00700d9a0;
    local_118 = FUN_fffffff00a2e2430;
    local_110 = &DAT_fffffff007bca200;
    local_108 = param_6;
    FUN_fffffff00a2299cc(param_1 + 0x30);
    uVar15 = FUN_fffffff00a347f10(&local_e0,param_1,uVar8,uVar11,0x26);
    plVar4 = local_f8;
    if ((int)uVar15 == 0) {
      local_e4 = 0;
      plVar9 = local_f8;
      while( true ) {
        lVar13 = *plVar9;
        lVar6 = FUN_fffffff00a34a078(&local_e0,&local_e4);
        if (lVar6 == 0) break;
        if (lVar13 == 0) {
LAB_fffffff00a2e165c:
          local_e4 = 1;
          break;
        }
        uVar15 = *(ulong *)(lVar13 + 0x28) & 3;
        if (uVar15 == 3) goto LAB_fffffff00a2e165c;
        lVar14 = *(long *)(lVar13 + 0x18) - *(long *)(lVar13 + 0x10);
        uVar2 = *(ulong *)(lVar6 + 0x10);
        uVar3 = *(ulong *)(lVar6 + 0x18);
        if (lVar14 != uVar3 - uVar2) goto LAB_fffffff00a2e165c;
        puVar1 = (undefined4 *)(*(ulong *)(lVar13 + 0x28) & 0xfffffffffffffffc);
        if (uVar15 != 0) {
          puVar1 = &DAT_fffffff00adbb300;
        }
        if (puVar1 == (undefined4 *)0x0) goto LAB_fffffff00a2e165c;
        uVar15 = *(ulong *)(lVar13 + 0x30);
        uVar12 = *(ulong *)(lVar6 + 0x30);
        uVar10 = *(uint *)(lVar6 + 0x38);
        FUN_fffffff00a34a93c(&local_e0,0);
        if (uVar2 < param_2) {
          lVar6 = param_2 - uVar8;
          if (uVar2 != uVar8) goto LAB_fffffff00a2e165c;
        }
        else {
          lVar6 = 0;
        }
        lVar7 = lVar14;
        if (param_3 < uVar3) {
          if (uVar3 != uVar11) goto LAB_fffffff00a2e165c;
          lVar7 = param_3 - uVar2;
        }
        uVar12 = uVar12 & 0xfffffffffffff000;
        if (param_4 != 0xffffffffffffffff) {
          uVar12 = param_4;
        }
        lVar7 = FUN_fffffff00a36f248
                          (puVar1,uVar15 & 0xfffffffffffff000,uVar12,param_5,lVar6,lVar7,1);
        if (lVar7 == 0) {
          local_e4 = 5;
          break;
        }
        local_f0 = uVar2;
        local_e4 = FUN_fffffff00a2e51f8
                             (local_d0,&local_f0,lVar14,0,
                              (ulong)(uVar10 >> 9) & 0x80 | 0x20000004001,lVar7,0,1,
                              CONCAT44(uVar10 >> 8,uVar10 >> 4) & 0xf00000007,uVar10 >> 0xc & 3,0,0)
        ;
        (**(code **)(*(long *)(lVar7 + 8) + 8))(lVar7);
        param_4 = (uVar3 + uVar12) - (uVar2 + lVar6);
        plVar9 = (long *)(lVar13 + 8);
      }
      FUN_fffffff00a2e2474(plVar4);
      lVar6 = tpidr_el1;
      *(undefined8 *)(lVar6 + 0x228) = 0;
      if ((uStack_b4 & 0xc) == 8) {
        if (((byte)uStack_b8 >> 2 & 1) == 0) {
          local_e0 = CONCAT44(uStack_94,uStack_98);
        }
        else {
          local_b0 = CONCAT44(uStack_7c,local_80) + CONCAT44(local_b0._4_4_,(undefined4)local_b0);
          local_e0 = local_e0 + CONCAT44(uStack_7c,local_80);
        }
        local_c8 = CONCAT44(uStack_74,local_78);
        local_d0 = CONCAT44(uStack_84,uStack_88);
        uStack_d8 = CONCAT44(uStack_8c,local_90);
        uStack_b4 = uStack_b4 & 0xfff3;
        local_80 = 0;
        uStack_7c = 0;
        local_78 = 0;
        uStack_74 = 0;
      }
      if ((uStack_b8 >> 2 & 1) == 0) {
        FUN_fffffff00a34ab40(&local_e0);
      }
      else if ((local_c8 != 0) &&
              (((~*(uint *)(local_c8 + 0x28) & 3) != 0 || ((*(uint *)(local_c8 + 0x24) & 1) == 0))))
      {
        FUN_fffffff00a346378();
      }
      uVar15 = (ulong)local_e4;
    }
    else {
      lVar6 = tpidr_el1;
      *(undefined8 *)(lVar6 + 0x228) = 0;
      local_d0 = 0;
      local_c8 = 0;
      local_b0._4_4_ = 0;
      uStack_a8 = 0;
      uStack_b4 = 0;
      uStack_b2 = 0;
      local_b0._0_4_ = 0;
      uStack_9c = 0;
      uStack_98 = 0;
      uStack_a4 = 0;
      local_a0 = 0;
      uStack_8c = 0;
      uStack_88 = 0;
      uStack_94 = 0;
      local_90 = 0;
      uStack_7c = 0;
      local_78 = 0;
      uStack_84 = 0;
      local_80 = 0;
      uStack_74 = 0;
      FUN_fffffff00a2e2474(local_f8);
    }
  }
  return uVar15;
}

