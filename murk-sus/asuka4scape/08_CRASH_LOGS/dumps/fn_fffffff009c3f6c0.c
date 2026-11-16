// FUN_fffffff009c3f6c0 @ fffffff009c3f6c0 size=188
// CALLERS:
//   fffffff00afec11e no-fn
//   fffffff009c35aa4 FUN_fffffff009c35a60@fffffff009c35a60
// CALLEES:
//   fffffff009c497e4 thunk_FUN_fffffff00a9a80ec
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c495d4 thunk_FUN_fffffff00a226de0
//   fffffff009c495b4 thunk_FUN_fffffff00a2262a8
//   fffffff009c3f044 FUN_fffffff009c3f044

void FUN_fffffff009c3f6c0
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               long param_8,ulong param_9,uint param_10,undefined8 param_11,undefined8 param_12,
               ulong param_13)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  long lStack_60;
  ulong local_58;
  ulong uStack_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  auVar2 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0xd8));
  uVar1 = FUN_fffffff009c3f044
                    (auVar2,param_2,param_3,param_4,param_5,param_6,param_7,param_10,&lStack_60);
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0xd8));
  if ((int)uVar1 != 0) {
    local_58 = param_9 & 0xffffffff;
    uStack_50 = (ulong)param_10;
    thunk_FUN_fffffff00a9a80ec
              ((ulong *)(param_8 + 0x10),0,(undefined1 (*) [12])&local_58,2,param_11,param_12,
               param_13);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

