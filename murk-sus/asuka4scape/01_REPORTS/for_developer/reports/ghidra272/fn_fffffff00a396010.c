// FUN_fffffff00a396010 @ fffffff00a396010 size=192

long FUN_fffffff00a396010(ulong param_1)

{
  ulong uVar1;
  
  uVar1 = param_1 & 0x7ffffffffff;
  if ((param_1 & 0x80000000000000) != 0) {
    uVar1 = param_1 | 0xffffff8000000000;
  }
  if (((DAT_fffffff007c6a360 <= uVar1 || uVar1 < DAT_fffffff007c6a358) &&
      (uVar1 < DAT_fffffff007c6a378 || DAT_fffffff007c6a380 <= uVar1)) &&
     (uVar1 < DAT_fffffff007c6a3a0 || DAT_fffffff007c6a3a8 <= uVar1)) {
    return 0;
  }
  if (DAT_fffffff007c6a378 <= param_1 && param_1 < DAT_fffffff007c6a380) {
    return param_1 - DAT_fffffff007c6a388;
  }
  if (param_1 < DAT_fffffff007c6a3a0 || DAT_fffffff007c6a3a8 <= param_1) {
    return param_1 - DAT_fffffff007c6a570;
  }
  return param_1 - DAT_fffffff007c6a3b0;
}

