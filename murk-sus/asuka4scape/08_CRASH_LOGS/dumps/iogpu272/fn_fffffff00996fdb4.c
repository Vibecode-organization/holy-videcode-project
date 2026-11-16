// FUN_fffffff00996fdb4 @ fffffff00996fdb4 size=108

undefined8 FUN_fffffff00996fdb4(long param_1,long param_2)

{
  long *plVar1;
  ulong uVar2;
  code *pcVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  ulong unaff_x30;
  
  uVar2 = *(ulong *)(param_1 + 0x20);
  if (uVar2 < *(ulong *)(param_1 + 0x28)) {
    *(ulong *)(param_1 + 0x20) = uVar2 + 1;
    lVar6 = uVar2 * 8;
    plVar1 = (long *)(*(long *)(param_1 + 0x18) + (long)(int)lVar6);
    if (lVar6 - (int)lVar6 != 0) {
      plVar1 = (long *)(*(long *)(param_1 + 0x18) + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *plVar1 = param_2;
    uVar4 = *(uint *)(param_2 + 0xc);
    *(uint *)(param_2 + 0xc) = uVar4 + 1;
    if (0xffffffe < uVar4) {
      FUN_fffffff009983678(param_2);
    }
    return 1;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996fe18);
    (*pcVar3)();
  }
  uVar5 = FUN_fffffff00996fc70();
  return uVar5;
}

