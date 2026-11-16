// FUN_fffffff0081e498c @ fffffff0081e498c size=84

void FUN_fffffff0081e498c
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  undefined8 *puVar1;
  long *plVar2;
  
  plVar2 = *(long **)(*(long *)(*(long *)(param_1 + 0x18) + 0x10) + 0x4b0);
  puVar1 = (undefined8 *)(*plVar2 + 0x220);
                    /* WARNING: Could not recover jumptable at 0xfffffff0081e49dc. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar1)(plVar2,param_3,param_5,*(byte *)(param_1 + 0x58) >> 3 & 1,param_5,puVar1);
  return;
}

