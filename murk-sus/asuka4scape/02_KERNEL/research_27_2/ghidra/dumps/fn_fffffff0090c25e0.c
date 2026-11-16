// thunk_FUN_fffffff009c29028 @ fffffff0090c25e0 size=16
// CALLERS:
//   fffffff009081da0 FUN_fffffff009080fb4@fffffff009080fb4
// CALLEES:
//   fffffff009c29028 FUN_fffffff009c29028

undefined4
thunk_FUN_fffffff009c29028
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_FUN_fffffff007eb7558)((int)param_7,param_8);
  return uVar1;
}

