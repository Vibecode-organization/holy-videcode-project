// FUN_fffffff009c314f8 @ fffffff009c314f8 size=28

ulong FUN_fffffff009c314f8(ulong param_1)

{
  ulong uVar1;
  
  uVar1 = param_1 >> 1 & 2;
  return (uVar1 | param_1 & 2) >> 1 | uVar1 | param_1;
}

