// FUN_fffffff00997e874 @ fffffff00997e874 size=96

undefined8 FUN_fffffff00997e874(undefined8 param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (2 < param_2) {
    return 0xe00002c2;
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00997e8d0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(PTR_DAT_fffffff007ff27d0 + 0x550))();
  return uVar1;
}

