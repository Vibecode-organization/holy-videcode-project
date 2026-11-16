// FUN_fffffff009946900 @ fffffff009946900 size=8

void FUN_fffffff009946900(long param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  long *plVar3;
  
  if (param_2 == 1) {
    piVar1 = (int *)(param_1 + 0x70);
    iVar2 = *piVar1;
    *piVar1 = iVar2 + -1;
    LORelease();
    if (iVar2 == 1) {
      FUN_fffffff0099835cc(piVar1,param_1);
    }
    return;
  }
  plVar3 = (long *)FUN_fffffff009983608();
                    /* WARNING: Could not recover jumptable at 0xfffffff009946970. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar3 + 0x20))(plVar3,(undefined8 *)(*plVar3 + 0x20));
  return;
}

