// FUN_fffffff0081e0f84 @ fffffff0081e0f84 size=116

undefined8 FUN_fffffff0081e0f84(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca1cc8,0x298);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(uVar1,&DAT_fffffff00ae23008);
  *puVar2 = &DAT_fffffff007c9c538;
  *(undefined2 *)(puVar2 + 9) = 0;
  *(undefined1 *)((long)puVar2 + 0x4a) = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae23008);
  return uVar1;
}

