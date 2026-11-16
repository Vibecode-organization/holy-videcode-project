// FUN_fffffff008183924 @ fffffff008183924 size=552

void FUN_fffffff008183924
               (long *param_1,uint *param_2,int param_3,undefined8 param_4,undefined4 param_5,
               long param_6)

{
  uint uVar1;
  int *piVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  undefined4 *puVar12;
  ulong uVar13;
  uint *puVar14;
  
  lVar10 = param_1[2];
  lVar7 = (**(code **)(**(long **)(*(long *)(lVar10 + 0x183b0) + 0x50) + 0x98))();
  uVar4 = *(uint *)(lVar10 + 0x4a4);
  lVar11 = param_1[2];
  lVar10 = (**(code **)(**(long **)(*(long *)(lVar11 + 0x183a8) + 0x50) + 0x98))();
  if (*param_2 != 0) {
    uVar13 = 0;
    uVar5 = *(uint *)(lVar11 + 0x4a0);
    uVar9 = *(ulong *)(param_1[2] + 0x5c8);
    do {
      puVar12 = *(undefined4 **)(param_6 + 8 + uVar13 * 8);
      puVar14 = param_2 + 1 + uVar13 * 3;
      if ((((ulong)(param_2 + 1) ^ (ulong)puVar14) & 0xffc0000000000000) != 0) {
        puVar14 = (uint *)((ulong)puVar14 & 0xffffffffffff | 0xc8a2000000000000);
      }
      uVar6 = puVar14[1];
      uVar8 = (**(code **)(**(long **)(param_1[2] + 0x148) + 0x88))
                        (*(long **)(param_1[2] + 0x148),(long)(int)uVar6);
      lVar11 = (long)(int)uVar6 * 4;
      piVar2 = (int *)(*(long *)(param_1[2] + 0x11e10) + (long)(int)lVar11);
      if (lVar11 - (int)lVar11 != 0) {
        piVar2 = (int *)(*(long *)(param_1[2] + 0x11e10) + lVar11 & 0xffffffffffffU |
                        0x2bad000000000000);
      }
      lVar11 = lVar7 + (ulong)uVar4 + (uVar8 & 0xffffffff);
      uVar1 = 0;
      if (*piVar2 != param_3) {
        uVar1 = (uint)(uVar9 >> 10) & 1;
      }
      lVar3 = lVar11;
      if (uVar1 == 1) {
        lVar3 = lVar10 + (ulong)uVar5 + (uVar8 & 0xffffffff);
      }
      *puVar12 = 4;
      *(long *)(puVar12 + 1) = lVar3;
      puVar12[5] = *puVar14;
      *(undefined8 *)(puVar12 + 10) = param_4;
      puVar12[8] = uVar6;
      puVar12[9] = param_5;
      puVar12[0xc] = uVar1;
      puVar12[0xe] = 0;
      *(long *)(puVar12 + 3) = lVar11;
      (**(code **)(*param_1 + 200))(param_1,*(undefined8 *)(param_6 + 0x80 + uVar13 * 8),puVar12,0);
      uVar13 = uVar13 + 1;
    } while (uVar13 < *param_2);
  }
  return;
}

