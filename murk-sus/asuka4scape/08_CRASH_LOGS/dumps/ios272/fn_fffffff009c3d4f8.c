// FUN_fffffff009c3d4f8 @ fffffff009c3d4f8 size=104

undefined8 FUN_fffffff009c3d4f8(undefined8 param_1,undefined8 param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  long *plVar2;
  undefined8 uVar3;
  
  plVar2 = (long *)FUN_fffffff009c3f1d0();
  if (plVar2 == (long *)0x0) {
    uVar3 = 0xe00002c2;
  }
  else {
    uVar1 = FUN_fffffff009c2a750();
    *param_3 = uVar1;
    (**(code **)(*plVar2 + 0x28))(plVar2);
    uVar3 = 0;
  }
  return uVar3;
}

