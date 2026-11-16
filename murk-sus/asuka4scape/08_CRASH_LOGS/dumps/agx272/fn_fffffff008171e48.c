// FUN_fffffff008171e48 @ fffffff008171e48 size=124

undefined8 FUN_fffffff008171e48(long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  long *plVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x10954) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008171ec0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(PTR_DAT_fffffff007ca6170 + 0x5f0))();
    return uVar2;
  }
  if ((param_2 != 0) && (plVar1 = *(long **)(param_2 + 0x58), plVar1 != (long *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008171e9c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*plVar1 + 0x178))
                      (plVar1,param_3,param_4,param_4,(undefined8 *)(*plVar1 + 0x178));
    return uVar2;
  }
  return 0;
}

