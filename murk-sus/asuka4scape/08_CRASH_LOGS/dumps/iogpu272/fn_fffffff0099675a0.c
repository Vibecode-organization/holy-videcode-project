// FUN_fffffff0099675a0 @ fffffff0099675a0 size=124

undefined8 FUN_fffffff0099675a0(long param_1,undefined8 param_2)

{
  long *plVar1;
  
  plVar1 = (long *)FUN_fffffff00997a2b4(param_2);
  if (plVar1 != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x20) + 0xe8))(*(long **)(param_1 + 0x20),plVar1);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return 0;
}

