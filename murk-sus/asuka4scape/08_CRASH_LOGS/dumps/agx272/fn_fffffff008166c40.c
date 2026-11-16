// FUN_fffffff008166c40 @ fffffff008166c40 size=876

undefined8 FUN_fffffff008166c40(long *param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  uint *puVar5;
  long *plVar6;
  ulong uVar7;
  code *pcVar8;
  undefined4 uVar9;
  ulong uVar10;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  
  lVar3 = thunk_EXT_FUN_8011000003890f30(param_1[0xc],&DAT_fffffff00ae21f50);
  if (*(int *)(*(long *)(*(long *)(lVar3 + 0x610) + 200) + 0x28) != 0) {
    (**(code **)(*param_1 + 0x88))(param_1);
    (**(code **)(*param_1 + 0x98))(param_1);
    return 0xe00002bd;
  }
  uStack_58 = 0;
  local_60 = 0;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_78 = 0;
  local_80 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  thunk_EXT_FUN_8011000002946f14(&local_80);
  thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(param_1[2] + 0x148),param_1 + 0x49,&local_80);
  uVar4 = thunk_EXT_FUN_8011000002969cc0(param_1,param_2);
  if ((int)uVar4 != 0) {
    (**(code **)(*param_1 + 0x98))(param_1);
    return uVar4;
  }
  if ((*(byte *)((long)param_1 + 0x241) & 1) == 0) {
    (**(code **)(*param_1 + 0x98))(param_1);
    return 0;
  }
  lVar3 = (**(code **)(*(long *)param_1[0xb] + 0x158))((long *)param_1[0xb],param_1[0x3d]);
  if (lVar3 != 0) {
    iVar2 = FUN_fffffff00819cb78
                      (param_1[2] + 0x11df0,lVar3,*(undefined4 *)((long)param_1 + 0x8f4),
                       param_1 + 0x3c);
    *(int *)((long)param_1 + 0x1dc) = iVar2;
    if (iVar2 != -1) {
      if ((*(byte *)(param_1 + 0x69) & 1) == 0) {
        uVar9 = *(undefined4 *)((long)param_1 + 0x8f4);
      }
      else {
        uVar9 = 0xffffffff;
      }
      puVar5 = (uint *)(**(code **)(*param_1 + 0x110))(param_1);
      uVar4 = thunk_EXT_FUN_801100000296a26c(param_1);
      thunk_EXT_FUN_8011000002947250(uVar4,0,&local_80,puVar5,uVar9);
      uVar1 = *puVar5;
      uVar7 = (ulong)uVar1;
      *(uint *)(param_1 + 0x6a) = uVar1;
      if (uVar1 != 0) {
        uVar10 = 0;
        do {
          if (param_1[uVar10 + 0x6b] == 0) {
            plVar6 = param_1 + 0x7a + uVar10;
            if ((((ulong)(param_1 + 0x7a) ^ (ulong)plVar6) & 0xffc0000000000000) != 0) {
              plVar6 = (long *)((ulong)plVar6 & 0xffffffffffff | 0xc8a2000000000000);
            }
            lVar3 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x1e8))
                              (*(long **)(param_1[2] + 0x4b0),plVar6);
            param_1[uVar10 + 0x6b] = lVar3;
            if (lVar3 == 0) goto LAB_fffffff008166f84;
            uVar7 = (ulong)*(uint *)(param_1 + 0x6a);
          }
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar7);
      }
      if ((*(byte *)(param_1 + 0xff) & 1) == 0) {
        if (param_1[0x90] != 0) goto LAB_fffffff008166f60;
        lVar3 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x1d0))
                          (*(long **)(param_1[2] + 0x4b0),param_1 + 0x91,param_1 + 0x92);
        param_1[0x90] = lVar3;
      }
      else {
        if (param_1[0x8d] != 0) goto LAB_fffffff008166f60;
        lVar3 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x1d8))
                          (*(long **)(param_1[2] + 0x4b0),param_1 + 0x8e,param_1 + 0x8f);
        param_1[0x8d] = lVar3;
      }
      if (lVar3 != 0) {
LAB_fffffff008166f60:
        if (param_1[0x2c] != 0) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1[0x2c] + 0x50));
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1[0x2c] + 0x50));
        }
        return 0;
      }
LAB_fffffff008166f84:
      pcVar8 = *(code **)(*param_1 + 0x98);
      goto LAB_fffffff008166de4;
    }
  }
  pcVar8 = *(code **)(*param_1 + 0x98);
LAB_fffffff008166de4:
  (*pcVar8)(param_1);
  return 0xe00002be;
}

