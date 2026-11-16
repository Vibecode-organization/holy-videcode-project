// FUN_fffffff00997fef4 @ fffffff00997fef4 size=212

void FUN_fffffff00997fef4(long param_1,undefined8 param_2,ulong param_3)

{
  uint uVar1;
  code *pcVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x18));
  FUN_fffffff00997fe30(param_1);
  if ((*(byte *)(param_1 + 0x38) & 1) == 0) {
    if (param_3 <= *(ulong *)(param_1 + 0x30)) goto LAB_fffffff00997ffa4;
    *(ulong *)(param_1 + 0x30) = param_3;
  }
  if (*(uint *)(param_1 + 0x44) - *(int *)(param_1 + 0x40) == 8) {
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  }
  FUN_fffffff00994c49c
            (*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148),param_2,
             param_1 + 0x88 + ((ulong)*(uint *)(param_1 + 0x44) & 7) * 0x40);
  uVar1 = *(uint *)(param_1 + 0x44);
  *(ulong *)(param_1 + 0x48 + ((ulong)uVar1 & 7) * 8) = param_3;
  *(uint *)(param_1 + 0x44) = uVar1 + 1;
  if (*(int *)(param_1 + 0x20) != 0) {
    thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x18),param_1,0);
  }
LAB_fffffff00997ffa4:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997ffc4);
    (*pcVar2)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x18));
  return;
}

