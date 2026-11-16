// FUN_fffffff00816edd0 @ fffffff00816edd0 size=10444

/* WARNING: Removing unreachable block (ram,0xfffffff008170f54) */
/* WARNING: Removing unreachable block (ram,0xfffffff008170ad4) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081706a0) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816fde4) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816faa8) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816fa34) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816f894) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816f57c) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816f29c) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816f1d4) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816f154) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816f110) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816f194) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816f214) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816f390) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816f7b0) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816f9f8) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816fa6c) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816fb70) */
/* WARNING: Removing unreachable block (ram,0xfffffff008170664) */
/* WARNING: Removing unreachable block (ram,0xfffffff008170a98) */
/* WARNING: Removing unreachable block (ram,0xfffffff008170f1c) */
/* WARNING: Removing unreachable block (ram,0xfffffff008170f94) */
/* WARNING: Removing unreachable block (ram,0xfffffff00816f020) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff00816edd0(long *param_1,long *param_2)

{
  ulong *puVar1;
  ulong *puVar2;
  byte *pbVar3;
  uint *puVar4;
  undefined8 *puVar5;
  uint uVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  bool bVar11;
  byte bVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  long *plVar16;
  uint *puVar17;
  undefined4 *puVar18;
  undefined8 uVar19;
  long lVar20;
  long lVar21;
  long *plVar22;
  long *plVar23;
  long *plVar24;
  long *plVar25;
  int *piVar26;
  uint uVar27;
  int iVar28;
  long lVar29;
  uint uVar30;
  ulong uVar31;
  undefined *puVar32;
  ulong uVar33;
  ulong uVar34;
  long lVar35;
  long lVar36;
  undefined8 uVar37;
  undefined4 local_74;
  ulong local_70 [2];
  
  local_70[0] = 0;
  local_74 = 0;
  thunk_EXT_FUN_8011000003203330(local_70,&local_74);
  lVar35 = (ulong)(DAT_fffffff00ae21b18 % 0x13) * 0x10;
  puVar18 = (undefined4 *)((long)(int)lVar35 + -0xff51de618);
  if (lVar35 != (int)lVar35) {
    puVar18 = (undefined4 *)(lVar35 - 0xff51de618U & 0xffffffffffff | 0x2bad000000000000);
  }
  uVar31 = local_70[0] - 0x6270;
  puVar18[3] = local_74;
  auVar7._8_8_ = 0;
  auVar7._0_8_ = uVar31;
  uVar15 = (int)uVar31 + SUB164(auVar7 * ZEXT816(0xc22e450672894ab7),10) * -0x15180;
  *(char *)(puVar18 + 2) = (char)uVar15 + (char)(uVar15 / 0x3c) * -0x3c;
  *(char *)((long)puVar18 + 7) =
       (char)(uVar15 / 0x3c) + (char)((uVar15 / 0x3c) * 0x8889 >> 0x15) * -0x3c;
  *(char *)((long)puVar18 + 6) = (char)(uVar15 / 0xe10);
  uVar31 = uVar31 / 0x15180 + 0x2db;
  uVar33 = uVar31 % 0x5b5;
  uVar31 = (uVar31 / 0x5b5) * 4 + 0x7b0;
  uVar30 = (int)uVar33 - 0x16e;
  uVar15 = (uVar30 & 0xffff) / 0x16d;
  puVar32 = &UNK_fffffff007115d18;
  if (0x16d < uVar33) {
    uVar31 = uVar31 + (uVar15 + 1);
    uVar33 = (ulong)(uVar30 + uVar15 * -0x16d) & 0xffff;
    puVar32 = &UNK_fffffff007115ce4;
  }
  if (uVar31 < 0x834) {
    uVar34 = 0;
    *puVar18 = (int)uVar31;
    lVar35 = 1;
    do {
      uVar34 = uVar34 + 1;
      lVar20 = lVar35 * 4;
      lVar35 = lVar35 + 1;
    } while (*(uint *)(puVar32 + lVar20) <= uVar33 && uVar34 < 0xc);
    *(char *)(puVar18 + 1) = (char)uVar34;
    *(char *)((long)puVar18 + 5) =
         ((char)uVar33 - (char)*(undefined4 *)(puVar32 + uVar34 * 4 + -4)) + '\x01';
  }
  (**(code **)(*param_1 + 0x38))(param_1);
  thunk_EXT_FUN_8011000003891b28();
  lVar35 = DAT_fffffff007113e60;
  DAT_fffffff00ae21b18 = DAT_fffffff00ae21b18 + 1;
  *(undefined4 *)(param_1 + 200) = 3;
  param_1[199] = lVar35;
  param_1[0xb9] = param_1[0xb9] & 0xffffffffbfffffffU | 1;
  bVar12 = (**(code **)(*param_1 + 0x8c0))(*param_1 + 0x8c0,param_1);
  bVar11 = (DAT_fffffff00ae22cf1 & 0x10) == 0;
  uVar31 = 2;
  if ((bVar12 & bVar11) == 0) {
    uVar31 = 0;
  }
  uVar33 = 0x100;
  if ((param_1[0xb9] & 0x40000000U) != 0 || !bVar11) {
    uVar33 = 0;
  }
  *(undefined4 *)(param_1 + 0xc0) = 4;
  *(undefined8 *)((long)param_1 + 0x5f4) = 0;
  *(undefined2 *)((long)param_1 + 0x654) = 0x528;
  *(undefined4 *)(param_1 + 0xcb) = 0x50;
  *(undefined2 *)((long)param_1 + 0x65c) = 5;
  *(undefined1 *)((long)param_1 + 0x66c) = 100;
  lVar35 = _DAT_fffffff0071136d0;
  param_1[0xc3] = _UNK_fffffff0071136d8;
  param_1[0xc2] = lVar35;
  *(undefined4 *)((long)param_1 + 0x62c) = 3;
  param_1[0xc6] = DAT_fffffff007113e68;
  *(undefined4 *)(param_1 + 0x20b8) = 0;
  *(undefined1 *)((long)param_1 + 0x65e) = 0;
  *(undefined4 *)(param_1 + 0xcd) = 0;
  param_1[0xcc] = 0;
  param_1[0x212e] = 0;
  param_1[0xb9] = param_1[0xb9] & 0xffffffffff061281U | uVar33 | uVar31 | 4;
  uVar13 = (**(code **)(*param_1 + 0xc60))(*param_1 + 0xc60,param_1);
  *(undefined4 *)(param_1 + 0x212f) = uVar13;
  *(undefined4 *)((long)param_1 + 0x1097c) = 0;
  uVar13 = (**(code **)(*param_1 + 0xc90))(*param_1 + 0xc90,param_1);
  *(undefined4 *)((long)param_1 + 0x10984) = uVar13;
  uVar13 = (**(code **)(*param_1 + 0xc78))(*param_1 + 0xc78,param_1);
  *(undefined4 *)(param_1 + 0x2130) = uVar13;
  uVar13 = (**(code **)(*param_1 + 0xc98))(*param_1 + 0xc98,param_1);
  *(undefined4 *)(param_1 + 0x2131) = uVar13;
  lVar35 = (**(code **)(*param_1 + 0xc00))(*param_1 + 0xc00,param_1);
  param_1[0x2122] = lVar35;
  param_1[0x2123] = 0;
  param_1[0x2127] = 0;
  param_1[0x2126] = 0;
  *(undefined4 *)(param_1 + 0x2125) = 1;
  param_1[0x2124] = 1;
  *(undefined2 *)(param_1 + 0x2128) = 0;
  *(undefined1 *)((long)param_1 + 0x10942) = 0;
  *(undefined4 *)((long)param_1 + 0x10944) = 1;
  *(undefined2 *)(param_1 + 0x2129) = 0;
  param_1[0xb9] = param_1[0xb9] & 0xfffffff140ffffff;
  *(undefined4 *)(param_1 + 0xbb) = 0;
  *(undefined4 *)((long)param_1 + 0x5fc) = 0;
  iVar14 = (**(code **)(*param_1 + 0xa08))(*param_1 + 0xa08,param_1);
  *(bool *)(param_1 + 0x2230) = iVar14 != 0;
  uVar19 = _DAT_fffffff0071136e0;
  *(undefined8 *)((long)param_1 + 0x109ec) = _UNK_fffffff0071136e8;
  *(undefined8 *)((long)param_1 + 0x109e4) = uVar19;
  param_1[0x2135] = 0;
  param_1[0x2134] = 0;
  *(undefined8 *)((long)param_1 + 0x624) = 0;
  *(undefined8 *)((long)param_1 + 0x109f4) = DAT_fffffff007113e70;
  *(undefined8 *)((long)param_1 + 0x10a14) = DAT_fffffff007113e78;
  uVar19 = DAT_fffffff007113e80;
  *(undefined1 *)(param_1 + 0x2141) = 0;
  *(undefined4 *)((long)param_1 + 0x10a0c) = 0;
  *(undefined4 *)((long)param_1 + 0x10a04) = 0;
  *(undefined2 *)(param_1 + 0x2136) = 0;
  *(undefined1 *)((long)param_1 + 0x10a8c) = 0;
  *(undefined8 *)((long)param_1 + 0x1094c) = 0;
  *(undefined1 *)(param_1 + 0x2142) = 0;
  *(undefined4 *)((long)param_1 + 0x5d4) = 0;
  *(int *)(param_1 + 0x214e) = (int)uVar19;
  *(undefined1 *)((long)param_1 + 0x10a1c) = 0;
  *(undefined1 *)((long)param_1 + 0x10a74) = 1;
  *(undefined1 *)((long)param_1 + 0x5e4) = 0;
  *(undefined2 *)(param_1 + 0xbd) = 0;
  *(undefined1 *)(param_1 + 0xbe) = 0;
  param_1[0xb9] = param_1[0xb9] & 0xfdf4800fffffff7fU | 0x200080000000000;
  (**(code **)(*param_1 + 0xa00))(*param_1 + 0xa00,param_1,param_1 + 0x2132);
  param_1[0x20bf] = 0;
  *(undefined4 *)(param_1 + 0x20c0) = 1;
  plVar25 = param_1 + 0x20c1;
  param_1[0x20c2] = 0;
  *plVar25 = 0;
  param_1[0x20c4] = 0;
  param_1[0x20c3] = 0;
  param_1[0x20c6] = 0;
  param_1[0x20c5] = 0;
  param_1[0x20c8] = 0;
  param_1[0x20c7] = 0;
  param_1[0x20ca] = 0;
  param_1[0x20c9] = 0;
  param_1[0x20cc] = 0;
  param_1[0x20cb] = 0;
  param_1[0x20ce] = 0;
  param_1[0x20cd] = 0;
  param_1[0x20d0] = 0;
  param_1[0x20cf] = 0;
  param_1[0x20d2] = 0;
  param_1[0x20d1] = 0;
  param_1[0x20d4] = 0;
  param_1[0x20d3] = 0;
  param_1[0x20d6] = 0;
  param_1[0x20d5] = 0;
  param_1[0x20d8] = 0;
  param_1[0x20d7] = 0;
  param_1[0x20da] = 0;
  param_1[0x20d9] = 0;
  param_1[0x20dc] = 0;
  param_1[0x20db] = 0;
  param_1[0x20de] = 0;
  param_1[0x20dd] = 0;
  param_1[0x20e0] = 0;
  param_1[0x20df] = 0;
  param_1[0x20e2] = 0;
  param_1[0x20e1] = 0;
  param_1[0x20e4] = 0;
  param_1[0x20e3] = 0;
  param_1[0x20e6] = 0;
  param_1[0x20e5] = 0;
  param_1[0x20e8] = 0;
  param_1[0x20e7] = 0;
  param_1[0x20ea] = 0;
  param_1[0x20e9] = 0;
  param_1[0x20ec] = 0;
  param_1[0x20eb] = 0;
  param_1[0x20ee] = 0;
  param_1[0x20ed] = 0;
  param_1[0x20f0] = 0;
  param_1[0x20ef] = 0;
  param_1[0x20f2] = 0;
  param_1[0x20f1] = 0;
  param_1[0x20f4] = 0;
  param_1[0x20f3] = 0;
  param_1[0x20f6] = 0;
  param_1[0x20f5] = 0;
  param_1[0x20f8] = 0;
  param_1[0x20f7] = 0;
  param_1[0x20fa] = 0;
  param_1[0x20f9] = 0;
  param_1[0x20fc] = 0;
  param_1[0x20fb] = 0;
  param_1[0x20fe] = 0;
  param_1[0x20fd] = 0;
  param_1[0x2100] = 0;
  param_1[0x20ff] = 0;
  param_1[0x2121] = 0;
  lVar35 = 0;
  if (param_1[0x77] == 0 && param_1[0x76] == 0) {
    lVar35 = 0x10;
  }
  puVar1 = (ulong *)((long)param_1 + lVar35 + 0x3b0);
  uVar31 = *puVar1;
  uVar33 = puVar1[1];
  if (uVar33 != 0 || uVar31 != 0) goto LAB_fffffff00816f504;
  uVar15 = *(uint *)(param_1 + 0x7c);
  local_70[0] = 0;
  local_70[1] = 0;
  uVar30 = uVar15 - 0x40;
  if (uVar15 < 0x40) {
    uVar34 = 0;
  }
  else {
    uVar34 = (ulong)((uVar30 >> 6) + 1);
    if (uVar30 < 0xc0) {
      uVar31 = 0;
LAB_fffffff00816f4a4:
      lVar35 = ((uVar30 >> 6) - uVar31) + 1;
      do {
        iVar14 = (int)(uVar31 * 8);
        puVar5 = (undefined8 *)((long)local_70 + (long)iVar14);
        if (uVar31 * 8 - (long)iVar14 != 0) {
          puVar5 = (undefined8 *)((ulong)(local_70 + uVar31) & 0xffffffffffff | 0x2bad000000000000);
        }
        *puVar5 = 0xffffffffffffffff;
        uVar31 = uVar31 + 1;
        lVar35 = lVar35 + -1;
      } while (lVar35 != 0);
    }
    else {
      lVar35 = 0;
      uVar31 = uVar34 & 0x7fffffc;
      uVar33 = uVar31;
      do {
        *(undefined8 *)(&stack0xffffffffffffffa8 + lVar35 * 8) = 0xffffffffffffffff;
        *(undefined8 *)(&stack0xffffffffffffffa0 + lVar35 * 8) = 0xffffffffffffffff;
        lVar35 = lVar35 + 4;
        uVar33 = uVar33 - 4;
      } while (uVar33 != 0);
      if (uVar31 != uVar34) goto LAB_fffffff00816f4a4;
    }
    uVar15 = uVar15 & 0x3f;
  }
  uVar31 = local_70[0];
  uVar33 = local_70[1];
  if (uVar15 != 0) {
    local_70[uVar34] = local_70[uVar34] | -1L << ((ulong)uVar15 & 0x3f) ^ 0xffffffffffffffffU;
    uVar31 = local_70[0];
    uVar33 = local_70[1];
  }
LAB_fffffff00816f504:
  lVar35 = (long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f));
  param_1[0x214f] =
       lVar35 + ((ulong)(byte)(POPCOUNT((char)uVar31) + POPCOUNT((char)(uVar31 >> 8)) +
                               POPCOUNT((char)(uVar31 >> 0x10)) + POPCOUNT((char)(uVar31 >> 0x18)) +
                               POPCOUNT((char)(uVar31 >> 0x20)) + POPCOUNT((char)(uVar31 >> 0x28)) +
                               POPCOUNT((char)(uVar31 >> 0x30)) + POPCOUNT((char)(uVar31 >> 0x38)))
                + (ulong)(byte)(POPCOUNT((char)uVar33) + POPCOUNT((char)(uVar33 >> 8)) +
                                POPCOUNT((char)(uVar33 >> 0x10)) + POPCOUNT((char)(uVar33 >> 0x18))
                                + POPCOUNT((char)(uVar33 >> 0x20)) +
                                POPCOUNT((char)(uVar33 >> 0x28)) + POPCOUNT((char)(uVar33 >> 0x30))
                               + POPCOUNT((char)(uVar33 >> 0x38)))) * 0x10c40 + 0x143 & -lVar35;
  lVar35 = *(long *)param_1[0x27];
  lVar35 = (**(code **)(lVar35 + 0x118))
                     (lVar35 + 0x118,(long *)param_1[0x27],"gpu-pwr-sample-period-aic-clks");
  puVar32 = PTR_DAT_fffffff007ca6090;
  if ((lVar35 == 0) ||
     (plVar16 = (long *)thunk_EXT_FUN_8011000003890f30
                                  (lVar35,*(undefined8 *)PTR_DAT_fffffff007ca6090),
     plVar16 == (long *)0x0)) {
    lVar35 = (**(code **)(*(long *)param_1[0x27] + 0x118))
                       ((long *)param_1[0x27],"gpu-power-sample-period");
    if ((lVar35 != 0) &&
       (plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,*(undefined8 *)puVar32),
       plVar16 != (long *)0x0)) {
      puVar18 = (undefined4 *)(**(code **)(*plVar16 + 0xd8))();
      *(undefined4 *)((long)param_1 + 0x10a14) = *puVar18;
    }
    *(int *)(param_1 + 0x2143) = *(int *)((long)param_1 + 0x10a14) * 24000;
  }
  else {
    puVar17 = (uint *)(**(code **)(*plVar16 + 0xd8))();
    uVar15 = *puVar17;
    *(uint *)(param_1 + 0x2143) = uVar15;
    *(uint *)((long)param_1 + 0x10a14) = uVar15 / 24000;
  }
  uVar19 = _DAT_fffffff0071136f0;
  *(undefined8 *)((long)param_1 + 0x10a54) = _UNK_fffffff0071136f8;
  *(undefined8 *)((long)param_1 + 0x10a4c) = uVar19;
  *(undefined4 *)((long)param_1 + 0x10aa4) = 100;
  lVar35 = (**(code **)(*(long *)param_1[0x27] + 0x118))
                     ((long *)param_1[0x27],"gpu-keepalive-perf-mode-threshold");
  if ((lVar35 != 0) &&
     (plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,*(undefined8 *)puVar32),
     plVar16 != (long *)0x0)) {
    puVar18 = (undefined4 *)(**(code **)(*plVar16 + 0xd8))();
    *(undefined4 *)((long)param_1 + 0x10aa4) = *puVar18;
  }
  *(undefined4 *)(param_1 + 0x2154) = 100;
  lVar35 = (**(code **)(*(long *)param_1[0x27] + 0x118))
                     ((long *)param_1[0x27],"gpu-keepalive-off-mode-threshold");
  if ((lVar35 != 0) &&
     (plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,*(undefined8 *)puVar32),
     plVar16 != (long *)0x0)) {
    puVar18 = (undefined4 *)(**(code **)(*plVar16 + 0xd8))();
    *(undefined4 *)(param_1 + 0x2154) = *puVar18;
  }
  bVar12 = 0;
  *(undefined4 *)((long)param_1 + 0x1094c) = 0x31;
  *(undefined4 *)(param_1 + 0x2231) = 0;
  if ((*(byte *)((long)param_1 + 0x65d) & 1) != 0) {
    bVar12 = (byte)(int)param_1[0xb9];
  }
  param_1[0x3039] = 100;
  param_1[0x2ff9] = 60000;
  *(byte *)((long)param_1 + 0x531) = bVar12 & 1;
  *(byte *)((long)param_1 + 0x5d1) = *(byte *)((long)param_1 + 0x5d1) & 0xfe;
  uVar19 = (**(code **)(*param_2 + 0x118))(*param_2 + 0x118,param_2,"interrupts");
  uVar37 = *(undefined8 *)puVar32;
  plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(uVar19,uVar37);
  if (plVar16 == (long *)0x0) {
    uVar15 = (uint)*(byte *)((long)param_1 + 0x646);
  }
  else {
    uVar31 = (**(code **)(*plVar16 + 0xa0))();
    uVar31 = uVar31 >> 2 & 0x3fffffff;
    uVar15 = (uint)uVar31;
    if (uVar15 - 5 < 4) {
      *(undefined2 *)((long)param_1 + 0x644) = 0x104;
    }
    else {
      if (uVar15 != 4 && uVar15 != 1) {
        return 0;
      }
      *(undefined2 *)((long)param_1 + 0x644) = 0;
    }
    *(char *)((long)param_1 + 0x646) = (char)uVar31;
  }
  puVar1 = (ulong *)(param_1 + 0x357c);
  uVar30 = 0xffffffff;
  if ((char)uVar15 < '@') {
    uVar30 = ~(uint)(-1L << ((long)(char)uVar15 & 0x3fU));
  }
  *(uint *)(param_1 + 0xc9) = uVar30;
  lVar35 = *(long *)param_1[0x27];
  lVar35 = (**(code **)(lVar35 + 0x118))(lVar35 + 0x118,(long *)param_1[0x27],"interrupts-valid");
  if ((lVar35 != 0) &&
     (plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,uVar37), plVar16 != (long *)0x0)) {
    puVar18 = (undefined4 *)(**(code **)(*plVar16 + 0xd8))();
    *(undefined4 *)(param_1 + 0xc9) = *puVar18;
  }
  uVar19 = (**(code **)(*param_2 + 0x118))(param_2,"meta-sw-interrupt");
  plVar16 = (long *)thunk_EXT_FUN_8011000003890f30(uVar19,uVar37);
  if (plVar16 == (long *)0x0) {
    *puVar1 = 0;
    param_1[0x357d] = 0;
    *(undefined4 *)(param_1 + 0x357e) = 0;
    uVar19 = 0;
  }
  else {
    uVar15 = (**(code **)(*plVar16 + 0xa0))();
    lVar20 = (**(code **)(*plVar16 + 0xd8))(plVar16);
    lVar35 = 0x14;
    if (uVar15 < 0x28) {
      lVar35 = 0;
    }
    puVar2 = (ulong *)(lVar20 + lVar35);
    *puVar1 = *puVar2;
    param_1[0x357d] = puVar2[1];
    *(int *)(param_1 + 0x357e) = (int)puVar2[2];
    uVar31 = param_1[0xb9];
    param_1[0xb9] = uVar31 & 0xffffffffffebe7ff;
    if (1 < *(uint *)((long)param_1 + 0x414)) {
      param_1[0xb9] = uVar31 & 0xffffffffffebe7ff | 0x200000;
    }
    uVar13 = (**(code **)(*param_1 + 0xc58))(param_1);
    *(undefined4 *)(param_1 + 0x212e) = uVar13;
    uVar13 = (**(code **)(*param_1 + 0xc20))(*param_1 + 0xc20,param_1);
    (**(code **)(*param_1 + 0xc28))(*param_1 + 0xc28,param_1);
    (**(code **)(*param_1 + 0xc30))(*param_1 + 0xc30,param_1);
    *(undefined4 *)((long)param_1 + 0x10974) = uVar13;
    (**(code **)(*param_1 + 0xc38))(*param_1 + 0xc38,param_1);
    uVar33 = param_1[0xb9];
    uVar31 = uVar33 & 0xffffffffffbfffff;
    param_1[0xb9] = uVar31;
    if ((((uint)(uVar33 >> 0x1e) ^ (uint)uVar33 >> 0x19) & 1) != 0) {
      (**(code **)(*param_1 + 0x38))(param_1);
      thunk_EXT_FUN_8011000003891b28();
      uVar31 = param_1[0xb9];
    }
    param_1[0xb9] = uVar31 & 0xfffffffffc000000 | uVar31 & 0x1ffffff | (uVar33 >> 0x1e & 1) << 0x19;
    if (*(int *)((long)param_1 + 0x5fc) != 0) {
      (**(code **)(*param_1 + 0x38))(param_1);
      thunk_EXT_FUN_8011000003891b28();
    }
    param_1[0x22c5] = -1;
    *(undefined1 *)((long)param_1 + 0x11181) = 0;
    *(undefined4 *)((long)param_1 + 0x11184) = 0;
    *(undefined1 *)(param_1 + 0x214e) = 1;
    *(undefined4 *)((long)param_1 + 0x604) = 0x35c;
    param_1[0xc1] = 0x1000000010;
    lVar35 = (**(code **)(*param_1 + 0x810))(*param_1 + 0x810,param_1,0);
    if (lVar35 == 0) {
      uVar19 = thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Fender address is unknown\n");
      return uVar19;
    }
    local_70[0] = 0;
    local_74 = 0;
    thunk_EXT_FUN_8011000003203330(local_70,&local_74);
    lVar35 = (ulong)(DAT_fffffff00ae21b18 % 0x13) * 0x10;
    puVar18 = (undefined4 *)((long)(int)lVar35 + -0xff51de618);
    if (lVar35 != (int)lVar35) {
      puVar18 = (undefined4 *)(lVar35 - 0xff51de618U & 0xffffffffffff | 0x2bad000000000000);
    }
    uVar31 = local_70[0] - 0x6270;
    puVar18[3] = local_74;
    auVar8._8_8_ = 0;
    auVar8._0_8_ = uVar31;
    uVar15 = (int)uVar31 + SUB164(auVar8 * ZEXT816(0xc22e450672894ab7),10) * -0x15180;
    *(char *)(puVar18 + 2) = (char)uVar15 + (char)(uVar15 / 0x3c) * -0x3c;
    *(char *)((long)puVar18 + 7) =
         (char)(uVar15 / 0x3c) + (char)((uVar15 / 0x3c) * 0x8889 >> 0x15) * -0x3c;
    *(char *)((long)puVar18 + 6) = (char)(uVar15 / 0xe10);
    uVar31 = uVar31 / 0x15180 + 0x2db;
    uVar33 = uVar31 % 0x5b5;
    uVar31 = (uVar31 / 0x5b5) * 4 + 0x7b0;
    if (uVar33 < 0x16e) {
      puVar32 = &UNK_fffffff007115d18;
    }
    else {
      uVar30 = (int)uVar33 - 0x16e;
      uVar15 = (uVar30 & 0xffff) / 0x16d;
      uVar33 = (ulong)(uVar30 + uVar15 * -0x16d) & 0xffff;
      uVar31 = uVar31 + (uVar15 + 1);
      puVar32 = &UNK_fffffff007115ce4;
    }
    if (uVar31 < 0x834) {
      uVar34 = 0;
      *puVar18 = (int)uVar31;
      lVar35 = 1;
      do {
        uVar34 = uVar34 + 1;
        lVar20 = lVar35 * 4;
        lVar35 = lVar35 + 1;
      } while (*(uint *)(puVar32 + lVar20) <= uVar33 && uVar34 < 0xc);
      *(char *)(puVar18 + 1) = (char)uVar34;
      *(char *)((long)puVar18 + 5) =
           ((char)uVar33 - (char)*(undefined4 *)(puVar32 + uVar34 * 4 + -4)) + '\x01';
    }
    (**(code **)(*param_1 + 0x38))(param_1);
    thunk_EXT_FUN_8011000003891b28();
    DAT_fffffff00ae21b18 = DAT_fffffff00ae21b18 + 1;
    (**(code **)(*param_1 + 0xce0))(*param_1 + 0xce0,param_1);
    plVar16 = param_1 + 0xcf;
    thunk_EXT_FUN_8011000003a61cc0(plVar16,0xff38);
    *(undefined4 *)(param_1 + 0x9c6) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x4e34,0x214);
    *(undefined4 *)(param_1 + 0xa09) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x504c,0x214);
    param_1[0xa4c] = (long)"RGX Regs";
    *(undefined4 *)(param_1 + 0x1cc2) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xe614,0x214);
    *(undefined4 *)(param_1 + 0x1d05) = 1;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xe82c,0x214);
    param_1[0x1d48] = (long)"TMB AFR DCPMS";
    *(undefined4 *)(param_1 + 0x1128) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x8944,0x214);
    *(undefined4 *)(param_1 + 0x116b) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x8b5c,0x214);
    param_1[0x11ae] = (long)"GFenderCfg Regs";
    *(undefined4 *)(param_1 + 0x11af) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x8d7c,0x214);
    *(undefined4 *)(param_1 + 0x11f2) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x8f94,0x214);
    param_1[0x1235] = (long)"GM GIFAF Regs";
    *(undefined4 *)(param_1 + 0x1236) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x91b4,0x214);
    *(undefined4 *)(param_1 + 0x1279) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x93cc,0x214);
    param_1[0x12bc] = (long)"CRE Regs";
    *(undefined4 *)(param_1 + 0x12bd) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x95ec,0x214);
    *(undefined4 *)(param_1 + 0x1300) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x9804,0x214);
    param_1[0x1343] = (long)"GCPMS Regs";
    *(undefined4 *)(param_1 + 0x1344) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x9a24,0x214);
    *(undefined4 *)(param_1 + 4999) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x9c3c,0x214);
    param_1[0x13ca] = (long)"KSM FE Regs";
    *(undefined4 *)(param_1 + 0x13cb) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x9e5c,0x214);
    *(undefined4 *)(param_1 + 0x140e) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xa074,0x214);
    param_1[0x1451] = (long)"MCW Regs";
    *(undefined4 *)(param_1 + 0x1452) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xa294,0x214);
    *(undefined4 *)(param_1 + 0x1495) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xa4ac,0x214);
    param_1[0x14d8] = (long)"FenderScratchRam";
    *(undefined4 *)(param_1 + 0x14d9) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xa6cc,0x214);
    *(undefined4 *)(param_1 + 0x151c) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xa8e4,0x214);
    param_1[0x155f] = (long)"Bumper Regs";
    *(undefined4 *)(param_1 + 0x1560) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xab04,0x214);
    *(undefined4 *)(param_1 + 0x15a3) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xad1c,0x214);
    param_1[0x15e6] = (long)"PRC Regs";
    *(undefined4 *)(param_1 + 0x15e7) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xaf3c,0x214);
    *(undefined4 *)(param_1 + 0x162a) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xb154,0x214);
    param_1[0x166d] = (long)"Fender MGPU Regs";
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xb374,0x42c);
    param_1[0x16f4] = (long)"Fender Power Transition Regs (G16G only)";
    *(undefined4 *)(param_1 + 0x16f5) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xb7ac,0x214);
    *(undefined4 *)(param_1 + 0x1738) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xb9c4,0x214);
    param_1[0x177b] = (long)"DFender CS Regs";
    *(undefined4 *)(param_1 + 0x177c) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xbbe4,0x214);
    *(undefined4 *)(param_1 + 0x17bf) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xbdfc,0x214);
    param_1[0x1802] = (long)"DFender IVDM Regs";
    *(undefined4 *)(param_1 + 0x1803) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xc01c,0x214);
    *(undefined4 *)(param_1 + 0x1846) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xc234,0x214);
    param_1[0x1889] = (long)"MetrologySensor Regs (unused)";
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xd534,0x42c);
    param_1[0x1b2c] = (long)"Fender HWL Regs";
    *(undefined4 *)(param_1 + 0x1c3b) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xe1dc,0x214);
    *(undefined4 *)(param_1 + 0x1c7e) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xe3f4,0x214);
    param_1[0x1cc1] = (long)"AFRMetrologySensor Regs (unused)";
    *(undefined4 *)(param_1 + 0x188a) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xc454,0x214);
    *(undefined4 *)(param_1 + 0x18cd) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xc66c,0x214);
    param_1[0x1910] = (long)"GFXClkGen Regs";
    *(undefined4 *)(param_1 + 0x1911) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xc88c,0x214);
    *(undefined4 *)(param_1 + 0x1954) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xcaa4,0x214);
    param_1[0x1997] = (long)"ThrottleStateCounters";
    *(undefined4 *)(param_1 + 0x1f65) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xfb2c,0x214);
    *(undefined4 *)(param_1 + 0x1fa8) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xfd44,0x214);
    param_1[0x1feb] = (long)"ThrottleStateCountersCS";
    *(undefined4 *)(param_1 + 0x1998) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xccc4,0x214);
    *(undefined4 *)(param_1 + 0x19db) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xcedc,0x214);
    param_1[0x1a1e] = (long)"AVMR Ctrl Fast Regs";
    *(undefined4 *)(param_1 + 0x1a1f) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xd0fc,0x214);
    *(undefined4 *)(param_1 + 0x1a62) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xd314,0x214);
    param_1[0x1aa5] = (long)"AFR NIA Regs";
    *(undefined4 *)(param_1 + 0xdfe) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x6ff4,0x214);
    *(undefined4 *)(param_1 + 0xe41) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x720c,0x214);
    param_1[0xe84] = (long)"CS RIF Perf Regs";
    *(undefined4 *)(param_1 + 0xe85) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x742c,0x214);
    *(undefined4 *)(param_1 + 0xec8) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x7644,0x214);
    param_1[0xf0b] = (long)"GPU CTL RIF Perf Regs";
    *(undefined4 *)(param_1 + 0xf0c) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x7864,0x214);
    *(undefined4 *)(param_1 + 0xf4f) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x7a7c,0x214);
    param_1[0xf92] = (long)"AGX HAT Regs";
    *(undefined4 *)(param_1 + 0x1bb4) = 1;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xdda4,0x214);
    *(undefined4 *)(param_1 + 0x1bf7) = 1;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xdfbc,0x214);
    param_1[0x1c3a] = (long)"Probe-time Fender mapping";
    iVar14 = 1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f);
    param_1[0xcf] = DAT_fffffff007113e88;
    param_1[0xd0] = *puVar1 & (long)-iVar14;
    param_1[0xd2] = 0;
    param_1[0xd1] = 0;
    param_1[0xd4] = 0;
    param_1[0xd3] = 0;
    param_1[0xd6] = 0;
    param_1[0xd5] = 0;
    param_1[0xd8] = 0;
    param_1[0xd7] = 0;
    param_1[0xda] = 0;
    param_1[0xd9] = 0;
    param_1[0xdc] = 0;
    param_1[0xdb] = 0;
    param_1[0xde] = 0;
    param_1[0xdd] = 0;
    param_1[0xe0] = 0;
    param_1[0xdf] = 0;
    param_1[0xe2] = 0;
    param_1[0xe1] = 0;
    param_1[0xe4] = 0;
    param_1[0xe3] = 0;
    param_1[0xe6] = 0;
    param_1[0xe5] = 0;
    param_1[0xe8] = 0;
    param_1[0xe7] = 0;
    param_1[0xea] = 0;
    param_1[0xe9] = 0;
    param_1[0xec] = 0;
    param_1[0xeb] = 0;
    param_1[0xee] = 0;
    param_1[0xed] = 0;
    param_1[0xf0] = 0;
    param_1[0xef] = 0;
    param_1[0xf2] = 0;
    param_1[0xf1] = 0;
    param_1[0xf4] = 0;
    param_1[0xf3] = 0;
    param_1[0xf6] = 0;
    param_1[0xf5] = 0;
    param_1[0xf8] = 0;
    param_1[0xf7] = 0;
    param_1[0xfa] = 0;
    param_1[0xf9] = 0;
    param_1[0xfc] = 0;
    param_1[0xfb] = 0;
    param_1[0xfe] = 0;
    param_1[0xfd] = 0;
    param_1[0x100] = 0;
    param_1[0xff] = 0;
    param_1[0x102] = 0;
    param_1[0x101] = 0;
    param_1[0x104] = 0;
    param_1[0x103] = 0;
    param_1[0x106] = 0;
    param_1[0x105] = 0;
    param_1[0x108] = 0;
    param_1[0x107] = 0;
    param_1[0x10a] = 0;
    param_1[0x109] = 0;
    param_1[0x10c] = 0;
    param_1[0x10b] = 0;
    param_1[0x10e] = 0;
    param_1[0x10d] = 0;
    param_1[0x10f] = 0;
    *(int *)(param_1 + 0x110) = iVar14;
    *(undefined8 *)((long)param_1 + 0x884) = 0;
    *(undefined8 *)((long)param_1 + 0x88c) = 0x200000000;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x894,0x214);
    param_1[0x155] = (long)"AICSWIntRegs";
    *(undefined4 *)(param_1 + 0x156) = 0;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xab4,0x42c);
    param_1[0x1dc] = (long)"TempSensorRegs (unused)";
    *(undefined4 *)(param_1 + 0x1dd) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xeec,0x214);
    *(undefined4 *)(param_1 + 0x220) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x1104,0x214);
    param_1[0x263] = (long)"PMPDoorbell (unused)";
    *(undefined4 *)(param_1 + 0x372) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x1b94,0x214);
    *(undefined4 *)(param_1 + 0x3b5) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x1dac,0x214);
    param_1[0x3f8] = (long)"PMGRScratch (unused)";
    *(undefined4 *)(param_1 + 0x831) = 0;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x418c,0x42c);
    param_1[0x8b7] = (long)"PMSMetrologySensorRegs (unused)";
    *(undefined4 *)(param_1 + 0x264) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x1324,0x214);
    *(undefined4 *)(param_1 + 0x2a7) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x153c,0x214);
    param_1[0x2ea] = (long)"MCache registers (unused)";
    *(undefined4 *)(param_1 + 0x2eb) = 0;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x175c,0x42c);
    param_1[0x371] = (long)"AICBankedRegisters (unused)";
    *(undefined4 *)(param_1 + 0x3f9) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x1fcc,0x214);
    *(undefined4 *)(param_1 + 0x43c) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x21e4,0x214);
    param_1[0x47f] = (long)"NIA Special agent idle register die 0 (unused)";
    *(undefined4 *)(param_1 + 0x480) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x2404,0x214);
    *(undefined4 *)(param_1 + 0x4c3) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x261c,0x214);
    param_1[0x506] = (long)"NIA Special agent idle register die 1 (unused)";
    *(undefined4 *)(param_1 + 0x507) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x283c,0x214);
    *(undefined4 *)(param_1 + 0x54a) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0x2a54,0x214);
    param_1[0x58d] = (long)"Streaming codec registers (unused)";
    *(undefined4 *)(param_1 + 0x1e57) = 0;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xf2bc,0x42c);
    param_1[0x1edd] = (long)"Dynamic Power Control Regs";
    *(undefined4 *)(param_1 + 0x1d49) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xea4c,0x214);
    *(undefined4 *)(param_1 + 0x1d8c) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xec64,0x214);
    param_1[0x1dcf] = (long)"PMGR Misc Die 0";
    *(undefined4 *)(param_1 + 0x1dd0) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xee84,0x214);
    *(undefined4 *)(param_1 + 0x1e13) = 2;
    thunk_EXT_FUN_8011000003a61cc0((long)param_1 + 0xf09c,0x214);
    param_1[0x1e56] = (long)"PMGR Misc Die 1";
    lVar20 = (**(code **)(*param_1 + 0xcd0))(*param_1 + 0xcd0,param_1);
    lVar35 = (**(code **)(*param_1 + 0xcd8))(*param_1 + 0xcd8,param_1);
    if (lVar35 != 0) {
      lVar36 = 0;
      do {
        lVar29 = lVar36 * 0x20;
        puVar17 = (uint *)(lVar20 + (int)lVar29);
        if (lVar29 - (int)lVar29 != 0) {
          puVar17 = (uint *)(lVar20 + lVar29 & 0xffffffffffffU | 0x2bad000000000000);
        }
        if (puVar17[1] != 0xffffffff) {
          lVar29 = (ulong)*puVar17 * 0x438;
          iVar14 = (int)lVar29;
          pbVar3 = (byte *)((long)plVar16 + (long)iVar14);
          if (lVar29 - iVar14 != 0) {
            pbVar3 = (byte *)((ulong)(plVar16 + (ulong)*puVar17 * 0x87) & 0xffffffffffff |
                             0x2bad000000000000);
          }
          if ((*pbVar3 & 1) == 0) {
            lVar29 = (**(code **)(*param_1 + 0x800))(param_1,0);
            uVar15 = puVar17[1];
            uVar31 = (ulong)*puVar17;
            uVar33 = uVar31 * 0x438;
            iVar14 = (int)(uVar33 + 8);
            plVar22 = (long *)((long)plVar16 + (long)iVar14);
            if (uVar33 + 8 != (long)iVar14) {
              plVar22 = (long *)((ulong)(plVar16 + uVar31 * 0x87 + 1) & 0xffffffffffff |
                                0x2bad000000000000);
            }
            *plVar22 = lVar29 + (ulong)uVar15;
            iVar14 = (int)(uVar33 + 0x208);
            puVar18 = (undefined4 *)((long)plVar16 + (long)iVar14);
            if (uVar33 + 0x208 != (long)iVar14) {
              puVar18 = (undefined4 *)
                        ((ulong)(plVar16 + uVar31 * 0x87 + 0x41) & 0xffffffffffff |
                        0x2bad000000000000);
            }
            *puVar18 = (int)*(undefined8 *)(puVar17 + 2);
            iVar14 = (int)(uVar33 + 0x210);
            puVar1 = (ulong *)((long)plVar16 + (long)iVar14);
            if (uVar33 + 0x210 != (long)iVar14) {
              puVar1 = (ulong *)((ulong)(plVar16 + uVar31 * 0x87 + 0x42) & 0xffffffffffff |
                                0x2bad000000000000);
            }
            *puVar1 = (ulong)uVar15;
            uVar33 = uVar33 | 4;
            puVar18 = (undefined4 *)((long)plVar16 + (long)(int)uVar33);
            if (uVar33 != (long)(int)uVar33) {
              puVar18 = (undefined4 *)((long)plVar16 + uVar33 & 0xffffffffffff | 0x2bad000000000000)
              ;
            }
            *puVar18 = 1;
          }
        }
        if (1 < puVar17[4] + 1) {
          lVar29 = (ulong)*puVar17 * 0x438;
          iVar14 = (int)lVar29;
          uVar31 = (long)plVar16 + (long)iVar14;
          if (lVar29 - iVar14 != 0) {
            uVar31 = (ulong)(plVar16 + (ulong)*puVar17 * 0x87) & 0xffffffffffff | 0x2bad000000000000
            ;
          }
          if ((*(byte *)(uVar31 + 0x218) & 1) == 0) {
            if (puVar17[4] == 0xdadadada) {
              thunk_EXT_FUN_8011000003a61b10(uVar31 + 0x218,uVar31,0x218);
              lVar29 = (ulong)*puVar17 * 0x438 + 0x218;
            }
            else {
              lVar21 = (**(code **)(*param_1 + 0x800))(param_1,1);
              lVar29 = (ulong)*puVar17 * 0x438 + 0x218;
              uVar31 = (long)plVar16 + (long)(int)lVar29;
              if (lVar29 != (int)lVar29) {
                uVar31 = (ulong)(plVar16 + (ulong)*puVar17 * 0x87 + 0x43) & 0xffffffffffff |
                         0x2bad000000000000;
              }
              uVar15 = puVar17[4];
              *(ulong *)(uVar31 + 8) = lVar21 + (ulong)uVar15;
              *(ulong *)(uVar31 + 0x210) = (ulong)uVar15;
              *(int *)(uVar31 + 0x208) = (int)*(undefined8 *)(puVar17 + 5);
            }
            puVar18 = (undefined4 *)((long)param_1 + (long)(int)lVar29 + 0x67c);
            if (lVar29 != (int)lVar29) {
              puVar18 = (undefined4 *)
                        ((long)param_1 + lVar29 + 0x67c & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar18 = 1;
          }
        }
        lVar36 = lVar36 + 1;
        lVar35 = lVar35 + -1;
      } while (lVar35 != 0);
    }
    local_70[0] = 0;
    local_74 = 0;
    thunk_EXT_FUN_8011000003203330(local_70,&local_74);
    lVar35 = (ulong)(DAT_fffffff00ae21b18 % 0x13) * 0x10;
    puVar18 = (undefined4 *)((long)(int)lVar35 + -0xff51de618);
    if (lVar35 != (int)lVar35) {
      puVar18 = (undefined4 *)(lVar35 - 0xff51de618U & 0xffffffffffff | 0x2bad000000000000);
    }
    uVar31 = local_70[0] - 0x6270;
    puVar18[3] = local_74;
    auVar9._8_8_ = 0;
    auVar9._0_8_ = uVar31;
    uVar15 = (int)uVar31 + SUB164(auVar9 * ZEXT816(0xc22e450672894ab7),10) * -0x15180;
    *(char *)(puVar18 + 2) = (char)uVar15 + (char)(uVar15 / 0x3c) * -0x3c;
    *(char *)((long)puVar18 + 7) =
         (char)(uVar15 / 0x3c) + (char)((uVar15 / 0x3c) * 0x8889 >> 0x15) * -0x3c;
    *(char *)((long)puVar18 + 6) = (char)(uVar15 / 0xe10);
    uVar31 = uVar31 / 0x15180 + 0x2db;
    uVar33 = uVar31 % 0x5b5;
    uVar31 = (uVar31 / 0x5b5) * 4 + 0x7b0;
    uVar30 = (int)uVar33 - 0x16e;
    uVar15 = (uVar30 & 0xffff) / 0x16d;
    puVar32 = &UNK_fffffff007115d18;
    if (0x16d < uVar33) {
      uVar31 = uVar31 + (uVar15 + 1);
      uVar33 = (ulong)(uVar30 + uVar15 * -0x16d) & 0xffff;
      puVar32 = &UNK_fffffff007115ce4;
    }
    if (uVar31 < 0x834) {
      uVar34 = 0;
      *puVar18 = (int)uVar31;
      lVar35 = 1;
      do {
        uVar34 = uVar34 + 1;
        lVar20 = lVar35 * 4;
        lVar35 = lVar35 + 1;
      } while (*(uint *)(puVar32 + lVar20) <= uVar33 && uVar34 < 0xc);
      *(char *)(puVar18 + 1) = (char)uVar34;
      *(char *)((long)puVar18 + 5) =
           ((char)uVar33 - (char)*(undefined4 *)(puVar32 + uVar34 * 4 + -4)) + '\x01';
    }
    plVar16 = param_1 + 0x20bf;
    (**(code **)(*param_1 + 0x38))(param_1);
    thunk_EXT_FUN_8011000003891b28();
    DAT_fffffff00ae21b18 = DAT_fffffff00ae21b18 + 1;
    plVar22 = (long *)(**(code **)(*param_1 + 0x9f8))(*param_1 + 0x9f8,param_1);
    iVar14 = (**(code **)(*param_1 + 0x7f0))(*param_1 + 0x7f0,param_1);
    if ((plVar22 != (long *)0x0) &&
       (plVar23 = (long *)thunk_EXT_FUN_801100000392ece0(plVar22,10000000000),
       plVar23 != (long *)0x0)) {
      uVar19 = (**(code **)(*plVar23 + 0x118))(plVar23,"MtrPolynomGFX");
      plVar24 = (long *)thunk_EXT_FUN_8011000003890f30(uVar19,uVar37);
      if (plVar24 != (long *)0x0) {
        uVar31 = (**(code **)(*param_1 + 0x7e8))(param_1);
        uVar15 = (**(code **)(*plVar24 + 0xa0))(plVar24);
        lVar35 = (**(code **)(*plVar24 + 0xd8))(plVar24);
        if (3 < uVar15) {
          uVar15 = uVar15 >> 2;
          if (iVar14 == 0) {
            if ((uVar31 & 1) == 0) {
              uVar31 = 0;
              do {
                lVar20 = uVar31 * 4;
                puVar17 = (uint *)(lVar35 + (int)lVar20);
                if (lVar20 != (int)lVar20) {
                  puVar17 = (uint *)(lVar35 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
                }
                uVar33 = (ulong)*puVar17;
                lVar20 = (ulong)((int)uVar31 + 1) * 4;
                puVar4 = (uint *)(lVar35 + (int)lVar20);
                if (lVar20 != (int)lVar20) {
                  puVar4 = (uint *)(lVar35 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
                }
                uVar30 = (int)uVar31 + 2;
                uVar27 = *puVar4;
                uVar6 = uVar27 >> 2;
                uVar31 = (ulong)(*puVar17 >> 3) & 0x1ffffff8;
                *(ulong *)((long)plVar16 + uVar31) =
                     1L << (uVar33 & 0x3f) | *(ulong *)((long)plVar16 + uVar31);
                if (3 < uVar27) {
                  uVar27 = uVar6;
                  if (0x14 < uVar6) {
                    uVar27 = 0x15;
                  }
                  puVar17 = (uint *)thunk_EXT_FUN_80110000038fe580((ulong)(uVar27 << 2) + 4);
                  iVar14 = (int)(uVar33 * 8);
                  puVar5 = (undefined8 *)((long)plVar25 + (long)iVar14);
                  if (uVar33 * 8 - (long)iVar14 != 0) {
                    puVar5 = (undefined8 *)
                             ((ulong)(plVar25 + uVar33) & 0xffffffffffff | 0x2bad000000000000);
                  }
                  *puVar5 = puVar17;
                  *puVar17 = uVar27;
                  lVar20 = (ulong)uVar30 * 4;
                  uVar31 = lVar35 + (int)lVar20;
                  if (lVar20 != (int)lVar20) {
                    uVar31 = lVar35 + lVar20 & 0xffffffffffffU | 0x2bad000000000000;
                  }
                  thunk_EXT_FUN_8011000003a61b10(puVar17 + 1,uVar31,(ulong)(uVar27 << 2));
                  lVar20 = uVar33 * 4;
                  puVar18 = (undefined4 *)((long)param_1 + (long)(int)lVar20 + 0x10808);
                  if (lVar20 - (int)lVar20 != 0) {
                    puVar18 = (undefined4 *)
                              ((long)param_1 + lVar20 + 0x10808 & 0xffffffffffffU |
                              0x2bad000000000000);
                  }
                  *puVar18 = 0;
                }
                uVar6 = uVar6 + uVar30;
                uVar31 = (ulong)uVar6;
              } while (uVar6 < uVar15);
            }
            else {
              uVar31 = 0;
              do {
                iVar14 = (int)uVar31;
                lVar20 = uVar31 * 4;
                puVar17 = (uint *)(lVar35 + (int)lVar20);
                if (lVar20 != (int)lVar20) {
                  puVar17 = (uint *)(lVar35 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
                }
                uVar31 = (ulong)*puVar17;
                lVar20 = (ulong)(iVar14 + 1) * 4;
                puVar4 = (uint *)(lVar35 + (int)lVar20);
                if (lVar20 != (int)lVar20) {
                  puVar4 = (uint *)(lVar35 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
                }
                uVar6 = *puVar4;
                uVar30 = uVar6 >> 2;
                uVar33 = (ulong)(*puVar17 >> 3) & 0x1ffffff8;
                *(ulong *)((long)plVar16 + uVar33) =
                     1L << (uVar31 & 0x3f) | *(ulong *)((long)plVar16 + uVar33);
                if (3 < uVar6) {
                  uVar27 = uVar30;
                  if (0x14 < uVar30) {
                    uVar27 = 0x15;
                  }
                  puVar17 = (uint *)thunk_EXT_FUN_80110000038fe580((ulong)(uVar27 << 2) + 4);
                  iVar28 = (int)(uVar31 * 8);
                  puVar5 = (undefined8 *)((long)plVar25 + (long)iVar28);
                  if (uVar31 * 8 - (long)iVar28 != 0) {
                    puVar5 = (undefined8 *)
                             ((ulong)(plVar25 + uVar31) & 0xffffffffffff | 0x2bad000000000000);
                  }
                  *puVar5 = puVar17;
                  *puVar17 = uVar27;
                  lVar20 = (ulong)(iVar14 + 2U) * 4;
                  uVar33 = lVar35 + (int)lVar20;
                  if (lVar20 != (int)lVar20) {
                    uVar33 = lVar35 + lVar20 & 0xffffffffffffU | 0x2bad000000000000;
                  }
                  thunk_EXT_FUN_8011000003a61b10(puVar17 + 1,uVar33,(ulong)(uVar27 << 2));
                  if (uVar6 < 0x58) {
                    uVar13 = 0;
                  }
                  else {
                    lVar20 = (ulong)(iVar14 + 0x17) * 4;
                    puVar18 = (undefined4 *)(lVar35 + (int)lVar20);
                    if (lVar20 != (int)lVar20) {
                      puVar18 = (undefined4 *)
                                (lVar35 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
                    }
                    uVar13 = *puVar18;
                  }
                  lVar20 = uVar31 * 4;
                  puVar18 = (undefined4 *)((long)param_1 + (long)(int)lVar20 + 0x10808);
                  if (lVar20 - (int)lVar20 != 0) {
                    puVar18 = (undefined4 *)
                              ((long)param_1 + lVar20 + 0x10808 & 0xffffffffffffU |
                              0x2bad000000000000);
                  }
                  *puVar18 = uVar13;
                }
                uVar30 = uVar30 + iVar14 + 2U;
                uVar31 = (ulong)uVar30;
              } while (uVar30 < uVar15);
            }
          }
          else {
            uVar31 = 0;
            do {
              lVar20 = uVar31 * 4;
              puVar17 = (uint *)(lVar35 + (int)lVar20);
              if (lVar20 != (int)lVar20) {
                puVar17 = (uint *)(lVar35 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
              }
              lVar20 = (ulong)((int)uVar31 + 1) * 4;
              puVar4 = (uint *)(lVar35 + (int)lVar20);
              if (lVar20 != (int)lVar20) {
                puVar4 = (uint *)(lVar35 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
              }
              uVar30 = *puVar4;
              uVar33 = (ulong)(*puVar17 >> 3) & 0x1ffffff8;
              *(ulong *)((long)plVar16 + uVar33) =
                   1L << ((ulong)*puVar17 & 0x3f) | *(ulong *)((long)plVar16 + uVar33);
              uVar30 = (int)uVar31 + (uVar30 >> 2) + 2;
              uVar31 = (ulong)uVar30;
            } while (uVar30 < uVar15);
          }
        }
      }
      (**(code **)(*plVar23 + 0x28))();
    }
    lVar35 = (**(code **)(*(long *)param_1[0x27] + 0x118))((long *)param_1[0x27],"mtr-enabled");
    if ((lVar35 != 0) &&
       (plVar25 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,uVar37), plVar25 != (long *)0x0)) {
      piVar26 = (int *)(**(code **)(*plVar25 + 0xd8))();
      *(uint *)(param_1 + 0x20be) = (uint)(*piVar26 != 0);
    }
    if (*plVar16 != 0) {
      *(undefined4 *)(param_1 + 0x20be) = 1;
    }
    (**(code **)(*param_1 + 0x7f0))(param_1);
    if (plVar22 != (long *)0x0) {
      (**(code **)(*plVar22 + 0x28))(plVar22);
    }
    local_70[0] = 0;
    local_74 = 0;
    thunk_EXT_FUN_8011000003203330(local_70,&local_74);
    lVar35 = (ulong)(DAT_fffffff00ae21b18 % 0x13) * 0x10;
    puVar18 = (undefined4 *)((long)(int)lVar35 + -0xff51de618);
    if (lVar35 != (int)lVar35) {
      puVar18 = (undefined4 *)(lVar35 - 0xff51de618U & 0xffffffffffff | 0x2bad000000000000);
    }
    uVar31 = local_70[0] - 0x6270;
    puVar18[3] = local_74;
    auVar10._8_8_ = 0;
    auVar10._0_8_ = uVar31;
    uVar15 = (int)uVar31 + SUB164(auVar10 * ZEXT816(0xc22e450672894ab7),10) * -0x15180;
    *(char *)(puVar18 + 2) = (char)uVar15 + (char)(uVar15 / 0x3c) * -0x3c;
    *(char *)((long)puVar18 + 7) =
         (char)(uVar15 / 0x3c) + (char)((uVar15 / 0x3c) * 0x8889 >> 0x15) * -0x3c;
    *(char *)((long)puVar18 + 6) = (char)(uVar15 / 0xe10);
    uVar31 = uVar31 / 0x15180 + 0x2db;
    uVar33 = uVar31 % 0x5b5;
    uVar31 = (uVar31 / 0x5b5) * 4 + 0x7b0;
    uVar30 = (int)uVar33 - 0x16e;
    uVar15 = (uVar30 & 0xffff) / 0x16d;
    puVar32 = &UNK_fffffff007115d18;
    if (0x16d < uVar33) {
      uVar31 = uVar31 + (uVar15 + 1);
      uVar33 = (ulong)(uVar30 + uVar15 * -0x16d) & 0xffff;
      puVar32 = &UNK_fffffff007115ce4;
    }
    if (uVar31 < 0x834) {
      uVar34 = 0;
      *puVar18 = (int)uVar31;
      lVar35 = 1;
      do {
        uVar34 = uVar34 + 1;
        lVar20 = lVar35 * 4;
        lVar35 = lVar35 + 1;
      } while (*(uint *)(puVar32 + lVar20) <= uVar33 && uVar34 < 0xc);
      *(char *)(puVar18 + 1) = (char)uVar34;
      *(char *)((long)puVar18 + 5) =
           ((char)uVar33 - (char)*(undefined4 *)(puVar32 + uVar34 * 4 + -4)) + '\x01';
    }
    (**(code **)(*param_1 + 0x38))(param_1);
    thunk_EXT_FUN_8011000003891b28();
    DAT_fffffff00ae21b18 = DAT_fffffff00ae21b18 + 1;
    param_1[0xb9] = param_1[0xb9] & 0xffdfffffffffffff;
    (**(code **)(*param_1 + 0x6e0))(*param_1 + 0x6e0,param_1);
    (**(code **)(*param_1 + 0x700))(*param_1 + 0x700,param_1);
    lVar35 = *(long *)param_1[0x27];
    lVar35 = (**(code **)(lVar35 + 0x118))
                       (lVar35 + 0x118,(long *)param_1[0x27],"gpu-idleoff-fn-hit");
    if ((lVar35 != 0) &&
       (plVar25 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,uVar37), plVar25 != (long *)0x0)) {
      puVar18 = (undefined4 *)(**(code **)(*plVar25 + 0xd8))();
      *(undefined4 *)(param_1 + 0x20ba) = *puVar18;
    }
    lVar35 = (**(code **)(*(long *)param_1[0x27] + 0x118))
                       ((long *)param_1[0x27],"gpu-idleoff-fi-hit");
    if ((lVar35 != 0) &&
       (plVar25 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,uVar37), plVar25 != (long *)0x0)) {
      puVar18 = (undefined4 *)(**(code **)(*plVar25 + 0xd8))();
      *(undefined4 *)((long)param_1 + 0x105d4) = *puVar18;
    }
    lVar35 = (**(code **)(*(long *)param_1[0x27] + 0x118))
                       ((long *)param_1[0x27],"gpu-idleoff-fn-miss");
    if ((lVar35 != 0) &&
       (plVar25 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,uVar37), plVar25 != (long *)0x0)) {
      puVar18 = (undefined4 *)(**(code **)(*plVar25 + 0xd8))();
      *(undefined4 *)(param_1 + 0x20bb) = *puVar18;
    }
    lVar35 = (**(code **)(*(long *)param_1[0x27] + 0x118))
                       ((long *)param_1[0x27],"gpu-idleoff-fi-miss");
    if ((lVar35 != 0) &&
       (plVar25 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,uVar37), plVar25 != (long *)0x0)) {
      puVar18 = (undefined4 *)(**(code **)(*plVar25 + 0xd8))();
      *(undefined4 *)((long)param_1 + 0x105dc) = *puVar18;
    }
    lVar35 = (**(code **)(*(long *)param_1[0x27] + 0x118))
                       ((long *)param_1[0x27],"gpu-idleoff-nei-hit");
    if ((lVar35 != 0) &&
       (plVar25 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,uVar37), plVar25 != (long *)0x0)) {
      puVar18 = (undefined4 *)(**(code **)(*plVar25 + 0xd8))();
      *(undefined4 *)(param_1 + 0x20bc) = *puVar18;
    }
    lVar35 = (**(code **)(*(long *)param_1[0x27] + 0x118))
                       ((long *)param_1[0x27],"gpu-idleoff-min_conf");
    if ((lVar35 != 0) &&
       (plVar25 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,uVar37), plVar25 != (long *)0x0)) {
      puVar18 = (undefined4 *)(**(code **)(*plVar25 + 0xd8))();
      *(undefined4 *)((long)param_1 + 0x105e4) = *puVar18;
    }
    lVar35 = (**(code **)(*(long *)param_1[0x27] + 0x118))
                       ((long *)param_1[0x27],"gpu-idleoff-high-conf");
    if ((lVar35 != 0) &&
       (plVar25 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,uVar37), plVar25 != (long *)0x0)) {
      puVar18 = (undefined4 *)(**(code **)(*plVar25 + 0xd8))();
      *(undefined4 *)(param_1 + 0x20bd) = *puVar18;
    }
    lVar35 = (**(code **)(*(long *)param_1[0x27] + 0x118))
                       ((long *)param_1[0x27],"gpu-idleoff-reset-iter");
    if ((lVar35 != 0) &&
       (plVar25 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,uVar37), plVar25 != (long *)0x0)) {
      puVar18 = (undefined4 *)(**(code **)(*plVar25 + 0xd8))();
      *(undefined4 *)((long)param_1 + 0x105ec) = *puVar18;
    }
    lVar35 = (**(code **)(*(long *)param_1[0x27] + 0x118))
                       ((long *)param_1[0x27],"gpu-idleoff-standby-timer");
    if ((lVar35 != 0) &&
       (plVar25 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,uVar37), plVar25 != (long *)0x0)) {
      puVar18 = (undefined4 *)(**(code **)(*plVar25 + 0xd8))();
      *(undefined4 *)(param_1 + 0x20b9) = *puVar18;
    }
    lVar35 = (**(code **)(*(long *)param_1[0x27] + 0x118))
                       ((long *)param_1[0x27],"gpu-idleoff-prob-init-val");
    if ((lVar35 != 0) &&
       (plVar25 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,uVar37), plVar25 != (long *)0x0)) {
      puVar18 = (undefined4 *)(**(code **)(*plVar25 + 0xd8))();
      *(undefined4 *)((long)param_1 + 0x105cc) = *puVar18;
    }
    lVar35 = (**(code **)(*(long *)param_1[0x27] + 0x118))
                       ((long *)param_1[0x27],"gpu-pwr-min-duty-cycle");
    if ((lVar35 != 0) &&
       (plVar25 = (long *)thunk_EXT_FUN_8011000003890f30(lVar35,uVar37), plVar25 != (long *)0x0)) {
      puVar18 = (undefined4 *)(**(code **)(*plVar25 + 0xd8))();
      *(undefined4 *)(param_1 + 0x2155) = *puVar18;
    }
    *(undefined4 *)(param_1 + 0xbc) = 0;
    param_1[0xb9] = param_1[0xb9] & 0xfeffffffffffffff;
    *(undefined4 *)(param_1 + 0xce) = 0;
    *(undefined4 *)((long)param_1 + 0x1111c) = 0;
    param_1[0x2224] = DAT_fffffff007113e90;
    *(undefined4 *)((long)param_1 + 0x1118c) = 0;
    *(undefined1 *)(param_1 + 0x2225) = 0;
    *(byte *)((long)param_1 + 0x5d1) = *(byte *)((long)param_1 + 0x5d1) | 6;
    uVar19 = 1;
  }
  return uVar19;
}

