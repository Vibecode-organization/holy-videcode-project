// FUN_fffffff00995af14 @ fffffff00995af14 size=268

/* WARNING: Removing unreachable block (ram,0xfffffff00995b0a0) */

void FUN_fffffff00995af14(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    if (*(long *)(param_1 + 0x58) == 0) {
      if (*(long *)(param_1 + 0x98) != 0) {
        thunk_EXT_FUN_8011000003277d90();
        thunk_EXT_FUN_801100000327731c(*(undefined8 *)(param_1 + 0x98));
        *(undefined8 *)(param_1 + 0x98) = 0;
      }
      if (*(long *)(param_1 + 0x68) != 0) {
        thunk_EXT_FUN_80110000038ff020();
        *(undefined8 *)(param_1 + 0x68) = 0;
      }
      if (*(long **)(param_1 + 0x28) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x28) + 0x28))();
      }
      *(undefined8 *)(param_1 + 0x28) = 0;
      if (*(long **)(param_1 + 0x38) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x38) + 0x28))();
      }
      *(undefined8 *)(param_1 + 0x38) = 0;
      if (*(long *)(param_1 + 0xa0) != 0) {
        thunk_EXT_FUN_80110000038ff020();
        *(undefined8 *)(param_1 + 0xa0) = 0;
      }
      if (*(long *)(param_1 + 0x90) != 0) {
        thunk_EXT_FUN_80110000038ff020();
        *(undefined8 *)(param_1 + 0x90) = 0;
      }
      if (*(long *)(param_1 + 0x20) != 0) {
        thunk_EXT_FUN_80110000038ff020();
        *(undefined8 *)(param_1 + 0x20) = 0;
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        (*DAT_fffffff007feb268)(param_1);
        return;
      }
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995b00c);
      (*pcVar1)();
    }
  }
  else {
    FUN_fffffff009983b10();
  }
  plVar2 = (long *)FUN_fffffff009983b40();
  *(undefined4 *)(plVar2 + 2) = 0;
  thunk_EXT_FUN_80110000032222a8(plVar2[4]);
  (**(code **)(*plVar2 + 0x80))(plVar2);
  thunk_EXT_FUN_8011000003222de0(plVar2[4]);
                    /* WARNING: Could not recover jumptable at 0xfffffff00995b0ac. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar2 + 0x28))(plVar2,(undefined8 *)(*plVar2 + 0x28));
  return;
}

