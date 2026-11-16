// FUN_fffffff00819f3e8 @ fffffff00819f3e8 size=116

undefined8 FUN_fffffff00819f3e8(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca0f08,0x38);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(uVar1,&DAT_fffffff00ae22210);
  *puVar2 = &DAT_fffffff007c94c10;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae22210);
  return uVar1;
}

