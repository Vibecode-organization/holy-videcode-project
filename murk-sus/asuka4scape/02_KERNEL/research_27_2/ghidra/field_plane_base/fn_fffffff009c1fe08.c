// FUN_fffffff009c1fe08 @ fffffff009c1fe08

/* WARNING: Removing unreachable block (ram,0xfffffff009c1fe94) */

void FUN_fffffff009c1fe08(long param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long *plVar3;
  undefined8 *puVar4;
  
  if (*(long *)(param_2 + 0x40) != 0) {
    lVar2 = *(long *)(param_2 + 0x30);
    if (lVar2 == 0) {
      plVar3 = *(long **)(param_2 + 0x38);
      if (*plVar3 != param_2) goto LAB_fffffff009c1fea4;
      *(long **)(*(long *)(param_2 + 0x40) + 8) = plVar3;
    }
    else {
      if (*(long **)(lVar2 + 0x38) != (long *)(param_2 + 0x30)) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c1feb4);
        (*pcVar1)();
      }
      if (**(long **)(param_2 + 0x38) != param_2) {
LAB_fffffff009c1fea4:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c1feac);
        (*pcVar1)();
      }
      *(long **)(lVar2 + 0x38) = *(long **)(param_2 + 0x38);
      plVar3 = *(long **)(param_2 + 0x38);
    }
    *plVar3 = lVar2;
  }
  if (*(long *)(param_1 + 0x38) == param_2) {
    *(undefined8 *)(param_1 + 0x38) = 0;
    puVar4 = *(undefined8 **)(param_1 + 0x178);
    *(undefined2 *)(puVar4 + 1) = 0;
    *puVar4 = 0;
    return;
  }
  return;
}

