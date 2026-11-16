// FUN_fffffff008d14c7c @ fffffff008d14c7c size=8
// CALLERS:
//   fffffff00afb8d48 no-fn
//   fffffff008d14c84 FUN_fffffff008d14c84@fffffff008d14c84
// CALLEES:

/* WARNING: Removing unreachable block (ram,0xfffffff008d14ec8) */

undefined8 FUN_fffffff008d14c7c(long param_1,long param_2,long param_3)

{
  uint *puVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  uint *puVar8;
  uint *puVar9;
  ulong unaff_x30;
  undefined1 auVar10 [16];
  
  if (*(int *)(param_1 + 0x164) == 0) {
    if ((param_2 != 0) && (param_3 != 0)) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        uVar5 = FUN_fffffff008d14888();
        return uVar5;
      }
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008d14cb0);
      (*pcVar3)();
    }
    iVar4 = FUN_fffffff008cd5954(1,4);
    if (iVar4 != 0) {
      FUN_fffffff008de677c();
    }
    return 0xe00002c2;
  }
  auVar10 = FUN_fffffff008de6760();
  lVar6 = auVar10._0_8_;
  if (*(int *)(lVar6 + 0x164) == 0) {
    uVar5 = 0xe00002c1;
    if ((*(byte *)(lVar6 + 0x160) & 1) == 0) {
      plVar7 = (long *)thunk_EXT_FUN_8011000003976e84
                                 (*auVar10._8_8_,*(undefined4 *)(lVar6 + 0x150),3,
                                  *(undefined8 *)(lVar6 + 0x130));
      if (plVar7 == (long *)0x0) {
        uVar5 = 0xe00002bd;
      }
      else {
        uVar5 = (**(code **)(*plVar7 + 0xd8))(plVar7,0);
        if ((int)uVar5 == 0) {
          uVar5 = FUN_fffffff008d5cfdc(*(undefined8 *)(lVar6 + 0x100),lVar6,plVar7);
          (**(code **)(*plVar7 + 0xe0))(plVar7,0);
        }
        else {
          iVar4 = FUN_fffffff008cd5954(1,4);
          if (iVar4 != 0) {
            FUN_fffffff008de67d0();
          }
        }
        (**(code **)(*plVar7 + 0x28))(plVar7);
      }
    }
    else {
      iVar4 = FUN_fffffff008cd5954(1,4);
      if (iVar4 != 0) {
        FUN_fffffff008de6808();
      }
    }
    return uVar5;
  }
  auVar10 = FUN_fffffff008de67b4();
  puVar8 = auVar10._8_8_;
  lVar6 = auVar10._0_8_;
  if (*(int *)(lVar6 + 0x164) == 0) {
    auVar10 = FUN_fffffff008de6840();
    if (*(int *)(auVar10._0_8_ + 0x164) != 0) {
      FUN_fffffff008de6870();
      return 0xe00002c7;
    }
    if (((auVar10._8_8_ != (uint *)0x0) && (param_3 == 0xfa8)) && (*auVar10._8_8_ < 0x3e9)) {
      uVar5 = FUN_fffffff008d56a18(*(undefined8 *)(auVar10._0_8_ + 0x100));
      return uVar5;
    }
    return 0xe00002c2;
  }
  if (puVar8 == (uint *)0x0) {
    uVar5 = 0xe00002c2;
  }
  else {
    puVar1 = puVar8 + 1;
    thunk_EXT_FUN_8011000003a61b10
              (puVar1,*(undefined8 *)(lVar6 + 0x158),*(undefined4 *)(lVar6 + 0x150));
    uVar5 = 0;
    *(uint **)(puVar8 + 0x182) = puVar1;
    uVar2 = *(uint *)(lVar6 + 0x148);
    puVar9 = puVar1 + uVar2;
    if ((((ulong)puVar1 ^ (ulong)puVar9) & 0xffc0000000000000) != 0) {
      puVar9 = (uint *)((ulong)puVar9 & 0xffffffffffff | 0xc8a2000000000000);
    }
    *(uint **)(puVar8 + 0x184) = puVar9;
    *(uint **)(puVar8 + 0x186) = puVar1 + (uVar2 << 1);
    *puVar8 = uVar2;
  }
  return uVar5;
}

