// FUN_fffffff009c2e650 @ fffffff009c2e650 size=60

void FUN_fffffff009c2e650(long param_1,uint param_2,undefined4 param_3)

{
  long lVar1;
  long lVar2;
  undefined4 *puVar3;
  
  if (param_2 < 3) {
    lVar1 = *(long *)(param_1 + 0x10) + 0x30;
    lVar2 = (ulong)(param_2 * 0x60) + 0x30;
    puVar3 = (undefined4 *)(lVar1 + (int)lVar2);
    if (lVar2 != (int)lVar2) {
      puVar3 = (undefined4 *)(lVar1 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar3 = param_3;
  }
  return;
}

