// FUN_fffffff009c1f34c @ fffffff009c1f34c size=164
// CALLERS:
//   fffffff00afebcca no-fn
//   fffffff009c338f4 FUN_fffffff009c33890@fffffff009c33890
//   fffffff009c33a9c FUN_fffffff009c33a4c@fffffff009c33a4c
//   fffffff009c34f50 FUN_fffffff009c34d4c@fffffff009c34d4c
// CALLEES:
//   fffffff009c49c14 thunk_FUN_fffffff00a6de494
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c49430 FUN_fffffff009c49430
//   fffffff009c49e74 thunk_FUN_fffffff00a2df760

bool FUN_fffffff009c1f34c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7)

{
  bool bVar1;
  undefined1 auVar2 [16];
  undefined4 uVar3;
  undefined4 uVar4;
  long local_40;
  long local_38;
  
  uVar4 = param_4._0_4_;
  uVar3 = param_3._0_4_;
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  bVar1 = FUN_fffffff009c49430
                    (param_1,param_2,param_3,param_4,param_5,param_6,(uint *)(param_7 + 0xc));
  local_40 = 0;
  auVar2 = thunk_FUN_fffffff00a2df760(*(ulong *)(param_7 + 0x30),&local_40);
  thunk_FUN_fffffff00a6de494
            (auVar2,param_2,uVar3,uVar4,param_5,param_6,0x85210034,local_40,
             (ulong)*(uint *)(param_7 + 0x10),(ulong)*(uint *)(param_7 + 0xc),0);
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return bVar1;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

