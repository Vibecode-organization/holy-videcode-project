// FUN_fffffff009c39748 @ fffffff009c39748 size=24
// CALLERS:
//   fffffff00afec076 ?
//   fffffff008069068 ?
//   fffffff0080699c8 ?
// CALLS:
//   fffffff009c3d978 FUN_fffffff009c3d978

void FUN_fffffff009c39748
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 param_8,long param_9)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_9 + 0x20);
  FUN_fffffff009c3d978
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,*puVar1,puVar1[2],puVar1[4]);
  return;
}

