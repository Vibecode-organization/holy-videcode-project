// thunk_FUN_fffffff009c28d28 @ fffffff008e00590 size=16
// CALLERS:
//   fffffff008df71b4 FUN_fffffff008df7198@fffffff008df7198
// CALLEES:
//   fffffff009c28d28 FUN_fffffff009c28d28

undefined4
thunk_FUN_fffffff009c28d28
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_FUN_fffffff007e61198)((int)param_7,param_8);
  return uVar1;
}

