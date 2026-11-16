// FUN_fffffff008182b54 @ fffffff008182b54 size=424

void FUN_fffffff008182b54(long param_1)

{
  ulong uVar1;
  long lVar2;
  undefined8 *puVar3;
  ulong uVar4;
  code *pcVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  ulong unaff_x30;
  
  uVar8 = *(ulong *)(param_1 + 0x130);
  if (uVar8 != 0) {
    lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0xc80));
    uVar1 = *(long *)(lVar7 + 0x920) + 0x4c28;
    uVar4 = uVar8 - uVar1;
    uVar6 = uVar4 & 0x7fffffff8;
    if ((uVar1 <= uVar8 && uVar8 < *(long *)(lVar7 + 0x920) + 0x6c28U) && uVar6 != 0x7fffffff8) {
      uVar8 = uVar4 >> 9 & 0x3ffffff;
      *(ulong *)(lVar7 + 0xc00 + uVar8 * 8) =
           *(ulong *)(lVar7 + 0xc00 + uVar8 * 8) | 1L << (uVar4 >> 3 & 0x3f);
      *(ulong *)(lVar7 + 0xbf8) = *(ulong *)(lVar7 + 0xbf8) | 1L << (uVar4 >> 9 & 0x3f);
      lVar2 = *(long *)(lVar7 + 0x910) + 0x4c28;
      puVar3 = (undefined8 *)(lVar2 + (int)uVar6);
      if (uVar6 != (long)(int)uVar6) {
        puVar3 = (undefined8 *)(lVar2 + uVar6 & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar3 = 0;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0xc80));
    *(undefined8 *)(param_1 + 0x130) = 0;
  }
  uVar8 = *(ulong *)(param_1 + 0x138);
  if (uVar8 != 0) {
    lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0xc80));
    uVar1 = *(long *)(lVar7 + 0x920) + 0x4c28;
    uVar4 = uVar8 - uVar1;
    uVar6 = uVar4 & 0x7fffffff8;
    if ((uVar1 <= uVar8 && uVar8 < *(long *)(lVar7 + 0x920) + 0x6c28U) && uVar6 != 0x7fffffff8) {
      uVar8 = uVar4 >> 9 & 0x3ffffff;
      *(ulong *)(lVar7 + 0xc00 + uVar8 * 8) =
           *(ulong *)(lVar7 + 0xc00 + uVar8 * 8) | 1L << (uVar4 >> 3 & 0x3f);
      *(ulong *)(lVar7 + 0xbf8) = *(ulong *)(lVar7 + 0xbf8) | 1L << (uVar4 >> 9 & 0x3f);
      lVar2 = *(long *)(lVar7 + 0x910) + 0x4c28;
      puVar3 = (undefined8 *)(lVar2 + (int)uVar6);
      if (uVar6 != (long)(int)uVar6) {
        puVar3 = (undefined8 *)(lVar2 + uVar6 & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar3 = 0;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0xc80));
    *(undefined8 *)(param_1 + 0x138) = 0;
  }
  *(undefined8 *)(param_1 + 0x140) = 0;
  *(undefined8 *)(param_1 + 0x148) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008182cf0);
    (*pcVar5)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff008182cf8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6110 + 0x80))(param_1);
  return;
}

