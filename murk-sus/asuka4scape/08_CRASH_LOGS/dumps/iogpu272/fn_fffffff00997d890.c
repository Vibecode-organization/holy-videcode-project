// FUN_fffffff00997d890 @ fffffff00997d890 size=100

void FUN_fffffff00997d890(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 8);
  if (lVar1 != 0) {
    lVar2 = (long)(int)*(uint *)(param_1 + 0x10) << 4;
    if (0x7fffffff < *(uint *)(param_1 + 0x10)) {
      lVar2 = -0x8000000000000000;
    }
    *(undefined8 *)(param_1 + 8) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1c28,lVar1,lVar2);
    *(undefined8 *)(param_1 + 8) = 0;
  }
  if (*(long *)(param_1 + 0x28) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  return;
}

