// FUN_fffffff008181698 @ fffffff008181698 size=220

undefined8 FUN_fffffff008181698(long param_1,long *param_2,undefined8 param_3)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  
  uVar3 = 0xe00002c2;
  lVar1 = thunk_EXT_FUN_8011000003890f30(param_3,*(undefined8 *)PTR_DAT_fffffff007ca60c8);
  if (((lVar1 != 0) &&
      (lVar1 = (**(code **)(*param_2 + 0x128))(param_2,DAT_fffffff00ae21b78), lVar1 != 0)) &&
     (plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(lVar1,*(undefined8 *)PTR_DAT_fffffff007ca60a8)
     , plVar2 != (long *)0x0)) {
    uVar3 = (**(code **)(*plVar2 + 0xa8))();
    if (*(long *)(param_1 + 0x4b0) == 0) {
      uVar3 = 0xe00002d8;
    }
    else {
      FUN_fffffff0081a8898(*(long *)(param_1 + 0x4b0),0,uVar3,0);
      uVar3 = 0;
    }
  }
  return uVar3;
}

