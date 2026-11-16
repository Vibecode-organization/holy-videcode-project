// FUN_fffffff008189024 @ fffffff008189024 size=180

void FUN_fffffff008189024(long param_1,uint *param_2,ulong param_3)

{
  ulong *puVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  int iVar5;
  long lVar6;
  
  lVar3 = *(long *)(param_1 + 0x20);
  if (((*(long *)(lVar3 + 0x68) == 0) ||
      (iVar5 = *(int *)(*(long *)(lVar3 + 0x68) + 200), iVar5 == 0 || iVar5 == 5)) ||
     (0xf < iVar5 - 1U)) {
    uVar4 = 0;
  }
  else {
    uVar4 = (ulong)(byte)(&DAT_fffffff007113da0)[iVar5 - 1U] << 0x3b;
  }
  if (7 < param_3) {
    uVar2 = *(uint *)(*(long *)(lVar3 + 0x230) + 0x68);
    if ((ulong)(uVar2 + 1) * 8 + 8 <= param_3) {
      lVar6 = (ulong)uVar2 * 8;
      iVar5 = (int)lVar6;
      puVar1 = (ulong *)((long)param_2 + (long)iVar5 + 8);
      if (lVar6 - iVar5 != 0) {
        puVar1 = (ulong *)((ulong)(param_2 + (ulong)uVar2 * 2 + 2) & 0xffffffffffff |
                          0x2bad000000000000);
      }
      *puVar1 = *(ulong *)(lVar3 + 0x228) & 0x1ffffffffffffff | uVar4;
      *param_2 = uVar2 + 1;
      *(int *)(*(long *)(lVar3 + 0x230) + 0x68) = *(int *)(*(long *)(lVar3 + 0x230) + 0x68) + 1;
    }
  }
  return;
}

