// FUN_fffffff0081a0160 @ fffffff0081a0160 size=120

undefined8 FUN_fffffff0081a0160(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca0f48,0x21450);
  puVar2 = (undefined8 *)thunk_EXT_FUN_80110000029468f8(uVar1,&DAT_fffffff00ae222c8);
  *puVar2 = &DAT_fffffff007c94d48;
  *(undefined4 *)((long)puVar2 + 0x144c) = 0x100;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae222c8);
  return uVar1;
}

