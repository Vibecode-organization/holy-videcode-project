// FUN_fffffff0081cae2c @ fffffff0081cae2c size=536

undefined8 FUN_fffffff0081cae2c(long *param_1,long param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  bool bVar7;
  
  if (*(char *)(param_2 + 8) == '\x01') {
    if (((long *)param_1[0x42] == (long *)0x0) ||
       (uVar4 = (**(code **)(*(long *)param_1[0x42] + 0xd8))(), (uVar4 & 1) != 0)) {
      bVar7 = false;
    }
    else {
      bVar7 = true;
      if ((*(byte *)(param_1[0x42] + 9) & 1) == 0) {
        return 1;
      }
    }
    uVar4 = *(ulong *)(param_1[0x50] + 0x580);
    (**(code **)(*(long *)param_1[0x28c] + 0x568))
              ((long *)param_1[0x28c],uVar4 & 0xfffffffffff | 0x86000000000000,1);
    iVar3 = *(int *)(param_1[0x50] + 0x23c) * 1000;
    lVar1 = uVar4 + 1;
    if (bVar7) {
      iVar3 = iVar3 + 1;
      do {
        lVar5 = (**(code **)(*param_1 + 0x110))(param_1);
        if (lVar1 == lVar5) goto LAB_fffffff0081cafc8;
        iVar2 = (**(code **)(*param_1 + 0x650))(param_1);
        if (iVar2 == 0) {
          return 0;
        }
        thunk_EXT_FUN_80110000038fe968(1);
        FUN_fffffff0081a6068(param_1,0);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    else {
      iVar3 = iVar3 + 1;
      do {
        lVar5 = (**(code **)(*param_1 + 0x110))(param_1);
        if (lVar1 == lVar5) goto LAB_fffffff0081cafc8;
        thunk_EXT_FUN_80110000038fe968(1);
        FUN_fffffff0081a6068(param_1,0);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    uVar6 = thunk_EXT_FUN_8011000003a49114
                      ("AGXk: %s:%d:%s: !!! Failed to stop GFX FW for GPU recovery\n");
    return uVar6;
  }
LAB_fffffff0081cafec:
  (**(code **)(*param_1 + 0x118))(param_1);
  return 1;
LAB_fffffff0081cafc8:
  iVar3 = (**(code **)(*param_1 + 0x118))(param_1);
  if (iVar3 == 0) {
    return 0;
  }
  goto LAB_fffffff0081cafec;
}

