// FUN_fffffff00994d990 @ fffffff00994d990 size=64

void FUN_fffffff00994d990(long param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  long *plVar3;
  
  if (param_2 == 1) {
    piVar1 = (int *)(param_1 + 0xc);
    iVar2 = *piVar1;
    *piVar1 = iVar2 + -1;
    LORelease();
    if (iVar2 == 1) {
      FUN_fffffff0099836b0(piVar1,param_1);
    }
    return;
  }
  plVar3 = (long *)FUN_fffffff0099836e4();
                    /* WARNING: Could not recover jumptable at 0xfffffff00994d9f8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar3 + 0x20))(plVar3,(undefined8 *)(*plVar3 + 0x20));
  return;
}

