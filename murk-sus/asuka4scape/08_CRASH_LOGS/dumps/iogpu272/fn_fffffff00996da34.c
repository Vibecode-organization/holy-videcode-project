// FUN_fffffff00996da34 @ fffffff00996da34 size=84

void FUN_fffffff00996da34(undefined8 param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  ulong unaff_x30;
  
  iVar2 = FUN_fffffff00996d708();
  if (iVar2 == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996da78);
    (*pcVar1)();
  }
  FUN_fffffff00996d884(param_1,*(undefined8 *)(param_2 + 0x18));
  return;
}

