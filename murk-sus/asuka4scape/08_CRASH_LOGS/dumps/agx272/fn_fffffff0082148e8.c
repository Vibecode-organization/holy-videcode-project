// FUN_fffffff0082148e8 @ fffffff0082148e8 size=276

void FUN_fffffff0082148e8(long param_1,ulong param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  long lVar2;
  code *pcVar3;
  long *plVar4;
  ulong unaff_x30;
  
  plVar4 = *(long **)(param_1 + 0x218);
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x110))(plVar4,param_2);
  }
  (**(code **)(**(long **)(param_1 + 0x220) + 0x110))(*(long **)(param_1 + 0x220),param_2,param_3);
  if ((5 < (uint)param_2) || ((0x37U >> (ulong)((uint)param_2 & 0x1f) & 1) == 0)) {
    thunk_EXT_FUN_8011000003a49114
              ("AGXk: %s:%d:%s: !!! Invalid priority %d used for work queue 0x%p\n");
    return;
  }
  lVar2 = (param_2 & 0xffffffff) * 4;
  puVar1 = (undefined4 *)(&DAT_fffffff007115cc0 + (int)lVar2);
  if (lVar2 != (int)lVar2) {
    puVar1 = (undefined4 *)
             ((ulong)(&DAT_fffffff007115cc0 + lVar2) & 0xffffffffffff | 0x2bad000000000000);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0082149cc);
    (*pcVar3)();
  }
  thunk_EXT_FUN_8011000002958c50(param_1,*puVar1);
  return;
}

