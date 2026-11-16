// FUN_fffffff008d14ce0 @ fffffff008d14ce0 size=280
// CALLERS:
//   fffffff00afb8d49 no-fn
//   fffffff008d14cf0 FUN_fffffff008d14ce0@fffffff008d14ce0
// CALLEES:
//   fffffff008de6808 FUN_fffffff008de6808
//   fffffff008de67d0 FUN_fffffff008de67d0
//   fffffff008d5cfdc FUN_fffffff008d5cfdc
//   fffffff008e00070 thunk_EXT_FUN_8011000003976e84
//   fffffff008de67b4 FUN_fffffff008de67b4
//   fffffff008cd5954 FUN_fffffff008cd5954

/* WARNING: Removing unreachable block (ram,0xfffffff008d14ec8) */

undefined8 FUN_fffffff008d14ce0(long param_1,undefined8 *param_2,long param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  uint *puVar6;
  uint *puVar7;
  undefined8 uVar8;
  undefined1 auVar9 [16];
  
  if (*(int *)(param_1 + 0x164) == 0) {
    uVar8 = 0xe00002c1;
    if ((*(byte *)(param_1 + 0x160) & 1) == 0) {
      plVar4 = (long *)thunk_EXT_FUN_8011000003976e84
                                 (*param_2,*(undefined4 *)(param_1 + 0x150),3,
                                  *(undefined8 *)(param_1 + 0x130));
      if (plVar4 == (long *)0x0) {
        uVar8 = 0xe00002bd;
      }
      else {
        uVar8 = (**(code **)(*plVar4 + 0xd8))(plVar4,0);
        if ((int)uVar8 == 0) {
          uVar8 = FUN_fffffff008d5cfdc(*(undefined8 *)(param_1 + 0x100),param_1,plVar4);
          (**(code **)(*plVar4 + 0xe0))(plVar4,0);
        }
        else {
          iVar3 = FUN_fffffff008cd5954(1,4);
          if (iVar3 != 0) {
            FUN_fffffff008de67d0();
          }
        }
        (**(code **)(*plVar4 + 0x28))(plVar4);
      }
    }
    else {
      iVar3 = FUN_fffffff008cd5954(1,4);
      if (iVar3 != 0) {
        FUN_fffffff008de6808();
      }
    }
    return uVar8;
  }
  auVar9 = FUN_fffffff008de67b4();
  puVar6 = auVar9._8_8_;
  lVar5 = auVar9._0_8_;
  if (*(int *)(lVar5 + 0x164) != 0) {
    if (puVar6 == (uint *)0x0) {
      uVar8 = 0xe00002c2;
    }
    else {
      puVar1 = puVar6 + 1;
      thunk_EXT_FUN_8011000003a61b10
                (puVar1,*(undefined8 *)(lVar5 + 0x158),*(undefined4 *)(lVar5 + 0x150));
      uVar8 = 0;
      *(uint **)(puVar6 + 0x182) = puVar1;
      uVar2 = *(uint *)(lVar5 + 0x148);
      puVar7 = puVar1 + uVar2;
      if ((((ulong)puVar1 ^ (ulong)puVar7) & 0xffc0000000000000) != 0) {
        puVar7 = (uint *)((ulong)puVar7 & 0xffffffffffff | 0xc8a2000000000000);
      }
      *(uint **)(puVar6 + 0x184) = puVar7;
      *(uint **)(puVar6 + 0x186) = puVar1 + (uVar2 << 1);
      *puVar6 = uVar2;
    }
    return uVar8;
  }
  auVar9 = FUN_fffffff008de6840();
  if (*(int *)(auVar9._0_8_ + 0x164) != 0) {
    FUN_fffffff008de6870();
    return 0xe00002c7;
  }
  if (((auVar9._8_8_ != (uint *)0x0) && (param_3 == 0xfa8)) && (*auVar9._8_8_ < 0x3e9)) {
    uVar8 = FUN_fffffff008d56a18(*(undefined8 *)(auVar9._0_8_ + 0x100));
    return uVar8;
  }
  return 0xe00002c2;
}

