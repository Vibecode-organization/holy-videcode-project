// FUN_fffffff00995f8b4 @ fffffff00995f8b4 size=808

/* WARNING: Removing unreachable block (ram,0xfffffff00995fb18) */

void FUN_fffffff00995f8b4(long *param_1)

{
  uint uVar1;
  undefined *puVar2;
  code *pcVar3;
  long *plVar4;
  undefined8 in_x6;
  undefined8 in_x7;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong unaff_x30;
  char *pcVar10;
  ulong uVar11;
  
  puVar2 = PTR_DAT_fffffff007ff2808;
  do {
    thunk_EXT_FUN_80110000032222a8(param_1[0x1e]);
    lVar5 = param_1[0x1f];
    uVar6 = *(uint *)(param_1[0x35] + 0x200);
    uVar9 = (ulong)uVar6;
    if (*(char *)(lVar5 + uVar9) == '\0') {
      if (uVar6 == 0) {
LAB_fffffff00995fb88:
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995fbb8);
          (*pcVar3)();
        }
        thunk_EXT_FUN_8011000003222de0(param_1[0x1e]);
        return;
      }
      uVar7 = 0;
      while (uVar6 = (uint)*(byte *)(lVar5 + uVar7), uVar6 == 0) {
        uVar7 = uVar7 + 1;
        if (uVar9 == uVar7) goto LAB_fffffff00995fb88;
      }
      uVar6 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
      uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
      uVar8 = LZCOUNT((uVar6 >> 4 | (uVar6 & 0xf0f0f0f) << 4) << 0x18);
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,puVar2,0x11,"%s: setting channel %d restart type to %d\n");
      *(byte *)(param_1[0x1f] + uVar7) =
           *(byte *)(param_1[0x1f] + uVar7) & ((byte)(1 << (ulong)((uint)uVar8 & 0x1f)) ^ 0xff);
    }
    else {
      uVar1 = (*(byte *)(lVar5 + (int)uVar6) & 0xaaaaaaaa) >> 1 |
              (*(byte *)(lVar5 + (int)uVar6) & 0x55555555) << 1;
      uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
      uVar8 = LZCOUNT((uVar1 >> 4 | (uVar1 & 0xf0f0f0f) << 4) << 0x18);
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,puVar2,0x11,"%s: setting global restart type to %d\n");
      *(byte *)(param_1[0x1f] + (long)(int)uVar6) =
           *(byte *)(param_1[0x1f] + (long)(int)uVar6) &
           ((byte)(1 << (ulong)((uint)uVar8 & 0x1f)) ^ 0xff);
      uVar7 = uVar9;
    }
    thunk_EXT_FUN_8011000003222de0(param_1[0x1e]);
    if ((int)uVar8 == 0) {
      return;
    }
    FUN_fffffff009962a98(param_1);
    *(int *)(param_1 + 0x1d) = (int)uVar8;
    if ((uint)uVar7 < *(uint *)(param_1[0x35] + 0x200)) {
      plVar4 = (long *)(**(code **)(*param_1 + 0x88))(param_1,uVar7);
      uVar9 = (ulong)*(uint *)(param_1 + 0x1d);
    }
    else {
      plVar4 = (long *)0x0;
      uVar9 = uVar8;
    }
    pcVar10 = "void IOGPUScheduler::hardware_error_interrupt(IOInterruptEventSource *, int)";
    uVar11 = uVar7;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,puVar2,0x11,"%s: GPURestartDequeued stampIdx=%d type=%d\n");
    lVar5 = (long)(int)(uint)uVar7;
    thunk_EXT_FUN_80110000036da494
              (0x85090090,lVar5,(int)param_1[0x1d],0xffffffffffffffff,0xffffffffffffffff,0,in_x6,
               in_x7,pcVar10,uVar11,uVar9);
    thunk_EXT_FUN_80110000036da494(0x8509009c,lVar5,(int)param_1[0x1d],0,0,0);
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,puVar2,0x11,"%s: GPURestartBegin stampIdx=%d type=%d\n");
    if (plVar4 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar2,0x11,"%s: global restart. type=%d\n");
      (**(code **)(*(long *)param_1[0x35] + 0x688))(*(long *)param_1[0x35] + 0x688);
    }
    else {
      (**(code **)(*plVar4 + 0x98))(plVar4);
    }
    uVar9 = (ulong)*(uint *)(param_1 + 0x1d);
    pcVar10 = "void IOGPUScheduler::hardware_error_interrupt(IOInterruptEventSource *, int)";
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,puVar2,0x11,"%s: GPURestartEnd stampIdx=%d type=%d\n");
    thunk_EXT_FUN_80110000036da494(0x850900a0,lVar5,uVar8,0,0,0,in_x6,in_x7,pcVar10,uVar7,uVar9);
    *(int *)(param_1 + 0x22) = (int)param_1[0x22] + 1;
    FUN_fffffff009962b18(param_1);
  } while( true );
}

