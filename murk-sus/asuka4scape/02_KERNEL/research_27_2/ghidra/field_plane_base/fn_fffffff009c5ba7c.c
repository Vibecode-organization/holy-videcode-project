// FUN_fffffff009c5ba7c @ fffffff009c5ba7c

void FUN_fffffff009c5ba7c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7)

{
  byte bVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  code *pcVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  long *plVar10;
  undefined8 extraout_x1;
  undefined8 uVar11;
  char *pcVar12;
  undefined4 **in_x4;
  long lVar13;
  long *plVar14;
  long *plVar15;
  int iVar16;
  ulong unaff_x30;
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 extraout_q0 [16];
  undefined4 uVar19;
  undefined1 auVar20 [12];
  undefined4 uVar21;
  undefined1 auVar22 [12];
  
  uVar21 = param_4._0_4_;
  auVar22 = param_4._4_12_;
  uVar19 = param_3._0_4_;
  auVar20 = param_3._4_12_;
  auVar17 = (**(code **)(*param_7 + 0x20))();
  auVar18._4_12_ = auVar20;
  auVar18._0_4_ = uVar19;
  auVar3._4_12_ = auVar22;
  auVar3._0_4_ = uVar21;
  thunk_FUN_fffffff00a25ae9c(auVar17,param_2,auVar18,auVar3,param_5,param_6,param_7[0x23]);
  lVar9 = (**(code **)(*param_7 + 0x38))(param_7);
  auVar18 = thunk_FUN_fffffff00a895b28(lVar9);
  thunk_FUN_fffffff00a8df19c
            (auVar18,param_2,uVar19,uVar21,param_5,param_6,&MACH_HEADER,
             (short *)PTR_DAT_fffffff00807b638,0,(byte *)"  %s(%s): Callback thread started");
  do {
    while( true ) {
      lVar13 = param_7[0x25];
      lVar9 = thunk_FUN_fffffff00a39bc88();
      auVar17._4_12_ = auVar20;
      auVar17._0_4_ = uVar19;
      auVar4._4_12_ = auVar22;
      auVar4._0_4_ = uVar21;
      iVar7 = thunk_FUN_fffffff00a25b494
                        (extraout_q0,param_2,auVar17,auVar4,param_5,param_6,lVar13,
                         param_7[0x26] + lVar9);
      thunk_FUN_fffffff00a2262a8(param_7[0x1a]);
      if (iVar7 == 0) {
        thunk_FUN_fffffff00a226de0(param_7[0x1a]);
      }
      else {
        bVar1 = *(byte *)((long)param_7 + 0x109);
        auVar18 = thunk_FUN_fffffff00a226de0(param_7[0x1a]);
        if ((bVar1 & 1) != 0) {
          auVar2._4_12_ = auVar20;
          auVar2._0_4_ = uVar19;
          auVar5._4_12_ = auVar22;
          auVar5._0_4_ = uVar21;
          iVar7 = thunk_FUN_fffffff00a25aff8
                            (auVar18,param_2,auVar2,auVar5,param_5,param_6,param_7[0x24]);
          if (iVar7 != 0) {
            lVar9 = (**(code **)(*param_7 + 0x38))(param_7);
            auVar18 = thunk_FUN_fffffff00a895b28(lVar9);
            thunk_FUN_fffffff00a8df19c
                      (auVar18,param_2,uVar19,uVar21,param_5,param_6,&MACH_HEADER,
                       (short *)PTR_DAT_fffffff00807b638,0,
                       (byte *)"  %s(%s): Callback thread stop semaphore signal returned error %d");
          }
          plVar14 = (long *)thunk_FUN_fffffff00a394230();
          lVar9 = (**(code **)(*param_7 + 0x38))(param_7);
          auVar18 = thunk_FUN_fffffff00a895b28(lVar9);
          pcVar12 = "  %s(%s): Callback thread stopped";
          uVar11 = 0;
          thunk_FUN_fffffff00a8df19c
                    (auVar18,param_2,uVar19,uVar21,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff00807b638,0,(byte *)"  %s(%s): Callback thread stopped"
                    );
          param_7[0x22] = 0;
          thunk_FUN_fffffff00a2262a8(param_7[0x1a]);
          *(undefined2 *)(param_7 + 0x21) = 0;
          thunk_FUN_fffffff00a226de0(param_7[0x1a]);
          (**(code **)(*param_7 + 0x28))(param_7);
          thunk_FUN_fffffff00a271cb0((long)plVar14);
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
            thunk_FUN_fffffff00a27628c(plVar14,extraout_x1,uVar11,(undefined **)pcVar12,in_x4);
            return;
          }
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c5be5c);
          (*pcVar6)();
        }
      }
      thunk_FUN_fffffff00a2262a8(param_7[0x2e]);
      plVar14 = (long *)param_7[0x2c];
      if (plVar14 == (long *)0x0) break;
      param_7[0x2c] = *plVar14;
      thunk_FUN_fffffff00a226de0(param_7[0x2e]);
      plVar15 = (long *)plVar14[1];
      iVar7 = FUN_fffffff009c64218((long)plVar15);
      thunk_FUN_fffffff00a2262a8(param_7[0x2a]);
      iVar8 = (**(code **)(*(long *)param_7[0x29] + 0x90))();
      if (iVar8 != 0) {
        iVar16 = 0;
        do {
          plVar10 = (long *)(**(code **)(*(long *)param_7[0x29] + 0x118))
                                      ((long *)param_7[0x29],iVar16);
          plVar10 = thunk_FUN_fffffff00a894f30(plVar10,-0xff50b7548);
          if ((plVar10 != (long *)0x0) && ((int)plVar10[4] == iVar7)) {
            (*(code *)plVar10[2])(plVar10[3],plVar15);
            break;
          }
          iVar16 = iVar16 + 1;
        } while (iVar8 != iVar16);
      }
      thunk_FUN_fffffff00a226de0(param_7[0x2a]);
      FUN_fffffff009c63f2c(plVar15);
      *(int *)((long)param_7 + 0x18c) = *(int *)((long)param_7 + 0x18c) + 1;
      plVar15 = (long *)&DAT_fffffff00807a820;
LAB_fffffff009c5bd38:
      thunk_FUN_fffffff00a22170c(plVar15,plVar14);
    }
    thunk_FUN_fffffff00a226de0(param_7[0x2e]);
    thunk_FUN_fffffff00a2262a8(param_7[0x2f]);
    plVar14 = (long *)param_7[0x2d];
    if (plVar14 != (long *)0x0) {
      param_7[0x2d] = *plVar14;
      thunk_FUN_fffffff00a226de0(param_7[0x2f]);
      plVar15 = (long *)plVar14[1];
      thunk_FUN_fffffff00a2262a8(param_7[0x28]);
      iVar7 = (**(code **)(*(long *)param_7[0x27] + 0x90))();
      if (iVar7 != 0) {
        iVar8 = 0;
        do {
          plVar10 = (long *)(**(code **)(*(long *)param_7[0x27] + 0x118))
                                      ((long *)param_7[0x27],iVar8);
          plVar10 = thunk_FUN_fffffff00a894f30(plVar10,-0xff50b7548);
          if (plVar10 != (long *)0x0) {
            (*(code *)plVar10[2])(plVar10[3],plVar15);
          }
          iVar8 = iVar8 + 1;
        } while (iVar7 != iVar8);
      }
      thunk_FUN_fffffff00a226de0(param_7[0x28]);
      FUN_fffffff009c63f2c(plVar15);
      *(int *)(param_7 + 0x33) = (int)param_7[0x33] + 1;
      plVar15 = (long *)&DAT_fffffff00807a860;
      goto LAB_fffffff009c5bd38;
    }
    thunk_FUN_fffffff00a226de0(param_7[0x2f]);
  } while( true );
}

