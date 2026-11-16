// FUN_fffffff009c206fc @ fffffff009c206fc

void FUN_fffffff009c206fc
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long param_7)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  
  iVar2 = *(int *)(param_7 + 0x9c);
  if (iVar2 == 0) {
    if (*(long **)(param_7 + 0x28) == (long *)0x0) goto LAB_fffffff009c2075c;
    iVar2 = (**(code **)(**(long **)(param_7 + 0x28) + 0xb8))();
    *(int *)(param_7 + 0x9c) = iVar2;
    param_1 = extraout_q0;
  }
  if (iVar2 == 0x100) {
    return;
  }
  if (iVar2 == 0x400) {
    return;
  }
  if (iVar2 == 0x700) {
    return;
  }
LAB_fffffff009c2075c:
  if (((*(byte *)(DAT_fffffff00af483b0 + 0x89) & 1) == 0) &&
     (plVar3 = *(long **)(param_7 + 0x30), plVar3 != (long *)0x0)) {
    iVar2 = (**(code **)(*plVar3 + 0xd8))(param_1,plVar3,0);
    if (iVar2 == 0) {
      plVar3 = *(long **)(param_7 + 0x30);
      uVar4 = (**(code **)(*plVar3 + 0xb0))(plVar3);
      (**(code **)(*plVar3 + 0x88))(plVar3,1,0,uVar4);
      puVar5 = (undefined8 *)(**(long **)(param_7 + 0x30) + 0xe0);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c20858. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)*puVar5)(*(long **)(param_7 + 0x30),0,puVar5);
        return;
      }
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c20850);
      (*pcVar1)();
    }
    thunk_FUN_fffffff00a8df19c
              (extraout_q0_00,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00806ca48,0x10,
               (byte *)"IOSurface::cleanProcessorCaches memory prepare failed\n");
  }
  return;
}

