// FUN_fffffff009c43f40 @ fffffff009c43f40 size=116
// CALLERS:
//   fffffff00afec1d1 no-fn
//   fffffff009c448d0 FUN_fffffff009c443e0@fffffff009c443e0
// CALLEES:
//   fffffff009c49674 thunk_FUN_fffffff00a228d30
//   fffffff009c49684 thunk_FUN_fffffff00a227a00

undefined8 FUN_fffffff009c43f40(long param_1,long *param_2)

{
  undefined8 *puVar1;
  
  thunk_FUN_fffffff00a227a00(*(ulong *)(param_1 + 0x18));
  param_2[6] = 0;
  puVar1 = *(undefined8 **)(param_1 + 0x38);
  param_2[7] = (long)puVar1;
  *puVar1 = param_2;
  *(long **)(param_1 + 0x38) = param_2 + 6;
  thunk_FUN_fffffff00a228d30(*(long *)(param_1 + 0x18));
  (**(code **)(*param_2 + 0x28))(param_2);
  return 1;
}

