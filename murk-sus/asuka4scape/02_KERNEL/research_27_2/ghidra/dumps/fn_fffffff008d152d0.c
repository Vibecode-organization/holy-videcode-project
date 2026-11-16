// FUN_fffffff008d152d0 @ fffffff008d152d0 size=104
// CALLERS:
//   fffffff00afb8d58 no-fn
// CALLEES:
//   fffffff008d50ff0 FUN_fffffff008d50ff0
//   fffffff008e007a0 thunk_EXT_FUN_8011000003a61b10

undefined8 FUN_fffffff008d152d0(long param_1,undefined8 param_2,ulong *param_3)

{
  undefined8 uVar1;
  ulong uVar2;
  
  uVar2 = *param_3;
  if (0x298 < uVar2) {
    uVar2 = 0x298;
    *param_3 = 0x298;
  }
  uVar1 = FUN_fffffff008d50ff0(*(undefined8 *)(param_1 + 0x100),8);
  thunk_EXT_FUN_8011000003a61b10(param_2,uVar1,uVar2);
  *param_3 = uVar2;
  return 0;
}

