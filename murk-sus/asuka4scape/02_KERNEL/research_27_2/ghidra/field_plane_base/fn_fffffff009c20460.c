// FUN_fffffff009c20460 @ fffffff009c20460

/* WARNING: Removing unreachable block (ram,0xfffffff009c20520) */

bool FUN_fffffff009c20460(long param_1)

{
  bool bVar1;
  undefined8 *puVar2;
  long lVar3;
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
  undefined8 uVar19;
  undefined *local_50;
  undefined8 local_48;
  code *local_40;
  undefined *local_38;
  long lStack_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  FUN_fffffff009c24830(param_1);
  bVar1 = false;
  if (*(long *)(param_1 + 0x210) != 0) {
    local_50 = PTR_DAT_fffffff00806c9b8;
    local_48 = DAT_fffffff0078a1280;
    local_40 = FUN_fffffff009c24a9c;
    local_38 = &DAT_fffffff008067248;
    lStack_30 = param_1;
    bVar1 = thunk_FUN_fffffff00a8a1600(*(long *)(param_1 + 0x210),(long)&local_50);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x260);
  if (puVar2 != (undefined8 *)0x0) {
    lVar3 = *(long *)(param_1 + 0x178);
    uVar5 = puVar2[1];
    uVar4 = *puVar2;
    uVar7 = puVar2[3];
    uVar6 = puVar2[2];
    uVar9 = puVar2[5];
    uVar8 = puVar2[4];
    uVar11 = puVar2[7];
    uVar10 = puVar2[6];
    uVar13 = puVar2[9];
    uVar12 = puVar2[8];
    uVar15 = puVar2[0xb];
    uVar14 = puVar2[10];
    uVar17 = puVar2[0xd];
    uVar16 = puVar2[0xc];
    uVar19 = puVar2[0xf];
    uVar18 = puVar2[0xe];
    *(undefined4 *)(lVar3 + 0xb4) = *(undefined4 *)(puVar2 + 0x10);
    *(undefined8 *)(lVar3 + 0xac) = uVar19;
    *(undefined8 *)(lVar3 + 0xa4) = uVar18;
    *(undefined8 *)(lVar3 + 0x9c) = uVar17;
    *(undefined8 *)(lVar3 + 0x94) = uVar16;
    *(undefined8 *)(lVar3 + 0x8c) = uVar15;
    *(undefined8 *)(lVar3 + 0x84) = uVar14;
    *(undefined8 *)(lVar3 + 0x7c) = uVar13;
    *(undefined8 *)(lVar3 + 0x74) = uVar12;
    *(undefined8 *)(lVar3 + 0x6c) = uVar11;
    *(undefined8 *)(lVar3 + 100) = uVar10;
    *(undefined8 *)(lVar3 + 0x5c) = uVar9;
    *(undefined8 *)(lVar3 + 0x54) = uVar8;
    *(undefined8 *)(lVar3 + 0x4c) = uVar7;
    *(undefined8 *)(lVar3 + 0x44) = uVar6;
    *(undefined8 *)(lVar3 + 0x3c) = uVar5;
    *(undefined8 *)(lVar3 + 0x34) = uVar4;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_28) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return bVar1;
}

