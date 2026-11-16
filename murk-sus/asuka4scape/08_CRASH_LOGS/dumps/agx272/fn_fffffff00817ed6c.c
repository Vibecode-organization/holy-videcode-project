// FUN_fffffff00817ed6c @ fffffff00817ed6c size=352

void FUN_fffffff00817ed6c(long param_1)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong unaff_x30;
  ulong local_38;
  
  if ((*(byte *)(param_1 + 0x5b8) & 1) != 0) {
    uVar5 = *(ulong *)(param_1 + 0x5c0);
    uVar3 = thunk_EXT_FUN_8011000003397c88();
    if (uVar3 < uVar5) {
LAB_fffffff00817edf4:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817ee1c);
        (*pcVar1)();
      }
      thunk_EXT_FUN_801100000295f33c
                (*(undefined8 *)(param_1 + 0x160),*(undefined8 *)(param_1 + 0x5c0));
      return;
    }
    if (((*(byte *)(param_1 + 0x5a0) & 1) == 0) &&
       (iVar2 = thunk_EXT_FUN_801100000294780c(*(undefined8 *)(param_1 + 0x148)), iVar2 == 0)) {
      iVar2 = (**(code **)(**(long **)(param_1 + 0x4b0) + 0x3b0))();
      if (iVar2 != 0) {
        thunk_EXT_FUN_8011000003204ed8(*(undefined4 *)(param_1 + 0x23c),1000000000,param_1 + 0x5c0);
        goto LAB_fffffff00817edf4;
      }
      *(undefined1 *)(param_1 + 0x5b8) = 0;
      *(undefined1 *)(param_1 + 0x189e8) = 1;
      local_38 = 0;
      uVar4 = thunk_EXT_FUN_8011000003397c88();
      thunk_EXT_FUN_8011000003398228(uVar4,&local_38);
      if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
        uVar3 = local_38 / 1000000;
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
        thunk_EXT_FUN_80110000036da494(0x85930cac,uVar3,0,0,0,0);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
      }
      thunk_EXT_FUN_801100000295e8ec(*(undefined8 *)(param_1 + 0x160),2,0x80);
    }
    else {
      *(undefined1 *)(param_1 + 0x5b8) = 0;
    }
  }
  return;
}

