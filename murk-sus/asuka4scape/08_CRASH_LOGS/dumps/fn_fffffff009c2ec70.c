// FUN_fffffff009c2ec70 @ fffffff009c2ec70 size=68
// CALLERS:
//   fffffff00afebefb no-fn
//   fffffff009c2a050 FUN_fffffff009c29ee4@fffffff009c29ee4
//   fffffff009c2a268 FUN_fffffff009c29ee4@fffffff009c29ee4
// CALLEES:

undefined4 FUN_fffffff009c2ec70(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  undefined4 *puVar3;
  
  if (param_2 < 3) {
    lVar1 = *(long *)(param_1 + 0x10) + 0x30;
    lVar2 = (ulong)(param_2 * 0x60) + 0x28;
    puVar3 = (undefined4 *)(lVar1 + (int)lVar2);
    if (lVar2 != (int)lVar2) {
      puVar3 = (undefined4 *)(lVar1 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
    }
    return *puVar3;
  }
  return 0;
}

