// FUN_fffffff009972f0c @ fffffff009972f0c size=68

undefined8 FUN_fffffff009972f0c(long param_1,undefined8 param_2,int param_3)

{
  if ((*(byte *)(param_1 + 0x1e0) >> 6 & 1) == 0) {
    return 0xe00002bc;
  }
  if ((param_3 != -0x1ffffcf0) && (param_3 != -0x1ffffdb0)) {
    return 0;
  }
  FUN_fffffff009961b14(*(undefined8 *)(param_1 + 0x160),0);
  return 0;
}

