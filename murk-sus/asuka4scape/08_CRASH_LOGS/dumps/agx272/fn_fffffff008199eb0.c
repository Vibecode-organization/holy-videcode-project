// FUN_fffffff008199eb0 @ fffffff008199eb0 size=836

void FUN_fffffff008199eb0(long param_1,undefined8 param_2,long param_3,long param_4,long param_5)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong unaff_x30;
  
  uVar5 = *(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148);
  lVar7 = *(long *)(param_3 + 0x28);
  uVar8 = *(ulong *)(lVar7 + 0x20);
  if (uVar8 != 0) {
    uVar9 = 0;
    if (param_4 == 0) {
      do {
        lVar6 = *(long *)(*(long *)(lVar7 + 0x18) + uVar9 * 8);
        thunk_EXT_FUN_8011000002951168(lVar6,0,0);
        thunk_EXT_FUN_8011000002950f84(lVar6,*(undefined8 *)(param_1 + 0x808),1);
        lVar2 = *(long *)(param_5 + 0x20);
        if (lVar2 != 0) {
          lVar3 = 0;
          do {
            if (*(long *)(*(long *)(param_5 + 0x18) + lVar3 * 8) == lVar6)
            goto LAB_fffffff008199fb8;
            lVar3 = lVar3 + 1;
            lVar2 = lVar2 + -1;
          } while (lVar2 != 0);
        }
        thunk_EXT_FUN_801100000296bdb4(param_5,lVar6);
LAB_fffffff008199fb8:
        uVar9 = (ulong)((int)uVar9 + 1);
      } while (uVar9 < uVar8);
    }
    else {
      do {
        lVar6 = *(long *)(*(long *)(lVar7 + 0x18) + uVar9 * 8);
        thunk_EXT_FUN_8011000002951168(lVar6,0,0);
        thunk_EXT_FUN_8011000002950f84(lVar6,*(undefined8 *)(param_1 + 0x808),1);
        lVar2 = thunk_EXT_FUN_801100000295198c(lVar6);
        thunk_EXT_FUN_80110000029486ac(uVar5,param_4,lVar2 + 0x100);
        lVar2 = thunk_EXT_FUN_801100000295198c(lVar6);
        thunk_EXT_FUN_80110000029486ac(uVar5,param_4,lVar2 + 0x140);
        lVar2 = *(long *)(param_5 + 0x20);
        if (lVar2 != 0) {
          lVar3 = 0;
          do {
            if (*(long *)(*(long *)(param_5 + 0x18) + lVar3 * 8) == lVar6)
            goto LAB_fffffff008199f18;
            lVar3 = lVar3 + 1;
            lVar2 = lVar2 + -1;
          } while (lVar2 != 0);
        }
        thunk_EXT_FUN_801100000296bdb4(param_5,lVar6);
LAB_fffffff008199f18:
        uVar9 = (ulong)((int)uVar9 + 1);
      } while (uVar9 < uVar8);
    }
  }
  lVar7 = *(long *)(param_3 + 0x20);
  uVar8 = *(ulong *)(lVar7 + 0x20);
  if (uVar8 != 0) {
    if (param_4 == 0) {
      uVar9 = 0;
      do {
        lVar6 = *(long *)(*(long *)(lVar7 + 0x18) + uVar9 * 8);
        thunk_EXT_FUN_8011000002950f84(lVar6,*(undefined8 *)(param_1 + 0x808),0);
        lVar2 = *(long *)(param_5 + 0x20);
        if (lVar2 != 0) {
          lVar3 = 0;
          do {
            if (*(long *)(*(long *)(param_5 + 0x18) + lVar3 * 8) == lVar6)
            goto LAB_fffffff00819a0c4;
            lVar3 = lVar3 + 1;
            lVar2 = lVar2 + -1;
          } while (lVar2 != 0);
        }
        thunk_EXT_FUN_801100000296bdb4(param_5,lVar6);
LAB_fffffff00819a0c4:
        uVar9 = (ulong)((int)uVar9 + 1);
      } while (uVar9 < uVar8);
    }
    else {
      uVar9 = 0;
      do {
        lVar6 = *(long *)(*(long *)(lVar7 + 0x18) + uVar9 * 8);
        thunk_EXT_FUN_8011000002950f84(lVar6,*(undefined8 *)(param_1 + 0x808),0);
        lVar2 = thunk_EXT_FUN_801100000295198c(lVar6);
        thunk_EXT_FUN_80110000029486ac(uVar5,param_4,lVar2 + 0x100);
        lVar2 = *(long *)(param_5 + 0x20);
        if (lVar2 != 0) {
          lVar3 = 0;
          do {
            if (*(long *)(*(long *)(param_5 + 0x18) + lVar3 * 8) == lVar6)
            goto LAB_fffffff00819a044;
            lVar3 = lVar3 + 1;
            lVar2 = lVar2 + -1;
          } while (lVar2 != 0);
        }
        thunk_EXT_FUN_801100000296bdb4(param_5,lVar6);
LAB_fffffff00819a044:
        uVar9 = (ulong)((int)uVar9 + 1);
      } while (uVar9 < uVar8);
    }
  }
  lVar7 = *(long *)(*(long *)(param_1 + 0x818) + 0x230);
  thunk_EXT_FUN_8011000002950f84(*(undefined8 *)(lVar7 + 0x130),*(undefined8 *)(param_1 + 0x808),0);
  thunk_EXT_FUN_8011000002969a34(param_2,*(undefined8 *)(*(long *)(lVar7 + 0x130) + 0x20));
  lVar2 = *(long *)(param_1 + 0x828);
  plVar4 = *(long **)(param_1 + 0x808);
  thunk_EXT_FUN_8011000002950f84(*(undefined8 *)(lVar2 + 0x48),plVar4,0);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar2 + 0x120));
  lVar7 = (ulong)*(uint *)(lVar2 + 0x2c) * 0x40;
  uVar8 = *(long *)(lVar2 + 0xc0) + (long)(int)lVar7;
  if (lVar7 - (int)lVar7 != 0) {
    uVar8 = *(long *)(lVar2 + 0xc0) + lVar7 & 0xffffffffffffU | 0x2bad000000000000;
  }
  (**(code **)(*plVar4 + 0x98))(plVar4,uVar8);
  (**(code **)(*plVar4 + 0x98))(plVar4,lVar2 + 200);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x120));
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00819a1f0);
  (*pcVar1)();
}

