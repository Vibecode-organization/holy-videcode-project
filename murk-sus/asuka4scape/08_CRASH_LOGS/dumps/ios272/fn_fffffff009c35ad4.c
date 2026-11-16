// FUN_fffffff009c35ad4 @ fffffff009c35ad4 size=236

void FUN_fffffff009c35ad4(long param_1,long param_2)

{
  long *plVar1;
  code *pcVar2;
  long *plVar3;
  long *plVar4;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x150));
  *(undefined1 *)(param_2 + 0xf1) = 1;
  plVar4 = *(long **)(param_1 + 0x188);
  do {
    do {
      plVar1 = plVar4;
      if (plVar1 == (long *)0x0) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x150));
          return;
        }
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c35bac);
        (*pcVar2)();
      }
      plVar4 = (long *)*plVar1;
    } while (plVar1[0xb] != param_2);
    if (plVar4 == (long *)0x0) {
      plVar3 = (long *)plVar1[1];
      if ((long *)*plVar3 != plVar1) goto LAB_fffffff009c35bb0;
      *(long **)(param_1 + 400) = plVar3;
    }
    else {
      if ((long *)plVar4[1] != plVar1) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c35bc0);
        (*pcVar2)();
      }
      if (*(long **)plVar1[1] != plVar1) {
LAB_fffffff009c35bb0:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c35bb8);
        (*pcVar2)();
      }
      plVar4[1] = (long)plVar1[1];
      plVar3 = (long *)plVar1[1];
    }
    *plVar3 = (long)plVar4;
    thunk_EXT_FUN_80110000039a3d30(plVar1 + 2);
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806b370,plVar1);
  } while( true );
}

