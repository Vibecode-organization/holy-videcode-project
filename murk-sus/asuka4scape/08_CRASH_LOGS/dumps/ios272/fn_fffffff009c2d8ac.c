// FUN_fffffff009c2d8ac @ fffffff009c2d8ac size=184

void FUN_fffffff009c2d8ac(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x10) != 0) {
    if (((*(long *)(param_1 + 0x18) != 0) && (*(code **)(param_1 + 0x28) != (code *)0x0)) &&
       (*(long *)(param_1 + 0x20) != 0)) {
      (**(code **)(param_1 + 0x28))(*(long *)(param_1 + 0x18),param_1,4,0,0);
    }
    if ((*(byte *)(param_1 + 0x59) & 1) == 0) {
      FUN_fffffff009c1fe08(*(undefined8 *)(param_1 + 0x10),param_1);
      (**(code **)(**(long **)(param_1 + 0x10) + 0x28))();
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2d958);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c2d960. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
  return;
}

