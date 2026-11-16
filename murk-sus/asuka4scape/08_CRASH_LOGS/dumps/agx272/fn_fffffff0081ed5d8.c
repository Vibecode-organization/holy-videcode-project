// FUN_fffffff0081ed5d8 @ fffffff0081ed5d8 size=152

void FUN_fffffff0081ed5d8(long param_1,long *param_2)

{
  uint *puVar1;
  ulong uVar2;
  long lVar3;
  
  (**(code **)(*param_2 + 0x80))(param_2);
  uVar2 = (**(code **)(*(long *)param_2[3] + 0xa0))();
  lVar3 = (ulong)*(uint *)((long)param_2 + 0xc) * 8;
  puVar1 = (uint *)(*(long *)(param_1 + 0x80) + (long)(int)lVar3);
  if (lVar3 - (int)lVar3 != 0) {
    puVar1 = (uint *)(*(long *)(param_1 + 0x80) + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar1 = (uint)(uVar2 >> 0xf) & 0x1ffffff;
  *(undefined1 *)(param_2 + 2) = 1;
  return;
}

