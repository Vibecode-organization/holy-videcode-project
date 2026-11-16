// FUN_fffffff009c37f40 @ fffffff009c37f40 size=328

undefined8 FUN_fffffff009c37f40(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 1000));
  uVar7 = *(ulong *)(param_1 + 0x420);
  uVar4 = *(ulong *)(param_1 + 0x3f0);
  if (uVar4 == uVar7) {
    uVar4 = uVar7 + 0x20;
    uVar5 = *(undefined8 *)(param_1 + 0x428);
    lVar3 = -0x8000000000000000;
    if (-1 < (long)(uVar4 * 0x10) && (uVar4 & 0xf000000000000000) == 0) {
      lVar3 = uVar4 * 0x10;
    }
    lVar3 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff00806c2e0,lVar3);
    if (lVar3 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,"Unable to grow task client map\n");
      uVar5 = 0;
      goto LAB_fffffff009c3803c;
    }
    *(long *)(param_1 + 0x428) = lVar3;
    *(ulong *)(param_1 + 0x420) = uVar4;
    lVar6 = uVar7 * 0x10;
    thunk_EXT_FUN_8011000003a61b10(lVar3,uVar5,lVar6);
    lVar3 = -0x8000000000000000;
    if (-1 < lVar6 && (uVar7 & 0xf000000000000000) == 0) {
      lVar3 = lVar6;
    }
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806c330,uVar5,lVar3);
    uVar4 = *(ulong *)(param_1 + 0x3f0);
  }
  lVar3 = *(long *)(param_1 + 0x428);
  lVar6 = uVar4 * 0x10;
  puVar1 = (undefined8 *)(lVar3 + (int)lVar6);
  if (lVar6 - (int)lVar6 != 0) {
    puVar1 = (undefined8 *)(lVar3 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar7 = (uVar4 & 0x7ffffffffffffff) << 4 | 8;
  puVar2 = (undefined8 *)(lVar3 + (int)uVar7);
  if (uVar7 != (long)(int)uVar7) {
    puVar2 = (undefined8 *)(lVar3 + uVar7 & 0xffffffffffff | 0x2bad000000000000);
  }
  *puVar1 = param_3;
  *puVar2 = param_2;
  *(ulong *)(param_1 + 0x3f0) = uVar4 + 1;
  uVar5 = 1;
LAB_fffffff009c3803c:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 1000));
  return uVar5;
}

