// FUN_fffffff0099519fc @ fffffff0099519fc size=72

void FUN_fffffff0099519fc(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff009974fa8(*(undefined8 *)(param_1 + 0x20));
  FUN_fffffff009951a44(param_1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009951a40);
    (*pcVar1)();
  }
  FUN_fffffff009974fb4(*(undefined8 *)(param_1 + 0x20));
  return;
}

