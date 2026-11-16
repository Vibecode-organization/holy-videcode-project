// FUN_fffffff0081f65e8 @ fffffff0081f65e8 size=300

undefined8 FUN_fffffff0081f65e8(long param_1)

{
  ulong uVar1;
  int *in_x4;
  ulong uVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  undefined4 local_70;
  long local_6c;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  
  lVar5 = *(long *)(in_x4 + 2);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x420));
  if (*(long *)(param_1 + 0x418) != 0) {
    lVar4 = 0;
    uVar1 = param_1 + 0x18;
    do {
      if (*(long *)(uVar1 + lVar4 * 0x40) == lVar5) {
        uVar2 = uVar1 + lVar4 * 0x40;
        if (((uVar1 ^ uVar2) & 0xffc0000000000000) != 0) {
          uVar2 = uVar2 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if (*in_x4 == 1) {
          if ((*(byte *)(uVar2 + 0x38) & 1) != 0) goto LAB_fffffff0081f66e4;
          uVar3 = 1;
        }
        else {
          if (*in_x4 != 2) {
            thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x420));
            return 0xe00002c2;
          }
          if ((*(byte *)(uVar2 + 0x38) & 1) == 0) goto LAB_fffffff0081f66e4;
          uVar3 = 0;
        }
        *(char *)(uVar2 + 0x38) = (char)uVar3;
        if (*(long *)(param_1 + 0x10) != 0) {
          uStack_48 = 0;
          local_50 = 0;
          uStack_38 = 0;
          uStack_40 = 0;
          uStack_58 = 0;
          local_60 = 0;
          local_70 = 0x3b;
          local_6c = lVar5;
          local_64 = uVar3;
          FUN_fffffff0081b6d20(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x4b0),&local_70,3);
        }
LAB_fffffff0081f66e4:
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x420));
        return 0;
      }
      lVar4 = lVar4 + 1;
    } while (*(long *)(param_1 + 0x418) != lVar4);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x420));
  return 0xe00002f0;
}

