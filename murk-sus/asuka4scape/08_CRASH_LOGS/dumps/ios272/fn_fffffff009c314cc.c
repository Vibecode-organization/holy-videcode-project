// FUN_fffffff009c314cc @ fffffff009c314cc size=44

ulong FUN_fffffff009c314cc(ulong param_1)

{
  ulong uVar1;
  
  if (param_1 != 0) {
    uVar1 = param_1 | 8;
    if ((*(uint *)(DAT_fffffff00af483b0 + 0x1a4) & 0x20000) != 0) {
      uVar1 = param_1;
    }
    if ((*(uint *)(DAT_fffffff00af483b0 + 0x1a4) & 0x10000) != 0) {
      param_1 = uVar1;
    }
  }
  return param_1;
}

