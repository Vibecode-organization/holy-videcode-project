// FUN_fffffff0081b6fc4 @ fffffff0081b6fc4 size=460

void FUN_fffffff0081b6fc4(long param_1,uint param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  code *pcVar5;
  int *piVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd78));
  if ((param_2 == 0xffffffff) ||
     (uVar2 = *(uint *)(param_1 + 0xd88), uVar7 = *(long *)(param_1 + 0xdc0) * (ulong)uVar2,
     uVar7 < param_2 || uVar7 - param_2 == 0)) {
    thunk_EXT_FUN_8011000003a49114
              (
              "AGXk: %s:%d:%s: !!! Assertion failed: %s: Attempt to release an out-of-range element (%d)\n"
              );
    return;
  }
  uVar4 = 0;
  if (uVar2 != 0) {
    uVar4 = param_2 / uVar2;
  }
  lVar3 = (ulong)uVar4 * 8;
  puVar1 = (undefined8 *)(*(long *)(param_1 + 0xdb8) + (long)(int)lVar3);
  if (lVar3 != (int)lVar3) {
    puVar1 = (undefined8 *)
             (*(long *)(param_1 + 0xdb8) + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
  }
  piVar6 = (int *)*puVar1;
  if (piVar6 != (int *)0x0) {
    if (*piVar6 == 0) {
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid ref count (%d %d)\n");
      return;
    }
    *piVar6 = *piVar6 + -1;
    lVar3 = *(long *)(param_1 + 0xdd8) + (ulong)(param_2 >> 8) * 0x20;
    uVar7 = (ulong)((param_2 & 0xff) >> 6);
    uVar9 = 1L << ((ulong)(param_2 & 0xff) & 0x3f);
    if ((*(ulong *)(lVar3 + uVar7 * 8) & uVar9) == 0) {
      uVar8 = (ulong)(param_2 >> 0xb) & 0x1ffff8;
      *(ulong *)(param_1 + 0xdd0 + uVar8) =
           *(ulong *)(param_1 + 0xdd0 + uVar8) | 1L << ((ulong)(param_2 >> 8) & 0x3f);
      *(ulong *)(lVar3 + uVar7 * 8) = *(ulong *)(lVar3 + uVar7 * 8) | uVar9;
      FUN_fffffff0081b399c(param_1 + 0xd40,(ulong)uVar4,1);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b70c0);
        (*pcVar5)();
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd78));
      return;
    }
    thunk_EXT_FUN_8011000003a49114
              ("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid element (%d)\n");
    return;
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Assertion failed: %s: Invalid allocation\n");
  return;
}

