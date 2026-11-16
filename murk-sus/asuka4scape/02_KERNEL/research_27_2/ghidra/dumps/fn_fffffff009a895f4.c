// FUN_fffffff009a895f4 @ fffffff009a895f4 size=284
// CALLERS:
//   fffffff00afe8497 no-fn
//   fffffff009a7d73c FUN_fffffff009a7d52c@fffffff009a7d52c
// CALLEES:
//   fffffff009a9a800 thunk_FUN_fffffff00aa4c590
//   fffffff009a9a390 thunk_FUN_fffffff009abc218
//   fffffff009a9a8f0 thunk_FUN_fffffff00aa65d70
//   fffffff009a9a380 thunk_FUN_fffffff009abc194

uint FUN_fffffff009a895f4
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               long param_8,undefined4 param_9,undefined4 param_10,undefined8 param_11)

{
  undefined1 auVar1 [16];
  uint local_29c;
  byte abStack_298 [556];
  undefined4 local_6c;
  undefined4 local_68;
  undefined8 local_64;
  undefined1 local_5c;
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff008022300;
  thunk_FUN_fffffff00aa65d70((long *)abStack_298,0xaa,0x240);
  local_29c = 0xaaaaaaaa;
  local_5c = param_8 == 0;
  if (!(bool)local_5c) {
    auVar1[8] = 0xaa;
    auVar1._0_8_ = &DAT_aaaaaaaaaaaaaaaa;
    auVar1[9] = 0xaa;
    auVar1[10] = 0xaa;
    auVar1[0xb] = 0xaa;
    auVar1[0xc] = 0xaa;
    auVar1[0xd] = 0xaa;
    auVar1[0xe] = 0xaa;
    auVar1[0xf] = 0xaa;
    thunk_FUN_fffffff009abc218(auVar1,param_2,param_3,param_4,param_5,param_6,abStack_298,param_8);
    thunk_FUN_fffffff009abc194((long)abStack_298);
  }
  local_6c = param_9;
  local_68 = param_10;
  local_64 = param_11;
  (**(code **)(*param_7 + 0x8b0))(param_7,0x41353332,abStack_298,0x240,&local_29c,4);
  if (*(long *)PTR_DAT_fffffff008022300 != local_58) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return local_29c & 1;
}

