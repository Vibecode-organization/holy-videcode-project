// FUN_fffffff00819eda4 @ fffffff00819eda4 size=112

undefined8 FUN_fffffff00819eda4(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca0ec8,0x138);
  puVar2 = (undefined8 *)thunk_EXT_FUN_8011000002942b9c(uVar1,&DAT_fffffff00ae221a0);
  *puVar2 = &DAT_fffffff007c94190;
  *(undefined1 *)(puVar2 + 0x26) = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae221a0);
  return uVar1;
}

