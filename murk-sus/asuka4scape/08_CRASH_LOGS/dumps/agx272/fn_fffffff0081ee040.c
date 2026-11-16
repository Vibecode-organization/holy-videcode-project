// FUN_fffffff0081ee040 @ fffffff0081ee040 size=120

undefined8 FUN_fffffff0081ee040(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca2148,0x248);
  puVar2 = (undefined8 *)thunk_EXT_FUN_801100000294973c(uVar1,&DAT_fffffff00ae23430);
  puVar2[4] = 0;
  puVar2[0x13] = 0;
  *(undefined4 *)(puVar2 + 0x14) = 0;
  *puVar2 = &DAT_fffffff007c9d500;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae23430);
  return uVar1;
}

