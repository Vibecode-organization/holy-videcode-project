// FUN_fffffff009c93e74 @ fffffff009c93e74

undefined8 FUN_fffffff009c93e74(long *param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined *local_80;
  undefined8 local_78;
  code *local_70;
  undefined *local_68;
  undefined8 *local_60;
  long *plStack_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  
  if ((((param_2 & 1) == 0) ||
      (lVar2 = (**(code **)(*(long *)param_1[0x17] + 0x118))
                         ((long *)param_1[0x17],"usb-device-slp-ddr"),
      lVar2 == **(long **)PTR_PTR_fffffff00807fb18)) ||
     (iVar1 = (**(code **)(*param_1 + 0x5c0))(param_1), 2 < iVar1)) {
    local_50 = 0;
    local_40 = DAT_fffffff0078b2b10;
    local_48 = &local_50;
    local_38 = (**(code **)(PTR_DAT_fffffff00807fae8 + 0x4f0))(param_1,param_2);
    local_80 = PTR_DAT_fffffff00807fa48;
    local_78 = DAT_fffffff0078b2b18;
    local_70 = FUN_fffffff009c93fe8;
    local_68 = &DAT_fffffff00807e298;
    local_60 = &local_50;
    plStack_58 = param_1;
    thunk_FUN_fffffff00a960120((long *)param_1[0x11],&local_80);
    uVar3 = local_48[3];
    thunk_FUN_fffffff00a8eddac((long)&local_50,8);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

