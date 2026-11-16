// FUN_fffffff0099633e8 @ fffffff0099633e8 size=4

void FUN_fffffff0099633e8(long *param_1)

{
  char cVar1;
  undefined *puVar2;
  code *pcVar3;
  int iVar4;
  long *plVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 in_x6;
  undefined8 in_x7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  long *plVar11;
  ulong unaff_x30;
  char *pcVar12;
  ulong uStack_e8;
  ulong uStack_e0;
  long lStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined4 uStack_70;
  long lStack_68;
  
  lStack_68 = *(long *)PTR_DAT_fffffff007ff2800;
  plVar5 = (long *)FUN_fffffff0099631a4(param_1,&lStack_d8,1);
  if (plVar5 == (long *)0x0) {
    if (*(long *)PTR_DAT_fffffff007ff2800 == lStack_68) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099634e8);
        (*pcVar3)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff0099634f0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0xa0))(param_1,(undefined8 *)(*param_1 + 0xa0));
      return;
    }
  }
  else {
    lVar8 = param_1[0x1c];
    uVar6 = thunk_EXT_FUN_8011000003397c88();
    if (uVar6 < (ulong)(lVar8 + lStack_d8)) {
      param_1[0x1b] = lStack_d8;
      (**(code **)(*(long *)param_1[0x19] + 0x130))((long *)param_1[0x19],lVar8 + lStack_d8);
    }
    else {
      plVar11 = (long *)plVar5[10];
      *(undefined4 *)(param_1 + 0x1d) = 2;
      cVar1 = (char)*(undefined4 *)((long)plVar5 + 0x84);
      uStack_70 = 0;
      uStack_88 = 0;
      uStack_90 = 0;
      uStack_78 = 0;
      uStack_80 = 0;
      uStack_a8 = 0;
      uStack_b0 = 0;
      uStack_98 = 0;
      uStack_a0 = 0;
      uStack_c8 = 0;
      uStack_d0 = 0;
      uStack_b8 = 0;
      uStack_c0 = 0;
      iVar4 = thunk_EXT_FUN_80110000037693ec(&uStack_d0,100,"stamp[idx:%d, %d]");
      if ((int)plVar5[0x11] != 0xff) {
        cVar1 = (char)(int)plVar5[0x11];
        thunk_EXT_FUN_80110000037693ec
                  ((long)&uStack_d0 + (long)iVar4,(long)(100 - iVar4),"[idx:%d, %d]");
      }
      uStack_e8 = 0;
      uStack_e0 = 0;
      thunk_EXT_FUN_8011000003398228(param_1[0x1b],&uStack_e0);
      uVar7 = thunk_EXT_FUN_8011000003397c88();
      thunk_EXT_FUN_8011000003398228(uVar7,&uStack_e8);
      puVar2 = PTR_DAT_fffffff007ff2808;
      uVar6 = uStack_e0 / 1000000;
      uVar9 = uStack_e8 / 1000000;
      uVar10 = (ulong)*(uint *)(plVar5[10] + 0x6c);
      pcVar12 = "virtual void IOGPUScheduler::progressTimerCheckInterrupt()";
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: command timeout detected - GPU start time %lld ms, now %lld ms, priority=%d\n"
                );
      thunk_EXT_FUN_80110000036da494
                (0x8509009c,(long)(int)cVar1,(int)param_1[0x1d],0,0,0,in_x6,in_x7,pcVar12,uVar6,
                 uVar9,uVar10);
      pcVar12 = "virtual void IOGPUScheduler::progressTimerCheckInterrupt()";
      thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar2,0x11,"%s: GPURestartBegin %s type=%d\n");
      FUN_fffffff009962a98(param_1);
      uVar6 = FUN_fffffff00994b4ec(param_1[0x36],plVar5 + 0x10);
      if ((uVar6 & 1) == 0) {
        (**(code **)(*plVar11 + 0x98))(plVar11);
        *(int *)(param_1 + 0x22) = (int)param_1[0x22] + 1;
      }
      else {
        pcVar12 = "virtual void IOGPUScheduler::progressTimerCheckInterrupt()";
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: command already GPU finished, skipping restart call\n");
      }
      FUN_fffffff009962b18(param_1);
      thunk_EXT_FUN_80110000036da494
                (0x850900a0,(long)(int)cVar1,(int)param_1[0x1d],0,0,0,in_x6,in_x7,pcVar12);
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: GPURestartEnd %s type=%d\n");
    }
    (**(code **)(*plVar5 + 0x28))(plVar5);
    if (*(long *)PTR_DAT_fffffff007ff2800 == lStack_68) {
      return;
    }
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

