// FUN_fffffff009c3d268 @ fffffff009c3d268 size=104

undefined8 FUN_fffffff009c3d268(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009c3f1d0();
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    FUN_fffffff009c2631c(plVar1,param_3);
    (**(code **)(*plVar1 + 0x28))(plVar1);
    uVar2 = 0;
  }
  return uVar2;
}

