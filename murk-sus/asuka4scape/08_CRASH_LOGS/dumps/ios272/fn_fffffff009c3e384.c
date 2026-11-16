// FUN_fffffff009c3e384 @ fffffff009c3e384 size=492

/* WARNING: Removing unreachable block (ram,0xfffffff009c3e4cc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c3e43c) */

undefined8
FUN_fffffff009c3e384
          (long param_1,undefined8 param_2,long *param_3,undefined8 param_4,undefined4 param_5)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  
  uVar5 = 0xe00002c2;
  plVar1 = (long *)thunk_EXT_FUN_80110000038d4754(param_4,param_5,0);
  plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(plVar1,*(undefined8 *)PTR_DAT_fffffff00806c9c8);
  if (plVar2 == (long *)0x0) {
    if (plVar1 != (long *)0x0) {
      (**(code **)(*plVar1 + 0x28))(plVar1);
    }
    plVar1 = (long *)FUN_fffffff009c372dc(*(undefined8 *)(param_1 + 0xe8));
    if (plVar1 == (long *)0x0) {
      return 0xe00002c2;
    }
  }
  else {
    plVar1 = (long *)FUN_fffffff009c372dc(*(undefined8 *)(param_1 + 0xe8));
    if (plVar1 == (long *)0x0) goto LAB_fffffff009c3e534;
    (**(code **)(*plVar2 + 0x20))(plVar2);
    lVar4 = *(long *)(param_1 + 0xf8);
    if (lVar4 == 0) {
      lVar4 = 0;
    }
    plVar3 = (long *)FUN_fffffff009c43898(plVar1,plVar2,lVar4);
    if (plVar3 != (long *)0x0) {
      *param_3 = plVar3[5];
      lVar4 = *(long *)(param_1 + 0xf8);
      if (lVar4 == 0) {
        lVar4 = 0;
      }
      uVar5 = thunk_EXT_FUN_80110000039a3b30(lVar4,plVar3,param_2);
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
  }
  (**(code **)(*plVar1 + 0x28))(plVar1);
  if (plVar2 == (long *)0x0) {
    return uVar5;
  }
LAB_fffffff009c3e534:
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return uVar5;
}

