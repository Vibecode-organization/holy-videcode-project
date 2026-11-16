// FUN_fffffff008211868 @ fffffff008211868 size=180

void FUN_fffffff008211868(long param_1,long param_2)

{
  ulong *puVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  
  uVar3 = FUN_fffffff0082103e8(param_1,0);
  uVar4 = FUN_fffffff0082103e8(param_1,1);
  lVar5 = *(long *)(param_1 + 0x18);
  lVar2 = (ulong)(uint)((int)param_2 << 1) * 8;
  puVar1 = (ulong *)(lVar5 + (int)lVar2);
  if (lVar2 != (int)lVar2) {
    puVar1 = (ulong *)(lVar5 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar1 = uVar3 & 0xffffffffffffc000 | param_2 << 0x30 | 1;
  lVar2 = (ulong)((int)param_2 << 1 | 1) * 8;
  puVar1 = (ulong *)(lVar5 + (int)lVar2);
  if (lVar2 != (int)lVar2) {
    puVar1 = (ulong *)(lVar5 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar1 = uVar3 & 0xffffff0000000000 | param_2 << 0x30 | 1 | uVar4 & 0xffffffffffffc000;
  DataMemoryBarrier(2,3);
  return;
}

