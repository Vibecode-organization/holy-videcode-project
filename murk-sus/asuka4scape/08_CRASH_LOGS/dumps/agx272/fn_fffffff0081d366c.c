// FUN_fffffff0081d366c @ fffffff0081d366c size=268

void FUN_fffffff0081d366c(long param_1,undefined8 param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xe8));
  if (*(long *)(param_1 + 0xf0) != 0) {
    thunk_EXT_FUN_8011000003a49114
              ("AGXk: %s:%d:%s: !!! AGXArmFirmwareMapper::stop: mapping list not empty!\n");
    return;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xe8));
  if (*(long *)(param_1 + 0xe8) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0xe8) = 0;
  }
  if (*(long **)(param_1 + 0xe0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xe0) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xe0) = 0;
  if (*(long *)(param_1 + 0xd8) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0xd8) = 0;
  }
  if (*(long **)(param_1 + 0xd0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0xd0) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0xd0) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081d3744);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081d374c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6178 + 0x2c8))(param_1,param_2,PTR_DAT_fffffff007ca6178 + 0x2c8);
  return;
}

