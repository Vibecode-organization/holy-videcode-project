// FUN_fffffff009c11e90 @ fffffff009c11e90

undefined8 FUN_fffffff009c11e90(long param_1)

{
  *(undefined8 *)(param_1 + 0xc0) = 0;
  if (*(long **)(param_1 + 0xa0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xa0) + 0x28))();
    *(undefined8 *)(param_1 + 0xa0) = 0;
  }
  if (*(long **)(param_1 + 0x98) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x98) + 0x28))();
    *(undefined8 *)(param_1 + 0x98) = 0;
  }
  *(undefined8 *)(param_1 + 0xb8) = 0;
  if (*(long **)(param_1 + 0xb0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xb0) + 0x28))();
    *(undefined8 *)(param_1 + 0xb0) = 0;
  }
  if (*(long **)(param_1 + 0xa8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xa8) + 0x28))();
    *(undefined8 *)(param_1 + 0xa8) = 0;
  }
  return 0;
}

