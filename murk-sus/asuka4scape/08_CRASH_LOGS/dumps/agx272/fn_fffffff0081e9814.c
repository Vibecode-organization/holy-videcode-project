// FUN_fffffff0081e9814 @ fffffff0081e9814 size=2132

undefined8 FUN_fffffff0081e9814(long *param_1,long param_2,uint *param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  int iVar7;
  undefined8 uVar8;
  long lVar9;
  uint uVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  ulong uVar15;
  long lVar16;
  long lVar17;
  
  bVar6 = (int)param_1[0x38] == 0;
  if ((int)param_1[0x38] == 0) {
    uVar8 = FUN_fffffff0081e0b20(param_1[7]);
    if ((int)uVar8 != 0) goto LAB_fffffff0081e9b84;
    *(int *)(param_1 + 0x38) = (int)param_1[0x38] + 1;
  }
  lVar11 = param_1[4];
  if (*(int *)(lVar11 + 0x80) == 0) {
    uVar8 = FUN_fffffff0081e0b20(*(undefined8 *)(lVar11 + 0x88));
    if ((int)uVar8 != 0) goto LAB_fffffff0081e9b84;
    lVar11 = param_1[4];
    *(int *)(lVar11 + 0x80) = *(int *)(lVar11 + 0x80) + 1;
    bVar6 = true;
  }
  uVar8 = thunk_EXT_FUN_801100000297b3fc(*(undefined8 *)(*(long *)(lVar11 + 0x20) + 0x20));
  if ((int)uVar8 != 0) {
LAB_fffffff0081e9b84:
    (**(code **)(*param_1 + 0x120))(param_1);
    if (*(long *)(param_2 + 0xc08) != 0) {
      thunk_EXT_FUN_801100000297b408();
      if (*(long **)(param_2 + 0xc08) != (long *)0x0) {
        (**(code **)(**(long **)(param_2 + 0xc08) + 0x28))();
      }
      *(undefined8 *)(param_2 + 0xc08) = 0;
    }
    if (*(long *)(param_2 + 0xc10) != 0) {
      thunk_EXT_FUN_801100000297b408(*(long *)(param_2 + 0xc10));
      if (*(long **)(param_2 + 0xc10) != (long *)0x0) {
        (**(code **)(**(long **)(param_2 + 0xc10) + 0x28))();
      }
      *(undefined8 *)(param_2 + 0xc10) = 0;
    }
    if (*(long *)(param_2 + 0xc30) != 0) {
      thunk_EXT_FUN_801100000297b408(*(long *)(param_2 + 0xc30));
      if (*(long **)(param_2 + 0xc30) != (long *)0x0) {
        (**(code **)(**(long **)(param_2 + 0xc30) + 0x28))();
      }
      *(undefined8 *)(param_2 + 0xc30) = 0;
    }
    lVar11 = *(long *)(param_2 + 0xc28);
    if (lVar11 != 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar11 + 0x40));
      if (0 < *(long *)(lVar11 + 0x38)) {
        if (*(long *)(lVar11 + 0x50) != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        if (*(long *)(lVar11 + 0x58) != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        *(long *)(lVar11 + 0x38) = *(long *)(lVar11 + 0x38) + -1;
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar11 + 0x40));
      if (*(long **)(param_2 + 0xc28) != (long *)0x0) {
        (**(code **)(**(long **)(param_2 + 0xc28) + 0x28))();
      }
      *(undefined8 *)(param_2 + 0xc28) = 0;
    }
    lVar11 = *(long *)(param_2 + 0xc38);
    if (lVar11 != 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar11 + 0x40));
      if (0 < *(long *)(lVar11 + 0x38)) {
        if (*(long *)(lVar11 + 0x50) != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        if (*(long *)(lVar11 + 0x58) != 0) {
          thunk_EXT_FUN_801100000297b408();
        }
        *(long *)(lVar11 + 0x38) = *(long *)(lVar11 + 0x38) + -1;
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar11 + 0x40));
      if (*(long **)(param_2 + 0xc38) != (long *)0x0) {
        (**(code **)(**(long **)(param_2 + 0xc38) + 0x28))();
      }
      *(undefined8 *)(param_2 + 0xc38) = 0;
    }
    *(undefined1 *)(param_1 + 5) = 1;
    *(int *)(param_1 + 0x26) = (int)param_1[0x27];
    return uVar8;
  }
  lVar11 = thunk_EXT_FUN_801100000293f960(*(undefined8 *)(*(long *)(param_1[4] + 0x20) + 0x28));
  lVar12 = param_1[4];
  lVar16 = *(long *)(lVar12 + 0x70);
  if (lVar16 != lVar11) {
    *(long *)(lVar12 + 0x70) = lVar11;
  }
  (**(code **)(**(long **)(*(long *)(lVar12 + 0x20) + 0x20) + 0x20))();
  uVar8 = *(undefined8 *)(param_1[4] + 0x28);
  *(undefined8 *)(param_2 + 0xc08) = *(undefined8 *)(*(long *)(param_1[4] + 0x20) + 0x20);
  uVar8 = thunk_EXT_FUN_801100000297b3fc(uVar8);
  if ((int)uVar8 != 0) goto LAB_fffffff0081e9b84;
  (**(code **)(**(long **)(param_1[4] + 0x28) + 0x20))();
  *(undefined8 *)(param_2 + 0xc10) = *(undefined8 *)(param_1[4] + 0x28);
  uVar8 = FUN_fffffff0081e0b20(param_1[8]);
  if ((int)uVar8 != 0) goto LAB_fffffff0081e9b84;
  lVar12 = thunk_EXT_FUN_801100000293f960(*(undefined8 *)(param_1[8] + 0x48));
  if (param_1[0x34] != lVar12) {
    param_1[0x34] = lVar12;
    bVar6 = true;
  }
  (**(code **)(*(long *)param_1[8] + 0x20))();
  *(long *)(param_2 + 0xc28) = param_1[8];
  uVar8 = FUN_fffffff0081e0b20(*(undefined8 *)(param_1[4] + 0x90));
  if ((int)uVar8 != 0) goto LAB_fffffff0081e9b84;
  lVar12 = thunk_EXT_FUN_801100000293f960(*(undefined8 *)(*(long *)(param_1[4] + 0x90) + 0x48));
  lVar13 = param_1[4];
  if (*(long *)(lVar13 + 0x78) != lVar12) {
    *(long *)(lVar13 + 0x78) = lVar12;
    bVar6 = true;
  }
  (**(code **)(**(long **)(lVar13 + 0x90) + 0x20))();
  *(undefined8 *)(param_2 + 0xc20) = *(undefined8 *)(param_1[4] + 0x90);
  uVar8 = FUN_fffffff0081e0b20(param_1[6]);
  if ((int)uVar8 != 0) goto LAB_fffffff0081e9b84;
  lVar12 = thunk_EXT_FUN_801100000293f960(*(undefined8 *)(param_1[6] + 0x48));
  if (param_1[0x37] != lVar12) {
    param_1[0x37] = lVar12;
    bVar6 = true;
  }
  (**(code **)(*(long *)param_1[6] + 0x20))();
  *(long *)(param_2 + 0xc38) = param_1[6];
  uVar8 = thunk_EXT_FUN_801100000297b3fc(*(undefined8 *)(param_1[9] + 0x20));
  if ((int)uVar8 != 0) goto LAB_fffffff0081e9b84;
  lVar12 = thunk_EXT_FUN_801100000293f960(*(undefined8 *)(param_1[9] + 0x28));
  lVar13 = param_1[0x35];
  if (lVar13 != lVar12) {
    param_1[0x35] = lVar12;
  }
  (**(code **)(**(long **)(param_1[9] + 0x20) + 0x20))();
  *(undefined8 *)(param_2 + 0xc30) = *(undefined8 *)(param_1[9] + 0x20);
  if ((*(byte *)(param_1 + 0x33) & 1) != 0) {
    uVar10 = *(uint *)(param_1[0x11] + 8);
    uVar2 = *(uint *)(param_1[0x11] + 4);
    if ((*(uint *)(param_1 + 0x27) <= uVar10) || (*(uint *)(param_1 + 0x27) <= uVar2))
    goto LAB_fffffff0081ea058;
    for (; uVar10 != uVar2; uVar10 = (uVar10 + 1) - uVar4 * uVar3) {
      lVar9 = (ulong)uVar10 * 8;
      puVar1 = (undefined8 *)(param_1[0x32] + (long)(int)lVar9);
      if (lVar9 != (int)lVar9) {
        puVar1 = (undefined8 *)(param_1[0x32] + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
      }
      (**(code **)(*(long *)*puVar1 + 0x78))((long *)*puVar1,2);
      uVar3 = *(uint *)(param_1 + 0x27);
      uVar4 = 0;
      if (uVar3 != 0) {
        uVar4 = (uVar10 + 1) / uVar3;
      }
    }
    *(undefined1 *)(param_1 + 0x33) = 0;
  }
  uVar8 = (**(code **)(*param_1 + 0x118))(param_1,param_2);
  if ((int)uVar8 != 0) goto LAB_fffffff0081e9b84;
  lVar9 = (**(code **)(*param_1 + 0x128))(param_1);
  lVar17 = param_1[0x36];
  if (lVar17 != lVar9) {
    param_1[0x36] = lVar9;
  }
  if ((int)param_1[0x23] != 0) {
    uVar15 = 0;
    lVar14 = param_1[0x22];
    do {
      (**(code **)(**(long **)(lVar14 + uVar15 * 8) + 0x90))();
      lVar14 = param_1[0x22];
      *(undefined8 *)(lVar14 + uVar15 * 8) = 0;
      uVar15 = uVar15 + 1;
    } while (uVar15 < *(uint *)(param_1 + 0x23));
  }
  *(undefined4 *)(param_1 + 0x23) = 0;
  if (lVar17 == lVar9) {
    uVar10 = *(uint *)(param_1 + 0x27);
  }
  else {
    uVar2 = *(uint *)(param_1[0x11] + 8);
    uVar3 = *(uint *)(param_1[0x11] + 4);
    uVar10 = *(uint *)(param_1 + 0x27);
    if ((uVar10 <= uVar2) || (uVar10 <= uVar3)) goto LAB_fffffff0081ea058;
    for (; uVar2 != uVar3; uVar2 = (uVar2 + 1) - uVar4 * uVar10) {
      lVar14 = (ulong)uVar2 * 8;
      puVar1 = (undefined8 *)(param_1[0x32] + (long)(int)lVar14);
      if (lVar14 != (int)lVar14) {
        puVar1 = (undefined8 *)(param_1[0x32] + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
      }
      (**(code **)(*param_1 + 0xe8))(param_1,*puVar1);
      uVar10 = *(uint *)(param_1 + 0x27);
      uVar4 = 0;
      if (uVar10 != 0) {
        uVar4 = (uVar2 + 1) / uVar10;
      }
    }
  }
  uVar2 = ((uint *)param_1[0x11])[1];
  if ((uVar10 <= uVar2) || (uVar3 = *(uint *)param_1[0x11], uVar4 = uVar2, uVar10 <= uVar3)) {
LAB_fffffff0081ea058:
    uVar8 = thunk_EXT_FUN_8011000003a49114
                      (
                      "AGXk: %s:%d:%s: !!! Assertion failed: %s: OOB access in GPU Driver Resource\n"
                      );
    return uVar8;
  }
  for (; uVar4 != uVar3; uVar4 = (uVar4 + 1) - uVar5 * uVar10) {
    lVar14 = (ulong)uVar4 * 8;
    puVar1 = (undefined8 *)(param_1[0x32] + (long)(int)lVar14);
    if (lVar14 != (int)lVar14) {
      puVar1 = (undefined8 *)(param_1[0x32] + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
    }
    (**(code **)(*param_1 + 0xe8))(param_1,*puVar1);
    uVar10 = *(uint *)(param_1 + 0x27);
    uVar5 = 0;
    if (uVar10 != 0) {
      uVar5 = (uVar4 + 1) / uVar10;
    }
    uVar2 = uVar3;
  }
  DataMemoryBarrier(2,3);
  *param_3 = uVar2;
  if (lVar16 != lVar11) {
    bVar6 = true;
  }
  if (((bVar6) || (lVar13 != lVar12)) || (lVar17 != lVar9)) {
    *(undefined1 *)(param_1 + 5) = 1;
    *(undefined4 *)(param_1 + 0x26) = *(undefined4 *)(param_1[0x11] + 8);
  }
  else if ((char)param_1[5] == '\0') goto LAB_fffffff0081e9f7c;
  if ((*(int *)(param_1[4] + 0x30) == 0) &&
     (iVar7 = (**(code **)(*param_1 + 0xf0))(param_1,param_3), iVar7 != 0)) {
    *(undefined1 *)(param_1 + 5) = 3;
    *(undefined4 *)(param_1 + 0x26) = *(undefined4 *)(param_1[0x11] + 8);
    *(uint *)((long)param_1 + 0x134) = *param_3;
  }
LAB_fffffff0081e9f7c:
  *(undefined4 *)((long)param_1 + 0x5c) = 1;
  return 0;
}

