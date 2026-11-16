// FUN_fffffff00a40b6b4 @ fffffff00a40b6b4 size=148
// CALLERS:
//   fffffff00afba41e ?
//   fffffff007c227f0 ?
// CALLS:
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00a226e08 FUN_fffffff00a226e08

undefined8 FUN_fffffff00a40b6b4(long param_1,undefined8 param_2,uint *param_3)

{
  ulong *puVar1;
  long lVar2;
  uint in_wzr;
  
  lVar2 = tpidr_el1;
  puVar1 = (ulong *)(param_1 + 0xd8);
  if (*puVar1 == 0) {
    *puVar1 = (ulong)*(uint *)(lVar2 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(param_1 + 0xd0,lVar2,(undefined **)0x0);
  }
  *param_3 = (uint)*(ushort *)(param_1 + 0xe2);
  if (*(uint *)puVar1 == *(uint *)(lVar2 + 0x4e8)) {
    *(uint *)puVar1 = in_wzr;
  }
  else {
    FUN_fffffff00a226e08(param_1 + 0xd0,lVar2,*(uint *)puVar1);
  }
  return 0;
}

