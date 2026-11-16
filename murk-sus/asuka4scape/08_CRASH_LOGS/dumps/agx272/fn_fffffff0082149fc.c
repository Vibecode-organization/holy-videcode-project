// FUN_fffffff0082149fc @ fffffff0082149fc size=208

void FUN_fffffff0082149fc(long param_1,uint param_2)

{
  undefined4 *puVar1;
  long lVar2;
  code *pcVar3;
  ulong unaff_x30;
  
  (**(code **)(**(long **)(param_1 + 0x218) + 0x110))();
  if ((5 < param_2) || ((0x37U >> (ulong)(param_2 & 0x1f) & 1) == 0)) {
    thunk_EXT_FUN_8011000003a49114
              ("AGXk: %s:%d:%s: !!! Invalid priority %d used for work queue 0x%p\n");
    return;
  }
  lVar2 = (ulong)param_2 * 4;
  puVar1 = (undefined4 *)(&DAT_fffffff007115cc0 + (int)lVar2);
  if (lVar2 != (int)lVar2) {
    puVar1 = (undefined4 *)
             ((ulong)(&DAT_fffffff007115cc0 + lVar2) & 0xffffffffffff | 0x2bad000000000000);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008214a9c);
    (*pcVar3)();
  }
  thunk_EXT_FUN_8011000002958c50(param_1,*puVar1);
  return;
}

