// FUN_fffffff0081d7ab8 @ fffffff0081d7ab8 size=116

undefined8 FUN_fffffff0081d7ab8(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca1b88,0x198);
  puVar2 = (undefined8 *)thunk_EXT_FUN_8011000002941404(uVar1,&DAT_fffffff00ae22b80);
  *(undefined8 *)((long)puVar2 + 0x104) = 0;
  *puVar2 = &DAT_fffffff007c99508;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae22b80);
  return uVar1;
}

