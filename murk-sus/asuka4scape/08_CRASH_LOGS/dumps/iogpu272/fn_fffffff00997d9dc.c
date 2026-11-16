// FUN_fffffff00997d9dc @ fffffff00997d9dc size=172

/* WARNING: Removing unreachable block (ram,0xfffffff00997dbac) */

void FUN_fffffff00997d9dc(long param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong extraout_x8;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  long *plVar10;
  long lVar11;
  undefined1 auVar12 [16];
  
  uVar4 = (ulong)*(uint *)(param_1 + 0x18);
  if (*(uint *)(param_1 + 0x18) != 0) {
    uVar5 = (ulong)*(uint *)(param_1 + 0x14);
    if (*(uint *)(param_1 + 0x14) != 0) {
      uVar6 = 0;
      lVar7 = 0;
      uVar8 = *(ulong *)(param_1 + 8);
      do {
        plVar10 = (long *)(uVar8 + lVar7 * 0x10);
        if (((uVar8 ^ (ulong)plVar10) & 0xffc0000000000000) != 0) {
          plVar10 = (long *)((ulong)plVar10 & 0xffffffffffff | 0xc8a2000000000000);
        }
        lVar9 = *plVar10;
        if (lVar9 != 0) {
          lVar11 = plVar10[1];
          plVar10 = (long *)(uVar8 + uVar6 * 0x10);
          if (((uVar8 ^ (ulong)plVar10) & 0xffc0000000000000) != 0) {
            plVar10 = (long *)((ulong)plVar10 & 0xffffffffffff | 0xc8a2000000000000);
          }
          *plVar10 = lVar9;
          plVar10[1] = lVar11;
          *(int *)(lVar9 + 0x20) = (int)uVar6;
          uVar6 = uVar6 + 1;
        }
        if (uVar4 <= uVar6) goto LAB_fffffff00997da64;
        lVar7 = lVar7 + 1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    param_1 = FUN_fffffff00998412c();
    uVar4 = extraout_x8;
  }
  uVar6 = 0;
LAB_fffffff00997da64:
  if (uVar6 == uVar4) {
    *(int *)(param_1 + 0x14) = (int)uVar4;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    return;
  }
  lVar7 = FUN_fffffff00998415c();
  uVar2 = *(int *)(lVar7 + 0x10) << 1;
  lVar9 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1c78,(ulong)uVar2 << 4);
  if (lVar9 == 0) {
    auVar12 = FUN_fffffff00998418c();
    lVar7 = auVar12._0_8_;
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x28));
    uVar4 = (ulong)*(uint *)(auVar12._8_8_ + 0x20);
    lVar9 = *(long *)(lVar7 + 8);
    lVar11 = uVar4 * 0x10;
    puVar1 = (undefined8 *)(lVar9 + (int)lVar11);
    if (lVar11 - (int)lVar11 != 0) {
      puVar1 = (undefined8 *)(lVar9 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar1 = 0;
    uVar4 = uVar4 << 4 | 8;
    puVar1 = (undefined8 *)(lVar9 + (int)uVar4);
    if (uVar4 != (long)(int)uVar4) {
      puVar1 = (undefined8 *)(lVar9 + uVar4 & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar1 = 0xffffffffffffffff;
    *(undefined1 *)(auVar12._8_8_ + 0x34) = 0;
    *(int *)(lVar7 + 0x18) = *(int *)(lVar7 + 0x18) + -1;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x28));
    return;
  }
  thunk_EXT_FUN_8011000003a61b10(lVar9,*(undefined8 *)(lVar7 + 8),(long)*(int *)(lVar7 + 0x10) << 4)
  ;
  lVar11 = (long)(int)*(uint *)(lVar7 + 0x10) << 4;
  if (0x7fffffff < *(uint *)(lVar7 + 0x10)) {
    lVar11 = -0x8000000000000000;
  }
  uVar3 = *(undefined8 *)(lVar7 + 8);
  *(undefined8 *)(lVar7 + 8) = 0;
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1cc8,uVar3,lVar11);
  *(uint *)(lVar7 + 0x10) = uVar2;
  *(long *)(lVar7 + 8) = lVar9;
  return;
}

