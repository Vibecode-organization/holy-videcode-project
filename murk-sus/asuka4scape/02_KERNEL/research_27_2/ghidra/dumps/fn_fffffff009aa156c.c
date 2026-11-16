// FUN_fffffff009aa156c @ fffffff009aa156c size=176
// CALLERS:
//   fffffff00afb8179 no-fn
// CALLEES:
//   fffffff009abd13c thunk_EXT_FUN_80110000038fe9a0

void FUN_fffffff009aa156c(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x3b8) != 0) {
    thunk_EXT_FUN_80110000038fe9a0
              ("IOMFB: WARNING: FB User Client freed without a stop call! Force releasing memory \n"
              );
    if (*(long **)(param_1 + 0x3b8) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x3b8) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x3b8) = 0;
    if (*(long **)(param_1 + 0x3c0) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x3c0) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x3c0) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009aa1610);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009aa1618. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00802a418 + 0x80))(param_1);
  return;
}

