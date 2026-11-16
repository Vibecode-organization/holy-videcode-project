// FUN_fffffff009c3d7c8 @ fffffff009c3d7c8 size=112

undefined8 FUN_fffffff009c3d7c8(undefined8 param_1,long param_2)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009c3f1d0(param_1,*(undefined4 *)(param_2 + 0x98));
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    FUN_fffffff009c25e38(plVar1,param_2,*(undefined8 *)(param_2 + 0x90));
    (**(code **)(*plVar1 + 0x28))(plVar1);
    uVar2 = 0;
  }
  return uVar2;
}

