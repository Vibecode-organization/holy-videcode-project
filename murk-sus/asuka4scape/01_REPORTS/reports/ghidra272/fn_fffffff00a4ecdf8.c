// FUN_fffffff00a4ecdf8 @ fffffff00a4ecdf8 size=108

bool FUN_fffffff00a4ecdf8(ulong param_1)

{
  ulong uVar1;
  bool bVar2;
  
  uVar1 = param_1 & 0x7ffffffffff;
  if ((param_1 & 0x80000000000000) != 0) {
    uVar1 = param_1 | 0xffffff8000000000;
  }
  bVar2 = true;
  if ((DAT_fffffff007c6a360 <= uVar1 || uVar1 < DAT_fffffff007c6a358) &&
     (uVar1 < DAT_fffffff007c6a378 || DAT_fffffff007c6a380 <= uVar1)) {
    bVar2 = DAT_fffffff007c6a3a0 <= uVar1 && uVar1 < DAT_fffffff007c6a3a8;
  }
  return bVar2;
}

