// FUN_fffffff009c31368 @ fffffff009c31368 size=252

undefined8 FUN_fffffff009c31368(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff00806ca38 + 0xb8))();
  uVar2 = thunk_EXT_FUN_8011000003397c88();
  *(undefined8 *)(param_1 + 0x438) = uVar2;
  DAT_fffffff00af48598 = 0x100000000000000;
  DAT_fffffff00af483b0 = param_1;
  uVar2 = thunk_EXT_FUN_80110000038961f4(4);
  if (*(long **)(param_1 + 0x220) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x220) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x220) = uVar2;
  uVar2 = thunk_EXT_FUN_80110000038ff010();
  *(undefined8 *)(param_1 + 0x228) = uVar2;
  uVar2 = thunk_EXT_FUN_80110000038ff010();
  *(undefined8 *)(param_1 + 0x150) = uVar2;
  uVar2 = thunk_EXT_FUN_80110000038ff010();
  *(undefined8 *)(param_1 + 0x230) = uVar2;
  uVar2 = thunk_EXT_FUN_80110000038ff010();
  *(undefined8 *)(param_1 + 1000) = uVar2;
  thunk_EXT_FUN_8011000003740c44(&DAT_fffffff00af48060);
  thunk_EXT_FUN_8011000003740c44(&DAT_fffffff00af480b0);
  uVar2 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff00806c060,0x200);
  *(undefined8 *)(param_1 + 0x428) = uVar2;
  *(undefined8 *)(param_1 + 0x420) = 0x20;
  uVar2 = thunk_EXT_FUN_8011000003397c88();
  *(undefined8 *)(param_1 + 0x440) = uVar2;
  return uVar1;
}

