// FUN_fffffff0081dab5c @ fffffff0081dab5c size=1324

void FUN_fffffff0081dab5c(long *param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  lVar3 = param_1[8];
  if (*(int *)(lVar3 + 0xdfbc) == 1) {
    iVar2 = *(int *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd08000);
  }
  else {
    iVar2 = FUN_fffffff0081f2fb8(lVar3,0xd08000);
  }
  if (iVar2 == 0) {
    (**(code **)(*param_1 + 0x90))(param_1);
    uVar4 = thunk_EXT_FUN_80110000039788dc();
    lVar3 = param_1[8];
    if (*(int *)(lVar3 + 0xdfbc) == 1) {
      *(uint *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd0802c) =
           (uint)(uVar4 >> 0xe) & 0x3ffffff;
    }
    else {
      FUN_fffffff0081f4430(lVar3,0xd0802c);
      FUN_fffffff0081f2fb8(lVar3,0xd0802c);
      lVar3 = param_1[8];
    }
    if (*(int *)(lVar3 + 0xdfbc) == 1) {
      *(undefined4 *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd08014) = 0x80d8;
    }
    else {
      FUN_fffffff0081f4430(lVar3,0xd08014,0x80d8);
      FUN_fffffff0081f2fb8(lVar3,0xd08014);
      lVar3 = param_1[8];
    }
    if (*(int *)(lVar3 + 0xdfbc) == 1) {
      *(undefined4 *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd08018) = 0x80d8;
    }
    else {
      FUN_fffffff0081f4430(lVar3,0xd08018,0x80d8);
      FUN_fffffff0081f2fb8(lVar3,0xd08018);
      lVar3 = param_1[8];
    }
    if (*(int *)(lVar3 + 0xdfbc) == 1) {
      *(undefined4 *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd0800c) = 0;
    }
    else {
      FUN_fffffff0081f4430(lVar3,0xd0800c,0);
      FUN_fffffff0081f2fb8(lVar3,0xd0800c);
      lVar3 = param_1[8];
    }
    if (*(int *)(lVar3 + 0xdfbc) == 1) {
      *(undefined4 *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd08010) = 0;
    }
    else {
      FUN_fffffff0081f4430(lVar3,0xd08010,0);
      FUN_fffffff0081f2fb8(lVar3,0xd08010);
      lVar3 = param_1[8];
    }
    if (*(int *)(lVar3 + 0xdfbc) == 1) {
      *(undefined4 *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd0801c) = 0;
    }
    else {
      FUN_fffffff0081f4430(lVar3,0xd0801c,0);
      FUN_fffffff0081f2fb8(lVar3,0xd0801c);
      lVar3 = param_1[8];
    }
    if (*(int *)(lVar3 + 0xdfbc) == 1) {
      *(undefined4 *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd08020) = 0;
    }
    else {
      FUN_fffffff0081f4430(lVar3,0xd08020,0);
      FUN_fffffff0081f2fb8(lVar3,0xd08020);
      lVar3 = param_1[8];
    }
    if (*(int *)(lVar3 + 0xdfbc) == 1) {
      *(undefined4 *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd08024) = 0;
    }
    else {
      FUN_fffffff0081f4430(lVar3,0xd08024,0);
      FUN_fffffff0081f2fb8(lVar3,0xd08024);
      lVar3 = param_1[8];
    }
    if (*(int *)(lVar3 + 0xdfbc) == 1) {
      *(undefined4 *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd08028) = 0;
    }
    else {
      FUN_fffffff0081f4430(lVar3,0xd08028,0);
      FUN_fffffff0081f2fb8(lVar3,0xd08028);
      lVar3 = param_1[8];
    }
    if (*(int *)(lVar3 + 0xdfbc) == 1) {
      *(undefined4 *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd08008) = 1;
    }
    else {
      FUN_fffffff0081f4430(lVar3,0xd08008,1);
      FUN_fffffff0081f2fb8(lVar3,0xd08008);
      lVar3 = param_1[8];
    }
    if (*(int *)(lVar3 + 0xdfbc) == 1) {
      *(undefined4 *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd08004) = 0x3ff;
    }
    else {
      FUN_fffffff0081f4430(lVar3,0xd08004,0x3ff);
      FUN_fffffff0081f2fb8(lVar3,0xd08004);
      lVar3 = param_1[8];
    }
    if (*(int *)(lVar3 + 0xdfbc) != 1) {
      FUN_fffffff0081f4430(lVar3,0xd08000,1);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        FUN_fffffff0081f2fb8(lVar3,0xd08000);
        return;
      }
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081dae90);
      (*pcVar1)();
    }
    *(undefined4 *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd08000) = 1;
  }
  return;
}

