// FUN_fffffff0081a6550 @ fffffff0081a6550 size=288

long FUN_fffffff0081a6550(long param_1,long *param_2)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  
  if (*(long *)(param_1 + 0x1328) == 0) {
    lVar6 = 0;
  }
  else {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1348));
    uVar2 = *(uint *)(param_1 + 0x1338);
    if (uVar2 != 0) {
      uVar4 = *(uint *)(param_1 + 0x133c);
      uVar5 = uVar2;
      do {
        uVar3 = 0;
        if (uVar2 != 0) {
          uVar3 = uVar4 / uVar2;
        }
        uVar3 = uVar4 - uVar3 * uVar2;
        uVar7 = (ulong)uVar3;
        pcVar1 = (char *)(*(long *)(param_1 + 0x1328) + (long)(int)uVar3);
        if (uVar7 != (long)(int)uVar3) {
          pcVar1 = (char *)(*(long *)(param_1 + 0x1328) + uVar7 & 0xffffffffffff |
                           0x2bad000000000000);
        }
        if (*pcVar1 == '\0') {
          uVar8 = (ulong)(uVar3 * *(int *)(param_1 + 0x1330));
          lVar6 = (**(code **)(**(long **)(*(long *)(param_1 + 0x1318) + 0x50) + 0x98))();
          *param_2 = lVar6 + uVar8;
          uVar2 = *(uint *)(param_1 + 0x1338);
          uVar4 = 0;
          if (uVar2 != 0) {
            uVar4 = (uVar3 + 1) / uVar2;
          }
          pcVar1 = (char *)(*(long *)(param_1 + 0x1328) + (long)(int)uVar3);
          if (uVar7 != (long)(int)uVar3) {
            pcVar1 = (char *)(*(long *)(param_1 + 0x1328) + uVar7 & 0xffffffffffff |
                             0x2bad000000000000);
          }
          *(uint *)(param_1 + 0x133c) = (uVar3 + 1) - uVar4 * uVar2;
          *pcVar1 = *pcVar1 + '\x01';
          lVar6 = *(long *)(param_1 + 0x1320) + uVar8;
          goto LAB_fffffff0081a6640;
        }
        uVar4 = uVar4 + 1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    lVar6 = 0;
LAB_fffffff0081a6640:
    *(uint *)(param_1 + 0x1340) = (uint)(lVar6 == 0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1348));
  }
  return lVar6;
}

