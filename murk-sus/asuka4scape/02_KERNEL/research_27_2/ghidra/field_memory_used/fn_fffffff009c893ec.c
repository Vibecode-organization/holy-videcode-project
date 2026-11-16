// FUN_fffffff009c893ec @ fffffff009c893ec

/* WARNING: Removing unreachable block (ram,0xfffffff009c89478) */

void FUN_fffffff009c893ec
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7,
               undefined8 param_8)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  short *psVar5;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 auVar6 [16];
  long *local_38;
  undefined1 *puStack_30;
  undefined8 local_28;
  
  if (*(int *)((long)param_7 + 0xc) == 7) {
    (**(code **)(*(long *)param_7[0x10] + 0xb8))();
    puStack_30 = &LAB_fffffff009c8a460;
    lVar4 = *(long *)param_7[0xd];
    local_38 = param_7;
    local_28 = param_8;
    iVar3 = (**(code **)(lVar4 + 0x748))
                      (lVar4 + 0x748,(long *)param_7[0xd],(int)param_7[0xc],param_7[0xe],0,&local_38
                       ,0,0);
    if (iVar3 != 0) {
      FUN_fffffff009c895b0(extraout_q0,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    return;
  }
  if ((*(uint *)((long)param_7 + 0x8c) & 1) != 0) {
    if (((*(uint *)((long)param_7 + 0x8c) >> 0x1e & 1) == 0) ||
       (bVar2 = thunk_FUN_fffffff00a394140(), !bVar2)) {
      psVar5 = *(short **)PTR_DAT_fffffff00807fa80;
      lVar4 = (**(code **)(*param_7 + 0x38))(param_7);
      auVar6 = thunk_FUN_fffffff00a895b28(lVar4);
      param_1 = thunk_FUN_fffffff00a8df19c
                          (auVar6,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar5,0,
                           (byte *)
                           "%s: %s::%s: Unexpected call to sendControlOutStatus in state %d\n");
    }
    else {
      lVar4 = (**(code **)(*param_7 + 0x38))(param_7);
      thunk_FUN_fffffff00a895b28(lVar4);
      thunk_FUN_fffffff00a9029a0
                ((byte *)"%s: %s::%s: Unexpected call to sendControlOutStatus in state %d\n");
      param_1 = extraout_q0_00;
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    FUN_fffffff009c895b0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c895ac);
  (*pcVar1)();
}

