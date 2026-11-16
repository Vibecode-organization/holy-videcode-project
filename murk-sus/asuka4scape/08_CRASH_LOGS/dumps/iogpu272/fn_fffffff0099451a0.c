// FUN_fffffff0099451a0 @ fffffff0099451a0 size=116

bool FUN_fffffff0099451a0(long param_1,undefined8 param_2)

{
  long *plVar1;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x20));
  plVar1 = (long *)FUN_fffffff00994508c(param_1,param_2);
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x20));
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return plVar1 != (long *)0x0;
}

