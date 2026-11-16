// FUN_fffffff009c34760 @ fffffff009c34760 size=176

void FUN_fffffff009c34760
               (long param_1,uint param_2,uint param_3,ulong param_4,ulong param_5,ulong param_6)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  *(uint *)(param_1 + 0xac) = *(uint *)(param_1 + 0xac) | param_2;
  *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | param_3;
  if ((param_4 & 0xffffffff) < *(ulong *)(param_1 + 0xb8)) {
    *(ulong *)(param_1 + 0xb8) = param_4 & 0xffffffff;
  }
  if ((param_5 & 0xffffffff) < *(ulong *)(param_1 + 0xc0)) {
    *(ulong *)(param_1 + 0xc0) = param_5 & 0xffffffff;
  }
  if ((param_6 & 0xffffffff) < *(ulong *)(param_1 + 200)) {
    *(ulong *)(param_1 + 200) = param_6 & 0xffffffff;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c3480c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
  return;
}

