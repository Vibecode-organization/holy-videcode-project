// FUN_fffffff0099628f0 @ fffffff0099628f0 size=424

void FUN_fffffff0099628f0(long param_1,ulong param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  code *pcVar6;
  undefined8 in_x6;
  undefined8 in_x7;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  ulong unaff_x30;
  char *pcVar12;
  
  uVar5 = 1 << (ulong)((uint)param_2 & 0x1f);
  uVar10 = param_2 & 0xffffffff;
  uVar3 = *(uint *)(*(long *)(param_1 + 0x1a8) + 0x200);
  uVar1 = param_3;
  if (uVar3 <= param_3) {
    uVar1 = uVar3;
  }
  uVar2 = uVar3;
  if (-1 < (int)param_3) {
    uVar2 = uVar1;
  }
  uVar11 = (ulong)uVar2;
  lVar9 = (long)(int)uVar2;
  thunk_EXT_FUN_80110000036da494
            (0x85090088,lVar9,uVar10,*(undefined1 *)(*(long *)(param_1 + 0xf8) + (long)(int)uVar2),
             uVar3,0);
  uVar7 = (ulong)*(byte *)(*(long *)(param_1 + 0xf8) + (long)(int)uVar2);
  uVar8 = (ulong)*(uint *)(*(long *)(param_1 + 0x1a8) + 0x200);
  pcVar12 = "void IOGPUScheduler::signalHardwareError(eRestartRequest, int32_t)";
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
             "%s: GPURestartSignaled stampIdx=%d type=%d prevType=%d numStamps=%d\n");
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xf0));
  bVar4 = *(byte *)(*(long *)(param_1 + 0xf8) + (long)(int)uVar2);
  if ((uVar5 & bVar4) == 0) {
    *(byte *)(*(long *)(param_1 + 0xf8) + lVar9) = bVar4 | (byte)uVar5;
    (**(code **)(**(long **)(param_1 + 0x100) + 0xf8))(*(long **)(param_1 + 0x100),0,0,0);
    thunk_EXT_FUN_80110000036da494
              (0x8509008c,lVar9,uVar10,0,0,0,in_x6,in_x7,pcVar12,uVar11,param_2,uVar7,uVar8);
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: GPURestartEnqueued stampIdx=%d type=%d\n");
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Redundant hardware error stampIdx=%d type=%d\n");
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009962a94);
    (*pcVar6)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xf0));
  return;
}

