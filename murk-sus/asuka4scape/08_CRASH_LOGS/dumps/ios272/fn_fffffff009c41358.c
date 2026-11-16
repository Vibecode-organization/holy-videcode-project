// FUN_fffffff009c41358 @ fffffff009c41358 size=68

undefined8 FUN_fffffff009c41358(long param_1,undefined4 param_2)

{
  if (*(long *)(param_1 + 0x10) != 0) {
    *(undefined4 *)(param_1 + 0x48) = param_2;
    FUN_fffffff009c269f0(*(long *)(param_1 + 0x10),param_1);
    return 0;
  }
  return 0xe00002bc;
}

