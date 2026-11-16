// FUN_fffffff0081e2dbc @ fffffff0081e2dbc size=128

undefined8 FUN_fffffff0081e2dbc(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca1e08,0x70);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(uVar1,&DAT_fffffff00ae23160);
  *puVar2 = &DAT_fffffff007c9cb08;
  puVar2[5] = 0;
  puVar2[7] = 0;
  puVar2[6] = 0;
  puVar2[10] = 0;
  puVar2[0xc] = 0;
  puVar2[0xb] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae23160);
  return uVar1;
}

