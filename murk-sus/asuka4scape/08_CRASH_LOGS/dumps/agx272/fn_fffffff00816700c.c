// FUN_fffffff00816700c @ fffffff00816700c size=152

undefined8 FUN_fffffff00816700c(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca0a88,0xb00);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000029690e4(uVar1,&DAT_fffffff00ae256c8);
  puVar2[0x3f] = 0;
  *(undefined1 *)(puVar2 + 0x47) = 0;
  *(undefined4 *)((long)puVar2 + 0x23c) = 0xffffffff;
  *puVar2 = &DAT_fffffff007c9f950;
  puVar2[0x11f] = 0xffffffffffffffff;
  puVar2[0x141] = 0;
  puVar2[0x143] = 0;
  puVar2[0x142] = 0;
  puVar2[0x144] = 0;
  *(undefined1 *)((long)puVar2 + 0xac9) = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae256c8);
  return uVar1;
}

