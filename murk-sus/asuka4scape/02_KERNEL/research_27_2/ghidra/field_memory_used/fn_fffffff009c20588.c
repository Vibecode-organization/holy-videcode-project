// FUN_fffffff009c20588 @ fffffff009c20588

void FUN_fffffff009c20588
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long param_7)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long *plVar4;
  undefined8 uVar5;
  ulong unaff_x30;
  undefined1 auVar6 [16];
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  
  auVar6 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0x50));
  if ((*(byte *)(param_7 + 0x3d0) >> 5 & 1) != 0) {
    iVar3 = *(int *)(param_7 + 0x9c);
    if (iVar3 == 0) {
      iVar3 = 0;
      if (*(long **)(param_7 + 0x28) != (long *)0x0) {
        iVar3 = (**(code **)(**(long **)(param_7 + 0x28) + 0xb8))();
        *(int *)(param_7 + 0x9c) = iVar3;
        auVar6 = extraout_q0;
      }
    }
    uVar1 = iVar3 - 0x100U >> 8;
    if ((uVar1 | iVar3 << 0x18) < 7 && (1 << (ulong)(uVar1 & 0x1f) & 0x4bU) != 0) {
      thunk_FUN_fffffff00a394134();
    }
    else {
      plVar4 = *(long **)(param_7 + 0x30);
      if ((plVar4 == (long *)0x0) ||
         (iVar3 = (**(code **)(*plVar4 + 0xd8))(plVar4,0), auVar6 = extraout_q0_00, iVar3 != 0)) {
        thunk_FUN_fffffff00a8df19c
                  (auVar6,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff00806ca48,0x10,
                   (byte *)"IOSurface::flushProcessorCaches memory prepare failed\n");
      }
      else {
        plVar4 = *(long **)(param_7 + 0x30);
        uVar5 = (**(code **)(*plVar4 + 0xb0))(plVar4);
        (**(code **)(*plVar4 + 0x88))(plVar4,1,0,uVar5);
        (**(code **)(**(long **)(param_7 + 0x30) + 0xe0))(*(long **)(param_7 + 0x30),0);
      }
    }
    *(uint *)(param_7 + 0x3d0) = *(uint *)(param_7 + 0x3d0) & 0xffffffdf;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c20630);
    (*pcVar2)();
  }
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x50));
  return;
}

