// FUN_fffffff009c334c4 @ fffffff009c334c4 size=132

void FUN_fffffff009c334c4(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  long *plVar4;
  
  lVar3 = *(long *)(param_2 + 0x18);
  if (lVar3 == 0) {
    plVar4 = *(long **)(param_2 + 0x20);
    if (*plVar4 != param_2) goto LAB_fffffff009c33538;
    *(long **)(param_1 + 0x98) = plVar4;
  }
  else {
    if (*(long **)(lVar3 + 0x20) != (long *)(param_2 + 0x18)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c33548);
      (*pcVar2)();
    }
    if (**(long **)(param_2 + 0x20) != param_2) {
LAB_fffffff009c33538:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c33540);
      (*pcVar2)();
    }
    *(long **)(lVar3 + 0x20) = *(long **)(param_2 + 0x20);
    plVar4 = *(long **)(param_2 + 0x20);
  }
  *plVar4 = lVar3;
  uVar1 = *(int *)(param_1 + 0x1e4) - 1;
  *(uint *)(param_1 + 0x1e4) = uVar1;
  if ((uVar1 < 0x4001) && ((*(byte *)(param_1 + 0x1e0) & 1) != 0)) {
    *(undefined1 *)(param_1 + 0x1e0) = 0;
  }
  return;
}

