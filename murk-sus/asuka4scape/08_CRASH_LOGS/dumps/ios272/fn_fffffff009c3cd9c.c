// FUN_fffffff009c3cd9c @ fffffff009c3cd9c size=460

/* WARNING: Removing unreachable block (ram,0xfffffff009c3ce0c) */

undefined8
FUN_fffffff009c3cd9c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  bool bVar2;
  long *plVar3;
  long *plVar4;
  undefined8 uVar5;
  long *plVar6;
  undefined4 local_5c;
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar3 = (long *)FUN_fffffff009c3f130();
  if (plVar3 == (long *)0x0) {
    uVar5 = 0xe00002c2;
    goto LAB_fffffff009c3cf10;
  }
  plVar6 = (long *)plVar3[8];
  if (plVar6 == (long *)0x0) {
    plVar6 = (long *)0x0;
LAB_fffffff009c3ce50:
    bVar2 = true;
  }
  else {
    if (plVar6 == (long *)0x0) goto LAB_fffffff009c3ce50;
    (**(code **)(*plVar6 + 0x20))(plVar6);
    bVar2 = false;
  }
  local_5c = 0xaaaaaaaa;
  uVar1 = (uint)param_3 & 1;
  if ((((uint)param_3 >> 2 & 1) != 0) &&
     (plVar4 = (long *)FUN_fffffff009c26fcc(plVar6,2 - uVar1,0xffffffff), plVar4 != (long *)0x0)) {
    FUN_fffffff009c41314(plVar4,0);
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  FUN_fffffff009c2af10(plVar6,uVar1);
  uVar5 = FUN_fffffff009c209b8(plVar6,param_3,&local_5c);
  if ((int)uVar5 == 0) {
    uVar5 = thunk_EXT_FUN_8011000003386690(&local_5c,param_4,4);
  }
  if (!bVar2) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  (**(code **)(*plVar3 + 0x28))(plVar3);
LAB_fffffff009c3cf10:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_58) {
    return uVar5;
  }
  uVar5 = thunk_EXT_FUN_8011000003a48590();
  return uVar5;
}

