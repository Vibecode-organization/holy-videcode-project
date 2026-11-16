// FUN_fffffff00996d850 @ fffffff00996d850 size=40

undefined8 FUN_fffffff00996d850(long param_1,ulong param_2)

{
  undefined8 *puVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  
  uVar2 = (param_2 & 0xffffffff) << 3;
  uVar4 = -(param_2 >> 0x1f & 1) & 0xfffffff800000000 | uVar2;
  iVar3 = (int)uVar2;
  puVar1 = (undefined8 *)(*(long *)(param_1 + 0x18) + (long)iVar3);
  if (uVar4 != (long)iVar3) {
    puVar1 = (undefined8 *)(*(long *)(param_1 + 0x18) + uVar4 & 0xffffffffffff | 0x2bad000000000000)
    ;
  }
  return *puVar1;
}

