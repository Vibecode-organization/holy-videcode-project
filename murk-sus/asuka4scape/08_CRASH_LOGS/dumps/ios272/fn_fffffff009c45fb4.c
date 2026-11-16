// FUN_fffffff009c45fb4 @ fffffff009c45fb4 size=280

void FUN_fffffff009c45fb4(long param_1)

{
  code *pcVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x38) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x38) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  if (*(long **)(param_1 + 0x98) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x98) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x98) = 0;
  if (*(long **)(param_1 + 0xa8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xa8) + 0x28))();
  }
  lVar3 = 0;
  *(undefined8 *)(param_1 + 0xa8) = 0;
  lVar4 = 10;
  do {
    plVar2 = *(long **)(param_1 + 0x48 + lVar3 * 8);
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x48 + lVar3 * 8) = 0;
    lVar3 = lVar3 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  if (*(long *)(param_1 + 0x40) != 0) {
    thunk_EXT_FUN_80110000038ff020();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c460c0);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c460c8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
  return;
}

