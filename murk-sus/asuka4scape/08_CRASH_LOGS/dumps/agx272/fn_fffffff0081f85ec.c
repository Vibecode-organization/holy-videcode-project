// FUN_fffffff0081f85ec @ fffffff0081f85ec size=176

void FUN_fffffff0081f85ec(long param_1,long param_2)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  ulong unaff_x30;
  
  if ((((*(byte *)(param_1 + 0xb1) & 1) != 0) && (param_2 != 0)) && (param_1 != 0)) {
    lVar3 = *(long *)(*(long *)(param_1 + 0x50) + 0x111e8);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0x18));
    if ((*(int *)(lVar3 + 0x20) != 0) && (iVar1 = *(int *)(param_2 + 0x1b8), iVar1 != 0)) {
      *(int *)(lVar3 + 0x20) = *(int *)(lVar3 + 0x20) + -1;
      *(int *)(param_2 + 0x1b8) = iVar1 + -1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x18));
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081f8690);
    (*pcVar2)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081f8698. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca60f0 + 0xc0))(param_1,param_2);
  return;
}

