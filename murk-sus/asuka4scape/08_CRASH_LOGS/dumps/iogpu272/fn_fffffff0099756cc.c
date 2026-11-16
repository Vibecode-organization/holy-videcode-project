// FUN_fffffff0099756cc @ fffffff0099756cc size=68

void FUN_fffffff0099756cc(long param_1,undefined8 param_2)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x108);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009975708. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x90))
              (plVar1,*(undefined8 *)(param_1 + 0x138),param_2,(undefined8 *)(*plVar1 + 0x90));
    return;
  }
  return;
}

