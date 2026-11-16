// FUN_fffffff0082016d4 @ fffffff0082016d4 size=1260

undefined8
FUN_fffffff0082016d4
          (long param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6,undefined8 param_7,undefined1 param_8)

{
  undefined8 *puVar1;
  long *plVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  long *plVar10;
  long *plVar11;
  long *plVar12;
  undefined8 uVar13;
  long lVar14;
  undefined8 uVar15;
  ulong uVar16;
  undefined8 local_68;
  
  (**(code **)(PTR_DAT_fffffff007ca6160 + 0x90))();
  *(undefined8 *)(param_1 + 0x230) = 0;
  *(undefined8 *)(param_1 + 0x228) = 0;
  *(undefined8 *)(param_1 + 0x158) = 0;
  *(undefined8 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x170) = 5;
  *(undefined8 *)(param_1 + 0x178) = 0;
  thunk_EXT_FUN_8011000002946f14(param_1 + 0x180);
  *(undefined8 *)(param_1 + 0x1c8) = 0;
  *(undefined8 *)(param_1 + 0x1c0) = 0;
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  *(undefined8 *)(param_1 + 0x1e8) = *(undefined8 *)(param_3 + 0x548);
  *(undefined8 *)(param_1 + 0x1f0) = 0;
  lVar6 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x60),&DAT_fffffff00ae21f50);
  *(long *)(param_1 + 0x148) = *(long *)(*(long *)(lVar6 + 0x530) + 0x4b0) + 400;
  *(undefined8 *)(param_1 + 0x240) = param_5;
  *(undefined8 *)(param_1 + 0x248) = param_6;
  uVar4 = thunk_EXT_FUN_8011000002c1353c(param_5);
  *(undefined4 *)(param_1 + 600) = uVar4;
  *(undefined8 *)(param_1 + 0x260) = 0;
  *(undefined8 *)(param_1 + 0x250) = param_7;
  lVar6 = *(long *)(*(long *)(param_1 + 0x10) + 0x11d98);
  uVar7 = thunk_EXT_FUN_8011000002c13530(param_5);
  uVar7 = uVar7 & 0xffffffff;
  uVar16 = (ulong)*(uint *)(lVar6 + 0x48);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0x40));
  uVar8 = FUN_fffffff0081e36b0(lVar6,uVar7);
  if ((uVar8 & 1) == 0) {
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0x40));
    return 0;
  }
  uVar8 = 0;
  if (uVar16 != 0) {
    uVar8 = uVar7 / uVar16;
  }
  lVar9 = uVar8 * 0x18 + 0x10;
  puVar1 = (undefined8 *)(*(long *)(lVar6 + 0x28) + (long)(int)lVar9);
  if (lVar9 != (int)lVar9) {
    puVar1 = (undefined8 *)(*(long *)(lVar6 + 0x28) + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
  }
  lVar9 = (**(code **)(*(long *)*puVar1 + 0x98))();
  *(ulong *)(param_1 + 0x260) = lVar9 + (uVar7 - uVar8 * uVar16) * 8;
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0x40));
  *(undefined8 *)(param_1 + 0x268) = 0;
  *(undefined4 *)(param_1 + 0x270) = 0;
  iVar5 = thunk_EXT_FUN_8011000002c13590(param_5);
  if (iVar5 == 0) goto LAB_fffffff008201b18;
  local_68 = 0;
  if (*(long *)(param_2 + 0xf8) == 0) {
    return 0;
  }
  plVar10 = (long *)thunk_EXT_FUN_8011000002c32e94
                              (*(long *)(param_2 + 0xf8),param_5,*(undefined8 *)(param_1 + 0x248),
                               (long)&local_68 + 4,&local_68);
  lVar6 = *(long *)(param_1 + 0x10);
  if (plVar10 == (long *)0x0) {
    if ((*(byte *)(lVar6 + 0x1ac44) >> 3 & 1) != 0) {
      uVar4 = thunk_EXT_FUN_8011000002c13530(param_5);
      uVar15 = *(undefined8 *)(param_1 + 0x248);
      uVar13 = thunk_EXT_FUN_8011000002c13500(param_5);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930da0,uVar4,uVar15,uVar13,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0x1ac48));
    }
    goto LAB_fffffff008201b18;
  }
  lVar9 = *(long *)(lVar6 + 0x11d98);
  thunk_EXT_FUN_8011000002c13530(param_5);
  uVar3 = (uint)local_68;
  uVar7 = local_68 & 0xffffffff;
  uVar4 = local_68._4_4_;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar9 + 0x68));
  lVar6 = *(long *)(lVar9 + 0x60);
  if (lVar6 != 0) {
    lVar14 = 0;
    do {
      uVar8 = *(ulong *)(lVar9 + 0x50) + lVar14 * 0x20;
      if (((*(ulong *)(lVar9 + 0x50) ^ uVar8) & 0xffc0000000000000) != 0) {
        uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if (*(long **)(uVar8 + 8) == plVar10) {
        plVar12 = *(long **)(uVar8 + 0x10);
        goto LAB_fffffff008201a00;
      }
      lVar14 = lVar14 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  (**(code **)(*plVar10 + 0x20))(plVar10);
  plVar11 = (long *)thunk_EXT_FUN_801100000297d1cc(*(undefined8 *)(lVar9 + 0x18),0,plVar10);
  if (plVar11 == (long *)0x0) {
LAB_fffffff008201a80:
    (**(code **)(*plVar10 + 0x28))(plVar10);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar9 + 0x68));
    lVar6 = *(long *)(param_1 + 0x10);
    if ((*(byte *)(lVar6 + 0x1ac44) >> 3 & 1) != 0) {
      uVar4 = thunk_EXT_FUN_8011000002c13530(param_5);
      uVar15 = *(undefined8 *)(param_1 + 0x248);
      uVar13 = thunk_EXT_FUN_8011000002c13500(param_5);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar6 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930d9c,uVar4,uVar15,uVar13,0,0);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar6 + 0x1ac48));
    }
    *(undefined8 *)(param_1 + 0x268) = 0;
  }
  else {
    plVar12 = (long *)(**(code **)(*plVar11 + 0x90))
                                (plVar11,*(undefined8 *)(*(long *)(lVar9 + 0x18) + 0x11da0),
                                 0x800000005);
    if (plVar12 == (long *)0x0) {
LAB_fffffff008201a60:
      (**(code **)(*plVar11 + 0x28))(plVar11);
      goto LAB_fffffff008201a80;
    }
    iVar5 = thunk_EXT_FUN_801100000297b3fc();
    if (iVar5 != 0) {
LAB_fffffff008201a40:
      (**(code **)(*plVar12 + 0x28))(plVar12);
      goto LAB_fffffff008201a60;
    }
    uVar8 = *(ulong *)(lVar9 + 0x60);
    if (*(ulong *)(lVar9 + 0x58) <= uVar8) {
      thunk_EXT_FUN_801100000297b408(plVar12);
      goto LAB_fffffff008201a40;
    }
    lVar6 = uVar8 * 0x20;
    plVar2 = (long *)(*(long *)(lVar9 + 0x50) + (long)(int)lVar6);
    if (lVar6 - (int)lVar6 != 0) {
      plVar2 = (long *)(*(long *)(lVar9 + 0x50) + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *(ulong *)(lVar9 + 0x60) = uVar8 + 1;
    *plVar2 = (long)plVar11;
    plVar2[1] = (long)plVar10;
    plVar2[2] = (long)plVar12;
    *(undefined4 *)(plVar2 + 3) = uVar4;
    *(undefined4 *)((long)plVar2 + 0x1c) = 0;
LAB_fffffff008201a00:
    lVar6 = (**(code **)(*plVar12 + 0x98))();
    *(ulong *)(param_1 + 0x268) = lVar6 + uVar7 * 8;
    *(uint *)(param_1 + 0x270) = uVar3 & 3;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar9 + 0x68));
  }
  (**(code **)(*plVar10 + 0x28))(plVar10);
LAB_fffffff008201b18:
  *(undefined4 *)(param_1 + 0x278) = 0xff;
  *(undefined1 *)(param_1 + 0x44c) = param_8;
  *(undefined8 *)(param_1 + 0x27c) = 0;
  *(undefined8 *)(param_1 + 0x28c) = 0;
  *(undefined8 *)(param_1 + 0x284) = 0;
  *(undefined8 *)(param_1 + 0x29c) = 0;
  *(undefined8 *)(param_1 + 0x294) = 0;
  *(undefined8 *)(param_1 + 0x2ac) = 0;
  *(undefined8 *)(param_1 + 0x2a4) = 0;
  *(undefined8 *)(param_1 + 700) = 0;
  *(undefined8 *)(param_1 + 0x2b4) = 0;
  *(undefined8 *)(param_1 + 0x2cc) = 0;
  *(undefined8 *)(param_1 + 0x2c4) = 0;
  *(undefined8 *)(param_1 + 0x2dc) = 0;
  *(undefined8 *)(param_1 + 0x2d4) = 0;
  *(undefined8 *)(param_1 + 0x2ec) = 0;
  *(undefined8 *)(param_1 + 0x2e4) = 0;
  *(undefined8 *)(param_1 + 0x2fc) = 0;
  *(undefined8 *)(param_1 + 0x2f4) = 0;
  *(undefined8 *)(param_1 + 0x30c) = 0;
  *(undefined8 *)(param_1 + 0x304) = 0;
  *(undefined8 *)(param_1 + 0x31c) = 0;
  *(undefined8 *)(param_1 + 0x314) = 0;
  *(undefined8 *)(param_1 + 0x32c) = 0;
  *(undefined8 *)(param_1 + 0x324) = 0;
  *(undefined8 *)(param_1 + 0x334) = 0;
  *(undefined4 *)(param_1 + 0x1dc) = 0xffffffff;
  *(undefined8 *)(param_1 + 0x348) = 0;
  *(undefined8 *)(param_1 + 0x340) = 0;
  *(undefined8 *)(param_1 + 0x358) = 0;
  *(undefined8 *)(param_1 + 0x350) = 0;
  *(undefined8 *)(param_1 + 0x368) = 0;
  *(undefined8 *)(param_1 + 0x360) = 0;
  *(undefined8 *)(param_1 + 0x378) = 0;
  *(undefined8 *)(param_1 + 0x370) = 0;
  *(undefined8 *)(param_1 + 0x388) = 0;
  *(undefined8 *)(param_1 + 0x380) = 0;
  *(undefined8 *)(param_1 + 0x398) = 0;
  *(undefined8 *)(param_1 + 0x390) = 0;
  *(undefined8 *)(param_1 + 0x3a8) = 0;
  *(undefined8 *)(param_1 + 0x3a0) = 0;
  *(undefined8 *)(param_1 + 0x3b8) = 0;
  *(undefined8 *)(param_1 + 0x3b0) = 0;
  *(undefined8 *)(param_1 + 0x3c8) = 0;
  *(undefined8 *)(param_1 + 0x3c0) = 0;
  *(undefined8 *)(param_1 + 0x3d8) = 0;
  *(undefined8 *)(param_1 + 0x3d0) = 0;
  *(undefined8 *)(param_1 + 1000) = 0;
  *(undefined8 *)(param_1 + 0x3e0) = 0;
  *(undefined8 *)(param_1 + 0x3f8) = 0;
  *(undefined8 *)(param_1 + 0x3f0) = 0;
  *(undefined8 *)(param_1 + 0x408) = 0;
  *(undefined8 *)(param_1 + 0x400) = 0;
  *(undefined8 *)(param_1 + 0x418) = 0;
  *(undefined8 *)(param_1 + 0x410) = 0;
  *(undefined8 *)(param_1 + 0x428) = 0;
  *(undefined8 *)(param_1 + 0x420) = 0;
  *(undefined8 *)(param_1 + 0x438) = 0;
  *(undefined8 *)(param_1 + 0x430) = 0;
  *(undefined8 *)(param_1 + 0x440) = 0;
  *(undefined4 *)(param_1 + 0x23c) = 9;
  return 1;
}

