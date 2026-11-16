// FUN_fffffff00a538418 @ fffffff00a538418 size=2236

undefined8 FUN_fffffff00a538418(ulong *param_1,undefined8 param_2,long param_3,long param_4)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  ulong uVar5;
  code *pcVar6;
  bool bVar7;
  int iVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  uint uVar12;
  undefined8 uVar13;
  undefined4 *puVar14;
  ulong uVar15;
  int *piVar16;
  long lVar17;
  uint *puVar18;
  undefined8 *puVar19;
  ulong *puVar20;
  long lVar21;
  ushort *puVar22;
  undefined8 *puVar23;
  undefined8 *puVar24;
  long lVar25;
  long lVar26;
  long lVar27;
  long *plVar28;
  undefined4 uVar29;
  undefined4 *puVar30;
  ulong uVar31;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined4 uStack_110;
  undefined4 local_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined4 uStack_e8;
  undefined4 local_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  ulong uStack_d0;
  undefined8 uStack_c8;
  ulong local_c0;
  ulong uStack_b8;
  undefined4 uStack_b0;
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  ulong uStack_98;
  ulong uStack_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  ulong local_70;
  undefined8 uStack_68;
  
  puVar30 = *(undefined4 **)(param_4 + 0x18);
  if (*(long *)(param_4 + 0x28) == 0 && puVar30 != (undefined4 *)0x0) goto LAB_fffffff00a538cd0;
  uStack_78 = 0;
  uStack_74 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_68 = 0;
  uStack_98 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  local_88 = 0;
  local_84 = 0;
  uStack_90 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  uStack_a8 = 0;
  uStack_a4 = 0;
  uStack_b0 = 0;
  local_ac = 0;
  bVar2 = *(byte *)(param_4 + 0xba);
  uVar12 = (uint)param_2;
  if (uVar12 == 1) {
    local_70._0_2_ = (ushort)bVar2 << 8;
    local_70 = (ulong)CONCAT12(0x32,(short)local_70);
    puVar19 = *(undefined8 **)(param_4 + 0x78);
    if (bVar2 == 0x1e) {
      if (puVar19 + 2 < puVar19) goto LAB_fffffff00a538cd0;
      uStack_7c = (undefined4)puVar19[1];
      uStack_78 = (undefined4)((ulong)puVar19[1] >> 0x20);
      local_84 = (undefined4)*puVar19;
      uStack_80 = (undefined4)((ulong)*puVar19 >> 0x20);
      puVar19 = *(undefined8 **)(param_4 + 0x80);
      if (puVar19 + 2 < puVar19) goto LAB_fffffff00a538cd0;
      uStack_a4 = (undefined4)puVar19[1];
      uStack_a0 = (undefined4)((ulong)puVar19[1] >> 0x20);
      local_ac = (undefined4)*puVar19;
      uStack_a8 = (undefined4)((ulong)*puVar19 >> 0x20);
    }
    else if (bVar2 == 2) {
      if ((undefined8 *)((long)puVar19 + 4U) < puVar19) goto LAB_fffffff00a538cd0;
      local_84 = *(undefined4 *)puVar19;
      puVar14 = *(undefined4 **)(param_4 + 0x80);
      if (puVar14 + 1 < puVar14) goto LAB_fffffff00a538cd0;
      local_ac = *puVar14;
    }
    uStack_9c = *puVar30;
    uVar9 = FUN_fffffff00a53ac88(param_3,&local_c0,1);
    *param_1 = uVar9;
    if (uVar9 != 0) goto LAB_fffffff00a538688;
    uStack_9c = 0;
    uVar10 = FUN_fffffff00a53ac88(param_3,&local_c0,1);
    if (uVar10 != 0) {
      uVar9 = *(ulong *)(uVar10 + 0xd0);
      FUN_fffffff00a529dc4(&DAT_fffffff00ad7cee0,uVar9);
      if (((uVar9 != 0) && (*(char *)(uVar9 + 0x50) == '\x1e')) &&
         (*(char *)(uVar9 + 0x51) == '\x02')) {
        DAT_fffffff00adce6a0 = DAT_fffffff00adce6a0 + -1;
      }
      uVar29 = *puVar30;
      *(undefined4 *)(uVar9 + 0x24) = uVar29;
      *(undefined4 *)(uVar9 + 0x10) = uVar29;
      if (uVar9 + 0xb0 <= uVar9) goto LAB_fffffff00a538cd0;
      uVar31 = uVar10 + 0x148;
      uVar5 = DAT_fffffff00ad7cee0;
      if (DAT_fffffff00ad7cee0 != 0) {
LAB_fffffff00a538604:
        while( true ) {
          uVar15 = uVar5;
          iVar8 = FUN_fffffff00a529f2c(uVar9,uVar15);
          if (iVar8 < 0) goto LAB_fffffff00a5385fc;
          if (iVar8 == 0) break;
          uVar5 = *(ulong *)(uVar15 + 0x88);
          if (*(ulong *)(uVar15 + 0x88) == 0) {
            *(undefined8 *)(uVar9 + 0x80) = 0;
            *(undefined8 *)(uVar9 + 0x88) = 0;
            *(ulong *)(uVar9 + 0x90) = uVar15 | 1;
            *(ulong *)(uVar15 + 0x88) = uVar9;
            goto LAB_fffffff00a538a04;
          }
        }
        if (uVar10 < uVar31) {
          uVar13 = 2;
LAB_fffffff00a5389e0:
          FUN_fffffff00a52b520(uVar10,uVar13);
          uVar9 = *param_1;
          uVar5 = uVar10;
          goto joined_r0xfffffff00a5389ec;
        }
        goto LAB_fffffff00a538cd0;
      }
      *(undefined8 *)(uVar9 + 0x80) = 0;
      *(undefined8 *)(uVar9 + 0x88) = 0;
      *(undefined8 *)(uVar9 + 0x90) = 1;
      DAT_fffffff00ad7cee0 = uVar9;
      goto LAB_fffffff00a538a04;
    }
LAB_fffffff00a538cb4:
    uVar9 = *param_1;
LAB_fffffff00a538cb8:
    if (uVar9 != 0) goto LAB_fffffff00a538688;
  }
  else {
    local_70 = (ulong)CONCAT21(0x3200,bVar2);
    puVar20 = *(ulong **)(param_4 + 0x78);
    if (bVar2 == 0x1e) {
      if (puVar20 + 2 < puVar20) goto LAB_fffffff00a538cd0;
      uStack_b8 = puVar20[1];
      local_c0 = *puVar20;
      puVar20 = *(ulong **)(param_4 + 0x80);
      if (puVar20 + 2 < puVar20) goto LAB_fffffff00a538cd0;
      uStack_90 = puVar20[1];
      uStack_98 = *puVar20;
    }
    else if (bVar2 == 2) {
      if ((ulong *)((long)puVar20 + 4U) < puVar20) goto LAB_fffffff00a538cd0;
      local_c0 = (ulong)(uint)*puVar20;
      puVar18 = *(uint **)(param_4 + 0x80);
      if (puVar18 + 1 < puVar18) goto LAB_fffffff00a538cd0;
      uStack_98 = (ulong)*puVar18;
    }
    local_88 = *puVar30;
    uVar9 = FUN_fffffff00a53ac88(param_3,&local_c0,param_2);
    *param_1 = uVar9;
    if (uVar9 == 0) {
      local_88 = 0;
      uVar10 = FUN_fffffff00a53ac88(param_3,&local_c0,param_2);
      if (uVar10 != 0) {
        uVar9 = *(ulong *)(uVar10 + 0xd0);
        FUN_fffffff00a5291c4(&DAT_fffffff00ad7ced8,uVar9);
        *(undefined4 *)(uVar9 + 0x38) = *puVar30;
        if (uVar9 + 0xb0 <= uVar9) goto LAB_fffffff00a538cd0;
        uVar31 = uVar10 + 0x148;
        uVar5 = DAT_fffffff00ad7ced8;
        if (DAT_fffffff00ad7ced8 == 0) {
          *(undefined8 *)(uVar9 + 0x68) = 0;
          *(undefined8 *)(uVar9 + 0x70) = 0;
          *(undefined8 *)(uVar9 + 0x78) = 1;
          DAT_fffffff00ad7ced8 = uVar9;
        }
        else {
          do {
            while (uVar15 = uVar5, iVar8 = FUN_fffffff00a52932c(uVar9,uVar15), iVar8 < 0) {
              uVar5 = *(ulong *)(uVar15 + 0x68);
              if (*(ulong *)(uVar15 + 0x68) == 0) {
                *(undefined8 *)(uVar9 + 0x68) = 0;
                *(undefined8 *)(uVar9 + 0x70) = 0;
                *(ulong *)(uVar9 + 0x78) = uVar15 | 1;
                *(ulong *)(uVar15 + 0x68) = uVar9;
                goto LAB_fffffff00a538a50;
              }
            }
            if (iVar8 == 0) {
              if (uVar31 <= uVar10) goto LAB_fffffff00a538cd0;
              uVar13 = 1;
              goto LAB_fffffff00a5389e0;
            }
            uVar5 = *(ulong *)(uVar15 + 0x70);
          } while (*(ulong *)(uVar15 + 0x70) != 0);
          *(undefined8 *)(uVar9 + 0x68) = 0;
          *(undefined8 *)(uVar9 + 0x70) = 0;
          *(ulong *)(uVar9 + 0x78) = uVar15 | 1;
          *(ulong *)(uVar15 + 0x70) = uVar9;
        }
LAB_fffffff00a538a50:
        FUN_fffffff00a528a64(&DAT_fffffff00ad7ced8,uVar9);
        goto LAB_fffffff00a538a60;
      }
      uVar9 = *param_1;
      if ((uVar12 == 2) && (uVar9 == 0)) {
        uStack_d8 = 0;
        uStack_d4 = 0;
        uStack_e0 = 0;
        uStack_dc = 0;
        uStack_c8 = 0;
        uStack_f8 = 0;
        uStack_100 = 0;
        uStack_fc = 0;
        uStack_e8 = 0;
        local_e4 = 0;
        uStack_f0 = 0;
        uStack_118 = 0;
        local_120 = 0;
        uStack_108 = 0;
        uStack_104 = 0;
        uStack_110 = 0;
        local_10c = 0;
        bVar2 = *(byte *)(param_4 + 0xba);
        uStack_d0._0_2_ = (ushort)bVar2 << 8;
        uStack_d0 = (ulong)CONCAT12(0x32,(short)uStack_d0);
        puVar19 = *(undefined8 **)(param_4 + 0x78);
        if (bVar2 == 0x1e) {
          if (puVar19 + 2 < puVar19) goto LAB_fffffff00a538cd0;
          uStack_104 = (undefined4)puVar19[1];
          uStack_100 = (undefined4)((ulong)puVar19[1] >> 0x20);
          local_10c = (undefined4)*puVar19;
          uStack_108 = (undefined4)((ulong)*puVar19 >> 0x20);
          puVar19 = *(undefined8 **)(param_4 + 0x80);
          if (puVar19 + 2 < puVar19) goto LAB_fffffff00a538cd0;
          uStack_dc = (undefined4)puVar19[1];
          uStack_d8 = (undefined4)((ulong)puVar19[1] >> 0x20);
          local_e4 = (undefined4)*puVar19;
          uStack_e0 = (undefined4)((ulong)*puVar19 >> 0x20);
        }
        else if (bVar2 == 2) {
          if ((undefined8 *)((long)puVar19 + 4U) < puVar19) goto LAB_fffffff00a538cd0;
          local_10c = *(undefined4 *)puVar19;
          puVar30 = *(undefined4 **)(param_4 + 0x80);
          if (puVar30 + 1 < puVar30) goto LAB_fffffff00a538cd0;
          local_e4 = *puVar30;
        }
        lVar17 = FUN_fffffff00a53ac88(param_3,&local_120,1);
        if ((lVar17 != 0) && (*(char *)(lVar17 + 0x136) != '\x1c')) {
          FUN_fffffff00a52bd28();
        }
        goto LAB_fffffff00a538cb4;
      }
      goto LAB_fffffff00a538cb8;
    }
LAB_fffffff00a538688:
    if ((*(uint *)(param_4 + 200) & 1) == 0) {
      *(undefined4 *)(param_4 + 0xcc) = *(undefined4 *)(*(long *)(uVar9 + 0xd0) + 0x60);
      iVar8 = *(int *)(*(long *)(*param_1 + 0xd0) + 100);
      *(int *)(param_4 + 0xd0) = iVar8;
      if (iVar8 != 0) {
        *(uint *)(param_4 + 200) = *(uint *)(param_4 + 200) & 0xfffffffc | 1;
      }
    }
  }
  uVar9 = *param_1;
  if (uVar9 == 0) {
    return 1;
  }
  if (*(char *)(uVar9 + 0x136) == '\x1b') {
    return 1;
  }
  if (uVar12 == 2) {
    lVar17 = *(long *)(uVar9 + 0x98);
    if (*(char *)(lVar17 + 0x3fd) == '\x04') {
      if (*(char *)(lVar17 + 0x3ed) == '\x01') {
LAB_fffffff00a538824:
        if ((*(long *)(uVar9 + 0xe0) != 0) && (*(long *)(uVar9 + 0xe0) != param_3)) {
          return 0;
        }
      }
    }
    else if ((*(char *)(lVar17 + 0x3fd) == '\x02') && (*(char *)(lVar17 + 0x3ed) == '\x02'))
    goto LAB_fffffff00a538824;
  }
  bVar7 = uVar12 != *(byte *)(*(long *)(uVar9 + 0xd0) + 0x53);
  lVar17 = 0x70;
  if (bVar7) {
    lVar17 = 0x48;
  }
  lVar11 = 0x48;
  if (bVar7) {
    lVar11 = 0x70;
  }
  lVar11 = uVar9 + lVar11;
  if (*(char *)(lVar11 + 0xe) == '\0') {
    *(undefined1 *)(lVar11 + 0xe) = 1;
  }
  lVar21 = tpidr_el1;
  lVar27 = *(long *)(*(long *)(lVar21 + 0x1b8) + 0x58);
  do {
    lVar26 = lVar27;
    lVar25 = UnkSytemRegRead(3,4,0xf,10,6);
    lVar27 = *(long *)(*(long *)(lVar21 + 0x1b8) + 0x58);
  } while (lVar27 != lVar26);
  uVar10 = 0;
  if ((ulong)DAT_fffffff00ad08000 != 0) {
    uVar10 = (ulong)(lVar25 + lVar26) / (ulong)DAT_fffffff00ad08000;
  }
  *(ulong *)(*param_1 + 0x120) = uVar10;
  if ((*(char *)(lVar11 + 0xe) == '\0') || (*(char *)(uVar9 + lVar17 + 0xe) == '\0')) {
    *(undefined1 *)(*param_1 + 0x136) = 0xf;
  }
  else {
    *(undefined1 *)(*param_1 + 0x136) = 0x10;
    *(undefined1 *)(lVar11 + 0xe) = 2;
    *(undefined1 *)(uVar9 + lVar17 + 0xe) = 2;
  }
  piVar16 = *(int **)(*param_1 + 0xd0);
  if (*piVar16 == piVar16[5]) {
    if ((char)piVar16[0x14] != '\x1e') {
      return 0;
    }
    if (((piVar16[1] == piVar16[6]) && (piVar16[2] == piVar16[7])) && (piVar16[3] == piVar16[8])) {
      return 0;
    }
  }
  uVar1 = *(uint *)(param_4 + 0x98);
  if ((int)uVar1 < 0) {
    return 1;
  }
  lVar17 = *(long *)(param_4 + 0x90);
  if (*(long *)(lVar17 + 0x58) == 0) {
    if (0x27 < uVar1) {
      return 1;
    }
LAB_fffffff00a538964:
    lVar11 = FUN_fffffff00a5562d0(lVar17,0x28);
    uVar29 = 0x28;
    if (lVar11 == 0) {
      uVar29 = 0xffffffff;
    }
    *(undefined4 *)(param_4 + 0x98) = uVar29;
    if (lVar11 == 0) {
      return 1;
    }
    *(undefined8 *)(param_4 + 0xa0) = *(undefined8 *)(lVar17 + 0xa0);
    cVar3 = *(char *)(param_4 + 0xba);
    if (cVar3 == '\x1e') {
      lVar17 = 0x80;
      lVar21 = 0x18;
      lVar27 = 0x78;
      lVar25 = 8;
LAB_fffffff00a538b60:
      *(long *)(param_4 + lVar27) = lVar11 + lVar25;
      *(long *)(param_4 + lVar17) = lVar11 + lVar21;
      goto LAB_fffffff00a538b70;
    }
    if (cVar3 == '\x02') {
      *(long *)(param_4 + 0x78) = lVar11 + 0xc;
      lVar17 = 0xa8;
      lVar21 = 10;
      lVar27 = 0x80;
      lVar25 = 0x10;
      goto LAB_fffffff00a538b60;
    }
  }
  else {
    if (*(int *)(lVar17 + 100) == 0) goto LAB_fffffff00a538cd0;
    if (uVar1 < 0x28) goto LAB_fffffff00a538964;
LAB_fffffff00a538b70:
    cVar3 = *(char *)(param_4 + 0xba);
  }
  if (uVar12 == 2) {
    if (cVar3 != '\x1e') {
      if (cVar3 != '\x02') {
        return 0;
      }
      puVar18 = *(uint **)(param_4 + 0x78);
      puVar22 = *(ushort **)(param_4 + 0xa8);
      uVar12 = *(uint *)(*(long *)(*param_1 + 0xd0) + 0x14);
LAB_fffffff00a538bd0:
      uVar1 = *puVar18;
      *puVar18 = uVar12;
      uVar4 = ((uint)*puVar22 + (uVar1 >> 0x10)) - (uVar12 >> 0x10);
      iVar8 = ((uVar1 & 0xffff) + (uVar4 + (uVar4 >> 0x10) & 0xffff)) - (uVar12 & 0xffff);
      *puVar22 = (short)iVar8 + (short)((uint)iVar8 >> 0x10);
      return 0;
    }
    puVar19 = *(undefined8 **)(param_4 + 0x78);
    if (puVar19 + 2 < puVar19) goto LAB_fffffff00a538cd0;
    puVar23 = (undefined8 *)(*(long *)(*param_1 + 0xd0) + 0x14);
    puVar24 = (undefined8 *)(*(long *)(*param_1 + 0xd0) + 0x24);
  }
  else {
    if (cVar3 != '\x1e') {
      if (cVar3 != '\x02') {
        return 0;
      }
      puVar18 = *(uint **)(param_4 + 0x80);
      puVar22 = *(ushort **)(param_4 + 0xa8);
      uVar12 = **(uint **)(*param_1 + 0xd0);
      goto LAB_fffffff00a538bd0;
    }
    puVar19 = *(undefined8 **)(param_4 + 0x80);
    if (puVar19 + 2 < puVar19) goto LAB_fffffff00a538cd0;
    puVar23 = *(undefined8 **)(*param_1 + 0xd0);
    puVar24 = puVar23 + 2;
  }
  if (puVar23 <= puVar24) {
    uVar13 = *puVar23;
    puVar19[1] = puVar23[1];
    *puVar19 = uVar13;
    return 0;
  }
LAB_fffffff00a538cd0:
                    /* WARNING: Does not return */
  pcVar6 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a538cd4);
  (*pcVar6)();
LAB_fffffff00a5385fc:
  uVar5 = *(ulong *)(uVar15 + 0x80);
  if (*(ulong *)(uVar15 + 0x80) == 0) goto LAB_fffffff00a5389f4;
  goto LAB_fffffff00a538604;
LAB_fffffff00a5389f4:
  *(undefined8 *)(uVar9 + 0x80) = 0;
  *(undefined8 *)(uVar9 + 0x88) = 0;
  *(ulong *)(uVar9 + 0x90) = uVar15 | 1;
  *(ulong *)(uVar15 + 0x80) = uVar9;
LAB_fffffff00a538a04:
  FUN_fffffff00a529664(&DAT_fffffff00ad7cee0,uVar9);
  if ((*(char *)(uVar9 + 0x50) == '\x1e') && (*(char *)(uVar9 + 0x51) == '\x02')) {
    DAT_fffffff00adce6a0 = DAT_fffffff00adce6a0 + 1;
  }
LAB_fffffff00a538a60:
  if (uVar31 <= uVar10) goto LAB_fffffff00a538cd0;
  *param_1 = uVar10;
  uVar5 = 0;
  uVar9 = uVar10;
joined_r0xfffffff00a5389ec:
  if (uVar9 == 0) {
    if ((uVar5 + 0x148 <= uVar31) && (*(undefined1 *)(uVar5 + 0x136) = 0x1c, uVar5 < uVar31)) {
      plVar28 = *(long **)(uVar5 + 0xc0);
      do {
        if (plVar28 == (long *)0x0) {
          FUN_fffffff00a52a8e8(&DAT_fffffff00ad7d010,uVar5);
          FUN_fffffff00a52c628(uVar5);
          FUN_fffffff00a52be64(uVar5);
          return 1;
        }
        lVar17 = *plVar28;
        if (lVar17 == 0) {
          if (*(long **)plVar28[1] != plVar28) goto LAB_fffffff00a538cc0;
          *(undefined8 **)(uVar5 + 200) = (undefined8 *)plVar28[1];
        }
        else {
          if (*(long **)(lVar17 + 8) != plVar28) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a538cd0);
            (*pcVar6)();
          }
          if (*(long **)plVar28[1] != plVar28) {
LAB_fffffff00a538cc0:
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00a538cc8);
            (*pcVar6)();
          }
          *(undefined8 **)(lVar17 + 8) = (undefined8 *)plVar28[1];
        }
        *(long *)plVar28[1] = *plVar28;
        (*(code *)plVar28[2])(plVar28[3]);
        FUN_fffffff00a29762c(&DAT_fffffff007c73ad0,plVar28);
        plVar28 = *(long **)(uVar5 + 0xc0);
      } while( true );
    }
    goto LAB_fffffff00a538cd0;
  }
  goto LAB_fffffff00a538688;
}

