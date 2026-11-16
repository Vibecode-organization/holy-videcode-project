// FUN_fffffff008171f98 @ fffffff008171f98 size=372

void FUN_fffffff008171f98(long param_1)

{
  uint uVar1;
  ulong uVar2;
  undefined4 uVar3;
  uint uVar4;
  code *pcVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  ulong unaff_x30;
  
  (**(code **)(PTR_DAT_fffffff007ca6170 + 0x5d8))();
  uVar4 = *(uint *)(*(long *)(param_1 + 0x11f38) + 0x10930);
  lVar8 = (long)(int)uVar4;
  uVar1 = uVar4 + *(int *)(*(long *)(param_1 + 0x11f38) + 0x10934);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x11f30));
  if (uVar4 < uVar1) {
    do {
      uVar7 = lVar8 * 0x60 | 8;
      uVar2 = param_1 + 0x11f70 + (long)(int)uVar7;
      if (uVar7 != (long)(int)uVar7) {
        uVar2 = param_1 + 0x11f70 + uVar7 & 0xffffffffffff | 0x2bad000000000000;
      }
      thunk_EXT_FUN_8011000002947a48(*(undefined8 *)(*(long *)(param_1 + 0x11f38) + 0x148),uVar2);
      lVar8 = lVar8 + 1;
    } while ((uint)lVar8 < uVar1);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x11f30));
  if (*(long **)(param_1 + 0x4b0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x4b0) + 0x738))();
  }
  *(int *)(param_1 + 0x300) = *(int *)(param_1 + 0x300) + 1;
  uVar6 = thunk_EXT_FUN_8011000003397c88();
  *(undefined8 *)(param_1 + 0x2f8) = uVar6;
  if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) == 0) {
    return;
  }
  uVar3 = *(undefined4 *)(param_1 + 0x300);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
  thunk_EXT_FUN_80110000036da494(0x85930cc0,uVar6,uVar3,0,0,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008172108);
    (*pcVar5)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
  return;
}

