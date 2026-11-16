// FUN_fffffff009961bfc @ fffffff009961bfc size=60

void FUN_fffffff009961bfc(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(**(long **)(param_1 + 0x20) + 0xf8);
                    /* WARNING: Could not recover jumptable at 0xfffffff009961c34. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(*(long **)(param_1 + 0x20),0,0,0,puVar1);
  return;
}

