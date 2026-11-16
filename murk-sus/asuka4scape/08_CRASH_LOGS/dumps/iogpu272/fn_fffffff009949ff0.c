// FUN_fffffff009949ff0 @ fffffff009949ff0 size=176

void FUN_fffffff009949ff0(long *param_1)

{
  (**(code **)(*param_1 + 0x100))(param_1,"AppUsage");
  if (param_1[0x24] != 0) {
    FUN_fffffff009965338();
  }
  if ((long *)param_1[0x22] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x22] + 0x28))();
  }
  param_1[0x22] = 0;
  if ((long *)param_1[0x21] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x21] + 0x28))();
  }
  param_1[0x21] = 0;
  *(undefined1 *)(param_1 + 0x20) = 0;
  return;
}

