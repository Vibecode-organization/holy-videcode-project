// FUN_fffffff009a89710 @ fffffff009a89710 size=236
// CALLERS:
//   fffffff00afe8499 no-fn
//   fffffff009a7e08c FUN_fffffff009a7e020@fffffff009a7e020
// CALLEES:
//   fffffff009a9a800 thunk_FUN_fffffff00aa4c590
//   fffffff009a9a390 thunk_FUN_fffffff009abc218
//   fffffff009a9a8f0 thunk_FUN_fffffff00aa65d70
//   fffffff009a9a380 thunk_FUN_fffffff009abc194

uint FUN_fffffff009a89710
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               long param_8)

{
  undefined1 auVar1 [16];
  uint local_26c;
  byte abStack_268 [556];
  undefined1 local_3c;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff008022300;
  thunk_FUN_fffffff00aa65d70((long *)abStack_268,0xaa,0x230);
  local_26c = 0xaaaaaaaa;
  local_3c = param_8 == 0;
  if (!(bool)local_3c) {
    auVar1[8] = 0xaa;
    auVar1._0_8_ = &DAT_aaaaaaaaaaaaaaaa;
    auVar1[9] = 0xaa;
    auVar1[10] = 0xaa;
    auVar1[0xb] = 0xaa;
    auVar1[0xc] = 0xaa;
    auVar1[0xd] = 0xaa;
    auVar1[0xe] = 0xaa;
    auVar1[0xf] = 0xaa;
    thunk_FUN_fffffff009abc218(auVar1,param_2,param_3,param_4,param_5,param_6,abStack_268,param_8);
    thunk_FUN_fffffff009abc194((long)abStack_268);
  }
  (**(code **)(*param_7 + 0x8b0))(param_7,0x41353333,abStack_268,0x230,&local_26c,4);
  if (*(long *)PTR_DAT_fffffff008022300 != local_38) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return local_26c & 1;
}

