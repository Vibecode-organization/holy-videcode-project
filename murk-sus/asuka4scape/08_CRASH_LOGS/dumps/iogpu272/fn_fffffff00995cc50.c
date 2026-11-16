// FUN_fffffff00995cc50 @ fffffff00995cc50 size=36

void FUN_fffffff00995cc50(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x6c) = param_2;
  *(undefined1 *)(param_1 + 99) = 0;
  if (*(long *)(param_1 + 0x18) != 0) {
    *(byte *)(param_1 + 99) = *(byte *)(*(long *)(param_1 + 0x18) + 0x43b) & 1;
  }
  return;
}

