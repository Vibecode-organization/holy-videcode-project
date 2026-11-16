// FUN_fffffff00817f678 @ fffffff00817f678 size=224

undefined8 FUN_fffffff00817f678(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  
  lVar2 = *(long *)(param_1 + 0x28);
  if ((*(byte *)(lVar2 + 0x70) & 1) != 0) {
    lVar3 = *(long *)(param_1 + 0x20);
    lVar4 = *(long *)(lVar2 + 0x60);
    if (lVar4 == 0) {
      plVar5 = *(long **)(lVar2 + 0x68);
      if (*plVar5 != lVar2) goto LAB_fffffff00817f750;
      *(long **)(lVar3 + 0x1aca0) = plVar5;
    }
    else {
      if (*(long **)(lVar4 + 0x68) != (long *)(lVar2 + 0x60)) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817f758);
        (*pcVar1)();
      }
      if (**(long **)(lVar2 + 0x68) != lVar2) {
LAB_fffffff00817f750:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817f754);
        (*pcVar1)();
      }
      *(long **)(lVar4 + 0x68) = *(long **)(lVar2 + 0x68);
      plVar5 = *(long **)(lVar2 + 0x68);
    }
    *plVar5 = lVar4;
    plVar5 = *(long **)(param_1 + 0x28);
    *(undefined1 *)(plVar5 + 0xe) = 0;
    (**(code **)(*plVar5 + 0x28))();
    if (*(long *)(lVar3 + 0x1ac98) == 0) {
      (**(code **)(**(long **)(lVar3 + 0x1ac90) + 0x138))();
    }
  }
  return 0;
}

