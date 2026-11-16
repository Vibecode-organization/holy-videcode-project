// FUN_fffffff0081cf544 @ fffffff0081cf544 size=7028

/* WARNING: Removing unreachable block (ram,0xfffffff0081d0a2c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d0768) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d03e0) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d0428) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d07b0) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d0d10) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081cf5d8) */

void FUN_fffffff0081cf544(long param_1)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  long *plVar5;
  undefined4 *puVar6;
  uint *puVar7;
  float *pfVar8;
  undefined4 uVar9;
  uint uVar10;
  long lVar11;
  uint uVar12;
  long lVar13;
  long *plVar14;
  undefined8 uVar15;
  int iVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar22;
  undefined8 uVar20;
  undefined8 uVar21;
  long local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  
  FUN_fffffff0081ab778();
  lVar11 = *(long *)(param_1 + 0x280);
  lVar13 = *(long *)(param_1 + 0x2a0);
  *(uint *)(lVar13 + 0xfdc) = *(uint *)(lVar11 + 0x5c8) >> 10 & 1;
  iVar2 = *(int *)(param_1 + 0xb70);
  *(uint *)(lVar13 + 0x1064) = *(uint *)(lVar11 + 0x5c8) >> 0x19 & 1;
  *(undefined4 *)(lVar13 + 0x1068) = *(undefined4 *)(lVar11 + 0x1094c);
  uVar15 = *(undefined8 *)(lVar11 + 68000);
  *(undefined8 *)(lVar13 + 0x1094) = *(undefined8 *)(lVar11 + 0x109a8);
  *(undefined8 *)(lVar13 + 0x108c) = uVar15;
  *(undefined4 *)(lVar11 + 0x10ec8) = 0x271;
  lVar13 = **(long **)(lVar11 + 0x138);
  lVar11 = (**(code **)(lVar13 + 0x118))
                     (lVar13 + 0x118,*(long **)(lVar11 + 0x138),"gpu-idle-off-delay-ms");
  puVar4 = PTR_DAT_fffffff007ca6090;
  if ((lVar11 == 0) ||
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30
                                 (lVar11,*(undefined8 *)PTR_DAT_fffffff007ca6090),
     plVar5 == (long *)0x0)) {
    uVar9 = 0;
  }
  else {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    uVar9 = *puVar6;
  }
  *(undefined4 *)(param_1 + 0x1bf4) = uVar9;
  *(undefined8 *)(param_1 + 0x1bf8) = 0;
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-fender-idle-off-delay-ms");
  if ((lVar11 == 0) ||
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 == (long *)0x0)) {
    uVar9 = 0x28;
  }
  else {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    uVar9 = *puVar6;
  }
  *(undefined4 *)(param_1 + 0x1c00) = uVar9;
  *(undefined8 *)(param_1 + 0x1c04) = 0;
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-fw-early-wake-timeout-ms");
  if ((lVar11 == 0) ||
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 == (long *)0x0)) {
    uVar9 = 5;
  }
  else {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    uVar9 = *puVar6;
  }
  *(undefined4 *)(param_1 + 0x1c0c) = uVar9;
  *(undefined8 *)(param_1 + 0x1c10) = 0;
  lVar13 = *(long *)(param_1 + 0x280);
  uVar9 = *(undefined4 *)(lVar13 + 0x10f20);
  lVar11 = (**(code **)(**(long **)(lVar13 + 0x138) + 0x118))
                     (*(long **)(lVar13 + 0x138),"gpu-perf-boost-min-util");
  if ((lVar11 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    uVar9 = *puVar6;
  }
  *(undefined4 *)(lVar13 + 0x10f20) = uVar9;
  uVar9 = *(undefined4 *)(lVar13 + 0x10f24);
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-perf-boost-ce-step");
  if ((lVar11 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    uVar9 = *puVar6;
  }
  *(undefined4 *)(lVar13 + 0x10f24) = uVar9;
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-perf-reset-iters");
  if ((lVar11 == 0) ||
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 == (long *)0x0)) {
    uVar9 = 6;
  }
  else {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    uVar9 = *puVar6;
  }
  plVar14 = *(long **)(param_1 + 0x280);
  *(undefined4 *)(plVar14 + 0x21e5) = uVar9;
  *(undefined4 *)(param_1 + 0x1b41) = 0;
  *(undefined4 *)(param_1 + 0x1b49) = 0;
  *(undefined4 *)(param_1 + 0x1b39) = 0;
  *(undefined1 *)(param_1 + 0x1b52) = 0;
  *(undefined1 *)(param_1 + 0x1b54) = 0;
  *(undefined1 *)(param_1 + 0x1b56) = 0;
  *(undefined4 *)(param_1 + 0x1b45) = 0;
  *(undefined4 *)(param_1 + 0x1b4d) = 0;
  *(undefined4 *)(param_1 + 0x1b3d) = 0;
  *(undefined1 *)(param_1 + 0x1b53) = 0;
  *(undefined1 *)(param_1 + 0x1b55) = 0;
  *(undefined1 *)(param_1 + 6999) = 0;
  *(undefined1 *)(param_1 + 0x1b51) = 0;
  *(undefined1 *)(param_1 + 7000) = 0;
  *(undefined4 *)(param_1 + 0x1b20) = 0;
  *(undefined4 *)(param_1 + 0x1b28) = 0;
  *(undefined4 *)(param_1 + 0x1b2c) = 0;
  *(undefined1 *)(param_1 + 0x1b38) = 0;
  *(undefined4 *)(param_1 + 0x1b30) = 0;
  *(undefined4 *)(param_1 + 0x1b24) = 0;
  *(undefined4 *)(param_1 + 0x1b34) = 0;
  *(undefined1 *)(*(long *)(param_1 + 0x918) + 0x5c8) = 0;
  iVar16 = *(int *)(param_1 + 0xb70);
  *(byte *)(plVar14 + 0x21ef) = (byte)(uint)((ulong)plVar14[0xb9] >> 0x22) & 1;
  uVar15 = NEON_fmov(0x3f800000,4);
  fVar22 = (float)((ulong)uVar15 >> 0x20);
  plVar5 = plVar14;
  if (((ulong)plVar14[0xb9] >> 0x22 & 1) == 0) goto LAB_fffffff0081d0388;
  lVar11 = (**(code **)(*(long *)plVar14[0x27] + 0x118))
                     ((long *)plVar14[0x27],"gpu-power-zone-target-0");
  if ((lVar11 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)((long)plVar14 + 0x10f94) = *puVar6;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-power-zone-target-offset-0");
  if ((lVar11 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(plVar14 + 0x21f3) = *puVar6;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-power-zone-filter-tc-0");
  if ((lVar11 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)((long)plVar14 + 0x10f9c) = *puVar6;
  }
  *(int *)(plVar14 + 0x21f4) = *(int *)((long)plVar14 + 0x10f9c) << 2;
  uVar9 = 0;
  if (*(int *)((long)plVar14 + 0x10f94) != 0) {
    plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
    lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-power-zone-target-1");
    if ((lVar11 != 0) &&
       (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
       plVar5 != (long *)0x0)) {
      puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
      *(undefined4 *)((long)plVar14 + 0x10fa4) = *puVar6;
    }
    plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
    lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-power-zone-target-offset-1");
    if ((lVar11 != 0) &&
       (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
       plVar5 != (long *)0x0)) {
      puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
      *(undefined4 *)(plVar14 + 0x21f5) = *puVar6;
    }
    plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
    lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-power-zone-filter-tc-1");
    if ((lVar11 != 0) &&
       (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
       plVar5 != (long *)0x0)) {
      puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
      *(undefined4 *)((long)plVar14 + 0x10fac) = *puVar6;
    }
    *(int *)(plVar14 + 0x21f6) = *(int *)((long)plVar14 + 0x10fac) << 2;
    if (*(int *)((long)plVar14 + 0x10fa4) == 0) {
      uVar9 = 1;
    }
    else {
      plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
      lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-power-zone-target-2");
      if ((lVar11 != 0) &&
         (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
         plVar5 != (long *)0x0)) {
        puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
        *(undefined4 *)((long)plVar14 + 0x10fb4) = *puVar6;
      }
      plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
      lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-power-zone-target-offset-2");
      if ((lVar11 != 0) &&
         (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
         plVar5 != (long *)0x0)) {
        puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
        *(undefined4 *)(plVar14 + 0x21f7) = *puVar6;
      }
      plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
      lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-power-zone-filter-tc-2");
      if ((lVar11 != 0) &&
         (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
         plVar5 != (long *)0x0)) {
        puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
        *(undefined4 *)((long)plVar14 + 0x10fbc) = *puVar6;
      }
      *(int *)(plVar14 + 0x21f8) = *(int *)((long)plVar14 + 0x10fbc) << 2;
      if (*(int *)((long)plVar14 + 0x10fb4) == 0) {
        uVar9 = 2;
      }
      else {
        plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
        lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-power-zone-target-3");
        if ((lVar11 != 0) &&
           (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
           plVar5 != (long *)0x0)) {
          puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
          *(undefined4 *)((long)plVar14 + 0x10fc4) = *puVar6;
        }
        plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
        lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-power-zone-target-offset-3");
        if ((lVar11 != 0) &&
           (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
           plVar5 != (long *)0x0)) {
          puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
          *(undefined4 *)(plVar14 + 0x21f9) = *puVar6;
        }
        plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
        lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-power-zone-filter-tc-3");
        if ((lVar11 != 0) &&
           (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
           plVar5 != (long *)0x0)) {
          puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
          *(undefined4 *)((long)plVar14 + 0x10fcc) = *puVar6;
        }
        *(int *)(plVar14 + 0x21fa) = *(int *)((long)plVar14 + 0x10fcc) << 2;
        if (*(int *)((long)plVar14 + 0x10fc4) == 0) {
          uVar9 = 3;
        }
        else {
          plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
          lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-power-zone-target-4");
          if ((lVar11 != 0) &&
             (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
             plVar5 != (long *)0x0)) {
            puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
            *(undefined4 *)((long)plVar14 + 0x10fd4) = *puVar6;
          }
          plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
          lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-power-zone-target-offset-4");
          if ((lVar11 != 0) &&
             (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
             plVar5 != (long *)0x0)) {
            puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
            *(undefined4 *)(plVar14 + 0x21fb) = *puVar6;
          }
          plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
          lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-power-zone-filter-tc-4");
          if ((lVar11 != 0) &&
             (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
             plVar5 != (long *)0x0)) {
            puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
            *(undefined4 *)((long)plVar14 + 0x10fdc) = *puVar6;
          }
          *(int *)(plVar14 + 0x21fc) = *(int *)((long)plVar14 + 0x10fdc) << 2;
          uVar9 = 4;
          if (*(int *)((long)plVar14 + 0x10fd4) != 0) {
            uVar9 = 5;
          }
        }
      }
    }
  }
  *(undefined4 *)(plVar14 + 0x21f0) = uVar9;
  *(undefined4 *)((long)plVar14 + 0x10f84) = uVar9;
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-avg-power-min-duty-cycle");
  if ((lVar11 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(plVar14 + 0x21f1) = *puVar6;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-avg-power-target-filter-tc");
  if ((lVar11 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)((long)plVar14 + 0x10f8c) = *puVar6;
  }
  *(int *)(plVar14 + 0x21f2) = *(int *)((long)plVar14 + 0x10f8c) << 2;
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-avg-power-filter-tc-ms");
  if ((lVar11 == 0) ||
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 == (long *)0x0)) {
    plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
    lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-avg-power-input-filter-tc");
    if ((lVar11 != 0) &&
       (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
       plVar5 != (long *)0x0)) {
      puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
      *(undefined4 *)(plVar14 + 0x21fe) = *puVar6;
    }
    *(int *)((long)plVar14 + 0x10ff4) = *(int *)((long)plVar14 + 0x10fec) * (int)plVar14[0x21fe];
  }
  else {
    puVar7 = (uint *)(**(code **)(*plVar5 + 0xd8))();
    uVar3 = *puVar7;
    uVar12 = 0;
    if (*(uint *)((long)plVar14 + 0x10fec) != 0) {
      uVar12 = uVar3 / *(uint *)((long)plVar14 + 0x10fec);
    }
    *(uint *)(plVar14 + 0x21fe) = uVar12;
    *(uint *)((long)plVar14 + 0x10ff4) = uVar3;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-avg-power-ki-only");
  if ((lVar11 == 0) ||
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 == (long *)0x0)) {
    plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
    lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-avg-power-ki");
    if ((lVar11 != 0) &&
       (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
       plVar5 != (long *)0x0)) {
      pfVar8 = (float *)(**(code **)(*plVar5 + 0xd8))();
      fVar17 = *pfVar8;
      goto LAB_fffffff0081d026c;
    }
  }
  else {
    pfVar8 = (float *)(**(code **)(*plVar5 + 0xd8))();
    fVar17 = (float)NEON_ucvtf(*(undefined4 *)((long)plVar14 + 0x10fec));
    fVar17 = *pfVar8 * (fVar17 / 1000.0);
LAB_fffffff0081d026c:
    *(float *)((long)plVar14 + 0x11014) = fVar17;
  }
  uVar3 = iVar16 * 100;
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-avg-power-kp");
  if ((lVar11 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(plVar14 + 0x2204) = *puVar6;
  }
  uVar10 = *(uint *)((long)plVar14 + 0x10f7c);
  *(uint *)(plVar14 + 0x21fd) = uVar10;
  uVar12 = *(uint *)(plVar14 + 0x21fe);
  plVar14[0x21ff] = (ulong)(uVar12 * *(int *)((long)plVar14 + 0x10fec) * 24000);
  *(uint *)(plVar14 + 0x2200) = uVar12 << 2;
  fVar17 = (float)uVar12;
  *(ulong *)((long)plVar14 + 0x11004) = CONCAT44(fVar22 / fVar17,(fVar17 + -1.0) / fVar17);
  *(undefined4 *)(plVar14 + 0x2203) = 0;
  *(uint *)((long)plVar14 + 0x1100c) = uVar10;
  *(uint *)(plVar14 + 0x2202) = uVar10;
  plVar5 = *(long **)(param_1 + 0x280);
  if ((*(byte *)((long)plVar5 + 0x5cc) >> 3 & 1) == 0) {
    iVar16 = (int)plVar14[0x21f1];
    fVar17 = 0.0;
    uVar10 = 0x10000;
    uVar12 = uVar3;
  }
  else {
    uVar12 = 0;
    fVar17 = -(float)uVar3 / (float)uVar10;
    iVar16 = (int)plVar14[0x21f1] + iVar16 * -100;
  }
  *(uint *)((long)plVar14 + 0x1101c) = uVar10;
  *(float *)((long)plVar14 + 0x11024) = fVar17;
  *(int *)(plVar14 + 0x2205) = iVar16;
  *(uint *)((long)plVar14 + 0x1102c) = uVar12;
  *(uint *)(plVar14 + 0x2206) = uVar3;
  *(undefined4 *)((long)plVar14 + 0x11044) = *(undefined4 *)((long)plVar5 + 0x10f0c);
LAB_fffffff0081d0388:
  *(undefined4 *)(*(long *)(param_1 + 0x2a0) + 0x10a0) = 0;
  local_60 = 0;
  uStack_78 = 0;
  local_80 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  uStack_a8 = 0;
  uStack_b0 = 0;
  uStack_d8 = 0;
  local_e0 = 0;
  uStack_c8 = 0;
  uStack_d0 = 0;
  uStack_f8 = 0;
  local_100 = 0;
  uStack_e8 = 0;
  uStack_f0 = 0;
  uStack_118 = 0;
  local_120 = 0;
  uStack_108 = 0;
  uStack_110 = 0;
  uStack_138 = 0;
  local_140 = 0;
  uStack_128 = 0;
  uStack_130 = 0;
  uStack_158 = 0;
  local_160 = 0;
  uStack_148 = 0;
  uStack_150 = 0;
  uStack_178 = 0;
  local_180 = 0;
  uStack_168 = 0;
  local_170 = 0;
  (**(code **)(*plVar5 + 0x9b8))(*plVar5 + 0x9b8,plVar5,&local_180);
  plVar14 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = *plVar14;
  lVar11 = (**(code **)(lVar11 + 0x118))(lVar11 + 0x118,plVar14,"gpu-fast-die0-release-temp");
  if ((lVar11 != 0) &&
     (plVar14 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar14 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar14 + 0xd8))();
    *(undefined4 *)((long)plVar5 + 0x10ad4) = *puVar6;
  }
  plVar14 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar14 + 0x118))(plVar14,"gpu-fast-die0-prop-tgt-delta");
  if ((lVar11 != 0) &&
     (plVar14 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar14 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar14 + 0xd8))();
    *(undefined4 *)(plVar5 + 0x215a) = *puVar6;
  }
  plVar14 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar14 + 0x118))(plVar14,"gpu-fast-die0-proportional-gain");
  if ((lVar11 != 0) &&
     (plVar14 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar14 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar14 + 0xd8))();
    *(undefined4 *)(plVar5 + 0x215d) = *puVar6;
  }
  plVar14 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar14 + 0x118))(plVar14,"gpu-fast-die0-integral-gain");
  if ((lVar11 != 0) &&
     (plVar14 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar14 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar14 + 0xd8))();
    *(undefined4 *)((long)plVar5 + 0x10aec) = *puVar6;
  }
  plVar5[0x2157] = local_180;
  *(int *)((long)plVar5 + 0x10acc) = (int)((float)uStack_178 * 100.0);
  uVar20 = NEON_ucvtf(plVar5[0x215a],4);
  iVar16 = (int)((float)((ulong)uVar20 >> 0x20) * 100.0);
  plVar5[0x215a] = CONCAT44(iVar16,(int)((float)uVar20 * 100.0));
  fVar17 = (float)NEON_ucvtf((int)plVar5[0x2158]);
  *(float *)((long)plVar5 + 0x10aec) =
       *(float *)((long)plVar5 + 0x10aec) * ((fVar17 / 24000.0) / 1000.0);
  *(int *)(plVar5 + 0x215b) = (int)((float)local_170 * 100.0);
  *(int *)((long)plVar5 + 0x10ac4) = (int)((float)uStack_178 * 100.0);
  *(int *)(plVar5 + 0x2159) = iVar16;
  *(undefined8 *)((long)plVar5 + 0x10afc) = local_160;
  *(undefined4 *)((long)plVar5 + 0x10b04) = local_160._4_4_;
  *(undefined8 *)((long)plVar5 + 0x10b54) = uStack_130;
  *(undefined8 *)((long)plVar5 + 0x10b4c) = uStack_138;
  *(undefined8 *)((long)plVar5 + 0x10b64) = local_120;
  *(undefined8 *)((long)plVar5 + 0x10b5c) = uStack_128;
  *(undefined8 *)((long)plVar5 + 0x10b34) = uStack_150;
  *(undefined8 *)((long)plVar5 + 0x10b2c) = uStack_158;
  *(undefined8 *)((long)plVar5 + 0x10b44) = local_140;
  *(undefined8 *)((long)plVar5 + 0x10b3c) = uStack_148;
  *(undefined8 *)((long)plVar5 + 0x10b94) = uStack_f0;
  *(undefined8 *)((long)plVar5 + 0x10b8c) = uStack_f8;
  *(undefined8 *)((long)plVar5 + 0x10ba4) = local_e0;
  *(undefined8 *)((long)plVar5 + 0x10b9c) = uStack_e8;
  *(undefined8 *)((long)plVar5 + 0x10b74) = uStack_110;
  *(undefined8 *)((long)plVar5 + 0x10b6c) = uStack_118;
  *(undefined8 *)((long)plVar5 + 0x10b84) = local_100;
  *(undefined8 *)((long)plVar5 + 0x10b7c) = uStack_108;
  *(undefined8 *)((long)plVar5 + 0x10bd4) = uStack_b0;
  *(undefined8 *)((long)plVar5 + 0x10bcc) = uStack_b8;
  *(undefined8 *)((long)plVar5 + 0x10be4) = local_a0;
  *(undefined8 *)((long)plVar5 + 0x10bdc) = uStack_a8;
  *(undefined8 *)((long)plVar5 + 0x10bb4) = uStack_d0;
  *(undefined8 *)((long)plVar5 + 0x10bac) = uStack_d8;
  *(undefined8 *)((long)plVar5 + 0x10bc4) = local_c0;
  *(undefined8 *)((long)plVar5 + 0x10bbc) = uStack_c8;
  *(undefined8 *)((long)plVar5 + 0x10c14) = uStack_70;
  *(undefined8 *)((long)plVar5 + 0x10c0c) = uStack_78;
  *(undefined8 *)((long)plVar5 + 0x10c24) = local_60;
  *(undefined8 *)((long)plVar5 + 0x10c1c) = uStack_68;
  *(undefined8 *)((long)plVar5 + 0x10bf4) = uStack_90;
  *(undefined8 *)((long)plVar5 + 0x10bec) = uStack_98;
  *(undefined8 *)((long)plVar5 + 0x10c04) = local_80;
  *(undefined8 *)((long)plVar5 + 0x10bfc) = uStack_88;
  *(undefined8 *)((long)plVar5 + 0x10cf4) = uStack_90;
  *(undefined8 *)((long)plVar5 + 0x10cec) = uStack_98;
  *(undefined8 *)((long)plVar5 + 0x10d04) = local_80;
  *(undefined8 *)((long)plVar5 + 0x10cfc) = uStack_88;
  *(undefined8 *)((long)plVar5 + 0x10d14) = uStack_70;
  *(undefined8 *)((long)plVar5 + 0x10d0c) = uStack_78;
  *(undefined8 *)((long)plVar5 + 0x10d24) = local_60;
  *(undefined8 *)((long)plVar5 + 0x10d1c) = uStack_68;
  *(undefined8 *)((long)plVar5 + 0x10cb4) = uStack_d0;
  *(undefined8 *)((long)plVar5 + 0x10cac) = uStack_d8;
  *(undefined8 *)((long)plVar5 + 0x10cc4) = local_c0;
  *(undefined8 *)((long)plVar5 + 0x10cbc) = uStack_c8;
  *(undefined8 *)((long)plVar5 + 0x10cd4) = uStack_b0;
  *(undefined8 *)((long)plVar5 + 0x10ccc) = uStack_b8;
  *(undefined8 *)((long)plVar5 + 0x10ce4) = local_a0;
  *(undefined8 *)((long)plVar5 + 0x10cdc) = uStack_a8;
  *(undefined8 *)((long)plVar5 + 0x10c74) = uStack_110;
  *(undefined8 *)((long)plVar5 + 0x10c6c) = uStack_118;
  *(undefined8 *)((long)plVar5 + 0x10c84) = local_100;
  *(undefined8 *)((long)plVar5 + 0x10c7c) = uStack_108;
  *(undefined8 *)((long)plVar5 + 0x10c94) = uStack_f0;
  *(undefined8 *)((long)plVar5 + 0x10c8c) = uStack_f8;
  *(undefined8 *)((long)plVar5 + 0x10ca4) = local_e0;
  *(undefined8 *)((long)plVar5 + 0x10c9c) = uStack_e8;
  *(undefined8 *)((long)plVar5 + 0x10c34) = uStack_150;
  *(undefined8 *)((long)plVar5 + 0x10c2c) = uStack_158;
  *(undefined8 *)((long)plVar5 + 0x10c44) = local_140;
  *(undefined8 *)((long)plVar5 + 0x10c3c) = uStack_148;
  *(undefined8 *)((long)plVar5 + 0x10c54) = uStack_130;
  *(undefined8 *)((long)plVar5 + 0x10c4c) = uStack_138;
  *(undefined8 *)((long)plVar5 + 0x10c64) = local_120;
  *(undefined8 *)((long)plVar5 + 0x10c5c) = uStack_128;
  *(undefined4 *)(plVar5 + 0x2161) = 0;
  *(undefined8 *)((long)plVar5 + 0x10b24) = 0;
  *(undefined8 *)((long)plVar5 + 0x10b1c) = 0;
  plVar5[0x2162] = 0;
  (**(code **)(**(long **)(param_1 + 0x280) + 0x9c8))(*(long **)(param_1 + 0x280),param_1 + 0x1858);
  lVar13 = *(long *)(param_1 + 0x280);
  lVar11 = **(long **)(lVar13 + 0x138);
  lVar11 = (**(code **)(lVar11 + 0x118))
                     (lVar11 + 0x118,*(long **)(lVar13 + 0x138),"gpu-ppm-filter-time-constant-ms");
  if ((lVar11 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar13 + 0x10d3c) = *puVar6;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-ppm-kp");
  if ((lVar11 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar13 + 0x10d68) = *puVar6;
  }
  iVar2 = iVar2 * 100;
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar11 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-ppm-ki");
  if ((lVar11 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar11,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar13 + 0x10d5c) = *puVar6;
  }
  *(undefined4 *)(lVar13 + 0x10d58) = *(undefined4 *)(lVar13 + 0x10d30);
  uVar3 = *(uint *)(lVar13 + 0x10d34);
  uVar12 = 0;
  if (uVar3 != 0) {
    uVar12 = *(uint *)(lVar13 + 0x10d3c) / uVar3;
  }
  *(uint *)(lVar13 + 0x10d38) = uVar12;
  *(ulong *)(lVar13 + 0x10d40) = (ulong)(uVar3 * uVar12 * 24000);
  *(uint *)(lVar13 + 0x10d48) = uVar12 << 2;
  fVar17 = (float)uVar12;
  *(ulong *)(lVar13 + 0x10d4c) = CONCAT44(fVar22 / fVar17,(fVar17 + -1.0) / fVar17);
  *(float *)(lVar13 + 0x10d5c) = ((float)uVar3 / 1000.0) * *(float *)(lVar13 + 0x10d5c);
  lVar11 = *(long *)(param_1 + 0x280);
  *(undefined4 *)(lVar13 + 0x10d60) = *(undefined4 *)(lVar11 + 0x10ee0);
  *(undefined4 *)(lVar13 + 0x10d54) = *(undefined4 *)(lVar13 + 0x10d30);
  *(undefined4 *)(lVar13 + 0x10d70) = *(undefined4 *)(lVar11 + 0x10aa8);
  *(int *)(lVar13 + 0x10d74) = iVar2;
  *(undefined4 *)(lVar13 + 0x10d7c) = 0;
  *(undefined8 *)(lVar13 + 69000) = 0;
  *(undefined8 *)(lVar13 + 0x10d80) = 0;
  *(undefined1 *)(param_1 + 0xba4) = 1;
  uVar9 = *(undefined4 *)(lVar11 + 0x10d30);
  *(undefined4 *)(param_1 + 0xbac) = uVar9;
  *(undefined4 *)(param_1 + 0xba8) = uVar9;
  *(undefined8 *)(param_1 + 0x18ec) = 0x1000000000000;
  *(undefined4 *)(param_1 + 0x18f4) = *(undefined4 *)(lVar11 + 0x10f64);
  *(int *)(param_1 + 0x18f8) = iVar2;
  lVar13 = (ulong)*(uint *)(param_1 + 0xb70) * 4;
  puVar7 = (uint *)(lVar11 + 0x19448 + (long)(int)lVar13);
  if (lVar13 - (int)lVar13 != 0) {
    puVar7 = (uint *)(lVar11 + 0x19448 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *(uint *)(param_1 + 0x18fc) = *puVar7 / 1000000;
  *(undefined8 *)(param_1 + 0x1900) = 0;
  *(undefined1 *)(param_1 + 0xbb0) = 1;
  *(undefined8 *)(param_1 + 0xbb4) = 0;
  lVar13 = **(long **)(lVar11 + 0x138);
  lVar13 = (**(code **)(lVar13 + 0x118))
                     (lVar13 + 0x118,*(long **)(lVar11 + 0x138),"gpu-se-filter-time-constant");
  if ((lVar13 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar13,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar11 + 0x10df4) = *puVar6;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar13 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-se-filter-time-constant-1");
  if ((lVar13 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar13,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar11 + 0x10df8) = *puVar6;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar13 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-se-kp");
  if ((lVar13 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar13,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar11 + 0x10e0c) = *puVar6;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar13 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-se-kp-1");
  if ((lVar13 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar13,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar11 + 0x10e10) = *puVar6;
  }
  puVar1 = (undefined8 *)(lVar11 + 0x10e14);
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar13 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-se-ki");
  if ((lVar13 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar13,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)puVar1 = *puVar6;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar13 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-se-ki-1");
  if ((lVar13 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar13,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar11 + 0x10e18) = *puVar6;
  }
  fVar17 = (float)NEON_ucvtf(*(undefined4 *)(lVar11 + 0x10ddc));
  uVar20 = NEON_ucvtf(*(undefined8 *)(lVar11 + 0x10df4),4);
  uVar21 = NEON_fmov(0xbf800000,4);
  fVar18 = (float)uVar20;
  fVar19 = (float)((ulong)uVar20 >> 0x20);
  *(ulong *)(lVar11 + 0x10e04) = CONCAT44(fVar22 / fVar19,(float)uVar15 / fVar18);
  *(ulong *)(lVar11 + 0x10dfc) =
       CONCAT44((fVar19 + (float)((ulong)uVar21 >> 0x20)) / fVar19,(fVar18 + (float)uVar21) / fVar18
               );
  *puVar1 = CONCAT44((float)((ulong)*puVar1 >> 0x20) * (fVar17 / 1000.0),
                     (float)*puVar1 * (fVar17 / 1000.0));
  *(int *)(lVar11 + 0x10e2c) = iVar2;
  lVar13 = *(long *)(param_1 + 0x280);
  *(undefined4 *)(lVar11 + 0x10e24) = *(undefined4 *)(lVar13 + 0x10f64);
  plVar5 = *(long **)(lVar13 + 0x138);
  lVar13 = *plVar5;
  lVar13 = (**(code **)(lVar13 + 0x118))(lVar13 + 0x118,plVar5,"gpu-se-tgt");
  if ((lVar13 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar13,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar11 + 0x10de0) = *puVar6;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar13 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-se-dz");
  if ((lVar13 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar13,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar11 + 0x10de0) = *puVar6;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar13 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-se-inactive-threshold");
  if ((lVar13 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar13,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar11 + 0x10e30) = *puVar6;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar13 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-se-engagement-criteria");
  if ((lVar13 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar13,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar11 + 0x10e34) = *puVar6;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar13 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-se-engagement-tolerance");
  if ((lVar13 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar13,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar11 + 0x10e38) = *puVar6;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar13 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-se-reset-tolerance");
  if ((lVar13 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar13,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar11 + 0x10e3c) = *puVar6;
  }
  plVar5 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar13 = (**(code **)(*plVar5 + 0x118))(plVar5,"gpu-se-reset-criteria");
  if ((lVar13 != 0) &&
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar13,*(undefined8 *)puVar4),
     plVar5 != (long *)0x0)) {
    puVar6 = (undefined4 *)(**(code **)(*plVar5 + 0xd8))();
    *(undefined4 *)(lVar11 + 0x10e40) = *puVar6;
  }
  *(int *)(lVar11 + 0x10de0) = *(int *)(lVar11 + 0x10de0) - *(int *)(lVar11 + 0x10de4);
  (**(code **)(**(long **)(param_1 + 0x280) + 0x9c0))(*(long **)(param_1 + 0x280),param_1 + 0x1910);
  *(undefined8 *)(param_1 + 0x1ae4) = *(undefined8 *)(param_1 + 0x19e4);
  *(undefined8 *)(param_1 + 0x1adc) = *(undefined8 *)(param_1 + 0x19dc);
  *(undefined8 *)(param_1 + 0x1af4) = *(undefined8 *)(param_1 + 0x19f4);
  *(undefined8 *)(param_1 + 0x1aec) = *(undefined8 *)(param_1 + 0x19ec);
  *(undefined8 *)(param_1 + 0x1b04) = *(undefined8 *)(param_1 + 0x1a04);
  *(undefined8 *)(param_1 + 0x1afc) = *(undefined8 *)(param_1 + 0x19fc);
  *(undefined8 *)(param_1 + 0x1b14) = *(undefined8 *)(param_1 + 0x1a14);
  *(undefined8 *)(param_1 + 0x1b0c) = *(undefined8 *)(param_1 + 0x1a0c);
  *(undefined8 *)(param_1 + 0x1aa4) = *(undefined8 *)(param_1 + 0x19a4);
  *(undefined8 *)(param_1 + 0x1a9c) = *(undefined8 *)(param_1 + 0x199c);
  *(undefined8 *)(param_1 + 0x1ab4) = *(undefined8 *)(param_1 + 0x19b4);
  *(undefined8 *)(param_1 + 0x1aac) = *(undefined8 *)(param_1 + 0x19ac);
  *(undefined8 *)(param_1 + 0x1ac4) = *(undefined8 *)(param_1 + 0x19c4);
  *(undefined8 *)(param_1 + 0x1abc) = *(undefined8 *)(param_1 + 0x19bc);
  *(undefined8 *)(param_1 + 0x1ad4) = *(undefined8 *)(param_1 + 0x19d4);
  *(undefined8 *)(param_1 + 0x1acc) = *(undefined8 *)(param_1 + 0x19cc);
  *(undefined8 *)(param_1 + 0x1a64) = *(undefined8 *)(param_1 + 0x1964);
  *(undefined8 *)(param_1 + 0x1a5c) = *(undefined8 *)(param_1 + 0x195c);
  *(undefined8 *)(param_1 + 0x1a74) = *(undefined8 *)(param_1 + 0x1974);
  *(undefined8 *)(param_1 + 0x1a6c) = *(undefined8 *)(param_1 + 0x196c);
  *(undefined8 *)(param_1 + 0x1a84) = *(undefined8 *)(param_1 + 0x1984);
  *(undefined8 *)(param_1 + 0x1a7c) = *(undefined8 *)(param_1 + 0x197c);
  *(undefined8 *)(param_1 + 0x1a94) = *(undefined8 *)(param_1 + 0x1994);
  *(undefined8 *)(param_1 + 0x1a8c) = *(undefined8 *)(param_1 + 0x198c);
  *(undefined8 *)(param_1 + 0x1a24) = *(undefined8 *)(param_1 + 0x1924);
  *(undefined8 *)(param_1 + 0x1a1c) = *(undefined8 *)(param_1 + 0x191c);
  *(undefined8 *)(param_1 + 0x1a34) = *(undefined8 *)(param_1 + 0x1934);
  *(undefined8 *)(param_1 + 0x1a2c) = *(undefined8 *)(param_1 + 0x192c);
  *(undefined8 *)(param_1 + 0x1a44) = *(undefined8 *)(param_1 + 0x1944);
  *(undefined8 *)(param_1 + 0x1a3c) = *(undefined8 *)(param_1 + 0x193c);
  *(undefined8 *)(param_1 + 0x1a54) = *(undefined8 *)(param_1 + 0x1954);
  *(undefined8 *)(param_1 + 0x1a4c) = *(undefined8 *)(param_1 + 0x194c);
  lVar11 = *(long *)(param_1 + 0x280);
  *(undefined4 *)(*(long *)(param_1 + 0x2a0) + 0xff8) = *(undefined4 *)(lVar11 + 0x5fc);
  lVar13 = *(long *)(param_1 + 0x348);
  uVar15 = *(undefined8 *)(lVar11 + 0x10a4c);
  *(undefined8 *)(lVar13 + 0x9a0) = *(undefined8 *)(lVar11 + 0x10a54);
  *(undefined8 *)(lVar13 + 0x998) = uVar15;
  *(undefined8 *)(lVar13 + 0x9a8) = *(undefined8 *)(lVar11 + 0x10a5c);
  return;
}

