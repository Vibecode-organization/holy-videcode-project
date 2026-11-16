// FUN_fffffff009c21f08 @ fffffff009c21f08 size=112

void FUN_fffffff009c21f08(long param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  FUN_fffffff009c21f78(param_1 + 0x30);
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  if (*(long *)(param_1 + 0x30) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = thunk_EXT_FUN_8011000003977aa8();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c21f74);
    (*pcVar2)();
  }
  thunk_EXT_FUN_80110000036da494(0x540000c,uVar1,uVar3,0,0,0);
  return;
}

