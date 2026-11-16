// FUN_fffffff008179d58 @ fffffff008179d58 size=232

undefined8 FUN_fffffff008179d58(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  
  uVar2 = param_1[1];
  if (uVar2 != param_2[1]) {
    return 0;
  }
  uVar1 = *param_1;
  if (*param_2 <= *param_1) {
    uVar1 = *param_2;
  }
  if ((uVar1 == 0) || (uVar2 == 0)) {
    return 1;
  }
  uVar5 = 0;
  do {
    lVar6 = 0;
    uVar7 = (ulong)uVar2;
    do {
      puVar3 = param_1 + 0x12 + uVar5 * 2;
      if ((((ulong)(param_1 + 0x12) ^ (ulong)puVar3) & 0xffc0000000000000) != 0) {
        puVar3 = (uint *)((ulong)puVar3 & 0xffffffffffff | 0xc8a2000000000000);
      }
      puVar4 = param_2 + 0x12 + uVar5 * 2;
      if ((((ulong)(param_2 + 0x12) ^ (ulong)puVar4) & 0xffc0000000000000) != 0) {
        puVar4 = (uint *)((ulong)puVar4 & 0xffffffffffff | 0xc8a2000000000000);
      }
      if (puVar3[lVar6] != puVar4[lVar6]) {
        return 0;
      }
      puVar3 = param_1 + 0x32 + uVar5 * 2;
      if ((((ulong)(param_1 + 0x32) ^ (ulong)puVar3) & 0xffc0000000000000) != 0) {
        puVar3 = (uint *)((ulong)puVar3 & 0xffffffffffff | 0xc8a2000000000000);
      }
      puVar4 = param_2 + 0x32 + uVar5 * 2;
      if ((((ulong)(param_2 + 0x32) ^ (ulong)puVar4) & 0xffc0000000000000) != 0) {
        puVar4 = (uint *)((ulong)puVar4 & 0xffffffffffff | 0xc8a2000000000000);
      }
      if (puVar3[lVar6] != puVar4[lVar6]) {
        return 0;
      }
      lVar6 = lVar6 + 1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
    uVar5 = uVar5 + 1;
    if (uVar5 == uVar1) {
      return 1;
    }
  } while( true );
}

