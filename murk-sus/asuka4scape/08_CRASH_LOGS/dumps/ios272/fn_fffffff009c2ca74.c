// FUN_fffffff009c2ca74 @ fffffff009c2ca74 size=132

bool FUN_fffffff009c2ca74(long param_1,uint param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  bool bVar5;
  ulong uVar6;
  
  if (param_2 < 2) {
    do {
      uVar6 = *(ulong *)(param_1 + 0x90);
      uVar1 = 0;
      if (uVar6 >> 0x20 != 0) {
        uVar1 = (uVar6 & 0xffffffff00000000) - 0x100000000;
      }
      uVar4 = (int)uVar6 - 1;
      uVar2 = 0;
      if ((int)uVar6 != 0) {
        uVar2 = (ulong)uVar4;
      }
      uVar3 = 0xffffffff;
      bVar5 = (uVar6 & 0xffffffff00000000) == 0x100000000;
      if (param_2 == 0) {
        uVar3 = 0xffffffff00000000;
        bVar5 = uVar4 == 0;
        uVar1 = uVar2;
      }
    } while (*(ulong *)(param_1 + 0x90) != uVar6);
    *(ulong *)(param_1 + 0x90) = uVar1 | uVar3 & uVar6;
  }
  else {
    bVar5 = false;
  }
  return bVar5;
}

