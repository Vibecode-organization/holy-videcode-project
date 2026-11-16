// FUN_fffffff00816b838 @ fffffff00816b838 size=12184

/* WARNING: Removing unreachable block (ram,0xfffffff00816e444) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816e16c) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816dea4) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816d820) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816df18) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816e400) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816e5ec) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816c1bc) */

void FUN_fffffff00816b838(long *param_1,long *param_2)

{
  long *plVar1;
  uint uVar2;
  ulong uVar3;
  ulong *puVar4;
  uint *puVar5;
  uint uVar6;
  code *pcVar7;
  bool bVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined8 *puVar12;
  long lVar13;
  long *plVar14;
  long *plVar15;
  long *plVar16;
  long **pplVar17;
  undefined8 uVar18;
  long lVar19;
  long lVar20;
  byte bVar21;
  undefined4 uVar22;
  int *piVar23;
  ulong uVar24;
  int iVar25;
  ulong uVar26;
  long lVar27;
  ulong uVar28;
  long *plVar29;
  long *plVar30;
  undefined8 uVar31;
  char *pcVar32;
  long *local_260;
  undefined8 local_230;
  undefined8 local_228;
  undefined *local_220;
  undefined8 local_218;
  code *local_210;
  undefined *local_208;
  long lStack_200;
  undefined4 local_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  long *local_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  ulong local_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  uint local_140;
  ulong local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined4 local_110;
  long **local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  ulong uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  long local_80;
  
  local_80 = *(long *)PTR_DAT_fffffff007ca61a0;
  if ((char)param_1[0x313d] == '\0') {
    *(undefined1 *)(param_1 + 0x313d) = 1;
    bVar21 = *(byte *)(param_1 + 0xb4);
joined_r0xfffffff00816b8ac:
    if ((bVar21 & 1) != 0) goto LAB_fffffff00816e780;
  }
  else {
    bVar21 = *(byte *)(param_1 + 0xb4);
    if ((char)param_1[0x313d] == '\x01') goto joined_r0xfffffff00816b8ac;
  }
  iVar9 = (**(code **)(*(long *)param_1[0x96] + 0xe8))((long *)param_1[0x96],param_1 + 0x313c);
  if (iVar9 == 0) goto LAB_fffffff00816e780;
  plVar1 = param_1 + 0x2349;
  DataMemoryBarrier(2,3);
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  plVar30 = param_2;
  if (*(int *)(param_1[0x2c] + 0xe8) == 2) {
    lVar27 = param_1[0x23db];
    uVar28 = *(ulong *)(param_1[0x23c8] + 0x5c0);
    local_100 = (long **)0x0;
    thunk_EXT_FUN_80110000033982c4(*(undefined4 *)(param_1[0x23c8] + 0x23c),1000000000,&local_100);
    if ((((lVar27 != 0) && ((ulong)((long)local_100 + *(long *)(lVar27 + 0x290)) <= uVar28)) &&
        (*(long *)(lVar27 + 0x70) != 0)) &&
       ((uVar28 = thunk_EXT_FUN_801100000294991c(), (uVar28 & 1) != 0 &&
        (plVar29 = *(long **)(lVar27 + 0x70), plVar29 != (long *)0x0)))) {
      lVar27 = (**(code **)(*plVar29 + 0xd0))(plVar29);
      piVar23 = *(int **)(lVar27 + 0x68);
      if (((*piVar23 == piVar23[0xc]) &&
          ((*(int *)(lVar27 + 0x78) == piVar23[0xc] && (piVar23[0xc] != piVar23[0x10])))) &&
         ((**(code **)(*plVar29 + 0x20))(plVar29), plVar30 = plVar29, param_2 != (long *)0x0)) {
        (**(code **)(*param_2 + 0x28))(param_2);
      }
      (**(code **)(*plVar29 + 0x28))(plVar29);
    }
  }
  plVar29 = (long *)(**(code **)(*plVar30 + 0xd0))(plVar30);
  if (plVar29 == (long *)0x0) {
    plVar29 = (long *)param_1[0x234a];
    bVar21 = *(byte *)((long)param_1 + 0x1ac44);
  }
  else {
    bVar21 = *(byte *)((long)param_1 + 0x1ac44);
  }
  if ((bVar21 >> 3 & 1) != 0) {
    lVar27 = param_1[0x313d];
    lVar13 = plVar29[3];
    thunk_EXT_FUN_80110000032222a8(param_1[0x3589]);
    thunk_EXT_FUN_80110000036da494(0x85930c58,(char)lVar27,(long)(int)lVar13,0,0,0);
    thunk_EXT_FUN_8011000003222de0(param_1[0x3589]);
  }
  if ((DAT_fffffff00ae22cf1 & 0x12) == 0x10) {
    (**(code **)(*param_1 + 0x798))(param_1);
    thunk_EXT_FUN_8011000003a1145c("GPU Hang - Channel Restart");
  }
  if ((*(byte *)(param_1 + 0x316d) >> 3 & 1) == 0) {
    lVar27 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca24c8,200);
    puVar12 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(lVar27,&DAT_fffffff00ae239d8);
    *puVar12 = &DAT_fffffff007c9e8b8;
    thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae239d8);
    *plVar1 = lVar27;
    iVar9 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))(lVar27);
    if (iVar9 == 0) {
LAB_fffffff00816bb4c:
      (**(code **)(*(long *)*plVar1 + 0x28))();
      *plVar1 = 0;
    }
    else {
      *(undefined4 *)(lVar27 + 0xc) = 1;
      *(undefined1 *)(lVar27 + 0x10) = 0;
      lVar13 = thunk_EXT_FUN_801100000389d0d8(8);
      *(long *)(lVar27 + 0xb8) = lVar13;
      if (lVar13 == 0) goto LAB_fffffff00816bb4c;
      *(undefined1 *)(lVar27 + 0x11) = 0;
      *(undefined1 *)(lVar27 + 0x51) = 0;
      *(undefined8 *)(lVar27 + 0xc0) = 0;
    }
    (**(code **)(*plVar29 + 0x38))(plVar29);
    thunk_EXT_FUN_8011000003891b28();
    (**(code **)(*(long *)param_1[0x96] + 0xe0))();
  }
  uVar2 = (uint)(*(byte *)(param_1 + 0x313d) - 2 < 5) &
          0x1dU >> (ulong)(*(byte *)(param_1 + 0x313d) - 2 & 0x1f);
  if (uVar2 == 0) {
    thunk_EXT_FUN_80110000032222a8(param_1[0x3074]);
    *(undefined4 *)(param_1 + 0x305a) = 0;
    *(undefined4 *)((long)param_1 + 0x182d4) = 0;
    thunk_EXT_FUN_8011000003222de0(param_1[0x3074]);
  }
  lVar27 = thunk_EXT_FUN_8011000002959a74(plVar30);
  if (lVar27 == 0) {
    uVar31 = 0xffffffffffffffff;
  }
  else {
    uVar31 = *(undefined8 *)(lVar27 + 0x100);
  }
  plVar29 = (long *)thunk_EXT_FUN_801100000389d0d8(5);
  if (plVar29 == (long *)0x0) {
    uStack_178 = 0;
    local_180 = 0;
    uStack_168 = 0;
    uStack_170 = 0;
    uStack_198 = 0;
    local_1a0 = 0;
    uStack_188 = 0;
    uStack_190 = 0;
    uStack_1b8 = 0;
    local_1c0 = 0;
    uStack_1a8 = 0;
    uStack_1b0 = 0;
    uStack_1d8 = 0;
    local_1e0 = (long *)0x0;
    uStack_1c8 = 0;
    uStack_1d0 = 0;
    local_100 = &local_1e0;
    local_220 = (undefined *)0x80;
    FUN_fffffff008214c38(&local_100,&local_220,"%s");
    FUN_fffffff008214c38(&local_100,&local_220,"%s");
    bVar8 = false;
    uVar31 = 0;
    local_260 = (long *)0x0;
  }
  else {
    plVar14 = (long *)(**(code **)(*plVar30 + 0xd0))(plVar30);
    if ((long *)param_1[0x234a] == plVar14) {
      uVar10 = 0;
    }
    else {
      uVar10 = (**(code **)(*plVar14 + 0x150))();
    }
    plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar10,0x20);
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar29 + 0x100))(plVar29,"guilty_dm",plVar14);
      (**(code **)(*plVar14 + 0x28))(plVar14);
    }
    lVar27 = (**(code **)(*plVar30 + 0xd0))(plVar30);
    iVar9 = 0;
    iVar11 = *(int *)(param_1[0x2c] + 0xe8);
    pcVar32 = "unknown lockup";
    if (iVar11 < 3) {
      if (iVar11 == 1) {
        bVar21 = *(byte *)(param_1 + 0x313d);
        if (bVar21 < 4) {
          if (bVar21 == 1) {
            pcVar32 = "timestamp timeout";
            iVar9 = 1;
            goto LAB_fffffff00816be30;
          }
          if (bVar21 == 2) {
            pcVar32 = &DAT_fffffff00ae23950;
            thunk_EXT_FUN_80110000037693ec(&DAT_fffffff00ae23950,0x40,"%s");
            iVar9 = 4;
          }
          else {
            if (bVar21 != 3) goto LAB_fffffff00816bf04;
            iVar9 = 5;
            pcVar32 = "firmware assert";
          }
        }
        else if (bVar21 < 6) {
          if (bVar21 == 4) {
            pcVar32 = &DAT_fffffff00ae23950;
            thunk_EXT_FUN_80110000037693ec(&DAT_fffffff00ae23950,0x40,"%s");
            iVar9 = 9;
          }
          else if (bVar21 == 5) {
            pcVar32 = &DAT_fffffff00ae23950;
            thunk_EXT_FUN_80110000037693ec(&DAT_fffffff00ae23950,0x40,"%s");
            iVar9 = 10;
          }
          else {
LAB_fffffff00816bf04:
            iVar9 = 0;
            pcVar32 = "unknown vendor lockup";
          }
        }
        else if (bVar21 == 6) {
          pcVar32 = &DAT_fffffff00ae23950;
          thunk_EXT_FUN_80110000037693ec(&DAT_fffffff00ae23950,0x40,"%s");
          iVar9 = 0xb;
        }
        else {
          if (bVar21 != 7) goto LAB_fffffff00816bf04;
          iVar9 = 0xc;
          pcVar32 = "DSF Pause Timeout";
        }
      }
      else {
        pcVar32 = "unknown lockup";
        if (iVar11 == 2) {
          pcVar32 = "progress timeout";
          iVar9 = 2;
          goto LAB_fffffff00816be30;
        }
      }
    }
    else {
      if (iVar11 == 3) {
        iVar9 = 1;
        pcVar32 = "timestamp timeout (unlocked)";
      }
      else {
        if (iVar11 != 4) goto LAB_fffffff00816c274;
        iVar9 = 1;
        pcVar32 = "timestamp timeout (locked)";
      }
LAB_fffffff00816be30:
      if ((((param_1[0x234a] != lVar27) &&
           (piVar23 = *(int **)(lVar27 + 0x68), *piVar23 == piVar23[0xc])) &&
          (*(int *)(lVar27 + 0x78) == piVar23[0xc])) && (piVar23[0xc] != piVar23[0x10])) {
        lVar27 = plVar30[0x1b];
        if (lVar27 != 0) {
          if (*(int *)(lVar27 + 0x288) == 0) {
            bVar8 = false;
          }
          else {
            uVar28 = 0;
            do {
              lVar13 = thunk_EXT_FUN_8011000002c26620
                                 (*(undefined8 *)(lVar27 + 0x88 + uVar28 * 0x10));
              if (lVar13 < 0) {
                bVar8 = true;
                goto LAB_fffffff00816bffc;
              }
              uVar28 = uVar28 + 1;
            } while (uVar28 < *(uint *)(lVar27 + 0x288));
            bVar8 = false;
          }
LAB_fffffff00816bffc:
          plVar14 = (long *)thunk_EXT_FUN_801100000389d0d8(2);
          if (plVar14 != (long *)0x0) {
            plVar15 = (long *)thunk_EXT_FUN_80110000038961f4(*(undefined4 *)(lVar27 + 0x288));
            if (plVar15 != (long *)0x0) {
              plVar16 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(lVar27 + 0x28c),0x20)
              ;
              if (plVar16 != (long *)0x0) {
                (**(code **)(*plVar14 + 0x100))(plVar14,"iofence_num_iosurfaces",plVar16);
                (**(code **)(*plVar16 + 0x28))(plVar16);
              }
              if (*(int *)(lVar27 + 0x288) != 0) {
                uVar28 = 0;
                do {
                  pplVar17 = (long **)thunk_EXT_FUN_8011000002c23c70
                                                (*(undefined8 *)(lVar27 + 0x88 + uVar28 * 0x10));
                  if (pplVar17 != (long **)0x0) {
                    local_100 = pplVar17;
                    (*(code *)(*pplVar17)[4])();
                    thunk_EXT_FUN_80110000038963f0(plVar15,&local_100);
                    if (local_100 != (long **)0x0) {
                      (*(code *)(*local_100)[5])();
                    }
                    (*(code *)(*pplVar17)[5])(pplVar17);
                  }
                  uVar28 = uVar28 + 1;
                } while (uVar28 < *(uint *)(lVar27 + 0x288));
              }
              (**(code **)(*plVar14 + 0x100))(plVar14,"iofence_iosurfaces",plVar15);
              (**(code **)(*plVar15 + 0x28))(plVar15);
              iVar9 = 7;
              if (bVar8) {
                iVar9 = 8;
              }
              pcVar32 = "blocked by IOFence (speculative)";
              if (!bVar8) {
                pcVar32 = "blocked by IOFence";
              }
              (**(code **)(*plVar29 + 0x100))(*plVar29 + 0x100,plVar29,"iofence_list",plVar14);
              (**(code **)(*plVar14 + 0x28))(plVar14);
              goto LAB_fffffff00816c274;
            }
            (**(code **)(*plVar14 + 0x28))(plVar14);
          }
          if (bVar8) {
            iVar9 = 8;
            pcVar32 = "blocked by IOFence (speculative)";
            goto LAB_fffffff00816c274;
          }
        }
        iVar9 = 7;
        pcVar32 = "blocked by IOFence";
      }
    }
LAB_fffffff00816c274:
    plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24(iVar9,0x20);
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar29 + 0x100))(plVar29,"restart_reason",plVar14);
      (**(code **)(*plVar14 + 0x28))(plVar14);
    }
    plVar14 = (long *)thunk_EXT_FUN_80110000038ce200(pcVar32);
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar29 + 0x100))(plVar29,"restart_reason_desc",plVar14);
      (**(code **)(*plVar14 + 0x28))(plVar14);
    }
    if (((*(byte *)(param_1 + 0x316d) >> 5 & 1) != 0) &&
       (iVar11 = (**(code **)(*(long *)param_1[0x96] + 0x2a0))(), iVar11 != 0)) {
      local_100 = (long **)((ulong)local_100 & 0xffffffff00000000);
      iVar11 = (**(code **)(*param_1 + 0x7d8))(param_1,&local_100);
      if (iVar11 != 0) {
        plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24(6,0x20);
        if (plVar14 != (long *)0x0) {
          (**(code **)(*plVar29 + 0x100))(plVar29,"restart_reason",plVar14);
          (**(code **)(*plVar14 + 0x28))(plVar14);
        }
        thunk_EXT_FUN_80110000037693ec(&DAT_fffffff00ae23950,0x40,"USC exception for DM: %d");
        plVar14 = (long *)thunk_EXT_FUN_80110000038ce200(&DAT_fffffff00ae23950);
        if (plVar14 != (long *)0x0) {
          (**(code **)(*plVar29 + 0x100))(plVar29,"restart_reason_desc",plVar14);
          (**(code **)(*plVar14 + 0x28))(plVar14);
        }
        iVar9 = 6;
      }
    }
    iVar11 = (**(code **)(*(long *)param_1[0x96] + 0x2a0))();
    if (iVar11 != 0) {
      local_d0 = 0;
      uStack_e8 = 0;
      local_f0 = 0;
      uStack_d8 = 0;
      local_e0 = 0;
      uStack_f8 = 0;
      local_100 = (long **)0x0;
      iVar11 = (**(code **)(*param_1 + 0x7b8))(param_1,0,&local_100,0);
      if (iVar11 != 0) {
        plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24(3,0x20);
        if (plVar14 != (long *)0x0) {
          (**(code **)(*plVar29 + 0x100))(plVar29,"restart_reason",plVar14);
          (**(code **)(*plVar14 + 0x28))(plVar14);
        }
        thunk_EXT_FUN_80110000037693ec(&DAT_fffffff00ae23950,0x40,"BIF%d page fault");
        plVar14 = (long *)thunk_EXT_FUN_80110000038ce200(&DAT_fffffff00ae23950);
        if (plVar14 != (long *)0x0) {
          (**(code **)(*plVar29 + 0x100))(plVar29,"restart_reason_desc",plVar14);
          (**(code **)(*plVar14 + 0x28))(plVar14);
        }
        plVar14 = (long *)thunk_EXT_FUN_801100000389d0d8(5);
        if (plVar14 == (long *)0x0) {
          iVar9 = 3;
        }
        else {
          plVar15 = (long *)thunk_EXT_FUN_80110000038c6e24(local_f0._4_4_,0x20);
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar14 + 0x100))(plVar14,"requestor",plVar15);
            (**(code **)(*plVar15 + 0x28))(plVar15);
          }
          plVar15 = (long *)thunk_EXT_FUN_80110000038c6e24(uStack_e8 & 0xffffffff,0x20);
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar14 + 0x100))(plVar14,"sideband",plVar15);
            (**(code **)(*plVar15 + 0x28))(plVar15);
          }
          plVar15 = (long *)thunk_EXT_FUN_80110000038c6e24(local_e0 & 0xff,0x20);
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar14 + 0x100))(plVar14,"level",plVar15);
            (**(code **)(*plVar15 + 0x28))(plVar15);
          }
          plVar15 = (long *)thunk_EXT_FUN_80110000038970c4(local_e0._1_1_ & 1);
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar14 + 0x100))(plVar14,"is_read",plVar15);
            (**(code **)(*plVar15 + 0x28))(plVar15);
          }
          plVar15 = (long *)thunk_EXT_FUN_80110000038970c4(local_e0._2_1_ & 1);
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar14 + 0x100))(plVar14,"pm_protect",plVar15);
            (**(code **)(*plVar15 + 0x28))(plVar15);
          }
          plVar15 = (long *)thunk_EXT_FUN_80110000038c6e24(uStack_d8,0x40);
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar14 + 0x100))(plVar14,"address",plVar15);
            (**(code **)(*plVar15 + 0x28))(plVar15);
          }
          thunk_EXT_FUN_80110000037693ec(&DAT_fffffff00ae23950,0x40,"bif%d_fault");
          local_1e0 = plVar14;
          (**(code **)(*plVar14 + 0x20))(plVar14);
          thunk_EXT_FUN_801100000389d40c(plVar29,&DAT_fffffff00ae23950,&local_1e0);
          if (local_1e0 != (long *)0x0) {
            (**(code **)(*local_1e0 + 0x28))();
          }
          (**(code **)(*plVar14 + 0x28))(plVar14);
          iVar9 = 3;
        }
      }
      local_d0 = 0;
      uStack_e8 = 0;
      local_f0 = 0;
      uStack_d8 = 0;
      local_e0 = 0;
      uStack_f8 = 0;
      local_100 = (long **)0x0;
      iVar11 = (**(code **)(*param_1 + 0x7b8))(param_1,1,&local_100,0);
      if (iVar11 != 0) {
        plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24(3,0x20);
        if (plVar14 != (long *)0x0) {
          (**(code **)(*plVar29 + 0x100))(plVar29,"restart_reason",plVar14);
          (**(code **)(*plVar14 + 0x28))(plVar14);
        }
        thunk_EXT_FUN_80110000037693ec(&DAT_fffffff00ae23950,0x40,"BIF%d page fault");
        plVar14 = (long *)thunk_EXT_FUN_80110000038ce200(&DAT_fffffff00ae23950);
        if (plVar14 != (long *)0x0) {
          (**(code **)(*plVar29 + 0x100))(plVar29,"restart_reason_desc",plVar14);
          (**(code **)(*plVar14 + 0x28))(plVar14);
        }
        plVar14 = (long *)thunk_EXT_FUN_801100000389d0d8(5);
        if (plVar14 == (long *)0x0) {
          iVar9 = 3;
        }
        else {
          plVar15 = (long *)thunk_EXT_FUN_80110000038c6e24(local_f0._4_4_,0x20);
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar14 + 0x100))(plVar14,"requestor",plVar15);
            (**(code **)(*plVar15 + 0x28))(plVar15);
          }
          plVar15 = (long *)thunk_EXT_FUN_80110000038c6e24(uStack_e8 & 0xffffffff,0x20);
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar14 + 0x100))(plVar14,"sideband",plVar15);
            (**(code **)(*plVar15 + 0x28))(plVar15);
          }
          plVar15 = (long *)thunk_EXT_FUN_80110000038c6e24(local_e0 & 0xff,0x20);
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar14 + 0x100))(plVar14,"level",plVar15);
            (**(code **)(*plVar15 + 0x28))(plVar15);
          }
          plVar15 = (long *)thunk_EXT_FUN_80110000038970c4(local_e0._1_1_ & 1);
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar14 + 0x100))(plVar14,"is_read",plVar15);
            (**(code **)(*plVar15 + 0x28))(plVar15);
          }
          plVar15 = (long *)thunk_EXT_FUN_80110000038970c4(local_e0._2_1_ & 1);
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar14 + 0x100))(plVar14,"pm_protect",plVar15);
            (**(code **)(*plVar15 + 0x28))(plVar15);
          }
          plVar15 = (long *)thunk_EXT_FUN_80110000038c6e24(uStack_d8,0x40);
          if (plVar15 != (long *)0x0) {
            (**(code **)(*plVar14 + 0x100))(plVar14,"address",plVar15);
            (**(code **)(*plVar15 + 0x28))(plVar15);
          }
          thunk_EXT_FUN_80110000037693ec(&DAT_fffffff00ae23950,0x40,"bif%d_fault");
          local_1e0 = plVar14;
          (**(code **)(*plVar14 + 0x20))(plVar14);
          thunk_EXT_FUN_801100000389d40c(plVar29,&DAT_fffffff00ae23950,&local_1e0);
          if (local_1e0 != (long *)0x0) {
            (**(code **)(*local_1e0 + 0x28))();
          }
          (**(code **)(*plVar14 + 0x28))(plVar14);
          iVar9 = 3;
        }
      }
    }
    plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar10 | iVar9 << 4 | 0x200,0x20);
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar29 + 0x100))(plVar29,"signature",plVar14);
      (**(code **)(*plVar14 + 0x28))(plVar14);
    }
    lVar27 = param_1[0x96];
    pplVar17 = (long **)thunk_EXT_FUN_801100000389d0d8((int)param_1[0x7f]);
    if (pplVar17 != (long **)0x0) {
      if ((int)param_1[0x7f] != 0) {
        uVar28 = 0;
        do {
          thunk_EXT_FUN_80110000037693ec(&DAT_fffffff00ae23948,8,"slot%u");
          plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24
                                      (*(undefined4 *)
                                        (*(long *)(lVar27 + 0x2a8) + 4 + (uVar28 * 0x18 | 4)),0x20);
          if (plVar14 != (long *)0x0) {
            (*(code *)(*pplVar17)[0x20])(pplVar17,&DAT_fffffff00ae23948,plVar14);
            (**(code **)(*plVar14 + 0x28))(plVar14);
          }
          uVar28 = uVar28 + 1;
        } while (uVar28 < *(uint *)(param_1 + 0x7f));
      }
      local_100 = pplVar17;
      (*(code *)(*pplVar17)[4])(pplVar17);
      thunk_EXT_FUN_801100000389d40c(plVar29,"fw_ta_state",&local_100);
      if (local_100 != (long **)0x0) {
        (*(code *)(*local_100)[5])();
      }
      (*(code *)(*pplVar17)[5])(pplVar17);
    }
    pplVar17 = (long **)thunk_EXT_FUN_801100000389d0d8((int)param_1[0x7f]);
    if (pplVar17 != (long **)0x0) {
      if ((int)param_1[0x7f] != 0) {
        uVar28 = 0;
        do {
          thunk_EXT_FUN_80110000037693ec(&DAT_fffffff00ae23948,8,"slot%u");
          plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24
                                      (*(undefined4 *)
                                        (*(long *)(lVar27 + 0x2a8) + uVar28 * 0x18 + 0xc),0x20);
          if (plVar14 != (long *)0x0) {
            (*(code *)(*pplVar17)[0x20])(pplVar17,&DAT_fffffff00ae23948,plVar14);
            (**(code **)(*plVar14 + 0x28))(plVar14);
          }
          uVar28 = uVar28 + 1;
        } while (uVar28 < *(uint *)(param_1 + 0x7f));
      }
      local_100 = pplVar17;
      (*(code *)(*pplVar17)[4])(pplVar17);
      thunk_EXT_FUN_801100000389d40c(plVar29,"fw_ta_substate",&local_100);
      if (local_100 != (long **)0x0) {
        (*(code *)(*local_100)[5])();
      }
      (*(code *)(*pplVar17)[5])(pplVar17);
    }
    pplVar17 = (long **)thunk_EXT_FUN_801100000389d0d8(*(undefined4 *)((long)param_1 + 0x3fc));
    if (pplVar17 != (long **)0x0) {
      if (*(int *)((long)param_1 + 0x3fc) != 0) {
        uVar28 = 0;
        do {
          thunk_EXT_FUN_80110000037693ec(&DAT_fffffff00ae23948,8,"slot%u");
          plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24
                                      (*(undefined4 *)
                                        (*(long *)(lVar27 + 0x2b0) + uVar28 * 0x30 + 0x24),0x20);
          if (plVar14 != (long *)0x0) {
            (*(code *)(*pplVar17)[0x20])(pplVar17,&DAT_fffffff00ae23948,plVar14);
            (**(code **)(*plVar14 + 0x28))(plVar14);
          }
          uVar28 = uVar28 + 1;
        } while (uVar28 < *(uint *)((long)param_1 + 0x3fc));
      }
      local_100 = pplVar17;
      (*(code *)(*pplVar17)[4])(pplVar17);
      thunk_EXT_FUN_801100000389d40c(plVar29,"fw_3d_state",&local_100);
      if (local_100 != (long **)0x0) {
        (*(code *)(*local_100)[5])();
      }
      (*(code *)(*pplVar17)[5])(pplVar17);
    }
    pplVar17 = (long **)thunk_EXT_FUN_801100000389d0d8((int)param_1[0x80]);
    if (pplVar17 != (long **)0x0) {
      if ((int)param_1[0x80] != 0) {
        uVar28 = 0;
        do {
          thunk_EXT_FUN_80110000037693ec(&DAT_fffffff00ae23948,8,"slot%u");
          uVar24 = *(ulong *)(lVar27 + 0x2b8) + uVar28 * 0x20;
          if (((*(ulong *)(lVar27 + 0x2b8) ^ uVar24) & 0xffc0000000000000) != 0) {
            uVar24 = uVar24 & 0xffffffffffff | 0xc8a2000000000000;
          }
          plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(uVar24 + 0xc),0x20);
          if (plVar14 != (long *)0x0) {
            (*(code *)(*pplVar17)[0x20])(pplVar17,&DAT_fffffff00ae23948,plVar14);
            (**(code **)(*plVar14 + 0x28))(plVar14);
          }
          uVar28 = uVar28 + 1;
        } while (uVar28 < *(uint *)(param_1 + 0x80));
      }
      local_100 = pplVar17;
      (*(code *)(*pplVar17)[4])(pplVar17);
      thunk_EXT_FUN_801100000389d40c(plVar29,"fw_cl_state",&local_100);
      if (local_100 != (long **)0x0) {
        (*(code *)(*local_100)[5])();
      }
      (*(code *)(*pplVar17)[5])(pplVar17);
    }
    plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(lVar27 + 0x2c0) + 0xc),0x20);
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar29 + 0x100))(plVar29,"fw_power_state",plVar14);
      (**(code **)(*plVar14 + 0x28))(plVar14);
    }
    plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(lVar27 + 0x2c0) + 0x10),0x20);
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar29 + 0x100))(plVar29,"fw_power_substate",plVar14);
      (**(code **)(*plVar14 + 0x28))(plVar14);
    }
    plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(lVar27 + 0x2c0) + 0x2c),0x20);
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar29 + 0x100))(plVar29,"fw_perf_state_lo",plVar14);
      (**(code **)(*plVar14 + 0x28))(plVar14);
    }
    plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(lVar27 + 0x2c0) + 0x30),0x20);
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar29 + 0x100))(plVar29,"fw_perf_state_hi",plVar14);
      (**(code **)(*plVar14 + 0x28))(plVar14);
    }
    plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(lVar27 + 0x2c0) + 0x34),0x20);
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar29 + 0x100))(plVar29,"fw_perf_state_select",plVar14);
      (**(code **)(*plVar14 + 0x28))(plVar14);
    }
    plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(lVar27 + 0x2c0) + 0x38),0x20);
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar29 + 0x100))(plVar29,"fw_gpc_perf_state",plVar14);
      (**(code **)(*plVar14 + 0x28))(plVar14);
    }
    plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(lVar27 + 0x2c0) + 0x3c),0x20);
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar29 + 0x100))(plVar29,"fw_power_boost_controller",plVar14);
      (**(code **)(*plVar14 + 0x28))(plVar14);
    }
    plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(lVar27 + 0x2c0) + 0x44),0x20);
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar29 + 0x100))(plVar29,"fw_power_limit_controller",plVar14);
      (**(code **)(*plVar14 + 0x28))(plVar14);
    }
    plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24
                                (*(undefined4 *)(*(long *)(lVar27 + 0x2c0) + 0x4c),0x20);
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar29 + 0x100))(plVar29,"fw_power_controller_in_charge",plVar14);
      (**(code **)(*plVar14 + 0x28))(plVar14);
    }
    plVar14 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar31,0x40);
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar29 + 0x100))(plVar29,"command_buffer_trace_id",plVar14);
      (**(code **)(*plVar14 + 0x28))(plVar14);
    }
    uVar31 = (**(code **)(*plVar29 + 0x138))(plVar29,"restart_reason");
    plVar14 = (long *)thunk_EXT_FUN_8011000003890f30(uVar31,*(undefined8 *)PTR_DAT_fffffff007ca60a8)
    ;
    if (plVar14 == (long *)0x0) {
      uVar31 = 0;
    }
    else {
      uVar31 = (**(code **)(*plVar14 + 0xa8))();
    }
    uVar10 = (uint)uVar31;
    bVar8 = uVar10 - 7 < 2;
    uStack_178 = 0;
    local_180 = 0;
    uStack_168 = 0;
    uStack_170 = 0;
    uStack_198 = 0;
    local_1a0 = 0;
    uStack_188 = 0;
    uStack_190 = 0;
    uStack_1b8 = 0;
    local_1c0 = 0;
    uStack_1a8 = 0;
    uStack_1b0 = 0;
    uStack_1d8 = 0;
    local_1e0 = (long *)0x0;
    uStack_1c8 = 0;
    uStack_1d0 = 0;
    uVar18 = (**(code **)(*plVar29 + 0x138))(*plVar29 + 0x138,plVar29,"restart_reason_desc");
    plVar14 = (long *)thunk_EXT_FUN_8011000003890f30(uVar18,*(undefined8 *)PTR_DAT_fffffff007ca60b8)
    ;
    if (plVar14 != (long *)0x0) {
      (**(code **)(*plVar14 + 0xa8))();
    }
    local_100 = &local_1e0;
    local_220 = (undefined *)0x80;
    FUN_fffffff008214c38(&local_100,&local_220,"%s");
    FUN_fffffff008214c38(&local_100,&local_220,"%s");
    local_260 = plVar29;
    if ((uVar10 < 0xc) && ((1 << (ulong)(uVar10 & 0x1f) & 0xa10U) != 0)) {
      FUN_fffffff008214c38(&local_100,&local_220," (pid=%u)");
    }
  }
  local_228 = 0;
  (**(code **)(*(long *)param_1[0x96] + 0x658))((long *)param_1[0x96],&local_228);
  local_230 = 0;
  thunk_EXT_FUN_8011000003398268((ulong)*(uint *)((long)param_1 + 0x23c) * 1000000000,&local_230);
  if ((char)param_1[0x313d] == '\x03') {
    if (*(byte *)(param_1 + 0x316d) < 0x40) {
      (**(code **)(*(long *)param_1[0x96] + 0x278))();
    }
    else {
      (**(code **)(*param_1 + 0x798))(param_1);
    }
    (**(code **)(*(long *)param_1[0x96] + 0x638))((long *)param_1[0x96],param_1 + 0x313c);
    if (*plVar1 != 0) {
      FUN_fffffff0081fa674(*plVar1,param_1);
      (**(code **)(*(long *)*plVar1 + 0x28))();
      *plVar1 = 0;
    }
    thunk_EXT_FUN_8011000003a1145c((long)param_1 + 0x189e9);
  }
  plVar14 = (long *)param_1[0x96];
  lVar27 = plVar14[0x122];
  (**(code **)(*plVar14 + 0x148))(plVar14,lVar27 + 0x4298);
  if (uVar2 == 0) {
    local_140 = 0;
    uStack_158 = 0;
    local_160 = 0;
    uStack_148 = 0;
    uStack_150 = 0;
    thunk_EXT_FUN_801100000295ede0(param_1[0x2c],5);
    if ((*(byte *)(param_1 + 0x316d) & 0xc) == 4) {
      lVar27 = thunk_EXT_FUN_8011000002959a74(plVar30);
      if (lVar27 == 0) goto LAB_fffffff00816db6c;
      lVar13 = *(long *)(lVar27 + 0x60);
      if (lVar13 != 0) {
        local_160 = local_160 & 0xffffffffffffff00;
        if (0 < *(int *)(lVar13 + 0x490)) {
          thunk_EXT_FUN_8011000003722d80(*(int *)(lVar13 + 0x490),&local_160,0x24);
          local_140 = local_140 & 0xffffff;
        }
        uVar22 = 2;
        if (2 < *(int *)(param_1[0x2c] + 0xe8) - 2U) {
          uVar22 = 3;
        }
        thunk_EXT_FUN_801100000295ed08(param_1[0x2c],lVar13,uVar22);
      }
    }
    else {
      lVar27 = 0;
LAB_fffffff00816db6c:
      lVar13 = 0;
    }
    local_1f0 = 0;
    uStack_1e8 = 0;
    thunk_EXT_FUN_801100000295c2dc(&local_1f0,param_1[0x2c]);
    uVar18 = DAT_fffffff007113e50;
    while (lVar19 = thunk_EXT_FUN_801100000295c384(&local_1f0), lVar19 != 0) {
      uStack_98 = 0;
      local_a0 = 0;
      uStack_88 = 0;
      uStack_90 = 0;
      uStack_b8 = 0;
      local_c0 = 0;
      uStack_a8 = 0;
      uStack_b0 = 0;
      uStack_d8 = 0;
      local_e0 = 0;
      uStack_c8 = 0;
      local_d0 = 0;
      uStack_f8 = 0;
      local_100 = (long **)0x0;
      uStack_e8 = 0;
      local_f0 = 0;
      local_110 = 0;
      uStack_128 = 0;
      local_130 = 0;
      uStack_118 = 0;
      uStack_120 = 0;
      lVar20 = thunk_EXT_FUN_8011000003890f30(lVar19,&DAT_fffffff00ae25b38);
      if (lVar20 == 0) {
        lVar20 = thunk_EXT_FUN_8011000003890f30(lVar19,&DAT_fffffff00ae25b60);
        if ((lVar20 != 0) && (*(long *)(lVar20 + 0x218) != 0)) {
          pcVar32 = "CL: stamp_idx=%d ";
          goto LAB_fffffff00816dc8c;
        }
      }
      else {
        if (*(long *)(lVar20 + 0x218) != 0) {
          thunk_EXT_FUN_80110000037693ec(&local_100,0x80,"TA: stamp_idx=%d ");
        }
        if (*(long *)(lVar20 + 0x220) != 0) {
          pcVar32 = "3D: stamp_idx=%d ";
LAB_fffffff00816dc8c:
          thunk_EXT_FUN_80110000037693ec(&local_100,0x80,pcVar32);
        }
      }
      lVar20 = thunk_EXT_FUN_8011000002959a74(lVar19);
      if (lVar20 != 0) {
        lVar20 = *(long *)(lVar20 + 0x60);
        if ((lVar20 != 0) && (lVar20 != lVar13)) {
          local_130 = local_130 & 0xffffffffffffff00;
          if (0 < *(int *)(lVar20 + 0x490)) {
            thunk_EXT_FUN_8011000003722d80(*(int *)(lVar20 + 0x490),&local_130,0x24);
          }
        }
        local_220 = PTR_DAT_fffffff007ca5f90;
        local_218 = uVar18;
        local_210 = FUN_fffffff00816e7d0;
        local_1f8 = (undefined4)uVar31;
        local_208 = &DAT_fffffff007c92f08;
        lStack_200 = lVar27;
        thunk_EXT_FUN_8011000002959c70(lVar19,&local_220);
      }
    }
    thunk_EXT_FUN_801100000295c350(&local_1f0);
  }
  else {
    lVar13 = (**(code **)(*(long *)param_1[0x96] + 0x140))
                       ((long *)param_1[0x96],lVar27 + 0x4298,uVar31);
  }
  if ((*(byte *)(param_1 + 0x316d) >> 3 & 1) == 0) {
    if (*plVar1 != 0) {
      if (plVar29 == (long *)0x0) {
LAB_fffffff00816dd94:
        pcVar32 = "unknown lockup";
        if (lVar13 == 0) goto LAB_fffffff00816dd70;
LAB_fffffff00816dda0:
        local_e0 = local_e0 & 0xffffffff00000000;
        uStack_f8 = 0;
        local_100 = (long **)0x0;
        uStack_e8 = 0;
        local_f0 = 0;
        if (0 < *(int *)(lVar13 + 0x490)) {
          thunk_EXT_FUN_8011000003722d80(*(int *)(lVar13 + 0x490),&local_100,0x24);
          local_e0._0_4_ = (uint)(uint3)local_e0;
        }
        lVar27 = *plVar1;
        if ((*(byte *)(lVar27 + 0x10) & 1) == 0) {
          if (pcVar32 == (char *)0x0) {
            *(undefined1 *)(lVar27 + 0x11) = 0;
          }
          else {
            thunk_EXT_FUN_8011000003350958(lVar27 + 0x11,pcVar32,0x40);
          }
          pcVar32 = (char *)&local_100;
          goto LAB_fffffff00816de0c;
        }
      }
      else {
        uVar31 = (**(code **)(*local_260 + 0x138))(local_260,"restart_reason_desc");
        plVar14 = (long *)thunk_EXT_FUN_8011000003890f30
                                    (uVar31,*(undefined8 *)PTR_DAT_fffffff007ca60b8);
        if (plVar14 == (long *)0x0) goto LAB_fffffff00816dd94;
        pcVar32 = (char *)(**(code **)(*plVar14 + 0xa8))();
        if (lVar13 != 0) goto LAB_fffffff00816dda0;
LAB_fffffff00816dd70:
        lVar27 = *plVar1;
        if ((*(byte *)(lVar27 + 0x10) & 1) == 0) {
          if (pcVar32 == (char *)0x0) {
            *(undefined1 *)(lVar27 + 0x11) = 0;
          }
          else {
            thunk_EXT_FUN_8011000003350958(lVar27 + 0x11,pcVar32,0x40);
          }
          pcVar32 = "<unknown>";
LAB_fffffff00816de0c:
          thunk_EXT_FUN_8011000003350958(lVar27 + 0x51,pcVar32,0x40);
        }
      }
      lVar27 = *plVar1;
      if ((*(byte *)(lVar27 + 0x10) & 1) == 0) {
        if (plVar29 != (long *)0x0) {
          (**(code **)(*local_260 + 0x20))();
        }
        if (*(long **)(lVar27 + 0xc0) != (long *)0x0) {
          (**(code **)(**(long **)(lVar27 + 0xc0) + 0x28))();
        }
        *(long **)(lVar27 + 0xc0) = local_260;
      }
    }
    thunk_EXT_FUN_80110000032222a8(param_1[0x23c9]);
    thunk_EXT_FUN_8011000003222de0(param_1[0x23c9]);
    (**(code **)(*(long *)param_1[0x96] + 0x110))(*(long *)param_1[0x96] + 0x110);
    if ((!bVar8) && (0x3f < *(byte *)(param_1 + 0x316d))) {
      (**(code **)(*param_1 + 0x798))(param_1);
      lVar27 = *(long *)param_1[0x96];
      (**(code **)(lVar27 + 0x638))(lVar27 + 0x638,(long *)param_1[0x96],param_1 + 0x313c);
    }
  }
  param_1[0xb0] = param_1[0xb0] + 1;
  lVar27 = thunk_EXT_FUN_8011000003397c88();
  param_1[0xb2] = lVar27;
  thunk_EXT_FUN_80110000039b5664(*(undefined8 *)(param_1[0x2a] + 0x28),3,1);
  uVar31 = thunk_EXT_FUN_8011000003397c88();
  thunk_EXT_FUN_80110000039b5574(*(undefined8 *)(param_1[0x2a] + 0x28),5,uVar31);
  if (uVar2 == 0) {
    (**(code **)(*(long *)param_1[0x96] + 0x380))();
    thunk_EXT_FUN_80110000029492d0(param_1[0x29]);
    thunk_EXT_FUN_80110000032222a8(param_1[0x23bf]);
    thunk_EXT_FUN_801100000294063c(*(undefined8 *)(param_1[0x23be] + 0x1d0));
    lVar27 = *(long *)(param_1[0x23be] + 0x1d0);
    if (1 < *(uint *)(lVar27 + 0x28)) {
      uVar10 = 1;
      do {
        plVar14 = (long *)thunk_EXT_FUN_8011000002940888(lVar27,uVar10);
        if (plVar14 != (long *)0x0) {
          (**(code **)(*plVar14 + 0x20))();
          (**(code **)(*plVar14 + 0x28))(plVar14);
          uVar6 = *(uint *)(plVar14 + 0x3d);
          uVar28 = (ulong)uVar6;
          if (0 < (int)uVar6) {
            lVar27 = uVar28 * 4;
            piVar23 = (int *)(param_1[0x23c5] + (long)(int)lVar27);
            if (lVar27 - (int)lVar27 != 0) {
              piVar23 = (int *)(param_1[0x23c5] + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
            }
            if (*piVar23 == 0) {
              thunk_EXT_FUN_8011000003223a00(plVar14[0x3a]);
              iVar9 = (int)param_1[0x23c0];
              iVar11 = 1 << (ulong)(-(int)LZCOUNT(iVar9 + -1) & 0x1f);
              iVar25 = (int)LZCOUNT(iVar11 + -1);
              uVar26 = (ulong)(iVar25 + 0x20);
              uVar24 = 0xffffffffffffffff;
              if (iVar25 != 0x20) {
                uVar24 = ~(-1L << (uVar26 & 0x3f));
              }
              uVar3 = 0;
              if (1 < iVar11) {
                uVar3 = uVar26;
              }
              uVar26 = 0xffffffffffffffff;
              if (1 < iVar11) {
                uVar26 = uVar24;
              }
              uVar24 = 0;
              if (1 < iVar9) {
                uVar24 = uVar3;
              }
              uVar3 = 0xffffffffffffffff;
              if (1 < iVar9) {
                uVar3 = uVar26;
              }
              lVar27 = uVar28 * 8;
              iVar9 = (int)lVar27;
              puVar4 = (ulong *)(param_1[0x23c3] + (long)iVar9);
              if (lVar27 - iVar9 != 0) {
                puVar4 = (ulong *)(param_1[0x23c3] + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
              }
              *puVar4 = (*puVar4 & uVar3) + 1 & uVar3 | uVar28 << (uVar24 & 0x3f);
              puVar12 = (undefined8 *)(param_1[0x23c4] + (long)iVar9);
              if (lVar27 - iVar9 != 0) {
                puVar12 = (undefined8 *)
                          (param_1[0x23c4] + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
              }
              *puVar12 = 0;
              (**(code **)(*plVar14 + 0x128))(*plVar14 + 0x128,plVar14,0xffffffff);
              lVar27 = (long)(int)param_1[0x23c7] + 1;
              *(int *)(param_1 + 0x23c7) = (int)lVar27;
              lVar27 = lVar27 * 4;
              puVar5 = (uint *)(param_1[0x23c6] + (long)(int)lVar27);
              if (lVar27 - (int)lVar27 != 0) {
                puVar5 = (uint *)(param_1[0x23c6] + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
              }
              *puVar5 = uVar6;
              thunk_EXT_FUN_8011000003224d30(plVar14[0x3a]);
            }
          }
          (**(code **)(*plVar14 + 0x28))(plVar14);
        }
        uVar10 = uVar10 + 1;
        lVar27 = *(long *)(param_1[0x23be] + 0x1d0);
      } while (uVar10 < *(uint *)(lVar27 + 0x28));
    }
    thunk_EXT_FUN_8011000002940648();
    thunk_EXT_FUN_8011000003222de0(param_1[0x23bf]);
    thunk_EXT_FUN_80110000032222a8(param_1[0x23c9]);
    lVar27 = param_1[0x23db];
    if (lVar27 != 0) {
      do {
        FUN_fffffff0081e1178(lVar27);
        lVar27 = *(long *)(lVar27 + 0x38);
      } while (lVar27 != 0);
      plVar14 = (long *)param_1[0x23db];
joined_r0xfffffff00816e1f4:
      plVar15 = plVar14;
      if (plVar14 != (long *)0x0) {
        do {
          plVar14 = (long *)plVar15[7];
          if (plVar14 == (long *)0x0) {
            plVar16 = (long *)plVar15[8];
            if ((long *)*plVar16 != plVar15) goto LAB_fffffff00816e7bc;
            param_1[0x23dc] = (long)plVar16;
          }
          else {
            if ((long *)plVar14[8] != plVar15 + 7) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00816e7cc);
              (*pcVar7)();
            }
            if (*(long **)plVar15[8] != plVar15) {
LAB_fffffff00816e7bc:
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00816e7c4);
              (*pcVar7)();
            }
            plVar14[8] = (long)plVar15[8];
            plVar16 = (long *)plVar15[8];
          }
          *plVar16 = (long)plVar14;
          *(undefined1 *)((long)plVar15 + 0xc) = 0;
          uVar10 = *(uint *)(param_1 + 0x23da);
          if (uVar10 < 0x10) goto code_r0xfffffff00816e284;
          (**(code **)(*plVar15 + 0x28))();
          plVar15 = plVar14;
          if (plVar14 == (long *)0x0) break;
        } while( true );
      }
    }
    thunk_EXT_FUN_8011000003222de0(param_1[0x23c9]);
    thunk_EXT_FUN_80110000032222a8(param_1[100]);
    for (plVar14 = (long *)param_1[0x65]; plVar14 != (long *)0x0; plVar14 = (long *)plVar14[0x3f]) {
      (**(code **)(*plVar14 + 0xc0))(plVar14);
    }
    thunk_EXT_FUN_8011000003222de0(param_1[100]);
    thunk_EXT_FUN_80110000032222a8(param_1[0x67]);
    for (lVar27 = param_1[0x68]; lVar27 != 0; lVar27 = *(long *)(lVar27 + 0x10)) {
      puVar12 = *(undefined8 **)(lVar27 + 5000);
      puVar12[4] = 0;
      puVar12[1] = 0;
      *puVar12 = 0;
      puVar12[3] = 0;
      puVar12[2] = 0;
      puVar12 = *(undefined8 **)(lVar27 + 5000);
      puVar12[2] = 0;
      *puVar12 = *(undefined8 *)(lVar27 + 0x1368);
    }
    thunk_EXT_FUN_8011000003222de0(param_1[0x67]);
    local_100 = (long **)0x0;
    uStack_f8 = 0;
    thunk_EXT_FUN_801100000295c2dc(&local_100,param_1[0x2c]);
    while (plVar14 = (long *)thunk_EXT_FUN_801100000295c384(&local_100), plVar14 != (long *)0x0) {
      (**(code **)(*plVar14 + 0xe0))();
    }
    thunk_EXT_FUN_801100000295c350(&local_100);
    (**(code **)(*(long *)param_1[0x96] + 0xa8))();
    param_1[0xb1] = param_1[0xb1] + 1;
  }
  (**(code **)(*(long *)param_1[0x2236] + 0xd0))();
  DataMemoryBarrier(2,3);
  (**(code **)(*(long *)param_1[0x96] + 0x388))(*(long *)param_1[0x96] + 0x388);
  thunk_EXT_FUN_801100000294cf74(param_1[0x2b]);
  uVar28 = (**(code **)(*(long *)param_1[0x96] + 0x3a8))(*(long *)param_1[0x96] + 0x3a8);
  if ((uVar28 & 1) == 0) {
    do {
      thunk_EXT_FUN_80110000038fe988(1);
      iVar9 = (**(code **)(*(long *)param_1[0x96] + 0x3a8))();
    } while (iVar9 == 0);
  }
  DataMemoryBarrier(2,3);
  if ((uVar2 == 0) && (*(int *)((long)param_1 + 0x10934) != 0)) {
    uVar10 = *(uint *)(param_1[0x23e7] + 0x10930);
    uVar28 = (ulong)(int)uVar10;
    uVar2 = uVar10 + *(int *)(param_1[0x23e7] + 0x10934);
    thunk_EXT_FUN_80110000032222a8(param_1[0x23e6]);
    while (uVar10 < uVar2) {
      uVar24 = (ulong)((uint)uVar28 >> 6);
      uVar26 = 1L << (uVar28 & 0x3f);
      if (((param_1[uVar24 + 0x2fee] & uVar26) == 0) && ((param_1[uVar24 + 0x2ff2] & uVar26) == 0))
      {
        iVar9 = (int)(uVar28 * 0x60);
        uVar24 = (long)param_1 + (long)iVar9 + 0x11f70;
        if (uVar28 * 0x60 - (long)iVar9 != 0) {
          uVar24 = (ulong)(param_1 + uVar28 * 0xc + 0x23ee) & 0xffffffffffff | 0x2bad000000000000;
        }
        if ((ulong)*(ushort *)(uVar24 + 0x58) < 0x100 &&
            *(int *)(*(long *)(*(long *)(uVar24 + 0x50) + 0x48) + 0x10934) != 0) {
          *(undefined2 *)
           (*(long *)(*(long *)(uVar24 + 0x50) + 0x178) + (ulong)*(ushort *)(uVar24 + 0x58) * 2) = 0
          ;
        }
        iVar9 = (int)param_1[0x2ff6] + 0x100;
        *(int *)(param_1 + 0x2ff6) = iVar9;
        *(int *)(uVar24 + 0x48) = iVar9;
        plVar14 = (long *)param_1[0x23e7];
        lVar27 = uVar28 * 4;
        piVar23 = (int *)(plVar14[0x92] + (long)(int)lVar27);
        if (lVar27 - (int)lVar27 != 0) {
          piVar23 = (int *)(plVar14[0x92] + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *piVar23 = iVar9;
        (**(code **)(*plVar14 + 0xbf0))(*plVar14 + 0xbf0,plVar14,(uint)uVar28 & 0xff);
        lVar27 = param_1[0x23e7];
        if ((*(byte *)(lVar27 + 0x1ac44) >> 3 & 1) != 0) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar27 + 0x1ac48));
          thunk_EXT_FUN_80110000036da494(0x85930c98,uVar28,0,1,0,0);
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar27 + 0x1ac48));
        }
        uVar24 = uVar28 >> 3 & 0x18;
        *(ulong *)((long)param_1 + uVar24 + 0x17f90) =
             *(ulong *)((long)param_1 + uVar24 + 0x17f90) | uVar26;
        *(undefined4 *)(param_1 + ((uVar28 & 0xff) + (uVar28 & 0xff) * 2) * 4 + 0x23ee) = 0;
        (param_1 + ((uVar28 & 0xff) + (uVar28 & 0xff) * 2) * 4 + 0x23ee)[10] = 0;
      }
      uVar28 = uVar28 + 1;
      uVar10 = (uint)uVar28;
    }
    uVar31 = (**(code **)(**(long **)(param_1[0x23e8] + 0x60) + 0x78))();
    thunk_EXT_FUN_8011000003a61cc0(uVar31,param_1[0x23e9]);
    thunk_EXT_FUN_8011000003222de0(param_1[0x23e6]);
  }
  (**(code **)(*(long *)param_1[0x96] + 0x390))();
  bVar21 = *(byte *)(param_1 + 0x316d);
  if (((bVar21 >> 3 & 1) == 0) && (*plVar1 != 0)) {
    FUN_fffffff0081fa674(*plVar1,param_1);
    (**(code **)(*(long *)*plVar1 + 0x28))();
    *plVar1 = 0;
    bVar21 = *(byte *)(param_1 + 0x316d);
  }
  *(byte *)(param_1 + 0x316d) = bVar21 & 0xf7;
  *(undefined2 *)(param_1 + 0x313d) = 0;
  param_1[0x313c] = DAT_fffffff007113e58;
  param_1[0x3158] = 0;
  *(undefined4 *)(param_1 + 0x3159) = 0;
  param_1[0x315b] = 0;
  param_1[0x315a] = 0;
  param_1[0x315d] = 0;
  param_1[0x315c] = 0;
  param_1[0x315f] = 0;
  param_1[0x315e] = 0;
  param_1[0x3161] = 0;
  param_1[0x3160] = 0;
  param_1[0x3163] = 0;
  param_1[0x3162] = 0;
  param_1[0x3165] = 0;
  param_1[0x3164] = 0;
  param_1[0x3167] = 0;
  param_1[0x3166] = 0;
  param_1[0x3169] = 0;
  param_1[0x3168] = 0;
  param_1[0x316b] = 0;
  param_1[0x316a] = 0;
  param_1[0x316c] = 0;
  if (plVar29 != (long *)0x0) {
    (**(code **)(*local_260 + 0x28))();
  }
  (**(code **)(*plVar30 + 0x28))(plVar30);
LAB_fffffff00816e780:
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_80) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
code_r0xfffffff00816e284:
  *(uint *)(param_1 + 0x23da) = uVar10 + 1;
  lVar27 = (ulong)uVar10 * 8;
  iVar9 = (int)lVar27;
  plVar16 = (long *)((long)param_1 + (long)iVar9 + 0x11e50);
  if (lVar27 - iVar9 != 0) {
    plVar16 = (long *)((ulong)(param_1 + (ulong)uVar10 + 0x23ca) & 0xffffffffffff |
                      0x2bad000000000000);
  }
  *plVar16 = (long)plVar15;
  goto joined_r0xfffffff00816e1f4;
}

