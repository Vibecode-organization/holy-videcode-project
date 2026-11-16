// FUN_fffffff009cb93ac @ fffffff009cb93ac

/* WARNING: Removing unreachable block (ram,0xfffffff009cb9fe8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb9bf0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb9dac) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb9cb0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb99f4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb9ef8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb9514) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cba04c) */

void FUN_fffffff009cb93ac
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               long *param_8,ulong param_9,char *param_10)

{
  uint *puVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  bool bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  long *plVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  char *pcVar12;
  long *extraout_x0;
  char *pcVar13;
  undefined8 extraout_x1;
  ulong uVar14;
  ulong uVar15;
  short *psVar16;
  char *pcVar17;
  long lVar18;
  ulong uVar19;
  undefined1 extraout_q0 [16];
  undefined1 auVar20 [16];
  undefined4 uVar21;
  undefined1 auVar22 [12];
  undefined4 uVar23;
  undefined1 auVar24 [12];
  
  uVar23 = param_4._0_4_;
  auVar24 = param_4._4_12_;
  uVar21 = param_3._0_4_;
  auVar22 = param_3._4_12_;
  uVar6 = *(uint *)((long)param_7 + 500);
  uVar14 = param_9;
  pcVar13 = param_10;
  if ((int)param_7[0x4c7] == 0) {
    if ((uVar6 >> 2 & 1) != 0) {
      if (((uVar6 >> 0x1e & 1) == 0) || (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
        psVar16 = *(short **)PTR_DAT_fffffff008081388;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar20 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        pcVar13 = "%s@%s: %s::%s: Applying tunable tag \'%s\' (block offset 0x%08x)\n";
        uVar14 = 0;
        thunk_FUN_fffffff00a8df19c
                  (auVar20,param_2,uVar21,uVar23,param_5,param_6,&MACH_HEADER,psVar16,0,
                   (byte *)"%s@%s: %s::%s: Applying tunable tag \'%s\' (block offset 0x%08x)\n");
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)"%s@%s: %s::%s: Applying tunable tag \'%s\' (block offset 0x%08x)\n");
      }
    }
  }
  else if ((uVar6 >> 2 & 1) != 0) {
    FUN_fffffff009cacb28
              ((ulong)param_7,
               (byte *)"AppleUSBXDCI::%s:Applying tunable tag \'%s\' (block offset 0x%08x)\n");
  }
  plVar8 = (long *)(**(code **)(*(long *)param_7[0x17] + 0x118))((long *)param_7[0x17],param_10);
  plVar8 = thunk_FUN_fffffff00a894f30(plVar8,*(long *)PTR_PTR_fffffff008081398);
  if ((plVar8 == (long *)0x0) ||
     (iVar5 = (**(code **)(*plVar8 + 0xa0))(),
     0x15555555 < ((uint)(iVar5 * -0x55555555) >> 2 | iVar5 * -0x40000000))) {
    uVar6 = *(uint *)((long)param_7 + 500);
    if ((int)param_7[0x4c7] == 0) {
      if ((uVar6 >> 2 & 1) == 0) {
        return;
      }
      if (((uVar6 >> 0x1e & 1) == 0) || (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
        psVar16 = *(short **)PTR_DAT_fffffff008081388;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar20 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar20,param_2,uVar21,uVar23,param_5,param_6,&MACH_HEADER,psVar16,0,
                   (byte *)"%s@%s: %s::%s: Tag not in device tree, continuing\n");
        return;
      }
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      pcVar13 = "%s@%s: %s::%s: Tag not in device tree, continuing\n";
      goto LAB_fffffff009cb96ac;
    }
    if ((uVar6 >> 2 & 1) == 0) {
      return;
    }
    pcVar13 = "AppleUSBXDCI::%s:Tag not in device tree, continuing\n";
  }
  else {
    uVar6 = (**(code **)(*plVar8 + 0xa0))(plVar8);
    lVar9 = (**(code **)(*plVar8 + 0xd8))(plVar8);
    if (param_8 != (long *)0x0) {
      lVar10 = (**(code **)(*param_8 + 0x78))(param_8);
      uVar11 = (**(code **)(*param_8 + 0x88))(param_8);
      if ((lVar10 != 0) && (uVar11 != 0)) {
        if (uVar6 < 0xc) {
          return;
        }
        lVar18 = 0;
        uVar15 = (ulong)uVar6 / 0xc;
        do {
          puVar1 = (uint *)(lVar9 + lVar18 * 0xc);
          uVar19 = uVar14;
          pcVar17 = pcVar13;
          if ((*puVar1 >> 0x1b < 0x1f) && (iVar5 = *puVar1 * 0x20, iVar5 != -0x20)) {
            uVar6 = (int)param_9 + (iVar5 >> 5);
            uVar19 = (ulong)uVar6;
            if (uVar6 < 0xfffffffc && uVar6 + 4 <= uVar11) {
              uVar14 = uVar19;
              uVar7 = (**(code **)(*param_7 + 0x818))(param_7,lVar10,uVar19);
              uVar6 = uVar7 & (puVar1[1] ^ 0xffffffff) | puVar1[2];
              pcVar17 = (char *)(ulong)uVar6;
              if (uVar7 == uVar6) {
                uVar6 = *(uint *)((long)param_7 + 500);
                uVar19 = uVar14;
                pcVar17 = pcVar13;
                if ((int)param_7[0x4c7] == 0) {
                  if ((uVar6 >> 3 & 1) != 0) {
                    if (((uVar6 >> 0x1e & 1) == 0) || (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)
                       ) {
                      psVar16 = *(short **)PTR_DAT_fffffff008081388;
                      (**(code **)(*param_7 + 0x1e8))(param_7,0);
                      auVar20 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                      uVar19 = 0;
                      pcVar17 = 
                      "%s@%s: %s::%s: tunable offset 0x%08x mask 0x%08x value 0x%08x already set (read 0x%08x)\n"
                      ;
                      thunk_FUN_fffffff00a8df19c
                                (auVar20,param_2,uVar21,uVar23,param_5,param_6,&MACH_HEADER,psVar16,
                                 0,(byte *)
                                   "%s@%s: %s::%s: tunable offset 0x%08x mask 0x%08x value 0x%08x already set (read 0x%08x)\n"
                                );
                    }
                    else {
                      (**(code **)(*param_7 + 0x1e8))(param_7,0);
                      (**(code **)(*param_7 + 0x218))(param_7,0);
                      pcVar12 = 
                      "%s@%s: %s::%s: tunable offset 0x%08x mask 0x%08x value 0x%08x already set (read 0x%08x)\n"
                      ;
                      uVar19 = uVar14;
                      pcVar17 = pcVar13;
LAB_fffffff009cb9b90:
                      thunk_FUN_fffffff00a9029a0((byte *)pcVar12);
                    }
                  }
                }
                else if ((uVar6 >> 3 & 1) != 0) {
                  pcVar13 = 
                  "AppleUSBXDCI::%s:tunable offset 0x%08x mask 0x%08x value 0x%08x already set (read 0x%08x)\n"
                  ;
LAB_fffffff009cb98ec:
                  FUN_fffffff009cacb28((ulong)param_7,(byte *)pcVar13);
                }
              }
              else {
                (**(code **)(*param_7 + 0x820))(param_7,lVar10,uVar19,pcVar17);
                uVar6 = *(uint *)((long)param_7 + 500);
                if ((int)param_7[0x4c7] == 0) {
                  if ((uVar6 >> 3 & 1) != 0) {
                    if (((uVar6 >> 0x1e & 1) != 0) && (bVar4 = thunk_FUN_fffffff00a394140(), bVar4))
                    {
                      (**(code **)(*param_7 + 0x1e8))(param_7,0);
                      (**(code **)(*param_7 + 0x218))(param_7,0);
                      pcVar12 = 
                      "%s@%s: %s::%s: tunable offset 0x%08x mask 0x%08x value 0x%08x (read 0x%08x wrote 0x%08x)\n"
                      ;
                      goto LAB_fffffff009cb9b90;
                    }
                    psVar16 = *(short **)PTR_DAT_fffffff008081388;
                    (**(code **)(*param_7 + 0x1e8))(param_7,0);
                    auVar20 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                    uVar19 = 0;
                    pcVar17 = 
                    "%s@%s: %s::%s: tunable offset 0x%08x mask 0x%08x value 0x%08x (read 0x%08x wrote 0x%08x)\n"
                    ;
                    thunk_FUN_fffffff00a8df19c
                              (auVar20,param_2,uVar21,uVar23,param_5,param_6,&MACH_HEADER,psVar16,0,
                               (byte *)
                               "%s@%s: %s::%s: tunable offset 0x%08x mask 0x%08x value 0x%08x (read 0x%08x wrote 0x%08x)\n"
                              );
                  }
                }
                else if ((uVar6 >> 3 & 1) != 0) {
                  pcVar13 = 
                  "AppleUSBXDCI::%s:tunable offset 0x%08x mask 0x%08x value 0x%08x (read 0x%08x wrote 0x%08x)\n"
                  ;
                  goto LAB_fffffff009cb98ec;
                }
              }
            }
            else if ((int)param_7[0x4c7] == 0) {
              if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
                 (bVar4 = thunk_FUN_fffffff00a394140(), bVar4)) {
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                (**(code **)(*param_7 + 0x218))(param_7,0);
                thunk_FUN_fffffff00a9029a0
                          ((byte *)"%s@%s: %s::%s: offset 0x%08x invalid (rangeLength 0x%08llx)\n");
                auVar20 = extraout_q0;
              }
              else {
                psVar16 = *(short **)PTR_DAT_fffffff008081388;
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                auVar20 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                uVar14 = 0x11;
                pcVar13 = "%s@%s: %s::%s: offset 0x%08x invalid (rangeLength 0x%08llx)\n";
                auVar20 = thunk_FUN_fffffff00a8df19c
                                    (auVar20,param_2,uVar21,uVar23,param_5,param_6,&MACH_HEADER,
                                     psVar16,0x11,
                                     (byte *)
                                     "%s@%s: %s::%s: offset 0x%08x invalid (rangeLength 0x%08llx)\n"
                                    );
              }
              uVar19 = uVar14;
              pcVar17 = pcVar13;
              if (*(int *)((long)param_7 + 500) < 0) {
                auVar2._4_12_ = auVar22;
                auVar2._0_4_ = uVar21;
                auVar3._4_12_ = auVar24;
                auVar3._0_4_ = uVar23;
                FUN_fffffff009cc8894(auVar20,param_2,auVar2,auVar3,param_5,param_6);
                plVar8 = (long *)(**(code **)(*(long *)extraout_x0[0x17] + 0x3d0))
                                           ((long *)extraout_x0[0x17],extraout_x1,0);
                (**(code **)(*extraout_x0 + 0x888))
                          (*extraout_x0 + 0x888,extraout_x0,plVar8,uVar14,pcVar13);
                if (plVar8 == (long *)0x0) {
                  return;
                }
                    /* WARNING: Could not recover jumptable at 0xfffffff009cba058. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
                (**(code **)(*plVar8 + 0x28))(plVar8,(undefined8 *)(*plVar8 + 0x28));
                return;
              }
            }
            else {
              uVar19 = uVar14;
              if ((*(uint *)((long)param_7 + 500) & 0x80000001) != 0) {
                pcVar13 = "AppleUSBXDCI::%s:offset 0x%08x invalid (rangeLength 0x%08llx)\n";
                goto LAB_fffffff009cb98ec;
              }
            }
          }
          lVar18 = lVar18 + 1;
          uVar15 = uVar15 - 1;
          uVar14 = uVar19;
          pcVar13 = pcVar17;
          if (uVar15 == 0) {
            return;
          }
        } while( true );
      }
    }
    uVar6 = *(uint *)((long)param_7 + 500);
    if ((int)param_7[0x4c7] == 0) {
      if ((uVar6 & 1) == 0) {
        return;
      }
      if (((uVar6 >> 0x1e & 1) == 0) || (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
        psVar16 = *(short **)PTR_DAT_fffffff008081388;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar20 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar20,param_2,uVar21,uVar23,param_5,param_6,&MACH_HEADER,psVar16,0,
                   (byte *)"%s@%s: %s::%s: Failed to apply tunable tag \'%s\'\n");
        return;
      }
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      pcVar13 = "%s@%s: %s::%s: Failed to apply tunable tag \'%s\'\n";
LAB_fffffff009cb96ac:
      thunk_FUN_fffffff00a9029a0((byte *)pcVar13);
      return;
    }
    if ((uVar6 & 1) == 0) {
      return;
    }
    pcVar13 = "AppleUSBXDCI::%s:Failed to apply tunable tag \'%s\'\n";
  }
  FUN_fffffff009cacb28((ulong)param_7,(byte *)pcVar13);
  return;
}

