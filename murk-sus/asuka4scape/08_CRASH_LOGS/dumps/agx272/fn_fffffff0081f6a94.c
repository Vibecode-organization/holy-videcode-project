// FUN_fffffff0081f6a94 @ fffffff0081f6a94 size=696

undefined8 FUN_fffffff0081f6a94(long *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint *puVar6;
  long *plVar7;
  code *pcVar8;
  ulong uVar9;
  
  *(undefined1 *)(param_1 + 0x47) = 0;
  uVar2 = thunk_EXT_FUN_8011000002969cc0();
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  lVar3 = (**(code **)(*(long *)param_1[0xb] + 0x158))((long *)param_1[0xb],param_1[0x3d]);
  if (lVar3 == 0) {
    return 0xe00002be;
  }
  iVar1 = FUN_fffffff00819cb78
                    (param_1[2] + 0x11df0,lVar3,*(undefined4 *)((long)param_1 + 0x424),
                     param_1 + 0x3c);
  *(int *)((long)param_1 + 0x1dc) = iVar1;
  if (iVar1 == -1) {
LAB_fffffff0081f6cb0:
    pcVar8 = *(code **)(*param_1 + 0x98);
LAB_fffffff0081f6cc4:
    (*pcVar8)(param_1);
    return 0xe00002be;
  }
  lVar3 = thunk_EXT_FUN_8011000003890f30(param_1[0xc],&DAT_fffffff00ae21f50);
  if (*(int *)(*(long *)(*(long *)(lVar3 + 0x610) + 200) + 0x28) != 0) {
    (**(code **)(*param_1 + 0x88))(param_1);
    (**(code **)(*param_1 + 0x98))(param_1);
    return 0xe00002bd;
  }
  if (param_1[0x49] == 0) {
    lVar3 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x1e8))
                      (*(long **)(param_1[2] + 0x4b0),param_1 + 0x4a);
    param_1[0x49] = lVar3;
    if (lVar3 == 0) goto LAB_fffffff0081f6cb0;
  }
  puVar4 = (undefined4 *)(**(code **)(*param_1 + 0xf8))(param_1);
  *(undefined4 *)(param_1 + 0x4b) = *puVar4;
  piVar5 = (int *)(**(code **)(*param_1 + 0xf8))(param_1);
  if (*piVar5 != 0) {
    uVar9 = 0;
    do {
      if (param_1[uVar9 + 0x4c] == 0) {
        plVar7 = param_1 + 0x5b + uVar9;
        if ((((ulong)(param_1 + 0x5b) ^ (ulong)plVar7) & 0xffc0000000000000) != 0) {
          plVar7 = (long *)((ulong)plVar7 & 0xffffffffffff | 0xc8a2000000000000);
        }
        lVar3 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x1e8))
                          (*(long **)(param_1[2] + 0x4b0),plVar7);
        param_1[uVar9 + 0x4c] = lVar3;
        if (lVar3 == 0) goto LAB_fffffff0081f6d3c;
      }
      uVar9 = uVar9 + 1;
      puVar6 = (uint *)(**(code **)(*param_1 + 0xf8))(param_1);
    } while (uVar9 < *puVar6);
  }
  if (param_1[0x6a] == 0) {
    lVar3 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x200))
                      (*(long **)(param_1[2] + 0x4b0),param_1 + 0x6b);
    param_1[0x6a] = lVar3;
    if (lVar3 == 0) {
LAB_fffffff0081f6d3c:
      pcVar8 = *(code **)(*param_1 + 0x98);
      goto LAB_fffffff0081f6cc4;
    }
  }
  *(undefined1 *)(param_1 + 0x47) = 1;
  return 0;
}

