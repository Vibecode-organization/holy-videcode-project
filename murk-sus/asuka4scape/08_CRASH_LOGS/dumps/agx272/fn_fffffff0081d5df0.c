// FUN_fffffff0081d5df0 @ fffffff0081d5df0 size=224

void FUN_fffffff0081d5df0(long param_1,long param_2,uint *param_3,ulong param_4)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  
  lVar6 = (**(code **)(**(long **)(*(long *)(param_1 + 0x115b0) + 0x60) + 0x78))();
  lVar5 = (param_4 & 0xffffffff) * 0x10;
  puVar2 = (uint *)(lVar6 + (int)lVar5);
  if (lVar5 != (int)lVar5) {
    puVar2 = (uint *)(lVar6 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar3 = *puVar2;
  uVar4 = puVar2[1];
  uVar1 = (uint)(*(ulong *)(param_2 + 0x20) >> 4) & 0xfffffff8;
  *puVar2 = uVar1 | uVar3 & 7;
  uVar1 = uVar1 | uVar3 & 6;
  if (param_3[3] != 0) {
    uVar1 = uVar1 + 1;
  }
  *puVar2 = uVar1;
  uVar1 = *(uint *)(param_2 + 0x21) & 0xf0000000;
  puVar2[1] = uVar1 | uVar4 & 0xfffffff;
  puVar2[1] = uVar1 | uVar4 & 0xfc00000 | *(uint *)(param_2 + 0x2c) & 0x3fffff;
  uVar1 = puVar2[3];
  puVar2[2] = puVar2[2] & 0xffc00000 | *param_3 & 0x3fffff;
  uVar3 = param_3[1];
  puVar2[3] = uVar1 & 0xffc00000 | uVar3 & 0x3fffff;
  puVar2[3] = uVar1 & 0x7fc00000 | uVar3 & 0x3fffff | param_3[2] << 0x1f;
  return;
}

