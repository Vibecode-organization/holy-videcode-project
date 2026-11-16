// FUN_fffffff009c3cb74 @ fffffff009c3cb74 size=276

/* WARNING: Removing unreachable block (ram,0xfffffff009c3cbd4) */

undefined8 FUN_fffffff009c3cb74(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  bool bVar4;
  
  if (1 < (uint)param_3) {
    return 0xe00002c2;
  }
  plVar2 = (long *)FUN_fffffff009c3f130();
  if (plVar2 == (long *)0x0) {
    return 0xe00002c2;
  }
  plVar3 = (long *)plVar2[8];
  if (plVar3 == (long *)0x0) {
    plVar3 = (long *)0x0;
  }
  else if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x20))(plVar3);
    bVar4 = false;
    goto LAB_fffffff009c3cc10;
  }
  bVar4 = true;
LAB_fffffff009c3cc10:
  iVar1 = FUN_fffffff009c2c9ec(plVar2,param_3);
  if (iVar1 != 0) {
    FUN_fffffff009c22ee0(plVar3,param_3);
  }
  if (!bVar4) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return 0;
}

