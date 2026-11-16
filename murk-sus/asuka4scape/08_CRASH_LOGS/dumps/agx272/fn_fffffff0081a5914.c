// FUN_fffffff0081a5914 @ fffffff0081a5914 size=4

void FUN_fffffff0081a5914(long *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  
  lVar4 = param_1[0xf8];
  if (lVar4 != 0) {
    uVar1 = *(uint *)param_1[0xf7];
    *(uint *)(param_1 + 0xf9) = uVar1;
    uVar2 = ((uint *)param_1[0xf7])[8];
    *(uint *)((long)param_1 + 0x7cc) = uVar2;
    if (((ulong)param_1[0xfb] <= (ulong)uVar1) || ((ulong)param_1[0xfb] <= (ulong)uVar2)) {
LAB_fffffff0081a5bf0:
      thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! read_index out of bounds\n");
      return;
    }
    if (uVar1 == uVar2) {
LAB_fffffff0081a596c:
      iVar3 = FUN_fffffff0081a5c00(param_1);
      if (iVar3 != 0) {
        (**(code **)(*param_1 + 0x7e0))(param_1);
      }
      if (param_1[0xec] != 0) {
        uVar1 = *(uint *)param_1[0xeb];
        uVar5 = (ulong)uVar1;
        *(uint *)(param_1 + 0xed) = uVar1;
        uVar2 = ((uint *)param_1[0xeb])[8];
        *(uint *)((long)param_1 + 0x76c) = uVar2;
        uVar6 = param_1[0xef];
        if ((uVar5 < uVar6) && (uVar2 < uVar6)) {
          do {
            uVar2 = (int)uVar5 + 1;
            iVar3 = 0;
            if (uVar6 != 0) {
              iVar3 = (int)(uVar2 / uVar6);
            }
            uVar2 = uVar2 - iVar3 * (int)uVar6;
            uVar5 = (ulong)uVar2;
          } while (uVar1 != uVar2);
          return;
        }
        goto LAB_fffffff0081a5bf0;
      }
    }
    else {
      while (lVar4 != 0) {
        if ((int)param_1[0xf9] == *(int *)((long)param_1 + 0x7cc)) goto LAB_fffffff0081a596c;
        uStack_40 = 0;
        uStack_58 = 0;
        uStack_60 = 0;
        uStack_48 = 0;
        uStack_50 = 0;
        uStack_78 = 0;
        uStack_80 = 0;
        uStack_68 = 0;
        uStack_70 = 0;
        iVar3 = FUN_fffffff0081b7c6c(param_1 + 0xf6,&uStack_80);
        if (iVar3 == 4) {
          if ((int)uStack_80 != 4) goto LAB_fffffff0081a5b80;
          uVar1 = uStack_78._4_4_;
          iVar3 = thunk_EXT_FUN_8011000002946bb0(*(undefined8 *)(param_1[0xf6] + 0x148));
          if ((uVar1 != 0xffffffff) && (iVar3 <= (int)uVar1 || 0x7fffffff < uVar1)) {
LAB_fffffff0081a5b10:
            thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Ring entry contains bad data\n");
            return;
          }
        }
        else if (iVar3 == 1) {
          if ((int)uStack_80 != 1) goto LAB_fffffff0081a5b80;
          if (5 < uStack_70._4_2_) goto LAB_fffffff0081a5b10;
        }
        else if ((iVar3 == 0) && ((int)uStack_80 != 0)) {
LAB_fffffff0081a5b80:
          thunk_EXT_FUN_8011000003a49114
                    ("AGXk: %s:%d:%s: !!! Ring is processing event of incorrect type\n");
          return;
        }
        lVar4 = param_1[0xf8];
      }
    }
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Using uninitialized validator class\n");
  return;
}

