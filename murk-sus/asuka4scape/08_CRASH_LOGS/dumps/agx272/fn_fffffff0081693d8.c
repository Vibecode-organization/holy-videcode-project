// FUN_fffffff0081693d8 @ fffffff0081693d8 size=1316

void FUN_fffffff0081693d8(long param_1)

{
  undefined *puVar1;
  long lVar2;
  long *plVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  long *plVar6;
  long lVar7;
  
  puVar5 = (undefined4 *)(*(long *)(param_1 + 0x4b0) + 0x930);
  plVar6 = (long *)(param_1 + 0x111a8);
  *plVar6 = (long)puVar5;
  *(undefined4 *)(*(long *)(param_1 + 0x4b0) + 0x930) = 0x41d763c8;
  lVar2 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-pwr-calc-coeff0");
  puVar1 = PTR_DAT_fffffff007ca6090;
  if ((lVar2 != 0) &&
     (plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca6090)
     , plVar3 != (long *)0x0)) {
    puVar4 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    *puVar5 = *puVar4;
  }
  lVar7 = *plVar6;
  *(undefined4 *)(lVar7 + 4) = 0x40c2b43c;
  lVar2 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-pwr-calc-coeff1");
  if ((lVar2 != 0) &&
     (plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)puVar1),
     plVar3 != (long *)0x0)) {
    puVar5 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    *(undefined4 *)(lVar7 + 4) = *puVar5;
  }
  lVar7 = *plVar6;
  *(undefined4 *)(lVar7 + 8) = 0x4328b2ad;
  lVar2 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-pwr-calc-coeff2");
  if ((lVar2 != 0) &&
     (plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)puVar1),
     plVar3 != (long *)0x0)) {
    puVar5 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    *(undefined4 *)(lVar7 + 8) = *puVar5;
  }
  lVar7 = *plVar6;
  *(undefined4 *)(lVar7 + 0xc) = 0;
  lVar2 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-pwr-calc-coeff3");
  if ((lVar2 != 0) &&
     (plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)puVar1),
     plVar3 != (long *)0x0)) {
    puVar5 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    *(undefined4 *)(lVar7 + 0xc) = *puVar5;
  }
  lVar7 = *plVar6;
  *(undefined4 *)(lVar7 + 0x10) = 0;
  lVar2 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-pwr-calc-coeff4");
  if ((lVar2 != 0) &&
     (plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)puVar1),
     plVar3 != (long *)0x0)) {
    puVar5 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    *(undefined4 *)(lVar7 + 0x10) = *puVar5;
  }
  lVar7 = *plVar6;
  *(undefined4 *)(lVar7 + 0xa0) = 0x42056be1;
  lVar2 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-pwr-calc-static");
  if ((lVar2 != 0) &&
     (plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)puVar1),
     plVar3 != (long *)0x0)) {
    puVar5 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    *(undefined4 *)(lVar7 + 0xa0) = *puVar5;
  }
  lVar7 = *plVar6;
  *(undefined4 *)(lVar7 + 0x120) = 0;
  lVar2 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-pwr-perf-scale0");
  if ((lVar2 != 0) &&
     (plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)puVar1),
     plVar3 != (long *)0x0)) {
    puVar5 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    *(undefined4 *)(lVar7 + 0x120) = *puVar5;
  }
  lVar7 = *plVar6;
  *(undefined4 *)(lVar7 + 0x124) = 0x3f800000;
  lVar2 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-pwr-perf-scale1");
  if ((lVar2 != 0) &&
     (plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)puVar1),
     plVar3 != (long *)0x0)) {
    puVar5 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    *(undefined4 *)(lVar7 + 0x124) = *puVar5;
  }
  lVar7 = *plVar6;
  *(undefined4 *)(lVar7 + 0x128) = 0x3f8de211;
  lVar2 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-pwr-perf-scale2");
  if ((lVar2 != 0) &&
     (plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)puVar1),
     plVar3 != (long *)0x0)) {
    puVar5 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    *(undefined4 *)(lVar7 + 0x128) = *puVar5;
  }
  lVar7 = *plVar6;
  *(undefined4 *)(lVar7 + 300) = 0x3fabc6a8;
  lVar2 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-pwr-perf-scale3");
  if ((lVar2 != 0) &&
     (plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)puVar1),
     plVar3 != (long *)0x0)) {
    puVar5 = (undefined4 *)(**(code **)(*plVar3 + 0xd8))();
    *(undefined4 *)(lVar7 + 300) = *puVar5;
  }
  lVar7 = *plVar6;
  *(undefined4 *)(lVar7 + 0x130) = 0x3fabc6a8;
  lVar2 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-pwr-perf-scale4");
  if ((lVar2 != 0) &&
     (plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)puVar1),
     plVar6 != (long *)0x0)) {
    puVar5 = (undefined4 *)(**(code **)(*plVar6 + 0xd8))();
    *(undefined4 *)(lVar7 + 0x130) = *puVar5;
  }
  return;
}

