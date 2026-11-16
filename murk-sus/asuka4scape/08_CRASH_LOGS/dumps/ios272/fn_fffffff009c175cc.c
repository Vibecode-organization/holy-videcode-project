// FUN_fffffff009c175cc @ fffffff009c175cc size=212

/* WARNING: Removing unreachable block (ram,0xfffffff009c1764c) */

void FUN_fffffff009c175cc(long param_1,long *param_2)

{
  code *pcVar1;
  long *plVar2;
  ulong uVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x30));
  param_2[5] = 0;
  plVar2 = *(long **)(param_1 + 0x48);
  param_2[6] = (long)plVar2;
  *plVar2 = (long)param_2;
  *(long **)(param_1 + 0x48) = param_2 + 5;
  (**(code **)(*param_2 + 0x20))(param_2);
  uVar4 = **(ulong **)(param_1 + 0x20);
  uVar3 = param_2[2];
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x30));
  if (uVar4 < uVar3) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    FUN_fffffff009c16fa0(param_1,1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c1769c);
  (*pcVar1)();
}

