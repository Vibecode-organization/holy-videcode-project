// FUN_fffffff00997da88 @ fffffff00997da88 size=144

/* WARNING: Removing unreachable block (ram,0xfffffff00997dbac) */

void FUN_fffffff00997da88(long param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  undefined1 auVar8 [16];
  
  uVar2 = *(int *)(param_1 + 0x10) << 1;
  lVar3 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1c78,(ulong)uVar2 << 4);
  if (lVar3 == 0) {
    auVar8 = FUN_fffffff00998418c();
    lVar3 = auVar8._0_8_;
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0x28));
    uVar5 = (ulong)*(uint *)(auVar8._8_8_ + 0x20);
    lVar6 = *(long *)(lVar3 + 8);
    lVar7 = uVar5 * 0x10;
    puVar1 = (undefined8 *)(lVar6 + (int)lVar7);
    if (lVar7 - (int)lVar7 != 0) {
      puVar1 = (undefined8 *)(lVar6 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar1 = 0;
    uVar5 = uVar5 << 4 | 8;
    puVar1 = (undefined8 *)(lVar6 + (int)uVar5);
    if (uVar5 != (long)(int)uVar5) {
      puVar1 = (undefined8 *)(lVar6 + uVar5 & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar1 = 0xffffffffffffffff;
    *(undefined1 *)(auVar8._8_8_ + 0x34) = 0;
    *(int *)(lVar3 + 0x18) = *(int *)(lVar3 + 0x18) + -1;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0x28));
    return;
  }
  thunk_EXT_FUN_8011000003a61b10
            (lVar3,*(undefined8 *)(param_1 + 8),(long)*(int *)(param_1 + 0x10) << 4);
  lVar6 = (long)(int)*(uint *)(param_1 + 0x10) << 4;
  if (0x7fffffff < *(uint *)(param_1 + 0x10)) {
    lVar6 = -0x8000000000000000;
  }
  uVar4 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = 0;
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1cc8,uVar4,lVar6);
  *(uint *)(param_1 + 0x10) = uVar2;
  *(long *)(param_1 + 8) = lVar3;
  return;
}

