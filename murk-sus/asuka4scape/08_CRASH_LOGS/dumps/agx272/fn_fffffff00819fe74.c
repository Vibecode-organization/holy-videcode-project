// FUN_fffffff00819fe74 @ fffffff00819fe74 size=72

void FUN_fffffff00819fe74(long param_1,uint param_2,uint *param_3,uint param_4)

{
  undefined4 *puVar1;
  ulong uVar2;
  
  *param_3 = param_4;
  param_3[1] = param_2;
  uVar2 = (ulong)(*(int *)(param_1 + 0x144c) - 1U & param_4 >> 8 & 0xff) << 2 |
          (long)(int)param_2 << 10;
  puVar1 = (undefined4 *)(param_1 + 0x1450 + (long)(int)uVar2);
  if (uVar2 != (long)(int)uVar2) {
    puVar1 = (undefined4 *)(param_1 + 0x1450 + uVar2 & 0xffffffffffff | 0x2bad000000000000);
  }
  *puVar1 = 0;
  return;
}

