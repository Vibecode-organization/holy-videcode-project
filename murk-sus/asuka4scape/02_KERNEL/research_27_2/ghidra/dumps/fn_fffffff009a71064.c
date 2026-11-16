// FUN_fffffff009a71064 @ fffffff009a71064 size=1888
// CALLERS:
//   fffffff00afe8261 no-fn
//   fffffff009a71a30 FUN_fffffff009a71a28@fffffff009a71a28
// CALLEES:
//   fffffff009a9a680 thunk_FUN_fffffff009c24784
//   fffffff009a9a900 thunk_FUN_fffffff00aa64ec0
//   fffffff009a9a760 thunk_FUN_fffffff009c223bc
//   fffffff009a9a740 thunk_FUN_fffffff009c225b4
//   fffffff009a9a7e0 thunk_FUN_fffffff009c28af0
//   fffffff009a9a7b0 thunk_FUN_fffffff009c22264
//   fffffff009a9a780 thunk_FUN_fffffff009c22350

void FUN_fffffff009a71064
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7)

{
  uint *puVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  long *plVar8;
  long *plVar9;
  ulong uVar10;
  long *plVar11;
  long lVar12;
  uint uVar13;
  uint uVar14;
  ulong uVar15;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 auVar16 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  
  if ((param_7 != 0) && (lVar7 = thunk_FUN_fffffff009c22264(param_7), lVar7 != 0)) {
    plVar8 = (long *)thunk_FUN_fffffff009c22264(param_7);
    plVar8 = (long *)(**(code **)(*plVar8 + 0xe8))(plVar8,0);
    if (plVar8 != (long *)0x0) {
      plVar9 = (long *)(**(code **)(*plVar8 + 0x78))();
      if ((plVar9 != (long *)0x0) && (iVar4 = thunk_FUN_fffffff009c223bc(param_7), iVar4 != 0)) {
        uVar14 = 0;
        auVar16 = extraout_q0;
        do {
          lVar7 = thunk_FUN_fffffff009c28af0
                            (auVar16,param_2,param_3,param_4,param_5,param_6,param_7,uVar14);
          if (lVar7 == 0) {
LAB_fffffff009a71174:
            uVar15 = thunk_FUN_fffffff009c225b4
                               (extraout_q0_00,param_2,param_3,param_4,param_5,param_6,param_7,
                                uVar14);
            uVar15 = uVar15 & 0xffffffff;
            uVar10 = 0;
            plVar11 = plVar9;
          }
          else if (*(char *)(lVar7 + 0x20) == '\x03') {
            uVar6 = *(uint *)(lVar7 + 8);
            uVar2 = *(uint *)(lVar7 + 0xc);
            uVar15 = thunk_FUN_fffffff009c225b4
                               (extraout_q0_00,param_2,param_3,param_4,param_5,param_6,param_7,
                                uVar14);
            thunk_FUN_fffffff00aa64ec0
                      ((long *)((long)plVar9 + (ulong)uVar2),uVar15 & 0xffffffff,0,
                       uVar15 & 0xffffffff);
            uVar5 = thunk_FUN_fffffff009c22350(param_7);
            lVar7 = 0x1b;
            if ((int)uVar5 < 0x73347630) {
              if (0x62336137 < (int)uVar5) {
                if ((int)uVar5 < 0x70343434) {
                  if ((int)uVar5 < 0x66336138) {
                    if (uVar5 != 0x62336138) {
                      if (uVar5 == 0x66306138) goto LAB_fffffff009a7162c;
                      uVar13 = 0x66326138;
LAB_fffffff009a71588:
                      if (uVar5 == uVar13) goto LAB_fffffff009a7162c;
                      goto LAB_fffffff009a71714;
                    }
                  }
                  else {
                    if (0x7034322f < (int)uVar5) {
                      if (uVar5 == 0x70343230) goto LAB_fffffff009a716a8;
                      uVar13 = 0x70343232;
                      goto LAB_fffffff009a716a0;
                    }
                    if (uVar5 != 0x66336138) {
                      uVar13 = 0x66346138;
                      goto LAB_fffffff009a71588;
                    }
                  }
LAB_fffffff009a71594:
                  lVar12 = 0;
                  if (uVar14 != 1) {
                    lVar12 = 0x1b;
                  }
                  goto LAB_fffffff009a71624;
                }
                if ((int)uVar5 < 0x70663434) {
                  if ((uVar5 != 0x70343434) && (uVar5 != 0x70663230)) {
                    uVar13 = 0x3232;
                    goto LAB_fffffff009a715f4;
                  }
                }
                else {
                  if ((uVar5 + 0x8ccb99d0 < 5) &&
                     ((1 << (ulong)(uVar5 + 0x8ccb99d0 & 0x1f) & 0x15U) != 0))
                  goto LAB_fffffff009a713e0;
                  uVar13 = 0x3434;
LAB_fffffff009a715f4:
                  uVar13 = uVar13 | 0x70660000;
LAB_fffffff009a716a0:
                  if (uVar5 != uVar13) goto LAB_fffffff009a71714;
                }
LAB_fffffff009a716a8:
                lVar12 = 10;
                if (uVar14 != 1) {
                  lVar12 = 0x1b;
                }
                lVar7 = 3;
                goto LAB_fffffff009a71710;
              }
              if ((int)uVar5 < 0x34323076) {
                if ((int)uVar5 < 0x26663338) {
                  if (uVar5 == 0x26424741) goto LAB_fffffff009a71704;
                  if (uVar5 == 0x26526841) goto LAB_fffffff009a716e4;
                  if (uVar5 != 0x26623338) goto LAB_fffffff009a71714;
                  goto LAB_fffffff009a71594;
                }
                if (0x26773460 < (int)uVar5) {
                  if (uVar5 == 0x26773461) goto LAB_fffffff009a716f4;
                  uVar13 = 0x3066;
                  goto LAB_fffffff009a71660;
                }
                if (uVar5 == 0x26663338) goto LAB_fffffff009a71594;
                uVar13 = 0x26773372;
LAB_fffffff009a71614:
                if (uVar5 != uVar13) goto LAB_fffffff009a71714;
                lVar12 = 0x1b;
LAB_fffffff009a71624:
                lVar7 = 0x13;
                goto LAB_fffffff009a71710;
              }
              if ((int)uVar5 < 0x34343466) {
                if ((uVar5 != 0x34323076) && (uVar5 != 0x34323266)) {
                  uVar13 = 0x3276;
LAB_fffffff009a71660:
                  uVar13 = uVar13 | 0x34320000;
LAB_fffffff009a71664:
                  if (uVar5 != uVar13) goto LAB_fffffff009a71714;
                }
              }
              else {
                if (0x42475240 < (int)uVar5) {
                  if (uVar5 != 0x42475241) {
                    if (uVar5 != 0x52476841) goto LAB_fffffff009a71714;
LAB_fffffff009a716e4:
                    lVar12 = 0x1b;
                    lVar7 = 0x18;
                    goto LAB_fffffff009a71710;
                  }
LAB_fffffff009a71704:
                  lVar12 = 0x1b;
                  lVar7 = 0x15;
                  goto LAB_fffffff009a71710;
                }
                if (uVar5 != 0x34343466) {
                  uVar13 = 0x34343476;
                  goto LAB_fffffff009a71664;
                }
              }
              lVar7 = 8;
              if (uVar14 != 1) {
                lVar7 = 0x1b;
              }
              if (uVar14 == 0) {
                lVar7 = 1;
              }
            }
            else {
              if ((int)uVar5 < 0x77343061) {
                if ((int)uVar5 < 0x74763230) {
                  if ((int)uVar5 < 0x74663230) {
                    if ((4 < uVar5 + 0x8ccb89d0) ||
                       ((1 << (ulong)(uVar5 + 0x8ccb89d0 & 0x1f) & 0x15U) == 0))
                    goto LAB_fffffff009a71714;
LAB_fffffff009a713e0:
                    lVar12 = 0x11;
                    if (uVar14 != 1) {
                      lVar12 = 0x1b;
                    }
                    lVar7 = 7;
                    goto LAB_fffffff009a71710;
                  }
                  if ((uVar5 != 0x74663230) && (uVar5 != 0x74663232)) {
                    uVar13 = 0x74663434;
                    goto LAB_fffffff009a714bc;
                  }
                }
                else {
                  if (0x76306137 < (int)uVar5) {
                    if ((int)uVar5 < 0x76346138) {
                      if (uVar5 != 0x76306138) {
                        uVar13 = 0x76326138;
                        goto LAB_fffffff009a71588;
                      }
                    }
                    else if (uVar5 != 0x76346138) {
                      uVar13 = 0x77333072;
                      goto LAB_fffffff009a71614;
                    }
LAB_fffffff009a7162c:
                    if (uVar14 < 3) {
                      lVar7 = (&DAT_fffffff007859348)[uVar14];
                    }
                    else {
                      lVar7 = 0x1b;
                    }
                    goto LAB_fffffff009a71714;
                  }
                  if ((uVar5 != 0x74763230) && (uVar5 != 0x74763232)) {
                    uVar13 = 0x74763434;
LAB_fffffff009a714bc:
                    if (uVar5 != uVar13) goto LAB_fffffff009a71714;
                  }
                }
                lVar12 = 0xb;
                if (uVar14 != 1) {
                  lVar12 = 0x1b;
                }
                lVar7 = 4;
              }
              else if ((int)uVar5 < 0x78663434) {
                if (0x78343433 < (int)uVar5) {
                  if ((uVar5 != 0x78343434) && (uVar5 != 0x78663230)) {
                    uVar13 = 0x3232;
                    goto LAB_fffffff009a71504;
                  }
                  goto LAB_fffffff009a71510;
                }
                if (uVar5 != 0x77343061) {
                  if (uVar5 == 0x78343230) goto LAB_fffffff009a71510;
                  uVar13 = 0x78343232;
                  goto LAB_fffffff009a71508;
                }
LAB_fffffff009a716f4:
                lVar12 = 0x1b;
                lVar7 = 0x19;
              }
              else if (((uVar5 + 0x868f99d0 < 5) &&
                       ((1 << (ulong)(uVar5 + 0x868f99d0 & 0x1f) & 0x15U) != 0)) ||
                      ((uVar5 + 0x868f89d0 < 5 &&
                       ((1 << (ulong)(uVar5 + 0x868f89d0 & 0x1f) & 0x15U) != 0)))) {
                lVar12 = 0xc;
                if (uVar14 != 1) {
                  lVar12 = 0x1b;
                }
                lVar7 = 5;
              }
              else {
                uVar13 = 0x3434;
LAB_fffffff009a71504:
                uVar13 = uVar13 | 0x78660000;
LAB_fffffff009a71508:
                if (uVar5 != uVar13) goto LAB_fffffff009a71714;
LAB_fffffff009a71510:
                lVar12 = 9;
                if (uVar14 != 1) {
                  lVar12 = 0x1b;
                }
                lVar7 = 2;
              }
LAB_fffffff009a71710:
              if (uVar14 != 0) {
                lVar7 = lVar12;
              }
            }
LAB_fffffff009a71714:
            lVar12 = lVar7 * 0x2c + 0x20;
            iVar4 = (int)lVar12;
            puVar1 = (uint *)(&UNK_fffffff007858e78 + iVar4);
            if (lVar12 != iVar4) {
              puVar1 = (uint *)((ulong)(&UNK_fffffff007858e98 + lVar7 * 0x2c) & 0xffffffffffff |
                               0x2bad000000000000);
            }
            uVar15 = (ulong)((uVar2 - uVar6) + (int)uVar15);
            uVar10 = (ulong)*puVar1;
            plVar11 = (long *)((long)plVar9 + (ulong)uVar6);
          }
          else {
            if (*(char *)(lVar7 + 0x20) != '\x02') goto LAB_fffffff009a71174;
            uVar6 = *(uint *)(lVar7 + 8);
            uVar2 = *(uint *)(lVar7 + 0xc);
            uVar10 = thunk_FUN_fffffff009c225b4
                               (extraout_q0_00,param_2,param_3,param_4,param_5,param_6,param_7,
                                uVar14);
            uVar15 = (ulong)((uVar2 - uVar6) + (int)uVar10);
            thunk_FUN_fffffff00aa64ec0
                      ((long *)((long)plVar9 + (ulong)uVar2),uVar10 & 0xffffffff,0,
                       uVar10 & 0xffffffff);
            uVar10 = 0xff;
            plVar11 = (long *)((long)plVar9 + (ulong)uVar6);
          }
          thunk_FUN_fffffff00aa64ec0(plVar11,uVar15,uVar10,uVar15);
          uVar14 = uVar14 + 1;
          uVar6 = thunk_FUN_fffffff009c223bc(param_7);
          auVar16 = extraout_q0_01;
        } while (uVar14 < uVar6);
      }
      (**(code **)(*plVar8 + 0x28))(plVar8);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        thunk_FUN_fffffff009c24784(param_7,0);
        return;
      }
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009a717a4);
      (*pcVar3)();
    }
  }
  return;
}

