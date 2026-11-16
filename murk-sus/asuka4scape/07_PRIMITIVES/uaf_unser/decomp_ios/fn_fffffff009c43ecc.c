// FUN_fffffff009c43ecc @ fffffff009c43ecc size=116
// CALLERS:
//   fffffff009c439a0 FUN_fffffff009c43898@fffffff009c43898

undefined8 FUN_fffffff009c43ecc(long param_1,long *param_2)

{
  long *plVar1;
  
  FUN_fffffff009c49684(*(undefined8 *)(param_1 + 0x10));
  param_2[2] = 0;
  plVar1 = *(long **)(param_1 + 0x28);
  param_2[3] = (long)plVar1;
  *plVar1 = (long)param_2;
  *(long **)(param_1 + 0x28) = param_2 + 2;
  FUN_fffffff009c49674(*(undefined8 *)(param_1 + 0x10));
  (**(code **)(*param_2 + 0x28))(param_2);
  return 1;
}

