// FUN_fffffff00996ecc0 @ fffffff00996ecc0 size=100

void FUN_fffffff00996ecc0(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x30);
  if (lVar2 != 0) {
    *(undefined8 *)(param_1 + 0x30) = 0;
    thunk_EXT_FUN_80110000038fe6b0(lVar2,(ulong)*(uint *)(param_1 + 0x3c) << 4);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996ed18);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb268)(param_1);
  return;
}

