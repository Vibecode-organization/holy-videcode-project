// FUN_fffffff00994f128 @ fffffff00994f128 size=88

void FUN_fffffff00994f128(long param_1,undefined8 param_2,undefined8 param_3)

{
  if ((*(byte *)(param_1 + 0x104) & 1) != 0) {
    if (*(long *)(param_1 + 0xf0) != 0) {
      FUN_fffffff009975758
                (*(undefined8 *)(param_1 + 0x10),*(long *)(param_1 + 0xf0),param_2,param_3);
    }
    *(undefined1 *)(param_1 + 0x104) = 0;
    if ((int)param_3 != 0) {
      *(undefined8 *)(param_1 + 0xf0) = 0;
    }
  }
  return;
}

