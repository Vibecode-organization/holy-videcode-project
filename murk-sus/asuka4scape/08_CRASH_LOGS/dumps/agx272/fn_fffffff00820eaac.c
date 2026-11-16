// FUN_fffffff00820eaac @ fffffff00820eaac size=216

void FUN_fffffff00820eaac(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  if (*(int *)(param_1 + 0x18) != -1) {
    lVar2 = *(long *)(param_1 + 0x30);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar2 + 0x40));
    if (0 < *(long *)(lVar2 + 0x38)) {
      if (*(long *)(lVar2 + 0x50) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (*(long *)(lVar2 + 0x58) != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      *(long *)(lVar2 + 0x38) = *(long *)(lVar2 + 0x38) + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x40));
    if (*(long **)(param_1 + 0x30) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x30) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x30) = 0;
    FUN_fffffff0081b6fc4
              (*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x4b0),*(undefined4 *)(param_1 + 0x18));
  }
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00820eb78);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00820eb80. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

