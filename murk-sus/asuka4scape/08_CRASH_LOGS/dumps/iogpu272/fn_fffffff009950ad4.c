// FUN_fffffff009950ad4 @ fffffff009950ad4 size=332

void FUN_fffffff009950ad4(long param_1,long *param_2,int param_3)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  
  plVar1 = (long *)*param_2;
  do {
    while( true ) {
      if (plVar1 == (long *)0x0) {
        return;
      }
      plVar6 = (long *)plVar1[0x16];
      if ((plVar1[4] == 0) &&
         (iVar3 = FUN_fffffff00994b9f8(*(undefined8 *)(param_1 + 0x18),plVar1 + 6), iVar3 != 0)) {
        lVar4 = thunk_EXT_FUN_8011000003397c88();
        plVar1[4] = lVar4;
      }
      iVar3 = FUN_fffffff00994b9f8(*(undefined8 *)(param_1 + 0x18),plVar1 + 0xe);
      if (iVar3 != 0) break;
      plVar1 = plVar6;
      if (param_3 == 0) {
        return;
      }
    }
    lVar4 = thunk_EXT_FUN_8011000003397c88();
    plVar1[5] = lVar4;
    lVar4 = plVar1[0x16];
    if (lVar4 == 0) {
      plVar5 = (long *)plVar1[0x17];
      if ((long *)*plVar5 != plVar1) goto LAB_fffffff009950c10;
      param_2[1] = (long)plVar5;
    }
    else {
      if (*(long **)(lVar4 + 0xb8) != plVar1 + 0x16) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009950c20);
        (*pcVar2)();
      }
      if (*(long **)plVar1[0x17] != plVar1) {
LAB_fffffff009950c10:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009950c18);
        (*pcVar2)();
      }
      *(long **)(lVar4 + 0xb8) = (long *)plVar1[0x17];
      plVar5 = (long *)plVar1[0x17];
    }
    *plVar5 = lVar4;
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + -1;
    if (plVar1[0x18] != 0) {
      FUN_fffffff00997a084(plVar1[0x18],plVar1);
      plVar1[0x18] = 0;
    }
    (**(code **)(*plVar1 + 0x80))(plVar1);
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = plVar6;
  } while( true );
}

