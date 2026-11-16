// FUN_fffffff008906f30 @ fffffff008906f30 size=4904
// CALLERS:
//   fffffff00af7810b no-fn
//   fffffff00890d188 FUN_fffffff00890ce64@fffffff00890ce64
// CALLEES:
//   fffffff008a4a498 thunk_EXT_FUN_80110000038be65c
//   fffffff008908648 FUN_fffffff008908648
//   fffffff00892a104 FUN_fffffff00892a104
//   fffffff008908258 FUN_fffffff008908258
//   fffffff00896f238 FUN_fffffff00896f238
//   fffffff0089082b0 FUN_fffffff0089082b0
//   fffffff0089875d4 FUN_fffffff0089875d4
//   fffffff0089aab80 FUN_fffffff0089aab80
//   fffffff008977f40 FUN_fffffff008977f40
//   fffffff008a4ae68 thunk_EXT_FUN_801100000389b3b0
//   fffffff0089875fc FUN_fffffff0089875fc

ulong FUN_fffffff008906f30(long param_1,long param_2)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  byte bVar5;
  code *pcVar6;
  long lVar7;
  ulong *puVar8;
  long *plVar9;
  uint uVar10;
  int iVar11;
  long lVar12;
  long *plVar13;
  bool bVar14;
  ulong *puVar15;
  long *plVar16;
  uint uVar17;
  ulong *puVar18;
  ulong uVar19;
  ulong uVar20;
  long lVar21;
  ulong uVar22;
  undefined4 *puVar23;
  undefined4 *puVar24;
  long lVar25;
  ulong uVar26;
  uint *puVar27;
  ulong uVar28;
  ulong uVar29;
  ulong uVar30;
  ulong uVar31;
  char *in_stack_fffffffffffffeb0;
  ulong in_stack_fffffffffffffec0;
  long local_f0;
  long lStack_e8;
  long local_e0;
  long local_d8;
  long local_d0;
  long lStack_c8;
  long local_c0;
  long lStack_b8;
  undefined8 local_b0;
  long lStack_a8;
  long local_a0;
  long local_98;
  long local_90;
  long lStack_88;
  long local_78;
  long local_70;
  
  if (((0x100 < *(uint *)(param_2 + 0x38)) || (0xc < *(uint *)(param_2 + 0x3950))) ||
     (0x100 < *(uint *)(param_2 + 0x3040))) {
    thunk_EXT_FUN_801100000389b3b0
              (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
               "[ERROR] %s: %s: numInputFreeEvents:%d, totalOutSet:%d, totalInput: %d\n");
    return 0xe00002c2;
  }
  local_78 = 0;
  local_70 = 0;
  local_90 = 0;
  lStack_88 = 0;
  FUN_fffffff008977f40
            (&local_90,*(undefined8 *)(*(long *)(param_1 + 0xb8) + 0x60),
             *(undefined8 *)(param_2 + 0x10),&local_78,0);
  lVar25 = local_70;
  lVar12 = local_78;
  if ((local_90 == 0) || (local_78 == 0)) {
    uVar30 = 0xe00002c2;
    thunk_EXT_FUN_801100000389b3b0
              (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
               "[ERROR] %s: %s: Program or process not found for handle 0x%llx\n");
    goto LAB_fffffff00890823c;
  }
  if (local_70 != 0) {
    FUN_fffffff0089875d4(local_70);
  }
  lVar7 = *(long *)(param_1 + 0x98);
  *(long *)(param_1 + 0x90) = lVar12;
  *(long *)(param_1 + 0x98) = lVar25;
  if (lVar7 != 0) {
    FUN_fffffff0089875fc();
    lVar12 = *(long *)(param_1 + 0x90);
    lVar25 = *(long *)(param_1 + 0x98);
  }
  local_a0 = lVar12;
  local_98 = lVar25;
  if (lVar25 != 0) {
    FUN_fffffff0089875d4(lVar25);
  }
  FUN_fffffff0089aab80(param_1,&local_a0);
  if (local_98 != 0) {
    FUN_fffffff0089875fc();
  }
  lVar25 = local_90;
  *(undefined8 *)(param_1 + 0xe0) = *(undefined8 *)(param_2 + 0x10);
  lVar12 = *(long *)(param_2 + 0xa628);
  if (lVar12 == 0) {
LAB_fffffff0089070e0:
    lVar12 = 0;
    if (*(long *)(*(long *)(param_1 + 0x90) + 0x150) != 0) {
      thunk_EXT_FUN_801100000389b3b0
                (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                 "[ERROR] %s: %s: One chaining/program - Please call ANEProgramStop to remove the existing chainingCacheRequest for a new request\n"
                );
      uVar30 = 0xe00002c5;
      goto LAB_fffffff00890823c;
    }
  }
  else if (lVar12 != *(long *)(local_90 + 0x178)) {
    *(undefined8 *)(param_2 + 0xa628) = 0;
    goto LAB_fffffff0089070e0;
  }
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_2 + 0x28);
  *(undefined8 *)(param_1 + 0xf0) = *(undefined8 *)(param_2 + 0x20);
  *(long *)(param_1 + 0xf8) = lVar12;
  uVar10 = *(uint *)(param_2 + 0x18);
  if (uVar10 < 2) {
    if (uVar10 < *(uint *)(local_90 + 0x1fb4)) {
      *(uint *)(param_1 + 0xd0) = uVar10;
    }
    else {
      if (*(uint *)(local_90 + 0x1fb4) != 1) {
        uVar30 = 0xe00002c2;
        thunk_EXT_FUN_801100000389b3b0
                  (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                   "[ERROR] %s: %s: procedureId: 0x%x not found!\n");
        goto LAB_fffffff00890823c;
      }
      *(undefined4 *)(param_1 + 0xd0) = 0;
      if ((DAT_fffffff00ae02f29 >> 2 & 1) != 0) {
        if (DAT_fffffff00adfd680 < 4) {
          lVar12 = (ulong)DAT_fffffff00adfd680 * 8;
          puVar2 = (undefined8 *)(&UNK_fffffff007db2928 + (int)lVar12);
          if (lVar12 - (int)lVar12 != 0) {
            puVar2 = (undefined8 *)
                     ((ulong)(&UNK_fffffff007db2928 + lVar12) & 0xffffffffffff | 0x2bad000000000000)
            ;
          }
          in_stack_fffffffffffffeb0 = (char *)*puVar2;
        }
        else {
          in_stack_fffffffffffffeb0 = "";
        }
        in_stack_fffffffffffffec0 = *(ulong *)(local_90 + 0x1fb8);
        thunk_EXT_FUN_801100000389b3b0
                  (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                   "%s: %s: Single procedure case: Defaulting to procedure 0: %s\n");
      }
    }
    if (*(long *)(lVar25 + 0x1f28) == 0) {
      if ((DAT_fffffff00ae02f29 >> 6 & 1) != 0) {
        if (DAT_fffffff00adfd680 < 4) {
          lVar12 = (ulong)DAT_fffffff00adfd680 * 8;
          puVar2 = (undefined8 *)(&UNK_fffffff007db2928 + (int)lVar12);
          if (lVar12 - (int)lVar12 != 0) {
            puVar2 = (undefined8 *)
                     ((ulong)(&UNK_fffffff007db2928 + lVar12) & 0xffffffffffff | 0x2bad000000000000)
            ;
          }
          in_stack_fffffffffffffeb0 = (char *)*puVar2;
        }
        else {
          in_stack_fffffffffffffeb0 = "";
        }
        thunk_EXT_FUN_801100000389b3b0
                  (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                   "%s: %s: Network doesn\'t requre intermediate buffer, return 0 for intermediateBufferHandle\n"
                  );
      }
    }
    else {
      uVar30 = FUN_fffffff00892a104(*(undefined8 *)(param_1 + 0x90),0);
      if ((int)uVar30 != 0) {
        thunk_EXT_FUN_801100000389b3b0
                  (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                   "[ERROR] %s: %s: failed to allocate intermediate buffer for program 0x%llx\n");
        goto LAB_fffffff00890823c;
      }
      FUN_fffffff008908258(param_1 + 0x100,*(long *)(param_1 + 0x90) + 0xd0);
      if (*(long *)(param_1 + 0x100) != 0) {
        FUN_fffffff00896f238
                  (*(long *)(param_1 + 0x100),*(undefined4 *)(param_1 + 0xa0),
                   *(undefined1 *)(param_1 + 0xe8),
                   *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x90) + 0xe0) + 0x70),0);
        lStack_a8 = *(long *)(param_1 + 0x108);
        local_b0 = *(undefined8 *)(param_1 + 0x100);
        if (*(long *)(param_1 + 0x108) != 0) {
          FUN_fffffff0089875d4();
        }
        FUN_fffffff0089aab80(param_1,&local_b0);
        if (lStack_a8 != 0) {
          FUN_fffffff0089875fc();
        }
      }
    }
    *(undefined4 *)(param_1 + 0x3118) = *(undefined4 *)(param_2 + 0x3944);
    *(undefined8 *)(param_1 + 0x3130) = *(undefined8 *)(param_2 + 0x3948);
    *(undefined4 *)(param_1 + 0x311c) = 4;
    uVar10 = *(uint *)(param_2 + 0x38);
    uVar30 = (ulong)uVar10;
    *(uint *)(param_1 + 0x110) = uVar10;
    if (uVar10 != 0) {
      lVar12 = 0;
      do {
        puVar23 = (undefined4 *)(param_2 + 0x40U + lVar12 * 0x30);
        if (((param_2 + 0x40U ^ (ulong)puVar23) & 0xffc0000000000000) != 0) {
          puVar23 = (undefined4 *)((ulong)puVar23 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar3 = *puVar23;
        puVar24 = (undefined4 *)(param_1 + 0x118U + lVar12 * 0x30);
        if (((param_1 + 0x118U ^ (ulong)puVar24) & 0xffc0000000000000) != 0) {
          puVar24 = (undefined4 *)((ulong)puVar24 & 0xffffffffffff | 0xc8a2000000000000);
        }
        *(undefined8 *)(puVar24 + 6) = *(undefined8 *)(puVar23 + 6);
        *puVar24 = uVar3;
        puVar24[1] = 5;
        puVar24[4] = puVar23[4];
        lVar12 = lVar12 + 1;
        uVar30 = uVar30 - 1;
      } while (uVar30 != 0);
    }
    uVar10 = *(uint *)(param_2 + 0x3040);
    uVar26 = (ulong)uVar10;
    *(uint *)(param_1 + 0x3148) = uVar10;
    *(undefined4 *)(param_1 + 0x3170) = *(undefined4 *)(param_2 + 0x3950);
    uVar30 = uVar26 << 5 | 0x18;
    puVar8 = (ulong *)thunk_EXT_FUN_80110000038be65c(&DAT_fffffff007dc8830,uVar30);
    *puVar8 = uVar30;
    puVar8[1] = 0x20;
    puVar8[2] = uVar26;
    puVar8 = puVar8 + 3;
    if (uVar10 != 0) {
      puVar15 = puVar8 + uVar26 * 4;
      puVar18 = puVar8;
      if ((((ulong)puVar8 ^ (ulong)puVar15) & 0xffc0000000000000) != 0) {
        puVar15 = (ulong *)((ulong)puVar15 & 0xffffffffffff | 0xc8a2000000000000);
      }
      do {
        puVar18[2] = 0;
        puVar18[3] = 0;
        puVar18 = puVar18 + 4;
      } while (puVar18 != puVar15);
    }
    *(ulong **)(param_1 + 0x3150) = puVar8;
    uVar10 = *(uint *)(param_1 + 0x3170);
    uVar30 = (ulong)uVar10;
    lVar12 = uVar30 * 0x50 + 0x18;
    plVar9 = (long *)thunk_EXT_FUN_80110000038be65c(&DAT_fffffff007dc8880,lVar12);
    *plVar9 = lVar12;
    plVar9[1] = 0x50;
    plVar9[2] = uVar30;
    plVar9 = plVar9 + 3;
    if (uVar10 != 0) {
      plVar13 = plVar9 + uVar30 * 10;
      plVar16 = plVar9;
      if ((((ulong)plVar9 ^ (ulong)plVar13) & 0xffc0000000000000) != 0) {
        plVar13 = (long *)((ulong)plVar13 & 0xffffffffffff | 0xc8a2000000000000);
      }
      do {
        plVar16[3] = 0;
        plVar16[2] = 0;
        plVar16[5] = 0;
        plVar16[4] = 0;
        plVar16[8] = 0;
        plVar16[7] = 0;
        plVar16[9] = 0;
        plVar16 = plVar16 + 10;
      } while (plVar16 != plVar13);
    }
    *(long **)(param_1 + 0x3178) = plVar9;
    uVar26 = *(ulong *)(param_1 + 0x3150);
    if (uVar26 == 0) {
      thunk_EXT_FUN_801100000389b3b0
                (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                 "[ERROR] %s: %s: failed to allocate chaining inputs or output sets\n");
      uVar30 = 0xe00002bd;
    }
    else {
      *(undefined4 *)(param_1 + 0x3158) = 0;
      *(undefined1 *)(param_1 + 0x315c) = 0;
      *(undefined8 *)(param_1 + 0x3160) = 0;
      uVar10 = *(uint *)(param_1 + 0x3148);
      uVar19 = (ulong)uVar10;
      uVar4 = *(uint *)(param_1 + 0x3170);
      if ((DAT_fffffff00ae02f29 >> 6 & 1) != 0) {
        if (DAT_fffffff00adfd680 < 4) {
          lVar12 = (ulong)DAT_fffffff00adfd680 * 8;
          puVar2 = (undefined8 *)(&UNK_fffffff007db2928 + (int)lVar12);
          if (lVar12 - (int)lVar12 != 0) {
            puVar2 = (undefined8 *)
                     ((ulong)(&UNK_fffffff007db2928 + lVar12) & 0xffffffffffff | 0x2bad000000000000)
            ;
          }
          in_stack_fffffffffffffeb0 = (char *)*puVar2;
        }
        else {
          in_stack_fffffffffffffeb0 = "";
        }
        in_stack_fffffffffffffec0 = uVar19;
        thunk_EXT_FUN_801100000389b3b0
                  (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0,
                   "%s: %s: total chaining input buffers: %d, output sets: %d\n");
        uVar10 = *(uint *)(param_1 + 0x3148);
      }
      if (uVar10 != 0) {
        uVar28 = 0;
        lVar7 = *(long *)(lVar25 + 0x1fb8);
        uVar30 = (ulong)*(uint *)(param_1 + 0xd0);
        lVar12 = uVar30 * 0xb40 + 0x600;
        puVar27 = (uint *)(lVar7 + (int)lVar12);
        if (lVar12 != (int)lVar12) {
          puVar27 = (uint *)(lVar7 + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar20 = (ulong)*puVar27;
        do {
          bVar5 = *(byte *)(param_2 + 0x3444 + uVar28);
          if ((int)uVar20 == 0) {
LAB_fffffff008908080:
            uVar30 = 0xe00002c2;
            thunk_EXT_FUN_801100000389b3b0
                      (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                       "[ERROR] %s: %s: failed to find match inputs with inputIndex: %d from bufferSymbolIndex[%d]\n"
                      );
LAB_fffffff008907f1c:
            thunk_EXT_FUN_801100000389b3b0
                      (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                       "[ERROR] %s: %s: failed when processing input buffers\n");
            thunk_EXT_FUN_801100000389b3b0
                      (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                       "[ERROR] %s: %s: failed when processing input buffers\n");
            goto LAB_fffffff00890823c;
          }
          uVar29 = 0;
          bVar14 = false;
          lVar12 = uVar30 * 0xb40;
          uVar22 = lVar7 + (int)lVar12;
          if (lVar12 - (int)lVar12 != 0) {
            uVar22 = lVar7 + lVar12 & 0xffffffffffffU | 0x2bad000000000000;
          }
          uVar31 = uVar26 + uVar28 * 0x20;
          if (((uVar26 ^ uVar31) & 0xffc0000000000000) != 0) {
            uVar31 = uVar31 & 0xffffffffffff | 0xc8a2000000000000;
          }
          do {
            lVar12 = lStack_88;
            lVar21 = uVar29 * 4;
            puVar27 = (uint *)(uVar22 + 0x204 + (long)(int)lVar21);
            if (lVar21 - (int)lVar21 != 0) {
              puVar27 = (uint *)(uVar22 + 0x204 + lVar21 & 0xffffffffffff | 0x2bad000000000000);
            }
            if ((*puVar27 == (uint)bVar5) || (*(uint *)(lVar7 + 0x204 + uVar29 * 4) == (uint)bVar5))
            {
              if (uVar19 <= uVar28) goto LAB_fffffff008908148;
              lStack_b8 = lStack_88;
              local_c0 = local_90;
              if (lStack_88 == 0) {
                uVar30 = FUN_fffffff0089082b0
                                   (param_1,uVar31 + 0x10,&local_c0,
                                    *(undefined4 *)(param_2 + 0x3544 + uVar28 * 4),1,bVar5);
              }
              else {
                FUN_fffffff0089875d4(lStack_88);
                uVar30 = FUN_fffffff0089082b0
                                   (param_1,uVar31 + 0x10,&local_c0,
                                    *(undefined4 *)(param_2 + 0x3544 + uVar28 * 4),1,bVar5);
                FUN_fffffff0089875fc(lVar12);
              }
              if ((int)uVar30 != 0) {
                thunk_EXT_FUN_801100000389b3b0
                          (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                           "[ERROR] %s: %s: could not create client resource for input surface (%u)\n"
                          );
                goto LAB_fffffff008907f1c;
              }
              iVar11 = *(int *)(param_2 + 0x3044 + uVar28 * 4);
              *(int *)(uVar31 + 8) = iVar11;
              if (iVar11 == 4) {
                *(int *)(param_1 + 0x3158) = *(int *)(param_1 + 0x3158) + 1;
              }
              bVar14 = true;
            }
            uVar29 = uVar29 + 1;
            lVar7 = *(long *)(lVar25 + 0x1fb8);
            uVar30 = (ulong)*(uint *)(param_1 + 0xd0);
            lVar12 = uVar30 * 0xb40;
            uVar22 = lVar7 + (int)lVar12;
            if (lVar12 - (int)lVar12 != 0) {
              uVar22 = lVar7 + lVar12 & 0xffffffffffffU | 0x2bad000000000000;
            }
            uVar20 = (ulong)*(uint *)(uVar22 + 0x600);
          } while (uVar29 < uVar20);
          if (!bVar14) goto LAB_fffffff008908080;
          uVar28 = uVar28 + 1;
        } while (uVar28 < *(uint *)(param_1 + 0x3148));
      }
      if (*(int *)(param_1 + 0x3170) != 0) {
        if (uVar4 != 0) {
          uVar26 = 0;
          uVar30 = 0;
          do {
            lVar12 = lStack_88;
            iVar11 = (int)(uVar26 * 0x50);
            puVar23 = (undefined4 *)((long)plVar9 + (long)iVar11);
            if (uVar26 * 0x50 - (long)iVar11 != 0) {
              puVar23 = (undefined4 *)
                        ((ulong)(plVar9 + uVar26 * 10) & 0xffffffffffff | 0x2bad000000000000);
            }
            puVar24 = (undefined4 *)(param_2 + 0x3954U + uVar26 * 0x910);
            if (((param_2 + 0x3954U ^ (ulong)puVar24) & 0xffc0000000000000) != 0) {
              puVar24 = (undefined4 *)((ulong)puVar24 & 0xffffffffffff | 0xc8a2000000000000);
            }
            iVar11 = puVar24[1];
            *puVar23 = *puVar24;
            if (iVar11 != 0) {
              lStack_c8 = lStack_88;
              local_d0 = local_90;
              if (lStack_88 == 0) {
                uVar30 = FUN_fffffff0089082b0(param_1,puVar23 + 4,&local_d0,iVar11,10,0);
              }
              else {
                FUN_fffffff0089875d4(lStack_88);
                uVar30 = FUN_fffffff0089082b0(param_1,puVar23 + 4,&local_d0,puVar24[1],10,0);
                FUN_fffffff0089875fc(lVar12);
              }
              if ((int)uVar30 == 0) goto LAB_fffffff008907a2c;
              thunk_EXT_FUN_801100000389b3b0
                        (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                         "[ERROR] %s: %s: could not create client resource for stats surface (%u)\n"
                        );
LAB_fffffff0089081cc:
              thunk_EXT_FUN_801100000389b3b0
                        (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                         "[ERROR] %s: %s: Failed when processing output buffers\n");
              goto LAB_fffffff00890823c;
            }
LAB_fffffff008907a2c:
            if (puVar24[2] != 0) {
              uVar19 = *(ulong *)(*(long *)(*(long *)(param_1 + 0xb8) + 0x10) + 0x38);
              uVar30 = 0;
              if (uVar19 != 0) {
                uVar30 = ((uVar19 + (uint)puVar24[2]) - 1) / uVar19;
              }
              in_stack_fffffffffffffec0 = in_stack_fffffffffffffec0 & 0xffffffffffffff00;
              in_stack_fffffffffffffeb0 =
                   (char *)((ulong)in_stack_fffffffffffffeb0 & 0xffffff0000000000);
              uVar30 = (**(code **)(**(long **)(param_1 + 0xa8) + 0x628))
                                 (*(long **)(param_1 + 0xa8),uVar30 * uVar19,puVar23 + 8,0x4d495343,
                                  1,0,*(undefined8 *)(param_2 + 0xa618),1,in_stack_fffffffffffffeb0,
                                  0,in_stack_fffffffffffffec0);
              if (((int)uVar30 == 0) && (lVar12 = *(long *)(puVar23 + 8), lVar12 != 0)) {
                local_d8 = *(long *)(puVar23 + 10);
                local_e0 = lVar12;
                if (local_d8 != 0) {
                  FUN_fffffff0089875d4();
                }
                FUN_fffffff0089aab80(param_1,&local_e0);
                if (local_d8 != 0) {
                  FUN_fffffff0089875fc();
                }
                uVar30 = 0;
              }
              else {
                in_stack_fffffffffffffeb0 = "";
                if (DAT_fffffff00adfd680 < 4) {
                  lVar12 = (ulong)DAT_fffffff00adfd680 * 8;
                  puVar2 = (undefined8 *)(&UNK_fffffff007db2928 + (int)lVar12);
                  if (lVar12 - (int)lVar12 != 0) {
                    puVar2 = (undefined8 *)
                             ((ulong)(&UNK_fffffff007db2928 + lVar12) & 0xffffffffffff |
                             0x2bad000000000000);
                  }
                  in_stack_fffffffffffffeb0 = (char *)*puVar2;
                }
                in_stack_fffffffffffffec0 = uVar30;
                thunk_EXT_FUN_801100000389b3b0
                          (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                           "[ERROR] %s: %s: Could not create raw stats buffer result=0x%x\n");
              }
            }
            uVar10 = puVar24[3];
            puVar23[0xd] = uVar10;
            if (0x100 < uVar10) {
              uVar30 = 0xe00002c2;
              thunk_EXT_FUN_801100000389b3b0
                        (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                         "[ERROR] %s: %s: Current set(%d) totalOutput (%d) exceeds max (%d)\n");
              goto LAB_fffffff0089081cc;
            }
            FUN_fffffff008908648(puVar23 + 0xe);
            lVar12 = (ulong)*(uint *)(param_1 + 0xd0) * 0xb40;
            uVar19 = *(long *)(lVar25 + 0x1fb8) + (long)(int)lVar12;
            if (lVar12 - (int)lVar12 != 0) {
              uVar19 = *(long *)(lVar25 + 0x1fb8) + lVar12 & 0xffffffffffffU | 0x2bad000000000000;
            }
            if (*(int *)(uVar19 + 0xa00) != 0) {
              uVar28 = 0;
              puVar1 = puVar24 + 0x144;
              uVar29 = (ulong)(uint)puVar23[0xd];
              uVar20 = uVar30;
              do {
                lVar12 = uVar28 * 4;
                puVar27 = (uint *)(uVar19 + 0x604 + (long)(int)lVar12);
                if (lVar12 - (int)lVar12 != 0) {
                  puVar27 = (uint *)(uVar19 + 0x604 + lVar12 & 0xffffffffffff | 0x2bad000000000000);
                }
                uVar10 = *puVar27;
                uVar19 = (ulong)uVar10;
                if (uVar29 == 0) {
LAB_fffffff008907e28:
                  thunk_EXT_FUN_801100000389b3b0
                            (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                             "[ERROR] %s: %s: output buffer NOT found bufferIndex=%d with outputSymbolIndex[%d] \n"
                            );
                  uVar30 = 0xe00002c2;
LAB_fffffff008907d94:
                  in_stack_fffffffffffffeb0 = "";
                  if (DAT_fffffff00adfd680 < 4) {
                    lVar12 = (ulong)DAT_fffffff00adfd680 * 8;
                    puVar2 = (undefined8 *)(&UNK_fffffff007db2928 + (int)lVar12);
                    if (lVar12 - (int)lVar12 != 0) {
                      puVar2 = (undefined8 *)
                               ((ulong)(&UNK_fffffff007db2928 + lVar12) & 0xffffffffffff |
                               0x2bad000000000000);
                    }
                    in_stack_fffffffffffffeb0 = (char *)*puVar2;
                  }
                  thunk_EXT_FUN_801100000389b3b0
                            (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                             "[ERROR] %s: %s: Failed when processing output buffers\n");
                  in_stack_fffffffffffffec0 = uVar19;
                  break;
                }
                uVar30 = 0;
                bVar14 = false;
                do {
                  lVar12 = lStack_88;
                  uVar17 = (uint)*(byte *)((long)puVar24 + uVar30 + 0x410);
                  if ((uVar10 == uVar17) ||
                     (*(uint *)(*(long *)(lVar25 + 0x1fb8) + 0x604 + uVar28 * 4) == uVar17)) {
                    lVar7 = *(long *)(puVar23 + 0xe);
                    if ((ulong)(*(long *)(puVar23 + 0x10) - lVar7 >> 4) <= uVar30)
                    goto LAB_fffffff008908148;
                    lVar21 = uVar30 * 0x10;
                    uVar20 = lVar7 + (int)lVar21;
                    if (lVar21 - (int)lVar21 != 0) {
                      uVar20 = lVar7 + lVar21 & 0xffffffffffffU | 0x2bad000000000000;
                    }
                    lStack_e8 = lStack_88;
                    local_f0 = local_90;
                    if (lStack_88 == 0) {
                      puVar27 = puVar1 + uVar30;
                      if ((((ulong)puVar1 ^ (ulong)puVar27) & 0xffc0000000000000) != 0) {
                        puVar27 = (uint *)((ulong)puVar27 & 0xffffffffffff | 0xc8a2000000000000);
                      }
                      uVar20 = FUN_fffffff0089082b0(param_1,uVar20,&local_f0,*puVar27,2,uVar19);
                      iVar11 = (int)uVar20;
                    }
                    else {
                      FUN_fffffff0089875d4(lStack_88);
                      puVar27 = puVar1 + uVar30;
                      if ((((ulong)puVar1 ^ (ulong)puVar27) & 0xffc0000000000000) != 0) {
                        puVar27 = (uint *)((ulong)puVar27 & 0xffffffffffff | 0xc8a2000000000000);
                      }
                      uVar20 = FUN_fffffff0089082b0(param_1,uVar20,&local_f0,*puVar27,2,uVar19);
                      FUN_fffffff0089875fc(lVar12);
                      iVar11 = (int)uVar20;
                    }
                    if (iVar11 != 0) {
                      uVar19 = (ulong)*puVar27;
                      thunk_EXT_FUN_801100000389b3b0
                                (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
                                 "[ERROR] %s: %s: could not create client resource for output surface (%u)\n"
                                );
                      uVar30 = uVar20;
                      goto LAB_fffffff008907d94;
                    }
                    uVar29 = (ulong)(uint)puVar23[0xd];
                    bVar14 = true;
                  }
                  uVar30 = uVar30 + 1;
                } while (uVar30 < uVar29);
                if (!bVar14) goto LAB_fffffff008907e28;
                uVar30 = uVar20;
                uVar19 = in_stack_fffffffffffffec0;
                if ((int)uVar20 != 0) goto LAB_fffffff008907d94;
                uVar30 = 0;
                uVar28 = uVar28 + 1;
                lVar12 = (ulong)*(uint *)(param_1 + 0xd0) * 0xb40;
                uVar19 = *(long *)(lVar25 + 0x1fb8) + (long)(int)lVar12;
                if (lVar12 - (int)lVar12 != 0) {
                  uVar19 = *(long *)(lVar25 + 0x1fb8) + lVar12 & 0xffffffffffffU |
                           0x2bad000000000000;
                }
              } while (uVar28 < *(uint *)(uVar19 + 0xa00));
            }
            uVar10 = (int)uVar26 + 1;
            uVar26 = (ulong)uVar10;
            if (*(uint *)(param_1 + 0x3170) <= uVar10) {
              if ((int)uVar30 != 0) goto LAB_fffffff0089081cc;
              goto LAB_fffffff00890823c;
            }
          } while (uVar10 != uVar4);
        }
LAB_fffffff008908148:
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x800,0xfffffff00890814c);
        (*pcVar6)();
      }
      uVar30 = 0;
    }
  }
  else {
    thunk_EXT_FUN_801100000389b3b0
              (&MACH_HEADER,PTR_DAT_fffffff007dd17d8,0x10,
               "[ERROR] %s: %s: procedureId (%u) exceed max allowed chaining procedures (%d)\n");
    uVar30 = 0xe00002e2;
  }
LAB_fffffff00890823c:
  if (lStack_88 != 0) {
    FUN_fffffff0089875fc();
  }
  if (local_70 != 0) {
    FUN_fffffff0089875fc();
  }
  return uVar30;
}

