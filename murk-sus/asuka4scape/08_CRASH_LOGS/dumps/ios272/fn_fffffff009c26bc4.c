// FUN_fffffff009c26bc4 @ fffffff009c26bc4 size=116

void FUN_fffffff009c26bc4(long param_1,undefined8 param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  ulong unaff_x30;
  
  lVar3 = *(long *)(param_1 + 0x360);
  if (lVar3 == 0) {
    lVar3 = thunk_EXT_FUN_80110000038fe074(&DAT_fffffff00806afb0);
    *(long *)(param_1 + 0x360) = lVar3;
  }
  uVar1 = *(uint *)(lVar3 + 0x3c0);
  *(uint *)(lVar3 + 0x3c0) = uVar1 + 1;
  *(uint *)(lVar3 + ((ulong)uVar1 & 7) * 0x78) = uVar1;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c26c34);
    (*pcVar2)();
  }
  FUN_fffffff009c413b4(param_2);
  return;
}

