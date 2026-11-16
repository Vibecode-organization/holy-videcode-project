// FUN_fffffff00817d23c @ fffffff00817d23c size=384

undefined8 FUN_fffffff00817d23c(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  undefined *puVar5;
  ulong unaff_x30;
  
  plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(param_2,*(undefined8 *)PTR_DAT_fffffff007ca5fc0);
  if (plVar2 == (long *)0x0) {
    return 0xe00002c2;
  }
  lVar3 = (**(code **)(*plVar2 + 0x138))(plVar2,"SetMaxGPUAbsolutePower");
  if (lVar3 == 0) {
    lVar3 = (**(code **)(*plVar2 + 0x138))(plVar2,"SetLifetimeServoFastDieTemperatureTarget");
    if (lVar3 == 0) {
      lVar3 = (**(code **)(*plVar2 + 0x138))(plVar2,"SetCLPCDeadlineControlEffort");
      if (lVar3 == 0) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817d3b0);
          (*pcVar1)();
        }
                    /* WARNING: Could not recover jumptable at 0xfffffff00817d3b8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        uVar4 = (**(code **)(PTR_DAT_fffffff007ca6170 + 0x170))
                          (param_1,param_2,PTR_DAT_fffffff007ca6170 + 0x170);
        return uVar4;
      }
      puVar5 = &UNK_fffffff007c92ec8;
    }
    else {
      puVar5 = &UNK_fffffff007c92ea8;
    }
  }
  else {
    puVar5 = &UNK_fffffff007c92e88;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817d374);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00817d378. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (**(code **)(puVar5 + 8))(param_1,plVar2,lVar3);
  return uVar4;
}

