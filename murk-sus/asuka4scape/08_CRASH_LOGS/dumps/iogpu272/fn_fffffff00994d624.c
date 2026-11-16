// FUN_fffffff00994d624 @ fffffff00994d624 size=88

undefined4 FUN_fffffff00994d624(long param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  ulong uVar4;
  
  uVar4 = (long)(int)param_2 << 4 | 0xc;
  puVar1 = (undefined4 *)(param_1 + 0x40 + (long)(int)uVar4);
  if (uVar4 != (long)(int)uVar4) {
    puVar1 = (undefined4 *)(param_1 + 0x40 + uVar4 & 0xffffffffffff | 0x2bad000000000000);
  }
  uVar4 = -(ulong)(param_2 >> 0x1f) & 0xfffffff800000000 | (ulong)param_2 << 3;
  iVar3 = (int)((ulong)param_2 << 3);
  puVar2 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)iVar3);
  if (uVar4 != (long)iVar3) {
    puVar2 = (undefined8 *)(*(long *)(param_1 + 0x20) + uVar4 & 0xffffffffffff | 0x2bad000000000000)
    ;
  }
  *param_3 = *puVar1;
  return *(undefined4 *)*puVar2;
}

