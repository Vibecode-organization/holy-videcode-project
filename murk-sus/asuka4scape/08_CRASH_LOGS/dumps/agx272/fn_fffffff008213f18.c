// FUN_fffffff008213f18 @ fffffff008213f18 size=112

undefined8 FUN_fffffff008213f18(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca2a48,0x240);
  puVar2 = (undefined8 *)thunk_EXT_FUN_8011000002958380(uVar1,&DAT_fffffff00ae25b60);
  puVar2[0x3a] = 0;
  *puVar2 = &DAT_fffffff007ca0710;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae25b60);
  return uVar1;
}

