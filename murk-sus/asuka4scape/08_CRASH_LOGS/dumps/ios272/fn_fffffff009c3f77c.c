// FUN_fffffff009c3f77c @ fffffff009c3f77c size=528

undefined8
FUN_fffffff009c3f77c
          (undefined8 param_1,undefined4 *param_2,undefined8 param_3,ulong param_4,uint *param_5)

{
  uint uVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  ulong uVar6;
  undefined8 uVar7;
  char *pcVar8;
  uint uVar9;
  undefined4 local_5c;
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar7 = 0xe00002c2;
  plVar2 = (long *)FUN_fffffff009c3f1d0(param_1,*param_2);
  if (plVar2 == (long *)0x0) goto LAB_fffffff009c3f950;
  pcVar8 = (char *)(param_2 + 3);
  if (*pcVar8 == '\0') {
    plVar3 = (long *)0x0;
LAB_fffffff009c3f808:
    local_5c = 0xaaaaaaaa;
    plVar4 = (long *)FUN_fffffff009c28380(plVar2,plVar3,&local_5c);
    if (plVar4 == (long *)0x0) {
      uVar7 = 0;
      *param_5 = 0;
    }
    else {
      plVar5 = (long *)thunk_EXT_FUN_8011000003890f30
                                 (plVar4,*(undefined8 *)PTR_DAT_fffffff00806c9e8);
      if (plVar5 == (long *)0x0) {
        uVar7 = 0xe00002c7;
      }
      else {
        uVar6 = (**(code **)(*plVar5 + 0xa0))();
        uVar7 = (**(code **)(*plVar5 + 0xd8))(plVar5);
        uVar9 = (uint)uVar6;
        if (*param_5 < uVar9) {
          *param_5 = uVar9;
          uVar1 = FUN_fffffff009c23788(plVar2);
          uVar7 = 0xe00002db;
        }
        else {
          thunk_EXT_FUN_8011000003a61b10(param_3,uVar7,uVar6 & 0xffffffff);
          *param_5 = uVar9;
          uVar1 = FUN_fffffff009c23788(plVar2);
          uVar7 = 0;
        }
        if (uVar1 < uVar9) {
          FUN_fffffff009c237b8(plVar2,uVar6);
        }
      }
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
  }
  else if ((pcVar8[(param_4 & 0xffffffff) - 0xd] == '\0') &&
          (plVar3 = (long *)thunk_EXT_FUN_80110000038ce200(pcVar8), plVar3 != (long *)0x0))
  goto LAB_fffffff009c3f808;
  (**(code **)(*plVar2 + 0x28))(plVar2);
LAB_fffffff009c3f950:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_58) {
    return uVar7;
  }
  uVar7 = thunk_EXT_FUN_8011000003a48590();
  return uVar7;
}

