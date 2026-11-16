// FUN_fffffff009c3c538 @ fffffff009c3c538 size=708

undefined8
FUN_fffffff009c3c538
          (undefined8 param_1,undefined4 *param_2,long param_3,ulong param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  ulong uVar8;
  undefined8 uVar9;
  
  uVar9 = 0xe00002c2;
  plVar4 = (long *)FUN_fffffff009c3f1d0(param_1,*param_2);
  if (plVar4 == (long *)0x0) {
    return 0xe00002c2;
  }
  if (*(char *)(param_2 + 3) == '\0') {
    plVar5 = (long *)0x0;
  }
  else if ((*(char *)((long)(param_2 + 3) + ((param_4 & 0xffffffff) - 0xd)) != '\0') ||
          (plVar5 = (long *)thunk_EXT_FUN_80110000038ce200(), plVar5 == (long *)0x0))
  goto LAB_fffffff009c3c7b8;
  plVar6 = (long *)FUN_fffffff009c28380(plVar4,plVar5,param_3 + 4);
  if (plVar6 == (long *)0x0) {
    uVar9 = 0;
    *param_5 = 0;
  }
  else {
    if ((param_2[2] != 0) &&
       (plVar7 = (long *)thunk_EXT_FUN_8011000003890f30
                                   (plVar6,*(undefined8 *)PTR_DAT_fffffff00806c9c8),
       plVar7 != (long *)0x0)) {
      (**(code **)(*plVar7 + 0x118))(plVar7,DAT_fffffff008066f80);
    }
    plVar7 = (long *)thunk_EXT_FUN_80110000038d4814(*param_5 - 0xc,0,0);
    if (plVar7 == (long *)0x0) {
      uVar9 = 0xe00002bd;
    }
    else {
      (**(code **)(*plVar7 + 0x80))();
      iVar1 = (**(code **)(*plVar6 + 0x30))(plVar6,plVar7);
      if (iVar1 == 0) {
        uVar9 = 0xe00002c7;
      }
      else {
        uVar2 = (**(code **)(*plVar7 + 0xb8))(plVar7);
        uVar8 = (ulong)uVar2;
        if ((ulong)*param_5 < uVar8 + 0xc) {
          FUN_fffffff009c2a738(plVar4);
          uVar3 = FUN_fffffff009c23788(plVar4);
          uVar9 = 0xe00002db;
        }
        else {
          uVar9 = (**(code **)(*plVar7 + 0x78))(plVar7);
          thunk_EXT_FUN_8011000003a61b10(param_3 + 0xc,uVar9,uVar8);
          *param_5 = (uint)(uVar8 + 0xc);
          FUN_fffffff009c2a738(plVar4);
          uVar3 = FUN_fffffff009c23788(plVar4);
          uVar9 = 0;
        }
        if (uVar3 < uVar2) {
          FUN_fffffff009c237b8(plVar4,uVar8);
        }
        FUN_fffffff009c2a744(plVar4);
      }
      (**(code **)(*plVar7 + 0x28))(plVar7);
    }
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
LAB_fffffff009c3c7b8:
  (**(code **)(*plVar4 + 0x28))(plVar4);
  return uVar9;
}

