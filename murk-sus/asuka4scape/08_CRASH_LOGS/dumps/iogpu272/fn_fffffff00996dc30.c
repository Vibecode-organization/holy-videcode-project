// FUN_fffffff00996dc30 @ fffffff00996dc30 size=52

void FUN_fffffff00996dc30(long param_1,long *param_2)

{
  *(long **)(param_1 + 0x68) = param_2;
                    /* WARNING: Could not recover jumptable at 0xfffffff00996dc60. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x20))(param_2,param_2,(undefined8 *)(*param_2 + 0x20));
  return;
}

