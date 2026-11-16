// FUN_fffffff009942500 @ fffffff009942500 size=4

void FUN_fffffff009942500(long *param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long *plVar9;
  long lVar10;
  long *plStack_70;
  undefined4 uStack_68;
  uint uStack_64;
  undefined8 uStack_60;
  undefined4 uStack_54;
  
  lVar10 = param_1[0x10];
  if ((long *)param_1[0x16] == (long *)0x0) {
    lVar5 = 0;
  }
  else {
    lVar5 = (**(code **)(*(long *)param_1[0x16] + 0xb0))();
  }
  if ((long *)param_1[0x17] == (long *)0x0) {
    lVar6 = 0;
  }
  else {
    lVar6 = (**(code **)(*(long *)param_1[0x17] + 0xb0))();
  }
  uVar7 = (**(code **)(*param_1 + 0x108))(param_1);
  if (DAT_fffffff00af227e8 != 0) {
    lVar3 = param_1[0x12];
    uVar8 = (**(code **)(*param_1 + 0xe0))(param_1);
    plStack_70 = (long *)0x0;
    thunk_EXT_FUN_80110000032db760(uVar8,&plStack_70);
    plVar9 = plStack_70;
    uVar8 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
    thunk_EXT_FUN_80110000036da494(0x851801a1,lVar5 + lVar10 + lVar6,(int)lVar3,plVar9,uVar8,0);
  }
  uVar1 = *(uint *)(param_1 + 6);
  uVar2 = *(uint *)(param_1[2] + 0x1fc);
  uStack_54 = 0;
  uStack_64 = (int)param_1[0x14] + 0x3fU >> 6;
  uStack_68 = 0;
  uStack_60 = 0xffffffff00000000;
  plStack_70 = param_1;
  do {
    plVar9 = (long *)FUN_fffffff009942410(&plStack_70,&uStack_54);
    if (plVar9 == (long *)0x0) goto LAB_fffffff0099426a4;
    iVar4 = (**(code **)(*plVar9 + 0xe0))(plVar9,0);
  } while (iVar4 == 0);
  FUN_fffffff0099832c0(param_1,&uStack_54);
LAB_fffffff0099426a4:
  plVar9 = (long *)param_1[0x16];
  if (plVar9 != (long *)0x0) {
    (**(code **)(*plVar9 + 0xe0))(plVar9,0);
  }
  plVar9 = (long *)param_1[0x17];
  if (plVar9 != (long *)0x0) {
    (**(code **)(*plVar9 + 0xe0))(plVar9,0);
  }
  FUN_fffffff0099758d8(param_1[2],uVar7,uVar1 & (uVar2 & 0x3fff) >> 0xd);
  if ((*(byte *)(param_1 + 6) >> 1 & 1) == 0) {
    FUN_fffffff00997db18(*(long *)(param_1[2] + 0x160) + 0x1b8,param_1);
  }
  if (DAT_fffffff00af227e8 != 0) {
    lVar3 = param_1[0x12];
    uVar7 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
    thunk_EXT_FUN_80110000036da494(0x851801a2,lVar5 + lVar10 + lVar6,(int)lVar3,1,uVar7,0);
  }
  return;
}

