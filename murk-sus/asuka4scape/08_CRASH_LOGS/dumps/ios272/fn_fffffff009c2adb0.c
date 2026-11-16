// FUN_fffffff009c2adb0 @ fffffff009c2adb0 size=280

/* WARNING: Removing unreachable block (ram,0xfffffff009c2af08) */

void FUN_fffffff009c2adb0(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = (**(code **)(**(long **)(param_1 + 0x3c8) + 0x90))();
  uVar6 = 0;
  if (uVar1 != 0) {
    uVar7 = 0;
    uVar6 = uVar1;
    do {
      uVar2 = (**(code **)(**(long **)(param_1 + 0x3c8) + 0x118))(*(long **)(param_1 + 0x3c8),uVar7)
      ;
      FUN_fffffff009c48cfc();
      uVar3 = FUN_fffffff009c17500();
      uVar4 = FUN_fffffff009c48d14(uVar2);
      if (uVar3 < uVar4) {
        uVar7 = uVar7 + 1;
      }
      else {
        (**(code **)(**(long **)(param_1 + 0x3c8) + 0x108))(*(long **)(param_1 + 0x3c8),uVar7);
        uVar6 = uVar6 - 1;
      }
    } while (uVar7 < uVar6);
  }
  uVar1 = (**(code **)(**(long **)(param_1 + 0x3c8) + 0x90))();
  if (uVar1 != uVar6) {
    lVar5 = FUN_fffffff009c49198();
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x50));
    FUN_fffffff009c2adb0(lVar5);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x50));
    return;
  }
  return;
}

