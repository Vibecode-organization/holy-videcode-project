// FUN_fffffff009942da8 @ fffffff009942da8 size=364

/* WARNING: Removing unreachable block (ram,0xfffffff009943038) */
/* WARNING: Removing unreachable block (ram,0xfffffff009942ffc) */

undefined8 FUN_fffffff009942da8(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  undefined1 auVar12 [16];
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x48));
  if (((*(byte *)(param_1 + 0x24) & 1) == 0) ||
     (iVar4 = FUN_fffffff00997f414(param_2,*(undefined8 *)(param_1 + 0x28)), iVar4 != 0)) {
    uVar2 = *(uint *)(param_1 + 0x50);
    if (uVar2 == 2) {
      lVar11 = param_1 + 0x60;
    }
    else {
      lVar11 = *(long *)(param_1 + 0x58);
    }
    uVar6 = (ulong)*(uint *)(param_1 + 0x54);
    if (*(uint *)(param_1 + 0x54) == uVar2) {
      uVar3 = uVar2 * 2;
      uVar6 = -(ulong)((uVar2 & 0x7fffffff) >> 0x1e) & 0xfffffff800000000 | (ulong)uVar3 << 3;
      if (0x7fffffff < uVar3) {
        uVar6 = 0x8000000000000000;
      }
      lVar5 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1098,uVar6);
      if (lVar5 == 0) {
        auVar12 = FUN_fffffff0099833c4();
        lVar11 = auVar12._0_8_;
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar11 + 0x48));
        if (*(int *)(lVar11 + 0x50) == 2) {
          lVar5 = lVar11 + 0x60;
        }
        else {
          lVar5 = *(long *)(lVar11 + 0x58);
        }
        uVar2 = *(uint *)(lVar11 + 0x54);
        uVar6 = (ulong)uVar2;
        if ((int)uVar2 < 1) {
          uVar7 = 0;
LAB_fffffff009942f94:
          if ((int)uVar7 < (int)uVar6) {
            lVar8 = uVar6 - (uVar7 & 0xffffffff);
            uVar7 = uVar7 & 0xffffffff;
            do {
              *(undefined8 *)(lVar5 + uVar7 * 8) = *(undefined8 *)(lVar5 + (uVar7 + 1) * 8);
              lVar8 = lVar8 + -1;
              uVar7 = uVar7 + 1;
            } while (lVar8 != 0);
          }
          if ((0 < (int)uVar2) && ((*(byte *)(lVar11 + 0x24) >> 1 & 1) != 0)) {
            FUN_fffffff00997f598(auVar12._8_8_,*(undefined8 *)(lVar11 + 0x28));
            uVar6 = (ulong)*(uint *)(lVar11 + 0x54);
          }
        }
        else {
          uVar7 = 0;
          do {
            if (*(long *)(lVar5 + uVar7 * 8) == auVar12._8_8_) {
              *(undefined8 *)(lVar5 + uVar7 * 8) = 0;
              *(uint *)(lVar11 + 0x54) = uVar2 - 1;
              uVar6 = (ulong)(uVar2 - 1);
              goto LAB_fffffff009942f94;
            }
            uVar7 = uVar7 + 1;
          } while (uVar6 != uVar7);
          uVar6 = 1;
        }
        if ((int)uVar6 != 0) {
          uVar10 = thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar11 + 0x48));
          return uVar10;
        }
        uVar2 = *(uint *)(lVar11 + 0x24);
        uVar10 = thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar11 + 0x48));
        if ((uVar2 >> 1 & 1) != 0) {
          uVar10 = FUN_fffffff009942c08(lVar11);
          return uVar10;
        }
        return uVar10;
      }
      uVar6 = (ulong)*(uint *)(param_1 + 0x54);
      if (0 < (int)*(uint *)(param_1 + 0x54)) {
        lVar8 = 0;
        uVar7 = uVar6;
        do {
          lVar9 = lVar8 * 8;
          puVar1 = (undefined8 *)(lVar5 + (int)lVar9);
          if (lVar9 - (int)lVar9 != 0) {
            puVar1 = (undefined8 *)(lVar5 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *puVar1 = *(undefined8 *)(lVar11 + lVar8 * 8);
          lVar8 = lVar8 + 1;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
      if (lVar11 != param_1 + 0x60) {
        lVar8 = (long)(int)*(uint *)(param_1 + 0x50) << 3;
        if (0x7fffffff < *(uint *)(param_1 + 0x50)) {
          lVar8 = -0x8000000000000000;
        }
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff10e8,lVar11,lVar8);
        uVar6 = (ulong)*(uint *)(param_1 + 0x54);
      }
      *(long *)(param_1 + 0x58) = lVar5;
      *(uint *)(param_1 + 0x50) = uVar3;
      lVar11 = lVar5;
    }
    *(int *)(param_1 + 0x54) = (int)uVar6 + 1;
    uVar7 = -(uVar6 >> 0x1f) & 0xfffffff800000000 | uVar6 << 3;
    iVar4 = (int)(uVar6 << 3);
    puVar1 = (undefined8 *)(lVar11 + iVar4);
    if (uVar7 != (long)iVar4) {
      puVar1 = (undefined8 *)(lVar11 + uVar7 & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar1 = param_2;
    uVar10 = 1;
  }
  else {
    uVar10 = 0;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x48));
  return uVar10;
}

