// FUN_fffffff0081a5eb0 @ fffffff0081a5eb0 size=440

void FUN_fffffff0081a5eb0(long *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong unaff_x30;
  
  if (param_2 < 4) {
    if (param_2 - 1U < 3) {
      puVar3 = (undefined8 *)(*(long *)param_1[0x42] + 0x20);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081a5f10);
        (*pcVar1)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081a5f18. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puVar3)((long *)param_1[0x42],puVar3);
      return;
    }
    if (param_2 != 0) {
LAB_fffffff0081a6038:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081a6058);
        (*pcVar1)();
      }
      thunk_EXT_FUN_8011000003a1145c("Invalid interrupt index received\n");
      return;
    }
    if ((*(byte *)(param_1[0x50] + 0x645) & 1) != 0) {
      iVar2 = (**(code **)(*param_1 + 0x2a0))();
      if (iVar2 != 0) {
        (**(code **)(*(long *)param_1[0x50] + 0x900))();
      }
      if ((DAT_fffffff00ae22cf1 >> 1 & 1) != 0) {
        return;
      }
    }
  }
  else if (param_2 != 4) {
    if (param_2 == 7) {
      puVar3 = (undefined8 *)(*(long *)param_1[0x50] + 0x910);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081a5f6c);
        (*pcVar1)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081a5f74. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puVar3)((long *)param_1[0x50],puVar3);
      return;
    }
    goto LAB_fffffff0081a6038;
  }
  (**(code **)(*param_1 + 2000))();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081a6034);
    (*pcVar1)();
  }
  FUN_fffffff0081a6068(param_1,1);
  return;
}

