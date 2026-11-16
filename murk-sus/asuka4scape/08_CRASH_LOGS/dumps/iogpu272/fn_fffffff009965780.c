// FUN_fffffff009965780 @ fffffff009965780 size=296

undefined8 FUN_fffffff009965780(long param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  undefined8 uVar5;
  
  lVar1 = thunk_EXT_FUN_80110000032970b4(*(undefined8 *)(param_1 + 0x50));
  uVar5 = 0;
  if (lVar1 != 0) {
    plVar2 = (long *)thunk_EXT_FUN_801100000392ef4c("AppleMobileFileIntegrity",0);
    if (plVar2 == (long *)0x0) {
      uVar5 = 0;
    }
    else {
      plVar3 = (long *)thunk_EXT_FUN_801100000392ece0(plVar2,10000000000);
      if (plVar3 == (long *)0x0) {
        uVar5 = 0;
      }
      else {
        plVar4 = (long *)thunk_EXT_FUN_8011000003890f30
                                   (plVar3,*(undefined8 *)PTR_DAT_fffffff007ff2780);
        if (plVar4 == (long *)0x0) {
          uVar5 = 0;
        }
        else {
          (**(code **)(*plVar4 + 0x20))();
          uVar5 = thunk_EXT_FUN_8011000001ec3e40(plVar4,lVar1);
          (**(code **)(*plVar4 + 0x28))(plVar4);
        }
        (**(code **)(*plVar3 + 0x28))(plVar3);
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  return uVar5;
}

