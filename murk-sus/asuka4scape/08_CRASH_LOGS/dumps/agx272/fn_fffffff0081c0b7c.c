// FUN_fffffff0081c0b7c @ fffffff0081c0b7c size=48

undefined8 FUN_fffffff0081c0b7c(long param_1,undefined4 param_2)

{
  if (*(long *)(param_1 + 0x348) != 0) {
    *(undefined4 *)(*(long *)(param_1 + 0x918) + 0x14c) = param_2;
    DataMemoryBarrier(2,3);
    return 0;
  }
  return 0xe00002d8;
}

