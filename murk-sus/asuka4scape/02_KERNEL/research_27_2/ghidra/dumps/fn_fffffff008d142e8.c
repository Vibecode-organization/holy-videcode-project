// FUN_fffffff008d142e8 @ fffffff008d142e8 size=472
// CALLERS:
//   fffffff00afb8d38 no-fn
//   fffffff008d141b0 FUN_fffffff008d14158@fffffff008d14158
// CALLEES:
//   fffffff008d56c60 thunk_FUN_fffffff008d56c68
//   fffffff008cd5954 FUN_fffffff008cd5954
//   fffffff008dc99d0 FUN_fffffff008dc99d0
//   fffffff008dffd30 thunk_EXT_FUN_80110000038fe270
//   fffffff008dc9650 FUN_fffffff008dc9650
//   fffffff008dffde0 thunk_EXT_FUN_80110000038fe074
//   fffffff008dfff50 thunk_EXT_FUN_80110000039a2360
//   fffffff008de655c FUN_fffffff008de655c

undefined8 FUN_fffffff008d142e8(long *param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  uint local_44;
  
  local_44 = 0;
  (**(code **)(*param_1 + 0x20))();
  if (*(int *)((long)param_1 + 0x164) == 0) {
    lVar3 = thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007e5c3e8);
    if (lVar3 == 0) {
      uVar2 = 0xe00002bd;
      iVar1 = FUN_fffffff008cd5954(1,4);
      if (iVar1 != 0) {
        FUN_fffffff008de655c();
      }
      lVar3 = 0;
      goto LAB_fffffff008d14454;
    }
    thunk_EXT_FUN_80110000039a2360
              (lVar3,param_1[0x24],*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x10),
               param_1[0x26]);
    *(long **)(lVar3 + 0x48) = param_1;
    (**(code **)(*param_1 + 0x20))(param_1);
    *(undefined8 *)(lVar3 + 0x40) = *(undefined8 *)(param_2 + 0x18);
    *(byte *)(lVar3 + 0x50) = (byte)(*(uint *)(param_2 + 0x20) >> 10) & 1;
    uVar2 = FUN_fffffff008dc9650(param_1[0x28],FUN_fffffff008d144cc,&local_44,0,lVar3,0,0);
    iVar1 = (int)uVar2;
  }
  else {
    uVar2 = FUN_fffffff008dc9650
                      (param_1[0x28],FUN_fffffff008d14588,&local_44,0,*(undefined8 *)(param_2 + 8),
                       *(undefined8 *)(param_2 + 0x10),*(undefined8 *)(param_2 + 0x18));
    lVar3 = 0;
    iVar1 = (int)uVar2;
  }
  if (iVar1 == 0) {
    *(ulong *)(param_2 + 0x10) = (ulong)local_44;
    *(undefined8 *)(param_2 + 0x18) = 0;
    uVar2 = thunk_FUN_fffffff008d56c68(param_1[0x20],param_2,(ulong)local_44,param_1);
    if ((int)uVar2 != 0) {
      FUN_fffffff008dc99d0(param_1[0x28],local_44);
    }
  }
LAB_fffffff008d14454:
  (**(code **)(*param_1 + 0x28))(param_1);
  if ((lVar3 != 0) && ((int)uVar2 != 0)) {
    (**(code **)(*param_1 + 0x28))(param_1);
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007e5c428,lVar3);
  }
  return uVar2;
}

