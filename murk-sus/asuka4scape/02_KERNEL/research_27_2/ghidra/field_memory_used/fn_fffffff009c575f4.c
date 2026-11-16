// FUN_fffffff009c575f4 @ fffffff009c575f4

undefined8
FUN_fffffff009c575f4
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long *param_7,undefined8 param_8,undefined4 param_9,
          undefined4 param_10,undefined8 param_11)

{
  long lVar1;
  ulong uVar2;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  
  param_7[0x11] = (long)&DAT_fffffff0078a321e;
  param_7[0x12] = 0;
  *(char *)(param_7 + 0x13) = (char)param_8;
  *(undefined4 *)((long)param_7 + 0x9c) = param_9;
  *(undefined4 *)(param_7 + 0x14) = param_10;
  lVar1 = thunk_FUN_fffffff00a903010();
  param_7[0x17] = lVar1;
  if (lVar1 == 0) {
    FUN_fffffff009c7a1e4(extraout_q0,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    uVar2 = (**(code **)(PTR_DAT_fffffff00807b628 + 0xb8))(param_7,param_11);
    if ((uVar2 & 1) != 0) {
      (**(code **)(*param_7 + 0xd8))(param_7,"SupportsRepeating",param_8);
      (**(code **)(*param_7 + 0xe0))(param_7,"MinimumPulseActiveTime",param_9,0x20);
      (**(code **)(*param_7 + 0xe0))(param_7,"MaximumPulseActiveTime",param_10,0x20);
      return 1;
    }
    FUN_fffffff009c7a17c(extraout_q0_00,param_2,param_3,param_4,param_5,param_6);
  }
  return 0;
}

