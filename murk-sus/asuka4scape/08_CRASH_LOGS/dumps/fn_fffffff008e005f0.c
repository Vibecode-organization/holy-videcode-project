// thunk_FUN_fffffff009c29028 @ fffffff008e005f0 size=16
// CALLERS:
//   fffffff008df72d4 FUN_fffffff008df72b8@fffffff008df72b8
// CALLEES:
//   fffffff009c29028 FUN_fffffff009c29028

undefined4
thunk_FUN_fffffff009c29028
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_FUN_fffffff007e611c8)((int)param_7,param_8);
  return uVar1;
}

