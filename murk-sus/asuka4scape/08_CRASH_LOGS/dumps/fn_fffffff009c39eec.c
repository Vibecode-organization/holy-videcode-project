// FUN_fffffff009c39eec @ fffffff009c39eec size=60
// CALLERS:
//   fffffff00afec091 no-fn
//   fffffff008069388 no-fn
//   fffffff008069ce8 no-fn
// CALLEES:
//   fffffff009c4060c FUN_fffffff009c4060c

undefined8
FUN_fffffff009c39eec
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 param_8,long param_9)

{
  undefined8 uVar1;
  
  if (*(long *)(param_9 + 0x68) != 0) {
    return 0xe00002c2;
  }
  uVar1 = FUN_fffffff009c4060c
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                     **(uint **)(param_9 + 0x20),*(ulong *)(*(uint **)(param_9 + 0x20) + 2),
                     (ulong)*(uint *)(param_9 + 0x60),*(long **)(param_9 + 0x48),
                     (ulong *)(*(long **)(param_9 + 0x48) + 1),(uint *)(param_9 + 0x60),
                     *(undefined8 **)(param_9 + 0x58));
  return uVar1;
}

