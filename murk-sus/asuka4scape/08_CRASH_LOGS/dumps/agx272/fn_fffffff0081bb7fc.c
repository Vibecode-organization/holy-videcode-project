// FUN_fffffff0081bb7fc @ fffffff0081bb7fc size=1056

/* WARNING: Removing unreachable block (ram,0xfffffff0081bb874) */

undefined8 FUN_fffffff0081bb7fc(long *param_1,long *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long *plVar6;
  float *pfVar7;
  undefined4 *puVar8;
  uint uVar9;
  float fVar10;
  undefined4 uVar11;
  
  (**(code **)(*param_1 + 0x6c0))(param_1,0,0);
  lVar5 = (**(code **)(*param_2 + 0x138))(*param_2 + 0x138,param_2,"target");
  puVar2 = PTR_DAT_fffffff007ca60a8;
  if (lVar5 != 0) {
    plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar6 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar3 = (**(code **)(*plVar6 + 0xa8))();
    lVar5 = param_1[0x50];
    *(int *)(lVar5 + 0x11104) = iVar3;
    if (*(int *)(lVar5 + 0x110a0) == 1) {
      if (iVar3 == 0) {
        uVar9 = 0;
        lVar5 = param_1[0x123];
        *(undefined4 *)(lVar5 + 0x114) = *(undefined4 *)(param_1[0x58] + 0x277a);
      }
      else {
        lVar5 = param_1[0x123];
        *(int *)(lVar5 + 0x114) = iVar3;
        uVar9 = 1;
      }
    }
    else {
      iVar4 = *(int *)(lVar5 + 0x110a4);
      if (iVar3 != 0) {
        iVar4 = iVar3;
      }
      lVar5 = param_1[0x123];
      *(int *)(lVar5 + 0x114) = iVar4;
      uVar9 = (uint)(iVar3 != 0);
    }
    *(uint *)(lVar5 + 0x118) = uVar9;
  }
  lVar5 = (**(code **)(*param_2 + 0x138))(param_2,"deadzone");
  if (lVar5 != 0) {
    plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2);
    if (plVar6 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar4 = (**(code **)(*plVar6 + 0xa8))();
    lVar5 = param_1[0x50];
    *(int *)(lVar5 + 0x1110c) = iVar4;
    iVar3 = *(int *)(lVar5 + 0x110a8);
    if (iVar4 != 0) {
      iVar3 = iVar4;
    }
    *(int *)(param_1[0x123] + 0x124) = iVar3;
  }
  lVar5 = (**(code **)(*param_2 + 0x138))(param_2,"Kp");
  puVar1 = PTR_DAT_fffffff007ca6090;
  if (lVar5 != 0) {
    plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)PTR_DAT_fffffff007ca6090);
    if (plVar6 == (long *)0x0) {
      return 0xe00002c2;
    }
    pfVar7 = (float *)(**(code **)(*plVar6 + 0xd8))();
    fVar10 = *pfVar7;
    lVar5 = param_1[0x50];
    *(float *)(lVar5 + 0x110f8) = fVar10;
    if (fVar10 == 0.0) {
      fVar10 = *(float *)(lVar5 + 0x110c4);
    }
    *(float *)(param_1[0x123] + 0x108) = fVar10;
  }
  lVar5 = (**(code **)(*param_2 + 0x138))(param_2,"Ki");
  if (lVar5 != 0) {
    plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar1);
    if (plVar6 == (long *)0x0) {
      return 0xe00002c2;
    }
    pfVar7 = (float *)(**(code **)(*plVar6 + 0xd8))();
    fVar10 = *pfVar7;
    lVar5 = param_1[0x50];
    *(float *)(lVar5 + 0x110fc) = fVar10;
    if (fVar10 == 0.0) {
      fVar10 = *(float *)(lVar5 + 0x110c8);
    }
    *(float *)(param_1[0x123] + 0x10c) = fVar10;
  }
  lVar5 = (**(code **)(*param_2 + 0x138))(param_2,"control");
  if (lVar5 != 0) {
    plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar1);
    if (plVar6 == (long *)0x0) {
      return 0xe00002c2;
    }
    puVar8 = (undefined4 *)(**(code **)(*plVar6 + 0xd8))();
    uVar11 = *puVar8;
    *(undefined4 *)(param_1[0x50] + 0x110f0) = uVar11;
    *(undefined4 *)(param_1[0x123] + 0x100) = uVar11;
  }
  lVar5 = (**(code **)(*param_2 + 0x138))(param_2,"transfer");
  if (lVar5 != 0) {
    plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2);
    if (plVar6 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar11 = (**(code **)(*plVar6 + 0xa8))();
    *(undefined4 *)(param_1[0x50] + 0x110f4) = uVar11;
    *(undefined4 *)(param_1[0x123] + 0x104) = uVar11;
  }
  lVar5 = (**(code **)(*param_2 + 0x138))(param_2,"tfc");
  if (lVar5 == 0) {
    lVar5 = param_1[0x123];
  }
  else {
    plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2);
    if (plVar6 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar4 = (**(code **)(*plVar6 + 0xa8))();
    lVar5 = param_1[0x50];
    *(int *)(lVar5 + 0x11100) = iVar4;
    iVar3 = *(int *)(lVar5 + 0x110d0);
    if (iVar4 != 0) {
      iVar3 = iVar4;
    }
    lVar5 = param_1[0x123];
    *(int *)(lVar5 + 0x110) = iVar3;
  }
  *(undefined4 *)(lVar5 + 0xec) = 1;
  return 0;
}

