// FUN_fffffff009950198 @ fffffff009950198 size=640

void FUN_fffffff009950198(long param_1)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  ulong unaff_x30;
  
  lVar5 = *(long *)(param_1 + 0x28);
  while (lVar5 != 0) {
    lVar4 = *(long *)(lVar5 + 0x50);
    if (lVar4 == 0) {
      plVar2 = *(long **)(lVar5 + 0x58);
      if (*plVar2 != lVar5) goto LAB_fffffff0099503e8;
      *(long **)(param_1 + 0x30) = plVar2;
    }
    else {
      if (*(long **)(lVar4 + 0x58) != (long *)(lVar5 + 0x50)) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009950408);
        (*pcVar1)();
      }
      if (**(long **)(lVar5 + 0x58) != lVar5) {
LAB_fffffff0099503e8:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0099503f0);
        (*pcVar1)();
      }
      *(long **)(lVar4 + 0x58) = *(long **)(lVar5 + 0x58);
      plVar2 = *(long **)(lVar5 + 0x58);
    }
    *plVar2 = lVar4;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff0368);
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
    lVar5 = lVar4;
  }
  lVar5 = *(long *)(param_1 + 0x40);
  while (lVar4 = lVar5, lVar4 != 0) {
    lVar5 = *(long *)(lVar4 + 0x470);
    if (lVar5 == 0) {
      plVar2 = *(long **)(lVar4 + 0x478);
      if (*plVar2 != lVar4) goto LAB_fffffff0099503f8;
      *(long **)(param_1 + 0x48) = plVar2;
    }
    else {
      if (*(long *)(lVar5 + 0x478) != lVar4 + 0x470) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009950418);
        (*pcVar1)();
      }
      if (**(long **)(lVar4 + 0x478) != lVar4) {
LAB_fffffff0099503f8:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009950400);
        (*pcVar1)();
      }
      *(long **)(lVar5 + 0x478) = *(long **)(lVar4 + 0x478);
      plVar2 = *(long **)(lVar4 + 0x478);
    }
    *plVar2 = lVar5;
    plVar2 = *(long **)(lVar4 + 0x460);
    while (plVar2 != (long *)0x0) {
      plVar6 = (long *)plVar2[0x16];
      if (plVar6 == (long *)0x0) {
        plVar3 = (long *)plVar2[0x17];
        if ((long *)*plVar3 != plVar2) goto LAB_fffffff0099503d8;
        *(long **)(lVar4 + 0x468) = plVar3;
      }
      else {
        if ((long *)plVar6[0x17] != plVar2 + 0x16) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0099503e8);
          (*pcVar1)();
        }
        if (*(long **)plVar2[0x17] != plVar2) {
LAB_fffffff0099503d8:
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0099503e0);
          (*pcVar1)();
        }
        plVar6[0x17] = (long)plVar2[0x17];
        plVar3 = (long *)plVar2[0x17];
      }
      *plVar3 = (long)plVar6;
      (**(code **)(*plVar2 + 0x28))();
      *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + -1;
      plVar2 = plVar6;
    }
  }
  plVar2 = *(long **)(param_1 + 0x50);
  do {
    if (plVar2 == (long *)0x0) {
      if (*(long *)(param_1 + 0x20) != 0) {
        thunk_EXT_FUN_80110000038ff020();
        *(undefined8 *)(param_1 + 0x20) = 0;
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0099503d4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x80))(param_1);
        return;
      }
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099503cc);
      (*pcVar1)();
    }
    plVar6 = (long *)plVar2[0x16];
    if (plVar6 == (long *)0x0) {
      plVar3 = (long *)plVar2[0x17];
      if ((long *)*plVar3 != plVar2) goto LAB_fffffff0099503f0;
      *(long **)(param_1 + 0x58) = plVar3;
    }
    else {
      if ((long *)plVar6[0x17] != plVar2 + 0x16) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009950410);
        (*pcVar1)();
      }
      if (*(long **)plVar2[0x17] != plVar2) {
LAB_fffffff0099503f0:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0099503f8);
        (*pcVar1)();
      }
      plVar6[0x17] = (long)plVar2[0x17];
      plVar3 = (long *)plVar2[0x17];
    }
    *plVar3 = (long)plVar6;
    (**(code **)(*plVar2 + 0x28))();
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + -1;
    plVar2 = plVar6;
  } while( true );
}

