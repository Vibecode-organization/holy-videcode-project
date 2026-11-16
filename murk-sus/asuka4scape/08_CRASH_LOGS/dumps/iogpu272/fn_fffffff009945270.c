// FUN_fffffff009945270 @ fffffff009945270 size=60

undefined8 FUN_fffffff009945270(long param_1,ulong param_2)

{
  undefined8 *puVar1;
  long lVar2;
  
  if (((uint)param_2 != 0) && ((uint)param_2 < *(uint *)(param_1 + 0x28))) {
    lVar2 = (param_2 & 0xffffffff) * 8;
    puVar1 = (undefined8 *)(*(long *)(param_1 + 0x10) + (long)(int)lVar2);
    if (lVar2 != (int)lVar2) {
      puVar1 = (undefined8 *)
               (*(long *)(param_1 + 0x10) + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
    }
    return *puVar1;
  }
  FUN_fffffff0099447e4(param_2);
  return 0;
}

