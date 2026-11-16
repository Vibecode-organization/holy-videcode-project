// FUN_fffffff0081e3b50 @ fffffff0081e3b50 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0081e3d44) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081e41e0) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081e40a8) */

void FUN_fffffff0081e3b50(long *param_1,code *param_2,ulong param_3)

{
  long *plVar1;
  long lVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  bool bVar9;
  long lVar10;
  long *plVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  long lVar15;
  int iVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar20;
  ulong uVar21;
  ulong uVar22;
  undefined8 uVar23;
  code *pcVar24;
  int iVar25;
  ulong uVar26;
  ulong uVar27;
  ulong uVar28;
  uint uVar29;
  uint uVar30;
  ulong uVar31;
  ulong uVar32;
  ulong uVar33;
  long lVar34;
  ulong uVar35;
  uint uVar36;
  uint uVar37;
  long lVar38;
  long lStack_110;
  long lStack_98;
  int iStack_84;
  long lStack_80;
  int iStack_78;
  int iStack_74;
  undefined1 auStack_70 [4];
  undefined1 auStack_6c [12];
  long lVar19;
  
  uVar8 = DAT_fffffff00ae2181c;
  uVar6 = DAT_fffffff00ae21818;
  uVar7 = DAT_fffffff00ae21810;
  uVar17 = (ulong)DAT_fffffff00ae21818;
  uVar35 = (ulong)DAT_fffffff00ae2181c;
  lVar10 = param_1[3];
  plVar11 = (long *)thunk_EXT_FUN_801100000297dd00();
  lStack_80 = 0;
  lVar12 = thunk_EXT_FUN_8011000003977d8c(plVar11,0);
  uVar18 = param_1[10];
  lVar13 = (**(code **)(*param_1 + 0x98))(param_1);
  uVar14 = (**(code **)(*plVar11 + 0x98))(plVar11,0,&lStack_80,0);
  lVar19 = (long)param_3 >> 1;
  iVar16 = (int)lVar19;
  if (uVar14 != 0) {
    lStack_110 = 0;
    lStack_98 = 0;
    iStack_84 = 0;
    uVar20 = ~uVar7;
    plVar1 = (long *)((long)param_1 + (long)iVar16);
    if (lVar19 != iVar16) {
      plVar1 = (long *)((long)param_1 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
    }
    do {
      uVar28 = (uVar14 & uVar7) + (ulong)(uVar6 - 1) + lStack_80 & uVar20;
      uVar26 = uVar28 >> (uVar35 & 0x3f);
      iVar25 = (int)uVar26;
      if (iVar25 != 0) {
        uVar32 = 0;
        uVar14 = uVar14 & uVar20;
        do {
          uVar31 = (uVar32 << (uVar35 & 0x3f)) + lStack_98;
          lVar34 = param_1[3];
          if (*(char *)(lVar34 + 0xe8) == '\x02') {
            if ((*(byte *)(lVar34 + 0x120) & 1) != 0) {
              bVar3 = *(byte *)(lVar34 + 0xf8);
              uVar29 = (uint)bVar3;
              if (bVar3 == 0) {
                uVar36 = 0;
                uVar5 = *(ushort *)(lVar34 + 0xf6);
                lVar38 = -1;
              }
              else {
                lVar38 = 0;
                uVar30 = 0;
                bVar4 = *(byte *)(lVar34 + 0xf9);
                uVar5 = *(ushort *)(lVar34 + 0xf6);
                do {
                  lVar15 = FUN_fffffff0081e4230
                                     (lVar34 + 0xf0,uVar30,auStack_6c,auStack_70,&iStack_74,
                                      &iStack_78);
                  uVar21 = (ulong)((uint)uVar5 * (uint)bVar4 * iStack_74 * iStack_78);
                  uVar36 = uVar30;
                  if ((ulong)(lVar15 << 2) / 3 <= uVar21) break;
                  lVar38 = lVar38 + uVar21;
                  uVar30 = uVar30 + 1;
                  uVar36 = uVar29;
                } while (bVar3 != uVar30);
                lVar38 = lVar38 + -1;
              }
              uVar33 = (ulong)uVar5;
              uVar30 = (uint)bVar3;
              lVar15 = FUN_fffffff0081e39cc(lVar34 + 0xf0,uVar36,uVar30 - uVar36);
              uVar27 = -uVar33;
              uVar21 = (ulong)*(ushort *)(lVar34 + 0xf4);
              if ((lVar38 + uVar33 + lVar15 & uVar27) * uVar21 <= uVar31) {
                if (uVar30 == 0) {
                  uVar36 = 0;
                  lVar38 = -1;
                }
                else {
                  lVar38 = 0;
                  uVar37 = 0;
                  bVar3 = *(byte *)(lVar34 + 0xf9);
                  do {
                    lVar15 = FUN_fffffff0081e4230
                                       (lVar34 + 0xf0,uVar37,auStack_6c,auStack_70,&iStack_74,
                                        &iStack_78);
                    uVar22 = (ulong)((uint)uVar5 * (uint)bVar3 * iStack_74 * iStack_78);
                    uVar36 = uVar37;
                    if ((ulong)(lVar15 << 2) / 3 <= uVar22) break;
                    lVar38 = lVar38 + uVar22;
                    uVar37 = uVar37 + 1;
                    uVar36 = uVar29;
                  } while (uVar30 != uVar37);
                  lVar38 = lVar38 + -1;
                }
                lVar15 = FUN_fffffff0081e39cc(lVar34 + 0xf0,uVar36,uVar30 - uVar36);
                lVar38 = FUN_fffffff0081e4580
                                   (lVar34 + 0x108,
                                    uVar31 - (lVar38 + uVar33 + lVar15 & uVar27) * uVar21);
                lVar15 = FUN_fffffff0081e39cc(lVar34 + 0xf0,0,uVar29);
                if (*(char *)(lVar34 + 0x105) == '\0') {
                  bVar9 = *(char *)(lVar34 + 0x106) != '\0';
                }
                else {
                  bVar9 = true;
                }
                uVar27 = (lVar15 + uVar33) - 1 & uVar27;
                bVar3 = *(byte *)(lVar34 + 0x101);
                lVar34 = 0x4000;
                if (!(bool)((uVar27 & 0xffffffffffffc000) != 0 & bVar9)) {
                  lVar34 = 0x80;
                }
                lVar15 = 0x4000;
                if (!(bool)((uVar27 & 0xffffffffffffc000) != 0 & bVar9)) {
                  lVar15 = 0x80;
                }
                if (bVar3 != 4) {
                  lVar15 = 0;
                }
                if (bVar3 != 3) {
                  lVar34 = lVar15;
                }
                lVar15 = 0x4000;
                if (!(bool)((uVar27 & 0xffffffffffffc000) != 0 & bVar9)) {
                  lVar15 = 0x40;
                }
                lVar2 = 0x4000;
                if (!(bool)((uVar27 & 0xffffffffffffc000) != 0 & bVar9)) {
                  lVar2 = 0x80;
                }
                if (bVar3 != 2) {
                  lVar2 = 0;
                }
                if (bVar3 != 1) {
                  lVar15 = lVar2;
                }
                if (bVar3 < 3) {
                  lVar34 = lVar15;
                }
                lVar38 = lVar38 + lVar13 + ((uVar27 + lVar34) - 1 & -lVar34) * uVar21;
                goto LAB_fffffff0081e4060;
              }
            }
            lVar38 = FUN_fffffff0081e4580(lVar34 + 0xf0,uVar31);
            lVar38 = lVar38 + lVar13;
          }
          else {
            lVar38 = uVar31 + lVar13;
            if (*(char *)(lVar34 + 0xe8) == '\x01') {
              uVar27 = (ulong)(uint)(*(int *)(lVar34 + 0xf4) << 0xc);
              uVar21 = 0;
              if (uVar27 != 0) {
                uVar21 = uVar31 / uVar27;
              }
              lVar38 = lVar38 + uVar21 * (uint)((*(int *)(lVar34 + 0xf0) - *(int *)(lVar34 + 0xf4))
                                               * 0x1000);
            }
          }
LAB_fffffff0081e4060:
          uVar31 = lVar38 - lVar13;
          if (uVar18 <= uVar31) goto LAB_fffffff0081e40fc;
          if ((param_3 & 1) == 0) {
            uVar23 = 0x706f;
            pcVar24 = param_2;
          }
          else {
            uVar23 = 0;
            pcVar24 = *(code **)(*plVar1 + ((ulong)param_2 & 0xffffffff));
          }
          (*pcVar24)(uVar23,plVar1,uVar31 >> (uVar35 & 0x3f),lVar38,iStack_84 + (int)uVar32,uVar14,0
                    );
          if (*(char *)(lVar10 + 0xe8) == '\x03') {
            if ((param_3 & 1) == 0) {
              uVar23 = 0x706f;
              pcVar24 = param_2;
            }
            else {
              uVar23 = 0;
              pcVar24 = *(code **)(*plVar1 + ((ulong)param_2 & 0xffffffff));
            }
            (*pcVar24)(uVar23,plVar1,uVar31 + lVar12 >> (uVar35 & 0x3f),lVar38 + lVar12,
                       iStack_84 + (int)uVar32,uVar14,0);
          }
          uVar14 = uVar14 + uVar17;
          uVar32 = uVar32 + 1;
        } while (uVar32 != (uVar26 & 0xffffffff));
      }
      lStack_110 = lStack_80 + lStack_110;
      lStack_98 = uVar28 + lStack_98;
      iStack_84 = iStack_84 + iVar25;
      uVar14 = (**(code **)(*plVar11 + 0x98))(plVar11,lStack_110,&lStack_80,0);
    } while (uVar14 != 0);
  }
LAB_fffffff0081e40fc:
  uVar23 = (**(code **)(*(long *)param_1[4] + 0xf8))();
  uVar14 = param_1[10];
  if ((uVar14 < (ulong)param_1[9]) &&
     (uVar6 = (uint)((int)param_1[9] - (int)uVar14) >> (ulong)(uVar8 & 0x1f), uVar6 != 0)) {
    plVar11 = (long *)((long)param_1 + (long)iVar16);
    if (lVar19 != iVar16) {
      plVar11 = (long *)((long)param_1 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
    }
    if ((param_3 & 1) == 0) {
      uVar29 = 0;
      do {
        lVar10 = uVar14 + lVar13 + (ulong)(uVar29 << (ulong)(uVar8 & 0x1f));
        (*param_2)(plVar11,(ulong)(lVar10 - lVar13) >> (uVar35 & 0x3f),lVar10,0,uVar23,1);
        uVar29 = uVar29 + 1;
      } while (uVar6 != uVar29);
    }
    else {
      uVar29 = 0;
      do {
        lVar10 = uVar14 + lVar13 + (ulong)(uVar29 << (ulong)(uVar8 & 0x1f));
        (**(code **)(*plVar11 + ((ulong)param_2 & 0xffffffff)))
                  (plVar11,(ulong)(lVar10 - lVar13) >> (uVar35 & 0x3f),lVar10,0,uVar23,1);
        uVar29 = uVar29 + 1;
      } while (uVar6 != uVar29);
    }
  }
  return;
}

