// FUN_fffffff009c2993c @ fffffff009c2993c size=188
// CALLERS:
//   fffffff00afebe02 no-fn
//   fffffff00802a2b8 no-fn
//   fffffff009c29d1c FUN_fffffff009c29cec@fffffff009c29cec
//   fffffff009abdaa8 thunk_FUN_fffffff009c2993c@fffffff009abda9c
//   fffffff009c29a28 no-fn
//   fffffff009c29b24 no-fn
//   fffffff009c29c20 no-fn
//   fffffff009c29e18 no-fn
// CALLEES:
//   fffffff009c48f3c FUN_fffffff009c48f3c
//   fffffff009c48f50 FUN_fffffff009c48f50
//   fffffff009c48f28 FUN_fffffff009c48f28
//   fffffff009c48f64 FUN_fffffff009c48f64

undefined1
FUN_fffffff009c2993c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8)

{
  uint uVar1;
  undefined1 uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  
  if (((ulong)param_8 < *(ulong *)(param_7 + 0x328)) &&
     (uVar3 = *(ulong *)(param_7 + 0x318), uVar3 != 0)) {
    uVar4 = uVar3 + (ulong)*(uint *)(param_7 + 800) * 0x18;
    if (((uVar3 ^ uVar4) & 0xffc0000000000000) != 0) {
      uVar4 = uVar4 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar4 < uVar3) || (uVar4 - uVar3 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f64(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    if ((ulong)param_8 * 0x18 - (long)(int)((ulong)param_8 * 0x18) != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f3c(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    if ((((ulong)(param_8 * 3) & 0x1fffffff) >> 0x1c != 0) ||
       (uVar1 = param_8 * 0x18, (uint)(uVar4 - uVar3) < uVar1 + 0x18)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f28(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    uVar5 = (ulong)CARRY8(uVar3,(ulong)uVar1);
    uVar4 = -uVar5;
    if ((uVar4 != uVar5) || ((long)uVar4 < 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f50(param_1,param_2,param_3,param_4,param_5,param_6);
    }
    uVar2 = *(undefined1 *)(uVar3 + uVar1);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

