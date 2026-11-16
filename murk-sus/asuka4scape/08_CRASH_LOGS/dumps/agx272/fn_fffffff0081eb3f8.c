// FUN_fffffff0081eb3f8 @ fffffff0081eb3f8 size=300

void FUN_fffffff0081eb3f8(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong uVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x120));
  if ((*(long *)(param_1 + 0xc0) != 0) && (*(int *)(param_1 + 0x50) != 0)) {
    uVar4 = 0;
    do {
      uVar3 = *(ulong *)(param_1 + 0xc0) + uVar4 * 0x40;
      if (((*(ulong *)(param_1 + 0xc0) ^ uVar3) & 0xffc0000000000000) != 0) {
        uVar3 = uVar3 & 0xffffffffffff | 0xc8a2000000000000;
      }
      thunk_EXT_FUN_8011000002947a48(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148),uVar3);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0x50));
  }
  thunk_EXT_FUN_8011000002947a48(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148),param_1 + 200);
  if ((*(long *)(param_1 + 0x188) != 0) && (*(int *)(param_1 + 0x138) != 0)) {
    uVar4 = 0;
    do {
      uVar3 = *(ulong *)(param_1 + 0x188) + uVar4 * 0x40;
      if (((*(ulong *)(param_1 + 0x188) ^ uVar3) & 0xffc0000000000000) != 0) {
        uVar3 = uVar3 & 0xffffffffffff | 0xc8a2000000000000;
      }
      thunk_EXT_FUN_8011000002947a48(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148),uVar3);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0x138));
  }
  plVar2 = *(long **)(*(long *)(param_1 + 0x20) + 0x20);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0xe8))();
  }
  if (*(long **)(param_1 + 0x48) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x48) + 0xe8))();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081eb520);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x120));
  return;
}

