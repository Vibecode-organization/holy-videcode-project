// FUN_fffffff00817c80c @ fffffff00817c80c size=272

void FUN_fffffff00817c80c(long *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(param_1[0x234c]);
  (**(code **)(*param_1 + 0x710))(param_1,"",0);
  iVar2 = thunk_EXT_FUN_80110000029477a8(param_1[0x29]);
  if (iVar2 != 0) {
    puVar3 = (undefined8 *)(*(long *)param_1[0x62] + 0xe8);
    (*(code *)*puVar3)(puVar3,(long *)param_1[0x62],FUN_fffffff00817c91c,0,0,0,0);
  }
  (**(code **)(*param_1 + 0x718))(param_1,"",0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817c918);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(param_1[0x234c]);
  return;
}

