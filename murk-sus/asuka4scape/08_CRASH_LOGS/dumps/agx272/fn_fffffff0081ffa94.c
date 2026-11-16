// FUN_fffffff0081ffa94 @ fffffff0081ffa94 size=212

void FUN_fffffff0081ffa94(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong uVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  (**(code **)(PTR_DAT_fffffff007ca60d0 + 0xd8))();
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x198));
  if (*(int *)(param_1 + 0x184) != 0) {
    uVar4 = 0;
    do {
      uVar3 = *(ulong *)(param_1 + 400) + uVar4 * 0x40;
      if (((*(ulong *)(param_1 + 400) ^ uVar3) & 0xffc0000000000000) != 0) {
        uVar3 = uVar3 & 0xffffffffffff | 0xc8a2000000000000;
      }
      thunk_EXT_FUN_8011000002947a48(*(undefined8 *)(*(long *)(param_1 + 0x48) + 0x148),uVar3);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0x184));
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x198));
  plVar2 = *(long **)(param_1 + 0x1f0);
  if (plVar2 != (long *)0x0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ffb50);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081ffb58. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar2 + 0x80))(plVar2,(undefined8 *)(*plVar2 + 0x80));
    return;
  }
  return;
}

