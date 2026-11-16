// FUN_fffffff0081e04bc @ fffffff0081e04bc size=284

void FUN_fffffff0081e04bc(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x50) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x50) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x50) = 0;
  if (*(long **)(param_1 + 0x58) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x58) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x58) = 0;
  if (*(long *)(param_1 + 0x60) != 0) {
    LOAcquire();
    DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 - *(long *)(param_1 + 0x30);
    LORelease();
    if (*(long **)(param_1 + 0x60) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x60) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x60) = 0;
  }
  if (*(long **)(param_1 + 0x48) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x48) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  if (*(long *)(param_1 + 0x40) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e05cc);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081e05d4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca60e0 + 0x80))(param_1);
  return;
}

