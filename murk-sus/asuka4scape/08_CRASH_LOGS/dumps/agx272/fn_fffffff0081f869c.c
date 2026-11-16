// FUN_fffffff0081f869c @ fffffff0081f869c size=4

ulong FUN_fffffff0081f869c(long param_1,long param_2)

{
  ulong uVar1;
  byte bVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  ulong uVar11;
  undefined8 uVar12;
  
  uVar6 = (**(code **)(PTR_DAT_fffffff007ca60f0 + 0xa0))();
  bVar2 = *(byte *)(param_1 + 0x10);
  if (param_2 == 0) {
    bVar4 = false;
    if (bVar2 != 0x80) goto LAB_fffffff0081f877c;
LAB_fffffff0081f86f8:
    if (*(long *)(param_1 + 0x30) == 0) {
LAB_fffffff0081f8784:
      if ((*(byte *)(param_1 + 0xb1) & 1) != 0) {
        return uVar6 & 0xfffffffc | 0x8500000001;
      }
      if (!(bool)(((bVar2 & 0xbf) == 0 || bVar2 == 0x80) & bVar4)) {
        if (bVar2 == 3) {
          return 0;
        }
        return uVar6;
      }
      uVar9 = (uint)*(undefined8 *)(param_2 + 0x58);
      if ((uVar9 >> 0x1b & 1) == 0) {
        uVar8 = *(ulong *)(param_2 + 0x20);
        if ((uVar8 == 0) || (*(long *)(param_2 + 0x28) == 0)) {
          return uVar6 | 0x500000000;
        }
        uVar11 = uVar8 >> 0x20;
        if (0x10 < uVar11) {
          if (uVar8 >> 0x21 < 9) {
            return uVar6 | 0x100000000;
          }
          if (0x12 < uVar11) {
            if (uVar8 >> 0x22 < 5) {
              return uVar6 | 0x200000000;
            }
            if (uVar8 < 0x14ffc00000) {
              return uVar6 | 0x300000000;
            }
            if (uVar11 < 0x15) {
              return uVar6 | 0x400000000;
            }
            if (uVar8 >> 0x24 < 7) {
              return uVar6 | 0x500000000;
            }
            if (0xffffff9fffdfffff < uVar8) {
              if (uVar8 < 0xffffffa000000000) {
                return uVar6 | 0x700000000;
              }
              if (uVar8 < 0xffffffa0c0000000) {
                return uVar6 | 0x800000000;
              }
              if (uVar8 < 0xffffffa180000000) {
                return uVar6 | 0x20900000000;
              }
              if (uVar8 < 0xffffffa181400000) {
                return uVar6 | 0xa00000000;
              }
              if (uVar8 < 0xffffffa185400000) {
                return uVar6 | 0xb00000000;
              }
              if (uVar8 < 0xffffffa189400000) {
                return uVar6 | 0xc00000000;
              }
            }
          }
        }
        goto LAB_fffffff0081f8a44;
      }
      uVar10 = *(uint *)(param_2 + 0x14) & 0x8000;
      uVar8 = 0x500000000;
      if (uVar10 != 0) {
        uVar8 = 0x100000000;
      }
      uVar9 = uVar9 >> 0x1c & 7;
      uVar10 = uVar10 >> 0xf;
      uVar11 = 1;
      if (uVar9 < 4) {
        if (uVar9 == 1) {
LAB_fffffff0081f88cc:
          uVar11 = 3;
        }
        else {
          uVar3 = 0;
          if (uVar9 != 2) {
            uVar3 = uVar10;
          }
          uVar10 = uVar3;
          uVar11 = 1;
        }
      }
      else {
        if (uVar9 == 4) goto LAB_fffffff0081f88cc;
        if (uVar9 == 5) {
          if ((*(byte *)(*(long *)(param_1 + 0x50) + 0x5ce) >> 1 & 1) != 0) {
            uVar11 = uVar6 & 2 | 1;
            uVar8 = 0x300000000;
            goto LAB_fffffff0081f88dc;
          }
          uVar11 = 1;
        }
      }
      uVar11 = uVar11 & (uVar6 & 2 | 1);
LAB_fffffff0081f88dc:
      uVar1 = 0x1000000000;
      if (uVar10 == 0) {
        uVar1 = 0;
      }
      return uVar11 | uVar6 & 0xfffffffc | uVar1 | uVar8;
    }
  }
  else {
    bVar4 = *(char *)(param_2 + 0x13) != '\0';
    if (bVar2 == 0x80) goto LAB_fffffff0081f86f8;
LAB_fffffff0081f877c:
    if (bVar2 != 0x82) goto LAB_fffffff0081f8784;
  }
  lVar7 = thunk_EXT_FUN_8011000002951974(param_1);
  uVar12 = *(undefined8 *)(*(long *)(lVar7 + 0x30) + 0x10);
  iVar5 = thunk_EXT_FUN_8011000002c26750(uVar12);
  if (iVar5 == 0) {
    uVar9 = 5;
  }
  else {
    uVar8 = thunk_EXT_FUN_8011000002c1e9b0(uVar12,*(undefined4 *)(*(long *)(lVar7 + 0x30) + 0x4c));
    if ((((uVar8 & 0xffffffff & DAT_fffffff00ae21810 >> 4) != 0) ||
        (uVar9 = (uint)(uVar8 >> 8) & 0xffffff, (uint)uVar8 < 0x200 || 0xffffffef < uVar9 - 0x11))
       || ((uVar9 - 1 & 0xfffffff0) != 0x10)) {
      return 0;
    }
    uVar9 = 3;
  }
  iVar5 = thunk_EXT_FUN_8011000002c269f8(uVar12);
  uVar10 = 0xe;
  if (iVar5 == 0) {
    uVar10 = uVar9;
  }
  if (uVar10 != 0xd && uVar10 != 6) {
    uVar8 = uVar6 & 0xfffffffc | 0x10;
    if (iVar5 == 0) {
      uVar8 = uVar6;
    }
    uVar6 = 0x1000000000000;
    if (iVar5 == 0) {
      uVar6 = 0;
    }
    return uVar6 | (ulong)uVar10 << 0x20 | uVar8;
  }
LAB_fffffff0081f8a44:
  uVar6 = thunk_EXT_FUN_8011000003a49114
                    (
                    "AGXk: %s:%d:%s: !!! Assertion failed: %s: attempting to encode illegal memory range\n"
                    );
  return uVar6;
}

