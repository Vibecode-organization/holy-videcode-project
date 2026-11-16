// FUN_fffffff0081ee340 @ fffffff0081ee340 size=160

void FUN_fffffff0081ee340(long param_1)

{
  ulong uVar1;
  code *pcVar2;
  ulong uVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x90) != 0) {
    uVar1 = 1;
    uVar4 = 0;
    do {
      uVar3 = uVar1;
      thunk_EXT_FUN_801100000293f7a0
                (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x80) + uVar4 * 8) + 0x18));
      thunk_EXT_FUN_801100000293ec08
                (*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x80) + uVar4 * 8) + 0x18));
      uVar1 = (ulong)((int)uVar3 + 1);
      uVar4 = uVar3;
    } while (uVar3 < *(ulong *)(param_1 + 0x90));
  }
  thunk_EXT_FUN_80110000029718d8(*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x98),0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ee3dc);
    (*pcVar2)();
  }
  thunk_EXT_FUN_8011000002979b18(*(long *)(*(long *)(param_1 + 0x10) + 0x160) + 0x1b8,param_1);
  return;
}

