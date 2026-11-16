// FUN_fffffff009a71064 @ fffffff009a71064 size=1888
// CALLERS:
//   fffffff00afb8071 no-fn
//   fffffff009a71a30 FUN_fffffff009a71a28@fffffff009a71a28
// CALLEES:
//   fffffff009a9a680 thunk_EXT_FUN_8011000002c20784
//   fffffff009a9a7e0 thunk_EXT_FUN_8011000002c24af0
//   fffffff009a9a740 thunk_EXT_FUN_8011000002c1e5b4
//   fffffff009a9a900 thunk_EXT_FUN_8011000003a60ec0
//   fffffff009a9a780 thunk_EXT_FUN_8011000002c1e350
//   fffffff009a9a7b0 thunk_EXT_FUN_8011000002c1e264
//   fffffff009a9a760 thunk_EXT_FUN_8011000002c1e3bc

void FUN_fffffff009a71064(long param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  long *plVar9;
  long lVar10;
  undefined4 uVar11;
  long lVar12;
  uint uVar13;
  uint uVar14;
  ulong uVar15;
  ulong unaff_x30;
  
  if ((param_1 != 0) && (lVar8 = thunk_EXT_FUN_8011000002c1e264(), lVar8 != 0)) {
    plVar9 = (long *)thunk_EXT_FUN_8011000002c1e264(param_1);
    plVar9 = (long *)(**(code **)(*plVar9 + 0xe8))(plVar9,0);
    if (plVar9 != (long *)0x0) {
      lVar8 = (**(code **)(*plVar9 + 0x78))();
      if ((lVar8 != 0) && (iVar4 = thunk_EXT_FUN_8011000002c1e3bc(param_1), iVar4 != 0)) {
        uVar15 = 0;
        do {
          lVar10 = thunk_EXT_FUN_8011000002c24af0(param_1,uVar15);
          uVar14 = (uint)uVar15;
          if (lVar10 == 0) {
LAB_fffffff009a71174:
            iVar4 = thunk_EXT_FUN_8011000002c1e5b4(param_1,uVar15);
            uVar11 = 0;
            lVar10 = lVar8;
          }
          else if (*(char *)(lVar10 + 0x20) == '\x03') {
            uVar7 = *(uint *)(lVar10 + 8);
            uVar2 = *(uint *)(lVar10 + 0xc);
            iVar4 = thunk_EXT_FUN_8011000002c1e5b4(param_1,uVar15);
            thunk_EXT_FUN_8011000003a60ec0(lVar8 + (ulong)uVar2,iVar4,0,iVar4);
            uVar6 = thunk_EXT_FUN_8011000002c1e350(param_1);
            lVar10 = 0x1b;
            if ((int)uVar6 < 0x73347630) {
              if (0x62336137 < (int)uVar6) {
                if ((int)uVar6 < 0x70343434) {
                  if ((int)uVar6 < 0x66336138) {
                    if (uVar6 != 0x62336138) {
                      if (uVar6 == 0x66306138) goto LAB_fffffff009a7162c;
                      uVar13 = 0x66326138;
LAB_fffffff009a71588:
                      if (uVar6 == uVar13) goto LAB_fffffff009a7162c;
                      goto LAB_fffffff009a71714;
                    }
                  }
                  else {
                    if (0x7034322f < (int)uVar6) {
                      if (uVar6 == 0x70343230) goto LAB_fffffff009a716a8;
                      uVar13 = 0x70343232;
                      goto LAB_fffffff009a716a0;
                    }
                    if (uVar6 != 0x66336138) {
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
                if ((int)uVar6 < 0x70663434) {
                  if ((uVar6 != 0x70343434) && (uVar6 != 0x70663230)) {
                    uVar13 = 0x3232;
                    goto LAB_fffffff009a715f4;
                  }
                }
                else {
                  if ((uVar6 + 0x8ccb99d0 < 5) &&
                     ((1 << (ulong)(uVar6 + 0x8ccb99d0 & 0x1f) & 0x15U) != 0))
                  goto LAB_fffffff009a713e0;
                  uVar13 = 0x3434;
LAB_fffffff009a715f4:
                  uVar13 = uVar13 | 0x70660000;
LAB_fffffff009a716a0:
                  if (uVar6 != uVar13) goto LAB_fffffff009a71714;
                }
LAB_fffffff009a716a8:
                lVar12 = 10;
                if (uVar14 != 1) {
                  lVar12 = 0x1b;
                }
                lVar10 = 3;
                goto LAB_fffffff009a71710;
              }
              if ((int)uVar6 < 0x34323076) {
                if ((int)uVar6 < 0x26663338) {
                  if (uVar6 == 0x26424741) goto LAB_fffffff009a71704;
                  if (uVar6 == 0x26526841) goto LAB_fffffff009a716e4;
                  if (uVar6 != 0x26623338) goto LAB_fffffff009a71714;
                  goto LAB_fffffff009a71594;
                }
                if (0x26773460 < (int)uVar6) {
                  if (uVar6 == 0x26773461) goto LAB_fffffff009a716f4;
                  uVar13 = 0x3066;
                  goto LAB_fffffff009a71660;
                }
                if (uVar6 == 0x26663338) goto LAB_fffffff009a71594;
                uVar13 = 0x26773372;
LAB_fffffff009a71614:
                if (uVar6 != uVar13) goto LAB_fffffff009a71714;
                lVar12 = 0x1b;
LAB_fffffff009a71624:
                lVar10 = 0x13;
                goto LAB_fffffff009a71710;
              }
              if ((int)uVar6 < 0x34343466) {
                if ((uVar6 != 0x34323076) && (uVar6 != 0x34323266)) {
                  uVar13 = 0x3276;
LAB_fffffff009a71660:
                  uVar13 = uVar13 | 0x34320000;
LAB_fffffff009a71664:
                  if (uVar6 != uVar13) goto LAB_fffffff009a71714;
                }
              }
              else {
                if (0x42475240 < (int)uVar6) {
                  if (uVar6 != 0x42475241) {
                    if (uVar6 != 0x52476841) goto LAB_fffffff009a71714;
LAB_fffffff009a716e4:
                    lVar12 = 0x1b;
                    lVar10 = 0x18;
                    goto LAB_fffffff009a71710;
                  }
LAB_fffffff009a71704:
                  lVar12 = 0x1b;
                  lVar10 = 0x15;
                  goto LAB_fffffff009a71710;
                }
                if (uVar6 != 0x34343466) {
                  uVar13 = 0x34343476;
                  goto LAB_fffffff009a71664;
                }
              }
              lVar10 = 8;
              if (uVar14 != 1) {
                lVar10 = 0x1b;
              }
              if (uVar14 == 0) {
                lVar10 = 1;
              }
            }
            else {
              if ((int)uVar6 < 0x77343061) {
                if ((int)uVar6 < 0x74763230) {
                  if ((int)uVar6 < 0x74663230) {
                    if ((4 < uVar6 + 0x8ccb89d0) ||
                       ((1 << (ulong)(uVar6 + 0x8ccb89d0 & 0x1f) & 0x15U) == 0))
                    goto LAB_fffffff009a71714;
LAB_fffffff009a713e0:
                    lVar12 = 0x11;
                    if (uVar14 != 1) {
                      lVar12 = 0x1b;
                    }
                    lVar10 = 7;
                    goto LAB_fffffff009a71710;
                  }
                  if ((uVar6 != 0x74663230) && (uVar6 != 0x74663232)) {
                    uVar13 = 0x74663434;
                    goto LAB_fffffff009a714bc;
                  }
                }
                else {
                  if (0x76306137 < (int)uVar6) {
                    if ((int)uVar6 < 0x76346138) {
                      if (uVar6 != 0x76306138) {
                        uVar13 = 0x76326138;
                        goto LAB_fffffff009a71588;
                      }
                    }
                    else if (uVar6 != 0x76346138) {
                      uVar13 = 0x77333072;
                      goto LAB_fffffff009a71614;
                    }
LAB_fffffff009a7162c:
                    if (uVar14 < 3) {
                      lVar10 = (&DAT_fffffff007859348)[uVar15];
                    }
                    else {
                      lVar10 = 0x1b;
                    }
                    goto LAB_fffffff009a71714;
                  }
                  if ((uVar6 != 0x74763230) && (uVar6 != 0x74763232)) {
                    uVar13 = 0x74763434;
LAB_fffffff009a714bc:
                    if (uVar6 != uVar13) goto LAB_fffffff009a71714;
                  }
                }
                lVar12 = 0xb;
                if (uVar14 != 1) {
                  lVar12 = 0x1b;
                }
                lVar10 = 4;
              }
              else if ((int)uVar6 < 0x78663434) {
                if (0x78343433 < (int)uVar6) {
                  if ((uVar6 != 0x78343434) && (uVar6 != 0x78663230)) {
                    uVar13 = 0x3232;
                    goto LAB_fffffff009a71504;
                  }
                  goto LAB_fffffff009a71510;
                }
                if (uVar6 != 0x77343061) {
                  if (uVar6 == 0x78343230) goto LAB_fffffff009a71510;
                  uVar13 = 0x78343232;
                  goto LAB_fffffff009a71508;
                }
LAB_fffffff009a716f4:
                lVar12 = 0x1b;
                lVar10 = 0x19;
              }
              else if (((uVar6 + 0x868f99d0 < 5) &&
                       ((1 << (ulong)(uVar6 + 0x868f99d0 & 0x1f) & 0x15U) != 0)) ||
                      ((uVar6 + 0x868f89d0 < 5 &&
                       ((1 << (ulong)(uVar6 + 0x868f89d0 & 0x1f) & 0x15U) != 0)))) {
                lVar12 = 0xc;
                if (uVar14 != 1) {
                  lVar12 = 0x1b;
                }
                lVar10 = 5;
              }
              else {
                uVar13 = 0x3434;
LAB_fffffff009a71504:
                uVar13 = uVar13 | 0x78660000;
LAB_fffffff009a71508:
                if (uVar6 != uVar13) goto LAB_fffffff009a71714;
LAB_fffffff009a71510:
                lVar12 = 9;
                if (uVar14 != 1) {
                  lVar12 = 0x1b;
                }
                lVar10 = 2;
              }
LAB_fffffff009a71710:
              if (uVar14 != 0) {
                lVar10 = lVar12;
              }
            }
LAB_fffffff009a71714:
            lVar12 = lVar10 * 0x2c + 0x20;
            iVar5 = (int)lVar12;
            puVar1 = (undefined4 *)(&UNK_fffffff007858e78 + iVar5);
            if (lVar12 != iVar5) {
              puVar1 = (undefined4 *)
                       ((ulong)(&UNK_fffffff007858e98 + lVar10 * 0x2c) & 0xffffffffffff |
                       0x2bad000000000000);
            }
            iVar4 = (uVar2 - uVar7) + iVar4;
            uVar11 = *puVar1;
            lVar10 = lVar8 + (ulong)uVar7;
          }
          else {
            if (*(char *)(lVar10 + 0x20) != '\x02') goto LAB_fffffff009a71174;
            uVar7 = *(uint *)(lVar10 + 8);
            uVar2 = *(uint *)(lVar10 + 0xc);
            iVar5 = thunk_EXT_FUN_8011000002c1e5b4(param_1,uVar15);
            iVar4 = (uVar2 - uVar7) + iVar5;
            thunk_EXT_FUN_8011000003a60ec0(lVar8 + (ulong)uVar2,iVar5,0,iVar5);
            uVar11 = 0xff;
            lVar10 = lVar8 + (ulong)uVar7;
          }
          thunk_EXT_FUN_8011000003a60ec0(lVar10,iVar4,uVar11,iVar4);
          uVar15 = (ulong)(uVar14 + 1);
          uVar7 = thunk_EXT_FUN_8011000002c1e3bc(param_1);
        } while (uVar14 + 1 < uVar7);
      }
      (**(code **)(*plVar9 + 0x28))(plVar9);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        thunk_EXT_FUN_8011000002c20784(param_1,0);
        return;
      }
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009a717a4);
      (*pcVar3)();
    }
  }
  return;
}

