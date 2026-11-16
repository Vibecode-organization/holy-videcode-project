// FUN_fffffff00816ea90 @ fffffff00816ea90 size=188

ulong FUN_fffffff00816ea90(undefined8 param_1,long *param_2)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar2 = (**(code **)(PTR_DAT_fffffff007ca6170 + 0x690))();
  uVar1 = (**(code **)(*param_2 + 0x148))(param_2);
  uVar3 = uVar2;
  if ((uVar1 & 1) == 0) {
    if ((uVar1 >> 1 & 1) != 0) {
      if ((uVar1 >> 2 & 1) == 0) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = 0x3fffffffc;
      }
      if (uVar4 <= uVar2) {
        uVar3 = uVar4;
      }
    }
  }
  else {
    uVar3 = 0x100000000 - (long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f));
    if (uVar2 <= uVar3) {
      uVar3 = uVar2;
    }
  }
  return uVar3;
}

