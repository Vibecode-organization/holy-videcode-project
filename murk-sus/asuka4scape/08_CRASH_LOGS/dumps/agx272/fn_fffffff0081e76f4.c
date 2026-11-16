// FUN_fffffff0081e76f4 @ fffffff0081e76f4 size=588

undefined8 FUN_fffffff0081e76f4(long *param_1)

{
  uint uVar1;
  uint uVar2;
  long *plVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  long lVar10;
  uint uVar11;
  ulong uVar12;
  
  puVar5 = PTR_DAT_fffffff007ca61a8;
  if (0x1000 < (uint)((int)param_1[9] + (int)param_1[9] * (int)param_1[0x14])) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"AGXk: out of fw resources");
    thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar5,1,"AGXk: out of fw resources");
    return 0;
  }
  lVar7 = (**(code **)*param_1)();
  if (lVar7 == 0) {
    return 0;
  }
  uVar11 = *(uint *)(param_1 + 0x14);
  uVar12 = (ulong)uVar11;
  uVar8 = param_1[0x10];
  if (uVar12 < uVar8) {
    uVar12 = 0;
    do {
      if (*(long *)(param_1[0xf] + uVar12 * 8) == 0) break;
      uVar12 = (ulong)((int)uVar12 + 1);
    } while (uVar12 < uVar8);
    uVar11 = (uint)uVar12;
    if (uVar8 == uVar12) goto LAB_fffffff0081e78d4;
  }
  else if (uVar8 == uVar12) {
    iVar6 = FUN_fffffff0081e71c4(param_1,uVar11 + 1);
    if (iVar6 == 0) goto LAB_fffffff0081e78d4;
    uVar8 = param_1[0x10];
  }
  if (uVar12 < uVar8) {
    lVar10 = uVar12 * 8;
    plVar3 = (long *)(param_1[0xf] + (long)(int)lVar10);
    if (lVar10 - (int)lVar10 != 0) {
      plVar3 = (long *)(param_1[0xf] + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *plVar3 = lVar7;
    *(int *)(param_1 + 0x14) = (int)param_1[0x14] + 1;
    uVar4 = *(uint *)(param_1 + 9);
    if (uVar4 != 0) {
      uVar9 = 0;
      lVar7 = param_1[0x13];
      do {
        uVar1 = uVar9 + uVar4 * uVar11;
        uVar8 = (ulong)(uVar1 >> 6);
        uVar12 = (ulong)(uVar1 >> 9) & 0x7ffff8;
        *(ulong *)((long)param_1 + uVar12 + 0x90) =
             1L << (uVar8 & 0x3f) | *(ulong *)((long)param_1 + uVar12 + 0x90);
        uVar2 = uVar4 - uVar9;
        if (0x3f < (uVar1 & 0x3f) + (uVar4 - uVar9)) {
          uVar2 = 0x40 - (uVar1 & 0x3f);
        }
        uVar12 = 0xffffffffffffffff;
        if (uVar2 < 0x40) {
          uVar12 = ~(-1L << ((ulong)uVar2 & 0x3f));
        }
        *(ulong *)(lVar7 + uVar8 * 8) =
             uVar12 << ((ulong)uVar1 & 0x3f) | *(ulong *)(lVar7 + uVar8 * 8);
        uVar9 = uVar2 + uVar9;
      } while (uVar9 < uVar4);
      return 1;
    }
    return 1;
  }
LAB_fffffff0081e78d4:
  (**(code **)(*param_1 + 8))(param_1,lVar7);
  puVar5 = PTR_DAT_fffffff007ca61a8;
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"AGXk: failed to grow fw resources");
  thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar5,1,"AGXk: failed to grow fw resources");
  return 0;
}

