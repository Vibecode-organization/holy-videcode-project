// FUN_fffffff009c33ed4 @ fffffff009c33ed4 size=192
// CALLERS:
//   fffffff009c33da4 FUN_fffffff009c33c34@fffffff009c33c34

void FUN_fffffff009c33ed4(long param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  ulong unaff_x30;
  
  FUN_fffffff009c495b4(*(undefined8 *)(param_1 + 0x1f0));
  uVar2 = (**(code **)(**(long **)(param_1 + 0x1f8) + 0x90))();
  while (0x7f < uVar2) {
    *(long *)(param_1 + 0x210) = *(long *)(param_1 + 0x210) + 1;
    iVar3 = FUN_fffffff009c495c4(*(undefined8 *)(param_1 + 0x1f0),param_1 + 0x1f8,1);
    *(long *)(param_1 + 0x210) = *(long *)(param_1 + 0x210) + -1;
    if (iVar3 == 2) break;
    uVar2 = (**(code **)(**(long **)(param_1 + 0x1f8) + 0x90))();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    FUN_fffffff009c495d4(*(undefined8 *)(param_1 + 0x1f0));
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c33f90);
  (*pcVar1)();
}

