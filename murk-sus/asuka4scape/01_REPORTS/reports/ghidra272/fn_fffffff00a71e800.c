// FUN_fffffff00a71e800 @ fffffff00a71e800 size=2596

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long FUN_fffffff00a71e800(long param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  ulong uVar13;
  int *piVar14;
  long *plVar15;
  uint *puVar16;
  undefined8 uVar17;
  long lVar18;
  undefined4 in_wzr;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined4 local_f0;
  undefined4 local_ec;
  int local_e8;
  long local_e0;
  long local_d8;
  undefined8 local_d0;
  long lStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  ulong local_b0;
  long local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  ulong local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined4 local_6c [3];
  
  lVar2 = tpidr_el1;
  lVar7 = FUN_fffffff00a292e20(*DAT_fffffff007c08000,DAT_fffffff007c08000[1],4);
  uVar8 = FUN_fffffff00a2216c4(&DAT_fffffff007c78b10,4);
  *(undefined8 *)(lVar7 + 0x178) = uVar8;
  FUN_fffffff00aa65b10(lVar7 + 400,param_1 + 400,0x2a0);
  puVar16 = (uint *)(lVar7 + 0x454);
  puVar16[0] = 0x101;
  puVar16[1] = 1;
  uVar3 = *puVar16;
  *puVar16 = uVar3 | 0x40;
  puVar9 = (undefined8 *)
           FUN_fffffff00a2216c4
                     (CONCAT44((int)((ulong)puVar16 >> 0x20),uVar3),&DAT_fffffff007c6d4d0,0);
  puVar9[1] = 0;
  *puVar9 = 0;
  puVar9[3] = 0;
  puVar9[2] = 0;
  puVar9[5] = 0;
  puVar9[4] = 0;
  puVar9[7] = 0;
  puVar9[6] = 0;
  puVar9[9] = 0;
  puVar9[10] = 0;
  puVar9[0xb] = FUN_fffffff00a761e28;
  puVar9[0xc] = lVar7;
  puVar9[0xe] = 0;
  puVar9[0xf] = 0;
  puVar9[0xd] = 0;
  puVar9[8] = 0x102010001;
  *(undefined8 **)(lVar7 + 0x658) = puVar9;
  FUN_fffffff00a6ed9d8(lVar7);
  uVar13 = (ulong)*(uint *)(lVar2 + 0x4e8);
  lVar10 = DAT_fffffff007c6b250;
  if (_DAT_fffffff00ad8a320 != 0) {
    FUN_fffffff00a2262d4(&DAT_fffffff00ad8a318,lVar2,0);
    uVar13 = _DAT_fffffff00ad8a320;
    lVar10 = DAT_fffffff007c6b250;
  }
  _DAT_fffffff00ad8a320 = uVar13;
  DAT_fffffff007c6b250 = lVar10;
  if ((param_2 >> 2 & 1) == 0) {
    uVar3 = 100;
    if ((int)DAT_fffffff00add42a8 < 0x1869e) {
      uVar3 = DAT_fffffff00add42a8 + 1;
    }
    do {
      if (uVar3 == 0) {
        if (lVar10 == 0) {
          uVar4 = 0;
LAB_fffffff00a71ea34:
          plVar15 = (long *)((DAT_fffffff00add42e8 | 0xff000000000000) +
                            (ulong)(uVar4 & (uint)(0xffffffffffffffff >>
                                                  (DAT_fffffff00add42e8 >> 0x30 & 0x3f))) * 8);
          do {
            plVar15 = (long *)*plVar15;
            if (plVar15 == (long *)0x0) goto LAB_fffffff00a71ea68;
          } while (uVar3 != *(uint *)(plVar15 + 3));
          if (plVar15 == (long *)0x10) {
LAB_fffffff00a71ea68:
            lVar11 = *(long *)(DAT_fffffff007c07f30 + (DAT_fffffff007c07f38 & (long)(int)uVar3) * 8)
            ;
            while( true ) {
              if (lVar11 == 0) {
                DAT_fffffff00ad95120 = DAT_fffffff00ad95120 + 1;
                DAT_fffffff00add42a8 = uVar3;
                *(uint *)(lVar7 + 0x60) = uVar3;
                local_e8 = DAT_fffffff00ad8a2ac;
                local_e0 = DAT_fffffff00add42a0 + 1;
                if (param_1 == lVar10) {
                  local_ec = 0;
                }
                else {
                  local_ec = *(undefined4 *)(param_1 + 0x60);
                }
                DAT_fffffff00ad8a2ac = DAT_fffffff00ad8a2ac + 1;
                DAT_fffffff00add42a0 = local_e0;
                local_f0 = FUN_fffffff00a724fc0(param_1);
                uVar13 = DAT_fffffff00add42d8 | 0xff000000000000;
                uVar3 = (*(uint *)(lVar7 + 0x60) ^ *(uint *)(lVar7 + 0x60) >> 0x10) * 0x7feb352d;
                uVar3 = (uVar3 ^ uVar3 >> 0xf) * -0x7b935975;
                uVar3 = (uVar3 ^ uVar3 >> 0x10) &
                        (uint)(0xffffffffffffffff >> (DAT_fffffff00add42d8 >> 0x30 & 0x3f));
                DAT_fffffff00add42e0 = DAT_fffffff00add42e0 + 1;
                *(undefined8 *)(lVar7 + 0xa0) = *(undefined8 *)(uVar13 + (ulong)uVar3 * 8);
                DataMemoryBarrier(2,3);
                *(undefined8 **)(uVar13 + (ulong)uVar3 * 8) = (undefined8 *)(lVar7 + 0xa0);
                uVar3 = *(uint *)(param_1 + 0x450);
                uVar13 = (ulong)uVar3;
                if ((uVar3 >> 2 & 1) != 0) {
                  *(uint *)(lVar7 + 0x450) = *(uint *)(lVar7 + 0x450) | 4;
                }
                if ((uVar3 >> 3 & 1) == 0) goto LAB_fffffff00a71eb6c;
                puVar16 = (uint *)(lVar7 + 0x450);
                uVar3 = 8;
                goto LAB_fffffff00a71eb68;
              }
              if (*(uint *)(lVar11 + 0x44) == uVar3) break;
              lVar11 = *(long *)(lVar11 + 0x10);
            }
          }
        }
      }
      else {
        uVar4 = (uVar3 ^ uVar3 >> 0x10) * 0x7feb352d;
        uVar4 = (uVar4 ^ uVar4 >> 0xf) * -0x7b935975;
        uVar4 = uVar4 ^ uVar4 >> 0x10;
        plVar15 = (long *)((DAT_fffffff00add42d8 | 0xff000000000000) +
                          (ulong)(uVar4 & (uint)(0xffffffffffffffff >>
                                                (DAT_fffffff00add42d8 >> 0x30 & 0x3f))) * 8);
        do {
          plVar15 = (long *)*plVar15;
          if (plVar15 == (long *)0x0) goto LAB_fffffff00a71ea34;
        } while (uVar3 != *(uint *)(plVar15 + -8));
      }
      uVar4 = 100;
      if ((int)uVar3 < 0x1869e) {
        uVar4 = uVar3 + 1;
      }
      uVar3 = uVar4;
      if (uVar4 == DAT_fffffff00add42a8) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114("Unable to allocate a new pid @%s:%d");
      }
    } while( true );
  }
  *(undefined4 *)(lVar7 + 0x60) = *(undefined4 *)(param_1 + 0x60);
  local_e8 = *(int *)(*(long *)(param_1 + 0x18) + 0x18);
  local_e0 = *(long *)(*(long *)(param_1 + 0x18) + 0x10);
  local_ec = FUN_fffffff00a72633c(param_1);
  local_f0 = FUN_fffffff00a7264c0(param_1);
  DAT_fffffff00ad95120 = DAT_fffffff00ad95120 + 1;
  puVar16 = (uint *)(lVar7 + 0x454);
  uVar3 = 0x20;
LAB_fffffff00a71eb68:
  uVar4 = *puVar16;
  *puVar16 = uVar4 | uVar3;
  uVar13 = CONCAT44((int)((ulong)puVar16 >> 0x20),uVar4);
LAB_fffffff00a71eb6c:
  lVar10 = FUN_fffffff00a72a9c8(uVar13,param_1,lVar7);
  if (DAT_fffffff00ad8a320 == *(int *)(lVar2 + 0x4e8)) {
    _DAT_fffffff00ad8a320 = CONCAT44(DAT_fffffff00ad8a320_4,in_wzr);
  }
  else {
    FUN_fffffff00a226e08(&DAT_fffffff00ad8a318,lVar2);
  }
  if (local_e0 == 300) {
    DAT_fffffff00ad1e6a4 = 0;
  }
  if (*(byte *)(lVar7 + 0xe09) < 4) {
    *(undefined2 *)(lVar7 + 0xe08) = 0x201;
    *(undefined1 *)(lVar7 + 100) = 1;
  }
  uVar8 = *(undefined8 *)(param_1 + 0x528);
  *(undefined8 *)(lVar7 + 0x530) = *(undefined8 *)(param_1 + 0x530);
  *(undefined8 *)(lVar7 + 0x528) = uVar8;
  plVar15 = (long *)(lVar7 + 0x538);
  *(undefined8 *)(lVar7 + 0x538) = *(undefined8 *)(param_1 + 0x538);
  uVar8 = *(undefined8 *)(param_1 + 0x540);
  *(undefined8 *)(lVar7 + 0x548) = *(undefined8 *)(param_1 + 0x548);
  *(undefined8 *)(lVar7 + 0x540) = uVar8;
  uVar17 = *(undefined8 *)(param_1 + 0x558);
  uVar8 = *(undefined8 *)(param_1 + 0x550);
  uVar19 = *(undefined8 *)(param_1 + 0x568);
  uVar12 = *(undefined8 *)(param_1 + 0x560);
  uVar21 = *(undefined8 *)(param_1 + 0x578);
  uVar20 = *(undefined8 *)(param_1 + 0x570);
  uVar22 = *(undefined8 *)(param_1 + 0x580);
  *(undefined8 *)(lVar7 + 0x588) = *(undefined8 *)(param_1 + 0x588);
  *(undefined8 *)(lVar7 + 0x580) = uVar22;
  *(undefined8 *)(lVar7 + 0x578) = uVar21;
  *(undefined8 *)(lVar7 + 0x570) = uVar20;
  *(undefined8 *)(lVar7 + 0x568) = uVar19;
  *(undefined8 *)(lVar7 + 0x560) = uVar12;
  *(undefined8 *)(lVar7 + 0x558) = uVar17;
  *(undefined8 *)(lVar7 + 0x550) = uVar8;
  uVar17 = *(undefined8 *)(param_1 + 0x598);
  uVar8 = *(undefined8 *)(param_1 + 0x590);
  uVar19 = *(undefined8 *)(param_1 + 0x5a8);
  uVar12 = *(undefined8 *)(param_1 + 0x5a0);
  uVar21 = *(undefined8 *)(param_1 + 0x5b8);
  uVar20 = *(undefined8 *)(param_1 + 0x5b0);
  *(undefined8 *)(lVar7 + 0x5c0) = *(undefined8 *)(param_1 + 0x5c0);
  *(undefined8 *)(lVar7 + 0x5b8) = uVar21;
  *(undefined8 *)(lVar7 + 0x5b0) = uVar20;
  *(undefined8 *)(lVar7 + 0x5a8) = uVar19;
  *(undefined8 *)(lVar7 + 0x5a0) = uVar12;
  *(undefined8 *)(lVar7 + 0x598) = uVar17;
  *(undefined8 *)(lVar7 + 0x590) = uVar8;
  if ((param_2 & 1) != 0) {
    if (*(long *)(param_1 + 0x678) != 0) {
      uVar8 = FUN_fffffff00a220c30(&DAT_fffffff007c6afb0,0x400,0x8004,0);
      *(undefined8 *)(lVar7 + 0x678) = uVar8;
      FUN_fffffff00a354958(uVar8,*(undefined8 *)(param_1 + 0x678),0x400);
    }
    *(byte *)(lVar7 + 0x6cc) = *(byte *)(param_1 + 0x6cc) & 1;
  }
  uVar8 = FUN_fffffff00a727bd4(param_1);
  lVar11 = FUN_fffffff00a726430(param_1);
  uVar17 = *(undefined8 *)(lVar11 + 0x40);
  uVar3 = *(uint *)(lVar11 + 0x48);
  *(uint *)(lVar7 + 0x444) = *(uint *)(param_1 + 0x444) & 0x31104;
  *(ushort *)(lVar7 + 0x616) = *(ushort *)(param_1 + 0x616) & 0xdeff;
  *(undefined4 *)(lVar7 + 0x44) = *(undefined4 *)(param_1 + 0x44);
  uVar4 = FUN_fffffff00a727a98(param_1);
  if (((lVar7 != 0) &&
      (iVar5 = *(int *)(param_1 + 0x524), *(int *)(lVar7 + 0x524) = iVar5, -1 < iVar5)) &&
     (lVar11 = FUN_fffffff00a72456c(), lVar11 != 0)) {
    uVar12 = *(undefined8 *)(lVar11 + 0x598);
    *(undefined8 *)(lVar7 + 0x5b8) = *(undefined8 *)(lVar11 + 0x5a0);
    *(undefined8 *)(lVar7 + 0x5b0) = uVar12;
    FUN_fffffff00a724838();
  }
  local_d8 = 0;
  lVar11 = FUN_fffffff00a29b24c();
  FUN_fffffff00a6e9e40(&local_d8,*(undefined8 *)(lVar11 + 8));
  lVar11 = local_d8;
  uVar6 = DAT_fffffff00ad24378;
  *(uint *)(lVar7 + 0x50) = DAT_fffffff00ad24378 & 0xffffff | 0x22000000;
  *(undefined4 *)(lVar7 + 0x54) = 0;
  *(undefined8 *)(lVar7 + 0x58) = 0;
  uVar1 = DAT_fffffff00ad24270;
  DAT_fffffff00ad24384 = DAT_fffffff00ad24384 + 1;
  if (((int)uVar6 < 0) &&
     (iVar5 = DAT_fffffff00ad24374 + 1, uVar6 = DAT_fffffff00ad24374 + 0xf0000001,
     DAT_fffffff00ad24374 = iVar5, uVar6 < 0xf0000002)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa61ed0(&DAT_fffffff00ad24374);
  }
  *(uint *)(lVar7 + 0xc0) = DAT_fffffff00ad24270 & 0xffffff | 0x22000000;
  *(undefined4 *)(lVar7 + 0xc4) = 0;
  *(undefined8 *)(lVar7 + 200) = 0;
  DAT_fffffff00ad2427c = DAT_fffffff00ad2427c + 1;
  if (((int)uVar1 < 0) &&
     (iVar5 = DAT_fffffff00ad2426c + 1, uVar1 = DAT_fffffff00ad2426c + 0xf0000001,
     DAT_fffffff00ad2426c = iVar5, uVar1 < 0xf0000002)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa61ed0(&DAT_fffffff00ad2426c);
  }
  *(undefined8 *)(lVar7 + 0x438) = 0x11;
  *(undefined8 *)(lVar7 + 0x430) = 0;
  DAT_fffffff00ad242cc = DAT_fffffff00ad242cc + 1;
  if ((DAT_fffffff00ad242c8 < 0) &&
     (iVar5 = DAT_fffffff00ad242c4 + 1, uVar1 = DAT_fffffff00ad242c4 + 0xf0000001,
     DAT_fffffff00ad242c4 = iVar5, uVar1 < 0xf0000002)) {
    piVar14 = &DAT_fffffff00ad242c4;
    goto LAB_fffffff00a71f204;
  }
  *(undefined8 *)(lVar7 + 0x5e8) = 0;
  lVar18 = *(long *)(lVar7 + 0x538);
  if ((lVar18 != 0) && (lVar18 != 0)) {
    iVar5 = FUN_fffffff00a3ec1d8(lVar18);
    if (iVar5 == 0) {
      lVar18 = *plVar15;
      if (lVar18 == 0) {
        lVar18 = 0;
      }
      iVar5 = FUN_fffffff00a3ebd30(lVar18,0,0);
      if (*plVar15 == 0) {
        FUN_fffffff00a3e8aa8(0);
      }
      else {
        FUN_fffffff00a3e8aa8(*plVar15);
      }
      if (iVar5 == 0) goto LAB_fffffff00a71ee70;
    }
    *plVar15 = 0;
  }
LAB_fffffff00a71ee70:
  uVar1 = 0xfefffffb;
  uVar6 = FUN_fffffff00a7266f8(param_1);
  if ((param_2 & 1) != 0) {
    uVar1 = 0xfeffffff;
  }
  uStack_78 = 0;
  local_80 = 0;
  uStack_88 = 0;
  local_90 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  local_a8 = 0;
  local_b0 = 0;
  lStack_c8 = 0;
  local_d0 = 0;
  uVar12 = FUN_fffffff00a297e2c(5,0x8004);
  if (lVar7 != 0) {
    lStack_c8 = local_e0;
    local_c0 = CONCAT44(local_ec,local_e8);
    uStack_b8 = CONCAT44(uVar6 & uVar1,local_f0);
    local_b0 = (ulong)(uVar4 & 0x7ff);
    local_a8 = lVar11;
    local_90 = (ulong)uVar3;
    local_d8 = lVar7;
    local_a0 = uVar8;
    uStack_98 = uVar17;
    FUN_fffffff00a297f64(5,uVar12,0,&local_d8,0x68);
  }
  *(undefined8 *)(lVar7 + 0x18) = uVar12;
  lVar11 = FUN_fffffff00a7272a0(lVar7);
  *(undefined4 *)(lVar7 + 0x28) = *(undefined4 *)(lVar11 + 0x18);
  *(undefined4 *)(lVar7 + 0x2c) = *(undefined4 *)(lVar11 + 0x28);
  *(undefined4 *)(lVar7 + 0x30) = *(undefined4 *)(lVar11 + 0x1c);
  *(undefined4 *)(lVar7 + 0x34) = *(undefined4 *)(lVar11 + 0x68);
  *(undefined4 *)(lVar7 + 0x38) = *(undefined4 *)(lVar11 + 0x20);
  *(undefined4 *)(lVar7 + 0x3c) = *(undefined4 *)(lVar11 + 0x6c);
  iVar5 = FUN_fffffff00a6ee84c(lVar7 + 0xd0,param_1,*(undefined8 *)(lVar2 + 0x730),param_2 >> 2 & 1)
  ;
  if (iVar5 == 0) {
    FUN_fffffff00a73430c(param_1,lVar7);
    uVar13 = FUN_fffffff00a7341bc(lVar7,0);
    if (uVar13 != 0x7fffffffffffffff) {
      if (0x7ffffffe < uVar13) {
        uVar13 = 0x7fffffff;
      }
      *(ulong *)(lVar7 + 0x4e0) = uVar13;
    }
    if ((param_2 >> 2 & 1) == 0) {
      FUN_fffffff00a20760c(&local_d8,local_6c,*(long *)(lVar7 + 0x178) + 0x148);
      *(long *)(lVar7 + 0x648) = local_d8;
    }
    else {
      *(undefined8 *)(*(long *)(lVar7 + 0x178) + 0x148) =
           *(undefined8 *)(*(long *)(param_1 + 0x178) + 0x148);
      *(undefined8 *)(lVar7 + 0x648) = *(undefined8 *)(param_1 + 0x648);
      local_6c[0] = *(undefined4 *)(param_1 + 0x650);
    }
    *(undefined4 *)(lVar7 + 0x650) = local_6c[0];
    uVar13 = 0;
    if ((*(long *)(*(long *)(lVar10 + 0x20) + 0x28) != 0) &&
       (uVar13 = (ulong)*(byte *)(param_1 + 0x444), (*(byte *)(param_1 + 0x444) >> 1 & 1) != 0)) {
      puVar16 = (uint *)(lVar7 + 0x444);
      uVar3 = *puVar16;
      *puVar16 = uVar3 | 2;
      uVar13 = CONCAT44((int)((ulong)puVar16 >> 0x20),uVar3);
    }
    FUN_fffffff00a737d30(uVar13,lVar7,0);
    FUN_fffffff00a72cd24(lVar7,0,0);
    *(undefined8 *)(lVar7 + 0x90) = 0;
    *(undefined4 *)(lVar7 + 0x594) = 0;
    *(undefined8 **)(lVar7 + 0x98) = (undefined8 *)(lVar7 + 0x90);
    *(undefined8 *)(lVar7 + 0x5c8) = 0;
    *(long *)(lVar7 + 0x5d0) = lVar7 + 0x5c8;
    *(undefined8 *)(lVar7 + 0x5d8) = 0;
    *(long *)(lVar7 + 0x5e0) = lVar7 + 0x5d8;
    *(undefined8 *)(lVar7 + 0x620) = *(undefined8 *)(param_1 + 0x620);
    *(undefined8 *)(lVar7 + 0x618) = *(undefined8 *)(param_1 + 0x618);
    *(undefined4 *)(lVar7 + 0x628) = *(undefined4 *)(param_1 + 0x628);
    if (*(char *)(param_1 + 0x44a) < '\0') {
      *(uint *)(lVar7 + 0x448) = *(uint *)(lVar7 + 0x448) | 0x800000;
    }
    uVar8 = *(undefined8 *)(param_1 + 0x680);
    *(undefined8 *)(lVar7 + 0x688) = *(undefined8 *)(param_1 + 0x688);
    *(undefined8 *)(lVar7 + 0x680) = uVar8;
    uVar8 = *(undefined8 *)(param_1 + 0x690);
    *(undefined8 *)(lVar7 + 0x698) = *(undefined8 *)(param_1 + 0x698);
    *(undefined8 *)(lVar7 + 0x690) = uVar8;
    *(undefined4 *)(lVar7 + 0x62c) = *(undefined4 *)(param_1 + 0x62c);
    uVar8 = *(undefined8 *)(param_1 + 0x6a0);
    *(undefined8 *)(lVar7 + 0x6a8) = *(undefined8 *)(param_1 + 0x6a8);
    *(undefined8 *)(lVar7 + 0x6a0) = uVar8;
    *(undefined8 *)(lVar7 + 0x6b0) = *(undefined8 *)(param_1 + 0x6b0);
    (**(code **)(DAT_fffffff007c06630 + 0x40))(lVar7);
    *(undefined8 *)(lVar7 + 0xa8) = 0;
    if (((*(long *)(param_1 + 0xa8) == 0) || (lVar10 = FUN_fffffff00a721e04(param_1), lVar10 == 0))
       || (iVar5 = FUN_fffffff00a722bb8(lVar7,lVar10,0), iVar5 == 0)) {
      uVar8 = _DAT_fffffff00700f960;
      *(undefined8 *)(lVar7 + 0x6d8) = _UNK_fffffff00700f968;
      *(undefined8 *)(lVar7 + 0x6d0) = uVar8;
      *(undefined8 *)(lVar7 + 0x6f8) = 0;
      lVar10 = *(long *)(*(long *)(lVar2 + 0x1b8) + 0x58);
      do {
        lVar18 = lVar10;
        lVar11 = UnkSytemRegRead(3,4,0xf,10,6);
        lVar10 = *(long *)(*(long *)(lVar2 + 0x1b8) + 0x58);
      } while (lVar10 != lVar18);
      *(long *)(lVar7 + 0x708) = lVar11 + lVar18;
      *(undefined8 *)(lVar7 + 0x710) = 0;
      *(undefined8 *)(lVar7 + 0x720) = 0;
      *(undefined8 *)(lVar7 + 0x718) = 0;
      *(undefined4 *)(lVar7 + 0x728) = 0;
      *(undefined4 *)(lVar7 + 0x6e0) = 0;
      *(undefined8 *)(lVar7 + 0x700) = 0;
      piVar14 = *(int **)(param_1 + 0x760);
      if (piVar14 == (int *)0x0) {
        return lVar7;
      }
      iVar5 = *piVar14;
      *piVar14 = iVar5 + 1;
      if (0xf0000001 < iVar5 + 0xf0000001U) {
        *(int **)(lVar7 + 0x760) = piVar14;
        return lVar7;
      }
LAB_fffffff00a71f204:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa61ed0(piVar14);
    }
  }
  FUN_fffffff00a71f424(lVar7);
  return 0;
}

