// FUN_fffffff008212a68 @ fffffff008212a68 size=112

undefined8 FUN_fffffff008212a68(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca29c8,0x240);
  puVar2 = (undefined8 *)thunk_EXT_FUN_8011000002958380(uVar1,&DAT_fffffff00ae25b10);
  *puVar2 = &DAT_fffffff007ca0370;
  puVar2[0x3a] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae25b10);
  return uVar1;
}

