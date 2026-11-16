// FUN_fffffff009c3d2d0 @ fffffff009c3d2d0 size=104

undefined8 FUN_fffffff009c3d2d0(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  long *plVar2;
  undefined8 uVar3;
  
  plVar2 = (long *)FUN_fffffff009c3f1d0();
  if (plVar2 == (long *)0x0) {
    uVar3 = 0xe00002c2;
  }
  else {
    uVar1 = FUN_fffffff009c233a0();
    *param_3 = uVar1;
    (**(code **)(*plVar2 + 0x28))(plVar2);
    uVar3 = 0;
  }
  return uVar3;
}

