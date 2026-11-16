// FUN_fffffff009c32ba8 @ fffffff009c32ba8 size=652

void FUN_fffffff009c32ba8(long param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  ulong unaff_x30;
  
  FUN_fffffff009c31514();
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  if (*(long **)(param_1 + 0x158) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x158) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x158) = 0;
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
  plVar2 = *(long **)(param_1 + 0x488);
  if (plVar2 != (long *)0x0) {
    plVar3 = *(long **)(param_1 + 0x490);
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0xb8))(plVar3);
      (**(code **)(**(long **)(param_1 + 0x488) + 0xa8))
                (*(long **)(param_1 + 0x488),*(undefined8 *)(param_1 + 0x490));
      if (*(long **)(param_1 + 0x490) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x490) + 0x28))();
      }
      *(undefined8 *)(param_1 + 0x490) = 0;
      plVar2 = *(long **)(param_1 + 0x488);
    }
    (**(code **)(*plVar2 + 0xb8))();
    if (*(long **)(param_1 + 0x488) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x488) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x488) = 0;
  }
  if (*(long **)(param_1 + 0x1b0) != (long *)0x0) {
    if (*(long *)(param_1 + 0x1b8) != 0) {
      (**(code **)(**(long **)(param_1 + 0x1b0) + 0xa8))();
      if (*(long **)(param_1 + 0x1b8) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x1b8) + 0x28))();
      }
      *(undefined8 *)(param_1 + 0x1b8) = 0;
    }
    if (*(long *)(param_1 + 0x1c0) != 0) {
      (**(code **)(**(long **)(param_1 + 0x1b0) + 0xa8))();
      if (*(long **)(param_1 + 0x1c0) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x1c0) + 0x28))();
      }
      *(undefined8 *)(param_1 + 0x1c0) = 0;
    }
    if (*(long *)(param_1 + 0x1c8) != 0) {
      thunk_EXT_FUN_80110000038ff020();
      *(undefined8 *)(param_1 + 0x1c8) = 0;
    }
    (**(code **)(**(long **)(param_1 + 0x1b0) + 0xb8))();
    if (*(long **)(param_1 + 0x1b0) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x1b0) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x1b0) = 0;
  }
  if (*(long *)(param_1 + 0x148) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x148) = 0;
  }
  if (*(long *)(param_1 + 0x140) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x140) = 0;
  }
  FUN_fffffff009c32e34(param_1);
  FUN_fffffff009c32e9c(param_1);
  FUN_fffffff009c32f04(param_1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c32e28);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c32e30. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca38 + 0x2c8))(param_1,param_2,PTR_DAT_fffffff00806ca38 + 0x2c8);
  return;
}

