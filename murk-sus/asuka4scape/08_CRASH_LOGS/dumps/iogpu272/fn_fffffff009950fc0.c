// FUN_fffffff009950fc0 @ fffffff009950fc0 size=216

void FUN_fffffff009950fc0(long param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  lVar2 = *(long *)(param_2 + 0x460);
  if (lVar2 != 0) {
    lVar3 = *(long *)(param_2 + 0x470);
    if (lVar3 == 0) {
      plVar4 = *(long **)(param_2 + 0x478);
      if (*plVar4 != param_2) goto LAB_fffffff009951088;
      *(long **)(param_1 + 0x48) = plVar4;
    }
    else {
      if (*(long *)(lVar3 + 0x478) != param_2 + 0x470) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009951098);
        (*pcVar1)();
      }
      if (**(long **)(param_2 + 0x478) != param_2) {
LAB_fffffff009951088:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009951090);
        (*pcVar1)();
      }
      *(long **)(lVar3 + 0x478) = *(long **)(param_2 + 0x478);
      plVar4 = *(long **)(param_2 + 0x478);
    }
    *plVar4 = lVar3;
    plVar4 = *(long **)(param_1 + 0x58);
    *plVar4 = lVar2;
    *(long **)(*(long *)(param_2 + 0x460) + 0xb8) = plVar4;
    *(undefined8 *)(param_1 + 0x58) = *(undefined8 *)(param_2 + 0x468);
    *(undefined8 *)(param_2 + 0x460) = 0;
    *(long *)(param_2 + 0x468) = param_2 + 0x460;
    do {
      *(undefined8 *)(lVar2 + 0xc0) = 0;
      lVar2 = *(long *)(lVar2 + 0xb0);
    } while (lVar2 != 0);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009951084);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
  return;
}

