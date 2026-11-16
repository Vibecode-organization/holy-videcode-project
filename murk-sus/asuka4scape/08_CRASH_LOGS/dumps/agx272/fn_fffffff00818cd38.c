// FUN_fffffff00818cd38 @ fffffff00818cd38 size=1288

undefined8 FUN_fffffff00818cd38(long param_1,undefined8 param_2)

{
  uint uVar1;
  long *plVar2;
  undefined8 *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  uint uVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  uint local_44;
  
  iVar6 = *(int *)(param_1 + 0x7fc);
  lVar9 = *(long *)(param_1 + 0x548);
  if ((lVar9 != 0) && ((*(byte *)(*(long *)(param_1 + 0x530) + 0x10a9d) & 1) != 0)) {
    lVar10 = *(long *)(param_1 + 0x610);
    if (lVar9 == 1) {
      lVar12 = 0;
    }
    else if (lVar9 == 7) {
      lVar12 = 2;
    }
    else {
      if (lVar9 != 3) goto LAB_fffffff00818d218;
      lVar12 = 1;
    }
    if (*(long *)(lVar10 + 0x80 + lVar12 * 8) == 0) {
      lVar12 = FUN_fffffff00818d460(param_1);
      if (lVar12 == 0) {
        return 0;
      }
      lVar10 = *(long *)(param_1 + 0x610);
      lVar9 = *(long *)(param_1 + 0x548);
      if (lVar9 == 1) {
        lVar13 = 0;
      }
      else if (lVar9 == 7) {
        lVar13 = 2;
      }
      else {
        if (lVar9 != 3) goto LAB_fffffff00818d218;
        lVar13 = 1;
      }
      *(long *)(lVar10 + 0x80 + lVar13 * 8) = lVar12;
    }
    if (lVar9 == 1) {
      lVar9 = 0;
    }
    else if (lVar9 == 7) {
      lVar9 = 2;
    }
    else {
      if (lVar9 != 3) {
LAB_fffffff00818d218:
        uVar8 = thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Invalid Protection Options\n");
        return uVar8;
      }
      lVar9 = 1;
    }
    return *(undefined8 *)(lVar10 + 0x80 + lVar9 * 8);
  }
  if (*(int *)(param_1 + 0x7ec) == 2) {
LAB_fffffff00818ce30:
    uVar16 = 0;
    lVar9 = 0x50;
    goto LAB_fffffff00818d024;
  }
  if (iVar6 == 2) {
LAB_fffffff00818cf74:
    if (*(long *)(param_1 + 0x820) == 0) {
LAB_fffffff00818d01c:
      uVar16 = 0;
    }
    else {
      uVar11 = *(int *)(*(long *)(param_1 + 0x820) + 0xe8) + 1;
      uVar1 = *(uint *)(param_1 + 0x838);
      uVar5 = 0;
      if (uVar1 != 0) {
        uVar5 = uVar11 / uVar1;
      }
      uVar16 = (ulong)(uVar11 - uVar5 * uVar1);
    }
LAB_fffffff00818d020:
    lVar9 = 0x70;
  }
  else {
    if (iVar6 == 3) {
      lVar9 = *(long *)(param_1 + 0x610);
      if (*(int *)(lVar9 + 0x9c) == 0) {
LAB_fffffff00818cf64:
        uVar16 = 0;
      }
      else {
        uVar16 = 0;
        uVar8 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
        do {
          if (*(int *)(*(long *)(*(long *)(lVar9 + 0x48 + uVar16 * 8) + 0x218) + 0x18) != 0x80) {
            iVar6 = thunk_EXT_FUN_8011000002948c40(uVar8,param_2);
            lVar9 = *(long *)(param_1 + 0x610);
            if (iVar6 != 0) {
              uVar11 = *(uint *)(lVar9 + 0x9c);
              break;
            }
          }
          uVar16 = uVar16 + 1;
          uVar11 = *(uint *)(lVar9 + 0x9c);
        } while (uVar16 < uVar11);
        if (uVar11 != (uint)uVar16) {
          lVar9 = 0x58;
          goto LAB_fffffff00818d024;
        }
        if (uVar11 == 0) goto LAB_fffffff00818cf64;
        uVar16 = 0;
        while (*(int *)(*(long *)(*(long *)(lVar9 + 0x48 + uVar16 * 8) + 0x218) + 0x18) != 0x80) {
          uVar7 = thunk_EXT_FUN_8011000002947748(uVar8);
          lVar9 = *(long *)(param_1 + 0x610);
          if (((uVar7 & 1) != 0) || (uVar16 = uVar16 + 1, *(uint *)(lVar9 + 0x9c) <= uVar16)) break;
        }
        if (*(int *)(lVar9 + 0x9c) != (int)uVar16) goto LAB_fffffff00818cfe0;
      }
      if (*(uint *)(param_1 + 0x838) <= (uint)uVar16) goto LAB_fffffff00818cf74;
    }
    else {
      if (iVar6 != 4) goto LAB_fffffff00818ce30;
      lVar9 = *(long *)(param_1 + 0x610);
      if (*(int *)(lVar9 + 0x9c) == 0) {
LAB_fffffff00818cfe8:
        uVar16 = 0;
      }
      else {
        uVar16 = 0;
        lVar10 = *(long *)(*(long *)(param_1 + 0x530) + 0x148);
        do {
          iVar6 = *(int *)(*(long *)(*(long *)(lVar9 + 0x48 + uVar16 * 8) + 0x218) + 0x18);
          local_44 = 0;
          if (iVar6 != 0x80) {
            uVar7 = thunk_EXT_FUN_80110000029493bc(lVar10,param_2,(long)iVar6,&local_44);
            if ((uVar7 & 1) != 0) {
              uVar7 = (ulong)(*(int *)(lVar10 + 0x144c) - 1U & local_44 >> 8 & 0xff) << 2 |
                      (long)iVar6 << 10;
              piVar4 = (int *)(lVar10 + 0x1450 + (long)(int)uVar7);
              if (uVar7 != (long)(int)uVar7) {
                piVar4 = (int *)(lVar10 + 0x1450 + uVar7 & 0xffffffffffff | 0x2bad000000000000);
              }
              iVar6 = *piVar4;
              *piVar4 = iVar6 + 1;
              uVar11 = iVar6 + (int)uVar16;
              uVar1 = *(uint *)(param_1 + 0x838);
              uVar5 = 0;
              if (uVar1 != 0) {
                uVar5 = uVar11 / uVar1;
              }
              uVar16 = (ulong)(uVar11 - uVar5 * uVar1);
              lVar9 = 0x58;
              if (iVar6 != 0) {
                lVar9 = 0x78;
              }
              goto LAB_fffffff00818d024;
            }
            lVar9 = *(long *)(param_1 + 0x610);
          }
          uVar16 = uVar16 + 1;
        } while (uVar16 < *(uint *)(lVar9 + 0x9c));
        if (*(uint *)(lVar9 + 0x9c) == 0) goto LAB_fffffff00818cfe8;
        uVar16 = 0;
        while (*(int *)(*(long *)(*(long *)(lVar9 + 0x48 + uVar16 * 8) + 0x218) + 0x18) != 0x80) {
          uVar7 = thunk_EXT_FUN_8011000002947748(lVar10);
          lVar9 = *(long *)(param_1 + 0x610);
          if (((uVar7 & 1) != 0) || (uVar16 = uVar16 + 1, *(uint *)(lVar9 + 0x9c) <= uVar16)) break;
        }
        if (*(int *)(lVar9 + 0x9c) != (int)uVar16) {
LAB_fffffff00818cfe0:
          lVar9 = 0x60;
          goto LAB_fffffff00818d024;
        }
      }
      uVar11 = *(uint *)(param_1 + 0x838);
      if (uVar11 <= (uint)uVar16) {
        if (*(long *)(param_1 + 0x820) == 0) goto LAB_fffffff00818d01c;
        uVar1 = *(int *)(*(long *)(param_1 + 0x820) + 0xe8) + 1;
        uVar5 = 0;
        if (uVar11 != 0) {
          uVar5 = uVar1 / uVar11;
        }
        uVar16 = (ulong)(uVar1 - uVar5 * uVar11);
        goto LAB_fffffff00818d020;
      }
    }
    lVar9 = 0x68;
  }
LAB_fffffff00818d024:
  lVar10 = *(long *)(param_1 + 0x610) + 0x48;
  uVar7 = (uVar16 & 0xffffffff) << 3;
  uVar14 = -(uVar16 >> 0x1f & 1) & 0xfffffff800000000 | uVar7;
  iVar6 = (int)uVar7;
  plVar2 = (long *)(lVar10 + iVar6);
  if (uVar14 != (long)iVar6) {
    plVar2 = (long *)(lVar10 + uVar14 & 0xffffffffffff | 0x2bad000000000000);
  }
  if (*plVar2 == 0) {
    lVar10 = FUN_fffffff00818d460(param_1,0);
    if (lVar10 == 0) {
      return 0;
    }
    lVar13 = *(long *)(*(long *)(param_1 + 0x530) + 0x1ac50);
    lVar12 = lVar13 + 0x11d8;
    lVar15 = (ulong)*(uint *)(*(long *)(param_1 + 0x610) + 0x9c) * 8;
    puVar3 = (undefined8 *)(lVar12 + (int)lVar15);
    if (lVar15 - (int)lVar15 != 0) {
      puVar3 = (undefined8 *)(lVar12 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b5664(*(undefined8 *)(lVar13 + 0xd8),*puVar3,1);
    lVar12 = *(long *)(param_1 + 0x610);
    uVar11 = *(uint *)(lVar12 + 0x9c);
    *(uint *)(lVar12 + 0x9c) = uVar11 + 1;
    lVar13 = (ulong)uVar11 * 8;
    plVar2 = (long *)(lVar12 + 0x48 + (long)(int)lVar13);
    if (lVar13 - (int)lVar13 != 0) {
      plVar2 = (long *)(lVar12 + 0x48 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *plVar2 = lVar10;
  }
  lVar10 = *(long *)(*(long *)(param_1 + 0x530) + 0x1ac50);
  thunk_EXT_FUN_80110000039b5664
            (*(undefined8 *)(lVar10 + 0xe0),*(undefined8 *)(lVar10 + 0x1110 + lVar9),1);
  lVar10 = *(long *)(*(long *)(param_1 + 0x530) + 0x1ac50);
  lVar9 = lVar10 + 0x11d8;
  uVar7 = (long)(int)uVar16 * 8;
  uVar16 = uVar7 & 0x7fffffff8;
  puVar3 = (undefined8 *)(lVar9 + (int)uVar16);
  if (uVar16 != (long)(int)uVar16) {
    puVar3 = (undefined8 *)(lVar9 + uVar16 & 0xffffffffffff | 0x2bad000000000000);
  }
  thunk_EXT_FUN_80110000039b5664(*(undefined8 *)(lVar10 + 0xd8),*puVar3,1);
  lVar9 = *(long *)(param_1 + 0x610) + 0x48;
  puVar3 = (undefined8 *)(lVar9 + (int)uVar7);
  if (uVar7 - (long)(int)uVar7 != 0) {
    puVar3 = (undefined8 *)(lVar9 + uVar7 & 0xffffffffffff | 0x2bad000000000000);
  }
  return *puVar3;
}

