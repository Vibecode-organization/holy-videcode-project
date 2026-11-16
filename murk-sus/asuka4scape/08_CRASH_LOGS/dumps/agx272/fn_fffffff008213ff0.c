// FUN_fffffff008213ff0 @ fffffff008213ff0 size=88

void FUN_fffffff008213ff0(long param_1)

{
  long *plVar1;
  undefined8 *puVar2;
  
  plVar1 = *(long **)(*(long *)(param_1 + 0x1a8) + 0x310);
  puVar2 = (undefined8 *)(*plVar1 + 0xe8);
                    /* WARNING: Could not recover jumptable at 0xfffffff008214044. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar2)(plVar1,FUN_fffffff00817ed4c,0,0,0,0,puVar2);
  return;
}

