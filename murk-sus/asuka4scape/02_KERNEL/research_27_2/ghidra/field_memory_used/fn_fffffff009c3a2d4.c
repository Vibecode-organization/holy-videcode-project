// FUN_fffffff009c3a2d4 @ fffffff009c3a2d4

undefined8
FUN_fffffff009c3a2d4
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long *param_8,
          long param_9,undefined8 param_10)

{
  undefined1 auVar1 [16];
  bool bVar2;
  undefined8 uVar3;
  ulong uVar4;
  long *plVar5;
  long lVar6;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 auVar7 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined1 extraout_q0_05 [16];
  undefined1 extraout_q0_06 [16];
  undefined4 uVar8;
  undefined1 auVar9 [12];
  undefined4 uVar10;
  undefined1 auVar11 [12];
  
  uVar10 = param_4._0_4_;
  auVar11 = param_4._4_12_;
  uVar8 = param_3._0_4_;
  auVar9 = param_3._4_12_;
  uVar3 = (**(code **)(PTR_DAT_fffffff00806ca28 + 0xb8))(param_7,param_10);
  if ((int)uVar3 != 0) {
    uVar3 = thunk_FUN_fffffff00a2706a4(param_9);
    lVar6 = param_9;
    if (param_9 == 0) {
      lVar6 = 0;
    }
    *(long *)(param_7 + 0xf8) = lVar6;
    bVar2 = FUN_fffffff009c3a60c(uVar3,param_9,-0xff87631c2);
    *(bool *)(param_7 + 0x122) = bVar2;
    bVar2 = FUN_fffffff009c3a60c((ulong)bVar2,param_9,-0xff87631a2);
    if (bVar2) {
      uVar4 = 1;
    }
    else {
      bVar2 = FUN_fffffff009c3a60c((ulong)bVar2,param_9,-0xff8763181);
      uVar4 = (ulong)bVar2;
    }
    *(char *)(param_7 + 0x127) = (char)uVar4;
    bVar2 = FUN_fffffff009c3a60c(uVar4,param_9,-0xff876315e);
    *(undefined1 *)(param_7 + 0x123) = 0;
    *(byte *)(param_7 + 0x126) = *(byte *)(param_7 + 0x122) & 1 | bVar2;
    plVar5 = thunk_FUN_fffffff00a894f30(param_8,(long)PTR_DAT_fffffff008067d90);
    *(long **)(param_7 + 0xe8) = plVar5;
    if (plVar5 == (long *)0x0) {
      thunk_FUN_fffffff00a8df19c
                (extraout_q0,param_2,uVar8,uVar10,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff00806ca48,0x11,(byte *)"provider not IOSurfaceRoot\n");
      uVar3 = 0;
    }
    else {
      plVar5 = FUN_fffffff009c418cc(param_9,param_8,*(byte *)(param_7 + 0x126) & 1);
      auVar7 = extraout_q0_00;
      if (*(long **)(param_7 + 0x118) != (long *)0x0) {
        auVar7 = (**(code **)(**(long **)(param_7 + 0x118) + 0x28))();
      }
      *(long **)(param_7 + 0x118) = plVar5;
      if (plVar5 == (long *)0x0) {
        thunk_FUN_fffffff00a8df19c
                  (auVar7,param_2,uVar8,uVar10,param_5,param_6,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff00806ca48,0x11,
                   (byte *)"Cannot allocate IOSurfaceShared\n");
        uVar3 = 0;
      }
      else {
        plVar5 = (long *)FUN_fffffff009c371f8(*(long *)(param_7 + 0xe8));
        auVar7._4_12_ = auVar9;
        auVar7._0_4_ = uVar8;
        auVar1._4_12_ = auVar11;
        auVar1._0_4_ = uVar10;
        lVar6 = thunk_FUN_fffffff00a970b64
                          (extraout_q0_01,param_2,auVar7,auVar1,param_5,param_6,plVar5,param_9,0,
                           (undefined ********)0x1001,(undefined ********)0x0,0);
        auVar7 = extraout_q0_02;
        if (*(long **)(param_7 + 0x138) != (long *)0x0) {
          auVar7 = (**(code **)(**(long **)(param_7 + 0x138) + 0x28))();
        }
        *(long *)(param_7 + 0x138) = lVar6;
        if (lVar6 == 0) {
          thunk_FUN_fffffff00a8df19c
                    (auVar7,param_2,uVar8,uVar10,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff00806ca48,0x11,
                     (byte *)"Cannot map graphics comm page\n");
          uVar3 = 0;
        }
        else {
          plVar5 = thunk_FUN_fffffff00a89a1f4(1);
          auVar7 = extraout_q0_03;
          if (*(long **)(param_7 + 0x100) != (long *)0x0) {
            auVar7 = (**(code **)(**(long **)(param_7 + 0x100) + 0x28))();
          }
          *(long **)(param_7 + 0x100) = plVar5;
          if (plVar5 == (long *)0x0) {
            thunk_FUN_fffffff00a8df19c
                      (auVar7,param_2,uVar8,uVar10,param_5,param_6,&MACH_HEADER,
                       (short *)PTR_DAT_fffffff00806ca48,0x11,
                       (byte *)"Cannot allocate notification array\n");
            uVar3 = 0;
          }
          else {
            plVar5 = thunk_FUN_fffffff00a89a1f4(1);
            auVar7 = extraout_q0_04;
            if (*(long **)(param_7 + 0x140) != (long *)0x0) {
              auVar7 = (**(code **)(**(long **)(param_7 + 0x140) + 0x28))();
            }
            *(long **)(param_7 + 0x140) = plVar5;
            if (plVar5 == (long *)0x0) {
              thunk_FUN_fffffff00a8df19c
                        (auVar7,param_2,uVar8,uVar10,param_5,param_6,&MACH_HEADER,
                         (short *)PTR_DAT_fffffff00806ca48,0x11,
                         (byte *)"Cannot allocate invalidated surface array\n");
              uVar3 = 0;
            }
            else {
              lVar6 = thunk_FUN_fffffff00a903010();
              *(long *)(param_7 + 0xd8) = lVar6;
              if (lVar6 == 0) {
                thunk_FUN_fffffff00a8df19c
                          (extraout_q0_05,param_2,uVar8,uVar10,param_5,param_6,&MACH_HEADER,
                           (short *)PTR_DAT_fffffff00806ca48,0x11,(byte *)"Cannot allocate IOLock\n"
                          );
                uVar3 = 0;
              }
              else {
                lVar6 = thunk_FUN_fffffff00a9033d8();
                *(long *)(param_7 + 0xe0) = lVar6;
                if (lVar6 == 0) {
                  thunk_FUN_fffffff00a8df19c
                            (extraout_q0_06,param_2,uVar8,uVar10,param_5,param_6,&MACH_HEADER,
                             (short *)PTR_DAT_fffffff00806ca48,0x11,
                             (byte *)"Cannot allocate IORWLock\n");
                  uVar3 = 0;
                }
                else {
                  uVar3 = 1;
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar3;
}

