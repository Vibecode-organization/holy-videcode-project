// FUN_fffffff00996ccc4 @ fffffff00996ccc4 size=172

undefined8 FUN_fffffff00996ccc4(long *param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = thunk_EXT_FUN_80110000038ccc44(4);
  param_1[4] = lVar1;
  uVar2 = 0;
  if (lVar1 != 0) {
    lVar1 = thunk_EXT_FUN_80110000039b54c0(param_1[2],0x8000,0);
    param_1[5] = lVar1;
    uVar2 = 0;
    if (lVar1 != 0) {
      (**(code **)(*(long *)param_1[4] + 0xf0))((long *)param_1[4],lVar1);
      (**(code **)(*param_1 + 0x90))(param_1);
      thunk_EXT_FUN_80110000039ba158(param_1[2],param_1[5],"Internal Statistics",0);
      uVar2 = 1;
    }
  }
  return uVar2;
}

