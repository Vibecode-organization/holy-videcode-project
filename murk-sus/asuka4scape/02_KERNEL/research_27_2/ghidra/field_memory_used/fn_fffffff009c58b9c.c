// FUN_fffffff009c58b9c @ fffffff009c58b9c

undefined8 FUN_fffffff009c58b9c(long param_1,long *param_2)

{
  thunk_FUN_fffffff00a2262a8(*(ulong *)(param_1 + 0xb8));
  if (*(long **)(param_1 + 0xb0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xb0) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xb0) = 0;
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x20))(param_2);
    *(long **)(param_1 + 0xb0) = param_2;
  }
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0xb8));
  return 0;
}

