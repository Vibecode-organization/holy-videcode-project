// FUN_fffffff009c2fb58 @ fffffff009c2fb58 size=100

undefined8 FUN_fffffff009c2fb58(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_fffffff009c30504(param_1,&DAT_fffffff00af48300);
  *puVar1 = &DAT_fffffff008067970;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[8] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00af48300);
  return param_1;
}

