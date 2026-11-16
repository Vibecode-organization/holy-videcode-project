// FUN_fffffff0081ca3ec @ fffffff0081ca3ec size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0081ca450) */

void FUN_fffffff0081ca3ec(long *param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  uint in_w4;
  int in_w5;
  ulong unaff_x30;
  
  if (*(char *)(param_1[0x50] + 0x115c1) == '\x02') {
    thunk_EXT_FUN_8011000003a49114
              ("AGXk: %s:%d:%s: !!! AGXArmFirmware:: Power State (%d) must be in external state\n");
    return;
  }
  FUN_fffffff0081a7628();
  iVar3 = (**(code **)(*param_1 + 0xa28))(*param_1 + 0xa28,param_1);
  if ((in_w5 != 0) && (iVar3 != 0)) {
    puVar1 = (undefined8 *)(*(long *)param_1[0x28c] + 0x568);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081ca4d4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puVar1)((long *)param_1[0x28c],(ulong)((in_w4 & 7) << 2) | 0x83000000000000,0,
                         puVar1);
      return;
    }
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ca4cc);
    (*pcVar2)();
  }
  return;
}

