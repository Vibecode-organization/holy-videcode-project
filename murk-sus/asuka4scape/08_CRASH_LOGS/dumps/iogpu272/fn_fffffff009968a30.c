// FUN_fffffff009968a30 @ fffffff009968a30 size=164

undefined8 FUN_fffffff009968a30(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_fffffff009942a3c(param_1,&DAT_fffffff00af22600);
  *puVar1 = &DAT_fffffff007fed448;
  puVar1[0x14] = 0;
  puVar1[0x11] = 0;
  puVar1[0x10] = 0;
  puVar1[0x13] = 0;
  puVar1[0x12] = 0;
  puVar1[0x16] = 0;
  puVar1[0x15] = 0;
  puVar1[0x17] = 0;
  puVar1[0x19] = 0;
  *(undefined4 *)(puVar1 + 0x18) = 0;
  *(undefined2 *)(puVar1 + 0x1a) = 0x100;
  puVar1[0x1e] = 0;
  puVar1[0x1d] = 0;
  puVar1[0x1f] = 0;
  puVar1[0x1c] = 0;
  puVar1[0x1b] = 0;
  puVar1[0x21] = 0;
  puVar1[0x20] = 0;
  puVar1[0x22] = 0;
  puVar1[0x24] = 0;
  *(undefined4 *)(puVar1 + 0x23) = 0;
  *(undefined2 *)(puVar1 + 0x25) = 0x100;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00af22600);
  return param_1;
}

