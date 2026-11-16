// FUN_fffffff009270e08 @ fffffff009270e08 size=4 depth=0
// CALLERS:
//   fffffff00afdd21e ?
//   fffffff007efede0 ?
// CALLS:

undefined8 FUN_fffffff009270e08(long *param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  ulong uVar2;
  ulong uStack_28;
  
  uVar2 = **(ulong **)(param_3 + 0x20);
  if ((int)uVar2 == 0x19) {
    uVar1 = 0xe00002e2;
  }
  else if ((int)uVar2 == 0x1a) {
    uVar1 = 0xe00002e2;
  }
  else if ((uVar2 & 0xffffff00) == 0) {
    uStack_28 = (ulong)*(uint *)(param_3 + 0x60);
    uVar1 = (**(code **)(*param_1 + 0x570))
                      (param_1,uVar2,*(undefined8 *)(param_3 + 0x30),*(undefined4 *)(param_3 + 0x38)
                       ,*(undefined8 *)(param_3 + 0x58),&uStack_28);
    *(int *)(param_3 + 0x60) = (int)uStack_28;
    if ((int)uVar1 == 0) {
      return uVar1;
    }
  }
  else {
    uVar1 = 0xe00002e2;
  }
  thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
  return uVar1;
}

