// FUN_fffffff0081ab778 @ fffffff0081ab778 size=2496

/* WARNING: Removing unreachable block (ram,0xfffffff0081ab9e4) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081abc54) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ab970) */

void FUN_fffffff0081ab778(long param_1)

{
  uint uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  long *plVar4;
  long lVar5;
  long *plVar6;
  undefined4 *puVar7;
  uint *puVar8;
  long lVar9;
  uint uVar10;
  undefined1 local_31;
  
  plVar4 = *(long **)(param_1 + 0x280);
  *(int *)(param_1 + 0xb70) = (int)plVar4[0x3288] + -1;
  local_31 = 0;
  uVar3 = (**(code **)(*plVar4 + 0xd40))(plVar4,0,&local_31);
  *(undefined4 *)(param_1 + 0xb74) = uVar3;
  plVar4 = *(long **)(param_1 + 0x280);
  if ((*(byte *)((long)plVar4 + 0x43d) & 1) != 0) {
    uVar3 = (**(code **)(*plVar4 + 0xd40))(plVar4,1,&local_31);
    *(undefined4 *)(param_1 + 0xb78) = uVar3;
    plVar4 = *(long **)(param_1 + 0x280);
  }
  if ((*(byte *)((long)plVar4 + 0x43e) & 1) != 0) {
    uVar3 = (**(code **)(*plVar4 + 0xd40))(plVar4,2,&local_31);
    *(undefined4 *)(param_1 + 0xb7c) = uVar3;
    plVar4 = *(long **)(param_1 + 0x280);
  }
  uVar10 = *(int *)(param_1 + 0xb70) * 100;
  lVar5 = (**(code **)(*(long *)plVar4[0x27] + 0x118))((long *)plVar4[0x27],"gpu-device-max-power");
  puVar2 = PTR_DAT_fffffff007ca6090;
  if (((lVar5 != 0) &&
      (plVar6 = (long *)thunk_EXT_FUN_8011000003890f30
                                  (lVar5,*(undefined8 *)PTR_DAT_fffffff007ca6090),
      plVar6 != (long *)0x0)) ||
     ((plVar6 = *(long **)(*(long *)(param_1 + 0x280) + 0x138),
      lVar5 = (**(code **)(*plVar6 + 0x118))(plVar6,"gpu-max-power"), lVar5 != 0 &&
      (plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
      plVar6 != (long *)0x0)))) {
    puVar7 = (undefined4 *)(**(code **)(*plVar6 + 0xd8))();
    *(undefined4 *)(plVar4 + 0x21d6) = *puVar7;
  }
  (**(code **)(**(long **)(param_1 + 0x280) + 0x978))
            (*(long **)(param_1 + 0x280),*(undefined4 *)(param_1 + 0xb70));
  (**(code **)(**(long **)(param_1 + 0x280) + 0xbe0))(**(long **)(param_1 + 0x280) + 0xbe0);
  *(uint *)((long)plVar4 + 0x10ee4) = *(uint *)(plVar4 + 0x21d6);
  *(float *)((long)plVar4 + 0x10eec) = -(float)uVar10 / (float)*(uint *)(plVar4 + 0x21d6);
  lVar5 = *(long *)(param_1 + 0x280);
  *(undefined4 *)(plVar4 + 0x21de) = *(undefined4 *)(lVar5 + 0x10aa8);
  *(uint *)((long)plVar4 + 0x10ef4) = uVar10;
  *(uint *)(plVar4 + 0x21df) = uVar10;
  plVar6 = *(long **)(lVar5 + 0x138);
  lVar5 = *plVar6;
  lVar5 = (**(code **)(lVar5 + 0x118))(lVar5 + 0x118,plVar6,"gpu-pwr-filter-time-constant");
  if ((lVar5 != 0) &&
     (plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
     plVar6 != (long *)0x0)) {
    puVar7 = (undefined4 *)(**(code **)(*plVar6 + 0xd8))();
    *(undefined4 *)(plVar4 + 0x21d7) = *puVar7;
  }
  plVar6 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar5 = (**(code **)(*plVar6 + 0x118))(plVar6,"gpu-pwr-integral-gain");
  if ((lVar5 != 0) &&
     (plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
     plVar6 != (long *)0x0)) {
    puVar7 = (undefined4 *)(**(code **)(*plVar6 + 0xd8))();
    *(undefined4 *)((long)plVar4 + 0x10edc) = *puVar7;
  }
  plVar6 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar5 = (**(code **)(*plVar6 + 0x118))(plVar6,"gpu-pwr-integral-min-clamp");
  if ((lVar5 != 0) &&
     (plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
     plVar6 != (long *)0x0)) {
    puVar7 = (undefined4 *)(**(code **)(*plVar6 + 0xd8))();
    *(undefined4 *)(plVar4 + 0x21dc) = *puVar7;
  }
  plVar6 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
  lVar5 = (**(code **)(*plVar6 + 0x118))(plVar6,"gpu-pwr-proportional-gain");
  if ((lVar5 != 0) &&
     (plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
     plVar6 != (long *)0x0)) {
    puVar7 = (undefined4 *)(**(code **)(*plVar6 + 0xd8))();
    *(undefined4 *)(plVar4 + 0x21dd) = *puVar7;
  }
  lVar9 = *(long *)(param_1 + 0x280);
  uVar10 = *(uint *)(lVar9 + 0x10f64) / 100;
  lVar5 = (**(code **)(**(long **)(lVar9 + 0x138) + 0x118))
                    (*(long **)(lVar9 + 0x138),"gpu-perf-base-pstate");
  if ((lVar5 != 0) &&
     (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
     plVar4 != (long *)0x0)) {
    puVar8 = (uint *)(**(code **)(*plVar4 + 0xd8))();
    uVar10 = *puVar8;
  }
  if (uVar10 != 0) {
    uVar1 = *(uint *)(param_1 + 0xb70);
    if (uVar10 <= uVar1) {
      *(float *)(lVar9 + 0x10f58) =
           (float)((uVar1 - uVar10) * 100) / (float)*(int *)(lVar9 + 0x10f4c);
      *(uint *)(lVar9 + 0x10f5c) = uVar10 * 100;
      *(uint *)(lVar9 + 0x10f60) = uVar1 * 100;
      *(uint *)(lVar9 + 0x10f64) = uVar10 * 100;
      plVar4 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
      lVar5 = *plVar4;
      lVar5 = (**(code **)(lVar5 + 0x118))(lVar5 + 0x118,plVar4,"gpu-perf-tgt-utilization");
      if ((lVar5 != 0) &&
         (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
         plVar4 != (long *)0x0)) {
        puVar7 = (undefined4 *)(**(code **)(*plVar4 + 0xd8))();
        *(undefined4 *)(lVar9 + 0x10f18) = *puVar7;
      }
      plVar4 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
      lVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,"gpu-perf-dz");
      if ((lVar5 != 0) &&
         (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
         plVar4 != (long *)0x0)) {
        puVar7 = (undefined4 *)(**(code **)(*plVar4 + 0xd8))();
        *(undefined4 *)(lVar9 + 0x10f1c) = *puVar7;
      }
      plVar4 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
      lVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,"gpu-perf-filter-time-constant");
      if ((lVar5 != 0) &&
         (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
         plVar4 != (long *)0x0)) {
        puVar7 = (undefined4 *)(**(code **)(*plVar4 + 0xd8))();
        *(undefined4 *)(lVar9 + 0x10f30) = *puVar7;
      }
      plVar4 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
      lVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,"gpu-perf-filter-time-constant2");
      if ((lVar5 != 0) &&
         (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
         plVar4 != (long *)0x0)) {
        puVar7 = (undefined4 *)(**(code **)(*plVar4 + 0xd8))();
        *(undefined4 *)(lVar9 + 0x10f34) = *puVar7;
      }
      plVar4 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
      lVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,"gpu-perf-filter-drop-threshold");
      if ((lVar5 != 0) &&
         (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
         plVar4 != (long *)0x0)) {
        puVar7 = (undefined4 *)(**(code **)(*plVar4 + 0xd8))();
        *(undefined4 *)(lVar9 + 0x10f38) = *puVar7;
      }
      plVar4 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
      lVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,"gpu-perf-integral-gain");
      if ((lVar5 != 0) &&
         (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
         plVar4 != (long *)0x0)) {
        puVar7 = (undefined4 *)(**(code **)(*plVar4 + 0xd8))();
        *(undefined4 *)(lVar9 + 0x10f40) = *puVar7;
      }
      plVar4 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
      lVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,"gpu-perf-integral-gain2");
      if ((lVar5 != 0) &&
         (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
         plVar4 != (long *)0x0)) {
        puVar7 = (undefined4 *)(**(code **)(*plVar4 + 0xd8))();
        *(undefined4 *)(lVar9 + 0x10f44) = *puVar7;
      }
      plVar4 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
      lVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,"gpu-perf-integral-min-clamp");
      if ((lVar5 != 0) &&
         (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
         plVar4 != (long *)0x0)) {
        puVar7 = (undefined4 *)(**(code **)(*plVar4 + 0xd8))();
        *(undefined4 *)(lVar9 + 0x10f48) = *puVar7;
      }
      plVar4 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
      lVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,"gpu-perf-proportional-gain");
      if ((lVar5 != 0) &&
         (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
         plVar4 != (long *)0x0)) {
        puVar7 = (undefined4 *)(**(code **)(*plVar4 + 0xd8))();
        *(undefined4 *)(lVar9 + 0x10f50) = *puVar7;
      }
      plVar4 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
      lVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,"gpu-perf-proportional-gain2");
      if ((lVar5 != 0) &&
         (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
         plVar4 != (long *)0x0)) {
        puVar7 = (undefined4 *)(**(code **)(*plVar4 + 0xd8))();
        *(undefined4 *)(lVar9 + 0x10f54) = *puVar7;
      }
      *(undefined4 *)(param_1 + 0xbc8) = 5;
      plVar4 = *(long **)(*(long *)(param_1 + 0x280) + 0x138);
      lVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,"gpu-perf-limiter-filter-time-constant");
      if ((lVar5 != 0) &&
         (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)puVar2),
         plVar4 != (long *)0x0)) {
        puVar7 = (undefined4 *)(**(code **)(*plVar4 + 0xd8))();
        *(undefined4 *)(param_1 + 0xbc8) = *puVar7;
      }
      *(undefined1 *)(param_1 + 0xb80) = 1;
      uVar3 = *(undefined4 *)(*(long *)(param_1 + 0x280) + 0x10eb0);
      *(undefined4 *)(param_1 + 0xb88) = uVar3;
      *(undefined4 *)(param_1 + 0xb84) = uVar3;
      *(undefined1 *)(param_1 + 0xb8c) = 1;
      *(undefined8 *)(param_1 + 0xb90) = 0x1000000010000;
      *(undefined1 *)(param_1 + 0xb98) = 1;
      *(undefined8 *)(param_1 + 0xb9c) = 0x1000000010000;
      return;
    }
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! base_perf_state not valid (%d)\n");
  return;
}

