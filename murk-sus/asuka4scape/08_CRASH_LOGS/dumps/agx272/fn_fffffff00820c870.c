// FUN_fffffff00820c870 @ fffffff00820c870 size=4

undefined8 FUN_fffffff00820c870(long *param_1,undefined8 param_2)

{
  long *plVar1;
  int *piVar2;
  uint *puVar3;
  int *piVar4;
  undefined8 *puVar5;
  byte bVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  long lVar10;
  undefined8 uVar11;
  code *pcVar12;
  long lVar13;
  ulong uVar14;
  long lVar15;
  long lVar16;
  undefined4 uVar17;
  long *plVar18;
  long *plVar19;
  ulong uVar20;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined4 uStack_44;
  
  *(undefined1 *)(param_1 + 0x47) = 0;
  lVar10 = thunk_EXT_FUN_8011000003890f30(param_1[0xc],&DAT_fffffff00ae21f50);
  if (*(int *)(*(long *)(*(long *)(lVar10 + 0x610) + 200) + 0x28) != 0) {
LAB_fffffff00820c8bc:
    (**(code **)(*param_1 + 0x88))(param_1);
    (**(code **)(*param_1 + 0x98))(param_1);
    return 0xe00002bd;
  }
  uStack_44 = 0;
  uStack_68 = 0;
  uStack_70 = 0;
  uStack_58 = 0;
  uStack_60 = 0;
  uStack_88 = 0;
  uStack_90 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  thunk_EXT_FUN_8011000002946f14(&uStack_90);
  thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(param_1[2] + 0x148),param_1 + 0x175,&uStack_90);
  uVar11 = FUN_fffffff008166c40(param_1,param_2);
  if ((int)uVar11 != 0) {
    pcVar12 = *(code **)(*param_1 + 0x98);
LAB_fffffff00820c960:
    (*pcVar12)(param_1);
    return uVar11;
  }
  lVar10 = (**(code **)(*(long *)param_1[0xb] + 0x158))((long *)param_1[0xb],param_1[0x3d]);
  if (lVar10 == 0) goto LAB_fffffff00820d23c;
  iVar8 = FUN_fffffff00819cb78(param_1[2] + 0x11df0,lVar10,(int)param_1[400],param_1 + 0x20b);
  *(int *)((long)param_1 + 0x1054) = iVar8;
  if (iVar8 == -1) goto LAB_fffffff00820d23c;
  if (param_1[0x2c] != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1[0x2c] + 0x50));
    if (((int *)param_1[0x3a] != (int *)0x0) && (*(int *)param_1[0x3a] != 0)) {
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1[0x2c] + 0x50));
      goto LAB_fffffff00820c8bc;
    }
    uVar11 = FUN_fffffff0081e6698(param_1[0x2c],param_1);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1[0x2c] + 0x50));
    if ((int)uVar11 != 0) {
      pcVar12 = *(code **)(*param_1 + 0x98);
      goto LAB_fffffff00820c960;
    }
  }
  if (param_1[0x17d] == 0) {
LAB_fffffff00820cf70:
    if ((*(byte *)((long)param_1 + 0xb8c) & 1) == 0) {
      uVar17 = (undefined4)param_1[400];
    }
    else {
      uVar17 = 0xffffffff;
    }
    uVar11 = thunk_EXT_FUN_801100000296a26c(param_1);
    thunk_EXT_FUN_8011000002947250(uVar11,0,&uStack_90,(long)param_1 + 0xad4,uVar17);
    uVar9 = *(uint *)((long)param_1 + 0xad4);
    uVar20 = (ulong)uVar9;
    *(uint *)(param_1 + 0x196) = uVar9;
    if (uVar9 != 0) {
      uVar14 = 0;
      do {
        if (param_1[uVar14 + 0x197] == 0) {
          plVar18 = param_1 + 0x1a6 + uVar14;
          if ((((ulong)(param_1 + 0x1a6) ^ (ulong)plVar18) & 0xffc0000000000000) != 0) {
            plVar18 = (long *)((ulong)plVar18 & 0xffffffffffff | 0xc8a2000000000000);
          }
          lVar10 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x1e8))
                             (*(long **)(param_1[2] + 0x4b0),plVar18);
          param_1[uVar14 + 0x197] = lVar10;
          if (lVar10 == 0) goto LAB_fffffff00820d210;
          uVar20 = (ulong)*(uint *)(param_1 + 0x196);
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < uVar20);
    }
    cVar7 = *(char *)((long)param_1 + 0x1044);
    if (cVar7 == '\x03') {
LAB_fffffff00820d040:
      if (param_1[0x1b9] != 0) goto LAB_fffffff00820d0c4;
      lVar10 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x1f8))
                         (*(long **)(param_1[2] + 0x4b0),param_1 + 0x1ba);
      param_1[0x1b9] = lVar10;
      if (lVar10 != 0) goto LAB_fffffff00820d0c4;
    }
    else {
      if (cVar7 == '\x02') {
        if (param_1[0x1bb] == 0) {
          lVar10 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x1f0))
                             (*(long **)(param_1[2] + 0x4b0),param_1 + 0x1bc);
          param_1[0x1bb] = lVar10;
          if (lVar10 == 0) goto LAB_fffffff00820d210;
        }
      }
      else if (cVar7 == '\x01') goto LAB_fffffff00820d040;
LAB_fffffff00820d0c4:
      if (param_1[0x1bd] != 0) {
LAB_fffffff00820d108:
        lVar10 = param_1[0x17d];
        if ((*(byte *)(lVar10 + 0x28) | 2) == 3) {
          thunk_EXT_FUN_80110000029486ac
                    (*(undefined8 *)(*(long *)(lVar10 + 0x10) + 0x148),param_1 + 0x188,
                     *(long *)(*(long *)(*(long *)(lVar10 + 0x20) + 0x20) + 0x18) + 0x40);
        }
        thunk_EXT_FUN_80110000029486ac
                  (*(undefined8 *)(*(long *)(lVar10 + 0x10) + 0x148),param_1 + 0x10,
                   *(undefined8 *)(*(long *)(*(long *)(lVar10 + 0x20) + 0x20) + 0x18));
        lVar10 = param_1[0x17e];
        iVar8 = *(int *)(lVar10 + 0x30);
        if (iVar8 == 0) {
          plVar18 = *(long **)(param_1[0x17d] + 0x10);
          lVar16 = *(long *)(param_1[0x17d] + 0x20);
          lVar13 = *(long *)(lVar16 + 0x48);
          *(int *)(lVar13 + 8) = (int)param_1[0x202];
          (**(code **)(*plVar18 + 0xcb8))(plVar18,lVar13,lVar16 + 0x34);
          iVar8 = *(int *)(lVar10 + 0x30);
        }
        *(int *)(lVar10 + 0x30) = iVar8 + 1;
        *(undefined1 *)((long)param_1 + 0xcac) = 1;
        (**(code **)(*(long *)param_1[0x17d] + 0x98))((long *)param_1[0x17d],&uStack_44);
        lVar10 = param_1[0x17d];
        *(undefined1 *)(lVar10 + 0x28) = 0;
        *(undefined4 *)(lVar10 + 0x130) = *(undefined4 *)(lVar10 + 0x138);
        *(undefined4 *)(lVar10 + 0x134) = 0;
        uVar11 = thunk_EXT_FUN_8011000003397c88();
        *(undefined8 *)(lVar10 + 0x168) = uVar11;
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1[0x17d] + 0x120));
        *(undefined1 *)(param_1 + 0x47) = 1;
        return 0;
      }
      lVar10 = (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x1c8))
                         (*(long **)(param_1[2] + 0x4b0),param_1 + 0x1be,param_1 + 0x1bf);
      param_1[0x1bd] = lVar10;
      if (lVar10 != 0) goto LAB_fffffff00820d108;
    }
LAB_fffffff00820d210:
    plVar18 = (long *)param_1[0x17d];
  }
  else {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1[0x17d] + 0x120));
    plVar18 = (long *)param_1[0x17d];
    (**(code **)(*plVar18 + 0xa8))
              (plVar18,param_1[0x173],(int)param_1[0x174],*(undefined4 *)((long)param_1 + 0xba4),
               (int)param_1[0x172],param_1);
    if (((char)plVar18[5] == '\x01') && (*(int *)((long)plVar18 + 0x5c) != 0)) {
      plVar19 = (long *)plVar18[4];
      if (plVar19 == (long *)0x0) {
        lVar10 = 0;
      }
      else {
        (**(code **)(*plVar19 + 0x20))(plVar19);
        lVar10 = plVar18[4];
      }
      lVar13 = plVar18[2];
      uVar11 = *(undefined8 *)(lVar13 + 0x11db0);
      thunk_EXT_FUN_80110000038ff214(uVar11);
      iVar8 = *(int *)(lVar10 + 0x10);
      if (iVar8 != -1) {
        lVar16 = (long)iVar8 * 8;
        plVar1 = (long *)(*(long *)(lVar13 + 0x11dc0) + (long)(int)lVar16);
        if (lVar16 - (int)lVar16 != 0) {
          plVar1 = (long *)(*(long *)(lVar13 + 0x11dc0) + lVar16 & 0xffffffffffffU |
                           0x2bad000000000000);
        }
        if (*plVar1 == lVar10) {
          lVar16 = (long)iVar8 * 4;
          piVar2 = (int *)(*(long *)(lVar13 + 0x11dc8) + (long)(int)lVar16);
          if (lVar16 - (int)lVar16 != 0) {
            piVar2 = (int *)(*(long *)(lVar13 + 0x11dc8) + lVar16 & 0xffffffffffffU |
                            0x2bad000000000000);
          }
          if (*piVar2 == 0) {
            *plVar1 = 0;
            lVar16 = (long)*(int *)(lVar13 + 0x11de0) + 1;
            *(int *)(lVar13 + 0x11de0) = (int)lVar16;
            lVar16 = lVar16 * 4;
            piVar2 = (int *)(*(long *)(lVar13 + 0x11dd8) + (long)(int)lVar16);
            if (lVar16 - (int)lVar16 != 0) {
              piVar2 = (int *)(*(long *)(lVar13 + 0x11dd8) + lVar16 & 0xffffffffffffU |
                              0x2bad000000000000);
            }
            *piVar2 = iVar8;
          }
        }
      }
      *(undefined4 *)(lVar10 + 0x10) = 0xffffffff;
      thunk_EXT_FUN_80110000038ff2e0(uVar11);
      uVar9 = FUN_fffffff0081ec04c(plVar18);
      if (uVar9 == 0) {
        if (plVar19 != (long *)0x0) goto LAB_fffffff00820cb78;
      }
      else {
        thunk_EXT_FUN_801100000294849c
                  (*(undefined8 *)(plVar18[2] + 0x148),*(undefined8 *)(plVar19[4] + 0x18),
                   *(undefined8 *)(*(long *)(plVar18[4] + 0x20) + 0x18));
        thunk_EXT_FUN_801100000294849c
                  (*(undefined8 *)(plVar18[2] + 0x148),*(long *)(plVar19[4] + 0x18) + 0x40,
                   *(long *)(*(long *)(plVar18[4] + 0x20) + 0x18) + 0x40);
LAB_fffffff00820cb78:
        (**(code **)(*plVar19 + 0x28))(plVar19);
        if ((uVar9 & 1) != 0) goto LAB_fffffff00820cb9c;
      }
      uVar11 = 0xe00002be;
      plVar18 = (long *)param_1[0x17d];
LAB_fffffff00820ce70:
      (**(code **)(*plVar18 + 0xa0))();
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1[0x17d] + 0x120));
      (**(code **)(*param_1 + 0x98))(param_1);
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,
                 "Failed to check usage and prepare PM resources\n");
      return uVar11;
    }
LAB_fffffff00820cb9c:
    uVar11 = (**(code **)(*plVar18 + 0x108))(plVar18,param_1,&uStack_44);
    plVar18 = (long *)param_1[0x17d];
    if ((int)uVar11 != 0) goto LAB_fffffff00820ce70;
    plVar18 = (long *)plVar18[4];
    if (plVar18 != (long *)0x0) {
      (**(code **)(*plVar18 + 0x20))(plVar18);
    }
    if ((long *)param_1[0x17e] != (long *)0x0) {
      (**(code **)(*(long *)param_1[0x17e] + 0x28))();
    }
    param_1[0x17e] = (long)plVar18;
    lVar10 = param_1[2];
    uVar11 = *(undefined8 *)(lVar10 + 0x11db0);
    thunk_EXT_FUN_80110000038ff214(uVar11);
    uVar9 = *(uint *)(plVar18 + 2);
    uVar20 = (ulong)uVar9;
    if (uVar9 == 0xffffffff) {
LAB_fffffff00820cc74:
      uVar9 = *(uint *)(lVar10 + 0x11de0);
      if ((int)uVar9 < 0) {
        uVar20 = 0;
        do {
          uVar14 = *(ulong *)(*(long *)(lVar10 + 0x11dd0) + uVar20 * 8);
          if (uVar14 != 0) {
            uVar14 = (uVar14 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar14 & 0x5555555555555555) << 1;
            uVar14 = (uVar14 & 0xcccccccccccccccc) >> 2 | (uVar14 & 0x3333333333333333) << 2;
            uVar14 = (uVar14 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar14 & 0xf0f0f0f0f0f0f0f) << 4;
            uVar14 = (uVar14 & 0xff00ff00ff00ff00) >> 8 | (uVar14 & 0xff00ff00ff00ff) << 8;
            uVar14 = (uVar14 & 0xffff0000ffff0000) >> 0x10 | (uVar14 & 0xffff0000ffff) << 0x10;
            uVar9 = (uint)LZCOUNT(uVar14 >> 0x20 | uVar14 << 0x20) | (int)uVar20 << 6;
            goto joined_r0xfffffff00820d308;
          }
          uVar20 = uVar20 + 1;
        } while ((*(int *)(lVar10 + 0x11db8) - 1U >> 6) + 1 != uVar20);
      }
      else {
        *(uint *)(lVar10 + 0x11de0) = uVar9 - 1;
        lVar13 = (ulong)uVar9 * 4;
        puVar3 = (uint *)(*(long *)(lVar10 + 0x11dd8) + (long)(int)lVar13);
        if (lVar13 - (int)lVar13 != 0) {
          puVar3 = (uint *)(*(long *)(lVar10 + 0x11dd8) + lVar13 & 0xffffffffffffU |
                           0x2bad000000000000);
        }
        uVar9 = *puVar3;
joined_r0xfffffff00820d308:
        if (uVar9 != 0xffffffff) {
          uVar20 = (ulong)uVar9;
          if ((int)uVar9 < *(int *)(lVar10 + 0x11db8)) {
            lVar16 = *(long *)(lVar10 + 0x11dc8);
            uVar14 = -(ulong)(uVar9 >> 0x1f) & 0xfffffffc00000000 | uVar20 << 2;
            iVar8 = (int)(uVar20 << 2);
            piVar2 = (int *)(lVar16 + iVar8);
            if (uVar14 != (long)iVar8) {
              piVar2 = (int *)(lVar16 + uVar14 & 0xffffffffffff | 0x2bad000000000000);
            }
            if (*piVar2 == -1) {
LAB_fffffff00820d3b4:
              uVar11 = thunk_EXT_FUN_8011000003a49114
                                 (
                                 "AGXk: %s:%d:%s: !!! Attempt to overflow fPrepareCounts for id %d\n"
                                 );
              return uVar11;
            }
            lVar13 = (long)(int)uVar9;
            lVar15 = lVar13 * 4;
            piVar4 = (int *)(lVar16 + (int)lVar15);
            if (lVar15 - (int)lVar15 != 0) {
              piVar4 = (int *)(lVar16 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *piVar4 = *piVar2 + 1;
            uVar14 = (ulong)(uVar9 >> 3) & 0x1ffffff8;
            *(ulong *)(*(long *)(lVar10 + 0x11dd0) + uVar14) =
                 *(ulong *)(*(long *)(lVar10 + 0x11dd0) + uVar14) &
                 (1L << (uVar20 & 0x3f) ^ 0xffffffffffffffffU);
            *(uint *)(plVar18 + 2) = uVar9;
            lVar15 = lVar13 * 8;
            puVar5 = (undefined8 *)(*(long *)(lVar10 + 0x11dc0) + (long)(int)lVar15);
            if (lVar15 - (int)lVar15 != 0) {
              puVar5 = (undefined8 *)
                       (*(long *)(lVar10 + 0x11dc0) + lVar15 & 0xffffffffffffU | 0x2bad000000000000)
              ;
            }
            *puVar5 = plVar18;
            *(undefined1 *)(lVar10 + 0x11dbc) = 0;
          }
          else {
            *(undefined1 *)(lVar10 + 0x11dbc) = 1;
            lVar16 = *(long *)(lVar10 + 0x11dc8);
            lVar13 = (long)(int)uVar9;
          }
          goto LAB_fffffff00820cdbc;
        }
      }
      *(undefined1 *)(lVar10 + 0x11dbc) = 1;
      thunk_EXT_FUN_80110000038ff2e0(uVar11);
LAB_fffffff00820d31c:
      *(undefined4 *)(param_1 + 0x202) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x115) = 0xffffffff;
      (**(code **)(*(long *)param_1[0x17d] + 0xa0))();
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1[0x17d] + 0x120));
      (**(code **)(*param_1 + 0x98))(param_1);
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to get ID for PM resources\n");
      return 0xe00002be;
    }
    lVar13 = (long)(int)uVar9;
    lVar16 = lVar13 * 8;
    plVar19 = (long *)(*(long *)(lVar10 + 0x11dc0) + (long)(int)lVar16);
    if (lVar16 - (int)lVar16 != 0) {
      plVar19 = (long *)(*(long *)(lVar10 + 0x11dc0) + lVar16 & 0xffffffffffffU | 0x2bad000000000000
                        );
    }
    if ((long *)*plVar19 != plVar18) goto LAB_fffffff00820cc74;
    lVar16 = *(long *)(lVar10 + 0x11dc8);
    lVar15 = lVar13 * 4;
    piVar2 = (int *)(lVar16 + (int)lVar15);
    if (lVar15 - (int)lVar15 != 0) {
      piVar2 = (int *)(lVar16 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
    }
    if (*piVar2 == -1) goto LAB_fffffff00820d3b4;
    *piVar2 = *piVar2 + 1;
    uVar14 = (ulong)(uVar9 >> 3) & 0x1ffffff8;
    *(ulong *)(*(long *)(lVar10 + 0x11dd0) + uVar14) =
         *(ulong *)(*(long *)(lVar10 + 0x11dd0) + uVar14) &
         (1L << (uVar20 & 0x3f) ^ 0xffffffffffffffffU);
LAB_fffffff00820cdbc:
    lVar13 = lVar13 * 4;
    piVar2 = (int *)(lVar16 + (int)lVar13);
    if (lVar13 - (int)lVar13 != 0) {
      piVar2 = (int *)(lVar16 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
    }
    iVar8 = *piVar2;
    thunk_EXT_FUN_80110000038ff2e0(uVar11);
    uVar14 = (**(code **)(*plVar18 + 0x80))(plVar18,iVar8 == 1);
    if ((uVar14 & 1) == 0) {
      FUN_fffffff0081dff40(lVar10 + 0x11da8,plVar18,uVar20);
      goto LAB_fffffff00820d31c;
    }
    *(int *)(param_1 + 0x202) = (int)uVar20;
    *(int *)(param_1 + 0x115) = (int)uVar20;
    lVar15 = param_1[0x17d];
    lVar16 = *(long *)(lVar15 + 0x20);
    lVar10 = *(long *)(lVar16 + 0x50);
    lVar13 = *(long *)(lVar16 + 0x58);
    param_1[0x203] = lVar13;
    param_1[0x116] = lVar13;
    param_1[0x11a] = lVar10;
    if ((*(byte *)(lVar15 + 0x28) | 2) == 3) {
      lVar10 = *(long *)(*(long *)(lVar16 + 0x20) + 0x18);
    }
    else {
      lVar10 = *(long *)(*(long *)(lVar16 + 0x20) + 0x18) + 0x40;
    }
    lVar13 = *(long *)(lVar15 + 0x10);
    if ((*(byte *)(lVar13 + 0x1ac45) & 1) != 0) {
      FUN_fffffff0081a0304(*(undefined8 *)(lVar13 + 0x148),0x803,lVar10,param_1[0x191]);
      lVar13 = *(long *)(lVar15 + 0x10);
    }
    uVar20 = thunk_EXT_FUN_80110000029484b4(*(undefined8 *)(lVar13 + 0x148),lVar10,&uStack_90);
    plVar18 = (long *)param_1[0x17d];
    if ((uVar20 & 1) != 0) {
      bVar6 = *(byte *)(plVar18 + 5);
      if (((bVar6 | 2) == 3) && ((int)plVar18[0x26] == (int)plVar18[0x27])) {
        uVar11 = thunk_EXT_FUN_8011000003a49114
                           ("AGXk: %s:%d:%s: !!! Bad shrink head during PM reinit\n\n");
        return uVar11;
      }
      *(undefined4 *)(param_1 + 0x208) = *(undefined4 *)((long)plVar18 + 0x134);
      *(int *)((long)param_1 + 0x103c) = (int)plVar18[0x26];
      *(byte *)((long)param_1 + 0x1044) = bVar6;
      goto LAB_fffffff00820cf70;
    }
  }
  (**(code **)(*plVar18 + 0xa0))();
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1[0x17d] + 0x120));
LAB_fffffff00820d23c:
  (**(code **)(*param_1 + 0x98))(param_1);
  return 0xe00002be;
}

