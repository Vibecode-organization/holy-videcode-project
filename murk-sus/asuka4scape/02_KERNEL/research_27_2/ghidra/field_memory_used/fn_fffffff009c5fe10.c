// FUN_fffffff009c5fe10 @ fffffff009c5fe10

/* WARNING: Removing unreachable block (ram,0xfffffff009c60128) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c5ff8c) */

void FUN_fffffff009c5fe10
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7,
               undefined8 param_8)

{
  undefined *puVar1;
  code *pcVar2;
  int iVar3;
  long *plVar4;
  int iVar5;
  ulong unaff_x30;
  
  thunk_FUN_fffffff00a8df19c
            (param_1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
             (short *)PTR_DAT_fffffff00807b638,0,(byte *)"IOTimeSyncClockManager::stop\n");
  if ((long *)param_7[0x26] != (long *)0x0) {
    (**(code **)(*(long *)param_7[0x26] + 0x80))();
    (**(code **)(*(long *)param_7[0x26] + 0x28))();
    param_7[0x26] = 0;
    (**(code **)(*param_7 + 0x28))(param_7);
  }
  if ((long *)param_7[0x27] != (long *)0x0) {
    (**(code **)(*(long *)param_7[0x27] + 0x80))();
    (**(code **)(*(long *)param_7[0x27] + 0x28))();
    param_7[0x27] = 0;
    (**(code **)(*param_7 + 0x28))(param_7);
  }
  if (param_7[0x1e] != 0) {
    thunk_FUN_fffffff00a2262a8(param_7[0x1e]);
    if (0 < param_7[0x12]) {
      (**(code **)(*param_7 + 0x100))(param_7,"WantsgPTPServices");
      (**(code **)(*param_7 + 0x430))(*param_7 + 0x430,param_7,0xe0000130,0,0);
      param_7[0x12] = 0;
    }
    thunk_FUN_fffffff00a226de0(param_7[0x1e]);
  }
  if ((param_7[0x23] != 0) && (param_7[0x24] != 0)) {
    thunk_FUN_fffffff00a2262a8(param_7[0x23]);
    (**(code **)(*(long *)param_7[0x24] + 0xb8))();
    thunk_FUN_fffffff00a226de0(param_7[0x23]);
  }
  if ((param_7[0x21] != 0) && (param_7[0x22] != 0)) {
    thunk_FUN_fffffff00a2262a8(param_7[0x21]);
    iVar3 = (**(code **)(*(long *)param_7[0x22] + 0x90))();
    puVar1 = PTR_DAT_fffffff008078e50;
    if (iVar3 != 0) {
      iVar5 = 0;
      do {
        plVar4 = (long *)(**(code **)(*(long *)param_7[0x22] + 0x118))((long *)param_7[0x22],iVar5);
        plVar4 = thunk_FUN_fffffff00a894f30(plVar4,(long)puVar1);
        if (plVar4 != (long *)0x0) {
          (**(code **)(*plVar4 + 0x2f0))(plVar4,0);
        }
        iVar5 = iVar5 + 1;
      } while (iVar3 != iVar5);
    }
    thunk_FUN_fffffff00a226de0(param_7[0x21]);
  }
  if (param_7[0x20] != 0) {
    thunk_FUN_fffffff00a2262a8(param_7[0x20]);
    if (0 < param_7[0x13]) {
      (**(code **)(*param_7 + 0x100))(param_7,"WantsTSNCapture");
      (**(code **)(*param_7 + 0x430))(*param_7 + 0x430,param_7,0xe0000130,0,0);
      param_7[0x13] = 0;
    }
    thunk_FUN_fffffff00a226de0(param_7[0x20]);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    (**(code **)(PTR_DAT_fffffff00807b628 + 0x2c8))
              (param_7,param_8,PTR_DAT_fffffff00807b628 + 0x2c8);
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c60198);
  (*pcVar2)();
}

