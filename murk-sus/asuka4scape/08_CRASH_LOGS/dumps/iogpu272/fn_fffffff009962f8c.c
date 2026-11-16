// FUN_fffffff009962f8c @ fffffff009962f8c size=400

ulong FUN_fffffff009962f8c(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x58));
  uVar2 = *(uint *)(param_1 + 0x50);
  uVar8 = (ulong)uVar2;
  if ((int)uVar2 < 1) {
    uVar11 = 0;
LAB_fffffff009962ff4:
    uVar8 = uVar11;
    if ((uint)uVar8 == uVar2) goto LAB_fffffff009962ffc;
    lVar6 = *(long *)(param_1 + 0x48);
  }
  else {
    uVar11 = 0;
    do {
      if (*(long *)(*(long *)(param_1 + 0x48) + uVar11 * 0x18) == 0) goto LAB_fffffff009962ff4;
      uVar11 = uVar11 + 1;
    } while (uVar8 != uVar11);
LAB_fffffff009962ffc:
    uVar3 = uVar2 << 1;
    lVar10 = ((-(ulong)((uVar2 & 0x7fffffff) >> 0x1e) & 0xfffffffe00000000 | (ulong)uVar3 << 1) +
             (long)(int)uVar3) * 8;
    auVar4._8_8_ = 0;
    auVar4._0_8_ = (long)(int)uVar3;
    lVar6 = -0x8000000000000000;
    if (SUB168(auVar4 * ZEXT816(0x18),8) == 0 && -1 < lVar10) {
      lVar6 = lVar10;
    }
    lVar6 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1638,lVar6);
    if (lVar6 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: sGPURestartRegisteredCommandQueue alloc fail\n");
      uVar8 = 0xffffffff;
      goto LAB_fffffff0099630f8;
    }
    thunk_EXT_FUN_8011000003a61b10
              (lVar6,*(undefined8 *)(param_1 + 0x48),(long)*(int *)(param_1 + 0x50) * 0x18);
    auVar5._8_8_ = 0;
    auVar5._0_8_ = (long)*(int *)(param_1 + 0x50);
    lVar9 = (long)*(int *)(param_1 + 0x50) * 0x18;
    lVar10 = -0x8000000000000000;
    if (SUB168(auVar5 * ZEXT816(0x18),8) == 0 && -1 < lVar9) {
      lVar10 = lVar9;
    }
    uVar7 = *(undefined8 *)(param_1 + 0x48);
    *(undefined8 *)(param_1 + 0x48) = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1688,uVar7,lVar10);
    *(long *)(param_1 + 0x48) = lVar6;
    *(uint *)(param_1 + 0x50) = uVar3;
  }
  lVar10 = (uVar8 & 0xffffffff) * 0x18;
  puVar1 = (undefined8 *)(lVar6 + (int)lVar10);
  if (lVar10 - (int)lVar10 != 0) {
    puVar1 = (undefined8 *)(lVar6 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *puVar1 = param_2;
LAB_fffffff0099630f8:
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x58));
  return uVar8;
}

