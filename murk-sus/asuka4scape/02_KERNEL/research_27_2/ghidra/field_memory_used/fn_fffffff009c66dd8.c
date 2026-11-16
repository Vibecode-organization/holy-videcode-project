// FUN_fffffff009c66dd8 @ fffffff009c66dd8

undefined8
FUN_fffffff009c66dd8
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long *param_7,long *param_8)

{
  long *plVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined1 auVar6 [16];
  
  if (param_8 == (long *)0x0) {
    FUN_fffffff009c7ba98(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    return 0;
  }
  plVar1 = (long *)(**(code **)(*param_8 + 0x148))(param_8,"CFBundleIdentifier");
  plVar2 = thunk_FUN_fffffff00a894f30(plVar1,*(long *)PTR_PTR_fffffff00807b5f0);
  if (plVar2 != (long *)0x0) {
    uVar3 = (**(code **)(*plVar2 + 0xb8))(plVar2,"com.apple.driver.AppleCentauriAlpha");
    if ((uVar3 & 1) != 0) {
      uVar5 = 1;
      goto LAB_fffffff009c66f04;
    }
    uVar3 = (**(code **)(*plVar2 + 0xb8))(plVar2,"com.apple.DriverKit-AppleBCMWLAN");
    if ((uVar3 & 1) != 0) {
      uVar5 = 2;
      goto LAB_fffffff009c66f04;
    }
    uVar3 = (**(code **)(*plVar2 + 0xb8))(plVar2,"com.apple.AppleSunriseWLAN");
    if ((uVar3 & 1) != 0) {
      uVar5 = 3;
      goto LAB_fffffff009c66f04;
    }
  }
  uVar5 = 0;
LAB_fffffff009c66f04:
  lVar4 = (**(code **)(*param_7 + 0x38))(param_7);
  auVar6 = thunk_FUN_fffffff00a895b28(lVar4);
  if (plVar2 != (long *)0x0) {
    auVar6 = (**(code **)(*plVar2 + 0xa8))(plVar2);
  }
  thunk_FUN_fffffff00a8df19c
            (auVar6,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
             (short *)PTR_DAT_fffffff00807b638,0,
             (byte *)"  %s(%s): Wi-Fi driver CFBundleIdentifier is \"%s\", chipset %s");
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar5;
}

