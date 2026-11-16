// FUN_fffffff0081e2230 @ fffffff0081e2230 size=500

void FUN_fffffff0081e2230(long param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  long *plVar7;
  undefined8 *puVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  undefined4 local_88;
  undefined8 local_84;
  undefined4 local_7c;
  ulong local_78;
  long local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined4 local_44;
  
  uStack_50 = 0;
  local_58 = 0;
  uStack_60 = 0;
  local_68 = 0;
  uVar4 = thunk_EXT_FUN_80110000029479f8
                    (*(undefined8 *)(*(long *)(param_1 + 0xc0) + 0x148),param_1 + 0x18);
  if ((uVar4 & 1) == 0) {
    lVar9 = *(long *)(param_1 + 0xc0);
    lVar5 = (**(code **)(**(long **)(*(long *)(lVar9 + 0x183b0) + 0x50) + 0x98))();
    uVar1 = *(uint *)(lVar9 + 0x4a4);
    lVar9 = *(long *)(param_1 + 0xc0);
    if ((*(byte *)(lVar9 + 0x1ac44) >> 3 & 1) != 0) {
      lVar11 = *(long *)(*(long *)(param_1 + 0x10) + 0x28);
      if (lVar11 == 0) {
        uVar2 = 0;
        uVar10 = *(undefined8 *)(param_1 + 0x78);
        uVar6 = 0;
      }
      else {
        uVar2 = thunk_EXT_FUN_8011000002c13530(lVar11);
        uVar10 = *(undefined8 *)(param_1 + 0x78);
        uVar6 = thunk_EXT_FUN_8011000002c13500(lVar11);
      }
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar9 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930d14,uVar2,uVar10,uVar6,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar9 + 0x1ac48));
      lVar9 = *(long *)(param_1 + 0xc0);
    }
    local_78 = (ulong)*(uint *)(param_1 + 0x80);
    local_7c = *(undefined4 *)(param_1 + 0x84);
    local_88 = 0x27;
    uVar4 = (**(code **)(**(long **)(lVar9 + 0x148) + 0x88))();
    local_70 = lVar5 + (ulong)uVar1 + (uVar4 & 0xffffffff);
    local_84 = *(undefined8 *)(param_1 + 0xa0);
    lVar5 = *(long *)(*(long *)(param_1 + 0xc0) + 0x4b0);
    local_44 = 1;
    uVar6 = (**(code **)(*(long *)(lVar5 + 0x848) + 0x30))(lVar5 + 0x848);
    local_48 = 0;
    plVar7 = *(long **)(*(long *)(lVar5 + 0x280) + 0x310);
    puVar8 = (undefined8 *)(*plVar7 + 0xe8);
    iVar3 = (*(code *)*puVar8)(puVar8,plVar7,FUN_fffffff00817ea94,&local_88,&local_44,&local_48,0);
    if ((iVar3 == 0) && (((byte)local_44 >> 1 & 1) != 0)) {
      FUN_fffffff0081a43cc(lVar5,uVar6,local_48);
    }
  }
  return;
}

