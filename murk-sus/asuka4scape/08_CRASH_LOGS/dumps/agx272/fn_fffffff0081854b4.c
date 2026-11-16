// FUN_fffffff0081854b4 @ fffffff0081854b4 size=6992

/* WARNING: Removing unreachable block (ram,0xfffffff00818635c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081860fc) */

void FUN_fffffff0081854b4(long param_1,long param_2,long param_3,uint param_4,byte *param_5)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined8 *puVar4;
  ulong *puVar5;
  uint *puVar6;
  undefined2 *puVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined *puVar21;
  code *pcVar22;
  bool bVar23;
  int iVar24;
  uint uVar25;
  undefined8 uVar26;
  long *plVar27;
  long *plVar28;
  long *plVar29;
  long *plVar30;
  uint *puVar31;
  long lVar32;
  ulong uVar33;
  int *piVar34;
  uint uVar35;
  ulong uVar36;
  long lVar37;
  ulong uVar38;
  ulong uVar39;
  undefined2 uVar40;
  long lVar41;
  ulong uVar42;
  ulong uVar43;
  long lVar44;
  ulong uVar45;
  long lVar46;
  ulong uVar47;
  undefined8 *puVar48;
  int iVar49;
  ulong uVar50;
  long lVar51;
  ulong *puVar52;
  long lVar53;
  ulong uVar54;
  long lVar55;
  ulong uVar56;
  ulong uVar57;
  ulong uVar58;
  ulong uVar59;
  undefined8 uVar60;
  long lVar61;
  uint *puVar62;
  int iVar63;
  float fVar64;
  ulong local_f8;
  ulong local_c0 [2];
  undefined8 local_b0;
  undefined2 uStack_a8;
  undefined6 uStack_a6;
  undefined2 local_a0;
  undefined6 uStack_9e;
  undefined8 uStack_98;
  long lStack_90;
  long local_80;
  
  local_80 = *(long *)PTR_DAT_fffffff007ca61a0;
  lVar53 = *(long *)(param_1 + 0x80);
  if (lVar53 == 0) {
LAB_fffffff008186d44:
    uVar26 = 1;
  }
  else {
    lVar51 = *(long *)(param_1 + 0x10);
    lVar41 = *(long *)(lVar53 + 0x28);
    lVar61 = 0;
    if (*(long *)(lVar41 + 0x3b8) == 0 && *(long *)(lVar41 + 0x3b0) == 0) {
      lVar61 = 0x10;
    }
    plVar27 = (long *)(lVar41 + 0x3b0 + lVar61);
    lVar61 = *plVar27;
    lVar37 = plVar27[1];
    if (lVar37 == 0 && lVar61 == 0) {
      uVar25 = *(uint *)(lVar41 + 0x3e0);
      local_b0._0_2_ = 0;
      local_b0._2_2_ = 0;
      local_b0._4_4_ = 0;
      uStack_a8 = 0;
      uStack_a6 = 0;
      uVar35 = uVar25 - 0x40;
      if (uVar25 < 0x40) {
        uVar36 = 0;
      }
      else {
        uVar36 = (ulong)((uVar35 >> 6) + 1);
        if (uVar35 < 0xc0) {
          uVar42 = 0;
LAB_fffffff008185590:
          lVar61 = ((uVar35 >> 6) - uVar42) + 1;
          do {
            iVar24 = (int)(uVar42 * 8);
            puVar4 = (undefined8 *)((long)&local_b0 + (long)iVar24);
            if (uVar42 * 8 - (long)iVar24 != 0) {
              puVar4 = (undefined8 *)
                       ((ulong)(&local_b0 + uVar42) & 0xffffffffffff | 0x2bad000000000000);
            }
            *puVar4 = 0xffffffffffffffff;
            uVar42 = uVar42 + 1;
            lVar61 = lVar61 + -1;
          } while (lVar61 != 0);
        }
        else {
          lVar61 = 0;
          uVar42 = uVar36 & 0x7fffffc;
          uVar50 = uVar42;
          do {
            (&uStack_98)[lVar61] = 0xffffffffffffffff;
            *(undefined8 *)(&local_a0 + lVar61 * 4) = 0xffffffffffffffff;
            lVar61 = lVar61 + 4;
            uVar50 = uVar50 - 4;
          } while (uVar50 != 0);
          if (uVar42 != uVar36) goto LAB_fffffff008185590;
        }
        uVar25 = uVar25 & 0x3f;
      }
      if (uVar25 != 0) {
        (&local_b0)[uVar36] =
             (&local_b0)[uVar36] | -1L << ((ulong)uVar25 & 0x3f) ^ 0xffffffffffffffffU;
      }
      lVar61 = CONCAT44(local_b0._4_4_,CONCAT22(local_b0._2_2_,(undefined2)local_b0));
      lVar37 = CONCAT62(uStack_a6,uStack_a8);
    }
    lVar41 = param_3 + 0x34;
    puVar1 = (uint *)(param_3 + 0x24);
    puVar2 = (uint *)(param_3 + 0x20);
    uVar25 = 0;
    uVar42 = 0;
    uVar35 = 0;
    uVar36 = 1;
    if ((param_4 & 1) == 0) {
      do {
        uVar9 = *(uint *)(lVar41 + uVar36 * 4);
        uVar50 = (ulong)uVar9;
        if (0x10d < uVar9) goto LAB_fffffff0081857b4;
        uVar9 = *(uint *)(&DAT_fffffff007115368 + uVar36 * 4);
        if ((*(byte *)(param_3 + 0x74) & 1) == 0) {
          if (uVar36 != *puVar1) goto LAB_fffffff008185680;
          uVar50 = uVar50 + 8;
LAB_fffffff008185684:
          auVar13._8_8_ = 0;
          auVar13._0_8_ = uVar50 * uVar9;
          auVar17._8_8_ = 0;
          auVar17._0_8_ = CONCAT44(0,*(uint *)(&UNK_fffffff0071153a8 + uVar36 * 4));
          if ((SUB168(auVar13 * auVar17,8) != 0) ||
             (uVar50 = uVar50 * uVar9 * CONCAT44(0,*(uint *)(&UNK_fffffff0071153a8 + uVar36 * 4)),
             bVar23 = CARRY8(uVar42,uVar50), uVar42 = uVar42 + uVar50, bVar23))
          goto LAB_fffffff0081857b4;
          uVar25 = uVar25 + 1;
          if (uVar35 <= uVar9) {
            uVar35 = uVar9;
          }
        }
        else {
          if (uVar36 == *puVar2) {
            uVar50 = uVar50 + 0x68;
            goto LAB_fffffff008185684;
          }
LAB_fffffff008185680:
          if (uVar50 != 0) goto LAB_fffffff008185684;
        }
        uVar36 = uVar36 + 1;
      } while (uVar36 != 0x10);
    }
    else {
      do {
        uVar9 = *(uint *)(lVar41 + uVar36 * 4);
        uVar50 = (ulong)uVar9;
        if (0x10d < uVar9) goto LAB_fffffff0081857b4;
        if ((*(byte *)(param_3 + 0x74) & 1) == 0) {
          if (uVar36 != *puVar1) goto LAB_fffffff0081856f8;
          uVar50 = uVar50 + 8;
LAB_fffffff0081856fc:
          uVar58 = uVar50 + (ulong)*(uint *)(param_3 + 0x2c) * 2;
        }
        else {
          if (uVar36 == *puVar2) {
            uVar50 = uVar50 + 0x68;
            goto LAB_fffffff0081856fc;
          }
LAB_fffffff0081856f8:
          uVar58 = 0;
          if (uVar50 != 0) goto LAB_fffffff0081856fc;
        }
        if (uVar36 == *(uint *)(param_3 + 0x28)) {
          uVar58 = uVar58 + *(uint *)(param_3 + 0x30);
        }
        if (uVar58 != 0) {
          uVar9 = *(uint *)(&DAT_fffffff007115368 + uVar36 * 4);
          auVar14._8_8_ = 0;
          auVar14._0_8_ = uVar58;
          auVar18._8_8_ = 0;
          auVar18._0_8_ = CONCAT44(0,uVar9);
          if (SUB168(auVar14 * auVar18,8) != 0) goto LAB_fffffff0081857b4;
          uVar58 = uVar58 * CONCAT44(0,uVar9);
          auVar15._8_8_ = 0;
          auVar15._0_8_ = uVar58;
          auVar19._8_8_ = 0;
          auVar19._0_8_ = CONCAT44(0,*(uint *)(&UNK_fffffff0071153a8 + uVar36 * 4));
          if ((SUB168(auVar15 * auVar19,8) != 0) ||
             (uVar58 = uVar58 * CONCAT44(0,*(uint *)(&UNK_fffffff0071153a8 + uVar36 * 4)),
             bVar23 = CARRY8(uVar42,uVar58), uVar42 = uVar42 + uVar58, bVar23))
          goto LAB_fffffff0081857b4;
          uVar25 = uVar25 + 1;
          if (uVar35 <= uVar9) {
            uVar35 = uVar9;
          }
        }
        uVar36 = uVar36 + 1;
      } while (uVar36 != 0x10);
    }
    if ((uVar25 < 0xf4899) &&
       (uVar36 = (ulong)(byte)(POPCOUNT((char)lVar61) + POPCOUNT((char)((ulong)lVar61 >> 8)) +
                               POPCOUNT((char)((ulong)lVar61 >> 0x10)) +
                               POPCOUNT((char)((ulong)lVar61 >> 0x18)) +
                               POPCOUNT((char)((ulong)lVar61 >> 0x20)) +
                               POPCOUNT((char)((ulong)lVar61 >> 0x28)) +
                               POPCOUNT((char)((ulong)lVar61 >> 0x30)) +
                              POPCOUNT((char)((ulong)lVar61 >> 0x38))) +
                 (ulong)(byte)(POPCOUNT((char)lVar37) + POPCOUNT((char)((ulong)lVar37 >> 8)) +
                               POPCOUNT((char)((ulong)lVar37 >> 0x10)) +
                               POPCOUNT((char)((ulong)lVar37 >> 0x18)) +
                               POPCOUNT((char)((ulong)lVar37 >> 0x20)) +
                               POPCOUNT((char)((ulong)lVar37 >> 0x28)) +
                               POPCOUNT((char)((ulong)lVar37 >> 0x30)) +
                              POPCOUNT((char)((ulong)lVar37 >> 0x38))), auVar16._8_8_ = 0,
       auVar16._0_8_ = uVar42, auVar20._8_8_ = 0, auVar20._0_8_ = uVar36,
       SUB168(auVar16 * auVar20,8) == 0)) {
      uVar9 = uVar25 * 0x10c0 + 0x40;
      lVar61 = uVar36 * uVar9;
      uVar50 = lVar61 + 0x144;
      if (!CARRY8(uVar50 + uVar35,uVar42 * uVar36)) {
        if (uVar25 == 0) {
LAB_fffffff008186cf8:
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar51 + 0x370));
          if (((*(byte *)(lVar51 + 0x380) & 1) == 0) && (*(long *)(lVar53 + 0x38) != 0)) {
            *(undefined1 *)(lVar51 + 0x380) = 1;
            (**(code **)(**(long **)(lVar51 + 0x378) + 0xf0))(*(long **)(lVar51 + 0x378),1000);
          }
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar51 + 0x370));
          goto LAB_fffffff008186d44;
        }
        lVar37 = (long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f));
        uVar42 = (((uVar50 + uVar35 + uVar42 * uVar36) - lVar61) + lVar37) - 0x145 & -lVar37;
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar53 + 0x80));
        uVar36 = *(ulong *)(lVar53 + 0x70);
        if (*(ulong *)(lVar53 + 0x70) <= uVar42) {
          uVar36 = uVar42;
        }
        *(ulong *)(lVar53 + 0x70) = uVar36;
        thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(*(long *)(lVar53 + 0x50) + 0x10));
        lVar37 = *(long *)(lVar53 + 0x50);
        uVar58 = *(ulong *)(lVar37 + 0x30);
        uVar36 = uVar58;
        if (*(ulong *)(lVar53 + 0x38) < uVar42) {
          uVar45 = uVar42 - uVar58;
          if (uVar58 <= uVar42 && uVar45 != 0) {
            lVar32 = *(long *)(lVar37 + 0x18);
            lVar55 = *(long *)(lVar37 + 0x28);
            if (0 < *(long *)(lVar37 + 0x28)) {
              do {
                lVar44 = lVar55 + -1;
                lVar46 = lVar44 * 0x20;
                uVar36 = lVar32 + (int)lVar46;
                if (lVar46 - (int)lVar46 != 0) {
                  uVar36 = lVar32 + lVar46 & 0xffffffffffffU | 0x2bad000000000000;
                }
                lVar46 = lVar55;
                if ((*(long *)(uVar36 + 0x10) == 0) ||
                   (lVar46 = lVar44, *(ulong *)(uVar36 + 8) <= uVar45)) goto LAB_fffffff0081858d0;
                bVar23 = 1 < lVar55;
                lVar55 = lVar44;
              } while (bVar23);
            }
            lVar46 = 0;
LAB_fffffff0081858d0:
            lVar46 = lVar46 * 0x20;
            uVar36 = lVar32 + (int)lVar46;
            if (lVar46 - (int)lVar46 != 0) {
              uVar36 = lVar32 + lVar46 & 0xffffffffffffU | 0x2bad000000000000;
            }
            lVar55 = *(long *)(lVar53 + 0x28);
            uVar26 = *(undefined8 *)(lVar53 + 0x30);
            uVar54 = *(ulong *)(uVar36 + 0x10);
            fVar64 = *(float *)(lVar37 + 0x58);
            uVar33 = uVar45;
            if (fVar64 < 1.0) {
              uVar33 = 0;
              if (uVar54 != 0) {
                uVar33 = (ulong)(long)(fVar64 * (float)uVar45) / uVar54;
              }
              uVar33 = uVar33 * uVar54;
              if (uVar33 < uVar54 || uVar33 - uVar54 == 0) {
                uVar33 = uVar54;
              }
            }
            uVar59 = 0;
            uVar25 = *(uint *)(uVar36 + 0x18);
            puVar62 = (uint *)PTR_DAT_fffffff007ca5f88;
            uVar36 = uVar58;
            do {
              uVar43 = uVar36;
              if (uVar33 != 0) {
                uVar56 = *(ulong *)(lVar37 + 0x28);
                lVar32 = *(long *)(lVar37 + 0x18);
                uVar43 = uVar56 - 1;
                if (0 < (long)uVar56) {
                  do {
                    uVar38 = uVar56 - 1;
                    lVar44 = uVar38 * 0x20;
                    uVar39 = lVar32 + (int)lVar44;
                    if (lVar44 - (int)lVar44 != 0) {
                      uVar39 = lVar32 + lVar44 & 0xffffffffffffU | 0x2bad000000000000;
                    }
                    uVar57 = uVar56;
                    if ((*(ulong *)(uVar39 + 0x10) < uVar54 || *(uint *)(uVar39 + 0x18) < uVar25) ||
                       (uVar57 = uVar38, *(ulong *)(uVar39 + 8) <= uVar33))
                    goto LAB_fffffff0081859e0;
                    bVar23 = 1 < (long)uVar56;
                    uVar56 = uVar38;
                  } while (bVar23);
                }
                uVar57 = 0;
LAB_fffffff0081859e0:
                uVar56 = uVar57 << 5 | 0x10;
                puVar52 = (ulong *)(lVar32 + (int)uVar56);
                if (uVar56 != (long)(int)uVar56) {
                  puVar52 = (ulong *)(lVar32 + uVar56 & 0xffffffffffff | 0x2bad000000000000);
                }
                uVar39 = *puVar52;
                uVar56 = 0;
                if (uVar39 != 0) {
                  uVar56 = ((uVar33 + uVar39) - 1) / uVar39;
                }
                uVar38 = uVar57;
                if (uVar57 <= uVar43) {
                  uVar38 = uVar43;
                }
                uVar56 = uVar56 * uVar39;
                uVar39 = uVar38;
                if (uVar57 < uVar43) {
                  while( true ) {
                    uVar43 = uVar57 + 1;
                    uVar39 = uVar43 * 0x20 | 8;
                    puVar52 = (ulong *)(lVar32 + (int)uVar39);
                    if (uVar39 != (long)(int)uVar39) {
                      puVar52 = (ulong *)(lVar32 + uVar39 & 0xffffffffffff | 0x2bad000000000000);
                    }
                    uVar47 = *puVar52;
                    uVar39 = uVar57;
                    if (*(ulong *)(lVar37 + 0x50) < uVar47) break;
                    lVar44 = uVar57 * 0x18;
                    plVar27 = (long *)(*(long *)(lVar37 + 0x20) + (long)(int)lVar44);
                    if (lVar44 - (int)lVar44 != 0) {
                      plVar27 = (long *)(*(long *)(lVar37 + 0x20) + lVar44 & 0xffffffffffffU |
                                        0x2bad000000000000);
                    }
                    if ((*plVar27 + uVar56 < uVar47) ||
                       (uVar56 = uVar47, uVar57 = uVar43, uVar39 = uVar38, uVar38 == uVar43)) break;
                  }
                }
                uVar43 = uVar39 << 5 | 0x10;
                puVar52 = (ulong *)(lVar32 + (int)uVar43);
                if (uVar43 != (long)(int)uVar43) {
                  puVar52 = (ulong *)(lVar32 + uVar43 & 0xffffffffffff | 0x2bad000000000000);
                }
                uVar38 = *puVar52;
                uVar56 = (uVar56 + uVar38) - 1;
                uVar43 = 0;
                if (uVar38 != 0) {
                  uVar43 = uVar56 / uVar38;
                }
                plVar27 = (long *)thunk_EXT_FUN_8011000003962900
                                            (0,*(uint *)(lVar55 + 0x18b70) | 0x100023,
                                             uVar56 + *(long *)PTR_DAT_fffffff007ca61e8 +
                                             ~(uVar56 - uVar43 * uVar38) &
                                             -*(long *)PTR_DAT_fffffff007ca61e8,
                                             (long)(1 << (ulong)(*puVar62 & 0x1f)));
                if (plVar27 != (long *)0x0) {
                  plVar28 = (long *)thunk_EXT_FUN_801100000297d1cc(lVar55,0,plVar27);
                  puVar21 = PTR_DAT_fffffff007ca61a8;
                  if (plVar28 == (long *)0x0) {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"AGXk: block alloc failed"
                              );
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,puVar21,1,"AGXk: block alloc failed");
                    plVar30 = (long *)0x0;
                  }
                  else {
                    (**(code **)(*plVar28 + 0x20))();
                    (**(code **)(*plVar28 + 0x28))(plVar28);
                    uVar43 = uVar39 << 5 | 0x18;
                    puVar31 = (uint *)(*(long *)(lVar37 + 0x18) + (long)(int)uVar43);
                    if (uVar43 != (long)(int)uVar43) {
                      puVar31 = (uint *)(*(long *)(lVar37 + 0x18) + uVar43 & 0xffffffffffff |
                                        0x2bad000000000000);
                    }
                    plVar29 = (long *)(**(code **)(*plVar28 + 0x90))
                                                (plVar28,uVar26,
                                                 ((ulong)*puVar31 & 0x1f) << 0x2b | 0x500000007);
                    puVar21 = PTR_DAT_fffffff007ca61a8;
                    if (plVar29 == (long *)0x0) {
                      thunk_EXT_FUN_80110000038db19c
                                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"AGXk: block map failed"
                                );
                      thunk_EXT_FUN_80110000038db19c
                                (&MACH_HEADER,puVar21,1,"AGXk: block map failed");
                      plVar30 = (long *)0x0;
                    }
                    else {
                      (**(code **)(*plVar29 + 0x20))();
                      (**(code **)(*plVar29 + 0x28))(plVar29);
                      plVar30 = (long *)thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4058,0x70);
                      puVar21 = PTR_DAT_fffffff007ca61a8;
                      if (plVar30 == (long *)0x0) {
                        thunk_EXT_FUN_80110000038db19c
                                  (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,
                                   "AGXk: block create failed");
                        thunk_EXT_FUN_80110000038db19c
                                  (&MACH_HEADER,puVar21,1,"AGXk: block create failed");
                        (**(code **)(*plVar29 + 0x28))(plVar29);
                        plVar30 = (long *)0x0;
                        puVar62 = (uint *)PTR_DAT_fffffff007ca5f88;
                      }
                      else {
                        plVar30[3] = uVar39;
                        *plVar30 = (long)plVar29;
                        lVar32 = (**(code **)(*plVar29 + 0x98))(plVar29);
                        plVar30[1] = lVar32;
                        lVar32 = (**(code **)(*(long *)*plVar30 + 200))();
                        plVar30[2] = lVar32;
                        thunk_EXT_FUN_8011000002946f14(plVar30 + 6);
                        puVar62 = (uint *)PTR_DAT_fffffff007ca5f88;
                        if (*(uint *)(*(long *)(*plVar30 + 0x18) + 0x78) < *(uint *)(lVar37 + 0x60))
                        {
                          thunk_EXT_FUN_801100000293ff9c();
                          puVar62 = (uint *)PTR_DAT_fffffff007ca5f88;
                        }
                      }
                    }
                    (**(code **)(*plVar28 + 0x28))(plVar28);
                  }
                  (**(code **)(*plVar27 + 0x28))(plVar27);
                  if (plVar30 != (long *)0x0) {
                    uVar43 = plVar30[2];
                    lVar32 = plVar30[3];
                    lVar46 = *(long *)(lVar37 + 0x20);
                    lVar44 = lVar32 * 0x18 + 8;
                    plVar27 = (long *)(lVar46 + (int)lVar44);
                    if (lVar44 != (int)lVar44) {
                      plVar27 = (long *)(lVar46 + lVar44 & 0xffffffffffffU | 0x2bad000000000000);
                    }
                    for (lVar44 = *plVar27; lVar44 != 0; lVar44 = *(long *)(lVar44 + 0x20)) {
                      if (uVar43 <= *(ulong *)(lVar44 + 0x10)) {
                        if (**(long **)(lVar44 + 0x28) != lVar44) {
                    /* WARNING: Does not return */
                          pcVar22 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff008186dcc);
                          (*pcVar22)();
                        }
                        plVar30[5] = (long)*(long **)(lVar44 + 0x28);
                        plVar30[4] = lVar44;
                        **(undefined8 **)(lVar44 + 0x28) = plVar30;
                        *(long **)(lVar44 + 0x28) = plVar30 + 4;
                        goto LAB_fffffff008185e24;
                      }
                    }
                    lVar44 = lVar32 * 0x18 + 0x10;
                    puVar4 = (undefined8 *)(lVar46 + (int)lVar44);
                    if (lVar44 != (int)lVar44) {
                      puVar4 = (undefined8 *)
                               (lVar46 + lVar44 & 0xffffffffffffU | 0x2bad000000000000);
                    }
                    plVar30[4] = 0;
                    puVar48 = (undefined8 *)*puVar4;
                    plVar30[5] = (long)puVar48;
                    *puVar48 = plVar30;
                    *puVar4 = plVar30 + 4;
LAB_fffffff008185e24:
                    lVar32 = lVar32 * 0x18;
                    plVar27 = (long *)(lVar46 + (int)lVar32);
                    if (lVar32 - (int)lVar32 != 0) {
                      plVar27 = (long *)(lVar46 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
                    }
                    *plVar27 = *plVar27 + uVar43;
                    lVar32 = *(long *)(lVar37 + 0x38);
                    uVar43 = *(long *)(lVar37 + 0x30) + uVar43;
                    uVar56 = lVar32 + 1;
                    *(ulong *)(lVar37 + 0x30) = uVar43;
                    *(ulong *)(lVar37 + 0x38) = uVar56;
                    uVar39 = *(ulong *)(lVar37 + 0x40);
                    if (uVar39 <= uVar56) {
                      uVar39 = lVar32 + 1;
                    }
                    *(ulong *)(lVar37 + 0x40) = uVar39;
                    fVar64 = *(float *)(lVar37 + 0x58);
                    goto LAB_fffffff008185e70;
                  }
                }
                lVar61 = *(long *)(lVar53 + 0x50);
                if ((*(byte *)(*(long *)(lVar53 + 0x28) + 0x1ac44) >> 3 & 1) != 0) {
                  uVar36 = *(ulong *)(lVar53 + 0x38);
                  if (uVar36 == 0) {
                    uVar42 = 0;
                  }
                  else {
                    uVar42 = 0;
                    if (uVar36 != 0) {
                      uVar42 = (ulong)(*(long *)(lVar61 + 0x30) * 100) / uVar36;
                    }
                  }
                  FUN_fffffff00817dc48
                            (*(long *)(lVar53 + 0x28),0x34d,0,lVar53,uVar36,*(long *)(lVar61 + 0x30)
                             ,uVar42,0);
                  lVar61 = *(long *)(lVar53 + 0x50);
                }
                thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(lVar61 + 0x10));
                *param_5 = *param_5 & 3;
                goto LAB_fffffff008186e20;
              }
LAB_fffffff008185e70:
              if (fVar64 < 1.0) {
                uVar56 = 0;
                if (uVar54 != 0) {
                  uVar56 = (ulong)(long)(fVar64 * (float)uVar33) / uVar54;
                }
                uVar33 = uVar56 * uVar54;
                if (uVar33 < uVar54 || uVar33 - uVar54 == 0) {
                  uVar33 = uVar54;
                }
              }
              uVar59 = (uVar59 - uVar36) + uVar43;
              uVar36 = uVar43;
            } while (uVar59 < uVar45);
            lVar37 = *(long *)(lVar53 + 0x50);
            uVar36 = *(ulong *)(lVar37 + 0x30);
          }
          *(ulong *)(lVar53 + 0x38) = uVar42;
        }
        local_b0._0_2_ = SUB82(PTR_DAT_fffffff007ca5f90,0);
        local_b0._2_2_ = (undefined2)((ulong)PTR_DAT_fffffff007ca5f90 >> 0x10);
        local_b0._4_4_ = (undefined4)((ulong)PTR_DAT_fffffff007ca5f90 >> 0x20);
        uStack_a8 = (undefined2)DAT_fffffff007113e50;
        uStack_a6 = (undefined6)((ulong)DAT_fffffff007113e50 >> 0x10);
        local_a0 = 0x40d8;
        uStack_9e = 0xfffffff0081d;
        uStack_98._0_2_ = 0x7600;
        uStack_98._2_2_ = 0x7c9;
        uStack_98._4_4_ = 0xfffffff0;
        lStack_90 = param_2;
        FUN_fffffff0081d40e8(&uStack_98,lVar37,&local_b0);
        thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(*(long *)(lVar53 + 0x50) + 0x10));
        if (uVar36 - uVar58 != 0) {
          FUN_fffffff00817eb58(*(undefined8 *)(lVar53 + 0x28),uVar36 - uVar58,0);
          lVar37 = *(long *)(lVar53 + 0x28);
          if ((*(byte *)(lVar37 + 0x1ac44) >> 3 & 1) != 0) {
            uVar42 = *(ulong *)(lVar53 + 0x38);
            if (uVar42 == 0) {
              thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar37 + 0x1ac48));
              uVar42 = 0;
              uVar58 = 0;
            }
            else {
              uVar58 = 0;
              if (uVar42 != 0) {
                uVar58 = (uVar36 * 100) / uVar42;
              }
              thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar37 + 0x1ac48));
            }
            thunk_EXT_FUN_80110000036da494(0x85930d34,lVar53,uVar42,uVar36,uVar58,0);
            thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar37 + 0x1ac48));
          }
        }
        lVar37 = *(long *)(lVar53 + 0x28);
        if ((*(byte *)(lVar37 + 0x1ac44) >> 3 & 1) != 0) {
          uVar26 = *(undefined8 *)(lVar53 + 0x38);
          uVar60 = *(undefined8 *)(param_2 + 0x100);
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar37 + 0x1ac48));
          thunk_EXT_FUN_80110000036da494(0x85930d50,lVar53,uVar26,uVar36,uVar60,0);
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar37 + 0x1ac48));
        }
        plVar27 = *(long **)(lVar53 + 0x58);
        if (plVar27 == (long *)0x0) {
LAB_fffffff0081860a8:
          *(undefined8 *)(lVar53 + 0x58) = 0;
          uVar26 = (**(code **)(DAT_fffffff00ae23e70 + 0x68))();
          *(undefined8 *)(lVar53 + 0x58) = uVar26;
          lVar37 = **(long **)(lVar53 + 0x30);
          plVar27 = (long *)(**(code **)(lVar37 + 0x158))
                                      (lVar37 + 0x158,*(long **)(lVar53 + 0x30),
                                       *(undefined8 *)(lVar53 + 0x60));
          plVar28 = *(long **)(lVar53 + 0x58);
          if (plVar27 == (long *)0x0) {
            if (plVar28 != (long *)0x0) {
              (**(code **)(*plVar28 + 0x28))(plVar28);
            }
            *(undefined8 *)(lVar53 + 0x58) = 0;
          }
          else {
            if (plVar28 != (long *)0x0) {
              lVar37 = *(long *)(lVar53 + 0x28);
              plVar28[2] = lVar37;
              plVar28[3] = (long)plVar27;
              plVar28[8] = *(long *)(lVar37 + 0x10a78);
              plVar28[9] = 0;
              *(undefined4 *)(plVar28 + 7) = 0xffffffff;
              plVar28[5] = 0;
              lVar37 = plVar27[0x3c];
              thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar37 + 0x38));
              if (*(long *)(lVar37 + 0x10) != 0) {
                puVar52 = (ulong *)(lVar37 + 0x90);
                uVar36 = *puVar52;
                if (uVar36 == 0) {
                  iVar24 = FUN_fffffff0081e76f4(lVar37);
                  if (iVar24 == 0) goto LAB_fffffff008186ee4;
                  uVar36 = *puVar52;
                }
                uVar42 = (uVar36 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar36 & 0x5555555555555555) << 1;
                uVar42 = (uVar42 & 0xcccccccccccccccc) >> 2 | (uVar42 & 0x3333333333333333) << 2;
                uVar42 = (uVar42 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar42 & 0xf0f0f0f0f0f0f0f) << 4;
                uVar42 = (uVar42 & 0xff00ff00ff00ff00) >> 8 | (uVar42 & 0xff00ff00ff00ff) << 8;
                uVar42 = (uVar42 & 0xffff0000ffff0000) >> 0x10 | (uVar42 & 0xffff0000ffff) << 0x10;
                uVar25 = (uint)LZCOUNT(uVar42 >> 0x20 | uVar42 << 0x20);
                if (uVar36 == 0) {
                  uVar25 = 0xffffffff;
                }
                lVar55 = (ulong)uVar25 * 8;
                iVar24 = (int)lVar55;
                puVar5 = (ulong *)(*(long *)(lVar37 + 0x98) + (long)iVar24);
                if (lVar55 != iVar24) {
                  puVar5 = (ulong *)(*(long *)(lVar37 + 0x98) + lVar55 & 0xffffffffffffU |
                                    0x2bad000000000000);
                }
                uVar42 = *puVar5;
                uVar36 = (uVar42 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar42 & 0x5555555555555555) << 1;
                uVar36 = (uVar36 & 0xcccccccccccccccc) >> 2 | (uVar36 & 0x3333333333333333) << 2;
                uVar36 = (uVar36 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar36 & 0xf0f0f0f0f0f0f0f) << 4;
                uVar36 = (uVar36 & 0xff00ff00ff00ff00) >> 8 | (uVar36 & 0xff00ff00ff00ff) << 8;
                uVar36 = (uVar36 & 0xffff0000ffff0000) >> 0x10 | (uVar36 & 0xffff0000ffff) << 0x10;
                uVar35 = (uint)LZCOUNT(uVar36 >> 0x20 | uVar36 << 0x20);
                if (uVar42 == 0) {
                  uVar35 = 0xffffffff;
                }
                uVar3 = uVar35 + uVar25 * 0x40;
                uVar8 = *(uint *)(lVar37 + 0x48);
                uVar12 = 0;
                if (uVar8 != 0) {
                  uVar12 = uVar3 / uVar8;
                }
                lVar44 = *(long *)(lVar37 + 0x40) * (ulong)(uVar3 - uVar12 * uVar8);
                lVar32 = (ulong)uVar12 * 8;
                iVar63 = (int)lVar32;
                plVar30 = (long *)(*(long *)(lVar37 + 0x78) + (long)iVar63);
                if (lVar32 != iVar63) {
                  plVar30 = (long *)(*(long *)(lVar37 + 0x78) + lVar32 & 0xffffffffffffU |
                                    0x2bad000000000000);
                }
                plVar30 = *(long **)(*plVar30 + 8);
                plVar28[4] = (long)plVar30;
                (**(code **)(*plVar30 + 0x20))();
                puVar4 = (undefined8 *)(*(long *)(lVar37 + 0x78) + (long)iVar63);
                if (lVar32 != iVar63) {
                  puVar4 = (undefined8 *)
                           (*(long *)(lVar37 + 0x78) + lVar32 & 0xffffffffffffU | 0x2bad000000000000
                           );
                }
                piVar34 = (int *)*puVar4;
                *piVar34 = *piVar34 + 1;
                lVar46 = (**(code **)(**(long **)(*(long *)(piVar34 + 2) + 0x58) + 0x98))();
                plVar28[6] = lVar46 + lVar44;
                plVar30 = (long *)(*(long *)(lVar37 + 0x78) + (long)iVar63);
                if (lVar32 != iVar63) {
                  plVar30 = (long *)(*(long *)(lVar37 + 0x78) + lVar32 & 0xffffffffffffU |
                                    0x2bad000000000000);
                }
                uVar42 = (**(code **)(**(long **)(*(long *)(*plVar30 + 8) + 0x60) + 0x78))();
                uVar36 = uVar42 + lVar44;
                if (((uVar42 ^ uVar36) & 0xffc0000000000000) != 0) {
                  uVar36 = uVar36 & 0xffffffffffff | 0xc8a2000000000000;
                }
                plVar28[5] = uVar36;
                plVar30 = (long *)(*(long *)(lVar37 + 0x98) + (long)iVar24);
                if (lVar55 != iVar24) {
                  plVar30 = (long *)(*(long *)(lVar37 + 0x98) + lVar55 & 0xffffffffffffU |
                                    0x2bad000000000000);
                }
                uVar36 = (ulong)(uVar35 >> 3) & 0x1ffffff8;
                puVar5 = (ulong *)((long)plVar30 + (long)(int)uVar36);
                if (uVar36 != (long)(int)uVar36) {
                  puVar5 = (ulong *)((long)plVar30 + uVar36 & 0xffffffffffff | 0x2bad000000000000);
                }
                *puVar5 = *puVar5 & (1L << ((ulong)uVar35 & 0x3f) ^ 0xffffffffffffffffU);
                if (*plVar30 == 0) {
                  uVar36 = (ulong)(uVar25 >> 3) & 0x1ffffff8;
                  *(ulong *)((long)puVar52 + uVar36) =
                       *(ulong *)((long)puVar52 + uVar36) &
                       (1L << ((ulong)uVar25 & 0x3f) ^ 0xffffffffffffffffU);
                }
                thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar37 + 0x38));
                *(uint *)(plVar28 + 7) = uVar3;
                lVar37 = plVar28[4];
                uVar25 = (**(code **)(*plVar27 + 0x160))(*plVar27 + 0x160,plVar27);
                if (*(uint *)(*(long *)(lVar37 + 0x48) + 0x78) < uVar25) {
                  thunk_EXT_FUN_801100000293ff9c();
                }
                goto LAB_fffffff008186398;
              }
LAB_fffffff008186ee4:
              thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar37 + 0x38));
              *(undefined4 *)(plVar28 + 7) = 0xffffffff;
              if (*(long **)(lVar53 + 0x58) != (long *)0x0) {
                (**(code **)(**(long **)(lVar53 + 0x58) + 0x28))();
              }
            }
            *(undefined8 *)(lVar53 + 0x58) = 0;
            *param_5 = *param_5 & 3 | 4;
          }
        }
        else {
          if ((ulong)plVar27[8] < plVar27[9] + (lVar61 + 0x183U & 0x1ffffffffc0)) {
            (**(code **)(*plVar27 + 0x28))();
            goto LAB_fffffff0081860a8;
          }
LAB_fffffff008186398:
          lVar37 = *(long *)(lVar53 + 0x58);
          uVar36 = lVar61 + 0x183U & 0x1ffffffffc0;
          lVar61 = *(long *)(lVar37 + 0x48);
          if (((lVar61 + uVar36 <= *(ulong *)(lVar37 + 0x40)) &&
              (lVar55 = *(long *)(lVar37 + 0x28), lVar55 != 0)) && (*(long *)(lVar37 + 0x30) != 0))
          {
            *(long *)(param_3 + 0x10) = *(long *)(lVar37 + 0x30) + lVar61;
            *(ulong *)(lVar37 + 0x48) = *(long *)(lVar37 + 0x48) + uVar36;
            thunk_EXT_FUN_8011000002969708(param_2,lVar37);
            lVar37 = *(long *)(lVar37 + 0x20);
            if (*(long *)(lVar37 + 0x50) != 0) {
              thunk_EXT_FUN_8011000002969a34(param_2);
            }
            puVar62 = (uint *)(lVar55 + lVar61);
            if (*(long *)(lVar37 + 0x58) != 0) {
              thunk_EXT_FUN_8011000002969a34(param_2);
            }
            thunk_EXT_FUN_80110000039b8f8c
                      (*(undefined8 *)(*(long *)(*(long *)(lVar53 + 0x28) + 0x1ac50) + 0xf0),
                       uVar50 >> 10);
            lVar37 = *(long *)(lVar53 + 0x28);
            uVar25 = *(uint *)(lVar37 + 0x3e0);
            local_c0[0] = 0;
            local_c0[1] = 0;
            lVar61 = 0;
            if (*(long *)(lVar37 + 0x3b8) == 0 && *(long *)(lVar37 + 0x3b0) == 0) {
              lVar61 = 0x10;
            }
            puVar52 = (ulong *)(lVar37 + 0x3b0 + lVar61);
            local_c0[0] = *puVar52;
            local_c0[1] = puVar52[1];
            if (local_c0[1] == 0 && local_c0[0] == 0) {
              uVar42 = 0;
              local_b0._0_2_ = 0;
              local_b0._2_2_ = 0;
              local_b0._4_4_ = 0;
              uStack_a8 = 0;
              uStack_a6 = 0;
              uVar35 = uVar25 - 0x40;
              uVar36 = (ulong)uVar25;
              if (0x3f < uVar25) {
                uVar42 = (ulong)((uVar35 >> 6) + 1);
                if (uVar35 < 0xc0) {
                  uVar36 = 0;
LAB_fffffff0081864d8:
                  lVar61 = ((uVar35 >> 6) - uVar36) + 1;
                  do {
                    iVar24 = (int)(uVar36 * 8);
                    puVar4 = (undefined8 *)((long)&local_b0 + (long)iVar24);
                    if (uVar36 * 8 - (long)iVar24 != 0) {
                      puVar4 = (undefined8 *)
                               ((ulong)(&local_b0 + uVar36) & 0xffffffffffff | 0x2bad000000000000);
                    }
                    *puVar4 = 0xffffffffffffffff;
                    uVar36 = uVar36 + 1;
                    lVar61 = lVar61 + -1;
                  } while (lVar61 != 0);
                }
                else {
                  lVar61 = 0;
                  uVar36 = uVar42 & 0x7fffffc;
                  uVar58 = uVar36;
                  do {
                    (&uStack_98)[lVar61] = 0xffffffffffffffff;
                    *(undefined8 *)(&local_a0 + lVar61 * 4) = 0xffffffffffffffff;
                    lVar61 = lVar61 + 4;
                    uVar58 = uVar58 - 4;
                  } while (uVar58 != 0);
                  if (uVar36 != uVar42) goto LAB_fffffff0081864d8;
                }
                uVar36 = (ulong)(uVar25 & 0x3f);
              }
              if ((int)uVar36 != 0) {
                (&local_b0)[uVar42] =
                     (&local_b0)[uVar42] | -1L << (uVar36 & 0x3f) ^ 0xffffffffffffffffU;
              }
              local_c0[0] = CONCAT44(local_b0._4_4_,CONCAT22(local_b0._2_2_,(undefined2)local_b0));
              local_c0[1] = CONCAT62(uStack_a6,uStack_a8);
            }
            else {
            }
            puVar62[0x3f] = 0;
            puVar62[0x40] = 0;
            puVar62[0x3d] = 0;
            puVar62[0x3e] = 0;
            puVar62[0x3b] = 0;
            puVar62[0x3c] = 0;
            puVar62[0x39] = 0;
            puVar62[0x3a] = 0;
            uVar35 = (uint)(byte)(POPCOUNT((char)local_c0[0]) + POPCOUNT((char)(local_c0[0] >> 8)) +
                                  POPCOUNT((char)(local_c0[0] >> 0x10)) +
                                  POPCOUNT((char)(local_c0[0] >> 0x18)) +
                                  POPCOUNT((char)(local_c0[0] >> 0x20)) +
                                  POPCOUNT((char)(local_c0[0] >> 0x28)) +
                                  POPCOUNT((char)(local_c0[0] >> 0x30)) +
                                 POPCOUNT((char)(local_c0[0] >> 0x38))) +
                     (uint)(byte)(POPCOUNT((char)local_c0[1]) + POPCOUNT((char)(local_c0[1] >> 8)) +
                                  POPCOUNT((char)(local_c0[1] >> 0x10)) +
                                  POPCOUNT((char)(local_c0[1] >> 0x18)) +
                                  POPCOUNT((char)(local_c0[1] >> 0x20)) +
                                  POPCOUNT((char)(local_c0[1] >> 0x28)) +
                                  POPCOUNT((char)(local_c0[1] >> 0x30)) +
                                 POPCOUNT((char)(local_c0[1] >> 0x38)));
            puVar62[0x37] = 0;
            puVar62[0x38] = 0;
            puVar62[0x35] = 0;
            puVar62[0x36] = 0;
            puVar62[0x33] = 0;
            puVar62[0x34] = 0;
            puVar62[0x31] = 0;
            puVar62[0x32] = 0;
            puVar62[0x2f] = 0;
            puVar62[0x30] = 0;
            puVar62[0x2d] = 0;
            puVar62[0x2e] = 0;
            puVar62[0x2b] = 0;
            puVar62[0x2c] = 0;
            puVar62[0x29] = 0;
            puVar62[0x2a] = 0;
            puVar62[0x27] = 0;
            puVar62[0x28] = 0;
            puVar62[0x25] = 0;
            puVar62[0x26] = 0;
            puVar62[0x23] = 0;
            puVar62[0x24] = 0;
            puVar62[0x21] = 0;
            puVar62[0x22] = 0;
            puVar62[0x1f] = 0;
            puVar62[0x20] = 0;
            puVar62[0x1d] = 0;
            puVar62[0x1e] = 0;
            puVar62[0x1b] = 0;
            puVar62[0x1c] = 0;
            puVar62[0x19] = 0;
            puVar62[0x1a] = 0;
            puVar62[0x17] = 0;
            puVar62[0x18] = 0;
            puVar62[0x15] = 0;
            puVar62[0x16] = 0;
            puVar62[0x13] = 0;
            puVar62[0x14] = 0;
            puVar62[0x11] = 0;
            puVar62[0x12] = 0;
            puVar62[0xf] = 0;
            puVar62[0x10] = 0;
            puVar62[0xd] = 0;
            puVar62[0xe] = 0;
            puVar62[0xb] = 0;
            puVar62[0xc] = 0;
            puVar62[9] = 0;
            puVar62[10] = 0;
            puVar62[7] = 0;
            puVar62[8] = 0;
            puVar62[5] = 0;
            puVar62[6] = 0;
            puVar62[3] = 0;
            puVar62[4] = 0;
            puVar62[1] = 0;
            puVar62[2] = 0;
            puVar62[0x4b] = 0;
            puVar62[0x4c] = 0;
            puVar62[0x49] = 0;
            puVar62[0x4a] = 0;
            puVar62[0x4f] = 0;
            puVar62[0x50] = 0;
            puVar62[0x4d] = 0;
            puVar62[0x4e] = 0;
            puVar62[0x43] = 0;
            puVar62[0x44] = 0;
            puVar62[0x41] = 0;
            puVar62[0x42] = 0;
            puVar62[0x47] = 0;
            puVar62[0x48] = 0;
            puVar62[0x45] = 0;
            puVar62[0x46] = 0;
            uVar9 = uVar9 >> 2;
            *puVar62 = uVar9;
            uStack_a8 = 0;
            uStack_a6 = 0;
            local_b0._0_2_ = 0;
            local_b0._2_2_ = 0;
            local_b0._4_4_ = 0;
            uStack_98._0_2_ = 0;
            uStack_98._2_2_ = 0;
            uStack_98._4_4_ = 0;
            local_a0 = 0;
            uStack_9e = 0;
            if (uVar25 != 0) {
              uVar36 = 0;
              iVar24 = 0;
              do {
                uVar40 = (undefined2)iVar24;
                uVar42 = *(ulong *)((long)local_c0 + (uVar36 >> 3 & 0x1ffffffffffffff8)) >>
                         (uVar36 & 0x3f);
                if ((uVar42 & 1) == 0) {
                  uVar40 = 0xffff;
                }
                lVar61 = uVar36 * 2;
                puVar7 = (undefined2 *)((long)puVar62 + (long)(int)lVar61 + 0x44);
                if (lVar61 - (int)lVar61 != 0) {
                  puVar7 = (undefined2 *)
                           ((long)puVar62 + lVar61 + 0x44 & 0xffffffffffffU | 0x2bad000000000000);
                }
                iVar24 = iVar24 + ((uint)uVar42 & 1);
                *puVar7 = uVar40;
                uVar36 = uVar36 + 1;
              } while (uVar25 != uVar36);
            }
            if (uVar35 != 0) {
              uVar42 = 0;
              uVar36 = (ulong)uVar35;
              do {
                iVar24 = (int)(uVar42 * 4);
                puVar4 = (undefined8 *)((long)puVar62 + (long)iVar24 + 0x144);
                if (uVar42 * 4 != (long)iVar24) {
                  puVar4 = (undefined8 *)
                           ((ulong)(puVar62 + uVar42 + 0x51) & 0xffffffffffff | 0x2bad000000000000);
                }
                puVar4[5] = 0;
                puVar4[4] = 0;
                puVar4[7] = 0;
                puVar4[6] = 0;
                puVar4[1] = 0;
                *puVar4 = 0;
                puVar4[3] = 0;
                puVar4[2] = 0;
                uVar42 = (ulong)((int)uVar42 + uVar9);
                uVar36 = uVar36 - 1;
              } while (uVar36 != 0);
            }
            thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(*(long *)(lVar53 + 0x50) + 0x10));
            lVar61 = *(long *)(lVar53 + 0x50);
            uVar42 = *(ulong *)(lVar61 + 0x28);
            uVar36 = uVar42 - 1;
            local_f8 = uVar36;
            if ((long)uVar42 < 1) {
              lVar37 = 0;
              lVar55 = 0;
            }
            else {
              lVar32 = *(long *)(lVar61 + 0x20);
              lVar37 = uVar36 * 0x18 + 0x10;
              plVar27 = (long *)(lVar32 + (int)lVar37);
              if (lVar37 != (int)lVar37) {
                plVar27 = (long *)(lVar32 + lVar37 & 0xffffffffffffU | 0x2bad000000000000);
              }
              lVar55 = **(long **)(*plVar27 + 8);
              if (lVar55 == 0) {
                if (uVar36 == 0) {
                  lVar55 = 0;
                  local_f8 = 0xffffffffffffffff;
                  lVar37 = 0;
                }
                else {
                  lVar44 = 2 - uVar42;
                  do {
                    lVar37 = uVar36 * 0x18 + -8;
                    plVar27 = (long *)(lVar32 + (int)lVar37);
                    if (lVar37 != (int)lVar37) {
                      plVar27 = (long *)(lVar32 + lVar37 & 0xffffffffffffU | 0x2bad000000000000);
                    }
                    lVar55 = **(long **)(*plVar27 + 8);
                    if (lVar55 != 0) {
                      local_f8 = -lVar44;
                      goto LAB_fffffff0081866c0;
                    }
                    lVar37 = 0;
                    uVar36 = uVar36 - 1;
                    lVar44 = lVar44 + 1;
                    local_f8 = 0xffffffffffffffff;
                  } while (lVar44 != 1);
                }
              }
              else {
LAB_fffffff0081866c0:
                lVar37 = **(long **)(*(long *)(lVar55 + 0x28) + 8);
                while (lVar37 == 0) {
                  if (uVar42 <= local_f8) {
                    lVar37 = 0;
                    break;
                  }
                  uVar36 = local_f8 - 1;
                  bVar23 = local_f8 != 0;
                  lVar37 = 0;
                  local_f8 = uVar36;
                  if (bVar23) {
                    lVar37 = uVar36 * 0x18 + 0x10;
                    plVar27 = (long *)(lVar32 + (int)lVar37);
                    if (lVar37 != (int)lVar37) {
                      plVar27 = (long *)(lVar32 + lVar37 & 0xffffffffffffU | 0x2bad000000000000);
                    }
                    lVar37 = **(long **)(*plVar27 + 8);
                  }
                }
              }
            }
            uVar58 = 0;
            uVar36 = 0;
            bVar10 = *(byte *)(param_3 + 0x74);
            puVar31 = (uint *)((long)puVar62 + uVar50);
            if ((((ulong)puVar62 ^ (ulong)puVar31) & 0xffc0000000000000) != 0) {
              puVar31 = (uint *)((ulong)puVar31 & 0xffffffffffff | 0xc8a2000000000000);
            }
            bVar23 = (bVar10 & 1) == 0;
            puVar6 = puVar2;
            if (bVar23) {
              puVar6 = puVar1;
            }
            lVar32 = 0x68;
            if (bVar23) {
              lVar32 = 8;
            }
            uVar50 = 0xf;
            iVar24 = 0;
            do {
              lVar44 = lVar32;
              if (uVar50 != *puVar6) {
                lVar44 = 0;
              }
              uVar45 = lVar44 + (ulong)*(uint *)(lVar41 + uVar50 * 4);
              if (param_4 != 0) {
                if (uVar45 != 0) {
                  uVar45 = uVar45 + (ulong)*(uint *)(param_3 + 0x2c) * 2;
                }
                if (uVar50 == *(uint *)(param_3 + 0x28)) {
                  uVar45 = uVar45 + *(uint *)(param_3 + 0x30);
                }
              }
              iVar63 = iVar24;
              if (uVar45 != 0) {
                iVar49 = (int)uVar58;
                if ((bVar10 & 1) == 0) {
                  *(short *)((long)&local_b0 + uVar50 * 2) = (short)uVar58;
                }
                else if (uVar50 == *puVar2) {
                  local_b0._2_2_ = (short)uVar58;
                }
                uVar33 = (ulong)*(uint *)(&DAT_fffffff007115368 + uVar50 * 4);
                bVar11 = (&UNK_fffffff007113d80)[uVar50];
                iVar63 = iVar49;
                if (uVar50 != *(uint *)(param_3 + 0x28)) {
                  iVar63 = iVar24;
                }
                lVar44 = uVar58 * 2;
                puVar7 = (undefined2 *)((long)puVar62 + (long)(int)lVar44 + 0x24);
                if (lVar44 != (int)lVar44) {
                  puVar7 = (undefined2 *)
                           ((long)puVar62 + lVar44 + 0x24 & 0xffffffffffffU | 0x2bad000000000000);
                }
                *puVar7 = (short)uVar45;
                if (uVar35 != 0) {
                  uVar58 = 0;
                  uVar54 = 1L << (uVar50 & 0x3f);
                  do {
                    uVar56 = 0;
                    uVar43 = (ulong)(uVar9 * (int)uVar58);
                    lVar44 = uVar43 * 4;
                    iVar24 = (int)lVar44;
                    uVar59 = (long)puVar62 + (long)iVar24 + 0x184;
                    if (lVar44 != iVar24) {
                      uVar59 = (ulong)(puVar62 + uVar43 + 0x61) & 0xffffffffffff |
                               0x2bad000000000000;
                    }
                    do {
                      if (lVar55 == 0) {
                        uVar25 = 0;
                      }
                      else {
                        uVar43 = uVar36 + uVar33;
                        if (*(ulong *)(lVar55 + 0x10) < uVar36 + uVar33) {
                          do {
                            lVar55 = lVar37;
                            if (lVar55 == 0) {
                              uVar36 = 0;
                              uVar25 = 0;
                              lVar37 = lVar55;
                              goto LAB_fffffff00818691c;
                            }
                            lVar37 = **(long **)(*(long *)(lVar55 + 0x28) + 8);
                            if (lVar37 == 0) {
                              if ((long)local_f8 < (long)uVar42) {
                                uVar36 = local_f8;
                                if (-2 < (long)local_f8) {
                                  uVar36 = 0xffffffffffffffff;
                                }
                                do {
                                  if ((long)local_f8 < 0) {
                                    lVar37 = 0;
                                    local_f8 = uVar36;
                                    break;
                                  }
                                  uVar43 = local_f8 - 1;
                                  if (local_f8 == 0) {
                                    lVar37 = 0;
                                  }
                                  else {
                                    lVar37 = uVar43 * 0x18 + 0x10;
                                    plVar27 = (long *)(*(long *)(lVar61 + 0x20) + (long)(int)lVar37)
                                    ;
                                    if (lVar37 != (int)lVar37) {
                                      plVar27 = (long *)(*(long *)(lVar61 + 0x20) + lVar37 &
                                                         0xffffffffffffU | 0x2bad000000000000);
                                    }
                                    lVar37 = **(long **)(*plVar27 + 8);
                                  }
                                  local_f8 = uVar43;
                                } while (lVar37 == 0);
                              }
                              else {
                                lVar37 = 0;
                              }
                            }
                          } while (*(ulong *)(lVar55 + 0x10) < uVar33);
                          uVar36 = 0;
                          uVar43 = uVar33;
                        }
                        uVar25 = (uint)(*(long *)(lVar55 + 8) + uVar36 >> 8);
                        uVar36 = uVar43;
                      }
LAB_fffffff00818691c:
                      uVar43 = (ulong)(uint)(iVar49 * 0x430 + (int)uVar56 * 4) * 4;
                      puVar1 = (uint *)(uVar59 + (long)(int)uVar43);
                      if (uVar43 - (long)(int)uVar43 != 0) {
                        puVar1 = (uint *)(uVar59 + uVar43 & 0xffffffffffff | 0x2bad000000000000);
                      }
                      if (puVar1 < puVar31) {
                        *puVar1 = uVar25 | bVar11;
                      }
                      if ((uVar54 & 0x6ffc) == 0) {
                        uVar25 = 0;
                      }
                      else if (lVar55 == 0) {
                        uVar25 = 1;
                      }
                      else {
                        uVar39 = uVar36 + uVar33;
                        if (*(ulong *)(lVar55 + 0x10) < uVar36 + uVar33) {
                          do {
                            lVar55 = lVar37;
                            if (lVar55 == 0) {
                              uVar36 = 0;
                              uVar25 = 1;
                              lVar37 = lVar55;
                              goto LAB_fffffff008186a2c;
                            }
                            lVar37 = **(long **)(*(long *)(lVar55 + 0x28) + 8);
                            if (lVar37 == 0) {
                              if ((long)local_f8 < (long)uVar42) {
                                uVar36 = local_f8;
                                if (-2 < (long)local_f8) {
                                  uVar36 = 0xffffffffffffffff;
                                }
                                do {
                                  if ((long)local_f8 < 0) {
                                    lVar37 = 0;
                                    local_f8 = uVar36;
                                    break;
                                  }
                                  uVar39 = local_f8 - 1;
                                  if (local_f8 == 0) {
                                    lVar37 = 0;
                                  }
                                  else {
                                    lVar37 = uVar39 * 0x18 + 0x10;
                                    plVar27 = (long *)(*(long *)(lVar61 + 0x20) + (long)(int)lVar37)
                                    ;
                                    if (lVar37 != (int)lVar37) {
                                      plVar27 = (long *)(*(long *)(lVar61 + 0x20) + lVar37 &
                                                         0xffffffffffffU | 0x2bad000000000000);
                                    }
                                    lVar37 = **(long **)(*plVar27 + 8);
                                  }
                                  local_f8 = uVar39;
                                } while (lVar37 == 0);
                              }
                              else {
                                lVar37 = 0;
                              }
                            }
                          } while (*(ulong *)(lVar55 + 0x10) < uVar33);
                          uVar36 = 0;
                          uVar39 = uVar33;
                        }
                        uVar25 = (uint)(*(long *)(lVar55 + 8) + uVar36 >> 8) | 1;
                        uVar36 = uVar39;
                      }
LAB_fffffff008186a2c:
                      uVar39 = uVar43 | 4;
                      puVar1 = (uint *)(uVar59 + (long)(int)uVar39);
                      if (uVar39 != (long)(int)uVar39) {
                        puVar1 = (uint *)(uVar59 + uVar39 & 0xffffffffffff | 0x2bad000000000000);
                      }
                      if (puVar1 < puVar31) {
                        *puVar1 = uVar25;
                      }
                      if ((uVar54 & 0xad8) == 0) {
                        uVar25 = 0;
                      }
                      else if (lVar55 == 0) {
                        uVar25 = 1;
                      }
                      else {
                        uVar39 = uVar36 + uVar33;
                        if (*(ulong *)(lVar55 + 0x10) < uVar36 + uVar33) {
                          do {
                            lVar55 = lVar37;
                            if (lVar55 == 0) {
                              uVar36 = 0;
                              uVar25 = 1;
                              lVar37 = lVar55;
                              goto LAB_fffffff008186b34;
                            }
                            lVar37 = **(long **)(*(long *)(lVar55 + 0x28) + 8);
                            if (lVar37 == 0) {
                              if ((long)local_f8 < (long)uVar42) {
                                uVar36 = local_f8;
                                if (-2 < (long)local_f8) {
                                  uVar36 = 0xffffffffffffffff;
                                }
                                do {
                                  if ((long)local_f8 < 0) {
                                    lVar37 = 0;
                                    local_f8 = uVar36;
                                    break;
                                  }
                                  uVar39 = local_f8 - 1;
                                  if (local_f8 == 0) {
                                    lVar37 = 0;
                                  }
                                  else {
                                    lVar37 = uVar39 * 0x18 + 0x10;
                                    plVar27 = (long *)(*(long *)(lVar61 + 0x20) + (long)(int)lVar37)
                                    ;
                                    if (lVar37 != (int)lVar37) {
                                      plVar27 = (long *)(*(long *)(lVar61 + 0x20) + lVar37 &
                                                         0xffffffffffffU | 0x2bad000000000000);
                                    }
                                    lVar37 = **(long **)(*plVar27 + 8);
                                  }
                                  local_f8 = uVar39;
                                } while (lVar37 == 0);
                              }
                              else {
                                lVar37 = 0;
                              }
                            }
                          } while (*(ulong *)(lVar55 + 0x10) < uVar33);
                          uVar36 = 0;
                          uVar39 = uVar33;
                        }
                        uVar25 = (uint)(*(long *)(lVar55 + 8) + uVar36 >> 8) | 1;
                        uVar36 = uVar39;
                      }
LAB_fffffff008186b34:
                      uVar39 = uVar43 | 8;
                      puVar1 = (uint *)(uVar59 + (long)(int)uVar39);
                      if (uVar39 != (long)(int)uVar39) {
                        puVar1 = (uint *)(uVar59 + uVar39 & 0xffffffffffff | 0x2bad000000000000);
                      }
                      if (puVar1 < puVar31) {
                        *puVar1 = uVar25;
                      }
                      if ((uVar54 & 0x290) == 0) {
                        uVar25 = 0;
                      }
                      else if (lVar55 == 0) {
                        uVar25 = 1;
                      }
                      else {
                        uVar39 = uVar36 + uVar33;
                        if (*(ulong *)(lVar55 + 0x10) < uVar36 + uVar33) {
                          do {
                            lVar55 = lVar37;
                            if (lVar55 == 0) {
                              uVar36 = 0;
                              uVar25 = 1;
                              lVar37 = lVar55;
                              goto LAB_fffffff008186c3c;
                            }
                            lVar37 = **(long **)(*(long *)(lVar55 + 0x28) + 8);
                            if (lVar37 == 0) {
                              if ((long)local_f8 < (long)uVar42) {
                                uVar36 = local_f8;
                                if (-2 < (long)local_f8) {
                                  uVar36 = 0xffffffffffffffff;
                                }
                                do {
                                  if ((long)local_f8 < 0) {
                                    lVar37 = 0;
                                    local_f8 = uVar36;
                                    break;
                                  }
                                  uVar39 = local_f8 - 1;
                                  if (local_f8 == 0) {
                                    lVar37 = 0;
                                  }
                                  else {
                                    lVar37 = uVar39 * 0x18 + 0x10;
                                    plVar27 = (long *)(*(long *)(lVar61 + 0x20) + (long)(int)lVar37)
                                    ;
                                    if (lVar37 != (int)lVar37) {
                                      plVar27 = (long *)(*(long *)(lVar61 + 0x20) + lVar37 &
                                                         0xffffffffffffU | 0x2bad000000000000);
                                    }
                                    lVar37 = **(long **)(*plVar27 + 8);
                                  }
                                  local_f8 = uVar39;
                                } while (lVar37 == 0);
                              }
                              else {
                                lVar37 = 0;
                              }
                            }
                          } while (*(ulong *)(lVar55 + 0x10) < uVar33);
                          uVar36 = 0;
                          uVar39 = uVar33;
                        }
                        uVar25 = (uint)(*(long *)(lVar55 + 8) + uVar36 >> 8) | 1;
                        uVar36 = uVar39;
                      }
LAB_fffffff008186c3c:
                      uVar43 = uVar43 | 0xc;
                      puVar1 = (uint *)(uVar59 + (long)(int)uVar43);
                      if (uVar43 != (long)(int)uVar43) {
                        puVar1 = (uint *)(uVar59 + uVar43 & 0xffffffffffff | 0x2bad000000000000);
                      }
                      if (puVar1 < puVar31) {
                        *puVar1 = uVar25;
                      }
                      uVar56 = (ulong)((int)uVar56 + 1);
                    } while (uVar56 < uVar45);
                    uVar58 = uVar58 + 1;
                  } while (uVar58 != uVar35);
                }
                uVar58 = (ulong)(iVar49 + 1);
              }
              uVar50 = uVar50 - 1;
              iVar24 = iVar63;
            } while (uVar50 != 0);
            thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(lVar61 + 0x10));
            *(short *)(puVar62 + 1) = (short)iVar63;
            *(ulong *)((long)puVar62 + 0xe) = CONCAT26(local_a0,uStack_a6);
            *(ulong *)((long)puVar62 + 6) =
                 CONCAT26(uStack_a8,CONCAT42(local_b0._4_4_,local_b0._2_2_));
            *(ulong *)((long)puVar62 + 0x16) = CONCAT26((undefined2)uStack_98,uStack_9e);
            *(undefined2 *)((long)puVar62 + 0x1e) = uStack_98._2_2_;
            puVar62[8] = uStack_98._4_4_;
            thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar53 + 0x80));
            goto LAB_fffffff008186cf8;
          }
          *param_5 = *param_5 & 3 | 8;
        }
LAB_fffffff008186e20:
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar53 + 0x80));
      }
    }
LAB_fffffff0081857b4:
    uVar26 = 0;
  }
  if (*(long *)PTR_DAT_fffffff007ca61a0 != local_80) {
    thunk_EXT_FUN_8011000003a48590(uVar26);
    return;
  }
  return;
}

