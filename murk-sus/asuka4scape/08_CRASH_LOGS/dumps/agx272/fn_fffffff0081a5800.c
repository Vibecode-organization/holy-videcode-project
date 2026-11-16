// FUN_fffffff0081a5800 @ fffffff0081a5800 size=60

void FUN_fffffff0081a5800(long param_1,int param_2)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  
  uVar1 = 0;
  if (param_2 == 0) {
    uVar1 = 3;
  }
  puVar2 = (undefined8 *)(**(long **)(param_1 + 0x210) + 0x18);
                    /* WARNING: Could not recover jumptable at 0xfffffff0081a5838. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar2)(*(long **)(param_1 + 0x210),uVar1,puVar2);
  return;
}

