// FUN_fffffff009c42d48 @ fffffff009c42d48 size=356
// CALLERS:
//   fffffff00afec1a3 no-fn
//   fffffff009c452dc FUN_fffffff009c45114@fffffff009c45114
//   fffffff009c42bb0 FUN_fffffff009c429e4@fffffff009c429e4
// CALLEES:
//   fffffff009c49a84 thunk_FUN_fffffff00a8cae24
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c49e74 thunk_FUN_fffffff00a2df760
//   fffffff009c49894 thunk_FUN_fffffff00a8a140c

undefined8 FUN_fffffff009c42d48(long param_1,long *param_2)

{
  undefined8 uVar1;
  long *local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_30 = (long *)0x0;
  thunk_FUN_fffffff00a2df760(*(ulong *)(param_1 + 0x18),(long *)&local_30);
  local_30 = thunk_FUN_fffffff00a8cae24(local_30,0x40);
  thunk_FUN_fffffff00a8a140c(param_2,"Descriptor address",&local_30);
  if (local_30 != (long *)0x0) {
    (**(code **)(*local_30 + 0x28))();
  }
  uVar1 = (**(code **)(**(long **)(param_1 + 0x18) + 0xb0))();
  local_30 = thunk_FUN_fffffff00a8cae24(uVar1,0x40);
  thunk_FUN_fffffff00a8a140c(param_2,"Length",&local_30);
  if (local_30 != (long *)0x0) {
    (**(code **)(*local_30 + 0x28))();
  }
  local_30 = thunk_FUN_fffffff00a8cae24((ulong)*(uint *)(param_1 + 0xc),0x20);
  thunk_FUN_fffffff00a8a140c(param_2,"Options",&local_30);
  if (local_30 != (long *)0x0) {
    (**(code **)(*local_30 + 0x28))();
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

