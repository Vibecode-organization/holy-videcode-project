// FUN_fffffff009c72510 @ fffffff009c72510

undefined4
FUN_fffffff009c72510
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7,ulong param_8,undefined8 param_9,
          undefined8 param_10,ulong param_11)

{
  undefined *puVar1;
  int iVar2;
  undefined8 extraout_x1;
  ulong uVar3;
  ulong uVar4;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  
  puVar1 = PTR_DAT_fffffff00807b638;
  if (5000 < (uint)param_8) {
    return 0xe00002c2;
  }
  do {
    if (*(long *)(param_7 + 0xb8) == 0) {
      return 0;
    }
    thunk_FUN_fffffff00a8df19c
              (param_1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,(short *)puVar1,0,
               (byte *)"Waiting for packets to flush.  _numberOfOutstandingPackets=%llu");
    uVar4 = 1000000;
    uVar3 = param_8;
    thunk_FUN_fffffff00a246e7c((uint *)(param_7 + 0xb8),0,param_8,1000000);
    iVar2 = thunk_FUN_fffffff00a24bbfc
                      (extraout_q0,param_2,param_3,param_4,param_5,param_6,0,extraout_x1,uVar3,uVar4
                       ,param_11);
    param_1 = extraout_q0_00;
  } while (iVar2 != 1);
  thunk_FUN_fffffff00a8df19c
            (extraout_q0_00,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
             (short *)PTR_DAT_fffffff00807b638,0,
             (byte *)
             "Unexpected timeout waiting for packets to flush. _numberOfOutstandingPackets=%llu");
  return *(undefined4 *)(param_7 + 0xb8);
}

