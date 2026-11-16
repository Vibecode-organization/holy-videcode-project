// FUN_fffffff009c32a2c @ fffffff009c32a2c size=1

void FUN_fffffff009c32a2c(long param_1)

{
  long *plVar1;
  code *pcVar2;
  long **pplVar3;
  long *plVar4;
  long **pplVar5;
  undefined8 *puVar6;
  long *plStack_38;
  long **pplStack_30;
  long lStack_28;
  
  lStack_28 = *(long *)PTR_DAT_fffffff00806ca40;
  pplStack_30 = &plStack_38;
  plStack_38 = (long *)0x0;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1c8));
  plVar1 = *(long **)(param_1 + 0x1d0);
  while (plVar1 != (long *)0x0) {
    pplVar5 = (long **)(plVar1 + 0xf);
    plVar4 = *pplVar5;
    if (plVar4 == (long *)0x0) {
      puVar6 = (undefined8 *)plVar1[0x10];
      if ((long *)*puVar6 != plVar1) goto LAB_fffffff009c32b8c;
      *(undefined8 **)(param_1 + 0x1d8) = puVar6;
    }
    else {
      if ((long **)plVar4[0x10] != pplVar5) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c32b9c);
        (*pcVar2)();
      }
      if (*(long **)plVar1[0x10] != plVar1) {
LAB_fffffff009c32b8c:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c32b90);
        (*pcVar2)();
      }
      plVar4[0x10] = (long)plVar1[0x10];
      puVar6 = (undefined8 *)plVar1[0x10];
    }
    *puVar6 = plVar4;
    *pplVar5 = (long *)0x0;
    plVar1[0x10] = 0;
    plVar1[0x10] = (long)pplStack_30;
    *pplStack_30 = plVar1;
    plVar1 = plVar4;
    pplStack_30 = pplVar5;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1c8));
  plVar1 = plStack_38;
  do {
    if (plVar1 == (long *)0x0) {
      if (*(long *)PTR_DAT_fffffff00806ca40 != lStack_28) {
        thunk_EXT_FUN_8011000003a48590();
        return;
      }
      return;
    }
    plVar4 = (long *)plVar1[0xf];
    if (plVar4 == (long *)0x0) {
      pplVar3 = (long **)plVar1[0x10];
      pplVar5 = pplVar3;
      if (*pplVar3 != plVar1) goto LAB_fffffff009c32b90;
    }
    else {
      if ((long *)plVar4[0x10] != plVar1 + 0xf) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c32ba4);
        (*pcVar2)();
      }
      if (*(long **)plVar1[0x10] != plVar1) {
LAB_fffffff009c32b90:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c32b98);
        (*pcVar2)();
      }
      plVar4[0x10] = (long)plVar1[0x10];
      pplVar3 = (long **)plVar1[0x10];
      pplVar5 = pplStack_30;
    }
    pplStack_30 = pplVar5;
    *pplVar3 = plVar4;
    FUN_fffffff009c26c38(plVar1[2]);
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = plVar4;
  } while( true );
}

