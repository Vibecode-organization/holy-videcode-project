// FUN_fffffff00a49c4e0 @ fffffff00a49c4e0 size=2964

void FUN_fffffff00a49c4e0(long param_1,byte *param_2,byte *param_3)

{
  ulong *puVar1;
  uint *puVar2;
  char cVar3;
  code *pcVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  undefined8 *puVar12;
  long *plVar13;
  undefined8 uVar14;
  ulong uVar15;
  byte bVar16;
  undefined4 uVar17;
  ulong uVar18;
  ulong uVar19;
  long lVar20;
  long lVar21;
  ulong uVar22;
  byte *pbVar23;
  ulong uVar24;
  int in_wzr;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  long local_f0;
  ulong uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined1 auStack_78 [8];
  long local_70;
  
  local_70 = DAT_fffffff00ad30000;
  bVar16 = param_2[1];
  uVar19 = 0x14;
  if (bVar16 != 0x12) {
    uVar19 = 0x20;
  }
  if (uVar19 <= *param_2) {
    uVar19 = (ulong)*param_2;
  }
  uVar18 = 0x14;
  if (param_3[1] != 0x12) {
    uVar18 = 0x20;
  }
  if (uVar18 <= *param_3) {
    uVar18 = (ulong)*param_3;
  }
  if ((bVar16 == 0x1e) || (bVar16 == 2)) {
    puVar1 = &DAT_fffffff00ad85b60 + bVar16;
    if ((ulong *)0xfffffff00ad85caf < puVar1 || puVar1 < &DAT_fffffff00ad85b60)
    goto LAB_fffffff00a49c850;
    if ((*(byte *)(param_1 + 0x77) >> 1 & 1) != 0) {
LAB_fffffff00a49cc6c:
      uVar17 = 0x10;
      goto LAB_fffffff00a49cc70;
    }
    uVar24 = *puVar1;
    FUN_fffffff00a49b804(param_1);
    if ((*(byte *)(param_1 + 0x74) >> 1 & 1) != 0) {
      bVar16 = param_2[1];
      if (*param_2 == *param_3) {
        if ((bVar16 == 0x1e) || (bVar16 == 2)) {
          uStack_88 = 0;
          local_90 = 0;
          auStack_78 = (undefined1  [8])0x0;
          uStack_80 = 0;
          uStack_a8 = 0;
          local_b0 = 0;
          uStack_98 = 0;
          uStack_a0 = 0;
          uStack_c8 = 0;
          local_d0 = 0;
          uStack_b8 = 0;
          uStack_c0 = 0;
          uStack_e8 = 0;
          local_f0 = 0;
          uStack_d8 = 0;
          uStack_e0 = 0;
          uStack_108 = 0;
          local_110 = 0;
          uStack_f8 = 0;
          uStack_100 = 0;
          uStack_128 = 0;
          local_130 = 0;
          uStack_118 = 0;
          uStack_120 = 0;
          uStack_148 = 0;
          local_150 = 0;
          uStack_138 = 0;
          uStack_140 = 0;
          uStack_168 = 0;
          local_170 = 0;
          uStack_158 = 0;
          uStack_160 = 0;
          FUN_fffffff00a497af0(param_2,&local_f0,0);
          FUN_fffffff00a497af0(param_3,&local_170,0);
          if ((byte)local_f0 == (byte)local_170) {
            if ((&stack0x0000000f < &local_f0) || (auStack_78 + 7 < &local_170))
            goto LAB_fffffff00a49c850;
            pbVar10 = (byte *)&local_f0;
            pbVar11 = (byte *)&local_170;
            goto LAB_fffffff00a49c85c;
          }
          bVar5 = false;
        }
        else {
          if ((param_2 + 0xff < param_2) ||
             (pbVar10 = param_2, pbVar11 = param_3, param_3 + 0xff < param_3))
          goto LAB_fffffff00a49c850;
LAB_fffffff00a49c85c:
          iVar9 = FUN_fffffff00a354278(pbVar10,pbVar11);
          bVar5 = iVar9 == 0;
        }
        uVar7 = DAT_fffffff00ad7cd2c;
        uVar6 = *(uint *)(param_1 + 0x74) & 0x406;
        if ((uVar6 != 2) || (!bVar5)) {
          if (!(bool)(uVar6 == 6 & bVar5)) {
            if ((*(uint *)(param_1 + 0x74) >> 1 & 1) == 0) goto LAB_fffffff00a49c5a0;
            bVar16 = param_2[1];
            goto LAB_fffffff00a49ca28;
          }
          uVar19 = *(ulong *)(param_1 + 0x18);
          if (uVar19 != 0) {
            if (((ulong)*(byte *)(param_1 + 0x14) < 2) ||
               (uVar19 + *(byte *)(param_1 + 0x14) < uVar19)) goto LAB_fffffff00a49c850;
            if ((DAT_fffffff00ad7cd2c & 1) != 0) {
              uVar6 = *(uint *)(param_1 + 0x37c);
              *(uint *)(param_1 + 0x37c) = uVar6 + 1;
              if ((uVar7 >> 1 & 1) != 0) {
                puVar12 = (undefined8 *)(param_1 + 0x770U) + (ulong)(uVar6 & 3) * 9;
                if ((puVar12 != (undefined8 *)0x0) &&
                   (((undefined8 *)(param_1 + 0x890U) <= puVar12 ||
                    (puVar12 < (undefined8 *)(param_1 + 0x770U))))) goto LAB_fffffff00a49c850;
                uVar14 = tpidr_el1;
                *puVar12 = uVar14;
                puVar12[4] = 0;
                puVar12[3] = 0;
                puVar12[6] = 0;
                puVar12[5] = 0;
                puVar12[8] = 0;
                puVar12[7] = 0;
                puVar12[2] = 0;
                puVar12[1] = 0;
                FUN_fffffff00a8949d8(puVar12 + 1,8);
              }
            }
            lVar20 = tpidr_el1;
            if (*(int *)(param_1 + 0x68) == *(int *)(lVar20 + 0x4e8)) {
              *(int *)(param_1 + 0x68) = in_wzr;
              uVar19 = *(ulong *)(param_1 + 0x18);
            }
            else {
              FUN_fffffff00a226e08(param_1 + 0x60,lVar20);
              uVar19 = *(ulong *)(param_1 + 0x18);
            }
            if ((uVar19 != 0) &&
               (((ulong)*(byte *)(param_1 + 0x14) < 2 ||
                (uVar19 + *(byte *)(param_1 + 0x14) < uVar19)))) goto LAB_fffffff00a49c850;
            uVar18 = *(ulong *)(param_1 + 0x20);
            if ((uVar18 != 0) &&
               (((ulong)*(byte *)(param_1 + 0x15) < 2 ||
                (uVar18 + *(byte *)(param_1 + 0x15) < uVar18)))) goto LAB_fffffff00a49c850;
            FUN_fffffff00a499fc8
                      (2,uVar19,*(undefined8 *)(param_1 + 0x80),uVar18,
                       *(uint *)(param_1 + 0x74) & 0xfeffffff,0,0);
            if (*(ulong *)(param_1 + 0x68) == 0) {
              *(ulong *)(param_1 + 0x68) = (ulong)*(uint *)(lVar20 + 0x4e8);
              uVar6 = DAT_fffffff00ad7cd2c;
            }
            else {
              FUN_fffffff00a2262d4(param_1 + 0x60,lVar20,0);
              uVar6 = DAT_fffffff00ad7cd2c;
            }
            DAT_fffffff00ad7cd2c = uVar6;
            if ((uVar6 & 1) != 0) {
              uVar7 = *(uint *)(param_1 + 0x378);
              *(uint *)(param_1 + 0x378) = uVar7 + 1;
              if ((uVar6 >> 1 & 1) != 0) {
                plVar13 = (long *)(param_1 + 0x650U) + (ulong)(uVar7 & 3) * 9;
                if ((plVar13 != (long *)0x0) &&
                   (((long *)(param_1 + 0x770U) <= plVar13 || (plVar13 < (long *)(param_1 + 0x650U))
                    ))) goto LAB_fffffff00a49c850;
                *plVar13 = lVar20;
                plVar13[4] = 0;
                plVar13[3] = 0;
                plVar13[6] = 0;
                plVar13[5] = 0;
                plVar13[8] = 0;
                plVar13[7] = 0;
                plVar13[2] = 0;
                plVar13[1] = 0;
                FUN_fffffff00a8949d8(plVar13 + 1,8);
              }
            }
          }
        }
        FUN_fffffff00a49e4c4(param_1);
        uVar17 = 0x31;
        goto LAB_fffffff00a49cc70;
      }
LAB_fffffff00a49ca28:
      uVar6 = DAT_fffffff00ad7cd2c;
      if (bVar16 == 0x1e) {
        if (*param_2 < 0x1c) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff00aa4d114("%s: bad sockaddr_in6 %p @%s:%d");
        }
        lVar20 = 0x18;
LAB_fffffff00a49ca5c:
        uVar7 = *(uint *)(param_2 + lVar20);
      }
      else {
        if (bVar16 == 2) {
          if (*param_2 < 0x10) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff00aa4d114("%s: bad sockaddr_in %p @%s:%d");
          }
          lVar20 = 8;
          goto LAB_fffffff00a49ca5c;
        }
        uVar7 = 0;
      }
      if ((DAT_fffffff00ad7cd2c & 1) != 0) {
        uVar8 = *(uint *)(param_1 + 0x37c);
        *(uint *)(param_1 + 0x37c) = uVar8 + 1;
        if ((uVar6 >> 1 & 1) != 0) {
          puVar12 = (undefined8 *)(param_1 + 0x770U) + (ulong)(uVar8 & 3) * 9;
          if ((puVar12 != (undefined8 *)0x0) &&
             (((undefined8 *)(param_1 + 0x890U) <= puVar12 ||
              (puVar12 < (undefined8 *)(param_1 + 0x770U))))) goto LAB_fffffff00a49c850;
          uVar14 = tpidr_el1;
          *puVar12 = uVar14;
          puVar12[4] = 0;
          puVar12[3] = 0;
          puVar12[6] = 0;
          puVar12[5] = 0;
          puVar12[8] = 0;
          puVar12[7] = 0;
          puVar12[2] = 0;
          puVar12[1] = 0;
          FUN_fffffff00a8949d8(puVar12 + 1,8);
        }
      }
      lVar20 = tpidr_el1;
      puVar1 = (ulong *)(param_1 + 0x68);
      if (*(int *)puVar1 == *(int *)(lVar20 + 0x4e8)) {
        *(int *)puVar1 = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(param_1 + 0x60,lVar20);
      }
      lVar21 = FUN_fffffff00a498db0(param_3,1,0x10000,uVar7);
      if (*puVar1 == 0) {
        *puVar1 = (ulong)*(uint *)(lVar20 + 0x4e8);
      }
      else {
        FUN_fffffff00a2262d4(param_1 + 0x60,lVar20,0);
      }
      uVar6 = DAT_fffffff00ad7cd2c;
      if ((DAT_fffffff00ad7cd2c & 1) != 0) {
        uVar8 = *(uint *)(param_1 + 0x378);
        *(uint *)(param_1 + 0x378) = uVar8 + 1;
        if ((uVar6 >> 1 & 1) != 0) {
          plVar13 = (long *)(param_1 + 0x650U) + (ulong)(uVar8 & 3) * 9;
          if ((plVar13 != (long *)0x0) &&
             (((long *)(param_1 + 0x770U) <= plVar13 || (plVar13 < (long *)(param_1 + 0x650U)))))
          goto LAB_fffffff00a49c850;
          *plVar13 = lVar20;
          plVar13[4] = 0;
          plVar13[3] = 0;
          plVar13[6] = 0;
          plVar13[5] = 0;
          plVar13[8] = 0;
          plVar13[7] = 0;
          plVar13[2] = 0;
          plVar13[1] = 0;
          FUN_fffffff00a8949d8(plVar13 + 1,8);
        }
      }
      if (lVar21 == param_1) {
        FUN_fffffff00a49e4c4(lVar21);
        FUN_fffffff00a49e4c4(param_1);
        uVar17 = 0x30;
        goto LAB_fffffff00a49cc70;
      }
      if ((((uVar7 != 0) && ((*(uint *)(param_1 + 0x74) >> 0x18 & 1) != 0)) && (lVar21 != 0)) &&
         ((*(long *)(lVar21 + 0x88) != 0 && (uVar7 != *(ushort *)(*(long *)(lVar21 + 0x88) + 0xcc)))
         )) {
        FUN_fffffff00a498684(lVar21,1);
        FUN_fffffff00a49e4c4(param_1);
        uVar17 = 0x33;
        if ((*(byte *)(param_1 + 0x74) & 4) != 0) {
          uVar17 = 0x41;
        }
        goto LAB_fffffff00a49cc70;
      }
      if ((*(uint *)(param_1 + 0x74) >> 0x19 & 1) != 0) {
        if (lVar21 != 0) {
          FUN_fffffff00a498684(lVar21,1);
        }
        FUN_fffffff00a49e4c4(param_1);
        goto LAB_fffffff00a49cc6c;
      }
      FUN_fffffff00a49d678(param_1,param_2,lVar21);
      bVar16 = param_2[1];
      if (bVar16 == 0x1e) {
        if ((*(int *)(param_2 + 8) == 0) && (*(int *)(param_2 + 0xc) == 0)) {
          if ((*(int *)(param_2 + 0x10) == 0) && (*(int *)(param_2 + 0x14) == 0))
          goto LAB_fffffff00a49ccc8;
LAB_fffffff00a49ce54:
          if ((*(int *)(param_2 + 0x10) == 0) && (*(int *)(param_2 + 0x14) == 0)) {
LAB_fffffff00a49ceb0:
            FUN_fffffff00a503978(0);
            bVar16 = param_2[1];
            goto LAB_fffffff00a49cbdc;
          }
        }
LAB_fffffff00a49ce64:
        if (lVar21 == 0) goto LAB_fffffff00a49c5a0;
      }
      else {
        if (bVar16 == 2) {
          if (*(int *)(param_2 + 4) == 0) {
LAB_fffffff00a49ccc8:
            if (((*(byte *)(param_1 + 0x77) & 1) == 0) && (*(long *)(param_1 + 0x88) != 0)) {
              puVar2 = &DAT_fffffff00adcac10;
              if (bVar16 != 2) {
                puVar2 = &DAT_fffffff00adcac14;
              }
              *puVar2 = (uint)*(ushort *)(*(long *)(param_1 + 0x88) + 0xcc);
            }
            if (bVar16 == 0x1e) {
              if ((*(int *)(param_2 + 8) == 0) && (*(int *)(param_2 + 0xc) == 0))
              goto LAB_fffffff00a49ce54;
              goto LAB_fffffff00a49ce64;
            }
            if (bVar16 != 2) goto LAB_fffffff00a49cbdc;
            if (*(int *)(param_2 + 4) == 0) goto LAB_fffffff00a49ceb0;
          }
          bVar16 = 2;
        }
LAB_fffffff00a49cbdc:
        if ((bVar16 != 2) || (lVar21 == 0)) goto LAB_fffffff00a49ce64;
        uVar22 = *(ulong *)(lVar21 + 0x80);
        if (((*(char *)(uVar22 + 1) == '\x12') &&
            (((DAT_fffffff00adcac10 == *(ushort *)(*(long *)(lVar21 + 0x88) + 0xcc) ||
              (DAT_fffffff00adcac10 == 0)) &&
             (lVar20 = uVar22 + *(byte *)(uVar22 + 5), uVar15 = lVar20 + 8, lVar20 != -8)))) &&
           ((uVar22 + 0xff <= uVar15 || (uVar15 < uVar22)))) goto LAB_fffffff00a49c850;
      }
      FUN_fffffff00a49df74(lVar21,1);
      FUN_fffffff00a49e4c4(lVar21);
      FUN_fffffff00a49deb4(lVar21);
    }
LAB_fffffff00a49c5a0:
    uVar18 = -uVar18 & 0xffffffffffffffe0;
    pbVar10 = *(byte **)(param_1 + 0x80);
    if (pbVar10 == (byte *)0x0) {
LAB_fffffff00a49c5e8:
      uVar22 = -((-uVar19 & 0xffffffffffffffe0) + uVar18);
      pbVar11 = (byte *)FUN_fffffff00a220c30(&DAT_fffffff007c6afb0,uVar22,4,0);
      if (pbVar11 == (byte *)0x0) {
        FUN_fffffff00a49d678(param_1,param_2,0);
        FUN_fffffff00a49e4c4(param_1);
        uVar17 = 0x37;
        goto LAB_fffffff00a49cc70;
      }
      pbVar23 = pbVar11 + uVar22;
      if ((((ulong)pbVar11 ^ (ulong)pbVar23) & 0xffc0000000000000) != 0) {
        pbVar23 = (byte *)((ulong)pbVar23 & 0xffffffffffff | 0xc8a2000000000000);
      }
      if (((param_2 + 0xff < param_2) || (pbVar23 < pbVar11)) ||
         ((ulong)((long)pbVar23 - (long)pbVar11) < (ulong)*param_2)) goto LAB_fffffff00a49c850;
      FUN_fffffff00aa65b10(pbVar11,param_2);
      uVar15 = *(ulong *)(param_1 + 0x18);
      if (uVar15 != 0) {
        if (((ulong)*(byte *)(param_1 + 0x14) < 2) || (uVar15 + *(byte *)(param_1 + 0x14) < uVar15))
        goto LAB_fffffff00a49c850;
        FUN_fffffff00a2214fc(&DAT_fffffff007c6afb0);
      }
      bVar16 = *param_2;
      if ((uVar22 < bVar16) || (*(byte *)(param_1 + 0x14) = bVar16, bVar16 == 0))
      goto LAB_fffffff00a49c850;
      *(byte **)(param_1 + 0x18) = pbVar11;
      pbVar10 = pbVar11 + -(-uVar19 & 0xffffffffffffffe0);
      if ((pbVar10 < pbVar11) || (pbVar23 < pbVar10)) goto LAB_fffffff00a49c850;
      *(byte **)(param_1 + 0x80) = pbVar10;
    }
    else {
      uVar22 = 0x14;
      if (pbVar10[1] != 0x12) {
        uVar22 = 0x20;
      }
      if (uVar22 <= *pbVar10) {
        uVar22 = (ulong)*pbVar10;
      }
      if (-(-uVar22 & 0xffffffffffffffe0) <= -uVar18 && (-uVar22 & 0xffffffffffffffe0) != uVar18)
      goto LAB_fffffff00a49c5e8;
    }
    if ((param_3 + 0xff < param_3) || (pbVar10 + 0xff < pbVar10)) goto LAB_fffffff00a49c850;
    FUN_fffffff00aa65b10(pbVar10,param_3,*param_3);
    pbVar10 = *(byte **)(param_1 + 0x80);
    if ((pbVar10[1] == 0x12) && (uVar19 = (ulong)pbVar10[5], uVar19 != 0)) {
      uStack_c8 = 0;
      local_d0 = 0;
      uStack_b8 = 0;
      uStack_c0 = 0;
      uStack_e8 = 0;
      local_f0 = 0;
      uStack_d8 = 0;
      uStack_e0 = 0;
      bVar16 = pbVar10[6];
      uVar22 = (ulong)bVar16;
      if (((0x40 < bVar16) || (uVar15 = uVar22 + 8, (ulong)*pbVar10 < uVar15 + uVar19)) ||
         (-uVar18 < uVar15)) {
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,&DAT_fffffff00ad98ba0,0x10,
                   "%s: rejecting AF_LINK gateway on index %u with unusable link address (nlen %u, alen %u, sdl_len %u)\n"
                  );
        FUN_fffffff00a49d678(param_1,param_2,0);
        FUN_fffffff00a49e4c4(param_1);
        goto LAB_fffffff00a49c760;
      }
      if (pbVar10 + 0x14 <= pbVar10) goto LAB_fffffff00a49c850;
      pbVar11 = pbVar10 + 8;
      pbVar23 = pbVar11 + uVar19;
      if (((pbVar10 + 0xff < pbVar23) || (pbVar23 < pbVar10)) || (0xf7 - uVar19 < uVar22))
      goto LAB_fffffff00a49c850;
      FUN_fffffff00aa65b10(&local_f0,pbVar23,uVar22);
      pbVar10[5] = 0;
      pbVar10[7] = 0;
      if (uVar15 < 0x15) {
        uVar15 = 0x14;
      }
      *pbVar10 = (byte)uVar15;
      if (0xc < uVar15 - 8) goto LAB_fffffff00a49c850;
      pbVar10[0x10] = 0;
      pbVar10[0x11] = 0;
      pbVar10[0x12] = 0;
      pbVar10[0x13] = 0;
      pbVar11[0] = 0;
      pbVar11[1] = 0;
      pbVar11[2] = 0;
      pbVar11[3] = 0;
      pbVar11[4] = 0;
      pbVar11[5] = 0;
      pbVar11[6] = 0;
      pbVar11[7] = 0;
      if (bVar16 != 0) {
        if ((pbVar10 + 0xff < pbVar11) || (pbVar11 < pbVar10)) goto LAB_fffffff00a49c850;
        FUN_fffffff00aa65b10(pbVar11,&local_f0,uVar22);
      }
    }
    if ((((*(byte *)(param_1 + 0x74) >> 1 & 1) != 0) &&
        (lVar20 = *(long *)(param_1 + 0x108), lVar20 != 0)) && ((*(byte *)(lVar20 + 0x77) & 1) != 0)
       ) {
      lVar21 = *(long *)(param_1 + 0x80);
      if (*(char *)(lVar21 + 1) == '\x1e') {
        uVar19 = *(ulong *)(lVar20 + 0x18);
        cVar3 = cRam0000000000000001;
        if (uVar19 != 0) {
          if (((ulong)*(byte *)(lVar20 + 0x14) < 2) || (uVar19 + *(byte *)(lVar20 + 0x14) < uVar19))
          goto LAB_fffffff00a49c850;
          cVar3 = *(char *)(uVar19 + 1);
        }
        if (cVar3 == '\x1e') {
          uVar14 = FUN_fffffff00a497a94();
          FUN_fffffff00a49e62c(lVar21,uVar14);
        }
      }
      else if (*(char *)(lVar21 + 1) == '\x02') {
        uVar19 = *(ulong *)(lVar20 + 0x18);
        cVar3 = cRam0000000000000001;
        if (uVar19 != 0) {
          if (((ulong)*(byte *)(lVar20 + 0x14) < 2) || (uVar19 + *(byte *)(lVar20 + 0x14) < uVar19))
          goto LAB_fffffff00a49c850;
          cVar3 = *(char *)(uVar19 + 1);
        }
        if (cVar3 == '\x02') {
          uVar14 = FUN_fffffff00a497a38();
          FUN_fffffff00a4979dc(lVar21,uVar14);
        }
      }
    }
    if (((*(byte *)(param_1 + 0x74) >> 2 & 1) == 0) &&
       (uVar19 = *(ulong *)(param_1 + 0x20), uVar19 != 0)) {
      if (((ulong)*(byte *)(param_1 + 0x15) < 2) ||
         ((uVar19 + *(byte *)(param_1 + 0x15) < uVar19 ||
          (local_f0 = param_1, uStack_e8 = uVar24, FUN_fffffff00a49deb4(param_1),
          uVar24 + 0x108 <= uVar24)))) {
LAB_fffffff00a49c850:
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a49c854);
        (*pcVar4)();
      }
      uVar19 = *(ulong *)(param_1 + 0x18);
      if (((uVar19 != 0) &&
          (((ulong)*(byte *)(param_1 + 0x14) < 2 || (uVar19 + *(byte *)(param_1 + 0x14) < uVar19))))
         || ((uVar18 = *(ulong *)(param_1 + 0x20), uVar18 != 0 &&
             (((ulong)*(byte *)(param_1 + 0x15) < 2 || (uVar18 + *(byte *)(param_1 + 0x15) < uVar18)
              ))))) goto LAB_fffffff00a49c850;
      (**(code **)(uVar24 + 0x60))(uVar24,uVar19,uVar18,FUN_fffffff00a49e068,&local_f0);
      FUN_fffffff00a49df74(param_1,0);
    }
    FUN_fffffff00a49e4c4(param_1);
    uVar17 = 0;
  }
  else {
LAB_fffffff00a49c760:
    uVar17 = 0x16;
  }
LAB_fffffff00a49cc70:
  if (DAT_fffffff00ad30000 == local_70) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590(uVar17);
}

