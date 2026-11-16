// FUN_fffffff008212da8 @ fffffff008212da8 size=128

void FUN_fffffff008212da8(long param_1)

{
  if (*(long **)(param_1 + 0x218) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x218) + 0x118))();
  }
  (**(code **)(**(long **)(param_1 + 0x220) + 0x118))();
  *(undefined8 *)(param_1 + 0xd8) = 0;
  *(undefined8 **)(param_1 + 0xe0) = (undefined8 *)(param_1 + 0xd8);
  return;
}

