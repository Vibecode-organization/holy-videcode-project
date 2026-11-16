// FUN_fffffff0082138b0 @ fffffff0082138b0 size=112

undefined8 FUN_fffffff0082138b0(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca2a08,0x240);
  puVar2 = (undefined8 *)thunk_EXT_FUN_8011000002958380(uVar1,&DAT_fffffff00ae25b38);
  puVar2[0x3a] = 0;
  *puVar2 = &DAT_fffffff007ca0560;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae25b38);
  return uVar1;
}

