// FUN_fffffff009c33ed4 @ fffffff009c33ed4 size=192

void FUN_fffffff009c33ed4(long param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1f0));
  uVar2 = (**(code **)(**(long **)(param_1 + 0x1f8) + 0x90))();
  while (0x7f < uVar2) {
    *(long *)(param_1 + 0x210) = *(long *)(param_1 + 0x210) + 1;
    iVar3 = thunk_EXT_FUN_80110000038ff064(*(undefined8 *)(param_1 + 0x1f0),param_1 + 0x1f8,1);
    *(long *)(param_1 + 0x210) = *(long *)(param_1 + 0x210) + -1;
    if (iVar3 == 2) break;
    uVar2 = (**(code **)(**(long **)(param_1 + 0x1f8) + 0x90))();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1f0));
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c33f90);
  (*pcVar1)();
}

