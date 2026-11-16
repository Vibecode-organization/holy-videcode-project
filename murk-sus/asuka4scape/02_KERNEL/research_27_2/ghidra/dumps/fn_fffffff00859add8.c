// thunk_FUN_fffffff009c28d28 @ fffffff00859add8 size=16
// CALLERS:
//   fffffff008528a28 FUN_fffffff0085287f4@fffffff0085287f4
//   fffffff008528c48 FUN_fffffff0085287f4@fffffff0085287f4
//   fffffff008528dd4 FUN_fffffff0085287f4@fffffff0085287f4
//   fffffff008528f74 FUN_fffffff0085287f4@fffffff0085287f4
//   fffffff008529064 FUN_fffffff0085287f4@fffffff0085287f4
// CALLEES:
//   fffffff009c28d28 FUN_fffffff009c28d28

undefined4
thunk_FUN_fffffff009c28d28
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_FUN_fffffff007d07670)((int)param_7,param_8);
  return uVar1;
}

