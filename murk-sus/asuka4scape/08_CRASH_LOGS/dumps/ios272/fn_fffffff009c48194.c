// FUN_fffffff009c48194 @ fffffff009c48194 size=100

undefined8 FUN_fffffff009c48194(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_fffffff009c30504(param_1,&DAT_fffffff00af48520);
  *puVar1 = &DAT_fffffff00806aae0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[8] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00af48520);
  return param_1;
}

