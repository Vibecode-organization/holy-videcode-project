// FUN_fffffff00817eb58 @ fffffff00817eb58 size=176

void FUN_fffffff00817eb58(long param_1,long param_2,long param_3)

{
  ulong uVar1;
  code *pcVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x390));
  if (param_2 - param_3 != 0) {
    uVar1 = (param_2 - param_3) + *(long *)(param_1 + 0x388);
    *(ulong *)(param_1 + 0x388) = uVar1;
    thunk_EXT_FUN_80110000039b8f8c
              (*(undefined8 *)(*(long *)(param_1 + 0x1ac50) + 0xe8),uVar1 >> 10 & 0x3fffff);
    if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930cd8,uVar1,0,0,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817ec04);
    (*pcVar2)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x390));
  return;
}

