// FUN_fffffff0081ee1a8 @ fffffff0081ee1a8 size=52

void FUN_fffffff0081ee1a8(long param_1)

{
  long *plVar1;
  undefined8 *puVar2;
  
  plVar1 = *(long **)(*(long *)(param_1 + 0x18) + 0x18);
  puVar2 = (undefined8 *)(*plVar1 + 0x88);
                    /* WARNING: Could not recover jumptable at 0xfffffff0081ee1d8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar2)(plVar1,puVar2);
  return;
}

