// FUN_fffffff00819c2a4 @ fffffff00819c2a4 size=4

void FUN_fffffff00819c2a4(long param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  long lVar5;
  long *plVar6;
  undefined8 uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 uStack_90;
  long lStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long lStack_70;
  ulong uStack_68;
  
  if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930d81,param_3,param_2,0,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
  }
  lStack_88 = 0;
  uStack_90 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  lStack_70 = thunk_EXT_FUN_8011000003397c88();
  if (param_2 != 0) {
    FUN_fffffff00819c014(param_2,&uStack_90);
  }
  lVar5 = thunk_EXT_FUN_8011000003397c88();
  uStack_68 = 0;
  thunk_EXT_FUN_8011000003398228(lVar5 - lStack_70,&uStack_68);
  uVar4 = *(uint *)(param_1 + 0x1ac44) & 8;
  if ((999999 < uStack_68) && (uVar4 != 0)) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930d82,param_3,param_2,0,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
    uVar3 = uStack_78;
    uVar2 = uStack_80;
    lVar5 = lStack_88;
    uVar7 = uStack_90;
    if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) == 0) goto LAB_fffffff00819c41c;
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930d8c,uVar7,lVar5,uVar2,uVar3,param_2);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
    uVar4 = *(uint *)(param_1 + 0x1ac44) & 8;
  }
  if (uVar4 != 0) {
    uVar7 = *(undefined8 *)(param_1 + 0x1c8);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930d99,&uStack_90,uVar7,1,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
  }
LAB_fffffff00819c41c:
  plVar6 = (long *)thunk_EXT_FUN_8011000002940a54(*(undefined8 *)(param_1 + 0x1c8));
  if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
    uVar7 = *(undefined8 *)(param_1 + 0x1c8);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930d9a,&uStack_90,uVar7,1,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
  }
  if (plVar6 != (long *)0x0) {
    uVar8 = *(ulong *)(param_1 + 0x1acb8);
    uVar4 = (**(code **)(*plVar6 + 0x90))(plVar6);
    if (uVar4 != 0) {
      uVar9 = (ulong)uVar4;
      uVar10 = uVar9;
      do {
        lVar5 = thunk_EXT_FUN_8011000003397c88();
        uStack_68 = 0;
        thunk_EXT_FUN_8011000003398228(lVar5 - lStack_70,&uStack_68);
        lVar5 = lStack_88;
        if (999999 < uStack_68) break;
        iVar1 = 0;
        if (uVar9 != 0) {
          iVar1 = (int)(uVar8 / uVar9);
        }
        uVar7 = (**(code **)(*plVar6 + 0x118))(plVar6,(int)uVar8 - iVar1 * uVar4);
        FUN_fffffff00819c014(uVar7,&uStack_90);
        if (lStack_88 == lVar5) {
          *(long *)(param_1 + 0x1acb8) = *(long *)(param_1 + 0x1acb8) + 1;
        }
        uVar8 = uVar8 + 1;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
  }
  if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930d82,param_3,param_2,0,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
    uVar3 = uStack_78;
    uVar2 = uStack_80;
    lVar5 = lStack_88;
    uVar7 = uStack_90;
    if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(0x85930d8c,uVar7,lVar5,uVar2,uVar3,param_2);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
    }
  }
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  return;
}

