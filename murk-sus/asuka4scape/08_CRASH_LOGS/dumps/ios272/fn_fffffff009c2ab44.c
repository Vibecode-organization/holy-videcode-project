// FUN_fffffff009c2ab44 @ fffffff009c2ab44 size=620

void FUN_fffffff009c2ab44
               (long param_1,undefined8 param_2,undefined8 param_3,ulong param_4,uint param_5,
               uint param_6,ulong *param_7,ulong *param_8,ulong *param_9)

{
  uint uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  code *pcVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  uVar5 = (**(code **)(**(long **)(param_1 + 0x3c8) + 0x90))();
  uVar13 = (ulong)uVar5;
  *param_8 = uVar13;
  uVar11 = 0;
  if (uVar5 != 0) {
    uVar12 = 0;
    do {
      (**(code **)(**(long **)(param_1 + 0x3c8) + 0x118))(*(long **)(param_1 + 0x3c8),uVar12);
      uVar6 = FUN_fffffff009c48d20();
      uVar1 = (uint)((param_5 & 2) == 0);
      if ((uVar6 & 1) == 0) {
        uVar1 = param_5 ^ 1;
      }
      uVar11 = uVar11 + ((ulong)uVar1 & 1);
      uVar12 = uVar12 + 1;
    } while (uVar13 != uVar12);
  }
  *param_9 = uVar11;
  if (param_4 <= uVar11) {
    uVar11 = param_4;
  }
  *param_7 = uVar11;
  if (uVar11 == 0) {
    param_6 = param_6 & 1;
  }
  else {
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar11;
    lVar7 = -0x8000000000000000;
    if (SUB168(auVar2 * ZEXT816(0x18),8) == 0 && -1 < (long)(uVar11 * 0x18)) {
      lVar7 = uVar11 * 0x18;
    }
    lVar7 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff00806bf20,lVar7);
    if (uVar5 != 0) {
      uVar11 = 0;
      uVar12 = 0;
      do {
        uVar8 = (**(code **)(**(long **)(param_1 + 0x3c8) + 0x118))
                          (*(long **)(param_1 + 0x3c8),uVar12);
        uVar5 = FUN_fffffff009c48d20();
        if ((((param_5 | uVar5) & 1) == 0) || (((param_5 & 2) == 0 & uVar5) != 0)) {
          lVar9 = uVar11 * 0x18;
          uVar6 = lVar7 + (int)lVar9;
          if (lVar9 - (int)lVar9 != 0) {
            uVar6 = lVar7 + lVar9 & 0xffffffffffffU | 0x2bad000000000000;
          }
          FUN_fffffff009c48c58(uVar8,uVar6,param_2);
          uVar11 = uVar11 + 1;
          if (uVar11 == *param_7) break;
        }
        uVar12 = uVar12 + 1;
      } while (uVar13 != uVar12);
    }
    thunk_EXT_FUN_8011000003386690(lVar7,param_3,*param_7 * 0x18);
    auVar3._8_8_ = 0;
    auVar3._0_8_ = *param_7;
    lVar10 = *param_7 * 0x18;
    lVar9 = -0x8000000000000000;
    if (SUB168(auVar3 * ZEXT816(0x18),8) == 0 && -1 < lVar10) {
      lVar9 = lVar10;
    }
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806bf70,lVar7,lVar9);
  }
  if (param_6 != 0) {
    FUN_fffffff009c2adb0(param_1);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2ada0);
    (*pcVar4)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  return;
}

