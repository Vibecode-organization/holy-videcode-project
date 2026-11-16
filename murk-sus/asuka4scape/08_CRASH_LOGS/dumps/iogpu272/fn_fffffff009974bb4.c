// FUN_fffffff009974bb4 @ fffffff009974bb4 size=72

ulong FUN_fffffff009974bb4(long param_1)

{
  ulong uVar1;
  
  if (DAT_fffffff00af227c0 == 0) {
    uVar1 = *(ulong *)(param_1 + 0x118);
  }
  else {
    uVar1 = (ulong)DAT_fffffff00af227c0 << 0x14;
    if (*(ulong *)(param_1 + 0x2c8) <= (ulong)DAT_fffffff00af227c0 << 0x14) {
      uVar1 = *(ulong *)(param_1 + 0x2c8);
    }
  }
  return (*(long *)PTR_DAT_fffffff007ff2838 + (uVar1 >> 3)) - 1 & -*(long *)PTR_DAT_fffffff007ff2838
  ;
}

