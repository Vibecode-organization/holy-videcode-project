// FUN_fffffff0081c3ecc @ fffffff0081c3ecc size=48

undefined8 FUN_fffffff0081c3ecc(long param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    param_2 = *(undefined4 *)(param_1 + 0x1c00);
  }
  else {
    *(undefined4 *)(param_1 + 0x1c04) = param_2;
  }
  *(uint *)(param_1 + 0x1c08) = (uint)(param_3 != 0);
  *(undefined4 *)(*(long *)(param_1 + 0x348) + 0x9bc) = param_2;
  return 0;
}

