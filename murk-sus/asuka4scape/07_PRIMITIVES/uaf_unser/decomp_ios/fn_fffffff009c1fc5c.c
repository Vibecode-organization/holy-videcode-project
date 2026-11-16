// FUN_fffffff009c1fc5c @ fffffff009c1fc5c size=108
// CALLERS:
//   fffffff009c33d10 FUN_fffffff009c33c34@fffffff009c33c34

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff009c1fc5c(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff009c495b4(*(undefined8 *)(_DAT_fffffff00af483b0 + 0x140));
  if ((*(uint *)(param_1 + 0x3d0) & 1) == 0) {
    FUN_fffffff009c332f4(_DAT_fffffff00af483b0,param_1);
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 1;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c1fcc4);
    (*pcVar1)();
  }
  FUN_fffffff009c495d4(*(undefined8 *)(_DAT_fffffff00af483b0 + 0x140));
  return;
}

