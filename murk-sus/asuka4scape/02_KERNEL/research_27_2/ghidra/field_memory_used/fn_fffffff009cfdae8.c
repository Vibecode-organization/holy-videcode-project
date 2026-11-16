// FUN_fffffff009cfdae8 @ fffffff009cfdae8

/* WARNING: Removing unreachable block (ram,0xfffffff009cfe1c4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cfe134) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cfdd7c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cfdfd0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cfe3b8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cfde0c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cfdc14) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cfe434) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cfe244) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cfe204) */

void FUN_fffffff009cfdae8
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  code *pcVar5;
  bool bVar6;
  long *plVar7;
  long *extraout_x0;
  long *extraout_x0_00;
  long lVar8;
  short *psVar9;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 auVar10 [16];
  undefined4 uVar11;
  undefined1 auVar12 [12];
  undefined4 uVar13;
  undefined1 auVar14 [12];
  
  uVar13 = param_4._0_4_;
  auVar14 = param_4._4_12_;
  uVar11 = param_3._0_4_;
  auVar12 = param_3._4_12_;
  plVar7 = thunk_FUN_fffffff00a894f30((long *)param_7[0x17],*(long *)PTR_PTR_fffffff008089ca8);
  if ((*(uint *)((long)param_7 + 500) >> 4 & 1) != 0) {
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar6 = thunk_FUN_fffffff00a394140(), !bVar6)) {
      psVar9 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar10 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      thunk_FUN_fffffff00a8df19c
                (auVar10,param_2,uVar11,uVar13,param_5,param_6,&MACH_HEADER,psVar9,0,
                 (byte *)"%s@%s: %s::%s: \n");
    }
    else {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: \n");
    }
  }
  if ((int)param_7[0x4ce] != 1) {
    if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
       (bVar6 = thunk_FUN_fffffff00a394140(), bVar6)) {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: unexpected _clockReferenceCount %u\n");
      auVar10 = extraout_q0;
    }
    else {
      psVar9 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar10 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      auVar10 = thunk_FUN_fffffff00a8df19c
                          (auVar10,param_2,uVar11,uVar13,param_5,param_6,&MACH_HEADER,psVar9,0x11,
                           (byte *)"%s@%s: %s::%s: unexpected _clockReferenceCount %u\n");
    }
    if (*(int *)((long)param_7 + 500) < 0) {
      auVar1._4_12_ = auVar12;
      auVar1._0_4_ = uVar11;
      auVar3._4_12_ = auVar14;
      auVar3._0_4_ = uVar13;
      FUN_fffffff009d15290(auVar10,param_2,auVar1,auVar3,param_5,param_6);
      plVar7 = thunk_FUN_fffffff00a894f30
                         ((long *)extraout_x0[0x17],*(long *)PTR_PTR_fffffff008089ca8);
      if ((*(uint *)((long)extraout_x0 + 500) >> 4 & 1) != 0) {
        if (((*(uint *)((long)extraout_x0 + 500) >> 0x1e & 1) == 0) ||
           (bVar6 = thunk_FUN_fffffff00a394140(), !bVar6)) {
          psVar9 = *(short **)PTR_DAT_fffffff008089cb8;
          (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
          auVar10 = (**(code **)(*extraout_x0 + 0x218))(*extraout_x0 + 0x218,extraout_x0,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar10,param_2,uVar11,uVar13,param_5,param_6,&MACH_HEADER,psVar9,0,
                     (byte *)"%s@%s: %s::%s: \n");
        }
        else {
          (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
          (**(code **)(*extraout_x0 + 0x218))(extraout_x0,0);
          thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: \n");
        }
      }
      if ((int)extraout_x0[0x4ce] != 0) {
        if ((((*(uint *)((long)extraout_x0 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
           (bVar6 = thunk_FUN_fffffff00a394140(), bVar6)) {
          (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
          (**(code **)(*extraout_x0 + 0x218))(extraout_x0,0);
          thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: unexpected _clockReferenceCount %u\n");
          auVar10 = extraout_q0_00;
        }
        else {
          psVar9 = *(short **)PTR_DAT_fffffff008089cb8;
          (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
          auVar10 = (**(code **)(*extraout_x0 + 0x218))(*extraout_x0 + 0x218,extraout_x0,0);
          auVar10 = thunk_FUN_fffffff00a8df19c
                              (auVar10,param_2,uVar11,uVar13,param_5,param_6,&MACH_HEADER,psVar9,
                               0x11,(byte *)"%s@%s: %s::%s: unexpected _clockReferenceCount %u\n");
        }
        if (*(int *)((long)extraout_x0 + 500) < 0) {
          auVar2._4_12_ = auVar12;
          auVar2._0_4_ = uVar11;
          auVar4._4_12_ = auVar14;
          auVar4._0_4_ = uVar13;
          FUN_fffffff009d152b4(auVar10,param_2,auVar2,auVar4,param_5,param_6);
          thunk_FUN_fffffff00a2262a8(extraout_x0_00[0x4cb]);
          lVar8 = extraout_x0_00[0x4cc];
          *(int *)(extraout_x0_00 + 0x4cc) = (int)lVar8 + 1;
          if ((int)lVar8 == 0) {
            (**(code **)(*extraout_x0_00 + 0x910))(extraout_x0_00);
          }
          if ((*(uint *)((long)extraout_x0_00 + 500) >> 4 & 1) != 0) {
            if (((*(uint *)((long)extraout_x0_00 + 500) >> 0x1e & 1) == 0) ||
               (bVar6 = thunk_FUN_fffffff00a394140(), !bVar6)) {
              psVar9 = *(short **)PTR_DAT_fffffff008089cb8;
              (**(code **)(*extraout_x0_00 + 0x1e8))(extraout_x0_00,0);
              auVar10 = (**(code **)(*extraout_x0_00 + 0x218))
                                  (*extraout_x0_00 + 0x218,extraout_x0_00,0);
              thunk_FUN_fffffff00a8df19c
                        (auVar10,param_2,uVar11,uVar13,param_5,param_6,&MACH_HEADER,psVar9,0,
                         (byte *)"%s@%s: %s::%s: count %d\n");
            }
            else {
              (**(code **)(*extraout_x0_00 + 0x1e8))(extraout_x0_00,0);
              (**(code **)(*extraout_x0_00 + 0x218))(extraout_x0_00,0);
              thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: count %d\n");
            }
          }
          thunk_FUN_fffffff00a226de0(extraout_x0_00[0x4cb]);
          return;
        }
      }
      lVar8 = *plVar7;
      if ((*(byte *)((long)extraout_x0 + 0x2664) & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009cfe250. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(lVar8 + 0x580))(plVar7,5,0,lVar8 + 0x580);
        return;
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff009cfe210. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(lVar8 + 0x588))(plVar7,0,0,0xffffffff,0xffffffff,lVar8 + 0x588);
      return;
    }
  }
  lVar8 = *plVar7;
  if ((*(byte *)((long)param_7 + 0x2664) & 1) != 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009cfde58. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(lVar8 + 0x588))(plVar7,1,0,0xffffffff,0xffffffff,lVar8 + 0x588);
      return;
    }
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009cfde50);
    (*pcVar5)();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009cfde98. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar8 + 0x580))(plVar7,7,0,lVar8 + 0x580);
    return;
  }
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009cfde90);
  (*pcVar5)();
}

