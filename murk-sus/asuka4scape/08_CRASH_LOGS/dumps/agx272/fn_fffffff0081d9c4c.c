// FUN_fffffff0081d9c4c @ fffffff0081d9c4c size=140

undefined8 FUN_fffffff0081d9c4c(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca1a48,0x300);
  puVar2 = (undefined8 *)thunk_EXT_FUN_801100000296c56c(uVar1,&DAT_fffffff00ae229e0);
  *(undefined1 *)((long)puVar2 + 0x2a1) = 0;
  puVar2[0x56] = 0;
  puVar2[0x55] = 0;
  puVar2[0x58] = 0;
  puVar2[0x57] = 0;
  *(undefined1 *)(puVar2 + 0x59) = 0;
  *(undefined1 *)(puVar2 + 0x5e) = 0;
  *puVar2 = &DAT_fffffff007c98d28;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae229e0);
  return uVar1;
}

