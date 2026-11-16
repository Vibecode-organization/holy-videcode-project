// FUN_fffffff009977480 @ fffffff009977480 size=416

void FUN_fffffff009977480(long param_1,undefined8 param_2,int *param_3,long param_4)

{
  ulong uVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  ulong unaff_x30;
  
  uVar5 = param_4 - (long)(param_3 + 2);
  if (*param_3 == 1) {
    if (7 < uVar5) {
      uVar3 = thunk_EXT_FUN_8011000003397c88();
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009977524);
        (*pcVar2)();
      }
      thunk_EXT_FUN_8011000003398228(uVar3,param_3 + 2);
      return;
    }
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s:kIOGPUKernelCommandCollectTimeStamp: Insufficient bytes (%llu) for sIOGPUKernelCommandCollectTimeStampArgs (%lu)\n"
              );
  }
  else if (*param_3 == 0) {
    if (7 < uVar5) {
      uVar1 = uVar5 - 8;
      if ((ulong)(uint)param_3[3] <= uVar5 - 8) {
        uVar1 = (ulong)(uint)param_3[3];
      }
      lVar4 = thunk_EXT_FUN_80110000038fe580(uVar1 + 1);
      thunk_EXT_FUN_8011000003a61b10(lVar4,param_3 + 4,uVar1);
      *(undefined1 *)(lVar4 + uVar1) = 0;
      if (param_3[2] == 0) {
        thunk_EXT_FUN_8011000003a132c0("kIOGPUKernelCommandDebugLog:%s\n");
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099775cc);
        (*pcVar2)();
      }
      thunk_EXT_FUN_80110000038fe6b0(lVar4,uVar1 + 1);
      return;
    }
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s:kIOGPUKernelCommandDebugLog: Insufficient bytes (%llu) for sIOGPUKernelCommandDebugLogArgs (%lu)\n"
              );
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Invalid eIOGPUKernelCommands enum (command_id=%u command_size=%llubytes)\n");
  }
  *(undefined4 *)(param_1 + 0x520) = 10;
  return;
}

