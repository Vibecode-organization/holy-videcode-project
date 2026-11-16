// FUN_fffffff009976cf8 @ fffffff009976cf8 size=620

undefined8
FUN_fffffff009976cf8(long *param_1,long param_2,long param_3,long param_4,undefined4 *param_5)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  
  uVar5 = 0xe00002bc;
  iVar2 = FUN_fffffff009975b64(param_1[0xa6],param_1);
  if (iVar2 == 0) {
    uVar5 = 0xe00002d7;
  }
  else {
    thunk_EXT_FUN_80110000032222a8(param_1[0xa5]);
    *(undefined1 *)((long)param_1 + 0x526) = 1;
    thunk_EXT_FUN_8011000003222de0(param_1[0xa5]);
    thunk_EXT_FUN_80110000032222a8(param_1[0x8b]);
    if ((param_1[0x85] != 0) && (param_1[0x91] != 0)) {
      if ((*(byte *)((long)param_1 + 0x43a) & 1) == 0) {
        *(undefined4 *)(param_1 + 0xa4) = 0;
        FUN_fffffff009976f64(param_1);
      }
      else {
        *(undefined4 *)(param_1 + 0xa4) = 4;
      }
      if (param_3 != 0) {
        lVar3 = 0;
        do {
          iVar2 = FUN_fffffff009962f24(*(undefined8 *)(param_1[0xa6] + 0x160),param_1);
          if ((int)param_1[0xa8] != iVar2) {
            uVar5 = FUN_fffffff009962ebc(*(undefined8 *)(param_1[0xa6] + 0x160),param_1);
            (**(code **)(*param_1 + 0xe8))(param_1,uVar5);
            *(int *)(param_1 + 0xa8) = iVar2;
          }
          lVar4 = lVar3 * param_4;
          uVar1 = param_2 + (int)lVar4;
          if (lVar4 - (int)lVar4 != 0) {
            uVar1 = param_2 + lVar4 & 0xffffffffffffU | 0x2bad000000000000;
          }
          if (*(int *)(uVar1 + 0x20) != 0) {
            uVar5 = FUN_fffffff009965b58(param_1[0x91]);
            (**(code **)(*param_1 + 0x80))(param_1,uVar5);
          }
          FUN_fffffff00997700c(param_1,uVar1);
          if ((long *)param_1[0xb0] != (long *)0x0) {
            (**(code **)(*(long *)param_1[0xb0] + 0x28))();
          }
          param_1[0xb0] = 0;
          thunk_EXT_FUN_80110000032222a8(param_1[0xa5]);
          if ((*(byte *)((long)param_1 + 0x525) & 1) != 0) {
            (**(code **)(*param_1 + 0xe0))(param_1);
            *(undefined1 *)((long)param_1 + 0x525) = 0;
          }
          thunk_EXT_FUN_8011000003222de0(param_1[0xa5]);
          lVar3 = lVar3 + 1;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
      uVar5 = 0;
      *(int *)(param_1[0xa6] + 0x2e8) = (int)param_1[0x92];
    }
    thunk_EXT_FUN_80110000032222a8(param_1[0xa5]);
    if ((*(byte *)((long)param_1 + 0x525) & 1) != 0) {
      (**(code **)(*param_1 + 0xe0))(param_1);
      *(undefined1 *)((long)param_1 + 0x525) = 0;
    }
    *(undefined1 *)((long)param_1 + 0x526) = 0;
    thunk_EXT_FUN_8011000003222de0(param_1[0xa5]);
    *param_5 = (int)param_1[0xa4];
    thunk_EXT_FUN_8011000003222de0(param_1[0x8b]);
    lVar3 = param_1[0xa6];
    if ((*(byte *)(lVar3 + 0x1ff) >> 2 & 1) != 0) {
      FUN_fffffff0099616bc(*(undefined8 *)(lVar3 + 0x160),0);
      lVar3 = param_1[0xa6];
    }
    FUN_fffffff009975bcc(lVar3);
  }
  return uVar5;
}

