// FUN_fffffff0099529c0 @ fffffff0099529c0 size=80

undefined8 FUN_fffffff0099529c0(long param_1)

{
  long *plVar1;
  undefined8 uVar2;
  
  if (((*(char *)(param_1 + 0x10) != -0x7e) || (param_1 = *(long *)(param_1 + 0x30), param_1 != 0))
     && (plVar1 = *(long **)(param_1 + 0x28), plVar1 != (long *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009952a04. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*plVar1 + 0xe0))(plVar1,(undefined8 *)(*plVar1 + 0xe0));
    return uVar2;
  }
  return 0;
}

