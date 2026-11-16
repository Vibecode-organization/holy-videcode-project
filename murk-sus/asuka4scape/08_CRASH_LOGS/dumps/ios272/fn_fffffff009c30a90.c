// FUN_fffffff009c30a90 @ fffffff009c30a90 size=80

void FUN_fffffff009c30a90(long param_1,long *param_2)

{
  if (*(long *)(param_1 + 0x20) != 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c30ad8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_2 + 0x100))
              (param_2,"Name",*(long *)(param_1 + 0x20),(undefined8 *)(*param_2 + 0x100));
    return;
  }
  return;
}

