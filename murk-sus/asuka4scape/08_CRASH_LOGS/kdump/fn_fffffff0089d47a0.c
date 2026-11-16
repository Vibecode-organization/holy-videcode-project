// FUN_fffffff0089d47a0 @ fffffff0089d47a0 size=3284
// CALLERS:
//   fffffff00afcc9e0 ?
//   fffffff0089d468c FUN_fffffff0089d45d4@fffffff0089d45d4
//   fffffff0089d46ec FUN_fffffff0089d45d4@fffffff0089d45d4
// CALLS:
//   fffffff0089c46cc FUN_fffffff0089c46cc
//   fffffff0089950d8 FUN_fffffff0089950d8
//   fffffff008a81ed4 thunk_FUN_fffffff00a8df19c
//   fffffff0089e9820 FUN_fffffff0089e9820
//   fffffff0089e946c FUN_fffffff0089e946c
//   fffffff0089aa9f8 FUN_fffffff0089aa9f8
//   fffffff0089ca398 FUN_fffffff0089ca398
//   fffffff008a81534 thunk_FUN_fffffff00a903214
//   fffffff0089c46a4 FUN_fffffff0089c46a4
//   fffffff008a82064 thunk_FUN_fffffff00a6de494
//   fffffff008a7b884 FUN_fffffff008a7b884
//   fffffff0089b2b80 FUN_fffffff0089b2b80
//   fffffff0089682d8 FUN_fffffff0089682d8
//   fffffff008a81574 thunk_FUN_fffffff00a9032e0

/* WARNING: Removing unreachable block (ram,0xfffffff0089d52fc) */

ulong FUN_fffffff0089d47a0
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                long *param_8)

{
  uint *puVar1;
  byte *pbVar2;
  long *plVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined *puVar24;
  ulong uVar25;
  long lVar26;
  bool bVar27;
  long *plVar28;
  ulong uVar29;
  undefined8 uVar30;
  char *pcVar31;
  undefined *puVar32;
  undefined8 uVar33;
  ulong in_x6;
  ulong uVar34;
  long lVar35;
  long lVar36;
  ulong uVar37;
  ulong uVar38;
  long *plVar39;
  int *piVar40;
  undefined8 extraout_d0;
  undefined8 extraout_d0_05;
  undefined8 extraout_d0_06;
  undefined8 extraout_d0_00;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined1 auVar43 [16];
  undefined8 extraout_d0_03;
  undefined8 extraout_d0_04;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  undefined1 auVar44 [16];
  undefined8 extraout_var_05;
  undefined8 extraout_var_06;
  undefined4 uVar45;
  undefined1 auVar46 [12];
  undefined4 uVar47;
  undefined1 auVar48 [12];
  long *local_d0;
  long *local_c8;
  ulong local_c0;
  long *plStack_b8;
  ulong local_b0;
  long *plStack_a8;
  long local_98;
  long *local_90;
  long local_88;
  long *local_80;
  undefined8 local_78;
  long *local_70;
  
  uVar47 = param_4._0_4_;
  auVar48 = param_4._4_12_;
  uVar45 = param_3._0_4_;
  auVar46 = param_3._4_12_;
  local_78 = 0;
  local_70 = (long *)0x0;
  local_88 = 0;
  local_80 = (long *)0x0;
  local_98 = 0;
  local_90 = (long *)0x0;
  bVar27 = FUN_fffffff0089aa9f8
                     (param_1,param_2,uVar45,uVar47,param_5,param_6,*(long *)(param_7 + 0x80),
                      *(ulong *)(*param_8 + 0x1090),&local_78);
  if (bVar27) {
    FUN_fffffff0089ca398(param_7,*(long *)(*param_8 + 0x1098),&local_88,&local_98);
    lVar26 = local_88;
    lVar35 = local_98;
    auVar23._8_8_ = extraout_var_00;
    auVar23._0_8_ = extraout_d0_00;
    auVar41._8_8_ = extraout_var_00;
    auVar41._0_8_ = extraout_d0_00;
    if ((local_88 != 0) && (local_98 != 0)) {
      uVar34 = (ulong)*(uint *)(*param_8 + 0x10a4);
      if ((*(byte *)(local_98 + 0x5e1) & 1) == 0) {
        if (0xff < *(uint *)(*param_8 + 0x10a4)) {
          uVar37 = 0xe00002c2;
          auVar9._8_8_ = extraout_var_00;
          auVar9._0_8_ = extraout_d0_00;
          thunk_FUN_fffffff00a8df19c
                    (auVar9,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff007ddeaa8,0x10,
                     (byte *)
                     "[ERROR] %s: %s: invalid procedure Id: %u for processInstance programHandle: 0x%llx\n"
                    );
          goto LAB_fffffff0089d4994;
        }
        lVar36 = uVar34 * 4;
        puVar1 = (uint *)(local_98 + 0x1d0 + (long)(int)lVar36);
        if (lVar36 - (int)lVar36 != 0) {
          puVar1 = (uint *)(local_98 + 0x1d0 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar34 = (ulong)*puVar1;
        auVar41 = auVar23;
        if ((DAT_fffffff00ae430b1 >> 2 & 1) != 0) {
          auVar8._8_8_ = extraout_var_00;
          auVar8._0_8_ = extraout_d0_00;
          auVar41 = thunk_FUN_fffffff00a8df19c
                              (auVar8,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
                               (short *)PTR_DAT_fffffff007ddeaa8,0,
                               (byte *)
                               "%s: %s: logical procedure Id: %u mapped to Id: %u for processInstance programHandle: 0x%llx\n"
                              );
        }
      }
      if ((uint)uVar34 < *(uint *)(lVar26 + 0x1fec)) {
        if ((DAT_fffffff00ae430b1 >> 2 & 1) != 0) {
          auVar41 = thunk_FUN_fffffff00a8df19c
                              (auVar41,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
                               (short *)PTR_DAT_fffffff007ddeaa8,0,
                               (byte *)"%s: %s: Procedure name %s found!\n");
        }
      }
      else {
        if (*(uint *)(lVar26 + 0x1fec) != 1) {
          uVar37 = 0xe00002c2;
          thunk_FUN_fffffff00a8df19c
                    (auVar41,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff007ddeaa8,0x10,
                     (byte *)"[ERROR] %s: %s: programHandle: 0x%llx, procedureId: %u not found!\n");
          goto LAB_fffffff0089d4994;
        }
        if ((DAT_fffffff00ae430b1 >> 2 & 1) == 0) {
          uVar34 = 0;
        }
        else {
          auVar41 = thunk_FUN_fffffff00a8df19c
                              (auVar41,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
                               (short *)PTR_DAT_fffffff007ddeaa8,0,
                               (byte *)
                               "%s: %s: Single procedure case: Defaulting to procedure 0: %s\n");
          uVar34 = 0;
        }
      }
      lVar36 = uVar34 * 0xb40 + 0xa4c;
      pbVar2 = (byte *)(*(long *)(lVar26 + 0x1ff0) + (long)(int)lVar36);
      if (lVar36 != (int)lVar36) {
        pbVar2 = (byte *)(*(long *)(lVar26 + 0x1ff0) + lVar36 & 0xffffffffffffU | 0x2bad000000000000
                         );
      }
      if ((*pbVar2 & 1) == 0) {
        lVar36 = *(long *)(lVar35 + 0x98);
        plVar3 = *(long **)(lVar35 + 0xa0);
        if (plVar3 != (long *)0x0) {
          auVar41 = FUN_fffffff0089c46a4((long)plVar3);
        }
        pcVar31 = (char *)0x0;
        puVar32 = (undefined *)0x0;
        uVar33 = 0;
        auVar42 = thunk_FUN_fffffff00a6de494
                            (auVar41,param_2,uVar45,uVar47,param_5,param_6,0x61b0109,
                             *(long *)(*param_8 + 0x1098),uVar34,0,0);
        if ((DAT_fffffff00ae430b1 >> 2 & 1) != 0) {
          FUN_fffffff0089950d8(lVar36);
          pcVar31 = 
          "%s: %s: programHandle: 0x%llx, programId: %u, processId: %u, procedureId %u, bufferCount: %u, numCachedResources: %u\n"
          ;
          auVar10._8_8_ = extraout_var_01;
          auVar10._0_8_ = extraout_d0_01;
          auVar42 = thunk_FUN_fffffff00a8df19c
                              (auVar10,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
                               (short *)PTR_DAT_fffffff007ddeaa8,0,
                               (byte *)
                               "%s: %s: programHandle: 0x%llx, programId: %u, processId: %u, procedureId %u, bufferCount: %u, numCachedResources: %u\n"
                              );
        }
        lVar35 = *param_8;
        if (*(int *)(lVar35 + 0x10a0) != 0) {
          uVar37 = 0;
          do {
            piVar40 = (int *)(lVar35 + 0xa0U + uVar37 * 0x10);
            if (((lVar35 + 0xa0U ^ (ulong)piVar40) & 0xffc0000000000000) != 0) {
              piVar40 = (int *)((ulong)piVar40 & 0xffffffffffff | 0xc8a2000000000000);
            }
            if ((DAT_fffffff00ae430b1 >> 2 & 1) != 0) {
              auVar42 = thunk_FUN_fffffff00a8df19c
                                  (auVar42,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
                                   (short *)PTR_DAT_fffffff007ddeaa8,0,
                                   (byte *)
                                   "%s: %s: programHandle: 0x%llx, usageType: %d, symbolIndex: %u, surfaceId: %u\n"
                                  );
            }
            uVar4 = piVar40[3];
            uVar5 = piVar40[1];
            if (uVar4 == 2) {
              if (*(uint *)(lVar26 + 0x1fe8) <= uVar5) {
                uVar37 = 0xe00002c2;
                thunk_FUN_fffffff00a8df19c
                          (auVar42,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
                           (short *)PTR_DAT_fffffff007ddeaa8,0x10,
                           (byte *)
                           "[ERROR] %s: %s: Invalid output symbol index: %u. Total outputs for model: %u\n"
                          );
                goto LAB_fffffff0089d535c;
              }
            }
            else if ((uVar4 == 1) && (*(uint *)(lVar26 + 0x1fa0) <= uVar5)) {
              uVar37 = 0xe00002c2;
              thunk_FUN_fffffff00a8df19c
                        (auVar42,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
                         (short *)PTR_DAT_fffffff007ddeaa8,0x10,
                         (byte *)
                         "[ERROR] %s: %s: Invalid input symbol index: %u. Total inputs for model: %u\n"
                        );
              goto LAB_fffffff0089d535c;
            }
            pcVar31 = (char *)FUN_fffffff0089682d8
                                        (auVar42,param_2,uVar45,uVar47,param_5,param_6,(ulong)uVar4,
                                         lVar26 + 0x1f58,uVar5);
            local_b0 = 0;
            plStack_a8 = (long *)0x0;
            uVar29 = (ulong)(uint)piVar40[1];
            auVar11._8_8_ = extraout_var_02;
            auVar11._0_8_ = extraout_d0_02;
            auVar42 = FUN_fffffff008a7b884
                                ((long *)&local_b0,auVar11,param_2,uVar45,uVar47,param_5,param_6,
                                 lVar36,*piVar40,piVar40[1],(int)pcVar31);
            plVar39 = plStack_a8;
            uVar25 = local_b0;
            if (local_b0 == 0) {
              if ((DAT_fffffff00ae430b1 >> 2 & 1) != 0) {
                pcVar31 = 
                "%s: %s: WARN: No resource in the buffer cache for programHandle: 0x%llx, surfaceId: %u, type: %d, symbolIndex: %u. Skipping\n"
                ;
                auVar42 = thunk_FUN_fffffff00a8df19c
                                    (auVar42,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
                                     (short *)PTR_DAT_fffffff007ddeaa8,0,
                                     (byte *)
                                     "%s: %s: WARN: No resource in the buffer cache for programHandle: 0x%llx, surfaceId: %u, type: %d, symbolIndex: %u. Skipping\n"
                                    );
              }
            }
            else {
              if (plStack_a8 != (long *)0x0) {
                auVar42 = FUN_fffffff0089c46a4((long)plStack_a8);
              }
              uVar38 = *(ulong *)(uVar25 + 0x170);
              if (uVar38 != 0) {
                auVar42 = thunk_FUN_fffffff00a903214(uVar38);
              }
              if (*(int *)(uVar25 + 0x274) == 0) {
                bVar27 = true;
              }
              else {
                iVar6 = *(int *)(uVar25 + 0x274) + -1;
                bVar27 = iVar6 == 0;
                *(int *)(uVar25 + 0x274) = iVar6;
              }
              if (uVar38 != 0) {
                auVar42 = thunk_FUN_fffffff00a9032e0(uVar38);
              }
              if (bVar27) {
                lVar35 = *param_8;
                plStack_b8 = plStack_a8;
                local_c0 = local_b0;
                auVar43._8_8_ = 0;
                auVar43._0_8_ = local_b0;
                if (plStack_a8 != (long *)0x0) {
                  auVar43 = FUN_fffffff0089c46a4((long)plStack_a8);
                }
                auVar15._4_12_ = auVar46;
                auVar15._0_4_ = uVar45;
                auVar19._4_12_ = auVar48;
                auVar19._0_4_ = uVar47;
                FUN_fffffff0089e9820
                          (auVar43,param_2,auVar15,auVar19,param_5,param_6,lVar35,(long *)&local_c0,
                           uVar29,pcVar31,puVar32);
                auVar42._8_8_ = extraout_var_03;
                auVar42._0_8_ = extraout_d0_03;
                if (plStack_b8 != (long *)0x0) {
                  auVar42 = FUN_fffffff0089c46cc(plStack_b8);
                }
              }
              else if ((DAT_fffffff00ae430b1 >> 2 & 1) != 0) {
                pcVar31 = 
                "%s: %s: Resource still prewired (prewireCount > 0), skipping unwire for programHandle: 0x%llx, surfaceId: %u\n"
                ;
                auVar42 = thunk_FUN_fffffff00a8df19c
                                    (auVar42,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
                                     (short *)PTR_DAT_fffffff007ddeaa8,0,
                                     (byte *)
                                     "%s: %s: Resource still prewired (prewireCount > 0), skipping unwire for programHandle: 0x%llx, surfaceId: %u\n"
                                    );
              }
              if (plVar39 != (long *)0x0) {
                auVar42 = FUN_fffffff0089c46cc(plVar39);
              }
            }
            if (plStack_a8 != (long *)0x0) {
              auVar42 = FUN_fffffff0089c46cc(plStack_a8);
            }
            uVar37 = uVar37 + 1;
            lVar35 = *param_8;
          } while (uVar37 < *(uint *)(lVar35 + 0x10a0));
        }
        local_b0 = 0;
        plStack_a8 = (long *)0x0;
        uVar30 = 1;
        auVar16._4_12_ = auVar46;
        auVar16._0_4_ = uVar45;
        auVar20._4_12_ = auVar48;
        auVar20._0_4_ = uVar47;
        FUN_fffffff0089e946c
                  (&local_b0,auVar42,param_2,auVar16,auVar20,param_5,param_6,
                   *(long *)(param_7 + 0x10),*(long *)(param_7 + 0x88),1,pcVar31,puVar32);
        puVar24 = PTR_DAT_fffffff007ddeaa8;
        auVar44._8_8_ = extraout_var_04;
        auVar44._0_8_ = extraout_d0_04;
        if (local_b0 == 0) {
          auVar12._8_8_ = extraout_var_04;
          auVar12._0_8_ = extraout_d0_04;
          thunk_FUN_fffffff00a8df19c
                    (auVar12,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff007ddeaa8,0x10,
                     (byte *)"[ERROR] %s: %s: Failed to allocate unwireRequest\n");
          uVar37 = 0xe00002bd;
        }
        else {
          plVar39 = *(long **)(*(long *)(*param_8 + 0x98) + 0x20);
          if (plVar39 != (long *)0x0) {
            do {
              plVar28 = (long *)plVar39[2];
              if ((int)plVar28[6] != 2) {
                if ((DAT_fffffff00ae430b1 >> 2 & 1) != 0) {
                  auVar13 = (**(code **)(*plVar28 + 0x30))();
                  uVar30 = 0;
                  pcVar31 = "%s: %s: Unwiring resource: resourceid: 0x%llx\n";
                  auVar44 = thunk_FUN_fffffff00a8df19c
                                      (auVar13,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
                                       (short *)puVar24,0,
                                       (byte *)"%s: %s: Unwiring resource: resourceid: 0x%llx\n");
                  plVar28 = (long *)plVar39[2];
                }
                uVar37 = local_b0;
                local_c8 = (long *)plVar39[3];
                local_d0 = plVar28;
                if (local_c8 != (long *)0x0) {
                  auVar44 = FUN_fffffff0089c46a4((long)local_c8);
                }
                auVar17._4_12_ = auVar46;
                auVar17._0_4_ = uVar45;
                auVar21._4_12_ = auVar48;
                auVar21._0_4_ = uVar47;
                FUN_fffffff0089e9820
                          (auVar44,param_2,auVar17,auVar21,param_5,param_6,uVar37,(long *)&local_d0,
                           uVar30,pcVar31,puVar32);
                auVar44._8_8_ = extraout_var_05;
                auVar44._0_8_ = extraout_d0_05;
                if (local_c8 != (long *)0x0) {
                  auVar44 = FUN_fffffff0089c46cc(local_c8);
                }
              }
              plVar39 = (long *)*plVar39;
            } while (plVar39 != (long *)0x0);
          }
          auVar18._4_12_ = auVar46;
          auVar18._0_4_ = uVar45;
          auVar22._4_12_ = auVar48;
          auVar22._0_4_ = uVar47;
          uVar37 = FUN_fffffff0089b2b80
                             (auVar44,param_2,auVar18,auVar22,param_5,param_6,
                              *(long *)(param_7 + 0x88),&local_b0,uVar30,pcVar31,puVar32,uVar33,
                              in_x6);
          auVar14._8_8_ = extraout_var_06;
          auVar14._0_8_ = extraout_d0_06;
          thunk_FUN_fffffff00a6de494
                    (auVar14,param_2,uVar45,uVar47,param_5,param_6,0x61b010a,
                     *(long *)(*param_8 + 0x1098),uVar34,0,0);
        }
        if (plStack_a8 != (long *)0x0) {
          FUN_fffffff0089c46cc(plStack_a8);
        }
LAB_fffffff0089d535c:
        if (plVar3 != (long *)0x0) {
          FUN_fffffff0089c46cc(plVar3);
        }
      }
      else if ((DAT_fffffff00ae430b1 >> 2 & 1) == 0) {
        uVar37 = 0;
      }
      else {
        thunk_FUN_fffffff00a8df19c
                  (auVar41,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff007ddeaa8,0,
                   (byte *)
                   "%s: %s: Procedure has coalesced IOs, pretend to unwire since autoPrewiring will handle it %s\n"
                  );
        uVar37 = 0;
      }
      goto LAB_fffffff0089d4994;
    }
    auVar7._8_8_ = extraout_var_00;
    auVar7._0_8_ = extraout_d0_00;
    thunk_FUN_fffffff00a8df19c
              (auVar7,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff007ddeaa8,0x10,
               (byte *)
               "[ERROR] %s: %s: Cannot find program or program info for programHandle: 0x%llx\n");
  }
  else {
    auVar13._8_8_ = extraout_var;
    auVar13._0_8_ = extraout_d0;
    thunk_FUN_fffffff00a8df19c
              (auVar13,param_2,uVar45,uVar47,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff007ddeaa8,0x10,
               (byte *)
               "[ERROR] %s: %s: programHandle: 0x%llx, Client Not found, dropping the memoryUnMap request\n"
              );
  }
  uVar37 = 0xe00002f0;
LAB_fffffff0089d4994:
  if (local_90 != (long *)0x0) {
    FUN_fffffff0089c46cc(local_90);
  }
  if (local_80 != (long *)0x0) {
    FUN_fffffff0089c46cc(local_80);
  }
  if (local_70 != (long *)0x0) {
    FUN_fffffff0089c46cc(local_70);
  }
  return uVar37;
}

