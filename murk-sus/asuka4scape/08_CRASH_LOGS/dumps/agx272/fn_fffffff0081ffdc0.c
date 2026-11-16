// FUN_fffffff0081ffdc0 @ fffffff0081ffdc0 size=580

void FUN_fffffff0081ffdc0(long *param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1[9] + 0x111b8));
  (**(code **)(**(long **)(param_1[9] + 0x111b0) + 0x90))
            (*(long **)(param_1[9] + 0x111b0),0,param_1);
  *(undefined4 *)(param_1 + 0x3f) = 0;
  lVar3 = param_1[0x40];
  if (lVar3 != 0) {
    if ((int)param_1[0x41] == 0) {
      lVar4 = 0;
    }
    else {
      uVar5 = 0;
      do {
        (**(code **)(*param_1 + 0xe8))(param_1,uVar5,0);
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(param_1 + 0x41));
      lVar3 = param_1[0x40];
      lVar4 = (ulong)*(uint *)(param_1 + 0x41) << 3;
    }
    param_1[0x40] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4b48,lVar3,lVar4);
    param_1[0x40] = 0;
    *(undefined4 *)(param_1 + 0x41) = 0;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1[9] + 0x111b8));
  if ((*(byte *)((long)param_1 + 0x1bc) & 1) != 0) {
    (**(code **)(**(long **)(param_1[9] + 0x4b0) + 0x6c0))(*(long **)(param_1[9] + 0x4b0),0,0);
    lVar3 = param_1[9];
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0x111c8));
    if ((*(int *)(lVar3 + 0x111e0) == 0) &&
       (*(long **)(lVar3 + 0x111d0) == (long *)0x0 || *(long **)(lVar3 + 0x111d0) == param_1)) {
      *(undefined8 *)(lVar3 + 0x111d0) = 0;
      (**(code **)(**(long **)(lVar3 + 0x4b0) + 0x6c0))(*(long **)(lVar3 + 0x4b0),0,0);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x111c8));
    *(undefined1 *)((long)param_1 + 0x1bc) = 0;
  }
  if ((*(byte *)(param_1 + 0x39) & 1) != 0) {
    lVar3 = param_1[9];
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0x111c8));
    if (((*(long *)(lVar3 + 0x111d0) == 0) &&
        (iVar2 = *(int *)(lVar3 + 0x111e0) + -1, *(int *)(lVar3 + 0x111e0) = iVar2, iVar2 == 0)) &&
       (iVar2 = (**(code **)(**(long **)(lVar3 + 0x4b0) + 0x6c0))(*(long **)(lVar3 + 0x4b0),0,0),
       iVar2 == 0)) {
      *(undefined4 *)(lVar3 + 0x111e4) = 4;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x111c8));
    *(undefined1 *)(param_1 + 0x39) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ffff8);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff008200000. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca60d0 + 0xb0))(param_1);
  return;
}

