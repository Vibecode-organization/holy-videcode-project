// FUN_fffffff009c23d94 @ fffffff009c23d94 size=2256

/* WARNING: Removing unreachable block (ram,0xfffffff009c24168) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c240ec) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c24024) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c240ac) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c24130) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c24274) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c23e48) */

void FUN_fffffff009c23d94(long *param_1,long *param_2,int param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  uint3 uVar2;
  undefined4 uVar3;
  int iVar4;
  long *plVar5;
  ulong uVar6;
  long *plVar7;
  undefined8 uVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  long *plVar12;
  bool bVar13;
  ulong uVar14;
  ulong uVar15;
  long *plVar16;
  ulong uVar17;
  uint uVar18;
  long *local_150;
  undefined1 *puStack_148;
  undefined1 *local_140;
  undefined1 *puStack_138;
  undefined1 *local_130;
  undefined8 local_128;
  long local_120;
  long local_118;
  long lStack_110;
  long local_108;
  uint local_100;
  uint uStack_fc;
  uint local_f8;
  undefined4 uStack_f4;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  uint uStack_d4;
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined8 local_c8;
  undefined1 *puStack_c0;
  undefined1 *local_b8;
  undefined8 uStack_b0;
  undefined1 *local_a8;
  undefined1 *puStack_a0;
  undefined1 *local_98;
  undefined1 *puStack_90;
  undefined1 *local_88;
  undefined1 *puStack_80;
  undefined1 *local_78;
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff00806ca40;
  local_78 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_80 = &DAT_aaaaaaaaaaaaaaaa;
  local_88 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_90 = &DAT_aaaaaaaaaaaaaaaa;
  local_98 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_a0 = &DAT_aaaaaaaaaaaaaaaa;
  local_a8 = &DAT_aaaaaaaaaaaaaaaa;
  uStack_b0 = &DAT_aaaaaaaaaaaaaaaa;
  local_b8 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_c0 = &DAT_aaaaaaaaaaaaaaaa;
  local_c8 = &DAT_aaaaaaaaaaaaaaaa;
  local_e0 = (undefined4)param_1[2];
  uStack_dc = (undefined4)param_1[0x10];
  local_d8 = (**(code **)(*param_1 + 0x18))();
  local_d0 = *(undefined4 *)((long)param_1 + 0x9c);
  uStack_d4 = (uint)*(byte *)(param_1[0x2f] + 0x6e);
  uStack_cc = (undefined4)param_1[0x46];
  local_b8 = (undefined1 *)param_1[0x12];
  puStack_c0 = (undefined1 *)param_1[0x11];
  uStack_b0 = (undefined1 *)
              (CONCAT71(uStack_b0._1_7_,*(byte *)(param_1 + 0x7a) >> 1) & 0xffffffffffffff01);
  plVar5 = (long *)param_1[6];
  uStack_b0._0_2_ = CONCAT11(plVar5 != (long *)0x0,(undefined1)uStack_b0);
  local_e8 = param_4;
  if (plVar5 == (long *)0x0) {
    bVar13 = false;
  }
  else {
    uVar6 = (**(code **)(*plVar5 + 0xa0))();
    bVar13 = 1 < uVar6;
  }
  uStack_b0._0_3_ = CONCAT12(bVar13,(undefined2)uStack_b0);
  uVar2 = (uint3)uStack_b0;
  uStack_b0 = (undefined1 *)(ulong)(uint3)uStack_b0;
  if (param_1[0x6f] != 0) {
    uStack_b0._0_4_ = (uint)uVar2;
    uStack_b0 = (undefined1 *)CONCAT44(*(undefined4 *)(param_1[0x6f] + 0x10),(uint)uStack_b0);
  }
  uStack_b0._0_4_ = (uint)(uint3)uStack_b0;
  puStack_90 = (undefined1 *)0x0;
  local_88 = (undefined1 *)0x0;
  puStack_80 = (undefined1 *)param_1[0x70];
  local_78 = (undefined1 *)0x0;
  FUN_fffffff009c23c30(param_1,1);
  thunk_EXT_FUN_80110000032222a8(param_1[10]);
  FUN_fffffff009c23c94(param_1);
  thunk_EXT_FUN_8011000003222de0(param_1[10]);
  if (param_1[6] == 0) {
    local_c8._4_4_ = (undefined4)param_1[0x45];
    local_c8._0_4_ = 0xffffffff;
    uVar3 = (undefined4)local_c8;
  }
  else {
    local_120 = 0;
    local_150 = (long *)0x0;
    local_f0 = 0;
    iVar4 = thunk_EXT_FUN_8011000003977f9c(param_1[6],&local_120,&local_150,&local_f0);
    if (iVar4 == 0) {
      puStack_90 = (undefined1 *)(ulong)(uint)(*(int *)PTR_DAT_fffffff00806ca78 * (int)local_120);
      local_88 = (undefined1 *)
                 (ulong)(uint)(((int)local_f0 + (int)local_150) * *(int *)PTR_DAT_fffffff00806ca78);
    }
    local_78 = (undefined1 *)thunk_EXT_FUN_8011000003977aa8(param_1[6]);
    plVar5 = (long *)param_1[6];
    local_c8._4_4_ = (undefined4)param_1[0x45];
    local_c8._0_4_ = 0xffffffff;
    uVar3 = (undefined4)local_c8;
    local_c8._0_4_ = 0xffffffff;
    if (plVar5 != (long *)0x0) {
      local_120 = CONCAT44(local_120._4_4_,2);
      iVar4 = (**(code **)(*plVar5 + 0x80))(plVar5,1,&local_120);
      uVar3 = (undefined4)local_c8;
      if (iVar4 == 0) {
        local_c8._0_4_ = (int)local_120;
        uVar3 = (undefined4)local_c8;
      }
    }
  }
  local_c8._0_4_ = uVar3;
  local_a8 = *(undefined1 **)(param_1[0x60] + 0x28);
  puStack_a0 = *(undefined1 **)(param_1[0x60] + 0x10);
  local_98 = (undefined1 *)param_1[0x74];
  FUN_fffffff009c24664(param_1 + 0x74,param_2,"BasicInfo",&local_e8,0x78);
  local_120 = param_1[0xf];
  lStack_110 = param_1[0xc];
  local_118 = param_1[0xb];
  local_108 = param_1[0xd];
  local_100 = (uint)*(ushort *)(param_1 + 0xe);
  uStack_fc = (uint)*(byte *)((long)param_1 + 0x72);
  _local_f8 = CONCAT44(0xaaaaaaaa,(uint)*(byte *)((long)param_1 + 0x73));
  FUN_fffffff009c24664(param_2,"Layout",&local_120,0x30);
  plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24
                             (*(ulong *)(param_1[0x2f] + 0x18) & 0xffffffff,0x20);
  (**(code **)(*param_2 + 0x100))(*param_2 + 0x100,param_2,"UseCount",plVar5);
  plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24(*(ulong *)(param_1[0x2f] + 0x18) >> 0x20,0x20);
  (**(code **)(*param_2 + 0x100))(*param_2 + 0x100,param_2,"UseCount1",plVar7);
  if (param_1[5] != 0) {
    uVar8 = FUN_fffffff009c30a78();
    (**(code **)(*param_2 + 0x100))(param_2,"IOSurfaceMemoryRegion",uVar8);
  }
  thunk_EXT_FUN_80110000032222a8(param_1[10]);
  plVar9 = (long *)param_1[0x35];
  if (((plVar9 != (long *)0x0) &&
      (lVar10 = (**(code **)(*plVar9 + 0x138))(plVar9,"IOSurfaceName"), lVar10 != 0)) &&
     (lVar11 = thunk_EXT_FUN_8011000003890f30(lVar10,*(undefined8 *)PTR_DAT_fffffff00806ca10),
     lVar11 != 0)) {
    (**(code **)(*param_2 + 0x100))(param_2,"IOSurfaceName",lVar10);
  }
  thunk_EXT_FUN_8011000003222de0(param_1[10]);
  if (param_3 != 0) {
    FUN_fffffff009c24664(param_2,"ColorAndSpatialKeys",param_1[0x2f] + 0x34,0x84);
    if (param_1[0x4d] != 0) {
      (**(code **)(*param_2 + 0x100))(param_2,"CreationProperties");
    }
    if (((int)param_1[0x13] != 0) &&
       (plVar9 = (long *)thunk_EXT_FUN_80110000038961f4(), plVar9 != (long *)0x0)) {
      if ((int)param_1[0x13] != 0) {
        uVar17 = 0;
        uVar18 = 0;
        uVar6 = 0xffffffff7fffffc8;
        do {
          puStack_138 = &DAT_aaaaaaaaaaaaaaaa;
          local_140 = &DAT_aaaaaaaaaaaaaaaa;
          local_128 = &DAT_aaaaaaaaaaaaaaaa;
          local_130 = &DAT_aaaaaaaaaaaaaaaa;
          puStack_148 = &DAT_aaaaaaaaaaaaaaaa;
          local_150 = (long *)&DAT_aaaaaaaaaaaaaaaa;
          uVar14 = param_1[0x30];
          uVar15 = uVar14 + (ulong)*(uint *)(param_1 + 0x31) * 0x38;
          if (((uVar14 ^ uVar15) & 0xffc0000000000000) != 0) {
            uVar15 = uVar15 & 0xffffffffffff | 0xc8a2000000000000;
          }
          if ((uVar15 < uVar14) || (uVar15 - uVar14 >> 0x20 != 0)) {
            FUN_fffffff009c48f64();
LAB_fffffff009c24654:
            FUN_fffffff009c48f3c();
LAB_fffffff009c24658:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28();
          }
          uVar6 = uVar6 + 0x38;
          if (uVar6 < 0xffffffff00000000) goto LAB_fffffff009c24654;
          if (((long)uVar17 < 0) || ((uint)(uVar15 - uVar14) < (int)(uVar17 >> 0x20) + 0x38U))
          goto LAB_fffffff009c24658;
          puVar1 = (undefined8 *)(uVar14 + (uVar17 >> 0x20));
          uVar14 = (ulong)CARRY8(uVar14,uVar17 >> 0x20);
          uVar15 = -uVar14;
          if ((uVar15 != uVar14) || ((long)uVar15 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50();
          }
          local_150 = (long *)puVar1[3];
          puStack_138 = (undefined1 *)puVar1[4];
          local_140 = (undefined1 *)puVar1[1];
          puStack_148 = (undefined1 *)*puVar1;
          local_130 = (undefined1 *)
                      (ulong)CONCAT14(*(undefined1 *)((long)puVar1 + 0x34),
                                      (uint)*(ushort *)(puVar1 + 6));
          local_128 = (undefined1 *)CONCAT44(0xaaaaaaaa,(uint)*(byte *)((long)puVar1 + 0x35));
          plVar12 = (long *)thunk_EXT_FUN_801100000389a264(&local_150,0x30);
          if (plVar12 != (long *)0x0) {
            (**(code **)(*plVar9 + 0xe8))(plVar9,plVar12);
            (**(code **)(*plVar12 + 0x28))(plVar12);
          }
          uVar17 = uVar17 + 0x3800000000;
          uVar18 = uVar18 + 1;
        } while (uVar18 < *(uint *)(param_1 + 0x13));
      }
      (**(code **)(*param_2 + 0x100))(param_2,"IOSurfacePlaneInfo",plVar9);
      (**(code **)(*plVar9 + 0x28))(plVar9);
    }
  }
  if ((param_1[0x68] != 0) && (param_1[6] != 0)) {
    plVar9 = (long *)FUN_fffffff009c372dc(DAT_fffffff00af483b0);
    plVar12 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
    plVar16 = (long *)param_1[6];
    if (plVar16 != (long *)0x0) {
      (**(code **)(*plVar16 + 0x20))(plVar16);
    }
    if ((plVar9 != (long *)0x0) && (plVar12 != (long *)0x0)) {
      (**(code **)(*plVar12 + 0x20))(plVar12);
      if (plVar16 != (long *)0x0) {
        (**(code **)(*plVar16 + 0x20))(plVar16);
      }
      iVar4 = FUN_fffffff009c455f4(plVar9,plVar12,plVar16);
      if (iVar4 != 0) {
        local_150 = plVar12;
        (**(code **)(*plVar12 + 0x20))(plVar12);
        thunk_EXT_FUN_801100000389d40c(param_2,"IOSurfaceMemoryPoolInfo",&local_150);
        if (local_150 != (long *)0x0) {
          (**(code **)(*local_150 + 0x28))();
        }
      }
    }
    if (plVar16 != (long *)0x0) {
      (**(code **)(*plVar16 + 0x28))(plVar16);
    }
    if (plVar12 != (long *)0x0) {
      (**(code **)(*plVar12 + 0x28))(plVar12);
    }
    if (plVar9 != (long *)0x0) {
      (**(code **)(*plVar9 + 0x28))(plVar9);
    }
  }
  if (plVar7 != (long *)0x0) {
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_70) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

