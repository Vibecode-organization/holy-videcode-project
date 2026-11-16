// FUN_fffffff00997f598 @ fffffff00997f598 size=372

void FUN_fffffff00997f598(long *param_1,ulong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_48;
  
  if (DAT_fffffff00af227e8 != 0) {
    uVar2 = (**(code **)(*(long *)param_1[3] + 0x108))();
    uVar1 = *(uint *)((long *)param_1[3] + 6);
    uVar3 = (**(code **)(*(long *)param_1[3] + 0xe0))();
    local_48 = 0;
    thunk_EXT_FUN_80110000032db760(uVar3,&local_48);
    thunk_EXT_FUN_80110000036da494
              (0x85180075,uVar2,(param_2 & 0x7ffffffffffffffe) << 1 | (ulong)(uVar1 >> 5) & 1,
               local_48,*(undefined4 *)(param_1[4] + 0x20),0);
  }
  (**(code **)(*param_1 + 0xe8))(param_1,param_2);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xffdf;
  if (DAT_fffffff00af227e8 != 0) {
    uVar2 = (**(code **)(*(long *)param_1[3] + 0x108))();
    uVar3 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1[3] + 0x10));
    thunk_EXT_FUN_80110000036da494(0x85180076,uVar2,0,uVar3,*(undefined4 *)(param_1[4] + 0x20),0);
  }
  return;
}

