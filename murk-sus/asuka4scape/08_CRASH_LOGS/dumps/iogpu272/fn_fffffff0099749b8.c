// FUN_fffffff0099749b8 @ fffffff0099749b8 size=104

ulong FUN_fffffff0099749b8(long param_1,uint param_2)

{
  uint *puVar1;
  ulong *puVar2;
  ulong uVar3;
  long lVar4;
  int iVar5;
  
  lVar4 = (ulong)param_2 * 4;
  iVar5 = (int)lVar4;
  puVar1 = (uint *)((long)&DAT_fffffff00af227c0 + (long)iVar5);
  if (lVar4 != iVar5) {
    puVar1 = (uint *)((ulong)(&DAT_fffffff00af227c0 + param_2) & 0xffffffffffff | 0x2bad000000000000
                     );
  }
  if (*puVar1 != 0) {
    uVar3 = (ulong)*puVar1 << 0x14;
    if (*(ulong *)(param_1 + 0x2c8) <= uVar3) {
      uVar3 = *(ulong *)(param_1 + 0x2c8);
    }
    return uVar3;
  }
  lVar4 = (ulong)param_2 * 8;
  puVar2 = (ulong *)(param_1 + 0x118 + (long)(int)lVar4);
  if (lVar4 - (int)lVar4 != 0) {
    puVar2 = (ulong *)(param_1 + 0x118 + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
  }
  return *puVar2;
}

