// FUN_fffffff009c94028 @ fffffff009c94028

/* WARNING: Removing unreachable block (ram,0xfffffff009c94204) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c94248) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c9416c) */

void FUN_fffffff009c94028
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7,
               undefined8 param_8,long *param_9)

{
  code *pcVar1;
  bool bVar2;
  ulong uVar3;
  long lVar4;
  short *psVar5;
  ulong unaff_x30;
  undefined1 auVar6 [16];
  
  if ((*(byte *)(param_7 + 0xd) & 1) == 0) {
    if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar2 = thunk_FUN_fffffff00a394140(), !bVar2)) {
        psVar5 = *(short **)PTR_DAT_fffffff00807fa80;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar6 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        param_9 = (long *)0x0;
        thunk_FUN_fffffff00a8df19c
                  (auVar6,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar5,0,
                   (byte *)"%s@%s: %s::%s: IOUSBDeviceController::joinPowerPlane\n");
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: IOUSBDeviceController::joinPowerPlane\n")
        ;
      }
    }
    (**(code **)(*param_7 + 0x480))(param_7);
    lVar4 = *(long *)param_7[0x17];
    (**(code **)(lVar4 + 0x490))(lVar4 + 0x490,(long *)param_7[0x17],param_7);
    thunk_FUN_fffffff00a94d580(param_7,0,param_9);
    param_9 = param_7 + 0x40;
    param_1 = (**(code **)(*param_7 + 0x498))(*param_7 + 0x498,param_7,param_7,param_9,5);
  }
  uVar3 = (**(code **)(*param_7 + 0x718))(param_1,param_7);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c942b8);
    (*pcVar1)();
  }
  thunk_FUN_fffffff00a94d4c8(param_7,uVar3 & 0xffffffff,param_9);
  return;
}

