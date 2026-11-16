// FUN_fffffff0081b7e2c @ fffffff0081b7e2c size=4

undefined8 FUN_fffffff0081b7e2c(long param_1,ulong *param_2,ulong *param_3)

{
  undefined8 *puVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  long lVar6;
  undefined4 *puVar7;
  ulong uStack_68;
  ulong uStack_60;
  ulong uStack_58;
  ulong uStack_50;
  ulong uStack_48;
  ulong uStack_40;
  
  uStack_68 = param_2[2];
  if ((((uStack_68 < *param_2) || (uStack_60 = uStack_68 + 0x9a8, 0xfffffffffffff657 < uStack_68))
      || (param_2[1] < uStack_60)) || (param_2[2] = uStack_60, uStack_60 == uStack_68)) {
    *(undefined4 *)(param_1 + 0xc) = 0x100;
    return 0;
  }
  uStack_58 = uStack_68;
  uVar3 = (*(code *)**(undefined8 **)(param_1 + 0x10))((undefined8 *)(param_1 + 0x10),&uStack_68);
  if ((uVar3 & 1) == 0) {
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x1c);
    return 0;
  }
  puVar7 = (undefined4 *)param_2[2];
  if (((puVar7 < (undefined4 *)*param_2) ||
      (puVar1 = (undefined8 *)(puVar7 + 1), (undefined4 *)0xfffffffffffffffb < puVar7)) ||
     ((undefined8 *)param_2[1] < puVar1)) {
    *(undefined4 *)(param_1 + 0xc) = 0x100;
    return 0;
  }
  *(undefined4 *)(param_1 + 0x1d8) = *puVar7;
  param_2[2] = (ulong)puVar1;
  if (((puVar1 < (undefined8 *)*param_2) || ((undefined8 *)0xfffffffffffffff7 < puVar1)) ||
     ((undefined4 *)param_2[1] < puVar7 + 3)) {
    *(undefined4 *)(param_1 + 0xc) = 0x100;
    return 0;
  }
  *(undefined8 *)(param_1 + 0x1e0) = *puVar1;
  param_2[2] = (ulong)(puVar7 + 3);
  uStack_40 = *param_3;
  uStack_48 = param_3[1];
  if (uStack_48 < uStack_40) {
    uStack_48 = 0;
    uStack_40 = 0;
  }
  uStack_50 = uStack_40;
  iVar2 = (*(code *)**(undefined8 **)(param_1 + 0x1e8))
                    ((undefined8 *)(param_1 + 0x1e8),param_2,&uStack_50);
  if (iVar2 == 0) {
    lVar6 = 500;
  }
  else {
    if ((*(byte *)(param_1 + 0x1f0) & 1) == 0) {
LAB_fffffff0081b8124:
      uVar4 = thunk_EXT_FUN_8011000003a49114
                        ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n")
      ;
      return uVar4;
    }
    if (*(int *)(param_1 + 0x27c) != 0) {
LAB_fffffff0081b8154:
      uVar5 = 10;
      goto LAB_fffffff0081b8194;
    }
    if (*(int *)(param_1 + 0x298) != 3) {
LAB_fffffff0081b815c:
      uVar5 = 0x106;
      goto LAB_fffffff0081b8194;
    }
    uVar3 = (*(code *)**(undefined8 **)(param_1 + 0x360))(param_1 + 0x360,param_1 + 0x2b8);
    if ((uVar3 & 1) == 0) {
      lVar6 = 0x36c;
    }
    else {
      uStack_40 = *param_3;
      uStack_48 = param_3[1];
      if (uStack_48 < uStack_40) {
        uStack_48 = 0;
        uStack_40 = 0;
      }
      uStack_50 = uStack_40;
      iVar2 = (*(code *)**(undefined8 **)(param_1 + 0x408))
                        ((undefined8 *)(param_1 + 0x408),param_2,&uStack_50);
      if (iVar2 == 0) {
        lVar6 = 0x414;
      }
      else {
        if ((*(byte *)(param_1 + 0x410) & 1) == 0) goto LAB_fffffff0081b8124;
        if (*(int *)(param_1 + 0x49c) != 0) goto LAB_fffffff0081b8154;
        if (*(int *)(param_1 + 0x4b8) != 3) goto LAB_fffffff0081b815c;
        uVar3 = (*(code *)**(undefined8 **)(param_1 + 0x580))(param_1 + 0x580,param_1 + 0x4d8);
        if ((uVar3 & 1) == 0) {
          lVar6 = 0x58c;
        }
        else {
          uStack_40 = *param_3;
          uStack_48 = param_3[1];
          if (uStack_48 < uStack_40) {
            uStack_48 = 0;
            uStack_40 = 0;
          }
          uStack_50 = uStack_40;
          iVar2 = (*(code *)**(undefined8 **)(param_1 + 0x628))
                            ((undefined8 *)(param_1 + 0x628),param_2,&uStack_50);
          if (iVar2 == 0) {
            lVar6 = 0x634;
          }
          else {
            if ((*(byte *)(param_1 + 0x630) & 1) == 0) goto LAB_fffffff0081b8124;
            if (*(int *)(param_1 + 0x6bc) != 0) goto LAB_fffffff0081b8154;
            if (*(int *)(param_1 + 0x6d8) != 3) goto LAB_fffffff0081b815c;
            uVar3 = (*(code *)**(undefined8 **)(param_1 + 0x7a0))(param_1 + 0x7a0,param_1 + 0x6f8);
            if ((uVar3 & 1) != 0) {
              *(undefined1 *)(param_1 + 8) = 1;
              return 1;
            }
            lVar6 = 0x7ac;
          }
        }
      }
    }
  }
  uVar5 = *(undefined4 *)(param_1 + lVar6);
LAB_fffffff0081b8194:
  *(undefined4 *)(param_1 + 0xc) = uVar5;
  return 0;
}

