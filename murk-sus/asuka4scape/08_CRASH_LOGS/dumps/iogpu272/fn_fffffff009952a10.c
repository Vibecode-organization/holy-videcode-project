// FUN_fffffff009952a10 @ fffffff009952a10 size=160

long * FUN_fffffff009952a10(long *param_1)

{
  long lVar1;
  
  lVar1 = param_1[2];
  if (lVar1 != 0) {
    param_1[2] = 0;
    thunk_EXT_FUN_80110000038fe6b0(lVar1,(ulong)*(uint *)(param_1 + 4) << 2);
  }
  lVar1 = *param_1;
  if (lVar1 != 0) {
    *param_1 = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff13b8,lVar1,(ulong)*(uint *)(param_1 + 4) << 3);
  }
  lVar1 = param_1[1];
  if (lVar1 != 0) {
    param_1[1] = 0;
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1408,lVar1,(ulong)*(uint *)(param_1 + 4) << 4);
  }
  lVar1 = param_1[3];
  if (lVar1 != 0) {
    param_1[3] = 0;
    thunk_EXT_FUN_80110000038fe6b0(lVar1,(int)param_1[4] + 0x3fU >> 3 & 0x1ffffff8);
  }
  return param_1;
}

