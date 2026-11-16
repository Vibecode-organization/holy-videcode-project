// FUN_fffffff0081c0bd4 @ fffffff0081c0bd4 size=36

undefined8 FUN_fffffff0081c0bd4(long param_1,undefined4 param_2)

{
  if (*(long *)(param_1 + 0x348) != 0) {
    *(undefined4 *)(*(long *)(param_1 + 0x348) + 0x7ec) = param_2;
    return 0;
  }
  return 0xe00002d8;
}

