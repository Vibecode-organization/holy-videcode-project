// FUN_fffffff0081f2d48 @ fffffff0081f2d48 size=116

undefined8 FUN_fffffff0081f2d48(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca22c8,0x98);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(uVar1,&DAT_fffffff00ae23608);
  puVar2[7] = 0;
  *(undefined4 *)(puVar2 + 8) = 0;
  *puVar2 = &DAT_fffffff007c9dd00;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae23608);
  return uVar1;
}

