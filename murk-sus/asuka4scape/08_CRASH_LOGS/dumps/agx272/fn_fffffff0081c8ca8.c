// FUN_fffffff0081c8ca8 @ fffffff0081c8ca8 size=200

undefined8 FUN_fffffff0081c8ca8(long param_1,uint param_2,uint param_3)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  uint *puVar6;
  long lVar7;
  long lVar8;
  
  lVar1 = *(long *)(param_1 + 0x280) + 0x10ab8;
  lVar7 = (ulong)param_3 * 0x278;
  uVar5 = lVar1 + (int)lVar7;
  if (lVar7 - (int)lVar7 != 0) {
    uVar5 = lVar1 + lVar7 & 0xffffffffffffU | 0x2bad000000000000;
  }
  uVar4 = *(uint *)(uVar5 + 0x14);
  if (param_2 <= *(uint *)(uVar5 + 0x14)) {
    uVar4 = param_2;
  }
  *(uint *)(uVar5 + 0xc) = uVar4;
  lVar8 = *(long *)(param_1 + 0x918);
  lVar7 = lVar8 + 0xc4;
  lVar1 = (ulong)param_3 + (ulong)param_3 * 4;
  uVar2 = lVar1 * 8 | 4;
  puVar6 = (uint *)(lVar7 + (int)uVar2);
  if (uVar2 != (long)(int)uVar2) {
    puVar6 = (uint *)(lVar7 + uVar2 & 0xffffffffffff | 0x2bad000000000000);
  }
  if (*(uint *)(uVar5 + 0x50) != 0) {
    uVar4 = *(uint *)(uVar5 + 0x50);
  }
  *puVar6 = uVar4;
  uVar3 = uVar4 - 500;
  if (*(uint *)(uVar5 + 0x1c) <= uVar4 - 500) {
    uVar3 = *(uint *)(uVar5 + 0x1c);
  }
  uVar4 = uVar3;
  if (*(uint *)(uVar5 + 0x54) != 0) {
    uVar4 = *(uint *)(uVar5 + 0x54);
  }
  lVar1 = lVar1 * 8 + 8;
  puVar6 = (uint *)(lVar7 + (int)lVar1);
  if (lVar1 != (int)lVar1) {
    puVar6 = (uint *)(lVar7 + lVar1 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *(uint *)(uVar5 + 0x10) = uVar3;
  *puVar6 = uVar4;
  *(undefined4 *)(lVar8 + 0xc4) = 1;
  return 0;
}

