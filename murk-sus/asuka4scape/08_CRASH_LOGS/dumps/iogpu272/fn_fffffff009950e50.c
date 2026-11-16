// FUN_fffffff009950e50 @ fffffff009950e50 size=276

void FUN_fffffff009950e50(long param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long *plVar4;
  long lVar5;
  long *plVar6;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  if (*(int *)(param_1 + 0x70) != 0) {
    lVar5 = *(long *)(param_1 + 0x40);
    while (lVar5 != 0) {
      plVar4 = (long *)(lVar5 + 0x460);
      lVar5 = *(long *)(lVar5 + 0x470);
      plVar4 = (long *)*plVar4;
      while (plVar4 != (long *)0x0) {
        plVar6 = (long *)plVar4[0x16];
        uVar3 = (**(code **)(*plVar4 + 0x88))(plVar4,param_2);
        plVar4 = plVar6;
        if ((uVar3 & 1) != 0) goto LAB_fffffff009950f40;
      }
    }
    plVar4 = *(long **)(param_1 + 0x50);
    do {
      if (plVar4 == (long *)0x0) {
        plVar4 = *(long **)(param_1 + 0x60);
        goto LAB_fffffff009950f0c;
      }
      plVar6 = (long *)plVar4[0x16];
      uVar3 = (**(code **)(*plVar4 + 0x88))(plVar4,param_2);
      plVar4 = plVar6;
    } while ((uVar3 & 1) == 0);
  }
  goto LAB_fffffff009950f40;
  while( true ) {
    plVar6 = (long *)plVar4[0x16];
    iVar2 = (**(code **)(*plVar4 + 0x88))(plVar4,param_2);
    plVar4 = plVar6;
    if (iVar2 != 0) break;
LAB_fffffff009950f0c:
    if (plVar4 == (long *)0x0) break;
  }
LAB_fffffff009950f40:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009950f60);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
  return;
}

