// FUN_fffffff009a7805c @ fffffff009a7805c size=160
// CALLERS:
//   fffffff00afe82e0 no-fn
//   fffffff007e74318 no-fn
//   fffffff009a7d638 FUN_fffffff009a7d52c@fffffff009a7d52c
//   fffffff009a7e230 FUN_fffffff009a7e020@fffffff009a7e020
//   fffffff008eb8c0c thunk_FUN_fffffff009a7805c@fffffff008eb8c00
// CALLEES:
//   fffffff009a99e90 thunk_FUN_fffffff009c34224
//   fffffff009a9a920 thunk_FUN_fffffff00aa4d114

long FUN_fffffff009a7805c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 extraout_q0 [16];
  
  lVar1 = param_7[0x23];
  if (lVar1 == 0) {
    if (param_7[0x28] == 0) {
      lVar1 = 0;
    }
    else {
      uVar2 = (**(code **)(*param_7 + 0xa90))(param_7);
      lVar1 = thunk_FUN_fffffff009c34224(param_7[0x28],uVar2);
      param_7[0x23] = lVar1;
      if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_fffffff00aa4d114
                  (extraout_q0,param_2,param_3,param_4,param_5,param_6,
                   (byte *)"\"IOMFB: carveout memory region \\\"%s\\\" not found\\n\" @%s:%d");
      }
    }
  }
  return lVar1;
}

