// FUN_fffffff0081f7a34 @ fffffff0081f7a34 size=232

void FUN_fffffff0081f7a34(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong uVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  if (*(int *)(param_1 + 0x280) != 0) {
    uVar4 = 0;
    do {
      uVar3 = *(ulong *)(param_1 + 0x290) + uVar4 * 0x58;
      if (((*(ulong *)(param_1 + 0x290) ^ uVar3) & 0xffc0000000000000) != 0) {
        uVar3 = uVar3 & 0xffffffffffff | 0xc8a2000000000000;
      }
      thunk_EXT_FUN_8011000002947a48
                (*(undefined8 *)(*(long *)(param_1 + 0x120) + 0x148),uVar3 + 0x18);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0x280));
  }
  if (*(long **)(param_1 + 0x1c0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1c0) + 0xe8))();
  }
  plVar2 = *(long **)(param_1 + 0x130);
  if (plVar2 != (long *)0x0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f7b00);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081f7b08. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar2 + 0xe8))(plVar2,(undefined8 *)(*plVar2 + 0xe8));
    return;
  }
  return;
}

