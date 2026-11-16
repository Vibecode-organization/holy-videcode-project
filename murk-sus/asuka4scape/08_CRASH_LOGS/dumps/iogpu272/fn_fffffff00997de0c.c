// FUN_fffffff00997de0c @ fffffff00997de0c size=80

long FUN_fffffff00997de0c(long param_1)

{
  if (*(long **)(param_1 + 8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 8) + 0x28))();
  }
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

