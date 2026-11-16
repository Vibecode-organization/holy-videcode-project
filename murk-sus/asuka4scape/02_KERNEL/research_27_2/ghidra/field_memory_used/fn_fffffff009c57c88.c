// FUN_fffffff009c57c88 @ fffffff009c57c88

undefined8
FUN_fffffff009c57c88
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long *param_7,long param_8,undefined8 param_9,
          undefined8 param_10,undefined8 param_11)

{
  undefined8 uVar1;
  
  if (param_8 == 0) {
    uVar1 = 0xe00002c2;
    FUN_fffffff009c7a414(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else if (param_7[0x17] == 0) {
    FUN_fffffff009c7a3dc(param_1,param_2,param_3,param_4,param_5,param_6);
    uVar1 = 0xe00002c9;
  }
  else {
    thunk_FUN_fffffff00a2262a8(param_7[0x17]);
    if ((param_7[0x16] == 0) || (param_7[0x16] == param_8)) {
      uVar1 = (**(code **)(*param_7 + 0x558))(param_7,param_9,param_10,param_11);
    }
    else {
      uVar1 = 0xe00002c5;
    }
    thunk_FUN_fffffff00a226de0(param_7[0x17]);
  }
  return uVar1;
}

