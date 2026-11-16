// FUN_fffffff0081fd54c @ fffffff0081fd54c size=328

void FUN_fffffff0081fd54c(long param_1,undefined8 param_2)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x10);
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar2 + 0x11a70));
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar2 + 0x11a78));
  if (*(int *)(*(long *)(param_1 + 0x10) + 0x11a68) != 0) {
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! AGXSecureGart::registerContextID\n");
    return;
  }
  if (*(int *)(param_1 + 0x1e8) != -1) {
    if ((DAT_fffffff00ae25928 & 1) == 0) {
      FUN_fffffff008210230(*(undefined8 *)(*(long *)(param_1 + 0x2d0) + 0x18));
    }
    else {
      thunk_EXT_FUN_80110000039ea210(*(undefined8 *)(*(long *)(param_1 + 0x2d0) + 0x10));
    }
    if (*(int *)(param_1 + 0x1e8) != -1) {
      (**(code **)(**(long **)(param_1 + 0x10) + 0xd80))();
    }
  }
  *(int *)(param_1 + 0x1e8) = (int)param_2;
  if ((int)param_2 != -1) {
    if ((DAT_fffffff00ae25928 & 1) == 0) {
      FUN_fffffff008210410(*(undefined8 *)(*(long *)(param_1 + 0x2d0) + 0x18),param_2);
    }
    else {
      thunk_EXT_FUN_80110000039ea0d0(*(undefined8 *)(*(long *)(param_1 + 0x2d0) + 0x10),param_2,0);
    }
  }
  lVar2 = *(long *)(param_1 + 0x10);
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar2 + 0x11a78));
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081fd668);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar2 + 0x11a70));
  return;
}

