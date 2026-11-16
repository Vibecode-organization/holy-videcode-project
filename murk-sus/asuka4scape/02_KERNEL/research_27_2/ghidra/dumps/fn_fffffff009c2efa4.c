// FUN_fffffff009c2efa4 @ fffffff009c2efa4 size=24
// CALLERS:
//   fffffff00afebf07 no-fn
//   fffffff009c2a018 FUN_fffffff009c29ee4@fffffff009c29ee4
// CALLEES:

uint FUN_fffffff009c2efa4(long param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0x10) + 0x28);
  if (uVar1 < 2) {
    uVar1 = 1;
  }
  return uVar1;
}

