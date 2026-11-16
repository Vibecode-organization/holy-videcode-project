// FUN_fffffff009967330 @ fffffff009967330 size=112

long FUN_fffffff009967330(long param_1)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = (**(code **)(**(long **)(param_1 + 0x20) + 0xa0))();
  if ((*(byte *)(param_1 + 0x10) & 0x7f) == 0) {
    uVar2 = *(ulong *)(param_1 + 0x48);
  }
  else if (*(byte *)(param_1 + 0x10) == 0x82) {
    uVar2 = (ulong)*(uint *)(param_1 + 0x4c);
  }
  else {
    uVar2 = 0;
  }
  return uVar2 + lVar1;
}

