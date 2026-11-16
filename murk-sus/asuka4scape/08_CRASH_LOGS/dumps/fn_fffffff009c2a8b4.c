// FUN_fffffff009c2a8b4 @ fffffff009c2a8b4 size=244
// CALLERS:
//   fffffff00afebe28 no-fn
//   fffffff007e61050 no-fn
//   fffffff009c40680 FUN_fffffff009c4060c@fffffff009c4060c
//   fffffff008e0030c thunk_FUN_fffffff009c2a8b4@fffffff008e00300
// CALLEES:
//   fffffff009c48f28 FUN_fffffff009c48f28
//   fffffff009c49c84 thunk_FUN_fffffff00aa65b10
//   fffffff009c495d4 thunk_FUN_fffffff00a226de0
//   fffffff009c48f50 FUN_fffffff009c48f50
//   fffffff009c495b4 thunk_FUN_fffffff00a2262a8
//   fffffff009c48f64 FUN_fffffff009c48f64

undefined8
FUN_fffffff009c2a8b4
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,ulong param_8,
          ulong param_9,ulong *param_10,undefined8 *param_11)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined1 auVar7 [16];
  
  uVar6 = 0xe00002c2;
  if ((param_8 < 6) && ((param_9 == 0 || (param_11 != (undefined8 *)0x0)))) {
    auVar7 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0x50));
    uVar4 = param_7 + 0x1b0;
    uVar5 = (param_7 + 0x210U) - uVar4;
    if ((param_7 + 0x210U < uVar4) || (uVar5 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f64(auVar7,param_2,param_3,param_4,param_5,param_6);
    }
    uVar3 = (int)param_8 * 0x10;
    if ((uint)uVar5 < uVar3 + 0x10) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f28(auVar7,param_2,param_3,param_4,param_5,param_6);
    }
    puVar1 = (undefined8 *)(uVar4 + uVar3);
    uVar5 = (ulong)CARRY8(uVar4,(ulong)uVar3);
    uVar4 = -uVar5;
    if ((uVar4 != uVar5) || ((long)uVar4 < 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f50(auVar7,param_2,param_3,param_4,param_5,param_6);
    }
    uVar6 = 0;
    puVar2 = (undefined8 *)*puVar1;
    uVar4 = puVar1[1];
    *param_10 = uVar4;
    if (((param_9 != 0) && (puVar2 != (undefined8 *)0x0)) && (uVar4 != 0)) {
      if (param_9 < uVar4) {
        uVar6 = 0xe00002e8;
      }
      else {
        thunk_FUN_fffffff00aa65b10(param_11,puVar2,uVar4);
        uVar6 = 0;
      }
    }
    thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x50));
  }
  return uVar6;
}

