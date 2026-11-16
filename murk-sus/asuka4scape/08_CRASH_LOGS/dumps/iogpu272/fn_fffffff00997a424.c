// FUN_fffffff00997a424 @ fffffff00997a424 size=180

void FUN_fffffff00997a424(long param_1,undefined8 param_2)

{
  code *pcVar1;
  long lVar2;
  ulong uVar3;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x430);
  uVar3 = (ulong)*(uint *)(lVar2 + 0x148);
  if (*(uint *)(lVar2 + 0x148) != 0) {
    lVar2 = 0;
    do {
      FUN_fffffff00996d9e0(param_2,*(undefined8 *)(*(long *)(param_1 + 0x430) + 8 + lVar2 * 8));
      lVar2 = lVar2 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
    lVar2 = *(long *)(param_1 + 0x430);
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar2 + 0x298));
  lVar2 = *(long *)(param_1 + 0x430);
  uVar3 = (ulong)*(uint *)(lVar2 + 0x290);
  if (*(uint *)(lVar2 + 0x290) != 0) {
    lVar2 = 0;
    do {
      FUN_fffffff00996d9e0(param_2,*(undefined8 *)(*(long *)(param_1 + 0x430) + 0x150 + lVar2 * 8));
      lVar2 = lVar2 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
    lVar2 = *(long *)(param_1 + 0x430);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997a4d4);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x298));
  return;
}

