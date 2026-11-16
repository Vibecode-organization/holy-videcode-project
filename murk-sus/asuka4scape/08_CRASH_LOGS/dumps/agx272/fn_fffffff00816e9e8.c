// FUN_fffffff00816e9e8 @ fffffff00816e9e8 size=168

void FUN_fffffff00816e9e8(long param_1)

{
  code *pcVar1;
  ulong uVar2;
  ulong unaff_x30;
  
  if ((((*(byte *)(param_1 + 0x5b8) & 1) == 0) && ((*(byte *)(param_1 + 0x5a0) & 1) == 0)) &&
     (uVar2 = thunk_EXT_FUN_801100000294780c(*(undefined8 *)(param_1 + 0x148)), (uVar2 & 1) == 0)) {
    (**(code **)(**(long **)(param_1 + 0x4b0) + 0x3b8))();
    *(undefined1 *)(param_1 + 0x5b8) = 1;
    thunk_EXT_FUN_8011000003204ed8(*(undefined4 *)(param_1 + 0x23c),1000000000,param_1 + 0x5c0);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00816ea8c);
      (*pcVar1)();
    }
    thunk_EXT_FUN_801100000295f33c
              (*(undefined8 *)(param_1 + 0x160),*(undefined8 *)(param_1 + 0x5c0));
    return;
  }
  return;
}

