// FUN_fffffff009970d24 @ fffffff009970d24 size=148

undefined8 FUN_fffffff009970d24(long param_1,ulong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 uVar3;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x18));
  lVar2 = (param_2 & 0xffffffff) * 8;
  puVar1 = (undefined8 *)(param_1 + 0x138 + (long)(int)lVar2);
  if (lVar2 != (int)lVar2) {
    puVar1 = (undefined8 *)(param_1 + 0x138 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar3 = (**(code **)(*(long *)*puVar1 + 0xb8))((long *)*puVar1,param_3,param_4);
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x18));
  return uVar3;
}

