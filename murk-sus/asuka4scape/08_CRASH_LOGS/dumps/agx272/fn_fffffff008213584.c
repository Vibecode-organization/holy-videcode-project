// FUN_fffffff008213584 @ fffffff008213584 size=112

void FUN_fffffff008213584(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x218);
  if (lVar2 != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar2 + 0x170));
    *(undefined8 *)(lVar2 + 0x168) = 0;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x170));
  }
  lVar2 = *(long *)(param_1 + 0x220);
  if (lVar2 != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar2 + 0x170));
    *(undefined8 *)(lVar2 + 0x168) = 0;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x170));
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0082135f0);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000029586e4(param_1);
  return;
}

