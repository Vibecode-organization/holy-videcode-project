// FUN_fffffff0081ea5e4 @ fffffff0081ea5e4 size=4

void FUN_fffffff0081ea5e4(long *param_1)

{
  undefined4 *puVar1;
  undefined4 uStack_24;
  
  thunk_EXT_FUN_80110000032222a8(param_1[0x24]);
  puVar1 = (undefined4 *)param_1[0xe];
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[8] = 1;
  *(undefined1 *)(param_1 + 5) = 1;
  *(undefined4 *)(param_1 + 0x26) = *(undefined4 *)(param_1[0x11] + 8);
  FUN_fffffff0081ea690(param_1[4]);
  if (*(int *)(param_1[4] + 0x30) != 0) {
    uStack_24 = *(undefined4 *)(param_1[0x11] + 4);
    (**(code **)(*param_1 + 0xf0))(param_1,&uStack_24);
  }
  thunk_EXT_FUN_8011000003222de0(param_1[0x24]);
  return;
}

