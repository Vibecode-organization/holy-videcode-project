// FUN_fffffff0081d16a0 @ fffffff0081d16a0 size=88

undefined8 FUN_fffffff0081d16a0(long param_1,uint param_2,int param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  long lVar5;
  
  lVar1 = *(long *)(param_1 + 0x2a0) + 0x26d0;
  lVar5 = (ulong)param_2 * 0x10;
  puVar4 = (undefined8 *)(lVar1 + (int)lVar5);
  if (lVar5 != (int)lVar5) {
    puVar4 = (undefined8 *)(lVar1 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar2 = (ulong)param_2 << 4 | 8;
  puVar3 = (undefined8 *)(lVar1 + (int)uVar2);
  if (uVar2 != (long)(int)uVar2) {
    puVar3 = (undefined8 *)(lVar1 + uVar2 & 0xffffffffffff | 0x2bad000000000000);
  }
  if (param_3 == 0) {
    puVar4 = puVar3;
  }
  return *puVar4;
}

