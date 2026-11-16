// FUN_fffffff0099596f0 @ fffffff0099596f0 size=196

void FUN_fffffff0099596f0
               (long param_1,undefined8 param_2,ulong param_3,undefined8 param_4,ulong param_5)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000036da494(0x85090100,param_4,param_3 & 0xffffffff,0,0,0);
  FUN_fffffff00995a318(param_1,param_2,param_3);
  if ((param_5 & 1) == 0) {
    LOAcquire();
    lVar2 = *(long *)(param_1 + 0x40);
    *(long *)(param_1 + 0x40) = lVar2 + 1;
    LORelease();
    if ((lVar2 + 1 == *(long *)(param_1 + 0x48)) && ((*(byte *)(param_1 + 0x50) & 1) != 0)) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099597a0);
        (*pcVar1)();
      }
      thunk_EXT_FUN_8011000003246024(param_1,0,0);
      return;
    }
  }
  return;
}

