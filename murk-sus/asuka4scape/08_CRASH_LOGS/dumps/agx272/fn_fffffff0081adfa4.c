// FUN_fffffff0081adfa4 @ fffffff0081adfa4 size=344

void FUN_fffffff0081adfa4(long *param_1)

{
  bool bVar1;
  undefined8 *puVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  uint uVar11;
  uint uVar12;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(param_1[7]);
  uVar4 = (**(code **)(*param_1 + 0x50))(param_1);
  uVar5 = uVar4 - *(uint *)(param_1 + 6);
  if ((*(uint *)(param_1 + 6) <= uVar4 && uVar5 != 0) && (uVar8 = param_1[0x10], uVar8 != 0)) {
    uVar4 = *(uint *)(param_1 + 9);
    uVar9 = uVar8;
    if ((uVar4 <= uVar5) && (uVar12 = (int)uVar8 - 1, uVar10 = (ulong)uVar12, -1 < (int)uVar12)) {
      uVar12 = 1;
      uVar11 = 0;
      if (uVar4 != 0) {
        uVar11 = uVar5 / uVar4;
      }
      do {
        if ((*(byte *)(param_1 + 5) & 1) == 0) {
          uVar5 = (uint)(*(int *)((long)param_1 + 0x2c) == 1);
        }
        else {
          uVar5 = 0;
        }
        lVar7 = uVar10 * 8;
        puVar2 = (undefined8 *)(param_1[0xf] + (long)(int)lVar7);
        if (lVar7 - (int)lVar7 != 0) {
          puVar2 = (undefined8 *)(param_1[0xf] + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
        }
        puVar6 = (uint *)*puVar2;
        if (puVar6 == (uint *)0x0) {
LAB_fffffff0081ae09c:
          uVar5 = (uint)uVar10;
          if (uVar12 == 0) {
            uVar5 = (uint)uVar8;
          }
          uVar9 = (ulong)uVar5;
        }
        else {
          if (*puVar6 == uVar5) {
            *puVar6 = 0;
            uVar5 = FUN_fffffff0081ae0fc(param_1,uVar10,0);
            uVar11 = uVar11 - 1;
            uVar12 = uVar12 & uVar5;
            goto LAB_fffffff0081ae09c;
          }
          uVar12 = 0;
          uVar9 = uVar8;
        }
      } while ((uVar11 != 0) &&
              (bVar1 = 0 < (long)uVar10, uVar8 = uVar9, uVar10 = uVar10 - 1, bVar1));
      uVar8 = param_1[0x10];
    }
    if ((uVar9 & 0xffffffff) <= uVar8 - 1) {
      FUN_fffffff0081ae3ac(param_1,uVar9);
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ae0f8);
    (*pcVar3)();
  }
  thunk_EXT_FUN_8011000003222de0(param_1[7]);
  return;
}

