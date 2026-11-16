// FUN_fffffff008211d9c @ fffffff008211d9c size=156

undefined8 FUN_fffffff008211d9c(long *param_1,undefined8 param_2,undefined4 param_3)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)thunk_EXT_FUN_80110000038c6e24(param_3,0x20);
  uVar2 = 0;
  if (plVar1 != (long *)0x0) {
    uVar2 = (**(code **)(*param_1 + 0x100))(param_1,param_2,plVar1);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

