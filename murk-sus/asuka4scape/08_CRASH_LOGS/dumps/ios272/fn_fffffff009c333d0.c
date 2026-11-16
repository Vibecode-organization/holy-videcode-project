// FUN_fffffff009c333d0 @ fffffff009c333d0 size=244

void FUN_fffffff009c333d0(long *param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long *plVar3;
  long lVar4;
  ulong unaff_x30;
  
  plVar3 = (long *)(**(code **)(*param_1 + 0x398))();
  if (plVar3 == (long *)0x0) {
    return;
  }
  lVar4 = (**(code **)(*plVar3 + 0x88))();
  uVar1 = DAT_fffffff008068500;
  while (lVar4 != 0) {
    lVar4 = thunk_EXT_FUN_8011000003890f30(lVar4,uVar1);
    if (lVar4 != 0) {
      FUN_fffffff009c3fdb4();
    }
    lVar4 = (**(code **)(*plVar3 + 0x88))(plVar3);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c334a8);
    (*pcVar2)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c334b0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar3 + 0x28))(plVar3,(undefined8 *)(*plVar3 + 0x28));
  return;
}

