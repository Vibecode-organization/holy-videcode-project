// FUN_fffffff009c21184 @ fffffff009c21184 size=88

void FUN_fffffff009c21184(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = thunk_EXT_FUN_8011000003890f30(param_1,DAT_fffffff0080669f0);
  if (lVar2 == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c211cc);
    (*pcVar1)();
  }
  FUN_fffffff009c16744(lVar2,param_3);
  return;
}

