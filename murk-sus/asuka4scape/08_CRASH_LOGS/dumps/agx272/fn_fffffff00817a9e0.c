// FUN_fffffff00817a9e0 @ fffffff00817a9e0 size=4

void FUN_fffffff00817a9e0(long param_1)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  bool bVar6;
  undefined4 uVar7;
  int iVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  undefined8 *puVar13;
  ulong uVar14;
  long **pplVar15;
  ulong uVar16;
  ulong uVar17;
  long *plVar18;
  long **pplVar19;
  ulong uVar20;
  long lVar21;
  undefined8 *puVar22;
  long **pplVar23;
  ulong uVar24;
  long *plVar25;
  ulong uVar26;
  long lVar27;
  long lVar28;
  int iVar29;
  long lVar30;
  ulong uVar31;
  bool bVar32;
  long lVar33;
  long *plVar34;
  ulong unaff_x30;
  long *plStack_100;
  long **pplStack_f8;
  undefined *puStack_f0;
  undefined8 uStack_e8;
  code *pcStack_e0;
  undefined *puStack_d8;
  undefined8 *puStack_d0;
  long lStack_c8;
  ulong uStack_c0;
  long **pplStack_b8;
  ulong uStack_b0;
  undefined8 uStack_a8;
  undefined8 *puStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x358));
  uVar4 = DAT_fffffff007113eb0;
  uVar3 = DAT_fffffff007113ea8;
  if (*(long *)(param_1 + 0x360) == 0) {
    bVar32 = false;
  }
  else {
    bVar32 = false;
    lVar10 = *(long *)(param_1 + 0x360);
    do {
      lVar33 = *(long *)(lVar10 + 0x10);
      lVar28 = *(long *)(*(long *)(*(long *)(lVar10 + 0x30) + 0x10) + 0x1ac50);
      uVar7 = (**(code **)(**(long **)(*(long *)(lVar10 + 0x30) + 0x1e0) + 0x50))();
      thunk_EXT_FUN_80110000039b8f8c(*(undefined8 *)(lVar28 + 0xf8),uVar7);
      plVar9 = *(long **)(*(long *)(lVar10 + 0x30) + 0x1e0);
      if (plVar9 != (long *)0x0) {
        (**(code **)(*plVar9 + 0x38))();
      }
      bVar6 = false;
      if (*(long *)(lVar10 + 0x38) != 0) {
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar10 + 0x80));
        uVar17 = *(ulong *)(lVar10 + 0x70);
        uVar20 = (uVar17 + *(long *)(lVar10 + 0x78) * 4) / 5;
        if (uVar20 <= uVar17) {
          uVar20 = uVar17;
        }
        *(undefined8 *)(lVar10 + 0x70) = 0;
        *(ulong *)(lVar10 + 0x78) = uVar20;
        uVar17 = *(ulong *)(lVar10 + 0x38);
        if ((*(byte *)(lVar10 + 0x4c) & 1) == 0) {
          uVar16 = (ulong)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f));
          if (uVar17 <= uVar16) {
            uVar1 = *(int *)(lVar10 + 0x68) + 1;
            *(uint *)(lVar10 + 0x68) = uVar1;
            if (uVar1 < 10) goto LAB_fffffff00817aa78;
            *(undefined4 *)(lVar10 + 0x68) = 0;
            goto LAB_fffffff00817abe4;
          }
          *(undefined4 *)(lVar10 + 0x68) = 0;
          uVar20 = ((uVar17 >> (uVar20 <= uVar17 >> 2)) + uVar16) - 1 & -uVar16;
joined_r0xfffffff00817abc0:
          bVar6 = uVar17 <= uVar20;
          uVar17 = uVar20;
          if (bVar6) goto LAB_fffffff00817aa78;
LAB_fffffff00817ac10:
          uVar20 = *(long *)(lVar10 + 0x38) - uVar17;
          if ((ulong)(long)((float)uVar17 * 0.05) <= uVar20) {
            uVar20 = (long)((float)uVar17 * 0.05);
          }
          lVar30 = *(long *)(lVar10 + 0x50);
          lVar28 = *(long *)(lVar30 + 0x30);
          thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(lVar30 + 0x10));
          uVar31 = *(ulong *)(lVar30 + 0x30);
          uVar16 = uVar31 - (uVar20 + uVar17);
          if (uVar31 < uVar20 + uVar17 || uVar16 == 0) {
            thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(lVar30 + 0x10));
          }
          else {
            uVar2 = uVar16 + uVar20;
            if (uVar31 <= uVar16 + uVar20) {
              uVar2 = uVar31;
            }
            plStack_100 = (long *)0x0;
            pplStack_f8 = &plStack_100;
            if (*(int *)(lVar30 + 0x48) == 1) {
              puStack_d0 = &uStack_a8;
              uStack_a8 = 0;
              uStack_98 = uVar3;
              uStack_90 = 0;
              puStack_f0 = PTR_DAT_fffffff007ca5f90;
              uStack_e8 = uVar4;
              pcStack_e0 = FUN_fffffff0081d4300;
              puStack_d8 = &DAT_fffffff007c976a0;
              lStack_c8 = lVar30;
              uStack_c0 = uVar2;
              pplStack_b8 = &plStack_100;
              uStack_b0 = uVar16;
              puStack_a0 = puStack_d0;
              FUN_fffffff0081d40e8(&puStack_d8,lVar30,&puStack_f0,0);
              thunk_EXT_FUN_80110000038e9dac(&uStack_a8,8);
            }
            else {
              uVar20 = *(ulong *)(lVar30 + 0x28);
              if (0 < (long)uVar20) {
                uVar12 = 0;
                uVar31 = 0;
                uVar24 = *(ulong *)(lVar30 + 0x20);
                pplVar23 = &plStack_100;
                do {
                  uVar26 = uVar24 + uVar31 * 0x18;
                  if (((uVar24 ^ uVar26) & 0xffc0000000000000) != 0) {
                    uVar26 = uVar26 & 0xffffffffffff | 0xc8a2000000000000;
                  }
                  plVar9 = *(long **)(uVar26 + 8);
                  while (plVar9 != (long *)0x0) {
                    pplVar19 = (long **)(plVar9 + 4);
                    plVar34 = *pplVar19;
                    lVar11 = plVar9[2];
                    if (uVar16 < lVar11 + uVar12) goto LAB_fffffff00817ae38;
                    lVar27 = plVar9[3];
                    if (plVar34 == (long *)0x0) {
                      puVar13 = (undefined8 *)plVar9[5];
                      if ((long *)*puVar13 != plVar9) goto LAB_fffffff00817b474;
                      lVar21 = lVar27 * 0x18 + 0x10;
                      puVar22 = (undefined8 *)(uVar24 + (long)(int)lVar21);
                      if (lVar21 != (int)lVar21) {
                        puVar22 = (undefined8 *)
                                  (uVar24 + lVar21 & 0xffffffffffff | 0x2bad000000000000);
                      }
                      *puVar22 = puVar13;
                    }
                    else {
                      if ((long **)plVar34[5] != pplVar19) {
                    /* WARNING: Does not return */
                        pcVar5 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817b47c);
                        (*pcVar5)();
                      }
                      if (*(long **)plVar9[5] != plVar9) {
LAB_fffffff00817b474:
                    /* WARNING: Does not return */
                        pcVar5 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817b478);
                        (*pcVar5)();
                      }
                      plVar34[5] = (long)plVar9[5];
                      puVar13 = (undefined8 *)plVar9[5];
                      pplStack_f8 = pplVar23;
                    }
                    lVar27 = lVar27 * 0x18;
                    plVar18 = (long *)(uVar24 + (long)(int)lVar27);
                    if (lVar27 - (int)lVar27 != 0) {
                      plVar18 = (long *)(uVar24 + lVar27 & 0xffffffffffff | 0x2bad000000000000);
                    }
                    *puVar13 = plVar34;
                    *plVar18 = *plVar18 - lVar11;
                    *(long *)(lVar30 + 0x38) = *(long *)(lVar30 + 0x38) + -1;
                    *(long *)(lVar30 + 0x30) = *(long *)(lVar30 + 0x30) - lVar11;
                    plVar9[4] = 0;
                    plVar9[5] = (long)pplStack_f8;
                    *pplStack_f8 = plVar9;
                    pplStack_f8 = pplVar19;
                    plVar9 = plVar34;
                    uVar12 = lVar11 + uVar12;
                    pplVar23 = pplVar19;
                  }
                  uVar31 = uVar31 + 1;
                } while (uVar31 != uVar20);
LAB_fffffff00817ae38:
                plVar34 = *(long **)(uVar24 + 8);
                plVar9 = plVar34;
                if (plVar34 == (long *)0x0) {
                  lVar11 = 0;
                  uVar31 = 1;
                  uVar26 = uVar20;
                  do {
                    lVar11 = lVar11 + 1;
                    if (uVar31 < uVar20) {
                      uVar14 = uVar24 + lVar11 * 0x18;
                      if (((uVar24 ^ uVar14) & 0xffc0000000000000) != 0) {
                        uVar14 = uVar14 & 0xffffffffffff | 0xc8a2000000000000;
                      }
                      plVar9 = *(long **)(uVar14 + 8);
                      if (plVar9 != (long *)0x0) goto LAB_fffffff00817ae44;
                    }
                    uVar31 = uVar31 + 1;
                    uVar26 = uVar26 - 1;
                  } while (uVar26 != 0);
                }
                else {
LAB_fffffff00817ae44:
                  plVar18 = (long *)*pplVar23[1];
                  if (plVar18 != (long *)0x0) {
                    lVar11 = plVar9[2];
                    uVar31 = plVar18[2];
                    if ((lVar11 - uVar31 != 0) &&
                       (uVar26 = (lVar11 - uVar31) + uVar12, uVar26 <= uVar16)) {
                      pplVar23 = (long **)(plVar9 + 4);
                      plVar34 = *pplVar23;
                      lVar27 = plVar9[3];
                      if (plVar34 == (long *)0x0) {
                        puVar13 = (undefined8 *)plVar9[5];
                        if ((long *)*puVar13 != plVar9) goto LAB_fffffff00817b48c;
                        lVar21 = lVar27 * 0x18 + 0x10;
                        puVar22 = (undefined8 *)(uVar24 + (long)(int)lVar21);
                        if (lVar21 != (int)lVar21) {
                          puVar22 = (undefined8 *)
                                    (uVar24 + lVar21 & 0xffffffffffff | 0x2bad000000000000);
                        }
                        *puVar22 = puVar13;
                      }
                      else {
                        if ((long **)plVar34[5] != pplVar23) {
                    /* WARNING: Does not return */
                          pcVar5 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817b4a0);
                          (*pcVar5)();
                        }
                        if (*(long **)plVar9[5] != plVar9) {
LAB_fffffff00817b48c:
                    /* WARNING: Does not return */
                          pcVar5 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817b494);
                          (*pcVar5)();
                        }
                        plVar34[5] = (long)plVar9[5];
                        puVar13 = (undefined8 *)plVar9[5];
                      }
                      *puVar13 = plVar34;
                      lVar27 = lVar27 * 0x18;
                      plVar34 = (long *)(uVar24 + (long)(int)lVar27);
                      if (lVar27 - (int)lVar27 != 0) {
                        plVar34 = (long *)(uVar24 + lVar27 & 0xffffffffffff | 0x2bad000000000000);
                      }
                      *plVar34 = *plVar34 - lVar11;
                      uVar16 = *(ulong *)(lVar30 + 0x38);
                      lVar11 = *(long *)(lVar30 + 0x30) - lVar11;
                      *(long *)(lVar30 + 0x30) = lVar11;
                      *(ulong *)(lVar30 + 0x38) = uVar16 - 1;
                      plVar34 = plVar18 + 4;
                      plVar25 = (long *)*plVar34;
                      if (plVar25 == (long *)0x0) {
                        pplVar19 = (long **)plVar18[5];
                        pplVar15 = pplVar19;
                        if (*pplVar19 != plVar18) goto LAB_fffffff00817b494;
                      }
                      else {
                        if ((long *)plVar25[5] != plVar34) {
                    /* WARNING: Does not return */
                          pcVar5 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817b4a4);
                          (*pcVar5)();
                        }
                        if (*(long **)plVar18[5] != plVar18) {
LAB_fffffff00817b494:
                    /* WARNING: Does not return */
                          pcVar5 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817b498);
                          (*pcVar5)();
                        }
                        plVar25[5] = (long)plVar18[5];
                        pplVar19 = pplStack_f8;
                        pplVar15 = (long **)plVar18[5];
                      }
                      *pplVar15 = plVar25;
                      plVar9[4] = 0;
                      plVar9[5] = (long)pplVar19;
                      *pplVar19 = plVar9;
                      lVar27 = plVar18[3];
                      lVar21 = lVar27 * 0x18 + 8;
                      plVar9 = (long *)(uVar24 + (long)(int)lVar21);
                      if (lVar21 != (int)lVar21) {
                        plVar9 = (long *)(uVar24 + lVar21 & 0xffffffffffff | 0x2bad000000000000);
                      }
                      for (lVar21 = *plVar9; pplStack_f8 = pplVar23, lVar21 != 0;
                          lVar21 = *(long *)(lVar21 + 0x20)) {
                        if (uVar31 <= *(ulong *)(lVar21 + 0x10)) {
                          plVar9 = *(long **)(lVar21 + 0x28);
                          if (*plVar9 != lVar21) {
                    /* WARNING: Does not return */
                            pcVar5 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817b4ac);
                            (*pcVar5)();
                          }
                          plVar18[4] = lVar21;
                          plVar18[5] = (long)plVar9;
                          **(undefined8 **)(lVar21 + 0x28) = plVar18;
                          *(long **)(lVar21 + 0x28) = plVar34;
                          goto LAB_fffffff00817aff8;
                        }
                      }
                      lVar21 = lVar27 * 0x18 + 0x10;
                      puVar13 = (undefined8 *)(uVar24 + (long)(int)lVar21);
                      if (lVar21 != (int)lVar21) {
                        puVar13 = (undefined8 *)
                                  (uVar24 + lVar21 & 0xffffffffffff | 0x2bad000000000000);
                      }
                      puVar22 = (undefined8 *)*puVar13;
                      plVar18[4] = 0;
                      plVar18[5] = (long)puVar22;
                      *puVar22 = plVar18;
                      *puVar13 = plVar34;
LAB_fffffff00817aff8:
                      lVar27 = lVar27 * 0x18;
                      plVar9 = (long *)(uVar24 + (long)(int)lVar27);
                      if (lVar27 - (int)lVar27 != 0) {
                        plVar9 = (long *)(uVar24 + lVar27 & 0xffffffffffff | 0x2bad000000000000);
                      }
                      *plVar9 = *plVar9 + uVar31;
                      *(ulong *)(lVar30 + 0x30) = lVar11 + uVar31;
                      *(ulong *)(lVar30 + 0x38) = uVar16;
                      uVar31 = *(ulong *)(lVar30 + 0x40);
                      if (*(ulong *)(lVar30 + 0x40) <= uVar16) {
                        uVar31 = uVar16;
                      }
                      *(ulong *)(lVar30 + 0x40) = uVar31;
                      plVar34 = *(long **)(uVar24 + 8);
                      uVar12 = uVar26;
                    }
                  }
                  if (plVar34 != (long *)0x0) {
LAB_fffffff00817b044:
                    lVar11 = plVar34[2];
                    if (lVar11 + uVar12 <= uVar2) {
                      pplVar23 = (long **)(plVar34 + 4);
                      plVar9 = *pplVar23;
                      lVar27 = plVar34[3];
                      if (plVar9 == (long *)0x0) {
                        puVar13 = (undefined8 *)plVar34[5];
                        if ((long *)*puVar13 != plVar34) goto LAB_fffffff00817b47c;
                        lVar21 = lVar27 * 0x18 + 0x10;
                        puVar22 = (undefined8 *)(uVar24 + (long)(int)lVar21);
                        if (lVar21 != (int)lVar21) {
                          puVar22 = (undefined8 *)
                                    (uVar24 + lVar21 & 0xffffffffffff | 0x2bad000000000000);
                        }
                        *puVar22 = puVar13;
                      }
                      else {
                        if ((long **)plVar9[5] != pplVar23) {
                    /* WARNING: Does not return */
                          pcVar5 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817b48c);
                          (*pcVar5)();
                        }
                        if (*(long **)plVar34[5] != plVar34) {
LAB_fffffff00817b47c:
                    /* WARNING: Does not return */
                          pcVar5 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817b484);
                          (*pcVar5)();
                        }
                        plVar9[5] = (long)plVar34[5];
                        puVar13 = (undefined8 *)plVar34[5];
                      }
                      lVar27 = lVar27 * 0x18;
                      plVar18 = (long *)(uVar24 + (long)(int)lVar27);
                      if (lVar27 - (int)lVar27 != 0) {
                        plVar18 = (long *)(uVar24 + lVar27 & 0xffffffffffff | 0x2bad000000000000);
                      }
                      *puVar13 = plVar9;
                      *plVar18 = *plVar18 - lVar11;
                      *(long *)(lVar30 + 0x38) = *(long *)(lVar30 + 0x38) + -1;
                      *(long *)(lVar30 + 0x30) = *(long *)(lVar30 + 0x30) - lVar11;
                      plVar34[4] = 0;
                      plVar34[5] = (long)pplStack_f8;
                      *pplStack_f8 = plVar34;
                      pplStack_f8 = pplVar23;
                    }
                    goto LAB_fffffff00817b110;
                  }
                }
                lVar11 = 0;
                uVar16 = 1;
                uVar31 = uVar20;
                do {
                  lVar11 = lVar11 + 1;
                  if (uVar16 < uVar20) {
                    uVar26 = uVar24 + lVar11 * 0x18;
                    if (((uVar24 ^ uVar26) & 0xffc0000000000000) != 0) {
                      uVar26 = uVar26 & 0xffffffffffff | 0xc8a2000000000000;
                    }
                    plVar34 = *(long **)(uVar26 + 8);
                    if (plVar34 != (long *)0x0) goto LAB_fffffff00817b044;
                  }
                  uVar16 = uVar16 + 1;
                  uVar31 = uVar31 - 1;
                } while (uVar31 != 0);
              }
            }
LAB_fffffff00817b110:
            uVar31 = *(ulong *)(lVar30 + 0x30);
            thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(lVar30 + 0x10));
            plVar9 = plStack_100;
            while (plVar9 != (long *)0x0) {
              plVar34 = (long *)plVar9[4];
              if (plVar34 == (long *)0x0) {
                pplVar19 = (long **)plVar9[5];
                pplVar23 = pplVar19;
                if (*pplVar19 != plVar9) goto LAB_fffffff00817b464;
              }
              else {
                if ((long *)plVar34[5] != plVar9 + 4) {
                    /* WARNING: Does not return */
                  pcVar5 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817b474);
                  (*pcVar5)();
                }
                if (*(long **)plVar9[5] != plVar9) {
LAB_fffffff00817b464:
                    /* WARNING: Does not return */
                  pcVar5 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817b46c);
                  (*pcVar5)();
                }
                plVar34[5] = (long)plVar9[5];
                pplVar19 = (long **)plVar9[5];
                pplVar23 = pplStack_f8;
              }
              pplStack_f8 = pplVar23;
              *pplVar19 = plVar34;
              if ((long *)*plVar9 != (long *)0x0) {
                (**(code **)(*(long *)*plVar9 + 0x28))();
              }
              *plVar9 = 0;
              thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca40a8,plVar9,0x70);
              plVar9 = plVar34;
            }
          }
          *(ulong *)(lVar10 + 0x38) = uVar17;
          FUN_fffffff00817eb58(*(undefined8 *)(lVar10 + 0x28),0,lVar28 - uVar31);
          lVar28 = *(long *)(lVar10 + 0x28);
          if ((*(byte *)(lVar28 + 0x1ac44) >> 3 & 1) != 0) {
            uVar20 = *(ulong *)(lVar10 + 0x38);
            if (uVar20 == 0) {
              thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar28 + 0x1ac48));
              uVar20 = 0;
              uVar16 = 0;
            }
            else {
              uVar16 = 0;
              if (uVar20 != 0) {
                uVar16 = (uVar31 * 100) / uVar20;
              }
              thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar28 + 0x1ac48));
            }
            thunk_EXT_FUN_80110000036da494(0x85930d34,lVar10,uVar20,uVar31,uVar16,0);
            thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar28 + 0x1ac48));
          }
        }
        else {
          if (uVar17 <= *(ulong *)(lVar10 + 0x40)) {
LAB_fffffff00817abe4:
            if (*(long **)(lVar10 + 0x58) != (long *)0x0) {
              (**(code **)(**(long **)(lVar10 + 0x58) + 0x28))();
            }
            *(undefined8 *)(lVar10 + 0x58) = 0;
            uVar17 = 0;
            goto LAB_fffffff00817ac10;
          }
          uVar16 = uVar17 - uVar20;
          if (uVar20 <= uVar17 && uVar16 != 0) {
            uVar20 = (ulong)(*(float *)(lVar10 + 0x48) * (float)uVar16);
            if (uVar16 - uVar20 < 0x401) {
              uVar20 = uVar16;
            }
            uVar20 = uVar17 - uVar20;
            goto joined_r0xfffffff00817abc0;
          }
          uVar17 = 1;
        }
LAB_fffffff00817aa78:
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar10 + 0x80));
        bVar6 = uVar17 != 0;
      }
      bVar32 = (bool)(bVar32 | bVar6);
      lVar10 = lVar33;
    } while (lVar33 != 0);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x358));
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x370));
  if (bVar32) {
    (**(code **)(**(long **)(param_1 + 0x378) + 0xf0))(*(long **)(param_1 + 0x378),1000);
  }
  else {
    *(undefined1 *)(param_1 + 0x380) = 0;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x370));
  plVar9 = (long *)thunk_EXT_FUN_8011000002940a54(*(undefined8 *)(param_1 + 0x1c8));
  if (plVar9 == (long *)0x0) {
    return;
  }
  iVar8 = (**(code **)(*plVar9 + 0x90))();
  if (iVar8 != 0) {
    iVar29 = 0;
    do {
      (**(code **)(*plVar9 + 0x118))(plVar9,iVar29);
      lVar10 = thunk_EXT_FUN_80110000029636a8();
      if (*(long **)(lVar10 + 0x1e0) != (long *)0x0) {
        (**(code **)(**(long **)(lVar10 + 0x1e0) + 0x38))();
      }
      iVar29 = iVar29 + 1;
    } while (iVar8 != iVar29);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00817b438. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar9 + 0x28))(plVar9,(undefined8 *)(*plVar9 + 0x28));
    return;
  }
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817b430);
  (*pcVar5)();
}

