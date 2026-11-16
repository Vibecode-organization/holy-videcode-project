// FUN_fffffff0081bbc1c @ fffffff0081bbc1c size=2272

/* WARNING: Removing unreachable block (ram,0xfffffff0081bbc94) */

undefined8 FUN_fffffff0081bbc1c(long *param_1,long *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  undefined4 *puVar8;
  long lVar9;
  long lVar10;
  
  (**(code **)(*param_1 + 0x6c0))(param_1,0,0);
  lVar6 = (**(code **)(*param_2 + 0x138))(*param_2 + 0x138,param_2,"target");
  puVar2 = PTR_DAT_fffffff007ca60a8;
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar3 = (**(code **)(*plVar7 + 0xa8))();
    lVar6 = param_1[0x50];
    *(int *)(lVar6 + 0x10e48) = iVar3;
    iVar5 = *(int *)(lVar6 + 0x10de0);
    if (iVar3 != 0) {
      iVar5 = iVar3;
    }
    *(int *)(param_1[0x123] + 0x154) = iVar5;
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"deadzone");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar2);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar4 = (**(code **)(*plVar7 + 0xa8))();
    lVar6 = param_1[0x50];
    *(undefined4 *)(lVar6 + 0x10e4c) = uVar4;
    iVar5 = *(int *)(lVar6 + 0x10de0);
    if (*(int *)(lVar6 + 0x10e48) != 0) {
      iVar5 = *(int *)(lVar6 + 0x10e48);
    }
    *(int *)(param_1[0x123] + 0x158) = iVar5;
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"Kp");
  puVar1 = PTR_DAT_fffffff007ca6090;
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)PTR_DAT_fffffff007ca6090);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    puVar8 = (undefined4 *)(**(code **)(*plVar7 + 0xd8))();
    uVar4 = *puVar8;
    lVar9 = param_1[0x50];
    *(undefined4 *)(lVar9 + 0x10e70) = 1;
    *(undefined4 *)(lVar9 + 0x10e68) = uVar4;
    lVar10 = param_1[0x123];
    *(undefined4 *)(lVar10 + 0x17c) = 1;
    lVar6 = 0x30;
    if (*(int *)(lVar9 + 0x10e70) != 0) {
      lVar6 = 0x8c;
    }
    *(undefined4 *)(lVar10 + 0x174) = *(undefined4 *)(lVar9 + 0x10ddc + lVar6);
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"Ki");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar1);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    puVar8 = (undefined4 *)(**(code **)(*plVar7 + 0xd8))();
    uVar4 = *puVar8;
    lVar9 = param_1[0x50];
    *(undefined4 *)(lVar9 + 0x10e80) = 1;
    *(undefined4 *)(lVar9 + 0x10e78) = uVar4;
    lVar10 = param_1[0x123];
    *(undefined4 *)(lVar10 + 0x18c) = 1;
    lVar6 = 0x38;
    if (*(int *)(lVar9 + 0x10e80) != 0) {
      lVar6 = 0x9c;
    }
    *(undefined4 *)(lVar10 + 0x184) = *(undefined4 *)(lVar9 + 0x10ddc + lVar6);
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"tfc");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar2);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar4 = (**(code **)(*plVar7 + 0xa8))();
    lVar9 = param_1[0x50];
    *(undefined4 *)(lVar9 + 0x10e60) = 1;
    *(undefined4 *)(lVar9 + 0x10e58) = uVar4;
    lVar10 = param_1[0x123];
    *(undefined4 *)(lVar10 + 0x16c) = 1;
    lVar6 = 0x18;
    if (*(int *)(lVar9 + 0x10e60) != 0) {
      lVar6 = 0x7c;
    }
    *(undefined4 *)(lVar10 + 0x164) = *(undefined4 *)(lVar9 + 0x10ddc + lVar6);
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"Kp-1");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar1);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    puVar8 = (undefined4 *)(**(code **)(*plVar7 + 0xd8))();
    uVar4 = *puVar8;
    lVar9 = param_1[0x50];
    *(undefined4 *)(lVar9 + 0x10e74) = 1;
    *(undefined4 *)(lVar9 + 0x10e6c) = uVar4;
    lVar10 = param_1[0x123];
    *(undefined4 *)(lVar10 + 0x180) = 1;
    lVar6 = 0x30;
    if (*(int *)(lVar9 + 0x10e74) != 0) {
      lVar6 = 0x8c;
    }
    *(undefined4 *)(lVar10 + 0x178) = *(undefined4 *)(lVar9 + lVar6 + 0x10de0);
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"Ki-1");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar1);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    puVar8 = (undefined4 *)(**(code **)(*plVar7 + 0xd8))();
    uVar4 = *puVar8;
    lVar9 = param_1[0x50];
    *(undefined4 *)(lVar9 + 0x10e84) = 1;
    *(undefined4 *)(lVar9 + 0x10e7c) = uVar4;
    lVar10 = param_1[0x123];
    *(undefined4 *)(lVar10 + 400) = 1;
    lVar6 = 0x38;
    if (*(int *)(lVar9 + 0x10e84) != 0) {
      lVar6 = 0x9c;
    }
    *(undefined4 *)(lVar10 + 0x188) = *(undefined4 *)(lVar9 + lVar6 + 0x10de0);
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"tfc-1");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar2);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar4 = (**(code **)(*plVar7 + 0xa8))();
    lVar9 = param_1[0x50];
    *(undefined4 *)(lVar9 + 0x10e64) = 1;
    *(undefined4 *)(lVar9 + 0x10e5c) = uVar4;
    lVar10 = param_1[0x123];
    *(undefined4 *)(lVar10 + 0x170) = 1;
    lVar6 = 0x18;
    if (*(int *)(lVar9 + 0x10e64) != 0) {
      lVar6 = 0x7c;
    }
    *(undefined4 *)(lVar10 + 0x168) = *(undefined4 *)(lVar9 + lVar6 + 0x10de0);
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"dual-filter");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar2);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar5 = (**(code **)(*plVar7 + 0xa8))();
    lVar6 = param_1[0x50];
    *(uint *)(lVar6 + 0x10e50) = (uint)(iVar5 != 0);
    *(undefined4 *)(lVar6 + 0x10e54) = 1;
    lVar9 = param_1[0x123];
    *(undefined4 *)(lVar9 + 0x160) = 1;
    *(uint *)(lVar9 + 0x15c) = (uint)(*(int *)(lVar6 + 0x10e50) != 0);
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"control");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar1);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    puVar8 = (undefined4 *)(**(code **)(*plVar7 + 0xd8))();
    uVar4 = *puVar8;
    *(undefined4 *)(param_1[0x50] + 0x10e90) = uVar4;
    *(undefined4 *)(param_1[0x123] + 0x194) = uVar4;
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"inactive-thresh");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar2);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar3 = (**(code **)(*plVar7 + 0xa8))();
    lVar6 = param_1[0x50];
    *(int *)(lVar6 + 0x10e94) = iVar3;
    iVar5 = *(int *)(lVar6 + 0x10e30);
    if (iVar3 != 0) {
      iVar5 = iVar3;
    }
    *(int *)(param_1[0x123] + 0x198) = iVar5;
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"se-criteria");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar2);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar3 = (**(code **)(*plVar7 + 0xa8))();
    lVar6 = param_1[0x50];
    *(int *)(lVar6 + 0x10e98) = iVar3;
    iVar5 = *(int *)(lVar6 + 0x10e34);
    if (iVar3 != 0) {
      iVar5 = iVar3;
    }
    *(int *)(param_1[0x123] + 0x19c) = iVar5;
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"engage-tolerance");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar2);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar3 = (**(code **)(*plVar7 + 0xa8))();
    lVar6 = param_1[0x50];
    *(int *)(lVar6 + 0x10e9c) = iVar3;
    iVar5 = *(int *)(lVar6 + 0x10e38);
    if (iVar3 != 0) {
      iVar5 = iVar3;
    }
    *(int *)(param_1[0x123] + 0x1a0) = iVar5;
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"reset-tolerance");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar2);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar3 = (**(code **)(*plVar7 + 0xa8))();
    lVar6 = param_1[0x50];
    *(int *)(lVar6 + 0x10ea0) = iVar3;
    iVar5 = *(int *)(lVar6 + 0x10e3c);
    if (iVar3 != 0) {
      iVar5 = iVar3;
    }
    *(int *)(param_1[0x123] + 0x1a4) = iVar5;
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"reset-criteria");
  if (lVar6 != 0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar2);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar3 = (**(code **)(*plVar7 + 0xa8))();
    lVar6 = param_1[0x50];
    *(int *)(lVar6 + 0x10ea4) = iVar3;
    iVar5 = *(int *)(lVar6 + 0x10e40);
    if (iVar3 != 0) {
      iVar5 = iVar3;
    }
    *(int *)(param_1[0x123] + 0x1a8) = iVar5;
  }
  lVar6 = (**(code **)(*param_2 + 0x138))(param_2,"downsample-count");
  if (lVar6 == 0) {
    lVar6 = param_1[0x123];
  }
  else {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)puVar2);
    if (plVar7 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar4 = (**(code **)(*plVar7 + 0xa8))();
    *(undefined4 *)(param_1[0x50] + 0x10ea8) = uVar4;
    lVar6 = param_1[0x123];
    *(undefined4 *)(lVar6 + 0x1ac) = uVar4;
  }
  *(undefined4 *)(lVar6 + 0x148) = 1;
  return 0;
}

