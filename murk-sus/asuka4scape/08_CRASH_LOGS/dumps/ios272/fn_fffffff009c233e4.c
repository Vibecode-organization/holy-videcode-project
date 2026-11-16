// FUN_fffffff009c233e4 @ fffffff009c233e4 size=92

bool FUN_fffffff009c233e4(long param_1)

{
  int iVar1;
  
  iVar1 = thunk_EXT_FUN_801100000389060c(param_1 + 0x3b0);
  if (iVar1 == 1) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xfffffff3;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  }
  return iVar1 == 1;
}

