// FUN_fffffff0099754f4 @ fffffff0099754f4 size=44

void FUN_fffffff0099754f4(long param_1)

{
  uint uVar1;
  
  uVar1 = DAT_fffffff00af22800 & 1;
  if ((DAT_fffffff00af227f1 & 1) != 0) {
    uVar1 = 1;
  }
  **(uint **)(param_1 + 0x178) = uVar1;
  return;
}

