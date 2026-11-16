// FUN_fffffff0081878ec @ fffffff0081878ec size=12

/* WARNING: Removing unreachable block (ram,0xfffffff008187d18) */
/* WARNING: Removing unreachable block (ram,0xfffffff008187cd0) */

void FUN_fffffff0081878ec(long *param_1,long *param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  long lVar15;
  
  if ((*(byte *)((long)param_2 + 0x4c) & 1) != 0) {
    return;
  }
  *(undefined8 *)(*(long *)(param_1[2] + 0x4b0) + 0xbf0) = 0;
  puVar4 = (undefined8 *)(**(code **)(*param_2 + 0xf0))(param_2);
  uVar5 = (**(code **)(*param_2 + 0xf8))(param_2);
  FUN_fffffff008183924
            (param_1,uVar5,*(undefined4 *)((long)param_2 + 0x1dc),param_2[0x20],
             *(undefined4 *)puVar4,param_2 + 0x6b);
  lVar15 = param_1[2];
  lVar6 = (**(code **)(**(long **)(*(long *)(lVar15 + 0x183a8) + 0x50) + 0x98))();
  uVar1 = *(uint *)(lVar15 + 0x4a0);
  lVar15 = param_1[2];
  lVar7 = (**(code **)(**(long **)(*(long *)(lVar15 + 0x183b0) + 0x50) + 0x98))();
  uVar2 = *(uint *)(lVar15 + 0x4a4);
  uVar8 = (**(code **)(**(long **)(param_1[2] + 0x148) + 0x88))
                    (*(long **)(param_1[2] + 0x148),*(undefined4 *)((long)puVar4 + 4));
  uVar9 = (**(code **)(**(long **)(param_1[2] + 0x148) + 0x88))
                    (*(long **)(param_1[2] + 0x148),*(undefined4 *)((long)puVar4 + 4));
  uVar5 = *puVar4;
  lVar15 = param_1[7];
  lVar3 = param_2[9];
  if (*(int *)((long)param_2 + 0x344) == 2) {
    uVar11 = 0xb;
    lVar12 = 0x488;
    lVar13 = 0x480;
  }
  else {
    if (*(int *)((long)param_2 + 0x344) != 1) goto LAB_fffffff008187ae8;
    uVar11 = 10;
    lVar12 = 0x478;
    lVar13 = 0x470;
  }
  puVar10 = *(undefined4 **)((long)param_2 + lVar13);
  *puVar10 = uVar11;
  puVar10[1] = (int)uVar5;
  (**(code **)(*param_1 + 200))(param_1,*(undefined8 *)((long)param_2 + lVar12),puVar10,0);
LAB_fffffff008187ae8:
  puVar10 = (undefined4 *)param_2[0x92];
  *puVar10 = 3;
  lVar12 = thunk_EXT_FUN_8011000003890f30(param_2[0xc],&DAT_fffffff00ae21f50);
  lVar13 = *(long *)(lVar12 + 0x620);
  *(long *)(lVar12 + 0x620) = lVar13 + 1;
  *(long *)(puVar10 + 1) = lVar13;
  puVar10[3] = *(undefined4 *)((long)param_2 + 0x1dc);
  *(long *)(puVar10 + 0xbf) = param_2[0x3c];
  puVar10[0xb0] = (int)param_2[0x3b];
  (**(code **)(*param_2 + 0xe0))(param_2,1);
  *(long *)(puVar10 + 4) = param_2[0x40];
  *(long *)(puVar10 + 0x74) = param_2[0xa8];
  puVar10[0x76] = (int)param_2[0xa9];
  puVar10[0x78] = *(undefined4 *)((long)param_2 + 0x54c);
  *(long *)(puVar10 + 0x80) = param_2[0x96];
  *(long *)(puVar10 + 0x82) = param_2[0x97];
  *(long *)(puVar10 + 0x8c) = param_2[0x9a];
  puVar10[0x8e] = (int)param_2[0x9b];
  *(long *)(puVar10 + 0x90) = param_2[0x9c];
  puVar10[0x92] = (int)param_2[0x9d];
  *(long *)(puVar10 + 0x94) = param_2[0x9e];
  puVar10[0x96] = (int)param_2[0x9f];
  lVar12 = param_2[0xa0];
  *(long *)(puVar10 + 0x8a) = param_2[0xa1];
  *(long *)(puVar10 + 0x88) = lVar12;
  lVar12 = param_2[0x98];
  *(long *)(puVar10 + 0x86) = param_2[0x99];
  *(long *)(puVar10 + 0x84) = lVar12;
  puVar10[0x7d] = 0;
  puVar10[0x99] = *(byte *)(param_2 + 0xa6) & 1;
  puVar10[0x9a] = *(undefined4 *)((long)param_2 + 0x534);
  puVar10[0x9b] = (int)param_2[0xa7];
  puVar10[0x9c] = *(undefined4 *)((long)param_2 + 0x53c);
  *(undefined8 *)(puVar10 + 0x9f) = 0;
  *(undefined8 *)(puVar10 + 0x9d) = 0;
  lVar12 = param_2[0xe3];
  *(long *)(puVar10 + 0xb9) = param_2[0xe4];
  *(long *)(puVar10 + 0xb7) = lVar12;
  *(undefined8 *)(puVar10 + 0xc1) = 0;
  *(undefined8 *)(puVar10 + 199) = 0;
  *(long *)(puVar10 + 0xbb) = param_2[0xe5];
  *(long *)(puVar10 + 0xbd) = param_2[0xe6];
  if ((*(byte *)(param_1[2] + 0x5cd) >> 6 & 1) != 0) {
    *(long *)(puVar10 + 0xa1) = param_2[0xaf];
    *(long *)(puVar10 + 0xa3) = param_2[0xb0];
  }
  lVar12 = param_2[0x43];
  *(long *)(puVar10 + 0xb5) = param_2[0x44];
  *(long *)(puVar10 + 0xb3) = lVar12;
  *(undefined1 *)(puVar10 + 0xa5) = *(undefined1 *)((long)param_2 + 0x5da);
  *(byte *)((long)puVar10 + 0x295) = *(byte *)((long)param_2 + 0x5db) & 1;
  *(undefined8 *)(puVar10 + 0xb1) = 0;
  puVar10[0xd0] = 0;
  *(long *)(puVar10 + 0xc9) = param_2[0x2a];
  *(long *)(puVar10 + 0xcb) = param_2[0x2b];
  *(long *)(puVar10 + 0xcd) = param_2[0x39];
  puVar10[0xcf] = (uint)((int)param_2[0x2e] == 0);
  if ((*(byte *)((long)param_2 + 0x34c) & 1) != 0) {
    puVar10[0xd0] = 1;
  }
  *(ulong *)(puVar10 + 0xa6) = lVar6 + (ulong)uVar1 + (uVar8 & 0xffffffff);
  *(ulong *)(puVar10 + 0xa8) = lVar7 + (ulong)uVar2 + (uVar9 & 0xffffffff);
  *(undefined8 *)(puVar10 + 0xaa) = uVar5;
  puVar10[0xac] = (int)lVar15;
  puVar10[0xad] = (uint)((int)lVar3 != 0);
  *(long *)(puVar10 + 0xae) = param_2[0x20];
  (**(code **)(*param_1 + 0x160))(*param_1 + 0x160,param_1,puVar10,param_2);
  (**(code **)(*param_1 + 0x178))
            (*param_1 + 0x178,param_1,puVar10,param_2,param_2[0x94],param_2 + 0x10);
  (**(code **)(*param_1 + 200))(param_1,param_2[0x94],puVar10,param_2[0x20]);
  *(byte *)((long)puVar10 + 0x296) = *(byte *)(param_2 + 0xe2) & 1;
  *(byte *)((long)puVar10 + 0x297) = *(byte *)(param_2 + 0xe7) & 1;
  if (param_1[0xc] != 0) {
    uVar14 = *(ulong *)(param_1[0xc] + 0x74);
    uVar9 = param_1[0x17];
    uVar8 = -uVar9;
    if (uVar14 < uVar9) {
      uVar8 = ~uVar9;
    }
    if (uVar14 + uVar8 != 0) {
      thunk_EXT_FUN_801100000320d864(1,0,0,((uVar14 + uVar8) * 0x7d) / 3,0);
      param_1[0x17] = uVar14;
    }
  }
  return;
}

