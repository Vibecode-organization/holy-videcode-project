// FUN_fffffff009970194 @ fffffff009970194 size=68

undefined8 FUN_fffffff009970194(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar2 = *(ulong *)(param_1 + 0x20);
  if (uVar2 < *(ulong *)(param_1 + 0x28)) {
    *(ulong *)(param_1 + 0x20) = uVar2 + 1;
    lVar4 = uVar2 * 8;
    puVar1 = (undefined8 *)(*(long *)(param_1 + 0x18) + (long)(int)lVar4);
    if (lVar4 - (int)lVar4 != 0) {
      puVar1 = (undefined8 *)
               (*(long *)(param_1 + 0x18) + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar1 = param_2;
    return 1;
  }
  uVar3 = FUN_fffffff00996fc70();
  return uVar3;
}

