// FUN_fffffff00996e930 @ fffffff00996e930 size=96

undefined8 FUN_fffffff00996e930(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_fffffff00994d73c(param_1,&DAT_fffffff00af22678);
  *puVar1 = &DAT_fffffff007fed928;
  puVar1[4] = 0;
  puVar1[5] = 0;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00af22678);
  return param_1;
}

