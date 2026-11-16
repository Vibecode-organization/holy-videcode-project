// FUN_fffffff009c332f4 @ fffffff009c332f4 size=220

void FUN_fffffff009c332f4(long param_1,long param_2)

{
  int iVar1;
  code *pcVar2;
  long *plVar3;
  long lVar4;
  
  plVar3 = (long *)(param_1 + 0x90);
  lVar4 = *plVar3;
  if (lVar4 == 0) {
    *(undefined8 *)(param_2 + 0x18) = 0;
    *(undefined8 **)(param_1 + 0x98) = (undefined8 *)(param_2 + 0x18);
  }
  else {
    if (*(long **)(lVar4 + 0x20) != plVar3) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c333d0);
      (*pcVar2)();
    }
    *(long *)(param_2 + 0x18) = lVar4;
    *(long **)(lVar4 + 0x20) = (long *)(param_2 + 0x18);
  }
  *(long *)(param_1 + 0x90) = param_2;
  *(long **)(param_2 + 0x20) = plVar3;
  iVar1 = *(int *)(param_1 + 0x1e4);
  *(int *)(param_1 + 0x1e4) = iVar1 + 1;
  if ((iVar1 - 0xfdffU < 0x201) && ((*(byte *)(param_1 + 0x1e0) & 1) == 0)) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,
               "IOSurface count of %d approaching limit of %d\n");
    thunk_EXT_FUN_80110000038fe9a0("IOSurface count of %d approaching limit of %d\n");
    FUN_fffffff009c333d0(param_1);
    *(undefined1 *)(param_1 + 0x1e0) = 1;
  }
  return;
}

