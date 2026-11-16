// FUN_fffffff009c5d058 @ fffffff009c5d058

void FUN_fffffff009c5d058
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined **param_7,
               undefined8 param_8,undefined8 param_9,undefined8 param_10,undefined *param_11)

{
  code *pcVar1;
  ulong unaff_x30;
  undefined1 auVar2 [16];
  
  auVar2 = FUN_fffffff009c5cfdc(param_7);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c5d09c);
    (*pcVar1)();
  }
  thunk_FUN_fffffff00a898430
            (auVar2,param_2,param_3,param_4,param_5,param_6,(long *)&DAT_fffffff00807a920,param_7,
             &DAT_000000b8,param_10,param_11);
  return;
}

