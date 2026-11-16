// FUN_fffffff00994cb88 @ fffffff00994cb88 size=48

undefined4 FUN_fffffff00994cb88(long param_1,int param_2)

{
  undefined4 *puVar1;
  ulong uVar2;
  
  uVar2 = (long)param_2 << 4 | 0xc;
  puVar1 = (undefined4 *)(param_1 + 0x40 + (long)(int)uVar2);
  if (uVar2 != (long)(int)uVar2) {
    puVar1 = (undefined4 *)(param_1 + 0x40 + uVar2 & 0xffffffffffff | 0x2bad000000000000);
  }
  return *puVar1;
}

