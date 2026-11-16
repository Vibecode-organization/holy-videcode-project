// FUN_fffffff009cfb708 @ fffffff009cfb708

/* WARNING: Removing unreachable block (ram,0xfffffff009cfb84c) */

void FUN_fffffff009cfb708
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7,ulong param_8,
               undefined8 param_9,long param_10)

{
  code *pcVar1;
  bool bVar2;
  long lVar3;
  short *psVar4;
  ulong unaff_x30;
  undefined1 auVar5 [16];
  
  lVar3 = thunk_FUN_fffffff00a92f600();
  if (((param_8 & 0x20004) != 0) && (param_10 == lVar3)) {
    if ((param_7 != (long *)0x0) && ((*(uint *)((long)param_7 + 500) >> 4 & 1) != 0)) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar2 = thunk_FUN_fffffff00a394140(), !bVar2)) {
        psVar4 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar5 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar5,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar4,0,
                   (byte *)"%s@%s: %s::%s: system sleep\n");
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: system sleep\n");
      }
    }
    lVar3 = (**(code **)(*(long *)param_7[0x17] + 0x118))
                      ((long *)param_7[0x17],"usb-device-slp-ddr");
    if (lVar3 != **(long **)PTR_PTR_fffffff008089d58) {
      (**(code **)(*(long *)param_7[0x4d4] + 0xb8))();
      thunk_FUN_fffffff00a94db58(param_7);
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    (**(code **)(PTR_DAT_fffffff008089d10 + 0x508))
              (param_7,param_8,param_9,param_10,PTR_DAT_fffffff008089d10 + 0x508);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009cfb954);
  (*pcVar1)();
}

