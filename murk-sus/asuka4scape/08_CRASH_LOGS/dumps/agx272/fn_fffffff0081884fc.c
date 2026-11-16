// FUN_fffffff0081884fc @ fffffff0081884fc size=4

undefined8 FUN_fffffff0081884fc(long *param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined8 uVar6;
  long lVar7;
  long *plVar8;
  code *pcVar9;
  ulong uVar10;
  undefined4 uVar11;
  ulong uVar12;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  
  *(undefined1 *)(param_1 + 0x47) = 0;
  lVar3 = thunk_EXT_FUN_8011000003890f30(param_1[0xc],&DAT_fffffff00ae21f50);
  if (*(int *)(*(long *)(*(long *)(lVar3 + 0x610) + 200) + 0x28) != 0) {
    (**(code **)(*param_1 + 0x88))(param_1);
    pcVar9 = *(code **)(*param_1 + 0x98);
    goto LAB_fffffff00818857c;
  }
  uStack_58 = 0;
  uStack_60 = 0;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  thunk_EXT_FUN_8011000002946f14(&uStack_80);
  thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(param_1[2] + 0x148),param_1 + 0x60,&uStack_80);
  uVar4 = thunk_EXT_FUN_8011000002969cc0(param_1,param_2);
  if ((int)uVar4 != 0) {
    pcVar9 = *(code **)(*param_1 + 0x98);
    goto LAB_fffffff0081885e8;
  }
  lVar3 = (**(code **)(*(long *)param_1[0xb] + 0x158))((long *)param_1[0xb],param_1[0x3d]);
  if (lVar3 != 0) {
    iVar2 = FUN_fffffff00819cb78(param_1[2] + 0x11df0,lVar3,(int)param_1[0xbc],param_1 + 0x3c);
    *(int *)((long)param_1 + 0x1dc) = iVar2;
    if (iVar2 != -1) {
      if ((*(byte *)(param_1 + 0x68) & 1) == 0) {
        uVar11 = (undefined4)param_1[0xbc];
      }
      else {
        uVar11 = 0xffffffff;
      }
      puVar5 = (uint *)(**(code **)(*param_1 + 0xf8))(param_1);
      uVar4 = thunk_EXT_FUN_801100000296a26c(param_1);
      thunk_EXT_FUN_8011000002947250(uVar4,0,&uStack_80,puVar5,uVar11);
      uVar1 = *puVar5;
      uVar10 = (ulong)uVar1;
      *(uint *)(param_1 + 0x6b) = uVar1;
      if (uVar1 != 0) {
        uVar12 = 0;
        do {
          if (param_1[uVar12 + 0x6c] == 0) {
            plVar8 = param_1 + 0x7b + uVar12;
            if ((((ulong)(param_1 + 0x7b) ^ (ulong)plVar8) & 0xffc0000000000000) != 0) {
              plVar8 = (long *)((ulong)plVar8 & 0xffffffffffff | 0xc8a2000000000000);
            }
            lVar3 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x1e8))
                              (*(long **)(param_1[2] + 0x4b0),plVar8);
            param_1[uVar12 + 0x6c] = lVar3;
            if (lVar3 == 0) goto LAB_fffffff008188958;
            uVar10 = (ulong)*(uint *)(param_1 + 0x6b);
          }
          uVar12 = uVar12 + 1;
        } while (uVar12 < uVar10);
      }
      if (param_1[0x92] == 0) {
        lVar3 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x1e0))
                          (*(long **)(param_1[2] + 0x4b0),param_1 + 0x93,param_1 + 0x94);
        param_1[0x92] = lVar3;
        if (lVar3 != 0) goto LAB_fffffff00818879c;
LAB_fffffff008188958:
        pcVar9 = *(code **)(*param_1 + 0x98);
        goto LAB_fffffff008188678;
      }
LAB_fffffff00818879c:
      if (param_1[0x2c] == 0) goto LAB_fffffff0081887a4;
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1[0x2c] + 0x50));
      if (((int *)param_1[0x3a] != (int *)0x0) && (*(int *)param_1[0x3a] != 0)) {
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1[0x2c] + 0x50));
        (**(code **)(*param_1 + 0x88))(param_1);
        pcVar9 = *(code **)(*param_1 + 0x98);
LAB_fffffff00818857c:
        (*pcVar9)(param_1);
        return 0xe00002bd;
      }
      FUN_fffffff0081e68ac(param_1[0x2c],param_1);
      if ((int)param_1[0x2e] == 1) {
        lVar3 = param_1[0x2c];
        iVar2 = *(int *)(lVar3 + 0x48);
        *(int *)((long)param_1 + 0x344) = iVar2;
        if (iVar2 == 0) goto LAB_fffffff008188880;
        if (iVar2 == 1) {
          if (param_1[0x8e] == 0) {
            lVar7 = FUN_fffffff0081b735c(*(undefined8 *)(param_1[2] + 0x4b0),param_1 + 0x8f);
            param_1[0x8e] = lVar7;
            lVar3 = param_1[0x2c];
            if (lVar7 == 0) {
LAB_fffffff008188950:
              thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x50));
              goto LAB_fffffff008188958;
            }
          }
          goto LAB_fffffff008188880;
        }
        if (iVar2 != 2) goto LAB_fffffff00818891c;
        uVar4 = FUN_fffffff0081e63f0(lVar3,param_1);
        if ((int)uVar4 == 0) {
          if (param_1[0x90] == 0) {
            lVar7 = FUN_fffffff0081b747c(*(undefined8 *)(param_1[2] + 0x4b0),param_1 + 0x91);
            param_1[0x90] = lVar7;
            lVar3 = param_1[0x2c];
            if (lVar7 == 0) goto LAB_fffffff008188950;
          }
          else {
            lVar3 = param_1[0x2c];
          }
          goto LAB_fffffff00818891c;
        }
        lVar3 = param_1[0x2c];
        if ((int)param_1[0x2e] == 0) {
          *(undefined4 *)(lVar3 + 0x48) = 2;
        }
        uVar6 = *(undefined8 *)(lVar3 + 0x50);
      }
      else {
        *(undefined4 *)((long)param_1 + 0x344) = 0;
        lVar3 = param_1[0x2c];
LAB_fffffff008188880:
        uVar4 = FUN_fffffff0081e6698(lVar3,param_1);
        lVar3 = param_1[0x2c];
        if ((int)uVar4 == 0) {
LAB_fffffff00818891c:
          if ((int)param_1[0x2e] == 1) {
            thunk_EXT_FUN_80110000029486ac
                      (*(undefined8 *)(*(long *)(lVar3 + 0x28) + 0x148),param_1 + 0x30,lVar3 + 0xe0)
            ;
            lVar3 = param_1[0x2c];
          }
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x50));
LAB_fffffff0081887a4:
          *(undefined1 *)(param_1 + 0x47) = 1;
          return 0;
        }
        if ((int)param_1[0x2e] == 0) {
          *(undefined4 *)(lVar3 + 0x48) = 2;
        }
        uVar6 = *(undefined8 *)(lVar3 + 0x50);
      }
      thunk_EXT_FUN_8011000003222de0(uVar6);
      pcVar9 = *(code **)(*param_1 + 0x98);
LAB_fffffff0081885e8:
      (*pcVar9)(param_1);
      return uVar4;
    }
  }
  pcVar9 = *(code **)(*param_1 + 0x98);
LAB_fffffff008188678:
  (*pcVar9)(param_1);
  return 0xe00002be;
}

