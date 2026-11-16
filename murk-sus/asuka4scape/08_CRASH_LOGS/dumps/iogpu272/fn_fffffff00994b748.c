// FUN_fffffff00994b748 @ fffffff00994b748 size=96

bool FUN_fffffff00994b748(long param_1,uint param_2)

{
  int *piVar1;
  undefined8 *puVar2;
  ulong uVar3;
  int iVar4;
  
  uVar3 = (long)(int)param_2 << 4 | 8;
  piVar1 = (int *)(param_1 + 0x40 + (long)(int)uVar3);
  if (uVar3 != (long)(int)uVar3) {
    piVar1 = (int *)(param_1 + 0x40 + uVar3 & 0xffffffffffff | 0x2bad000000000000);
  }
  uVar3 = -(ulong)(param_2 >> 0x1f) & 0xfffffff800000000 | (ulong)param_2 << 3;
  iVar4 = (int)((ulong)param_2 << 3);
  puVar2 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)iVar4);
  if (uVar3 != (long)iVar4) {
    puVar2 = (undefined8 *)(*(long *)(param_1 + 0x20) + uVar3 & 0xffffffffffff | 0x2bad000000000000)
    ;
  }
  return *piVar1 - *(int *)*puVar2 < 1;
}

