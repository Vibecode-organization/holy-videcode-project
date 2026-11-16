// FUN_fffffff009961688 @ fffffff009961688 size=52

void FUN_fffffff009961688(long param_1,ulong param_2,long param_3,long param_4)

{
  ulong uVar1;
  long lVar2;
  
  for (lVar2 = *(long *)(param_1 + 0x168); lVar2 != 0; lVar2 = *(long *)(lVar2 + 0x30)) {
    if (lVar2 != param_4) {
      uVar1 = *(long *)(lVar2 + 0x78) + param_3;
      if (param_2 <= uVar1) {
        uVar1 = param_2;
      }
      *(ulong *)(lVar2 + 0x78) = uVar1;
    }
  }
  return;
}

