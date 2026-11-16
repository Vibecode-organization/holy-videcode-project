// FUN_fffffff00997b424 @ fffffff00997b424 size=308

void FUN_fffffff00997b424(long param_1)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  ulong unaff_x30;
  
  lVar3 = 0;
  do {
    plVar1 = (long *)*(long *)(param_1 + 0x18 + lVar3 * 8);
    while (plVar1 != (long *)0x0) {
      lVar4 = *plVar1;
      (**(code **)(*(long *)plVar1[2] + 0x28))();
      plVar1[2] = 0;
      thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff0de8,plVar1);
      plVar1 = (long *)lVar4;
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 0x80);
  if (*(long **)(param_1 + 0x418) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x418) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x418) = 0;
  if (*(long **)(param_1 + 0x420) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x420) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x420) = 0;
  if (*(long **)(param_1 + 0x428) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x428) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x428) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00997b554. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x80))(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997b54c);
  (*pcVar2)();
}

