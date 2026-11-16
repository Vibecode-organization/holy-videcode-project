// FUN_fffffff00a552d28 @ fffffff00a552d28 size=1700

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a552d28(ulong param_1,undefined8 param_2)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  code *pcVar5;
  int iVar6;
  byte *pbVar7;
  ulong uVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  int iVar12;
  long lVar13;
  byte *pbVar14;
  byte *pbVar15;
  ulong *puVar16;
  byte *pbVar17;
  byte *pbVar18;
  
  if (DAT_fffffff00ad3dfc0 != 0) {
    uVar10 = param_1 & 0x7ffffffffff;
    if ((param_1 & 0x80000000000000) != 0) {
      uVar10 = param_1 | 0xffffff8000000000;
    }
    if (((DAT_fffffff007c5e218 <= uVar10 || uVar10 < DAT_fffffff007c5e210) &&
        (uVar10 < DAT_fffffff007c5e230 || DAT_fffffff007c5e238 <= uVar10)) &&
       ((DAT_fffffff007c5e260 <= uVar10 || uVar10 < DAT_fffffff007c5e258) &&
        uVar10 + 0x2400000000 >> 0x25 == 0)) {
      FUN_fffffff00a1952d4(uVar10);
    }
  }
  lVar13 = *(long *)(param_1 + 0x50);
  _DAT_fffffff00acd25e0 = _DAT_fffffff00acd25e0 + 1;
  DAT_fffffff00ad8f288 = DAT_fffffff00ad8f288 + 1;
  if ((*(ushort *)(param_1 + 0x1e) & 1) == 0) {
    pbVar7 = (byte *)(param_1 + 0xe0);
    pbVar15 = (byte *)(param_1 + 0x200);
  }
  else {
    pbVar7 = *(byte **)(param_1 + 0x20);
    pbVar15 = pbVar7 + *(uint *)(param_1 + 0x30);
  }
  puVar16 = (ulong *)(param_1 + 0x10);
  pbVar14 = (byte *)*puVar16;
  if (pbVar14 < pbVar7 || pbVar15 < pbVar14 + 0x14) goto LAB_fffffff00a55339c;
  uVar3 = *(ushort *)(pbVar14 + 2);
  if (uVar3 < 8) {
    _DAT_fffffff00acd25e8 = _DAT_fffffff00acd25e8 + 1;
    DAT_fffffff00ad8f28c = DAT_fffffff00ad8f28c + 1;
    do {
      lVar13 = FUN_fffffff00a74f6b4();
    } while (lVar13 != 0);
    return;
  }
  iVar6 = 0xc;
  if (uVar3 < 0xc) {
    iVar6 = 8;
  }
  iVar12 = (int)param_2;
  uVar9 = param_2;
  if (iVar12 == 0) {
    if (*(int *)(param_1 + 0x18) < iVar6) {
      uVar9 = 0;
      goto LAB_fffffff00a552e90;
    }
    pbVar7 = pbVar14;
    if ((*(ushort *)(param_1 + 0x1e) & 1) == 0) {
      pbVar18 = (byte *)(param_1 + 0xe0);
      pbVar17 = (byte *)(param_1 + 0x200);
    }
    else {
      pbVar18 = *(byte **)(param_1 + 0x20);
      pbVar17 = pbVar18 + *(uint *)(param_1 + 0x30);
    }
  }
  else {
LAB_fffffff00a552e90:
    pbVar7 = (byte *)FUN_fffffff00a757cac(param_1,uVar9,iVar6,0);
    if (pbVar7 == (byte *)0x0) goto LAB_fffffff00a553334;
    if (*(int *)(pbVar7 + 0x18) < iVar6) goto LAB_fffffff00a5533ac;
    pbVar17 = pbVar7 + 0x200;
    if (pbVar17 <= pbVar7) goto LAB_fffffff00a55339c;
    if ((*(ushort *)(pbVar7 + 0x1e) & 1) == 0) {
      pbVar18 = pbVar7 + 0xe0;
    }
    else {
      pbVar18 = *(byte **)(pbVar7 + 0x20);
      pbVar17 = pbVar18 + *(uint *)(pbVar7 + 0x30);
    }
    pbVar7 = *(byte **)(pbVar7 + 0x10);
  }
  if (pbVar7 == (byte *)0x0) goto LAB_fffffff00a553334;
  *(long *)(param_1 + 0x10) = *(long *)(param_1 + 0x10) + (long)iVar12;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - iVar12;
  iVar6 = FUN_fffffff00a759394(param_1,0,uVar3);
  if (iVar6 != 0xffff) {
    _DAT_fffffff00acd25f8 = _DAT_fffffff00acd25f8 + 1;
    DAT_fffffff00ad8f290 = DAT_fffffff00ad8f290 + 1;
    do {
      param_1 = FUN_fffffff00a74f6b4(param_1);
    } while (param_1 != 0);
    return;
  }
  *(long *)(param_1 + 0x10) = *(long *)(param_1 + 0x10) - (long)iVar12;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + iVar12;
  if ((pbVar17 < pbVar7 + 8) || (pbVar7 < pbVar18)) goto LAB_fffffff00a55339c;
  bVar2 = *pbVar7;
  if (bVar2 == 0x13) goto LAB_fffffff00a552f9c;
  if (pbVar14[8] != 1) {
    _DAT_fffffff00acd25f0 = _DAT_fffffff00acd25f0 + 1;
    do {
      lVar13 = FUN_fffffff00a74f6b4();
    } while (lVar13 != 0);
    return;
  }
  if (0x15 < bVar2) {
    if (bVar2 == 0x16) {
      if (_DAT_fffffff00acd2690 != 0) {
        iVar6 = FUN_fffffff00a5860f8();
        if (iVar6 == 0) {
          _DAT_fffffff00acd2650 = _DAT_fffffff00acd2650 + 1;
        }
        if ((pbVar15 <= pbVar14 && pbVar14 != (byte *)0x0) || (pbVar17 <= pbVar7))
        goto LAB_fffffff00a55339c;
        iVar6 = FUN_fffffff00a554630(lVar13,param_1,pbVar14,pbVar7);
        if (iVar6 != 0) {
          do {
            param_1 = FUN_fffffff00a74f6b4(param_1);
          } while (param_1 != 0);
          return;
        }
      }
    }
    else if ((bVar2 == 0x22) && (iVar6 = FUN_fffffff00a5860f8(param_1), iVar6 == 0)) {
      _DAT_fffffff00acd2650 = _DAT_fffffff00acd2650 + 1;
    }
    goto LAB_fffffff00a552f9c;
  }
  if (bVar2 != 0x11) {
    if ((bVar2 == 0x12) && (_DAT_fffffff00acd268c != 0)) {
      if ((pbVar15 <= pbVar14 && pbVar14 != (byte *)0x0) || (pbVar17 <= pbVar7))
      goto LAB_fffffff00a55339c;
      _DAT_fffffff00acd2638 = _DAT_fffffff00acd2638 + 1;
      DAT_fffffff00ad8f29c = DAT_fffffff00ad8f29c + 1;
      if (((*(ushort *)(lVar13 + 0xd2) >> 3 & 1) == 0) &&
         ((*(byte *)(param_1 + 0x75) >> 5 & 1) == 0)) {
        _DAT_fffffff00acd2640 = _DAT_fffffff00acd2640 + 1;
        DAT_fffffff00ad8f2a0 = DAT_fffffff00ad8f2a0 + 1;
        do {
          lVar13 = FUN_fffffff00a74f6b4();
        } while (lVar13 != 0);
        return;
      }
    }
    goto LAB_fffffff00a552f9c;
  }
  if (uVar3 == 8) {
    DAT_fffffff00ad8f294 = DAT_fffffff00ad8f294 + 1;
    _DAT_fffffff00acd2600 = _DAT_fffffff00acd2600 + 1;
    if (pbVar7[1] == 0) {
      if (_DAT_fffffff00acd268c != 0) {
        if ((pbVar15 <= pbVar14 && pbVar14 != (byte *)0x0) || (pbVar17 <= pbVar7))
        goto LAB_fffffff00a55339c;
        FUN_fffffff00a5533cc(lVar13,*(undefined4 *)(pbVar14 + 0x10),pbVar7);
      }
    }
    else if (_DAT_fffffff00acd2690 != 0) {
      if ((pbVar15 <= pbVar14 && pbVar14 != (byte *)0x0) || (pbVar17 <= pbVar7))
      goto LAB_fffffff00a55339c;
      FUN_fffffff00a553760(lVar13,pbVar14,pbVar7);
    }
    goto LAB_fffffff00a552f9c;
  }
  if (uVar3 < 0xc) {
    _DAT_fffffff00acd25e8 = _DAT_fffffff00acd25e8 + 1;
    DAT_fffffff00ad8f28c = DAT_fffffff00ad8f28c + 1;
    do {
      lVar13 = FUN_fffffff00a74f6b4();
    } while (lVar13 != 0);
    return;
  }
  DAT_fffffff00ad8f294 = DAT_fffffff00ad8f294 + 1;
  _DAT_fffffff00acd2608 = _DAT_fffffff00acd2608 + 1;
  if (pbVar17 < pbVar7 + 0xc) goto LAB_fffffff00a55339c;
  uVar4 = *(ushort *)(pbVar7 + 10);
  if (0x16e < ((uint)(uVar4 >> 8) | (uVar4 & 0xff00ff) << 8)) {
    _DAT_fffffff00acd25e8 = _DAT_fffffff00acd25e8 + 1;
    DAT_fffffff00ad8f28c = DAT_fffffff00ad8f28c + 1;
    do {
      lVar13 = FUN_fffffff00a74f6b4();
    } while (lVar13 != 0);
    return;
  }
  uVar1 = ((uint)(uVar4 >> 8) | (uVar4 & 0xff00ff) << 8) * 4 + 0xc;
  if ((uint)uVar3 < (uVar1 & 0xfffc)) {
    _DAT_fffffff00acd25e8 = _DAT_fffffff00acd25e8 + 1;
    DAT_fffffff00ad8f28c = DAT_fffffff00ad8f28c + 1;
    do {
      lVar13 = FUN_fffffff00a74f6b4();
    } while (lVar13 != 0);
    return;
  }
  uVar9 = param_2;
  if (iVar12 == 0) {
    if (*(int *)(param_1 + 0x18) < (int)(uVar1 & 0xffff)) {
      uVar9 = 0;
      goto LAB_fffffff00a5532bc;
    }
    if ((*(ushort *)(param_1 + 0x1e) & 1) == 0) {
      uVar11 = param_1 + 0xe0;
      uVar10 = param_1 + 0x200;
    }
    else {
      uVar11 = *(ulong *)(param_1 + 0x20);
      uVar10 = uVar11 + *(uint *)(param_1 + 0x30);
    }
  }
  else {
LAB_fffffff00a5532bc:
    uVar8 = FUN_fffffff00a757cac(param_1,uVar9,uVar1 & 0xffff,0);
    if (uVar8 == 0) goto LAB_fffffff00a553334;
    if (*(int *)(uVar8 + 0x18) < (int)(uVar1 & 0xffff)) {
LAB_fffffff00a5533ac:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa0c4f8("m_pulldown malfunction @%s:%d");
    }
    uVar10 = uVar8 + 0x200;
    if (uVar10 <= uVar8) goto LAB_fffffff00a55339c;
    if ((*(ushort *)(uVar8 + 0x1e) & 1) == 0) {
      uVar11 = uVar8 + 0xe0;
    }
    else {
      uVar11 = *(ulong *)(uVar8 + 0x20);
      uVar10 = uVar11 + *(uint *)(uVar8 + 0x30);
    }
    puVar16 = (ulong *)(uVar8 + 0x10);
  }
  uVar8 = *puVar16;
  if (uVar8 != 0) {
    if ((pbVar14 < pbVar15 || pbVar14 == (byte *)0x0) && (uVar11 <= uVar8)) {
      FUN_fffffff00a553cac(lVar13,pbVar14,uVar8,uVar10);
LAB_fffffff00a552f9c:
      FUN_fffffff00a58f14c(param_1,param_2);
      return;
    }
LAB_fffffff00a55339c:
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a5533a0);
    (*pcVar5)();
  }
LAB_fffffff00a553334:
  DAT_fffffff00ad8f28c = DAT_fffffff00ad8f28c + 1;
  _DAT_fffffff00acd25e8 = _DAT_fffffff00acd25e8 + 1;
  return;
}

