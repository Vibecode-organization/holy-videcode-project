// FUN_fffffff0099605fc @ fffffff0099605fc size=84

void FUN_fffffff0099605fc(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if ((*(byte *)(*(long *)(param_1 + 0x1a8) + 0x238) >> 6 & 1) == 0) {
    FUN_fffffff009950f84(*(undefined8 *)(*(long *)(param_1 + 0x1a8) + 0x158));
  }
  FUN_fffffff009960650(param_1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996064c);
    (*pcVar1)();
  }
  FUN_fffffff009960834(param_1);
  return;
}

