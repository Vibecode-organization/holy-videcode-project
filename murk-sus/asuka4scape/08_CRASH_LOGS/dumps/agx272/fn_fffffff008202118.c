// FUN_fffffff008202118 @ fffffff008202118 size=124

undefined8 FUN_fffffff008202118(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca2648,0x480);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000029690e4(uVar1,&DAT_fffffff00ae23d00);
  puVar2[0x3f] = 0;
  *(undefined1 *)(puVar2 + 0x47) = 0;
  *(undefined4 *)((long)puVar2 + 0x23c) = 0xffffffff;
  *puVar2 = &DAT_fffffff007c9ef50;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae23d00);
  return uVar1;
}

