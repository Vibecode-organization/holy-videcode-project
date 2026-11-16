// FUN_fffffff009c26b68 @ fffffff009c26b68 size=92

ulong FUN_fffffff009c26b68(ulong param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x240);
  if (lVar1 == 0) {
    param_1 = 1;
  }
  else {
    do {
      param_1 = FUN_fffffff009c26af8(param_1,param_2,lVar1,param_3);
      if ((param_1 & 1) == 0) {
        return param_1;
      }
      lVar1 = *(long *)(lVar1 + 0x58);
    } while (lVar1 != 0);
  }
  return param_1;
}

