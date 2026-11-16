// FUN_fffffff0081ca054 @ fffffff0081ca054 size=292

void FUN_fffffff0081ca054(long *param_1,uint param_2,uint param_3)

{
  undefined8 *puVar1;
  code *pcVar2;
  ulong uVar3;
  ulong unaff_x30;
  
  if (*(char *)(param_1[0x50] + 0x115c1) == '\x02') {
    thunk_EXT_FUN_8011000003a49114
              ("AGXk: %s:%d:%s: !!! AGXArmFirmware:: Power State (%d) must be in external state\n");
    return;
  }
  uVar3 = (**(code **)(*param_1 + 0xa28))();
  if ((uVar3 & 1) != 0) {
    puVar1 = (undefined8 *)(*(long *)param_1[0x28c] + 0x568);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ca114);
      (*pcVar2)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081ca11c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*puVar1)((long *)param_1[0x28c],
                       (ulong)((param_2 & 7) << 2) | (ulong)(param_3 & 0x3f) << 0x30 |
                       0x80000000000000,0,puVar1);
    return;
  }
  thunk_EXT_FUN_8011000003a49114
            ("AGXk: %s:%d:%s: !!! AGXArmFirmware::kickFirmware: Command submission is disabled!\n");
  return;
}

