// FUN_fffffff00a9b1444 @ fffffff00a9b1444 size=44 depth=0
// CALLERS:
//   fffffff00afbf68f ?
//   fffffff007c38660 ?
//   fffffff007c38688 ?
//   fffffff007c386b0 ?
//   fffffff007c386d8 ?
//   fffffff007c38700 ?
//   fffffff007c38728 ?
//   fffffff007c38750 ?
// CALLS:

undefined4 FUN_fffffff00a9b1444(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xe00002c2;
  if ((0x3f < *(uint *)(param_3 + 0x38)) && (*(long *)(param_3 + 0x30) != 0)) {
    uVar1 = 0xe00002d8;
  }
  return uVar1;
}

