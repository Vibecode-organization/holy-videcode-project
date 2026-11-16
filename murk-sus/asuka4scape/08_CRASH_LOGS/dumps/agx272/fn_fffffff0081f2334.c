// FUN_fffffff0081f2334 @ fffffff0081f2334 size=156

void FUN_fffffff0081f2334(long *param_1)

{
  if (param_1[4] != 0) {
    (**(code **)(*param_1 + 0xc0))();
    (**(code **)(*param_1 + 0xb8))(param_1,param_1[4]);
    if (param_1[4] != 0) {
      *(bool *)((long)param_1 + 0x54) =
           *(int *)(*(long *)(*(long *)(param_1[2] + 0x4b0) + 0x910) + 0x4040) != 0;
    }
  }
  return;
}

