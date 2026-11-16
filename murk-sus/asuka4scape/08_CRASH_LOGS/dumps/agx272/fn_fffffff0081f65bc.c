// FUN_fffffff0081f65bc @ fffffff0081f65bc size=44

undefined8
FUN_fffffff0081f65bc
          (long param_1,undefined8 param_2,int param_3,undefined8 param_4,int *param_5,long param_6)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  undefined4 uStack_70;
  long lStack_6c;
  undefined4 uStack_64;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  
  if (param_3 == -0x1ff87eff) {
    uVar2 = 0xe00002c2;
    if ((param_5 != (int *)0x0) && (param_6 == 0x10)) {
      lVar6 = *(long *)(param_5 + 2);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x420));
      if (*(long *)(param_1 + 0x418) != 0) {
        lVar5 = 0;
        uVar1 = param_1 + 0x18;
        do {
          if (*(long *)(uVar1 + lVar5 * 0x40) == lVar6) {
            uVar3 = uVar1 + lVar5 * 0x40;
            if (((uVar1 ^ uVar3) & 0xffc0000000000000) != 0) {
              uVar3 = uVar3 & 0xffffffffffff | 0xc8a2000000000000;
            }
            if (*param_5 == 1) {
              if ((*(byte *)(uVar3 + 0x38) & 1) != 0) goto LAB_fffffff0081f66e4;
              uVar4 = 1;
            }
            else {
              if (*param_5 != 2) {
                thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x420));
                return 0xe00002c2;
              }
              if ((*(byte *)(uVar3 + 0x38) & 1) == 0) goto LAB_fffffff0081f66e4;
              uVar4 = 0;
            }
            *(char *)(uVar3 + 0x38) = (char)uVar4;
            if (*(long *)(param_1 + 0x10) != 0) {
              uStack_48 = 0;
              uStack_50 = 0;
              uStack_38 = 0;
              uStack_40 = 0;
              uStack_58 = 0;
              uStack_60 = 0;
              uStack_70 = 0x3b;
              lStack_6c = lVar6;
              uStack_64 = uVar4;
              FUN_fffffff0081b6d20(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x4b0),&uStack_70,3);
            }
LAB_fffffff0081f66e4:
            thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x420));
            return 0;
          }
          lVar5 = lVar5 + 1;
        } while (*(long *)(param_1 + 0x418) != lVar5);
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x420));
      return 0xe00002f0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

