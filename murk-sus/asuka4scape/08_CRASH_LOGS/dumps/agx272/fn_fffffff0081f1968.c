// FUN_fffffff0081f1968 @ fffffff0081f1968 size=8

void FUN_fffffff0081f1968(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007ca2308);
  *(undefined1 *)(puVar1 + 2) = 0;
  *(undefined4 *)((long)puVar1 + 0x14) = 0;
  *puVar1 = &DAT_fffffff007c9e000;
  puVar1[1] = 0;
  return;
}

