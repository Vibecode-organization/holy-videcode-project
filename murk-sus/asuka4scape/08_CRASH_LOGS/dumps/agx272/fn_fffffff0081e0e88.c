// FUN_fffffff0081e0e88 @ fffffff0081e0e88 size=156

void FUN_fffffff0081e0e88(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(int *)(param_1 + 0x28) != 0) {
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Verification failed: %s\n");
    return;
  }
  if (*(long *)(param_1 + 0x18) != 0) {
    thunk_EXT_FUN_80110000038ff020(*(long *)(param_1 + 0x18));
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e0ee8);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081e0ef0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

