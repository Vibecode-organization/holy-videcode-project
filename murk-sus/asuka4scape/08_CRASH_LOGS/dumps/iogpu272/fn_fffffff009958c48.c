// FUN_fffffff009958c48 @ fffffff009958c48 size=80

void FUN_fffffff009958c48(long param_1)

{
  *(undefined4 *)(param_1 + 0x28) = 0;
  if (*(long **)(param_1 + 0x10) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x10) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x10) = 0;
  return;
}

