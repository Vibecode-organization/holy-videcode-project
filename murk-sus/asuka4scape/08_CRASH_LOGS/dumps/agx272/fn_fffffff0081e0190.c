// FUN_fffffff0081e0190 @ fffffff0081e0190 size=332

void FUN_fffffff0081e0190(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x48) != 0) {
    thunk_EXT_FUN_80110000038ff020();
  }
  plVar2 = *(long **)(param_1 + 0x58);
  if (plVar2 == (long *)0x0) goto LAB_fffffff0081e023c;
  if (*(int *)(param_1 + 0x68) == 0) {
LAB_fffffff0081e0218:
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
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + -1;
    plVar2 = *(long **)(param_1 + 0x58);
    if (plVar2 != (long *)0x0) goto LAB_fffffff0081e0218;
  }
  *(undefined8 *)(param_1 + 0x58) = 0;
LAB_fffffff0081e023c:
  if (*(long **)(param_1 + 8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 8) + 0x28))();
  }
  *(undefined8 *)(param_1 + 8) = 0;
  if (*(long **)(param_1 + 0x18) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  if (*(long **)(param_1 + 0x28) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x28) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x80) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e02d8);
    (*pcVar1)();
  }
  FUN_fffffff00816b2a8(*(undefined8 *)(param_1 + 0x50));
  return;
}

