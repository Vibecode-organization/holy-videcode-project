// FUN_fffffff009c2d964 @ fffffff009c2d964 size=56

void FUN_fffffff009c2d964(long param_1)

{
  if (((*(long *)(param_1 + 0x18) != 0) && (*(code **)(param_1 + 0x28) != (code *)0x0)) &&
     (*(long *)(param_1 + 0x20) != 0)) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c2d994. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1 + 0x28))(*(long *)(param_1 + 0x18),param_1,0,0,0);
    return;
  }
  return;
}

