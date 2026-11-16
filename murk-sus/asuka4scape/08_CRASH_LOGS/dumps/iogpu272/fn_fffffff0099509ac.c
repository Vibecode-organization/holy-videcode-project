// FUN_fffffff0099509ac @ fffffff0099509ac size=272

void FUN_fffffff0099509ac(long param_1)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  long *plVar4;
  long lVar5;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  if (*(int *)(param_1 + 0x70) != 0) {
    lVar5 = *(long *)(param_1 + 0x40);
    while (lVar1 = lVar5, lVar1 != 0) {
      lVar5 = *(long *)(lVar1 + 0x470);
      FUN_fffffff009950ad4(param_1,lVar1 + 0x460,0);
      if (*(long *)(lVar1 + 0x460) == 0) {
        lVar3 = *(long *)(lVar1 + 0x470);
        if (lVar3 == 0) {
          plVar4 = *(long **)(lVar1 + 0x478);
          if (*plVar4 != lVar1) goto LAB_fffffff009950aac;
          *(long **)(param_1 + 0x48) = plVar4;
        }
        else {
          if (*(long **)(lVar3 + 0x478) != (long *)(lVar1 + 0x470)) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009950abc);
            (*pcVar2)();
          }
          if (**(long **)(lVar1 + 0x478) != lVar1) {
LAB_fffffff009950aac:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009950ab4);
            (*pcVar2)();
          }
          *(long **)(lVar3 + 0x478) = *(long **)(lVar1 + 0x478);
          plVar4 = *(long **)(lVar1 + 0x478);
        }
        *plVar4 = lVar3;
      }
    }
    FUN_fffffff009950ad4(param_1,param_1 + 0x50,0);
    FUN_fffffff009950ad4(param_1,param_1 + 0x60,1);
    if (*(int *)(param_1 + 0x74) != 0) {
      thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x20),param_1,0);
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009950aa8);
    (*pcVar2)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
  return;
}

