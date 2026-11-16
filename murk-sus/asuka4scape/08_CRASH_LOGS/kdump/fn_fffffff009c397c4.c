// FUN_fffffff009c397c4 @ fffffff009c397c4 size=20
// CALLERS:
//   fffffff00afec079 ?
//   fffffff0080690b8 ?
// CALLS:
//   fffffff009c3da58 FUN_fffffff009c3da58

void FUN_fffffff009c397c4
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 param_8,long param_9)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_9 + 0x20);
  FUN_fffffff009c3da58
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,*puVar1,*(ulong *)(puVar1 + 2),
             *(undefined8 *)(puVar1 + 4));
  return;
}

