// FUN_fffffff008211d04 @ fffffff008211d04 size=152

undefined8 FUN_fffffff008211d04(long *param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)thunk_EXT_FUN_80110000038ce200(param_3);
  uVar2 = 0;
  if (plVar1 != (long *)0x0) {
    uVar2 = (**(code **)(*param_1 + 0x100))(param_1,param_2,plVar1);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

