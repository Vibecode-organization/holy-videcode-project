// FUN_fffffff009c40588 @ fffffff009c40588 size=132

undefined8
FUN_fffffff009c40588
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
    uVar2 = FUN_fffffff009c2a76c(plVar1,param_3,param_4,param_5);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

