// FUN_fffffff0081889c8 @ fffffff0081889c8 size=140

undefined8 FUN_fffffff0081889c8(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca0d08,0x780);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000029690e4(uVar1,&DAT_fffffff00ae21e00);
  puVar2[0x3f] = 0;
  *(undefined1 *)(puVar2 + 0x47) = 0;
  *(undefined4 *)((long)puVar2 + 0x23c) = 0xffffffff;
  *puVar2 = &DAT_fffffff007c937a8;
  *(undefined4 *)((long)puVar2 + 0x5e4) = 0xffffffff;
  puVar2[0xdf] = 0;
  puVar2[0xde] = 0;
  puVar2[0xe1] = 0;
  puVar2[0xe0] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae21e00);
  return uVar1;
}

