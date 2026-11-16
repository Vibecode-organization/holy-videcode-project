// FUN_fffffff00994afcc @ fffffff00994afcc size=100

void FUN_fffffff00994afcc(long param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  ulong uVar3;
  
  uVar3 = (long)param_2 << 4 | 8;
  puVar2 = (uint *)(param_1 + 0x40 + (long)(int)uVar3);
  if (uVar3 != (long)(int)uVar3) {
    puVar2 = (uint *)(param_1 + 0x40 + uVar3 & 0xffffffffffff | 0x2bad000000000000);
  }
  uVar1 = *puVar2 + 0x100;
  if ((uVar1 ^ *puVar2) >> 0x1e != 0) {
    FUN_fffffff009975568(*(undefined8 *)(param_1 + 0x10));
  }
  *puVar2 = uVar1;
  return;
}

