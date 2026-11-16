// FUN_fffffff00818a7b0 @ fffffff00818a7b0 size=136

void FUN_fffffff00818a7b0(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x30) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x30) + 0x28))();
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  if (*(long **)(param_1 + 0x278) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x278) + 0x28))();
    *(undefined8 *)(param_1 + 0x278) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00818a834);
    (*pcVar1)();
  }
  FUN_fffffff00816b2a8(*(undefined8 *)(param_1 + 0x18));
  return;
}

