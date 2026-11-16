// FUN_fffffff00997690c @ fffffff00997690c size=108

void FUN_fffffff00997690c(long param_1)

{
  long *plVar1;
  
  FUN_fffffff009976978();
  FUN_fffffff009950fc0(*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x158),param_1);
  plVar1 = *(long **)(param_1 + 0x430);
  if ((long *)*plVar1 != (long *)0x0) {
    (**(code **)(*(long *)*plVar1 + 0x28))();
    plVar1 = *(long **)(param_1 + 0x430);
  }
  *plVar1 = 0;
  *(undefined8 *)(param_1 + 0x488) = 0;
  return;
}

