// FUN_fffffff0081c082c @ fffffff0081c082c size=124

int FUN_fffffff0081c082c(long param_1,int param_2)

{
  if (param_2 == 3) {
    return *(int *)(param_1 + 0xb70) * 100;
  }
  if (param_2 != 2) {
    if (param_2 == 1) {
      return *(int *)(*(long *)(param_1 + 0x280) + 0x10f64);
    }
    return 0;
  }
  return ((uint)(*(int *)(*(long *)(param_1 + 0x280) + 0x10f64) + *(int *)(param_1 + 0xb70) * 100) /
         200) * 100;
}

