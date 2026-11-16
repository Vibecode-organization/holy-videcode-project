// FUN_fffffff009c2c6e8 @ fffffff009c2c6e8 size=304

void FUN_fffffff009c2c6e8(long param_1,long param_2,uint param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  bool bVar5;
  ulong uVar6;
  int iVar7;
  ulong uVar8;
  uint uVar9;
  long lVar10;
  
  uVar9 = param_3;
  if (3 < param_3) {
    uVar9 = 4;
  }
  uVar8 = (ulong)uVar9;
  *(char *)(param_1 + 0x34) = (char)uVar9;
  if (param_3 == 0) {
    uVar8 = 0;
  }
  else {
    lVar10 = 0;
    uVar6 = uVar8;
    do {
      *(undefined1 *)(param_1 + 0x38 + lVar10) = *(undefined1 *)(param_2 + 4 + lVar10);
      *(undefined1 *)(param_1 + 0x3c + lVar10) = *(undefined1 *)(param_2 + 8 + lVar10);
      *(undefined1 *)(param_1 + 0x40 + lVar10) = *(undefined1 *)(param_2 + 0xc + lVar10);
      *(undefined1 *)(param_1 + 0x44 + lVar10) = *(undefined1 *)(param_2 + 0x10 + lVar10);
      *(undefined1 *)(param_1 + 0x48 + lVar10) = *(undefined1 *)(param_2 + 0x14 + lVar10);
      lVar10 = lVar10 + 1;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
    if (3 < param_3) {
      return;
    }
  }
  lVar10 = uVar8 - 4;
  do {
    iVar7 = (int)uVar8;
    puVar4 = (undefined1 *)(param_1 + 0x38 + (long)iVar7);
    if (uVar8 != (long)iVar7) {
      puVar4 = (undefined1 *)(param_1 + 0x38 + uVar8 & 0xffffffffffff | 0x2bad000000000000);
    }
    puVar1 = (undefined1 *)(param_1 + 0x3c + (long)iVar7);
    if (uVar8 != (long)iVar7) {
      puVar1 = (undefined1 *)(param_1 + 0x3c + uVar8 & 0xffffffffffff | 0x2bad000000000000);
    }
    puVar2 = (undefined1 *)(param_1 + 0x40 + (long)iVar7);
    if (uVar8 != (long)iVar7) {
      puVar2 = (undefined1 *)(param_1 + 0x40 + uVar8 & 0xffffffffffff | 0x2bad000000000000);
    }
    puVar3 = (undefined1 *)(param_1 + 0x44 + (long)iVar7);
    if (uVar8 != (long)iVar7) {
      puVar3 = (undefined1 *)(param_1 + 0x44 + uVar8 & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar4 = 0;
    puVar4 = (undefined1 *)(param_1 + 0x48 + (long)iVar7);
    if (uVar8 != (long)iVar7) {
      puVar4 = (undefined1 *)(param_1 + 0x48 + uVar8 & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar1 = 0;
    *puVar2 = 0;
    *puVar3 = 0;
    *puVar4 = 0;
    uVar8 = uVar8 + 1;
    bVar5 = lVar10 != -1;
    lVar10 = lVar10 + 1;
  } while (bVar5);
  return;
}

