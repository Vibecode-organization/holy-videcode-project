// FUN_fffffff009c27858 @ fffffff009c27858

void FUN_fffffff009c27858
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long param_7)

{
  long lVar1;
  undefined *puVar2;
  code *pcVar3;
  undefined8 uVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auVar6 [16];
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  
  auVar6 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0x50));
  puVar2 = PTR_DAT_fffffff00806ca48;
  auVar6 = thunk_FUN_fffffff00a8df19c
                     (auVar6,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                      (short *)PTR_DAT_fffffff00806ca48,2,
                      (byte *)"IOSurface fence debug: surface: %p id: %d\n");
  uVar4 = thunk_FUN_fffffff00a8df19c
                    (auVar6,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,(short *)puVar2,2,
                     (byte *)"Current Fences:\n");
  lVar1 = *(long *)(param_7 + 0x240);
  auVar6 = extraout_q0;
  while (lVar1 != 0) {
    lVar5 = *(long *)(lVar1 + 0x58);
    uVar4 = FUN_fffffff009c27be8(auVar6,param_2,param_3,param_4,param_5,param_6,uVar4,lVar1);
    lVar1 = lVar5;
    auVar6 = extraout_q0_00;
  }
  uVar4 = thunk_FUN_fffffff00a8df19c
                    (auVar6,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff00806ca48,2,(byte *)"Waiting Fences:\n");
  lVar1 = *(long *)(param_7 + 0x250);
  auVar6 = extraout_q0_01;
  while (lVar1 != 0) {
    lVar5 = *(long *)(lVar1 + 0x58);
    uVar4 = FUN_fffffff009c27be8(auVar6,param_2,param_3,param_4,param_5,param_6,uVar4,lVar1);
    lVar1 = lVar5;
    auVar6 = extraout_q0_02;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x50));
    return;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2793c);
  (*pcVar3)();
}

