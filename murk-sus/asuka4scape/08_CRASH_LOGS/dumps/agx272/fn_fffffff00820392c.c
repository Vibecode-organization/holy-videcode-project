// FUN_fffffff00820392c @ fffffff00820392c size=1168

undefined8 FUN_fffffff00820392c(undefined8 param_1,long param_2)

{
  ulong uVar1;
  uint *puVar2;
  undefined8 *puVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  ulong uVar11;
  
  lVar6 = thunk_EXT_FUN_8011000003397c88();
  FUN_fffffff0081b759c(*(undefined8 *)(*(long *)(param_2 + 0x10) + 0x4b0));
  uVar1 = lVar6 - 24000;
  lVar6 = uVar1 - *(ulong *)(param_2 + 0x538);
  if (*(ulong *)(param_2 + 0x538) <= uVar1 && lVar6 != 0) {
    lVar9 = *(long *)(param_2 + 0x10) + 0x18b78;
    lVar8 = (ulong)*(uint *)(param_2 + 0x530) * 4;
    puVar2 = (uint *)(lVar9 + (int)lVar8);
    if (lVar8 - (int)lVar8 != 0) {
      puVar2 = (uint *)(lVar9 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar9 = (ulong)*puVar2 * 8;
    puVar3 = (undefined8 *)(param_2 + 0x1200 + (long)(int)lVar9);
    if (lVar9 - (int)lVar9 != 0) {
      puVar3 = (undefined8 *)(param_2 + 0x1200 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b74c8(*(undefined8 *)(param_2 + 0x60),0x4750555048,*puVar3,lVar6,0,0);
    *(ulong *)(param_2 + 0x538) = uVar1;
  }
  lVar6 = uVar1 - *(ulong *)(param_2 + 0x548);
  if (*(ulong *)(param_2 + 0x548) <= uVar1 && lVar6 != 0) {
    lVar9 = *(long *)(param_2 + 0x540) * 8;
    puVar3 = (undefined8 *)(param_2 + 0x1280 + (long)(int)lVar9);
    if (lVar9 - (int)lVar9 != 0) {
      puVar3 = (undefined8 *)(param_2 + 0x1280 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_2 + 0x68),0x4146525354415445,*puVar3,lVar6,0,0);
    *(ulong *)(param_2 + 0x548) = uVar1;
  }
  if ((*(long *)(param_2 + 0x440) != 0) &&
     (lVar6 = uVar1 - *(ulong *)(param_2 + 0xfe8),
     *(ulong *)(param_2 + 0xfe8) <= uVar1 && lVar6 != 0)) {
    lVar9 = (ulong)*(uint *)(param_2 + 0xfe0) * 8;
    puVar3 = (undefined8 *)(param_2 + 0x1838 + (long)(int)lVar9);
    if (lVar9 - (int)lVar9 != 0) {
      puVar3 = (undefined8 *)(param_2 + 0x1838 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b74c8(*(long *)(param_2 + 0x440),0x4750555f53570000,*puVar3,lVar6,0,0);
    *(ulong *)(param_2 + 0xfe8) = uVar1;
  }
  lVar6 = uVar1 - *(ulong *)(param_2 + 0x558);
  if (*(ulong *)(param_2 + 0x558) <= uVar1 && lVar6 != 0) {
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_2 + 0x70),0x46454e444552,*(undefined8 *)(param_2 + 0x550),lVar6
               ,0,0);
    *(ulong *)(param_2 + 0x558) = uVar1;
  }
  lVar6 = uVar1 - *(ulong *)(param_2 + 0x570);
  if (*(ulong *)(param_2 + 0x570) <= uVar1 && lVar6 != 0) {
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_2 + 0x80),0x4750555f434c544d,*(undefined8 *)(param_2 + 0x568),
               lVar6,0,0);
    *(ulong *)(param_2 + 0x570) = uVar1;
  }
  lVar6 = uVar1 - *(ulong *)(param_2 + 0x580);
  if (*(ulong *)(param_2 + 0x580) <= uVar1 && lVar6 != 0) {
    if (*(int *)(param_2 + 0x5d8) != 0) {
      thunk_EXT_FUN_80110000039b5664(*(undefined8 *)(param_2 + 0x100),0x505a454e47414745,lVar6);
    }
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_2 + 0x108),0x505a5253444e4359,*(undefined8 *)(param_2 + 0x5c8),
               uVar1 - *(long *)(param_2 + 0x5d0),0,0);
    *(ulong *)(param_2 + 0x5d0) = uVar1;
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_2 + 0x110),0x5057524354524c,*(undefined8 *)(param_2 + 0x578),
               uVar1 - *(long *)(param_2 + 0x580),0,0);
    *(ulong *)(param_2 + 0x580) = uVar1;
  }
  lVar6 = uVar1 - *(ulong *)(param_2 + 0x590);
  if (*(ulong *)(param_2 + 0x590) <= uVar1 && lVar6 != 0) {
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_2 + 0x118),0x4146524354524c,*(undefined8 *)(param_2 + 0x588),
               lVar6,0,0);
    *(ulong *)(param_2 + 0x590) = uVar1;
  }
  lVar6 = uVar1 - *(ulong *)(param_2 + 0x5a0);
  if (*(ulong *)(param_2 + 0x5a0) <= uVar1 && lVar6 != 0) {
    uVar10 = *(undefined8 *)(param_2 + 0x598);
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_2 + 0x120),0x504d555f52430000,uVar10,lVar6,0,0);
    thunk_EXT_FUN_80110000039b74c8(*(undefined8 *)(param_2 + 0x120),0x504d555f52430000,uVar10,0,1,0)
    ;
    *(undefined8 *)(param_2 + 0x598) = uVar10;
    *(ulong *)(param_2 + 0x5a0) = uVar1;
  }
  if ((*(int *)(param_2 + 0x5b0) == 0) && (*(ulong *)(param_2 + 0x5b8) < uVar1)) {
    uVar4 = *(uint *)(param_2 + 0x5a8) % 100;
    uVar7 = *(ulong *)(param_2 + 0x5b8);
    if (uVar4 != 0) {
      uVar7 = *(ulong *)(param_2 + 0x5c0);
      uVar5 = (**(code **)(**(long **)(param_2 + 0x10) + 0xb80))();
      uVar11 = (ulong)((float)uVar7 + ((float)uVar4 / -100.0 + 1.0) * (float)uVar5 * 1000.0 * 24.0);
      uVar7 = *(ulong *)(param_2 + 0x5b8);
      if ((uVar7 <= uVar11 && uVar11 - uVar7 != 0) && uVar11 <= uVar1) {
        lVar6 = param_2 + 0x1200;
        lVar9 = (ulong)*(uint *)(param_2 + 0x5ac) * 8;
        puVar3 = (undefined8 *)(lVar6 + (int)lVar9);
        if (lVar9 - (int)lVar9 != 0) {
          puVar3 = (undefined8 *)(lVar6 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
        }
        thunk_EXT_FUN_80110000039b74c8
                  (*(undefined8 *)(param_2 + 0x128),0x4253544750555048,*puVar3,uVar11 - uVar7,0,0);
        lVar9 = (ulong)(*(int *)(param_2 + 0x5ac) + 1) * 8;
        puVar3 = (undefined8 *)(lVar6 + (int)lVar9);
        if (lVar9 != (int)lVar9) {
          puVar3 = (undefined8 *)(lVar6 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
        }
        thunk_EXT_FUN_80110000039b74c8
                  (*(undefined8 *)(param_2 + 0x128),0x4253544750555048,*puVar3,0,1,0);
        *(int *)(param_2 + 0x5ac) = *(int *)(param_2 + 0x5ac) + 1;
        *(ulong *)(param_2 + 0x5b8) = uVar11;
        uVar7 = uVar11;
      }
    }
    lVar6 = (ulong)*(uint *)(param_2 + 0x5ac) * 8;
    puVar3 = (undefined8 *)(param_2 + 0x1200 + (long)(int)lVar6);
    if (lVar6 - (int)lVar6 != 0) {
      puVar3 = (undefined8 *)(param_2 + 0x1200 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
    }
    thunk_EXT_FUN_80110000039b74c8
              (*(undefined8 *)(param_2 + 0x128),0x4253544750555048,*puVar3,uVar1 - uVar7,0,0);
    *(ulong *)(param_2 + 0x5b8) = uVar1;
  }
  return 0;
}

