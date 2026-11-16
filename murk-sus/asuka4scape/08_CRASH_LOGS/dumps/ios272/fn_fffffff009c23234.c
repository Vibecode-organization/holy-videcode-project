// FUN_fffffff009c23234 @ fffffff009c23234 size=364

/* WARNING: Removing unreachable block (ram,0xfffffff009c23388) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c232b0) */

void FUN_fffffff009c23234(long param_1)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 *puVar3;
  long lVar4;
  ulong unaff_x30;
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
  undefined8 uVar20;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  if (((*(long **)(param_1 + 0x1a8) == (long *)0x0) || (*(long *)(param_1 + 0x210) == 0)) ||
     (uVar2 = (**(code **)(**(long **)(param_1 + 0x1a8) + 0x148))(), (uVar2 & 1) != 0)) {
    puVar3 = *(undefined8 **)(param_1 + 0x260);
    lVar4 = *(long *)(param_1 + 0x178);
    if (puVar3 == (undefined8 *)0x0) {
      *(undefined4 *)(lVar4 + 0xb4) = 0;
      uVar5 = 0;
      uVar6 = 0;
      *(undefined8 *)(lVar4 + 0xac) = 0;
      *(undefined8 *)(lVar4 + 0xa4) = 0;
      *(undefined8 *)(lVar4 + 0x9c) = 0;
      *(undefined8 *)(lVar4 + 0x94) = 0;
      *(undefined8 *)(lVar4 + 0x8c) = 0;
      *(undefined8 *)(lVar4 + 0x84) = 0;
      *(undefined8 *)(lVar4 + 0x7c) = 0;
      *(undefined8 *)(lVar4 + 0x74) = 0;
      *(undefined8 *)(lVar4 + 0x6c) = 0;
      *(undefined8 *)(lVar4 + 100) = 0;
      *(undefined8 *)(lVar4 + 0x5c) = 0;
      *(undefined8 *)(lVar4 + 0x54) = 0;
      *(undefined8 *)(lVar4 + 0x4c) = 0;
      *(undefined8 *)(lVar4 + 0x44) = 0;
    }
    else {
      uVar6 = puVar3[1];
      uVar5 = *puVar3;
      uVar8 = puVar3[3];
      uVar7 = puVar3[2];
      uVar10 = puVar3[5];
      uVar9 = puVar3[4];
      uVar12 = puVar3[7];
      uVar11 = puVar3[6];
      uVar14 = puVar3[9];
      uVar13 = puVar3[8];
      uVar16 = puVar3[0xb];
      uVar15 = puVar3[10];
      uVar18 = puVar3[0xd];
      uVar17 = puVar3[0xc];
      uVar20 = puVar3[0xf];
      uVar19 = puVar3[0xe];
      *(undefined4 *)(lVar4 + 0xb4) = *(undefined4 *)(puVar3 + 0x10);
      *(undefined8 *)(lVar4 + 0xac) = uVar20;
      *(undefined8 *)(lVar4 + 0xa4) = uVar19;
      *(undefined8 *)(lVar4 + 0x9c) = uVar18;
      *(undefined8 *)(lVar4 + 0x94) = uVar17;
      *(undefined8 *)(lVar4 + 0x8c) = uVar16;
      *(undefined8 *)(lVar4 + 0x84) = uVar15;
      *(undefined8 *)(lVar4 + 0x7c) = uVar14;
      *(undefined8 *)(lVar4 + 0x74) = uVar13;
      *(undefined8 *)(lVar4 + 0x6c) = uVar12;
      *(undefined8 *)(lVar4 + 100) = uVar11;
      *(undefined8 *)(lVar4 + 0x5c) = uVar10;
      *(undefined8 *)(lVar4 + 0x54) = uVar9;
      *(undefined8 *)(lVar4 + 0x4c) = uVar8;
      *(undefined8 *)(lVar4 + 0x44) = uVar7;
    }
    *(undefined8 *)(lVar4 + 0x3c) = uVar6;
    *(undefined8 *)(lVar4 + 0x34) = uVar5;
  }
  else {
    if (*(long **)(param_1 + 0x1a8) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x1a8) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x1a8) = 0;
    FUN_fffffff009c20460(param_1);
    *(uint *)(*(long *)(param_1 + 0x178) + 0x20) =
         (*(uint *)(*(long *)(param_1 + 0x178) + 0x20) | 1) + 2;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c23334);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  return;
}

