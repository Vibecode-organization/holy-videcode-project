// FUN_fffffff009955be4 @ fffffff009955be4 size=212

void FUN_fffffff009955be4(long *param_1)

{
  code *pcVar1;
  uint uVar2;
  long *plVar3;
  ulong unaff_x30;
  
  uVar2 = *(uint *)(param_1 + 2);
  if ((uVar2 & 0xff) == 3) {
    return;
  }
  if (((uVar2 & 0xff) == 0x82) &&
     (plVar3 = (long *)param_1[6], plVar3 != (long *)0x0 && plVar3 != param_1)) {
    thunk_EXT_FUN_80110000032222a8(plVar3[0xc]);
    (**(code **)(*plVar3 + 0xe8))(plVar3);
    thunk_EXT_FUN_8011000003222de0(plVar3[0xc]);
    uVar2 = *(uint *)(param_1 + 2);
  }
  if ((uVar2 >> 0x11 & 1) != 0) {
    FUN_fffffff00994ba48(*(undefined8 *)(param_1[10] + 0x148),param_1[0xb]);
    FUN_fffffff00994ba48(*(undefined8 *)(param_1[10] + 0x148),param_1[0xb] + 0x40);
  }
  FUN_fffffff00994ba48(*(undefined8 *)(param_1[10] + 0x148),param_1[3]);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009955cb0);
    (*pcVar1)();
  }
  FUN_fffffff00994ba48(*(undefined8 *)(param_1[10] + 0x148),param_1[3] + 0x40);
  return;
}

