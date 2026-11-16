// FUN_fffffff0081d1aa0 @ fffffff0081d1aa0 size=84

undefined1  [16] FUN_fffffff0081d1aa0(long param_1)

{
  undefined8 *puVar1;
  undefined4 extraout_s0;
  undefined4 extraout_var;
  undefined8 extraout_var_00;
  undefined1 auVar2 [16];
  
  if (*(ulong *)(param_1 + 0x1c18) != 0) {
    return ZEXT416((uint)((float)*(ulong *)(param_1 + 0x1c18) / 1000.0));
  }
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x280) + 0xac8);
                    /* WARNING: Could not recover jumptable at 0xfffffff0081d1af0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x280),puVar1);
  auVar2._4_4_ = extraout_var;
  auVar2._0_4_ = extraout_s0;
  auVar2._8_8_ = extraout_var_00;
  return auVar2;
}

