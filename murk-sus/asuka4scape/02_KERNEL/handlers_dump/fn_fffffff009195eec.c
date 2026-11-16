// FUN_fffffff009195eec @ fffffff009195eec size=84 depth=1
// CALLERS:
//   fffffff00afdb4a1 ?
//   fffffff009185050 FUN_fffffff009185030
//   fffffff0091850b8 FUN_fffffff009185098
//   fffffff00918512c FUN_fffffff009185104
//   fffffff0091851c4 FUN_fffffff00918519c
//   fffffff00918525c FUN_fffffff009185234
//   fffffff009186620 FUN_fffffff009186600
//   fffffff0091ad0d4 FUN_fffffff0091ad0a8
// CALLS:
//   fffffff0091b89b0 thunk_FUN_fffffff00a894f30
//   fffffff009195d1c FUN_fffffff009195d1c

void FUN_fffffff009195eec
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               uint param_8)

{
  long *plVar1;
  
  if (*(long *)(param_7 + 0x1f8) == 0) {
    plVar1 = (long *)FUN_fffffff009195d1c
                               (param_1,param_2,param_3,param_4,param_5,param_6,param_7,0x64656275,
                                param_8);
    plVar1 = thunk_FUN_fffffff00a894f30(plVar1,(long)PTR_DAT_fffffff007ec9918);
    *(long **)(param_7 + 0x1f8) = plVar1;
  }
  return;
}

