// FUN_fffffff009c20460 @ fffffff009c20460 size=296

/* WARNING: Removing unreachable block (ram,0xfffffff009c20520) */

void FUN_fffffff009c20460(long param_1)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined *local_50;
  undefined8 local_48;
  code *local_40;
  undefined *local_38;
  long lStack_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  FUN_fffffff009c24830();
  if (*(long *)(param_1 + 0x210) != 0) {
    local_50 = PTR_DAT_fffffff00806c9b8;
    local_48 = DAT_fffffff0078a1280;
    local_40 = FUN_fffffff009c24a9c;
    local_38 = &DAT_fffffff008067248;
    lStack_30 = param_1;
    thunk_EXT_FUN_801100000389d600(&local_38,*(long *)(param_1 + 0x210),&local_50);
  }
  puVar1 = *(undefined8 **)(param_1 + 0x260);
  if (puVar1 != (undefined8 *)0x0) {
    lVar2 = *(long *)(param_1 + 0x178);
    uVar4 = puVar1[1];
    uVar3 = *puVar1;
    uVar6 = puVar1[3];
    uVar5 = puVar1[2];
    uVar8 = puVar1[5];
    uVar7 = puVar1[4];
    uVar10 = puVar1[7];
    uVar9 = puVar1[6];
    uVar12 = puVar1[9];
    uVar11 = puVar1[8];
    uVar14 = puVar1[0xb];
    uVar13 = puVar1[10];
    uVar16 = puVar1[0xd];
    uVar15 = puVar1[0xc];
    uVar18 = puVar1[0xf];
    uVar17 = puVar1[0xe];
    *(undefined4 *)(lVar2 + 0xb4) = *(undefined4 *)(puVar1 + 0x10);
    *(undefined8 *)(lVar2 + 0xac) = uVar18;
    *(undefined8 *)(lVar2 + 0xa4) = uVar17;
    *(undefined8 *)(lVar2 + 0x9c) = uVar16;
    *(undefined8 *)(lVar2 + 0x94) = uVar15;
    *(undefined8 *)(lVar2 + 0x8c) = uVar14;
    *(undefined8 *)(lVar2 + 0x84) = uVar13;
    *(undefined8 *)(lVar2 + 0x7c) = uVar12;
    *(undefined8 *)(lVar2 + 0x74) = uVar11;
    *(undefined8 *)(lVar2 + 0x6c) = uVar10;
    *(undefined8 *)(lVar2 + 100) = uVar9;
    *(undefined8 *)(lVar2 + 0x5c) = uVar8;
    *(undefined8 *)(lVar2 + 0x54) = uVar7;
    *(undefined8 *)(lVar2 + 0x4c) = uVar6;
    *(undefined8 *)(lVar2 + 0x44) = uVar5;
    *(undefined8 *)(lVar2 + 0x3c) = uVar4;
    *(undefined8 *)(lVar2 + 0x34) = uVar3;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_28) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

