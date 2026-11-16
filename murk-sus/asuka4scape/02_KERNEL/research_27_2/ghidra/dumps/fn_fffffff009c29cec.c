// FUN_fffffff009c29cec @ fffffff009c29cec size=252
// CALLERS:
//   fffffff00afebe0a no-fn
//   fffffff007e61188 no-fn
//   fffffff00802a2b0 no-fn
//   fffffff008e0057c thunk_FUN_fffffff009c29cec@fffffff008e00570
//   fffffff009abda98 thunk_FUN_fffffff009c29cec@fffffff009abda8c
// CALLEES:
//   fffffff009c2993c FUN_fffffff009c2993c
//   fffffff009c48f3c FUN_fffffff009c48f3c
//   fffffff009c48f50 FUN_fffffff009c48f50
//   fffffff009c48f28 FUN_fffffff009c48f28
//   fffffff009c48f64 FUN_fffffff009c48f64

undefined1
FUN_fffffff009c29cec
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8,
          uint param_9)

{
  long lVar1;
  undefined1 *puVar2;
  uint uVar3;
  byte bVar4;
  undefined1 uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  undefined1 extraout_q0 [16];
  
  if (((ulong)param_8 < *(ulong *)(param_7 + 0x328)) &&
     (bVar4 = FUN_fffffff009c2993c(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8),
     param_9 < bVar4)) {
    uVar6 = *(ulong *)(param_7 + 0x318);
    uVar7 = uVar6 + (ulong)*(uint *)(param_7 + 800) * 0x18;
    if (((uVar6 ^ uVar7) & 0xffc0000000000000) != 0) {
      uVar7 = uVar7 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar7 < uVar6) || (uVar7 - uVar6 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f64(extraout_q0,param_2,param_3,param_4,param_5,param_6);
    }
    if ((ulong)param_8 * 0x18 - (long)(int)((ulong)param_8 * 0x18) != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f3c(extraout_q0,param_2,param_3,param_4,param_5,param_6);
    }
    if ((((ulong)(param_8 * 3) & 0x1fffffff) >> 0x1c != 0) ||
       (uVar3 = param_8 * 0x18, (uint)(uVar7 - uVar6) < uVar3 + 0x18)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f28(extraout_q0,param_2,param_3,param_4,param_5,param_6);
    }
    uVar8 = (ulong)CARRY8(uVar6,(ulong)uVar3);
    uVar7 = -uVar8;
    if ((uVar7 != uVar8) || ((long)uVar7 < 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f50(extraout_q0,param_2,param_3,param_4,param_5,param_6);
    }
    lVar1 = uVar6 + uVar3 + 0x10;
    puVar2 = (undefined1 *)(lVar1 + (int)param_9);
    if ((ulong)param_9 != (long)(int)param_9) {
      puVar2 = (undefined1 *)(lVar1 + (ulong)param_9 & 0xffffffffffff | 0x2bad000000000000);
    }
    uVar5 = *puVar2;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}

