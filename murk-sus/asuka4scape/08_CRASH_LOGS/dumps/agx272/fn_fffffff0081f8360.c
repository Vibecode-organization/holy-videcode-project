// FUN_fffffff0081f8360 @ fffffff0081f8360 size=112

undefined8 FUN_fffffff0081f8360(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca2448,0x78);
  puVar2 = (undefined8 *)thunk_EXT_FUN_8011000003976500(uVar1,&DAT_fffffff00ae23868);
  *puVar2 = &DAT_fffffff007c9e530;
  puVar2[0xc] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae23868);
  return uVar1;
}

