// FUN_fffffff00aa119e4 @ fffffff00aa119e4 size=156 depth=1
// CALLERS:
//   fffffff00afbfdc2 ?
//   fffffff00a9e03c4 FUN_fffffff00a9dfff0
// CALLS:

undefined8 FUN_fffffff00aa119e4(long param_1,undefined8 param_2)

{
  undefined8 local_18;
  
  if (*(long *)(param_1 + 0xd0) != 0) {
    if (DAT_fffffff00add78a0 != (long *)0x0) {
      local_18 = param_2;
      (**(code **)(*DAT_fffffff00add78a0 + 0x100))
                ((undefined8 *)(*DAT_fffffff00add78a0 + 0x100),DAT_fffffff00add78a0,
                 FUN_fffffff00aa11a80,*(long *)(param_1 + 0xd0),&local_18,0,0,0);
    }
    return 0;
  }
  return 0xe00002f0;
}

