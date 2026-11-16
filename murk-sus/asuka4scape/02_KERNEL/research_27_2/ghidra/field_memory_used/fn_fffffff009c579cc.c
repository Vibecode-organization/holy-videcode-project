// FUN_fffffff009c579cc @ fffffff009c579cc

undefined8
FUN_fffffff009c579cc
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7,long param_8)

{
  undefined8 uVar1;
  
  if (param_8 == 0) {
    uVar1 = 0xe00002c2;
    FUN_fffffff009c7a254(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else if (*(ulong *)(param_7 + 0xb8) == 0) {
    FUN_fffffff009c7a21c(param_1,param_2,param_3,param_4,param_5,param_6);
    uVar1 = 0xe00002c9;
  }
  else {
    thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0xb8));
    if ((*(long *)(param_7 + 0xb0) == 0) || (*(long *)(param_7 + 0xb0) == param_8)) {
      uVar1 = 0;
      *(long *)(param_7 + 0xb0) = param_8;
    }
    else {
      uVar1 = 0xe00002c5;
    }
    thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0xb8));
  }
  return uVar1;
}

