// FUN_fffffff009c3578c @ fffffff009c3578c size=196

undefined8 FUN_fffffff009c3578c(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  long *plVar2;
  
  plVar1 = (long *)thunk_EXT_FUN_8011000003890f30(param_3,DAT_fffffff008067ad8);
  if ((plVar1 != (long *)0x0) &&
     (plVar2 = (long *)thunk_EXT_FUN_801100000389d0d8(1), plVar2 != (long *)0x0)) {
    (**(code **)(*plVar1 + 0x98))(plVar1,plVar2);
    (**(code **)(**(long **)(param_1 + 0x20) + 0xe8))(*(long **)(param_1 + 0x20),plVar2);
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return 0;
}

