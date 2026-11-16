// FUN_fffffff00a51a514 @ fffffff00a51a514 size=152

ulong FUN_fffffff00a51a514(long param_1,long param_2)

{
  ulong uVar1;
  bool bVar2;
  ulong uVar3;
  ulong uVar4;
  
  if ((param_2 == 0) || (uVar3 = *(ulong *)(param_1 + 0x4a0), *(ulong *)(param_1 + 0x4a0) == 0)) {
    uVar3 = 0;
  }
  else {
    do {
      uVar4 = uVar3;
      uVar3 = *(ulong *)(uVar4 + 0x30);
    } while (*(ulong *)(uVar4 + 0x30) != 0);
    if (*(long *)(uVar4 + 0x78) == param_2) {
      return uVar4;
    }
    do {
      uVar1 = *(ulong *)(uVar4 + 0x38);
      if (*(ulong *)(uVar4 + 0x38) == 0) {
        uVar3 = *(ulong *)(uVar4 + 0x40) & 0xfffffffffffffffe;
        if ((uVar3 == 0) || (uVar4 != *(ulong *)(uVar3 + 0x30))) {
          do {
            uVar3 = *(ulong *)(uVar4 + 0x40) & 0xfffffffffffffffe;
            if (uVar3 == 0) {
              return 0;
            }
            bVar2 = uVar4 == *(ulong *)(uVar3 + 0x38);
            uVar4 = uVar3;
          } while (bVar2);
        }
      }
      else {
        do {
          uVar3 = uVar1;
          uVar1 = *(ulong *)(uVar3 + 0x30);
        } while (*(ulong *)(uVar3 + 0x30) != 0);
      }
      uVar4 = uVar3;
    } while (*(long *)(uVar3 + 0x78) != param_2);
  }
  return uVar3;
}

