// FUN_fffffff009963e2c @ fffffff009963e2c size=336

void FUN_fffffff009963e2c(long param_1)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  ulong unaff_x30;
  
  plVar1 = (long *)*(long *)(param_1 + 0x20);
  while (plVar1 != (long *)0x0) {
    lVar3 = *plVar1;
    if ((long *)plVar1[3] != (long *)0x0) {
      (**(code **)(*(long *)plVar1[3] + 0x28))();
    }
    plVar1[3] = 0;
    if ((long *)plVar1[2] != (long *)0x0) {
      (**(code **)(*(long *)plVar1[2] + 0x28))();
    }
    plVar1[2] = 0;
    if ((long *)plVar1[1] != (long *)0x0) {
      (**(code **)(*(long *)plVar1[1] + 0x28))();
    }
    plVar1[1] = 0;
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff0768,plVar1);
    plVar1 = (long *)lVar3;
  }
  if (*(long *)(param_1 + 0x40) != 0) {
    thunk_EXT_FUN_80110000038fe6b0(*(long *)(param_1 + 0x40),*(uint *)(param_1 + 0x50) >> 3);
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  if (*(long **)(param_1 + 0x38) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x38) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  if (*(long *)(param_1 + 0x48) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x48) = 0;
  }
  if (*(long *)(param_1 + 0x18) != 0) {
    thunk_EXT_FUN_801100000326c730();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009963f70);
    (*pcVar2)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009963f78. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x80))(param_1);
  return;
}

