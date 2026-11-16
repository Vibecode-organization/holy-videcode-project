// FUN_fffffff009c36fa0 @ fffffff009c36fa0 size=180

void FUN_fffffff009c36fa0(long param_1,long *param_2)

{
  code *pcVar1;
  long *plVar2;
  undefined8 *puVar3;
  ulong unaff_x30;
  
  (**(code **)(*param_2 + 0x20))(param_2);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1c8));
  param_2[0xf] = 0;
  plVar2 = *(long **)(param_1 + 0x1d8);
  param_2[0x10] = (long)plVar2;
  *plVar2 = (long)param_2;
  *(long **)(param_1 + 0x1d8) = param_2 + 0xf;
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1c8));
  puVar3 = (undefined8 *)(**(long **)(param_1 + 0x1c0) + 0xf8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c37048);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c37050. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar3)(*(long **)(param_1 + 0x1c0),0,0,0,puVar3);
  return;
}

