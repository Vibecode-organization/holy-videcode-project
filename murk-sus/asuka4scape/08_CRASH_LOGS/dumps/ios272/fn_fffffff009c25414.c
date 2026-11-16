// FUN_fffffff009c25414 @ fffffff009c25414 size=4

undefined8 FUN_fffffff009c25414(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined8 uVar2;
  undefined *puStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined *puStack_78;
  undefined8 uStack_70;
  undefined8 *puStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 *puStack_50;
  undefined8 uStack_48;
  undefined1 uStack_40;
  long lStack_38;
  
  lStack_38 = *(long *)PTR_DAT_fffffff00806ca40;
  puStack_68 = &uStack_58;
  uStack_58 = 0;
  uStack_48 = DAT_fffffff0078a1288;
  uStack_40 = 0;
  puStack_90 = PTR_DAT_fffffff00806c9b8;
  uStack_88 = DAT_fffffff0078a1290;
  pcStack_80 = FUN_fffffff009c2554c;
  uStack_70 = *(undefined8 *)(param_1 + 0x20);
  puStack_78 = &DAT_fffffff008067298;
  uStack_60 = param_2;
  puStack_50 = puStack_68;
  thunk_EXT_FUN_801100000389794c(*(undefined8 *)(param_1 + 0x30),&puStack_90);
  if ((*(byte *)(puStack_50 + 3) & 1) == 0) {
    plVar1 = *(long **)(*(long *)(*(long *)(param_1 + 0x28) + 8) + 0x28);
    (**(code **)(*plVar1 + 0xf0))(plVar1,param_2,param_3);
  }
  thunk_EXT_FUN_80110000038e9dac(&uStack_58,8);
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_38) {
    return 0;
  }
  uVar2 = thunk_EXT_FUN_8011000003a48590();
  return uVar2;
}

