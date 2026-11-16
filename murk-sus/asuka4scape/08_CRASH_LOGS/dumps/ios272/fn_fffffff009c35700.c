// FUN_fffffff009c35700 @ fffffff009c35700 size=64

void FUN_fffffff009c35700(long param_1,long param_2)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_2 + 0x20);
  *(long **)(param_1 + 0x20) = plVar1;
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c35738. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x20))(plVar1,(undefined8 *)(*plVar1 + 0x20));
    return;
  }
  return;
}

