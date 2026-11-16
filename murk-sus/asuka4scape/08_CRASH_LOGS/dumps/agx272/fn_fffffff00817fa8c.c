// FUN_fffffff00817fa8c @ fffffff00817fa8c size=116

void FUN_fffffff00817fa8c(long param_1)

{
  code *pcVar1;
  long lVar2;
  uint uVar3;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x4b0);
  uVar3 = *(uint *)(*(long *)(lVar2 + 0x280) + 0x10efc);
  if (uVar3 == 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar2 + 0xbc0));
    uVar3 = 0;
    if (*(uint *)(lVar2 + 0xb84) != 0) {
      uVar3 = (uint)(*(int *)(lVar2 + 0xb88) * 100) / *(uint *)(lVar2 + 0xb84);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0xbc0));
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817fafc);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038c6e24(uVar3,0x20);
  return;
}

