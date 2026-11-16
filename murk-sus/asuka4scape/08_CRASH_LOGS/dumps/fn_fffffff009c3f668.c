// FUN_fffffff009c3f668 @ fffffff009c3f668 size=88
// CALLERS:
//   fffffff00afec11c no-fn
//   fffffff009c3364c FUN_fffffff009c33548@fffffff009c33548
// CALLEES:
//   fffffff009c3f044 FUN_fffffff009c3f044
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590

void FUN_fffffff009c3f668
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               long param_8)

{
  long lStack_20;
  long local_18;
  
  local_18 = *(long *)PTR_DAT_fffffff00806ca40;
  FUN_fffffff009c3f044
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,*(uint *)(param_8 + 0x10),
             &lStack_20);
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

