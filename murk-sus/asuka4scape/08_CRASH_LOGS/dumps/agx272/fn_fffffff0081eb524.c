// FUN_fffffff0081eb524 @ fffffff0081eb524 size=2856

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff0081eb524(long *param_1,long param_2,long param_3,long *param_4,long param_5)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  long *plVar9;
  ulong uVar10;
  long *plVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;
  ulong uVar20;
  
  uVar6 = (**(code **)(PTR_DAT_fffffff007ca60e0 + 0x78))();
  if ((int)uVar6 == 0) {
    return uVar6;
  }
  param_1[2] = param_2;
  param_1[3] = param_3;
  iVar5 = *(int *)(param_2 + 0x11144);
  if (iVar5 == 0) {
    iVar5 = *(int *)(param_2 + 0x614);
  }
  *(int *)(param_1 + 10) = iVar5;
  *(undefined8 *)((long)param_1 + 0x54) = *(undefined8 *)(param_5 + 0xc);
  param_1[0x42] = 0;
  param_1[0x21] = *(long *)(param_5 + 0x28);
  *(undefined1 *)(param_1 + 5) = 1;
  *(undefined4 *)((long)param_1 + 0x5c) = 0;
  *(undefined4 *)((long)param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x23) = 0;
  param_1[0x25] = 0;
  *(int *)(param_1 + 0x26) = (int)param_1[0x27];
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  lVar7 = thunk_EXT_FUN_8011000003397c88();
  param_1[0x2c] = lVar7;
  lVar7 = thunk_EXT_FUN_8011000003397c88();
  param_1[0x2d] = lVar7;
  param_1[0x2f] = 0;
  param_1[0x2e] = 0;
  param_1[0x30] = 0;
  *(undefined4 *)(param_1 + 0x41) = 0;
  uVar2 = *(uint *)(param_1 + 10);
  uVar20 = (ulong)uVar2;
  uVar8 = thunk_EXT_FUN_80110000038fe5cc(uVar20 << 3);
  lVar7 = thunk_EXT_FUN_80110000038ff010();
  param_1[0x24] = lVar7;
  if (lVar7 == 0) goto LAB_fffffff0081ebfec;
  lVar15 = param_4[1];
  lVar7 = *param_4;
  lVar16 = param_4[2];
  lVar13 = param_4[5];
  lVar12 = param_4[4];
  param_1[0x3c] = param_4[3];
  param_1[0x3b] = lVar16;
  param_1[0x3e] = lVar13;
  param_1[0x3d] = lVar12;
  param_1[0x3a] = lVar15;
  param_1[0x39] = lVar7;
  plVar9 = (long *)param_1[2];
  lVar7 = plVar9[0x22bf];
  if (lVar7 == 0) {
    lVar7 = plVar9[0x22bc];
  }
  uVar10 = (**(code **)(*plVar9 + 0xc10))(plVar9,lVar7);
  *(int *)(param_1 + 0x27) = (int)(uVar10 >> 0x11);
  lVar7 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca4698,(ulong)*(uint *)(param_1 + 10) << 3);
  param_1[0xf] = lVar7;
  if (lVar7 == 0) goto LAB_fffffff0081ebfec;
  uVar3 = *(uint *)(param_1 + 10);
  uVar20 = (ulong)uVar3;
  if (uVar3 != 0) {
    if (uVar3 < 4) {
      uVar10 = 0;
    }
    else {
      lVar15 = 0;
      uVar10 = uVar20 & 0xfffffffc;
      uVar19 = uVar10;
      do {
        lVar16 = lVar15 * 8;
        puVar1 = (undefined8 *)(lVar7 + (int)lVar16);
        if (lVar16 - (int)lVar16 != 0) {
          puVar1 = (undefined8 *)(lVar7 + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
        }
        puVar1[1] = 0;
        *puVar1 = 0;
        puVar1[3] = 0;
        puVar1[2] = 0;
        lVar15 = lVar15 + 4;
        uVar19 = uVar19 - 4;
      } while (uVar19 != 0);
      if (uVar10 == uVar20) goto LAB_fffffff0081eb700;
    }
    lVar15 = uVar20 - uVar10;
    do {
      lVar16 = uVar10 * 8;
      puVar1 = (undefined8 *)(lVar7 + (int)lVar16);
      if (lVar16 - (int)lVar16 != 0) {
        puVar1 = (undefined8 *)(lVar7 + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = 0;
      uVar10 = uVar10 + 1;
      lVar15 = lVar15 + -1;
    } while (lVar15 != 0);
  }
LAB_fffffff0081eb700:
  lVar7 = param_1[0x13];
  uVar3 = *(uint *)(param_1 + 0x14);
  param_1[0x13] = uVar8;
  *(uint *)(param_1 + 0x14) = uVar2;
  if (lVar7 != 0) {
    thunk_EXT_FUN_80110000038fe6b0(lVar7,(ulong)uVar3 << 3);
    uVar8 = param_1[0x13];
  }
  if (uVar8 == 0) {
LAB_fffffff0081ec044:
    uVar8 = 0;
    uVar20 = 0;
    goto LAB_fffffff0081ebfec;
  }
  uVar2 = *(uint *)(param_1 + 10);
  if (uVar2 != 0) {
    uVar20 = uVar8 + (ulong)*(uint *)(param_1 + 0x14) * 8;
    if (((uVar8 ^ uVar20) & 0xffc0000000000000) != 0) {
      uVar20 = uVar20 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar20 < uVar8) || (uVar20 - uVar8 >> 0x20 != 0)) {
LAB_fffffff0081ebfb8:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                );
    }
    lVar7 = 0x10000000;
    uVar10 = 0;
    uVar19 = (ulong)uVar2;
    do {
      if (lVar7 == 0) goto LAB_fffffff0081ebf94;
      if (((long)uVar10 < 0) || ((uint)(uVar20 - uVar8) < (int)(uVar10 >> 0x20) + 8U))
      goto LAB_fffffff0081ebfa0;
      uVar18 = (ulong)CARRY8(uVar8,uVar10 >> 0x20);
      uVar17 = -uVar18;
      if ((uVar17 != uVar18) || ((long)uVar17 < 0)) goto LAB_fffffff0081ebfac;
      *(undefined8 *)(uVar8 + (uVar10 >> 0x20)) = 0;
      lVar7 = lVar7 + -1;
      uVar10 = uVar10 + 0x800000000;
      uVar19 = uVar19 - 1;
    } while (uVar19 != 0);
  }
  lVar7 = thunk_EXT_FUN_80110000038fe580((ulong)uVar2 << 6);
  param_1[0x18] = lVar7;
  if (lVar7 != 0) {
    if ((int)param_1[10] != 0) {
      uVar8 = 0;
      do {
        uVar20 = param_1[0x18] + uVar8 * 0x40;
        if (((param_1[0x18] ^ uVar20) & 0xffc0000000000000) != 0) {
          uVar20 = uVar20 & 0xffffffffffff | 0xc8a2000000000000;
        }
        thunk_EXT_FUN_8011000002946f14(uVar20);
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(uint *)(param_1 + 10));
    }
    thunk_EXT_FUN_8011000002946f14(param_1 + 0x19);
    lVar7 = thunk_EXT_FUN_80110000038fe580((ulong)*(uint *)(param_1 + 0x27) << 6);
    param_1[0x31] = lVar7;
    if (lVar7 != 0) {
      lVar7 = thunk_EXT_FUN_80110000038fe750
                        (&DAT_fffffff007ca46e8,(ulong)*(uint *)(param_1 + 0x27) << 3);
      param_1[0x32] = lVar7;
      if (lVar7 != 0) {
        uVar2 = *(uint *)(param_1 + 10);
        plVar9 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))(&DAT_fffffff00ae22f20);
        puVar4 = PTR_DAT_fffffff007ca61d0;
        if (plVar9 == (long *)0x0) goto LAB_fffffff0081ec044;
        lVar7 = param_1[2];
        uVar3 = *(uint *)(lVar7 + 0x18b70);
        plVar9[2] = *(long *)PTR_DAT_fffffff007ca61d0;
        iVar5 = FUN_fffffff0081e07cc(plVar9,lVar7,(ulong)uVar2 * 0x40 + 0x40,uVar3 | 99);
        if (iVar5 != 0) {
          plVar11 = (long *)plVar9[10];
          if (plVar11 == (long *)0x0) {
            plVar11 = (long *)(**(code **)(*(long *)plVar9[9] + 0x90))
                                        ((long *)plVar9[9],plVar9[3],0x20900000084);
            if (plVar11 == (long *)0x0) goto LAB_fffffff0081ebfc4;
            (**(code **)(*plVar11 + 0x20))();
            (**(code **)(*plVar11 + 0x28))(plVar11);
            plVar9[10] = (long)plVar11;
          }
          lVar7 = (**(code **)(*plVar11 + 0x98))();
          if (lVar7 != 0) {
            plVar11 = (long *)plVar9[0xc];
            if (plVar11 == (long *)0x0) {
              lVar7 = thunk_EXT_FUN_801100000297ea14(plVar9[9],0);
              plVar9[0xc] = lVar7;
              if (lVar7 == 0) goto LAB_fffffff0081ebfc4;
              LOAcquire();
              DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + plVar9[6];
              LORelease();
              plVar11 = (long *)plVar9[0xc];
            }
            lVar7 = (**(code **)(*plVar11 + 0x78))();
            if (lVar7 != 0) {
              param_1[7] = (long)plVar9;
              lVar7 = (**(code **)(*(long *)plVar9[10] + 0x98))();
              lVar15 = (**(code **)(**(long **)(param_1[7] + 0x60) + 0x78))();
              lVar16 = _DAT_fffffff007113c60;
              if (lVar15 == 0) goto LAB_fffffff0081ebfe8;
              param_1[0xd] = _UNK_fffffff007113c68;
              param_1[0xc] = lVar16;
              plVar9 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))(&DAT_fffffff00ae22f20);
              if (plVar9 == (long *)0x0) goto LAB_fffffff0081ec044;
              lVar16 = param_1[2];
              uVar2 = *(uint *)(lVar16 + 0x18b70);
              plVar9[2] = *(long *)puVar4;
              iVar5 = FUN_fffffff0081e07cc(plVar9,lVar16,0x80,uVar2 | 99);
              if (iVar5 != 0) {
                plVar11 = (long *)plVar9[10];
                if (plVar11 == (long *)0x0) {
                  plVar11 = (long *)(**(code **)(*(long *)plVar9[9] + 0x90))
                                              ((long *)plVar9[9],plVar9[3],0x800000084);
                  if (plVar11 == (long *)0x0) goto LAB_fffffff0081ebfc4;
                  (**(code **)(*plVar11 + 0x20))();
                  (**(code **)(*plVar11 + 0x28))(plVar11);
                  plVar9[10] = (long)plVar11;
                }
                lVar16 = (**(code **)(*plVar11 + 0x98))();
                if (lVar16 != 0) {
                  plVar11 = (long *)plVar9[0xc];
                  if (plVar11 == (long *)0x0) {
                    lVar16 = thunk_EXT_FUN_801100000297ea14(plVar9[9],0);
                    plVar9[0xc] = lVar16;
                    if (lVar16 == 0) goto LAB_fffffff0081ebfc4;
                    LOAcquire();
                    DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + plVar9[6];
                    LORelease();
                    plVar11 = (long *)plVar9[0xc];
                  }
                  lVar16 = (**(code **)(*plVar11 + 0x78))();
                  if (lVar16 != 0) {
                    param_1[8] = (long)plVar9;
                    lVar16 = (**(code **)(*(long *)plVar9[10] + 0x98))();
                    lVar12 = (**(code **)(**(long **)(param_1[8] + 0x60) + 0x78))();
                    if (lVar12 == 0) goto LAB_fffffff0081ebfe8;
                    plVar9 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))
                                               (&DAT_fffffff00ae22f20);
                    if (plVar9 == (long *)0x0) goto LAB_fffffff0081ec044;
                    lVar13 = param_1[2];
                    lVar14 = param_1[0xd];
                    uVar2 = *(uint *)(param_1 + 0x27);
                    uVar3 = *(uint *)(lVar13 + 0x18b70);
                    plVar9[2] = *(long *)puVar4;
                    iVar5 = FUN_fffffff0081e07cc(plVar9,lVar13,lVar14 * (ulong)uVar2,uVar3 | 99);
                    if (iVar5 != 0) {
                      plVar11 = (long *)plVar9[10];
                      if (plVar11 == (long *)0x0) {
                        plVar11 = (long *)(**(code **)(*(long *)plVar9[9] + 0x90))
                                                    ((long *)plVar9[9],plVar9[3],0x20900000084);
                        if (plVar11 == (long *)0x0) goto LAB_fffffff0081ebfc4;
                        (**(code **)(*plVar11 + 0x20))();
                        (**(code **)(*plVar11 + 0x28))(plVar11);
                        plVar9[10] = (long)plVar11;
                      }
                      lVar13 = (**(code **)(*plVar11 + 0x98))();
                      if (lVar13 != 0) {
                        plVar11 = (long *)plVar9[0xc];
                        if (plVar11 == (long *)0x0) {
                          lVar13 = thunk_EXT_FUN_801100000297ea14(plVar9[9],0);
                          plVar9[0xc] = lVar13;
                          if (lVar13 == 0) goto LAB_fffffff0081ebfc4;
                          LOAcquire();
                          DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + plVar9[6];
                          LORelease();
                          plVar11 = (long *)plVar9[0xc];
                        }
                        lVar13 = (**(code **)(*plVar11 + 0x78))();
                        if (lVar13 != 0) {
                          param_1[6] = (long)plVar9;
                          uVar2 = *(uint *)(param_1 + 10);
                          if (uVar2 != 0) {
                            uVar8 = 0;
                            lVar14 = 0;
                            lVar13 = 0;
                            uVar20 = param_1[0x13];
                            do {
                              if (uVar20 == 0) {
                                uVar10 = 0;
                              }
                              else {
                                uVar19 = uVar20 + (ulong)*(uint *)(param_1 + 0x14) * 8;
                                if (((uVar20 ^ uVar19) & 0xffc0000000000000) != 0) {
                                  uVar19 = uVar19 & 0xffffffffffff | 0xc8a2000000000000;
                                }
                                uVar10 = uVar19 - uVar20;
                                if ((uVar19 < uVar20) || (uVar10 >> 0x20 != 0))
                                goto LAB_fffffff0081ebfb8;
                              }
                              if (lVar14 == 0x80000000) {
LAB_fffffff0081ebf94:
                    /* WARNING: Subroutine does not return */
                                FUN_fffffff008214ca8
                                          (
                                          "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
                                          );
                              }
                              if (((long)uVar8 < 0) || ((uint)uVar10 < (int)(uVar8 >> 0x20) + 8U)) {
LAB_fffffff0081ebfa0:
                    /* WARNING: Subroutine does not return */
                                FUN_fffffff008214ca8
                                          (
                                          "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                                          );
                              }
                              uVar19 = (ulong)CARRY8(uVar20,uVar8 >> 0x20);
                              uVar10 = -uVar19;
                              if ((uVar10 != uVar19) || ((long)uVar10 < 0)) {
LAB_fffffff0081ebfac:
                    /* WARNING: Subroutine does not return */
                                FUN_fffffff008214ca8
                                          (
                                          "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
                                          );
                              }
                              *(long *)(uVar20 + (uVar8 >> 0x20)) = lVar7;
                              *(long *)(param_1[0xf] + lVar13 * 8) = lVar15;
                              lVar7 = lVar7 + 0x40;
                              lVar15 = lVar15 + 0x40;
                              lVar13 = lVar13 + 1;
                              lVar14 = lVar14 + 8;
                              uVar8 = uVar8 + 0x800000000;
                            } while ((ulong)uVar2 * 8 - lVar14 != 0);
                          }
                          param_1[0x15] = lVar7;
                          param_1[0x17] = lVar16;
                          param_1[0x11] = lVar12;
                          param_1[0x12] = lVar16 + 0x40;
                          param_1[0xe] = lVar12 + 0x40;
                          lVar7 = (**(code **)(*(long *)plVar9[10] + 0x98))();
                          param_1[0x16] = lVar7;
                          lVar7 = (**(code **)(**(long **)(param_1[6] + 0x60) + 0x78))();
                          param_1[0x10] = lVar7;
                          if (lVar7 == 0) goto LAB_fffffff0081ebfe8;
                          if ((int)param_1[0x27] != 0) {
                            uVar8 = 0;
                            do {
                              uVar20 = param_1[0x31] + uVar8 * 0x40;
                              if (((param_1[0x31] ^ uVar20) & 0xffc0000000000000) != 0) {
                                uVar20 = uVar20 & 0xffffffffffff | 0xc8a2000000000000;
                              }
                              thunk_EXT_FUN_8011000002946f14(uVar20);
                              uVar8 = uVar8 + 1;
                            } while (uVar8 < *(uint *)(param_1 + 0x27));
                          }
                          lVar7 = 0x115d8;
                          plVar9 = (long *)param_1[2];
                          *(uint *)(param_1 + 0x2a) =
                               *(byte *)(plVar9 + 0x22bd) & 1 |
                               (*(byte *)((long)plVar9 + 0x115e9) & 1) << 1;
                          *(undefined4 *)((long)param_1 + 0x154) = 0;
                          param_1[0x2b] = 0;
                          if ((*(byte *)(param_5 + 0x25) & 1) == 0) {
                            lVar15 = plVar9[0x22be];
                            if (lVar15 == 0) goto LAB_fffffff0081ebe74;
                          }
                          else {
                            lVar15 = plVar9[0x22bf];
                            if (lVar15 == 0) {
                              lVar7 = 0x115e0;
LAB_fffffff0081ebe74:
                              lVar15 = *(long *)((long)plVar9 + lVar7);
                            }
                          }
                          *(int *)((long)param_1 + 0x13c) = (int)(lVar15 + 0x1ffffU >> 0x11);
                          *(undefined4 *)(param_1 + 0x28) = 0;
                          uVar2 = *(uint *)(param_5 + 0x18);
                          *(undefined4 *)((long)param_1 + 0x144) = *(undefined4 *)(param_5 + 0x14);
                          *(uint *)((long)param_1 + 0x14c) = uVar2;
                          *(undefined4 *)(param_1 + 0x29) = *(undefined4 *)(param_5 + 0x1c);
                          (**(code **)(*plVar9 + 0xe0))
                                    (plVar9,"AGXParameterBufferMaxSize",(ulong)uVar2 << 0x11,0x20);
                          (**(code **)(*(long *)param_1[2] + 0xe0))
                                    ((long *)param_1[2],"AGXParameterBufferMaxSizeEverMemless",
                                     (ulong)*(uint *)(param_1 + 0x29) << 0x11,0x20);
                          (**(code **)(*(long *)param_1[2] + 0xe0))
                                    ((long *)param_1[2],"AGXParameterBufferMaxSizeNeverMemless",
                                     (ulong)*(uint *)((long)param_1 + 0x144) << 0x11,0x20);
                          iVar5 = (**(code **)(*param_1 + 0x90))(param_1);
                          if (iVar5 != 0) {
                            if ((long *)param_1[4] != (long *)0x0) {
                              (**(code **)(*(long *)param_1[4] + 0x28))();
                            }
                            param_1[4] = 0;
                            uVar8 = FUN_fffffff0081ec04c(param_1);
                            if ((uVar8 & 1) != 0) {
                              return 1;
                            }
                          }
                          goto LAB_fffffff0081ebfe8;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
LAB_fffffff0081ebfc4:
        (**(code **)(*plVar9 + 0x28))(plVar9);
      }
    }
  }
LAB_fffffff0081ebfe8:
  uVar20 = 0;
  uVar8 = 0;
LAB_fffffff0081ebfec:
  (**(code **)(*param_1 + 0x140))(param_1);
  if (uVar8 != 0) {
    thunk_EXT_FUN_80110000038fe6b0(uVar8,uVar20 << 3);
  }
  return 0;
}

