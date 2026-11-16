// FUN_fffffff009ca3cac @ fffffff009ca3cac

/* WARNING: Removing unreachable block (ram,0xfffffff009ca4cb0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca48a0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca4c44) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca4cec) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca4b10) */

void FUN_fffffff009ca3cac
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7)

{
  char cVar1;
  short sVar2;
  byte bVar3;
  undefined1 auVar4 [16];
  undefined *puVar5;
  undefined *puVar6;
  code *pcVar7;
  bool bVar8;
  undefined2 uVar9;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  byte *pbVar15;
  long *plVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  long lVar19;
  long *plVar20;
  ulong uVar21;
  ulong uVar22;
  ushort uVar23;
  long *plVar24;
  ushort uVar25;
  ushort uVar26;
  short *psVar27;
  long lVar28;
  undefined2 *puVar29;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined1 extraout_q0_05 [16];
  undefined1 extraout_q0_06 [16];
  undefined1 extraout_q0_07 [16];
  undefined1 extraout_q0_08 [16];
  undefined1 extraout_q0_09 [16];
  undefined1 extraout_q0_10 [16];
  undefined1 extraout_q0_11 [16];
  undefined1 extraout_q0_12 [16];
  undefined1 extraout_q0_13 [16];
  undefined1 extraout_q0_14 [16];
  undefined1 extraout_q0_15 [16];
  undefined1 extraout_q0_16 [16];
  undefined1 extraout_q0_17 [16];
  undefined1 extraout_q0_18 [16];
  undefined1 auVar30 [16];
  undefined1 extraout_q0_19 [16];
  undefined1 extraout_q0_20 [16];
  undefined1 extraout_q0_21 [16];
  undefined1 extraout_q0_22 [16];
  undefined1 extraout_q0_23 [16];
  undefined1 extraout_q0_24 [16];
  undefined1 extraout_q0_25 [16];
  undefined1 extraout_q0_26 [16];
  undefined4 uVar31;
  undefined1 auVar32 [12];
  undefined4 uVar33;
  undefined1 auVar34 [12];
  long in_stack_ffffffffffffffc8;
  
  uVar33 = param_4._0_4_;
  auVar34 = param_4._4_12_;
  uVar31 = param_3._0_4_;
  auVar32 = param_3._4_12_;
  plVar24 = (long *)param_7[0x3d];
  bVar3 = *(byte *)(plVar24 + 2);
  if ((char)bVar3 < '\0') {
    if (*(short *)((long)plVar24 + 0x16) != 0) {
      if ((bVar3 & 0x60) != 0) goto LAB_fffffff009ca3d14;
      if ((bVar3 & 0x1f) == 2) {
        if (*(char *)((long)plVar24 + 0x11) == '\0') {
          plVar24 = (long *)param_7[0x3d];
          if (*(short *)((long)plVar24 + 0x16) != 2) {
            if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca43fc);
              (*pcVar7)();
            }
            FUN_fffffff009c895b0(param_1,param_2,uVar31,uVar33,param_5,param_6,plVar24);
            return;
          }
          uVar9 = (**(code **)(*param_7 + 0x600))(param_7,*(undefined1 *)((long)plVar24 + 0x14));
          *(undefined2 *)param_7[0x1f] = uVar9;
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca43e0);
            (*pcVar7)();
          }
          FUN_fffffff009c89964
                    (extraout_q0_14,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d],2,0,
                     0,0);
          return;
        }
      }
      else if ((bVar3 & 0x1f) == 1) {
        cVar1 = *(char *)((long)plVar24 + 0x11);
        if (cVar1 == '\n') {
          plVar24 = (long *)param_7[0x3d];
          if (*(short *)((long)plVar24 + 0x16) == 1) {
            plVar24 = (long *)FUN_fffffff009c9c630
                                        ((long)param_7,(ulong)*(ushort *)((long)plVar24 + 0x14));
            if (plVar24 != (long *)0x0) {
              uVar11 = FUN_fffffff009c80fa0(plVar24);
              *(char *)param_7[0x1f] = (char)uVar11;
              if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4230);
                (*pcVar7)();
              }
              FUN_fffffff009c89964
                        (extraout_q0_11,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d],
                         1,0,0,0);
              return;
            }
            plVar24 = (long *)param_7[0x3d];
            param_1 = extraout_q0_10;
          }
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4250);
            (*pcVar7)();
          }
          FUN_fffffff009c895b0(param_1,param_2,uVar31,uVar33,param_5,param_6,plVar24);
          return;
        }
        if (cVar1 == '\x06') {
          uVar23 = *(ushort *)(param_7[0x3d] + 0x12);
          bVar3 = *(byte *)(param_7[0x3d] + 0x14);
          plVar24 = (long *)FUN_fffffff009c9c630((long)param_7,(ulong)bVar3);
          auVar30 = extraout_q0_12;
          if (plVar24 != (long *)0x0) {
            lVar28 = param_7[0x1f];
            lVar19 = param_7[0x20];
            uVar11 = (**(code **)(*param_7 + 0x5c0))(param_7);
            uVar10 = FUN_fffffff009c81c68
                               (plVar24,lVar28,(int)lVar19,(uint)(uVar23 >> 8),uVar11,(uint)bVar3,
                                0xffffffff);
            auVar30 = extraout_q0_13;
            if (uVar10 != 0) {
              uVar23 = *(ushort *)(param_7[0x3d] + 0x16);
              if ((int)(uint)uVar23 <= (int)uVar10) {
                uVar10 = (uint)uVar23;
              }
              if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca432c);
                (*pcVar7)();
              }
              FUN_fffffff009c89964
                        (extraout_q0_13,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d],
                         (long)(int)uVar10,0,0,0);
              return;
            }
          }
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4354);
            (*pcVar7)();
          }
          FUN_fffffff009c895b0(auVar30,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d]);
          return;
        }
        if (cVar1 == '\0') {
          iVar12 = (**(code **)(*param_7 + 0x5c0))();
          plVar24 = (long *)param_7[0x3d];
          auVar30 = extraout_q0_08;
          if (1 < *(ushort *)((long)plVar24 + 0x16) && 2 < iVar12) {
            lVar19 = FUN_fffffff009c9c630((long)param_7,(ulong)*(ushort *)((long)plVar24 + 0x14));
            if (lVar19 != 0) {
              uVar23 = 2;
              if ((*(byte *)(lVar19 + 0x132) & 1) == 0) {
                uVar23 = 0;
              }
              *(ushort *)param_7[0x1f] = uVar23 | *(byte *)(lVar19 + 0x131) & 1;
              if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca419c);
                (*pcVar7)();
              }
              FUN_fffffff009c89964
                        (extraout_q0_09,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d],
                         2,0,0,0);
              return;
            }
            plVar24 = (long *)param_7[0x3d];
            auVar30 = extraout_q0_09;
          }
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca41bc);
            (*pcVar7)();
          }
          FUN_fffffff009c895b0(auVar30,param_2,uVar31,uVar33,param_5,param_6,plVar24);
          return;
        }
      }
      else if ((bVar3 & 0x1f) == 0) {
        cVar1 = *(char *)((long)plVar24 + 0x11);
        if (cVar1 == '\b') {
          if (*(short *)(param_7[0x3d] + 0x16) != 0) {
            *(char *)param_7[0x1f] = (char)(int)param_7[0x1b];
            FUN_fffffff009c89964
                      (param_1,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d],1,0,0,0);
            return;
          }
          FUN_fffffff009c895b0(param_1,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d]);
          return;
        }
        if (cVar1 == '\x06') {
          plVar24 = (long *)param_7[0x3d];
          uVar23 = *(ushort *)((long)plVar24 + 0x12) >> 8;
          if (uVar23 < 6) {
            if (uVar23 == 1) {
LAB_fffffff009ca4034:
              if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4050);
                (*pcVar7)();
              }
              iVar12 = (**(code **)(*param_7 + 0x5c0))();
              plVar24 = (long *)param_7[0x3d];
              if (*(char *)((long)plVar24 + 0x13) == '\x06') {
                if (1 < iVar12 - 1U) {
                  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
                    pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca2d98);
                    (*pcVar7)();
                  }
                  FUN_fffffff009c895b0(extraout_q0_03,param_2,uVar31,uVar33,param_5,param_6,plVar24)
                  ;
                  return;
                }
                uVar10 = (uint)*(ushort *)((long)plVar24 + 0x16);
                if (9 < uVar10) {
                  uVar10 = 10;
                }
                lVar19 = 0x140;
              }
              else {
                uVar10 = (uint)*(ushort *)((long)plVar24 + 0x16);
                if (0x11 < uVar10) {
                  uVar10 = 0x12;
                }
                lVar19 = 0x138;
              }
              auVar30 = thunk_FUN_fffffff00aa65b10
                                  ((undefined8 *)param_7[0x1f],
                                   *(undefined8 **)((long)param_7 + lVar19),(ulong)uVar10);
              if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca2d7c);
                (*pcVar7)();
              }
              FUN_fffffff009c89964
                        (auVar30,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d],
                         (ulong)uVar10,0,0,0);
              return;
            }
            if (uVar23 != 2) {
              if (uVar23 == 3) {
                uVar10 = FUN_fffffff009c99a34
                                   (param_7[0x2a],(undefined1 *)param_7[0x1f],
                                    *(uint *)(param_7 + 0x20),
                                    (uint)*(ushort *)((long)plVar24 + 0x14),
                                    *(ushort *)((long)plVar24 + 0x12) & 0xff);
                plVar24 = (long *)param_7[0x3d];
                if ((*(uint *)(param_7 + 0x2b) == (uint)*(byte *)((long)plVar24 + 0x12)) &&
                   ((int)uVar10 < 0x52)) {
                  *(undefined1 *)param_7[0x1f] = 0x52;
                  auVar30 = thunk_FUN_fffffff00aa65cc0
                                      ((undefined8 *)(param_7[0x1f] + (long)(int)uVar10),
                                       (ulong)(0x52 - uVar10));
                  plVar24 = (long *)param_7[0x3d];
                  uVar10 = 0x52;
                }
                else {
                  auVar30 = extraout_q0_07;
                  param_1 = extraout_q0_07;
                  if (uVar10 == 0) goto LAB_fffffff009ca40d0;
                }
                if ((int)(uint)*(ushort *)((long)plVar24 + 0x16) <= (int)uVar10) {
                  uVar10 = (uint)*(ushort *)((long)plVar24 + 0x16);
                }
                if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
                  pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca40cc);
                  (*pcVar7)();
                }
                FUN_fffffff009c89964
                          (auVar30,param_2,uVar31,uVar33,param_5,param_6,plVar24,(long)(int)uVar10,0
                           ,0,0);
                return;
              }
LAB_fffffff009ca40d0:
              if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca40e8);
                (*pcVar7)();
              }
              FUN_fffffff009c895b0(param_1,param_2,uVar31,uVar33,param_5,param_6,plVar24);
              return;
            }
          }
          else {
            if (uVar23 == 0xf) {
              if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4090);
                (*pcVar7)();
              }
              puVar29 = (undefined2 *)param_7[0x1f];
              iVar14 = (**(code **)(*(long *)param_7[0x36] + 0x90))();
              puVar6 = PTR_PTR_fffffff00807fa88;
              iVar12 = 0;
              if (iVar14 == 0) {
                uVar22 = 5;
              }
              else {
                uVar10 = 0;
                lVar19 = *(long *)PTR_PTR_fffffff00807fa88;
                uVar22 = 5;
                do {
                  plVar24 = (long *)(**(code **)(*(long *)param_7[0x36] + 0x118))
                                              ((long *)param_7[0x36],uVar10);
                  plVar24 = thunk_FUN_fffffff00a894f30(plVar24,lVar19);
                  if ((plVar24 != (long *)0x0) &&
                     (pbVar15 = (byte *)(**(code **)(*plVar24 + 0xd8))(), pbVar15 != (byte *)0x0)) {
                    thunk_FUN_fffffff00aa65b10
                              ((undefined8 *)(param_7[0x1f] + uVar22),(undefined8 *)pbVar15,
                               (ulong)*pbVar15);
                    uVar22 = (ulong)((int)uVar22 + (uint)*pbVar15);
                    iVar12 = iVar12 + 1;
                  }
                  uVar10 = uVar10 + 1;
                  uVar13 = (**(code **)(*(long *)param_7[0x36] + 0x90))();
                } while (uVar10 < uVar13);
              }
              plVar24 = (long *)(**(code **)(*param_7 + 0x180))
                                          (param_7,*(undefined8 *)PTR_DAT_fffffff00807fb08);
              auVar30 = extraout_q0_04;
              if (plVar24 != (long *)0x0) {
                plVar20 = (long *)(**(code **)(*plVar24 + 0x88))();
                puVar5 = PTR_DAT_fffffff00807d2c0;
                if (plVar20 != (long *)0x0) {
                  lVar19 = *(long *)puVar6;
                  do {
                    plVar20 = thunk_FUN_fffffff00a894f30(plVar20,(long)puVar5);
                    if (plVar20 != (long *)0x0) {
                      plVar16 = thunk_FUN_fffffff00a89a1f4(1);
                      iVar14 = (**(code **)(*plVar20 + 0x540))(plVar20,plVar16);
                      if (iVar14 == 0) {
                        if (plVar16 == (long *)0x0) goto LAB_fffffff009ca3084;
                      }
                      else {
                        iVar14 = (**(code **)(*plVar16 + 0x90))(plVar16);
                        if (iVar14 != 0) {
                          uVar10 = 0;
                          do {
                            plVar20 = (long *)(**(code **)(*plVar16 + 0x118))(plVar16,uVar10);
                            plVar20 = thunk_FUN_fffffff00a894f30(plVar20,lVar19);
                            if (plVar20 != (long *)0x0) {
                              pbVar15 = (byte *)(**(code **)(*plVar20 + 0xd8))();
                              if (pbVar15 == (byte *)0x0) {
LAB_fffffff009ca3150:
                                auVar30._4_12_ = auVar32;
                                auVar30._0_4_ = uVar31;
                                auVar4._4_12_ = auVar34;
                                auVar4._0_4_ = uVar33;
                    /* WARNING: Subroutine does not return */
                                thunk_FUN_fffffff00aa4d114
                                          (extraout_q0_05,param_2,auVar30,auVar4,param_5,param_6,
                                           (byte *)
                                           "\"failed to append device capability descriptor, totalLength: %d, bLength: %d\\n\" @%s:%d"
                                          );
                              }
                              if ((ulong)param_7[0x20] <= (ulong)((int)uVar22 + (uint)*pbVar15))
                              goto LAB_fffffff009ca3150;
                              thunk_FUN_fffffff00aa65b10
                                        ((undefined8 *)(param_7[0x1f] + uVar22),
                                         (undefined8 *)pbVar15,(ulong)*pbVar15);
                              uVar22 = (ulong)((int)uVar22 + (uint)*pbVar15);
                              iVar12 = iVar12 + 1;
                            }
                            uVar10 = uVar10 + 1;
                            uVar13 = (**(code **)(*plVar16 + 0x90))(plVar16);
                          } while (uVar10 < uVar13);
                        }
                      }
                      (**(code **)(*plVar16 + 0x28))(plVar16);
                    }
LAB_fffffff009ca3084:
                    plVar20 = (long *)(**(code **)(*plVar24 + 0x88))(plVar24);
                  } while (plVar20 != (long *)0x0);
                }
                auVar30 = (**(code **)(*plVar24 + 0x28))(plVar24);
              }
              if (iVar12 == 0) {
                if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
                  pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca314c);
                  (*pcVar7)();
                }
                FUN_fffffff009c895b0
                          (auVar30,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d]);
                return;
              }
              *puVar29 = 0xf05;
              puVar29[1] = (short)uVar22;
              *(char *)(puVar29 + 2) = (char)iVar12;
              uVar13 = (uint)*(ushort *)(param_7[0x3d] + 0x16);
              uVar10 = (uint)uVar22;
              if (uVar13 <= (uint)uVar22) {
                uVar10 = uVar13;
              }
              if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca3118);
                (*pcVar7)();
              }
              FUN_fffffff009c89964
                        (auVar30,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d],
                         (ulong)uVar10,0,0,0);
              return;
            }
            if (uVar23 != 7) {
              if (uVar23 != 6) goto LAB_fffffff009ca40d0;
              goto LAB_fffffff009ca4034;
            }
          }
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4070);
            (*pcVar7)();
          }
          bVar3 = *(byte *)(param_7[0x3d] + 0x12);
          uVar10 = (**(code **)(*(long *)param_7[0x2e] + 0x90))();
          if (bVar3 < uVar10) {
            iVar12 = (**(code **)(*param_7 + 0x5c0))(param_7);
            plVar24 = (long *)param_7[0x3d];
            cVar1 = *(char *)((long)plVar24 + 0x13);
            if (cVar1 == '\a') {
              auVar30 = extraout_q0_00;
              if (2 < iVar12) goto LAB_fffffff009ca2bfc;
              bVar8 = iVar12 != 2;
              iVar12 = 1;
              if (bVar8) {
                iVar12 = 2;
              }
              plVar24 = param_7 + 0x2f;
            }
            else {
              plVar24 = param_7 + 0x2e;
            }
            lVar19 = (**(code **)(*(long *)*plVar24 + 0x118))((long *)*plVar24,bVar3);
            uVar10 = FUN_fffffff009c9a660
                               (extraout_q0_01,param_2,uVar31,uVar33,param_5,param_6,lVar19,
                                (undefined1 *)param_7[0x1f],*(uint *)(param_7 + 0x20),bVar3 + 1,
                                iVar12,(uint)(cVar1 == '\a'));
            uVar23 = *(ushort *)(param_7[0x3d] + 0x16);
            if ((int)(uint)uVar23 <= (int)uVar10) {
              uVar10 = (uint)uVar23;
            }
            if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca2cac);
              (*pcVar7)();
            }
            FUN_fffffff009c89964
                      (extraout_q0_02,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d],
                       (long)(int)uVar10,0,0,0);
            return;
          }
          plVar24 = (long *)param_7[0x3d];
          auVar30 = extraout_q0;
LAB_fffffff009ca2bfc:
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca2c18);
            (*pcVar7)();
          }
          FUN_fffffff009c895b0(auVar30,param_2,uVar31,uVar33,param_5,param_6,plVar24);
          return;
        }
        if (cVar1 == '\0') {
          iVar12 = (**(code **)(*param_7 + 0x5c0))();
          plVar24 = (long *)param_7[0x3d];
          if (*(ushort *)((long)plVar24 + 0x16) < 2) {
            if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca3ed4);
              (*pcVar7)();
            }
            FUN_fffffff009c895b0(extraout_q0_06,param_2,uVar31,uVar33,param_5,param_6,plVar24);
            return;
          }
          if (iVar12 < 3) {
            uVar23 = 2;
            if ((*(byte *)((long)param_7 + 0x10d) & 1) == 0) {
              uVar23 = 0;
            }
          }
          else {
            uVar23 = 0;
          }
          uVar25 = 4;
          if ((*(byte *)((long)param_7 + 0x43a) & 1) == 0) {
            uVar25 = 0;
          }
          uVar26 = 8;
          if ((*(byte *)((long)param_7 + 0x43b) & 1) == 0) {
            uVar26 = 0;
          }
          *(ushort *)param_7[0x1f] = uVar25 | uVar23 | uVar26;
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca3f34);
            (*pcVar7)();
          }
          FUN_fffffff009c89964(extraout_q0_06,param_2,uVar31,uVar33,param_5,param_6,plVar24,2,0,0,0)
          ;
          return;
        }
      }
    }
    goto LAB_fffffff009ca3e20;
  }
  if (0x1f < bVar3) {
LAB_fffffff009ca3d14:
                    /* WARNING: Could not recover jumptable at 0xfffffff009ca3d40. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_7 + 0x710))(param_7,(undefined8 *)(*param_7 + 0x710));
    return;
  }
  if (bVar3 == 2) {
    if (*(char *)((long)plVar24 + 0x11) == '\x03') {
      FUN_fffffff009ca51ac(param_1,param_2,uVar31,uVar33,param_5,param_6,param_7);
      return;
    }
    if (*(char *)((long)plVar24 + 0x11) == '\x01') {
      FUN_fffffff009ca50ac(param_1,param_2,uVar31,uVar33,param_5,param_6,param_7);
      return;
    }
LAB_fffffff009ca3e20:
    FUN_fffffff009c895b0(param_1,param_2,uVar31,uVar33,param_5,param_6,plVar24);
    return;
  }
  if (bVar3 == 1) {
    cVar1 = *(char *)((long)plVar24 + 0x11);
    if (cVar1 != '\x01') {
      if (cVar1 == '\x03') {
        FUN_fffffff009ca4fc0(param_1,param_2,uVar31,uVar33,param_5,param_6,param_7);
        return;
      }
      if (cVar1 == '\v') {
        plVar24 = (long *)FUN_fffffff009c9c630
                                    ((long)param_7,(ulong)*(ushort *)(param_7[0x3d] + 0x14));
        auVar30 = extraout_q0_25;
        if ((plVar24 != (long *)0x0) &&
           (uVar17 = FUN_fffffff009c80904(plVar24,(uint)*(ushort *)(param_7[0x3d] + 0x12)),
           auVar30 = extraout_q0_26, (int)uVar17 == 0)) {
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4fb0);
            (*pcVar7)();
          }
          FUN_fffffff009c893ec
                    (extraout_q0_26,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d],0);
          return;
        }
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4f8c);
          (*pcVar7)();
        }
        FUN_fffffff009c895b0(auVar30,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d]);
        return;
      }
    }
    goto LAB_fffffff009ca3e20;
  }
  if (bVar3 != 0) goto LAB_fffffff009ca3e20;
  bVar3 = *(byte *)((long)plVar24 + 0x11);
  if (8 < bVar3) {
    if (bVar3 == 9) {
      uVar23 = *(ushort *)(param_7[0x3d] + 0x12);
      uVar10 = (uint)uVar23;
      if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
        if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
           (bVar8 = thunk_FUN_fffffff00a394140(), !bVar8)) {
          psVar27 = *(short **)PTR_DAT_fffffff00807fa80;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar30 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar30,param_2,uVar31,uVar33,param_5,param_6,&MACH_HEADER,psVar27,0,
                     (byte *)"%s@%s: %s::%s: configuration %d -> %d\n");
        }
        else {
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: configuration %d -> %d\n");
        }
      }
      if (uVar10 != 0) {
        uVar13 = (**(code **)(*(long *)param_7[0x2e] + 0x90))();
        auVar30 = extraout_q0_20;
        if (uVar10 <= uVar13) {
          if (*(uint *)(param_7 + 0x1b) == uVar10) {
            lVar19 = (**(code **)(*(long *)param_7[0x2e] + 0x118))((long *)param_7[0x2e],uVar10 - 1)
            ;
            auVar30 = FUN_fffffff009c9b148(lVar19);
            goto LAB_fffffff009ca4bb8;
          }
          iVar12 = (**(code **)(*param_7 + 0x5c0))(param_7);
          lVar19 = *(long *)param_7[0x2e];
          lVar19 = (**(code **)(lVar19 + 0x118))(lVar19 + 0x118,(long *)param_7[0x2e],uVar10 - 1);
          iVar14 = FUN_fffffff009c9a9b8(lVar19);
          auVar30 = extraout_q0_21;
          if (iVar14 <= iVar12) {
            FUN_fffffff009c9bc2c((long)param_7);
            FUN_fffffff009c9afec(lVar19,iVar12);
            plVar24 = (long *)FUN_fffffff009c9b228(lVar19);
            (**(code **)(*param_7 + 0x5d0))(*param_7 + 0x5d0,param_7,plVar24);
            (**(code **)(*param_7 + 0x658))(*param_7 + 0x658,param_7,uVar23);
            iVar14 = (**(code **)(*plVar24 + 0x90))(plVar24);
            auVar30 = extraout_q0_22;
            if (iVar14 != 0) {
              uVar22 = 0;
              do {
                plVar20 = (long *)(**(code **)(*plVar24 + 0x118))(plVar24,uVar22);
                (**(code **)(*plVar20 + 0xe0))(plVar20,"Index",uVar22,0x20);
                (**(code **)(*plVar20 + 0xe0))(plVar20,"Configuration",uVar23,0x20);
                FUN_fffffff009c80740((long)plVar20,iVar12);
                uVar22 = uVar22 + 1;
                uVar21 = (**(code **)(*plVar24 + 0x90))(plVar24);
                auVar30 = extraout_q0_23;
              } while (uVar22 < (uVar21 & 0xffffffff));
            }
            FUN_fffffff009c893ec
                      (auVar30,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d],0);
            if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4e54);
              (*pcVar7)();
            }
                    /* WARNING: Could not recover jumptable at 0xfffffff009ca4e5c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
            (**(code **)(*param_7 + 0x6e8))(param_7,uVar23,(undefined8 *)(*param_7 + 0x6e8));
            return;
          }
        }
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4ab0);
          (*pcVar7)();
        }
        FUN_fffffff009c895b0(auVar30,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d]);
        return;
      }
      auVar30 = FUN_fffffff009c9be10(param_7);
LAB_fffffff009ca4bb8:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4bec);
        (*pcVar7)();
      }
      FUN_fffffff009c893ec(auVar30,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d],0);
      return;
    }
    if (bVar3 == 0x30) {
      plVar24 = (long *)param_7[0x3d];
      if ((((*(short *)((long)plVar24 + 0x12) == 0) && (*(short *)((long)plVar24 + 0x14) == 0)) &&
          (*(short *)((long)plVar24 + 0x16) == 6)) && (2 < *(int *)((long)param_7 + 0xd4))) {
        iVar12 = (**(code **)(*param_7 + 0x5c0))(param_7);
        if (2 < iVar12) {
          FUN_fffffff009c885cc
                    (extraout_q0_24,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d],
                     (ulong)*(ushort *)(param_7[0x3d] + 0x16),(long *)&stack0xffffffffffffffc8,
                     (long *)0x0);
          return;
        }
        plVar24 = (long *)param_7[0x3d];
        param_1 = extraout_q0_24;
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4ef8);
        (*pcVar7)();
      }
      FUN_fffffff009c895b0(param_1,param_2,uVar31,uVar33,param_5,param_6,plVar24);
      return;
    }
    if (bVar3 == 0x31) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009ca3df4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_7 + 0x778))(param_7,(undefined8 *)(*param_7 + 0x778));
      return;
    }
    goto LAB_fffffff009ca3e20;
  }
  if (bVar3 == 1) {
    uVar17 = (**(code **)(*param_7 + 0x5c0))();
    plVar24 = (long *)param_7[0x3d];
    sVar2 = *(short *)((long)plVar24 + 0x12);
    iVar12 = (int)uVar17;
    auVar30 = extraout_q0_15;
    if (sVar2 == 0x31) {
      if ((*(short *)((long)plVar24 + 0x16) != 0) ||
         (*(short *)((long)plVar24 + 0x14) != 0 || iVar12 < 3)) goto LAB_fffffff009ca4510;
      *(undefined1 *)((long)param_7 + 0x43b) = 0;
      pcVar7 = *(code **)(*param_7 + 0x780);
      uVar18 = 2;
    }
    else {
      if (sVar2 != 0x30) {
        if (((sVar2 != 1) || (*(short *)((long)plVar24 + 0x16) != 0)) ||
           (*(short *)((long)plVar24 + 0x14) != 0 || 2 < iVar12)) goto LAB_fffffff009ca4510;
        *(undefined1 *)((long)param_7 + 0x10d) = 0;
        goto LAB_fffffff009ca452c;
      }
      if ((*(short *)((long)plVar24 + 0x16) != 0) ||
         (*(short *)((long)plVar24 + 0x14) != 0 || iVar12 < 3)) goto LAB_fffffff009ca4510;
      *(undefined1 *)((long)param_7 + 0x43a) = 0;
      pcVar7 = *(code **)(*param_7 + 0x780);
      uVar18 = 1;
    }
    iVar12 = (*pcVar7)(param_7,uVar17,uVar18);
    plVar24 = (long *)param_7[0x3d];
    auVar30 = extraout_q0_16;
    if (iVar12 != 0) {
LAB_fffffff009ca4510:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4528);
        (*pcVar7)();
      }
      FUN_fffffff009c895b0(auVar30,param_2,uVar31,uVar33,param_5,param_6,plVar24);
      return;
    }
LAB_fffffff009ca452c:
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4548);
      (*pcVar7)();
    }
    FUN_fffffff009c893ec(auVar30,param_2,uVar31,uVar33,param_5,param_6,plVar24,0);
    return;
  }
  if (bVar3 != 3) {
    if (bVar3 == 5) {
      *(undefined2 *)(param_7 + 0x35) = *(undefined2 *)(param_7[0x3d] + 0x12);
      if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
        if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
           (bVar8 = thunk_FUN_fffffff00a394140(), !bVar8)) {
          psVar27 = *(short **)PTR_DAT_fffffff00807fa80;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar30 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar30,param_2,uVar31,uVar33,param_5,param_6,&MACH_HEADER,psVar27,0,
                     (byte *)"%s@%s: %s::%s: setting USB device address %d\n");
        }
        else {
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: setting USB device address %d\n");
        }
      }
      iVar12 = (**(code **)(*param_7 + 0x5b0))(param_7,(short)param_7[0x35]);
      if (iVar12 != 0) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca494c);
          (*pcVar7)();
        }
        FUN_fffffff009c895b0
                  (extraout_q0_19,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d]);
        return;
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca497c);
        (*pcVar7)();
      }
      FUN_fffffff009c893ec
                (extraout_q0_19,param_2,uVar31,uVar33,param_5,param_6,(long *)param_7[0x3d],
                 (ulong)*(ushort *)(param_7 + 0x35) << 8 | 1);
      return;
    }
    goto LAB_fffffff009ca3e20;
  }
  uVar17 = (**(code **)(*param_7 + 0x5c0))();
  plVar24 = (long *)param_7[0x3d];
  uVar23 = *(ushort *)((long)plVar24 + 0x12);
  iVar12 = (int)uVar17;
  auVar30 = extraout_q0_17;
  if (uVar23 < 0x30) {
    if (uVar23 != 1) {
      if (((uVar23 != 2) || (*(short *)((long)plVar24 + 0x16) != 0 || 2 < iVar12)) ||
         ((*(ushort *)((long)plVar24 + 0x14) & 0xff) != 0)) goto LAB_fffffff009ca470c;
      uVar22 = (ulong)*(ushort *)((long)plVar24 + 0x14) | 2;
      goto LAB_fffffff009ca4734;
    }
    if ((*(short *)((long)plVar24 + 0x16) != 0) ||
       (*(short *)((long)plVar24 + 0x14) != 0 || 2 < iVar12)) goto LAB_fffffff009ca470c;
    *(undefined1 *)((long)param_7 + 0x10d) = 1;
  }
  else {
    if (uVar23 == 0x30) {
      if (*(int *)((long)param_7 + 0xd4) < 4 || iVar12 < 3) goto LAB_fffffff009ca470c;
      if ((*(char *)((long)param_7 + 0x434) == '\0') || (*(char *)((long)param_7 + 0x435) == '\0'))
      {
        bVar8 = true;
LAB_fffffff009ca46d4:
        *(bool *)((long)param_7 + 0x43a) = bVar8;
      }
      else {
        uVar18 = FUN_fffffff009ca5248
                           (extraout_q0_17,param_2,uVar31,uVar33,param_5,param_6,param_7,
                            (uint *)&stack0xffffffffffffffcc);
        if ((int)uVar18 == 0) {
          bVar8 = *(byte *)((long)param_7 + 0x434) + 0x7d <
                  (uint)((ulong)in_stack_ffffffffffffffc8 >> 0x20);
          goto LAB_fffffff009ca46d4;
        }
      }
      pcVar7 = *(code **)(*param_7 + 0x780);
      uVar18 = 1;
    }
    else {
      if ((uVar23 != 0x31) || (*(int *)((long)param_7 + 0xd4) < 4 || iVar12 < 3))
      goto LAB_fffffff009ca470c;
      if ((*(short *)((long)param_7 + 0x436) == 0) || ((short)param_7[0x87] == 0)) {
        bVar8 = true;
LAB_fffffff009ca46a8:
        *(bool *)((long)param_7 + 0x43b) = bVar8;
      }
      else {
        uVar18 = FUN_fffffff009ca5248
                           (extraout_q0_17,param_2,uVar31,uVar33,param_5,param_6,param_7,
                            (uint *)&stack0xffffffffffffffc8);
        if ((int)uVar18 == 0) {
          bVar8 = *(ushort *)((long)param_7 + 0x436) + 0x7d < (uint)in_stack_ffffffffffffffc8;
          goto LAB_fffffff009ca46a8;
        }
      }
      pcVar7 = *(code **)(*param_7 + 0x780);
      uVar18 = 2;
    }
    iVar12 = (*pcVar7)(param_7,uVar17,uVar18);
    plVar24 = (long *)param_7[0x3d];
    auVar30 = extraout_q0_18;
    if (iVar12 != 0) {
LAB_fffffff009ca470c:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca472c);
        (*pcVar7)();
      }
      FUN_fffffff009c895b0(auVar30,param_2,uVar31,uVar33,param_5,param_6,plVar24);
      return;
    }
  }
  uVar22 = 0;
LAB_fffffff009ca4734:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca4754);
    (*pcVar7)();
  }
  FUN_fffffff009c893ec(auVar30,param_2,uVar31,uVar33,param_5,param_6,plVar24,uVar22);
  return;
}

