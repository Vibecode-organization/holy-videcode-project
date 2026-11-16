// FUN_fffffff009972b14 @ fffffff009972b14 size=532

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff009972b14(void)

{
  int iVar1;
  long *plVar2;
  code *local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  code *local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff007ff2800;
  iVar1 = thunk_EXT_FUN_801100000389057c(0,1,&DAT_fffffff00af22814);
  if (iVar1 != 0) {
    plVar2 = (long *)thunk_EXT_FUN_80110000038d02e4("lastSubmittedTime");
    if (DAT_fffffff00af22820 != (long *)0x0) {
      (**(code **)(*DAT_fffffff00af22820 + 0x28))();
    }
    DAT_fffffff00af22820 = plVar2;
    plVar2 = (long *)thunk_EXT_FUN_80110000038d02e4("accumulatedGPUTime");
    if (DAT_fffffff00af22828 != (long *)0x0) {
      (**(code **)(*DAT_fffffff00af22828 + 0x28))();
    }
    DAT_fffffff00af22828 = plVar2;
    plVar2 = (long *)thunk_EXT_FUN_80110000038d02e4("API");
    if (DAT_fffffff00af22830 != (long *)0x0) {
      (**(code **)(*DAT_fffffff00af22830 + 0x28))();
    }
    DAT_fffffff00af22830 = plVar2;
    plVar2 = (long *)thunk_EXT_FUN_80110000038d02e4("GL/CL");
    if (DAT_fffffff00af22838 != (long *)0x0) {
      (**(code **)(*DAT_fffffff00af22838 + 0x28))();
    }
    DAT_fffffff00af22838 = plVar2;
    plVar2 = (long *)thunk_EXT_FUN_80110000038d02e4("Metal");
    if (DAT_fffffff00af22840 != (long *)0x0) {
      (**(code **)(*DAT_fffffff00af22840 + 0x28))();
    }
    uRamfffffff00af227f8 = 0;
    _DAT_fffffff00af227f0 = 0;
    uRamfffffff00af22808 = 0;
    _DAT_fffffff00af22800 = 0;
    uStack_38 = 0;
    local_30 = 0;
    local_40 = FUN_fffffff0099751e4;
    DAT_fffffff00af22840 = plVar2;
    thunk_EXT_FUN_8011000003350958(&local_30,"IOGPUFamily",8);
    uStack_58 = uStack_38;
    local_60 = local_40;
    local_50 = local_30;
    iVar1 = thunk_EXT_FUN_80110000036db7a8(&local_60);
    if (iVar1 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"Failed to create the ktrace callback\n"
                );
    }
  }
  if (*(long *)PTR_DAT_fffffff007ff2800 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

