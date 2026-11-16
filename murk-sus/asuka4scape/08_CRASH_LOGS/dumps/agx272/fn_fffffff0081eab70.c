// FUN_fffffff0081eab70 @ fffffff0081eab70 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0081eac00) */

undefined8 FUN_fffffff0081eab70(long *param_1,long param_2)

{
  undefined8 *puVar1;
  ulong uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  long lVar13;
  uint uVar14;
  ulong uStack_60;
  ulong uStack_58;
  
  if ((*(byte *)(param_1[2] + 0x10a9c) & 1) == 0) {
    return 1;
  }
  uStack_60 = 0;
  uStack_58 = 0;
  thunk_EXT_FUN_8011000003398268(10000000000,&uStack_58);
  thunk_EXT_FUN_8011000003398268(1000000000,&uStack_60);
  thunk_EXT_FUN_80110000032222a8(param_1[0x24]);
  uVar8 = (**(code **)(*param_1 + 0x138))(*param_1 + 0x138,param_1);
  if ((uVar8 & 1) != 0) {
    uVar12 = 1;
    goto LAB_fffffff0081eaf00;
  }
  uVar7 = (**(code **)(*param_1 + 200))(param_1);
  uVar2 = param_1[0x2e];
  uVar8 = (uVar2 + param_1[0x2f] * 4) / 5;
  if (uVar8 <= uVar2) {
    uVar8 = uVar2;
  }
  param_1[0x2e] = 0;
  param_1[0x2f] = uVar8;
  if ((uVar7 == 0) || ((ulong)(param_2 - param_1[0x2d]) < uStack_58)) {
    if (uStack_60 <= (ulong)(param_2 - param_1[0x2c])) {
      uVar14 = (uint)(uVar8 < (ulong)param_1[0x25] >> 2);
      uVar12 = 1;
      goto LAB_fffffff0081ead6c;
    }
    uVar12 = 1;
LAB_fffffff0081eaeb0:
    uVar11 = 4;
  }
  else {
    uVar14 = *(uint *)(param_1[0x11] + 8);
    uVar3 = *(uint *)(param_1[0x11] + 4);
    if ((*(uint *)(param_1 + 0x27) <= uVar14) || (*(uint *)(param_1 + 0x27) <= uVar3)) {
      uVar12 = thunk_EXT_FUN_8011000003a49114
                         (
                         "AGXk: %s:%d:%s: !!! Assertion failed: %s: OOB access in GPU Driver Resource\n"
                         );
      return uVar12;
    }
    for (; uVar14 != uVar3; uVar14 = (uVar14 + 1) - uVar5 * uVar6) {
      lVar9 = (ulong)uVar14 * 8;
      puVar1 = (undefined8 *)(param_1[0x32] + (long)(int)lVar9);
      if (lVar9 != (int)lVar9) {
        puVar1 = (undefined8 *)(param_1[0x32] + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
      }
      (**(code **)(*(long *)*puVar1 + 0x78))((long *)*puVar1,4);
      uVar6 = *(uint *)(param_1 + 0x27);
      uVar5 = 0;
      if (uVar6 != 0) {
        uVar5 = (uVar14 + 1) / uVar6;
      }
    }
    uVar12 = 0;
    *(undefined1 *)(param_1 + 0x33) = 1;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)((long)param_1 + 0x154) = 0;
    param_1[0x2b] = 0;
    uVar14 = (int)((ulong)param_1[0x25] >> 0x11) - *(int *)((long)param_1 + 0x13c);
LAB_fffffff0081ead6c:
    uVar7 = uVar7 ^ 1;
    if (uVar14 == 0) {
      uVar7 = 1;
    }
    if ((uVar7 & 1) == 0) {
      (**(code **)(*param_1 + 0x120))(param_1);
    }
    else if (uVar14 == 0) goto LAB_fffffff0081eaeb0;
    do {
      uVar8 = param_1[0x25];
      uVar7 = *(uint *)((long)param_1 + 0x13c);
      if (*(uint *)((long)param_1 + 0x13c) <= *(uint *)(param_1 + 0x28)) {
        uVar7 = *(uint *)(param_1 + 0x28);
      }
      if ((uVar8 <= (ulong)uVar7 * 0x20000) ||
         (lVar9 = param_1[0x11], *(int *)(lVar9 + 8) == *(int *)(lVar9 + 4))) break;
      lVar13 = param_1[0x32];
      lVar10 = (ulong)*(uint *)(lVar9 + 8) * 8;
      puVar1 = (undefined8 *)(lVar13 + (int)lVar10);
      if (lVar10 - (int)lVar10 != 0) {
        puVar1 = (undefined8 *)(lVar13 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar11 = *puVar1;
      lVar9 = (ulong)*(uint *)(lVar9 + 8) * 8;
      puVar1 = (undefined8 *)(lVar13 + (int)lVar9);
      if (lVar9 - (int)lVar9 != 0) {
        puVar1 = (undefined8 *)(lVar13 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = 0;
      param_1[0x25] = uVar8 - 0x20000;
      *(undefined1 *)(param_1 + 5) = 1;
      (**(code **)(*param_1 + 0xe0))(param_1,uVar11);
      (**(code **)(*param_1 + 0xf8))(param_1,uVar11);
      uVar7 = *(int *)(param_1[0x11] + 8) + 1;
      uVar3 = *(uint *)(param_1 + 0x27);
      uVar6 = 0;
      if (uVar3 != 0) {
        uVar6 = uVar7 / uVar3;
      }
      *(uint *)(param_1[0x11] + 8) = uVar7 - uVar6 * uVar3;
      uVar14 = uVar14 - 1;
    } while (uVar14 != 0);
    FUN_fffffff00816b2a8(param_1[2]);
    if ((char)param_1[5] == '\x01') {
      *(undefined4 *)(param_1 + 0x26) = *(undefined4 *)(param_1[0x11] + 8);
      param_1[0x2c] = param_2;
    }
    uVar11 = 3;
  }
  lVar9 = param_1[2];
  if ((*(byte *)(lVar9 + 0x1ac44) >> 3 & 1) != 0) {
    lVar13 = param_1[0x25];
    iVar4 = *(int *)(param_1[3] + 0x60);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar9 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930da4,lVar13,uVar11,(long)iVar4,param_1,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar9 + 0x1ac48));
  }
LAB_fffffff0081eaf00:
  thunk_EXT_FUN_8011000003222de0(param_1[0x24]);
  return uVar12;
}

