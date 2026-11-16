// FUN_fffffff0081effd8 @ fffffff0081effd8 size=684

undefined8 FUN_fffffff0081effd8(long *param_1)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined8 uVar5;
  long *plVar6;
  uint uVar7;
  long lVar8;
  undefined8 *puVar9;
  long lVar10;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined4 local_38;
  undefined4 local_34;
  
  lVar8 = *(long *)(*(long *)(param_1[2] + 0x4b0) + 0x910);
  if (*(int *)(lVar8 + 0x4040) == 1) {
    return 1;
  }
  uVar5 = (**(code **)(*param_1 + 0x108))(param_1);
  if ((int)uVar5 == 0) {
    return uVar5;
  }
  *(undefined4 *)(lVar8 + 0x4048) = *(undefined4 *)((long)param_1 + 0x2c);
  uStack_58 = 0;
  local_60 = 0;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_78 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  local_80 = 4;
  lVar10 = *(long *)(param_1[2] + 0x4b0);
  local_34 = 2;
  uVar5 = (**(code **)(*(long *)(lVar10 + 0x848) + 0x30))(lVar10 + 0x848);
  local_38 = 0;
  plVar6 = *(long **)(*(long *)(lVar10 + 0x280) + 0x310);
  puVar9 = (undefined8 *)(*plVar6 + 0xe8);
  iVar4 = (*(code *)*puVar9)(puVar9,plVar6,FUN_fffffff00817ea94,&local_80,&local_34,&local_38,0);
  if (iVar4 != 0) {
    *(bool *)((long)param_1 + 0x54) = *(int *)(lVar8 + 0x4040) != 0;
    return 0;
  }
  if (((byte)local_34 >> 1 & 1) == 0) {
    *(bool *)((long)param_1 + 0x54) = *(int *)(lVar8 + 0x4040) != 0;
  }
  else {
    iVar4 = FUN_fffffff0081a43cc(lVar10,uVar5,local_38);
    *(bool *)((long)param_1 + 0x54) = *(int *)(lVar8 + 0x4040) != 0;
    if (iVar4 != 0) {
      return 0;
    }
  }
  if (((*(byte *)((long)param_1 + 0x2c) >> 5 & 1) != 0) &&
     (iVar4 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x6c0))
                        (*(long **)(param_1[2] + 0x4b0),1,(int)param_1[6]), iVar4 == 0)) {
    *(undefined1 *)((long)param_1 + 0x34) = 1;
  }
  uVar7 = *(uint *)((long)param_1 + 0x2c);
  if ((uVar7 >> 4 & 1) != 0) {
    thunk_EXT_FUN_801100000295d6e0(*(undefined8 *)(param_1[2] + 0x160),1);
    uVar7 = *(uint *)((long)param_1 + 0x2c);
  }
  if ((uVar7 >> 9 & 1) == 0) {
    return 1;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1[2] + 0x11190));
  lVar8 = param_1[2];
  piVar1 = (int *)(lVar8 + 0x109fc);
  bVar3 = *(byte *)(lVar8 + 0x11181);
  *(int *)((long)param_1 + 0x8c) = *piVar1;
  *(uint *)(param_1 + 0x12) = bVar3 & 1;
  iVar4 = *(int *)(lVar8 + 0x11184);
  *(int *)((long)param_1 + 0x94) = iVar4;
  iVar2 = *piVar1;
  if (iVar2 == 0) {
    if ((bVar3 & 1) == 0 && iVar4 == 0) goto LAB_fffffff0081f0274;
  }
  else {
    thunk_EXT_FUN_801100000295c3cc(*(undefined8 *)(lVar8 + 0x160));
    thunk_EXT_FUN_80110000029476b0(*(undefined8 *)(lVar8 + 0x148));
    *(undefined1 *)(lVar8 + 0x11181) = 1;
    *(undefined4 *)(lVar8 + 0x11184) = 0;
  }
  (**(code **)(**(long **)(lVar8 + 0x4b0) + 0x2c8))(*(long **)(lVar8 + 0x4b0),0);
  *piVar1 = 0;
  if (iVar2 != 0) {
    thunk_EXT_FUN_801100000295c4b0(*(undefined8 *)(lVar8 + 0x160));
  }
LAB_fffffff0081f0274:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1[2] + 0x11190));
  return 1;
}

