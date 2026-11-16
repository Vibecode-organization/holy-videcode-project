// FUN_fffffff009c3a12c @ fffffff009c3a12c size=160

void FUN_fffffff009c3a12c(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  puVar1 = *(undefined4 **)(param_3 + 0x20);
  local_38 = 0;
  uStack_30 = 0;
  local_40 = 0;
  FUN_fffffff009c40a4c
            (param_1,*puVar1,*(undefined8 *)(puVar1 + 2),*(undefined8 *)(puVar1 + 4),puVar1[6],
             *(long *)(puVar1 + 8) != 0,&uStack_30,&local_38,&local_40);
  puVar2 = *(undefined8 **)(param_3 + 0x48);
  *puVar2 = uStack_30;
  puVar2[1] = local_38;
  puVar2[2] = local_40;
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

