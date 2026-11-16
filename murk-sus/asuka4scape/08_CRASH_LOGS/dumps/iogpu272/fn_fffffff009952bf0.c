// FUN_fffffff009952bf0 @ fffffff009952bf0 size=172

void FUN_fffffff009952bf0(long param_1,long param_2)

{
  code *pcVar1;
  long *plVar2;
  long lVar3;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x60));
  plVar2 = (long *)(param_2 + 0x38);
  lVar3 = *plVar2;
  if (lVar3 == 0) {
    if (**(long **)(param_2 + 0x40) != param_2) goto LAB_fffffff009952c8c;
    *(long **)(param_1 + 0x40) = *(long **)(param_2 + 0x40);
  }
  else {
    if (*(long **)(lVar3 + 0x40) != plVar2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009952c9c);
      (*pcVar1)();
    }
    if (**(long **)(param_2 + 0x40) != param_2) {
LAB_fffffff009952c8c:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009952c94);
      (*pcVar1)();
    }
    *(long **)(lVar3 + 0x40) = *(long **)(param_2 + 0x40);
  }
  **(long **)(param_2 + 0x40) = *plVar2;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009952c88);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x60));
  return;
}

