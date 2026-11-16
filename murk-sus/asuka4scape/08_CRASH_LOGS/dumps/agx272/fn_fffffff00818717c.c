// FUN_fffffff00818717c @ fffffff00818717c size=984

void FUN_fffffff00818717c(long *param_1,long *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  undefined4 *puVar13;
  long lVar14;
  long lVar15;
  undefined8 uVar16;
  undefined4 *puVar17;
  long lVar18;
  undefined *local_a0;
  undefined8 local_98;
  code *local_90;
  undefined *local_88;
  long lStack_80;
  long local_78;
  
  if ((*(byte *)((long)param_2 + 0x4c) & 1) == 0) {
    puVar5 = (undefined8 *)(**(code **)(*param_2 + 0xf0))(param_2);
    uVar6 = (**(code **)(*param_2 + 0xf8))(param_2);
    FUN_fffffff008183924
              (param_1,uVar6,*(undefined4 *)((long)param_2 + 0x1dc),param_2[0x20],
               *(undefined4 *)puVar5,param_2 + 0x4b);
    lVar14 = param_2[0x20];
    uVar1 = *(undefined4 *)puVar5;
    uVar6 = *(undefined8 *)(param_2[0x48] + 0x78);
    uVar16 = *(undefined8 *)(*(long *)(param_2[0x48] + 0x10) + 0x58);
    puVar13 = (undefined4 *)param_2[0x49];
    lVar12 = param_2[0x4a];
    *puVar13 = 4;
    puVar13[8] = 0x80;
    uVar2 = *(undefined4 *)((long)param_2 + 0x424);
    *(undefined8 *)(puVar13 + 1) = uVar16;
    *(undefined8 *)(puVar13 + 6) = uVar6;
    puVar13[9] = uVar1;
    puVar13[0xe] = 0;
    *(long *)(puVar13 + 10) = lVar14;
    puVar13[0xc] = 1;
    puVar13[0xd] = uVar2;
    *(long *)(param_2[0x48] + 0xa0) = lVar12;
    *(undefined8 *)(puVar13 + 3) = 0;
    (**(code **)(*param_1 + 200))(param_1,lVar12,puVar13,0);
    lVar12 = param_1[2];
    lVar7 = (**(code **)(**(long **)(*(long *)(lVar12 + 0x183a8) + 0x50) + 0x98))();
    uVar3 = *(uint *)(lVar12 + 0x4a0);
    lVar12 = param_1[2];
    lVar8 = (**(code **)(**(long **)(*(long *)(lVar12 + 0x183b0) + 0x50) + 0x98))();
    uVar4 = *(uint *)(lVar12 + 0x4a4);
    uVar9 = (**(code **)(**(long **)(param_1[2] + 0x148) + 0x88))
                      (*(long **)(param_1[2] + 0x148),*(undefined4 *)((long)puVar5 + 4));
    uVar10 = (**(code **)(**(long **)(param_1[2] + 0x148) + 0x88))
                       (*(long **)(param_1[2] + 0x148),*(undefined4 *)((long)puVar5 + 4));
    lVar12 = param_1[7];
    lVar14 = param_2[9];
    lVar18 = param_2[0x6b];
    puVar17 = (undefined4 *)param_2[0x6a];
    *puVar17 = 7;
    uVar6 = *puVar5;
    lVar11 = thunk_EXT_FUN_8011000003890f30(param_2[0xc],&DAT_fffffff00ae21f50);
    lVar15 = *(long *)(lVar11 + 0x620);
    *(long *)(lVar11 + 0x620) = lVar15 + 1;
    *(long *)(puVar17 + 1) = lVar15;
    puVar17[5] = *(undefined4 *)((long)param_2 + 0x1dc);
    lVar11 = param_2[0x20];
    puVar17[6] = param_3;
    *(long *)(puVar17 + 10) = lVar11;
    *(ulong *)(puVar17 + 0xc) = lVar7 + (ulong)uVar3 + (uVar9 & 0xffffffff);
    *(ulong *)(puVar17 + 0xe) = lVar8 + (ulong)uVar4 + (uVar10 & 0xffffffff);
    *(undefined8 *)(puVar17 + 0x10) = uVar6;
    puVar17[0x12] = (int)lVar12;
    puVar17[0x13] = (uint)((int)lVar14 != 0);
    *(long *)(puVar17 + 3) = param_2[0x40];
    puVar17[0x14] = 0;
    (**(code **)(*param_2 + 0xe0))(param_2,1);
    FUN_fffffff008202ad8(param_2[0x29],param_2 + 0x10,puVar17[10]);
    uVar1 = puVar17[5];
    uVar6 = *(undefined8 *)(puVar17 + 10);
    uVar16 = *(undefined8 *)(puVar17 + 0xe);
    uVar2 = puVar17[0x10];
    puVar13 = *(undefined4 **)(param_2[0x29] + 0x68);
    *(undefined4 **)(param_2[0x29] + 0x68) = puVar13 + 0xb;
    *puVar13 = 0xd;
    puVar13[1] = uVar1;
    *(undefined8 *)(puVar13 + 2) = uVar6;
    *(undefined8 *)(puVar13 + 4) = uVar16;
    puVar13[6] = uVar2;
    *(undefined8 *)(puVar13 + 9) = 0;
    *(undefined8 *)(puVar13 + 7) = 0;
    uVar6 = FUN_fffffff008202d20(param_2[0x29],puVar17 + 9);
    *(undefined8 *)(puVar17 + 7) = uVar6;
    (**(code **)(*param_1 + 200))(param_1,lVar18,puVar17,param_2[0x20]);
    local_78 = param_2[0x48];
    if (*(int *)(local_78 + 0x88) != 0) {
      if (*(long *)(puVar17 + 3) != 0) {
        uVar6 = *(undefined8 *)(puVar17 + 1);
        *(undefined8 *)(local_78 + 0x98) = *(undefined8 *)(puVar17 + 3);
        *(undefined8 *)(local_78 + 0x90) = uVar6;
      }
      local_a0 = (undefined *)0x0;
      thunk_EXT_FUN_8011000003204ed8(*(int *)(local_78 + 0x88),1000000,&local_a0);
      *(undefined **)(local_78 + 0x58) = local_a0;
      local_78 = param_2[0x48];
    }
    lStack_80 = param_2[2];
    local_a0 = PTR_DAT_fffffff007ca5f90;
    local_98 = DAT_fffffff007113e50;
    local_90 = FUN_fffffff00817f5cc;
    local_88 = &DAT_fffffff007c92f48;
    thunk_EXT_FUN_801100000395c120(*(undefined8 *)(lStack_80 + 0x1ac80),&local_a0);
  }
  return;
}

