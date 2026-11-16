// FUN_fffffff0099546e8 @ fffffff0099546e8 size=260

undefined8 FUN_fffffff0099546e8(long *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (param_3 < param_2) {
    return 0;
  }
  *(uint *)(param_1 + 4) = param_2;
  lVar2 = thunk_EXT_FUN_80110000038fe5cc((ulong)param_2 << 2);
  param_1[2] = lVar2;
  lVar2 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1458,(ulong)*(uint *)(param_1 + 4) << 3);
  *param_1 = lVar2;
  lVar2 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff14a8,(ulong)*(uint *)(param_1 + 4) << 4);
  param_1[1] = lVar2;
  lVar2 = thunk_EXT_FUN_80110000038fe5cc((int)param_1[4] + 0x3fU >> 3 & 0x1ffffff8);
  param_1[3] = lVar2;
  if (((param_1[2] == 0) || (param_1[1] == 0)) || (lVar2 == 0)) {
    uVar3 = 0;
    *(undefined1 *)(param_1 + 8) = 0;
  }
  else {
    *(bool *)(param_1 + 8) = *param_1 != 0;
    if (*param_1 == 0) {
      uVar3 = 0;
    }
    else {
      *(uint *)((long)param_1 + 0x24) = param_2 - 1;
      *(uint *)(param_1 + 5) = (param_2 >> 6) - 1;
      uVar1 = (*(uint *)(param_1 + 4) & 0xaaaaaaaa) >> 1 |
              (*(uint *)(param_1 + 4) & 0x55555555) << 1;
      uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
      uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
      uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
      *(int *)((long)param_1 + 0x2c) = (int)LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10);
      *(uint *)((long)param_1 + 0x34) = param_3;
      uVar3 = 1;
    }
  }
  return uVar3;
}

