// FUN_fffffff009c578f0 @ fffffff009c578f0

void FUN_fffffff009c578f0
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  undefined1 auVar3 [16];
  
  lVar2 = (**(code **)(*param_7 + 0x38))();
  auVar3 = thunk_FUN_fffffff00a895b28(lVar2);
  thunk_FUN_fffffff00a8df19c
            (auVar3,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
             (short *)PTR_DAT_fffffff00807b638,0,(byte *)"  %s(%s): freeing\n");
  param_7[0x11] = (long)&DAT_fffffff0078a32d8;
  if ((long *)param_7[0x12] != (long *)0x0) {
    (**(code **)(*(long *)param_7[0x12] + 0x28))();
    param_7[0x12] = 0;
  }
  if ((undefined8 *)param_7[0x17] != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020((undefined8 *)param_7[0x17]);
    param_7[0x17] = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c579c0);
    (*pcVar1)();
  }
  (**(code **)(PTR_DAT_fffffff00807b628 + 0x80))(param_7);
  return;
}

