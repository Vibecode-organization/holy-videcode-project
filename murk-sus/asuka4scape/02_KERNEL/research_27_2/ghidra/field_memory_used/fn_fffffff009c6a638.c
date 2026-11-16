// FUN_fffffff009c6a638 @ fffffff009c6a638

undefined8
FUN_fffffff009c6a638
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7,undefined8 param_8)

{
  long lVar1;
  ulong uVar2;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  
  *(undefined **)(param_7 + 0x88) = &DAT_fffffff0078a321e;
  *(undefined8 *)(param_7 + 0x90) = 0;
  *(undefined1 *)(param_7 + 0x1b0) = 0;
  *(undefined8 *)(param_7 + 0xa0) = 0;
  lVar1 = thunk_FUN_fffffff00a903010();
  *(long *)(param_7 + 0x1a8) = lVar1;
  if (lVar1 == 0) {
    FUN_fffffff009c7c584(extraout_q0,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    uVar2 = (**(code **)(PTR_DAT_fffffff00807b628 + 0xb8))(param_7,param_8);
    if ((uVar2 & 1) != 0) {
      return 1;
    }
    FUN_fffffff009c7c51c(extraout_q0_00,param_2,param_3,param_4,param_5,param_6);
  }
  return 0;
}

