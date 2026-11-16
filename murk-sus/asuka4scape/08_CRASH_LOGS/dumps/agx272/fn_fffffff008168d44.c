// FUN_fffffff008168d44 @ fffffff008168d44 size=436

void FUN_fffffff008168d44(long param_1,ulong *param_2)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  long *plVar4;
  ulong *puVar5;
  uint *puVar6;
  undefined4 *puVar7;
  ulong uVar8;
  undefined4 uVar9;
  
  uVar8 = *(ulong *)(param_1 + 0x105f8);
  lVar3 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-fast-die0-sensor-mask64");
  puVar2 = PTR_DAT_fffffff007ca6090;
  if ((lVar3 == 0) ||
     (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar3,*(undefined8 *)PTR_DAT_fffffff007ca6090)
     , plVar4 == (long *)0x0)) {
    lVar3 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                      (*(long **)(param_1 + 0x138),"gpu-fast-die0-sensor-mask");
    if ((lVar3 != 0) &&
       (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar3,*(undefined8 *)puVar2),
       plVar4 != (long *)0x0)) {
      puVar6 = (uint *)(**(code **)(*plVar4 + 0xd8))();
      uVar8 = uVar8 & *puVar6;
    }
  }
  else {
    puVar5 = (ulong *)(**(code **)(*plVar4 + 0xd8))();
    uVar8 = *puVar5 & uVar8;
  }
  lVar3 = (**(code **)(**(long **)(param_1 + 0x138) + 0x118))
                    (*(long **)(param_1 + 0x138),"gpu-fast-die0-target");
  if ((lVar3 == 0) ||
     (plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar3,*(undefined8 *)puVar2),
     plVar4 == (long *)0x0)) {
    uVar9 = 0x42ca0000;
  }
  else {
    puVar7 = (undefined4 *)(**(code **)(*plVar4 + 0xd8))();
    uVar9 = NEON_ucvtf(*puVar7);
  }
  *param_2 = uVar8;
  *(undefined4 *)(param_2 + 1) = uVar9;
  *(undefined4 *)(param_2 + 2) = 0;
  iVar1 = *(int *)(param_1 + 0x19440);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x10aa8);
  *(int *)((long)param_2 + 0x24) = iVar1 * 100 + -100;
  return;
}

