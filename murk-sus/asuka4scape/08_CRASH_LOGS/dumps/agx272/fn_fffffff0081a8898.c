// FUN_fffffff0081a8898 @ fffffff0081a8898 size=1072

void FUN_fffffff0081a8898(long *param_1,uint param_2,ulong param_3,ulong param_4)

{
  byte *pbVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  code *pcVar9;
  undefined8 uVar10;
  long lVar11;
  uint uVar12;
  uint uVar13;
  long lVar14;
  int iVar15;
  ulong uVar16;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(param_1[0x178]);
  pbVar1 = (byte *)((long)param_1 + (ulong)param_2 * 0xc + 0xb80);
  *(int *)(pbVar1 + 8) = (int)param_3;
  if ((*pbVar1 & 1) == 0) {
    param_3 = (ulong)*(uint *)(pbVar1 + 4);
    if (1 < (int)param_2) goto LAB_fffffff0081a88f0;
LAB_fffffff0081a8a94:
    uVar12 = (uint)param_3;
    if (param_2 == 0) {
      lVar11 = param_1[0x50];
      *(uint *)(param_1[0x69] + 0x84) = uVar12;
      uVar7 = *(uint *)(lVar11 + 0x10eb0);
      uVar13 = 0;
      if (uVar7 != 0) {
        uVar13 = uVar12 / uVar7;
      }
      uVar13 = uVar13 * 100;
      if (99 < uVar13) {
        uVar13 = 100;
      }
      thunk_EXT_FUN_80110000039b78d4
                (*(undefined8 *)(*(long *)(lVar11 + 0x1ac50) + 0x78),0,
                 (ulong)uVar13 * 0x1999999a >> 0x20);
      lVar11 = param_1[0x50];
      if ((*(byte *)(lVar11 + 0x1ac44) >> 2 & 1) == 0) goto LAB_fffffff0081a8c78;
      uVar5 = *(undefined4 *)(param_1[0x69] + 0x84);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar11 + 0x1ac48));
      uVar6 = 0x85920860;
      goto LAB_fffffff0081a8b1c;
    }
    if (0x10000 < uVar12) goto LAB_fffffff0081a8c78;
    lVar11 = param_1[0x54] + 0x10e4;
    uVar13 = *(uint *)(param_1[0x54] + 0x10e0);
    lVar14 = (ulong)uVar13 * 4;
    piVar3 = (int *)(lVar11 + (int)lVar14);
    if (lVar14 - (int)lVar14 != 0) {
      piVar3 = (int *)(lVar11 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar12 = *piVar3 * uVar12 >> 0x10;
    uVar16 = (ulong)(uVar13 + 1);
    do {
      iVar15 = (int)uVar16;
      uVar7 = iVar15 - 2;
      uVar16 = (ulong)uVar13;
      if (uVar13 <= uVar7) break;
      lVar14 = (ulong)uVar7 * 4;
      puVar2 = (uint *)(lVar11 + (int)lVar14);
      if (lVar14 != (int)lVar14) {
        puVar2 = (uint *)(lVar11 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar16 = (ulong)(iVar15 - 1);
    } while (uVar12 <= *puVar2);
    if ((uint)uVar16 < uVar7) {
      lVar11 = param_1[0x50];
      uVar13 = *(uint *)(lVar11 + 0x10aa8);
    }
    else {
      lVar14 = (ulong)uVar7 * 4;
      piVar3 = (int *)(lVar11 + (int)lVar14);
      if (lVar14 != (int)lVar14) {
        piVar3 = (int *)(lVar11 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar14 = uVar16 * 4;
      piVar4 = (int *)(lVar11 + (int)lVar14);
      if (lVar14 != (int)lVar14) {
        piVar4 = (int *)(lVar11 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar8 = *piVar4 - *piVar3;
      uVar13 = 0;
      if (uVar8 != 0) {
        uVar13 = ((uVar12 - *piVar3) * 100) / uVar8;
      }
      uVar13 = uVar13 + uVar7 * 100;
      lVar11 = param_1[0x50];
      if (uVar13 <= *(uint *)(lVar11 + 0x10aa8)) {
        uVar13 = *(uint *)(lVar11 + 0x10aa8);
      }
    }
    lVar14 = param_1[0x69];
    *(uint *)(lVar14 + 0x88) = uVar13;
    if ((*(byte *)(lVar11 + 0x1ac44) >> 2 & 1) == 0) goto LAB_fffffff0081a8c78;
    uVar5 = *(undefined4 *)(lVar14 + 0x88);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar11 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85920864,uVar5,param_3 & 0xffffffff,0,0,0);
    uVar10 = *(undefined8 *)(lVar11 + 0x1ac48);
  }
  else {
    if ((int)param_2 < 2) goto LAB_fffffff0081a8a94;
LAB_fffffff0081a88f0:
    if (param_2 != 2) {
      if (param_2 == 3) {
        (**(code **)(*param_1 + 0x9e0))(param_1,param_3,param_4);
      }
      else {
        (**(code **)(*param_1 + 0x9e8))(param_1,param_3);
      }
      goto LAB_fffffff0081a8c78;
    }
    if (0x10000 < (uint)param_3) goto LAB_fffffff0081a8c78;
    lVar11 = param_1[0x54] + 0x10e4;
    uVar12 = *(uint *)(param_1[0x54] + 0x10e0);
    lVar14 = (ulong)uVar12 * 4;
    piVar3 = (int *)(lVar11 + (int)lVar14);
    if (lVar14 - (int)lVar14 != 0) {
      piVar3 = (int *)(lVar11 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar13 = *piVar3 * (uint)param_3 >> 0x10;
    uVar16 = (ulong)(uVar12 + 1);
    do {
      iVar15 = (int)uVar16;
      uVar7 = iVar15 - 2;
      uVar16 = (ulong)uVar12;
      if (uVar12 <= uVar7) break;
      lVar14 = (ulong)uVar7 * 4;
      puVar2 = (uint *)(lVar11 + (int)lVar14);
      if (lVar14 != (int)lVar14) {
        puVar2 = (uint *)(lVar11 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar16 = (ulong)(iVar15 - 1);
    } while (uVar13 <= *puVar2);
    if ((uint)uVar16 < uVar7) {
      lVar11 = param_1[0x50];
      uVar12 = *(uint *)(lVar11 + 0x10aa8);
    }
    else {
      lVar14 = (ulong)uVar7 * 4;
      piVar3 = (int *)(lVar11 + (int)lVar14);
      if (lVar14 != (int)lVar14) {
        piVar3 = (int *)(lVar11 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar14 = uVar16 * 4;
      piVar4 = (int *)(lVar11 + (int)lVar14);
      if (lVar14 != (int)lVar14) {
        piVar4 = (int *)(lVar11 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar8 = *piVar4 - *piVar3;
      uVar12 = 0;
      if (uVar8 != 0) {
        uVar12 = ((uVar13 - *piVar3) * 100) / uVar8;
      }
      uVar12 = uVar12 + uVar7 * 100;
      lVar11 = param_1[0x50];
      if (uVar12 <= *(uint *)(lVar11 + 0x10aa8)) {
        uVar12 = *(uint *)(lVar11 + 0x10aa8);
      }
    }
    lVar14 = param_1[0x69];
    *(uint *)(lVar14 + 0x8c) = uVar12;
    if ((*(byte *)(lVar11 + 0x1ac44) >> 2 & 1) == 0) goto LAB_fffffff0081a8c78;
    uVar5 = *(undefined4 *)(lVar14 + 0x8c);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar11 + 0x1ac48));
    uVar6 = 0x85920868;
LAB_fffffff0081a8b1c:
    thunk_EXT_FUN_80110000036da494(uVar6,uVar5,param_3 & 0xffffffff,param_4 & 0xffffffff,0,0);
    uVar10 = *(undefined8 *)(lVar11 + 0x1ac48);
  }
  thunk_EXT_FUN_8011000003222de0(uVar10);
LAB_fffffff0081a8c78:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000003222de0(param_1[0x178]);
    return;
  }
                    /* WARNING: Does not return */
  pcVar9 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081a8c9c);
  (*pcVar9)();
}

