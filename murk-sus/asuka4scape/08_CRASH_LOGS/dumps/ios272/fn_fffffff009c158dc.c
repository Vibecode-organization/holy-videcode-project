// FUN_fffffff009c158dc @ fffffff009c158dc size=216

void FUN_fffffff009c158dc(long *param_1,long *param_2)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(param_1[2]);
  param_2[5] = 0;
  plVar2 = (long *)param_1[4];
  param_2[6] = (long)plVar2;
  *plVar2 = (long)param_2;
  param_1[4] = (long)(param_2 + 5);
  (**(code **)(*param_2 + 0x20))(param_2);
  if ((*(byte *)(param_1 + 5) & 1) == 0) {
    *(undefined1 *)(param_1 + 5) = 1;
    (**(code **)(*param_1 + 0x20))(param_1);
    (**(code **)(*(long *)param_1[7] + 0xf8))((long *)param_1[7],0,0,0);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c159b0);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(param_1[2]);
  return;
}

