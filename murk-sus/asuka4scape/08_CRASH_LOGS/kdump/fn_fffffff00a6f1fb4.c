// FUN_fffffff00a6f1fb4 @ fffffff00a6f1fb4 size=168
// CALLERS:
//   fffffff00afbc632 ?
//   fffffff007c221c0 ?
// CALLS:
//   fffffff00aa5cec8 FUN_fffffff00aa5cec8
//   fffffff00a6f1b38 FUN_fffffff00a6f1b38
//   fffffff00a29b24c FUN_fffffff00a29b24c

ulong FUN_fffffff00a6f1fb4
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,ulong param_7,
                uint *param_8,int *param_9)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long *plVar4;
  ulong uVar5;
  undefined1 extraout_q0 [16];
  
  uVar1 = *param_8;
  uVar2 = param_8[2];
  if ((uVar1 == uVar2) || (uVar3 = param_8[4], (uVar3 & 0xf6ffffff) != 0)) {
    return 0x16;
  }
  plVar4 = FUN_fffffff00a29b24c();
  if ((param_7 != 0) && (plVar4[3] != param_7)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa5cec8(extraout_q0,param_2,param_3,param_4,param_5,param_6);
  }
  uVar5 = FUN_fffffff00a6f1b38
                    (extraout_q0,param_2,param_3,param_4,param_5,param_6,param_7,plVar4[2],
                     (ulong)uVar1,(undefined ********)(ulong)uVar2,
                     (undefined ********)(ulong)(uVar3 >> 0x18 & 1 | uVar3 >> 0x1a),param_9);
  return uVar5;
}

