// FUN_fffffff009c3a128 @ fffffff009c3a128 size=4

void FUN_fffffff009c3a128(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  long lStack_28;
  
  lStack_28 = *(long *)PTR_DAT_fffffff00806ca40;
  puVar1 = *(undefined4 **)(param_3 + 0x20);
  uStack_38 = 0;
  uStack_30 = 0;
  uStack_40 = 0;
  FUN_fffffff009c40a4c
            (param_1,*puVar1,*(undefined8 *)(puVar1 + 2),*(undefined8 *)(puVar1 + 4),puVar1[6],
             *(long *)(puVar1 + 8) != 0,&uStack_30,&uStack_38,&uStack_40);
  puVar2 = *(undefined8 **)(param_3 + 0x48);
  *puVar2 = uStack_30;
  puVar2[1] = uStack_38;
  puVar2[2] = uStack_40;
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

