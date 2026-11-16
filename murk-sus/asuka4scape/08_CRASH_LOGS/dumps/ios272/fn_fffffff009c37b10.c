// FUN_fffffff009c37b10 @ fffffff009c37b10 size=160

void FUN_fffffff009c37b10(long param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long *plVar3;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x3a8));
  lVar2 = *(long *)(param_2 + 0x10);
  if (lVar2 == 0) {
    plVar3 = *(long **)(param_2 + 0x18);
    if (*plVar3 != param_2) goto LAB_fffffff009c37ba0;
    *(long **)(param_1 + 0x3a0) = plVar3;
  }
  else {
    if (*(long **)(lVar2 + 0x18) != (long *)(param_2 + 0x10)) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c37bb0);
      (*pcVar1)();
    }
    if (**(long **)(param_2 + 0x18) != param_2) {
LAB_fffffff009c37ba0:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c37ba8);
      (*pcVar1)();
    }
    *(long **)(lVar2 + 0x18) = *(long **)(param_2 + 0x18);
    plVar3 = *(long **)(param_2 + 0x18);
  }
  *plVar3 = lVar2;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c37b9c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x3a8));
  return;
}

