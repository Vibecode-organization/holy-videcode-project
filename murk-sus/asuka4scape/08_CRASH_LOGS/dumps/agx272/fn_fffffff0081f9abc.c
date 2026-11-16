// FUN_fffffff0081f9abc @ fffffff0081f9abc size=68

undefined8 FUN_fffffff0081f9abc(long param_1)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  if (param_1 != 0) {
    lVar2 = thunk_EXT_FUN_8011000003890f30(param_1,&DAT_fffffff00ae21bd0);
    if (lVar2 != 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f9af4);
        (*pcVar1)();
      }
      uVar3 = thunk_EXT_FUN_801100000297dd00();
      return uVar3;
    }
  }
  return 0;
}

