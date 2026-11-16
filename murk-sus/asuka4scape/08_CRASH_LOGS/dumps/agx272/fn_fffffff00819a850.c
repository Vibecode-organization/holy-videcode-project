// FUN_fffffff00819a850 @ fffffff00819a850 size=120

undefined8 FUN_fffffff00819a850(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca0dc8,0x948);
  puVar2 = (undefined8 *)thunk_EXT_FUN_8011000002972368(uVar1,&DAT_fffffff00ae21f50);
  *puVar2 = &DAT_fffffff007c93bb8;
  *(undefined4 *)(puVar2 + 0xfe) = 4;
  puVar2[0x128] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae21f50);
  return uVar1;
}

