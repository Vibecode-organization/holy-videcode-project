// FUN_fffffff009c5be70 @ fffffff009c5be70

undefined8
FUN_fffffff009c5be70
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long *param_7)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined8 local_38;
  
  local_38 = 0x800;
  thunk_FUN_fffffff00a8df19c
            (param_1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
             (short *)PTR_DAT_fffffff00807b638,0,&DAT_fffffff0078a90be);
  if (param_7[0x12] == 0) {
    plVar2 = (long *)(**(code **)(*(long *)PTR_DAT_fffffff0080786a0 + 0x68))();
    param_7[0x12] = (long)plVar2;
    if (plVar2 == (long *)0x0) {
      uVar4 = 0xe00002bc;
      auVar5 = FUN_fffffff009c7ae8c(extraout_q0,param_2,param_3,param_4,param_5,param_6);
    }
    else {
      uVar3 = (**(code **)(*plVar2 + 0x78))(plVar2,2000,1,&local_38,param_7[0x17]);
      if ((uVar3 & 1) == 0) {
        uVar4 = 0xe00002bc;
        auVar5 = FUN_fffffff009c7ae48(extraout_q0_00,param_2,param_3,param_4,param_5,param_6);
      }
      else {
        lVar1 = (**(code **)(*param_7 + 0x38))(param_7);
        auVar5 = thunk_FUN_fffffff00a895b28(lVar1);
        auVar5 = thunk_FUN_fffffff00a8df19c
                           (auVar5,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                            (short *)PTR_DAT_fffffff00807b638,0,
                            (byte *)"  %s(%s): %s Allocate packetpool successfully");
        uVar4 = 0;
      }
    }
  }
  else {
    uVar4 = 0xe00002bc;
    lVar1 = (**(code **)(*param_7 + 0x38))(param_7);
    auVar5 = thunk_FUN_fffffff00a895b28(lVar1);
    auVar5 = thunk_FUN_fffffff00a8df19c
                       (auVar5,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                        (short *)PTR_DAT_fffffff00807b638,0,
                        (byte *)"  %s(%s): %s _timeSyncPacketPool isn\'t NULL and re-use it");
  }
  thunk_FUN_fffffff00a8df19c
            (auVar5,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
             (short *)PTR_DAT_fffffff00807b638,0,&DAT_fffffff0078a9195);
  return uVar4;
}

