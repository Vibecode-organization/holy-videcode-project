// FUN_fffffff00a1d12d4 @ fffffff00a1d12d4 size=32

ulong FUN_fffffff00a1d12d4(undefined8 param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar2 = pacga(5,param_1);
  uVar1 = pacga(0x15,param_1);
  return uVar2 | 1 | uVar1 >> 0x20;
}

