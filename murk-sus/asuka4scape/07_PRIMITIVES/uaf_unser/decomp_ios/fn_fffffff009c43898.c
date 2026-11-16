// FUN_fffffff009c43898 @ fffffff009c43898 size=388
// CALLERS:
//   fffffff009c3e498 FUN_fffffff009c3e388@fffffff009c3e388

/* WARNING: Removing unreachable block (ram,0xfffffff009c43980) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * FUN_fffffff009c43898(long *param_1,long *param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  
  if (param_1[8] == 0) {
    FUN_fffffff009c495f4(0xfffffff00789d62f);
  }
  else {
    lVar1 = param_1[8];
    param_1[8] = lVar1 + 1;
    plVar3 = (long *)(**(code **)(_DAT_fffffff00af484a8 + 0x68))();
    if (plVar3 == (long *)0x0) goto LAB_fffffff009c439dc;
    if (param_2 != (long *)0x0) {
      (**(code **)(*param_2 + 0x20))(param_2);
    }
    (**(code **)(*param_1 + 0x20))(param_1);
    iVar2 = FUN_fffffff009c43a1c(plVar3,lVar1,param_2,param_3,param_1);
    if (iVar2 != 0) {
      (**(code **)(*plVar3 + 0x20))(plVar3);
      FUN_fffffff009c43ecc(param_1,plVar3);
      goto LAB_fffffff009c439dc;
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  plVar3 = (long *)0x0;
LAB_fffffff009c439dc:
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  return plVar3;
}

