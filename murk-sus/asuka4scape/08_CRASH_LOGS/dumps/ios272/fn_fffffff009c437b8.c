// FUN_fffffff009c437b8 @ fffffff009c437b8 size=124

bool FUN_fffffff009c437b8(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))();
  *(undefined8 *)(param_1 + 0x40) = 1;
  uVar1 = thunk_EXT_FUN_80110000038ff3d8();
  *(undefined8 *)(param_1 + 0x10) = uVar1;
  lVar2 = thunk_EXT_FUN_80110000038ff3d8();
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(long *)(param_1 + 0x18) = lVar2;
  *(undefined8 **)(param_1 + 0x28) = (undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 **)(param_1 + 0x38) = (undefined8 *)(param_1 + 0x30);
  return *(long *)(param_1 + 0x10) != 0 && lVar2 != 0;
}

