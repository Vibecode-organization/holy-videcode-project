// FUN_fffffff0081b0350 @ fffffff0081b0350 size=168

void FUN_fffffff0081b0350(long param_1)

{
  bool bVar1;
  code *pcVar2;
  ulong uVar3;
  ulong uVar4;
  int *piVar5;
  ulong uVar6;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x38));
  uVar3 = *(ulong *)(param_1 + 0x80);
  if (uVar3 != 0) {
    uVar4 = 0;
    uVar6 = 1;
    do {
      piVar5 = *(int **)(*(long *)(param_1 + 0x78) + uVar4 * 8);
      if (piVar5 != (int *)0x0) {
        if (*(int *)(param_1 + 0x2c) == 1) {
          *piVar5 = *piVar5 + -1;
        }
        FUN_fffffff0081af724(param_1,(int)uVar6 + -1,0);
        uVar3 = *(ulong *)(param_1 + 0x80);
      }
      bVar1 = uVar6 < uVar3;
      uVar4 = uVar6;
      uVar6 = (ulong)((int)uVar6 + 1);
    } while (bVar1);
  }
  *(undefined1 *)(param_1 + 0x28) = 1;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b03f4);
    (*pcVar2)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x38));
  return;
}

