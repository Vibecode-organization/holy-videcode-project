// FUN_fffffff0081ec918 @ fffffff0081ec918 size=312

void FUN_fffffff0081ec918(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x20) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x20) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x20) = 0;
  if (*(long **)(param_1 + 0x28) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x28) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  plVar2 = *(long **)(param_1 + 0x88);
  if (plVar2 == (long *)0x0) goto LAB_fffffff0081eca08;
  if (*(int *)(param_1 + 0x80) == 0) {
LAB_fffffff0081ec9e4:
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  else {
    thunk_EXT_FUN_80110000032222a8(plVar2[8]);
    if (0 < plVar2[7]) {
      if (plVar2[10] != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      if (plVar2[0xb] != 0) {
        thunk_EXT_FUN_801100000297b408();
      }
      plVar2[7] = plVar2[7] + -1;
    }
    thunk_EXT_FUN_8011000003222de0(plVar2[8]);
    *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + -1;
    plVar2 = *(long **)(param_1 + 0x88);
    if (plVar2 != (long *)0x0) goto LAB_fffffff0081ec9e4;
  }
  *(undefined8 *)(param_1 + 0x88) = 0;
LAB_fffffff0081eca08:
  if (*(long **)(param_1 + 0x90) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x90) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x90) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081eca4c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_801100000389390c(param_1);
  return;
}

