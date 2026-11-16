// FUN_fffffff009c47bf0 @ fffffff009c47bf0 size=172

/* WARNING: Removing unreachable block (ram,0xfffffff009c47c38) */

void FUN_fffffff009c47bf0(long param_1)

{
  code *pcVar1;
  long lVar2;
  long *plVar3;
  ulong unaff_x30;
  
  if ((*(long *)(param_1 + 0x18) != 0) && ((*(byte *)(param_1 + 0x21) & 1) != 0)) {
    thunk_EXT_FUN_801100000389060c(*(long *)(*(long *)(param_1 + 0x18) + 0x178) + 0x24);
    lVar2 = FUN_fffffff009c22264(*(undefined8 *)(param_1 + 0x18));
    if (lVar2 != 0) {
      plVar3 = (long *)FUN_fffffff009c22264(*(undefined8 *)(param_1 + 0x18));
      (**(code **)(*plVar3 + 0xe0))(plVar3,0);
    }
    *(undefined1 *)(param_1 + 0x21) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    FUN_fffffff009c47644(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c47c98);
  (*pcVar1)();
}

