// FUN_fffffff0081d70e0 @ fffffff0081d70e0 size=244

void FUN_fffffff0081d70e0(long param_1)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  ulong unaff_x30;
  
  lVar3 = *(long *)(param_1 + 0x10);
  if (*(int *)(lVar3 + 0xdfbc) == 1) {
    uVar2 = *(uint *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd06030);
  }
  else {
    uVar2 = FUN_fffffff0081f2fb8(lVar3,0xd06030);
    lVar3 = *(long *)(param_1 + 0x10);
    if (*(int *)(lVar3 + 0xdfbc) != 1) {
      FUN_fffffff0081f4430(lVar3,0xd06030);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081d7178);
        (*pcVar1)();
      }
      FUN_fffffff0081f2fb8(lVar3,0xd06030);
      return;
    }
  }
  *(uint *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd06030) =
       uVar2 & 0xfffffff9;
  return;
}

