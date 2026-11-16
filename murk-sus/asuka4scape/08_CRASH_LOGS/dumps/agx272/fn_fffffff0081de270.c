// FUN_fffffff0081de270 @ fffffff0081de270 size=64

void FUN_fffffff0081de270(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  
  uVar2 = (ulong)*param_2;
  if (*param_2 != 0) {
    lVar3 = 0;
    do {
      uVar1 = param_2[lVar3 * 0x10 + 0x12];
      if (uVar1 < 0x303) {
        uVar1 = 0x302;
      }
      param_2[lVar3 * 0x10 + 0x112] = uVar1;
      lVar3 = lVar3 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}

