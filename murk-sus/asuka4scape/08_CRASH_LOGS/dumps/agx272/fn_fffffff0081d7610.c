// FUN_fffffff0081d7610 @ fffffff0081d7610 size=284

void FUN_fffffff0081d7610(long param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  long lVar5;
  ulong unaff_x30;
  
  lVar5 = *(long *)(param_1 + 0x10);
  if (*(int *)(lVar5 + 0xdfbc) == 1) {
    uVar4 = *(uint *)((*(long *)(lVar5 + 0x11568) - *(long *)(lVar5 + 0xe1c8)) + 0xd01010);
  }
  else {
    uVar4 = FUN_fffffff0081f2fb8(lVar5,0xd01010);
  }
  uVar1 = 0;
  if (param_2 == 2) {
    uVar1 = uVar4 | 4;
  }
  uVar2 = uVar4 | 2;
  if (param_2 != 1) {
    uVar2 = uVar1;
  }
  uVar4 = uVar4 | 1;
  if (param_2 != 0) {
    uVar4 = uVar2;
  }
  lVar5 = *(long *)(param_1 + 0x10);
  if (*(int *)(lVar5 + 0xdfbc) != 1) {
    FUN_fffffff0081f4430(lVar5,0xd01010);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081d76d0);
      (*pcVar3)();
    }
    FUN_fffffff0081f2fb8(lVar5,0xd01010);
    return;
  }
  *(uint *)((*(long *)(lVar5 + 0x11568) - *(long *)(lVar5 + 0xe1c8)) + 0xd01010) = uVar4;
  return;
}

