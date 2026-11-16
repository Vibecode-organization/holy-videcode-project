// FUN_fffffff0081e5394 @ fffffff0081e5394 size=176

void FUN_fffffff0081e5394(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  thunk_EXT_FUN_8011000002947a48(*(undefined8 *)(*(long *)(param_1 + 0x28) + 0x148),param_1 + 0xe0);
  thunk_EXT_FUN_8011000002947a48(*(undefined8 *)(*(long *)(param_1 + 0x28) + 0x148),param_1 + 0x120)
  ;
  lVar2 = 0;
  lVar3 = 0x40;
  do {
    thunk_EXT_FUN_8011000002947a48
              (*(undefined8 *)(*(long *)(param_1 + 0x28) + 0x148),param_1 + 0x160 + lVar2 * 0x40);
    lVar2 = lVar2 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  thunk_EXT_FUN_8011000002947a48(*(undefined8 *)(*(long *)(param_1 + 0x28) + 0x148),param_1 + 0x60);
  thunk_EXT_FUN_8011000002947a48(*(undefined8 *)(*(long *)(param_1 + 0x28) + 0x148),param_1 + 0xa0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e5440);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  return;
}

