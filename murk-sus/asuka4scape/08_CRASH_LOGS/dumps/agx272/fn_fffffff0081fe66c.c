// FUN_fffffff0081fe66c @ fffffff0081fe66c size=132

void FUN_fffffff0081fe66c(long param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  if ((DAT_fffffff00ae25928 & 1) == 0) {
    uVar2 = FUN_fffffff0082110f8(*(undefined8 *)(*(long *)(param_1 + 0x2d0) + 0x18));
  }
  else {
    uVar2 = (**(code **)(**(long **)(*(long *)(param_1 + 0x2d0) + 0x10) + 0x80))();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081fe6ec);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000002979258(param_2,uVar2,0,"Page Tables");
  return;
}

