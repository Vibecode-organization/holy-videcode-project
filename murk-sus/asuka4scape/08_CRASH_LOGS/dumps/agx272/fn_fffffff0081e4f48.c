// FUN_fffffff0081e4f48 @ fffffff0081e4f48 size=140

void FUN_fffffff0081e4f48(long param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  code *pcVar2;
  char *pcVar3;
  ulong unaff_x30;
  
  pcVar3 = *(char **)(*(long *)(param_1 + 0x40) + 0x20);
  pcVar1 = "Firmware MSE Allocation State, Statistics";
  if (pcVar3 != (char *)0x0) {
    pcVar1 = pcVar3;
  }
  thunk_EXT_FUN_8011000002977e48(param_2,*(undefined8 *)(*(long *)(param_1 + 0x40) + 0x48),pcVar1);
  if ((int)param_3 != 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e4fc0);
      (*pcVar2)();
    }
    thunk_EXT_FUN_8011000002977950
              (param_2,*(undefined8 *)(*(long *)(param_1 + 0x40) + 0x48),param_3);
    return;
  }
  return;
}

