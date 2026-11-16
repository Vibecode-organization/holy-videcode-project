// FUN_fffffff0081be994 @ fffffff0081be994 size=44

undefined8 FUN_fffffff0081be994(long param_1,uint param_2)

{
  *(float *)(*(long *)(param_1 + 0x280) + 0x10f70) = (float)param_2;
  *(uint *)(param_1 + 0x1b20) = param_2;
  *(uint *)(*(long *)(param_1 + 0x348) + 0xa4) = param_2;
  return 0;
}

