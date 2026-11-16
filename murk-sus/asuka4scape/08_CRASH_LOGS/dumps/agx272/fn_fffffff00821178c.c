// FUN_fffffff00821178c @ fffffff00821178c size=220

void FUN_fffffff00821178c(long param_1,int param_2)

{
  ulong *puVar1;
  ulong *puVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong unaff_x30;
  
  lVar4 = *(long *)(param_1 + 0x18);
  lVar5 = (ulong)(uint)(param_2 << 1) * 8;
  puVar2 = (ulong *)(lVar4 + (int)lVar5);
  if (lVar5 != (int)lVar5) {
    puVar2 = (ulong *)(lVar4 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar6 = (ulong)(param_2 << 1 | 1);
  lVar5 = uVar6 * 8;
  puVar1 = (ulong *)(lVar4 + (int)lVar5);
  if (lVar5 != (int)lVar5) {
    puVar1 = (ulong *)(lVar4 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar7 = *puVar1;
  if ((((uint)*puVar2 | (uint)uVar7) & 1) != 0) {
    lVar5 = (ulong)(uint)(param_2 << 1) * 8;
    puVar1 = (ulong *)(lVar4 + (int)lVar5);
    if (lVar5 - (int)lVar5 != 0) {
      puVar1 = (ulong *)(lVar4 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar1 = *puVar2 & 0xfffffffffffffffe;
    lVar5 = uVar6 * 8;
    puVar2 = (ulong *)(lVar4 + (int)lVar5);
    if (lVar5 - (int)lVar5 != 0) {
      puVar2 = (ulong *)(lVar4 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar2 = uVar7 & 0xfffffffffffffffe;
    DataMemoryBarrier(2,3);
    FUN_fffffff00821010c(param_1,param_2,0,0);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008211860);
      (*pcVar3)();
    }
    FUN_fffffff008210570(param_1);
    return;
  }
  return;
}

