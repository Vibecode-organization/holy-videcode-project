// FUN_fffffff009c583d4 @ fffffff009c583d4

undefined8
FUN_fffffff009c583d4
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,
          long *param_13)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 auVar5 [16];
  
  thunk_FUN_fffffff00a8df19c
            (param_1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
             (short *)PTR_DAT_fffffff00807b638,0,
             (byte *)"+ TSNUserWiFiControlInterface(static)::_Create_Internal\n");
  plVar1 = (long *)(**(code **)(DAT_fffffff00af48a68 + 0x68))();
  if (plVar1 == (long *)0x0) {
    uVar4 = 0xe00002bc;
    auVar5 = FUN_fffffff009c7a570(extraout_q0,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    *param_13 = (long)plVar1;
    uVar2 = (**(code **)(*plVar1 + 0x548))
                      (plVar1,param_7,param_8,param_9,param_10,param_11,param_12,0);
    if ((uVar2 & 1) == 0) {
      uVar4 = 0xe00002bc;
      auVar5 = FUN_fffffff009c7a52c(extraout_q0_00,param_2,param_3,param_4,param_5,param_6);
    }
    else {
      plVar1[0x18] = (long)&DAT_fffffff0078a232d;
      lVar3 = thunk_FUN_fffffff00a903010();
      plVar1[0x17] = lVar3;
      if (lVar3 == 0) {
        (**(code **)(*plVar1 + 0x28))(plVar1);
        return 0xe00002bd;
      }
      uVar4 = 0;
      auVar5 = extraout_q0_01;
    }
  }
  thunk_FUN_fffffff00a8df19c
            (auVar5,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
             (short *)PTR_DAT_fffffff00807b638,0,
             (byte *)"- TSNUserWiFiControlInterface(static)::_Create_Internal\n");
  return uVar4;
}

