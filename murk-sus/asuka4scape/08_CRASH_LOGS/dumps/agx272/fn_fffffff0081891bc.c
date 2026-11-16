// FUN_fffffff0081891bc @ fffffff0081891bc size=568

void FUN_fffffff0081891bc(long param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  long lVar3;
  code *pcVar4;
  ulong uVar5;
  uint uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  uint uVar10;
  uint uVar11;
  ulong unaff_x30;
  
  uVar10 = (*(int *)(param_1 + 0x28) + 1U) % 0x24;
  *(uint *)(param_1 + 0x28) = uVar10;
  lVar7 = (ulong)uVar10 * 0x40;
  uVar5 = param_1 + 0x4c0 + (long)(int)lVar7;
  if (lVar7 != (int)lVar7) {
    uVar5 = param_1 + 0x4c0 + lVar7 & 0xffffffffffffU | 0x2bad000000000000;
  }
  thunk_EXT_FUN_8011000002947870(*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x148),uVar5);
  lVar7 = (ulong)*(uint *)(param_1 + 0x28) * 8;
  puVar9 = (undefined8 *)(param_1 + 0x280 + (long)(int)lVar7);
  if (lVar7 - (int)lVar7 != 0) {
    puVar9 = (undefined8 *)(param_1 + 0x280 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
  }
  puVar9 = (undefined8 *)*puVar9;
  puVar9[0x18] = 0;
  puVar9[0x15] = 0;
  puVar9[0x14] = 0;
  puVar9[0x17] = 0;
  puVar9[0x16] = 0;
  puVar9[0x11] = 0;
  puVar9[0x10] = 0;
  puVar9[0x13] = 0;
  puVar9[0x12] = 0;
  puVar9[0xd] = 0;
  puVar9[0xc] = 0;
  puVar9[0xf] = 0;
  puVar9[0xe] = 0;
  puVar9[9] = 0;
  puVar9[8] = 0;
  puVar9[0xb] = 0;
  puVar9[10] = 0;
  puVar9[5] = 0;
  puVar9[4] = 0;
  puVar9[7] = 0;
  puVar9[6] = 0;
  puVar9[1] = 0;
  *puVar9 = 0;
  puVar9[3] = 0;
  puVar9[2] = 0;
  lVar7 = (ulong)*(uint *)(param_1 + 0x28) * 8;
  puVar2 = (undefined8 *)(param_1 + 0x38 + (long)(int)lVar7);
  if (lVar7 - (int)lVar7 != 0) {
    puVar2 = (undefined8 *)(param_1 + 0x38 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *(undefined4 *)*puVar2 = 0;
  lVar7 = *(long *)(param_1 + 0x10);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x198));
  uVar6 = *(uint *)(lVar7 + 0x184);
  uVar10 = *(uint *)(lVar7 + 0x180);
  if (uVar6 != 0) {
    uVar11 = 0;
    do {
      uVar1 = uVar10 & uVar6 - 1;
      if (uVar1 != *(uint *)(lVar7 + 0x188)) {
        lVar3 = (ulong)uVar1 * 0x40;
        uVar5 = *(long *)(lVar7 + 400) + (long)(int)lVar3;
        if (lVar3 != (int)lVar3) {
          uVar5 = *(long *)(lVar7 + 400) + lVar3 & 0xffffffffffffU | 0x2bad000000000000;
        }
        uVar5 = thunk_EXT_FUN_80110000029479f8
                          (*(undefined8 *)(*(long *)(lVar7 + 0x48) + 0x148),uVar5);
        uVar10 = *(uint *)(lVar7 + 0x180);
        if ((uVar5 & 1) != 0) break;
        uVar6 = *(uint *)(lVar7 + 0x184);
      }
      uVar10 = uVar10 + 1;
      *(uint *)(lVar7 + 0x180) = uVar10;
      uVar11 = uVar11 + 1;
    } while (uVar11 < uVar6);
  }
  *(uint *)(lVar7 + 0x180) = uVar10 + 1;
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x198));
  lVar7 = (ulong)*(uint *)(param_1 + 0x28) * 8;
  puVar2 = (undefined8 *)(param_1 + 0x158 + (long)(int)lVar7);
  if (lVar7 - (int)lVar7 != 0) {
    puVar2 = (undefined8 *)(param_1 + 0x158 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar8 = *puVar2;
  *puVar9 = uVar8;
  *(uint *)(puVar9 + 1) = uVar10;
  *(undefined4 *)((long)puVar9 + 0xc) = 0;
  lVar7 = *(long *)(param_1 + 0x18);
  uVar6 = *(uint *)(lVar7 + 0x11140);
  if (uVar6 == 0) {
    uVar6 = *(uint *)(lVar7 + 0x610);
  }
  uVar1 = *(uint *)(lVar7 + 0x11148);
  uVar11 = uVar6;
  if (uVar1 <= uVar6) {
    uVar11 = uVar1;
  }
  if (uVar1 != 0) {
    uVar6 = uVar11;
  }
  *(uint *)(puVar9 + 2) = uVar6;
  *(undefined4 *)((long)puVar9 + 0x14) = 0;
  puVar9[3] = 0;
  if ((*(byte *)(lVar7 + 0x1ac44) >> 3 & 1) == 0) {
    return;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x1ac48));
  thunk_EXT_FUN_80110000036da494(0x85930c8c,uVar10,uVar8,0,0,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081893f0);
    (*pcVar4)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x1ac48));
  return;
}

