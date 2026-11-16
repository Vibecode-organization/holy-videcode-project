// FUN_fffffff0081ef5ac @ fffffff0081ef5ac size=328

void FUN_fffffff0081ef5ac(long param_1)

{
  long lVar1;
  
  if ((*(int *)(param_1 + 0x48) != 0) && (*(long *)(param_1 + 0x68) != 0)) {
    lVar1 = *(long *)(param_1 + 0x60);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar1 + 0x40));
    if (0 < *(long *)(lVar1 + 0x38)) {
      if (*(long *)(lVar1 + 0x50) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (*(long *)(lVar1 + 0x58) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      *(long *)(lVar1 + 0x38) = *(long *)(lVar1 + 0x38) + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar1 + 0x40));
    if (*(long **)(param_1 + 0x60) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x60) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x60) = 0;
    lVar1 = *(long *)(param_1 + 0x68);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar1 + 0x40));
    if (0 < *(long *)(lVar1 + 0x38)) {
      if (*(long *)(lVar1 + 0x50) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (*(long *)(lVar1 + 0x58) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      *(long *)(lVar1 + 0x38) = *(long *)(lVar1 + 0x38) + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar1 + 0x40));
    if (*(long **)(param_1 + 0x68) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x68) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined8 *)(param_1 + 0x80) = 0;
    *(undefined4 *)(param_1 + 0x88) = 0;
    lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0x4b0) + 0x910);
    *(undefined8 *)(lVar1 + 0x4060) = 0;
    *(undefined4 *)(lVar1 + 0x4068) = 0;
    *(undefined8 *)(lVar1 + 0x406c) = 0;
    *(undefined4 *)(lVar1 + 0x4074) = 0;
    *(undefined8 *)(lVar1 + 0x404c) = 0;
    *(undefined4 *)(lVar1 + 0x4054) = 0;
    *(undefined8 *)(lVar1 + 0x4058) = 0;
    DataMemoryBarrier(2,3);
  }
  return;
}

