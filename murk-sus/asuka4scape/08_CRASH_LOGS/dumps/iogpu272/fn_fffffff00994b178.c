// FUN_fffffff00994b178 @ fffffff00994b178 size=156

void FUN_fffffff00994b178(long param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  uVar4 = (long)param_2 << 4 | 0xc;
  puVar1 = (undefined4 *)(param_1 + 0x40 + (long)(int)uVar4);
  if (uVar4 != (long)(int)uVar4) {
    puVar1 = (undefined4 *)(param_1 + 0x40 + uVar4 & 0xffffffffffff | 0x2bad000000000000);
  }
  *puVar1 = param_3;
  if (DAT_fffffff00af227e8 != 0) {
    uVar3 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x10));
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00994b204);
      (*pcVar2)();
    }
    thunk_EXT_FUN_80110000036da494(0x85180008,(long)param_2,param_3,uVar3,0,0);
    return;
  }
  return;
}

