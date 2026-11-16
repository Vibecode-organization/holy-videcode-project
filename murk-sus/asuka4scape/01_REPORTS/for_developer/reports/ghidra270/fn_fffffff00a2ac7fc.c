// FUN_fffffff00a2ac7fc @ fffffff00a2ac7fc size=1580

undefined8
FUN_fffffff00a2ac7fc
          (long param_1,ulong *param_2,ulong param_3,undefined8 param_4,ulong param_5,long param_6,
          ulong param_7,ulong param_8,uint *param_9,uint *param_10,uint param_11)

{
  ulong uVar1;
  uint uVar2;
  byte bVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  uint uVar14;
  undefined8 uVar15;
  undefined4 *puVar16;
  ulong uVar17;
  ulong local_138;
  undefined1 auStack_130 [8];
  ulong local_128;
  long *local_120;
  undefined8 uStack_118;
  undefined8 local_110;
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
  long local_a0;
  long *local_98;
  long *local_90;
  uint local_88;
  uint local_84;
  long local_80;
  undefined8 local_78;
  undefined8 local_70;
  
  local_78 = 0;
  local_80 = 0;
  local_98 = &local_a0;
  local_a0 = 0;
  local_90 = (long *)0x0;
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
  uVar15 = 4;
  uStack_108 = 0;
  local_110 = 0;
  local_70 = param_5;
  if (((param_1 != 0) && (param_6 != 0)) && (param_11 < 3)) {
    bVar3 = *(byte *)(param_1 + 0x2c);
    uVar10 = *param_2;
    local_84 = *param_9;
    uVar14 = *param_10;
    if (((local_84 < 8) && (local_88 = uVar14, uVar14 < 8)) &&
       (((local_84 & (uVar14 ^ 0xffffffff)) == 0 && (param_3 != 0)))) {
      uVar14 = -1 << (ulong)(*(byte *)(param_6 + 0x2c) & 0x1f);
      uVar17 = (ulong)~uVar14;
      uVar8 = param_7 & (uVar17 ^ 0xffffffffffffffff);
      uVar13 = uVar8;
      if ((param_5 & 0x100000) != 0) {
        uVar13 = param_7;
      }
      if ((!CARRY8(uVar13,param_3)) &&
         (uVar9 = uVar13 + param_3 + uVar17 & ~uVar17, uVar13 = uVar9 - uVar8,
         uVar8 <= uVar9 && uVar13 != 0)) {
        if ((param_5 & 1) == 0) {
          param_5 = param_5 & 0xffffffffffffbffe;
        }
        uVar9 = uVar13;
        if ((param_5 & 0x100000) != 0) {
          uVar9 = param_3;
        }
        if (((int)param_8 != 0) || (local_70 = param_5, ((uint)param_5 >> 6 & 1) == 0)) {
          uVar1 = 0x2000000000000;
          if (param_6 != param_1) {
            uVar1 = 0;
          }
          local_70 = param_5 & 0xfffdffffffffffff | uVar1;
          uVar15 = FUN_fffffff00a2a4f54
                             (param_6,uVar8,uVar13,param_8,&local_90,&local_84,&local_88,param_11,
                              local_70);
          if ((int)uVar15 == 0) {
            uVar11 = -1L << ((ulong)bVar3 & 0x3f);
            uVar8 = param_7 & uVar17 & (long)(param_5 << 0x2b) >> 0x3f;
            if (param_6 == param_1) {
              local_70 = param_5 & 0x8000000000000000 |
                         param_5 & 0xffdffffffffffff | uVar1 |
                         (ulong)(*(byte *)((long)local_90 + 0x2f) & 7) << 0x3c;
              plVar5 = local_120;
              local_120 = local_90;
            }
            else {
              FUN_fffffff00a2a9bd4(&local_70,param_1,uVar13,param_4);
              plVar5 = local_120;
              local_120 = local_90;
            }
            local_90 = local_120;
            if (uVar14 != (uint)uVar11) {
              local_138 = 0;
              local_128 = 0;
              uVar15 = FUN_fffffff00a2a9d30
                                 (local_120,uVar8,uVar9,param_1,param_8 & 0xffffffff,&local_120,
                                  &local_128,auStack_130,&local_138);
              if ((int)uVar15 != 0) goto LAB_fffffff00a2ac960;
              uVar13 = 0;
              if (local_138 <= uVar8) {
                uVar13 = uVar8 - local_138;
              }
              if (local_138 != 0) {
                uVar8 = uVar13;
              }
              uVar8 = uVar8 + local_128;
              uVar13 = local_120[4];
              plVar5 = local_120;
            }
            local_120 = plVar5;
            uVar13 = uVar13 + ~(uint)uVar11 & uVar11;
            if (uVar13 == 0) {
              uVar15 = 4;
            }
            else {
              local_128 = local_128 & 0xffffffff00000000;
              local_120 = (long *)0x0;
              uStack_118 = 0;
              lVar7 = tpidr_el1;
              *(int *)(lVar7 + 0x21c) = *(int *)(lVar7 + 0x21c) + 1;
              if (((*(ulong *)(param_1 + 0x38) & 0xffffffff0001ffff) == 0x10000) &&
                 (*(int *)(param_1 + 0x3c) == 0)) {
                *(int *)(param_1 + 0x3c) = 2;
              }
              else {
                FUN_fffffff00a1edff8(param_1 + 0x30,lVar7,0,param_4);
              }
              uVar17 = local_70;
              *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(lVar7 + 0x4e8);
              uVar14 = (uint)local_70;
              if ((local_70 & 1) == 0) {
                uVar15 = FUN_fffffff00a2a6c88
                                   (param_1,uVar10 & uVar11,uVar13,param_4,local_70,&local_80);
              }
              else {
                uVar15 = FUN_fffffff00a2a7d4c
                                   (param_1,uVar10 & uVar11,uVar13,param_4,local_70,&local_80,
                                    &local_110,&local_128);
              }
              plVar5 = local_90;
              if ((int)uVar15 == 0) {
                lVar12 = *local_90;
                while (lVar4 = lVar12, lVar4 != 0) {
                  lVar12 = *(long *)(lVar4 + 8);
                  if ((uVar17 >> 0x2a & 1) != 0) {
                    uVar2 = *(uint *)(lVar4 + 0x38);
                    if (((uVar2 >> 0x10 & 1) == 0) ||
                       ((((uVar2 >> 10 & 1) != 0 && (DAT_fffffff007c08e68 != (byte *)0x0)) &&
                        ((*DAT_fffffff007c08e68 & 1) != 0)))) {
                      *(uint *)(lVar4 + 0x38) = uVar2 | 0x200;
                    }
                    else {
                      uVar15 = FUN_fffffff00a25f6f4(lVar7);
                      lVar6 = FUN_fffffff00a25ecac();
                      if (lVar6 != 0) {
                        FUN_fffffff00a25ecac(uVar15);
                      }
                    }
                  }
                  if ((uVar14 >> 5 & 1) != 0) {
                    local_88 = 1;
                    local_84 = 1;
                    *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) & 0xffdff08f | 0x200110;
                  }
                  if ((uVar14 >> 6 & 1) != 0) {
                    puVar16 = (undefined4 *)(*(ulong *)(lVar4 + 0x28) & 0xfffffffffffffffc);
                    if ((*(ulong *)(lVar4 + 0x28) & 3) != 0) {
                      puVar16 = &DAT_fffffff00ad7b300;
                    }
                    if ((puVar16 == (undefined4 *)0x0) ||
                       ((*(byte *)((long)puVar16 + 0x75) >> 4 & 1) != 0)) {
                      *(uint *)(lVar4 + 0x38) = *(uint *)(lVar4 + 0x38) | 0x400000;
                    }
                  }
                  if (((uVar17 >> 0x2a & 1) == 0) && ((*(uint *)(lVar4 + 0x38) >> 0x12 & 1) != 0)) {
                    FUN_fffffff00a89f3b0
                              (&MACH_HEADER,&DAT_fffffff00ad58ac0,0,
                               "%s: downgrading VM entry [%p, %p) from JIT to non-JIT");
                    uVar2 = *(uint *)(lVar4 + 0x38);
                    *(uint *)(lVar4 + 0x38) = uVar2 & 0xfffbfbbf;
                    if ((uVar17 >> 0x2b & 1) != 0) {
                      local_84 = local_84 & uVar2 >> 4 & 3;
                      local_88 = local_88 & uVar2 >> 8 & 0xb;
                    }
                  }
                }
                uVar15 = FUN_fffffff00a2ab970
                                   (param_1,plVar5,&local_110,&local_120,
                                    uVar17 >> 2 & 2 | uVar17 >> 0x34 & 1 | uVar17 >> 0x2a & 0xc |
                                    (uVar17 & 1) << 4 | uVar17 >> 9 & 0x20 | uVar17 >> 0x10 & 0x40 |
                                    0x800);
                if ((int)uVar15 == 0) {
                  if ((uVar14 >> 0xe & 1) != 0) {
                    FUN_fffffff00a2a8750
                              (param_1,&local_110,local_128 & 0xffffffff,&local_a0,&local_80);
                  }
                  puVar16 = (undefined4 *)*plVar5;
                  lVar12 = local_80;
                  while (puVar16 != (undefined4 *)0x0) {
                    FUN_fffffff00a2c1578(plVar5,puVar16);
                    lVar4 = local_80;
                    lVar12 = (lVar12 << 1) >> 1;
                    *(long *)(puVar16 + 6) = lVar12 + *(long *)(puVar16 + 6);
                    *(long *)(puVar16 + 4) = lVar12 + *(long *)(puVar16 + 4);
                    *puVar16 = 0x30000;
                    *(int *)(lVar7 + 0x21c) = *(int *)(lVar7 + 0x21c) + 1;
                    uVar15 = FUN_fffffff00a2c1630(param_1,puVar16,local_80,local_78,uVar17);
                    FUN_fffffff00a309834(uVar15,puVar16);
                    lVar12 = lVar4;
                    puVar16 = (undefined4 *)*plVar5;
                  }
                  *(long *)(param_1 + 0x60) = *(long *)(param_1 + 0x60) - (long)local_120;
                  FUN_fffffff00a1ee668(param_1 + 0x30);
                  uVar15 = 0;
                  *param_2 = (uVar8 & (long)(uVar17 << 0x2b) >> 0x3f) + ((lVar12 << 1) >> 1);
                  *param_9 = local_84;
                  *param_10 = local_88;
                  goto LAB_fffffff00a2ac960;
                }
                FUN_fffffff00a2c05d0(param_1,local_80,local_78);
              }
              FUN_fffffff00a1ee668(param_1 + 0x30);
            }
          }
        }
      }
    }
  }
LAB_fffffff00a2ac960:
  if (((local_70._1_1_ >> 6 & 1) != 0) && (local_a0 != 0)) {
    do {
      lVar7 = *(long *)(local_a0 + 8);
      if (lVar7 == 0) {
        local_98 = &local_a0;
      }
      *(undefined8 *)(local_a0 + 8) = 0;
      local_a0 = lVar7;
      FUN_fffffff00a2a3324(0);
    } while (local_a0 != 0);
  }
  if (local_90 != (long *)0x0) {
    FUN_fffffff00a2a5c40();
  }
  return uVar15;
}

