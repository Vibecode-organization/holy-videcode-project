// FUN_fffffff009cfdea4 @ fffffff009cfdea4

/* WARNING: Removing unreachable block (ram,0xfffffff009cfe3b8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cfe134) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cfe1c4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cfdfd0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cfe434) */

void FUN_fffffff009cfdea4
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  code *pcVar3;
  bool bVar4;
  long *plVar5;
  long *extraout_x0;
  long lVar6;
  short *psVar7;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 auVar8 [16];
  undefined4 uVar9;
  undefined1 auVar10 [12];
  undefined4 uVar11;
  undefined1 auVar12 [12];
  
  uVar11 = param_4._0_4_;
  auVar12 = param_4._4_12_;
  uVar9 = param_3._0_4_;
  auVar10 = param_3._4_12_;
  plVar5 = thunk_FUN_fffffff00a894f30((long *)param_7[0x17],*(long *)PTR_PTR_fffffff008089ca8);
  if ((*(uint *)((long)param_7 + 500) >> 4 & 1) != 0) {
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
      psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      thunk_FUN_fffffff00a8df19c
                (auVar8,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,psVar7,0,
                 (byte *)"%s@%s: %s::%s: \n");
    }
    else {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: \n");
    }
  }
  if ((int)param_7[0x4ce] != 0) {
    if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
       (bVar4 = thunk_FUN_fffffff00a394140(), bVar4)) {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: unexpected _clockReferenceCount %u\n");
      auVar8 = extraout_q0;
    }
    else {
      psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar8 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      auVar8 = thunk_FUN_fffffff00a8df19c
                         (auVar8,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,psVar7,0x11,
                          (byte *)"%s@%s: %s::%s: unexpected _clockReferenceCount %u\n");
    }
    if (*(int *)((long)param_7 + 500) < 0) {
      auVar1._4_12_ = auVar10;
      auVar1._0_4_ = uVar9;
      auVar2._4_12_ = auVar12;
      auVar2._0_4_ = uVar11;
      FUN_fffffff009d152b4(auVar8,param_2,auVar1,auVar2,param_5,param_6);
      thunk_FUN_fffffff00a2262a8(extraout_x0[0x4cb]);
      lVar6 = extraout_x0[0x4cc];
      *(int *)(extraout_x0 + 0x4cc) = (int)lVar6 + 1;
      if ((int)lVar6 == 0) {
        (**(code **)(*extraout_x0 + 0x910))(extraout_x0);
      }
      if ((*(uint *)((long)extraout_x0 + 500) >> 4 & 1) != 0) {
        if (((*(uint *)((long)extraout_x0 + 500) >> 0x1e & 1) == 0) ||
           (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
          psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
          (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
          auVar8 = (**(code **)(*extraout_x0 + 0x218))(*extraout_x0 + 0x218,extraout_x0,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar8,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,psVar7,0,
                     (byte *)"%s@%s: %s::%s: count %d\n");
        }
        else {
          (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
          (**(code **)(*extraout_x0 + 0x218))(extraout_x0,0);
          thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: count %d\n");
        }
      }
      thunk_FUN_fffffff00a226de0(extraout_x0[0x4cb]);
      return;
    }
  }
  lVar6 = *plVar5;
  if ((*(byte *)((long)param_7 + 0x2664) & 1) != 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009cfe208);
      (*pcVar3)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff009cfe210. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar6 + 0x588))(plVar5,0,0,0xffffffff,0xffffffff,lVar6 + 0x588);
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009cfe248);
    (*pcVar3)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009cfe250. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(lVar6 + 0x580))(plVar5,5,0,lVar6 + 0x580);
  return;
}

