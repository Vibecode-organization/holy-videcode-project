// FUN_fffffff00a2e34bc @ fffffff00a2e34bc size=788

undefined8
FUN_fffffff00a2e34bc
          (long param_1,ulong param_2,ulong param_3,ulong param_4,ulong param_5,undefined8 param_6)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  code *pcVar4;
  bool bVar5;
  undefined8 uVar6;
  ulong uVar7;
  int iVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong *puVar12;
  
  if (param_1 == DAT_fffffff007c678d8) {
    uVar10 = param_5 >> 0x3c & 7;
    iVar8 = (int)uVar10;
    if ((iVar8 == 7) || (iVar8 == 0)) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2e37c4);
      (*pcVar4)();
    }
    uVar11 = (ulong)(iVar8 - 1) * 0x380 - 0xff5246290;
    if (((uVar11 ^ 0xfffffff00adb9d70) & 0xffc0000000000000) != 0) {
      uVar11 = uVar11 & 0xffffffffffff | 0xc8a2000000000000;
    }
    uVar7 = uVar11 + (param_5 >> 0x3b & 1) * 0x1c0;
    if (((uVar11 ^ uVar7) & 0xffc0000000000000) != 0) {
      uVar7 = uVar7 & 0xffffffffffff | 0xc8a2000000000000;
    }
    puVar12 = (ulong *)(&DAT_fffffff007bca160 + uVar10 * 4);
    if ((((ulong)puVar12 ^ 0xfffffff007bca170) & 0xffc0000000000000) != 0) {
      puVar12 = (ulong *)((ulong)puVar12 & 0xffffffffffff | 0xc8a2000000000000);
    }
    uVar11 = *puVar12;
    uVar10 = puVar12[1];
    if ((((uint)param_5 >> 0x16 & 1) != 0) || (iVar8 == 4)) goto LAB_fffffff00a2e3694;
  }
  else {
    uVar7 = 0;
    uVar3 = *(uint *)(param_1 + 0xf8);
    if ((((uint)param_5 >> 0x16 & 1) == 0) && ((uVar3 >> 8 & 1) == 0)) {
      uVar7 = *(ulong *)(param_1 + 0xd8);
    }
    uVar10 = 1L << ((ulong)*(byte *)(param_1 + 0x2c) & 0x3f);
    uVar2 = *(ulong *)(param_1 + 0x18);
    uVar1 = *(ulong *)(param_1 + 0x10);
    if (*(ulong *)(param_1 + 0x10) <= uVar10) {
      uVar1 = uVar10;
    }
    uVar11 = uVar1;
    uVar10 = uVar2;
    if ((uVar3 & 0x8008) == 0x8000) {
      uVar9 = (uint)(param_5 >> 0x3c) & 7;
      if (uVar9 < 3) {
        if (uVar9 == 0) goto LAB_fffffff00a2e363c;
        if (uVar9 == 1) goto LAB_fffffff00a2e3630;
        if (uVar9 != 2) goto LAB_fffffff00a2e37c4;
      }
      else {
        if (uVar9 != 5) {
          if (uVar9 != 4) {
            if (uVar9 != 3) {
LAB_fffffff00a2e37c4:
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2e37d0);
              (*pcVar4)();
            }
            bVar5 = (uVar3 & 0x100000) != 0;
            uVar10 = 0;
            if (bVar5) {
              uVar10 = 0x80000000000;
            }
            uVar11 = 0;
            if (bVar5) {
              uVar11 = 0x40000000000;
            }
            goto LAB_fffffff00a2e3694;
          }
          uVar11 = *(ulong *)(param_1 + 0xb8);
          uVar10 = *(ulong *)(param_1 + 0xc0);
          if (uVar10 != uVar11) goto LAB_fffffff00a2e3694;
LAB_fffffff00a2e3630:
          uVar11 = *(ulong *)(param_1 + 0xa8);
          uVar10 = *(ulong *)(param_1 + 0xb0);
          if (uVar10 != uVar11) {
            if (uVar7 == 0) goto LAB_fffffff00a2e3694;
            param_5 = param_5 | 0x800000000000000;
            uVar7 = uVar7 + 0x1c0;
            uVar10 = uVar2;
            uVar11 = uVar1;
            goto LAB_fffffff00a2e3660;
          }
LAB_fffffff00a2e363c:
          if (uVar7 == 0) {
            uVar11 = *(ulong *)(param_1 + 0x98);
            uVar10 = *(ulong *)(param_1 + 0xa0);
            goto LAB_fffffff00a2e3694;
          }
          param_5 = param_5 & 0xf7ffffffffffffff;
          uVar10 = uVar2;
          uVar11 = uVar1;
          goto LAB_fffffff00a2e3660;
        }
        uVar11 = *(ulong *)(param_1 + 200);
        uVar10 = *(ulong *)(param_1 + 0xd0);
      }
    }
    if (uVar7 == 0) goto LAB_fffffff00a2e3694;
  }
LAB_fffffff00a2e3660:
  uVar6 = FUN_fffffff00a2fb814(param_1,uVar7,uVar11,uVar10,param_5,param_3,param_4,param_6);
  if ((int)uVar6 != 0x2e) {
    return uVar6;
  }
  param_2 = uVar11;
  if ((param_5 & 0x800000000000000) != 0) {
    param_2 = uVar10;
  }
LAB_fffffff00a2e3694:
  uVar7 = param_2;
  if (param_2 <= uVar11) {
    uVar7 = uVar11;
  }
  uVar1 = uVar10;
  if ((param_5 & 0x800000000000000) != 0) {
    uVar1 = param_2;
    uVar7 = uVar11;
  }
  if (uVar10 <= uVar1 - 1) {
    uVar1 = uVar10;
  }
  while( true ) {
    if (uVar1 <= uVar7 || uVar1 - uVar7 < param_3) {
      return 3;
    }
    if (((*(uint *)(param_1 + 0xf8) >> 3 & 1) == 0) && (((uint)param_5 >> 3 & 1) != 0)) {
      uVar6 = FUN_fffffff00a2faa64(param_1,uVar7,uVar1,param_3,param_6);
    }
    else {
      uVar10 = (ulong)(uint)~(-1 << (ulong)(*(byte *)(param_1 + 0x2c) & 0x1f));
      if ((param_5 >> 0x3b & 1) == 0) {
        uVar11 = uVar7;
        if (((*(uint *)(param_1 + 0xf8) >> 3 & 1) != 0) &&
           (uVar2 = *(long *)(param_1 + 0xe8) + 0x4000, uVar7 <= uVar2)) {
          uVar11 = uVar2;
        }
        uVar6 = FUN_fffffff00a2fb208(param_1,uVar11,uVar1,param_5,param_3,param_4 | uVar10,param_6);
      }
      else {
        uVar6 = FUN_fffffff00a2fac2c(param_1,uVar7,uVar1,param_5,param_3,param_4 | uVar10,param_6);
      }
    }
    if ((int)uVar6 != 3) break;
    if ((*(byte *)(param_1 + 0xf8) & 1) == 0) {
      return 3;
    }
    FUN_fffffff00a22b120(param_1 + 0x30,0,param_1,2,0);
  }
  return uVar6;
}

