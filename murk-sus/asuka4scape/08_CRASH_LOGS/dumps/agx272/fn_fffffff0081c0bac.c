// FUN_fffffff0081c0bac @ fffffff0081c0bac size=40

undefined8 FUN_fffffff0081c0bac(long param_1,undefined4 param_2)

{
  if (*(long *)(param_1 + 0x348) != 0) {
    *(undefined4 *)(*(long *)(param_1 + 0x348) + 0x7f0) = param_2;
    DataMemoryBarrier(2,3);
    return 0;
  }
  return 0xe00002d8;
}

