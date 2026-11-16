// FUN_fffffff0081b991c @ fffffff0081b991c size=384

/* WARNING: Removing unreachable block (ram,0xfffffff0081b9a24) */

undefined8
FUN_fffffff0081b991c(long param_1,long *param_2,undefined8 param_3,code *param_4,ulong param_5)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  undefined8 uVar4;
  ulong uVar5;
  
  lVar2 = (**(code **)(*param_2 + 0x138))(param_2,param_3);
  if (lVar2 != 0) {
    lVar2 = thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca60c8);
    if (lVar2 == 0) {
      return 0xe00002c2;
    }
    lVar2 = (**(code **)(*param_2 + 0x138))(param_2,"Value");
    if (lVar2 == 0) {
      return 0xe00002c2;
    }
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar3 == (long *)0x0) {
      return 0xe00002c2;
    }
    lVar2 = (long)param_5 >> 1;
    plVar1 = (long *)(param_1 + (int)lVar2);
    if (lVar2 != (int)lVar2) {
      plVar1 = (long *)(param_1 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
    }
    if ((param_5 & 1) != 0) {
      param_4 = *(code **)(*plVar1 + ((ulong)param_4 & 0xffffffff));
    }
    uVar4 = (**(code **)(*plVar3 + 0xb0))();
    uVar5 = (*param_4)(plVar1,uVar4);
    if ((uVar5 & 1) == 0) {
      (**(code **)(*plVar3 + 0xa0))(plVar3);
      return 0xe00002c2;
    }
  }
  return 0;
}

