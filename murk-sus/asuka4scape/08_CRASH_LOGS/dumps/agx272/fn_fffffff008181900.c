// FUN_fffffff008181900 @ fffffff008181900 size=112

undefined8 FUN_fffffff008181900(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca0b48,0x130);
  puVar2 = (undefined8 *)thunk_EXT_FUN_801100000297c218(uVar1,&DAT_fffffff00ae21bd0);
  *puVar2 = &DAT_fffffff007c930a0;
  *(undefined1 *)(puVar2 + 0x1d) = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae21bd0);
  return uVar1;
}

