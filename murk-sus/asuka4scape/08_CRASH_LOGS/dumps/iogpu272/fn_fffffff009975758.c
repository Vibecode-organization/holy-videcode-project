// FUN_fffffff009975758 @ fffffff009975758 size=76

void FUN_fffffff009975758(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x108);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00997579c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0xa8))
              (plVar1,*(undefined8 *)(param_1 + 0x138),param_2,param_3,param_4,
               (undefined8 *)(*plVar1 + 0xa8));
    return;
  }
  return;
}

