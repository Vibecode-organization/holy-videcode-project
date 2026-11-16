// FUN_fffffff00a3bac10 @ fffffff00a3bac10 size=48

void FUN_fffffff00a3bac10(ulong *param_1)

{
  param_1[4] = (ulong)(uint)param_1[3];
  param_1[3] = (ulong)*(uint *)((long)param_1 + 0x14);
  param_1[2] = *(ulong *)((long)param_1 + 0xc);
  param_1[1] = *(ulong *)((long)param_1 + 4);
  *param_1 = (ulong)(uint)*param_1;
  return;
}

