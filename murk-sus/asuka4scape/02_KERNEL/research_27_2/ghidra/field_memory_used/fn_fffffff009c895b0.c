// FUN_fffffff009c895b0 @ fffffff009c895b0

void FUN_fffffff009c895b0
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7)

{
  uint uVar1;
  undefined4 uVar2;
  code *pcVar3;
  bool bVar4;
  long lVar5;
  long *plVar6;
  int iVar7;
  undefined8 *puVar8;
  short *psVar9;
  ulong unaff_x30;
  undefined1 auVar10 [16];
  
  uVar1 = *(uint *)((long)param_7 + 0x8c);
  if (5 < *(int *)((long)param_7 + 0xc) - 3U) {
    if ((uVar1 & 1) != 0) {
      if (((uVar1 >> 0x1e & 1) == 0) || (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
        psVar9 = *(short **)PTR_DAT_fffffff00807fa80;
        lVar5 = (**(code **)(*param_7 + 0x38))(param_7);
        auVar10 = thunk_FUN_fffffff00a895b28(lVar5);
        thunk_FUN_fffffff00a8df19c
                  (auVar10,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar9,0,
                   (byte *)"%s: %s::%s: Unexpected call to stallSetupRequest in state %d\n");
      }
      else {
        lVar5 = (**(code **)(*param_7 + 0x38))(param_7);
        thunk_FUN_fffffff00a895b28(lVar5);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)"%s: %s::%s: Unexpected call to stallSetupRequest in state %d\n");
      }
    }
    return;
  }
  if ((uVar1 & 1) != 0) {
    if (((uVar1 >> 0x1e & 1) == 0) || (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
      psVar9 = *(short **)PTR_DAT_fffffff00807fa80;
      lVar5 = (**(code **)(*param_7 + 0x38))(param_7);
      auVar10 = thunk_FUN_fffffff00a895b28(lVar5);
      thunk_FUN_fffffff00a8df19c
                (auVar10,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar9,0,
                 (byte *)"%s: %s::%s: %02x %02x %04x %04x %04x\n");
    }
    else {
      lVar5 = (**(code **)(*param_7 + 0x38))(param_7);
      thunk_FUN_fffffff00a895b28(lVar5);
      thunk_FUN_fffffff00a9029a0((byte *)"%s: %s::%s: %02x %02x %04x %04x %04x\n");
    }
  }
  if ((char)param_7[2] < '\0') {
    FUN_fffffff009c951e8((long *)param_7[0xd],*(int *)((long)param_7 + 100),1);
    plVar6 = (long *)param_7[0xd];
    iVar7 = (int)param_7[0xc];
  }
  else {
    FUN_fffffff009c951e8((long *)param_7[0xd],(int)param_7[0xc],1);
    plVar6 = (long *)param_7[0xd];
    iVar7 = *(int *)((long)param_7 + 100);
  }
  FUN_fffffff009c951e8(plVar6,iVar7,1);
  uVar2 = *(undefined4 *)((long)param_7 + 0xc);
  *(undefined4 *)((long)param_7 + 0xc) = 9;
  if ((*(uint *)((long)param_7 + 0x8c) >> 5 & 1) != 0) {
    if (((*(uint *)((long)param_7 + 0x8c) >> 0x1e & 1) == 0) ||
       (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
      psVar9 = *(short **)PTR_DAT_fffffff00807fa80;
      lVar5 = (**(code **)(*param_7 + 0x38))(param_7);
      auVar10 = thunk_FUN_fffffff00a895b28(lVar5);
      thunk_FUN_fffffff00a8df19c
                (auVar10,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar9,0,
                 (byte *)"%s: %s::%s: state change %d -> %d\n");
    }
    else {
      lVar5 = (**(code **)(*param_7 + 0x38))(param_7);
      thunk_FUN_fffffff00a895b28(lVar5);
      thunk_FUN_fffffff00a9029a0((byte *)"%s: %s::%s: state change %d -> %d\n");
    }
  }
  (**(code **)(*(long *)param_7[0xd] + 0x6d0))
            ((long *)param_7[0xd],uVar2,*(undefined4 *)((long)param_7 + 0xc));
  puVar8 = (undefined8 *)(*(long *)param_7[0x10] + 0xb8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c89958);
    (*pcVar3)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c89960. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar8)((long *)param_7[0x10],puVar8);
  return;
}

