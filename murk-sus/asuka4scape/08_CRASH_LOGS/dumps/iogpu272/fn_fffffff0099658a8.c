// FUN_fffffff0099658a8 @ fffffff0099658a8 size=64

uint FUN_fffffff0099658a8(long param_1)

{
  uint uVar1;
  
  uVar1 = FUN_fffffff009964e38(param_1,"com.apple.private.graphics-restart-no-kill");
  return uVar1 | (*(uint *)(*(long *)(param_1 + 0x48) + 0x1fc) & 0x40000000) >> 0x1e;
}

