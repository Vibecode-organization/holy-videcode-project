// FUN_fffffff0099590f0 @ fffffff0099590f0 size=144

/* WARNING: Removing unreachable block (ram,0xfffffff009959200) */

void FUN_fffffff0099590f0(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x40) != 0) {
    plVar2 = (long *)FUN_fffffff009983a94();
    *(undefined4 *)(plVar2 + 2) = 0;
    thunk_EXT_FUN_80110000032222a8(plVar2[3]);
    (**(code **)(*plVar2 + 0x80))(plVar2);
    thunk_EXT_FUN_8011000003222de0(plVar2[3]);
                    /* WARNING: Could not recover jumptable at 0xfffffff00995920c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar2 + 0x28))(plVar2,(undefined8 *)(*plVar2 + 0x28));
    return;
  }
  if (*(long **)(param_1 + 0x50) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x50) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x50) = 0;
  if (*(long *)(param_1 + 0x18) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x18) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    (*DAT_fffffff007feb268)(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009959170);
  (*pcVar1)();
}

