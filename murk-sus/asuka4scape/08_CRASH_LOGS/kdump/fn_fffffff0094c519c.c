// FUN_fffffff0094c519c @ fffffff0094c519c size=44
// CALLERS:
//   fffffff00afb8096 ?
//   fffffff0094c6fb8 FUN_fffffff0094c6eac@fffffff0094c6eac
//   fffffff0094c6fcc FUN_fffffff0094c6eac@fffffff0094c6eac
//   fffffff0094c2f90 FUN_fffffff0094c2f4c@fffffff0094c2f4c
//   fffffff0094c6374 FUN_fffffff0094c6324@fffffff0094c6324
//   fffffff0094c8358 FUN_fffffff0094c82cc@fffffff0094c82cc
//   fffffff0094c83ac FUN_fffffff0094c82cc@fffffff0094c82cc
//   fffffff0094c83dc FUN_fffffff0094c82cc@fffffff0094c82cc
//   fffffff0094c8268 FUN_fffffff0094c8220@fffffff0094c8220
//   fffffff0094c8540 FUN_fffffff0094c84c4@fffffff0094c84c4
//   fffffff0094c85ec FUN_fffffff0094c8580@fffffff0094c8580
//   fffffff0094c86ac FUN_fffffff0094c8638@fffffff0094c8638
//   fffffff0094c8738 FUN_fffffff0094c8638@fffffff0094c8638
//   fffffff0094c877c FUN_fffffff0094c8638@fffffff0094c8638
//   fffffff0094c884c FUN_fffffff0094c8638@fffffff0094c8638
//   fffffff0094c8964 FUN_fffffff0094c8638@fffffff0094c8638
//   fffffff0094c8974 FUN_fffffff0094c8638@fffffff0094c8638
//   fffffff0094c8a3c FUN_fffffff0094c8638@fffffff0094c8638
//   fffffff0094c8bcc FUN_fffffff0094c8638@fffffff0094c8638
//   fffffff0094c8bdc FUN_fffffff0094c8638@fffffff0094c8638
//   fffffff0094c7440 FUN_fffffff0094c7388@fffffff0094c7388
//   fffffff0094c7464 FUN_fffffff0094c7388@fffffff0094c7388
//   fffffff0094c8c60 FUN_fffffff0094c8c04@fffffff0094c8c04
//   fffffff0094c8c74 FUN_fffffff0094c8c04@fffffff0094c8c04
//   fffffff0094c8d98 FUN_fffffff0094c8d1c@fffffff0094c8d1c
//   fffffff0094c8dec FUN_fffffff0094c8d1c@fffffff0094c8d1c
//   fffffff0094c8e18 FUN_fffffff0094c8d1c@fffffff0094c8d1c
//   fffffff0094c8eb4 FUN_fffffff0094c8d1c@fffffff0094c8d1c
//   fffffff0094c8f08 FUN_fffffff0094c8d1c@fffffff0094c8d1c
//   fffffff0094c8f9c FUN_fffffff0094c8f38@fffffff0094c8f38
//   fffffff0094c8fac FUN_fffffff0094c8f38@fffffff0094c8f38
//   fffffff0094bf4a4 FUN_fffffff0094bf3f0@fffffff0094bf3f0
//   fffffff0094bf4b8 FUN_fffffff0094bf3f0@fffffff0094bf3f0
//   fffffff0094bf4cc FUN_fffffff0094bf3f0@fffffff0094bf3f0
//   fffffff0094bf4e0 FUN_fffffff0094bf3f0@fffffff0094bf3f0
//   fffffff0094bf5d0 FUN_fffffff0094bf51c@fffffff0094bf51c
//   fffffff0094bf5e4 FUN_fffffff0094bf51c@fffffff0094bf51c
//   fffffff0094bf5f8 FUN_fffffff0094bf51c@fffffff0094bf51c
//   fffffff0094bf60c FUN_fffffff0094bf51c@fffffff0094bf51c
//   fffffff0094c1ad8 FUN_fffffff0094c1a90@fffffff0094c1a90
//   fffffff0094c1af4 FUN_fffffff0094c1a90@fffffff0094c1a90
//   fffffff0094c2b78 FUN_fffffff0094c2ae8@fffffff0094c2ae8
//   fffffff0094c2b8c FUN_fffffff0094c2ae8@fffffff0094c2ae8
//   fffffff0094c2da0 FUN_fffffff0094c2cac@fffffff0094c2cac
//   fffffff0094c32f0 FUN_fffffff0094c32a0@fffffff0094c32a0
//   fffffff0094c330c FUN_fffffff0094c32a0@fffffff0094c32a0
//   fffffff0094c36dc FUN_fffffff0094c3658@fffffff0094c3658
//   fffffff0094c7d08 FUN_fffffff0094c7c64@fffffff0094c7c64
//   fffffff0094c7d2c FUN_fffffff0094c7c64@fffffff0094c7c64
//   fffffff0094c7f48 FUN_fffffff0094c7e00@fffffff0094c7e00
//   fffffff0094c7f60 FUN_fffffff0094c7e00@fffffff0094c7e00
//   fffffff0094c33e8 FUN_fffffff0094c3364@fffffff0094c3364
// CALLS:
//   fffffff0094c9bb4 thunk_EXT_FUN_80110000033502b4

ulong FUN_fffffff0094c519c(undefined8 *param_1,undefined8 *param_2)

{
  uint uVar1;
  ulong uVar2;
  
  if (param_1[1] == param_2[1]) {
    uVar2 = thunk_EXT_FUN_80110000033502b4(*param_1,*param_2);
    return uVar2;
  }
  uVar1 = 1;
  if ((ulong)param_2[1] < (ulong)param_1[1]) {
    uVar1 = 0xffffffff;
  }
  return (ulong)uVar1;
}

