// FUN_fffffff00996f1e0 @ fffffff00996f1e0 size=76

undefined8 FUN_fffffff00996f1e0(long param_1)

{
  undefined8 uVar1;
  undefined8 in_x4;
  
  uVar1 = FUN_fffffff00996d358();
  if ((int)uVar1 != 0) {
    *(undefined8 *)(param_1 + 0x160) = 0;
    *(long *)(param_1 + 0x168) = param_1 + 0x160;
    uVar1 = FUN_fffffff00994d91c(in_x4);
    if ((int)uVar1 != 0) {
      *(undefined8 *)(param_1 + 0x148) = in_x4;
      uVar1 = 1;
    }
  }
  return uVar1;
}

