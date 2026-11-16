// FUN_fffffff00995c1b0 @ fffffff00995c1b0 size=4

undefined8 FUN_fffffff00995c1b0(long param_1,long param_2,long param_3,long param_4)

{
  undefined8 uVar1;
  
  uVar1 = (*DAT_fffffff007feb260)();
  if ((int)uVar1 != 0) {
    *(long *)(param_1 + 0x10) = param_2;
    *(long *)(param_1 + 0x18) = param_3;
    *(long *)(param_1 + 0x20) = param_4;
    if (param_3 != 1) {
      uVar1 = thunk_EXT_FUN_8011000003a49114
                        (
                        "\"IOGPUDeviceAssertion::initWithAccelerator Unsupported assertionType %lld\" @%s:%d"
                        );
      return uVar1;
    }
    if (param_4 == 0) {
      FUN_fffffff009961c6c(*(undefined8 *)(param_2 + 0x160));
      return 1;
    }
    uVar1 = 0;
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  return uVar1;
}

