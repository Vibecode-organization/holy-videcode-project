// FUN_fffffff009c3b3ac @ fffffff009c3b3ac size=480

/* WARNING: Removing unreachable block (ram,0xfffffff009c3b444) */

undefined8
FUN_fffffff009c3b3ac(undefined8 param_1,undefined4 *param_2,long param_3,int param_4,int *param_5)

{
  uint uVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  undefined8 uVar5;
  bool bVar6;
  undefined4 local_5c;
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar5 = 0xe00002c2;
  if ((((param_3 == 0) || (param_2 == (undefined4 *)0x0)) || (param_4 != 0xc)) ||
     (*param_5 != 0xc68)) goto LAB_fffffff009c3b550;
  uVar1 = param_2[1];
  plVar2 = (long *)FUN_fffffff009c3f130(param_1,*param_2);
  if (plVar2 == (long *)0x0) goto LAB_fffffff009c3b550;
  plVar4 = (long *)plVar2[8];
  if (plVar4 == (long *)0x0) {
    plVar4 = (long *)0x0;
LAB_fffffff009c3b47c:
    bVar6 = true;
  }
  else {
    if (plVar4 == (long *)0x0) goto LAB_fffffff009c3b47c;
    (**(code **)(*plVar4 + 0x20))(plVar4);
    bVar6 = false;
  }
  local_5c = 0xaaaaaaaa;
  if (((uVar1 >> 2 & 1) != 0) &&
     (plVar3 = (long *)FUN_fffffff009c26fcc(plVar4,2 - (uVar1 & 1),0xffffffff),
     plVar3 != (long *)0x0)) {
    FUN_fffffff009c41314(plVar3,0);
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  FUN_fffffff009c2af10(plVar4,uVar1 & 1);
  uVar5 = FUN_fffffff009c209b8(plVar4,uVar1,&local_5c);
  if ((int)uVar5 == 0) {
    FUN_fffffff009c2c18c(plVar2,param_3);
    *(undefined4 *)(param_3 + 0x68) = local_5c;
  }
  if (!bVar6) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  (**(code **)(*plVar2 + 0x28))(plVar2);
LAB_fffffff009c3b550:
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_58) {
    uVar5 = thunk_EXT_FUN_8011000003a48590();
    return uVar5;
  }
  return uVar5;
}

