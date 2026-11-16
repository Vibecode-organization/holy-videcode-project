// FUN_fffffff00819d7cc @ fffffff00819d7cc size=1096

/* WARNING: Removing unreachable block (ram,0xfffffff00819dac0) */
/* WARNING: Removing unreachable block (ram,0xfffffff00819da14) */
/* WARNING: Removing unreachable block (ram,0xfffffff00819d9d4) */

undefined4 FUN_fffffff00819d7cc(long param_1,byte *param_2,undefined1 *param_3)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  long *plVar9;
  long lVar10;
  ulong uVar11;
  
  uVar8 = 0xe00002bc;
  if (param_2 == (byte *)0x0) {
    return 0xe00002c2;
  }
  lVar10 = *(long *)(param_1 + 0x120);
  iVar4 = thunk_EXT_FUN_8011000002960e38(lVar10,"com.apple.private.agx.performance-spi");
  if ((iVar4 == 0) ||
     (lVar5 = thunk_EXT_FUN_801100000372056c(*(undefined4 *)(lVar10 + 0x60)), lVar5 == 0)) {
LAB_fffffff00819d83c:
    iVar4 = thunk_EXT_FUN_80110000039dae48
                      (*(undefined8 *)(lVar10 + 0x50),
                       "com.apple.developer.metal.performance-state-assertion");
    if (iVar4 == 0) {
      return 0xe00002c1;
    }
  }
  else {
    iVar4 = thunk_EXT_FUN_80110000036e83c0();
    thunk_EXT_FUN_8011000003720838(lVar5);
    if (iVar4 == 0) goto LAB_fffffff00819d83c;
  }
  if (1 < *param_2 - 1) {
    return 0xe00002c2;
  }
  if (*param_2 == 2) {
    if (param_3 != (undefined1 *)0x0) {
      lVar5 = *(long *)(lVar10 + 0x48);
      plVar9 = *(long **)(lVar5 + 0x4b0);
      uVar11 = *(ulong *)(lVar10 + 0x1d0);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x111c8));
      if (uVar11 < *(ulong *)(lVar5 + 0x111d8)) {
        uVar3 = 0;
      }
      else {
        uVar11 = (**(code **)(**(long **)(lVar5 + 0x4b0) + 0x6d8))(*(long **)(lVar5 + 0x4b0),0);
        if ((uVar11 & 1) == 0) {
          uVar6 = thunk_EXT_FUN_8011000003397c88();
          uVar3 = 0;
          *(undefined8 *)(lVar5 + 0x111d8) = uVar6;
        }
        else {
          uVar3 = 1;
        }
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x111c8));
      *param_3 = 2;
      uVar2 = (**(code **)(*plVar9 + 0x6c8))(plVar9);
      param_3[2] = uVar2;
      param_3[3] = uVar3;
      uVar6 = (**(code **)(*plVar9 + 0x6d0))(*plVar9 + 0x6d0,plVar9);
      uVar3 = (**(code **)(*plVar9 + 0x6b8))(*plVar9 + 0x6b8,plVar9,uVar6);
      param_3[4] = uVar3;
      return 0;
    }
    return 0xe00002bc;
  }
  uVar6 = *(undefined8 *)(lVar10 + 0x1c0);
  thunk_EXT_FUN_80110000032222a8(uVar6);
  bVar1 = param_2[1];
  if (bVar1 == 4) {
    if ((*(byte *)(lVar10 + 0x1c8) & 1) == 0) {
      uVar8 = 0xe0000001;
      goto LAB_fffffff00819db68;
    }
    lVar5 = *(long *)(lVar10 + 0x48);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x111c8));
    if (*(long *)(lVar5 + 0x111d0) != 0) {
      uVar8 = 0xe00002e2;
LAB_fffffff00819d8e4:
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x111c8));
      goto LAB_fffffff00819db68;
    }
    iVar4 = *(int *)(lVar5 + 0x111e0) + -1;
    *(int *)(lVar5 + 0x111e0) = iVar4;
    if (iVar4 == 0) {
      iVar4 = (**(code **)(**(long **)(lVar5 + 0x4b0) + 0x6c0))(*(long **)(lVar5 + 0x4b0),0,0);
      if (iVar4 != 0) {
        uVar8 = 0xe00002c9;
        goto LAB_fffffff00819d8e4;
      }
      *(undefined4 *)(lVar5 + 0x111e4) = 4;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x111c8));
    uVar3 = 0;
    uVar8 = 0;
  }
  else {
    if ((*(byte *)(lVar10 + 0x1c8) & 1) != 0) {
      uVar8 = 0xe00002c5;
      goto LAB_fffffff00819db68;
    }
    lVar5 = *(long *)(lVar10 + 0x48);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x111c8));
    if (*(long *)(lVar5 + 0x111d0) == 0) {
      if (*(uint *)(lVar5 + 0x111e4) == 4) {
        plVar9 = *(long **)(lVar5 + 0x4b0);
        uVar7 = (**(code **)(*plVar9 + 0x6b0))(plVar9,bVar1);
        iVar4 = (**(code **)(*plVar9 + 0x6c0))(*plVar9 + 0x6c0,plVar9,1,uVar7);
        if (iVar4 != -0x1ffffd3b) {
          if (iVar4 == 0) {
            *(uint *)(lVar5 + 0x111e4) = (uint)bVar1;
            *(undefined8 *)(lVar5 + 0x111d8) = 0;
            goto LAB_fffffff00819db40;
          }
          (**(code **)(**(long **)(lVar5 + 0x4b0) + 0x6c0))(*(long **)(lVar5 + 0x4b0),0,0);
          uVar8 = 0xe00002c9;
        }
      }
      else {
        if (*(uint *)(lVar5 + 0x111e4) == (uint)bVar1) {
          uVar11 = (**(code **)(**(long **)(lVar5 + 0x4b0) + 0x6d8))(*(long **)(lVar5 + 0x4b0),1);
          if ((uVar11 & 1) == 0) {
            uVar7 = thunk_EXT_FUN_8011000003397c88();
            *(undefined8 *)(lVar5 + 0x111d8) = uVar7;
          }
LAB_fffffff00819db40:
          *(int *)(lVar5 + 0x111e0) = *(int *)(lVar5 + 0x111e0) + 1;
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x111c8));
          uVar7 = thunk_EXT_FUN_8011000003397c88();
          uVar8 = 0;
          *(undefined8 *)(lVar10 + 0x1d0) = uVar7;
          uVar3 = 1;
          goto LAB_fffffff00819db64;
        }
        uVar8 = 0xe00002c5;
      }
    }
    else {
      uVar8 = 0xe00002e2;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x111c8));
    uVar3 = 0;
  }
LAB_fffffff00819db64:
  *(undefined1 *)(lVar10 + 0x1c8) = uVar3;
LAB_fffffff00819db68:
  thunk_EXT_FUN_8011000003222de0(uVar6);
  return uVar8;
}

