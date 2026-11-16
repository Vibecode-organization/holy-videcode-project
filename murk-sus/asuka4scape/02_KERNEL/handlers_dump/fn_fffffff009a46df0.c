// FUN_fffffff009a46df0 @ fffffff009a46df0 size=884 depth=1
// CALLERS:
//   fffffff00afe7cfb ?
//   fffffff009a1dedc FUN_fffffff009a1ded4
// CALLS:
//   fffffff009a489ac thunk_FUN_fffffff00a1d14a0
//   fffffff009a4804c thunk_FUN_fffffff00a902580
//   fffffff0099cb890 FUN_fffffff0099cb890
//   fffffff009a483ac thunk_FUN_fffffff00a912bc0
//   fffffff009a4815c thunk_FUN_fffffff00a8d8754
//   fffffff009a4881c thunk_FUN_fffffff00a8df19c
//   fffffff009a483bc thunk_FUN_fffffff00a894f30
//   fffffff0099cd400 FUN_fffffff0099cd400
//   fffffff0099cd448 FUN_fffffff0099cd448
//   fffffff0099f0cd4 FUN_fffffff0099f0cd4
//   fffffff009a1eb14 FUN_fffffff009a1eb14
//   fffffff009a1e974 FUN_fffffff009a1e974
//   fffffff009a47fdc thunk_FUN_fffffff00a9026b0

undefined8
FUN_fffffff009a46df0
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,long param_8,
          undefined **param_9,char *param_10,undefined *param_11)

{
  undefined8 *puVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  bool bVar5;
  long *plVar6;
  ulong *puVar7;
  undefined **extraout_x0;
  ulong *puVar8;
  undefined ******ppppppuVar9;
  long *plVar10;
  short *psVar11;
  mach_header *pmVar12;
  long extraout_x16;
  long extraout_x16_00;
  undefined8 uVar13;
  undefined8 *puVar14;
  undefined8 uVar15;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 auVar16 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined4 uVar17;
  undefined1 auVar18 [12];
  undefined4 uVar19;
  undefined1 auVar20 [12];
  
  uVar19 = param_4._0_4_;
  auVar20 = param_4._4_12_;
  uVar17 = param_3._0_4_;
  auVar18 = param_3._4_12_;
  uVar13 = 0xe00002c9;
  uVar15 = uVar13;
  if (param_7[0x1d] == 0) {
    plVar6 = FUN_fffffff009a1e974(param_7,param_8);
    uVar15 = 0xe00002bd;
    if (plVar6 != (long *)0x0) {
      puVar7 = (ulong *)(**(code **)(*plVar6 + 0xb0))();
      if (puVar7 == (ulong *)0x0) {
        uVar15 = 0xe00002be;
      }
      else {
        auVar16._4_12_ = auVar18;
        auVar16._0_4_ = uVar17;
        auVar3._4_12_ = auVar20;
        auVar3._0_4_ = uVar19;
        thunk_FUN_fffffff00a902580(extraout_q0,param_2,auVar16,auVar3,param_5,param_6,puVar7);
        if (extraout_x0 != (undefined **)0x0) {
          uVar15 = (**(code **)(*plVar6 + 0xd8))(plVar6,0);
          auVar16 = extraout_q0_00;
          if ((int)uVar15 == 0) {
            param_9 = extraout_x0;
            param_10 = (char *)puVar7;
            (**(code **)(*plVar6 + 200))(plVar6,0);
            (**(code **)(*plVar6 + 0xe0))(plVar6,0);
            puVar8 = (ulong *)thunk_FUN_fffffff00a1d14a0((ulong)extraout_x0,(long)puVar7);
            uVar15 = uVar13;
            auVar16 = extraout_q0_01;
            if (puVar8 < puVar7) {
              param_9 = (undefined **)0x0;
              ppppppuVar9 = thunk_FUN_fffffff00a8d8754
                                      ((char *)extraout_x0,(ulong)puVar7,(undefined8 *)0x0);
              if (ppppppuVar9 == (undefined ******)0x0) {
                psVar11 = (short *)FUN_fffffff0099cb890(0);
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                thunk_FUN_fffffff00a912bc0((long)param_7);
                pmVar12 = FUN_fffffff0099cd448();
                param_10 = "%s:0x%llx OSUnserializeXML:NULL\n\n";
                param_9 = (undefined **)&DAT_00000010;
                auVar16 = thunk_FUN_fffffff00a8df19c
                                    (extraout_q0_02,param_2,uVar17,uVar19,param_5,param_6,pmVar12,
                                     psVar11,0x10,(byte *)"%s:0x%llx OSUnserializeXML:NULL\n\n");
              }
              else {
                if ((long *)param_7[0x1c] != (long *)0x0) {
                  (**(code **)(*(long *)param_7[0x1c] + 0x28))();
                }
                param_7[0x1c] = 0;
                plVar10 = thunk_FUN_fffffff00a894f30
                                    ((long *)ppppppuVar9,*(long *)PTR_PTR_fffffff008017358);
                param_7[0x1c] = (long)plVar10;
                if (plVar10 == (long *)0x0) {
                  psVar11 = (short *)FUN_fffffff0099cb890(0);
                  (**(code **)(*param_7 + 0x1e8))(param_7,0);
                  thunk_FUN_fffffff00a912bc0((long)param_7);
                  pmVar12 = FUN_fffffff0099cd448();
                  param_10 = "%s:0x%llx properties is not OSDictionary\n\n";
                  param_9 = (undefined **)&DAT_00000010;
                  thunk_FUN_fffffff00a8df19c
                            (extraout_q0_03,param_2,uVar17,uVar19,param_5,param_6,pmVar12,psVar11,
                             0x10,(byte *)"%s:0x%llx properties is not OSDictionary\n\n");
                }
                else {
                  FUN_fffffff0099cd400();
                  (**(code **)(extraout_x16 + 0x20))();
                  bVar5 = FUN_fffffff0099f0cd4((long *)param_7[0x1c]);
                  if (bVar5) {
                    uVar13 = 0xe00002c2;
                  }
                  else {
                    puVar14 = *(undefined8 **)PTR_PTR_fffffff008017468;
                    puVar1 = *(undefined8 **)PTR_PTR_fffffff008017470;
                    if ((*(byte *)((long)param_7 + 0x16d) & 1) == 0) {
                      puVar1 = puVar14;
                    }
                    param_9 = (undefined **)*puVar1;
                    uVar15 = FUN_fffffff0099cd400();
                    auVar16 = (**(code **)(extraout_x16_00 + 0x100))(uVar15,"Privileged");
                    if ((**(byte **)(param_8 + 0x20) & 1) != 0) {
                      param_9 = (undefined **)*puVar14;
                      auVar16 = (**(code **)(*(long *)param_7[0x1c] + 0x100))
                                          ((long *)param_7[0x1c],"RegisterService");
                    }
                    *(undefined1 *)((long)param_7 + 0x16c) = 1;
                    auVar2._4_12_ = auVar18;
                    auVar2._0_4_ = uVar17;
                    auVar4._4_12_ = auVar20;
                    auVar4._0_4_ = uVar19;
                    uVar13 = FUN_fffffff009a1eb14
                                       (auVar16,param_2,auVar2,auVar4,param_5,param_6,(long)param_7)
                    ;
                  }
                }
                auVar16 = (*(code *)(*ppppppuVar9)[5])(ppppppuVar9);
                uVar15 = uVar13;
              }
            }
          }
          thunk_FUN_fffffff00a9026b0
                    (auVar16,param_2,uVar17,uVar19,param_5,param_6,extraout_x0,(undefined *)puVar7,
                     param_9,param_10,param_11);
        }
      }
      (**(code **)(*plVar6 + 0x28))(plVar6);
    }
  }
  return uVar15;
}

