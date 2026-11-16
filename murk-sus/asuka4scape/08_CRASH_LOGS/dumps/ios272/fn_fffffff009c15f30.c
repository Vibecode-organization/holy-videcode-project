// FUN_fffffff009c15f30 @ fffffff009c15f30 size=112

undefined8 FUN_fffffff009c15f30(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff00806adb0,0x90);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(uVar1,&DAT_fffffff00af48148);
  puVar2[6] = 0;
  puVar2[7] = 0;
  *puVar2 = &DAT_fffffff0080667c0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00af48148);
  return uVar1;
}

