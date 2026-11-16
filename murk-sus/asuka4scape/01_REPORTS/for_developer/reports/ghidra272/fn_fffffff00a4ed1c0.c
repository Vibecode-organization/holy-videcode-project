// FUN_fffffff00a4ed1c0 @ fffffff00a4ed1c0 size=11308

/* WARNING: Type propagation algorithm not settling */

ulong FUN_fffffff00a4ed1c0
                (long param_1,int param_2,int param_3,ulong param_4,undefined1 *param_5,int param_6,
                int param_7,undefined8 param_8,ulong param_9,ulong param_10,char param_11,
                long param_12,undefined8 param_13,undefined8 param_14,undefined8 param_15,
                short param_16,undefined8 param_17,long param_18,long param_19,ulong param_20,
                undefined8 param_21,char param_22,long param_23,undefined8 param_24,long param_25,
                ulong param_26,ulong param_27,undefined8 param_28,long param_29,char param_30,
                ulong param_31)

{
  long lVar1;
  byte bVar2;
  char cVar3;
  short sVar4;
  undefined8 uVar5;
  code *pcVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  long lVar12;
  ushort uVar13;
  ulong uVar14;
  long lVar15;
  ushort uVar16;
  long lVar17;
  short sVar18;
  
  uVar5 = DAT_fffffff00ad7ce10;
  uVar14 = *(ulong *)(param_1 + 0x20);
  if ((uVar14 & 1) == 0) {
    if (((uint)uVar14 >> 1 & 1) != 0) {
      if (*(long *)(param_1 + 0x70) == 0) {
        uVar11 = 0;
        if (2 < param_26._4_4_) goto LAB_fffffff00a4ed4cc;
LAB_fffffff00a4ed90c:
        bVar2 = *(byte *)(param_1 + 0x28);
      }
      else {
        uVar11 = (uint)*(ushort *)(*(long *)(param_1 + 0x70) + 0xcc);
        if (param_26._4_4_ < 3) goto LAB_fffffff00a4ed90c;
LAB_fffffff00a4ed4cc:
        uVar14 = param_31 & 0x7ffffffffff;
        if ((param_31 & 0x80000000000000) != 0) {
          uVar14 = param_31 | 0xffffff8000000000;
        }
        if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
            (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
           ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
          FUN_fffffff00a396010();
        }
        else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,uVar5,0x10,
                   "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                  );
        bVar2 = *(byte *)(param_1 + 0x28);
      }
      if ((bVar2 >> 1 & 1) == 0) {
        if ((uint)param_15 != uVar11) {
          return 0;
        }
      }
      else if ((uint)param_15 == uVar11) {
        return 0;
      }
    }
    uVar5 = DAT_fffffff00ad7ce10;
    if ((*(byte *)(param_1 + 0x24) >> 6 & 1) != 0) {
      if (2 < param_26._4_4_) {
        uVar14 = param_31 & 0x7ffffffffff;
        if ((param_31 & 0x80000000000000) != 0) {
          uVar14 = param_31 | 0xffffff8000000000;
        }
        if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
            (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
           ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
          FUN_fffffff00a396010(uVar14);
        }
        else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4(uVar14);
        }
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,uVar5,0x10,
                   "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                  );
        uVar5 = DAT_fffffff00ad7ce10;
        if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
            (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
           ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
          FUN_fffffff00a396010(uVar14);
        }
        else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4(uVar14);
        }
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,uVar5,0x10,
                   "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                  );
        uVar5 = DAT_fffffff00ad7ce10;
        if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
            (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
           ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
          FUN_fffffff00a396010(uVar14);
        }
        else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4(uVar14);
        }
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,uVar5,0x10,
                   "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                  );
      }
      uVar11 = *(uint *)(param_1 + 0x160);
      if ((*(byte *)(param_1 + 0x2c) >> 6 & 1) == 0) {
        if ((uVar11 != 0) && ((uVar11 & param_27._4_4_) == 0)) {
          return 0;
        }
        if ((*(uint *)(param_1 + 0x164) != 0) &&
           ((*(uint *)(param_1 + 0x164) & (uint)param_28) == 0)) {
          return 0;
        }
        if ((*(uint *)(param_1 + 0x168) != 0) &&
           ((*(uint *)(param_1 + 0x168) & param_28._4_4_) == 0)) {
          return 0;
        }
      }
      else {
        if ((uVar11 & param_27._4_4_) != 0) {
          return 0;
        }
        if ((*(uint *)(param_1 + 0x164) & (uint)param_28) != 0) {
          return 0;
        }
        if ((*(uint *)(param_1 + 0x168) & param_28._4_4_) != 0) {
          return 0;
        }
      }
    }
    uVar5 = DAT_fffffff00ad7ce10;
    uVar14 = *(ulong *)(param_1 + 0x20);
    if ((uVar14 & 0x4000000002) == 0) {
      if (2 < param_26._4_4_) {
        uVar14 = param_31 & 0x7ffffffffff;
        if ((param_31 & 0x80000000000000) != 0) {
          uVar14 = param_31 | 0xffffff8000000000;
        }
        if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
            (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
           ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
          FUN_fffffff00a396010();
        }
        else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,uVar5,0x10,
                   "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                  );
      }
      if ((uint)param_15 != 0) {
        return 0;
      }
      uVar14 = *(ulong *)(param_1 + 0x20);
      if (uVar14 == 0) {
        return 1;
      }
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if (((uint)uVar14 >> 9 & 1) == 0) {
    uVar11 = (uint)*(undefined8 *)(param_1 + 0x28);
  }
  else {
    if (2 < param_26._4_4_) {
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
          (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
         ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
        FUN_fffffff00a396010();
      }
      else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
        FUN_fffffff00a1d12d4();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    bVar7 = param_2 != *(int *)(param_1 + 0x38);
    uVar11 = (uint)*(undefined8 *)(param_1 + 0x28);
    if ((uVar11 >> 9 & 1) == 0) {
      if (bVar7) {
        return 0;
      }
    }
    else if (!bVar7) {
      return 0;
    }
  }
  if (((uVar11 >> 0x1c & 1) != 0) || ((*(byte *)(param_1 + 0x23) >> 4 & 1) != 0)) {
    if (((param_4 & 1) == 0) && ((*(byte *)(param_1 + 0x21) >> 1 & 1) == 0)) {
      *param_5 = 1;
      return 0;
    }
    lVar12 = param_23;
    if (param_23 == 0) {
      lVar12 = FUN_fffffff00a29b24c(0);
      lVar12 = *(long *)(lVar12 + 0x18);
      if (lVar12 == 0) {
        lVar12 = DAT_fffffff007c6b250;
      }
    }
    lVar12 = FUN_fffffff00a6ed0b4(lVar12);
    uVar5 = DAT_fffffff00ad7ce10;
    if (2 < param_26._4_4_) {
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
          (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
         ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
        FUN_fffffff00a396010();
      }
      else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
        FUN_fffffff00a1d12d4();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value %s %s %s input %s %s %s>\n"
                );
    }
    if (lVar12 == 0) {
      uVar11 = (uint)*(undefined8 *)(param_1 + 0x28);
      if ((uVar11 >> 0x1c & 1) == 0) {
        return 0;
      }
    }
    else {
      uVar14 = FUN_fffffff00aa7451c(lVar12,*(undefined8 *)(param_1 + 0x148));
      uVar11 = (uint)*(undefined8 *)(param_1 + 0x28);
      if ((uVar11 >> 0x1c & 1) == 0) {
        if ((int)uVar14 != 0) {
          return 0;
        }
      }
      else if ((int)uVar14 == 0) {
        return uVar14;
      }
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((*(byte *)(param_1 + 0x21) >> 2 & 1) != 0) {
    if (2 < param_26._4_4_) {
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
          (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
         ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
        FUN_fffffff00a396010();
      }
      else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
        FUN_fffffff00a1d12d4();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
      uVar11 = (uint)*(undefined8 *)(param_1 + 0x28);
    }
    bVar7 = param_3 != *(int *)(param_1 + 0x3c);
    if ((uVar11 >> 10 & 1) == 0) {
      if (bVar7) {
        return 0;
      }
    }
    else if (!bVar7) {
      return 0;
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  uVar11 = (uint)*(undefined8 *)(param_1 + 0x20);
  if ((uVar11 >> 0x15 & 1) != 0) {
    if (2 < param_26._4_4_) {
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
          (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
         ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
        FUN_fffffff00a396010();
      }
      else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
        FUN_fffffff00a1d12d4();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if (param_20._4_1_ == '\0') {
      return 0;
    }
    uVar11 = (uint)*(undefined8 *)(param_1 + 0x20);
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((uVar11 >> 0x12 & 1) != 0) {
    if (2 < param_26._4_4_) {
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
          (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
         ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
        FUN_fffffff00a396010();
      }
      else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
        FUN_fffffff00a1d12d4();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if (param_6 == 0) {
      return 0;
    }
    uVar11 = (uint)*(undefined8 *)(param_1 + 0x20);
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((uVar11 >> 0x1a & 1) != 0) {
    if (2 < param_26._4_4_) {
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
          (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
         ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
        FUN_fffffff00a396010();
      }
      else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
        FUN_fffffff00a1d12d4();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if ((*(byte *)(param_1 + 0x2b) >> 2 & 1) == 0) {
      if (param_21._4_4_ == 0) {
        return 0;
      }
    }
    else if (param_21._4_4_ != 0) {
      return 0;
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  uVar14 = *(ulong *)(param_1 + 0x20);
  if ((uVar14 >> 0x22 & 1) != 0) {
    if (2 < param_26._4_4_) {
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (((uVar14 < DAT_fffffff007c6a360 && DAT_fffffff007c6a358 <= uVar14) ||
          (DAT_fffffff007c6a378 <= uVar14 && uVar14 < DAT_fffffff007c6a380)) ||
         ((DAT_fffffff007c6a3a0 <= uVar14 && (uVar14 < DAT_fffffff007c6a3a8)))) {
        FUN_fffffff00a396010();
      }
      else if (uVar14 + 0x2400000000 >> 0x25 == 0) {
        FUN_fffffff00a1d12d4();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if (param_22 == '\0') {
      return 0;
    }
    uVar14 = *(ulong *)(param_1 + 0x20);
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((param_23 != 0) && (((uint)uVar14 >> 0x1b & 1) != 0)) {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4(uVar14);
        }
      }
      else {
        FUN_fffffff00a396010(uVar14);
      }
      FUN_fffffff00a726898(param_23);
      FUN_fffffff00a726898(param_23);
      FUN_fffffff00a726938(param_23);
      FUN_fffffff00a726938(param_23);
      FUN_fffffff00a7269d8(param_23);
      FUN_fffffff00a7269d8(param_23);
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    iVar8 = *(int *)(param_1 + 0x139);
    if ((iVar8 != 0) && (iVar9 = FUN_fffffff00a726898(param_23), iVar8 != iVar9)) {
      return 0;
    }
    uVar11 = *(uint *)(param_1 + 0x13d);
    if ((uVar11 != 0) && (uVar10 = FUN_fffffff00a726938(param_23), uVar10 < uVar11)) {
      return 0;
    }
    uVar11 = *(uint *)(param_1 + 0x141);
    if ((uVar11 != 0) && (uVar10 = FUN_fffffff00a7269d8(param_23), uVar10 < uVar11)) {
      return 0;
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((*(ulong *)(param_1 + 0x20) >> 0x23 & 1) == 0) {
    if (((uint)*(ulong *)(param_1 + 0x20) >> 0xb & 1) != 0) {
      if (2 < param_26._4_4_) {
        iVar8 = FUN_fffffff00a4ecdf8(param_31);
        uVar14 = param_31 & 0x7ffffffffff;
        if ((param_31 & 0x80000000000000) != 0) {
          uVar14 = param_31 | 0xffffff8000000000;
        }
        if (iVar8 == 0) {
          if (uVar14 + 0x2400000000 >> 0x25 == 0) {
            FUN_fffffff00a1d12d4();
          }
        }
        else {
          FUN_fffffff00a396010();
        }
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,uVar5,0x10,
                   "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value %s %s %s input %s %s %s>\n"
                  );
      }
      uVar14 = FUN_fffffff00a4e5000
                         (param_9,param_10,param_11,*(undefined8 *)(param_1 + 0x50),
                          *(undefined1 *)(param_1 + 0x58));
      if ((param_31 != 0) && ((int)uVar14 != 0)) {
        *(uint *)(param_31 + 0x234) = *(uint *)(param_31 + 0x234) | 0x80000000;
      }
      if ((*(byte *)(param_1 + 0x29) >> 3 & 1) == 0) {
        if ((int)uVar14 == 0) {
          return uVar14;
        }
      }
      else {
LAB_fffffff00a4ee488:
        if ((uVar14 & 1) != 0) {
          return 0;
        }
      }
    }
  }
  else {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value %s %s %s input %s %s %s>\n"
                );
    }
    if (param_11 == *(char *)(param_1 + 0x58)) {
      uVar14 = FUN_fffffff00a4e5000
                         (param_9,param_10,param_11,*(undefined8 *)(param_1 + 0x50),param_11);
      if ((param_31 != 0) && ((int)uVar14 != 0)) {
        *(uint *)(param_31 + 0x234) = *(uint *)(param_31 + 0x234) | 0x80000000;
      }
      if ((*(byte *)(param_1 + 0x2c) >> 3 & 1) != 0) goto LAB_fffffff00a4ee488;
      if ((uVar14 & 1) == 0) {
        return 0;
      }
    }
    else if ((*(byte *)(param_1 + 0x2c) >> 3 & 1) == 0) {
      return 0;
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((*(byte *)(param_1 + 0x24) >> 1 & 1) != 0) {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4(uVar14);
        }
      }
      else {
        FUN_fffffff00a396010(uVar14);
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
      uVar5 = DAT_fffffff00ad7ce10;
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4(uVar14);
        }
      }
      else {
        FUN_fffffff00a396010(uVar14);
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value %s %s %s input %s %s %s>\n"
                );
    }
    uVar11 = *(uint *)(param_1 + 0x5c);
    lVar12 = DAT_fffffff00adcda30;
    if (uVar11 < 0x2711) {
      for (; lVar12 != 0; lVar12 = *(long *)(lVar12 + 0x10)) {
        if (*(uint *)(lVar12 + 0x20) == uVar11) {
          if ((*(long *)(lVar12 + 0x28) != 0 && param_10 != 0) && param_9 != 0) {
            uVar14 = param_10 + param_9;
            if (((param_10 ^ uVar14) & 0xffc0000000000000) != 0) {
              uVar14 = uVar14 & 0xffffffffffff | 0xc8a2000000000000;
            }
            if (uVar14 - param_10 < (param_9 & 0xffffffff)) goto LAB_fffffff00a4efde8;
            uVar11 = FUN_fffffff00a52481c(*(long *)(lVar12 + 0x28),param_10,param_9);
            goto joined_r0xfffffff00a4ee834;
          }
          break;
        }
      }
      if ((*(byte *)(param_1 + 0x2c) >> 1 & 1) == 0) {
        return 0;
      }
    }
    else {
      uVar14 = param_10 + param_9;
      if (((param_10 ^ uVar14) & 0xffc0000000000000) != 0) {
        uVar14 = uVar14 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if (uVar14 - param_10 < param_9) {
LAB_fffffff00a4efde8:
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a4efdec);
        (*pcVar6)();
      }
      uVar11 = FUN_fffffff00a4efdec(uVar11,param_10,param_9);
      if (param_26._4_4_ != 0) {
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,
                   "%s: DATA-TRACE: matching <%s %zu> with trie id %d - matched %d\n");
      }
joined_r0xfffffff00a4ee834:
      if ((param_31 != 0) && (uVar11 != 0)) {
        *(uint *)(param_31 + 0x234) = *(uint *)(param_31 + 0x234) | 0x80000000;
      }
      if ((*(byte *)(param_1 + 0x2c) >> 1 & 1) == 0) {
        if (uVar11 == 0) {
          return 0;
        }
      }
      else if ((uVar11 & 1) != 0) {
        return 0;
      }
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((*(byte *)(param_1 + 0x24) >> 5 & 1) != 0) {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value %s %s %s input %s %s %s>\n"
                );
    }
    if (param_12 == 0) {
      if ((*(byte *)(param_1 + 0x2c) >> 5 & 1) == 0) {
        return 0;
      }
    }
    else {
      uVar14 = FUN_fffffff00a3543ac(*(undefined8 *)(param_1 + 0x150),param_12);
      if ((*(byte *)(param_1 + 0x2c) >> 5 & 1) == 0) {
        if ((int)uVar14 != 0) {
          return 0;
        }
      }
      else if ((int)uVar14 == 0) {
        return uVar14;
      }
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((*(byte *)(param_1 + 0x21) >> 4 & 1) != 0) {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if ((*(byte *)(param_1 + 0x29) >> 4 & 1) == 0) {
      if (param_7 != *(int *)(param_1 + 0x48)) {
        return 0;
      }
    }
    else if (param_7 == *(int *)(param_1 + 0x48)) {
      return 0;
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((*(byte *)(param_1 + 0x21) >> 6 & 1) != 0) {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if ((*(byte *)(param_1 + 0x29) >> 6 & 1) == 0) {
      if ((int)param_13 != *(int *)(param_1 + 0x60)) {
        return 0;
      }
      if ((*(int *)(param_1 + 0x15c) != 0) && (param_13._4_4_ != *(int *)(param_1 + 0x15c))) {
        return 0;
      }
    }
    else {
      if ((int)param_13 == *(int *)(param_1 + 0x60)) {
        return 0;
      }
      if ((*(int *)(param_1 + 0x15c) != 0) && (param_13._4_4_ == *(int *)(param_1 + 0x15c))) {
        return 0;
      }
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if (*(char *)(param_1 + 0x21) < '\0') {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if (*(char *)(param_1 + 0x29) < '\0') {
      if ((int)param_14 == *(int *)(param_1 + 100)) {
        return 0;
      }
    }
    else if ((int)param_14 != *(int *)(param_1 + 100)) {
      return 0;
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((*(byte *)(param_1 + 0x24) >> 4 & 1) != 0) {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if ((*(byte *)(param_1 + 0x2c) >> 4 & 1) == 0) {
      if (param_14._4_4_ != *(int *)(param_1 + 0x68)) {
        return 0;
      }
    }
    else if (param_14._4_4_ == *(int *)(param_1 + 0x68)) {
      return 0;
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((*(byte *)(param_1 + 0x22) >> 1 & 1) != 0) {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if ((*(byte *)(param_1 + 0x2a) >> 1 & 1) == 0) {
      if (param_15._4_4_ < *(uint *)(param_1 + 0x78)) {
        return 0;
      }
      if (*(uint *)(param_1 + 0x7c) < param_15._4_4_) {
        return 0;
      }
    }
    else if ((*(uint *)(param_1 + 0x78) <= param_15._4_4_) &&
            (param_15._4_4_ <= *(uint *)(param_1 + 0x7c))) {
      return 0;
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((*(byte *)(param_1 + 0x20) >> 2 & 1) != 0) {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if ((*(byte *)(param_1 + 0x28) >> 2 & 1) == 0) {
      if (param_16 != *(short *)(param_1 + 0x80)) {
        return 0;
      }
    }
    else if (param_16 == *(short *)(param_1 + 0x80)) {
      return 0;
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  uVar11 = (uint)*(undefined8 *)(param_1 + 0x20);
  if ((uVar11 >> 0x14 & 1) != 0) {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value %s %s %s input %s %s %s>\n"
                );
    }
    if ((int)param_20 == 0) {
      return 0;
    }
    lVar12 = FUN_fffffff00a1d14a0(param_1 + 0xf9,0x20);
    uVar14 = 0;
    while( true ) {
      lVar1 = param_19 + uVar14 * 0x40;
      if (lVar12 != 0) {
        lVar15 = 0;
        lVar17 = 0x1f;
        do {
          cVar3 = *(char *)(lVar1 + lVar15);
          if (cVar3 != *(char *)(param_1 + 0xf9 + lVar15)) goto LAB_fffffff00a4eef54;
          lVar15 = lVar15 + 1;
          bVar7 = lVar17 != 0;
          lVar17 = lVar17 + -1;
        } while (cVar3 != '\0' && bVar7);
      }
      lVar15 = FUN_fffffff00a1d14a0(param_1 + 0x119,0x20);
      if (lVar15 == 0) break;
      lVar15 = 0;
      lVar17 = 0x1f;
      while (cVar3 = *(char *)(lVar1 + 0x20 + lVar15), cVar3 == *(char *)(param_1 + 0x119 + lVar15))
      {
        lVar15 = lVar15 + 1;
        bVar7 = lVar17 == 0;
        lVar17 = lVar17 + -1;
        if (cVar3 == '\0' || bVar7) goto LAB_fffffff00a4eefd8;
      }
LAB_fffffff00a4eef54:
      uVar14 = uVar14 + 1;
      if (uVar14 == (param_20 & 0xffffffff)) {
        return 0;
      }
    }
LAB_fffffff00a4eefd8:
    uVar11 = (uint)*(undefined8 *)(param_1 + 0x20);
  }
  if ((uVar11 >> 0x16 & 1) != 0) {
    bVar2 = *(byte *)(param_1 + 0x16c);
    if (param_25 == 0) {
      uVar14 = FUN_fffffff00a4effe4(param_18,bVar2 & 1);
      uVar13 = *(ushort *)(param_29 + 0x90);
      if ((uVar14 & 1) != 0) goto LAB_fffffff00a4ef1f4;
      goto LAB_fffffff00a4efa34;
    }
    if (((*(uint *)(param_25 + 0x74) >> 1 & 1) == 0) &&
       (((((bVar2 & 1) != 0 || ((*(uint *)(param_25 + 0x74) >> 0x15 & 1) == 0)) &&
         (*(long *)(param_25 + 0x90) != 0)) &&
        (lVar12 = *(long *)(*(long *)(param_25 + 0x90) + 0x30), lVar12 != 0)))) {
      if (((*(ushort *)(lVar12 + 0xd2) >> 4 & 1) == 0) && ((bVar2 & 1) == 0)) {
        if ((*(byte *)(lVar12 + 0xd7) >> 5 & 1) != 0) goto LAB_fffffff00a4ef194;
        uVar14 = FUN_fffffff00a4efe84(param_18);
        uVar13 = *(ushort *)(param_29 + 0x90);
        if ((uVar14 & 1) == 0) goto LAB_fffffff00a4ef1f4;
      }
      else {
        uVar13 = *(ushort *)(param_29 + 0x90);
        if ((*(ushort *)(lVar12 + 0xd2) >> 4 & 1) == 0) {
LAB_fffffff00a4ef1f4:
          uVar16 = 0x100;
          bVar7 = true;
          goto LAB_fffffff00a4efa3c;
        }
      }
LAB_fffffff00a4efa34:
      bVar7 = false;
      uVar16 = 0;
    }
    else {
LAB_fffffff00a4ef194:
      bVar7 = false;
      uVar16 = 0;
      uVar13 = *(ushort *)(param_29 + 0x90);
    }
LAB_fffffff00a4efa3c:
    *(ushort *)(param_29 + 0x90) = uVar16 | uVar13 & 0xfeff;
    uVar5 = DAT_fffffff00ad7ce10;
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if ((*(byte *)(param_1 + 0x2a) >> 6 & 1) == 0) {
      if (!bVar7) {
        return 0;
      }
    }
    else if (bVar7) {
      return 0;
    }
  }
  uVar11 = (uint)*(undefined8 *)(param_1 + 0x20);
  if ((uVar11 >> 3 & 1) != 0) {
    if ((uVar11 >> 4 & 1) == 0) {
      if ((uVar11 >> 5 & 1) != 0) {
        uVar11 = FUN_fffffff00a4dc5ac(param_17,param_1 + 0x84,*(undefined1 *)(param_1 + 0xbc));
        uVar5 = DAT_fffffff00ad7ce10;
        if (2 < param_26._4_4_) {
          iVar8 = FUN_fffffff00a4ecdf8(param_31);
          uVar14 = param_31 & 0x7ffffffffff;
          if ((param_31 & 0x80000000000000) != 0) {
            uVar14 = param_31 | 0xffffff8000000000;
          }
          if (iVar8 == 0) {
            if (uVar14 + 0x2400000000 >> 0x25 == 0) {
              FUN_fffffff00a1d12d4();
            }
          }
          else {
            FUN_fffffff00a396010();
          }
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar5,0x10,
                     "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                    );
        }
        if ((*(byte *)(param_1 + 0x28) >> 5 & 1) != 0) goto LAB_fffffff00a4ef8b8;
joined_r0xfffffff00a4ef514:
        if (uVar11 == 0) {
          return 0;
        }
      }
    }
    else {
      uVar11 = FUN_fffffff00a4f010c(param_17,param_1 + 0x84,param_1 + 0xa0);
      uVar5 = DAT_fffffff00ad7ce10;
      if (2 < param_26._4_4_) {
        iVar8 = FUN_fffffff00a4ecdf8(param_31);
        uVar14 = param_31 & 0x7ffffffffff;
        if ((param_31 & 0x80000000000000) != 0) {
          uVar14 = param_31 | 0xffffff8000000000;
        }
        if (iVar8 == 0) {
          if (uVar14 + 0x2400000000 >> 0x25 == 0) {
            FUN_fffffff00a1d12d4();
          }
        }
        else {
          FUN_fffffff00a396010();
        }
        FUN_fffffff00a8df19c
                  (&MACH_HEADER,uVar5,0x10,
                   "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                  );
      }
      if ((*(byte *)(param_1 + 0x28) >> 4 & 1) == 0) {
        uVar11 = uVar11 & 1;
        goto joined_r0xfffffff00a4ef514;
      }
LAB_fffffff00a4ef8b8:
      if ((uVar11 & 1) != 0) {
        return 0;
      }
    }
  }
  uVar11 = (uint)*(undefined8 *)(param_1 + 0x20);
  if ((uVar11 >> 6 & 1) == 0) goto LAB_fffffff00a4eeffc;
  if ((uVar11 >> 7 & 1) == 0) {
    if ((uVar11 >> 8 & 1) == 0) goto LAB_fffffff00a4eeffc;
    uVar11 = FUN_fffffff00a4dc5ac(param_18,param_1 + 0xc0,*(undefined1 *)(param_1 + 0xf8));
    uVar5 = DAT_fffffff00ad7ce10;
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if ((*(byte *)(param_1 + 0x29) & 1) != 0) goto LAB_fffffff00a4efa24;
  }
  else {
    uVar11 = FUN_fffffff00a4f010c(param_18,param_1 + 0xc0,param_1 + 0xdc);
    uVar5 = DAT_fffffff00ad7ce10;
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if (*(char *)(param_1 + 0x28) < '\0') {
LAB_fffffff00a4efa24:
      if ((uVar11 & 1) != 0) {
        return 0;
      }
      goto LAB_fffffff00a4eeffc;
    }
    uVar11 = uVar11 & 1;
  }
  if (uVar11 == 0) {
    return 0;
  }
LAB_fffffff00a4eeffc:
  uVar5 = DAT_fffffff00ad7ce10;
  if (*(char *)(param_1 + 0x22) < '\0') {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    uVar11 = *(uint *)(param_1 + 0x30);
    if (*(char *)(param_1 + 0x2a) < '\0') {
      if ((uVar11 & (uint)param_21) == uVar11) {
        return 0;
      }
    }
    else if ((uVar11 & (uint)param_21) != uVar11) {
      return 0;
    }
  }
  if ((*(byte *)(param_1 + 0x23) & 1) != 0) {
    uVar11 = FUN_fffffff00a4e8d10(param_17);
    uVar5 = DAT_fffffff00ad7ce10;
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if ((*(byte *)(param_1 + 0x2b) & 1) == 0) {
      if (uVar11 == 0) {
        return 0;
      }
    }
    else if ((uVar11 & 1) != 0) {
      return 0;
    }
  }
  if ((*(byte *)(param_1 + 0x23) >> 1 & 1) != 0) {
    uVar11 = FUN_fffffff00a4e8d10(param_18);
    uVar5 = DAT_fffffff00ad7ce10;
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if ((*(byte *)(param_1 + 0x2b) >> 1 & 1) == 0) {
      if (uVar11 == 0) {
        return 0;
      }
    }
    else if ((uVar11 & 1) != 0) {
      return 0;
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((*(byte *)(param_1 + 0x24) & 1) != 0) {
    if ((*(char *)(param_18 + 1) == '\x1e') || (*(char *)(param_18 + 1) == '\x02')) {
      sVar18 = *(short *)(param_18 + 2);
    }
    else {
      sVar18 = 0;
    }
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    sVar4 = *(short *)(param_1 + 0x15a);
    if ((*(byte *)(param_1 + 0x2c) & 1) == 0) {
      if (sVar4 != param_24._2_2_ && sVar18 != sVar4) {
        return 0;
      }
    }
    else if (sVar4 == param_24._2_2_ || sVar18 == sVar4) {
      return 0;
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((*(byte *)(param_1 + 0x23) >> 5 & 1) != 0) {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    uVar13 = (ushort)((short)param_24 == -0xff) & *(ushort *)(param_1 + 0x158);
    if ((*(byte *)(param_1 + 0x2b) >> 5 & 1) == 0) {
      if (uVar13 == 0) {
        return 0;
      }
    }
    else if (uVar13 != 0) {
      return 0;
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((*(byte *)(param_1 + 0x23) >> 6 & 1) != 0) {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if ((*(byte *)(param_1 + 0x2b) >> 6 & 1) == 0) {
      if ((char)param_26 == '\0') {
        return 0;
      }
    }
    else if ((param_26 & 1) != 0) {
      return 0;
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if (*(char *)(param_1 + 0x23) < '\0') {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value (%d / 0x%X) (%d / 0x%X) (%d / 0x%X) input (%d / 0x%X) (%d / 0x%X) (%d / 0x%X)>\n"
                );
    }
    if (param_30 == '\0') {
      if ((*(byte *)(param_1 + 0x21) & 0x42) == 0) {
        if (*(char *)(param_1 + 0x2b) < '\0') {
          if (param_21._4_4_ != 0) {
            return 0;
          }
        }
        else if (param_21._4_4_ == 0) {
          return 0;
        }
      }
    }
    else if (*(char *)(param_1 + 0x2b) < '\0') {
      if ((param_27 & 1) != 0) {
        return 0;
      }
    }
    else if ((param_27 & 1) == 0) {
      return 0;
    }
  }
  uVar5 = DAT_fffffff00ad7ce10;
  if ((*(byte *)(param_1 + 0x22) >> 3 & 1) != 0) {
    if (2 < param_26._4_4_) {
      iVar8 = FUN_fffffff00a4ecdf8(param_31);
      uVar14 = param_31 & 0x7ffffffffff;
      if ((param_31 & 0x80000000000000) != 0) {
        uVar14 = param_31 | 0xffffff8000000000;
      }
      if (iVar8 == 0) {
        if (uVar14 + 0x2400000000 >> 0x25 == 0) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        FUN_fffffff00a396010();
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar5,0x10,
                 "%s: DATA-TRACE <%s %llx>: ------ %smatching <%s> <value %s %s %s input %s %s %s>\n"
                );
    }
    if (*(long *)(param_1 + 0x40) != 0) {
      if (param_23 == 0) {
        return 0;
      }
      if ((*(byte *)(param_23 + 0x448) >> 1 & 1) == 0) {
        return 0;
      }
      if (param_23 + 0x768 == 0) {
        return 0;
      }
      uVar14 = FUN_fffffff00a9df14c(param_23 + 0x768);
      if ((int)uVar14 == 0) {
        return uVar14;
      }
    }
  }
  return 1;
}

