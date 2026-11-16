// FUN_fffffff009c40508 @ fffffff009c40508 size=128

undefined8
FUN_fffffff009c40508
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009c3f1d0();
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    FUN_fffffff009c2a5a4(plVar1,param_3,param_4,param_5);
    (**(code **)(*plVar1 + 0x28))(plVar1);
    uVar2 = 0;
  }
  return uVar2;
}

