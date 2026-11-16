// FUN_fffffff0081bc4fc @ fffffff0081bc4fc size=1528

undefined8 FUN_fffffff0081bc4fc(long *param_1,long *param_2)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  
  lVar2 = (**(code **)(*param_2 + 0x138))(param_2,"Kp");
  if (lVar2 != 0) {
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca6090);
    if (plVar3 == (long *)0x0) {
      return 0xe00002c2;
    }
    puVar4 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    uVar5 = (**(code **)(*param_1 + 0x870))(*puVar4,param_1,0);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
  }
  lVar2 = (**(code **)(*param_2 + 0x138))(param_2,"Ki");
  if (lVar2 != 0) {
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca6090);
    if (plVar3 == (long *)0x0) {
      return 0xe00002c2;
    }
    puVar4 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    uVar5 = (**(code **)(*param_1 + 0x868))(*puVar4,param_1,0);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
  }
  lVar2 = (**(code **)(*param_2 + 0x138))(param_2,"tfc");
  if (lVar2 != 0) {
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar3 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar5 = (**(code **)(*plVar3 + 0xa8))();
    uVar5 = (**(code **)(*param_1 + 0x878))(param_1,uVar5,0);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
  }
  lVar2 = (**(code **)(*param_2 + 0x138))(param_2,"Kp-1");
  if (lVar2 != 0) {
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca6090);
    if (plVar3 == (long *)0x0) {
      return 0xe00002c2;
    }
    puVar4 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    uVar5 = (**(code **)(*param_1 + 0x870))(*puVar4,param_1,1);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
  }
  lVar2 = (**(code **)(*param_2 + 0x138))(param_2,"Ki-1");
  if (lVar2 != 0) {
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca6090);
    if (plVar3 == (long *)0x0) {
      return 0xe00002c2;
    }
    puVar4 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    uVar5 = (**(code **)(*param_1 + 0x868))(*puVar4,param_1,1);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
  }
  lVar2 = (**(code **)(*param_2 + 0x138))(param_2,"tfc-1");
  if (lVar2 != 0) {
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar3 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar5 = (**(code **)(*plVar3 + 0xa8))();
    uVar5 = (**(code **)(*param_1 + 0x878))(param_1,uVar5,1);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
  }
  lVar2 = (**(code **)(*param_2 + 0x138))(param_2,"dual-filter");
  if (lVar2 != 0) {
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar3 == (long *)0x0) {
      return 0xe00002c2;
    }
    iVar1 = (**(code **)(*plVar3 + 0xa8))();
    uVar5 = (**(code **)(*param_1 + 0x880))(param_1,iVar1 != 0);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
  }
  lVar2 = (**(code **)(*param_2 + 0x138))(param_2,"transfer");
  if (lVar2 != 0) {
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar3 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar5 = (**(code **)(*plVar3 + 0xa8))();
    uVar5 = (**(code **)(*param_1 + 0x888))(param_1,uVar5);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
  }
  lVar2 = (**(code **)(*param_2 + 0x138))(param_2,"target");
  if (lVar2 != 0) {
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar3 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar5 = (**(code **)(*plVar3 + 0xa8))();
    uVar5 = (**(code **)(*param_1 + 0x890))(param_1,uVar5);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
  }
  lVar2 = (**(code **)(*param_2 + 0x138))(param_2,"deadzone");
  if (lVar2 != 0) {
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar3 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar5 = (**(code **)(*plVar3 + 0xa8))();
    uVar5 = (**(code **)(*param_1 + 0x898))(param_1,uVar5);
    if ((int)uVar5 != 0) {
      return uVar5;
    }
  }
  *(undefined1 *)(param_1[0x123] + 0x5c8) = 1;
  return 0;
}

