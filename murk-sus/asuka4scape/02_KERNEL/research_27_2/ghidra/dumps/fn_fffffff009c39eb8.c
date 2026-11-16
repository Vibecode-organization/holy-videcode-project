// FUN_fffffff009c39eb8 @ fffffff009c39eb8 size=52
// CALLERS:
//   fffffff00afec08f no-fn
//   fffffff008069360 no-fn
//   fffffff008069cc0 no-fn
// CALLEES:
//   fffffff009c40588 FUN_fffffff009c40588

undefined8
FUN_fffffff009c39eb8
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 param_8,long param_9)

{
  undefined8 uVar1;
  
  if (*(long *)(param_9 + 0x40) != 0) {
    return 0xe00002c2;
  }
  uVar1 = FUN_fffffff009c40588
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                     **(uint **)(param_9 + 0x20),*(ulong *)(*(uint **)(param_9 + 0x20) + 2),
                     (ulong *)(ulong)*(uint *)(param_9 + 0x38),*(undefined8 **)(param_9 + 0x30));
  return uVar1;
}

