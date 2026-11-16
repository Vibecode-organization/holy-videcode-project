// FUN_fffffff009c28a80 @ fffffff009c28a80 size=112
// CALLERS:
//   fffffff00afebddb ?
//   fffffff007e61070 ?
//   fffffff009c3d9ac FUN_fffffff009c3d978@fffffff009c3d978
//   fffffff008e0034c thunk_FUN_fffffff009c28a80@fffffff008e00340
// CALLS:

/* WARNING: Removing unreachable block (ram,0xfffffff009c28ac8) */

undefined8 FUN_fffffff009c28a80(long param_1,uint param_2,undefined4 param_3)

{
  long lVar1;
  undefined4 *puVar2;
  long lVar3;
  undefined8 uVar4;
  
  uVar4 = 0xe00002c2;
  if ((param_2 < 5) && (param_2 < *(uint *)(param_1 + 0x98))) {
    uVar4 = 0;
    lVar1 = *(long *)(param_1 + 0x178) + 0xb8;
    lVar3 = (ulong)param_2 * 4;
    puVar2 = (undefined4 *)(lVar1 + (int)lVar3);
    if (lVar3 != (int)lVar3) {
      puVar2 = (undefined4 *)(lVar1 + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar2 = param_3;
  }
  return uVar4;
}

