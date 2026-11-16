// FUN_fffffff009270d64 @ fffffff009270d64 size=4 depth=0
// CALLERS:
//   fffffff00afdd21c ?
//   fffffff007efedc8 ?
// CALLS:

undefined8 FUN_fffffff009270d64(long *param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x628))
                    (param_1,**(undefined4 **)(param_3 + 0x20),*(undefined8 *)(param_3 + 0x30),
                     *(undefined4 *)(param_3 + 0x38));
  if ((int)uVar1 != 0) {
    thunk_FUN_fffffff00a9029a0((byte *)"AssertMacros: %s, %s file: %s, line: %d error: %#08x\n");
  }
  return uVar1;
}

