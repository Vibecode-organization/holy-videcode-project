// FUN_fffffff0081d9b14 @ fffffff0081d9b14 size=72

void FUN_fffffff0081d9b14(long param_1,undefined8 param_2)

{
  long *plVar1;
  undefined8 *puVar2;
  
  if ((DAT_fffffff00ae25928 & 1) != 0) {
    plVar1 = *(long **)(*(long *)(param_1 + 0x2d0) + 0x10);
    puVar2 = (undefined8 *)(*plVar1 + 0x90);
                    /* WARNING: Could not recover jumptable at 0xfffffff0081d9b50. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*puVar2)(plVar1,param_2,puVar2);
    return;
  }
  FUN_fffffff0082103e8(*(undefined8 *)(*(long *)(param_1 + 0x2d0) + 0x18));
  return;
}

