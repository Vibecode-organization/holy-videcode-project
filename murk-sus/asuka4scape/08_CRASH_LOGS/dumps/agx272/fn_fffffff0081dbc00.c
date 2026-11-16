// FUN_fffffff0081dbc00 @ fffffff0081dbc00 size=56

void FUN_fffffff0081dbc00(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x10) + 0xcb0);
                    /* WARNING: Could not recover jumptable at 0xfffffff0081dbc34. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x10),puVar1);
  return;
}

