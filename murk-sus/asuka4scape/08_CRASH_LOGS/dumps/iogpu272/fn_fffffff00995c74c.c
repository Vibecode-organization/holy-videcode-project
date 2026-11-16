// FUN_fffffff00995c74c @ fffffff00995c74c size=112

void FUN_fffffff00995c74c(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x58);
  if (lVar2 != 0) {
    *(undefined8 *)(param_1 + 0x58) = 0;
    thunk_EXT_FUN_80110000038fe768
              (&DAT_fffffff007ff1548,lVar2,(ulong)*(uint *)(param_1 + 0x54) << 3);
    *(undefined8 *)(param_1 + 0x58) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995c7b0);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb268)(param_1);
  return;
}

