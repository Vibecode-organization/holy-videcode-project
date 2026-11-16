// FUN_fffffff009c2f380 @ fffffff009c2f380 size=112

undefined8 FUN_fffffff009c2f380(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff00806b170,0x30);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(uVar1,&DAT_fffffff00af482d8);
  *puVar2 = &DAT_fffffff008067848;
  puVar2[3] = 0;
  puVar2[4] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00af482d8);
  return uVar1;
}

