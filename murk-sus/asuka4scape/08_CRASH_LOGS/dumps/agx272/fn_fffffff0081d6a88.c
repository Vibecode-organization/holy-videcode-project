// FUN_fffffff0081d6a88 @ fffffff0081d6a88 size=4

void FUN_fffffff0081d6a88(long *param_1)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  ulong unaff_x30;
  
  iVar2 = FUN_fffffff0081d6c4c();
  if (((iVar2 == 0x8015) || (iVar2 = FUN_fffffff0081d6c4c(), iVar2 == 0x8027)) ||
     (iVar2 = FUN_fffffff0081d6c4c(), iVar2 == 0x8020)) {
    return;
  }
  plVar3 = (long *)thunk_EXT_FUN_801100000392ef4c("AGXArmFirmwareMapper",0);
  if (plVar3 == (long *)0x0) {
    thunk_EXT_FUN_8011000003a49114
              (
              "AGXk: %s:%d:%s: !!! Failed to create matching dictionary for AGXArmFirmwareMapper!\n"
              );
    return;
  }
  plVar4 = (long *)thunk_EXT_FUN_801100000392ece0(plVar3,10000000000);
  lVar5 = thunk_EXT_FUN_8011000003890f30(plVar4,&DAT_fffffff00ae22650);
  if (lVar5 != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0xd8));
    if (*(long *)(lVar5 + 0xe0) != 0) {
      thunk_EXT_FUN_8011000003a49114
                (
                "AGXk: %s:%d:%s: !!! Setting AGXArmFirmwareMapper accelerator handle a second time (fAccelerator=0x%p accel=0x%p)!\n"
                );
      return;
    }
    (**(code **)(*param_1 + 0x20))(param_1);
    *(long **)(lVar5 + 0xe0) = param_1;
    thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(lVar5 + 0xd8),(long *)(lVar5 + 0xe0),0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0xd8));
  }
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081d6bec);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081d6bf4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar3 + 0x28))(plVar3,(undefined8 *)(*plVar3 + 0x28));
  return;
}

