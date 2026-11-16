// FUN_fffffff009951160 @ fffffff009951160 size=124

void FUN_fffffff009951160(long param_1,long param_2,undefined4 param_3)

{
  code *pcVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  lVar3 = *(long *)(param_2 + 0x460);
  do {
    if (lVar3 == 0) {
LAB_fffffff0099511b8:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099511d8);
        (*pcVar1)();
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
      return;
    }
    uVar2 = FUN_fffffff00994b9f8(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148),lVar3 + 0x70);
    if ((uVar2 & 1) == 0) {
      *(undefined4 *)(lVar3 + 200) = param_3;
      goto LAB_fffffff0099511b8;
    }
    lVar3 = *(long *)(lVar3 + 0xb0);
  } while( true );
}

