// FUN_fffffff009c2c9ec @ fffffff009c2c9ec size=136

bool FUN_fffffff009c2c9ec(long param_1,uint param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  bool bVar4;
  int iVar5;
  ulong uVar6;
  
  if (param_2 < 2) {
    do {
      uVar6 = *(ulong *)(param_1 + 0x90);
      uVar1 = (uVar6 & 0xffffffff00000000) + 0x100000000;
      if (0xfffffffeffffffff < uVar6) {
        uVar1 = 0xffffffff00000000;
      }
      iVar5 = (int)uVar6;
      uVar2 = 0xffffffff;
      if (iVar5 != -1) {
        uVar2 = (ulong)(iVar5 + 1);
      }
      uVar3 = 0xffffffff;
      bVar4 = uVar6 >> 0x20 == 0;
      if (param_2 == 0) {
        uVar3 = 0xffffffff00000000;
        bVar4 = iVar5 == 0;
        uVar1 = uVar2;
      }
    } while (*(ulong *)(param_1 + 0x90) != uVar6);
    *(ulong *)(param_1 + 0x90) = uVar1 | uVar3 & uVar6;
  }
  else {
    bVar4 = false;
  }
  return bVar4;
}

