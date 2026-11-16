// FUN_fffffff00817fc0c @ fffffff00817fc0c size=3836

long * FUN_fffffff00817fc0c(long param_1,int param_2)

{
  ulong *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  long *plVar8;
  long *plVar9;
  undefined8 uVar10;
  long *plVar11;
  long *plVar12;
  long *plVar13;
  long *plVar14;
  ulong uVar15;
  long lVar16;
  byte bVar17;
  byte *pbVar18;
  undefined8 *puVar19;
  ulong uVar20;
  long lVar21;
  long *local_b8;
  byte *local_b0;
  long lStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined4 local_64;
  
  bVar17 = 4;
  if (param_2 == 0) {
    bVar17 = 0;
  }
  plVar8 = (long *)thunk_EXT_FUN_801100000389d0d8((bVar17 | *(byte *)(param_1 + 0x43a) & 1) + 6);
  if (plVar8 == (long *)0x0) {
    return (long *)0x0;
  }
  if (param_2 == 0) {
LAB_fffffff0081805ec:
    plVar9 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(param_1 + 0x3e0),0x20);
    if (plVar9 != (long *)0x0) {
      iVar5 = (**(code **)(*plVar8 + 0x100))(plVar8,"num_cores",plVar9);
      (**(code **)(*plVar9 + 0x28))(plVar9);
      if ((iVar5 != 0) &&
         (plVar9 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(param_1 + 0x3f4),0x20),
         plVar9 != (long *)0x0)) {
        iVar5 = (**(code **)(*plVar8 + 0x100))(plVar8,"num_frags",plVar9);
        (**(code **)(*plVar9 + 0x28))(plVar9);
        if ((iVar5 != 0) &&
           (plVar9 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(param_1 + 0x3ec),0x20),
           plVar9 != (long *)0x0)) {
          iVar5 = (**(code **)(*plVar8 + 0x100))(plVar8,"num_gps",plVar9);
          (**(code **)(*plVar9 + 0x28))(plVar9);
          if ((iVar5 != 0) &&
             (plVar9 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(param_1 + 0x414),0x20)
             , plVar9 != (long *)0x0)) {
            iVar5 = (**(code **)(*plVar8 + 0x100))(plVar8,"num_mgpus",plVar9);
            (**(code **)(*plVar9 + 0x28))(plVar9);
            if ((iVar5 != 0) &&
               (plVar9 = (long *)thunk_EXT_FUN_80110000038c6e24
                                           (*(undefined4 *)(param_1 + 0x442),0x20),
               plVar9 != (long *)0x0)) {
              iVar5 = (**(code **)(*plVar8 + 0x100))(plVar8,"usc_gen",plVar9);
              (**(code **)(*plVar9 + 0x28))(plVar9);
              if ((iVar5 != 0) && (iVar5 = FUN_fffffff008211d9c(plVar8,"is_sksm",0), iVar5 != 0)) {
                if ((*(byte *)(param_1 + 0x43a) & 1) == 0) {
LAB_fffffff0081809e8:
                  lVar16 = (ulong)*(uint *)(param_1 + 0x3d0) * 8;
                  puVar19 = (undefined8 *)(&DAT_fffffff007c94f28 + (int)lVar16);
                  if (lVar16 - (int)lVar16 != 0) {
                    puVar19 = (undefined8 *)
                              ((ulong)(&DAT_fffffff007c94f28 + lVar16) & 0xffffffffffff |
                              0x2bad000000000000);
                  }
                  if (*(char *)*puVar19 == 'G') {
                    local_b0 = (byte *)0x0;
                    iVar5 = thunk_EXT_FUN_80110000039baff8((char *)*puVar19 + 1,&local_b0,10);
                    if (iVar5 - 1U < 0xfffffffe) {
                      iVar5 = FUN_fffffff008211d9c(plVar8,"gpu_gen");
                      if (iVar5 == 0) goto LAB_fffffff008180ac0;
                      if (*local_b0 != 0) {
                        local_b8._0_2_ = (ushort)*local_b0;
                        uVar20 = FUN_fffffff008211d04(plVar8,"gpu_var",&local_b8);
                        if ((uVar20 & 1) == 0) goto LAB_fffffff008180ac0;
                      }
                    }
                  }
                  (**(code **)(*plVar8 + 0x20))(plVar8);
                  plVar9 = plVar8;
                  goto LAB_fffffff008180ac4;
                }
                plVar9 = (long *)thunk_EXT_FUN_80110000038961f4(*(undefined4 *)(param_1 + 0x414));
                if (plVar9 != (long *)0x0) {
                  if (*(int *)(param_1 + 0x414) != 0) {
                    uVar6 = 0;
                    do {
                      lVar16 = 0;
                      if (*(long *)(param_1 + 0x3b8) == 0 && *(long *)(param_1 + 0x3b0) == 0) {
                        lVar16 = 0x10;
                      }
                      uVar3 = *(uint *)(param_1 + 0x42c);
                      uVar4 = uVar3 * uVar6;
                      puVar19 = (undefined8 *)(param_1 + 0x3b0 + lVar16);
                      lStack_a8 = puVar19[1];
                      local_b0 = (byte *)*puVar19;
                      uVar7 = uVar4 & 0x3f;
                      if (uVar7 == 0) {
                        if (uVar4 < 0x80) {
                          pbVar18 = (&local_b0)[uVar4 >> 6];
                        }
                        else {
                          pbVar18 = (byte *)0x0;
                        }
                      }
                      else if (uVar4 < 0x80) {
                        if (uVar4 < 0x40) {
                          pbVar18 = (byte *)(lStack_a8 << ((ulong)(0x40 - uVar7) & 0x3f) |
                                            (ulong)(&local_b0)[uVar4 >> 6] >> uVar7);
                        }
                        else {
                          pbVar18 = (byte *)((ulong)(&local_b0)[uVar4 >> 6] >> uVar7);
                        }
                      }
                      else {
                        pbVar18 = (byte *)(0L >> uVar7);
                      }
                      uVar20 = (ulong)~(uint)(-1L << ((ulong)uVar3 & 0x3f));
                      if (0x3f < uVar3) {
                        uVar20 = 0xffffffff;
                      }
                      pbVar18 = (byte *)thunk_EXT_FUN_80110000038c6e24(uVar20 & (ulong)pbVar18,0x20)
                      ;
                      if (pbVar18 == (byte *)0x0) {
                        (**(code **)(*plVar9 + 0x28))(plVar9);
                        goto LAB_fffffff008180ac0;
                      }
                      local_b0 = pbVar18;
                      (**(code **)(*(long *)pbVar18 + 0x20))();
                      thunk_EXT_FUN_80110000038963f0(plVar9,&local_b0);
                      if (local_b0 != (byte *)0x0) {
                        (**(code **)(*(long *)local_b0 + 0x28))();
                      }
                      (**(code **)(*(long *)pbVar18 + 0x28))(pbVar18);
                      uVar6 = uVar6 + 1;
                    } while (uVar6 < *(uint *)(param_1 + 0x414));
                  }
                  iVar5 = (**(code **)(*plVar8 + 0x100))(plVar8,"core_mask_list",plVar9);
                  (**(code **)(*plVar9 + 0x28))(plVar9);
                  if (iVar5 != 0) goto LAB_fffffff0081809e8;
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    lVar16 = (ulong)*(uint *)(param_1 + 0x3d0) * 8;
    puVar19 = (undefined8 *)(&DAT_fffffff007c94f28 + (int)lVar16);
    if (lVar16 - (int)lVar16 != 0) {
      puVar19 = (undefined8 *)
                ((ulong)(&DAT_fffffff007c94f28 + lVar16) & 0xffffffffffff | 0x2bad000000000000);
    }
    plVar9 = (long *)thunk_EXT_FUN_80110000038ce200(*puVar19);
    if (plVar9 != (long *)0x0) {
      iVar5 = (**(code **)(*plVar8 + 0x100))(plVar8,"gpu_type",plVar9);
      (**(code **)(*plVar9 + 0x28))(plVar9);
      if (iVar5 != 0) {
        lVar16 = (ulong)*(uint *)(param_1 + 0x3d4) * 8;
        puVar19 = (undefined8 *)(&DAT_fffffff007c95000 + (int)lVar16);
        if (lVar16 - (int)lVar16 != 0) {
          puVar19 = (undefined8 *)
                    ((ulong)(&DAT_fffffff007c95000 + lVar16) & 0xffffffffffff | 0x2bad000000000000);
        }
        plVar9 = (long *)thunk_EXT_FUN_80110000038ce200(*puVar19);
        if (plVar9 != (long *)0x0) {
          iVar5 = (**(code **)(*plVar8 + 0x100))(plVar8,"gpu_rev",plVar9);
          (**(code **)(*plVar9 + 0x28))(plVar9);
          if ((iVar5 != 0) &&
             (plVar9 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(param_1 + 0x41c),0x20)
             , plVar9 != (long *)0x0)) {
            iVar5 = (**(code **)(*plVar8 + 0x100))(plVar8,"num_agcs",plVar9);
            (**(code **)(*plVar9 + 0x28))(plVar9);
            if (iVar5 != 0) {
              lVar16 = *(long *)(param_1 + 0x4b0);
              lVar21 = *(long *)(lVar16 + 0x910);
              uStack_88 = 0;
              local_90 = 0;
              uStack_78 = 0;
              uStack_80 = 0;
              lStack_a8 = 0;
              uStack_98 = 0;
              uStack_a0 = 0;
              local_b0 = (byte *)0x7;
              local_b8 = (long *)CONCAT44(local_b8._4_4_,2);
              uVar10 = (**(code **)(*(long *)(lVar16 + 0x848) + 0x30))(lVar16 + 0x848);
              local_64 = 0;
              plVar9 = *(long **)(*(long *)(lVar16 + 0x280) + 0x310);
              puVar19 = (undefined8 *)(*plVar9 + 0xe8);
              iVar5 = (*(code *)*puVar19)(puVar19,plVar9,FUN_fffffff00817ea94,&local_b0,&local_b8,
                                          &local_64,0);
              if ((iVar5 != 0) ||
                 ((((byte)local_b8 >> 1 & 1) != 0 &&
                  (iVar5 = FUN_fffffff0081a43cc(lVar16,uVar10,local_64), iVar5 != 0)))) {
                *(undefined1 *)(lVar21 + 0x8a2c) = 0;
              }
              if (*(char *)(lVar21 + 0x8a2c) == '\0') goto LAB_fffffff0081805ec;
              plVar9 = (long *)thunk_EXT_FUN_801100000389d0d8
                                         (POPCOUNT(*(undefined1 *)(lVar21 + 0x8a2c)));
              if ((*(byte *)(lVar21 + 0x8a2c) & 1) == 0) {
                uVar7 = 1;
              }
              else {
                puVar1 = (ulong *)(lVar21 + 0x851c);
                plVar13 = (long *)thunk_EXT_FUN_801100000389d0d8
                                            (((uint)(*puVar1 >> 0x28) & 0xff) + 1);
                plVar14 = (long *)thunk_EXT_FUN_801100000389d0d8(5);
                plVar11 = (long *)thunk_EXT_FUN_80110000038c6e24(*puVar1 & 0xff,0x20);
                if (plVar11 == (long *)0x0) {
LAB_fffffff00818005c:
                  uVar6 = 0;
                }
                else {
                  iVar5 = (**(code **)(*plVar14 + 0x100))(plVar14,"pi_ctrl_enable",plVar11);
                  (**(code **)(*plVar11 + 0x28))(plVar11);
                  if (iVar5 == 0) {
                    uVar6 = 0;
                  }
                  else {
                    iVar5 = FUN_fffffff008211d9c(plVar14,"pi_eval_window",(uint)*puVar1 >> 8 & 0xff)
                    ;
                    if ((((iVar5 == 0) ||
                         (iVar5 = FUN_fffffff008211d9c
                                            (plVar14,"pi_proportional_gain",
                                             (uint)*puVar1 >> 0x10 & 0xff), iVar5 == 0)) ||
                        (iVar5 = FUN_fffffff008211d9c
                                           (plVar14,"pi_integral_gain",*puVar1 >> 0x18 & 0xff),
                        iVar5 == 0)) ||
                       (iVar5 = FUN_fffffff008211d9c
                                          (plVar14,"pi_sg_target_profile_sel",*puVar1 >> 0x20 & 0xff
                                          ), iVar5 == 0)) goto LAB_fffffff00818005c;
                    iVar5 = FUN_fffffff008211d9c
                                      (plVar14,"num_omu_metric_entries",*puVar1 >> 0x28 & 0xff);
                    uVar6 = 0;
                    if ((iVar5 != 0) && (plVar14 != (long *)0x0)) {
                      uVar6 = (**(code **)(*plVar13 + 0x100))(plVar13,"config",plVar14);
                    }
                  }
                }
                if ((*puVar1 & 0xff0000000000) != 0) {
                  uVar20 = 0;
                  do {
                    puVar2 = (undefined2 *)(lVar21 + 0x844c + uVar20 * 0x10);
                    plVar11 = (long *)thunk_EXT_FUN_801100000389d0d8(8);
                    if (((uVar6 & 1) == 0) ||
                       (plVar12 = (long *)thunk_EXT_FUN_80110000038c6e24(*puVar2,0x20),
                       plVar12 == (long *)0x0)) {
LAB_fffffff008180318:
                      if (plVar11 != (long *)0x0) {
                        uVar6 = 0;
                        goto LAB_fffffff008180328;
                      }
LAB_fffffff008180094:
                      uVar6 = 0;
                    }
                    else {
                      iVar5 = (**(code **)(*plVar11 + 0x100))(plVar11,"target",plVar12);
                      (**(code **)(*plVar12 + 0x28))(plVar12);
                      if ((iVar5 == 0) ||
                         (plVar12 = (long *)thunk_EXT_FUN_80110000038c6e24(puVar2[1],0x20),
                         plVar12 == (long *)0x0)) goto LAB_fffffff008180318;
                      iVar5 = (**(code **)(*plVar11 + 0x100))(plVar11,"coeff_range_low",plVar12);
                      (**(code **)(*plVar12 + 0x28))(plVar12);
                      if ((iVar5 == 0) ||
                         (plVar12 = (long *)thunk_EXT_FUN_80110000038c6e24(puVar2[2],0x20),
                         plVar12 == (long *)0x0)) goto LAB_fffffff008180318;
                      iVar5 = (**(code **)(*plVar11 + 0x100))(plVar11,"coeff_range_mid",plVar12);
                      (**(code **)(*plVar12 + 0x28))(plVar12);
                      if ((iVar5 == 0) ||
                         (plVar12 = (long *)thunk_EXT_FUN_80110000038c6e24(puVar2[3],0x20),
                         plVar12 == (long *)0x0)) goto LAB_fffffff008180318;
                      iVar5 = (**(code **)(*plVar11 + 0x100))(plVar11,"coeff_range_high",plVar12);
                      (**(code **)(*plVar12 + 0x28))(plVar12);
                      if ((((iVar5 == 0) ||
                           (iVar5 = FUN_fffffff008211d9c(plVar11,"coeff_low",puVar2[4]), iVar5 == 0)
                           ) || (iVar5 = FUN_fffffff008211d9c(plVar11,"coeff_mid_low",puVar2[5]),
                                iVar5 == 0)) ||
                         ((iVar5 = FUN_fffffff008211d9c(plVar11,"coeff_mid_high",puVar2[6]),
                          iVar5 == 0 ||
                          (iVar5 = FUN_fffffff008211d9c(plVar11,"coeff_high",puVar2[7]), iVar5 == 0)
                          ))) goto LAB_fffffff008180318;
                      if (plVar11 == (long *)0x0) goto LAB_fffffff008180094;
                      uVar6 = (**(code **)(*plVar13 + 0x100))
                                        (plVar13,(&DAT_fffffff007c93028)[uVar20],plVar11);
LAB_fffffff008180328:
                      (**(code **)(*plVar11 + 0x28))(plVar11);
                    }
                    uVar20 = uVar20 + 1;
                  } while (uVar20 < (*puVar1 >> 0x28 & 0xff));
                }
                uVar7 = 0;
                if ((uVar6 != 0) && (plVar13 != (long *)0x0)) {
                  uVar7 = (**(code **)(*plVar9 + 0x100))(plVar9,"omu_crs",plVar13);
                }
                if (plVar14 != (long *)0x0) {
                  (**(code **)(*plVar14 + 0x28))(plVar14);
                }
                if (plVar13 != (long *)0x0) {
                  (**(code **)(*plVar13 + 0x28))(plVar13);
                }
              }
              if (((*(byte *)(lVar21 + 0x8a2c) >> 1 & 1) == 0) || (*(int *)(lVar21 + 0x8a24) == 0))
              {
LAB_fffffff00818058c:
                *(undefined1 *)(lVar21 + 0x8a2c) = 0;
                if (uVar7 == 0) goto LAB_fffffff008180580;
LAB_fffffff008180594:
                if (plVar9 == (long *)0x0) goto LAB_fffffff008180ac0;
                uVar20 = (**(code **)(*plVar8 + 0x100))(plVar8,"device_state",plVar9);
              }
              else {
                plVar13 = (long *)thunk_EXT_FUN_801100000389d0d8(2);
                plVar14 = (long *)thunk_EXT_FUN_80110000038961f4(*(undefined4 *)(lVar21 + 0x8a24));
                if (*(int *)(lVar21 + 0x8a24) != 0) {
                  uVar20 = 0;
                  do {
                    uVar15 = lVar21 + 0x8524U + uVar20 * 0x20;
                    if (((lVar21 + 0x8524U ^ uVar15) & 0xffc0000000000000) != 0) {
                      uVar15 = uVar15 & 0xffffffffffff | 0xc8a2000000000000;
                    }
                    local_b8 = (long *)thunk_EXT_FUN_80110000038ce200(uVar15);
                    thunk_EXT_FUN_80110000038963f0(plVar14,&local_b8);
                    if (local_b8 != (long *)0x0) {
                      (**(code **)(*local_b8 + 0x28))();
                    }
                    uVar20 = uVar20 + 1;
                  } while (uVar20 < *(uint *)(lVar21 + 0x8a24));
                }
                if ((uVar7 & 1) == 0) {
                  uVar7 = 0;
                  if (plVar14 != (long *)0x0) goto LAB_fffffff008180534;
                }
                else if (plVar14 == (long *)0x0) {
                  uVar7 = 0;
                }
                else {
                  iVar5 = (**(code **)(*plVar13 + 0x100))(plVar13,"counter_list",plVar14);
                  if (iVar5 == 0 || plVar13 == (long *)0x0) {
                    uVar7 = 0;
                  }
                  else {
                    uVar7 = (**(code **)(*plVar9 + 0x100))(plVar9,"rif_shadow",plVar13);
                  }
LAB_fffffff008180534:
                  (**(code **)(*plVar14 + 0x28))(plVar14);
                }
                if (plVar13 == (long *)0x0) goto LAB_fffffff00818058c;
                (**(code **)(*plVar13 + 0x28))(plVar13);
                *(undefined1 *)(lVar21 + 0x8a2c) = 0;
                if ((uVar7 & 1) != 0) goto LAB_fffffff008180594;
LAB_fffffff008180580:
                if (plVar9 == (long *)0x0) goto LAB_fffffff008180ac0;
                uVar20 = 0;
              }
              (**(code **)(*plVar9 + 0x28))(plVar9);
              if ((uVar20 & 1) != 0) goto LAB_fffffff0081805ec;
            }
          }
        }
      }
    }
  }
LAB_fffffff008180ac0:
  plVar9 = (long *)0x0;
LAB_fffffff008180ac4:
  (**(code **)(*plVar8 + 0x28))(plVar8);
  return plVar9;
}

