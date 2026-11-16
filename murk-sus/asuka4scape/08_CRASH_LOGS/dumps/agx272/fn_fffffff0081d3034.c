// FUN_fffffff0081d3034 @ fffffff0081d3034 size=132

void FUN_fffffff0081d3034(long param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  undefined8 *puVar7;
  ulong unaff_x30;
  undefined8 uStack_60;
  undefined8 uStack_58;
  
  FUN_fffffff0081d30b8();
  lVar3 = thunk_EXT_FUN_8011000002971b4c(*(undefined8 *)(param_1 + 0xe0));
  if ((DAT_fffffff00ae25928 & 1) == 0) {
    lVar3 = FUN_fffffff00821569c();
    lVar5 = thunk_EXT_FUN_801100000320503c();
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0xd8));
    plVar4 = (long *)(lVar3 + 0xe0);
    lVar6 = *plVar4;
    while (lVar6 == 0) {
      uStack_58 = 0;
      thunk_EXT_FUN_8011000003204ed8(0x14,1000000000,&uStack_58);
      iVar2 = thunk_EXT_FUN_80110000038ff078(*(undefined8 *)(lVar3 + 0xd8),plVar4,uStack_58,0);
      if (iVar2 == 1) {
        uStack_60 = 0;
        lVar6 = thunk_EXT_FUN_801100000320503c();
        thunk_EXT_FUN_8011000003398228(lVar6 - lVar5,&uStack_60);
      }
      lVar6 = *plVar4;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0xd8));
    lVar3 = thunk_EXT_FUN_801100000320503c();
    uStack_58 = 0;
    thunk_EXT_FUN_8011000003398228(lVar3 - lVar5,&uStack_58);
    return;
  }
  plVar4 = *(long **)(*(long *)(lVar3 + 0x2d0) + 0x10);
  puVar7 = (undefined8 *)(*plVar4 + 0xa0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081d30a8);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081d30b0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar7)(plVar4,param_2,puVar7);
  return;
}

