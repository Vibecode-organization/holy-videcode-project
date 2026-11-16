// FUN_fffffff009c3f044 @ fffffff009c3f044 size=236
// CALLERS:
//   fffffff00afec112 no-fn
//   fffffff009c3f714 FUN_fffffff009c3f6c0@fffffff009c3f6c0
//   fffffff009c3f17c FUN_fffffff009c3f130@fffffff009c3f130
//   fffffff009c3f218 FUN_fffffff009c3f1d0@fffffff009c3f1d0
//   fffffff009c3f694 FUN_fffffff009c3f668@fffffff009c3f668
//   fffffff009c3b290 FUN_fffffff009c3b240@fffffff009c3b240
//   fffffff009c3b680 FUN_fffffff009c3b628@fffffff009c3b628
//   fffffff009c3b880 FUN_fffffff009c3b7b0@fffffff009c3b7b0
// CALLEES:
//   fffffff009c48f3c FUN_fffffff009c48f3c
//   fffffff009c492c0 FUN_fffffff009c492c0
//   fffffff009c48f64 FUN_fffffff009c48f64
//   fffffff009c48f50 FUN_fffffff009c48f50
//   fffffff009c48f28 FUN_fffffff009c48f28

/* WARNING: Removing unreachable block (ram,0xfffffff009c3f0ec) */

undefined8
FUN_fffffff009c3f044
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8,
          long *param_9)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  
  if ((param_8 != 0) && (param_8 < *(uint *)(param_7 + 0x110))) {
    uVar2 = *(ulong *)(param_7 + 0x108);
    uVar4 = uVar2 + (ulong)*(uint *)(param_7 + 0x110) * 8;
    if (((uVar2 ^ uVar4) & 0xffc0000000000000) != 0) {
      uVar4 = uVar4 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar4 < uVar2) || (uVar4 - uVar2 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f64(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    lVar5 = (ulong)param_8 * 8;
    if (lVar5 - (int)lVar5 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f3c(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    if ((((ulong)param_8 & 0x1fffffff) >> 0x1c != 0) ||
       (uVar1 = param_8 * 8, (uint)(uVar4 - uVar2) < uVar1 + 8)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f28(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    uVar3 = (ulong)CARRY8(uVar2,(ulong)uVar1);
    uVar4 = -uVar3;
    if ((uVar4 != uVar3) || ((long)uVar4 < 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f50(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    lVar5 = *(long *)(uVar2 + uVar1);
    if ((lVar5 != 0) && (lVar5 != 0)) {
      if (*(long *)(lVar5 + 0x10) == *(long *)(param_7 + 0x118)) {
        *param_9 = lVar5;
        return 1;
      }
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c492c0(param_1,param_2,param_3,param_4,param_5,param_6);
    }
  }
  return 0;
}

