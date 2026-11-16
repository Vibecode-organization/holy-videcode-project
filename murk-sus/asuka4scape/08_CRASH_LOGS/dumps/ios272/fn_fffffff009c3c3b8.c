// FUN_fffffff009c3c3b8 @ fffffff009c3c3b8 size=384

undefined4
FUN_fffffff009c3c3b8(undefined8 param_1,undefined4 *param_2,ulong param_3,undefined8 param_4)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined4 uVar8;
  
  uVar8 = 0xe00002c2;
  plVar2 = (long *)FUN_fffffff009c3f1d0(param_1,*param_2);
  if (plVar2 != (long *)0x0) {
    plVar3 = (long *)thunk_EXT_FUN_80110000038d4754
                               (param_2 + 3,
                                (long)param_2 + ((param_3 & 0xffffffff) - (long)(param_2 + 3)),0);
    if (plVar3 != (long *)0x0) {
      plVar4 = (long *)thunk_EXT_FUN_8011000003890f30
                                 (plVar3,*(undefined8 *)PTR_DAT_fffffff00806c9f0);
      if (plVar4 != (long *)0x0) {
        lVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,0);
        lVar6 = (**(code **)(*plVar4 + 0x118))(plVar4,1);
        if (lVar6 == 0) {
          lVar7 = 0;
        }
        else {
          lVar7 = thunk_EXT_FUN_8011000003890f30(lVar6,*(undefined8 *)PTR_DAT_fffffff00806ca10);
        }
        if (lVar5 != 0 && (lVar6 == 0 || lVar7 != 0)) {
          iVar1 = FUN_fffffff009c28220(plVar2,lVar7,lVar5,param_4);
          uVar8 = 0;
          if (iVar1 == 0) {
            uVar8 = 0xe00002c9;
          }
        }
      }
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return uVar8;
}

