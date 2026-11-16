// FUN_fffffff009c516a4 @ fffffff009c516a4

undefined8
FUN_fffffff009c516a4
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long *param_8)

{
  undefined *puVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined1 extraout_q0 [16];
  undefined1 auVar5 [16];
  undefined4 uVar6;
  undefined4 uVar7;
  uint local_24;
  
  uVar7 = param_4._0_4_;
  uVar6 = param_3._0_4_;
  local_24 = 0;
  *(undefined8 *)(param_7 + 0x140) = 0;
  *(undefined8 *)(param_7 + 0x148) = 0;
  *(undefined8 *)(param_7 + 0x150) = 0;
  *(undefined1 *)(param_7 + 0x184) = 0;
  *(undefined2 *)(param_7 + 0x160) = 0;
  *(undefined8 *)(param_7 + 0x168) = 0;
  *(undefined1 *)(param_7 + 0x170) = 0;
  *(undefined8 *)(param_7 + 0x178) = 0;
  plVar3 = thunk_FUN_fffffff00a96500c
                     (param_1,param_2,param_3,param_4,param_5,param_6,0xff,param_7,
                      FUN_fffffff009c517f0);
  *(long **)(param_7 + 0x148) = plVar3;
  puVar1 = PTR_DAT_fffffff00807b638;
  if (plVar3 == (long *)0x0) {
    auVar5 = thunk_FUN_fffffff00a8df19c
                       (extraout_q0,param_2,uVar6,uVar7,param_5,param_6,&MACH_HEADER,
                        (short *)PTR_DAT_fffffff00807b638,0,
                        (byte *)
                        " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                       );
    thunk_FUN_fffffff00a8df19c
              (auVar5,param_2,uVar6,uVar7,param_5,param_6,&MACH_HEADER,(short *)puVar1,0,
               (byte *)"could not create fTimeDomainSnapshotTimer\n\n");
    uVar4 = 0;
  }
  else {
    uVar4 = (*(code *)PTR_FUN_fffffff008070180)(param_7,param_8,0);
    iVar2 = thunk_FUN_fffffff00aa14b0c((byte *)"timesync_log",&local_24,4);
    if (iVar2 == 0) {
      *(undefined2 *)(param_7 + 0x181) = 0;
      *(undefined1 *)(param_7 + 0x183) = 0;
    }
    else {
      *(byte *)(param_7 + 0x181) = (byte)(local_24 >> 8) & 1;
      *(byte *)(param_7 + 0x182) = (byte)(local_24 >> 9) & 1;
      *(byte *)(param_7 + 0x183) = (byte)(local_24 >> 10) & 1;
    }
  }
  return uVar4;
}

