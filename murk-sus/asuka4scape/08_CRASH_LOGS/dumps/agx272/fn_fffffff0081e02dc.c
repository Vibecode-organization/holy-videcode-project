// FUN_fffffff0081e02dc @ fffffff0081e02dc size=480

void FUN_fffffff0081e02dc(long param_1,ulong param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  undefined8 *puVar7;
  long lVar8;
  undefined4 local_98;
  long local_94;
  undefined4 local_8c;
  long local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 local_54;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x48));
  iVar2 = *(int *)(param_1 + 0x60c8) + 0x100;
  *(int *)(param_1 + 0x60c8) = iVar2;
  lVar6 = (param_2 & 0xffffffff) * 0x60 + 0x48;
  *(int *)(param_1 + 0x88 + lVar6) = iVar2;
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x48));
  lVar8 = *(long *)(param_1 + 0x50);
  lVar3 = (**(code **)(**(long **)(*(long *)(lVar8 + 0x183b8) + 0x50) + 0x98))();
  uVar1 = *(uint *)(lVar8 + 0x4a8);
  local_8c = *(undefined4 *)(param_1 + 0x88 + lVar6);
  lVar6 = *(long *)(param_1 + 0x50);
  if ((*(byte *)(lVar6 + 0x1ac44) >> 3 & 1) != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930c98,param_2 & 0xffffffff,local_8c,0,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0x1ac48));
    lVar6 = *(long *)(param_1 + 0x50);
  }
  local_94 = lVar3 + (param_2 & 0xffffffff) * 4 + (ulong)uVar1;
  uStack_60 = 0;
  local_68 = 0;
  uStack_80 = 0;
  uStack_70 = 0;
  local_78 = 0;
  local_98 = 0x14;
  local_88 = (param_2 & 0xff) << 0x20;
  lVar3 = *(long *)(lVar6 + 0x4b0);
  local_54 = 2;
  if ((*(byte *)(lVar6 + 0x57a) & 1) == 0) {
    local_54 = 4;
  }
  uVar4 = (**(code **)(*(long *)(lVar3 + 0x848) + 0x30))(lVar3 + 0x848);
  local_58 = 0;
  plVar5 = *(long **)(*(long *)(lVar3 + 0x280) + 0x310);
  puVar7 = (undefined8 *)(*plVar5 + 0xe8);
  iVar2 = (*(code *)*puVar7)(puVar7,plVar5,FUN_fffffff00817ea94,&local_98,&local_54,&local_58,0);
  if ((iVar2 == 0) && (((byte)local_54 >> 1 & 1) != 0)) {
    FUN_fffffff0081a43cc(lVar3,uVar4,local_58);
  }
  return;
}

