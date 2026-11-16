// FUN_fffffff00817d3bc @ fffffff00817d3bc size=796

void FUN_fffffff00817d3bc(undefined8 param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  undefined *puVar5;
  ulong unaff_x30;
  
  uVar4 = thunk_EXT_FUN_80110000031cd550(param_2);
  if (uVar4 < 4) {
LAB_fffffff00817d3ec:
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817d420);
      (*pcVar2)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff00817d428. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(PTR_DAT_fffffff007ca6170 + 0x158))
              (param_1,param_2,PTR_DAT_fffffff007ca6170 + 0x158);
    return;
  }
  iVar3 = thunk_EXT_FUN_80110000031cd5d0(param_2,&DAT_fffffff007114018,3);
  lVar1 = 3;
  if (iVar3 != 0) {
    lVar1 = 0;
  }
  lVar1 = param_2 + lVar1;
  iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"GPUAccumulatedEnergy");
  if (iVar3 == 0) {
    puVar5 = &UNK_fffffff007c92c28;
  }
  else {
    iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"MaxGPUAbsolutePower");
    if (iVar3 == 0) {
      puVar5 = &UNK_fffffff007c92c48;
    }
    else {
      iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"GPUMaxPower");
      if (iVar3 == 0) {
        puVar5 = &UNK_fffffff007c92c68;
      }
      else {
        iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"FilteredGPUPower");
        if (iVar3 == 0) {
          puVar5 = &UNK_fffffff007c92c88;
        }
        else {
          iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"GPUUtilization");
          if (iVar3 == 0) {
            puVar5 = &UNK_fffffff007c92ca8;
          }
          else {
            iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"MaxGPUUtilization");
            if (iVar3 == 0) {
              puVar5 = &UNK_fffffff007c92cc8;
            }
            else {
              iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"CLTMPerfMax");
              if (iVar3 == 0) {
                puVar5 = &UNK_fffffff007c92ce8;
              }
              else {
                iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"PPMPerfMax");
                if (iVar3 == 0) {
                  puVar5 = &UNK_fffffff007c92d08;
                }
                else {
                  iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"AbsTimeOffset");
                  if (iVar3 == 0) {
                    puVar5 = &UNK_fffffff007c92d28;
                  }
                  else {
                    iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"ContTimeOffset");
                    if (iVar3 == 0) {
                      puVar5 = &UNK_fffffff007c92d48;
                    }
                    else {
                      iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"CoreConfig");
                      if (iVar3 == 0) {
                        puVar5 = &UNK_fffffff007c92d68;
                      }
                      else {
                        iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"PerfCtrPartitionInfoList");
                        if (iVar3 == 0) {
                          puVar5 = &UNK_fffffff007c92d88;
                        }
                        else {
                          iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"PPMGPUPowerMax");
                          if (iVar3 == 0) {
                            puVar5 = &UNK_fffffff007c92da8;
                          }
                          else {
                            iVar3 = thunk_EXT_FUN_8011000003a7051c
                                              (lVar1,"NoiseSuppressionGPUIdlePowerOffState");
                            if (iVar3 == 0) {
                              puVar5 = &UNK_fffffff007c92dc8;
                            }
                            else {
                              iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"GPUMtrMaxOverallTemp");
                              if (iVar3 == 0) {
                                puVar5 = &UNK_fffffff007c92de8;
                              }
                              else {
                                iVar3 = thunk_EXT_FUN_8011000003a7051c
                                                  (lVar1,"GPUCLPCDynamicSplitRatio");
                                if (iVar3 == 0) {
                                  puVar5 = &UNK_fffffff007c92e08;
                                }
                                else {
                                  iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"GPUCLPCSharedData");
                                  if (iVar3 == 0) {
                                    puVar5 = &UNK_fffffff007c92e28;
                                  }
                                  else {
                                    iVar3 = thunk_EXT_FUN_8011000003a7051c(lVar1,"GPUPerfMap");
                                    if (iVar3 == 0) {
                                      puVar5 = &UNK_fffffff007c92e48;
                                    }
                                    else {
                                      iVar3 = thunk_EXT_FUN_8011000003a7051c
                                                        (lVar1,"GPUMtrAverageTemp");
                                      if (iVar3 != 0) goto LAB_fffffff00817d3ec;
                                      puVar5 = &UNK_fffffff007c92e68;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817d6d0);
    (*pcVar2)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00817d6d4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(puVar5 + 8))(param_1);
  return;
}

