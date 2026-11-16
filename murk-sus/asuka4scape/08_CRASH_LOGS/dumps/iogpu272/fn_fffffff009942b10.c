// FUN_fffffff009942b10 @ fffffff009942b10 size=124

bool FUN_fffffff009942b10(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  (*DAT_fffffff007feb260)();
  *(undefined8 *)(param_1 + 0x10) = param_2;
  lVar2 = thunk_EXT_FUN_80110000038ff010();
  *(long *)(param_1 + 0x48) = lVar2;
  if (lVar2 != 0) {
    *(undefined4 *)(param_1 + 0x50) = 2;
    *(undefined8 *)(param_1 + 0x58) = 0;
    *(undefined1 *)(param_1 + 0x35) = 2;
    lVar1 = DAT_fffffff00af21d30 + 1;
    *(long *)(param_1 + 0x70) = DAT_fffffff00af21d30;
    DAT_fffffff00af21d30 = lVar1;
  }
  return lVar2 != 0;
}

