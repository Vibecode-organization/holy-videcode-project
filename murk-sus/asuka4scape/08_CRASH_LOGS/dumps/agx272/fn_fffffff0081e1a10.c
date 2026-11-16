// FUN_fffffff0081e1a10 @ fffffff0081e1a10 size=112

undefined8 FUN_fffffff0081e1a10(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca1d48,200);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(uVar1,&DAT_fffffff00ae230a0);
  *puVar2 = &DAT_fffffff007c9c7a0;
  *(undefined1 *)(puVar2 + 0xe) = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae230a0);
  return uVar1;
}

