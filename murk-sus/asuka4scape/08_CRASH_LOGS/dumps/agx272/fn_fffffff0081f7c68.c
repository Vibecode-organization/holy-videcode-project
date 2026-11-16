// FUN_fffffff0081f7c68 @ fffffff0081f7c68 size=252

void FUN_fffffff0081f7c68(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x130) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x130) + 0x28))();
    *(undefined8 *)(param_1 + 0x130) = 0;
  }
  plVar2 = *(long **)(param_1 + 0x1c0);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0xb0))(plVar2,*(undefined8 *)(param_1 + 0x128));
    (**(code **)(**(long **)(param_1 + 0x1c0) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x1c0) = 0;
  *(undefined8 *)(param_1 + 0x1c8) = 0;
  if (*(long *)(param_1 + 0x290) != 0) {
    thunk_EXT_FUN_80110000038fe6b0(*(long *)(param_1 + 0x290),*(undefined8 *)(param_1 + 0x278));
    *(undefined8 *)(param_1 + 0x290) = 0;
    *(undefined8 *)(param_1 + 0x278) = 0;
  }
  if (*(long **)(param_1 + 0x128) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x128) + 0x28))();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f7d58);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081f7d60. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))(param_1);
  return;
}

