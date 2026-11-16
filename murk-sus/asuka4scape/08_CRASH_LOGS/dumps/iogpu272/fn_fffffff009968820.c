// FUN_fffffff009968820 @ fffffff009968820 size=152

long * FUN_fffffff009968820(long *param_1)

{
  long lVar1;
  
  lVar1 = param_1[2];
  if (lVar1 != 0) {
    param_1[2] = 0;
    thunk_EXT_FUN_80110000038fe6b0(lVar1,(ulong)*(uint *)(param_1 + 5) << 2);
  }
  lVar1 = *param_1;
  if (lVar1 != 0) {
    *param_1 = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1778,lVar1,(ulong)*(uint *)(param_1 + 5) << 3);
  }
  lVar1 = param_1[1];
  if (lVar1 != 0) {
    param_1[1] = 0;
    thunk_EXT_FUN_80110000038fe6b0(lVar1,(ulong)*(uint *)(param_1 + 5) << 2);
  }
  lVar1 = param_1[3];
  if (lVar1 != 0) {
    param_1[3] = 0;
    thunk_EXT_FUN_80110000038fe6b0(lVar1,(int)param_1[5] + 0x3fU >> 3 & 0x1ffffff8);
  }
  return param_1;
}

