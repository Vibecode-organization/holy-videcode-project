// FUN_fffffff009c2a65c @ fffffff009c2a65c size=36
// CALLERS:
//   fffffff00afebe1a no-fn
//   fffffff007ff2490 no-fn
//   fffffff008022028 no-fn
//   fffffff00802a150 no-fn
//   fffffff009984a98 thunk_FUN_fffffff009c2a65c@fffffff009984a8c
//   fffffff009a9a5ec thunk_FUN_fffffff009c2a65c@fffffff009a9a5e0
//   fffffff009abd7d8 thunk_FUN_fffffff009c2a65c@fffffff009abd7cc
// CALLEES:

void FUN_fffffff009c2a65c(long param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0x100;
  if (param_2 == 0) {
    uVar1 = 0;
  }
  *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xfffffeff | uVar1;
  return;
}

