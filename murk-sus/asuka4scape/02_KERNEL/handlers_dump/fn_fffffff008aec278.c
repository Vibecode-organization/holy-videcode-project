// FUN_fffffff008aec278 @ fffffff008aec278 size=80 depth=0
// CALLERS:
//   fffffff00afce0d6 ?
//   fffffff007dee6f8 ?
// CALLS:
//   fffffff008ac49d4 FUN_fffffff008ac49d4

undefined8 FUN_fffffff008aec278(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *(uint *)(param_3 + 0x38) >> 3;
  if (((ulong)uVar1 / 7) * 0x38 == (ulong)*(uint *)(param_3 + 0x38)) {
    uVar2 = FUN_fffffff008ac49d4
                      (*(long *)(param_1 + 0xd8),*(undefined8 *)(param_3 + 0x30),uVar1 / 7,param_1,
                       *(undefined8 *)(param_3 + 0x10));
    return uVar2;
  }
  return 0xe00002c2;
}

