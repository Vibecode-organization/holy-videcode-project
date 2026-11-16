// FUN_fffffff00995cf04 @ fffffff00995cf04 size=572

undefined8 FUN_fffffff00995cf04(long param_1,int param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  ulong uVar11;
  long *plVar12;
  
  uVar3 = *(uint *)(param_1 + 0x4c);
  uVar4 = *(uint *)(param_1 + 0x48);
  uVar5 = *(uint *)(param_1 + 0x54);
  uVar7 = 0;
  if (uVar5 != 0) {
    uVar7 = uVar3 / uVar5;
  }
  lVar6 = (ulong)(uVar3 - uVar7 * uVar5) * 8;
  puVar1 = (undefined8 *)(*(long *)(param_1 + 0x58) + (long)(int)lVar6);
  if (lVar6 != (int)lVar6) {
    puVar1 = (undefined8 *)
             (*(long *)(param_1 + 0x58) + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
  }
  plVar12 = (long *)*puVar1;
  if ((plVar12[0xc] != 0) &&
     (lVar6 = plVar12[0xf], iVar8 = FUN_fffffff009962f24(*(undefined8 *)(param_1 + 0x10)),
     (int)lVar6 != iVar8)) {
    if (plVar12[0xd] != 0) {
      uVar9 = FUN_fffffff009962ebc(*(undefined8 *)(param_1 + 0x10),plVar12[0xc]);
      *(undefined4 *)(plVar12[0xd] + 200) = uVar9;
    }
    if ((*(byte *)((long)plVar12 + 0x4c) & 1) == 0) {
      (**(code **)(*plVar12 + 0x88))(plVar12);
    }
  }
  (**(code **)(*plVar12 + 0xa0))(plVar12);
  if (DAT_fffffff00af227e8 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 200);
    uVar10 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0xc0));
    thunk_EXT_FUN_80110000036da494(0x8518016d,uVar2,uVar10,0,0,0);
  }
  if (((*(byte *)((long)plVar12 + 0x4c) & 1) == 0) ||
     ((*(byte *)(*(long *)(param_1 + 0xc0) + 0x239) & 1) != 0)) {
    (**(code **)(*plVar12 + 0xb8))(plVar12,param_1);
  }
  else {
    uVar11 = FUN_fffffff00994b4ec(*(undefined8 *)(*(long *)(param_1 + 0xc0) + 0x148),plVar12 + 0x10)
    ;
    if ((uVar11 & 1) == 0) {
      FUN_fffffff00994d228(*(undefined8 *)(*(long *)(param_1 + 0xc0) + 0x148),plVar12 + 0x10);
    }
  }
  (**(code **)(*plVar12 + 0xa8))(plVar12);
  if (DAT_fffffff00af227e8 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 200);
    uVar10 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0xc0));
    thunk_EXT_FUN_80110000036da494(0x8518016e,uVar2,uVar10,(long)param_2,0,0);
  }
  *(long *)(param_1 + 0x40) = *(long *)(param_1 + 0x40) + 1;
  *(uint *)(param_1 + 0x4c) = uVar3 + 1;
  if (uVar4 != uVar3) {
    DataMemoryBarrier(2,3);
    if (*(uint *)(param_1 + 0x48) != uVar3) goto LAB_fffffff00995d100;
  }
  FUN_fffffff009961554(*(undefined8 *)(param_1 + 0x10),param_1);
LAB_fffffff00995d100:
  (**(code **)(**(long **)(param_1 + 0x10) + 0x98))();
  return 0;
}

