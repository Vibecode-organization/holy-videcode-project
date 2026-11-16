// FUN_fffffff0099438ec @ fffffff0099438ec size=116

void FUN_fffffff0099438ec(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  if (*(int *)(param_1 + 0x50) == 2) {
    lVar1 = param_1 + 0x60;
  }
  else {
    lVar1 = *(long *)(param_1 + 0x58);
  }
  if (0 < *(int *)(param_1 + 0x54)) {
    lVar2 = 0;
    do {
      FUN_fffffff00997f598(*(undefined8 *)(lVar1 + lVar2 * 8),param_2);
      lVar2 = lVar2 + 1;
    } while (lVar2 < *(int *)(param_1 + 0x54));
  }
  return;
}

