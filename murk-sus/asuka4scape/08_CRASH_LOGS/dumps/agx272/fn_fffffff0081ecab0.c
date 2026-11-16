// FUN_fffffff0081ecab0 @ fffffff0081ecab0 size=112

undefined8 FUN_fffffff0081ecab0(void)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca2108,0xa0);
  puVar2 = (undefined8 *)thunk_EXT_FUN_801100000294973c(uVar1,&DAT_fffffff00ae23390);
  *puVar2 = &DAT_fffffff007c9d3d0;
  *(undefined4 *)(puVar2 + 6) = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae23390);
  return uVar1;
}

