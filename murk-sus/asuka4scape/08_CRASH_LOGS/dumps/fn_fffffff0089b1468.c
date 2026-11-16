// FUN_fffffff0089b1468 @ fffffff0089b1468 size=4096
// CALLERS:
//   fffffff00afb8857 no-fn
//   fffffff0089b2864 FUN_fffffff0089b2708@fffffff0089b2708
//   fffffff0089b1348 FUN_fffffff0089b1310@fffffff0089b1310
// CALLEES:
//   fffffff0089a50b8 FUN_fffffff0089a50b8
//   fffffff0089b3e54 FUN_fffffff0089b3e54
//   fffffff008a820d4 thunk_EXT_FUN_8011000003397c88
//   fffffff0089c46a4 FUN_fffffff0089c46a4
//   fffffff0089a4b90 FUN_fffffff0089a4b90
//   fffffff008a8031c FUN_fffffff008a8031c
//   fffffff008a82064 thunk_EXT_FUN_80110000036da494
//   fffffff00898e68c FUN_fffffff00898e68c
//   fffffff008a81ee4 thunk_EXT_FUN_8011000003398228
//   fffffff008a81534 thunk_EXT_FUN_80110000038ff214
//   fffffff0089609c8 FUN_fffffff0089609c8
//   fffffff0089c46cc FUN_fffffff0089c46cc
//   fffffff00898d588 FUN_fffffff00898d588
//   fffffff008a7c8c8 FUN_fffffff008a7c8c8
//   fffffff008a81574 thunk_EXT_FUN_80110000038ff2e0
//   fffffff008a81ed4 thunk_EXT_FUN_80110000038db19c
//   fffffff0089a5e60 FUN_fffffff0089a5e60
//   fffffff0089b3f9c FUN_fffffff0089b3f9c
//   fffffff008a7bf58 FUN_fffffff008a7bf58
//   fffffff008a80388 FUN_fffffff008a80388

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff0089b1468(long param_1,long param_2)

{
  uint *puVar1;
  long lVar2;
  byte bVar3;
  ulong uVar4;
  undefined *puVar5;
  code *pcVar6;
  bool bVar7;
  byte bVar8;
  undefined1 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  ulong uVar13;
  undefined8 uVar14;
  long lVar15;
  ulong uVar16;
  ulong *puVar17;
  long lVar18;
  ulong uVar19;
  ulong uVar20;
  long *plVar21;
  ulong uVar22;
  undefined4 uVar23;
  long *plVar24;
  long lVar25;
  undefined8 uVar26;
  byte bVar27;
  uint uVar28;
  long lVar29;
  long lVar30;
  long lVar31;
  ulong local_170;
  uint5 uStack_168;
  undefined3 uStack_163;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  ulong local_a0;
  undefined8 uStack_98;
  undefined4 local_90;
  uint uStack_8c;
  ulong local_88;
  undefined4 local_7c;
  undefined8 local_78;
  ulong local_70 [2];
  
  thunk_EXT_FUN_80110000036da494
            (0x61b0185,*(undefined8 *)(*(long *)(param_2 + 0x120) + 0xc0),
             *(undefined4 *)(param_2 + 0x10c),*(undefined8 *)(param_2 + 0x100),0xffff,0);
  lVar30 = *(long *)(param_1 + 0x328);
  if (lVar30 != 0) {
    thunk_EXT_FUN_80110000038ff214(lVar30);
  }
  lVar29 = *(long *)(param_2 + 0x120);
  lVar2 = *(long *)(param_2 + 0x128);
  if (lVar2 != 0) {
    FUN_fffffff0089c46a4(lVar2);
  }
  if (lVar29 == 0) {
    uVar14 = 0xe00002c2;
    FUN_fffffff008a80388();
    goto LAB_fffffff0089b23fc;
  }
  plVar24 = *(long **)(lVar29 + 0x5d0);
  lVar31 = *(long *)(lVar29 + 0x5d8);
  if (lVar31 != 0) {
    FUN_fffffff0089c46a4(lVar31);
  }
  if (plVar24 == (long *)0x0) {
    uVar14 = 0xe00002c2;
    FUN_fffffff008a8031c();
  }
  else {
    bVar8 = (**(code **)(*plVar24 + 0x70))(plVar24,*(undefined4 *)(param_2 + 0x10c));
    uVar10 = (**(code **)(*plVar24 + 0x78))(plVar24,*(undefined4 *)(param_2 + 0x10c));
    bVar27 = 0;
    bVar3 = *(byte *)(param_2 + 0xa0);
    local_78 = 0xffffffffffffffff;
    local_7c = 0;
    puVar17 = (ulong *)(lVar29 + 0xc0);
    local_a0 = *puVar17;
    uStack_98 = *(undefined8 *)(param_2 + 0x100);
    local_a8 = *(undefined8 *)(param_2 + 0x40);
    uVar28 = *(uint *)(param_2 + 0x42c0);
    uVar12 = *(uint *)(param_2 + 0x42c4);
    local_88 = (ulong)((CONCAT15((uVar28 & uVar28 - 1) != 0,
                                 CONCAT14(*(undefined1 *)(param_2 + 0x29ed),
                                          (uint)*(byte *)(param_2 + 0xa2))) ^ 0xff00000000) &
                      0xff01ffffffff);
    lVar18 = *(long *)(param_1 + 0x18);
    local_b0 = *(undefined8 *)(lVar18 + 0xc0);
    local_90 = *(undefined4 *)(param_2 + 0x10c);
    uStack_8c = (uint)bVar3;
    uStack_d8 = *(undefined8 *)(lVar18 + 0x98);
    local_e0 = *(undefined8 *)(lVar18 + 0x90);
    uStack_c8 = *(undefined8 *)(lVar18 + 0xa8);
    uStack_d0 = *(undefined8 *)(lVar18 + 0xa0);
    uStack_b8 = *(undefined8 *)(lVar18 + 0xb8);
    local_c0 = *(undefined8 *)(lVar18 + 0xb0);
    uStack_118 = *(undefined8 *)(lVar18 + 0x58);
    local_120 = *(undefined8 *)(lVar18 + 0x50);
    uStack_108 = *(undefined8 *)(lVar18 + 0x68);
    uStack_110 = *(undefined8 *)(lVar18 + 0x60);
    uStack_f8 = *(undefined8 *)(lVar18 + 0x78);
    local_100 = *(undefined8 *)(lVar18 + 0x70);
    uStack_e8 = *(undefined8 *)(lVar18 + 0x88);
    uStack_f0 = *(undefined8 *)(lVar18 + 0x80);
    uStack_138 = *(undefined8 *)(lVar18 + 0x38);
    local_140 = *(undefined8 *)(lVar18 + 0x30);
    uStack_128 = *(undefined8 *)(lVar18 + 0x48);
    local_130 = *(undefined8 *)(lVar18 + 0x40);
    if (*(byte *)(param_2 + 0xa1) < 8) {
      bVar27 = *(byte *)((long)&uStack_118 + (ulong)*(byte *)(param_2 + 0xa1) * 3 + 1);
    }
    if (uVar12 == 0xffffffff || (uVar10 & 1) != 0) {
      lVar18 = *(long *)(lVar29 + 0x5d0);
      lVar29 = *(long *)(lVar29 + 0x5d8);
      if (lVar29 == 0) {
        if ((*(byte *)(plVar24 + 0x57) & 1) != 0) goto LAB_fffffff0089b16f8;
LAB_fffffff0089b1760:
        lVar15 = 0;
        uStack_128 = 0;
        local_130 = 0;
        uStack_118 = 0;
        local_120 = 0;
        uStack_138 = 0;
        local_140 = 0;
      }
      else {
        FUN_fffffff0089c46a4(lVar29);
        if ((*(byte *)(plVar24 + 0x57) & 1) == 0) goto LAB_fffffff0089b1760;
        FUN_fffffff0089c46a4(lVar29);
LAB_fffffff0089b16f8:
        uStack_128 = 0;
        local_130 = 0;
        uStack_118 = 0;
        local_120 = 0;
        uStack_138 = 0;
        local_140 = 0;
        lVar15 = lVar29;
        if ((lVar18 != 0) &&
           (uVar13 = FUN_fffffff0089609c8(lVar18,*(undefined4 *)(param_2 + 0x10c),&local_140),
           (uVar13 & 1) == 0)) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0x10,
                     "[ERROR] %s: %s: Could not query execution times from the mach-o\n");
        }
      }
      if ((*(byte *)(param_1 + 0xaa0) & 1) == 0) {
        uVar14 = 0;
LAB_fffffff0089b1828:
        if ((bVar27 & 1) == 0) goto LAB_fffffff0089b1978;
LAB_fffffff0089b182c:
        uVar26 = local_78;
        if (((((*(byte *)(*(long *)(param_1 + 0x228) + 0x1d6) & bVar8 & 1) == 0) ||
             ((*(byte *)(param_1 + 0xaa0) & 1) == 0)) || (*(int *)(param_2 + 0x114) == 1)) ||
           ((iVar11 = FUN_fffffff008a7c8c8
                                (*(undefined8 *)(param_1 + 0x20),&local_a8,&local_140,local_78,
                                 uVar14), uVar12 != 0xffffffff || (iVar11 != 1))))
        goto LAB_fffffff0089b1978;
        uVar28 = **(uint **)(param_1 + 0x18);
        if (uVar28 == 0) {
          uVar12 = 0;
        }
        else {
          uVar12 = 0;
          uVar10 = (uVar28 & 0xaaaaaaaa) >> 1 | (uVar28 & 0x55555555) << 1;
          uVar10 = (uVar10 & 0xcccccccc) >> 2 | (uVar10 & 0x33333333) << 2;
          uVar10 = (uVar10 & 0xf0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f) << 4;
          uVar10 = (uVar10 & 0xff00ff00) >> 8 | (uVar10 & 0xff00ff) << 8;
          uVar10 = uVar10 >> 0x10 | uVar10 << 0x10;
          do {
            lVar18 = LZCOUNT(uVar10);
            local_170 = 0;
            FUN_fffffff00898e68c
                      (param_1,*puVar17,*(undefined4 *)(param_2 + 0x10c),1,bVar3,&local_170);
            if ((uint)lVar18 < 4) {
              uVar12 = (&DAT_fffffff007491e60)[lVar18] | uVar12;
            }
            FUN_fffffff00898d588(param_1,lVar18,bVar3,local_170);
            *(ulong *)(param_2 + 0x50 + lVar18 * 8) = local_170;
            uVar28 = uVar28 - 1 & uVar28;
            uVar10 = (uVar28 & 0xaaaaaaaa) >> 1 | (uVar28 & 0x55555555) << 1;
            uVar10 = (uVar10 & 0xcccccccc) >> 2 | (uVar10 & 0x33333333) << 2;
            uVar10 = (uVar10 & 0xf0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f) << 4;
            uVar10 = (uVar10 & 0xff00ff00) >> 8 | (uVar10 & 0xff00ff) << 8;
            uVar10 = uVar10 >> 0x10 | uVar10 << 0x10;
          } while (uVar28 != 0);
        }
LAB_fffffff0089b239c:
        *(undefined8 *)(param_2 + 0xe0) = uVar26;
        *(uint *)(param_2 + 0x42c0) = uVar12;
        bVar7 = (uVar12 & uVar12 - 1) != 0;
        *(uint *)(param_2 + 0x118) = (uint)bVar7;
        thunk_EXT_FUN_80110000036da494
                  (0x61b0186,*(undefined8 *)(*(long *)(param_2 + 0x120) + 0xc0),
                   *(undefined4 *)(param_2 + 0x10c),*(undefined8 *)(param_2 + 0x100),bVar7,0);
        uVar14 = 0;
      }
      else {
        uVar14 = FUN_fffffff0089b3e54(param_1,&local_a8,&local_140,&local_78,&local_7c,4);
        if ((DAT_fffffff00ae430b3 >> 4 & 1) == 0) goto LAB_fffffff0089b1828;
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                   "%s: %s: CLPC recommendation: %s, allowedClusters = 0x%llx\n");
        if ((bVar27 & 1) != 0) goto LAB_fffffff0089b182c;
LAB_fffffff0089b1978:
        if (uVar10 != 0) {
          uStack_158 = 0;
          local_160 = 0;
          uStack_148 = 0;
          uStack_150 = 0;
          _uStack_168 = 0;
          bVar27 = *(byte *)(*(long *)(param_1 + 0x18) + 4);
          uVar13 = (ulong)bVar27;
          local_170 = (ulong)bVar27;
          if (bVar27 < 5) {
            if (bVar27 == 0) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0x10,
                         "[ERROR] %s: %s: hwInterface->getNumANEs() returned 0, defaulting to 1\n");
              uVar13 = 1;
              goto LAB_fffffff0089b1b24;
            }
          }
          else {
            uVar13 = 4;
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0x10,
                       "[ERROR] %s: %s: hwInterface->getNumANEs() returned %u which exceeds NUM_OF_ANES (%u), clamping to %u\n"
                      );
LAB_fffffff0089b1b24:
            local_170 = CONCAT71(local_170._1_7_,(char)uVar13);
          }
          _uStack_168 = CONCAT44(stack0xfffffffffffffe9c,
                                 **(uint **)(param_1 + 0x18) & (uint)local_78);
          uVar28 = (uint)uVar13;
          if (((uVar12 != 0xffffffff) && (uVar12 < uVar28)) &&
             (_uStack_168 = CONCAT44(stack0xfffffffffffffe9c,1 << (ulong)(uVar12 & 0x1f)),
             (_DAT_fffffff00ae430b0 >> 0x1c & 1) != 0)) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                       "%s: %s: User specified debug ANE %u for programHandle 0x%llx\n");
          }
          if ((_DAT_fffffff00ae430b0 >> 0x1c & 1) != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                       "%s: %s: After overriding the clustermask, aneMask = 0x%x, allowedClusters = 0x%llx\n"
                      );
          }
          puVar5 = PTR_DAT_fffffff007ddeaa8;
          lVar18 = 0;
          local_170 = (ulong)CONCAT14(bVar3,(undefined4)local_170);
          uStack_168 = (uint5)(uint)uStack_168;
          local_160 = CONCAT44(local_160._4_4_,0x5f);
          do {
            *(undefined1 *)((long)&uStack_158 + lVar18) = 0;
            *(undefined4 *)((long)&uStack_158 + lVar18 * 4 + 4) = 0;
            lVar18 = lVar18 + 1;
            uVar13 = uVar13 - 1;
          } while (uVar13 != 0);
          uVar12 = **(uint **)(param_1 + 0x18);
          if (uVar12 != 0) {
            uVar10 = (uVar12 & 0xaaaaaaaa) >> 1 | (uVar12 & 0x55555555) << 1;
            uVar10 = (uVar10 & 0xcccccccc) >> 2 | (uVar10 & 0x33333333) << 2;
            uVar10 = (uVar10 & 0xf0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f) << 4;
            uVar10 = (uVar10 & 0xff00ff00) >> 8 | (uVar10 & 0xff00ff) << 8;
            uVar10 = uVar10 >> 0x10 | uVar10 << 0x10;
            do {
              lVar18 = LZCOUNT(uVar10);
              plVar24 = *(long **)(param_1 + 0x28 + lVar18 * 0x80);
              if (plVar24 != (long *)0x0 && (uint)lVar18 < uVar28) {
                uVar9 = (**(code **)(*plVar24 + 0x6c0))(plVar24,0);
                *(undefined1 *)((long)&uStack_158 + lVar18) = uVar9;
                if ((DAT_fffffff00ae430b3 >> 4 & 1) != 0) {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,puVar5,0,"%s: %s: ANE %u throttle percentage: %u%%\n");
                }
                uVar13 = (**(code **)(*plVar24 + 0x6a8))(plVar24);
                if ((uVar13 & 1) == 0) {
                  *(undefined4 *)((long)&uStack_158 + lVar18 * 4 + 4) = 0;
                }
                else {
                  iVar11 = (**(code **)(*plVar24 + 0x6b0))(plVar24);
                  if (iVar11 == 0) {
                    iVar11 = (**(code **)(*plVar24 + 0x6b8))(plVar24);
                    if (iVar11 == 0) {
                      uVar23 = 3;
                    }
                    else {
                      uVar23 = 1;
                    }
                  }
                  else {
                    uVar23 = 2;
                  }
                  *(undefined4 *)((long)&uStack_158 + lVar18 * 4 + 4) = uVar23;
                }
                if ((DAT_fffffff00ae430b3 >> 4 & 1) != 0) {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,puVar5,0,"%s: %s: ANE %u power readiness: %u\n");
                }
              }
              uVar12 = uVar12 - 1 & uVar12;
              uVar10 = (uVar12 & 0xaaaaaaaa) >> 1 | (uVar12 & 0x55555555) << 1;
              uVar10 = (uVar10 & 0xcccccccc) >> 2 | (uVar10 & 0x33333333) << 2;
              uVar10 = (uVar10 & 0xf0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f) << 4;
              uVar10 = (uVar10 & 0xff00ff00) >> 8 | (uVar10 & 0xff00ff) << 8;
              uVar10 = uVar10 >> 0x10 | uVar10 << 0x10;
            } while (uVar12 != 0);
          }
          if ((*(byte *)(*(long *)(param_1 + 0x228) + 0x1dc) & 1) == 0) {
            uVar23 = 0x7f;
          }
          else {
            lVar25 = *(long *)(param_1 + 0x9f8);
            lVar18 = thunk_EXT_FUN_8011000003397c88();
            local_70[0] = 0;
            thunk_EXT_FUN_8011000003398228(lVar18 - lVar25,local_70);
            if (*(uint *)(*(long *)(param_1 + 0x228) + 0x1e0) <= (uint)(local_70[0] / 1000000)) {
              uVar12 = FUN_fffffff0089a5e60
                                 (*(undefined4 *)(param_1 + 0xa00),**(undefined4 **)(param_1 + 0x18)
                                 );
              if (uVar12 < uVar28) {
                *(uint *)(param_1 + 0xa00) = uVar12;
                uVar14 = thunk_EXT_FUN_8011000003397c88();
                *(undefined8 *)(param_1 + 0x9f8) = uVar14;
                if ((DAT_fffffff00ae430b3 >> 4 & 1) != 0) {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                             "%s: %s: Single-ANE rotation flipped preferred ANE to %u\n");
                }
              }
              else {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0x10,
                           "[ERROR] %s: %s: GetNextRotationTargetANE returned out-of-range index %u (numANEs: %u), skipping flip\n"
                          );
              }
            }
            local_160 = CONCAT44(local_160._4_4_,0xdf);
            uStack_148 = CONCAT44(*(undefined4 *)(param_1 + 0xa00),(undefined4)uStack_148);
            uVar23 = 0xff;
          }
          iVar11 = *(int *)(param_2 + 0x42c8);
          if (iVar11 != 0) {
            if ((DAT_fffffff00ae430b3 >> 4 & 1) != 0) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                         "%s: %s: User has specified a desire to schedule the insference on ANE%u. Updating the decision mask to consider the hint\n"
                        );
              iVar11 = *(int *)(param_2 + 0x42c8);
            }
            local_160 = CONCAT44(iVar11 + -1,uVar23);
          }
          uVar13 = *puVar17;
          if (uVar13 == 0) {
            lVar18 = param_1 + 0x958;
          }
          else {
            plVar24 = (long *)(param_1 + 0x9c8);
            uVar16 = *(ulong *)(param_1 + 0x9d0);
            if ((uVar16 != 0) && (*(long *)(param_1 + 0x9e8) != 0)) {
              uVar19 = uVar16 - 1;
              if ((uVar16 & uVar19) == 0) {
                uVar20 = uVar19 & uVar13;
              }
              else {
                uVar20 = uVar13;
                if (uVar16 <= uVar13) {
                  uVar20 = 0;
                  if (uVar16 != 0) {
                    uVar20 = uVar13 / uVar16;
                  }
                  uVar20 = uVar13 - uVar20 * uVar16;
                }
              }
              if (*(ulong *)(param_1 + 0x9d8) <= uVar20) {
                    /* WARNING: Does not return */
                pcVar6 = (code *)SoftwareBreakpoint(0x800,0xfffffff0089b2468);
                (*pcVar6)();
              }
              lVar18 = uVar20 * 8;
              plVar21 = (long *)(*plVar24 + (long)(int)lVar18);
              if (lVar18 - (int)lVar18 != 0) {
                plVar21 = (long *)(*plVar24 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
              }
              plVar21 = (long *)*plVar21;
              if (plVar21 != (long *)0x0) {
                do {
                  while( true ) {
                    plVar21 = (long *)*plVar21;
                    if (plVar21 == (long *)0x0) goto LAB_fffffff0089b21f4;
                    uVar22 = plVar21[1];
                    if (uVar22 != uVar13) break;
                    if (plVar21[2] == uVar13) {
                      lVar18 = (long)(plVar21 + 3);
                      goto LAB_fffffff0089b2218;
                    }
                  }
                  if ((uVar16 & uVar19) == 0) {
                    uVar22 = uVar22 & uVar19;
                  }
                  else if (uVar16 <= uVar22) {
                    uVar4 = 0;
                    if (uVar16 != 0) {
                      uVar4 = uVar22 / uVar16;
                    }
                    uVar22 = uVar22 - uVar4 * uVar16;
                  }
                } while (uVar22 == uVar20);
              }
            }
LAB_fffffff0089b21f4:
            FUN_fffffff0089b3f9c(plVar24,puVar17);
            FUN_fffffff0089a4b90();
            lVar18 = FUN_fffffff0089b3f9c(plVar24,puVar17);
            uVar13 = *puVar17;
          }
LAB_fffffff0089b2218:
          thunk_EXT_FUN_80110000036da494(0x61b0191,uVar13,*(undefined4 *)(param_2 + 0x10c),0,0,0);
          uVar13 = FUN_fffffff0089a50b8
                             (param_1 + 0x3d8,lVar18,*puVar17,*(undefined4 *)(param_2 + 0x10c),
                              &local_170);
          if ((DAT_fffffff00ae430b3 >> 4 & 1) != 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                       "%s: %s: Selected ANE %u for programHandle 0x%llx with priority %u\n");
          }
          if ((uint)uVar13 < 4) {
            lVar18 = (uVar13 & 0xffffffff) * 4;
            iVar11 = (int)lVar18;
            puVar1 = (uint *)((long)&DAT_fffffff007491e60 + (long)iVar11);
            if (lVar18 != iVar11) {
              puVar1 = (uint *)((ulong)(&DAT_fffffff007491e60 + (uVar13 & 0xffffffff)) &
                                0xffffffffffff | 0x2bad000000000000);
            }
            uVar12 = *puVar1;
          }
          else {
            uVar12 = 0;
          }
          thunk_EXT_FUN_80110000036da494
                    (0x61b0192,*puVar17,*(undefined4 *)(param_2 + 0x10c),0,uVar12,0);
          local_70[0] = 0;
          FUN_fffffff008a7bf58
                    (*(undefined8 *)(param_1 + 0x20),*puVar17,*(undefined4 *)(param_2 + 0x10c),0,
                     bVar3,local_70);
          FUN_fffffff00898d588(param_1,uVar13,*(undefined1 *)(param_2 + 0xa0),local_70[0]);
          lVar18 = (uVar13 & 0xffffffff) * 8;
          puVar17 = (ulong *)(param_2 + 0x50 + (long)(int)lVar18);
          if (lVar18 != (int)lVar18) {
            puVar17 = (ulong *)(param_2 + 0x50 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *puVar17 = local_70[0];
          uVar26 = local_78;
          goto LAB_fffffff0089b239c;
        }
        uVar14 = 0xe00002c2;
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0x10,
                   "[ERROR] %s: %s: not able to select correct variant for request\n");
      }
      if (lVar15 != 0) {
        FUN_fffffff0089c46cc();
      }
      if (lVar29 != 0) {
        FUN_fffffff0089c46cc(lVar29);
      }
    }
    else {
      uVar14 = 0xe00002c2;
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0x10,
                 "[ERROR] %s: %s: debugANE selection (debugANE=%u) requires program to have single-ANE variant, but procedure %u only has bonded variant\n"
                );
    }
  }
  if (lVar31 != 0) {
    FUN_fffffff0089c46cc(lVar31);
  }
LAB_fffffff0089b23fc:
  if (lVar2 != 0) {
    FUN_fffffff0089c46cc(lVar2);
  }
  if (lVar30 != 0) {
    thunk_EXT_FUN_80110000038ff2e0(lVar30);
  }
  return uVar14;
}

