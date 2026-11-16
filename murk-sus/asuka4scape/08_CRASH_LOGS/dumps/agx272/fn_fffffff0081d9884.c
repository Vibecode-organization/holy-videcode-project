// FUN_fffffff0081d9884 @ fffffff0081d9884 size=116

undefined8 FUN_fffffff0081d9884(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca1a08,0x188);
  puVar2 = (undefined8 *)thunk_EXT_FUN_8011000002941404(uVar1,&DAT_fffffff00ae22948);
  *(undefined8 *)((long)puVar2 + 0x104) = 0;
  *puVar2 = &DAT_fffffff007c98b08;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae22948);
  return uVar1;
}

