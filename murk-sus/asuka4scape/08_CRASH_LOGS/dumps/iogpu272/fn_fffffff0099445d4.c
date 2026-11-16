// FUN_fffffff0099445d4 @ fffffff0099445d4 size=92

void FUN_fffffff0099445d4(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x10) = 0;
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1228,uVar2,(ulong)*(uint *)(param_1 + 0x28) << 3);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994462c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038fe6b0(*(undefined8 *)(param_1 + 0x18),*(uint *)(param_1 + 0x28) >> 3);
  return;
}

