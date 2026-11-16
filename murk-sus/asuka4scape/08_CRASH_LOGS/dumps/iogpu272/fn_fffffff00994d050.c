// FUN_fffffff00994d050 @ fffffff00994d050 size=116

undefined8 FUN_fffffff00994d050(long param_1,uint param_2)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 uVar3;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x840));
  if (param_2 < *(uint *)(param_1 + 0x28)) {
    lVar2 = (ulong)param_2 * 0x18;
    puVar1 = (undefined8 *)(param_1 + 0x848 + (long)(int)lVar2);
    if (lVar2 - (int)lVar2 != 0) {
      puVar1 = (undefined8 *)(param_1 + 0x848 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar3 = *puVar1;
  }
  else {
    uVar3 = 0;
  }
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x840));
  return uVar3;
}

