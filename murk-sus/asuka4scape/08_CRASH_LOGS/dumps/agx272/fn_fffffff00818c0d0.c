// FUN_fffffff00818c0d0 @ fffffff00818c0d0 size=748

void FUN_fffffff00818c0d0
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,long param_5,
               undefined8 param_6)

{
  long lVar1;
  uint uVar2;
  bool bVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  
  uStack_88 = 0;
  local_90 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  uStack_98 = 0;
  uStack_a0 = 0;
  uStack_c8 = 0;
  local_d0 = 0;
  uStack_b8 = 0;
  uStack_c0 = 0;
  uStack_e8 = 0;
  local_f0 = 0;
  uStack_d8 = 0;
  uStack_e0 = 0;
  uStack_108 = 0;
  local_110 = 0;
  uStack_f8 = 0;
  uStack_100 = 0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_118 = 0;
  uStack_120 = 0;
  if ((*(byte *)(param_2 + 8) & 1) != 0) {
    if (*(int *)(param_2 + 0x98) == 0) {
      return;
    }
    bVar3 = (*(byte *)(param_1 + 0x527) & 1) == 0;
    lVar6 = 2;
    if (bVar3) {
      lVar6 = 0;
    }
    lVar1 = 3;
    if (bVar3) {
      lVar1 = 1;
    }
    thunk_EXT_FUN_8011000002946f14(&local_b0);
    if (param_5 == 0) {
      uVar7 = 0;
      while ((*(byte *)(param_2 + 8) & 1) != 0) {
        uVar2 = 0;
        if (*(int *)(param_2 + 0x98) != 0) {
          if ((int)param_3 == 0) {
            uVar2 = *(uint *)(param_2 + 0x120);
          }
          else {
            uVar2 = *(uint *)(param_2 + 0x124);
          }
        }
        if (uVar2 <= uVar7) {
LAB_fffffff00818c2c4:
          FUN_fffffff00818dc84(param_1,&local_b0,&local_130);
          lVar6 = *(long *)(param_1 + 0x530);
          if ((*(byte *)(lVar6 + 0x1ac45) & 1) != 0) {
            FUN_fffffff0081a0304(*(undefined8 *)(lVar6 + 0x148),0x805,&local_130,param_6);
            lVar6 = *(long *)(param_1 + 0x530);
          }
          thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar6 + 0x148),&local_130,param_4);
          if (param_5 != 0) {
            FUN_fffffff00818dc84(param_1,&local_f0,&local_130);
            lVar6 = *(long *)(param_1 + 0x530);
            if ((*(byte *)(lVar6 + 0x1ac45) & 1) != 0) {
              FUN_fffffff0081a0304(*(undefined8 *)(lVar6 + 0x148),0x81a,&local_130,param_6);
              lVar6 = *(long *)(param_1 + 0x530);
            }
            thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar6 + 0x148),&local_130,param_5);
          }
          return;
        }
        uVar8 = *(undefined8 *)(param_1 + 0x488);
        uVar4 = FUN_fffffff0081df9c4(param_2,param_3,uVar7);
        plVar5 = (long *)thunk_EXT_FUN_8011000002961f30(uVar8,uVar4);
        if (plVar5 != (long *)0x0) {
          thunk_EXT_FUN_80110000029486ac
                    (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),plVar5 + lVar6 * 8 + 3,
                     &local_b0);
          (**(code **)(*plVar5 + 0x28))(plVar5);
        }
        uVar7 = uVar7 + 1;
      }
    }
    else {
      thunk_EXT_FUN_8011000002946f14(&local_f0);
      uVar7 = 0;
      while ((*(byte *)(param_2 + 8) & 1) != 0) {
        uVar2 = 0;
        if (*(int *)(param_2 + 0x98) != 0) {
          if ((int)param_3 == 0) {
            uVar2 = *(uint *)(param_2 + 0x120);
          }
          else {
            uVar2 = *(uint *)(param_2 + 0x124);
          }
        }
        if (uVar2 <= uVar7) goto LAB_fffffff00818c2c4;
        uVar8 = *(undefined8 *)(param_1 + 0x488);
        uVar4 = FUN_fffffff0081df9c4(param_2,param_3,uVar7);
        plVar5 = (long *)thunk_EXT_FUN_8011000002961f30(uVar8,uVar4);
        if (plVar5 != (long *)0x0) {
          thunk_EXT_FUN_80110000029486ac
                    (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),plVar5 + lVar6 * 8 + 3,
                     &local_b0);
          thunk_EXT_FUN_80110000029486ac
                    (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),plVar5 + lVar1 * 8 + 3,
                     &local_f0);
          (**(code **)(*plVar5 + 0x28))(plVar5);
        }
        uVar7 = uVar7 + 1;
      }
    }
  }
  thunk_EXT_FUN_8011000003a49114
            ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n");
  return;
}

