// FUN_fffffff009975710 @ fffffff009975710 size=72

void FUN_fffffff009975710(long param_1,undefined8 param_2)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x108);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009975750. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0xa0))
              (plVar1,*(undefined8 *)(param_1 + 0x138),param_2,0,(undefined8 *)(*plVar1 + 0xa0));
    return;
  }
  return;
}

