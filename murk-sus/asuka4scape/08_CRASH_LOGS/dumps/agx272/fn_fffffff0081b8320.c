// FUN_fffffff0081b8320 @ fffffff0081b8320 size=172

void FUN_fffffff0081b8320(long *param_1,int param_2)

{
  int *piVar1;
  long lVar2;
  int iVar3;
  code *pcVar4;
  long lVar5;
  ulong unaff_x30;
  
  if (param_2 == 0) {
    (**(code **)(*param_1 + 0xa08))();
    lVar5 = param_1[0x50];
    piVar1 = (int *)(lVar5 + 0x11a68);
    iVar3 = *piVar1;
    *piVar1 = 0;
    if (iVar3 != 0) {
      lVar2 = 0x11a70;
      if (iVar3 != 2) {
        lVar2 = 0x11a78;
      }
      thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar5 + lVar2));
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b83c8);
        (*pcVar4)();
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1[0x50] + 0x11d88));
      return;
    }
  }
  return;
}

