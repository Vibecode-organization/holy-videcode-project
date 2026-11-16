// FUN_fffffff009c885cc @ fffffff009c885cc

void FUN_fffffff009c885cc
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7,ulong param_8,
               long *param_9,long *param_10)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  ushort uVar3;
  undefined1 auVar4 [16];
  code *pcVar5;
  bool bVar6;
  int iVar7;
  undefined4 uVar8;
  long lVar9;
  ushort uVar10;
  short *psVar11;
  long *plVar12;
  ulong unaff_x30;
  long lVar13;
  
  if (*(int *)((long)param_7 + 0xc) != 4) {
    if ((*(uint *)((long)param_7 + 0x8c) & 1) != 0) {
      if (((*(uint *)((long)param_7 + 0x8c) >> 0x1e & 1) == 0) ||
         (bVar6 = thunk_FUN_fffffff00a394140(), !bVar6)) {
        psVar11 = *(short **)PTR_DAT_fffffff00807fa80;
        lVar9 = (**(code **)(*param_7 + 0x38))(param_7);
        auVar4 = thunk_FUN_fffffff00a895b28(lVar9);
        thunk_FUN_fffffff00a8df19c
                  (auVar4,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar11,0,
                   (byte *)"%s: %s::%s: Unexpected call to setControlOutResponse in state %d\n");
      }
      else {
        lVar9 = (**(code **)(*param_7 + 0x38))(param_7);
        thunk_FUN_fffffff00a895b28(lVar9);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)"%s: %s::%s: Unexpected call to setControlOutResponse in state %d\n");
      }
    }
    return;
  }
  (**(code **)(*(long *)param_7[0x10] + 0xb8))(param_1._0_8_);
  if (param_10 == (long *)0x0) {
    param_10 = (long *)param_7[0xe];
  }
  param_7[8] = (long)param_10;
  (**(code **)(*param_10 + 0x20))(param_10);
  (**(code **)(*(long *)param_7[8] + 0xd8))((long *)param_7[8],0);
  plVar12 = param_7 + 5;
  if (*(ushort *)((long)param_7 + 0x16) <= param_8) {
    param_8 = (ulong)*(ushort *)((long)param_7 + 0x16);
  }
  param_7[3] = param_8;
  param_7[4] = 0;
  if ((long *)*plVar12 != (long *)0x0) {
    (**(code **)(*(long *)*plVar12 + 0x28))();
  }
  *plVar12 = 0;
  param_7[6] = 0;
  param_7[7] = 0;
  if (param_9 != (long *)0x0) {
    lVar9 = param_9[2];
    lVar13 = *param_9;
    param_7[6] = param_9[1];
    *plVar12 = lVar13;
    param_7[7] = lVar9;
    if ((long *)*plVar12 != (long *)0x0) {
      (**(code **)(*(long *)*plVar12 + 0x20))();
    }
  }
  uVar3 = *(ushort *)((long)param_7 + 0x16);
  uVar10 = 0x40;
  if ((long *)param_7[0xd] != (long *)0x0) {
    iVar7 = (**(code **)(*(long *)param_7[0xd] + 0x5c0))();
    uVar10 = 0x200;
    if (iVar7 < 3) {
      uVar10 = 0x40;
    }
  }
  uVar8 = 5;
  if (uVar3 <= uVar10) {
    uVar8 = 6;
  }
  uVar2 = *(undefined4 *)((long)param_7 + 0xc);
  *(undefined4 *)((long)param_7 + 0xc) = uVar8;
  if ((*(uint *)((long)param_7 + 0x8c) >> 5 & 1) != 0) {
    if (((*(uint *)((long)param_7 + 0x8c) >> 0x1e & 1) == 0) ||
       (bVar6 = thunk_FUN_fffffff00a394140(), !bVar6)) {
      psVar11 = *(short **)PTR_DAT_fffffff00807fa80;
      lVar9 = (**(code **)(*param_7 + 0x38))(param_7);
      auVar4 = thunk_FUN_fffffff00a895b28(lVar9);
      thunk_FUN_fffffff00a8df19c
                (auVar4,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar11,0,
                 (byte *)"%s: %s::%s: state change %d -> %d\n");
    }
    else {
      lVar9 = (**(code **)(*param_7 + 0x38))(param_7);
      thunk_FUN_fffffff00a895b28(lVar9);
      thunk_FUN_fffffff00a9029a0((byte *)"%s: %s::%s: state change %d -> %d\n");
    }
  }
  puVar1 = (undefined8 *)(*(long *)param_7[0xd] + 0x6d0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c888d8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*puVar1)((long *)param_7[0xd],uVar2,*(undefined4 *)((long)param_7 + 0xc),puVar1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c888d0);
  (*pcVar5)();
}

