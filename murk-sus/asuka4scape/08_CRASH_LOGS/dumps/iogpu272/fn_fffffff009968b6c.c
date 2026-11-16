// FUN_fffffff009968b6c @ fffffff009968b6c size=152

undefined8 FUN_fffffff009968b6c(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  iVar2 = (*DAT_fffffff007fe9090)();
  if (iVar2 != 0) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x40;
    iVar2 = FUN_fffffff009968c04(param_1 + 0x80,param_3,0x80000,1);
    if (iVar2 != 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009968bf0);
        (*pcVar1)();
      }
      uVar3 = FUN_fffffff009968c04(param_1 + 0xd8,0x80,0x100,1);
      return uVar3;
    }
  }
  return 0;
}

