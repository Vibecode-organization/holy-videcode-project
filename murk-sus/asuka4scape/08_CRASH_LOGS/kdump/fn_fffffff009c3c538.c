// FUN_fffffff009c3c538 @ fffffff009c3c538 size=708
// CALLERS:
//   fffffff00afec0cd ?
//   fffffff009c38ddc FUN_fffffff009c38c48@fffffff009c38c48
// CALLS:
//   fffffff009c2a738 FUN_fffffff009c2a738
//   fffffff009c49ad4 thunk_FUN_fffffff00a8d2200
//   fffffff009c3f1d0 FUN_fffffff009c3f1d0
//   fffffff009c49c84 thunk_FUN_fffffff00aa65b10
//   fffffff009c23788 FUN_fffffff009c23788
//   fffffff009c28380 FUN_fffffff009c28380
//   fffffff009c237b8 FUN_fffffff009c237b8
//   fffffff009c497d4 thunk_FUN_fffffff00a8d8814
//   fffffff009c2a744 FUN_fffffff009c2a744
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30

undefined8
FUN_fffffff009c3c538
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint *param_8,
          long param_9,ulong param_10,uint *param_11)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  long *plVar5;
  uint *puVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  
  uVar11 = 0xe00002c2;
  plVar5 = FUN_fffffff009c3f1d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,*param_8);
  if (plVar5 == (long *)0x0) {
    return 0xe00002c2;
  }
  puVar6 = param_8 + 3;
  if ((char)*puVar6 == '\0') {
    plVar7 = (long *)0x0;
  }
  else if ((*(char *)((long)puVar6 + ((param_10 & 0xffffffff) - 0xd)) != '\0') ||
          (plVar7 = thunk_FUN_fffffff00a8d2200(puVar6), plVar7 == (long *)0x0))
  goto LAB_fffffff009c3c7b8;
  plVar8 = FUN_fffffff009c28380((long)plVar5,plVar7,(undefined4 *)(param_9 + 4));
  if (plVar8 == (long *)0x0) {
    uVar11 = 0;
    *param_11 = 0;
  }
  else {
    if ((param_8[2] != 0) &&
       (plVar9 = thunk_FUN_fffffff00a894f30(plVar8,*(long *)PTR_PTR_fffffff00806c9c8),
       plVar9 != (long *)0x0)) {
      (**(code **)(*plVar9 + 0x118))(plVar9,PTR_s_CreationProperties_fffffff008066f80);
    }
    plVar9 = thunk_FUN_fffffff00a8d8814((ulong)(*param_11 - 0xc),0,0);
    if (plVar9 == (long *)0x0) {
      uVar11 = 0xe00002bd;
    }
    else {
      (**(code **)(*plVar9 + 0x80))();
      iVar2 = (**(code **)(*plVar8 + 0x30))(plVar8,plVar9);
      if (iVar2 == 0) {
        uVar11 = 0xe00002c7;
      }
      else {
        uVar3 = (**(code **)(*plVar9 + 0xb8))(plVar9);
        uVar1 = (ulong)uVar3 + 0xc;
        if (*param_11 < uVar1) {
          FUN_fffffff009c2a738((long)plVar5);
          uVar4 = FUN_fffffff009c23788((long)plVar5);
          uVar11 = 0xe00002db;
        }
        else {
          puVar10 = (undefined8 *)(**(code **)(*plVar9 + 0x78))(plVar9);
          thunk_FUN_fffffff00aa65b10((undefined8 *)(param_9 + 0xc),puVar10,(ulong)uVar3);
          *param_11 = (uint)uVar1;
          FUN_fffffff009c2a738((long)plVar5);
          uVar4 = FUN_fffffff009c23788((long)plVar5);
          uVar11 = 0;
        }
        if (uVar4 < uVar3) {
          FUN_fffffff009c237b8((long)plVar5,uVar3);
        }
        FUN_fffffff009c2a744((long)plVar5);
      }
      (**(code **)(*plVar9 + 0x28))(plVar9);
    }
    (**(code **)(*plVar8 + 0x28))(plVar8);
  }
  if (plVar7 != (long *)0x0) {
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
LAB_fffffff009c3c7b8:
  (**(code **)(*plVar5 + 0x28))(plVar5);
  return uVar11;
}

