// FUN_fffffff00818d240 @ fffffff00818d240 size=544

void FUN_fffffff00818d240
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,long param_5)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  bool bVar4;
  undefined8 uVar5;
  long *plVar6;
  byte bVar7;
  uint uVar8;
  undefined8 uVar9;
  
  if ((*(byte *)(param_2 + 8) & 1) != 0) {
    if (*(int *)(param_2 + 0x98) == 0) {
      return;
    }
    bVar4 = (*(byte *)(param_1 + 0x527) & 1) == 0;
    lVar1 = 2;
    if (bVar4) {
      lVar1 = 0;
    }
    lVar2 = 3;
    if (bVar4) {
      lVar2 = 1;
    }
    if (param_5 == 0) {
      uVar8 = 0;
      bVar7 = 1;
      while ((bVar7 & 1) != 0) {
        uVar3 = 0;
        if (*(int *)(param_2 + 0x98) != 0) {
          if ((int)param_3 == 3) {
            uVar3 = *(uint *)(param_2 + 300);
          }
          else {
            uVar3 = *(uint *)(param_2 + 0x128);
          }
        }
        if (uVar3 <= uVar8) {
          return;
        }
        uVar9 = *(undefined8 *)(param_1 + 0x488);
        uVar5 = FUN_fffffff0081df9c4(param_2,param_3,uVar8);
        plVar6 = (long *)thunk_EXT_FUN_8011000002961f30(uVar9,uVar5);
        if (plVar6 != (long *)0x0) {
          thunk_EXT_FUN_80110000029486ac
                    (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_4,
                     plVar6 + lVar1 * 8 + 3);
          (**(code **)(*plVar6 + 0x28))(plVar6);
        }
        uVar8 = uVar8 + 1;
        bVar7 = *(byte *)(param_2 + 8);
      }
    }
    else {
      uVar8 = 0;
      bVar7 = 1;
      while ((bVar7 & 1) != 0) {
        uVar3 = 0;
        if (*(int *)(param_2 + 0x98) != 0) {
          if ((int)param_3 == 3) {
            uVar3 = *(uint *)(param_2 + 300);
          }
          else {
            uVar3 = *(uint *)(param_2 + 0x128);
          }
        }
        if (uVar3 <= uVar8) {
          return;
        }
        uVar9 = *(undefined8 *)(param_1 + 0x488);
        uVar5 = FUN_fffffff0081df9c4(param_2,param_3,uVar8);
        plVar6 = (long *)thunk_EXT_FUN_8011000002961f30(uVar9,uVar5);
        if (plVar6 != (long *)0x0) {
          thunk_EXT_FUN_80110000029486ac
                    (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_4,
                     plVar6 + lVar1 * 8 + 3);
          thunk_EXT_FUN_80110000029486ac
                    (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_5,
                     plVar6 + lVar2 * 8 + 3);
          (**(code **)(*plVar6 + 0x28))(plVar6);
        }
        uVar8 = uVar8 + 1;
        bVar7 = *(byte *)(param_2 + 8);
      }
    }
  }
  thunk_EXT_FUN_8011000003a49114
            ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n");
  return;
}

