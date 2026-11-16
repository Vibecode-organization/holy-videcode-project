// FUN_fffffff009cb8314 @ fffffff009cb8314

/* WARNING: Removing unreachable block (ram,0xfffffff009cb8a6c) */

undefined8
FUN_fffffff009cb8314
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long *param_7)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  undefined4 *puVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  ulong uVar13;
  uint *puVar14;
  ulong uVar15;
  undefined1 *puVar16;
  char *pcVar17;
  long lVar18;
  long lVar19;
  long *plVar20;
  ulong uVar21;
  uint uVar22;
  long *plVar23;
  long lVar24;
  uint *puVar25;
  ulong uVar26;
  long lVar27;
  undefined1 extraout_q0 [16];
  undefined1 auVar28 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  char *in_stack_ffffffffffffff30;
  undefined8 local_78;
  undefined1 *local_70;
  undefined1 *local_68;
  
  local_68 = &DAT_aaaaaaaaaaaaaaaa;
  plVar20 = (long *)param_7[0xb9];
  uVar13 = (**(code **)(*param_7 + 0x7f0))(param_7,0x70c);
  thunk_FUN_fffffff00a209048((long *)&local_68);
  if (plVar20 == (long *)0x0) {
    plVar20 = (long *)param_7[0xb7];
  }
  puVar14 = (uint *)(**(code **)(*plVar20 + 0x88))(plVar20);
  if (puVar14 != (uint *)0x0) {
    puVar25 = (uint *)PTR_DAT_fffffff0080813c0;
    auVar28 = extraout_q0;
    do {
      if ((*puVar25 & 0xfffffff7) != 0) {
        thunk_FUN_fffffff00a6de494
                  (auVar28,param_2,param_3,param_4,param_5,param_6,0x52d8000,5,uVar13 & 0xffffffff,2
                   ,(ulong)*puVar14);
      }
      uVar22 = *puVar14;
      if ((*puVar14 & 1) == 0) {
        uVar9 = *puVar14 >> 6 & 0xf;
        plVar23 = (long *)param_7[0x8d];
        thunk_FUN_fffffff00a393504();
        auVar28 = thunk_FUN_fffffff00a38ec30(plVar23);
        lVar27 = param_7[(ulong)(uVar22 >> 1 & 0x1f) + 0x8f];
        if (lVar27 == 0) {
          thunk_FUN_fffffff00a22c478((undefined8 *)param_7[0x8d]);
          thunk_FUN_fffffff00a393504();
          puVar25 = (uint *)PTR_DAT_fffffff0080813c0;
          if (((int)param_7[0x4c7] != 0) && ((*(byte *)((long)param_7 + 500) & 1) != 0)) {
            pcVar17 = "AppleUSBXDCI::%s:event %d on inactive endpoint 0x%02x\n";
LAB_fffffff009cb86ec:
            in_stack_ffffffffffffff30 = "filterOccurredIsoc";
            FUN_fffffff009cacb28((ulong)param_7,(byte *)pcVar17);
          }
        }
        else {
          if (((int)param_7[0x4c7] != 0) && ((*(byte *)((long)param_7 + 500) >> 6 & 1) != 0)) {
            in_stack_ffffffffffffff30 = "filterOccurredIsoc";
            FUN_fffffff009cacb28
                      ((ulong)param_7,(byte *)"AppleUSBXDCI::%s:event %d on endpoint 0x%02x\n");
            auVar28 = extraout_q0_00;
          }
          if (uVar9 == 2) {
            FUN_fffffff009cc02b4
                      (auVar28,param_2,param_3,param_4,param_5,param_6,param_7,puVar14,
                       (ulong)local_68);
          }
          else if (uVar9 == 7) {
            uVar22 = *puVar14 >> 0x18 & 0xf;
            if (uVar22 == 8) {
              uVar22 = *puVar14 >> 0xc & 0xf;
              if (uVar22 == 1) {
                if (((int)param_7[0x4c7] != 0) && ((*(byte *)((long)param_7 + 500) & 1) != 0)) {
                  pcVar17 = 
                  "AppleUSBXDCI::%s:kEpCommandEndXfer failed as XferResNotAvailable for ep 0x%02x\n"
                  ;
                  goto LAB_fffffff009cb8844;
                }
              }
              else if (uVar22 == 0) {
                if (*(char *)(lVar27 + 0x1a) == -2) {
                  *(undefined1 *)(lVar27 + 0x1a) = 0xff;
                }
                local_78 = 0;
                bVar7 = *(byte *)(lVar27 + 0x18);
                if (0 < *(int *)(lVar27 + 0x90)) {
                  uVar22 = 0;
                  do {
                    lVar24 = *(long *)(lVar27 + 0x48);
                    if (lVar24 == 0) break;
                    uVar9 = **(uint **)(lVar24 + 0x18);
                    uVar15 = (ulong)uVar9;
                    uVar21 = (ulong)(int)uVar9;
                    if ((ulong)(long)(int)uVar9 < *(ulong *)(lVar24 + 0x40)) {
                      uVar26 = uVar21 * 0x18 | 6;
                      uVar15 = uVar21;
                      do {
                        FUN_fffffff009cc6568(lVar27,(int *)&local_78,(uint *)((long)&local_78 + 4));
                        if ((local_78._4_4_ == 1) &&
                           (*(int *)(lVar27 + 0x38) != 1 && (bVar7 & 1) == 0)) {
                          if (((int)param_7[0x4c7] != 0) &&
                             ((*(byte *)((long)param_7 + 500) >> 6 & 1) != 0)) {
                            in_stack_ffffffffffffff30 = "filterOccurredIsoc";
                            FUN_fffffff009cacb28
                                      ((ulong)param_7,
                                       (byte *)
                                       "AppleUSBXDCI::%s:Missed Isoc for frame number %llu remaining %d bytes\n"
                                      );
                          }
                          *(undefined2 *)(*(long *)(lVar24 + 0x48) + uVar26) = 0;
                          uVar21 = uVar15;
                          break;
                        }
                        lVar18 = *(long *)(lVar24 + 0x48);
                        uVar21 = uVar15 * 0x18 | 4;
                        psVar4 = (short *)(lVar18 + (int)uVar21);
                        if (uVar21 != (long)(int)uVar21) {
                          psVar4 = (short *)(lVar18 + uVar21 & 0xffffffffffff | 0x2bad000000000000);
                        }
                        lVar19 = uVar15 * 0x18;
                        sVar1 = 0;
                        if (-1 < *(char *)(lVar27 + 0xc)) {
                          sVar1 = (short)local_78;
                        }
                        uVar21 = uVar15 * 0x18 | 6;
                        psVar5 = (short *)(lVar18 + (int)uVar21);
                        if (uVar21 != (long)(int)uVar21) {
                          psVar5 = (short *)(lVar18 + uVar21 & 0xffffffffffff | 0x2bad000000000000);
                        }
                        *psVar5 = *psVar4 - sVar1;
                        uVar2 = 0;
                        if (local_78._4_4_ != 0) {
                          uVar2 = 0xe00002bc;
                        }
                        puVar6 = (undefined4 *)(*(long *)(lVar24 + 0x48) + (long)(int)lVar19);
                        if (lVar19 - (int)lVar19 != 0) {
                          puVar6 = (undefined4 *)
                                   (*(long *)(lVar24 + 0x48) + lVar19 & 0xffffffffffffU |
                                   0x2bad000000000000);
                        }
                        *puVar6 = uVar2;
                        uVar22 = local_78._4_4_ | uVar22;
                        uVar15 = uVar15 + 1;
                        uVar26 = uVar26 + 0x18;
                        uVar21 = uVar15;
                      } while (uVar15 < *(ulong *)(lVar24 + 0x40));
                    }
                    **(undefined4 **)(lVar24 + 0x18) = (int)uVar15;
                    if (uVar21 < *(ulong *)(lVar24 + 0x40)) break;
                    FUN_fffffff009cc62f8(lVar27);
                    thunk_FUN_fffffff00a89460c((int *)(lVar27 + 0x90));
                    local_70 = &DAT_aaaaaaaaaaaaaaaa;
                    thunk_FUN_fffffff00a39c228((ulong)local_68,(long *)&local_70);
                    iVar11 = *(int *)(lVar27 + 0x10);
                    iVar12 = (**(code **)(*param_7 + 0x5c0))(*param_7 + 0x5c0,param_7);
                    iVar10 = *(int *)(lVar24 + 0x40) + -1;
                    if ((int)uVar9 <= iVar10) {
                      iVar3 = 0x1e848;
                      if (iVar12 < 2) {
                        iVar3 = 1000000;
                      }
                      do {
                        lVar18 = (long)iVar10 * 0x18 + 8;
                        plVar23 = (long *)(*(long *)(lVar24 + 0x48) + (long)(int)lVar18);
                        if (lVar18 != (int)lVar18) {
                          plVar23 = (long *)(*(long *)(lVar24 + 0x48) + lVar18 & 0xffffffffffffU |
                                            0x2bad000000000000);
                        }
                        if (*plVar23 != 0xe0005108) {
                          thunk_FUN_fffffff00a39c268((ulong)local_70,plVar23);
                        }
                        local_70 = local_70 + -(ulong)(uint)(iVar3 << (ulong)(iVar11 - 1U & 0x1f));
                        iVar10 = iVar10 + -1;
                      } while ((int)uVar9 <= iVar10);
                    }
                    uVar2 = 0;
                    if (uVar22 != 0) {
                      uVar2 = 0xe00002bc;
                    }
                    if ((bVar7 & 1) != 0) {
                      uVar2 = 0xe00002eb;
                    }
                    *(undefined4 *)(lVar24 + 0x28) = uVar2;
                    FUN_fffffff009cc6394(lVar27,lVar24);
                  } while (0 < *(int *)(lVar27 + 0x90));
                }
                FUN_fffffff009cab93c(*(long *)(lVar27 + 0x98));
                auVar28 = FUN_fffffff009cc64ac(lVar27);
                if ((bVar7 & 1) == 0) {
                  FUN_fffffff009cb0b28
                            (auVar28,param_2,param_3,param_4,param_5,param_6,param_7,
                             (uint)*(byte *)(lVar27 + 0xc));
                }
                else {
                  thunk_FUN_fffffff00a89461c(0xfffffffe,(uint *)(lVar27 + 0x18));
                  lVar24 = FUN_fffffff009cc62f8(lVar27);
                  while (lVar24 != 0) {
                    *(undefined4 *)(lVar24 + 0x28) = 0xe00002eb;
                    FUN_fffffff009cc6394(lVar27,lVar24);
                    lVar24 = FUN_fffffff009cc62f8(lVar27);
                  }
                }
              }
            }
            else if (uVar22 == 6) {
              uVar22 = *puVar14 >> 0xc & 0xf;
              if (uVar22 == 2) {
                if (((int)param_7[0x4c7] != 0) && ((*(byte *)((long)param_7 + 500) & 1) != 0)) {
                  in_stack_ffffffffffffff30 = "filterOccurredIsoc";
                  FUN_fffffff009cacb28
                            ((ulong)param_7,
                             (byte *)
                             "AppleUSBXDCI::%s:kEpCommandStartXfer failed as IsocIntervalExpired for ep 0x%02x\n"
                            );
                }
                if (*(char *)(lVar27 + 0x1a) == -2) {
                  in_stack_ffffffffffffff30 =
                       (char *)((ulong)in_stack_ffffffffffffff30 & 0xffffffff00000000);
                  iVar11 = (**(code **)(*param_7 + 0x7e0))
                                     (param_7,*(undefined1 *)(lVar27 + 0xc),8,
                                      *puVar14 >> 0x10 & 0x7f,0,1,0,0,in_stack_ffffffffffffff30);
                  if (((iVar11 != 0) &&
                      (*(undefined1 *)(lVar27 + 0x1a) = 0xff, (int)param_7[0x4c7] != 0)) &&
                     ((*(byte *)((long)param_7 + 500) & 1) != 0)) {
                    pcVar17 = 
                    "AppleUSBXDCI::%s:failed to kEpCommandEndXfer for endpoint 0x%02x (status 0x%08x)\n"
                    ;
                    goto LAB_fffffff009cb8844;
                  }
                }
              }
              else if (uVar22 == 1) {
                if (((int)param_7[0x4c7] != 0) && ((*(byte *)((long)param_7 + 500) & 1) != 0)) {
                  pcVar17 = 
                  "AppleUSBXDCI::%s:kEpCommandStartXfer failed as XferResNotAvailable for ep 0x%02x\n"
                  ;
LAB_fffffff009cb8844:
                  in_stack_ffffffffffffff30 = "filterOccurredIsoc";
                  FUN_fffffff009cacb28((ulong)param_7,(byte *)pcVar17);
                }
              }
              else if (uVar22 == 0) {
                uVar22 = *puVar14 >> 0x10 & 0x7f;
                if (((int)param_7[0x4c7] != 0) && ((*(byte *)((long)param_7 + 500) >> 6 & 1) != 0))
                {
                  in_stack_ffffffffffffff30 = "filterOccurredIsoc";
                  FUN_fffffff009cacb28
                            ((ulong)param_7,
                             (byte *)
                             "AppleUSBXDCI::%s:kEpCommandStartXfer success for ep 0x%02x XferResIndex %d\n"
                            );
                }
                if ((*(char *)(lVar27 + 0x1a) == -2) &&
                   (*(char *)(lVar27 + 0x1a) = (char)uVar22, (*(byte *)(lVar27 + 0x18) & 1) != 0)) {
                  if (((int)param_7[0x4c7] != 0) && ((*(byte *)((long)param_7 + 500) >> 6 & 1) != 0)
                     ) {
                    in_stack_ffffffffffffff30 = "filterOccurredIsoc";
                    FUN_fffffff009cacb28
                              ((ulong)param_7,
                               (byte *)"AppleUSBXDCI::%s:kEpStatusStopPending for ep 0x%02x\n");
                  }
                  in_stack_ffffffffffffff30 =
                       (char *)((ulong)in_stack_ffffffffffffff30 & 0xffffffff00000000);
                  iVar11 = (**(code **)(*param_7 + 0x7e0))
                                     (param_7,*(undefined1 *)(lVar27 + 0xc),8,uVar22,0,1,0,0,
                                      in_stack_ffffffffffffff30);
                  if (iVar11 != 0) goto LAB_fffffff009cb85d4;
                  *(undefined1 *)(lVar27 + 0x1a) = 0xfe;
                }
              }
              else if (((int)param_7[0x4c7] != 0) && ((*(byte *)((long)param_7 + 500) & 1) != 0)) {
                pcVar17 = 
                "AppleUSBXDCI::%s:kEpCommandStartXfer failed - event status %d for ep 0x%02x\n";
                goto LAB_fffffff009cb8844;
              }
            }
          }
          else if (uVar9 == 3) {
            if (*(char *)(lVar27 + 0x1a) == -1) {
              uVar22 = *puVar14;
              local_70 = &DAT_aaaaaaaaaaaaaaaa;
              uVar15 = thunk_FUN_fffffff00a39bc88();
              thunk_FUN_fffffff00a39c228(uVar15,(long *)&local_70);
              if (((int)param_7[0x4c7] != 0) && ((*(byte *)((long)param_7 + 500) >> 6 & 1) != 0)) {
                in_stack_ffffffffffffff30 = "filterOccurredIsoc";
                FUN_fffffff009cacb28
                          ((ulong)param_7,
                           (byte *)"AppleUSBXDCI::%s:futureFrameNumber read value %d interval %d\n")
                ;
              }
              iVar10 = (**(code **)(*param_7 + 0x5c0))(param_7);
              uVar8 = *(int *)(lVar27 + 0x10) - 1;
              iVar11 = 1 << (ulong)(uVar8 & 0x1f);
              uVar9 = -iVar11;
              if (uVar8 < 4) {
                iVar11 = 8;
              }
              uVar8 = *(int *)(lVar27 + 0x10) + (uVar22 >> 0x10);
              if (1 < iVar10) {
                uVar8 = (uVar22 >> 0x10 & uVar9) + iVar11;
              }
              if (((int)param_7[0x4c7] != 0) && ((*(byte *)((long)param_7 + 500) >> 6 & 1) != 0)) {
                in_stack_ffffffffffffff30 = "filterOccurredIsoc";
                FUN_fffffff009cacb28
                          ((ulong)param_7,
                           (byte *)"AppleUSBXDCI::%s:futureFrameNumber write value %d\n");
              }
              if (*(int *)(lVar27 + 0x90) < 1) {
                *(uint *)(lVar27 + 0x28) = uVar8 & 0xffff;
                *(undefined1 **)(lVar27 + 0x30) = local_70;
              }
              else {
                puVar16 = FUN_fffffff009cabab4(*(long *)(lVar27 + 0x98));
                in_stack_ffffffffffffff30 =
                     (char *)((ulong)in_stack_ffffffffffffff30 & 0xffffffff00000000);
                iVar11 = (**(code **)(*param_7 + 0x7e0))
                                   (param_7,*(undefined1 *)(lVar27 + 0xc),6,uVar8 & 0xffff,0,1,
                                    (ulong)puVar16 >> 0x20,puVar16,in_stack_ffffffffffffff30);
                if (iVar11 == 0) {
                  *(undefined1 *)(lVar27 + 0x1a) = 0xfe;
                  *(undefined4 *)(lVar27 + 0x28) = 0xffffffff;
                }
                else {
LAB_fffffff009cb85d4:
                  if (((int)param_7[0x4c7] != 0) &&
                     ((*(uint *)((long)param_7 + 500) & 0x80000001) != 0)) {
                    pcVar17 = "AppleUSBXDCI::%s:failed send kEpCommandStartXfer - status 0x%08x\n";
                    goto LAB_fffffff009cb8844;
                  }
                }
              }
            }
          }
          else if (((int)param_7[0x4c7] != 0) && ((*(byte *)((long)param_7 + 500) >> 6 & 1) != 0)) {
            pcVar17 = "AppleUSBXDCI::%s:unexpected event %d\n";
            goto LAB_fffffff009cb8844;
          }
          thunk_FUN_fffffff00a22c478((undefined8 *)param_7[0x8d]);
          thunk_FUN_fffffff00a393504();
          puVar25 = (uint *)PTR_DAT_fffffff0080813c0;
        }
      }
      else if ((uVar22 >> 8 & 0xf) == 0xb) {
        if (((int)param_7[0x4c7] != 0) && ((*(byte *)((long)param_7 + 500) & 1) != 0)) {
          in_stack_ffffffffffffff30 = "filterOccurredIsoc";
          FUN_fffffff009cacb28
                    ((ulong)param_7,
                     (byte *)"AppleUSBXDCI::%s:Event buffer overflow, flushing the event queue\n");
        }
        (**(code **)(*plVar20 + 0xa8))(plVar20,1);
        (**(code **)(*plVar20 + 0xa0))(plVar20);
      }
      else if (((int)param_7[0x4c7] != 0) && ((*(byte *)((long)param_7 + 500) >> 6 & 1) != 0)) {
        pcVar17 = "AppleUSBXDCI::%s:unknown device event %d\n";
        goto LAB_fffffff009cb86ec;
      }
      puVar14 = (uint *)(**(code **)(*plVar20 + 0x88))(plVar20);
      auVar28 = extraout_q0_01;
    } while (puVar14 != (uint *)0x0);
  }
  (**(code **)(*plVar20 + 0xb8))(plVar20);
  return 0;
}

