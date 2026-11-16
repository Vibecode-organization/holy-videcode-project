// FUN_fffffff00819dc68 @ fffffff00819dc68 size=1200

/* WARNING: Removing unreachable block (ram,0xfffffff00819de94) */
/* WARNING: Removing unreachable block (ram,0xfffffff00819e038) */
/* WARNING: Removing unreachable block (ram,0xfffffff00819dff8) */
/* WARNING: Removing unreachable block (ram,0xfffffff00819de48) */
/* WARNING: Removing unreachable block (ram,0xfffffff00819dd84) */
/* WARNING: Removing unreachable block (ram,0xfffffff00819dfb8) */

undefined8 FUN_fffffff00819dc68(long param_1,byte *param_2,undefined1 *param_3)

{
  long lVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  code *pcVar8;
  undefined8 uVar9;
  long *plVar10;
  long lVar11;
  
  uVar9 = 0xe00002bc;
  if (param_2 == (byte *)0x0) {
    return 0xe00002c2;
  }
  lVar11 = *(long *)(param_1 + 0x120);
  if ((*(byte *)(lVar11 + 0x1bc) & 1) == 0) {
    iVar4 = thunk_EXT_FUN_8011000002960e38(lVar11,"com.apple.private.agx.performance-spi");
    if (iVar4 == 0) {
      return 0xe00002c1;
    }
    lVar5 = thunk_EXT_FUN_801100000372056c(*(undefined4 *)(lVar11 + 0x60));
    if (lVar5 == 0) {
      return 0xe00002c1;
    }
    iVar4 = thunk_EXT_FUN_80110000036e83c0();
    thunk_EXT_FUN_8011000003720838(lVar5);
    if (iVar4 == 0) {
      return 0xe00002c1;
    }
    bVar2 = *param_2;
    if (3 < bVar2) {
      return 0xe00002bc;
    }
    if (bVar2 == 1) {
      return 0xe00002bc;
    }
  }
  else {
    bVar2 = *param_2;
  }
  lVar5 = *(long *)(lVar11 + 0x48);
  plVar10 = *(long **)(lVar5 + 0x4b0);
  if (bVar2 < 2) {
    if (bVar2 == 0) {
      bVar2 = param_2[1];
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x111c8));
      if ((*(int *)(lVar5 + 0x111e0) == 0) &&
         (*(long *)(lVar5 + 0x111d0) == 0 || *(long *)(lVar5 + 0x111d0) == lVar11)) {
        lVar1 = lVar11;
        if (bVar2 == 0) {
          lVar1 = 0;
        }
        *(long *)(lVar5 + 0x111d0) = lVar1;
        if (bVar2 == 0) {
          (**(code **)(**(long **)(lVar5 + 0x4b0) + 0x6c0))(*(long **)(lVar5 + 0x4b0),0,0);
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x111c8));
        uVar9 = 0;
        *(bool *)(lVar11 + 0x1bc) = bVar2 != 0;
      }
      else {
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x111c8));
        uVar9 = 0xe00002cc;
      }
    }
    else if (bVar2 == 1) {
      bVar2 = param_2[1];
      if (bVar2 - 1 < 3) {
        uVar6 = (**(code **)(*plVar10 + 0x6b0))(plVar10);
        iVar4 = (**(code **)(*plVar10 + 0x6c0))(*plVar10 + 0x6c0,plVar10,1,uVar6);
        if (iVar4 == -0x1ffffd3b || iVar4 == 0) {
          return 0;
        }
        pcVar8 = *(code **)(*plVar10 + 0x6c0);
      }
      else {
        if (bVar2 == 0) {
          (**(code **)(*plVar10 + 0x6c0))(plVar10,bVar2,0);
          return 0;
        }
        pcVar8 = *(code **)(*plVar10 + 0x6c0);
      }
      (*pcVar8)(plVar10,0,0);
    }
  }
  else if (bVar2 == 2) {
    if (param_3 != (undefined1 *)0x0) {
      *param_3 = 2;
      uVar3 = (**(code **)(*plVar10 + 0x6c8))(plVar10);
      param_3[2] = uVar3;
      uVar3 = (**(code **)(*plVar10 + 0x6d8))(*plVar10 + 0x6d8,plVar10,param_2[1] != 0);
      param_3[3] = uVar3;
      uVar9 = (**(code **)(*plVar10 + 0x6d0))(*plVar10 + 0x6d0,plVar10);
      uVar3 = (**(code **)(*plVar10 + 0x6b8))(*plVar10 + 0x6b8,plVar10,uVar9);
      uVar9 = 0;
      param_3[4] = uVar3;
    }
  }
  else if ((bVar2 == 3) && (param_3 != (undefined1 *)0x0)) {
    *param_3 = 3;
    uVar7 = (**(code **)(*plVar10 + 0x6b0))(plVar10,1);
    param_3[1] = (char)((uVar7 & 0xffffffff) / 100);
    uVar7 = (**(code **)(*plVar10 + 0x6b0))(*plVar10 + 0x6b0,plVar10,2);
    param_3[2] = (char)((uVar7 & 0xffffffff) / 100);
    uVar7 = (**(code **)(*plVar10 + 0x6b0))(*plVar10 + 0x6b0,plVar10,3);
    uVar9 = 0;
    param_3[3] = (char)((uVar7 & 0xffffffff) / 100);
  }
  return uVar9;
}

