// FUN_fffffff008172298 @ fffffff008172298 size=180

void FUN_fffffff008172298(long param_1,char *param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  ulong unaff_x30;
  
  if (*param_2 == '\0') {
    *(undefined1 *)(param_1 + 0x115c1) = 0;
    if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
      uVar1 = 0x85930c10;
LAB_fffffff008172308:
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
      thunk_EXT_FUN_80110000036da494(uVar1,0,0,0,0,0);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008172348);
        (*pcVar2)();
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
      return;
    }
  }
  else if (*param_2 == '\x01') {
    *(undefined1 *)(param_1 + 0x115c1) = 1;
    if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
      uVar1 = 0x85930c0c;
      goto LAB_fffffff008172308;
    }
  }
  return;
}

