// FUN_fffffff0081cd978 @ fffffff0081cd978 size=3516

/* WARNING: Removing unreachable block (ram,0xfffffff0081ce65c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ce540) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ce4cc) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ce458) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ce3e4) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ce370) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ce060) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081cdda8) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081cda9c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081cdcb4) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081cdf38) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ce1f0) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ce3a8) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ce41c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ce490) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ce508) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ce57c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081ce6cc) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081cda34) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0081cd978(long *param_1)

{
  byte *pbVar1;
  undefined *puVar2;
  code *pcVar3;
  undefined4 uVar4;
  long *plVar5;
  int *piVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  long lVar10;
  long lVar11;
  uint uVar12;
  long lVar13;
  ulong unaff_x30;
  ulong uVar14;
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  int iVar17;
  int iVar20;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  
  FUN_fffffff0081a8cc8();
  lVar13 = param_1[0x54];
  uVar8 = *(undefined8 *)(param_1[0x50] + 0x10990);
  *(undefined8 *)(lVar13 + 0xfb8) = *(undefined8 *)(param_1[0x50] + 0x10998);
  *(undefined8 *)(lVar13 + 0xfb0) = uVar8;
  plVar5 = (long *)param_1[0x50];
  lVar13 = param_1[0x54];
  *(uint *)(lVar13 + 0xfe0) = *(uint *)(plVar5 + 0xb9) >> 0xb & 1;
  *(undefined4 *)(lVar13 + 0xfec) = 24000;
  *(undefined4 *)(lVar13 + 0x1030) = 0;
  *(undefined8 *)(lVar13 + 0x1000) = 0x100000001;
  *(undefined4 *)(lVar13 + 0x1020) = 0x1f;
  *(undefined4 *)(lVar13 + 0x2704) = 0;
  *(int *)(lVar13 + 0x2708) = (int)plVar5[0xc5];
  *(undefined8 *)(lVar13 + 0x2718) = 0;
  auVar16 = _DAT_fffffff007113900;
  *(long *)(lVar13 + 0x1054) = DAT_fffffff007113900._8_8_;
  *(long *)(lVar13 + 0x104c) = auVar16._0_8_;
  uVar4 = (**(code **)(*plVar5 + 0xb80))(*plVar5 + 0xb80);
  lVar13 = param_1[0x54];
  *(undefined4 *)(lVar13 + 0xff4) = uVar4;
  *(undefined4 *)(lVar13 + 0x103c) = 0;
  *(undefined4 *)(lVar13 + 0x1018) = 0;
  *(undefined4 *)(lVar13 + 0xfe8) = 0;
  *(undefined8 *)(lVar13 + 0x10c0) = 0;
  *(undefined8 *)(lVar13 + 0x10b8) = 0;
  *(undefined4 *)(lVar13 + 0x10c8) = 0;
  lVar13 = **(long **)(param_1[0x50] + 0x138);
  lVar13 = (**(code **)(lVar13 + 0x118))
                     (lVar13 + 0x118,*(long **)(param_1[0x50] + 0x138),"pmp-sw-interrupt");
  puVar2 = PTR_DAT_fffffff007ca6090;
  if ((lVar13 == 0) ||
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30
                                 (lVar13,*(undefined8 *)PTR_DAT_fffffff007ca6090),
     plVar5 == (long *)0x0)) {
    lVar13 = param_1[0x54];
  }
  else {
    piVar6 = (int *)(**(code **)(*plVar5 + 0xd8))();
    lVar13 = param_1[0x54];
    if (*piVar6 != 0) {
      *(undefined4 *)(lVar13 + 0x101c) = 1;
    }
  }
  lVar11 = param_1[0x50];
  *(uint *)(lVar13 + 0x102c) = (uint)(*(char *)(lVar11 + 0x65e) != '\0');
  lVar13 = param_1[0x101];
  if (*(long *)(lVar11 + 0x115b0) == 0) {
    *(undefined8 *)(lVar13 + 0x2e0) = 0;
  }
  else {
    lVar7 = (**(code **)(**(long **)(*(long *)(lVar11 + 0x115b0) + 0x58) + 0x98))();
    *(long *)(lVar13 + 0x2e0) = lVar7;
    lVar11 = param_1[0x50];
    if (lVar7 != 0) {
      if (*(long *)(lVar11 + 0x115b0) == 0) {
        uVar8 = 0;
      }
      else {
        plVar5 = *(long **)(*(long *)(lVar11 + 0x115b0) + 0x50);
        uVar8 = 0;
        if (plVar5 != (long *)0x0) {
          uVar8 = (**(code **)(*plVar5 + 0x98))();
        }
      }
      *(undefined8 *)(lVar13 + 0x2e8) = uVar8;
      lVar11 = param_1[0x50];
    }
  }
  if (*(long *)(lVar11 + 0x115b8) == 0) {
    *(undefined8 *)(lVar13 + 0x2f0) = 0;
  }
  else {
    lVar7 = (**(code **)(**(long **)(*(long *)(lVar11 + 0x115b8) + 0x58) + 0x98))();
    *(long *)(lVar13 + 0x2f0) = lVar7;
    lVar11 = param_1[0x50];
    if (lVar7 != 0) {
      if (*(long *)(lVar11 + 0x115b8) == 0) {
        uVar8 = 0;
      }
      else {
        plVar5 = *(long **)(*(long *)(lVar11 + 0x115b8) + 0x50);
        uVar8 = 0;
        if (plVar5 != (long *)0x0) {
          uVar8 = (**(code **)(*plVar5 + 0x98))();
        }
      }
      *(undefined8 *)(lVar13 + 0x2f8) = uVar8;
      lVar11 = param_1[0x50];
    }
  }
  *(undefined8 *)(lVar13 + 0x300) = 0;
  *(undefined4 *)(lVar13 + 0x308) = *(undefined4 *)(lVar11 + 0x109fc);
  *(undefined4 *)(param_1[0x69] + 0x9c4) = 0;
  *(undefined1 *)(lVar13 + 0x3e4) = 0xff;
  *(undefined8 *)(lVar13 + 0x3ed) = 0;
  *(undefined8 *)(lVar13 + 0x3e5) = 0;
  *(undefined8 *)(lVar13 + 0x3fd) = 0;
  *(undefined8 *)(lVar13 + 0x3f5) = 0;
  *(undefined8 *)(lVar13 + 0x40d) = 0;
  *(undefined8 *)(lVar13 + 0x405) = 0;
  *(undefined8 *)(lVar13 + 0x41d) = 0;
  *(undefined8 *)(lVar13 + 0x415) = 0;
  *(undefined8 *)(lVar13 + 0x42d) = 0;
  *(undefined8 *)(lVar13 + 0x425) = 0;
  *(undefined8 *)(lVar13 + 0x43d) = 0;
  *(undefined8 *)(lVar13 + 0x435) = 0;
  *(undefined8 *)(lVar13 + 0x44d) = 0;
  *(undefined8 *)(lVar13 + 0x445) = 0;
  *(undefined8 *)(lVar13 + 0x45d) = 0;
  *(undefined8 *)(lVar13 + 0x455) = 0;
  *(undefined8 *)(lVar13 + 0x46d) = 0;
  *(undefined8 *)(lVar13 + 0x465) = 0;
  param_1[0x308] = 0;
  param_1[0x307] = 0;
  param_1[0x30a] = 0;
  param_1[0x309] = 0;
  param_1[0x304] = 0;
  param_1[0x303] = 0;
  param_1[0x306] = 0;
  param_1[0x305] = 0;
  param_1[0x300] = 0;
  param_1[0x2ff] = 0;
  param_1[0x302] = 0;
  param_1[0x301] = 0;
  param_1[0x2fc] = 0;
  param_1[0x2fb] = 0;
  param_1[0x2fe] = 0;
  param_1[0x2fd] = 0;
  param_1[0x2fa] = 0;
  param_1[0x2f9] = 0;
  uVar8 = (**(code **)(*(long *)param_1[0x50] + 0xd38))(*(long *)param_1[0x50] + 0xd38);
  lVar13 = param_1[0x54];
  *(undefined8 *)(lVar13 + 0x10cc) = uVar8;
  *(undefined4 *)(lVar13 + 0xffc) = 1;
  *(undefined4 *)(lVar13 + 0x1074) = 0;
  *(undefined8 *)(lVar13 + 0x26a0) = 0;
  lVar11 = param_1[0x50];
  lVar7 = *(long *)(lVar11 + 0x115f0);
  if (lVar7 == 0) {
    lVar7 = *(long *)(lVar11 + 0x115d8);
  }
  *(long *)(lVar13 + 0x26a8) = lVar7;
  *(undefined4 *)(lVar13 + 0x265c) = 0;
  if (*(int *)(lVar11 + 0x624) != 0) {
    *(int *)(lVar13 + 0x2660) = *(int *)(lVar11 + 0x624);
  }
  *(uint *)(lVar13 + 0x2664) =
       *(uint *)(lVar11 + 0x5c8) >> 4 & 4 | *(uint *)(lVar11 + 0x5c8) >> 6 & 2;
  uVar14 = *(ulong *)(lVar11 + 0x3f8);
  iVar17 = -(uint)(0x3f < (uint)uVar14);
  iVar20 = -(uint)(0x3f < (uint)(uVar14 >> 0x20));
  auVar15._0_8_ = uVar14 & 0xffffffff;
  auVar15._8_8_ = uVar14 >> 0x20;
  auVar16._8_8_ = 0xffffffffffffffff;
  auVar16._0_8_ = 0xffffffffffffffff;
  auVar16 = NEON_ushl(auVar16,auVar15,8);
  *(ulong *)(lVar13 + 0x2668) =
       CONCAT17((byte)((uint)iVar20 >> 0x18) | ~auVar16[0xb],
                CONCAT16((byte)((uint)iVar20 >> 0x10) | ~auVar16[10],
                         CONCAT15((byte)((uint)iVar20 >> 8) | ~auVar16[9],
                                  CONCAT14((byte)iVar20 | ~auVar16[8],
                                           CONCAT13((byte)((uint)iVar17 >> 0x18) | ~auVar16[3],
                                                    CONCAT12((byte)((uint)iVar17 >> 0x10) |
                                                             ~auVar16[2],
                                                             CONCAT11((byte)((uint)iVar17 >> 8) |
                                                                      ~auVar16[1],
                                                                      (byte)iVar17 | ~auVar16[0]))))
                                 )));
  uVar12 = 0xffffffff;
  if (*(uint *)(lVar11 + 0x400) < 0x40) {
    uVar12 = ~(uint)(-1L << ((ulong)*(uint *)(lVar11 + 0x400) & 0x3f));
  }
  *(uint *)(lVar13 + 0x2670) = uVar12;
  *(undefined4 *)(lVar13 + 0x2678) = 0;
  *(undefined4 *)(lVar13 + 0x105c) = 0;
  *(undefined4 *)(lVar13 + 0x1034) = 0;
  *(undefined4 *)(param_1[0x69] + 0x5e) = 0;
  (**(code **)(*param_1 + 0x550))(*param_1 + 0x550,param_1,0);
  lVar11 = param_1[0x69];
  *(undefined4 *)(lVar11 + 0x14) = 0;
  lVar13 = param_1[0x50];
  *(undefined2 *)(lVar11 + 0x58) = *(undefined2 *)(lVar13 + 0x660);
  *(undefined2 *)(lVar11 + 0x5a) = *(undefined2 *)(lVar13 + 0x662);
  *(undefined2 *)(lVar11 + 0x5c) = *(undefined2 *)(lVar13 + 0x664);
  *(undefined4 *)(param_1[0x122] + 0x6c28) = 0;
  *(undefined4 *)(lVar11 + 0x54) = 0;
  *(undefined4 *)(lVar11 + 0x50) = 0;
  *(undefined4 *)(lVar11 + 0x9dc) = 0;
  if (*(long *)(lVar13 + 0x3b8) != 0 || *(long *)(lVar13 + 0x3b0) != 0) {
    *(long *)(param_1[0x54] + 0x267c) = *(long *)(lVar13 + 0x3b0);
  }
  if ((*(byte *)(lVar13 + 0x43a) & 1) == 0) {
    iVar17 = *(int *)(lVar13 + 0x3e0);
  }
  else {
    lVar7 = 0;
    if (*(long *)(lVar13 + 0x3b8) == 0 && *(long *)(lVar13 + 0x3b0) == 0) {
      lVar7 = 0x10;
    }
    puVar9 = (undefined8 *)(lVar13 + 0x3b0 + lVar7);
    uVar18 = *puVar9;
    uVar8 = puVar9[1];
    iVar17 = (uint)(byte)(POPCOUNT((char)uVar8) + POPCOUNT((char)((ulong)uVar8 >> 8)) +
                          POPCOUNT((char)((ulong)uVar8 >> 0x10)) +
                          POPCOUNT((char)((ulong)uVar8 >> 0x18)) +
                          POPCOUNT((char)((ulong)uVar8 >> 0x20)) +
                          POPCOUNT((char)((ulong)uVar8 >> 0x28)) +
                          POPCOUNT((char)((ulong)uVar8 >> 0x30)) +
                         POPCOUNT((char)((ulong)uVar8 >> 0x38))) +
             (uint)(byte)(POPCOUNT((char)uVar18) + POPCOUNT((char)((ulong)uVar18 >> 8)) +
                          POPCOUNT((char)((ulong)uVar18 >> 0x10)) +
                          POPCOUNT((char)((ulong)uVar18 >> 0x18)) +
                          POPCOUNT((char)((ulong)uVar18 >> 0x20)) +
                          POPCOUNT((char)((ulong)uVar18 >> 0x28)) +
                          POPCOUNT((char)((ulong)uVar18 >> 0x30)) +
                         POPCOUNT((char)((ulong)uVar18 >> 0x38)));
  }
  lVar7 = param_1[0x54];
  *(int *)(lVar7 + 0x2684) = iVar17;
  *(undefined4 *)(lVar7 + 0x100c) = *(undefined4 *)(lVar13 + 0x1091c);
  *(undefined8 *)(lVar7 + 0x1040) = *(undefined8 *)(lVar13 + 0x10910);
  *(undefined4 *)(lVar7 + 0x1048) = *(undefined4 *)(lVar13 + 0x10918);
  *(uint *)(lVar7 + 0x1060) = *(uint *)(lVar13 + 0x5c8) >> 0x14 & 1;
  *(undefined4 *)(lVar7 + 0x2688) = 0;
  *(undefined8 *)(lVar7 + 0x106c) = 0;
  *(undefined8 *)(lVar7 + 0x1078) = 0;
  *(undefined4 *)(lVar7 + 0x1080) = 0;
  *(undefined4 *)(lVar7 + 0x10b0) = 0;
  *(uint *)(lVar7 + 0x109c) = *(uint *)(lVar13 + 0x5c8) >> 0x18 & 1;
  uVar12 = *(uint *)(lVar7 + 0xff0);
  if (uVar12 < 2) {
    uVar12 = 1;
  }
  *(uint *)(lVar11 + 0x6e) = uVar12;
  *(undefined4 *)(lVar7 + 0x268c) = 1;
  *(uint *)(lVar7 + 0x1084) = (uint)((ulong)*(undefined8 *)(lVar13 + 0x5c8) >> 0x2c) & 1;
  lVar11 = **(long **)(lVar13 + 0x138);
  lVar13 = (**(code **)(lVar11 + 0x118))
                     (lVar11 + 0x118,*(long **)(lVar13 + 0x138),"gpu-noise-suppression");
  if ((lVar13 == 0) ||
     (plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(lVar13,*(undefined8 *)puVar2),
     plVar5 == (long *)0x0)) {
    lVar13 = param_1[0x69];
  }
  else {
    piVar6 = (int *)(**(code **)(*plVar5 + 0xd8))();
    lVar13 = param_1[0x69];
    if (*piVar6 != 0) {
      *(undefined4 *)(lVar13 + 0x3c) = 0;
    }
  }
  *(undefined4 *)(param_1[0x54] + 0x26cc) = 0;
  *(undefined4 *)(lVar13 + 0x44) = 0;
  *(undefined4 *)(lVar13 + 0x48) = 0;
  (**(code **)(*param_1 + 0x710))(param_1,1);
  puVar9 = (undefined8 *)(**(code **)(*(long *)param_1[0x28d] + 0x78))();
  *puVar9 = 0xc8a8052839204c8;
  puVar9[3] = param_1[0x105];
  puVar9[4] = param_1[0x6a];
  puVar9[0x15] = param_1[0x108];
  uVar8 = (**(code **)(*(long *)param_1[0x294] + 0x98))();
  uVar8 = (**(code **)(*param_1 + 0x208))(*param_1 + 0x208,param_1,uVar8,0);
  puVar9[1] = uVar8;
  lVar13 = *(long *)(param_1[0x50] + 0x189d0);
  uVar8 = *(undefined8 *)(lVar13 + 0x18);
  uVar18 = *(undefined8 *)(lVar13 + 0x20);
  uVar19 = *(undefined8 *)(lVar13 + 0x28);
  uVar22 = *(undefined8 *)(lVar13 + 0x40);
  uVar21 = *(undefined8 *)(lVar13 + 0x38);
  puVar9[9] = *(undefined8 *)(lVar13 + 0x30);
  puVar9[8] = uVar19;
  puVar9[0xb] = uVar22;
  puVar9[10] = uVar21;
  puVar9[7] = uVar18;
  puVar9[6] = uVar8;
  uVar8 = *(undefined8 *)(lVar13 + 0x48);
  uVar18 = *(undefined8 *)(lVar13 + 0x50);
  uVar21 = *(undefined8 *)(lVar13 + 0x60);
  uVar19 = *(undefined8 *)(lVar13 + 0x58);
  uVar23 = *(undefined8 *)(lVar13 + 0x70);
  uVar22 = *(undefined8 *)(lVar13 + 0x68);
  puVar9[0x12] = *(undefined8 *)(lVar13 + 0x78);
  puVar9[0xf] = uVar21;
  puVar9[0xe] = uVar19;
  puVar9[0x11] = uVar23;
  puVar9[0x10] = uVar22;
  puVar9[0xd] = uVar18;
  puVar9[0xc] = uVar8;
  puVar9[5] = DAT_fffffff007113ec0;
  lVar11 = (**(code **)(*(long *)param_1[0x28d] + 0x78))();
  lVar7 = (**(code **)(*(long *)param_1[0x28d] + 0x78))();
  lVar13 = 0;
  *(long *)(lVar11 + 0xb0) = param_1[0x124];
  *(long *)(lVar7 + 0xb8) = param_1[0x125];
  *(long *)(lVar7 + 0xc0) = param_1[0x6c];
  lVar7 = param_1[0x50];
  lVar11 = 0x648;
  do {
    pbVar1 = (byte *)(lVar7 + 0x678 + lVar13 * 0x438);
    if (((*(long *)(pbVar1 + 8) == 0) || (*(int *)(pbVar1 + 0x208) == 0)) || ((*pbVar1 & 1) != 0)) {
      *(undefined8 *)(param_1[0x54] + lVar13 * 0x28 + 0x648) = 0;
    }
    else if (lVar11 == 0xcb0) {
      *(undefined8 *)(param_1[0x54] + 0xcb0) = 0;
    }
    else {
      lVar10 = (**(code **)(*(long *)param_1[lVar13 + 0x29e] + 0x98))();
      uVar8 = (**(code **)(*param_1 + 0x208))
                        (param_1,lVar10 + (ulong)*(uint *)((long)param_1 + lVar13 * 4 + 0x16d0),0);
      *(undefined8 *)(param_1[0x54] + lVar13 * 0x28 + 0x648) = uVar8;
    }
    lVar13 = lVar13 + 1;
    lVar11 = lVar11 + 0x28;
  } while (lVar11 != 0xfa8);
  if ((long *)param_1[0x2f8] != (long *)0x0) {
    uVar8 = (**(code **)(*(long *)param_1[0x2f8] + 0x98))();
    uVar8 = (**(code **)(*param_1 + 0x208))(param_1,uVar8,0);
    *(undefined8 *)(param_1[0x54] + 4000) = uVar8;
  }
  uVar4 = (**(code **)(*(long *)param_1[0x50] + 0x768))();
  lVar13 = param_1[0x54];
  *(undefined4 *)(lVar13 + 0x10a4) = uVar4;
  lVar11 = param_1[0x50];
  *(undefined8 *)(lVar13 + 0x10a8) = *(undefined8 *)(lVar11 + 0x10920);
  *(uint *)(lVar13 + 0x26b0) = (uint)((ulong)*(undefined8 *)(lVar11 + 0x5c8) >> 0x24) & 1;
  *(undefined4 *)(lVar13 + 0x26b4) = 1;
  *(undefined8 *)(lVar13 + 0x26d8) = 0xffffffffffffffff;
  *(undefined8 *)(lVar13 + 0x26d0) = 0xffffffffffffffff;
  *(undefined8 *)(lVar13 + 0x26e8) = 0xffffffffffffffff;
  *(undefined8 *)(lVar13 + 0x26e0) = 0xffffffffffffffff;
  *(undefined8 *)(lVar13 + 0x26f8) = 0xffffffffffffffff;
  *(undefined8 *)(lVar13 + 0x26f0) = 0xffffffffffffffff;
  *(undefined4 *)(lVar13 + 0x2700) = 0;
  *(uint *)(lVar13 + 0x26c8) = *(uint *)(lVar11 + 0x5c8) >> 7 & 1;
  *(undefined4 *)(lVar13 + 0x275c) = *(undefined4 *)(lVar11 + 0x5e0);
  *(undefined1 *)(lVar13 + 0x2760) = *(undefined1 *)(lVar11 + 0x5e8);
  *(undefined1 *)(lVar13 + 0x2761) = *(undefined1 *)(lVar11 + 0x5f0);
  uVar14 = *(ulong *)(lVar11 + 0x5c8);
  *(uint *)(lVar13 + 0x26b8) = (uint)(uVar14 >> 0x25) & 1;
  if ((uVar14 >> 0x25 & 1) != 0) {
    *(undefined4 *)(lVar13 + 0x26bc) = 0;
  }
  *(undefined8 *)(lVar13 + 0x26c0) = 0x100000001;
  uVar8 = (**(code **)(*param_1 + 0x470))(param_1);
  (**(code **)(*param_1 + 0x460))(*param_1 + 0x460,param_1,uVar8);
  uVar8 = (**(code **)(*param_1 + 0x4a8))(*param_1 + 0x4a8,param_1);
  (**(code **)(*param_1 + 0x498))(*param_1 + 0x498,param_1,uVar8);
  uVar8 = (**(code **)(*param_1 + 0x478))(*param_1 + 0x478,param_1);
  (**(code **)(*param_1 + 0x4a0))(*param_1 + 0x4a0,param_1,uVar8);
  (**(code **)(*param_1 + 0x4b0))(*param_1 + 0x4b0,param_1,1);
  uVar8 = (**(code **)(*param_1 + 0x490))(*param_1 + 0x490,param_1);
  (**(code **)(*param_1 + 0x480))(*param_1 + 0x480,param_1,uVar8);
  uVar8 = (**(code **)(*param_1 + 0x4c8))(*param_1 + 0x4c8,param_1);
  (**(code **)(*param_1 + 0x4c0))(*param_1 + 0x4c0,param_1,uVar8);
  plVar5 = (long *)param_1[0x50];
  if ((*(byte *)((long)plVar5 + 0x5d1) >> 1 & 1) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (**(code **)(*plVar5 + 0xd50))();
    plVar5 = (long *)param_1[0x50];
  }
  *(undefined4 *)(param_1[0x69] + 0xe08) = uVar4;
  lVar13 = param_1[0x54];
  *(undefined8 *)(lVar13 + 0x2720) = 0x100000000;
  *(int *)(param_1[0x122] + 0x6c2c) = (int)plVar5[0xbb];
  *(uint *)(lVar13 + 0x2728) = (uint)((ulong)plVar5[0xb9] >> 0x35) & 1;
  *(undefined8 *)(lVar13 + 0x2754) = 1;
  *(undefined4 *)(lVar13 + 0x2772) = 0;
  *(int *)(lVar13 + 0x2776) = (int)plVar5[0x2224];
  (**(code **)(*param_1 + 0x160))(*param_1 + 0x160,param_1,3);
  lVar13 = param_1[0x50];
  lVar11 = param_1[0x54];
  *(uint *)(lVar11 + 0x277e) = *(byte *)(lVar13 + 0x11128) & 1;
  *(uint *)(lVar11 + 0x2782) = *(byte *)(lVar13 + 0x11138) & 1;
  (**(code **)(*param_1 + 0x1b8))(*param_1 + 0x1b8,param_1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081ce730. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xf0))(param_1,(undefined8 *)(*param_1 + 0xf0));
    return;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ce728);
  (*pcVar3)();
}

