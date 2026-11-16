// FUN_fffffff0081d7bc0 @ fffffff0081d7bc0 size=52

uint FUN_fffffff0081d7bc0(long param_1,undefined4 *param_2)

{
  ulong uVar1;
  
  uVar1 = *(ulong *)(*(long *)(param_1 + 0x308) + 0x11108);
  if ((uVar1 & 1) != 0) {
    *param_2 = *(undefined4 *)(&DAT_fffffff007114e3c + (uVar1 & 0x1c));
  }
  return (uint)uVar1 & 1;
}

