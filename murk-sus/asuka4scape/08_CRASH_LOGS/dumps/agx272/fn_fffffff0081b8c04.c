// FUN_fffffff0081b8c04 @ fffffff0081b8c04 size=352

undefined8 FUN_fffffff0081b8c04(long param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
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
  
  if (param_3 < 0x186a1) {
    param_3 = 100000;
  }
  if (399999 < param_3) {
    param_3 = 400000;
  }
  lVar4 = *(long *)(param_1 + 0x348);
  *(ulong *)(lVar4 + 0x990) = param_3;
  *(undefined8 *)(lVar4 + 0x988) = param_2;
  DataMemoryBarrier(2,3);
  uStack_58 = 0;
  local_60 = 0;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_78 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  local_80 = 0x22;
  local_34 = 4;
  uVar2 = (**(code **)(*(long *)(param_1 + 0x848) + 0x30))(param_1 + 0x848);
  local_38 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x280) + 0x310);
  puVar5 = (undefined8 *)(*plVar3 + 0xe8);
  iVar1 = (*(code *)*puVar5)(puVar5,plVar3,FUN_fffffff00817ea94,&local_80,&local_34,&local_38,0);
  if ((iVar1 == 0) && (((byte)local_34 >> 1 & 1) != 0)) {
    FUN_fffffff0081a43cc(param_1,uVar2,local_38);
  }
  lVar4 = *(long *)(param_1 + 0x280);
  if ((*(byte *)(lVar4 + 0x1ac44) >> 3 & 1) != 0) {
    uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x348) + 0x988);
    uVar6 = *(undefined8 *)(*(long *)(param_1 + 0x348) + 0x990);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar4 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930cdc,uVar2,uVar6,0,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar4 + 0x1ac48));
  }
  return 0;
}

