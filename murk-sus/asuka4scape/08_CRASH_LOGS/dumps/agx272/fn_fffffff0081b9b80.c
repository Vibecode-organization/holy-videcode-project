// FUN_fffffff0081b9b80 @ fffffff0081b9b80 size=1084

/* WARNING: Removing unreachable block (ram,0xfffffff0081b9bf8) */

undefined8 FUN_fffffff0081b9b80(long *param_1,long *param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  long *plVar7;
  float *pfVar8;
  uint uVar9;
  float fVar10;
  
  (**(code **)(*param_1 + 0x6c0))(param_1,0,0);
  lVar6 = (**(code **)(*param_2 + 0x138))(*param_2 + 0x138,param_2,"enable");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)PTR_DAT_fffffff007ca60c8);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar3 = (**(code **)(*plVar7 + 0x78))();
    *(undefined4 *)(param_1[0x123] + 0x620) = uVar3;
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"Kp");
  puVar2 = PTR_DAT_fffffff007ca6090;
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)PTR_DAT_fffffff007ca6090);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    pfVar8 = (float *)(**(code **)(*plVar7 + 0xd8))();
    fVar10 = *(float *)(param_1[0x50] + 0x11058);
    if (*pfVar8 != 0.0) {
      fVar10 = *pfVar8;
    }
    *(float *)(param_1[0x123] + 0x624) = fVar10;
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"Ki");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar2);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    pfVar8 = (float *)(**(code **)(*plVar7 + 0xd8))();
    fVar10 = *(float *)(param_1[0x50] + 0x1105c);
    if (*pfVar8 != 0.0) {
      fVar10 = *pfVar8;
    }
    *(float *)(param_1[0x123] + 0x628) = fVar10;
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"tfc");
  puVar2 = PTR_DAT_fffffff007ca60a8;
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar4 = (**(code **)(*plVar7 + 0xa8))();
    iVar1 = *(int *)(param_1[0x50] + 0x11060);
    if (iVar4 != 0) {
      iVar1 = iVar4;
    }
    *(int *)(param_1[0x123] + 0x62c) = iVar1;
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"deadzone");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar2);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar4 = (**(code **)(*plVar7 + 0xa8))();
    iVar1 = *(int *)(param_1[0x50] + 0x11090);
    if (iVar4 != 0) {
      iVar1 = iVar4;
    }
    *(int *)(param_1[0x123] + 0x634) = iVar1;
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"target");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar2);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar4 = (**(code **)(*plVar7 + 0xa8))();
    iVar1 = *(int *)(param_1[0x50] + 0x1108c);
    if (iVar4 != 0) {
      iVar1 = iVar4;
    }
    lVar6 = param_1[0x123];
    *(int *)(lVar6 + 0x630) = iVar1;
    *(uint *)(lVar6 + 0x638) = (uint)(iVar4 != 0);
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"transfer_min_clamp");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar2);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar5 = (**(code **)(*plVar7 + 0xa8))();
    if (0x28f5c28 < (uVar5 * -0x3d70a3d7 >> 2 | uVar5 * 0x40000000)) {
      return 0xe00002c2;
    }
    lVar6 = param_1[0x50];
    if (uVar5 == 0) {
      uVar9 = *(uint *)(lVar6 + 0x1107c);
    }
    else {
      uVar9 = *(int *)(lVar6 + 0x19440) * 100 - 100;
      if (uVar5 <= uVar9) {
        uVar9 = uVar5;
      }
    }
    *(uint *)(param_1[0x123] + 0x640) = uVar9;
    FUN_fffffff00817eee4(lVar6,param_1[0x58] + 0x2ee4,(ulong)uVar9 / 100);
  }
  *(undefined4 *)(param_1[0x123] + 0x61c) = 1;
  return 0;
}

