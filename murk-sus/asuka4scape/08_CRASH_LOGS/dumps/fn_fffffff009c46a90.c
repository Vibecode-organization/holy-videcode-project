// FUN_fffffff009c46a90 @ fffffff009c46a90 size=168
// CALLERS:
//   fffffff00afec203 no-fn
//   fffffff009c3ea88 FUN_fffffff009c3e86c@fffffff009c3e86c
// CALLEES:
//   fffffff009c495d4 thunk_FUN_fffffff00a226de0
//   fffffff009c495b4 thunk_FUN_fffffff00a2262a8

undefined8 FUN_fffffff009c46a90(long param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  
  thunk_FUN_fffffff00a2262a8(*(ulong *)(param_1 + 0x40));
  lVar1 = 0;
  lVar2 = 10;
  do {
    (**(code **)(**(long **)(param_1 + 0x48 + lVar1 * 8) + 0xb8))();
    lVar1 = lVar1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0x40));
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  return 1;
}

