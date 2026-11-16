// FUN_fffffff009942b8c @ fffffff009942b8c size=108

ulong FUN_fffffff009942b8c(long param_1)

{
  code *pcVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  
  if (*(uint *)(param_1 + 0x24) < 4) {
    FUN_fffffff009942c08();
    if (*(int *)(param_1 + 0x24) == 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009942be4);
        (*pcVar1)();
      }
      uVar2 = (*DAT_fffffff007feb270)(param_1);
      return uVar2;
    }
  }
  else {
    FUN_fffffff009983364();
  }
  lVar3 = FUN_fffffff009983394();
  return (ulong)(uint)(*(int *)(lVar3 + 0x24) >> 2);
}

