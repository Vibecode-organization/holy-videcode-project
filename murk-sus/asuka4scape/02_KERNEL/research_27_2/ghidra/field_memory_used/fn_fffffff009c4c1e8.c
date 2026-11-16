// FUN_fffffff009c4c1e8 @ fffffff009c4c1e8

undefined8
FUN_fffffff009c4c1e8
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7)

{
  undefined *puVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined1 extraout_q0 [16];
  undefined1 auVar5 [16];
  long local_28;
  
  iVar2 = DAT_fffffff00af487f0;
  DAT_fffffff00af487f0 = DAT_fffffff00af487f0 + 1;
  *(undefined4 *)(param_7 + 0x98) = 0;
  *(int *)(param_7 + 0x9c) = iVar2;
  local_28 = 0;
  iVar2 = thunk_FUN_fffffff00aa14b0c((byte *)"timesync_tsnotifytest",(uint *)&local_28,8);
  *(bool *)(param_7 + 0xa0) = iVar2 != 0 && local_28 != 0;
  lVar3 = thunk_FUN_fffffff00a903010();
  *(long *)(param_7 + 0xa8) = lVar3;
  puVar1 = PTR_DAT_fffffff00807b638;
  if (lVar3 == 0) {
    auVar5 = thunk_FUN_fffffff00a8df19c
                       (extraout_q0,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                        (short *)PTR_DAT_fffffff00807b638,0,
                        (byte *)
                        " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                       );
    thunk_FUN_fffffff00a8df19c
              (auVar5,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,(short *)puVar1,0,
               (byte *)"Failed to allocate stop lock\n");
    uVar4 = 0;
  }
  else {
    uVar4 = (**(code **)(PTR_DAT_fffffff00807b628 + 0xb8))(param_7,0);
  }
  return uVar4;
}

