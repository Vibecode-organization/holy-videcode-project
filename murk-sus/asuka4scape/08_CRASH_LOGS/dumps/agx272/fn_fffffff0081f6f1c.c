// FUN_fffffff0081f6f1c @ fffffff0081f6f1c size=124

undefined8 FUN_fffffff0081f6f1c(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca2388,0x440);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000029690e4(uVar1,&DAT_fffffff00ae23760);
  puVar2[0x3f] = 0;
  *(undefined1 *)(puVar2 + 0x47) = 0;
  *(undefined4 *)((long)puVar2 + 0x23c) = 0xffffffff;
  *puVar2 = &DAT_fffffff007c9e188;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae23760);
  return uVar1;
}

