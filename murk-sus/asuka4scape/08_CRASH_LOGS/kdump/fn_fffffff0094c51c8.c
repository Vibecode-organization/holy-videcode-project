// FUN_fffffff0094c51c8 @ fffffff0094c51c8 size=36
// CALLERS:
//   fffffff00afb8097 ?
//   fffffff0094c7044 FUN_fffffff0094c6eac@fffffff0094c6eac
//   fffffff0094c7060 FUN_fffffff0094c6eac@fffffff0094c6eac
//   fffffff0094c707c FUN_fffffff0094c6eac@fffffff0094c6eac
//   fffffff0094c709c FUN_fffffff0094c6eac@fffffff0094c6eac
//   fffffff0094c71f0 FUN_fffffff0094c71b0@fffffff0094c71b0
//   fffffff0094c7208 FUN_fffffff0094c71b0@fffffff0094c71b0
//   fffffff0094c7220 FUN_fffffff0094c71b0@fffffff0094c71b0
//   fffffff0094c7238 FUN_fffffff0094c71b0@fffffff0094c71b0
//   fffffff0094c7250 FUN_fffffff0094c71b0@fffffff0094c71b0
//   fffffff0094c7268 FUN_fffffff0094c71b0@fffffff0094c71b0
//   fffffff0094c7280 FUN_fffffff0094c71b0@fffffff0094c71b0
//   fffffff0094c7298 FUN_fffffff0094c71b0@fffffff0094c71b0
//   fffffff0094c59b8 FUN_fffffff0094c5408@fffffff0094c5408
//   fffffff0094bf724 FUN_fffffff0094bf644@fffffff0094bf644
//   fffffff0094bfa98 FUN_fffffff0094bf918@fffffff0094bf918
//   fffffff0094c2f04 FUN_fffffff0094c2ebc@fffffff0094c2ebc
//   fffffff0094c1bc0 FUN_fffffff0094c1b1c@fffffff0094c1b1c
//   fffffff0094c2ff4 FUN_fffffff0094c2fc8@fffffff0094c2fc8
//   fffffff0094c300c FUN_fffffff0094c2fc8@fffffff0094c2fc8
//   fffffff0094c3028 FUN_fffffff0094c2fc8@fffffff0094c2fc8
//   fffffff0094c3040 FUN_fffffff0094c2fc8@fffffff0094c2fc8
//   fffffff0094c305c FUN_fffffff0094c2fc8@fffffff0094c2fc8
//   fffffff0094c3074 FUN_fffffff0094c2fc8@fffffff0094c2fc8
//   fffffff0094c3090 FUN_fffffff0094c2fc8@fffffff0094c2fc8
//   fffffff0094c30a8 FUN_fffffff0094c2fc8@fffffff0094c2fc8
//   fffffff0094c30c0 FUN_fffffff0094c2fc8@fffffff0094c2fc8
//   fffffff0094c30d8 FUN_fffffff0094c2fc8@fffffff0094c2fc8
// CALLS:
//   fffffff0094c9bb4 thunk_EXT_FUN_80110000033502b4

ulong FUN_fffffff0094c51c8(undefined8 *param_1,undefined8 param_2,ulong param_3)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_1[1] == param_3) {
    uVar2 = thunk_EXT_FUN_80110000033502b4(*param_1);
    return uVar2;
  }
  uVar1 = 1;
  if (param_3 < (ulong)param_1[1]) {
    uVar1 = 0xffffffff;
  }
  return (ulong)uVar1;
}

