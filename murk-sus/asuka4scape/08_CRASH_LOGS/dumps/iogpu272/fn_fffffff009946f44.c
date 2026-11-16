// FUN_fffffff009946f44 @ fffffff009946f44 size=300

void FUN_fffffff009946f44(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x120) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x120) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x120) = 0;
  if (*(long **)(param_1 + 0x110) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x110) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x110) = 0;
  if (*(long **)(param_1 + 0x108) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x108) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x108) = 0;
  plVar2 = *(long **)(param_1 + 0xd8);
  if (plVar2 != (long *)0x0) {
    if ((long *)plVar2[1] != (long *)0x0) {
      (**(code **)(*(long *)plVar2[1] + 0x28))();
      plVar2 = *(long **)(param_1 + 0xd8);
    }
    plVar2[1] = 0;
    if (*plVar2 != 0) {
      thunk_EXT_FUN_801100000326c730();
      **(undefined8 **)(param_1 + 0xd8) = 0;
    }
    *(undefined8 *)(param_1 + 0xd8) = 0;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff0068);
  }
  if (*(long *)(param_1 + 0xf0) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0xf0) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009947064);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00994706c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ff27d0 + 0x80))(param_1);
  return;
}

