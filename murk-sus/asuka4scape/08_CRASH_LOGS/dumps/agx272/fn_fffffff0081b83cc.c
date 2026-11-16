// FUN_fffffff0081b83cc @ fffffff0081b83cc size=4

void FUN_fffffff0081b83cc(long *param_1,int param_2,int param_3)

{
  long lVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    (**(code **)(*param_1 + 0xa08))(param_1,1);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1[0x50] + 0x11d88));
    if (*(int *)(param_1[0x50] + 0x11a68) != 0) {
      thunk_EXT_FUN_8011000003a49114
                (
                "AGXk: %s:%d:%s: !!! AGXPowerTransitionState (%d) must be in kAGXPowerTransitionStateNone\n"
                );
      return;
    }
    lVar1 = 0x11a70;
    if (param_3 == 0) {
      lVar1 = 0x11a78;
    }
    uVar2 = 1;
    if (param_3 != 0) {
      uVar2 = 2;
    }
    thunk_EXT_FUN_8011000003223a00(*(undefined8 *)(param_1[0x50] + lVar1));
    *(undefined4 *)(param_1[0x50] + 0x11a68) = uVar2;
  }
  return;
}

