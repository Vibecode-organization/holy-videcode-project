// FUN_fffffff008d141d0 @ fffffff008d141d0 size=280
// CALLERS:
//   fffffff00afb8d37 no-fn
//   fffffff008d141b8 FUN_fffffff008d14158@fffffff008d14158
// CALLEES:
//   fffffff008d56c60 thunk_FUN_fffffff008d56c68
//   fffffff008dc99d0 FUN_fffffff008dc99d0
//   fffffff008dc9b54 FUN_fffffff008dc9b54
//   fffffff008dc9650 FUN_fffffff008dc9650
//   fffffff008cd5a74 FUN_fffffff008cd5a74

int FUN_fffffff008d141d0(long *param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_38;
  int local_34;
  
  local_38 = 0;
  local_34 = -0x1ffffd16;
  (**(code **)(*param_1 + 0x20))();
  iVar2 = FUN_fffffff008dc9650(param_1[0x28],FUN_fffffff008d144c0,&local_38,0,&local_34,0,0);
  if (iVar2 == 0) {
    iVar2 = thunk_FUN_fffffff008d56c68(param_1[0x20],param_2,local_38,param_1);
    if (iVar2 == 0) {
      iVar2 = FUN_fffffff008dc9b54(param_1[0x28],local_38,0);
    }
    else {
      FUN_fffffff008dc99d0();
    }
  }
  (**(code **)(*param_1 + 0x28))(param_1);
  iVar1 = local_34;
  if (iVar2 != 0) {
    iVar1 = iVar2;
  }
  FUN_fffffff008cd5a74(0x115,0x230,0,param_1,1);
  return iVar1;
}

