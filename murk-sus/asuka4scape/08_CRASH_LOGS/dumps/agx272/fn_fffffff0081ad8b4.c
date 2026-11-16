// FUN_fffffff0081ad8b4 @ fffffff0081ad8b4 size=284

undefined8 * FUN_fffffff0081ad8b4(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  
  *param_1 = &DAT_fffffff007c950f0;
  uVar4 = param_1[0x10];
  if (uVar4 != 0) {
    if (param_1[0x11] != 0) {
      param_1[0x11] = 0;
    }
    lVar3 = -0x8000000000000000;
    if (-1 < (long)(uVar4 * 8) && (uVar4 & 0xe000000000000000) == 0) {
      lVar3 = uVar4 * 8;
    }
    uVar2 = param_1[0xf];
    param_1[0xf] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca36f8,uVar2,lVar3);
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    param_1[10] = 0;
    *(undefined4 *)(param_1 + 9) = 0;
  }
  lVar3 = param_1[0x13];
  if (lVar3 != 0) {
    param_1[0x13] = 0;
    thunk_EXT_FUN_80110000038fe768
              (&DAT_fffffff007ca3ce8,lVar3,*(uint *)((long)param_1 + 0xa4) >> 3 & 0x1fffffe0);
    param_1[0x12] = 0;
    param_1[0x13] = 0;
    *(undefined4 *)((long)param_1 + 0xa4) = 0;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  if (param_1[7] != 0) {
    thunk_EXT_FUN_80110000038ff020();
    param_1[7] = 0;
  }
  if (((param_1[0xf] == 0) && (param_1[0x10] == 0)) && (param_1[0x11] == 0)) {
    return param_1;
  }
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003a49114
                     ("AGXk: %s:%d:%s: !!! growable array is not empty at destruction\n");
  return puVar1;
}

