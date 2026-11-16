// FUN_fffffff00a2ac15c @ fffffff00a2ac15c size=1696

/* WARNING: Type propagation algorithm not settling */

ulong FUN_fffffff00a2ac15c(long param_1,ulong param_2,long param_3,int param_4,uint param_5)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong *puVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  long lVar10;
  ushort uVar11;
  long lVar12;
  undefined8 uVar13;
  uint uVar14;
  byte bVar15;
  ulong uVar16;
  ulong uVar17;
  uint uVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  undefined *local_140;
  undefined8 local_138;
  code *local_130;
  undefined *local_128;
  undefined8 *puStack_120;
  int local_118;
  uint local_110 [2];
  ulong local_108;
  ulong local_100;
  ulong uStack_f8;
  ulong local_f0;
  ulong uStack_e8;
  undefined **local_e0;
  undefined8 local_d8;
  ulong local_d0 [9];
  undefined8 local_88;
  undefined8 *local_80;
  undefined8 local_78;
  uint local_70;
  
  local_80 = &local_88;
  local_88 = 0;
  local_78 = DAT_fffffff00700da58;
  local_d0[5] = 0;
  local_d0[4] = 0;
  local_d0[7] = 0;
  local_d0[6] = 0;
  local_d0[1] = 0;
  local_d0[0] = 0;
  local_d0[3] = 0;
  local_d0[2] = 0;
  uStack_e8 = 0;
  local_f0 = 0;
  local_d8 = 0;
  local_e0 = (undefined **)0x0;
  uStack_f8 = 0;
  local_100 = 0;
  if ((param_5 & 0xffffffe8) != 0) {
    local_70 = 0;
    uVar2 = 4;
    goto LAB_fffffff00a2ac718;
  }
  uVar2 = param_3 - param_2;
  local_70 = param_5;
  if (param_1 == 0) {
    if (uVar2 != 0) {
      if (!CARRY8(param_2,uVar2)) {
        uVar19 = param_2 & 0xffffffffffffc000;
        uVar20 = param_2 + uVar2 + 0x3fff & 0xffffffffffffc000;
        if (uVar19 < uVar20) goto LAB_fffffff00a2ac230;
      }
      uVar8 = 0x3fff;
      lVar10 = 0;
      goto LAB_fffffff00a2ac78c;
    }
  }
  else if (uVar2 != 0) {
    uVar8 = (ulong)(uint)~(-1 << (ulong)(*(byte *)(param_1 + 0x2c) & 0x1f));
    lVar10 = param_1;
    if (CARRY8(param_2,uVar2)) {
LAB_fffffff00a2ac78c:
      uVar2 = FUN_fffffff00a308f64(4,param_2,uVar2,uVar8,lVar10);
      uVar19 = uVar2 & 0xffffffff;
      uVar20 = uVar19;
      if ((int)uVar2 != 0) {
        if ((int)uVar2 != 0x20000001) goto LAB_fffffff00a2ac718;
        goto LAB_fffffff00a2ac714;
      }
    }
    else {
      uVar19 = param_2 & (uVar8 ^ 0xffffffffffffffff);
      uVar20 = param_2 + uVar2 + uVar8 & ~uVar8;
      if (uVar20 <= uVar19) goto LAB_fffffff00a2ac78c;
    }
LAB_fffffff00a2ac230:
    if (0xf < param_5) {
      uVar2 = 1;
      if (*(ulong *)(param_1 + 0x18) <= uVar19) goto LAB_fffffff00a2ac718;
      local_110[0] = param_5 & 7;
      local_110[1] = 0;
      uVar13 = 0x8040000004001;
      if ((*(uint *)(param_1 + 0xf8) & 0x10000) != 0) {
        uVar13 = 0x40000004001;
      }
      local_108 = uVar19;
      uVar2 = FUN_fffffff00a2ac7fc
                        (param_1,&local_108,uVar20 - uVar19,0,uVar13,param_1,uVar19,1,local_110 + 1,
                         local_110,1);
      if ((int)uVar2 != 0) goto LAB_fffffff00a2ac718;
      *(uint *)(local_80 + 3) = *(uint *)(local_80 + 3) & 0xffffffef;
    }
    lVar10 = tpidr_el1;
    *(int *)(lVar10 + 0x21c) = *(int *)(lVar10 + 0x21c) + 1;
    if (((*(ulong *)(param_1 + 0x38) & 0xffffffff0001ffff) == 0x10000) &&
       (*(int *)(param_1 + 0x3c) == 0)) {
      *(int *)(param_1 + 0x3c) = 2;
    }
    else {
      FUN_fffffff00a1edff8(param_1 + 0x30,lVar10,0);
    }
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(lVar10 + 0x4e8);
    if (uVar19 < *(ulong *)(param_1 + 0x18)) {
      local_e0 = &local_140;
      local_140 = &DAT_fffffff00ad58ce0;
      local_138 = DAT_fffffff00700da60;
      local_130 = FUN_fffffff00a2ace28;
      puStack_120 = &local_88;
      local_128 = &DAT_fffffff007bbe278;
      local_118 = param_4;
      FUN_fffffff00a1ee700(param_1 + 0x30);
      uVar2 = FUN_fffffff00a30bc18(&local_100,param_1,uVar19,uVar20,0x6029);
      if ((int)uVar2 == 0) {
        uVar18 = 0;
LAB_fffffff00a2ac32c:
        uVar20 = local_d8;
        uVar7 = (uint)local_d8;
        uVar2 = local_d0[0];
        uVar19 = local_100;
        uVar8 = local_d0[6];
        uVar16 = local_d0[7];
        uVar17 = uStack_f8;
        uVar21 = uStack_e8;
        uVar11 = local_d8._4_2_;
        do {
          uVar1 = uVar19;
          uVar19 = uVar1;
          if (uVar21 == 0) {
            local_d8 = CONCAT26(local_d8._6_2_,CONCAT24(uVar11,(uint)local_d8)) & 0xfffffffdffffffff
            ;
            puVar4 = local_d0;
            uVar11 = uVar11 & 0xfffd;
          }
          else {
            uVar3 = uVar16;
            if (((uVar11 & 0xc) == 8) && (uVar17 <= *(ulong *)(uVar21 + 0x18))) {
              local_100 = local_d0[3];
              if ((uVar7 >> 2 & 1) != 0) {
                uVar2 = uVar8 + uVar2;
                local_d0[0] = uVar2;
                local_100 = uVar1 + uVar8;
              }
              uVar8 = 0;
              local_f0 = local_d0[5];
              uStack_f8 = local_d0[4];
              local_d8 = CONCAT26(local_d8._6_2_,CONCAT24(uVar11,(uint)local_d8)) &
                         0xfffffff3ffffffff;
              local_d0[6] = 0;
              local_d0[7] = 0;
              uVar3 = 0;
              uVar19 = local_100;
              uVar21 = uVar16;
              uVar17 = local_d0[4];
              uVar11 = uVar11 & 0xfff3;
            }
            uVar1 = *(ulong *)(uVar21 + 0x18);
            if (uVar17 <= uVar1) goto LAB_fffffff00a2ac684;
            puVar4 = (ulong *)(uVar21 + 8);
            uVar16 = uVar3;
          }
          uVar21 = *puVar4;
          puVar5 = *(undefined4 **)(uVar21 + 0x28);
        } while (puVar5 == &DAT_fffffff00ad7b500);
        if (((~(uint)puVar5 & 3) == 0 && (uVar20 & 0x40000) != 0) &&
           ((*(uint *)(uVar21 + 0x24) & 1) == 0)) {
          uStack_f8 = local_d0[4];
          if (*(ulong *)(uVar21 + 0x18) <= local_d0[4]) {
            uStack_f8 = *(ulong *)(uVar21 + 0x18);
          }
          local_d0[6] = *(long *)(uVar21 + 0x10) - (*(ulong *)(uVar21 + 0x30) & 0xfffffffffffff000);
          local_100 = uVar1 - local_d0[6];
          uStack_f8 = uStack_f8 - local_d0[6];
          local_f0 = (ulong)puVar5 & 0xfffffffffffffffc;
          uStack_e8 = 0;
          local_d8 = CONCAT26(local_d8._6_2_,CONCAT24(uVar11,(uint)local_d8)) & 0xfffffff3ffffffff |
                     0x800000000;
          if ((uVar7 >> 2 & 1) != 0) {
            local_d0[0] = local_100;
          }
          local_d0[7] = uVar21;
          uVar21 = FUN_fffffff00a2a4828();
          if (uVar21 == 0) goto LAB_fffffff00a2ac748;
        }
        uVar2 = local_f0;
        uVar7 = *(uint *)(uVar21 + 0x38);
        uVar9 = uVar7 >> 4 & 7;
        if (param_4 == 0) {
          uVar14 = uVar7 & 0xffffff80 | uVar7 & 0xf | (*(uint *)(local_80 + 3) & 7) << 4;
        }
        else {
          uVar14 = (*(uint *)(local_80 + 3) & 0xf) << 8;
          *(uint *)(uVar21 + 0x38) = uVar7 & 0xfffff000 | uVar7 & 0xff | uVar14;
          uVar14 = uVar7 & 0xfffff000 | uVar7 & 0x80 | uVar14 |
                   uVar7 & 0xf | (*(uint *)(local_80 + 3) & uVar9) << 4;
        }
        *(uint *)(uVar21 + 0x38) = uVar14;
        uStack_e8 = uVar21;
        if (((uVar14 >> 0x13 & 1) == 0) && (uVar9 < 4)) {
          if ((uVar14 >> 6 & 1) != 0) {
LAB_fffffff00a2ac4cc:
            FUN_fffffff00a2acf98(local_f0,uVar21,0x40000000000);
            uVar14 = *(uint *)(uVar21 + 0x38);
          }
        }
        else if (((uVar14 >> 5 & 1) != 0) && ((uVar14 & 0x80000) != 0 && (uVar7 & 0x20) == 0))
        goto LAB_fffffff00a2ac4cc;
        uVar7 = uVar14 >> 4 & 7;
        if (uVar7 != uVar9) {
          uVar20 = *(ulong *)(uVar21 + 0x28);
          uVar19 = uVar20 & 3;
          if (((uVar19 == 3) || (uVar19 != 0)) ||
             ((undefined4 *)(uVar20 & 0xfffffffffffffffc) != &DAT_fffffff00ad7b400)) {
            uVar7 = uVar14 >> 4 & 5;
          }
          else {
            uVar18 = (uVar14 & 0x20) << 7 | uVar18;
          }
          lVar12 = *(long *)(uVar2 + 0x58);
          if ((lVar12 == 0) || (lVar12 == 0)) {
            bVar15 = 1;
          }
          else {
            bVar15 = *(byte *)(*(long *)(lVar12 + 0x20) + 0x4c) ^ 1;
          }
          if ((uVar7 == 7) && ((bVar15 & 1) != 0)) {
            if (*(short *)(uVar21 + 0x3c) != 0) {
                    /* WARNING: Subroutine does not return */
              FUN_fffffff00aa0c4f8("vm_map_protect(%p,0x%llx,0x%llx) new=0x%x wired=%x @%s:%d");
            }
            uVar7 = 0;
          }
          if ((uVar19 == 3) && ((uVar14 >> 0xe & 1) != 0)) {
            lVar12 = *(long *)((uVar20 & 0xfffffffffffffffc) + 0x58);
            if (lVar12 == 0) {
              lVar12 = 0;
            }
            uVar13 = *(undefined8 *)(uVar21 + 0x10);
            uVar6 = *(undefined8 *)(uVar21 + 0x18);
            uVar9 = 0;
          }
          else {
            if (lVar12 == 0) {
              lVar12 = 0;
            }
            uVar13 = *(undefined8 *)(uVar21 + 0x10);
            uVar6 = *(undefined8 *)(uVar21 + 0x18);
            uVar9 = uVar18;
          }
          FUN_fffffff00a33b504
                    (uVar2 + 0x58 & 0xffffffffffff | 0x250c000000000000,lVar12,uVar13,uVar6,uVar7,
                     uVar9,0);
        }
        goto LAB_fffffff00a2ac32c;
      }
      *(undefined8 *)(lVar10 + 0x228) = 0;
    }
    else {
      FUN_fffffff00a1ee668(param_1 + 0x30);
      uVar2 = 1;
    }
    goto LAB_fffffff00a2ac718;
  }
LAB_fffffff00a2ac714:
  uVar2 = 0;
LAB_fffffff00a2ac718:
  FUN_fffffff00a8adfc0(&local_88,8);
  return uVar2;
LAB_fffffff00a2ac748:
  uVar7 = (uint)local_d8;
LAB_fffffff00a2ac684:
  uStack_e8 = 0;
  *(undefined8 *)(lVar10 + 0x228) = 0;
  if ((local_d8._4_2_ & 0xc) == 8) {
    uVar2 = local_d0[3];
    if (((byte)local_d8 >> 2 & 1) != 0) {
      local_d0[0] = local_d0[6] + local_d0[0];
      uVar2 = local_100 + local_d0[6];
    }
    uStack_e8 = local_d0[7];
    local_f0 = local_d0[5];
    uStack_f8 = local_d0[4];
    local_d8 = local_d8 & 0xfffffff3ffffffff;
    local_d0[6] = 0;
    local_d0[7] = 0;
    local_100 = uVar2;
  }
  if ((uVar7 >> 2 & 1) == 0) {
    FUN_fffffff00a30dfb8(&local_100);
  }
  else if ((uStack_e8 != 0) &&
          (((~*(uint *)(uStack_e8 + 0x28) & 3) != 0 || ((*(uint *)(uStack_e8 + 0x24) & 1) == 0)))) {
    FUN_fffffff00a309834();
  }
  goto LAB_fffffff00a2ac714;
}

