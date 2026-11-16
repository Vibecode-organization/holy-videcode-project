// FUN_fffffff009c2a5a4 @ fffffff009c2a5a4 size=124

/* WARNING: Removing unreachable block (ram,0xfffffff009c2a5f8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2a5d4) */

void FUN_fffffff009c2a5a4(long param_1,ulong param_2,ulong param_3,long param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x300);
  if (param_4 != 0) {
    *(long *)(lVar1 + 0x10) = param_4;
  }
  *(ulong *)(lVar1 + 0x28) =
       *(ulong *)(lVar1 + 0x28) & (param_2 ^ 0xffffffffffffffff) | param_3 & param_2;
  return;
}

