// FUN_fffffff008d56c68 @ fffffff008d56c68 size=1680
// CALLERS:
//   fffffff00afb95f0 no-fn
//   fffffff008d56c64 thunk_FUN_fffffff008d56c68@fffffff008d56c60
// CALLEES:
//   fffffff008e00660 thunk_EXT_FUN_8011000002c1e368
//   fffffff008e003b0 thunk_EXT_FUN_8011000002c13530
//   fffffff008df42cc FUN_fffffff008df42cc
//   fffffff008dba6e8 FUN_fffffff008dba6e8
//   fffffff008dba984 FUN_fffffff008dba984
//   fffffff008d06098 FUN_fffffff008d06098
//   fffffff008e00740 thunk_EXT_FUN_80110000036da494
//   fffffff008df4284 FUN_fffffff008df4284
//   fffffff008e007a0 thunk_EXT_FUN_8011000003a61b10
//   fffffff008d56ae8 FUN_fffffff008d56ae8
//   fffffff008d57364 FUN_fffffff008d57364
//   fffffff008cd5a74 FUN_fffffff008cd5a74
//   fffffff008e00680 thunk_EXT_FUN_8011000002c1e374
//   fffffff008e000d0 thunk_EXT_FUN_8011000002c13424
//   fffffff008dffe60 thunk_EXT_FUN_80110000038905fc
//   fffffff008d5c290 FUN_fffffff008d5c290
//   fffffff008e006b0 thunk_EXT_FUN_8011000003398228
//   fffffff008df4244 FUN_fffffff008df4244
//   fffffff008e00760 thunk_EXT_FUN_8011000003397c88
//   fffffff008cd5954 FUN_fffffff008cd5954

undefined8 FUN_fffffff008d56c68(long param_1,undefined4 *param_2,long param_3,long param_4)

{
  int *piVar1;
  long *plVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  long *plVar8;
  long lVar9;
  undefined8 uVar10;
  bool bVar11;
  ulong uVar12;
  long lVar13;
  undefined8 *puVar14;
  undefined8 uVar15;
  bool bVar16;
  long lVar17;
  double dVar18;
  uint uVar19;
  long local_68;
  
  plVar8 = (long *)FUN_fffffff008dba6e8(param_4,param_1);
  if (plVar8 == (long *)0x0) {
    uVar15 = 0;
  }
  else {
    plVar8[6] = param_3;
    do {
      iVar5 = thunk_EXT_FUN_80110000038905fc(param_1 + 0x324);
    } while (iVar5 == 0);
    *(int *)((long)plVar8 + 0xd2c) = iVar5;
    uVar12 = *(ulong *)(param_1 + 0x1c0);
    if (((uVar12 == 0) ||
        (uVar12 = (uVar12 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar12 & 0x5555555555555555) << 1,
        uVar12 = (uVar12 & 0xcccccccccccccccc) >> 2 | (uVar12 & 0x3333333333333333) << 2,
        uVar12 = (uVar12 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar12 & 0xf0f0f0f0f0f0f0f) << 4,
        uVar12 = (uVar12 & 0xff00ff00ff00ff00) >> 8 | (uVar12 & 0xff00ff00ff00ff) << 8,
        uVar12 = (uVar12 & 0xffff0000ffff0000) >> 0x10 | (uVar12 & 0xffff0000ffff) << 0x10,
        iVar5 = *(int *)(*(long *)(param_1 + 0x150 + LZCOUNT(uVar12 >> 0x20 | uVar12 << 0x20) * 8) +
                        0x4c), iVar5 == 0x1c || iVar5 == 0x12)) &&
       ((0 < DAT_fffffff00ae6f2bc || (*(int *)(*(long *)(param_1 + 0x288) + 0x84) != 0)))) {
      uVar15 = 0xe00002e2;
      iVar5 = FUN_fffffff008cd5954(1,8);
      if (iVar5 != 0) {
        FUN_fffffff008df42cc((long)plVar8 + 0xd2c,plVar8);
      }
    }
    else {
      thunk_EXT_FUN_8011000003a61b10(plVar8 + 0xb,param_2,0x1b0);
      local_68 = 0;
      uVar15 = thunk_EXT_FUN_8011000003397c88();
      uVar15 = thunk_EXT_FUN_8011000003398228(uVar15,&local_68);
      plVar8[0x198] = local_68;
      if (*(int *)(param_4 + 0x164) == 0) {
        uVar6 = param_2[1];
        *(undefined4 *)((long)plVar8 + 0x51c) = *param_2;
        *(undefined4 *)((long)plVar8 + 0x7dc) = uVar6;
        uVar10 = *(undefined8 *)(plVar8[10] + 0x130);
        if ((int)plVar8[0x1a] != 0) {
          lVar17 = plVar8[0x1b];
          lVar13 = plVar8[0x1c];
          lVar9 = thunk_EXT_FUN_8011000002c13424(uVar10);
          plVar8[0x154] = lVar9;
          uVar15 = 0;
          if (lVar9 != 0) {
            uVar15 = thunk_EXT_FUN_8011000002c13530();
            *(int *)(plVar8 + 0x155) = (int)uVar15;
            plVar8[0x156] = lVar17;
            plVar8[0x157] = lVar13;
          }
        }
        if ((int)plVar8[0x1d] != 0) {
          lVar17 = plVar8[0x1e];
          lVar13 = plVar8[0x1f];
          lVar9 = thunk_EXT_FUN_8011000002c13424(uVar10);
          plVar8[0x144] = lVar9;
          uVar15 = 0;
          if (lVar9 != 0) {
            uVar15 = thunk_EXT_FUN_8011000002c13530();
            *(int *)(plVar8 + 0x145) = (int)uVar15;
            plVar8[0x146] = lVar17;
            plVar8[0x147] = lVar13;
          }
        }
      }
      else {
        lVar17 = *(long *)(param_2 + 0x16);
        plVar8[0xa4] = *(long *)(param_2 + 0x14);
        plVar8[0xfc] = lVar17;
      }
      FUN_fffffff008d56ae8(uVar15,plVar8,*(undefined8 *)(param_2 + 8));
      *(undefined4 *)((long)plVar8 + 0xd34) = *(undefined4 *)(param_4 + 0x168);
      lVar17 = FUN_fffffff008d06098(*(undefined8 *)(param_2 + 0xe),0x2f,0x10,0);
      plVar8[0x16a] = lVar17;
      lVar17 = FUN_fffffff008d06098(*(undefined8 *)(param_2 + 0x10),0x2f,0x10,0);
      plVar8[0x169] = lVar17;
      lVar17 = FUN_fffffff008d06098(*(undefined8 *)(param_2 + 10),0x2f,0x10,0);
      plVar8[0x9d] = lVar17;
      lVar17 = FUN_fffffff008d06098(*(undefined8 *)(param_2 + 0xc),0x2f,0x10,0);
      plVar8[0x9a] = lVar17;
      dVar18 = (double)FUN_fffffff008d06098(*(undefined8 *)(param_2 + 10),0,0x10,0);
      *(int *)(plVar8 + 0x97) = (int)(dVar18 + (double)plVar8[0x16a]);
      dVar18 = (double)FUN_fffffff008d06098(*(undefined8 *)(param_2 + 0xc),0,0x10,0);
      *(int *)((long)plVar8 + 0x4bc) = (int)(dVar18 + (double)plVar8[0x169]);
      uVar7 = param_2[0x1a];
      uVar3 = param_2[0x1b];
      *(uint *)(plVar8 + 0xef) = uVar7;
      *(uint *)((long)plVar8 + 0x77c) = uVar3;
      plVar8[0x168] = (long)(double)uVar7;
      plVar8[0x167] = (long)(double)uVar3;
      uVar19 = param_2[0x19];
      lVar17 = NEON_ucvtf((ulong)(uint)param_2[0x18]);
      plVar8[0xf5] = lVar17;
      lVar17 = NEON_ucvtf((ulong)uVar19);
      plVar8[0xf2] = lVar17;
      if ((uVar7 == 0) || (uVar3 == 0)) {
        *(undefined1 *)(plVar8 + 0x128) = 1;
        plVar8[0xef] = 0;
        plVar8[0xf5] = 0;
        plVar8[0xf2] = 0;
      }
      if (((int)plVar8[0x97] == 0) || ((int)(dVar18 + (double)plVar8[0x169]) == 0)) {
        *(undefined1 *)(plVar8 + 0xd0) = 1;
        plVar8[0x97] = 0;
        plVar8[0x9d] = 0;
        plVar8[0x9a] = 0;
        plVar8[0x169] = 0;
        plVar8[0x16a] = 0;
      }
      if ((*(byte *)((long)plVar8 + 0xc34) & 1) != 0) {
        *(undefined4 *)(plVar8 + 0x187) = param_2[0x2a];
      }
      if ((*(byte *)((long)plVar8 + 0xc3c) & 1) != 0) {
        *(undefined8 *)((long)plVar8 + 0xc3e) = *(undefined8 *)(param_2 + 0x33);
      }
      if ((*(byte *)((long)plVar8 + 0x22c2) & 1) != 0) {
        uVar15 = NEON_rev64(*(undefined8 *)(param_2 + 0x2f),4);
        *(undefined8 *)((long)plVar8 + 0x22c4) = uVar15;
      }
      if ((*(byte *)(plVar8 + 0x189) & 1) != 0) {
        uVar7 = param_2[0x2b];
        uVar3 = param_2[0x2c];
        *(uint *)((long)plVar8 + 0xc4c) = uVar7;
        *(uint *)(plVar8 + 0x18a) = uVar3;
        iVar5 = param_2[0x2d];
        iVar4 = param_2[0x2e];
        *(int *)((long)plVar8 + 0xc54) = iVar5;
        *(int *)(plVar8 + 0x18b) = iVar4;
        if (*(int *)((long)plVar8 + 0x7c4) == 2) {
          *(uint *)((long)plVar8 + 0xc54) = iVar5 + (uVar7 & 1) & 0xfffffffe;
          *(uint *)((long)plVar8 + 0xc4c) = uVar7 & 0xfffffffe;
        }
        if ((int)plVar8[0xf8] == 2) {
          *(uint *)(plVar8 + 0x18b) = iVar4 + (uVar3 & 1) & 0xfffffffe;
          *(uint *)(plVar8 + 0x18a) = uVar3 & 0xfffffffe;
        }
        uVar15 = *(undefined8 *)(param_2 + 0x2f);
        *(undefined8 *)((long)plVar8 + 0xc64) = *(undefined8 *)(param_2 + 0x31);
        *(undefined8 *)((long)plVar8 + 0xc5c) = uVar15;
      }
      if ((*(byte *)((long)plVar8 + 0xc49) & 1) != 0) {
        uVar15 = *(undefined8 *)(param_2 + 0x2f);
        *(undefined8 *)((long)plVar8 + 0xc64) = *(undefined8 *)(param_2 + 0x31);
        *(undefined8 *)((long)plVar8 + 0xc5c) = uVar15;
      }
      if ((int)plVar8[0x18e] != 0) {
        lVar17 = 0;
        uVar15 = *(undefined8 *)(param_2 + 0x37);
        *(undefined8 *)((long)plVar8 + 0xc7c) = *(undefined8 *)(param_2 + 0x39);
        *(undefined8 *)((long)plVar8 + 0xc74) = uVar15;
        *(undefined4 *)((long)plVar8 + 0xc84) = param_2[0x3b];
        lVar13 = 8;
        do {
          *(undefined4 *)((long)plVar8 + lVar17 * 4 + 0xc88) = param_2[lVar17 + 0x3c];
          lVar17 = lVar17 + 1;
          lVar13 = lVar13 + -1;
        } while (lVar13 != 0);
      }
      lVar17 = 0;
      lVar13 = 4;
      do {
        piVar1 = param_2 + lVar17 * 10 + 0x44;
        iVar5 = *piVar1;
        plVar2 = plVar8 + lVar17 * 5 + 0x1be;
        *(int *)plVar2 = iVar5;
        plVar2[1] = *(long *)(piVar1 + 2);
        iVar4 = piVar1[5];
        plVar2[2] = *(long *)(piVar1 + 4);
        plVar2[3] = *(long *)(piVar1 + 6);
        *(int *)(plVar2 + 4) = piVar1[8];
        if (iVar5 != 0 || iVar4 != 0) {
          *(undefined1 *)((long)plVar8 + 0xde4) = 1;
        }
        lVar17 = lVar17 + 1;
        lVar13 = lVar13 + -1;
      } while (lVar13 != 0);
      FUN_fffffff008cd5a74
                (0x11f,0xaab,plVar8,
                 (long)*(int *)((long)plVar8 + 0xd2c) |
                 (ulong)*(uint *)((long)plVar8 + 0xd34) << 0x20,0);
      uVar10 = 0;
      bVar16 = true;
      do {
        uVar15 = FUN_fffffff008d5c290(param_1,uVar10,plVar8);
        if (!bVar16) break;
        bVar16 = false;
        uVar10 = 1;
      } while ((int)uVar15 == 0);
      if ((int)uVar15 == 0) {
        uVar6 = thunk_EXT_FUN_8011000002c1e368(plVar8[0xa4]);
        *(undefined4 *)(plVar8 + 0x96) = uVar6;
        uVar6 = thunk_EXT_FUN_8011000002c1e374(plVar8[0xa4]);
        *(undefined4 *)((long)plVar8 + 0x4b4) = uVar6;
        uVar6 = thunk_EXT_FUN_8011000002c1e368(plVar8[0xfc]);
        *(undefined4 *)(plVar8 + 0xee) = uVar6;
        uVar7 = thunk_EXT_FUN_8011000002c1e374(plVar8[0xfc]);
        *(uint *)((long)plVar8 + 0x774) = uVar7;
        if ((*(byte *)(plVar8 + 0xd0) & 1) != 0) {
          *(uint *)(plVar8 + 0x97) = *(uint *)(plVar8 + 0x96);
          *(uint *)((long)plVar8 + 0x4bc) = *(uint *)((long)plVar8 + 0x4b4);
          plVar8[0x16a] = (long)(double)*(uint *)(plVar8 + 0x96);
          plVar8[0x169] = (long)(double)*(uint *)((long)plVar8 + 0x4b4);
        }
        if ((*(byte *)(plVar8 + 0x128) & 1) != 0) {
          *(uint *)(plVar8 + 0xef) = *(uint *)(plVar8 + 0xee);
          *(uint *)((long)plVar8 + 0x77c) = uVar7;
          plVar8[0x168] = (long)(double)*(uint *)(plVar8 + 0xee);
          plVar8[0x167] = (long)(double)uVar7;
        }
        if (*(int *)(*(long *)(param_1 + 0x288) + 0x7c) != 0) {
          iVar5 = FUN_fffffff008cd5954(4,10);
          if (iVar5 != 0) {
            FUN_fffffff008df4244();
          }
          *(undefined1 *)((long)plVar8 + 0x22c1) = 1;
        }
        uVar12 = (*(ulong *)(param_1 + 0x1c0) & 0xaaaaaaaaaaaaaaaa) >> 1 |
                 (*(ulong *)(param_1 + 0x1c0) & 0x5555555555555555) << 1;
        uVar12 = (uVar12 & 0xcccccccccccccccc) >> 2 | (uVar12 & 0x3333333333333333) << 2;
        uVar12 = (uVar12 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar12 & 0xf0f0f0f0f0f0f0f) << 4;
        uVar12 = (uVar12 & 0xff00ff00ff00ff00) >> 8 | (uVar12 & 0xff00ff00ff00ff) << 8;
        uVar12 = (uVar12 & 0xffff0000ffff0000) >> 0x10 | (uVar12 & 0xffff0000ffff) << 0x10;
        if ((*(char *)(*(long *)(*(long *)(param_1 + 0x150 +
                                          LZCOUNT(uVar12 >> 0x20 | uVar12 << 0x20) * 8) + 0xb8) +
                      0x209) == '\0' || DAT_fffffff00ae6f2b4 < 1) ||
           ((*(byte *)(param_1 + 0x89) & 1) != 0)) {
          puVar14 = (undefined8 *)(**(long **)(param_1 + 0xb8) + 0xe8);
          (*(code *)*puVar14)(puVar14,*(long **)(param_1 + 0xb8),FUN_fffffff008df2f84,plVar8,0,0,0);
          lVar17 = plVar8[0x85];
          iVar5 = FUN_fffffff008cd5954(4,8);
          if (iVar5 != 0) {
            FUN_fffffff008df4284((long)plVar8 + 0xd2c,(int)lVar17);
          }
          thunk_EXT_FUN_80110000036da494
                    (0x31b000e0,(long)*(int *)((long)plVar8 + 0xd2c),
                     *(undefined4 *)((long)plVar8 + 0xd34),0,(int)lVar17,0);
          uVar15 = FUN_fffffff008d57364(param_1,plVar8);
        }
        else {
          uVar15 = 0xe00002d8;
        }
      }
      else {
        uVar10 = 0;
        bVar16 = true;
        do {
          bVar11 = bVar16;
          lVar17 = FUN_fffffff008dba984(plVar8,uVar10);
          if (*(long **)(lVar17 + 0x90) != (long *)0x0) {
            (**(code **)(**(long **)(lVar17 + 0x90) + 0x28))();
          }
          *(undefined8 *)(lVar17 + 0x90) = 0;
          uVar10 = 1;
          bVar16 = false;
        } while (bVar11);
        (**(code **)(*plVar8 + 0x28))(plVar8);
      }
    }
  }
  return uVar15;
}

