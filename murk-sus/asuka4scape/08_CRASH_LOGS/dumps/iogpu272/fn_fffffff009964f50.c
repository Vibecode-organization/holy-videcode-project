// FUN_fffffff009964f50 @ fffffff009964f50 size=136

void FUN_fffffff009964f50(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x48);
  if (lVar2 != 0) {
    if (*(int *)(param_1 + 100) != 0) {
      FUN_fffffff009944a04(*(undefined8 *)(lVar2 + 0x1c8));
      lVar2 = *(long *)(param_1 + 0x48);
      if (lVar2 == 0) goto LAB_fffffff009964f94;
    }
    FUN_fffffff00994cca8(*(undefined8 *)(lVar2 + 0x148),param_1);
  }
LAB_fffffff009964f94:
  if (*(long *)(param_1 + 0x58) != 0) {
    FUN_fffffff009970a14(*(long *)(param_1 + 0x58),0);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009964fcc);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb270)(param_1);
  return;
}

