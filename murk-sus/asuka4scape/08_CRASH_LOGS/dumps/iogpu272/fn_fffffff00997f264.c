// FUN_fffffff00997f264 @ fffffff00997f264 size=172

undefined8 FUN_fffffff00997f264(long *param_1)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  if ((*(ushort *)(param_1 + 2) & 1) == 0) {
    lVar1 = (**(code **)(*(long *)param_1[4] + 0x88))((long *)param_1[4],param_1);
    uVar3 = 0;
    if (lVar1 != 0) {
      param_1[5] = lVar1;
      *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | 1;
      uVar2 = FUN_fffffff009942da8(param_1[3],param_1);
      if ((uVar2 & 1) == 0) {
        (**(code **)(*param_1 + 0xc0))(param_1);
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
    }
    return uVar3;
  }
  return 1;
}

