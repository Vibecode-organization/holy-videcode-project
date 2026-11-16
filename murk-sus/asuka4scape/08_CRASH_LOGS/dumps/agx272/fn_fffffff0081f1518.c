// FUN_fffffff0081f1518 @ fffffff0081f1518 size=224

void FUN_fffffff0081f1518(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  
  if ((*(int *)(param_1 + 0x14) == 0) && ((*(byte *)(param_1 + 0x151c) & 1) == 0)) {
    uVar2 = (ulong)*(uint *)(param_1 + 0x1518);
    if (1 < *(uint *)(param_1 + 0x1518)) {
      uVar1 = param_1 + 0x18;
      uVar3 = uVar2;
      do {
        uVar3 = uVar3 - 1;
        lVar5 = 1;
        uVar4 = uVar3;
        do {
          puVar6 = (undefined8 *)(uVar1 + lVar5 * 0x18 + -0x18);
          if (((uVar1 ^ (ulong)puVar6) & 0xffc0000000000000) != 0) {
            puVar6 = (undefined8 *)((ulong)puVar6 & 0xffffffffffff | 0xc8a2000000000000);
          }
          puVar7 = (undefined8 *)(uVar1 + lVar5 * 0x18);
          if (((uVar1 ^ (ulong)puVar7) & 0xffc0000000000000) != 0) {
            puVar7 = (undefined8 *)((ulong)puVar7 & 0xffffffffffff | 0xc8a2000000000000);
          }
          if (*(byte *)(puVar7 + 1) < *(byte *)(puVar6 + 1)) {
            uVar8 = puVar6[2];
            uVar10 = puVar6[1];
            uVar9 = *puVar6;
            uVar11 = *puVar7;
            puVar6[1] = puVar7[1];
            *puVar6 = uVar11;
            puVar6[2] = puVar7[2];
            puVar7[1] = uVar10;
            *puVar7 = uVar9;
            puVar7[2] = uVar8;
          }
          lVar5 = lVar5 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        uVar2 = uVar2 - 1;
      } while ((uVar2 & 0xfffffffe) != 0);
    }
    *(byte *)(param_1 + 0x151c) = 1;
    return;
  }
  return;
}

