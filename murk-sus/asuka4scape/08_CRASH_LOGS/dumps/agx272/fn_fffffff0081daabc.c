// FUN_fffffff0081daabc @ fffffff0081daabc size=160

void FUN_fffffff0081daabc(long param_1,int param_2,uint param_3)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x40);
  if (*(int *)(lVar2 + 0xdfbc) == 1) {
    *(uint *)((*(long *)(lVar2 + 0x11568) - *(long *)(lVar2 + 0xe1c8)) + 0xd08030) =
         param_3 | param_2 << 8;
    return;
  }
  FUN_fffffff0081f4430(lVar2,0xd08030);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081dab28);
    (*pcVar1)();
  }
  FUN_fffffff0081f2fb8(lVar2,0xd08030);
  return;
}

