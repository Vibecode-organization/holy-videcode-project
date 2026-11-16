// FUN_fffffff00997a248 @ fffffff00997a248 size=80

void FUN_fffffff00997a248(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff00994ba48(*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x498);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997a294);
    (*pcVar1)();
  }
  FUN_fffffff00994ba48(*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x4d8);
  return;
}

