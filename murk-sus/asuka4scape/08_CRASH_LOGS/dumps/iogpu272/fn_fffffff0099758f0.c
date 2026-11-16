// FUN_fffffff0099758f0 @ fffffff0099758f0 size=188

bool FUN_fffffff0099758f0(long param_1,long param_2,uint param_3)

{
  ulong uVar1;
  ulong uVar2;
  uint *puVar3;
  ulong *puVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  ulong *puVar8;
  
  lVar7 = (ulong)param_3 * 4;
  iVar5 = (int)lVar7;
  puVar3 = (uint *)((long)&DAT_fffffff00af227c0 + (long)iVar5);
  if (lVar7 != iVar5) {
    puVar3 = (uint *)((ulong)(&DAT_fffffff00af227c0 + param_3) & 0xffffffffffff | 0x2bad000000000000
                     );
  }
  lVar7 = (ulong)param_3 * 8;
  iVar5 = (int)lVar7;
  if (*puVar3 == 0) {
    puVar4 = (ulong *)(param_1 + 0x118 + (long)iVar5);
    if (lVar7 - iVar5 != 0) {
      puVar4 = (ulong *)(param_1 + 0x118 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar6 = *puVar4;
  }
  else {
    uVar6 = (ulong)*puVar3 << 0x14;
    if (*(ulong *)(param_1 + 0x2c8) <= uVar6) {
      uVar6 = *(ulong *)(param_1 + 0x2c8);
    }
  }
  uVar1 = param_1 + 0x128;
  puVar4 = (ulong *)(uVar1 + (long)iVar5);
  if (lVar7 - iVar5 != 0) {
    puVar4 = (ulong *)(uVar1 + lVar7 & 0xffffffffffff | 0x2bad000000000000);
  }
  do {
    uVar2 = *puVar4 + param_2;
    if (uVar6 < uVar2) goto LAB_fffffff0099759a0;
    puVar8 = (ulong *)(uVar1 + (ulong)param_3 * 8);
    if (((uVar1 ^ (ulong)puVar8) & 0xffc0000000000000) != 0) {
      puVar8 = (ulong *)((ulong)puVar8 & 0xffffffffffff | 0xc8a2000000000000);
    }
  } while (*puVar8 != *puVar4);
  *puVar8 = uVar2;
LAB_fffffff0099759a0:
  return uVar2 <= uVar6;
}

