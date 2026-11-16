// FUN_fffffff009965f3c @ fffffff009965f3c size=1004

void FUN_fffffff009965f3c(long param_1)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  int iVar9;
  ulong unaff_x30;
  
  plVar3 = (long *)FUN_fffffff009944a54(*(undefined8 *)(param_1 + 0x10));
  plVar4 = (long *)FUN_fffffff009944a54(*(undefined8 *)(param_1 + 0x80));
  plVar5 = (long *)FUN_fffffff009944a54(*(undefined8 *)(param_1 + 0x18));
  plVar6 = (long *)FUN_fffffff009944a54(*(undefined8 *)(param_1 + 0x100));
  plVar7 = (long *)FUN_fffffff009944a54(*(undefined8 *)(param_1 + 0x88));
  if (plVar3 != (long *)0x0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
    iVar2 = (**(code **)(*plVar3 + 0x90))(plVar3);
    if (iVar2 != 0) {
      iVar9 = 0;
      do {
        plVar8 = (long *)(**(code **)(*plVar3 + 0x118))(plVar3,iVar9);
        (**(code **)(*plVar8 + 0xe8))();
        iVar9 = iVar9 + 1;
      } while (iVar2 != iVar9);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
    thunk_EXT_FUN_8011000003247bfc(0);
  }
  if (plVar4 != (long *)0x0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
    iVar2 = (**(code **)(*plVar4 + 0x90))(plVar4);
    if (iVar2 != 0) {
      iVar9 = 0;
      do {
        (**(code **)(*plVar4 + 0x118))(plVar4,iVar9);
        FUN_fffffff00994defc();
        iVar9 = iVar9 + 1;
      } while (iVar2 != iVar9);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
    thunk_EXT_FUN_8011000003247bfc(0);
  }
  if (plVar5 != (long *)0x0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
    iVar2 = (**(code **)(*plVar5 + 0x90))(plVar5);
    if (iVar2 != 0) {
      iVar9 = 0;
      do {
        (**(code **)(*plVar5 + 0x118))(plVar5,iVar9);
        FUN_fffffff00997feac();
        iVar9 = iVar9 + 1;
      } while (iVar2 != iVar9);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
    thunk_EXT_FUN_8011000003247bfc(0);
  }
  if (plVar6 != (long *)0x0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
    iVar2 = (**(code **)(*plVar6 + 0x90))(plVar6);
    if (iVar2 != 0) {
      iVar9 = 0;
      do {
        (**(code **)(*plVar6 + 0x118))(plVar6,iVar9);
        iVar9 = iVar9 + 1;
      } while (iVar2 != iVar9);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
    thunk_EXT_FUN_8011000003247bfc(0);
  }
  if (plVar7 != (long *)0x0) {
    iVar2 = (**(code **)(*plVar7 + 0x90))(plVar7);
    if (iVar2 != 0) {
      iVar9 = 0;
      do {
        (**(code **)(*plVar7 + 0x118))(plVar7,iVar9);
        FUN_fffffff009976c70();
        iVar9 = iVar9 + 1;
      } while (iVar2 != iVar9);
    }
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  if (plVar3 != (long *)0x0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009966300);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff009966308. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar3 + 0x28))(plVar3,(undefined8 *)(*plVar3 + 0x28));
    return;
  }
  return;
}

