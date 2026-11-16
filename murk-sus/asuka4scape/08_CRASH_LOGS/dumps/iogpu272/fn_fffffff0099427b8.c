// FUN_fffffff0099427b8 @ fffffff0099427b8 size=76

long * FUN_fffffff0099427b8(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0xb8);
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x20))(plVar1);
  }
  return plVar1;
}

