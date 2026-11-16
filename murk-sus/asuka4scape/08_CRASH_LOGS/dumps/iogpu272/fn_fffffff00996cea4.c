// FUN_fffffff00996cea4 @ fffffff00996cea4 size=172

undefined8
FUN_fffffff00996cea4
          (long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5
          )

{
  undefined8 uVar1;
  
  thunk_EXT_FUN_80110000038ff214(param_1[3]);
  uVar1 = (**(code **)(*param_1 + 0xa0))(param_1,param_2,param_3,param_4,param_5);
  if ((int)uVar1 == 0) {
    uVar1 = thunk_EXT_FUN_80110000039b3e28(param_1[4],param_2,param_3,param_4,param_5);
  }
  thunk_EXT_FUN_80110000038ff2e0(param_1[3]);
  return uVar1;
}

