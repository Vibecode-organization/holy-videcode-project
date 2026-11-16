// FUN_fffffff0081d74fc @ fffffff0081d74fc size=276

void FUN_fffffff0081d74fc(long *param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  ulong unaff_x30;
  
  iVar2 = (**(code **)(*param_1 + 0xd8))();
  if (iVar2 != 0) {
    lVar3 = param_1[2];
    if (*(int *)(lVar3 + 0xdfbc) == 1) {
      iVar2 = *(int *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd01014);
    }
    else {
      iVar2 = FUN_fffffff0081f2fb8(lVar3,0xd01014);
    }
    if (iVar2 != 0) {
      lVar3 = param_1[2];
      if (*(int *)(lVar3 + 0xdfbc) != 1) {
        FUN_fffffff0081f4430(lVar3,0xd01014);
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081d75b4);
          (*pcVar1)();
        }
        FUN_fffffff0081f2fb8(lVar3,0xd01014);
        return;
      }
      *(int *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd01014) = iVar2;
    }
  }
  return;
}

