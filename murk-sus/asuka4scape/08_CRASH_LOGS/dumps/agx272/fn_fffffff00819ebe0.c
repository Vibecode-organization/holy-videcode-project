// FUN_fffffff00819ebe0 @ fffffff00819ebe0 size=76

undefined8 FUN_fffffff00819ebe0(long param_1,long param_2,int param_3)

{
  undefined8 uVar1;
  
  if (param_3 != 1) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00819ec1c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(PTR_DAT_fffffff007ca6150 + 0x558))();
    return uVar1;
  }
  if (param_2 != 0) {
    *(long *)(*(long *)(param_1 + 0x120) + 0x1d8) = param_2;
    return 0;
  }
  return 0xe00002bf;
}

