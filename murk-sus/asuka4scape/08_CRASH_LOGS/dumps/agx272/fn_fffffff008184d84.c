// FUN_fffffff008184d84 @ fffffff008184d84 size=244

/* WARNING: Removing unreachable block (ram,0xfffffff008184dfc) */

void FUN_fffffff008184d84(undefined8 param_1,long param_2,long param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  ulong uVar3;
  long *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined4 *puVar8;
  long lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  
  FUN_fffffff008202ad8(*(undefined8 *)(param_3 + 0x148),param_4,*(undefined4 *)(param_2 + 0x28));
  uVar1 = *(undefined4 *)(param_2 + 0x14);
  uVar10 = *(undefined8 *)(param_2 + 0x28);
  uVar3 = thunk_EXT_FUN_8011000002c13530(*(undefined8 *)(param_3 + 0x240));
  uVar11 = *(undefined8 *)(param_3 + 0x248);
  plVar4 = *(long **)(*(long *)(param_3 + 0x10) + 0x4b0);
  lVar9 = *plVar4;
  uVar5 = (**(code **)(lVar9 + 0x208))(lVar9 + 0x208,plVar4,*(undefined8 *)(param_3 + 0x260),0);
  uVar6 = *(undefined8 *)(param_3 + 0x250);
  uVar7 = *(undefined8 *)(param_2 + 0x38);
  uVar2 = *(undefined4 *)(param_2 + 0x40);
  puVar8 = *(undefined4 **)(*(long *)(param_3 + 0x148) + 0x68);
  *(undefined4 **)(*(long *)(param_3 + 0x148) + 0x68) = puVar8 + 0x13;
  *puVar8 = 0xe;
  puVar8[1] = uVar1;
  *(undefined8 *)(puVar8 + 2) = uVar10;
  *(ulong *)(puVar8 + 4) = uVar3 & 0xffffffff;
  *(undefined8 *)(puVar8 + 6) = uVar11;
  *(undefined8 *)(puVar8 + 8) = uVar6;
  *(undefined8 *)(puVar8 + 10) = uVar5;
  *(undefined8 *)(puVar8 + 0xc) = uVar7;
  puVar8[0xe] = uVar2;
  *(undefined8 *)(puVar8 + 0x11) = 0;
  *(undefined8 *)(puVar8 + 0xf) = 0;
  uVar5 = FUN_fffffff008202d20(*(undefined8 *)(param_3 + 0x148),param_2 + 0x24);
  *(undefined8 *)(param_2 + 0x1c) = uVar5;
  return;
}

