// FUN_fffffff009c2dba4 @ fffffff009c2dba4 size=60

void FUN_fffffff009c2dba4(long param_1,undefined4 param_2)

{
  if (((*(long *)(param_1 + 0x18) != 0) && (*(code **)(param_1 + 0x28) != (code *)0x0)) &&
     (*(long *)(param_1 + 0x20) != 0)) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c2dbd8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1 + 0x28))(*(long *)(param_1 + 0x18),param_1,7,param_2,0);
    return;
  }
  return;
}

