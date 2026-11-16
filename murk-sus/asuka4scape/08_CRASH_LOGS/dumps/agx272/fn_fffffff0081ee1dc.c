// FUN_fffffff0081ee1dc @ fffffff0081ee1dc size=56

void FUN_fffffff0081ee1dc(long param_1,undefined8 param_2)

{
  long *plVar1;
  undefined8 *puVar2;
  
  plVar1 = *(long **)(*(long *)(param_1 + 0x18) + 0x18);
  puVar2 = (undefined8 *)(*plVar1 + 0xa8);
                    /* WARNING: Could not recover jumptable at 0xfffffff0081ee210. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar2)(plVar1,param_2,0,puVar2);
  return;
}

