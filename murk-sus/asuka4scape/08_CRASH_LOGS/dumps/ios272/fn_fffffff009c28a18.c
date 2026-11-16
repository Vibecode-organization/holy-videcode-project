// FUN_fffffff009c28a18 @ fffffff009c28a18 size=88

/* WARNING: Removing unreachable block (ram,0xfffffff009c28a44) */

void FUN_fffffff009c28a18(long param_1,ulong param_2)

{
  *(ulong *)(*(long *)(param_1 + 0x300) + 0x28) =
       *(ulong *)(*(long *)(param_1 + 0x300) + 0x28) & 0xffffffffffff | param_2;
  return;
}

