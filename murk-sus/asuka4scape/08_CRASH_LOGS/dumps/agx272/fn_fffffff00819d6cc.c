// FUN_fffffff00819d6cc @ fffffff00819d6cc size=100

undefined * FUN_fffffff00819d6cc(undefined8 param_1,undefined8 *param_2,int param_3)

{
  undefined *puVar1;
  long lVar2;
  
  *param_2 = param_1;
  if (param_3 - 0x100U < 0x13) {
    lVar2 = (ulong)(param_3 - 0x100U) * 0x30;
    puVar1 = &UNK_fffffff007c94858 + (int)lVar2;
    if (lVar2 - (int)lVar2 != 0) {
      puVar1 = (undefined *)
               ((ulong)(&UNK_fffffff007c94858 + lVar2) & 0xffffffffffff | 0x2bad000000000000);
    }
    if (*(long *)(puVar1 + 8) != 0) {
      return puVar1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00819d72c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  puVar1 = (undefined *)(**(code **)(PTR_DAT_fffffff007ca6150 + 0x5c0))();
  return puVar1;
}

