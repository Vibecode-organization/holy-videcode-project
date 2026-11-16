// FUN_fffffff00a1dfa68 @ fffffff00a1dfa68 size=248

undefined8 FUN_fffffff00a1dfa68(long param_1,int param_2)

{
  uint uVar1;
  code *pcVar2;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  ulong uVar6;
  
  uVar6 = *(ulong *)(param_1 + 0x48);
  if (uVar6 == 0) {
    iVar5 = *(int *)(param_1 + 0x14);
    uVar3 = 0;
    uVar4 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 0x14);
    uVar3 = 0;
    if (uVar6 != 0) {
      uVar3 = (uVar6 & 0x3fff) << 0xe;
    }
    uVar4 = 0;
    if (uVar6 != 0) {
      uVar4 = uVar6 & 0xffffffffffffc000 | 0x4000000000;
    }
    if ((uVar6 & 0x4000000000) != 0) {
      uVar3 = (uVar6 & 0x10 | 0x20) << (uVar6 & 0xf);
      uVar4 = uVar6 & 0xffffffffffffffe0;
    }
  }
  uVar6 = uVar4;
  if ((uint)(iVar5 + param_2) <= (uint)((int)((uVar3 & 0xffffffff) * 0xaaaaaab >> 0x20) * 7) >> 3) {
    while( true ) {
      if (param_2 == 0) {
        return 0;
      }
      uVar1 = *(uint *)(uVar6 + 0xc);
      if (uVar1 == 0) break;
      if (uVar3 < (ulong)uVar1 * 0x18 + 0x18) {
LAB_fffffff00a1dfb4c:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a1dfb58);
        (*pcVar2)();
      }
      uVar6 = uVar4 + (ulong)uVar1 * 0x18;
      if (((uVar4 ^ uVar6) & 0xffc0000000000000) != 0) {
        uVar6 = uVar6 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if (uVar6 == 0) goto LAB_fffffff00a1dfb4c;
      param_2 = param_2 + -1;
    }
  }
  return 3;
}

