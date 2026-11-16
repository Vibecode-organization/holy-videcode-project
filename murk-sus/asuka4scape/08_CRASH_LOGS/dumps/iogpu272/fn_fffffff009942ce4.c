// FUN_fffffff009942ce4 @ fffffff009942ce4 size=140

void FUN_fffffff009942ce4(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x58);
  if (lVar2 != 0) {
    lVar3 = (long)(int)*(uint *)(param_1 + 0x50) << 3;
    if (0x7fffffff < *(uint *)(param_1 + 0x50)) {
      lVar3 = -0x8000000000000000;
    }
    *(undefined8 *)(param_1 + 0x58) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1048,lVar2,lVar3);
    *(undefined8 *)(param_1 + 0x58) = 0;
  }
  if (*(long *)(param_1 + 0x48) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x48) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009942d64);
    (*pcVar1)();
  }
  (*DAT_fffffff007feb268)(param_1);
  return;
}

