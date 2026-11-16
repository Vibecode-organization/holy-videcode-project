// FUN_fffffff0099601b0 @ fffffff0099601b0 size=236

void FUN_fffffff0099601b0(long param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  long lVar7;
  ulong unaff_x30;
  
  uVar3 = *(uint *)(*(long *)(param_1 + 0x1a8) + 0x238);
  if ((uVar3 >> 6 & 1) != 0) {
    FUN_fffffff009950f84(*(undefined8 *)(*(long *)(param_1 + 0x1a8) + 0x158));
    uVar3 = *(uint *)(*(long *)(param_1 + 0x1a8) + 0x238);
  }
  if (((uVar3 >> 7 & 1) != 0) &&
     (iVar2 = thunk_EXT_FUN_8011000003222c9c(*(undefined8 *)(param_1 + 0x160)), iVar2 != 0)) {
    uVar6 = *(undefined8 *)(param_1 + 0x1b0);
    lVar4 = *(long *)(param_1 + 0x168);
    do {
      if (lVar4 == 0) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009960298);
          (*pcVar1)();
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x160));
        return;
      }
      lVar7 = *(long *)(lVar4 + 0x30);
      iVar2 = FUN_fffffff00994b4ec(uVar6,lVar4 + 0x80);
      lVar4 = lVar7;
    } while (iVar2 == 0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x160));
  }
  puVar5 = (undefined8 *)(**(long **)(param_1 + 0x20) + 0xf8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996026c);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009960274. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar5)(*(long **)(param_1 + 0x20),0,0,0,puVar5);
  return;
}

