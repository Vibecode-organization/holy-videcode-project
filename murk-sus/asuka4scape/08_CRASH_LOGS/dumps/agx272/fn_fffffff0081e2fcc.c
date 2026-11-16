// FUN_fffffff0081e2fcc @ fffffff0081e2fcc size=896

long * FUN_fffffff0081e2fcc(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  int iVar8;
  ulong uVar9;
  undefined8 *puVar10;
  long lVar11;
  long *plVar12;
  ulong uVar13;
  long *plVar14;
  ulong uVar15;
  undefined8 uVar16;
  long lVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  
  uVar4 = thunk_EXT_FUN_8011000002c13530(param_2);
  uVar2 = *(uint *)(param_1 + 0x24);
  uVar3 = 0;
  if (uVar2 != 0) {
    uVar3 = (uVar2 + uVar4) / uVar2;
  }
  uVar3 = uVar3 * uVar2;
  uVar15 = (ulong)uVar3;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x28));
  uVar13 = (ulong)uVar4;
  if (*(uint *)(param_1 + 0x1c) < uVar3) {
    if ((*(byte *)(*(long *)(param_1 + 0x30) + 0x1ac44) >> 3 & 1) != 0) {
      FUN_fffffff00817dc48
                (*(long *)(param_1 + 0x30),0x342,0,param_1,uVar13,*(uint *)(param_1 + 0x1c),uVar15,0
                );
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x28));
    lVar5 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca42d8,uVar15 << 3);
    if (lVar5 == 0) {
      return (long *)0x0;
    }
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x28));
    if (*(uint *)(param_1 + 0x1c) < uVar3) {
      if ((*(byte *)(*(long *)(param_1 + 0x30) + 0x1ac44) >> 3 & 1) != 0) {
        FUN_fffffff00817dc48
                  (*(long *)(param_1 + 0x30),0x342,0,param_1,uVar13,*(uint *)(param_1 + 0x1c),uVar15
                   ,0);
      }
      uVar2 = *(uint *)(param_1 + 0x20);
      uVar6 = (ulong)uVar2;
      uVar15 = *(ulong *)(param_1 + 0x10);
      if (uVar2 == 0) {
        lVar17 = 0;
      }
      else {
        uVar7 = 0;
        if ((uVar2 < 4) || (lVar5 - uVar15 < 0x20)) {
LAB_fffffff0081e32e0:
          lVar17 = uVar6 - uVar7;
          do {
            lVar11 = uVar7 * 8;
            iVar8 = (int)lVar11;
            puVar10 = (undefined8 *)(uVar15 + (long)iVar8);
            if (lVar11 - iVar8 != 0) {
              puVar10 = (undefined8 *)(uVar15 + lVar11 & 0xffffffffffff | 0x2bad000000000000);
            }
            puVar1 = (undefined8 *)(lVar5 + iVar8);
            if (lVar11 - iVar8 != 0) {
              puVar1 = (undefined8 *)(lVar5 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
            }
            *puVar1 = *puVar10;
            uVar7 = uVar7 + 1;
            lVar17 = lVar17 + -1;
          } while (lVar17 != 0);
        }
        else {
          lVar17 = 0;
          uVar7 = uVar6 & 0xfffffffc;
          uVar9 = uVar7;
          do {
            puVar10 = (undefined8 *)(uVar15 + lVar17 * 8);
            if (((uVar15 ^ (ulong)puVar10) & 0xffc0000000000000) != 0) {
              puVar10 = (undefined8 *)((ulong)puVar10 & 0xffffffffffff | 0xc8a2000000000000);
            }
            lVar11 = lVar17 * 8;
            puVar1 = (undefined8 *)(lVar5 + (int)lVar11);
            if (lVar11 - (int)lVar11 != 0) {
              puVar1 = (undefined8 *)(lVar5 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
            }
            uVar16 = *puVar10;
            uVar19 = puVar10[3];
            uVar18 = puVar10[2];
            puVar1[1] = puVar10[1];
            *puVar1 = uVar16;
            puVar1[3] = uVar19;
            puVar1[2] = uVar18;
            lVar17 = lVar17 + 4;
            uVar9 = uVar9 - 4;
          } while (uVar9 != 0);
          if (uVar7 != uVar6) goto LAB_fffffff0081e32e0;
        }
        lVar17 = uVar6 << 3;
      }
      *(undefined8 *)(param_1 + 0x10) = 0;
      thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4288,uVar15,lVar17);
      *(long *)(param_1 + 0x10) = lVar5;
      *(uint *)(param_1 + 0x1c) = uVar3;
      *(uint *)(param_1 + 0x20) = uVar3;
      goto LAB_fffffff0081e3024;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x28));
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca4328,lVar5,uVar15 << 3);
  }
  else {
LAB_fffffff0081e3024:
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x28));
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x28));
  lVar5 = *(long *)(param_1 + 0x10);
  lVar17 = uVar13 * 8;
  iVar8 = (int)lVar17;
  puVar10 = (undefined8 *)(lVar5 + iVar8);
  if (lVar17 - iVar8 != 0) {
    puVar10 = (undefined8 *)(lVar5 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
  }
  plVar14 = (long *)*puVar10;
  if (plVar14 != (long *)0x0) {
    uVar13 = thunk_EXT_FUN_801100000294991c(plVar14);
    if ((uVar13 & 1) != 0) goto LAB_fffffff0081e3188;
    lVar5 = *(long *)(param_1 + 0x10);
  }
  puVar10 = (undefined8 *)(lVar5 + iVar8);
  if (lVar17 - iVar8 != 0) {
    puVar10 = (undefined8 *)(lVar5 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar10 = 0;
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x28));
  uVar16 = *(undefined8 *)(param_1 + 0x30);
  plVar14 = (long *)(**(code **)(DAT_fffffff00ae230c8 + 0x68))();
  if (plVar14 == (long *)0x0) {
    return (long *)0x0;
  }
  uVar13 = FUN_fffffff0081e2424(plVar14,uVar16,param_2);
  if ((uVar13 & 1) == 0) {
    (**(code **)(*plVar14 + 0x28))(plVar14);
    return (long *)0x0;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x28));
  lVar5 = *(long *)(param_1 + 0x10);
  plVar12 = (long *)(lVar5 + iVar8);
  if (lVar17 - iVar8 != 0) {
    plVar12 = (long *)(lVar5 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
  }
  plVar12 = (long *)*plVar12;
  if (plVar12 != (long *)0x0) {
    uVar13 = thunk_EXT_FUN_801100000294991c(plVar12);
    if ((uVar13 & 1) != 0) {
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x28));
      (**(code **)(*plVar14 + 0x28))(plVar14);
      return plVar12;
    }
    lVar5 = *(long *)(param_1 + 0x10);
  }
  plVar12 = (long *)(lVar5 + iVar8);
  if (lVar17 - iVar8 != 0) {
    plVar12 = (long *)(lVar5 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *plVar12 = (long)plVar14;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  *(undefined1 *)(plVar14 + 6) = 1;
LAB_fffffff0081e3188:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x28));
  return plVar14;
}

