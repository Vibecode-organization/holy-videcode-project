// FUN_fffffff009958c98 @ fffffff009958c98 size=120

void FUN_fffffff009958c98(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  *(undefined4 *)(param_1 + 0x28) = 0;
  if (*(long **)(param_1 + 0x10) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x10) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x10) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009958d04);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb268)(param_1);
  return;
}

