// FUN_fffffff009c38818 @ fffffff009c38818 size=116

undefined8 FUN_fffffff009c38818(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)thunk_EXT_FUN_80110000039a385c(param_1,&DAT_fffffff00af483b8);
  *puVar1 = &DAT_fffffff008068520;
  puVar1[0x21] = 0;
  puVar1[0x20] = 0;
  *(undefined4 *)(puVar1 + 0x22) = 0;
  puVar1[0x23] = 0;
  puVar1[0x27] = 0;
  puVar1[0x26] = 0;
  puVar1[0x28] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00af483b8);
  return param_1;
}

