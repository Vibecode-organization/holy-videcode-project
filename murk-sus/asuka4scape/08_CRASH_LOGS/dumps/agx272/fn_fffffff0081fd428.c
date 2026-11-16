// FUN_fffffff0081fd428 @ fffffff0081fd428 size=288

void FUN_fffffff0081fd428(long param_1)

{
  code *pcVar1;
  long *plVar2;
  long lVar3;
  ulong unaff_x30;
  
  lVar3 = *(long *)(param_1 + 0x10);
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar3 + 0x11a70));
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar3 + 0x11a78));
  if ((DAT_fffffff00ae25928 & 1) == 0) {
    FUN_fffffff00820f890(*(undefined8 *)(*(long *)(param_1 + 0x2d0) + 0x18));
  }
  else {
    thunk_EXT_FUN_80110000039e91e4(*(undefined8 *)(*(long *)(param_1 + 0x2d0) + 0x10));
  }
  lVar3 = *(long *)(param_1 + 0x10);
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar3 + 0x11a78));
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar3 + 0x11a70));
  if (*(long **)(param_1 + 0x2d8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x2d8) + 0x130))();
    if (*(long **)(param_1 + 0x2e0) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x2e0) + 0x130))();
      plVar2 = *(long **)(param_1 + 0x2e8);
      if (plVar2 != (long *)0x0) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081fd53c);
          (*pcVar1)();
        }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081fd544. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*plVar2 + 0x130))(plVar2,(undefined8 *)(*plVar2 + 0x130));
        return;
      }
    }
  }
  return;
}

