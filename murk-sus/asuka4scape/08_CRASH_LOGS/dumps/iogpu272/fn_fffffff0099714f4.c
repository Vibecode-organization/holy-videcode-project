// FUN_fffffff0099714f4 @ fffffff0099714f4 size=4

undefined8 FUN_fffffff0099714f4(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x1e8) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: accelName must not NULL\n");
    uVar2 = 0;
  }
  else if (*(int *)(param_1 + 0x200) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: numEventChannels must at least 1\n");
    uVar2 = 0;
  }
  else if (*(int *)(param_1 + 0x23c) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: waitForGPUTimeoutSeconds can not be zero.\n");
    uVar2 = 0;
  }
  else if (*(uint *)(param_1 + 0x264) < 9) {
    uVar1 = *(uint *)(param_1 + 0x274) - 1;
    if (uVar1 < (*(uint *)(param_1 + 0x274) ^ uVar1)) {
      uVar2 = 1;
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: minVirtualPageSize is not a power of 2\n");
      uVar2 = 0;
    }
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: maxSchedulerPriorityCount can not exceed %d\n");
    uVar2 = 0;
  }
  return uVar2;
}

