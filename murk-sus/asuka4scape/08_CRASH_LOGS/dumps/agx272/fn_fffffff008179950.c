// FUN_fffffff008179950 @ fffffff008179950 size=1032

void FUN_fffffff008179950(long *param_1,long *param_2,int param_3,int *param_4)

{
  ulong *puVar1;
  int *piVar2;
  char *pcVar3;
  byte bVar4;
  uint uVar5;
  long *plVar6;
  long *plVar7;
  ulong *puVar8;
  undefined8 uVar9;
  long lVar10;
  ulong uVar11;
  int *piVar12;
  ulong uVar13;
  ulong uVar14;
  int iVar15;
  ulong uVar16;
  uint uVar17;
  long lVar18;
  ulong *puVar19;
  ulong uVar20;
  uint local_50 [2];
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff007ca61a0;
  lVar10 = 0x43d;
  if (param_3 != 1) {
    lVar10 = 0x43e;
  }
  bVar4 = *(byte *)((long)param_1 + lVar10);
  param_4[0x50] = 0;
  param_4[0x51] = 0;
  param_4[0x4a] = 0;
  param_4[0x4b] = 0;
  param_4[0x48] = 0;
  param_4[0x49] = 0;
  param_4[0x4e] = 0;
  param_4[0x4f] = 0;
  param_4[0x4c] = 0;
  param_4[0x4d] = 0;
  param_4[0x42] = 0;
  param_4[0x43] = 0;
  param_4[0x40] = 0;
  param_4[0x41] = 0;
  param_4[0x46] = 0;
  param_4[0x47] = 0;
  param_4[0x44] = 0;
  param_4[0x45] = 0;
  param_4[0x3a] = 0;
  param_4[0x3b] = 0;
  param_4[0x38] = 0;
  param_4[0x39] = 0;
  param_4[0x3e] = 0;
  param_4[0x3f] = 0;
  param_4[0x3c] = 0;
  param_4[0x3d] = 0;
  param_4[0x32] = 0;
  param_4[0x33] = 0;
  param_4[0x30] = 0;
  param_4[0x31] = 0;
  param_4[0x36] = 0;
  param_4[0x37] = 0;
  param_4[0x34] = 0;
  param_4[0x35] = 0;
  param_4[0x2a] = 0;
  param_4[0x2b] = 0;
  param_4[0x28] = 0;
  param_4[0x29] = 0;
  param_4[0x2e] = 0;
  param_4[0x2f] = 0;
  param_4[0x2c] = 0;
  param_4[0x2d] = 0;
  param_4[0x22] = 0;
  param_4[0x23] = 0;
  param_4[0x20] = 0;
  param_4[0x21] = 0;
  param_4[0x26] = 0;
  param_4[0x27] = 0;
  param_4[0x24] = 0;
  param_4[0x25] = 0;
  param_4[0x1a] = 0;
  param_4[0x1b] = 0;
  param_4[0x18] = 0;
  param_4[0x19] = 0;
  param_4[0x1e] = 0;
  param_4[0x1f] = 0;
  param_4[0x1c] = 0;
  param_4[0x1d] = 0;
  param_4[0x12] = 0;
  param_4[0x13] = 0;
  param_4[0x10] = 0;
  param_4[0x11] = 0;
  param_4[0x16] = 0;
  param_4[0x17] = 0;
  param_4[0x14] = 0;
  param_4[0x15] = 0;
  param_4[10] = 0;
  param_4[0xb] = 0;
  param_4[8] = 0;
  param_4[9] = 0;
  param_4[0xe] = 0;
  param_4[0xf] = 0;
  param_4[0xc] = 0;
  param_4[0xd] = 0;
  param_4[2] = 0;
  param_4[3] = 0;
  param_4[0] = 0;
  param_4[1] = 0;
  param_4[6] = 0;
  param_4[7] = 0;
  param_4[4] = 0;
  param_4[5] = 0;
  if ((bVar4 & 1) == 0) {
    uVar9 = 1;
    goto LAB_fffffff008179ce4;
  }
  pcVar3 = "cs-perf-states";
  if (param_3 != 1) {
    pcVar3 = "afr-perf-states";
  }
  plVar6 = (long *)(**(code **)(*param_2 + 0x118))(param_2,pcVar3);
  if (plVar6 == (long *)0x0) {
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(0,*(undefined8 *)PTR_DAT_fffffff007ca6090);
    if (plVar7 != (long *)0x0) goto LAB_fffffff008179a8c;
LAB_fffffff008179cbc:
    (**(code **)(*param_1 + 0x38))(param_1);
    thunk_EXT_FUN_8011000003891b28();
  }
  else {
    (**(code **)(*plVar6 + 0x20))();
    plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(plVar6,*(undefined8 *)PTR_DAT_fffffff007ca6090);
    if (plVar7 == (long *)0x0) {
      (**(code **)(*plVar6 + 0x28))(plVar6);
      goto LAB_fffffff008179cbc;
    }
LAB_fffffff008179a8c:
    puVar8 = (ulong *)(**(code **)(*plVar7 + 0xd8))();
    if ((puVar8 != (ulong *)0x0) && (uVar5 = (**(code **)(*plVar7 + 0xa0))(plVar7), 0x37 < uVar5)) {
      uVar16 = *puVar8;
      uVar14 = puVar8[1];
      iVar15 = (int)uVar14;
      uVar17 = (uint)uVar16;
      if (((iVar15 << 4 | 8U) * uVar17 + 0x10 <= uVar5 && 0xfffffff0 < iVar15 - 0x11U) &&
         (uVar17 < 3 && *(uint *)(param_1 + 0x84) == uVar17)) {
        *param_4 = iVar15;
        param_4[1] = uVar17;
        if (uVar17 != 0) {
          uVar20 = 0;
          puVar8 = puVar8 + 2;
          piVar2 = param_4 + 0x12;
          uVar13 = uVar16 & 3;
          uVar14 = uVar14 & 0xffffffff;
          do {
            lVar10 = 0;
            puVar19 = puVar8 + 1;
            uVar11 = uVar14;
            do {
              piVar12 = piVar2 + lVar10 * 2;
              if ((((ulong)piVar2 ^ (ulong)piVar12) & 0xffc0000000000000) != 0) {
                piVar12 = (int *)((ulong)piVar12 & 0xffffffffffff | 0xc8a2000000000000);
              }
              piVar12[uVar20] = (int)(*puVar8 / 1000);
              puVar1 = puVar8 + 1;
              puVar8 = puVar8 + 2;
              param_4[lVar10 + 2] = (int)*puVar1;
              lVar10 = lVar10 + 1;
              puVar19 = puVar19 + 2;
              uVar11 = uVar11 - 1;
            } while (uVar11 != 0);
            uVar20 = uVar20 + 1;
          } while (uVar20 != uVar13);
          lVar10 = 0;
          local_50[0] = 0;
          local_50[1] = 0;
          if (uVar13 < 2) {
LAB_fffffff008179c08:
            lVar18 = uVar13 - lVar10;
            do {
              local_50[lVar10] = (uint)(*puVar8 / 1000);
              lVar10 = lVar10 + 1;
              lVar18 = lVar18 + -1;
              puVar8 = puVar8 + 1;
            } while (lVar18 != 0);
          }
          else {
            lVar10 = 0;
            uVar20 = uVar16 & 2;
            do {
              uVar11 = *puVar19;
              local_50[lVar10] = (uint)(puVar19[-1] / 1000);
              *(int *)((long)local_50 + (lVar10 * 4 | 4U)) = (int)(uVar11 / 1000);
              lVar10 = lVar10 + 2;
              puVar19 = puVar19 + 2;
              uVar20 = uVar20 - 2;
            } while (uVar20 != 0);
            if (uVar13 != 2) {
              puVar8 = puVar8 + (uVar16 & 2);
              lVar10 = 2;
              goto LAB_fffffff008179c08;
            }
          }
          if (iVar15 != 0) {
            uVar16 = 0;
            do {
              lVar10 = 0;
              uVar20 = uVar13;
              do {
                piVar12 = piVar2 + uVar16 * 2;
                if ((((ulong)piVar2 ^ (ulong)piVar12) & 0xffc0000000000000) != 0) {
                  piVar12 = (int *)((ulong)piVar12 & 0xffffffffffff | 0xc8a2000000000000);
                }
                uVar5 = piVar12[lVar10];
                if ((uint)piVar12[lVar10] <= local_50[lVar10]) {
                  uVar5 = local_50[lVar10];
                }
                piVar12 = param_4 + 0x32 + uVar16 * 2;
                if ((((ulong)(param_4 + 0x32) ^ (ulong)piVar12) & 0xffc0000000000000) != 0) {
                  piVar12 = (int *)((ulong)piVar12 & 0xffffffffffff | 0xc8a2000000000000);
                }
                piVar12[lVar10] = uVar5;
                lVar10 = lVar10 + 1;
                uVar20 = uVar20 - 1;
              } while (uVar20 != 0);
              uVar16 = uVar16 + 1;
            } while (uVar16 != uVar14);
          }
        }
        (**(code **)(*plVar7 + 0x28))(plVar7);
        uVar9 = 1;
        goto LAB_fffffff008179ce4;
      }
    }
    (**(code **)(*param_1 + 0x38))(param_1);
    thunk_EXT_FUN_8011000003891b28();
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  uVar9 = 0;
LAB_fffffff008179ce4:
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_48) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar9);
  return;
}

