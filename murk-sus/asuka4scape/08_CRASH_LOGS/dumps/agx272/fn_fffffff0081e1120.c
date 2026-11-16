// FUN_fffffff0081e1120 @ fffffff0081e1120 size=88

void FUN_fffffff0081e1120(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined8 *puVar2;
  
  plVar1 = *(long **)(*(long *)(param_1 + 0x10) + 0x310);
  puVar2 = (undefined8 *)(*plVar1 + 0xe8);
                    /* WARNING: Could not recover jumptable at 0xfffffff0081e1174. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar2)(plVar1,FUN_fffffff00817e15c,param_1,param_3,param_2,0,puVar2);
  return;
}

