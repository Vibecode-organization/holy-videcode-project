// FUN_fffffff00a40504c @ fffffff00a40504c size=88
// CALLERS:
//   fffffff00afba3bf ?
//   fffffff007c227d8 ?
// CALLS:
//   fffffff00a29b24c FUN_fffffff00a29b24c
//   fffffff00a404d04 FUN_fffffff00a404d04

ulong FUN_fffffff00a40504c
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
                undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined8 param_7,
                uint *param_8)

{
  uint uVar1;
  undefined4 **ppuVar2;
  ulong uVar3;
  undefined1 extraout_q0 [16];
  
  uVar1 = param_8[6];
  if ((uVar1 & 0xffffd7df) != 0) {
    return 0x16;
  }
  ppuVar2 = (undefined4 **)FUN_fffffff00a29b24c();
  uVar3 = FUN_fffffff00a404d04
                    (extraout_q0,param_2,param_3,param_4,param_5,param_6,ppuVar2,
                     *(long *)(param_8 + 2),param_8[4],(ulong)*param_8,(undefined *)(ulong)uVar1);
  return uVar3;
}

