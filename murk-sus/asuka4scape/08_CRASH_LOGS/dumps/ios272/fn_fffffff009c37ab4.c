// FUN_fffffff009c37ab4 @ fffffff009c37ab4 size=92

void FUN_fffffff009c37ab4(long param_1,long param_2)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x3a8));
  *(undefined8 *)(param_2 + 0x10) = 0;
  plVar2 = *(long **)(param_1 + 0x3a0);
  *(long **)(param_2 + 0x18) = plVar2;
  *plVar2 = param_2;
  *(undefined8 **)(param_1 + 0x3a0) = (undefined8 *)(param_2 + 0x10);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c37b0c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x3a8));
  return;
}

