// FUN_fffffff009c3caa8 @ fffffff009c3caa8 size=136

undefined8
FUN_fffffff009c3caa8(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009c3f1d0();
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    FUN_fffffff009c2af10(plVar1,0);
    uVar2 = FUN_fffffff009c21128(plVar1,param_3,param_4);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

