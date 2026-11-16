// FUN_fffffff009abc21c @ fffffff009abc21c size=1280
// CALLERS:
// CALLEES:
//   fffffff009abd96c thunk_EXT_FUN_8011000002c1e74c
//   fffffff009abd97c thunk_EXT_FUN_8011000002c1e4e8
//   fffffff009abda9c thunk_EXT_FUN_8011000002c2593c
//   fffffff009abdabc thunk_EXT_FUN_8011000002c1e368
//   fffffff009abda2c thunk_EXT_FUN_8011000002c1c364
//   fffffff009abda0c thunk_EXT_FUN_8011000002c1e9b0
//   fffffff009abd98c thunk_EXT_FUN_8011000002c20754
//   fffffff009abd9cc thunk_EXT_FUN_8011000002c23940
//   fffffff009abdaac thunk_EXT_FUN_8011000002c225f8
//   fffffff009abd92c thunk_EXT_FUN_8011000002c1e680
//   fffffff009abd3dc thunk_EXT_FUN_8011000003890f30
//   fffffff009abd90c thunk_EXT_FUN_8011000002c1e380
//   fffffff009abda1c thunk_EXT_FUN_8011000002c1e818
//   fffffff009abd8fc thunk_EXT_FUN_8011000002c1e35c
//   fffffff009abd9dc thunk_EXT_FUN_8011000002c22438
//   fffffff009abd94c thunk_EXT_FUN_8011000002c1e38c
//   fffffff009abd91c thunk_EXT_FUN_8011000002c1e3bc
//   fffffff009abda6c thunk_EXT_FUN_8011000002c24af0
//   fffffff009abd95c thunk_EXT_FUN_8011000002c1e350
//   fffffff009abd9bc thunk_EXT_FUN_8011000002c1e3b0
//   fffffff009abda7c thunk_EXT_FUN_8011000002c1ea7c
//   fffffff009abd8dc thunk_EXT_FUN_8011000002c1e41c
//   fffffff009abda5c thunk_EXT_FUN_8011000002c1e8e4
//   fffffff009abda4c thunk_EXT_FUN_8011000002c1eb48
//   fffffff009abd85c thunk_EXT_FUN_8011000002c26750
//   fffffff009abdacc thunk_EXT_FUN_8011000002c1e374
//   fffffff009abdb8c thunk_EXT_FUN_8011000003a61b10
//   fffffff009abd99c thunk_EXT_FUN_8011000002c1e3a4
//   fffffff009abd8cc thunk_EXT_FUN_8011000002c1b1a8
//   fffffff009abd9ec thunk_EXT_FUN_8011000002c1e398
//   fffffff009abd8ec thunk_EXT_FUN_8011000002c1e5b4
//   fffffff009abda8c thunk_EXT_FUN_8011000002c25cec

undefined8 FUN_fffffff009abc21c(undefined1 *param_1,long param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  undefined8 uVar12;
  long *plVar13;
  long lVar14;
  long *plVar15;
  long *plVar16;
  undefined8 uVar17;
  undefined8 *puVar18;
  undefined1 *puVar19;
  ulong uVar20;
  undefined8 *puVar21;
  bool bVar22;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined4 uStack_98;
  undefined4 local_94;
  undefined4 uStack_90;
  uint uStack_8c;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined4 local_70;
  
  if (param_2 == 0) {
    return 0;
  }
  uVar20 = 0;
  bVar22 = false;
  puVar21 = (undefined8 *)0x0;
  plVar13 = (long *)(param_1 + 0x149);
  *plVar13 = 0;
  *(undefined8 *)(param_1 + 0x1ed) = 0;
  puVar1 = param_1 + 0x59;
  puVar2 = param_1 + 0x39;
  puVar3 = param_1 + 0x151;
  do {
    uVar10 = thunk_EXT_FUN_8011000002c1e3bc(param_2);
    if (uVar20 < (uVar10 & 0xffffffff)) {
      uVar7 = thunk_EXT_FUN_8011000002c1e680(param_2,uVar20);
      puVar4 = (undefined4 *)(puVar1 + uVar20 * 0x50);
      *puVar4 = uVar7;
      uVar7 = thunk_EXT_FUN_8011000002c1e74c(param_2,uVar20);
      puVar4[1] = uVar7;
      uVar7 = thunk_EXT_FUN_8011000002c1e41c(param_2,uVar20);
      puVar4[2] = uVar7;
      uVar7 = thunk_EXT_FUN_8011000002c1e4e8(param_2,uVar20);
      puVar4[3] = uVar7;
      uVar7 = thunk_EXT_FUN_8011000002c1e9b0(param_2,uVar20);
      puVar4[4] = uVar7;
      uVar7 = thunk_EXT_FUN_8011000002c1e5b4(param_2,uVar20);
      puVar4[5] = uVar7;
      uVar6 = thunk_EXT_FUN_8011000002c1ea7c(param_2,uVar20);
      *(undefined2 *)(puVar4 + 6) = uVar6;
      uVar5 = thunk_EXT_FUN_8011000002c1e818(param_2,uVar20);
      *(undefined1 *)((long)puVar4 + 0x1a) = uVar5;
      uVar5 = thunk_EXT_FUN_8011000002c1e8e4(param_2,uVar20);
      *(undefined1 *)((long)puVar4 + 0x1b) = uVar5;
      uVar5 = thunk_EXT_FUN_8011000002c1eb48(param_2,uVar20);
      *(undefined1 *)((long)puVar4 + 0x29) = uVar5;
      puVar21 = (undefined8 *)thunk_EXT_FUN_8011000002c24af0(param_2,uVar20);
      iVar8 = thunk_EXT_FUN_8011000002c2593c(param_2,uVar20);
      if (iVar8 != 0) {
        uVar10 = 0;
        do {
          uVar5 = thunk_EXT_FUN_8011000002c25cec(param_2,uVar20,uVar10);
          puVar2[uVar10 + (uVar20 << 3 | 1)] = uVar5;
          uVar10 = uVar10 + 1;
          uVar11 = thunk_EXT_FUN_8011000002c2593c(param_2,uVar20);
        } while (uVar10 < (uVar11 & 0xffffffff));
      }
      uVar5 = thunk_EXT_FUN_8011000002c2593c(param_2,uVar20);
      puVar2[uVar20 * 8] = uVar5;
    }
    else {
      puVar18 = (undefined8 *)(puVar1 + uVar20 * 0x50);
      puVar18[7] = 0;
      puVar18[6] = 0;
      puVar18[9] = 0;
      puVar18[8] = 0;
      puVar18[3] = 0;
      puVar18[2] = 0;
      puVar18[5] = 0;
      puVar18[4] = 0;
      puVar18[1] = 0;
      *puVar18 = 0;
      *(undefined8 *)(puVar2 + uVar20 * 8) = 0;
    }
    puVar18 = (undefined8 *)(puVar3 + uVar20 * 0x34);
    if ((((ulong)puVar3 ^ (ulong)puVar18) & 0xffc0000000000000) != 0) {
      puVar18 = (undefined8 *)((ulong)puVar18 & 0xffffffffffff | 0xc8a2000000000000);
    }
    puVar19 = puVar3;
    if (puVar21 == (undefined8 *)0x0) {
      *(undefined4 *)(puVar18 + 6) = 0;
      puVar18[3] = 0;
      puVar18[2] = 0;
      puVar18[5] = 0;
      puVar18[4] = 0;
      puVar18[1] = 0;
      *puVar18 = 0;
      if (!bVar22) {
        puVar19 = (undefined1 *)0x0;
      }
      *plVar13 = (long)puVar1;
    }
    else {
      uVar12 = *puVar21;
      puVar18[1] = puVar21[1];
      *puVar18 = uVar12;
      uVar12 = puVar21[2];
      puVar18[3] = puVar21[3];
      puVar18[2] = uVar12;
      *(undefined1 *)(puVar18 + 4) = *(undefined1 *)(puVar21 + 4);
      *(undefined2 *)((long)puVar18 + 0x21) = *(undefined2 *)((long)puVar21 + 0x21);
      *(undefined4 *)((long)puVar18 + 0x23) = *(undefined4 *)((long)puVar21 + 0x24);
      *(undefined8 *)((long)puVar18 + 0x2b) = *(undefined8 *)((long)puVar21 + 0x2c);
      *(undefined1 *)((long)puVar18 + 0x27) = *(undefined1 *)(puVar21 + 5);
      *plVar13 = (long)puVar1;
      bVar22 = true;
    }
    *(undefined1 **)(param_1 + 0x1ed) = puVar19;
    *(undefined1 **)(param_1 + 0x51) = puVar2;
    uVar20 = uVar20 + 1;
  } while (uVar20 != 3);
  uVar5 = thunk_EXT_FUN_8011000002c26750(param_2);
  *param_1 = uVar5;
  uVar5 = thunk_EXT_FUN_8011000002c23940(param_2);
  param_1[1] = uVar5;
  uVar7 = thunk_EXT_FUN_8011000002c1e3bc(param_2);
  *(undefined4 *)(param_1 + 3) = uVar7;
  uVar7 = thunk_EXT_FUN_8011000002c1e350(param_2);
  *(undefined4 *)(param_1 + 0xb) = uVar7;
  uVar7 = thunk_EXT_FUN_8011000002c20754(param_2);
  *(undefined4 *)(param_1 + 0xf) = uVar7;
  local_70 = 0xaaaaaaaa;
  uStack_88 = 0xaaaaaaaaaaaaaaaa;
  uStack_90 = 0xaaaaaaaa;
  uStack_8c = 0xaaaaaaaa;
  uStack_78 = 0xaaaaaaaaaaaaaaaa;
  uStack_80 = 0xaaaaaaaaaaaaaaaa;
  uStack_a8 = 0xaaaaaaaaaaaaaaaa;
  local_b0 = 0xaaaaaaaaaaaaaaaa;
  uStack_98 = 0xaaaaaaaa;
  local_94 = 0xaaaaaaaa;
  uStack_a0 = 0xaaaaaaaaaaaaaaaa;
  uStack_c8 = 0xaaaaaaaaaaaaaaaa;
  local_d0 = 0xaaaaaaaaaaaaaaaa;
  uStack_b8 = 0xaaaaaaaaaaaaaaaa;
  uStack_c0 = 0xaaaaaaaaaaaaaaaa;
  uStack_e8 = 0xaaaaaaaaaaaaaaaa;
  local_f0 = 0xaaaaaaaaaaaaaaaa;
  uStack_d8 = 0xaaaaaaaaaaaaaaaa;
  uStack_e0 = 0xaaaaaaaaaaaaaaaa;
  local_f8 = 0x84;
  thunk_EXT_FUN_8011000002c22438(param_2,&local_f0,&local_f8);
  param_1[0x14] = uStack_b8._3_1_;
  param_1[0x13] = uStack_b8._4_1_;
  *(ulong *)(param_1 + 0x1f5) = CONCAT44(uStack_90,local_94);
  param_1[2] = (uStack_8c & 0xfd) == 0;
  uVar7 = thunk_EXT_FUN_8011000002c1e38c(param_2);
  *(undefined4 *)(param_1 + 0x15) = uVar7;
  uVar6 = thunk_EXT_FUN_8011000002c1e398(param_2);
  *(undefined2 *)(param_1 + 0x19) = uVar6;
  uVar5 = thunk_EXT_FUN_8011000002c1e3a4(param_2);
  param_1[0x1b] = uVar5;
  uVar5 = thunk_EXT_FUN_8011000002c1e3b0(param_2);
  param_1[0x1c] = uVar5;
  uVar7 = thunk_EXT_FUN_8011000002c1e380(param_2);
  *(undefined4 *)(param_1 + 0x1d) = uVar7;
  uVar7 = thunk_EXT_FUN_8011000002c1e368(param_2);
  *(undefined4 *)(param_1 + 0x21) = uVar7;
  uVar7 = thunk_EXT_FUN_8011000002c1e374(param_2);
  *(undefined4 *)(param_1 + 0x25) = uVar7;
  uVar7 = thunk_EXT_FUN_8011000002c1b1a8(param_2);
  *(undefined4 *)(param_1 + 0x29) = uVar7;
  uVar7 = thunk_EXT_FUN_8011000002c1e35c(param_2);
  *(undefined4 *)(param_1 + 0x35) = uVar7;
  uVar12 = thunk_EXT_FUN_8011000002c1c364(param_2);
  *(undefined8 *)(param_1 + 0x2d) = uVar12;
  *(undefined4 *)(param_1 + 7) = *(undefined4 *)(param_1 + 3);
  *(undefined4 *)(param_1 + 0x201) = 0;
  plVar13 = (long *)thunk_EXT_FUN_8011000002c225f8(param_2);
  if (plVar13 == (long *)0x0) {
    return 1;
  }
  lVar14 = (**(code **)(*plVar13 + 0x138))(plVar13,"Data");
  if ((lVar14 != 0) &&
     (plVar15 = (long *)thunk_EXT_FUN_8011000003890f30
                                  (lVar14,*(undefined8 *)PTR_DAT_fffffff00802a3d0),
     plVar15 != (long *)0x0)) {
    uVar20 = (**(code **)(*plVar15 + 0xa0))();
    uVar9 = (uint)uVar20;
    if (uVar9 != 0) {
      lVar14 = (**(code **)(*plVar13 + 0x138))(plVar13,"Type");
      if (((lVar14 == 0) ||
          (plVar16 = (long *)thunk_EXT_FUN_8011000003890f30
                                       (lVar14,*(undefined8 *)PTR_DAT_fffffff00802a3f0),
          plVar16 == (long *)0x0)) ||
         (iVar8 = (**(code **)(*plVar16 + 0xb8))(plVar16,"CEA-861:Type1"), iVar8 == 0)) {
        *(undefined8 *)(param_1 + 0x201) = 0;
        *(undefined8 *)(param_1 + 0x211) = 0;
        *(undefined8 *)(param_1 + 0x219) = 0;
        uVar12 = 1;
        *(undefined8 *)(param_1 + 0x209) = 0;
        goto LAB_fffffff009abc6e0;
      }
      *(undefined4 *)(param_1 + 0x201) = 1;
      *(uint *)(param_1 + 0x205) = uVar9;
      uVar17 = (**(code **)(*plVar15 + 0xe0))(plVar15,0,uVar20);
      uVar12 = 0;
      if (0x18 < uVar9) goto LAB_fffffff009abc6e0;
      thunk_EXT_FUN_8011000003a61b10(param_1 + 0x209,uVar17,uVar20 & 0xffffffff);
    }
  }
  uVar12 = 1;
LAB_fffffff009abc6e0:
  (**(code **)(*plVar13 + 0x28))(plVar13);
  return uVar12;
}

