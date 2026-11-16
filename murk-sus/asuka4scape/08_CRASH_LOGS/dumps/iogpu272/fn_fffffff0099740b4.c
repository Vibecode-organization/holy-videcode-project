// FUN_fffffff0099740b4 @ fffffff0099740b4 size=72

void FUN_fffffff0099740b4(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar2 = thunk_EXT_FUN_8011000002c1e264(param_2);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099740f8);
    (*pcVar1)();
  }
  FUN_fffffff0099811cc(param_1,0,uVar2);
  return;
}

