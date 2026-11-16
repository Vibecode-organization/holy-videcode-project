// FUN_fffffff009c3d48c @ fffffff009c3d48c size=108

undefined8 FUN_fffffff009c3d48c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009c3f1d0();
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = FUN_fffffff009c247d0(plVar1,param_3);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

