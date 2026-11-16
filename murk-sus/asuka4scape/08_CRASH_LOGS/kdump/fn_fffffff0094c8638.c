// FUN_fffffff0094c8638 @ fffffff0094c8638 size=1472
// CALLERS:
//   fffffff00afb80d3 ?
//   fffffff0094c28e0 FUN_fffffff0094c264c@fffffff0094c264c
//   fffffff0094c3c28 FUN_fffffff0094c3a14@fffffff0094c3a14
//   fffffff0094c4b5c FUN_fffffff0094c49b4@fffffff0094c49b4
//   fffffff0094c4b7c FUN_fffffff0094c49b4@fffffff0094c49b4
//   fffffff0094c8c00 FUN_fffffff0094c8bf8@fffffff0094c8bf8
// CALLS:
//   fffffff0094c70e8 FUN_fffffff0094c70e8
//   fffffff0094c519c FUN_fffffff0094c519c
//   fffffff0094c84c4 FUN_fffffff0094c84c4
//   fffffff0094c8d1c FUN_fffffff0094c8d1c
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590
//   fffffff0094c8580 FUN_fffffff0094c8580
//   fffffff0094c6bf4 FUN_fffffff0094c6bf4
//   fffffff0094c7388 FUN_fffffff0094c7388
//   fffffff0094c8c04 FUN_fffffff0094c8c04

void FUN_fffffff0094c8638
               (uint param_1,undefined4 param_2,ulong *param_3,ulong *param_4,ulong *param_5)

{
  long lVar1;
  long lVar2;
  bool bVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  ulong uVar7;
  undefined4 uVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  uint uVar15;
  undefined1 *local_98;
  undefined1 *puStack_90;
  undefined1 *local_88;
  undefined1 *puStack_80;
  undefined1 *local_78;
  undefined1 *puStack_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff007f5bb60;
  uVar12 = *param_3;
  if (((param_4 != (ulong *)0x0) && (param_4[6] != 0)) && (*(long *)(param_4[6] + 8) != 0)) {
    if (uVar12 + 0xe0 < uVar12 + 0xd0) goto LAB_fffffff0094c8be8;
    iVar6 = FUN_fffffff0094c519c();
    if (iVar6 != 0) {
      uVar7 = 0x50015;
      goto LAB_fffffff0094c8b74;
    }
    uVar12 = *param_3;
  }
  if (uVar12 == 0) {
    bVar4 = false;
    uVar7 = 0;
    uVar14 = 0xffffffffffffffff;
  }
  else {
    uVar10 = 0;
    uVar15 = 0;
    bVar4 = false;
    uVar14 = 0xffffffffffffffff;
    do {
      uVar7 = uVar12 + 0x130;
      uVar13 = *(ulong *)(uVar12 + 0x120);
      uVar11 = uVar13 + 0x130;
      if (uVar13 == 0) {
        if (uVar7 < uVar12) goto LAB_fffffff0094c8be8;
        iVar6 = FUN_fffffff0094c519c(uVar12 + 0x78,uVar12 + 0x68);
        if (iVar6 != 0) {
          if (param_4 != (ulong *)0x0) {
            if ((param_4[2] & 1) == 0) {
              if (param_4[3] != 0) {
                uVar13 = FUN_fffffff0094c8580(uVar12 + 0xa8);
                goto LAB_fffffff0094c8894;
              }
            }
            else {
              uVar13 = FUN_fffffff0094c84c4(uVar12 + 0xa8,*(byte *)((long)param_4 + 0x11) & 1);
LAB_fffffff0094c8894:
              bVar4 = (bool)(uVar13 != 0 | bVar4);
              uVar11 = uVar13 + 0x130;
              if (uVar13 != 0) goto LAB_fffffff0094c86ec;
            }
            if ((*(byte *)((long)param_4 + 0x13) & 1) != 0) {
              bVar3 = true;
              uVar13 = 0;
              goto LAB_fffffff0094c86f0;
            }
          }
          uVar7 = (ulong)(uVar15 | 0x9000d);
          goto LAB_fffffff0094c8b74;
        }
        bVar3 = false;
        uVar11 = uVar7;
        uVar13 = uVar12;
      }
      else {
LAB_fffffff0094c86ec:
        bVar3 = false;
      }
LAB_fffffff0094c86f0:
      if (uVar7 < uVar12) goto LAB_fffffff0094c8be8;
      if ((uVar10 != 0) && (1 < *(ulong *)(uVar12 + 0x20))) {
        if ((*(byte *)(uVar12 + 0x109) & 1) == 0) {
          uVar9 = 0x90001;
        }
        else {
          if ((*(byte *)(uVar12 + 0x108) >> 2 & 1) != 0) goto LAB_fffffff0094c8718;
          uVar9 = 0x90002;
        }
LAB_fffffff0094c8b70:
        uVar7 = (ulong)(uVar15 | uVar9);
        goto LAB_fffffff0094c8b74;
      }
LAB_fffffff0094c8718:
      if ((*(ulong *)(uVar12 + 200) != 0) && (*(ulong *)(uVar12 + 200) < uVar10)) {
        uVar9 = 0x90003;
        goto LAB_fffffff0094c8b70;
      }
      if ((*(byte *)(uVar12 + 0x10a) & 1) != 0) {
        uVar9 = 0x90007;
        goto LAB_fffffff0094c8b70;
      }
      iVar6 = FUN_fffffff0094c519c(uVar12 + 0x28,uVar12 + 0x98);
      if (iVar6 != 0) {
        uVar9 = 0x90004;
        goto LAB_fffffff0094c8b70;
      }
      if (((!bVar3) && (*(long *)(uVar12 + 0xb0) != 0)) && (*(long *)(uVar12 + 0xa8) != 0)) {
        if (((uVar11 < uVar13 + 0x130) || (uVar13 + 0x130 < uVar13)) ||
           (uVar13 + 200 < uVar13 + 0xb8)) goto LAB_fffffff0094c8be8;
        iVar6 = FUN_fffffff0094c519c(uVar12 + 0xa8);
        if (iVar6 != 0) {
          uVar7 = (ulong)(uVar15 | 0x9000a);
          goto LAB_fffffff0094c8b74;
        }
      }
      if (((param_4 != (ulong *)0x0) && (uVar10 != 0)) &&
         ((*(ulong *)(uVar12 + 0xf0) & param_4[1]) == 0)) {
        FUN_fffffff0094c8c04(uVar12);
      }
      if ((uVar13 == uVar12) && (*(long *)(uVar12 + 0xf0) == 0)) {
        FUN_fffffff0094c8d1c(param_4,uVar12);
      }
      uVar14 = *(ulong *)(uVar12 + 0xf0) & uVar14;
      if (((param_4 != (ulong *)0x0) && (param_4[1] != 0)) && ((param_4[1] & uVar14) == 0)) {
        uVar9 = 0x90005;
        goto LAB_fffffff0094c8b70;
      }
      param_1 = param_1 | uVar13 == uVar12;
      if (!bVar3) {
        if ((uVar11 < uVar13 + 0x130) || (uVar13 + 0x130 < uVar13)) goto LAB_fffffff0094c8be8;
        uVar7 = FUN_fffffff0094c70e8
                          (param_1,param_2,uVar13,uVar12 + 0x10,uVar12 + 0x28,uVar12 + 0x38);
        if ((int)uVar7 != 0) {
          if ((int)uVar7 == 0xa0111) {
            uVar7 = (ulong)(uVar15 | 0x9000e);
          }
          goto LAB_fffffff0094c8b74;
        }
      }
      uVar7 = uVar10 + 1;
      if (0xfffffffffffffffe < uVar10) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5500,0xfffffff0094c8bf0);
        (*pcVar5)();
      }
      uVar12 = *(ulong *)(uVar12 + 0x120);
      uVar15 = uVar15 + 0x100;
      uVar10 = uVar10 + 1;
    } while (uVar12 != 0);
  }
  if (param_4 != (ulong *)0x0) {
    if (*param_4 != 0) {
      uVar12 = uVar7;
      if ((bVar4) && (uVar12 = uVar7 + 1, 0xfffffffffffffffe < uVar7)) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5500,0xfffffff0094c8bf8);
        (*pcVar5)();
      }
      if (*param_4 != uVar12) {
        uVar7 = (ulong)((int)uVar12 << 8 | 0x90006);
        goto LAB_fffffff0094c8b74;
      }
    }
    if ((param_4[3] != 0) && (*(long *)(param_4[3] + 8) != 0)) {
      uVar10 = **(ulong **)(param_3[1] + 8);
      uVar12 = uVar10 + 0x130;
      if ((param_4[2] & 1) != 0) goto LAB_fffffff0094c89c0;
      local_78 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_70 = &DAT_aaaaaaaaaaaaaaaa;
      local_88 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_80 = &DAT_aaaaaaaaaaaaaaaa;
      local_98 = &DAT_aaaaaaaaaaaaaaaa;
      puStack_90 = &DAT_aaaaaaaaaaaaaaaa;
      if (uVar12 < uVar10 || uVar10 + 0x68 < uVar10 + 0x58) goto LAB_fffffff0094c8be8;
      iVar6 = FUN_fffffff0094c6bf4(uVar10 + 0x58,&local_78,&local_98,&local_88);
      if (iVar6 == 0) {
        iVar6 = FUN_fffffff0094c519c(&local_78,param_4[4]);
        if ((iVar6 == 0) && (iVar6 = FUN_fffffff0094c519c(&local_88,param_4[3]), iVar6 == 0)) {
          iVar6 = FUN_fffffff0094c519c(param_4[4],&DAT_fffffff007f5ade8);
          if (iVar6 != 0) goto LAB_fffffff0094c8aec;
          iVar6 = FUN_fffffff0094c519c(&local_98,param_4[5]);
        }
        else {
          iVar6 = FUN_fffffff0094c7388
                            (param_4[3],param_4[4],param_4[5],uVar10 + 0x10,uVar10 + 0x28,
                             uVar10 + 0x38);
        }
        if (iVar6 == 0) goto LAB_fffffff0094c8aec;
      }
      uVar15 = 0x90008;
LAB_fffffff0094c8a94:
      uVar7 = (ulong)((int)uVar7 << 8 | uVar15);
      goto LAB_fffffff0094c8b74;
    }
    if ((param_4[2] & 1) != 0) {
      uVar10 = **(ulong **)(param_3[1] + 8);
      uVar12 = uVar10 + 0x130;
LAB_fffffff0094c89c0:
      if (uVar12 < uVar10) goto LAB_fffffff0094c8be8;
      lVar1 = 0xb8;
      if (!bVar4) {
        lVar1 = 200;
      }
      lVar2 = 0xa8;
      if (!bVar4) {
        lVar2 = 0xb8;
      }
      uVar12 = uVar10 + lVar2;
      if (uVar10 + lVar1 < uVar12 + 0x10 || uVar12 + 0x10 < uVar12) goto LAB_fffffff0094c8be8;
      uVar12 = FUN_fffffff0094c84c4(uVar12,*(byte *)((long)param_4 + 0x11) & 1);
      if (uVar12 == 0) {
        uVar7 = (ulong)((int)uVar7 << 8 | 0x9000b);
        goto LAB_fffffff0094c8b74;
      }
      uVar11 = uVar12 + 0x130;
      if (!bVar4) {
        if ((uVar10 + 0x68 < uVar10 + 0x58 || uVar11 < uVar12) || uVar12 + 0x68 < uVar12 + 0x58)
        goto LAB_fffffff0094c8be8;
        iVar6 = FUN_fffffff0094c519c();
        if (iVar6 == 0) goto LAB_fffffff0094c8aec;
      }
      uVar8 = 7;
      if ((*(byte *)((long)param_4 + 0x14) & 1) == 0) {
        uVar8 = 4;
      }
      uVar13 = uVar10 + 0x38;
      if ((((uVar11 < uVar12 || uVar10 + 0x20 < uVar10 + 0x10) || uVar13 < uVar10 + 0x28) ||
          uVar10 + 0x48 <= uVar13) &&
          (((uVar11 < uVar12 || uVar10 + 0x20 < uVar10 + 0x10) || uVar13 < uVar10 + 0x28) ||
          uVar13 != uVar10 + 0x48)) {
LAB_fffffff0094c8be8:
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c8bec);
        (*pcVar5)();
      }
      iVar6 = FUN_fffffff0094c70e8(0x1d,uVar8,uVar12);
      if (iVar6 != 0) {
        uVar15 = 0x9000c;
        goto LAB_fffffff0094c8a94;
      }
    }
  }
LAB_fffffff0094c8aec:
  uVar7 = 0;
  if (param_5 != (ulong *)0x0) {
    *param_5 = uVar14;
  }
LAB_fffffff0094c8b74:
  if (*(long *)PTR_DAT_fffffff007f5bb60 != local_68) {
    thunk_EXT_FUN_8011000003a48590(uVar7);
    return;
  }
  return;
}

