// FUN_fffffff0081d5d54 @ fffffff0081d5d54 size=156

void FUN_fffffff0081d5d54(long param_1,undefined8 param_2,uint *param_3,ulong param_4)

{
  uint *puVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = (**(code **)(**(long **)(*(long *)(param_1 + 0x115b0) + 0x60) + 0x78))();
  lVar2 = (param_4 & 0xffffffff) * 0x10;
  puVar1 = (uint *)(lVar3 + (int)lVar2);
  if (lVar2 != (int)lVar2) {
    puVar1 = (uint *)(lVar3 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *param_3 = puVar1[2] & 0x3fffff;
  param_3[1] = puVar1[3] & 0x3fffff;
  param_3[2] = puVar1[3] >> 0x1f;
  param_3[3] = *puVar1 & 1;
  return;
}

