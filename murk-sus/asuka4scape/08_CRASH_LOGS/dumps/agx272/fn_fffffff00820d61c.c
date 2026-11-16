// FUN_fffffff00820d61c @ fffffff00820d61c size=176

undefined8 FUN_fffffff00820d61c(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca27c8,0x1280);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000029690e4(uVar1,&DAT_fffffff00ae256a0);
  puVar2[0x3f] = 0;
  *(undefined1 *)(puVar2 + 0x47) = 0;
  *(undefined4 *)((long)puVar2 + 0x23c) = 0xffffffff;
  puVar2[0x11f] = 0xffffffffffffffff;
  puVar2[0x141] = 0;
  puVar2[0x143] = 0;
  puVar2[0x142] = 0;
  puVar2[0x144] = 0;
  *(undefined1 *)((long)puVar2 + 0xac9) = 0;
  *puVar2 = &DAT_fffffff007c9f788;
  puVar2[0x17e] = 0;
  puVar2[0x192] = 0;
  *(undefined1 *)((long)puVar2 + 0xcac) = 0;
  *(undefined4 *)(puVar2 + 0x20c) = 0xffffffff;
  puVar2[0x22f] = 0;
  puVar2[0x22e] = 0;
  puVar2[0x231] = 0;
  puVar2[0x230] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae256a0);
  return uVar1;
}

